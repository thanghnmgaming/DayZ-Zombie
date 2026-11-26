@echo off
rem Dumps the project database to backups\ and keeps the 30 newest files. The database must be running.
setlocal
cd /d "%~dp0"
if not exist backups mkdir backups
for /f %%i in ('powershell -NoProfile -Command "Get-Date -Format yyyyMMdd-HHmmss"') do set STAMP=%%i
"tools\mariadb\bin\mariadb-dump.exe" --defaults-extra-file="%~dp0database\root.cnf" --single-transaction --result-file="backups\samp-%STAMP%.sql" samp
if errorlevel 1 (
  echo BACKUP FAILED
  del "backups\samp-%STAMP%.sql" 2>nul
  exit /b 1
)
powershell -NoProfile -Command "Get-ChildItem backups\samp-*.sql | Sort-Object Name -Descending | Select-Object -Skip 30 | Remove-Item"
echo Saved backups\samp-%STAMP%.sql
