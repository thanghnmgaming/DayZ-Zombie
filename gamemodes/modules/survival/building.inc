// ---------------------------------------------------------------------------
// Base building: walls and gates placed by players, kept in MySQL.
// ---------------------------------------------------------------------------

#define MAX_STRUCTURES          500
#define MAX_STRUCTURES_PER_PLAYER 20
#define GATE_DROP               3.6     // how far an open gate sinks into the ground

new const StructureItem[][ITEM_NAME_SIZE] = {"Wooden Wall", "Wooden Gate"};

enum E_STRUCTURE
{
	bool:stUsed,
	bool:stOpen,
	stType,
	stOwner[MAX_PLAYER_NAME],
	Float:stX,
	Float:stY,
	Float:stZ,
	Float:stAngle,
	stObject
}

new Structure[MAX_STRUCTURES][E_STRUCTURE];

stock SpawnStructure(id, type, const owner[], Float:x, Float:y, Float:z, Float:angle)
{
	Structure[id][stUsed] = true;
	Structure[id][stOpen] = false;
	Structure[id][stType] = type;
	format(Structure[id][stOwner], MAX_PLAYER_NAME, "%s", owner);
	Structure[id][stX] = x;
	Structure[id][stY] = y;
	Structure[id][stZ] = z;
	Structure[id][stAngle] = angle;
	Structure[id][stObject] = CreateDynamicObject(19353, x, y, z, 0.0, 0.0, angle, 0, 0, -1, 300.0);
	// gates get a different texture so they can be told apart
	if(type == STRUCTURE_GATE) SetDynamicObjectMaterial(Structure[id][stObject], 0, 1355, "break_s_bins", "CJ_WOOD_DARK", 0);
	else SetDynamicObjectMaterial(Structure[id][stObject], 0, 1355, "break_s_bins", "CJ_SLATEDWOOD", 0);
	return 1;
}

stock LoadStructures()
{
	mysql_query(handle, "CREATE TABLE IF NOT EXISTS `structures` (`ID` int NOT NULL, `Type` int NOT NULL, `Owner` varchar(24) NOT NULL, `X` float NOT NULL, `Y` float NOT NULL, `Z` float NOT NULL, `Angle` float NOT NULL, PRIMARY KEY (`ID`))", false);
	new Cache:result = mysql_query(handle, "SELECT * FROM `structures`"), rows, loaded;
	cache_get_row_count(rows);
	for(new row; row < rows; row++)
	{
		new id, type, owner[MAX_PLAYER_NAME], Float:x, Float:y, Float:z, Float:angle;
		cache_get_value_name_int(row, "ID", id);
		cache_get_value_name_int(row, "Type", type);
		if(!(0 <= id < MAX_STRUCTURES) || !(0 <= type < sizeof(StructureItem))) continue;
		cache_get_value_name(row, "Owner", owner);
		cache_get_value_name_float(row, "X", x);
		cache_get_value_name_float(row, "Y", y);
		cache_get_value_name_float(row, "Z", z);
		cache_get_value_name_float(row, "Angle", angle);
		SpawnStructure(id, type, owner, x, y, z, angle);
		loaded++;
	}
	cache_delete(result);
	printf("[DB] %d structure(s) loaded.", loaded);
	return 1;
}

stock PlaceStructure(playerid, type)
{
	if(IsPlayerInAnyVehicle(playerid) || GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0)
		return SendClientMessage(playerid, -1, ""chat" You cannot build here."), 0;

	new name[MAX_PLAYER_NAME], owned, id = -1;
	GetPlayerName(playerid, name, sizeof(name));
	for(new i; i < MAX_STRUCTURES; i++)
	{
		if(!Structure[i][stUsed]) { if(id == -1) id = i; }
		else if(!strcmp(Structure[i][stOwner], name)) owned++;
	}
	if(owned >= MAX_STRUCTURES_PER_PLAYER) return SendClientMessage(playerid, -1, ""chat" You have reached your building limit."), 0;
	if(id == -1) return SendClientMessage(playerid, -1, ""chat" There are too many structures in the world."), 0;

	new Float:x, Float:y, Float:z, Float:angle, query[256];
	GetPlayerPos(playerid, x, y, z);
	GetPlayerFacingAngle(playerid, angle);
	x += 1.8 * floatsin(-angle, degrees);
	y += 1.8 * floatcos(-angle, degrees);
	SpawnStructure(id, type, name, x, y, z + 0.7, angle + 90.0);
	mysql_format(handle, query, sizeof(query), "REPLACE INTO `structures` VALUES (%d,%d,'%e',%f,%f,%f,%f)", id, type, name, x, y, z + 0.7, angle + 90.0);
	mysql_tquery(handle, query);
	RemoveSlotToInventory(playerid, StructureItem[type], 1);
	SendClientMessage(playerid, -1, ""chat" Built. /gate opens your gate, /demolish removes your structure.");
	return 1;
}

stock GetNearStructure(playerid, type = -1)
{
	new near = -1, Float:best = 3.5;
	for(new i; i < MAX_STRUCTURES; i++)
	{
		if(!Structure[i][stUsed] || (type != -1 && Structure[i][stType] != type)) continue;
		new Float:distance = GetPlayerDistanceFromPoint(playerid, Structure[i][stX], Structure[i][stY], Structure[i][stZ]);
		if(distance < best)
		{
			best = distance;
			near = i;
		}
	}
	return near;
}

// Owners, and members of the owner's group, may use a gate
stock bool:CanUseStructure(playerid, id)
{
	new name[MAX_PLAYER_NAME];
	GetPlayerName(playerid, name, sizeof(name));
	if(!strcmp(name, Structure[id][stOwner])) return true;
	if(pInfo[playerid][IsPlayerInGroup] != 1) return false;
	foreach(new i : Player)
	{
		GetPlayerName(i, name, sizeof(name));
		if(!strcmp(name, Structure[id][stOwner]))
			return pInfo[i][IsPlayerInGroup] == 1 && pInfo[i][IsPlayerInGroupID] == pInfo[playerid][IsPlayerInGroupID];
	}
	return false;
}

CMD:gate(playerid)
{
	new id = GetNearStructure(playerid, STRUCTURE_GATE);
	if(id == -1) return SendClientMessage(playerid, -1, ""chat" There is no gate here.");
	if(!CanUseStructure(playerid, id)) return SendClientMessage(playerid, -1, ""chat" This is not your gate.");
	Structure[id][stOpen] = !Structure[id][stOpen];
	new Float:z = Structure[id][stZ];
	if(Structure[id][stOpen]) z -= GATE_DROP;
	MoveDynamicObject(Structure[id][stObject], Structure[id][stX], Structure[id][stY], z, 2.5);
	return 1;
}

CMD:demolish(playerid)
{
	new id = GetNearStructure(playerid), name[MAX_PLAYER_NAME], query[96];
	if(id == -1) return SendClientMessage(playerid, -1, ""chat" There is nothing to demolish here.");
	GetPlayerName(playerid, name, sizeof(name));
	new bool:owner = !strcmp(name, Structure[id][stOwner]);
	if(!owner && pInfo[playerid][pAdminLevel] < 5) return SendClientMessage(playerid, -1, ""chat" This is not your structure.");
	if(owner)
	{
		if(!PlayerHasItem(playerid, "Toolbox")) return SendClientMessage(playerid, -1, ""chat" You need a Toolbox.");
		if(!AddSlotToInventoryWorld(playerid, StructureItem[Structure[id][stType]], 1)) return 1;
	}
	DestroyDynamicObject(Structure[id][stObject]);
	Structure[id][stUsed] = false;
	mysql_format(handle, query, sizeof(query), "DELETE FROM `structures` WHERE `ID`=%d", id);
	mysql_tquery(handle, query);
	SendClientMessage(playerid, -1, ""chat" Demolished.");
	return 1;
}
