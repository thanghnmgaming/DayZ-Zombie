@echo off
cd /d "%~dp0"
"tools\mariadb\bin\mariadb-admin.exe" --defaults-extra-file="%~dp0database\root.cnf" shutdown
