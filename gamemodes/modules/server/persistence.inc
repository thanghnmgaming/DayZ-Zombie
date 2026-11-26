// ---------------------------------------------------------------------------
// MySQL persistence for inventories, tents and vehicle storage.
// ---------------------------------------------------------------------------



// ---- schema and world loading (called once at start-up) -------------------

stock CreatePersistenceTables()
{
	mysql_query(handle, "CREATE TABLE IF NOT EXISTS `inventory` (`Username` varchar(24) NOT NULL, `Slot` int NOT NULL, `Item` varchar(64) NOT NULL, `Amount` int NOT NULL, PRIMARY KEY (`Username`,`Slot`))", false);
	mysql_query(handle, "CREATE TABLE IF NOT EXISTS `tents` (`ID` int NOT NULL, `Owner` varchar(24) NOT NULL, `X` float NOT NULL, `Y` float NOT NULL, `Z` float NOT NULL, PRIMARY KEY (`ID`))", false);
	mysql_query(handle, "CREATE TABLE IF NOT EXISTS `vehicle_state` (`ID` int NOT NULL, `Model` int NOT NULL, `Fuel` int NOT NULL, `Engine` int NOT NULL, `Tires` int NOT NULL, PRIMARY KEY (`ID`))", false);
	mysql_query(handle, "CREATE TABLE IF NOT EXISTS `storage_items` (`Kind` int NOT NULL, `Container` int NOT NULL, `Slot` int NOT NULL, `Item` varchar(64) NOT NULL, PRIMARY KEY (`Kind`,`Container`,`Slot`))", false);
	return 1;
}

stock LoadTents()
{
	new Cache:result = mysql_query(handle, "SELECT * FROM `tents`"), rows, loaded;
	cache_get_row_count(rows);
	for(new row; row < rows; row++)
	{
		new id, owner[MAX_PLAYER_NAME], Float:x, Float:y, Float:z;
		cache_get_value_name_int(row, "ID", id);
		if(id <= 0 || id >= MAX_TENTS) continue;
		cache_get_value_name(row, "Owner", owner);
		cache_get_value_name_float(row, "X", x);
		cache_get_value_name_float(row, "Y", y);
		cache_get_value_name_float(row, "Z", z);
		SpawnTent(id, owner, x, y, z);
		loaded++;
	}
	cache_delete(result);
	printf("[DB] %d tent(s) loaded.", loaded);
	return 1;
}

stock LoadVehicleStates()
{
	new Cache:result = mysql_query(handle, "SELECT * FROM `vehicle_state`"), rows, loaded;
	cache_get_row_count(rows);
	for(new row; row < rows; row++)
	{
		new id, model;
		cache_get_value_name_int(row, "ID", id);
		cache_get_value_name_int(row, "Model", model);
		// A changed vehicle list must not hand one vehicle's cargo to another model
		if(id <= 0 || id >= MAX_VEHICLES || GetVehicleModel(id) != model) continue;
		cache_get_value_name_int(row, "Fuel", vInfo[id][vehicleFuel]);
		cache_get_value_name_int(row, "Engine", vInfo[id][vehicleEngine]);
		cache_get_value_name_int(row, "Tires", vInfo[id][vehicleTires]);
		loaded++;
	}
	cache_delete(result);
	printf("[DB] %d vehicle state(s) loaded.", loaded);
	return 1;
}

// Must run after the tents and vehicles exist
stock LoadStorageItems()
{
	new Cache:result = mysql_query(handle, "SELECT * FROM `storage_items`"), rows;
	cache_get_row_count(rows);
	for(new row; row < rows; row++)
	{
		new kind, container, slot, item[64];
		cache_get_value_name_int(row, "Kind", kind);
		cache_get_value_name_int(row, "Container", container);
		cache_get_value_name_int(row, "Slot", slot);
		cache_get_value_name(row, "Item", item);
		if(kind == STORAGE_TENT && 0 < container < MAX_TENTS && 0 <= slot < MAX_TENT_SLOTS) format(TentSlots[container][slot], 64, "%s", item);
		if(kind == STORAGE_VEHICLE && 0 < container < MAX_VEHICLES && 0 <= slot < MAX_VEHICLE_SLOTS) format(VehicleSlots[container][slot], 64, "%s", item);
	}
	cache_delete(result);
	return 1;
}

// ---- saving ---------------------------------------------------------------

stock SaveStorageSlot(kind, container, slot, const item[])
{
	if(kind == STORAGE_VEHICLE && AdminVehicle[container]) return 0;
	new query[256];
	if(IsItemName(item)) mysql_format(handle, query, sizeof(query), "REPLACE INTO `storage_items` VALUES (%d,%d,%d,'%e')", kind, container, slot, item);
	else mysql_format(handle, query, sizeof(query), "DELETE FROM `storage_items` WHERE `Kind`=%d AND `Container`=%d AND `Slot`=%d", kind, container, slot);
	mysql_tquery(handle, query);
	return 1;
}

stock SaveTent(id, const owner[])
{
	new query[256];
	mysql_format(handle, query, sizeof(query), "REPLACE INTO `tents` VALUES (%d,'%e',%f,%f,%f)", id, owner, Tent[id][xTent], Tent[id][yTent], Tent[id][zTent]);
	mysql_tquery(handle, query);
	return 1;
}

stock DeleteTentRecord(id)
{
	new query[128];
	mysql_format(handle, query, sizeof(query), "DELETE FROM `tents` WHERE `ID`=%d", id);
	mysql_tquery(handle, query);
	mysql_format(handle, query, sizeof(query), "DELETE FROM `storage_items` WHERE `Kind`=%d AND `Container`=%d", STORAGE_TENT, id);
	mysql_tquery(handle, query);
	return 1;
}

stock SaveVehicleState(id)
{
	new query[256], model = GetVehicleModel(id);
	if(model < 400 || AdminVehicle[id]) return 0;
	mysql_format(handle, query, sizeof(query), "REPLACE INTO `vehicle_state` VALUES (%d,%d,%d,%d,%d)", id, model, vInfo[id][vehicleFuel], vInfo[id][vehicleEngine], vInfo[id][vehicleTires]);
	mysql_tquery(handle, query);
	return 1;
}

stock SaveAllVehicleStates()
{
	for(new i = 1; i < MAX_VEHICLES; i++) SaveVehicleState(i);
	return 1;
}

// ---- inventories ----------------------------------------------------------

stock SaveInventory(playerid)
{
	if(IsPlayerNPC(playerid) || pInfo[playerid][pLogged] != 1 || !InventoryLoaded[playerid]) return 0;

	new query[256], name[MAX_PLAYER_NAME];
	GetPlayerName(playerid, name, sizeof(name));
	mysql_tquery(handle, "START TRANSACTION");
	mysql_format(handle, query, sizeof(query), "DELETE FROM `inventory` WHERE `Username`='%e'", name);
	mysql_tquery(handle, query);
	for(new item; item < MAX_ITEMS; item++)
	{
		new amount = _GetItemAmountPVar(playerid, item);
		if(amount <= 0 || !strlen(_GetItemNamePVar(playerid, item))) continue;
		mysql_format(handle, query, sizeof(query), "INSERT INTO `inventory` VALUES ('%e',%d,'%e',%d)", name, item, _GetItemNamePVar(playerid, item), amount);
		mysql_tquery(handle, query);
	}
	mysql_tquery(handle, "COMMIT");
	return 1;
}

stock LoadInventory(playerid)
{
	if(IsPlayerNPC(playerid)) return 0;
	new query[128], name[MAX_PLAYER_NAME];
	GetPlayerName(playerid, name, sizeof(name));
	InventoryLoaded[playerid] = false;
	mysql_format(handle, query, sizeof(query), "SELECT `Item`,`Amount` FROM `inventory` WHERE `Username`='%e' ORDER BY `Slot`", name);
	mysql_tquery(handle, query, "OnInventoryLoaded", "ii", playerid, LoginSerial[playerid]);
	return 1;
}

forward OnInventoryLoaded(playerid, serial);
public OnInventoryLoaded(playerid, serial)
{
	if(!IsPlayerConnected(playerid) || serial != LoginSerial[playerid]) return 1;
	new rows, item[64], amount;
	cache_get_row_count(rows);
	for(new row; row < rows; row++)
	{
		cache_get_value_name(row, "Item", item);
		cache_get_value_name_int(row, "Amount", amount);
		AddItem(playerid, item, amount);
	}
	InventoryLoaded[playerid] = true;
	if(!rows) ImportInventoryFile(playerid);
	RecountBackpack(playerid);
	printf("[INV] %s[%d]'s inventory loaded.", PlayerName(playerid), playerid);
	return 1;
}

// One-time migration of the old scriptfiles/DayZSA/Inv/<name>.inv files
stock ImportInventoryFile(playerid)
{
	new path[64], line[64], amountText[24], name[MAX_PLAYER_NAME];
	GetPlayerName(playerid, name, sizeof(name));
	format(path, sizeof(path), ITEM_PATH"/%s.inv", name);
	if(!fexist(path)) return 0;
	new File:file = fopen(path, io_read);
	while(fread(file, line) && fread(file, amountText))
	{
		new len = strlen(line);
		while(len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r')) line[--len] = EOS;
		if(len) AddItem(playerid, line, strval(amountText));
	}
	fclose(file);
	if(SaveInventory(playerid)) fremove(path);
	return 1;
}
