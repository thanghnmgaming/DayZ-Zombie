@echo off
rem Backs up the database, then runs the game server in this window.
cd /d "%~dp0"
call backup-database.bat
if errorlevel 1 echo Continuing without a backup. Is start-database.bat running?
omp-server.exe
