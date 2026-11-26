// ---------------------------------------------------------------------------
// Containers (tents, vehicle storage, loot piles, crates).
// The server decides what a player takes or stores: the dialog target is fixed
// when the dialog opens and is re-checked when the answer arrives.
// ---------------------------------------------------------------------------


stock GetEntryItemName(const entry[], dest[], size = sizeof(dest))
{
	// Entries look like "Item" or "1\tItem"
	new pos = strfind(entry, "\t");
	while(pos != -1 && entry[pos] == '\t') pos++;
	strmid(dest, entry, (pos == -1) ? 0 : pos, strlen(entry), size);
	return 1;
}

stock bool:IsItemName(const name[])
{
	return name[0] != EOS && strcmp(name, EMPTY_SLOT, true) != 0;
}

stock GetTentSlot(tentid, slot, dest[])
{
	if(!(0 <= slot < MAX_TENT_SLOTS)) return 0;
	format(dest, 64, "%s", TentSlots[tentid][slot]);
	return 1;
}

stock SetTentSlot(tentid, slot, const value[])
{
	if(!(0 <= slot < MAX_TENT_SLOTS)) return 0;
	format(TentSlots[tentid][slot], 64, "%s", value);
	SaveStorageSlot(STORAGE_TENT, tentid, slot, value);
	return 1;
}

stock GetStorageSlot(vehicleid, slot, dest[])
{
	if(!(0 <= slot < MAX_VEHICLE_SLOTS)) return 0;
	format(dest, 64, "%s", VehicleSlots[vehicleid][slot]);
	return 1;
}

stock SetStorageSlot(vehicleid, slot, const value[])
{
	if(!(0 <= slot < MAX_VEHICLE_SLOTS)) return 0;
	format(VehicleSlots[vehicleid][slot], 64, "%s", value);
	SaveStorageSlot(STORAGE_VEHICLE, vehicleid, slot, value);
	return 1;
}

#define CRATE_CASE(%0,%1,%2) case %0: format(dest, 64, "%s", Loot[id][%1Slot%2])
#define CRATE_SET(%0,%1,%2) case %0: format(Loot[id][%1Slot%2], 64, "0\t%s", EMPTY_SLOT)
stock GetAirSlot(id, slot, dest[])
{
	switch(slot)
	{
		CRATE_CASE(0,Air,1); CRATE_CASE(1,Air,2); CRATE_CASE(2,Air,3); CRATE_CASE(3,Air,4);
		CRATE_CASE(4,Air,5); CRATE_CASE(5,Air,6); CRATE_CASE(6,Air,7); CRATE_CASE(7,Air,8);
		CRATE_CASE(8,Air,9); CRATE_CASE(9,Air,10); CRATE_CASE(10,Air,11); CRATE_CASE(11,Air,12);
		default: return 0;
	}
	return 1;
}

stock ClearAirSlot(id, slot)
{
	switch(slot)
	{
		CRATE_SET(0,Air,1); CRATE_SET(1,Air,2); CRATE_SET(2,Air,3); CRATE_SET(3,Air,4);
		CRATE_SET(4,Air,5); CRATE_SET(5,Air,6); CRATE_SET(6,Air,7); CRATE_SET(7,Air,8);
		CRATE_SET(8,Air,9); CRATE_SET(9,Air,10); CRATE_SET(10,Air,11); CRATE_SET(11,Air,12);
	}
	return 1;
}

stock GetHospitalSlot(id, slot, dest[])
{
	switch(slot)
	{
		CRATE_CASE(0,Hos,1); CRATE_CASE(1,Hos,2); CRATE_CASE(2,Hos,3);
		CRATE_CASE(3,Hos,4); CRATE_CASE(4,Hos,5); CRATE_CASE(5,Hos,6);
		default: return 0;
	}
	return 1;
}

stock ClearHospitalSlot(id, slot)
{
	switch(slot)
	{
		CRATE_SET(0,Hos,1); CRATE_SET(1,Hos,2); CRATE_SET(2,Hos,3);
		CRATE_SET(3,Hos,4); CRATE_SET(4,Hos,5); CRATE_SET(5,Hos,6);
	}
	return 1;
}

stock ContainerGone(playerid)
{
	SendClientMessage(playerid, -1, ""chat" That is no longer available.");
	return 1;
}

stock bool:IsViewingTent(playerid, tentid)
{
	return tentid > 0 && tentid < MAX_TENTS && IsPlayerInRangeOfPoint(playerid, 3.5, Tent[tentid][xTent], Tent[tentid][yTent], Tent[tentid][zTent]);
}

stock bool:IsViewingStorage(playerid, vehicleid)
{
	return vehicleid > 0 && vehicleid < MAX_VEHICLES && IsPlayerInRangeOfPoint(playerid, 3.5, vInfo[vehicleid][vX], vInfo[vehicleid][vY], vInfo[vehicleid][vZ]);
}

stock GetMaxTires(playerid)
{
	if(FOUR_TIRE_ADD1(playerid) || FOUR_TIRE_ADD2(playerid)) return 4;
	if(TWO_TIRE_VEHICLE_ADD) return 2;
	if(SIX_TIRE_VEHICLE_ADD) return 6;
	return 0;
}

stock PlayRepairAnim(playerid)
{
	if(ViewId[playerid] > 0) SaveVehicleState(ViewId[playerid]);
	if(!IsPlayerInAnyVehicle(playerid))
	{
		ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.1, false, true, false, true, 1);
		SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
	}
	return 1;
}

// Moves one item from the inventory into a vehicle slot; parts and fuel are fitted instead of stored
stock StoreInVehicle(playerid, vehicleid, slot, const item[])
{
	new msg[128];
	if(!strcmp(item, "Engine", true))
	{
		if(vInfo[vehicleid][vehicleEngine] == 1) return SendClientMessage(playerid, -1, ""chat" This vehicle already has an engine!");
		RemoveSlotToInventory(playerid, item, 1);
		vInfo[vehicleid][vehicleEngine] = 1;
		return PlayRepairAnim(playerid);
	}
	if(!strcmp(item, "Tire", true) && GetMaxTires(playerid) > 0)
	{
		if(vInfo[vehicleid][vehicleTires] >= GetMaxTires(playerid)) return SendClientMessage(playerid, -1, ""chat" Vehicle already has enough tires!");
		RemoveSlotToInventory(playerid, item, 1);
		vInfo[vehicleid][vehicleTires]++;
		return PlayRepairAnim(playerid);
	}
	if(!strcmp(item, "Full Jerry Can", true))
	{
		if(vInfo[vehicleid][vehicleFuel] >= 100) return SendClientMessage(playerid, -1, ""chat" Vehicle already has enough fuel!");
		RemoveSlotToInventory(playerid, item, 1);
		vInfo[vehicleid][vehicleFuel] += random(75);
		if(vInfo[vehicleid][vehicleFuel] > 100) vInfo[vehicleid][vehicleFuel] = 100;
		AddSlotToInventoryWorld(playerid, "Empty Jerry Can", 1);
		return PlayRepairAnim(playerid);
	}
	RemoveSlotToInventory(playerid, item, 1);
	SetStorageSlot(vehicleid, slot, item);
	format(msg, sizeof(msg), ""chat" Added the item '%s' to slot %d!", item, slot + 1);
	SendClientMessage(playerid, -1, msg);
	return 1;
}

// Returns 1 when the dialog belongs to this module
stock HandleItemDialog(playerid, dialogid, response, listitem, const inputtext[])
{
	new item[64], msg[128];
	new id = ViewId[playerid];

	switch(dialogid)
	{
		case DIALOG_TENT_VIEW:
		{
			if(!response) return 1;
			pInfo[playerid][pTentLink] = listitem;
			ShowPlayerDialog(playerid, DIALOG_TENT_VIEW_S, DIALOG_STYLE_LIST, ""COL_WHITE"Viewing Tent"COL_GREEN" (16 SLOTS)", "Add Item\nTake Item", "Select", "Close");
		}
		case DIALOG_TENT_VIEW_S:
		{
			if(!IsViewingTent(playerid, id)) return ContainerGone(playerid);
			if(!response) return 1;
			if(listitem == 0) return ShowInventoryTent(playerid), 1;
			if(!GetTentSlot(id, pInfo[playerid][pTentLink], item) || !IsItemName(item)) return 1;
			if(!AddSlotToInventoryWorld(playerid, item, 1)) return 1;
			SetTentSlot(id, pInfo[playerid][pTentLink], EMPTY_SLOT);
			format(msg, sizeof(msg), ""chat" Taken item '%s' from tent storage slot %d", item, pInfo[playerid][pTentLink] + 1);
			SendClientMessage(playerid, -1, msg);
		}
		case DIALOG_TENT_VIEW_S2:
		{
			if(!response) return 1;
			if(!IsViewingTent(playerid, id)) return ContainerGone(playerid);
			new current[64];
			GetEntryItemName(inputtext, item);
			if(!IsItemName(item) || !PlayerHasItem(playerid, item)) return 1;
			if(!GetTentSlot(id, pInfo[playerid][pTentLink], current)) return 1;
			if(IsItemName(current)) return SendClientMessage(playerid, -1, ""chat" That slot is not empty!");
			RemoveSlotToInventory(playerid, item, 1);
			SetTentSlot(id, pInfo[playerid][pTentLink], item);
			format(msg, sizeof(msg), ""chat" Added the item '%s' to slot %d!", item, pInfo[playerid][pTentLink] + 1);
			SendClientMessage(playerid, -1, msg);
		}
		case DIALOG_VEHICLE_STORAGE:
		{
			if(!response) return 1;
			pInfo[playerid][pStorageLink] = listitem;
			ShowPlayerDialog(playerid, DIALOG_VEHICLE_STORAGE_S, DIALOG_STYLE_LIST, ""COL_WHITE"Vehicle Storage", "Add Item\nTake Item", "Select", "Close");
		}
		case DIALOG_VEHICLE_STORAGE_S:
		{
			if(!IsViewingStorage(playerid, id)) return ContainerGone(playerid);
			if(!response) return 1;
			if(listitem == 0) return ShowInventoryStorage(playerid), 1;
			if(pInfo[playerid][pStorageLink] >= vInfo[id][vehicleSlots]) return 1;
			if(!GetStorageSlot(id, pInfo[playerid][pStorageLink], item) || !IsItemName(item)) return 1;
			if(!AddSlotToInventoryWorld(playerid, item, 1)) return 1;
			SetStorageSlot(id, pInfo[playerid][pStorageLink], EMPTY_SLOT);
			format(msg, sizeof(msg), ""chat" Taken item '%s' from vehicle storage slot %d", item, pInfo[playerid][pStorageLink] + 1);
			SendClientMessage(playerid, -1, msg);
			PlayRepairAnim(playerid);
		}
		case DIALOG_VEHICLE_STORAGE_S2:
		{
			if(!response) return 1;
			if(!IsViewingStorage(playerid, id) || GetVehicleNearID(playerid) != id) return ContainerGone(playerid);
			new current[64];
			GetEntryItemName(inputtext, item);
			if(!IsItemName(item) || !PlayerHasItem(playerid, item)) return 1;
			if(pInfo[playerid][pStorageLink] >= vInfo[id][vehicleSlots]) return 1;
			if(!GetStorageSlot(id, pInfo[playerid][pStorageLink], current)) return 1;
			if(IsItemName(current)) return SendClientMessage(playerid, -1, ""chat" That slot is not empty!");
			StoreInVehicle(playerid, id, pInfo[playerid][pStorageLink], item);
		}
		case DIALOG_LOOTING:
		{
			if(!response) return 1;
			if(id <= 0 || Loot[id][AntiDup] != 1 || strcmp(ViewItem[playerid], Loot[id][LootName]) || !IsPlayerInRangeOfPoint(playerid, 2.3, Loot[id][xLoot], Loot[id][yLoot], Loot[id][zLoot])) return ContainerGone(playerid);
			GetEntryItemName(Loot[id][LootName], item);
			if(!AddSlotToInventoryLoot(playerid, item, 1)) return 1;
			Loot[id][AntiDup] = 0;
			DayZSA_DestroyLoot(id);
		}
		case DIALOG_LOOTING_DROP:
		{
			if(!response) return 1;
			if(id <= 0 || Loot[id][AntiDup] != 1 || strcmp(ViewItem[playerid], Loot[id][lootDrop]) || !IsPlayerInRangeOfPoint(playerid, 2.3, Loot[id][xLootdrop], Loot[id][yLootdrop], Loot[id][zLootdrop])) return ContainerGone(playerid);
			GetEntryItemName(Loot[id][lootDrop], item);
			if(!AddSlotToInventoryLoot(playerid, item, 1)) return 1;
			Loot[id][AntiDup] = 0;
			DayZSA_DestroyLootDroped(id);
		}
		case DIALOG_LOOTING_DROPZ:
		{
			if(!response) return 1;
			if(id <= 0 || Loot[id][AntiDup] != 1 || strcmp(ViewItem[playerid], Loot[id][lootDrop]) || !IsPlayerInRangeOfPoint(playerid, 2.3, Loot[id][xLootdropZ], Loot[id][yLootdropZ], Loot[id][zLootdropZ])) return ContainerGone(playerid);
			GetEntryItemName(Loot[id][lootDrop], item);
			if(!AddSlotToInventoryLoot(playerid, item, 1)) return 1;
			Loot[id][AntiDup] = 0;
			DayZSA_DestroyLootZombie(id);
		}
		case DIALOG_AIRDROP:
		{
			if(!response) return 1;
			if(id <= 0 || !IsPlayerInRangeOfPoint(playerid, 3.5, Loot[id][xAir], Loot[id][yAir], Loot[id][zAir])) return ContainerGone(playerid);
			new entry[64];
			if(!GetAirSlot(id, listitem, entry)) return 1;
			GetEntryItemName(entry, item);
			if(IsItemName(item) && AddSlotToInventoryWorld(playerid, item, 1)) ClearAirSlot(id, listitem);
		}
		case DIALOG_HOSPITAL:
		{
			if(!response) return 1;
			if(id <= 0 || !IsPlayerInRangeOfPoint(playerid, 3.5, Loot[id][xHos], Loot[id][yHos], Loot[id][zHos])) return ContainerGone(playerid);
			new entry[64];
			if(!GetHospitalSlot(id, listitem, entry)) return 1;
			GetEntryItemName(entry, item);
			if(IsItemName(item) && AddSlotToInventoryWorld(playerid, item, 1)) ClearHospitalSlot(id, listitem);
		}
		case INV_DIALOG_ID:
		{
			if(!response) return 1;
			GetEntryItemName(inputtext, item);
			if(!IsItemName(item) || !PlayerHasItem(playerid, item)) return 1;
			format(pInfo[playerid][pItemLink], 64, "%s", item);
			ShowPlayerDialog(playerid, DIALOG_INV_EDIT, DIALOG_STYLE_LIST, ""COL_GREEN"GEAR", "Use\nDrop", "Select", "Close");
		}
		case DIALOG_INV_EDIT:
		{
			if(!response) return 1;
			format(item, sizeof(item), "%s", pInfo[playerid][pItemLink]);
			if(!IsItemName(item) || !PlayerHasItem(playerid, item)) return 1;
			if(listitem == 0)
			{
				OnPlayerUseItem(playerid, item);
				GameTextForPlayer(playerid, "~n~~n~~n~~n~~n~~g~please wait......", 800, 5);
			}
			else
			{
				if(gettime() - 3 < pInfo[playerid][pSpamDrop]) return SendClientMessage(playerid, -1, "*"COL_RED" Wait 3 seconds to drop your item!");
				new Float:pos[3];
				GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
				RemoveSlotToInventory(playerid, item, 1);
				DayZSA_CreateLootsFunction(item, pos[0] + random(2), pos[1] + random(2), pos[2]);
				pInfo[playerid][pSpamDrop] = gettime();
			}
		}
		default: return 0;
	}
	return 1;
}

// Backpack usage is always derived from what is really in the inventory
stock RecountBackpack(playerid)
{
	new used;
	for(new i; i < MAX_ITEMS; i++) used += _GetItemAmountPVar(playerid, i);
	pInfo[playerid][BackpackSlotsUsed] = used;
	return used;
}

stock RemoveSlotToInventory(playerid, const addItem[], amount)
{
	new removed = RemoveItem(playerid, addItem, amount);
	RecountBackpack(playerid);
	return removed;
}

stock AddSlotToInventoryWorld(playerid, const addItem[], amount)
{
	if(RecountBackpack(playerid) + amount > pInfo[playerid][BackpackSlots])
	{
		SendClientMessage(playerid, -1, ""chat" Your backpack is full");
		return 0;
	}
	new added = AddItem(playerid, addItem, amount);
	RecountBackpack(playerid);
	return added;
}

stock AddSlotToInventoryLoot(playerid, const addItem[], amount) return AddSlotToInventoryWorld(playerid, addItem, amount);

CMD:dropgun(playerid)
{
	new WEAPON:weaponid = GetPlayerWeapon(playerid), id = FindWeaponItem(_:weaponid);
	if(id == -1) return SendClientMessage(playerid, -1, ""chat" You have no weapon you can drop");

	new Float:pos[3], msg[128], ammo = GetPlayerAmmo(playerid);
	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	RemovePlayerWeapon(playerid, weaponid);
	DayZSA_DropWeapon(ItemCatalog[id][itemName], ammo, pos[0], pos[1], pos[2]);
	format(msg, sizeof(msg), ""chat" You have dropped %s with %i ammo!", ItemCatalog[id][itemName], ammo);
	SendClientMessage(playerid, -1, msg);
	return 1;
}


CMD:pickupgun(playerid)
{
	if(IsPlayerInAnyVehicle(playerid)) return 1;
	new id = GetLootW_ID(playerid);
	if(id <= 0 || Loot[id][AntiDup] != 1) return SendClientMessage(playerid, -1, ""chat" There is no weapon here");
	new item = FindWeaponModel(Loot[id][DropGunID]);
	if(item == -1) return 1;
	// The weapon itself is picked up; no inventory copy is created
	Loot[id][AntiDup] = 0;
	GivePlayerWeaponEx(playerid, ItemCatalog[item][itemWeapon], Loot[id][DropGunAmmo]);
	DayZSA_DestroyLoot(id);
	return 1;
}


