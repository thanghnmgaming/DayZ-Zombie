# Dumps the database to backups\ and keeps the 30 newest files. The database must be running.
$ErrorActionPreference = "Stop"
$root = $PSScriptRoot
$settings = @{}
Get-Content "$root\mysql.ini" | Where-Object { $_ -match '^\s*(\w+)\s*=\s*(.*?)\s*$' } | ForEach-Object { $settings[$Matches[1]] = $Matches[2] }
$database = $settings["database"]

$dump = "$root\tools\mariadb\bin\mariadb-dump.exe"
if (-not (Test-Path $dump)) {
    $found = Get-Command mariadb-dump, mysqldump -ErrorAction SilentlyContinue | Select-Object -First 1
    if (-not $found) { Write-Host "BACKUP FAILED: mariadb-dump was not found (add MariaDB's bin folder to PATH)"; exit 1 }
    $dump = $found.Source
}

New-Item -ItemType Directory -Force "$root\backups" | Out-Null
$file = "$root\backups\$database-$(Get-Date -Format yyyyMMdd-HHmmss).sql"
$port = if ($settings["server_port"]) { $settings["server_port"] } else { 3306 }
$env:MYSQL_PWD = $settings["password"]    # keeps the password off the command line
& $dump "--host=$($settings['hostname'])" "--port=$port" "--user=$($settings['username'])" --single-transaction "--result-file=$file" $database
$code = $LASTEXITCODE
Remove-Item Env:MYSQL_PWD
if ($code -ne 0) { Remove-Item $file -ErrorAction SilentlyContinue; Write-Host "BACKUP FAILED"; exit 1 }
Get-ChildItem "$root\backups\*.sql" | Sort-Object LastWriteTime -Descending | Select-Object -Skip 30 | Remove-Item
Write-Host "Saved $file"
