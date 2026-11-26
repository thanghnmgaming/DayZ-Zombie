@echo off
rem Private MariaDB created by setup.bat -PortableMariaDB. Keep this window open.
cd /d "%~dp0"
if not exist "tools\mariadb\bin\mariadbd.exe" (
  echo No private database here. Run setup.bat with -PortableMariaDB, or start your own MariaDB server.
  pause
  exit /b 1
)
"tools\mariadb\bin\mariadbd.exe" --defaults-file="%~dp0database\my.ini" --datadir="%~dp0database\data" --console
