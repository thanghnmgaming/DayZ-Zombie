@echo off
cd /d "%~dp0gamemodes"
"..\qawno\pawncc.exe" dayz.pwn -i..\qawno\include "-;+" "-(+"
pause
