public OnPlayerSpawn(playerid)
{
	if(IsPlayerNPC(playerid))
	{

	    return 1;
	}
	else
	{

		PreloadAnimLib(playerid,"BOMBER"); PreloadAnimLib(playerid,"RAPPING");
		PreloadAnimLib(playerid,"SHOP"); PreloadAnimLib(playerid,"BEACH");
		PreloadAnimLib(playerid,"SMOKING"); PreloadAnimLib(playerid,"FOOD");
		PreloadAnimLib(playerid,"ON_LOOKERS"); PreloadAnimLib(playerid,"DEALER");
		PreloadAnimLib(playerid,"CRACK"); PreloadAnimLib(playerid,"CARRY");
		PreloadAnimLib(playerid,"COP_AMBIENT"); PreloadAnimLib(playerid,"PARK");
		PreloadAnimLib(playerid,"INT_HOUSE"); PreloadAnimLib(playerid,"PED");
		PreloadAnimLib(playerid,"MISC"); PreloadAnimLib(playerid,"OTB");
		PreloadAnimLib(playerid,"BD_Fire"); PreloadAnimLib(playerid,"BENCHPRESS");
		PreloadAnimLib(playerid,"KISSING"); PreloadAnimLib(playerid,"BSKTBALL");
		PreloadAnimLib(playerid,"MEDIC"); PreloadAnimLib(playerid,"SWORD");
		PreloadAnimLib(playerid,"POLICE"); PreloadAnimLib(playerid,"SUNBATHE");
		PreloadAnimLib(playerid,"FAT"); PreloadAnimLib(playerid,"WUZI");
		PreloadAnimLib(playerid,"SWEET"); PreloadAnimLib(playerid,"ROB_BANK");
		PreloadAnimLib(playerid,"GANGS"); PreloadAnimLib(playerid,"RIOT");
		PreloadAnimLib(playerid,"GYMNASIUM"); PreloadAnimLib(playerid,"CAR");
		PreloadAnimLib(playerid,"CAR_CHAT"); PreloadAnimLib(playerid,"GRAVEYARD");
		PreloadAnimLib(playerid,"POOL");

		if(isPlayerInMenu[playerid] == 0)
	 	{
	  		if(pInfo[playerid][pLogged] == 1)
	    	{
		    	SpawnVars(playerid);
	   			SendClientMessage(playerid, -1, ""chat" Zombies are now enabled");
				SetCameraBehindPlayer(playerid);
	 			GameTextForPlayer(playerid, "~w~loading spawn...", 2800, 4);
				SetPlayerColor(playerid,0xFFFFFF00);
				PlayerTextDrawHide(playerid, MenuLogo[playerid]);
				if(pInfo[playerid][pAmbientEnable] == 1)
				if(pInfo[playerid][pKidnapped] == 1)
	{
	    TogglePlayerControllable(playerid,false);
	    SendClientMessage(playerid,COLOR_RED,"WARNING: You are still tied with rope!");
	}
	  			{
					if(timeMode == DAY)
	  				{
	   					PlayAudioStreamForPlayer(playerid, "http://pgagaming.net/samp/dayz/dayz_ambient_day.mp3");
					}

					if(timeMode == NIGHT)
	  				{
	   					PlayAudioStreamForPlayer(playerid, "http://pgagaming.net/samp/dayz/dayz_ambient_night.mp3");
					}
				}
			}
		}
	}
	return 1;
}

public OnPlayerDeath(playerid, killerid, WEAPON:reason)
{
	if(IsPlayerNPC(playerid)) return 1;    // zombie deaths are handled in OnNPCDeath
	PlayerDying[playerid] = false;
	if(killerid != INVALID_PLAYER_ID)
	{
	    if(!IsPlayerNPC(playerid))
	    {
			new name[24], kname[30], string[64];
			GetPlayerName(playerid, name, 24);
			GetPlayerName(killerid, kname, 30);
			format(string, sizeof(string), "%s Has been killed by %s", name,kname,reason);
			SendMessageToAllAdmins(string, -1);
		}
	}

    if(IsPlayerNPC(playerid))
	{

    }


	if(!IsPlayerNPC(killerid))
    {
	    if(killerid != INVALID_PLAYER_ID)
	    {
		    if(GetPlayerSkin(playerid) == BANDIT)
		    {
				pInfo[killerid][BanditsKilled]++;
				pInfo[killerid][Murders]++;
				pInfo[killerid][Humanity] += random(1000);

				if(pInfo[killerid][Humanity] >= 3000)
				{
				    if(pInfo[killerid][IsPlayerHero] == 0)
				    {
				 		SetPlayerSkin(killerid,HERO);
					    SendClientMessage(killerid,-1,""COL_GREY" You are a hero now!");
					    ClearAnimations(killerid);
		                pInfo[killerid][IsPlayerHero] = 1;
					}
				}
			}

		 	if(GetPlayerSkin(playerid) == NORMAL)
		    {
				pInfo[killerid][Murders]++;
				pInfo[killerid][Humanity] -= 650;

				if(pInfo[killerid][Humanity] <= 1500)
				{
				    if(pInfo[killerid][IsPlayerBandit] == 0)
				    {
			 			SetPlayerSkin(killerid,BANDIT);
				    	SendClientMessage(killerid,-1,""COL_GREY" You are a bandit now!");
				    	ClearAnimations(killerid);
						pInfo[killerid][IsPlayerBandit] = 1;
					}
				}
			}

			if(GetPlayerSkin(playerid) == FEMALE)
		    {
				pInfo[killerid][Murders]++;
				pInfo[killerid][Humanity] -= random(700);

				if(pInfo[killerid][Humanity] <= 1500)
				{
				    if(pInfo[killerid][IsPlayerBandit] == 0)
				    {
			 			SetPlayerSkin(killerid,BANDIT);
				    	SendClientMessage(killerid,-1,""COL_GREY" You are a bandit now!");
				    	ClearAnimations(killerid);
						pInfo[killerid][IsPlayerBandit] = 1;
					}
				}
			}

			if(GetPlayerSkin(playerid) == HERO)
		    {
				pInfo[killerid][Murders]++;
				pInfo[killerid][Humanity] -= random(700);

				if(pInfo[killerid][Humanity] <= 1500)
				{
				    if(pInfo[killerid][IsPlayerBandit] == 0)
				    {
			 			SetPlayerSkin(killerid,BANDIT);
				    	SendClientMessage(killerid,-1,""COL_GREY" You are a bandit now!");
				    	ClearAnimations(killerid);
						pInfo[killerid][IsPlayerBandit] = 1;
					}
				}
			}

		 	if(IsPlayerAimingTargetBodyPart(killerid, playerid, BODY_PART_HEAD))
			{
		  		GameTextForPlayer(killerid, "~r~~h~Head shot!", 3000, 3);
		  		pInfo[killerid][Headshots]++;
			}
		}
	}

	if(!IsPlayerNPC(playerid))
    {
		TeleportAllowed[playerid] = 1;
		abAllow[playerid] = 1;
		new str[128];
		format(str,sizeof(str),"%s is now~r~ dead!",PlayerName(playerid));
		UpdateAnnouncement(str);

		new Float:fPos[3];
		GetPlayerPos(playerid,fPos[0],fPos[1],fPos[2]);
	    DayZSA_CreateLootsDeadBody(playerid,fPos[0],fPos[1],fPos[2]);

        PlayerTextDrawHide(playerid, vehicleInfo[playerid]);
       	PlayerTextDrawHide(playerid, vehicleInfo[playerid]);
		PlayerTextDrawHide(playerid, VehicleBG[playerid]);
		PlayerTextDrawHide(playerid, EngineIcon[playerid]);
		PlayerTextDrawHide(playerid, SpeedIcon[playerid]);
		PlayerTextDrawHide(playerid, TireIcon[playerid]);
		PlayerTextDrawHide(playerid, FuelIcon[playerid]);
		PlayerTextDrawHide(playerid, PlayerVehicleName[playerid]);
		pInfo[playerid][Headshots] = 0;
		pInfo[playerid][Murders] = 0;
		pInfo[playerid][BanditsKilled] = 0;
		pInfo[playerid][ZombiesKilled] = 0;
		pInfo[playerid][Backpack] = 0;
		pInfo[playerid][BackpackSlots] = 0;
		pInfo[playerid][pX] = 0.0;
		pInfo[playerid][pY] = 0.0;
		pInfo[playerid][pZ] = 0.0;
		pInfo[playerid][pWeap1] = 0;
		pInfo[playerid][pAmmo1] = 0;
		pInfo[playerid][pWeap2] = 0;
		pInfo[playerid][pAmmo2] = 0;
		pInfo[playerid][pWeap3] = 0;
		pInfo[playerid][pAmmo3] = 0;
		pInfo[playerid][pWeap4] = 0;
		pInfo[playerid][pAmmo4] = 0;
		pInfo[playerid][pBlood] = 9999;
		pInfo[playerid][pThrist] = 9999;
		pInfo[playerid][pHunger] = 9999;
		pInfo[playerid][Humanity] = 2500;
		pInfo[playerid][pFirstSpawn] = 1;
		pInfo[playerid][IsPlayerLegBroken] = 0;
		pInfo[playerid][IsPlayerMakingNoise] = 0;
		pInfo[playerid][IsPlayerHero] = 0;
		pInfo[playerid][IsPlayerBandit] = 0;
		pInfo[playerid][IsPlayerBleeding] = 0;
		pInfo[playerid][pIsMapOpened] = 0;
		pInfo[playerid][IsPlayerDrunk] = 0;
		pInfo[playerid][pTemp] = 100.0;
		PlayerTextDrawHide(playerid,PlayerBlood[playerid]);
		PlayerTextDrawHide(playerid,PlayerHunger[playerid]);
		PlayerTextDrawHide(playerid,PlayerThirst[playerid]);
		PlayerTextDrawHide(playerid,playerBandit[playerid]);
		PlayerTextDrawHide(playerid,PlayerTemp[playerid]);
	    PlayerTextDrawColor(playerid,PlayerBlood[playerid], 0x10F44155);
		PlayerTextDrawColor(playerid,PlayerHunger[playerid], 0x10F44155);
		PlayerTextDrawColor(playerid,PlayerThirst[playerid], 0x10F44155);
		PlayerTextDrawColor(playerid,playerBandit[playerid], 0x10F44155);
		PlayerTextDrawColor(playerid,PlayerTemp[playerid], 0x10F44155);
		PlayerTextDrawShow(playerid,PlayerBlood[playerid]);
		PlayerTextDrawShow(playerid,PlayerHunger[playerid]);
		PlayerTextDrawShow(playerid,PlayerThirst[playerid]);
		PlayerTextDrawShow(playerid,playerBandit[playerid]);
		PlayerTextDrawShow(playerid,PlayerTemp[playerid]);
		PlayerTextDrawHide(playerid, PlayerFade[playerid]);
		pInfo[playerid][pFade] = 0;

		pInfo[playerid][pAliveTime] = 0;
		ClearChatPlayer(playerid);
		ResetPlayerInventory(playerid);
		pInfo[playerid][pIsSpawned] = 0;
		pInfo[playerid][pWeap1] = 0;
		pInfo[playerid][pAmmo1] = 0;
		pInfo[playerid][pWeap2] = 0;
		pInfo[playerid][pAmmo2] = 0;
		pInfo[playerid][pWeap3] = 0;
		pInfo[playerid][pAmmo3] = 0;
		pInfo[playerid][pWeap4] = 0;
		pInfo[playerid][pAmmo4] = 0;
		pInfo[playerid][pWeap5] = 0;
		pInfo[playerid][pAmmo5] = 0;
		pInfo[playerid][pWeap6] = 0;
		pInfo[playerid][pAmmo6] = 0;
		pInfo[playerid][pWeap7] = 0;
		pInfo[playerid][pAmmo7] = 0;
		pInfo[playerid][pWeap8] = 0;
		pInfo[playerid][pAmmo8] = 0;
		pInfo[playerid][pWeap9] = 0;
		pInfo[playerid][pAmmo9] = 0;
		SaveStats(playerid);    // a death must survive a crash or a quick quit

		RemovePlayerAttachedObject(playerid, 2);
		StopTimer(pInfo[playerid][Bleeding]);
		PlayerTextDrawHide(playerid, LegBroken[playerid]);

        if(pInfo[playerid][pInfection] == 1)
        {
            pInfo[playerid][pInfection] = 0;
            new str2[180];
			format(str2,sizeof(str2),"*"COL_RED" %s(%i) has suffered from an infection and died!",PlayerName(playerid),playerid);
			ProxDetector(60.0, playerid, str2, COLOR_GREY);
			SendClientMessage(playerid,-1,"*"COL_RED" You suffered from an infection!");
			PlayerTextDrawSetString(playerid, LegBroken[playerid], "Broken Leg");
			PlayerTextDrawHide(playerid, LegBroken[playerid]);
			SetPlayerDrunkLevel(playerid, 0);
			StopTimer(pInfo[playerid][Bleeding]);
		}

		if(IsBeingSpeced[playerid] == 1)
	    {
	        foreach (new i : Player)
	        {
	            if(spectatorid[i] == playerid)
	            {
	                TogglePlayerSpectating(i,false);
	                giveWeaponAllow[i] = 1;
	            }
	        }
	    }
	    Handup[playerid] = 0;
	}

   	new time = gettime();
    switch(time - LastDeath[playerid])
    {
        case 0..3:
        {
            DeathSpam[playerid]++;
            if(DeathSpam[playerid] == 3)
            {
				jBan(playerid, -1, "Fake Kill Hack", 0);
                return 1;
            }
        }
        default: DeathSpam[playerid] = 0;
    }
    LastDeath[playerid] = time;
	return 1;
}

public OnPlayerText(playerid, text[])
{
    if(pInfo[playerid][IsPlayerMuted] == 1)
    {
        SendClientMessage(playerid,-1,"*"COL_RED" You are muted!");
	}
	else
	{
		new message[257];

		if(pInfo[playerid][pPremium] == 0)
		{
 			format(message, sizeof(message), "%s says: %s", PlayerName(playerid), text);
	    	ProxDetector(20.0, playerid, message, COLOR_GREY);
		}
		else
		{
 			format(message, sizeof(message), ""COL_WHITE"[%s]"COL_GREY" %s says: %s",GetPremiumName(playerid),PlayerName(playerid), text);
	    	ProxDetector(30.0, playerid, message, COLOR_GREY);
		}

	    if(strfind(text, ":", true) != -1)
		{
			new i_numcount, i_period, i_pos;
			while(text[i_pos])
			{
				if('0' <= text[i_pos] <= '9') i_numcount ++;
				else if(text[i_pos] == '.') i_period ++;
				i_pos++;
			}
			if(i_numcount >= 8 && i_period >= 3)
			{
				jBan(playerid, -1, "Advertisement", 60);
				return 0;
			}
		}
	}
	return 0;
}

public OnPlayerStateChange(playerid, PLAYER_STATE:newstate, PLAYER_STATE:oldstate)
{
    if(oldstate == PLAYER_STATE_ONFOOT && newstate == PLAYER_STATE_DRIVER)
    {
        if(IsPlayerInAnyVehicle(playerid))
        {
			DayZSA_SetPlayerNoiseLevel(playerid,4);
			DayZSA_SetPlayerEyeLevel(playerid,3);

			new i = GetPlayerVehicleID(playerid);
			if(pInfo[playerid][pPremium] == 1)
			{
				if(vInfo[i][vehicleFuel] == 0)
				{
					if(vInfo[i][vehicleTires] == 0)
					{
						if(vInfo[i][vehicleEngine] == 0)
						{
							vInfo[i][vehicleTires] = 1;
						}
					}
				}
			}

			if(pInfo[playerid][pPremium] == 2)
			{
				if(vInfo[i][vehicleFuel] == 0)
				{
					if(vInfo[i][vehicleTires] == 0)
					{
						if(vInfo[i][vehicleEngine] == 0)
						{
							vInfo[i][vehicleTires] = 2;
							vInfo[i][vehicleEngine] = 1;
						}
					}
				}
			}

			if(pInfo[playerid][pPremium] == 3)
			{
				if(vInfo[i][vehicleFuel] == 0)
				{
					if(vInfo[i][vehicleTires] == 0)
					{
						if(vInfo[i][vehicleEngine] == 0)
						{
							vInfo[i][vehicleTires] = 2;
							vInfo[i][vehicleEngine] = 1;
							vInfo[i][vehicleFuel] = 80;
						}
					}
				}
			}

			if(pInfo[playerid][pPremium] == 4)
			{
				if(vInfo[i][vehicleFuel] == 0)
				{
					if(vInfo[i][vehicleTires] == 0)
					{
						if(vInfo[i][vehicleEngine] == 0)
						{
							vInfo[i][vehicleTires] = 3;
							vInfo[i][vehicleEngine] = 1;
							vInfo[i][vehicleFuel] += random(80);
						}
					}
				}
			}
		}
    }

    if(oldstate == PLAYER_STATE_DRIVER && newstate == PLAYER_STATE_ONFOOT)
    {
    	PlayerTextDrawHide(playerid, vehicleInfo[playerid]);
		PlayerTextDrawHide(playerid, VehicleBG[playerid]);
		PlayerTextDrawHide(playerid, EngineIcon[playerid]);
		PlayerTextDrawHide(playerid, SpeedIcon[playerid]);
		PlayerTextDrawHide(playerid, TireIcon[playerid]);
		PlayerTextDrawHide(playerid, FuelIcon[playerid]);
		PlayerTextDrawHide(playerid, PlayerVehicleName[playerid]);
        DayZSA_SetPlayerNoiseLevel(playerid,3);
        DayZSA_SetPlayerEyeLevel(playerid,2);
	}

	if(oldstate == PLAYER_STATE_PASSENGER && newstate == PLAYER_STATE_ONFOOT)
	{
    	PlayerTextDrawHide(playerid, vehicleInfo[playerid]);
		PlayerTextDrawHide(playerid, VehicleBG[playerid]);
		PlayerTextDrawHide(playerid, EngineIcon[playerid]);
		PlayerTextDrawHide(playerid, SpeedIcon[playerid]);
		PlayerTextDrawHide(playerid, TireIcon[playerid]);
		PlayerTextDrawHide(playerid, FuelIcon[playerid]);
		PlayerTextDrawHide(playerid, PlayerVehicleName[playerid]);
        DayZSA_SetPlayerNoiseLevel(playerid,3);
        DayZSA_SetPlayerEyeLevel(playerid,2);
	}

 	if(newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER)
    {
        if(IsBeingSpeced[playerid] == 1)
        {
            foreach (new i : Player)
            {
                if(spectatorid[i] == playerid)
                {
                    PlayerSpectateVehicle(i, GetPlayerVehicleID(playerid));
                }
            }
        }
    }

    if(newstate == PLAYER_STATE_ONFOOT)
    {
        if(IsBeingSpeced[playerid] == 1)
        {
            foreach (new i : Player)
            {
                if(spectatorid[i] == playerid)
                {
                    PlayerSpectatePlayer(i, playerid);
                }
            }
        }
    }

    if(newstate == PLAYER_STATE_DRIVER && pInfo[playerid][pAdminLevel] <= 0)
    {
        if(GetPlayerVehicleID(playerid) != p_CarWarpVehicleID[playerid])
        {
            if(p_CarWarpTime[ playerid ] > gettime())
            {
				ReportSuspect(playerid, "fast vehicle switching");
                return 1;
            }
            p_CarWarpTime[playerid] = gettime() + 1;
            p_CarWarpVehicleID[playerid] = GetPlayerVehicleID(playerid);
        }
    }
	return 1;
}

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	return 1;
}

public OnPlayerExitVehicle(playerid, vehicleid)
{
	return 1;
}

public OnVehicleMod(playerid, vehicleid, componentid)
{
	jBan(playerid, -1, "Vehicle Mod Hack", 0);
    return 0;
}

public OnObjectMoved(objectid)
{
	return 1;
}

public OnPlayerObjectMoved(playerid, objectid)
{
	return 1;
}

public OnPlayerPickUpPickup(playerid, pickupid)
{
	return 1;
}

