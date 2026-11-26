// ---------------------------------------------------------------------------
// Item catalogue: every item is described once, here.
// To add an item: add one row, then put its name in the loot pools it should spawn in.
// ---------------------------------------------------------------------------

#define ITEM_NAME_SIZE 24

enum
{
	ITEM_INFO,    // cannot be used directly; shows itemText
	ITEM_FOOD,
	ITEM_DRINK,
	ITEM_GUN,     // needs one box of itemAmmo to be equipped
	ITEM_AMMO,    // reloads the matching gun in hand
	ITEM_TOOL,    // melee weapons and binoculars
	ITEM_SKIN,
	ITEM_SPECIAL  // own code in UseSpecialItem
}

enum E_ITEM
{
	itemName[ITEM_NAME_SIZE],
	itemType,
	itemModel,        // object shown when the item lies on the ground
	Float:itemRotX,
	Float:itemRotY,
	Float:itemRotZ,
	itemHunger,
	itemBlood,
	itemBloodRandom,
	itemThirst,
	itemWeapon,
	itemLoadAmmo,     // ammo given when equipped
	itemAmmo[ITEM_NAME_SIZE],
	itemReloadAmmo,   // ammo given when an ammo box is used on the held gun
	bool:itemDeathDrop,
	itemSkin,
	itemText[96]      // ITEM_INFO message, or the item left after drinking
}

//  name, type, model, rotX, rotY, rotZ, hunger, blood, random blood, thirst, weapon, load, ammo item, reload, drops on death, skin, text
new const ItemCatalog[][E_ITEM] =
{
	{"Binoculars", ITEM_TOOL, 3070, 0.0, 0.0, 0.0, 0, 0, 0, 0, 43, 99, "", 0, true, 0, ""},
	{"Katana", ITEM_TOOL, 339, 276.0, 90.0, 90.0, 0, 0, 0, 0, 8, 1, "", 0, true, 0, ""},
	{"Baseball Bat", ITEM_TOOL, 336, 276.0, 90.0, 90.0, 0, 0, 0, 0, 5, 1, "", 0, true, 0, ""},
	{"AK-47", ITEM_GUN, 355, 276.0, 90.0, 90.0, 0, 0, 0, 0, 30, 35, "Assault Ammo", 28, true, 0, ""},
	{"M4", ITEM_GUN, 356, 276.0, 90.0, 90.0, 0, 0, 0, 0, 31, 60, "Assault Ammo", 25, true, 0, ""},
	{"Silenced Pistol", ITEM_GUN, 347, 276.0, 90.0, 90.0, 0, 0, 0, 0, 23, 15, "Pistol Ammo", 10, true, 0, ""},
	{"Pistol", ITEM_GUN, 346, 276.0, 90.0, 90.0, 0, 0, 0, 0, 22, 30, "Pistol Ammo", 30, true, 0, ""},
	{"Shotgun", ITEM_GUN, 349, 276.0, 90.0, 90.0, 0, 0, 0, 0, 25, 10, "Shotgun Ammo", 10, true, 0, ""},
	{"SPAZ-12 Shotgun", ITEM_GUN, 351, 276.0, 90.0, 90.0, 0, 0, 0, 0, 27, 15, "Shotgun Ammo", 15, true, 0, ""},
	{"Country Rifle", ITEM_GUN, 357, 276.0, 90.0, 90.0, 0, 0, 0, 0, 33, 10, "Sniper Ammo", 15, true, 0, ""},
	{"Sniper Rifle", ITEM_GUN, 358, 276.0, 90.0, 90.0, 0, 0, 0, 0, 34, 15, "Sniper Ammo", 10, true, 0, ""},
	{"MP5", ITEM_GUN, 353, 276.0, 90.0, 90.0, 0, 0, 0, 0, 29, 35, "SMG Ammo", 15, true, 0, ""},
	{"Pistol Ammo", ITEM_AMMO, 3013, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, "", 0, true, 0, ""},
	{"Shotgun Ammo", ITEM_AMMO, 3013, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, "", 0, true, 0, ""},
	{"Sniper Ammo", ITEM_AMMO, 3013, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, "", 0, true, 0, ""},
	{"Assault Ammo", ITEM_AMMO, 3013, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, "", 0, true, 0, ""},
	{"SMG Ammo", ITEM_AMMO, 3013, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, "", 0, true, 0, ""},
	{"Cooked Meat", ITEM_FOOD, 2804, 82.7929077, 236.4282684, 123.7814941, 1250, 2500, 0, 0, 0, 0, "", 0, true, 0, ""},
	{"Can of Beans", ITEM_FOOD, 2769, 0.0, 0.0, 0.0, 750, 0, 350, 0, 0, 0, "", 0, true, 0, ""},
	{"Burger", ITEM_FOOD, 2663, 0.0, 0.0, 0.0, 600, 0, 350, 0, 0, 0, "", 0, true, 0, ""},
	{"Dirty Pizza Slice", ITEM_FOOD, 2814, 0.0, 0.0, 0.0, 950, 0, 350, 0, 0, 0, "", 0, true, 0, ""},
	{"Orange", ITEM_FOOD, 19574, 0.0, 0.0, 0.0, 400, 0, 350, 0, 0, 0, "", 0, true, 0, ""},
	{"Apple", ITEM_FOOD, 19576, 0.0, 0.0, 0.0, 400, 0, 350, 0, 0, 0, "", 0, true, 0, ""},
	{"Banana", ITEM_FOOD, 19578, 0.0, 0.0, 0.0, 300, 0, 350, 0, 0, 0, "", 0, true, 0, ""},
	{"Tomato", ITEM_FOOD, 19577, 0.0, 0.0, 0.0, 400, 0, 350, 0, 0, 0, "", 0, true, 0, ""},
	{"Packet Of Cereals", ITEM_FOOD, 19561, 0.0, 0.0, 0.0, 290, 0, 350, 0, 0, 0, "", 0, true, 0, ""},
	{"Soda Bottle", ITEM_DRINK, 2647, 0.0, 0.0, 0.0, 0, 0, 0, 580, 0, 0, "", 0, true, 0, ""},
	{"Milk", ITEM_DRINK, 2856, 0.0, 0.0, 0.0, 0, 0, 0, 780, 0, 0, "", 0, true, 0, ""},
	{"Full Water Bottle", ITEM_DRINK, 2683, 0.0, 0.0, 0.0, 0, 0, 0, 850, 0, 0, "", 0, true, 0, "Empty Water Bottle"},
	{"Fresh Juice", ITEM_DRINK, 19563, 0.0, 0.0, 0.0, 0, 0, 0, 850, 0, 0, "", 0, true, 0, ""},
	{"Rum", ITEM_DRINK, 1512, 0.0, 0.0, 0.0, 0, 0, 0, 850, 0, 0, "", 0, true, 0, ""},
	{"Gin", ITEM_DRINK, 19823, 0.0, 0.0, 0.0, 0, 0, 0, 850, 0, 0, "", 0, true, 0, ""},
	{"Army Skin", ITEM_SKIN, 1275, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, "", 0, true, CIV, ""},
	{"Civilian Skin", ITEM_SKIN, 1275, 272.828125, 134.98297119141, 135.01782226563, 0, 0, 0, 0, 0, 0, "", 0, true, CIVSKIN, ""},
	{"Sniper Skin", ITEM_SKIN, 1275, 272.828125, 134.98297119141, 135.01782226563, 0, 0, 0, 0, 0, 0, "", 0, true, SNIP, ""},
	{"Antibiotics", ITEM_SPECIAL, 1577, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, "", 0, true, 0, ""},
	{"Wood", ITEM_SPECIAL, 1463, 82.7929077, 236.4282684, 123.7814941, 0, 0, 0, 0, 0, 0, "", 0, true, 0, ""},
	{"Lighter", ITEM_SPECIAL, 2751, 82.7929077, 236.4282684, 123.7814941, 0, 0, 0, 0, 0, 0, "", 0, true, 0, ""},
	{"Bandage", ITEM_SPECIAL, 1578, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, "", 0, true, 0, ""},
	{"Morphine", ITEM_SPECIAL, 11736, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, "", 0, true, 0, ""},
	{"Flashlight", ITEM_SPECIAL, 18641, 82.7929077, 236.4282684, 123.7814941, 0, 0, 0, 0, 0, 0, "", 0, false, 0, ""},
	{"Blood Bag", ITEM_SPECIAL, 1575, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, "", 0, true, 0, ""},
	{"Painkiller", ITEM_SPECIAL, 1579, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, "", 0, true, 0, ""},
	{"Medical Kit", ITEM_SPECIAL, 11738, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, "", 0, true, 0, ""},
	{"Road Flare", ITEM_SPECIAL, 1904, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, "", 0, true, 0, ""},
	{"Whiskey Bottle", ITEM_SPECIAL, 2683, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, "", 0, true, 0, ""},
	{"Dirty Water Bottle", ITEM_SPECIAL, 2683, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, "", 0, true, 0, ""},
	{"Toolbox", ITEM_SPECIAL, 3052, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, "", 0, true, 0, ""},
	{"GPS", ITEM_SPECIAL, 19042, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, "", 0, true, 0, ""},
	{"Tent", ITEM_SPECIAL, 1279, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, "", 0, true, 0, ""},
	{"Radio Device", ITEM_SPECIAL, 330, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, "", 0, true, 0, ""},
	{"Heat Pack", ITEM_SPECIAL, 2058, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, "", 0, true, 0, ""},
	{"Heat Pack Basic", ITEM_SPECIAL, 2058, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, "", 0, false, 0, ""},
	{"Empty Water Bottle", ITEM_INFO, 2683, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, "", 0, false, 0, "This item is not useable enter an area that is swimmable to refill the water bottle!"},
	{"Rope", ITEM_INFO, 19088, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, "", 0, false, 0, "Write /kidnap when you're near a player."},
	{"Raw Meat", ITEM_INFO, 2804, 82.7929077, 236.4282684, 123.7814941, 0, 0, 0, 0, 0, 0, "", 0, true, 0, "You cannot eat raw food. Find some wood and Lighter to cook this!"},
	{"Map", ITEM_INFO, 3017, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, "", 0, true, 0, "Press 'middle mouse button' to open/close map. A GPS unlocks the Mini-map"},
	{"Full Jerry Can", ITEM_INFO, 1650, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, "", 0, true, 0, "Add the vehicle part into the vehicle gear!"},
	{"Engine", ITEM_INFO, 2891, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, "", 0, true, 0, "Add the vehicle part into the vehicle gear!"},
	{"Tire", ITEM_INFO, 1025, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, "", 0, true, 0, "Add the vehicle part into the vehicle gear!"},
	{"Empty Jerry Can", ITEM_INFO, 1650, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, "", 0, true, 0, ""},
	{"Coyote Patrol Pack", ITEM_INFO, 3026, 272.828125, 45.0169677734380, 314.98205566406, 0, 0, 0, 0, 0, 0, "", 0, false, 0, ""},
	{"Czech Vest Pouch", ITEM_INFO, 371, 274.0, 180.0, 180.0, 0, 0, 0, 0, 0, 0, "", 0, false, 0, ""},
	{"Alice Pack", ITEM_INFO, 1310, 271.99987792969, 270.00048828125, 270.00036621094, 0, 0, 0, 0, 0, 0, "", 0, false, 0, ""},
	{"Coyote Backpack", ITEM_INFO, 1550, 79.237274169922, 68.415649414063, 107.93438720703, 0, 0, 0, 0, 0, 0, "", 0, false, 0, ""}
};

new const LootPoolMarket[][ITEM_NAME_SIZE] =
{
	"Soda Bottle", "Burger", "Whiskey Bottle", "Milk", "Dirty Pizza Slice",
	"Full Water Bottle", "Can of Beans", "Civilian Skin", "Raw Meat", "Lighter",
	"Antibiotics", "Orange", "Dirty Water Bottle", "Rope"
};

new const LootPoolFarm[][ITEM_NAME_SIZE] =
{
	"Empty Jerry Can", "Soda Bottle", "Toolbox", "Can of Beans", "Dirty Pizza Slice",
	"Full Water Bottle", "Country Rifle", "Sniper Ammo", "Alice Pack", "Burger",
	"Whiskey Bottle", "Milk", "Czech Vest Pouch", "Full Water Bottle", "Army Skin",
	"Raw Meat", "Wood", "Orange", "Flashlight", "Rope"
};

new const LootPoolLow[][ITEM_NAME_SIZE] =
{
	"Pistol Ammo", "Shotgun Ammo", "Dirty Pizza Slice", "SMG Ammo", "Empty Jerry Can",
	"Soda Bottle", "Toolbox", "Silenced Pistol", "Pistol", "Burger",
	"Full Water Bottle", "Empty Water Bottle", "Can of Beans", "Dirty Pizza Slice", "Baseball Bat",
	"Katana", "Heat Pack", "Whiskey Bottle", "Lighter", "Antibiotics",
	"Wood", "Orange", "Flashlight", "Dirty Water Bottle", "Rope"
};

new const LootPoolMedium[][ITEM_NAME_SIZE] =
{
	"MP5", "Morphine", "Bandage", "Shotgun", "Map",
	"GPS", "Milk", "Can of Beans", "Tire", "Blood Bag",
	"Country Rifle", "SPAZ-12 Shotgun", "Czech Vest Pouch", "Army Skin", "Road Flare",
	"Burger", "Full Water Bottle", "Can of Beans", "Dirty Pizza Slice", "Radio Device",
	"Civilian Skin", "Binoculars", "Antibiotics", "Heat Pack", "Sniper Rifle",
	"Orange", "Apple", "Tomato", "Banana", "Packet Of Cereals",
	"Fresh Juice", "Gin", "Rum", "Dirty Water Bottle", "Rope"
};

new const LootPoolHigh[][ITEM_NAME_SIZE] =
{
	"AK-47", "Sniper Rifle", "Medical Kit", "Engine", "Alice Pack",
	"Coyote Backpack", "Tent", "Radio Device", "Sniper Skin", "Antibiotics",
	"Heat Pack", "Rope"
};

new const LootPoolMilitary[][ITEM_NAME_SIZE] =
{
	"AK-47", "M4", "Sniper Rifle", "Sniper Ammo", "Engine",
	"Alice Pack", "Coyote Backpack", "Tent", "Radio Device", "Sniper Skin",
	"Army Skin", "Assault Ammo", "Tire", "Toolbox", "Pistol Ammo",
	"Shotgun Ammo", "Assault Ammo", "Sniper Ammo", "Dirty Pizza Slice", "SMG Ammo",
	"Full Jerry Can", "Shotgun", "Flashlight", "Rope"
};

stock FindItem(const name[])
{
	for(new i; i < sizeof(ItemCatalog); i++) if(!strcmp(ItemCatalog[i][itemName], name, true)) return i;
	return -1;
}

stock FindWeaponItem(weaponid)
{
	if(weaponid <= 0) return -1;
	for(new i; i < sizeof(ItemCatalog); i++) if(ItemCatalog[i][itemWeapon] == weaponid) return i;
	return -1;
}

stock FindWeaponModel(model)
{
	for(new i; i < sizeof(ItemCatalog); i++) if(ItemCatalog[i][itemWeapon] > 0 && ItemCatalog[i][itemModel] == model) return i;
	return -1;
}

stock SetupGroundLoot(const name[])
{
	new id = FindItem(name);
	if(id == -1) return 0;
	Loot[lootCount][ModelID] = ItemCatalog[id][itemModel];
	format(Loot[lootCount][LootName], 64, "%s", ItemCatalog[id][itemName]);
	Loot[lootCount][LootRotX] = ItemCatalog[id][itemRotX];
	Loot[lootCount][LootRotY] = ItemCatalog[id][itemRotY];
	Loot[lootCount][LootRotZ] = ItemCatalog[id][itemRotZ];
	return 1;
}

stock PlayItemAnim(playerid, const library[], const name[], bool:lockX = true)
{
	if(!IsPlayerInAnyVehicle(playerid))
	{
		ApplyAnimation(playerid, library, name, 4.1, false, lockX, false, true, 1);
		SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
	}
	return 1;
}

stock EatItem(playerid, id)
{
	if(pInfo[playerid][pHunger] >= 2350) return SendClientMessage(playerid, -1, ""chat" You are not hungry!");
	pInfo[playerid][pHunger] += ItemCatalog[id][itemHunger];
	pInfo[playerid][pBlood] += ItemCatalog[id][itemBlood];
	if(ItemCatalog[id][itemBloodRandom]) pInfo[playerid][pBlood] += random(ItemCatalog[id][itemBloodRandom]);
	RemoveSlotToInventory(playerid, ItemCatalog[id][itemName], 1);
	if(ItemCatalog[id][itemBlood]) PlayItemAnim(playerid, "FOOD", "EAT_Chicken");
	else PlayItemAnim(playerid, "FOOD", "EAT_Burger", false);
	return 1;
}

stock DrinkItem(playerid, id)
{
	if(pInfo[playerid][pThrist] >= 980) return SendClientMessage(playerid, -1, ""chat" You are not thirsty!");
	pInfo[playerid][pThrist] += ItemCatalog[id][itemThirst];
	RemoveSlotToInventory(playerid, ItemCatalog[id][itemName], 1);
	if(ItemCatalog[id][itemText][0]) AddSlotToInventoryWorld(playerid, ItemCatalog[id][itemText], 1);
	return PlayItemAnim(playerid, "VENDING", "VEND_Drink_P");
}

stock LoadGunItem(playerid, id)
{
	if(!PlayerHasItem(playerid, ItemCatalog[id][itemAmmo]))
	{
		new msg[128];
		format(msg, sizeof(msg), ""chat" You don't have any %s on you!", ItemCatalog[id][itemAmmo]);
		return SendClientMessage(playerid, -1, msg);
	}
	GivePlayerWeaponEx(playerid, ItemCatalog[id][itemWeapon], ItemCatalog[id][itemLoadAmmo]);
	RemoveSlotToInventory(playerid, ItemCatalog[id][itemName], 1);
	RemoveSlotToInventory(playerid, ItemCatalog[id][itemAmmo], 1);
	return PlayItemAnim(playerid, "RIFLE", "RIFLE_load");
}

stock UseAmmoItem(playerid, id)
{
	new gun = FindWeaponItem(_:GetPlayerWeapon(playerid)), msg[128];
	if(gun == -1 || strcmp(ItemCatalog[gun][itemAmmo], ItemCatalog[id][itemName], true) || !ItemCatalog[gun][itemAmmo][0]) return 1;
	GivePlayerWeaponEx(playerid, ItemCatalog[gun][itemWeapon], ItemCatalog[gun][itemReloadAmmo]);
	format(msg, sizeof(msg), ""chat" Added ammo to your '%s'", ItemCatalog[gun][itemName]);
	SendClientMessage(playerid, -1, msg);
	RemoveSlotToInventory(playerid, ItemCatalog[id][itemName], 1);
	return PlayItemAnim(playerid, "RIFLE", "RIFLE_load");
}
