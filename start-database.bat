@echo off
rem Local MariaDB for this project (127.0.0.1:3307). Keep this window open.
cd /d "%~dp0"
"tools\mariadb\bin\mariadbd.exe" --defaults-file="%~dp0database\my.ini" --datadir="%~dp0database\data" --console
