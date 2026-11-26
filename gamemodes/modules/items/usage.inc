public OnPlayerUseItem(playerid,ItemName[])
{
    if(!PlayerHasItem(playerid, ItemName)) return 0;
    if(!IsPlayerNPC(playerid))
    {
        if(!strcmp(ItemName,"Empty Water Bottle",true))
        {
            SendClientMessage(playerid,-1,"*"COL_RED" This item is not useable enter an area that is swimmable to refill the water bottle!");
		}
  		if(!strcmp(ItemName,"Rope",true))
        {
            SendClientMessage(playerid,-1,"*"COL_RED" Write /kidnap when you're near a player.");
		}

        if(!strcmp(ItemName,"Raw Meat",true))
        {
			SendClientMessage(playerid, -1, ""chat" You cannot eat raw food. Find some wood and Lighter to cook this!");
		}

		if(!strcmp(ItemName, "Cooked Meat",true))
		{
	 	    if(pInfo[playerid][pHunger] >= 2350) return SendClientMessage(playerid,-1,""chat" You are not hungry!");
			pInfo[playerid][pHunger] += 1250;
			pInfo[playerid][pBlood] += 2500;
			RemoveSlotToInventory(playerid,"Cooked Meat",1);
			if(!IsPlayerInAnyVehicle(playerid))
			{
				ApplyAnimation(playerid, "FOOD", "EAT_Chicken",4.1,false,true,false,1000,1);
				SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
			}
		}
		if(!strcmp(ItemName,"Dirty Water Bottle",true))
	 	{
	 	    if(pInfo[playerid][pThrist] >= 98) return SendClientMessage(playerid,-1,"*"COL_GREY" You are not thirsty!");
			pInfo[playerid][pThrist] -= 30;

			RemoveSlotToInventory(playerid,"Dirty Water Bottle",1);
			SendClientMessage(playerid, COLOR_RED, "You lost thirst while drinking dirty water");
			AddSlotToInventoryWorld(playerid,"Empty Water Bottle",1);
			if(!IsPlayerInAnyVehicle(playerid))
	    	{
				ApplyAnimation(playerid, "VENDING", "VEND_Drink_P",4.1,false,true,false,1000,1);
				SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
			}
	  	}
        if(!strcmp(ItemName,"Antibiotics",true))
        {
            if(pInfo[playerid][pInfection] == 0)
            {
				SendClientMessage(playerid, -1, "*"COL_RED" You are not infected of any sort!");
			}
			else
			{
				PlayerTextDrawSetString(playerid, LegBroken[playerid], "Broken Leg");
				PlayerTextDrawHide(playerid, LegBroken[playerid]);
				SetPlayerDrunkLevel(playerid, 0);
				KillTimer(pInfo[playerid][Bleeding]);
			    SendClientMessage(playerid, -1, ""chat" You have sucessfully used antibiotics. You have been cured. If screen still dark use painkiller!");
			}
		}

        if(!strcmp(ItemName,"Wood",true))
        {
        	if(PlayerHasItem(playerid, "Lighter"))
         	{
                DayZSA_CreateCampFire(playerid);
				if(!IsPlayerInAnyVehicle(playerid))
				{
					ApplyAnimation(playerid, "BOMBER", "BOM_Plant",4.1,false,true,false,1000,1);
					SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
				}
			}
			else SendClientMessage(playerid, -1, ""chat" You need Lighter to start a camp fire!");
		}

        if(!strcmp(ItemName,"Lighter",true))
		{
        	if(PlayerHasItem(playerid, "Wood"))
         	{
                DayZSA_CreateCampFire(playerid);
       			if(!IsPlayerInAnyVehicle(playerid))
				{
					ApplyAnimation(playerid, "BOMBER", "BOM_Plant",4.1,false,true,false,1000,1);
					SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
				}
			}
			else SendClientMessage(playerid, -1, ""chat" You need some wood to start a camp fire!");
		}

		if(!strcmp(ItemName,"Bandage",true))
	 	{
	 	    if(pInfo[playerid][IsPlayerBleeding] == 0) return SendClientMessage(playerid,-1,""chat" You are not bleeding!");
			RemovePlayerAttachedObject(playerid, 2);
	 		KillTimer(pInfo[playerid][Bleeding]);
	 		pInfo[playerid][IsPlayerBleeding] = 0;
			RemoveSlotToInventory(playerid,"Bandage",1);
			if(!IsPlayerInAnyVehicle(playerid))
			{
				ApplyAnimation(playerid, "BOMBER", "BOM_Plant",4.1,false,true,false,1000,1);
				SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
			}
	  	}

		if(!strcmp(ItemName,"Morphine",true))
	 	{
	 	    if(pInfo[playerid][IsPlayerLegBroken] == 0) return SendClientMessage(playerid,-1,""chat" Your leg is not broken!");
			PlayerTextDrawHide(playerid, LegBroken[playerid]);
	    	pInfo[playerid][IsPlayerLegBroken] = 0;
			RemoveSlotToInventory(playerid,"Morphine",1);
			if(!IsPlayerInAnyVehicle(playerid))
			{
				ApplyAnimation(playerid, "BOMBER", "BOM_Plant",4.1,false,true,false,1000,1);
				SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
			}
	  	}

		if(!strcmp(ItemName,"Can of Beans",true))
	 	{
	 	    if(pInfo[playerid][pHunger] >= 2350) return SendClientMessage(playerid,-1,""chat" You are not hungry!");
			pInfo[playerid][pHunger] += 750;
			pInfo[playerid][pBlood] += random(350);
			RemoveSlotToInventory(playerid,"Can of Beans",1);
			if(!IsPlayerInAnyVehicle(playerid))
	    	{
				ApplyAnimation(playerid, "FOOD", "EAT_Burger",4.1,false,false,false,1000,1);
				SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
			}
	  	}

		if(!strcmp(ItemName,"Dirty Pizza Slice",true))
	 	{
	 	    if(pInfo[playerid][pHunger] >= 2350) return SendClientMessage(playerid,-1,""chat" You are not hungry!");
			pInfo[playerid][pHunger] += 950;
			pInfo[playerid][pBlood] += random(350);
			RemoveSlotToInventory(playerid,"Dirty Pizza Slice",1);
  			if(!IsPlayerInAnyVehicle(playerid))
	    	{
				ApplyAnimation(playerid, "FOOD", "EAT_Burger",4.1,false,false,false,1000,1);
				SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
			}
	  	}
  		if(!strcmp(ItemName,"Flashlight",true))
        {
			if(pInfo[playerid][pFlashlight] == 0)
			{
	   			if(IsPlayerAttachedObjectSlotUsed(playerid,3)) RemovePlayerAttachedObject(playerid,3);
				if(IsPlayerAttachedObjectSlotUsed(playerid,4)) RemovePlayerAttachedObject(playerid,4);
				SetPlayerAttachedObject(playerid, 3,18656, 5, 0.1, 0.038, -0.1, -90, 180, 0, 0.03, 0.03, 0.03);
				SetPlayerAttachedObject(playerid, 4,18641, 5, 0.1, 0.02, -0.05, 0, 0, 0, 1, 1, 1);
				SendClientMessage(playerid, -1, "*"COL_GREEN" Flashlight sucessfully equipped, to turn it off /flashoff");
				pInfo[playerid][pFlashlight] = 1;
			}
			else
			{
			    SendClientMessage(playerid, -1, "*"COL_RED" Flashlight is currently on to turn it off, /flashoff");
			}
		}


        if(!strcmp(ItemName,"Orange",true))
	 	{
	 	    if(pInfo[playerid][pHunger] >= 2350) return SendClientMessage(playerid,-1,""chat" You are not hungry!");
			pInfo[playerid][pHunger] += 400;
			pInfo[playerid][pBlood] += random(350);
			RemoveSlotToInventory(playerid,"Orange",1);
  			if(!IsPlayerInAnyVehicle(playerid))
	    	{
				ApplyAnimation(playerid, "FOOD", "EAT_Burger",4.1,false,false,false,1000,1);
				SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
			}
	  	}
 		if(!strcmp(ItemName,"Banana",true))
	 	{
	 	    if(pInfo[playerid][pHunger] >= 2350) return SendClientMessage(playerid,-1,""chat" You are not hungry!");
			pInfo[playerid][pHunger] += 300;
			pInfo[playerid][pBlood] += random(350);
			RemoveSlotToInventory(playerid,"Banana",1);
  			if(!IsPlayerInAnyVehicle(playerid))
	    	{
				ApplyAnimation(playerid, "FOOD", "EAT_Burger",4.1,false,false,false,1000,1);
				SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
			}
	  	}
  		if(!strcmp(ItemName,"Tomato",true))
	 	{
	 	    if(pInfo[playerid][pHunger] >= 2350) return SendClientMessage(playerid,-1,""chat" You are not hungry!");
			pInfo[playerid][pHunger] += 400;
			pInfo[playerid][pBlood] += random(350);
			RemoveSlotToInventory(playerid,"Tomato",1);
  			if(!IsPlayerInAnyVehicle(playerid))
	    	{
				ApplyAnimation(playerid, "FOOD", "EAT_Burger",4.1,false,false,false,1000,1);
				SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
			}
	  	}
	  	if(!strcmp(ItemName,"Apple",true))
	 	{
	 	    if(pInfo[playerid][pHunger] >= 2350) return SendClientMessage(playerid,-1,""chat" You are not hungry!");
			pInfo[playerid][pHunger] += 400;
			pInfo[playerid][pBlood] += random(350);
			RemoveSlotToInventory(playerid,"Apple",1);
  			if(!IsPlayerInAnyVehicle(playerid))
	    	{
				ApplyAnimation(playerid, "FOOD", "EAT_Burger",4.1,false,false,false,1000,1);
				SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
			}
	  	}
	  	if(!strcmp(ItemName,"Packet Of Cereals",true))
	 	{
	 	    if(pInfo[playerid][pHunger] >= 2350) return SendClientMessage(playerid,-1,""chat" You are not hungry!");
			pInfo[playerid][pHunger] += 290;
			pInfo[playerid][pBlood] += random(350);
			RemoveSlotToInventory(playerid,"Packet Of Cereals",1);
  			if(!IsPlayerInAnyVehicle(playerid))
	    	{
				ApplyAnimation(playerid, "FOOD", "EAT_Burger",4.1,false,false,false,1000,1);
				SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
			}
	  	}
		if(!strcmp(ItemName,"Burger",true))
	 	{
	 	    if(pInfo[playerid][pHunger] >= 2350) return SendClientMessage(playerid,-1,""chat" You are not hungry!");
			pInfo[playerid][pHunger] += 600;
			pInfo[playerid][pBlood] += random(350);
			RemoveSlotToInventory(playerid,"Burger",1);
			if(!IsPlayerInAnyVehicle(playerid))
	    	{
				ApplyAnimation(playerid, "FOOD", "EAT_Burger",4.1,false,false,false,1000,1);
				SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
			}
	  	}

		if(!strcmp(ItemName,"Blood Bag",true))
	 	{
	 	    if(pInfo[playerid][pBlood] == 12000) return SendClientMessage(playerid,-1,""chat" You already have enough blood injected!");
			pInfo[playerid][pBlood] = 12000;
			RemoveSlotToInventory(playerid,"Blood Bag",1);
			if(!IsPlayerInAnyVehicle(playerid))
			{
				ApplyAnimation(playerid, "BOMBER", "BOM_Plant",4.1,false,true,false,1000,1);
				SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
			}
	  	}

		if(!strcmp(ItemName,"Painkiller",true))
	 	{
	 	    if(pInfo[playerid][IsPlayerDrunk] == 1)
	 	    {
				SetPlayerDrunkLevel(playerid,0);
			}

			if(pInfo[playerid][pFade] == 1)
			{
  				PlayerTextDrawHide(playerid, PlayerFade[playerid]);
				pInfo[playerid][pFade] = -1;
			}
			RemoveSlotToInventory(playerid,"Painkiller",1);
			if(!IsPlayerInAnyVehicle(playerid))
			{
				ApplyAnimation(playerid, "BOMBER", "BOM_Plant",4.1,false,true,false,1000,1);
				SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
			}
	  	}

		if(!strcmp(ItemName,"Medical Kit",true))
	 	{
			pInfo[playerid][pBlood] = 12000;
			SetPlayerDrunkLevel(playerid,0);
			if(pInfo[playerid][IsPlayerLegBroken] == 1)
			{
				PlayerTextDrawHide(playerid, LegBroken[playerid]);
	    		pInfo[playerid][IsPlayerLegBroken] = 0;
			}

			if(pInfo[playerid][IsPlayerBleeding] == 1)
			{
				RemovePlayerAttachedObject(playerid, 2);
		 		KillTimer(pInfo[playerid][Bleeding]);
		 		pInfo[playerid][IsPlayerBleeding] = 0;
			}
			RemoveSlotToInventory(playerid,"Medical Kit",1);
			if(!IsPlayerInAnyVehicle(playerid))
			{
				ApplyAnimation(playerid, "BOMBER", "BOM_Plant",4.1,false,true,false,1000,1);
				SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
			}
	  	}

	  	if(!strcmp(ItemName,"Road Flare",true))
	  	{
			//ApplyAnimation(playerid,"GRENADE","WEAPON_throwu",4.0,false,true,true,false,1,1);
			ApplyAnimation(playerid, "GRENADE", "WEAPON_throw", 4.5, false, true, true, true, 1, 1);
			SetTimerEx("ThrowFlare",4000,false,"i",playerid);
			SetTimerEx("DestroyRoadFlare",480000,false,"i",playerid);
			RemoveSlotToInventory(playerid,"Road Flare",1);
		}

		if(!strcmp(ItemName,"Whiskey Bottle",true))
		{
		    if(pInfo[playerid][IsPlayerDrunk] == 0)
		    {
		    	KillTimer(pInfo[playerid][IsPlayerDrunkTimer]);
		    	pInfo[playerid][IsPlayerDrunkTimer] = SetTimerEx("VodkaStop",60000,false,"i",playerid);
				SetPlayerDrunkLevel(playerid,8000);
				pInfo[playerid][IsPlayerDrunk] = 1;
            	//ApplyAnimation(playerid,"PED","WALK_DRUNK",4.0,true,true,true,true,1);
            	ApplyAnimation(playerid, "PED", "WALK_DRUNK", 4.0, true, true, true, true, 1, 1);
            	pInfo[playerid][pThrist] += 800;
            	pInfo[playerid][pBlood] += 800;
            	RemoveSlotToInventory(playerid,"Whiskey Bottle",1);
			}
			else return SendClientMessage(playerid,-1,"*"COL_RED" No just no.");
		}

		if(!strcmp(ItemName,"Soda Bottle",true))
	 	{
	 	    if(pInfo[playerid][pThrist] >= 980) return SendClientMessage(playerid,-1,""chat" You are not thirsty!");
			pInfo[playerid][pThrist] += 580;
			RemoveSlotToInventory(playerid,"Soda Bottle",1);
			if(!IsPlayerInAnyVehicle(playerid))
	    	{
				ApplyAnimation(playerid, "VENDING", "VEND_Drink_P",4.1,false,true,false,1000,1);
				SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
			}
	  	}

		if(!strcmp(ItemName,"Milk",true))
	 	{
	 	    if(pInfo[playerid][pThrist] >= 980) return SendClientMessage(playerid,-1,""chat" You are not thirsty!");
			pInfo[playerid][pThrist] += 780;
			RemoveSlotToInventory(playerid,"Milk",1);
	  	}

		if(!strcmp(ItemName,"Full Water Bottle",true))
	 	{
	 	    if(pInfo[playerid][pThrist] >= 980) return SendClientMessage(playerid,-1,""chat" You are not thirsty!");
			pInfo[playerid][pThrist] += 850;
			RemoveSlotToInventory(playerid,"Full Water Bottle",1);
			AddSlotToInventoryWorld(playerid,"Empty Water Bottle",1);
			if(!IsPlayerInAnyVehicle(playerid))
	    	{
				ApplyAnimation(playerid, "VENDING", "VEND_Drink_P",4.1,false,true,false,1000,1);
				SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
			}
	  	}
	    if(!strcmp(ItemName,"Fresh Juice",true))
	 	{
	 	    if(pInfo[playerid][pThrist] >= 980) return SendClientMessage(playerid,-1,""chat" You are not thirsty!");
			pInfo[playerid][pThrist] += 850;
			RemoveSlotToInventory(playerid,"Fresh Juice",1);
			if(!IsPlayerInAnyVehicle(playerid))
	    	{
				ApplyAnimation(playerid, "VENDING", "VEND_Drink_P",4.1,false,true,false,1000,1);
				SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
			}
	  	}
		if(!strcmp(ItemName,"Rum",true))
	 	{
	 	    if(pInfo[playerid][pThrist] >= 980) return SendClientMessage(playerid,-1,""chat" You are not thirsty!");
			pInfo[playerid][pThrist] += 850;
			RemoveSlotToInventory(playerid,"Rum",1);
			if(!IsPlayerInAnyVehicle(playerid))
	    	{
				ApplyAnimation(playerid, "VENDING", "VEND_Drink_P",4.1,false,true,false,1000,1);
				SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
			}
	  	}
		if(!strcmp(ItemName,"Gin",true))
	 	{
	 	    if(pInfo[playerid][pThrist] >= 980) return SendClientMessage(playerid,-1,""chat" You are not thirsty!");
			pInfo[playerid][pThrist] += 850;
			RemoveSlotToInventory(playerid,"Gin",1);
			if(!IsPlayerInAnyVehicle(playerid))
	    	{
				ApplyAnimation(playerid, "VENDING", "VEND_Drink_P",4.1,false,true,false,1000,1);
				SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
			}
	  	}

	  	if(!strcmp(ItemName,"SPAZ-12 Shotgun",true))
	 	{
			if(PlayerHasItem(playerid,"Shotgun Ammo"))
			{
				GivePlayerWeaponEx(playerid, 27, 15);
				RemoveSlotToInventory(playerid,"SPAZ-12 Shotgun",1);
				RemoveSlotToInventory(playerid,"Shotgun Ammo",1);
				if(!IsPlayerInAnyVehicle(playerid))
		    	{
					ApplyAnimation(playerid, "RIFLE", "RIFLE_load",4.1,false,true,false,1000,1);
					SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
				}
			}
			else return SendClientMessage(playerid,-1,""chat" You don't have any shotgun ammo on you!");
		}

	  	if(!strcmp(ItemName,"Pistol",true))
	 	{
	 	    if(PlayerHasItem(playerid,"Pistol Ammo"))
	 	    {
				GivePlayerWeaponEx(playerid, 22, 30);
				RemoveSlotToInventory(playerid,"Pistol",1);
				RemoveSlotToInventory(playerid,"Pistol Ammo",1);
				if(!IsPlayerInAnyVehicle(playerid))
		    	{
					ApplyAnimation(playerid, "RIFLE", "RIFLE_load",4.1,false,true,false,1000,1);
					SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
				}
			}
			else return SendClientMessage(playerid,-1,""chat" You don't have any pistol ammo on you!");
	  	}

		if(!strcmp(ItemName,"AK-47",true))
	 	{
			if(PlayerHasItem(playerid,"Assault Ammo"))
			{
				GivePlayerWeaponEx(playerid, 30, 35);
				RemoveSlotToInventory(playerid,"AK-47",1);
				RemoveSlotToInventory(playerid,"Assault Ammo",1);
				if(!IsPlayerInAnyVehicle(playerid))
		    	{
					ApplyAnimation(playerid, "RIFLE", "RIFLE_load",4.1,false,true,false,1000,1);
					SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
				}
			}
			else return SendClientMessage(playerid,-1,""chat" You don't have any assault ammo on you!");
	  	}

		if(!strcmp(ItemName,"M4",true))
	 	{
			if(PlayerHasItem(playerid,"Assault Ammo"))
			{
				GivePlayerWeaponEx(playerid, 31,60);
				RemoveSlotToInventory(playerid,"M4",1);
				RemoveSlotToInventory(playerid,"Assault Ammo",1);
				if(!IsPlayerInAnyVehicle(playerid))
		    	{
					ApplyAnimation(playerid, "RIFLE", "RIFLE_load",4.1,false,true,false,1000,1);
					SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
				}
			}
			else return SendClientMessage(playerid,-1,""chat" You don't have any assault ammo on you!");
		}

		if(!strcmp(ItemName,"Sniper Rifle",true))
	 	{
			if(PlayerHasItem(playerid,"Sniper Ammo"))
			{
				GivePlayerWeaponEx(playerid, 34, 15);
				RemoveSlotToInventory(playerid,"Sniper Rifle",1);
				RemoveSlotToInventory(playerid,"Sniper Ammo",1);
				if(!IsPlayerInAnyVehicle(playerid))
		    	{
					ApplyAnimation(playerid, "RIFLE", "RIFLE_load",4.1,false,true,false,1000,1);
					SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
				}
			}
			else return SendClientMessage(playerid,-1,""chat" You don't have any sniper ammo on you!");
		}

		if(!strcmp(ItemName,"Country Rifle",true))
	 	{
			if(PlayerHasItem(playerid,"Sniper Ammo"))
			{
				GivePlayerWeaponEx(playerid, 33, 10);
				RemoveSlotToInventory(playerid,"Country Rifle",1);
				RemoveSlotToInventory(playerid,"Sniper Ammo",1);
 				if(!IsPlayerInAnyVehicle(playerid))
		    	{
					ApplyAnimation(playerid, "RIFLE", "RIFLE_load",4.1,false,true,false,1000,1);
					SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
				}
			}
			else return SendClientMessage(playerid,-1,""chat" You don't have any sniper ammo on you!");
		}

		if(!strcmp(ItemName,"Shotgun",true))
	 	{
	 	    if(PlayerHasItem(playerid,"Shotgun Ammo"))
	 	    {
				GivePlayerWeaponEx(playerid, 25, 10);
				RemoveSlotToInventory(playerid,"Shotgun",1);
				RemoveSlotToInventory(playerid,"Shotgun Ammo",1);
 				if(!IsPlayerInAnyVehicle(playerid))
		    	{
					ApplyAnimation(playerid, "RIFLE", "RIFLE_load",4.1,false,true,false,1000,1);
					SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
				}
			}
			else return SendClientMessage(playerid,-1,""chat" You don't have any shotgun ammo on you!");
	  	}

		if(!strcmp(ItemName,"MP5",true))
	 	{
			if(PlayerHasItem(playerid,"SMG Ammo"))
			{
				GivePlayerWeaponEx(playerid, 29, 35);
				RemoveSlotToInventory(playerid,"MP5",1);
				RemoveSlotToInventory(playerid,"SMG Ammo",1);
				if(!IsPlayerInAnyVehicle(playerid))
		    	{
					ApplyAnimation(playerid, "RIFLE", "RIFLE_load",4.1,false,true,false,1000,1);
					SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
				}
			}
			else return SendClientMessage(playerid,-1,""chat" You don't have any SMG ammo on you!");
	  	}

		if(!strcmp(ItemName,"Silenced Pistol",true))
		{
			if(PlayerHasItem(playerid,"Pistol Ammo"))
			{
				GivePlayerWeaponEx(playerid, 23, 15);
				RemoveSlotToInventory(playerid,"Silenced Pistol",1);
				RemoveSlotToInventory(playerid,"Pistol Ammo",1);
				if(!IsPlayerInAnyVehicle(playerid))
		    	{
					ApplyAnimation(playerid, "RIFLE", "RIFLE_load",4.1,false,true,false,1000,1);
					SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
				}
			}
			else return SendClientMessage(playerid,-1,""chat" You don't have any pistol ammo on you!");
		}

		if(!strcmp(ItemName,"Toolbox",true))
		{
		    if(!IsPlayerInAnyVehicle(playerid))
		    {
		        if(IsPlayerInRangeOfPoint(playerid,10.0,vInfo[GetVehicleNearID(playerid)][vX],vInfo[GetVehicleNearID(playerid)][vY],vInfo[GetVehicleNearID(playerid)][vZ]))
		        {
					RepairVehicle(GetVehicleNearID(playerid));
					SetVehicleHealth(GetVehicleNearID(playerid),800.0);
					if(!IsPlayerInAnyVehicle(playerid))
					{
						ApplyAnimation(playerid, "BOMBER", "BOM_Plant",4.1,false,true,false,1000,1);
						SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
					}
				}
				else return SendClientMessage(playerid,-1,""chat" You must be near a vehicle to repair!");
			}
			else return SendClientMessage(playerid,-1,""chat" You cannot be in a vehicle to repair!");
		}

		if(!strcmp(ItemName,"Map",true))
	 	{
	 	    SendClientMessage(playerid, -1, "*"COL_RED" Press 'middle mouse button' to open/close map. A GPS unlocks the Mini-map");
	  	}

		if(!strcmp(ItemName,"GPS",true))
	 	{
   			if(pInfo[playerid][pIsMapOpened] == 1)
   			{
   				PlayerTextDrawShow(playerid, blockMap[playerid]);
				GangZoneShowForPlayer(playerid,BlockMap,0x000000FF);
	    		pInfo[playerid][pIsMapOpened] = 0;
    		}
			else
			{
				PlayerTextDrawHide(playerid, blockMap[playerid]);
	    		GangZoneHideForPlayer(playerid,BlockMap);
	    		pInfo[playerid][pIsMapOpened] = 1;
			}
		}

	  	if(!strcmp(ItemName,"Sniper Ammo",true))
	  	{
	  	    if(GetPlayerWeapon(playerid) == 34)
	  	    {
				GivePlayerWeaponEx(playerid,34,10);
				SendClientMessage(playerid,-1,""chat" Added ammo to your 'Sniper Rifle'");
				RemoveSlotToInventory(playerid,"Sniper Ammo",1);
				if(!IsPlayerInAnyVehicle(playerid))
		    	{
					ApplyAnimation(playerid, "RIFLE", "RIFLE_load",4.1,false,true,false,1000,1);
					SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
				}
			}

			if(GetPlayerWeapon(playerid) == 33)
			{
			    GivePlayerWeaponEx(playerid,33,15);
				SendClientMessage(playerid,-1,""chat" Added ammo to your 'Country Rifle'");
				RemoveSlotToInventory(playerid,"Sniper Ammo",1);
				if(!IsPlayerInAnyVehicle(playerid))
		    	{
					ApplyAnimation(playerid, "RIFLE", "RIFLE_load",4.1,false,true,false,1000,1);
					SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
				}
			}
		}

		if(!strcmp(ItemName,"Shotgun Ammo",true))
	  	{
	  	    if(GetPlayerWeapon(playerid) == 25)
	  	    {
				GivePlayerWeaponEx(playerid,25,10);
				SendClientMessage(playerid,-1,""chat" Added ammo to your 'Shotgun'");
				RemoveSlotToInventory(playerid,"Shotgun Ammo",1);
				if(!IsPlayerInAnyVehicle(playerid))
		    	{
					ApplyAnimation(playerid, "RIFLE", "RIFLE_load",4.1,false,true,false,1000,1);
					SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
				}
			}

			if(GetPlayerWeapon(playerid) == 27)
			{
			    GivePlayerWeaponEx(playerid,27,15);
				SendClientMessage(playerid,-1,""chat" Added ammo to your 'SPAZ-12 Shotgun'");
				RemoveSlotToInventory(playerid,"Shotgun Ammo",1);
				if(!IsPlayerInAnyVehicle(playerid))
		    	{
					ApplyAnimation(playerid, "RIFLE", "RIFLE_load",4.1,false,true,false,1000,1);
					SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
				}
			}
		}

		if(!strcmp(ItemName,"Pistol Ammo",true))
	  	{
	  	    if(GetPlayerWeapon(playerid) == 22)
	  	    {
				GivePlayerWeaponEx(playerid,22,30);
				SendClientMessage(playerid,-1,""chat" Added ammo to your 'Pistol'");
				RemoveSlotToInventory(playerid,"Pistol Ammo",1);
				if(!IsPlayerInAnyVehicle(playerid))
		    	{
					ApplyAnimation(playerid, "RIFLE", "RIFLE_load",4.1,false,true,false,1000,1);
					SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
				}
			}

			if(GetPlayerWeapon(playerid) == 23)
			{
			    GivePlayerWeaponEx(playerid,23,10);
				SendClientMessage(playerid,-1,""chat" Added ammo to your 'Silenced Pistol'");
				RemoveSlotToInventory(playerid,"Pistol Ammo",1);
				if(!IsPlayerInAnyVehicle(playerid))
		    	{
					ApplyAnimation(playerid, "RIFLE", "RIFLE_load",4.1,false,true,false,1000,1);
					SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
				}
			}
		}

		if(!strcmp(ItemName,"Assault Ammo",true))
	  	{
	  	    if(GetPlayerWeapon(playerid) == 30)
	  	    {
				GivePlayerWeaponEx(playerid,30,28);
				SendClientMessage(playerid,-1,""chat" Added ammo to your 'AK-47'");
				RemoveSlotToInventory(playerid,"Assault Ammo",1);
				if(!IsPlayerInAnyVehicle(playerid))
		    	{
					ApplyAnimation(playerid, "RIFLE", "RIFLE_load",4.1,false,true,false,1000,1);
					SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
				}
			}

			if(GetPlayerWeapon(playerid) == 31)
			{
			    GivePlayerWeaponEx(playerid,31,25);
				SendClientMessage(playerid,-1,""chat" Added ammo to your 'M4'");
				RemoveSlotToInventory(playerid,"Assault Ammo",1);
				if(!IsPlayerInAnyVehicle(playerid))
		    	{
					ApplyAnimation(playerid, "RIFLE", "RIFLE_load",4.1,false,true,false,1000,1);
					SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
				}
			}
		}

		if(!strcmp(ItemName,"SMG Ammo",true))
	  	{
	  	    if(GetPlayerWeapon(playerid) == 29)
	  	    {
				GivePlayerWeaponEx(playerid,29,15);
				SendClientMessage(playerid,-1,""chat" Added ammo to your 'MP5'");
				RemoveSlotToInventory(playerid,"SMG Ammo",1);
				if(!IsPlayerInAnyVehicle(playerid))
		    	{
					ApplyAnimation(playerid, "RIFLE", "RIFLE_load",4.1,false,true,false,1000,1);
					SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
				}
			}
		}

		if(!strcmp(ItemName,"Tent",true))
		{
			if(pInfo[playerid][pTentCreated] == 0)
			{
		    	if(!DayZSA_CreateTent(playerid)) return 0;
		    	SendClientMessage(playerid,-1,"*"COL_GREEN" Placed a tent!");
            	RemoveSlotToInventory(playerid,"Tent",1);
   				if(!IsPlayerInAnyVehicle(playerid))
				{
					ApplyAnimation(playerid, "BOMBER", "BOM_Plant",4.1,false,true,false,1000,1);
					SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
				}
			}
			else return SendClientMessage(playerid, -1, ""chat" Cannot place tent, you've already created one please destroy your old one.");
		}

		if(!strcmp(ItemName,"Army Skin",true))
		{
		    SetPlayerSkin(playerid,CIV);
			RemoveSlotToInventory(playerid,"Army Skin",1);
			RemovePlayerAttachedObject(playerid, 4);
			if(!IsPlayerInAnyVehicle(playerid))
			{
				ApplyAnimation(playerid, "BOMBER", "BOM_Plant",4.1,false,true,false,1000,1);
				SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
			}
		}

		if(!strcmp(ItemName,"Civilian Skin",true))
		{
		    SetPlayerSkin(playerid,CIVSKIN);
			RemoveSlotToInventory(playerid,"Civilian Skin",1);
			RemovePlayerAttachedObject(playerid, 4);
			if(!IsPlayerInAnyVehicle(playerid))
			{
				ApplyAnimation(playerid, "BOMBER", "BOM_Plant",4.1,false,true,false,1000,1);
				SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
			}
		}

		if(!strcmp(ItemName,"Sniper Skin",true))
		{
		    SetPlayerSkin(playerid,SNIP);
			RemoveSlotToInventory(playerid,"Sniper Skin",1);
			RemovePlayerAttachedObject(playerid, 4);
			if(!IsPlayerInAnyVehicle(playerid))
			{
				ApplyAnimation(playerid, "BOMBER", "BOM_Plant",4.1,false,true,false,1000,1);
				SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
			}
		}

		if(!strcmp(ItemName,"Katana",true))
		{
		    GivePlayerWeaponEx(playerid,8,1);
			RemoveSlotToInventory(playerid,"Katana",1);
			if(!IsPlayerInAnyVehicle(playerid))
  			{
				ApplyAnimation(playerid, "BASEBALL", "BAT_PART",4.1,false,true,false,1000,1);
				SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
			}
		}

		if(!strcmp(ItemName,"Baseball Bat",true))
		{
		    GivePlayerWeaponEx(playerid,5,1);
			RemoveSlotToInventory(playerid,"Baseball Bat",1);
			if(!IsPlayerInAnyVehicle(playerid))
  			{
				ApplyAnimation(playerid, "BASEBALL", "BAT_PART",4.1,false,true,false,1000,1);
				SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
			}
		}

		if(!strcmp(ItemName,"Binoculars",true))
		{
  		  	GivePlayerWeaponEx(playerid,43,99);
			RemoveSlotToInventory(playerid,"Binoculars",1);
			if(!IsPlayerInAnyVehicle(playerid))
  			{
				ApplyAnimation(playerid, "BASEBALL", "BAT_PART",4.1,false,true,false,1000,1);
				SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
			}
		}

		if(!strcmp(ItemName,"Full Jerry Can",true))
		{
		    SendClientMessage(playerid,-1,"*"COL_RED" Add the vehicle part into the vehicle gear!");
		}

		if(!strcmp(ItemName,"Engine",true))
		{
		    SendClientMessage(playerid,-1,"*"COL_RED" Add the vehicle part into the vehicle gear!");
		}

		if(!strcmp(ItemName,"Tire",true))
		{
		    SendClientMessage(playerid,-1,"*"COL_RED" Add the vehicle part into the vehicle gear!");
		}

		if(!strcmp(ItemName,"Radio Device",true))
		{
			ShowPlayerDialog(playerid,DIALOG_RADIO,DIALOG_STYLE_LIST,"DayZ - Radio Frequency","Low Frequency\nMedium Frequency\nNormal Frequency\nHigh Frequency","Change","Cancel");
		}

  		if(!strcmp(ItemName,"Heat Pack",true))
        {
			if(pInfo[playerid][pTemp] >= 99.0)
			{
            	SendClientMessage(playerid,-1,"*"COL_RED" You don't need to use any heat packs, your body is warm!");
			}
			else
			{
			    pInfo[playerid][pTemp] = 91.0;
   				if(!IsPlayerInAnyVehicle(playerid))
				{
					ApplyAnimation(playerid, "BOMBER", "BOM_Plant",4.1,false,true,false,1000,1);
					RemoveSlotToInventory(playerid,"Heat Pack",1);
					SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
				}
			}
		}

		if(!strcmp(ItemName,"Heat Pack Basic",true))
        {
			if(pInfo[playerid][pTemp] >= 99.0)
			{
            	SendClientMessage(playerid,-1,"*"COL_RED" You don't need to use any heat packs, your body is warm!");
			}
			else
			{
			    pInfo[playerid][pTemp] = 95.0;
   				if(!IsPlayerInAnyVehicle(playerid))
				{
					ApplyAnimation(playerid, "BOMBER", "BOM_Plant",4.1,false,true,false,1000,1);
					SetTimerEx("ResetAction", 1450, false, "ii", playerid, ACTION_ANIMATION);
				}
			    RemoveSlotToInventory(playerid,"Heat Pack Basic",1);
			}
		}
	}
  	return 0;
}

stock DayZSA_CreateAllVehicles()
{
	CreateVehicle(500,-1839.6999500,-1630.5999800,22.3000000,180.0000000,88,89,0); //Mesa
	CreateVehicle(500,-1983.0000000,949.7000100,45.7000000,180.0000000,88,89,0); //Mesa
	CreateVehicle(500,-702.7000100,946.9000200,12.4000000,90.0000000,88,89,0); //Mesa
	CreateVehicle(500,2426.8999000,1957.3000500,6.2000000,90.0000000,88,89,0); //Mesa
	CreateVehicle(445,1342.0000000,1980.6999500,10.8000000,0.0000000,95,10,0); //Admiral
	CreateVehicle(445,1860.0999800,-1872.1999500,13.5000000,0.0000000,95,10,0); //Admiral
	CreateVehicle(445,-2193.8000500,-2303.8000500,30.6000000,320.0000000,95,10,0); //Admiral
	CreateVehicle(471,-1960.8000500,-1601.4000200,86.5000000,240.0000000,19,69,0); //Quad
	CreateVehicle(471,-191.5000000,-247.8999900,1.0000000,319.9960000,19,69,0); //Quad
	CreateVehicle(471,648.5000000,876.9000200,-42.5000000,319.9930000,19,69,0); //Quad
	CreateVehicle(468,-85.9000000,1078.4000200,19.5000000,0.0000000,157,152,0); //Sanchez
	CreateVehicle(468,1877.8000500,1815.0999800,12.5000000,0.0000000,157,152,0); //Sanchez
	CreateVehicle(468,2173.0000000,1390.3000500,10.6000000,80.0000000,157,152,0); //Sanchez
	CreateVehicle(468,2265.1001000,15.2000000,27.2000000,79.9970000,157,152,0); //Sanchez
	CreateVehicle(468,1278.6999500,301.3999900,19.3000000,79.9970000,157,152,0); //Sanchez
	CreateVehicle(468,1960.0999800,-1627.5000000,15.7000000,329.9970000,157,152,0); //Sanchez
	CreateVehicle(468,-1673.0999800,438.5000000,6.9000000,329.9960000,157,152,0); //Sanchez
	CreateVehicle(468,-1735.8000500,1007.5999800,17.3000000,259.9960000,157,152,0); //Sanchez
	CreateVehicle(509,-1799.3000500,770.0000000,24.5000000,0.0000000,66,31,0); //Bike
	CreateVehicle(509,-2023.3000500,-96.4000000,34.8000000,0.0000000,66,31,0); //Bike
	CreateVehicle(509,-1965.0999800,120.2000000,27.3000000,0.0000000,66,31,0); //Bike
	CreateVehicle(509,-306.3999900,1039.5000000,19.3000000,270.0000000,66,31,0); //Bike
	CreateVehicle(509,-343.0000000,1537.3000500,75.2000000,180.0000000,66,31,0); //Bike
	CreateVehicle(509,1911.6999500,2315.1001000,10.4000000,180.0000000,66,31,0); //Bike
	CreateVehicle(509,2530.3000500,1456.1999500,10.4000000,180.0000000,66,31,0); //Bike
	CreateVehicle(509,1944.1999500,165.3999900,36.9000000,260.0000000,66,31,0); //Bike
	CreateVehicle(509,1320.5999800,204.3000000,19.2000000,259.9970000,66,31,0); //Bike
	CreateVehicle(509,797.5999800,-616.5999800,15.9000000,39.9970000,66,31,0); //Bike
	CreateVehicle(509,1011.2999900,-1088.0999800,23.4000000,129.9960000,66,31,0); //Bike
	CreateVehicle(604,1085.9000200,-1340.0000000,13.6000000,180.0000000,42,119,0); //Glendale
	CreateVehicle(468,166.0000000,-1955.8000500,3.5000000,0.0000000,132,4,0); //Sanchez
	CreateVehicle(604,-1108.1999500,-1638.0000000,76.3000000,270.0000000,106,122,0); //Glendale
	CreateVehicle(487,-73.8000000,-1172.3000500,5.9000000,70.0000000,39,47,0); //Maverick
	CreateVehicle(487,-1679.0999800,704.0000000,30.9000000,89.9990000,39,47,0); //Maverick
	CreateVehicle(487,186.8999900,1835.9000200,23.5000000,359.9950000,39,47,0); //Maverick
	CreateVehicle(487,364.8999900,2533.1999500,17.0000000,177.9940000,39,47,0); //Maverick
	CreateVehicle(487,894.4000200,-1376.8000500,25.3000000,183.9900000,39,47,0); //Maverick
	CreateVehicle(554,584.0000000,-1354.4000200,14.8000000,280.0000000,93,27,0); //Yosemite
	CreateVehicle(554,-31.3000000,-297.5000000,5.6000000,271.9980000,93,27,0); //Yosemite
	CreateVehicle(554,-1446.0999800,2627.5000000,56.0000000,271.9940000,93,27,0); //Yosemite
	CreateVehicle(431,-1988.3000500,145.8000000,27.8000000,0.0000000,122,117,0); //Bus
	CreateVehicle(431,1278.0999800,-1301.0000000,13.6000000,0.0000000,122,117,0); //Bus
	CreateVehicle(431,1696.6999500,1452.3000500,11.0000000,180.0000000,122,117,0); //Bus
	CreateVehicle(531,-157.3999900,2706.5000000,62.5000000,0.0000000,37,37,0); //Tractor
	CreateVehicle(531,-98.3000000,-26.9000000,3.1000000,340.0000000,37,37,0); //Tractor
	CreateVehicle(531,1057.4000200,-305.3999900,74.0000000,173.9990000,37,37,0); //Tractor
	CreateVehicle(418,1991.9000200,-1278.5000000,24.0000000,270.0000000,145,115,0); //Moonbeam
	CreateVehicle(418,2473.5000000,-1699.8000500,13.7000000,358.0000000,145,115,0); //Moonbeam
	CreateVehicle(455,2739.6999500,-2426.8999000,14.2000000,0.0000000,170,157,0); //Flatbed
	CreateVehicle(455,93.3000000,1934.4000200,18.5000000,0.0000000,170,157,0); //Flatbed
	CreateVehicle(433,-1511.0999800,477.2999900,7.8000000,90.0000000,95,10,0); //Barracks
	CreateVehicle(433,-885.9000200,1008.7000100,21.8000000,70.0000000,95,10,0); //Barracks
	CreateVehicle(542,-1949.9000200,585.9000200,35.0000000,0.0000000,71,53,0); //Clover
	CreateVehicle(542,-1649.1999500,-2235.6999500,30.0000000,0.0000000,71,53,0); //Clover
	CreateVehicle(542,1062.3000500,-1767.0000000,13.2000000,270.0000000,88,89,0); //Clover
	CreateVehicle(542,2136.8000500,1425.9000200,10.7000000,270.0000000,88,89,0); //Clover
	CreateVehicle(453,1627.5999800,570.5999800,0.0000000,90.0000000,158,164,0); //Reefer
	CreateVehicle(453,-1632.9000200,163.1000100,2.6000000,134.0000000,158,164,0); //Reefer
	CreateVehicle(473,-279.2999900,-345.6000100,0.0000000,200.0000000,158,164,0); //Dinghy
	CreateVehicle(473,510.8999900,603.5999800,0.0000000,199.9950000,158,164,0); //Dinghy
	CreateVehicle(473,724.0999800,-1501.9000200,0.0000000,199.9950000,158,164,0); //Dinghy
	CreateVehicle(484,165.2000000,632.7000100,0.0000000,200.0000000,132,137,0); //Marquis
	CreateVehicle(484,-610.0000000,1322.3000500,0.0000000,229.9950000,132,137,0); //Marquis
	CreateVehicle(484,-1466.4000200,1096.5999800,0.0000000,269.9930000,132,137,0); //Marquis
	CreateVehicle(470,-1350.4000200,460.6000100,7.3000000,0.0000000,95,10,0); //Patriot
	CreateVehicle(470,442.7000100,2221.8000500,38.1000000,110.0000000,95,10,0); //Patriot
	CreateVehicle(470,2843.3000500,899.4000200,10.9000000,39.9950000,95,10,0); //Patriot
	CreateVehicle(470,154.5000000,-317.5000000,1.7000000,351.9900000,95,10,0); //Patriot
	CreateVehicle(470,-567.9000200,-1481.6999500,10.3000000,40.0000000,95,10,0); //Patriot
	CreateVehicle(422,-377.2999900,-1441.4000200,25.8000000,0.0000000,30,46,0); //Bobcat
	CreateVehicle(422,2411.0000000,-1239.1999500,23.9000000,180.0000000,30,46,0); //Bobcat
	CreateVehicle(422,2360.8000500,-650.2000100,128.2000000,180.0000000,30,46,0); //Bobcat
	CreateVehicle(417,275.3999900,1380.5000000,10.9000000,0.0000000,-1,-1,0); //Leviathan
	CreateVehicle(511,1477.5999800,1210.5000000,12.3000000,0.0000000,100,100,0); //Beagle
	CreateVehicle(511,-1427.6999500,-949.5999800,203.3999900,270.0000000,100,100,0); //Beagle
	CreateVehicle(510,297.5000000,1397.4000200,9.6000000,0.0000000,134,68,0); //Mountain Bike
	CreateVehicle(510,1891.5000000,1592.3000500,10.4000000,130.0000000,134,68,0); //Mountain Bike
	CreateVehicle(510,2332.6001000,1390.0999800,36.1000000,359.9960000,134,68,0); //Mountain Bike
	CreateVehicle(468,1526.0000000,949.0999800,10.6000000,0.0000000,215,142,0); //Sanchez
	return 1;
}

stock UpdateVehicleParts(playerid)
{
    if(IsPlayerInAnyVehicle(playerid))
    {
		if(FOUR_TIRE(playerid) || FOUR_TIRE2(playerid))
		{
			if(vInfo[GetPlayerVehicleID(playerid)][vehicleTires] >= 5)
			{
			    vInfo[GetPlayerVehicleID(playerid)][vehicleTires] = 4;
			}
		}

		if(TWO_TIRE_VEHICLE)
		{
			if(vInfo[GetPlayerVehicleID(playerid)][vehicleTires] >= 3)
			{
			    vInfo[GetPlayerVehicleID(playerid)][vehicleTires] = 2;
			}
		}

		if(SIX_TIRE_VEHICLE)
		{
			if(vInfo[GetPlayerVehicleID(playerid)][vehicleTires] >= 7)
			{
			    vInfo[GetPlayerVehicleID(playerid)][vehicleTires] = 6;
			}
		}

		if(vInfo[GetPlayerVehicleID(playerid)][vehicleEngine] >= 2)
		{
	 		vInfo[GetPlayerVehicleID(playerid)][vehicleEngine] = 1;
		}
	}
	return 1;
}

stock GetPlayerVehicleSpeed( playerid )
{
    new
        Float:x,
        Float:y,
        Float:z,
        vel,
        vehicleid;
    vehicleid = GetPlayerVehicleID(playerid);
    GetVehicleVelocity( vehicleid, x, y, z );
    vel = floatround( floatsqroot( x*x + y*y + z*z ) * 180 );           // KM/H
//  vel = floatround( floatsqroot( x*x + y*y + z*z ) * 180 / MPH_KMH ); // Mph
    return vel;
}
