stock PlayerToPoint(Float:radi, playerid, Float:x, Float:y, Float:z)
{
	if(IsPlayerConnected(playerid))
	{
		new Float:oldposx, Float:oldposy, Float:oldposz;
		new Float:tempposx, Float:tempposy, Float:tempposz;
		GetPlayerPos(playerid, oldposx, oldposy, oldposz);
		tempposx = (oldposx -x);
		tempposy = (oldposy -y);
		tempposz = (oldposz -z);
		if (((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi)))
		{
			return 1;
		}
	}
	return 0;
}

stock GetVehicleNearID(playerid)
{
	for(new i=0; i<MAX_VEHICLES; i++)
 	{
  		if(IsPlayerInRangeOfPoint(playerid,2.7, vInfo[i][vX],vInfo[i][vY],vInfo[i][vZ]))
    	{
     		return i;
       	}
	}
 	return 0;
}

stock GetHospitalID(playerid)
{
	for(new i=0; i<MAX_LOOTING; i++)
 	{
  		if(IsPlayerInRangeOfPoint(playerid,3.5, Loot[i][xHos],Loot[i][yHos],Loot[i][zHos]))
    	{
     		return i;
       	}
	}
 	return 0;
}

stock GetAirDropID(playerid)
{
	for(new i=0; i<MAX_LOOTING; i++)
 	{
  		if(IsPlayerInRangeOfPoint(playerid,3.5, Loot[i][xAir],Loot[i][yAir],Loot[i][zAir]))
    	{
     		return i;
       	}
	}
 	return 0;
}

stock GetTentID(playerid)
{
	for(new i=0; i<MAX_TENTS; i++)
 	{
  		if(IsPlayerInRangeOfPoint(playerid,3.5, Tent[i][xTent],Tent[i][yTent],Tent[i][zTent]))
    	{
     		return i;
       	}
	}
 	return 0;
}

stock GetCampID(playerid)
{
	for(new i=0; i<MAX_TENTS; i++)
 	{
  		if(IsPlayerInRangeOfPoint(playerid,2.1, CampFire[i][xTent],CampFire[i][yTent],CampFire[i][zTent]))
    	{
     		return i;
       	}
	}
 	return 0;
}

stock GetLootW_ID(playerid)
{
	for(new i=0; i<MAX_LOOTING; i++)
 	{
  		if(IsPlayerInRangeOfPoint(playerid,1.1, Loot[i][DropGunX],Loot[i][DropGunY],Loot[i][DropGunZ]))
    	{
     		return i;
       	}
	}
 	return 0;
}

stock GetLootID(playerid)
{
	for(new i=0; i<MAX_LOOTING; i++)
 	{
  		if(IsPlayerInRangeOfPoint(playerid,1.1, Loot[i][xLoot],Loot[i][yLoot],Loot[i][zLoot]))
    	{
     		return i;
       	}
	}
 	return 0;
}

stock GetLootIDFunction(playerid)
{
	for(new i=0; i<MAX_LOOTING; i++)
 	{
  		if(IsPlayerInRangeOfPoint(playerid,1.1,Loot[i][xLootdrop],Loot[i][yLootdrop],Loot[i][zLootdrop]))
    	{
     		return i;
       	}
	}
 	return 0;
}

stock GetLootIDZombie(playerid)
{
	for(new i=0; i<MAX_LOOTING; i++)
 	{
  		if(IsPlayerInRangeOfPoint(playerid,1.9,Loot[i][xLootdropZ],Loot[i][yLootdropZ],Loot[i][zLootdropZ]))
    	{
     		return i;
       	}
	}
 	return 0;
}

stock GetLootIDPlayer(playerid)
{
	for(new i=0; i<MAX_LOOTING; i++)
 	{
  		if(IsPlayerInRangeOfPoint(playerid,3.7, Loot[i][zLootDeadBodyX],Loot[i][zLootDeadBodyY],Loot[i][zLootDeadBodyZ]))
    	{
     		return i;
       	}
	}
 	return 0;
}

public OnPlayerCommandPerformed(playerid, cmd[], params[], result, flags)
{
	if(result == -1) { SendClientMessage(playerid, -1, ""chat" Command does not exist, to find out the server commnads type in /cmds or /help!"); }
	return 1;
}

function DayZSA_CreateAllLoots()
{
	for(new i; i < sizeof(DayZSA_Loots); i++)
	{
	    DayZSA_CreateLoots(DayZSA_Loots[i][xLoo], DayZSA_Loots[i][yLoo], DayZSA_Loots[i][zLoo]);
	}
	printf("Loaded %i Looting areas!",lootCount);

	for(new i; i < sizeof(DayZSA_Military); i++)
	{
	    DayZSA_CreateMilitaryLoots(DayZSA_Military[i][xLoo], DayZSA_Military[i][yLoo], DayZSA_Military[i][zLoo]);
	}

	for(new i; i < sizeof(DayZSA_Farms); i++)
	{
	    DayZSA_CreateFarmLoots(DayZSA_Farms[i][xLoo], DayZSA_Farms[i][yLoo], DayZSA_Farms[i][zLoo]);
	}

	for(new i; i < sizeof(DayZSA_Market); i++)
	{
		DayZSA_CreateMarketLoots(DayZSA_Market[i][xLoo], DayZSA_Market[i][yLoo], DayZSA_Market[i][zLoo]);
	}

	printf("Loaded 182 military Looting areas!");
    printf("Loaded 986 farm Looting areas!");
    printf("Loaded 434 market Looting areas!");

	DayZSA_CreateHospital(2023.5582,-1405.0769,17.1937);
    DayZSA_CreateHospital(2036.0295,-1404.5823,17.2557);
    DayZSA_CreateHospital(1179.2520,-1327.7645,14.1603);
    DayZSA_CreateHospital(1179.0232,-1319.0414,14.1490);
    DayZSA_CreateHospital(-2668.2903,636.6271,14.4531);
    DayZSA_CreateHospital(-2639.6472,636.2640,14.4531);
    DayZSA_CreateHospital(1615.5638,1817.7030,10.8203);
    DayZSA_CreateHospital(1599.5947,1817.7300,10.8203);
    DayZSA_CreateHospital(-1514.4979,2521.6721,55.8504);
    DayZSA_CreateHospital(-314.7439,1051.8927,20.3403);
    DayZSA_CreateHospital(-325.9240,1051.6086,20.3403);
    DayZSA_CreateHospital(1245.3959,326.4455,19.7555);
	DayZSA_CreateHospital(1238.7815,328.9627,19.7555);
	printf("Loaded 13 Hospitals!!");
	DayZSA_CreateAirdrop(306.42618, 2026.72473, 16.73662);
	DayZSA_CreateAirdrop(2486.3821,-1662.7250,13.3359);
	DayZSA_CreateAirdrop(-1631.7996,1419.6204,7.1875);
	printf("Loaded 3 Military Crates!!");
	return 1;
}


stock GetAdminName(playerid)
{
	new adminname[128];
	switch(pInfo[playerid][pAdminLevel])
	{
		case 0: adminname = "Not Admin";
		case 1: adminname = "Trial Moderator";
		case 2: adminname = "Moderator Team";
		case 3: adminname = "Administrator Team";
		case 4: adminname = "Support Team";
		case 5: adminname = "Management Team";
		case 6: adminname = "Developer Team";
		case 7: adminname = "Community Owner";
	}
	return adminname;
}

stock UpdatePlayer3DName(playerid)
{
	new string[256];
	/*if(pInfo[playerid][pPremium] >= 1)
	{
		format(string,sizeof(string),"%s"COL_WHITE" (%i)\n"COL_LIGHTBLUE"%s",PlayerName(playerid),playerid,GetPremiumName(playerid));
	}*/

	if(pInfo[playerid][IsPlayerInGroup] == 1)
	{
		format(string,sizeof(string),"%s"COL_WHITE" (%i)\nGroup:"COL_LIGHTBLUE" %s",PlayerName(playerid),playerid,GetPlayerGroupName(playerid));
	}

	else
	{
		format(string,sizeof(string),"%s"COL_WHITE" (%i)",PlayerName(playerid),playerid);
	}

	UpdateDynamic3DTextLabelText(PlayerLabel[playerid], 0xADFF2FAA, string);
	return 1;
}

stock CreatePlayer3DName(playerid)
{
	new string[256];
	if(pInfo[playerid][pPremium] >= 1)
	{
		format(string,sizeof(string),"%s"COL_WHITE" (%i)\n"COL_LIGHTBLUE"%s",PlayerName(playerid),playerid,GetPremiumName(playerid));
	}
	else
	{
		format(string,sizeof(string),"%s"COL_WHITE" (%i)",PlayerName(playerid),playerid);
	}
	return 1;
}

stock GetPremiumName(playerid)
{
	new premiumname[128];
	switch(pInfo[playerid][pPremium])
	{
		case 0: premiumname = "Not Premium";
		case 1: premiumname = "Premium Bronze";
		case 2: premiumname = "Premium Silver";
		case 3: premiumname = "Premium Gold";
		case 4: premiumname = "Premium Specialist";
	}
	return premiumname;
}

stock escstring(stri[])
{
	new escstr[200];
	mysql_escape_string(stri, escstr);
	return escstr;
}

stock ShowRulesToPlayer(playerid)
{
	new str[600];
	strcat(str,"1. Respect your fellow Players, Administrators, and Moderators.\n2. No offensive language is tolerated either in game\n3. Do not use any third party mod!\n\
	4. Do not argue with any staff members!\n5. Do not duplicate loots!\n6. Use common sense. If you are being an ass you will be treated like one.\n7. No Advertising\n8. Do not bunnyhop\n");
	strcat(str,"9. Do not abuse or exploit any bugs!\n10. No pausing during playing!\n11. Do not spam or flood the chat\n12. Do not C-Bug or any other SA-MP glitches!");
	ShowPlayerDialog(playerid,8618,DIALOG_STYLE_MSGBOX,"DayZ - Rules",str,"I Accept","Deny");
	return 1;
}

stock GlobalResetVars()
{
	ServerLimit[RandomMessage] = 0;
	ServerLimit[TimeCheck] = 0;
	ServerLimit[WeatherCheck] = 0;
	ServerLimit[TentRespawn] = 0;
	return 1;
}

stock CheckPlayerColor(playerid)
{
	if(GetPlayerSkin(playerid) == BANDIT)
	{
	    SetPlayerColor(playerid,COLOR_RED);
	}

	if(GetPlayerSkin(playerid) == HERO)
	{
	    SetPlayerColor(playerid,COLOR_BLUE);
	}

	if(GetPlayerSkin(playerid) == NORMAL)
	{
		SetPlayerColor(playerid,COLOR_WHITE);
	}

	if(GetPlayerSkin(playerid) == FEMALE)
	{
		SetPlayerColor(playerid,COLOR_PINK);
	}

	if(GetPlayerSkin(playerid) == CIV)
	{
		SetPlayerColor(playerid,COLOR_BROWN);
	}

	if(GetPlayerSkin(playerid) == CIVSKIN)
	{
		SetPlayerColor(playerid,0x19197000);
	}

	if(GetPlayerSkin(playerid) == SNIP)
	{
		SetPlayerColor(playerid,0xADFF2F00);
	}
	return 1;
}

stock ChangeTextdrawColor(playerid)
{
	if(pInfo[playerid][Humanity] >= 3000)
	{
 		PlayerTextDrawHide(playerid,playerBandit[playerid]);
	    PlayerTextDrawColor(playerid,playerBandit[playerid], 0x33AA3355);
		PlayerTextDrawShow(playerid,playerBandit[playerid]);
	}

	if(pInfo[playerid][Humanity] == 2500)
	{
 		PlayerTextDrawHide(playerid,playerBandit[playerid]);
	    PlayerTextDrawColor(playerid,playerBandit[playerid], 0xFFFF0055);
		PlayerTextDrawShow(playerid,playerBandit[playerid]);
	}

	if(pInfo[playerid][Humanity] <= 2000)
	{
 		PlayerTextDrawHide(playerid,playerBandit[playerid]);
	    PlayerTextDrawColor(playerid,playerBandit[playerid], 0xAA333355);
		PlayerTextDrawShow(playerid,playerBandit[playerid]);
	}

	if(pInfo[playerid][pTemp] >= 100.0)
	{
		PlayerTextDrawHide(playerid,PlayerTemp[playerid]);
	    PlayerTextDrawColor(playerid,PlayerTemp[playerid], 0x33AA3355);
		PlayerTextDrawShow(playerid,PlayerTemp[playerid]);
	}

	if(pInfo[playerid][pTemp] <= 59.0)
	{
	    PlayerTextDrawHide(playerid,PlayerTemp[playerid]);
	    PlayerTextDrawColor(playerid,PlayerTemp[playerid], 0xFFFF0055);
		PlayerTextDrawShow(playerid,PlayerTemp[playerid]);
	}

	if(pInfo[playerid][pTemp] <= 25.0)
	{
	    PlayerTextDrawHide(playerid,PlayerTemp[playerid]);
	    PlayerTextDrawColor(playerid,PlayerTemp[playerid], 0xFF450055);
		PlayerTextDrawShow(playerid,PlayerTemp[playerid]);
	}

	if(pInfo[playerid][pTemp] <= 10.0)
	{
	    PlayerTextDrawHide(playerid,PlayerTemp[playerid]);
	    PlayerTextDrawColor(playerid,PlayerTemp[playerid], 0xAA333355);
		PlayerTextDrawShow(playerid,PlayerTemp[playerid]);
	}

	if(pInfo[playerid][pBlood] >= 12000)
	{
	    PlayerTextDrawHide(playerid,PlayerBlood[playerid]);
	    PlayerTextDrawColor(playerid,PlayerBlood[playerid], 0x10F44155);
		PlayerTextDrawShow(playerid,PlayerBlood[playerid]);
	}

	if(pInfo[playerid][pBlood] <= 7500)
	{
	    PlayerTextDrawHide(playerid,PlayerBlood[playerid]);
	    PlayerTextDrawColor(playerid,PlayerBlood[playerid], 0x84E34D66);
		PlayerTextDrawShow(playerid,PlayerBlood[playerid]);
	}

	if(pInfo[playerid][pBlood] <= 5000)
	{
	    PlayerTextDrawHide(playerid,PlayerBlood[playerid]);
	    PlayerTextDrawColor(playerid,PlayerBlood[playerid], 0xFFFF0055);
		PlayerTextDrawShow(playerid,PlayerBlood[playerid]);
	}

	if(pInfo[playerid][pBlood] <= 2500)
	{
	    PlayerTextDrawHide(playerid,PlayerBlood[playerid]);
	    PlayerTextDrawColor(playerid,PlayerBlood[playerid], 0xFF450055);
		PlayerTextDrawShow(playerid,PlayerBlood[playerid]);
	}

	if(pInfo[playerid][pBlood] <= 1000)
	{
	    PlayerTextDrawHide(playerid,PlayerBlood[playerid]);
	    PlayerTextDrawColor(playerid,PlayerBlood[playerid], 0xAA333355);
		PlayerTextDrawShow(playerid,PlayerBlood[playerid]);
	}

	if(pInfo[playerid][pHunger] >= 2500)
	{
	    PlayerTextDrawHide(playerid,PlayerHunger[playerid]);
	    PlayerTextDrawColor(playerid,PlayerHunger[playerid], 0x10F44155);
		PlayerTextDrawShow(playerid,PlayerHunger[playerid]);
	}

	if(pInfo[playerid][pHunger] <= 1750)
	{
	    PlayerTextDrawHide(playerid,PlayerHunger[playerid]);
	    PlayerTextDrawColor(playerid,PlayerHunger[playerid], 0x84E34D6);
		PlayerTextDrawShow(playerid,PlayerHunger[playerid]);
	}

	if(pInfo[playerid][pHunger] <= 1200)
	{
	    PlayerTextDrawHide(playerid,PlayerHunger[playerid]);
	    PlayerTextDrawColor(playerid,PlayerHunger[playerid], 0xFFFF0055);
		PlayerTextDrawShow(playerid,PlayerHunger[playerid]);
	}

	if(pInfo[playerid][pHunger] <= 650)
	{
        PlayerTextDrawHide(playerid,PlayerHunger[playerid]);
	    PlayerTextDrawColor(playerid,PlayerHunger[playerid], 0xFF450055);
		PlayerTextDrawShow(playerid,PlayerHunger[playerid]);
	}

	if(pInfo[playerid][pHunger] <= 100)
	{
        PlayerTextDrawHide(playerid,PlayerHunger[playerid]);
	    PlayerTextDrawColor(playerid,PlayerHunger[playerid], 0xAA333355);
		PlayerTextDrawShow(playerid,PlayerHunger[playerid]);
	}

	if(pInfo[playerid][pThrist] >= 1000)
	{
	    PlayerTextDrawHide(playerid,PlayerThirst[playerid]);
	    PlayerTextDrawColor(playerid,PlayerThirst[playerid], 0x10F44155);
		PlayerTextDrawShow(playerid,PlayerThirst[playerid]);
	}

	if(pInfo[playerid][pThrist] <= 700)
	{
	    PlayerTextDrawHide(playerid,PlayerThirst[playerid]);
	    PlayerTextDrawColor(playerid,PlayerThirst[playerid], 0x84E34D66);
		PlayerTextDrawShow(playerid,PlayerThirst[playerid]);
	}

	if(pInfo[playerid][pThrist] <= 450)
	{
	    PlayerTextDrawHide(playerid,PlayerThirst[playerid]);
	    PlayerTextDrawColor(playerid,PlayerThirst[playerid], 0xFFFF0055);
		PlayerTextDrawShow(playerid,PlayerThirst[playerid]);
	}

	if(pInfo[playerid][pThrist] <= 250)
	{
	    PlayerTextDrawHide(playerid,PlayerThirst[playerid]);
	    PlayerTextDrawColor(playerid,PlayerThirst[playerid], 0xFF450055);
		PlayerTextDrawShow(playerid,PlayerThirst[playerid]);
	}

	if(pInfo[playerid][pThrist] <= 100)
	{
		PlayerTextDrawHide(playerid,PlayerThirst[playerid]);
	    PlayerTextDrawColor(playerid,PlayerThirst[playerid], 0xAA333355);
		PlayerTextDrawShow(playerid,PlayerThirst[playerid]);
	}
	return 1;
}


stock IsPlayerInZone(playerid, zone[])
{
	new TmpZone[MAX_ZONE_NAME];
	GetPlayer3DZone(playerid, TmpZone, sizeof(TmpZone));
	for(new i = 0; i != sizeof(gSAZones); i++)
	{
		if(strfind(TmpZone, zone, true) != -1)
			return 1;
	}
	return 0;
}

stock GetPlayer2DZone(playerid, zone[], len)
{
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z);
 	for(new i = 0; i != sizeof(gSAZones); i++ )
 	{
		if(x >= gSAZones[i][SAZONE_AREA][0] && x <= gSAZones[i][SAZONE_AREA][3] && y >= gSAZones[i][SAZONE_AREA][1] && y <= gSAZones[i][SAZONE_AREA][4])
		{
		    return format(zone, len, gSAZones[i][SAZONE_NAME], 0);
		}
	}
	return 0;
}

stock GetPlayer3DZone(playerid, zone[], len)
{
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z);
 	for(new i = 0; i != sizeof(gSAZones); i++ )
 	{
		if(x >= gSAZones[i][SAZONE_AREA][0] && x <= gSAZones[i][SAZONE_AREA][3] && y >= gSAZones[i][SAZONE_AREA][1] && y <= gSAZones[i][SAZONE_AREA][4] && z >= gSAZones[i][SAZONE_AREA][2] && z <= gSAZones[i][SAZONE_AREA][5])
		{
		    return format(zone, len, gSAZones[i][SAZONE_NAME], 0);
		}
	}
	return 0;
}

stock GetWeaponModel(weaponid)
{
	switch(weaponid)
	{
	    case 1:
	        return 331;

		case 2..8:
		    return weaponid+331;

        case 9:
		    return 341;

		case 10..15:
			return weaponid+311;

		case 16..18:
		    return weaponid+326;

		case 22..29:
		    return weaponid+324;

		case 30,31:
		    return weaponid+325;

		case 32:
		    return 372;

		case 33..45:
		    return weaponid+324;

		case 46:
		    return 371;
	}
	return 0;
}

function DayZSA_LootModelDropWeapon(objectname[])
{
	new dayzsaid, Float:rotx, Float:roty, Float:rotz;
    if(strfind(objectname, "Binoculars", true) != -1) dayzsaid = 3070, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "AK-47", true) != -1) dayzsaid = 355, rotx = 276.0, roty = 90.0, rotz = 90.0;
	if(strfind(objectname, "M4", true) != -1) dayzsaid = 356, rotx = 276.0, roty = 90.0, rotz = 90.0;
	if(strfind(objectname, "Silenced Pistol", true) != -1) dayzsaid =  347, rotx = 276.0, roty = 90.0, rotz = 90.0;
	if(strfind(objectname, "Pistol", true) != -1) dayzsaid = 346, rotx = 276.0, roty = 90.0, rotz = 90.0;
	if(strfind(objectname, "Shotgun", true) != -1) dayzsaid = 349, rotx = 276.0, roty = 90.0, rotz = 90.0;
	if(strfind(objectname, "SPAZ-12 Shotgun", true) != -1) dayzsaid = 351, rotx = 276.0, roty = 90.0, rotz = 90.0;
	if(strfind(objectname, "Country Rifle", true) != -1) dayzsaid = 357, rotx = 276.0, roty = 90.0, rotz = 90.0;
	if(strfind(objectname, "Sniper Rifle", true) != -1) dayzsaid = 358, rotx = 276.0, roty = 90.0, rotz = 90.0;
	if(strfind(objectname, "MP5", true) != -1) dayzsaid = 353, rotx = 276.0, roty = 90.0, rotz = 90.0;
	if(strfind(objectname, "Katana", true) != -1) dayzsaid = 339, rotx = 276.0, roty = 90.0, rotz = 90.0;
	if(strfind(objectname, "Baseball Bat", true) != -1) dayzsaid = 336, rotx = 276.0, roty = 90.0, rotz = 90.0;

	Loot[lootCount][DropGunID] = dayzsaid;
	Loot[lootCount][DropGunXR] = rotx, Loot[lootCount][DropGunYR] = roty, Loot[lootCount][DropGunZR] = rotz;
    return 1;
}

function DayZSA_LootModelDrop(objectname[])
{
	new dayzsaid, Float:rotx, Float:roty, Float:rotz;
    if(strfind(objectname, "Binoculars", true) != -1) dayzsaid = 3070, rotx = 0.0, roty = 0.0, rotz = 0.0;
    if(strfind(objectname, "Road Flare", true) != -1) dayzsaid = 1904, rotx = 0.0, roty = 0.0, rotz = 0.0;
    if(strfind(objectname, "Map", true) != -1) dayzsaid = 3017, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "GPS", true) != -1) dayzsaid = 19042, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Sniper Skin", true) != -1) dayzsaid = 1275, rotx = 272.828125, roty = 134.98297119141, rotz = 135.01782226563;
	if(strfind(objectname, "Civilian Skin", true) != -1) dayzsaid = 1275, rotx = 272.828125, roty = 134.98297119141, rotz = 135.01782226563;
	if(strfind(objectname, "Army Skin", true) != -1) dayzsaid = 1275, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Tent", true) != -1) dayzsaid = 1279, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Radio Device", true) != -1) dayzsaid = 330, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Bandage", true) != -1) dayzsaid = 1578, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Painkiller", true) != -1) dayzsaid = 1579, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Morphine", true) != -1) dayzsaid = 11736, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Medical Kit", true) != -1) dayzsaid = 11738, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Blood Bag", true) != -1) dayzsaid = 1575, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Can of Beans", true) != -1) dayzsaid = 2769, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Burger", true) != -1) dayzsaid = 2663, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Dirty Pizza Slice", true) != -1) dayzsaid = 2814, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Orange", true) != -1) dayzsaid = 19574, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Apple", true) != -1) dayzsaid = 19576, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Rum", true) != -1) dayzsaid = 1512, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Banana", true) != -1) dayzsaid = 19578, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Gin", true) != -1) dayzsaid = 19823, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Packet Of Cereals", true) != -1) dayzsaid = 19561, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Fresh Juice", true) != -1) dayzsaid = 19563, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Tomato", true) != -1) dayzsaid = 19577, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Full Water Bottle", true) != -1) dayzsaid = 2683, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Milk", true) != -1) dayzsaid = 2856, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Soda Bottle", true) != -1) dayzsaid = 2647, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Tire", true) != -1) dayzsaid = 1025, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Empty Jerry Can", true) != -1) dayzsaid = 1650, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Full Jerry Can", true) != -1) dayzsaid = 1650, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Engine", true) != -1) dayzsaid = 2891, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Toolbox", true) != -1) dayzsaid = 3052, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "AK-47", true) != -1) dayzsaid = 355, rotx = 276.0, roty = 90.0, rotz = 90.0;
	if(strfind(objectname, "M4", true) != -1) dayzsaid = 356, rotx = 276.0, roty = 90.0, rotz = 90.0;
	if(strfind(objectname, "Silenced Pistol", true) != -1) dayzsaid =  347, rotx = 276.0, roty = 90.0, rotz = 90.0;
	if(strfind(objectname, "Pistol", true) != -1) dayzsaid = 346, rotx = 276.0, roty = 90.0, rotz = 90.0;
	if(strfind(objectname, "Shotgun", true) != -1) dayzsaid = 349, rotx = 276.0, roty = 90.0, rotz = 90.0;
	if(strfind(objectname, "SPAZ-12 Shotgun", true) != -1) dayzsaid = 351, rotx = 276.0, roty = 90.0, rotz = 90.0;
	if(strfind(objectname, "Country Rifle", true) != -1) dayzsaid = 357, rotx = 276.0, roty = 90.0, rotz = 90.0;
	if(strfind(objectname, "Sniper Rifle", true) != -1) dayzsaid = 358, rotx = 276.0, roty = 90.0, rotz = 90.0;
	if(strfind(objectname, "MP5", true) != -1) dayzsaid = 353, rotx = 276.0, roty = 90.0, rotz = 90.0;
	if(strfind(objectname, "Katana", true) != -1) dayzsaid = 339, rotx = 276.0, roty = 90.0, rotz = 90.0;
	if(strfind(objectname, "Baseball Bat", true) != -1) dayzsaid = 336, rotx = 276.0, roty = 90.0, rotz = 90.0;
	if(strfind(objectname, "Pistol Ammo", true) != -1) dayzsaid = 3013, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Shotgun Ammo", true) != -1) dayzsaid = 3013, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Sniper Ammo", true) != -1) dayzsaid = 3013, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Assault Ammo", true) != -1) dayzsaid = 3013, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "SMG Ammo", true) != -1) dayzsaid = 3013, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Heat Pack", true) != -1) dayzsaid = 2058, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Heat Pack Basic", true) != -1) dayzsaid = 2058, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Whiskey Bottle", true) != -1) dayzsaid = 2683, rotx = 0.0, roty = 0.0, rotz = 0.0;
    if(strfind(objectname, "Coyote Patrol Pack", true) != -1) dayzsaid = 3026, rotx = 272.828125, roty = 45.0169677734380, rotz = 314.98205566406;
    if(strfind(objectname, "Czech Vest Pouch", true) != -1) dayzsaid = 371, rotx = 274.0, roty = 180.0, rotz = 180.0;
    if(strfind(objectname, "Alice Pack", true) != -1) dayzsaid = 1310, rotx = 271.99987792969, roty = 270.00048828125, rotz = 270.00036621094;
    if(strfind(objectname, "Coyote Backpack", true) != -1) dayzsaid = 1550, rotx = 79.237274169922, roty = 68.415649414063, rotz = 107.93438720703;
    if(strfind(objectname, "Raw Meat", true) != -1) dayzsaid =  2804, rotx = 82.7929077, roty = 236.4282684, rotz = 123.7814941;
    if(strfind(objectname, "Cooked Meat", true) != -1) dayzsaid =  2804, rotx = 82.7929077, roty = 236.4282684, rotz = 123.7814941;
    if(strfind(objectname, "Wood", true) != -1) dayzsaid = 1463, rotx = 82.7929077, roty = 236.4282684, rotz = 123.7814941;
    if(strfind(objectname, "Lighter", true) != -1) dayzsaid = 2751, rotx = 82.7929077, roty = 236.4282684, rotz = 123.7814941;
    if(strfind(objectname, "Antibiotics", true) != -1) dayzsaid = 1577, rotx = 0.0, roty = 0.0, rotz = 0.0;
	if(strfind(objectname, "Flashlight", true) != -1) dayzsaid = 18641, rotx = 82.7929077, roty = 236.4282684, rotz = 123.7814941;
    if(strfind(objectname, "Dirty Water Bottle", true) != -1) dayzsaid = 2683, rotx = 0.0, roty = 0.0, rotz = 0.0;

	Loot[lootCount][dropID] = dayzsaid;
	Loot[lootCount][dLootRotX] = rotx, Loot[lootCount][dLootRotY] = roty, Loot[lootCount][dLootRotZ] = rotz;
    return 1;
}

stock GetPlayerGroupName(playerid)
{
	new gname[24];
	format(gname,sizeof(gname),"%s",Groups[pInfo[playerid][IsPlayerInGroupID]][GroupName]);
	return gname;
}

/*DayZSA_GetSwimmingPointZ(playerid)
{
	if(IsPlayerInRangeOfPoint(playerid, 50.0, 1962.15, -1198.71, 17.45)) return 19;
	if(IsPlayerInRangeOfPoint(playerid, 100.0, -1127.58, 2764.43, 40.00)) return 43;
	if(IsPlayerInRangeOfPoint(playerid, 100.0, -988.19, 2486.89, 40.00)) return 43;
	if(IsPlayerInRangeOfPoint(playerid, 100.0, -924.33, 2306.59, 40.00)) return 43;
	if(IsPlayerInRangeOfPoint(playerid, 100.0, -1104.15, 2175.83, 40.00)) return 43;
	if(IsPlayerInRangeOfPoint(playerid, 100.0, -1307.06, 2119.33, 40.00)) return 43;
	if(IsPlayerInRangeOfPoint(playerid, 100.0, -831.85, 2122.23, 40.00)) return 43;
	if(IsPlayerInRangeOfPoint(playerid, 100.0, -595.76, 2138.34, 40.00)) return 43;
	if(IsPlayerInRangeOfPoint(playerid, 100.0, -569.24, 2274.40, 40.00)) return 43;
	if(IsPlayerInRangeOfPoint(playerid, 12.0, 1095.800, -674.950, 111.908)) return 113;
 	if(IsPlayerInRangeOfPoint(playerid, 12.0, 224.500, -1185.725, 73.908)) return 76;
  	if(IsPlayerInRangeOfPoint(playerid, 12.0, 193.700, -1230.608, 76.603)) return 79;
   	if(IsPlayerInRangeOfPoint(playerid, 12.0, 1277.500, -805.200, 86.581)) return 88;
    if(IsPlayerInRangeOfPoint(playerid, 12.0, 2582.0, 2387.0, 16.0)) return 18;
	return 10;
}*/

DayZSA_GetVehicleSpeed(vehicleid)
{
    new Float: vVel[3];
	GetVehicleVelocity(vehicleid, vVel[0], vVel[1], vVel[2]);
	return floatround(floatsqroot((vVel[0]*vVel[1]+vVel[2]*vVel[2]))*100.0*1.6);
}

stock IsPlayerNearSpawn(playerid)
{
	if(IsPlayerInRangeOfPoint(playerid, 20.0, 896.9587,2892.6489,37.5137)) return 1;
	if(IsPlayerInRangeOfPoint(playerid, 20.0, 1097.0283,2938.3865,40.1624)) return 1;
	if(IsPlayerInRangeOfPoint(playerid, 20.0, 1296.5024,2979.8425,17.4619)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, 2783.9072,614.0805,10.8984)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, 2867.5149,-341.7785,4.7310)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, -261.4227,-2167.7725,28.9799)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, 10.0890,-2541.1738,36.4986)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, 37.2395,-2711.1577,40.7622)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, -2381.2095,-2783.9360,5.2847)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, -2592.3835,-2687.4109,6.8228)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, -2686.7085,-2309.7456,9.7577)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, -2882.9514,-1170.3204,8.3407)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, -2804.3250,-916.2314,6.6717)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, -2032.6765,-1365.8677,27.9453)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, -1514.1663,-2896.9551,36.2866)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, 258.2556,2921.2253,2.4099)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, -162.6886,2890.2515,69.4884)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, -767.8674,2909.6902,36.2154)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, -1309.0072,2927.9607,73.6017)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, -2808.2583,2839.0881,207.1883)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, -2885.0125,2779.8203,230.5088)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, -2954.5725,761.5862,13.5812)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, -2929.7065,648.1838,13.3614)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, -2911.4805,-222.4231,2.5815)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, 89.4478,-1578.9141,10.5615)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, 27.8256,-1548.2875,3.6570)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, -59.0989,-1623.1260,3.4638)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, 2943.2224,-740.7009,2.0903)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, 2947.9048,-599.2261,2.6566)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, 2907.0012,-1868.3958,1.4930)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, 2910.2698,-1924.7443,1.2293)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, 2911.5835,-2061.7764,1.2522)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, 2907.9006,-2128.4133,1.6745)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, 1917.8435,-2769.5659,1.2644)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, 1709.0188,-2768.6555,1.5160)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, 1447.8463,-2768.2688,1.5921)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, 1257.2092,-2574.3057,1.3367)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, 976.4642,-1988.6869,1.5947)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 20.0, 117.9445,-1757.2789,6.6126)) return 1;
    return 0;
}

stock IsPlayerNearZombie(playerid)
{
    for(new i = 0; i < MAX_ZOMBIES; i++)
    {
        if(IsPlayerNPC(i))
        {
    		if(PlayerToPlayer(playerid, i, 50.0))
			{
	    	    return 1;
			}
		}
	}
	return 0;
}

stock PlayerToPlayer(playerid,targetid,Float:distance)
{
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid,x,y,z);
    if(IsPlayerInRangeOfPoint(targetid,distance,x,y,z))
    {
        return 1;
    }
    return 0;
}

stock DayZSA_SetPlayerNoiseLevel(playerid,level)
{
	if(level == 0)
	{
	    PlayerTextDrawHide(playerid,NoiseLevel1[playerid]);
	    PlayerTextDrawHide(playerid,NoiseLevel2[playerid]);
	    PlayerTextDrawHide(playerid,NoiseLevel3[playerid]);
	    PlayerTextDrawHide(playerid,NoiseLevel4[playerid]);
	    pInfo[playerid][IsPlayerMakingNoise] = 80;
	}

	if(level == 1)
	{
	    PlayerTextDrawHide(playerid,NoiseLevel2[playerid]);
	    PlayerTextDrawHide(playerid,NoiseLevel3[playerid]);
	    PlayerTextDrawHide(playerid,NoiseLevel4[playerid]);
		PlayerTextDrawShow(playerid,NoiseLevel1[playerid]);
		pInfo[playerid][IsPlayerMakingNoise] = 100;
	}

	if(level == 2)
	{
	    PlayerTextDrawHide(playerid,NoiseLevel3[playerid]);
	    PlayerTextDrawShow(playerid,NoiseLevel1[playerid]);
		PlayerTextDrawShow(playerid,NoiseLevel2[playerid]);
		pInfo[playerid][IsPlayerMakingNoise] = 300;
	}

	if(level == 3)
	{
 		PlayerTextDrawHide(playerid,NoiseLevel4[playerid]);
 		PlayerTextDrawShow(playerid,NoiseLevel1[playerid]);
		PlayerTextDrawShow(playerid,NoiseLevel2[playerid]);
		PlayerTextDrawShow(playerid,NoiseLevel3[playerid]);
		pInfo[playerid][IsPlayerMakingNoise] = 350;
	}

	if(level == 4)
	{
 		PlayerTextDrawShow(playerid,NoiseLevel1[playerid]);
		PlayerTextDrawShow(playerid,NoiseLevel2[playerid]);
		PlayerTextDrawShow(playerid,NoiseLevel3[playerid]);
		PlayerTextDrawShow(playerid,NoiseLevel4[playerid]);
		pInfo[playerid][IsPlayerMakingNoise] = 1000;
	}
	return 1;
}

stock DayZSA_SetPlayerEyeLevel(playerid,level)
{
	if(level == 0)
	{
	    PlayerTextDrawShow(playerid,EyeLevel1[playerid]);
	    PlayerTextDrawHide(playerid,EyeLevel2[playerid]);
	    PlayerTextDrawHide(playerid,EyeLevel3[playerid]);
	    PlayerTextDrawHide(playerid,EyeLevel4[playerid]);
	    pInfo[playerid][IsPlayerVisual] = 80;
	}

	if(level == 1)
	{
	    PlayerTextDrawHide(playerid,EyeLevel3[playerid]);
	    PlayerTextDrawHide(playerid,EyeLevel4[playerid]);
	    PlayerTextDrawShow(playerid,EyeLevel1[playerid]);
		PlayerTextDrawShow(playerid,EyeLevel2[playerid]);
		pInfo[playerid][IsPlayerVisual] = 100;
	}

	if(level == 2)
	{
	    PlayerTextDrawHide(playerid,EyeLevel4[playerid]);
	    PlayerTextDrawShow(playerid,EyeLevel1[playerid]);
		PlayerTextDrawShow(playerid,EyeLevel2[playerid]);
        PlayerTextDrawShow(playerid,EyeLevel3[playerid]);
		pInfo[playerid][IsPlayerVisual] = 200;
	}

	if(level == 3)
	{
	    PlayerTextDrawShow(playerid,EyeLevel1[playerid]);
		PlayerTextDrawShow(playerid,EyeLevel2[playerid]);
        PlayerTextDrawShow(playerid,EyeLevel3[playerid]);
		PlayerTextDrawShow(playerid,EyeLevel4[playerid]);
		pInfo[playerid][IsPlayerVisual] = 300;
	}
	return 1;
}

function ThrowFlare(playerid)
{
	new Float:pz, Float:x, Float:y, Float:z;
	GetPlayerFacingAngle(playerid, pz);
	GetPlayerPos(playerid, Float:x, Float:y, Float:z);
	GetXYInFrontOfPlayer(playerid, Float:x,Float:y, 10.0);
	RoadFlare[playerid] = CreateDynamicObject(354,Float:x,Float:y,Float:z-0.6,0.0,0.0,pz,-1,-1,-1,1000.0);
	ClearAnimations(playerid);
	return 1;
}

function VodkaStop(playerid)
{
	SetPlayerDrunkLevel(playerid,0);
	ClearAnimations(playerid);
	pInfo[playerid][IsPlayerDrunk] = 0;
	KillTimer(pInfo[playerid][IsPlayerDrunkTimer]);
	return 1;
}

stock IsPlayerNearVehicle(playerid, vehicleid, Float:distance)
{
    new m = GetVehicleModel(vehicleid);
    if(m == 0) return 0;
    new Float:x, Float:y, Float:z;
    GetVehiclePos(vehicleid, x, y, z);
    if(!IsPlayerInRangeOfPoint(playerid, distance, x, y, z)) return 0;
    return 1;
}

stock DayZSA_GetWeaponName(playerid)
{
	new wepname[64];
	switch(GetPlayerWeapon(playerid))
	{
	    case 0: wepname = "Fists";
	    case 25: wepname = "Shotgun";
	    case 30: wepname = "AK-47";
	    case 31: wepname = "M4";
	    case 34: wepname = "Sniper Rifle";
	    case 33: wepname = "Country Rifle";
	    case 22: wepname = "Pistol";
	    case 27: wepname = "SPAZ-12 Shotgun";
	    case 29: wepname = "MP5";
	    case 8: wepname = "Katana";
	    case 5: wepname = "Baseball Bat";
	    case 23: wepname = "Silenced Pistol";
	    case 43: wepname = "Binoculars";
	}
	return wepname;
}

stock DayZSA_GetVehicleName(vehicleid)
{
	new String[128];
    format(String,sizeof(String),"%s",VehicleNames[GetVehicleModel(vehicleid) - 400]);
    return String;
}

stock GetMaxZombies()
{
	return 350;
}

function GetClosestPlayer(p1)
{
    new x,Float:dis,Float:dis2,player;
    player = -1;
    dis = 99999.99;
    for (x=0;x<MAX_PLAYERS;x++) {
        if(IsPlayerConnected(x)) {
            if(x != p1) {
                dis2 = GetDistanceBetweenPlayers(x,p1);
                if(dis2 < dis && dis2 != -1.00) {
                    dis = dis2;
                    player = x;
                }
            }
        }
    }
    return player;
}

function Float:GetDistanceBetweenPlayers(p1,p2)
{
    new Float:x1,Float:y1,Float:z1,Float:x2,Float:y2,Float:z2;
    if(!IsPlayerConnected(p1) || !IsPlayerConnected(p2)) {
        return -1.00;
    }
    GetPlayerPos(p1,x1,y1,z1);
    GetPlayerPos(p2,x2,y2,z2);
    return floatsqroot(floatpower(floatabs(floatsub(x2,x1)),2)+floatpower(floatabs(floatsub(y2,y1)),2)+floatpower(floatabs(floatsub(z2,z1)),2));
}

stock GetNearest_Player(playerid, Float:distance)
{
	new Float:xX, Float:yY, Float:zZ, retElement = -1;
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
    	if((i == playerid) || (i == INVALID_PLAYER_ID)) continue;
        GetPlayerPos(i, xX, yY, zZ);
        new Float:odist = GetPlayerDistanceFromPoint(playerid, xX, yY, zZ);
        if (retElement == -1)
        {
            retElement = i;
            distance = odist;
        }
        else if (odist < distance)
        {
            retElement = i;
            distance = odist;
        }
    }
    return retElement;
}

stock IsPlayerMoving(playerid)
{
	if(GetPlayerAnimationIndex(playerid))
	{
	    new animname[32], animlib[32];
		GetAnimationName(GetPlayerAnimationIndex(playerid), animlib, sizeof(animlib), animname, sizeof(animname));
		if(!strcmp(animname, "WEAPON_CROUCH", true) || !strcmp(animname, "GUNCROUCHFWD", true))
		{
			return false;
		}
		else
		{
			new Float:Velocity[3];
    		GetPlayerVelocity(playerid, Velocity[0], Velocity[1], Velocity[2]);
    		if(Velocity[0] == 0 && Velocity[1] == 0 && Velocity[2] == 0) return false;
		}
	}
	return true;
}

stock IsPlayerSight(Float:point1[3], Float:point2[3])
{
    new Float: vector[3];
    new Float: dpoint[3];
    dpoint[0] = point2[0];
    dpoint[1] = point2[1];
    dpoint[2] = point2[2];
    new Float:konst;
    do
    {
        vector[0] = point1[0]-dpoint[0];
        vector[1] = point1[1]-dpoint[1];
        vector[2] = point1[2]-dpoint[2];
        konst = ACCURACY/floatsqroot(vector[0]*vector[0]+vector[1]*vector[1]+vector[2]*vector[2]);
        vector[0] = konst*vector[0];
        vector[1] = konst*vector[1];
        vector[2] = konst*vector[2];
        dpoint[0] = dpoint[0]+vector[0];
        dpoint[1] = dpoint[1]+vector[1];
        dpoint[2] = dpoint[2]+vector[2];
        new Float:zpoint;
        GetPointZPos(dpoint[0],dpoint[1], zpoint);
        //CreateObject(19130,dpoint[0],dpoint[1],zpoint+0.5,0.0,0.0,0.0);
        //CreateObject(19130,dpoint[0],dpoint[1],dpoint[2]+0.5,0.0,0.0,0.0);
        //printf("%.2f | %.2f",dpoint[2], zpoint);
        if(dpoint[2] < zpoint) return 0;
    }while(konst<1);
    return 1;
}

function SetWeatherEx(weatherid)
{
	SetWeather(weatherid);
	CurrentWeather = weatherid;
}


stock GetPlayerTemperature(playerid)
{
	new Float:temp = pInfo[playerid][pTemp]/100;
	return _:temp;
}

function FOUR_TIRE(playerid)
{
	if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 500 || GetVehicleModel(GetPlayerVehicleID(playerid)) == 445 || GetVehicleModel(GetPlayerVehicleID(playerid)) == 471 || GetVehicleModel(GetPlayerVehicleID(playerid)) == 604 || GetVehicleModel(GetPlayerVehicleID(playerid)) == 554) return 1;
	return 0;
}

function FOUR_TIRE2(playerid)
{
	if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 531 || GetVehicleModel(GetPlayerVehicleID(playerid)) == 418 ||GetVehicleModel(GetPlayerVehicleID(playerid)) == 542 || GetVehicleModel(GetPlayerVehicleID(playerid)) == 470 || GetVehicleModel(GetPlayerVehicleID(playerid)) == 422) return 1;
	return 0;
}

function FOUR_TIRE_ADD1(playerid)
{
	if(GetVehicleModel(GetVehicleNearID(playerid)) == 500 || GetVehicleModel(GetVehicleNearID(playerid)) == 445 || GetVehicleModel(GetVehicleNearID(playerid)) == 471 || GetVehicleModel(GetVehicleNearID(playerid)) == 604 || GetVehicleModel(GetVehicleNearID(playerid)) == 554) return 1;
	return 0;
}

function FOUR_TIRE_ADD2(playerid)
{
	if(GetVehicleModel(GetVehicleNearID(playerid)) == 531 || GetVehicleModel(GetVehicleNearID(playerid)) == 418 ||GetVehicleModel(GetVehicleNearID(playerid)) == 542 || GetVehicleModel(GetVehicleNearID(playerid)) == 470 || GetVehicleModel(GetVehicleNearID(playerid)) == 422) return 1;
	return 0;
}

