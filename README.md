# DayZ Zombie Survival (open.mp)

## Setup
1. Copy `config.example.json` to `config.json` and set `rcon.password`.
2. Put `SAfull.hmap` (MapAndreas v1.2.1 release) into `scriptfiles/`.
3. Database: copy `mysql.example.ini` to `mysql.ini`, then import `samp.sql` into your database. The local setup uses `start-database.bat` / `stop-database.bat` (portable MariaDB in `tools/mariadb`, port 3307; not in Git).
4. Build: `cd gamemodes`, then `..\qawno\pawncc.exe dayz.pwn -i..\qawno\include "-;+" "-(+"`.
5. Run `omp-server.exe`.

Admin: log in with `/rcon login`, then `/thanghnm`.

## Credits
- https://github.com/lightningpriest/samp-dayz
- https://github.com/AaronNader96/Project-DayZ-SAMP
