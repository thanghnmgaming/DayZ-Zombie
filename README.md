# DayZ Zombie Survival (open.mp)

## Setup
1. Copy `config.example.json` to `config.json` and set `rcon.password`.
2. Put `SAfull.hmap` (MapAndreas v1.2.1 release) into `scriptfiles/`.
3. Import `samp.sql` into a MySQL database named `samp` (settings at the top of `gamemodes/dayz.pwn`).
4. Build: `cd gamemodes`, then `..\qawno\pawncc.exe dayz.pwn -i..\qawno\include "-;+" "-(+"`.
5. Run `omp-server.exe`.

Admin: log in with `/rcon login`, then `/thanghnm`.

## Credits
- https://github.com/lightningpriest/samp-dayz
- https://github.com/AaronNader96/Project-DayZ-SAMP
