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
#include "modules/core/data.inc"
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
#include "modules/zombies/zombies.inc"
