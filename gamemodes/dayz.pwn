/*
	Created for Pro Gaming Arena Gaming Community

	Created by: Kitten aka AldenJ aka AaronN (https://github.com/AaronNader96)
	Created date: 1/1/12
	Created time: 3:41 PM
	Name: GTA SA: DayZ Version
	Saving: MySQL
	Version: 15.0
	Website: www.pgagaming.net

	YSI + Foreach Fix by Eternity (https://github.com/rizzyneck)
	All credits going to AaronN, and also plugins developer.
*/

#define MIXED_SPELLINGS
#define NO_TAGS // legacy code passes plain numbers for weapons, fonts and flags
#include <open.mp>
#include <a_mysql>
#include <samp_bcrypt>
#include <sscanf2>
#include <streamer>
#include <Pawn.CMD>
#include <foreach>
#include <mapandreas>
#include <em_actors>
#include <TWD_Map>
#include <dayzmap>
#include <dayzmap2>
#include <OPA>
#include <OPRF>
#include <em_callbacks>
#include <DayZ_AntiG>

// Modules (order matters: Pawn compiles them as one script)
#include "modules/config.inc"
#include "modules/core/data.inc"
#include "modules/items/catalog.inc"
#include "modules/core/init.inc"
#include "modules/core/timers.inc"
#include "modules/player/combat.inc"
#include "modules/player/account.inc"
#include "modules/player/spawn.inc"
#include "modules/player/keys.inc"
#include "modules/player/dialogs.inc"
#include "modules/commands/general.inc"
#include "modules/commands/admin.inc"
#include "modules/player/stats.inc"
#include "modules/player/hud.inc"
#include "modules/items/inventory.inc"
#include "modules/items/usage.inc"
#include "modules/vehicles/vehicles.inc"
#include "modules/world/mapping.inc"
#include "modules/items/loot.inc"
#include "modules/world/helpers.inc"
#include "modules/items/containers.inc"
#include "modules/server/bans.inc"
#include "modules/server/session.inc"
#include "modules/server/persistence.inc"
#include "modules/server/audit.inc"
#include "modules/commands/admin_tools.inc"
#include "modules/commands/help.inc"
#include "modules/survival/infection.inc"
#include "modules/survival/building.inc"
#include "modules/survival/crafting.inc"
#include "modules/survival/world.inc"
#include "modules/zombies/collision.inc"
#include "modules/zombies/zombies.inc"
