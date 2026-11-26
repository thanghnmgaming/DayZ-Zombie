<#
.SYNOPSIS
  Prepares a fresh copy of the server: configuration, database settings, build and checks.
.EXAMPLE
  .\setup.bat -PortableMariaDB "C:\Downloads\mariadb-11.8.6-winx64"
  Creates a private database inside this folder from an unpacked MariaDB ZIP.
.EXAMPLE
  .\setup.bat -DbHost 127.0.0.1 -DbPort 3306 -DbUser dayz -DbPassword secret -DbName samp
  Uses a MariaDB server you already run (the database and user must exist).
#>
param(
    [string]$PortableMariaDB,
    [string]$DbHost = "127.0.0.1",
    [int]$DbPort = 3307,
    [string]$DbUser,
    [string]$DbPassword,
    [string]$DbName = "samp"
)

$ErrorActionPreference = "Stop"
$root = $PSScriptRoot
Set-Location $root

function New-Secret {
    $chars = "ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnpqrstuvwxyz23456789"
    $bytes = New-Object byte[] 24
    [System.Security.Cryptography.RandomNumberGenerator]::Create().GetBytes($bytes)
    -join ($bytes | ForEach-Object { $chars[$_ % $chars.Length] })
}

function Write-Text($path, $text) {
    [System.IO.File]::WriteAllText($path, $text, (New-Object System.Text.UTF8Encoding($false)))
}

# 1. config.json
if (Test-Path "config.json") {
    Write-Host "[ok]   config.json already exists"
} else {
    $config = Get-Content "config.example.json" -Raw
    $rcon = New-Secret
    $config = $config -replace '("rcon":\s*\{[^}]*?"enable":\s*)false', '${1}true'
    $config = $config -replace '"password":\s*"changeme1"', ('"password": "' + $rcon + '"')
    Write-Text "$root\config.json" $config
    Write-Host "[done] config.json created with a random RCON password (see the rcon section)"
}

# 2. database
if ($PortableMariaDB) {
    if (-not (Test-Path "$PortableMariaDB\bin\mariadbd.exe")) { throw "No bin\mariadbd.exe in '$PortableMariaDB'. Point to an unpacked MariaDB Windows ZIP." }
    if (Test-Path "database\data") { throw "database\data already exists. Delete the database folder only if you want to start over." }
    if (Get-NetTCPConnection -LocalPort $DbPort -State Listen -ErrorAction SilentlyContinue) { throw "Port $DbPort is already in use. Pass another one with -DbPort." }

    New-Item -ItemType Directory -Force "tools\mariadb", "database" | Out-Null
    foreach ($part in "bin", "share", "lib") {
        if (Test-Path "$PortableMariaDB\$part") { Copy-Item "$PortableMariaDB\$part" "tools\mariadb" -Recurse -Force }
    }
    $bin = "$root\tools\mariadb\bin"
    if (-not (Test-Path "$bin\mysqld.exe")) { Copy-Item "$bin\mariadbd.exe" "$bin\mysqld.exe" }

    & "$bin\mariadb-install-db.exe" "--datadir=$root\database\data" | Out-Null
    if ($LASTEXITCODE -ne 0) { throw "mariadb-install-db failed" }
    Remove-Item "database\data\my.ini" -ErrorAction SilentlyContinue
    Write-Text "$root\database\my.ini" "[mariadbd]`nport=$DbPort`nbind-address=127.0.0.1`nskip-name-resolve`ncharacter-set-server=utf8mb4`n"

    $rootPassword = New-Secret
    $DbUser = "dayz"; $DbPassword = New-Secret; $DbHost = "127.0.0.1"
    $server = Start-Process "$bin\mariadbd.exe" -ArgumentList "--defaults-file=`"$root\database\my.ini`"", "--datadir=`"$root\database\data`"" -WindowStyle Hidden -PassThru
    $ready = $false
    foreach ($try in 1..60) {
        if (Get-NetTCPConnection -LocalPort $DbPort -State Listen -ErrorAction SilentlyContinue) { $ready = $true; break }
        Start-Sleep -Milliseconds 500
    }
    if (-not $ready) { throw "The database did not start. See database\data\*.err" }

    $sql = @"
DELETE FROM mysql.global_priv WHERE User='';
DROP USER IF EXISTS 'root'@'$($env:COMPUTERNAME.ToLower())', 'root'@'127.0.0.1', 'root'@'::1';
ALTER USER 'root'@'localhost' IDENTIFIED BY '$rootPassword';
CREATE USER 'root'@'127.0.0.1' IDENTIFIED BY '$rootPassword';
GRANT ALL ON *.* TO 'root'@'127.0.0.1' WITH GRANT OPTION;
CREATE DATABASE ``$DbName`` CHARACTER SET utf8mb4;
CREATE USER '$DbUser'@'127.0.0.1' IDENTIFIED BY '$DbPassword';
GRANT ALL ON ``$DbName``.* TO '$DbUser'@'127.0.0.1';
FLUSH PRIVILEGES;
"@
    $sql | & "$bin\mariadb.exe" --no-defaults "--host=127.0.0.1" "--port=$DbPort" "--user=root"
    if ($LASTEXITCODE -ne 0) { Stop-Process -Id $server.Id; throw "Creating the database users failed" }
    Write-Text "$root\database\root.cnf" "[client]`nhost=127.0.0.1`nport=$DbPort`nuser=root`npassword=$rootPassword`n"
    Write-Host "[done] private database created on port $DbPort and left running"
}

if ($DbUser) {
    Write-Text "$root\mysql.ini" "hostname = $DbHost`nusername = $DbUser`npassword = $DbPassword`ndatabase = $DbName`nserver_port = $DbPort`nauto_reconnect = true`n"
    Write-Host "[done] mysql.ini written"
} elseif (Test-Path "mysql.ini") {
    Write-Host "[ok]   mysql.ini already exists"
} else {
    Copy-Item "mysql.example.ini" "mysql.ini"
    Write-Host "[todo] edit mysql.ini with the login of your MariaDB server"
}

# 3. build
Push-Location "gamemodes"
& "..\qawno\pawncc.exe" "dayz.pwn" "-i..\qawno\include" "-;+" "-(+" | Out-Host
$built = $LASTEXITCODE -eq 0
Pop-Location
if (-not $built) { throw "The gamemode did not compile" }
Write-Host "[done] gamemodes\dayz.amx built"

# 4. map data
if (Test-Path "scriptfiles\SAfull.hmap") { Write-Host "[ok]   scriptfiles\SAfull.hmap" }
else { Write-Host "[todo] REQUIRED: scriptfiles\SAfull.hmap (see README, 'Map data')" }
if (Test-Path "scriptfiles\colandreas\ColAndreas.cadb") { Write-Host "[ok]   scriptfiles\colandreas\ColAndreas.cadb" }
else {
    New-Item -ItemType Directory -Force "scriptfiles\colandreas" | Out-Null
    Write-Host "[todo] recommended: scriptfiles\colandreas\ColAndreas.cadb, otherwise zombies walk through walls (see README)"
}

Write-Host ""
Write-Host "Next: start-database.bat (private database only), then start-server.bat"
