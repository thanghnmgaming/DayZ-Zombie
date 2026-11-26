forward RespawnGeneral();
public RespawnGeneral()
{
    DayZSA_RespawnItems();
    return 1;
}

forward UpdateWeather();
public UpdateWeather()
{
	switch(random(5))
    {
        case 0: SetWeatherEx(3); // Sunny
        case 1: SetWeatherEx(7); // Cloudy
        case 2: SetWeatherEx(15); // Cloudy 2
        case 3: SetWeatherEx(8); // Rainy
        case 4: SetWeatherEx(9); // Foggy
    }
	return 1;
}

forward UpdateServer();
public UpdateServer()
{
	if(PlayersAlive >= 1)
	{
		if(gettime() - 180 > ServerLimit[RandomMessage])
		{
			new randomMsg = random(sizeof(randomMessages));
			SendClientMessageToAll(-1, randomMessages[randomMsg]);
			ServerLimit[RandomMessage] = gettime();
		}

		if(gettime() - 60 > ServerLimit[TimeCheck])
		{
			ChangeServerTime();
			ServerLimit[TimeCheck] = gettime();
		}

/*		if(gettime() - 1800 > ServerLimit[WeatherCheck])
		{
			WeatherUpdate();
			ServerLimit[WeatherCheck] = gettime();
		}
*/

		if(gettime() - 108000 > ServerLimit[TentRespawn])
		{
			for(new iv2 = 0; iv2 < 500; iv2++)
		 	{
			    DestroyDynamicObject(Tent[iv2][TentID]);
			    DestroyDynamic3DTextLabel(Tent[iv2][tentText]);
   				Tent[iv2][xTent] = 0.0;
				Tent[iv2][yTent] = 0.0;
				Tent[iv2][zTent] = 0.0;
				tentCount = 0;
			}

			foreach (new i : Player)
			{
			   	if(!IsPlayerNPC(i))
   				{
					PlayerLabel[i] = CreateDynamic3DTextLabel("" , 0xADFF2FAA, 0.0, 0.0, 0.2, 15.0, i, INVALID_VEHICLE_ID, 1, -1, -1, -1, 100.0);
				}
			}

			ServerLimit[TentRespawn] = gettime();
		}

  		for(new iv = 0; iv < MAX_VEHICLES; iv++)
	    {
	        GetVehiclePos(iv, x2d, y2d, z2d);

	        vInfo[iv][vX] = x2d;
	        vInfo[iv][vY] = y2d;
	        vInfo[iv][vZ] = z2d;
		}
	}
	return 1;
}

forward UpdatePlayer();
public UpdatePlayer()
{
	if(PlayersAlive >= 1)
	{
		foreach (new i : Player)
		{
		    if(!IsPlayerNPC(i))
		    {
		        if(isPlayerInMenu[i] == 0)
		        {
				    if(pInfo[i][pLogged] == 1)
				    {
				        if(pInfo[i][pIsSpawned] == 1)
				        {
				            SetPlayerHealth(i,100.0);
				    		CheckBars(i);
				    		DecreaseBars(i);
				            pInfo[i][pAliveTime]++;
				            UpdatePlayer3DName(i);

		                    if(IsSpecing[i] == 0)
		                    {
								format(strupdate,sizeof(strupdate),"Zombies Killed: %i~n~Headshots: %i~n~Murders: %i~n~Bandits Killed: %i~n~Blood: %i~n~Zombies: %i~n~Temperature: %0.2f F~n~Alive Time: %s~n~Name: %s",
								pInfo[i][ZombiesKilled],pInfo[i][Headshots],pInfo[i][Murders],pInfo[i][BanditsKilled],pInfo[i][pBlood],ZombiesAlive,pInfo[i][pTemp],TimeConvert(pInfo[i][pAliveTime]),PlayerName(i));
		                        format(strwep, sizeof(strwep), "%s / %i Ammo", DayZSA_GetWeaponName(i),GetPlayerAmmo(i));
								PlayerTextDrawSetString(i,DebugInfo[i],strupdate);
								PlayerTextDrawSetString(i,Debug_GunInfo[i],strwep);
							}
							else
							{
								format(strupdate,sizeof(strupdate),"Zombies Killed: %i~n~Headshots: %i~n~Murders: %i~n~Bandits Killed: %i~n~Zombies: %i~n~Temperature: %0.2f F~n~Alive Time: %s~n~Name: %s",
								pInfo[spectatorid[i]][ZombiesKilled],pInfo[spectatorid[i]][Headshots],pInfo[spectatorid[i]][Murders],pInfo[spectatorid[i]][BanditsKilled],ZombiesAlive,pInfo[spectatorid[i]][pTemp],TimeConvert(pInfo[spectatorid[i]][pAliveTime]),PlayerName(spectatorid[i]));
								format(strwep, sizeof(strwep), "%s / %i Ammo", DayZSA_GetWeaponName(spectatorid[i]),GetPlayerAmmo(spectatorid[i]));
								PlayerTextDrawSetString(i,DebugInfo[i],strupdate);
								PlayerTextDrawSetString(i,Debug_GunInfo[i],strwep);
								//format(strupdate,sizeof(strupdate),"Zombies Killed: %i~n~Headshots: %i~n~Murders: %i~n~Bandits Killed: %i~n~Blood: %i~n~Zombies Alive: %i(%i)~n~Temperature: %0.2f F~n~Alive Time: %s~n~Wep: %s / %i AMMO~n~Name: %s",
								//pInfo[spectatorid[i]][ZombiesKilled], pInfo[spectatorid[i]][Headshots],pInfo[spectatorid[i]][Murders],pInfo[spectatorid[i]][BanditsKilled],pInfo[spectatorid[i]][pBlood],ZombiesAlive,ZombieMax,pInfo[spectatorid[i]][pTemp],TimeConvert(pInfo[spectatorid[i]][pAliveTime]),DayZSA_GetWeaponName(i),GetPlayerAmmo(i),PlayerName(i));
							}


			                UpdateVehicleStatus(i);
		   					ChangeTextdrawColor(i);
			                UpdateVehicleParts(i);
			                StartVehicle(i);
			                CheckPlayerColor(i);

			                if(GetPlayerPing(i) >= 850)
			                {
			                    SendClientMessage(i, -1, ""chat""COL_RED" You have been kicked. Reason: High Ping Over 850");
			                    KickEx(i);
							}

			                if(pInfo[i][pTemp] >= 87.0)
			                {
			                    pInfo[i][pTemp] = 87.0;
							}

							if(IsPlayerInWater(i))
							{
								pInfo[i][pTemp] -= 0.9;
							}

		     				if(IsPlayerInRangeOfPoint(i,3.5,CampFire[GetCampID(i)][xTent],CampFire[GetCampID(i)][yTent],CampFire[GetCampID(i)][zTent]))
							{
							    if(!IsPlayerMoving(i))
							    {
							    	switch(random(20))
							    	{
										case 2: pInfo[i][pTemp] += 4.0;
										case 8: pInfo[i][pTemp] += 2.1;
									}
								}
							}

							if(pInfo[i][pTemp] <= -00.0)
							{
							    new str2[180];
		     					pInfo[i][pInfection] = 0;
		     					pInfo[i][pTemp] = 100.0;
								format(str2,sizeof(str2),"*"COL_RED" %s(%i) has freezed to death!",PlayerName(i),i);
								ProxDetector(60.0, i, str2, COLOR_GREY);
								SendClientMessage(i,-1,"*"COL_RED" You freezed to death!");
							    SetPlayerHealth(i, 0.0);
							}

							if(IsPlayerInAnyVehicle(i))
							{
								switch(random(40))
		   						{
		    						case 5: pInfo[i][pTemp] += 0.2;
		    						case 10: pInfo[i][pTemp] += 0.3;
		   							case 15: pInfo[i][pTemp] += 0.1;
								}
							}

							if(GetPlayerAnimationIndex(i))
							{
							    new animname[32], animlib[32];
								GetAnimationName(GetPlayerAnimationIndex(i), animlib, sizeof(animlib), animname, sizeof(animname));
			                    if(!strcmp(animname, "IDLE_stance", true) || !strcmp(animname, "IDLE_armed", true) || !strcmp(animname, "IDLE_tired", true))
			                    {
			                        // N / A
								}
								else
								{
									new hour,minute,second;
									gettime(hour,minute,second);
									if(hour < 8 || hour > 21)
									{
										if(IsPlayerMoving(i))
										{
										    switch(random(600))
										    {
					                        	case 50: pInfo[i][pTemp] += 0.1;
					                        	case 12: pInfo[i][pTemp] += 0.4;
					                        	case 16: pInfo[i][pTemp] += 0.6;
					                        	case 200: pInfo[i][pTemp] += 0.5;
					                        	case 1: pInfo[i][pTemp] += 0.6;
					                        	case 7: pInfo[i][pTemp] += 0.7;
					                        	case 170: pInfo[i][pTemp] += 0.5;
											}
										}
									}

									if(hour < 0 || hour > 7)
									{
										if(IsPlayerMoving(i))
										{
										    switch(random(200))
										    {
					                        	case 50: pInfo[i][pTemp] -= 0.9;
					                        	case 12: pInfo[i][pTemp] -= 2.1;
					                        	case 16: pInfo[i][pTemp] -= 5.1;
					                        	case 200: pInfo[i][pTemp] -= 1.3;
					                        	case 1: pInfo[i][pTemp] -= 0.9;
					                        	case 7: pInfo[i][pTemp] -= 3.1;
					                        	case 170: pInfo[i][pTemp] -= 2.1;
											}
										}
									}

									if(GetWeather() == 8 || GetWeather() == 16 || GetWeather() == 9 || GetWeather() == 32)
									{
										if(IsPlayerMoving(i))
										{
										    switch(random(250))
										    {
					                        	case 50: pInfo[i][pTemp] -= 0.9;
					                        	case 12: pInfo[i][pTemp] -= 1.2;
					                        	case 16: pInfo[i][pTemp] -= 1.8;
					                        	case 80: pInfo[i][pTemp] -= 1.2;
											}
										}
									}
									else
									{
										if(IsPlayerMoving(i))
										{
										    switch(random(49))
										    {
					                        	case 3: pInfo[i][pTemp] += 0.4;
					                        	case 9: pInfo[i][pTemp] += 0.2;
					                        	case 10: pInfo[i][pTemp] += 0.2;
					                        	case 26: pInfo[i][pTemp] += 0.3;
					                        	case 48: pInfo[i][pTemp] += 0.5;
											}
										}
									}
								}
							}

							if(pInfo[i][pBlood] <= 8000)
							{
								if(pInfo[i][pFade] == 0)
								{
							    	PlayerTextDrawShow(i, PlayerFade[i]);
									pInfo[i][pFade] = 1;
								}
							}

			                if(PlayerHasItem(i,"None"))
							{
			    				RemoveSlotToInventory(i,"None",1);
							}

							if(PlayerHasItem(i,"Empty Slot"))
							{
								RemoveSlotToInventory(i,"Empty Slot",1);
							}

							if(PlayerHasItem(i,"0\tEmpty Slot"))
							{
								RemoveSlotToInventory(i,"0\tEmpty Slot",1);
							}

							if(PlayerHasItem(i,"mpty Slot"))
							{
								RemoveSlotToInventory(i,"mpty Slot",1);
							}

			  				if(GetPlayerMoney(i) >= 1)
			  				{
								jBan(i, -1, "Money Hack", 0);
							}

							if(GetPlayerSpecialAction(i) == SPECIAL_ACTION_USEJETPACK)
							{
								jBan(i, -1, "Jetpack Hack", 0);
							}

							new Float:armor;
							GetPlayerArmour(i,armor);
							if(armor > 1)
							{
								jBan(i, -1, "Armour Hack", 0);
							}

							if(PlayerHasItem(i,"Coyote Patrol Pack"))
							{
								SendClientMessage(i,-1,"*"COL_RED" You already have an larger backpack!");
								RemoveSlotToInventory(i,"Coyote Patrol Pack",1);
							}

					        if(PlayerHasItem(i,"Czech Vest Pouch"))
							{
							    if(pInfo[i][BackpackSlots] >= 28)
							    {
									SendClientMessage(i,-1,"*"COL_RED" You already have an larger backpack!");
									RemoveSlotToInventory(i,"Czech Vest Pouch",1);
								}
								else
								{
							    	RemovePlayerAttachedObject(i, 1);
							    	pInfo[i][Backpack] = 1;
							    	pInfo[i][BackpackSlots] = 16;
							    	SetPlayerAttachedObject( i, 1, 371, 1, 0.000000, -0.100000, 0.000000, 3.000000, 90.000000, 1.000000, 1.000000, 1.000000, 1.000000);
							    	RemoveSlotToInventory(i,"Czech Vest Pouch",1);
		   							if(!IsPlayerInAnyVehicle(i))
									{
										ApplyAnimation(i, "BOMBER", "BOM_Plant",4.1,false,true,false,1000,1);
										SetTimerEx("ResetAction", 1450, false, "ii", i, ACTION_ANIMATION);
									}
								}
							}

							if(PlayerHasItem(i,"Alice Pack"))
							{
							    if(pInfo[i][BackpackSlots] >= 38)
							    {
									SendClientMessage(i,-1,"*"COL_RED" You already have an larger backpack!");
									RemoveSlotToInventory(i,"Alice Pack",1);
								}
								else
								{
									RemovePlayerAttachedObject(i, 1);
									pInfo[i][Backpack] = 2;
									pInfo[i][BackpackSlots] = 28;
									SetPlayerAttachedObject( i, 1, 1310, 1, 0.000000, -0.100000, 0.000000, 3.000000, 90.000000, 1.000000, 1.000000, 1.000000, 1.000000 );
									RemoveSlotToInventory(i,"Alice Pack",1);
	 								if(!IsPlayerInAnyVehicle(i))
									{
										ApplyAnimation(i, "BOMBER", "BOM_Plant",4.1,false,true,false,1000,1);
										SetTimerEx("ResetAction", 1450, false, "ii", i, ACTION_ANIMATION);
									}
								}
							}

							if(PlayerHasItem(i,"Coyote Backpack"))
							{
								RemovePlayerAttachedObject(i, 1);
								pInfo[i][Backpack] = 3;
								pInfo[i][BackpackSlots] = 38;
								SetPlayerAttachedObject( i, 1, 1550, 1, 0.200000, -0.200000, 0.000000, 0.000000, 85.000000, 0.000000, 1.000000, 1.000000, 1.000000 );
								RemoveSlotToInventory(i,"Coyote Backpack",1);
			    				if(!IsPlayerInAnyVehicle(i))
								{
									ApplyAnimation(i, "BOMBER", "BOM_Plant",4.1,false,true,false,1000,1);
									SetTimerEx("ResetAction", 1450, false, "ii", i, ACTION_ANIMATION);
								}
							}

							if(IsPlayerInWater(i))
							{
								pInfo[i][pHunger]--;
								pInfo[i][pThrist]--;

								if(PlayerHasItem(i,"Empty Water Bottle"))
								{
									RemoveSlotToInventory(i,"Empty Water Bottle",1);
									AddSlotToInventoryWorld(i,"Full Water Bottle",1);
								}

								DayZSA_SetPlayerNoiseLevel(i,4);
								DayZSA_SetPlayerEyeLevel(i,2);
							}

						    new animname[32], animlib[32];

						    GetAnimationName(GetPlayerAnimationIndex(i), animlib, sizeof(animlib), animname, sizeof(animname));
						    if (!strcmp(animname, "SWIM_CRAWL", true) && !IsPlayerInAnyVehicle(i))
						    {
						        new Float:velocityX, Float:velocityY, Float:velocityZ, Float:speed;
						        GetPlayerVelocity(i, velocityX, velocityY, velocityZ);
						        speed = floatsqroot((velocityX * velocityX) + (velocityY * velocityY) + (velocityZ * velocityZ) * 100);
						        if (floatround(speed, floatround_round) >= 3)
						        {
								jBan(i, -1, "Fly Hack", 0);
						        }
					    	}

							if(GetPlayerAnimationIndex(i))
							{
						    	GetAnimationName(GetPlayerAnimationIndex(i), animlib, sizeof(animlib), animname, sizeof(animname));
						    	if(!strcmp(animlib, "PARACHUTE", true) && !strcmp(animname, "FALL_SkyDive_Accel", true))
						    	{
						    	    if(GetPlayerWeapon(i) != 46)
						    	    {
										jBan(i, -1, "Fly Hack", 0);
									}
								}
							}

							if(GetPlayerState(i) == PLAYER_STATE_DRIVER)
					  		{
					    		new vehicleid = GetPlayerVehicleID(i);
								if(DayZSA_GetVehicleSpeed(vehicleid) > MAX_SPEED)
					   			{
					      			if(GetVehicleModel(vehicleid) != 487)
					         		{
					           			new Float:vehicleVelocity[3];
					              		GetVehicleVelocity(vehicleid, vehicleVelocity[0], vehicleVelocity[1], vehicleVelocity[2]);
					                	if(vehicleVelocity[2] > -0.5)
					                 	{
											jBan(i, -1, "Veicle Speed Hack", 0);
										}
									}
								}
							}

							if(GetPlayerState(i) == PLAYER_STATE_PASSENGER || GetPlayerState(i) == PLAYER_STATE_DRIVER)
							{
							    SetPlayerArmedWeapon(i,0);
							}

							if(pInfo[i][pTemp] <= 36.0)
							{
							    if(pInfo[i][pInfection] == 0)
							    {
									switch(random(800))
									{
									    case 257: pInfo[i][pInfection] = 1;
									    case 183: pInfo[i][pInfection] = 1;
									    case 751: pInfo[i][pInfection] = 1;
									    case 521: pInfo[i][pInfection] = 1;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 1;
}

forward AutoSaveAll();
public AutoSaveAll()
{
	new count;
	foreach (new i : Player)
	{
		if(IsPlayerNPC(i) || pInfo[i][pLogged] != 1) continue;
		SaveStats(i);
		count++;
	}
	if(count) printf("[SAVE] %d player(s) saved.", count);
	return 1;
}

