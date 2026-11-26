public OnPlayerKeyStateChange(playerid, KEY:newkeys, KEY:oldkeys)
{

	if(PRESSED(KEY_WALK))
	{
		if(IsPlayerInRangeOfPoint(playerid,4,vInfo[GetVehicleNearID(playerid)][vX],vInfo[GetVehicleNearID(playerid)][vY],vInfo[GetVehicleNearID(playerid)][vZ]))
		{
			DayZSA_DisplayVehicleStorage(playerid);
		}
	}

	if(PRESSED(KEY_FIRE))
	{
		switch(GetPlayerWeapon(playerid))
		{
  			case 1,2,3,9,6,7,10,11,12,13,14,15,16,17,18,19,20,21,24,26,28,32,35,36,37,38,39,40,41,42,44,45:
		  	{
				jBan(playerid, -1, "Weapon Hack (NOT ALLOWED)", 0);
		  	}
  		}
	}

	if(PRESSED(KEY_FIRE))
	{
	    pInfo[playerid][ZombiesWarn]++;
	}

	if(PRESSED(KEY_FIRE))
	{
		if(pInfo[playerid][pIsSpawned] == 1)
		{
			new weapon2 = GetPlayerWeapon(playerid);
			if(weapon2 != 0 && !PlayerWeapons[playerid][weapon2] && weapon2 != 40 && weapon2 != 46)
			{
				jBan(playerid, -1, "Weapon Hack", 0);
			}
		}
	}

	if(PRESSED(KEY_SUBMISSION))
	{
	    if(PlayerHasItem(playerid,"Map"))
	    {
			if(pInfo[playerid][pIsMapOpened] == 0)
			{
		    	PlayerTextDrawShow(playerid, Map[playerid]);
		    	SendClientMessage(playerid,-1,"*"COL_RED" Press numpad1/middle mouse button again to disabled");
		    	pInfo[playerid][pIsMapOpened] = 1;
			}
			else return pInfo[playerid][pIsMapOpened] = 0,PlayerTextDrawHide(playerid, Map[playerid]);
		}
	}

	if(HOLDING(KEY_CTRL_BACK))
	{
	    if(!IsPlayerInAnyVehicle(playerid))
		{
		    if(pInfo[playerid][IsPlayerDrunk] == 0)
		    {
		    	if(gettime() - 5 < pInfo[playerid][pProneSpam]) return SendClientMessage(playerid,-1,"*"COL_RED" Don't prone abuse!");
				{
			    	ApplyAnimation(playerid,"WUZI","CS_Dead_Guy",4.1,true,true,true,true,0,1);
				    pInfo[playerid][pProne] = 1;
		     	 	DayZSA_SetPlayerNoiseLevel(playerid,0);
		     	 	DayZSA_SetPlayerEyeLevel(playerid,1);
		     	 	pInfo[playerid][pProneSpam] = gettime();
				}
			}
		}
	}

	if(RELEASED(KEY_CTRL_BACK))
	{
 		if(!IsPlayerInAnyVehicle(playerid))
		{
	    	ClearAnimations(playerid);
	    	pInfo[playerid][pProne] = 0;
			DayZSA_SetPlayerNoiseLevel(playerid,3);
			DayZSA_SetPlayerEyeLevel(playerid,2);
		}
	}

	if(PRESSED(KEY_ANALOG_LEFT))
	{
		if(IsPlayerInAnyVehicle(playerid))
		{
			if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
			{
				new engine_boot, lights_boot, alarm_boot, doors_boot, bonnet_boot, boot_boot, objective_boot;
				GetVehicleParamsEx(GetPlayerVehicleID(playerid), engine_boot, lights_boot, alarm_boot, doors_boot, bonnet_boot, boot_boot, objective_boot);
				if(engine == 1)
				{
				    new engine_but, lights_but, alarm_but, doors_but, bonnet_but, boot_but, objective_but;
					GetVehicleParamsEx(GetPlayerVehicleID(playerid), engine_but, lights_but, alarm_but, doors_but, bonnet_but, boot_but, objective_but);
					SetVehicleParamsEx(GetPlayerVehicleID(playerid), 0, lights_but, alarm_but, doors_but, bonnet_but, boot_but, objective_but);
					SendClientMessage(playerid, -1, ""chat" Vehicle engine has stopped!");
				}

				if(engine == 0)
				{
				    new engine_but, lights_but, alarm_but, doors_but, bonnet_but, boot_but, objective_but;
					GetVehicleParamsEx(GetPlayerVehicleID(playerid), engine_but, lights_but, alarm_but, doors_but, bonnet_but, boot_but, objective_but);
					SetVehicleParamsEx(GetPlayerVehicleID(playerid), 1, lights_but, alarm_but, doors_but, bonnet_but, boot_but, objective_but);
					SendClientMessage(playerid, -1, ""chat" Vehicle engine has started!");
				}
			}
	    }
	}

	if(PRESSED(KEY_NO))
	{
	    if(!IsPlayerInAnyVehicle(playerid))
		{
			if(IsPlayerInRangeOfPoint(playerid,1.1,Loot[GetLootID(playerid)][xLoot],Loot[GetLootID(playerid)][yLoot],Loot[GetLootID(playerid)][zLoot]))
			{
			    DayZSA_DisplayLootForPlayer(playerid);
			}
		}
	}

	if(PRESSED(KEY_WALK))
	{
	    if(!IsPlayerInAnyVehicle(playerid))
		{
			if(IsPlayerInRangeOfPoint(playerid,1.1,Loot[GetLootIDFunction(playerid)][xLootdrop],Loot[GetLootIDFunction(playerid)][yLootdrop],Loot[GetLootIDFunction(playerid)][zLootdrop]))
			{
			    DayZSA_DisplayLootFunction(playerid);
			}
		}
	}

	if(PRESSED(KEY_WALK))
	{
		if(IsPlayerInRangeOfPoint(playerid,3.3,Tent[GetTentID(playerid)][xTent],Tent[GetTentID(playerid)][yTent],Tent[GetTentID(playerid)][zTent]))
		{
			DayZSA_DisplayTent(playerid);
		}
	}

	if(PRESSED(KEY_WALK))
{
    if(IsPlayerInRangeOfPoint(playerid,2.1,CampFire[GetCampID(playerid)][xTent],CampFire[GetCampID(playerid)][yTent],CampFire[GetCampID(playerid)][zTent]))
    {
        if(PlayerHasItem(playerid, "Raw Meat"))
        {
            AddSlotToInventoryWorld(playerid, "Cooked Meat", 1);
            RemoveSlotToInventory(playerid, "Raw Meat", 1);
            SendClientMessage(playerid, -1, ""chat" Sucessfully cooked raw Meat! Check your inventory!");
        }
    }
}
	{
    if(IsPlayerInRangeOfPoint(playerid,2.1,CampFire[GetCampID(playerid)][xTent],CampFire[GetCampID(playerid)][yTent],CampFire[GetCampID(playerid)][zTent]))
    	{
        if(PlayerHasItem(playerid, "Dirty Water Bottle"))
       		 {
            AddSlotToInventoryWorld(playerid, "Full Water Bottle", 1);
            RemoveSlotToInventory(playerid, "Dirty Water Bottle", 1);
            SendClientMessage(playerid, -1, ""chat" Sucessfully boiled Water! Check your inventory!");
        }
        else return SendClientMessage(playerid, -1, ""chat", You have nothing to boil!");
    }
}

	if(PRESSED(KEY_NO))
	{
	    if(IsPlayerInRangeOfPoint(playerid,3.5,Tent[GetTentID(playerid)][xTent],Tent[GetTentID(playerid)][yTent],Tent[GetTentID(playerid)][zTent]))
	    {
			if(PlayerHasItem(playerid,"Toolbox"))
			{
				new Float:fPos[3];
				GetPlayerPos(playerid,fPos[0],fPos[1],fPos[2]);
				DayZSA_CreateLootsFunction("Tent",fPos[0],fPos[1],fPos[2]);
			    RemoveTent(GetTentID(playerid));
				SendClientMessage(playerid, -1, "*"COL_RED" Tent sucessfully destroyed.");
			}
            else return SendClientMessage(playerid,-1,"*"COL_RED" You need a toolbox to destroy this tent");
		}
	}

	if(PRESSED(KEY_WALK))
	{
		if(IsPlayerInRangeOfPoint(playerid,3.5,Loot[GetHospitalID(playerid)][xHos],Loot[GetHospitalID(playerid)][yHos],Loot[GetHospitalID(playerid)][zHos]))
		{
			DayZSA_DisplayHospital(playerid);
		}
	}
	
	if(PRESSED(KEY_WALK))
	{
		if(IsPlayerInRangeOfPoint(playerid,3.5,Loot[GetAirDropID(playerid)][xAir],Loot[GetAirDropID(playerid)][yAir],Loot[GetAirDropID(playerid)][zAir]))
		{
			DayZSA_DisplayAirdrop(playerid);
		}
	}
	
	

	if(PRESSED(KEY_CROUCH))
	{
	    if(!IsPlayerInAnyVehicle(playerid))
	    {
			if(DayZSA_IsPlayerAtGasStation(playerid))
			{
				if(PlayerHasItem(playerid,"Empty Jerry Can"))
				{
	                RemoveSlotToInventory(playerid,"Empty Jerry Can",1);
				    AddSlotToInventoryWorld(playerid,"Full Jerry Can",1);
				    SendClientMessage(playerid,-1,""chat" You filled the cainster with fuel!");
				}
				else return SendClientMessage(playerid,-1,""chat" You need to have empty Jerry Can to add fuel into your cainster!");
			}
		}
	}

	if(PRESSED(KEY_NO))
	{
	    if(!IsPlayerInAnyVehicle(playerid))
		{
			if(IsPlayerInRangeOfPoint(playerid,2.5,Loot[GetLootIDZombie(playerid)][xLootdropZ],Loot[GetLootIDZombie(playerid)][yLootdropZ],Loot[GetLootIDZombie(playerid)][zLootdropZ]))
			{
			    DayZSA_DisplayLootZombie(playerid);
			}
		}
	}

	if(PRESSED(KEY_SPRINT) || PRESSED(KEY_JUMP))
	{
	    if(pInfo[playerid][IsPlayerLegBroken] == 1)
	    {
	        ClearAnimations(playerid);
		}
	}

	if(HOLDING(KEY_SPRINT))
	{
	    if(!IsPlayerInAnyVehicle(playerid))
	    {
			if(pInfo[playerid][IsPlayerLegBroken] == 1)
	        {
			    ClearAnimations(playerid);
			}
		}
	}

	if(HOLDING(KEY_FIRE))
	{
 		if(!IsPlayerInAnyVehicle(playerid))
	    {
			new weap = GetPlayerWeapon(playerid);
	        if(weap == 29 || weap == 30 || weap == 31 || weap == 33 || weap == 34 || weap == 25 || weap == 22)
	        {
				DayZSA_SetPlayerNoiseLevel(playerid,4);
				DayZSA_SetPlayerEyeLevel(playerid,3);
			}
		}
	}

	if(RELEASED(KEY_FIRE))
	{
 		if(!IsPlayerInAnyVehicle(playerid))
	    {
   			new weap2 = GetPlayerWeapon(playerid);
	        if(weap2 == 29 || weap2 == 30 || weap2 == 31 || weap2 == 33 || weap2 == 34 || weap2 == 25 || weap2 == 22)
	        {
				DayZSA_SetPlayerNoiseLevel(playerid,3);
				DayZSA_SetPlayerEyeLevel(playerid,2);
			}
		}
	}

	if(PRESSED(KEY_YES))
	{
	    ShowInventory(playerid);
	}
	return 1;
}

forward CheckPlayerStatusZ();
public CheckPlayerStatusZ()
{
	foreach (new i : Player)
	{
		if(isPlayerInMenu[i] == 0)
  		{
    		if(pInfo[i][pLogged] == 1)
		    {
      			if(pInfo[i][pIsSpawned] == 1)
	        	{
					if(GetPlayerAnimationIndex(i))
					{
					    new animname[32], animlib[32];
			    		static Keys,ud,lr;
						GetPlayerKeys(i,Keys,ud,lr);
						GetAnimationName(GetPlayerAnimationIndex(i), animlib, sizeof(animlib), animname, sizeof(animname));
						if(!strcmp(animname, "JUMP_glide", true))
						{
   							if(pInfo[i][ZombiesWarn] >= 8)
						    {
			       				pInfo[i][ZombiesWarn] = 8;
							}
							pInfo[i][ZombiesWarn] += 2;
						}

						if(!strcmp(animname, "run_player", true) || !strcmp(animname, "run_right", true))
						{
						    if(ud == KEY_UP)
						    {
								pInfo[i][ZombiesWarn] += 3;
				    			if(pInfo[i][ZombiesWarn] >= 8)
							    {
							        pInfo[i][ZombiesWarn] = 8;
								}
							}
							else
							{
    							if(pInfo[i][ZombiesWarn] >= 8)
							    {
							        pInfo[i][ZombiesWarn] = 8;
								}
								pInfo[i][ZombiesWarn] += 2;
							}
						}

						if(!strcmp(animname, "IDLE_stance", true) || !strcmp(animname, "IDLE_armed", true) || !strcmp(animname, "IDLE_tired", true))
						{
		    				if(pInfo[i][ZombiesWarn] <= 0)
						    {
						        pInfo[i][ZombiesWarn] = 0;
							}
							pInfo[i][ZombiesWarn] -= 2;
						}

						if(!strcmp(animname, "Run_stopR", true))
						{
		    				if(pInfo[i][ZombiesWarn] <= 0)
						    {
						        pInfo[i][ZombiesWarn] = 0;
							}
							pInfo[i][ZombiesWarn]--;
						}

						if(!strcmp(animname, "WEAPON_CROUCH", true))
						{
		    				if(pInfo[i][ZombiesWarn] <= 0)
						    {
						        pInfo[i][ZombiesWarn] = 0;
							}
							pInfo[i][ZombiesWarn]--;
						}

						if(!strcmp(animname, "GUNCROUCHFWD", true))
						{
						    if(pInfo[i][ZombiesWarn] <= 0)
						    {
						        pInfo[i][ZombiesWarn] = 0;
							}
							pInfo[i][ZombiesWarn]--;
						}
					}
				}
			}
		}
	}
	return 1;
}

public OnPlayerUpdate(playerid)
{
	if(!IsPlayerNPC(playerid))
 	{
		static Keys,ud,lr;
		GetPlayerKeys(playerid,Keys,ud,lr);
		new animname[32], animlib[32];
		if(GetPlayerAnimationIndex(playerid))
		{
			GetAnimationName(GetPlayerAnimationIndex(playerid), animlib, sizeof(animlib), animname, sizeof(animname));
			if(!strcmp(animname, "FALL_SKYDIVE", true))
			{
                pInfo[playerid][IsPlayerCleoFly]++;
				pInfo[playerid][pCleoFlyWarning]++;

			    if(pInfo[playerid][IsPlayerCleoFly] >= 300)
				{
				    if(pInfo[playerid][pCleoFlyWarning] >= 6)
				    {
						if(GetPlayerWeapon(playerid) != 46)
						{
							jBan(playerid, -1, "Fly Hack", 0);
						}
					}
				}
			}
		}

	    /*if(GetPlayerAnimationIndex(playerid))
	    {
	        new msg[128];
	        GetAnimationName(GetPlayerAnimationIndex(playerid),animlib,32,animname,32);
	        format(msg, 128, "Animation: %s %s", animlib, animname);
	        SendClientMessage(playerid, 0xFFFFFFFF, msg);
	    }*/

		if(GetPlayerAnimationIndex(playerid))
		{
			GetAnimationName(GetPlayerAnimationIndex(playerid), animlib, sizeof(animlib), animname, sizeof(animname));
			if(!strcmp(animname, "JUMP_glide", true))
			{
				DayZSA_SetPlayerNoiseLevel(playerid,3);
				DayZSA_SetPlayerEyeLevel(playerid,3);
			}

			if(!strcmp(animname, "JUMP_land", true))
			{
				DayZSA_SetPlayerNoiseLevel(playerid,2);
				DayZSA_SetPlayerEyeLevel(playerid,1);
			}

			if(!strcmp(animname, "run_player", true) || !strcmp(animname, "run_right", true))
			{
			    if(ud == KEY_UP)
			    {
					DayZSA_SetPlayerNoiseLevel(playerid,4);
					DayZSA_SetPlayerEyeLevel(playerid,3);
				}
				else
				{
					DayZSA_SetPlayerNoiseLevel(playerid,3);
					DayZSA_SetPlayerEyeLevel(playerid,3);
				}
			}

			if(!strcmp(animname, "IDLE_stance", true) || !strcmp(animname, "IDLE_armed", true) || !strcmp(animname, "IDLE_tired", true))
			{
				DayZSA_SetPlayerNoiseLevel(playerid,0);
				DayZSA_SetPlayerEyeLevel(playerid,1);
			}

			if(!strcmp(animname, "Run_stopR", true))
			{
				DayZSA_SetPlayerNoiseLevel(playerid,1);
				DayZSA_SetPlayerEyeLevel(playerid,1);
			}

			if(!strcmp(animname, "Run_stopR", true))
			{
				DayZSA_SetPlayerNoiseLevel(playerid,2);
				DayZSA_SetPlayerEyeLevel(playerid,1);
			}

			if(!strcmp(animname, "WEAPON_CROUCH", true))
			{
				DayZSA_SetPlayerNoiseLevel(playerid,2);
				DayZSA_SetPlayerEyeLevel(playerid,1);
			}

			if(!strcmp(animname, "GUNCROUCHFWD", true))
			{
				DayZSA_SetPlayerNoiseLevel(playerid,2);
				DayZSA_SetPlayerEyeLevel(playerid,2);
			}
		}

        new drunk2 = GetPlayerDrunkLevel(playerid);
        if(drunk2 < 100)
        {
            SetPlayerDrunkLevel(playerid,2000);
        }
        else
        {
            if(DLlast[playerid] != drunk2)
            {
                new fps = DLlast[playerid] - drunk2;
                if((fps > 0) && (fps < 200))
				FPS2[playerid] = fps;
				DLlast[playerid] = drunk2;
     		}
        }

  		static Float: X, Float: Y, Float: Z;
	    GetPlayerPos(playerid, X, Y, Z);


	    if(X >= 99999.0 || Y >= 99999.0 || Z >= 99999.0 || X <= -99999.0 || Y <= -99999.0 || Z <= -99999.0)
		{
	        SendClientMessage(playerid, 0xa9c4e4ff, "Warning: Excessive X, Y, Z has been breached thus last location set.");
	        SetPlayerPos_Allow(playerid, p_PlayerBuggerX[playerid], p_PlayerBuggerY[playerid], p_PlayerBuggerZ[playerid]);
	    }
	    else
	    {
	        p_PlayerBuggerX[playerid] = X;
	        p_PlayerBuggerY[playerid] = Y;
	        p_PlayerBuggerZ[playerid] = Z;
	    }

     	static Float:X2, Float:Y2, Float:Z2;
	    if(IsPlayerInAnyVehicle(playerid))
	    {
	        GetVehicleVelocity(GetPlayerVehicleID(playerid), X2, Y2, Z2);
	        if(X2 > 3.0 || Y2 > 3.0 || Z2 > 3.0 || X2 < -3.0 || Y2 < -3.0 || Z2 < -3.0)
	        {
				jBan(playerid, -1, "Vehicle Warp Hack (Spin)", 0);
	        }
	    }

		if(tickcount() - armedbody_pTick[playerid] > 113)
		{
			new
				weaponid[13],weaponammo[13],pArmedWeapon;
			pArmedWeapon = GetPlayerWeapon(playerid);
			GetPlayerWeaponData(playerid,1,weaponid[1],weaponammo[1]);
			GetPlayerWeaponData(playerid,2,weaponid[2],weaponammo[2]);
			GetPlayerWeaponData(playerid,4,weaponid[4],weaponammo[4]);
			GetPlayerWeaponData(playerid,5,weaponid[5],weaponammo[5]);
			#if ARMEDBODY_USE_HEAVY_WEAPON
			GetPlayerWeaponData(playerid,7,weaponid[7],weaponammo[7]);
			#endif
			if(weaponid[1] && weaponammo[1] > 0){
				if(pArmedWeapon != weaponid[1]){
					if(!IsPlayerAttachedObjectSlotUsed(playerid,5)){
						//SetPlayerAttachedObject(playerid,5,GetWeaponModel(weaponid[1]),1, 0.199999, -0.139999, 0.030000, 0.500007, -115.000000, 0.000000, 1.000000, 1.000000, 1.000000);
                        SetPlayerAttachedObject( playerid, 5, GetWeaponModel(weaponid[1]), 16, -0.195032, 0.120565, -0.052446, 0.000000, 20.250000, 0.000000, 0.968602, 0.904952, 1.110462 );
					}
				}
				else {
					if(IsPlayerAttachedObjectSlotUsed(playerid,5)){
						RemovePlayerAttachedObject(playerid,5);
					}
				}
			}
			else if(IsPlayerAttachedObjectSlotUsed(playerid,5)){
				RemovePlayerAttachedObject(playerid,5);
			}
			if(weaponid[2] && weaponammo[2] > 0){
				if(pArmedWeapon != weaponid[2]){
					if(!IsPlayerAttachedObjectSlotUsed(playerid,6)){
						//SetPlayerAttachedObject(playerid,6,GetWeaponModel(weaponid[2]),8, -0.079999, -0.039999, 0.109999, -90.100006, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000);
						SetPlayerAttachedObject(playerid, 6, GetWeaponModel(weaponid[2]), 12, -0.050205, -0.069741, -0.080912, 20.179998, 17.460956, 354.668945, 1.150907, 1.061156, 0.884258 );
					}
				}
				else {
					if(IsPlayerAttachedObjectSlotUsed(playerid,6)){
						RemovePlayerAttachedObject(playerid,6);
					}
				}
			}
			else if(IsPlayerAttachedObjectSlotUsed(playerid,6)){
				RemovePlayerAttachedObject(playerid,6);
			}
			if(weaponid[4] && weaponammo[4] > 0){
				if(pArmedWeapon != weaponid[4]){
					if(!IsPlayerAttachedObjectSlotUsed(playerid,7)){
						SetPlayerAttachedObject(playerid,7,GetWeaponModel(weaponid[4]),7, 0.000000, -0.100000, -0.080000, -95.000000, -10.000000, 0.000000, 1.000000, 1.000000, 1.000000);
					}
				}
				else {
					if(IsPlayerAttachedObjectSlotUsed(playerid,7)){
						RemovePlayerAttachedObject(playerid,7);
					}
				}
			}
			else if(IsPlayerAttachedObjectSlotUsed(playerid,7)){
				RemovePlayerAttachedObject(playerid,7);
			}
			if(weaponid[5] && weaponammo[5] > 0){
				if(pArmedWeapon != weaponid[5]){
					if(!IsPlayerAttachedObjectSlotUsed(playerid,8)){
						SetPlayerAttachedObject(playerid,8,GetWeaponModel(weaponid[5]),1, 0.200000, -0.119999, -0.059999, 0.000000, 206.000000, 0.000000, 1.000000, 1.000000, 1.000000);
					}
				}
				else {
					if(IsPlayerAttachedObjectSlotUsed(playerid,8)){
						RemovePlayerAttachedObject(playerid,8);
					}
				}
			}
			else if(IsPlayerAttachedObjectSlotUsed(playerid,8)){
				RemovePlayerAttachedObject(playerid,8);
			}
			#if ARMEDBODY_USE_HEAVY_WEAPON
			if(weaponid[7] && weaponammo[7] > 0){
				if(pArmedWeapon != weaponid[7]){
					if(!IsPlayerAttachedObjectSlotUsed(playerid,9)){
						SetPlayerAttachedObject(playerid,9,GetWeaponModel(weaponid[7]),1,-0.100000, 0.000000, -0.100000, 84.399932, 112.000000, 10.000000, 1.099999, 1.000000, 1.000000);
					}
				}
				else {
					if(IsPlayerAttachedObjectSlotUsed(playerid,9)){
						RemovePlayerAttachedObject(playerid,9);
					}
				}
			}
			else if(IsPlayerAttachedObjectSlotUsed(playerid,9)){
				RemovePlayerAttachedObject(playerid,9);
			}
			#endif
			armedbody_pTick[playerid] = tickcount();
		}
		}
	return 1;
}

public OnVehicleStreamOut(vehicleid, forplayerid)
{
	return 1;
}

