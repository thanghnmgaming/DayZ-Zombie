# DayZ Survival for open.mp

A free zombie survival gamemode you can download and run as your own server (Windows).

## Features
- Accounts with bcrypt passwords; characters, inventories, tents, vehicle cargo and buildings saved in MariaDB
- Zombies that appear around players, see, hear, wander, chase and claw at walls (walker, runner, brute)
- Hunger, thirst, temperature, bleeding, broken legs and infection
- Loot, crafting, camp fires, tents, wooden walls and gates, vehicle parts and fuel
- Danger zones, supply airdrops, kill missions, groups
- Admin tools, audit log and server-side cheat checks
- In-game guide: `/help`

## Requirements
- Windows
- [MariaDB](https://mariadb.org/download/) 10.5 or newer (MySQL is not supported). The Windows ZIP package is enough.
- Players use SA-MP 0.3.7 / 0.3.DL or the open.mp client

## Quick start
1. Download this repository (`git clone`, or Code > Download ZIP) and unpack it.
2. Get the map data (next section).
3. Run **one** of these in the server folder:

   Private database inside the server folder, from an unpacked MariaDB ZIP:
   ```
   .\setup.bat -PortableMariaDB "C:\path\to\mariadb-folder"
   ```
   Or use a MariaDB server you already have (create the database and user first):
   ```
   .\setup.bat -DbHost 127.0.0.1 -DbPort 3306 -DbUser dayz -DbPassword yourpassword -DbName samp
   ```
4. With the private database: `start-database.bat` (keep the window open; setup leaves it running the first time).
5. `start-server.bat`
6. Connect to `127.0.0.1:7777`.

Tables are created automatically on the first start. `database.sql` lists their structure (no data) if you prefer to import it yourself.

## Map data
These files are too large for the repository.

| File | Needed | How to get it |
|---|---|---|
| `scriptfiles/SAfull.hmap` | Required | `MapAndreas-win-x86.zip` from the [MapAndreas v1.2.1 release](https://github.com/philip1337/samp-plugin-mapandreas/releases/tag/v1.2.1), folder `windows/scriptfiles` |
| `scriptfiles/colandreas/ColAndreas.cadb` | Recommended | Run `ColAndreasWizard.exe` from the [ColAndreas 1.5.0 release](https://github.com/Pottus/ColAndreas/releases/tag/1.5.0), choose your GTA San Andreas folder (with SA-MP installed) and save the file to that path |

Without the collision file the server still runs, but zombies walk through walls.

## Make it yours
| What | Where |
|---|---|
| Server name, website, slots, port, password, RCON password | `config.json` |
| Title, version text, optional music links | `gamemodes/modules/config.inc` |
| Items (food values, weapons, models, loot pools) | `gamemodes/modules/items/catalog.inc` |
| Crafting recipes | `gamemodes/modules/survival/crafting.inc` |
| Zombie types, numbers, senses | top of `gamemodes/modules/zombies/zombies.inc` |
| Danger zones, airdrop sites, mission rewards | `gamemodes/modules/survival/world.inc` |
| Guide pages | `gamemodes/modules/commands/help.inc` |

`max_players` in `config.json` includes the zombies: keep `max_bots` at 200 or more.

After editing the gamemode, rebuild with `build.bat` and restart the server.

## Becoming an administrator
1. Log in to your account in game.
2. `/rcon login <password from config.json>`
3. `/adminme` (grants level 5). For level 6, set `pAdminLevel` in the `users` table while you are offline.

Useful level 5 commands: `/veh`, `/delveh`, `/gun`, `/god`, `/logs`. The full list is under `/acmds`.

## Backups
`start-server.bat` makes a backup before starting. `backup-database.bat` writes `backups\<database>-<time>.sql` and keeps the 30 newest.
To restore: `mariadb --host=... --user=... -p yourdatabase < backups\file.sql`

## Folder layout
```
gamemodes/dayz.pwn      entry point (includes the modules)
gamemodes/modules/      core, player, items, world, vehicles, zombies, survival, server, commands
qawno/                  compiler and includes
components/, plugins/   open.mp components and plugins
```

## Credits
- Original DayZ gamemode by AaronN (Kitten / AldenJ): https://github.com/AaronNader96/Project-DayZ-SAMP
- https://github.com/lightningpriest/samp-dayz
- open.mp, YSF-era community includes, and the authors of the MySQL, streamer, sscanf, Pawn.CMD, MapAndreas, ColAndreas and bcrypt plugins

The bundled third-party binaries and includes keep their own licences.
