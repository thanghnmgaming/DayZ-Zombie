// ---------------------------------------------------------------------------
// Crafting. To add a recipe, add one row.
// ---------------------------------------------------------------------------

#define DIALOG_CRAFT 5001

enum E_RECIPE
{
	rcResult[ITEM_NAME_SIZE],
	rcFirst[ITEM_NAME_SIZE],
	rcFirstAmount,
	rcSecond[ITEM_NAME_SIZE],   // "" if not needed
	rcSecondAmount,
	rcTool[ITEM_NAME_SIZE]      // must be carried, is not used up
}

new const Recipes[][E_RECIPE] =
{
	{"Bandage",         "Cloth",       2, "",      0, ""},
	{"Splint",          "Wood",        1, "Cloth", 1, ""},
	{"Heat Pack Basic", "Cloth",       1, "",      0, "Lighter"},
	{"Pistol Ammo",     "Scrap Metal", 2, "",      0, "Toolbox"},
	{"Shotgun Ammo",    "Scrap Metal", 2, "Nails", 1, "Toolbox"},
	{"Wooden Wall",     "Wood",        2, "Nails", 1, "Toolbox"},
	{"Wooden Gate",     "Wood",        2, "Nails", 2, "Toolbox"}
};

CMD:craft(playerid)
{
	if(pInfo[playerid][pLogged] != 1 || pInfo[playerid][pIsSpawned] != 1) return 1;
	new list[1024] = "Item\tNeeds\tTool\n", line[128];
	for(new i; i < sizeof(Recipes); i++)
	{
		format(line, sizeof(line), "%s\t%dx %s", Recipes[i][rcResult], Recipes[i][rcFirstAmount], Recipes[i][rcFirst]);
		strcat(list, line);
		if(Recipes[i][rcSecondAmount])
		{
			format(line, sizeof(line), ", %dx %s", Recipes[i][rcSecondAmount], Recipes[i][rcSecond]);
			strcat(list, line);
		}
		format(line, sizeof(line), "\t%s\n", Recipes[i][rcTool]);
		strcat(list, line);
	}
	ShowPlayerDialog(playerid, DIALOG_CRAFT, DIALOG_STYLE_TABLIST_HEADERS, "DayZ - Crafting", list, "Craft", "Close");
	return 1;
}

stock CraftItem(playerid, id)
{
	if((Recipes[id][rcTool][0] && !PlayerHasItem(playerid, Recipes[id][rcTool])) ||
	   PlayerHasItem(playerid, Recipes[id][rcFirst]) < Recipes[id][rcFirstAmount] ||
	   (Recipes[id][rcSecondAmount] && PlayerHasItem(playerid, Recipes[id][rcSecond]) < Recipes[id][rcSecondAmount]))
		return SendClientMessage(playerid, -1, ""chat" You are missing materials or the tool."), 0;

	// every recipe uses at least one slot of material, so the result always fits
	RemoveSlotToInventory(playerid, Recipes[id][rcFirst], Recipes[id][rcFirstAmount]);
	if(Recipes[id][rcSecondAmount]) RemoveSlotToInventory(playerid, Recipes[id][rcSecond], Recipes[id][rcSecondAmount]);
	AddSlotToInventoryWorld(playerid, Recipes[id][rcResult], 1);

	new msg[96];
	format(msg, sizeof(msg), ""chat" You crafted: %s", Recipes[id][rcResult]);
	SendClientMessage(playerid, -1, msg);
	PlayItemAnim(playerid, "BOMBER", "BOM_Plant");
	return 1;
}

stock HandleSurvivalDialog(playerid, dialogid, response, listitem)
{
	if(dialogid != DIALOG_CRAFT) return 0;
	if(response && pInfo[playerid][pLogged] == 1 && 0 <= listitem < sizeof(Recipes)) CraftItem(playerid, listitem);
	return 1;
}
