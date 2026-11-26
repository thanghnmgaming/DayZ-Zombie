stock DayZSA_SelectObj()
{
	new obj;
	switch(random(35))
	{
	    case 0: obj = 353;
	    case 1: obj = 355;
	    case 2: obj = 356;
	    case 3: obj = 358;
	    case 4: obj = 357;
	    case 5: obj = 346;
	    case 6: obj = 347;
	    case 7: obj = 349;
	    case 8: obj = 3082;
	    case 9: obj = 3082;
	    case 10: obj = 3082;
	    case 11: obj = 3082;
	    case 12: obj = 3082;
	    case 13: obj = 1579;
	    case 14: obj = 1580;
	    case 15: obj = 1578;
	    case 16: obj = 1575;
	    case 17: obj = 1576;
	    case 18: obj = 1650;
	    case 19: obj = 1650;
	    case 20: obj = 1327;
	    case 21: obj = 19130;
	    case 22: obj = 19166;
	    case 23: obj = 2683;
	    case 24: obj = 2814;
	    case 25: obj = 2703;
	    case 26: obj = 354;
	    case 27: obj = 2647;
	    case 28: obj = 2856;
	    case 29: obj = 2647;
	    case 30: obj = 2969;
	    case 31: obj = 943;
	    case 32: obj = 371;
		case 33: obj = 1310;
		case 34: obj = 1550;
	}
	return obj;
}

function DayZSA_DisplayLootFunction(playerid)
{
	ViewId[playerid] = GetLootIDFunction(playerid);
	format(ViewItem[playerid], 64, "%s", Loot[ViewId[playerid]][lootDrop]);
	new str[64];
	format(str,sizeof(str),"1\t%s",Loot[GetLootIDFunction(playerid)][lootDrop]);
	ShowPlayerDialog(playerid,DIALOG_LOOTING_DROP,DIALOG_STYLE_LIST,""COL_LIGHTBLUE"GEAR Looting",str,"Take","Close");
	return 1;
}

stock DayZSA_IsPlayerNearObject(playerid, objectid, Float:range)
{
    new Float:X, Float:Y, Float:Z;
    GetDynamicObjectPos(objectid, X, Y, Z);
    if(IsPlayerInRangeOfPoint(playerid, range, X, Y, Z))return true;
    return false;
}

stock DayZSA_GetLootNameLow()
{
	new str[128];
	switch(random(23))
	{
	    case 0: str = "Pistol Ammo";
	    case 1: str = "Shotgun Ammo";
	    case 2: str = "Assault Ammo";
	    case 3: str = "Sniper Ammo";
	    case 4: str = "Dirty Pizza Slice";
	    case 5: str = "SMG Ammo";
	    case 6: str = "Empty Jerry Can";
	    case 7: str = "Soda Bottle";
	    case 8: str = "Toolbox";
	    case 9: str = "Silenced Pistol";
	    case 10: str = "Pistol";
		case 11: str = "Burger";
		case 12: str = "Full Water Bottle";
		case 13: str = "Empty Water Bottle";
		case 14: str = "Can of Beans";
		case 15: str = "Dirty Pizza Slice";
		case 16: str = "Baseball Bat";
		case 17: str = "Katana";
		case 18: str = "Binoculars";
		case 19: str = "Heat Pack";
		case 20: str = "Orange";
		case 21: str = "Dirty Water Bottle";
		case 22: str = "Rope";
	}
	return str;
}

stock DayZSA_GetLootNameMedium()
{
	new str[128];
	switch(random(24))
	{
	    case 0: str = "MP5";
	    case 1: str = "Morphine";
	    case 2: str = "Bandage";
	    case 3: str = "Shotgun";
	    case 4: str = "Map";
	    case 5: str = "GPS";
		case 6: str = "Milk";
		case 7: str = "Can of Beans";
		case 8: str = "Tire";
		case 9: str = "Blood Bag";
		case 10: str = "Country Rifle";
		case 11: str = "SPAZ-12 Shotgun";
		case 12: str = "Czech Vest Pouch";
		case 13: str = "Army Skin";
		case 14: str = "Road Flare";
		case 15: str = "Burger";
		case 16: str = "Full Water Bottle";
		case 17: str = "Can of Beans";
		case 18: str = "Dirty Pizza Slice";
		case 19: str = "Radio Device";
		case 20: str = "Civilian Skin";
		case 21: str=  "Orange";
		case 22: str = "Dirty Water Bottle";
		case 23: str = "Rope";
	}
	return str;
}

stock DayZSA_GetLootNameHigh()
{
	new str[128];
	switch(random(11))
	{
	    case 0: str = "AK-47";
	    case 1: str = "M4";
	    case 2: str = "Sniper Rifle";
	    case 3: str = "Medical Kit";
	    case 4: str = "Engine";
	    case 5: str = "Alice Pack";
	    case 6: str = "Coyote Backpack";
	    case 7: str = "Tent";
	    case 8: str = "Radio Device";
	    case 9: str = "Sniper Skin";
	    case 10: str = "Rope";
	}
	return str;
}



function DayZSA_DisplayHospital(playerid)
{
	ViewId[playerid] = GetHospitalID(playerid);
	new str[256];
	format(str,sizeof(str),"%s\n%s\n%s\n%s\n%s\n%s",
	Loot[GetHospitalID(playerid)][HosSlot1],
	Loot[GetHospitalID(playerid)][HosSlot2],
	Loot[GetHospitalID(playerid)][HosSlot3],
	Loot[GetHospitalID(playerid)][HosSlot4],
	Loot[GetHospitalID(playerid)][HosSlot5],
	Loot[GetHospitalID(playerid)][HosSlot6]);

	ShowPlayerDialog(playerid,DIALOG_HOSPITAL,DIALOG_STYLE_LIST,""COL_WHITE"GEAR Hospital Crate"COL_GREEN" (6 SLOTS)",str,"Take","Close");
	return 1;
}

function DayZSA_DisplayAirdrop(playerid)
{
	ViewId[playerid] = GetAirDropID(playerid);
	new str[500];
	format(str,sizeof(str),"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s",
	Loot[GetAirDropID(playerid)][AirSlot1],
	Loot[GetAirDropID(playerid)][AirSlot2],
	Loot[GetAirDropID(playerid)][AirSlot3],
	Loot[GetAirDropID(playerid)][AirSlot4],
	Loot[GetAirDropID(playerid)][AirSlot5],
	Loot[GetAirDropID(playerid)][AirSlot6],
	Loot[GetAirDropID(playerid)][AirSlot7],
	Loot[GetAirDropID(playerid)][AirSlot8],
	Loot[GetAirDropID(playerid)][AirSlot9],
	Loot[GetAirDropID(playerid)][AirSlot10],
	Loot[GetAirDropID(playerid)][AirSlot11],
	Loot[GetAirDropID(playerid)][AirSlot12]);

	ShowPlayerDialog(playerid,DIALOG_AIRDROP,DIALOG_STYLE_LIST,""COL_WHITE"GEAR Military Crate"COL_GREEN" (12 SLOTS)",str,"Take","Close");
	return 1;
}

stock ShowInventoryStorage(playerid)
{
    if(!IsPlayerNPC(playerid))
    {
		gItemList="";
		for(new item;item<MAX_ITEMS;item++)
		{
			if(!strlen(_GetItemNamePVar(playerid,item))||!_GetItemAmountPVar(playerid,item))continue;
			format(gItemList,sizeof(gItemList),"%s\n%d\t\t%s",gItemList,_GetItemAmountPVar(playerid,item),_GetItemNamePVar(playerid,item));
		}
		format(gItemList,sizeof(gItemList),"%s",gItemList);
		ShowPlayerDialog(playerid,DIALOG_VEHICLE_STORAGE_S2,DIALOG_STYLE_LIST,""COL_GREEN"GEAR Vehicle Storage",gItemList,"Add Item","Close");
	}
	return 1;
}

stock ShowInventoryTent(playerid)
{
    if(!IsPlayerNPC(playerid))
    {
		gItemList="";
		for(new item;item<MAX_ITEMS;item++)
		{
			if(!strlen(_GetItemNamePVar(playerid,item))||!_GetItemAmountPVar(playerid,item))continue;
			format(gItemList,sizeof(gItemList),"%s\n%d\t\t%s",gItemList,_GetItemAmountPVar(playerid,item),_GetItemNamePVar(playerid,item));
		}
		format(gItemList,sizeof(gItemList),"%s",gItemList);
		ShowPlayerDialog(playerid,DIALOG_TENT_VIEW_S2,DIALOG_STYLE_LIST,""COL_GREEN"GEAR Viewing Tent (16 SLOTS)",gItemList,"Add Item","Close");
	}
	return 1;
}

function DayZSA_DisplayLootZombie(playerid)
{
	ViewId[playerid] = GetLootIDZombie(playerid);
	format(ViewItem[playerid], 64, "%s", Loot[ViewId[playerid]][lootDrop]);
	new str[64];
	format(str,sizeof(str),"1\t%s",Loot[GetLootIDZombie(playerid)][lootDrop]);
	ShowPlayerDialog(playerid,DIALOG_LOOTING_DROPZ,DIALOG_STYLE_LIST,""COL_LIGHTBLUE"GEAR Looting",str,"Take","Close");
	return 1;
}

function DayZSA_DisplayLootForPlayer(playerid)
{
	ViewId[playerid] = GetLootID(playerid);
	format(ViewItem[playerid], 64, "%s", Loot[ViewId[playerid]][LootName]);
	new str[64];
	format(str,sizeof(str),"1\t%s",Loot[GetLootID(playerid)][LootName]);
	ShowPlayerDialog(playerid,DIALOG_LOOTING,DIALOG_STYLE_LIST,""COL_LIGHTBLUE"GEAR Looting",str,"Take","Cancel");
	return 1;
}

function DayZSA_LootSetupMarket() return SetupGroundLoot(LootPoolMarket[random(sizeof(LootPoolMarket))]);

function DayZSA_LootSetupFarm() return SetupGroundLoot(LootPoolFarm[random(sizeof(LootPoolFarm))]);

function DayZSA_LootSetupLow() return SetupGroundLoot(LootPoolLow[random(sizeof(LootPoolLow))]);

function DayZSA_LootSetupMedium() return SetupGroundLoot(LootPoolMedium[random(sizeof(LootPoolMedium))]);

function DayZSA_LootSetupHigh() return SetupGroundLoot(LootPoolHigh[random(sizeof(LootPoolHigh))]);

function DayZSA_LootSetupMilitary() return SetupGroundLoot(LootPoolMilitary[random(sizeof(LootPoolMilitary))]);

function DayZSA_CreateVehicleStorage()
{
	new str[128];
    new Float:x, Float:y, Float:z;
    for(new i = 0; i < MAX_VEHICLES; i++)
    {
        GetVehiclePos(i, x, y, z);
        vInfo[i][vX] = x;
        vInfo[i][vY] = y;
        vInfo[i][vZ] = z;
        for(new slot; slot < MAX_VEHICLE_SLOTS; slot++) format(VehicleSlots[i][slot], 64, EMPTY_SLOT);

        new vID = GetVehicleModel(i);

        // BELOW = 1 SLOTS
        if(vID == 510 || vID == 509 || vID == 473 || vID == 471 || vID == 531)
        {
            vInfo[i][vehicleSlots] = 1;
		}

        // BELOW = 4 SLOTS
        if(vID == 453 || vID == 484 || vID == 511 || vID == 417 || vID == 445 || vID == 554 || vID == 542 || vID == 470 || vID == 422)
        {
            vInfo[i][vehicleSlots] = 4;
		}

        // BELOW = 2 SLOTS
        if(vID == 487 || vID == 468 || vID == 500 || vID == 604)
		{
            vInfo[i][vehicleSlots] = 2;
		}

		// BELOW = 6 SLOTS
		if(vID == 471 || vID == 455 || vID == 433 || vID == 418)
		{
            vInfo[i][vehicleSlots] = 6;
		}

		format(str,sizeof(str),""COL_GREEN"GEAR\n"COL_GREY" Press LEFT ALT to view vehicle gear!");
        vInfo[i][vehicleText] = CreateDynamic3DTextLabel(str, -1, x, y, z, 8.0,INVALID_PLAYER_ID, i,1,-1,-1, -1, 8.0);
       	new panelss, doorss, lightss, tiress;
		GetVehicleDamageStatus(i, panelss, doorss, lightss, tiress);
		UpdateVehicleDamageStatus(i, 5, 7, 4, 8);
		switch(random(4))
		{
			case 0: SetVehicleHealth(i,480.0), vInfo[i][vehicleFuel] = random(21), vInfo[i][vehicleEngine] = random(1), vInfo[i][vehicleTires] = random(4);
			case 1: SetVehicleHealth(i,800.0), vInfo[i][vehicleFuel] = random(21), vInfo[i][vehicleEngine] = random(1), vInfo[i][vehicleTires] = random(4);
			case 2: SetVehicleHealth(i,580.0), vInfo[i][vehicleFuel] = random(21), vInfo[i][vehicleEngine] = random(1), vInfo[i][vehicleTires] = random(4);
			case 3: SetVehicleHealth(i,400.0), vInfo[i][vehicleFuel] = random(21), vInfo[i][vehicleEngine] = random(1), vInfo[i][vehicleTires] = random(4);
		}

		if(GetVehicleModel(i) == 510 || GetVehicleModel(i) == 473)
		{
		    vInfo[i][vehicleFuel] = 99999999999999999999999999999999999999999999;
		    vInfo[i][vehicleEngine] = 1;
		    vInfo[i][vehicleTires] = 4;
		}
	}
	return 1;
}

function DayZSA_CreateHospital(Float:pXX,Float:pYX,Float:pZX)
{
	new strt[128],slot1[64],slot2[64],slot3[64],slot4[64],slot5[64],slot6[64];
	lootCount += 1;

	format(slot1,sizeof(slot1),"1\tMedical Kit");
    Loot[lootCount][HosSlot1] = slot1;
   	format(slot2,sizeof(slot2),"1\tMorphine");
    Loot[lootCount][HosSlot2] = slot2;
   	format(slot3,sizeof(slot3),"1\tBandage");
    Loot[lootCount][HosSlot3] = slot3;
   	format(slot4,sizeof(slot4),"1\tPainkiller");
    Loot[lootCount][HosSlot4] = slot4;
   	format(slot5,sizeof(slot5),"1\tBlood Bag");
    Loot[lootCount][HosSlot5] = slot5;
   	format(slot6,sizeof(slot6),"1\tAntibiotics");
    Loot[lootCount][HosSlot6] = slot6;

    Loot[lootCount][xHos] = pXX;
    Loot[lootCount][yHos] = pYX;
    Loot[lootCount][zHos] = pZX;

   	Loot[lootCount][HospitalID] = CreateDynamicObject(1685/*DayZSA_SelectObj()*/,pXX+0.3,pYX+float(1),pZX-0.7,0.0,0.0,0.0,-1,-1,-1,1000.0);
	format(strt,sizeof(strt),""COL_GREEN"GEAR\n"COL_GREY"Press LEFT ALT to view hospital crate");
    Loot[lootCount][TextID] = CreateDynamic3DTextLabel(strt,-1,pXX+0.3,pYX+float(1),pZX-0.7,8.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1,-1,-1,-1, 8.0);

    return 1;
}


function DayZSA_CreateAirdrop(Float:pXX,Float:pYX,Float:pZX)
{
	new strt[128],slot1[64],slot2[64],slot3[64],slot4[64],slot5[64],slot6[64],slot7[064],slot8[64],slot9[64],slot10[64],slot11[64],slot12[64];
	lootCount += 1;

	format(slot1,sizeof(slot1),"1\tMedical Kit");
    Loot[lootCount][AirSlot1] = slot1;
   	format(slot2,sizeof(slot2),"1\tMorphine");
    Loot[lootCount][AirSlot2] = slot2;
   	format(slot3,sizeof(slot3),"1\tM4");
    Loot[lootCount][AirSlot3] = slot3;
   	format(slot4,sizeof(slot4),"1\tSniper Rifle");
    Loot[lootCount][AirSlot4] = slot4;
   	format(slot5,sizeof(slot5),"1\tAssault Ammo");
    Loot[lootCount][AirSlot5] = slot5;
   	format(slot6,sizeof(slot6),"1\tAssault Ammo");
    Loot[lootCount][AirSlot6] = slot6;
   	format(slot7,sizeof(slot7),"1\tSniper Ammo");
    Loot[lootCount][AirSlot7] = slot7;
   	format(slot8,sizeof(slot8),"1\tSniper Ammo");
    Loot[lootCount][AirSlot8] = slot8;
   	format(slot9,sizeof(slot9),"1\tFull Water Bottle");
    Loot[lootCount][AirSlot9] = slot9;
   	format(slot10,sizeof(slot10),"1\tApple");
    Loot[lootCount][AirSlot10] = slot10;
   	format(slot11,sizeof(slot11),"1\tBlood Bag");
    Loot[lootCount][AirSlot11] = slot11;
   	format(slot12,sizeof(slot12),"1\tTent");
    Loot[lootCount][AirSlot12] = slot12;

    Loot[lootCount][xAir] = pXX;
    Loot[lootCount][yAir] = pYX;
    Loot[lootCount][zAir] = pZX;

   	Loot[lootCount][AirID] = CreateDynamicObject(3800/*DayZSA_SelectObj()*/,pXX+0.3,pYX+float(1),pZX-0.7,0.0,0.0,0.0,-1,-1,-1,1000.0);
   	SetDynamicObjectMaterial(Loot[lootCount][AirID], 0, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
	//SetDynamicObjectMaterialText(Loot[lootCount][AirID],0, "MILITARY CRATE", OBJECT_MATERIAL_SIZE_256x128,"Arial", 28, 0, 0xFFFF8200, 0xFF000000, OBJECT_MATERIAL_TEXT_ALIGN_CENTER);
	//SetDynamicObjectMaterialText(Loot[lootCount][AirID], 0, "Military Crate", 100, "Ariel", 199, 1, 0x00000000, 0x00000000, 1);
	
	format(strt,sizeof(strt),""COL_GREEN"GEAR\n"COL_GREY"Press LEFT ALT to view airdrop crate");
    CreateDynamic3DTextLabel(strt,-1,pXX+0.3,pYX+float(1),pZX-0.7,8.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1,-1,-1,-1, 8.0);

    return 1;
}


function DayZSA_CreateCampFire(playerid)
{
	new strt[128];
	campCount += 1;

	// 841 Wood
	// 18688 Fire

	static Float:px, Float:py, Float:pz, Float:pa;

	GetPlayerPos(playerid, px, py, pz);
	GetPlayerFacingAngle(playerid, pa);

	px += floatsin ( -pa,  degrees) * 1.5;
	py += floatcos ( -pa,  degrees) * 1.5;

	CampFire[campCount][xTent] = px;
	CampFire[campCount][yTent] = py;
	CampFire[campCount][zTent] = pz;

	CreateDynamicObject(18688, px, py, pz-1.47, 0.0, 0.0, 0.0, -1, -1, -1, 1000.0);
	CreateDynamicObject(19632, px, py, pz-0.7, 0.0, 0.0, 0.0, -1, -1, -1, 1000.0);
	format(strt,sizeof(strt),""COL_GREEN"GEAR\n"COL_GREY"Press LEFT ALT to cook meat!");
	CampFire[campCount][tentText] = CreateDynamic3DTextLabel(strt,-1,px,py,pz,8.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1,-1,-1,-1, 8.0);
	SendClientMessage(playerid, -1, ""chat" You have sucessfully created a camp fire!");
	RemoveSlotToInventory(playerid,"Wood",1);
	RemoveSlotToInventory(playerid,"Lighter",1);
	return 1;
}


function DayZSA_CreateLootsDeadBody(playerid,Float:pXX,Float:pYX,Float:pZX)
{
	lootCount += 1;

	Loot[lootCount][zLootDeadBodyX] = pXX;
	Loot[lootCount][zLootDeadBodyY] = pYX;
	Loot[lootCount][zLootDeadBodyZ] = pZX;

	for(new i; i < sizeof(ItemCatalog); i++)
	{
		if(ItemCatalog[i][itemDeathDrop] && PlayerHasItem(playerid, ItemCatalog[i][itemName]))
			DayZSA_CreateLootsFunction(ItemCatalog[i][itemName], pXX + random(2), pYX + random(4), pZX);
	}


	if(GetPlayerSkin(playerid) == CIVSKIN) DayZSA_CreateLootsFunction("Civilian Skin",pXX+random(7),pYX+random(3),pZX);
	if(GetPlayerSkin(playerid) == CIV) DayZSA_CreateLootsFunction("Army Skin",pXX+random(7),pYX+random(3),pZX);
	if(GetPlayerSkin(playerid) == SNIP) DayZSA_CreateLootsFunction("Sniper Skin",pXX+random(7),pYX+random(3),pZX);

	if(pInfo[playerid][Backpack] == 0) DayZSA_CreateLootsFunction("Coyote Patrol Pack",pXX+random(8),pYX+random(6),pZX);
	if(pInfo[playerid][Backpack] == 1) DayZSA_CreateLootsFunction("Czech Vest Pouch",pXX+random(2),pYX+random(4),pZX);
	if(pInfo[playerid][Backpack] == 2) DayZSA_CreateLootsFunction("Alice Pack",pXX+random(9),pYX+random(5),pZX);
	if(pInfo[playerid][Backpack] == 3) DayZSA_CreateLootsFunction("Coyote Backpack",pXX+random(6),pYX+random(3),pZX);
	return 1;
}

function DayZSA_CreateLootsFunction(const item[],Float:pXX,Float:pYX,Float:pZX)
{
	new strt[128];
	lootCount += 1;
	Loot[lootCount][xLootdrop] = pXX;
	Loot[lootCount][yLootdrop] = pYX;
	Loot[lootCount][zLootdrop] = pZX;
	Loot[lootCount][AntiDup] = 1;
	format(Loot[lootCount][lootDrop], 128, "%s", item);

	DayZSA_LootModelDrop(item);

	Loot[lootCount][LootID] = CreateDynamicObject(Loot[lootCount][dropID],pXX,pYX,pZX-0.9,Loot[lootCount][dLootRotX],Loot[lootCount][dLootRotY],Loot[lootCount][dLootRotZ],-1,-1,-1,1000.0);
	format(strt,sizeof(strt),""COL_GREEN"GEAR\n"COL_GREY"Press LEFT ALT to loot");
    Loot[lootCount][TextID] = CreateDynamic3DTextLabel(strt,-1,pXX,pYX,pZX-0.7,8.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1,-1,-1,-1, 8.0);
	return 1;
}

function DayZSA_DropWeapon(const item[], ammo, Float:pXX,Float:pYX,Float:pZX)
{
	new strt[128];
	lootCount += 1;
	Loot[lootCount][DropGunX] = pXX;
	Loot[lootCount][DropGunY] = pYX;
	Loot[lootCount][DropGunZ] = pZX;
	Loot[lootCount][DropGunAmmo] = ammo;
	Loot[lootCount][AntiDup] = 1;
	format(Loot[lootCount][lootDrop], 128, "%s", item);

	DayZSA_LootModelDropWeapon(item);

	Loot[lootCount][LootID] = CreateDynamicObject(Loot[lootCount][DropGunID],pXX,pYX,pZX-0.9,Loot[lootCount][DropGunXR],Loot[lootCount][DropGunYR],Loot[lootCount][DropGunZR],-1,-1,-1,1000.0);
	format(strt,sizeof(strt),""COL_GREEN"WEAPON GEAR\n"COL_GREY"Type /pickupgun");
    Loot[lootCount][TextID] = CreateDynamic3DTextLabel(strt,-1,pXX,pYX,pZX-0.7,8.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1,-1,-1,-1, 8.0);
	return 1;
}

function DayZSA_CreateGroup(playerid,groupname[],owner[])
{
	new str[24],gname[16];
	groupCount += 1;

	format(str,sizeof(str),"%s",owner);
	format(gname,sizeof(gname),"%s",groupname);

	Groups[groupCount][GroupID] = groupCount;
	Groups[groupCount][GroupOwner] = str;
	Groups[groupCount][GroupName] = gname;
	Groups[groupCount][GroupMembers]++;
	pInfo[playerid][IsPlayerInGroup] = 1;
	pInfo[playerid][IsPlayerGroupOwner] = 1;
	pInfo[playerid][IsPlayerInGroupID] = groupCount;

	new stra[256];
	format(stra,sizeof(stra),"*"COL_LGREEN" Player %s(%i) has created a group named %s(%i)",PlayerName(playerid),playerid, groupname, groupCount);
	SendClientMessageToAll(-1,stra);
	return 1;
}

function DayZSA_CreateFarmLoots(Float:pXX,Float:pYX,Float:pZX)
{
	new strt[128];
	lootCount += 1;
	Loot[lootCount][xLoot] = pXX;
	Loot[lootCount][yLoot] = pYX;
	Loot[lootCount][zLoot] = pZX;

    DayZSA_LootSetupFarm();

    Loot[lootCount][AntiDup] = 1;
	Loot[lootCount][LootID] = CreateDynamicObject(Loot[lootCount][ModelID],pXX,pYX,pZX-0.9,Loot[lootCount][LootRotX],Loot[lootCount][LootRotY],Loot[lootCount][LootRotZ],-1,-1,-1,1000.0);
	format(strt,sizeof(strt),""COL_GREEN"GEAR\n"COL_GREY"Press N to loot");
    Loot[lootCount][TextID] = CreateDynamic3DTextLabel(strt,-1,pXX,pYX,pZX-0.9,8.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1,-1,-1,-1, 8.0);
	return 1;
}

function DayZSA_CreateMarketLoots(Float:pXX,Float:pYX,Float:pZX)
{
	new strt[128];
	lootCount += 1;
	Loot[lootCount][xLoot] = pXX;
	Loot[lootCount][yLoot] = pYX;
	Loot[lootCount][zLoot] = pZX;

    DayZSA_LootSetupMarket();

    Loot[lootCount][AntiDup] = 1;
	Loot[lootCount][LootID] = CreateDynamicObject(Loot[lootCount][ModelID],pXX,pYX,pZX-0.9,Loot[lootCount][LootRotX],Loot[lootCount][LootRotY],Loot[lootCount][LootRotZ],-1,-1,-1,1000.0);
	format(strt,sizeof(strt),""COL_GREEN"GEAR\n"COL_GREY"Press N to loot");
    Loot[lootCount][TextID] = CreateDynamic3DTextLabel(strt,-1,pXX,pYX,pZX-0.9,8.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1,-1,-1,-1, 8.0);
	return 1;
}

function DayZSA_CreateMilitaryLoots(Float:pXX,Float:pYX,Float:pZX)
{
	new strt[128];
	lootCount += 1;
	Loot[lootCount][xLoot] = pXX;
	Loot[lootCount][yLoot] = pYX;
	Loot[lootCount][zLoot] = pZX;

    DayZSA_LootSetupMilitary();

    Loot[lootCount][AntiDup] = 1;
	Loot[lootCount][LootID] = CreateDynamicObject(Loot[lootCount][ModelID],pXX,pYX,pZX-0.9,Loot[lootCount][LootRotX],Loot[lootCount][LootRotY],Loot[lootCount][LootRotZ],-1,-1,-1,1000.0);
	format(strt,sizeof(strt),""COL_GREEN"GEAR\n"COL_GREY"Press N to loot");
    Loot[lootCount][TextID] = CreateDynamic3DTextLabel(strt,-1,pXX,pYX,pZX-0.9,8.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1,-1,-1,-1, 8.0);
	return 1;
}

function DayZSA_CreateLoots(Float:pXX,Float:pYX,Float:pZX)
{
	new strt[128];
	lootCount += 1;
	Loot[lootCount][xLoot] = pXX;
	Loot[lootCount][yLoot] = pYX;
	Loot[lootCount][zLoot] = pZX;

	switch(random(16))
	{
		case 0: DayZSA_LootSetupLow();
		case 1: DayZSA_LootSetupMedium();
		case 2: DayZSA_LootSetupHigh();
		case 3: DayZSA_LootSetupLow();
		case 4: DayZSA_LootSetupMedium();
		case 5: DayZSA_LootSetupHigh();
		case 6: DayZSA_LootSetupMedium();
		case 7: DayZSA_LootSetupHigh();
		case 8: DayZSA_LootSetupMedium();
		case 9: DayZSA_LootSetupLow();
		case 10: DayZSA_LootSetupLow();
		case 11: DayZSA_LootSetupMedium();
		case 12: DayZSA_LootSetupMedium();
		case 13: DayZSA_LootSetupLow();
		case 14: DayZSA_LootSetupMedium();
		case 15: DayZSA_LootSetupLow();
	}

    Loot[lootCount][AntiDup] = 1;
	Loot[lootCount][LootID] = CreateDynamicObject(Loot[lootCount][ModelID],pXX,pYX,pZX-0.9,Loot[lootCount][LootRotX],Loot[lootCount][LootRotY],Loot[lootCount][LootRotZ],-1,-1,-1,1000.0);
	format(strt,sizeof(strt),""COL_GREEN"GEAR\n"COL_GREY"Press N to loot");
    Loot[lootCount][TextID] = CreateDynamic3DTextLabel(strt,-1,pXX,pYX,pZX-0.9,8.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1,-1,-1,-1, 8.0);
	return 1;
}

function DayZSA_CreateLootsZombie(item[],Float:pXX,Float:pYX,Float:pZX)
{
	new strt[128];
	lootCount += 1;
	Loot[lootCount][xLootdropZ] = pXX;
	Loot[lootCount][yLootdropZ] = pYX;
	Loot[lootCount][zLootdropZ] = pZX;
	format(Loot[lootCount][lootDrop], 128, "%s", item);

	Loot[lootCount][LootID] = CreateDynamicObject(2907/*DayZSA_SelectObj()*/,pXX+0.3,pYX+float(1),pZX-0.7,0.0,0.0,0.0,-1,-1,-1,1000.0);
	format(strt,sizeof(strt),""COL_GREEN"GEAR\n"COL_GREY"Press N to loot zombie body");
    Loot[lootCount][TextID] = CreateDynamic3DTextLabel(strt,-1,pXX+0.3,pYX+float(1),pZX-0.7,8.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1,-1,-1,-1, 8.0);
	return 1;
}

function DayZSA_RespawnItems()
{
	SendClientMessageToAll(-1, ""chat""COL_RED"*** Server is backing up data this may cause lag for few seconds/minutes.");
	for(new i = 0; i < 20000; i++)
    {
   		DestroyDynamicObject(Loot[i][LootID]);
		DestroyDynamic3DTextLabel(Loot[i][TextID]);
		DestroyDynamicObject(Loot[i][HospitalID]);
		DestroyDynamicObject(Loot[i][AirID]);
		Loot[i][xLoot] = 0.0;
		Loot[i][yLoot] = 0.0;
		Loot[i][zLoot] = 0.0;
		Loot[i][DropGunX] = 0.0;
		Loot[i][DropGunY] = 0.0;
		Loot[i][DropGunZ] = 0.0;
		Loot[i][xLootdrop] = 0.0;
		Loot[i][yLootdrop] = 0.0;
		Loot[i][zLootdrop] = 0.0;
		Loot[i][xLootdropZ] = 0.0;
		Loot[i][yLootdropZ] = 0.0;
		Loot[i][zLootdropZ] = 0.0;
		Loot[i][zLootDeadBodyX] = 0.0;
		Loot[i][zLootDeadBodyY] = 0.0;
		Loot[i][zLootDeadBodyZ] = 0.0;
	    Loot[i][xHos] = 0.0;
	    Loot[i][yHos] = 0.0;
	    Loot[i][zHos] = 0.0;
	    Loot[i][xAir] = 0.0;
	    Loot[i][yAir] = 0.0;
	    Loot[i][zAir] = 0.0;

		lootCount = 0;
	}

	DayZSA_CreateAllLoots();
	foreach (new i : Player)
	{
		PlayerLabel[i] = CreateDynamic3DTextLabel("" , 0xADFF2FAA, 0.0, 0.0, 0.2, 15.0, i, INVALID_VEHICLE_ID, 1, -1, -1, -1, 100.0);
	}
	return 1;
}

CMD:lootres(playerid)
{
	if(pInfo[playerid][pAdminLevel] >= 6)
	{
		DayZSA_RespawnItems();
	}
	return 1;
}

CMD:tentres(playerid)
{
	if(pInfo[playerid][pAdminLevel] >= 6)
	{
		for(new i = 1; i < MAX_TENTS; i++) RemoveTent(i);
	}
	return 1;
}

function DayZSA_DestroyLoot(id)
{
	Loot[id][DropGunX] = 0.0;
	Loot[id][DropGunY] = 0.0;
	Loot[id][DropGunZ] = 0.0;
	DestroyDynamicObject(Loot[id][LootID]);
	DestroyDynamic3DTextLabel(Loot[id][TextID]);
	Loot[id][xLoot] = 0.0;
	Loot[id][yLoot] = 0.0;
	Loot[id][zLoot] = 0.0;
	Loot[id][xLootdrop] = 0.0;
	Loot[id][yLootdrop] = 0.0;
	Loot[id][zLootdrop] = 0.0;
	Loot[id][xLootdropZ] = 0.0;
	Loot[id][yLootdropZ] = 0.0;
	Loot[id][zLootdropZ] = 0.0;
	Loot[id][zLootDeadBodyX] = 0.0;
	Loot[id][zLootDeadBodyY] = 0.0;
	Loot[id][zLootDeadBodyZ] = 0.0;
	return 1;
}

function DayZSA_DestroyLootDroped(id)
{
	DestroyDynamicObject(Loot[id][LootID]);
	DestroyDynamic3DTextLabel(Loot[id][TextID]);
	Loot[id][xLootdrop] = 0.0;
	Loot[id][yLootdrop] = 0.0;
	Loot[id][zLootdrop] = 0.0;
	return 1;
}

function DayZSA_DestroyLootZombie(id)
{
	DestroyDynamic3DTextLabel(Loot[id][TextID]);
	Loot[id][xLootdropZ] = 0.0;
	Loot[id][yLootdropZ] = 0.0;
	Loot[id][zLootdropZ] = 0.0;
	return 1;
}


stock BuildSlotList(const slots[][], count, dest[], size)
{
	dest[0] = EOS;
	for(new i; i < count; i++)
	{
		if(i) strcat(dest, "\n", size);
		strcat(dest, slots[i], size);
	}
	return 1;
}

function DayZSA_DisplayVehicleStorage(playerid)
{
	new id = GetVehicleNearID(playerid);
	ViewId[playerid] = id;
	if(id <= 0 || vInfo[id][vehicleSlots] <= 0) return 1;

	new list[MAX_VEHICLE_SLOTS * 65], title[64];
	BuildSlotList(VehicleSlots[id], vInfo[id][vehicleSlots], list, sizeof(list));
	format(title, sizeof(title), ""COL_GREEN"GEAR Vehicle Storage (%d SLOTS)", vInfo[id][vehicleSlots]);
	ShowPlayerDialog(playerid, DIALOG_VEHICLE_STORAGE, DIALOG_STYLE_LIST, title, list, "Select", "Close");
	return 1;
}

function DayZSA_DisplayTent(playerid)
{
	new id = GetTentID(playerid);
	ViewId[playerid] = id;
	if(id <= 0) return 1;

	new list[MAX_TENT_SLOTS * 65];
	BuildSlotList(TentSlots[id], MAX_TENT_SLOTS, list, sizeof(list));
	ShowPlayerDialog(playerid, DIALOG_TENT_VIEW, DIALOG_STYLE_LIST, ""COL_WHITE"GEAR Tent"COL_GREEN" (16 SLOTS)", list, "Select", "Close");
	return 1;
}

// Places a tent object in an array slot (new tents and tents loaded from the database)
stock SpawnTent(id, const owner[], Float:x, Float:y, Float:z)
{
	Tent[id][xTent] = x;
	Tent[id][yTent] = y;
	Tent[id][zTent] = z;
	format(TentOwner[id], MAX_PLAYER_NAME, "%s", owner);
	for(new slot; slot < MAX_TENT_SLOTS; slot++) format(TentSlots[id][slot], 64, EMPTY_SLOT);
	Tent[id][TentID] = CreateDynamicObject(1336, x, y, z, 0.0, 0.0, 0.0, -1, -1, -1, 1000.0);
	SetDynamicObjectMaterial(Tent[id][TentID], 0, 2068, "cj_ammo_net", "CJ_cammonet", 0);
	Tent[id][tentText] = CreateDynamic3DTextLabel(""COL_GREEN"GEAR\n"COL_GREY"Press LEFT ALT to view tent!\nPress N to Destroy it!", -1, x, y, z, 8.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, -1, -1, -1, 8.0);
	return 1;
}

stock RemoveTent(id)
{
	if(id <= 0 || id >= MAX_TENTS || !TentOwner[id][0]) return 0;
	DestroyDynamicObject(Tent[id][TentID]);
	DestroyDynamic3DTextLabel(Tent[id][tentText]);
	Tent[id][xTent] = 0.0;
	Tent[id][yTent] = 0.0;
	Tent[id][zTent] = 0.0;
	foreach(new i : Player)
	{
		new name[MAX_PLAYER_NAME];
		GetPlayerName(i, name, sizeof(name));
		if(!strcmp(name, TentOwner[id])) pInfo[i][pTentCreated] = 0;
	}
	TentOwner[id][0] = EOS;
	DeleteTentRecord(id);
	return 1;
}

public bool:PlayerOwnsTent(playerid)
{
	new name[MAX_PLAYER_NAME];
	GetPlayerName(playerid, name, sizeof(name));
	for(new i = 1; i < MAX_TENTS; i++) if(TentOwner[i][0] && !strcmp(name, TentOwner[i])) return true;
	return false;
}

function DayZSA_CreateTent(playerid)
{
	new id = 1;
	while(id < MAX_TENTS && TentOwner[id][0]) id++;
	if(id == MAX_TENTS) return SendClientMessage(playerid, -1, ""chat" There are too many tents in the world."), 0;

	new Float:x, Float:y, Float:z, name[MAX_PLAYER_NAME];
	GetPlayerPos(playerid, x, y, z);
	GetXYInFrontOfPlayer(playerid, x, y, 3.8);
	GetPlayerName(playerid, name, sizeof(name));
	SpawnTent(id, name, x, y, z);
	SaveTent(id, name);
	pInfo[playerid][pTentCreated] = 1;
	return 1;
}
