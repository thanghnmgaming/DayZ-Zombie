stock UpdateVehicleStatus(playerid)
{
	if(IsPlayerInAnyVehicle(playerid))
	{
	    new str[128];
	    new strv[128];
    	if(FOUR_TIRE(playerid) || FOUR_TIRE2(playerid))
		{
			format(str,sizeof(str),"%i / 1~n~~n~%i / 4~n~~n~%i ~n~~n~%i KM/H",
			vInfo[GetPlayerVehicleID(playerid)][vehicleEngine],
			vInfo[GetPlayerVehicleID(playerid)][vehicleTires],
			vInfo[GetPlayerVehicleID(playerid)][vehicleFuel],
			GetPlayerVehicleSpeed(playerid));
			PlayerTextDrawSetString(playerid,vehicleInfo[playerid],str);
			PlayerTextDrawShow(playerid, vehicleInfo[playerid]);
			//PlayerTextDrawShow(playerid, VehicleBG[playerid]);
			PlayerTextDrawShow(playerid, EngineIcon[playerid]);
			PlayerTextDrawShow(playerid, SpeedIcon[playerid]);
			PlayerTextDrawShow(playerid, TireIcon[playerid]);
			PlayerTextDrawShow(playerid, FuelIcon[playerid]);
			format(strv,sizeof(strv),"%s",DayZSA_GetVehicleName(GetPlayerVehicleID(playerid)));
			PlayerTextDrawSetString(playerid,PlayerVehicleName[playerid],strv);
			PlayerTextDrawShow(playerid, PlayerVehicleName[playerid]);
		}

		if(TWO_TIRE_VEHICLE)
		{
			format(str,sizeof(str),"%i / 1~n~~n~%i / 2~n~~n~%i ~n~~n~%i KM/H",
			vInfo[GetPlayerVehicleID(playerid)][vehicleEngine],
			vInfo[GetPlayerVehicleID(playerid)][vehicleTires],
			vInfo[GetPlayerVehicleID(playerid)][vehicleFuel],
			GetPlayerVehicleSpeed(playerid));
			PlayerTextDrawSetString(playerid,vehicleInfo[playerid],str);
			PlayerTextDrawShow(playerid, vehicleInfo[playerid]);
			//PlayerTextDrawShow(playerid, VehicleBG[playerid]);
			PlayerTextDrawShow(playerid, EngineIcon[playerid]);
			PlayerTextDrawShow(playerid, SpeedIcon[playerid]);
			PlayerTextDrawShow(playerid, TireIcon[playerid]);
			PlayerTextDrawShow(playerid, FuelIcon[playerid]);
			format(strv,sizeof(strv),"%s",DayZSA_GetVehicleName(GetPlayerVehicleID(playerid)));
			PlayerTextDrawSetString(playerid,PlayerVehicleName[playerid],strv);
			PlayerTextDrawShow(playerid, PlayerVehicleName[playerid]);
		}

		if(SIX_TIRE_VEHICLE)
		{
			
			format(str,sizeof(str),"%i / 1~n~~n~%i / 6~n~~n~%i ~n~~n~%i KM/H",
			vInfo[GetPlayerVehicleID(playerid)][vehicleEngine],
			vInfo[GetPlayerVehicleID(playerid)][vehicleTires],
			vInfo[GetPlayerVehicleID(playerid)][vehicleFuel],
			GetPlayerVehicleSpeed(playerid));
			PlayerTextDrawSetString(playerid,vehicleInfo[playerid],str);
			PlayerTextDrawShow(playerid, vehicleInfo[playerid]);
			//PlayerTextDrawShow(playerid, VehicleBG[playerid]);
			PlayerTextDrawShow(playerid, EngineIcon[playerid]);
			PlayerTextDrawShow(playerid, SpeedIcon[playerid]);
			PlayerTextDrawShow(playerid, TireIcon[playerid]);
			PlayerTextDrawShow(playerid, FuelIcon[playerid]);
			format(strv,sizeof(strv),"%s",DayZSA_GetVehicleName(GetPlayerVehicleID(playerid)));
			PlayerTextDrawSetString(playerid,PlayerVehicleName[playerid],strv);
			PlayerTextDrawShow(playerid, PlayerVehicleName[playerid]);
		}

		if(NO_TIRE_VEHICLE)
		{
			
			format(str,sizeof(str),"0 / 0~n~~n~0 / 0~n~~n~0 ~n~~n~%i KM/H",
			vInfo[GetPlayerVehicleID(playerid)][vehicleEngine],
			vInfo[GetPlayerVehicleID(playerid)][vehicleTires],
			vInfo[GetPlayerVehicleID(playerid)][vehicleFuel],
			GetPlayerVehicleSpeed(playerid));
			PlayerTextDrawSetString(playerid,vehicleInfo[playerid],str);
			PlayerTextDrawShow(playerid, vehicleInfo[playerid]);
			//PlayerTextDrawShow(playerid, VehicleBG[playerid]);
			PlayerTextDrawShow(playerid, EngineIcon[playerid]);
			PlayerTextDrawShow(playerid, SpeedIcon[playerid]);
			PlayerTextDrawShow(playerid, TireIcon[playerid]);
			PlayerTextDrawShow(playerid, FuelIcon[playerid]);
			format(strv,sizeof(strv),"%s",DayZSA_GetVehicleName(GetPlayerVehicleID(playerid)));
			PlayerTextDrawSetString(playerid,PlayerVehicleName[playerid],strv);
			PlayerTextDrawShow(playerid, PlayerVehicleName[playerid]);
		}

		if(ENGINE_ONLY_VEHICLE)
		{
			format(str,sizeof(str),"%i / 1~n~~n~0 / 0~n~~n~%i ~n~~n~%i KM/H",
			vInfo[GetPlayerVehicleID(playerid)][vehicleEngine],
			vInfo[GetPlayerVehicleID(playerid)][vehicleFuel],
			GetPlayerVehicleSpeed(playerid));
			PlayerTextDrawSetString(playerid,vehicleInfo[playerid],str);
			PlayerTextDrawShow(playerid, vehicleInfo[playerid]);
			//PlayerTextDrawShow(playerid, VehicleBG[playerid]);
			PlayerTextDrawShow(playerid, EngineIcon[playerid]);
			PlayerTextDrawShow(playerid, SpeedIcon[playerid]);
			PlayerTextDrawShow(playerid, TireIcon[playerid]);
			PlayerTextDrawShow(playerid, FuelIcon[playerid]);
			format(strv,sizeof(strv),"%s",DayZSA_GetVehicleName(GetPlayerVehicleID(playerid)));
			PlayerTextDrawSetString(playerid,PlayerVehicleName[playerid],strv);
			PlayerTextDrawShow(playerid, PlayerVehicleName[playerid]);
		}
	}

	new i = GetPlayerVehicleID(playerid);
	if(vInfo[i][vehicleFuel] == 0)
	{
		SetVehicleParamsEx(GetPlayerVehicleID(playerid),0,lights,alarm,doors,bonnet,boot,objective);
	}

	if(vInfo[i][vehicleEngine] == 0)
	{
		SetVehicleParamsEx(GetPlayerVehicleID(playerid),0,lights,alarm,doors,bonnet,boot,objective);
	}


	if(vInfo[GetPlayerVehicleID(playerid)][vehicleFuel] >= 101)
	{
	    vInfo[GetPlayerVehicleID(playerid)][vehicleFuel] = 100;
	}
	return 1;
}

stock StartVehicle(playerid)
{
	new i = GetPlayerVehicleID(playerid);
	GetVehicleParamsEx(GetPlayerVehicleID(playerid),engine,lights,alarm,doors,bonnet,boot,objective);
	if(FOUR_TIRE(playerid) || FOUR_TIRE2(playerid))
	{
		if(vInfo[i][vehicleFuel] >= 1)
		{
			if(vInfo[i][vehicleTires] == 4)
			{
				if(vInfo[i][vehicleEngine] == 1)
				{
					SetVehicleParamsEx(GetPlayerVehicleID(playerid),1,lights,alarm,doors,bonnet,boot,objective);
				}
			}
		}

		if(vInfo[i][vehicleTires] <= 3)
		{
			SetVehicleParamsEx(GetPlayerVehicleID(playerid),0,lights,alarm,doors,bonnet,boot,objective);
		}
	}

	if(TWO_TIRE_VEHICLE)
	{
		if(vInfo[i][vehicleFuel] >= 1)
		{
			if(vInfo[i][vehicleTires] == 2)
			{
				if(vInfo[i][vehicleEngine] == 1)
				{
					SetVehicleParamsEx(GetPlayerVehicleID(playerid),1,lights,alarm,doors,bonnet,boot,objective);
				}
			}
		}

		if(vInfo[i][vehicleTires] <= 1)
		{
			SetVehicleParamsEx(GetPlayerVehicleID(playerid),0,lights,alarm,doors,bonnet,boot,objective);
		}
	}

	if(SIX_TIRE_VEHICLE)
	{
		if(vInfo[i][vehicleFuel] >= 1)
		{
			if(vInfo[i][vehicleTires] == 6)
			{
				if(vInfo[i][vehicleEngine] == 1)
				{
					SetVehicleParamsEx(GetPlayerVehicleID(playerid),1,lights,alarm,doors,bonnet,boot,objective);
				}
			}
		}

		if(vInfo[i][vehicleTires] <= 5)
		{
			SetVehicleParamsEx(GetPlayerVehicleID(playerid),0,lights,alarm,doors,bonnet,boot,objective);
		}
	}

	if(ENGINE_ONLY_VEHICLE)
	{
	    if(vInfo[i][vehicleFuel] >= 1)
	    {
	        if(vInfo[i][vehicleEngine] == 1)
	        {
 	           SetVehicleParamsEx(GetPlayerVehicleID(playerid),1,lights,alarm,doors,bonnet,boot,objective);
	        }
		 }
	}

	if(NO_TIRE_VEHICLE)
	{
	    SetVehicleParamsEx(GetPlayerVehicleID(playerid),1,lights,alarm,doors,bonnet,boot,objective);
	}
	return 1;
}

stock Float:GetVehicleSpeed(vehicleid,UseMPH = 0)
{
    new Float:speed_x,Float:speed_y,Float:speed_z,Float:temp_speed;
    GetVehicleVelocity(vehicleid,speed_x,speed_y,speed_z);
    if(UseMPH == 0)
    {
        temp_speed = floatsqroot(((speed_x*speed_x)+(speed_y*speed_y))+(speed_z*speed_z))*136.666667;
    } else {
        temp_speed = floatsqroot(((speed_x*speed_x)+(speed_y*speed_y))+(speed_z*speed_z))*85.4166672;
    }
    floatround(temp_speed,floatround_round);return temp_speed;
}

stock CheckVehicleStatusGlobal(playerid)
{
	if(IsPlayerInAnyVehicle(playerid))
	{
		new i = GetPlayerVehicleID(playerid);
		GetVehicleParamsEx(GetPlayerVehicleID(playerid),engine,lights,alarm,doors,bonnet,boot,objective);
		if(FOUR_TIRE(playerid) || FOUR_TIRE2(playerid))
		{
			if(vInfo[i][vehicleFuel] >= 1)
			{
				if(vInfo[i][vehicleTires] == 4)
				{
					if(vInfo[i][vehicleEngine] == 1)
					{
					    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
					    {
					        if(GetVehicleSpeed(GetPlayerVehicleID(playerid), 1) >= 5)
					        {
								vInfo[i][vehicleFuel]--;
							}
						}
					}
				}
			}
		}

		if(TWO_TIRE_VEHICLE)
		{
			if(vInfo[i][vehicleFuel] >= 1)
			{
				if(vInfo[i][vehicleTires] == 2)
				{
					if(vInfo[i][vehicleEngine] == 1)
					{
	    				if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
					    {
					        if(GetVehicleSpeed(GetPlayerVehicleID(playerid), 1) >= 5)
					        {
								vInfo[i][vehicleFuel]--;
							}
						}
					}
				}
			}
		}

		if(SIX_TIRE_VEHICLE)
		{
			if(vInfo[i][vehicleFuel] >= 1)
			{
				if(vInfo[i][vehicleTires] == 6)
				{
					if(vInfo[i][vehicleEngine] == 1)
					{
	    				if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
					    {
					        if(GetVehicleSpeed(GetPlayerVehicleID(playerid), 1) >= 5)
					        {
								vInfo[i][vehicleFuel]--;
							}
						}
					}
				}
			}
		}

		if(ENGINE_ONLY_VEHICLE)
		{
		    if(vInfo[i][vehicleFuel] >= 1)
		    {
		        if(vInfo[i][vehicleEngine] == 1)
		        {
		    		if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
		    		{
        				if(GetVehicleSpeed(GetPlayerVehicleID(playerid), 1) >= 5)
        				{
							vInfo[i][vehicleFuel]--;
						}
					}
				}
			}
		}
	}
	return 1;
}

stock CreateBases()
{
	// ** ADDITONAL MAPPING BY ALDENJ ** //

	CreateDynamicObject(13591,2124.3999000,957.4000200,10.3000000,0.0000000,0.0000000,0.0000000); //object(kickcar28)(1)
	CreateDynamicObject(13591,268.2999900,2534.3000500,16.3000000,0.0000000,0.0000000,0.0000000); //object(kickcar28)(2)
	CreateDynamicObject(3399,182.7000000,1822.1999500,18.2000000,0.0000000,338.0000000,90.0000000); //object(cxrf_a51_stairs)(1)
	CreateDynamicObject(1225,-1479.0000000,454.2999900,6.6000000,0.0000000,0.0000000,0.0000000); //object(barrel4)(1)
	CreateDynamicObject(1225,-1559.1999500,538.2000100,6.4000000,0.0000000,0.0000000,0.0000000); //object(barrel4)(2)
	CreateDynamicObject(2780,-1671.5999800,451.7999900,2.7000000,0.0000000,0.0000000,0.0000000); //object(cj_smoke_mach)(1)
	CreateDynamicObject(2985,-1524.5999800,485.1000100,9.6000000,0.0000000,0.0000000,140.0000000); //object(minigun_base)(1)
	CreateDynamicObject(2921,-1525.9000200,482.7000100,9.2000000,0.0000000,0.0000000,0.0000000); //object(kmb_cam)(1)
	CreateDynamicObject(2899,-1529.6999500,481.0000000,6.3000000,0.0000000,0.0000000,90.0000000); //object(temp_stinger2)(1)
	CreateDynamicObject(3794,-1537.8000500,480.6000100,6.8000000,0.0000000,0.0000000,0.0000000); //object(missile_07_sfxr)(1)
	CreateDynamicObject(16644,-1652.5999800,434.2000100,6.3000000,0.0000000,0.0000000,0.0000000); //object(a51_ventsouth)(1)

	/*
	Objects converted: 11
	Vehicles converted: 0
	Vehicle models found: 0
	----------------------
	In the time this conversion took to finish the US national debt has risen by about $214.97!
	*/


	// ** ISLAND BY [pGA]Cold ** //
	CreateVehicle(468,-5058.1000977,-2700.8999023,3.4000001,202.0000000,-1,-1,0); //Sanchez
	CreateDynamicObject(17083,-4992.7998047,-2682.5996094,38.2000008,359.5001221,358.7365723,283.2330322); //object(cuntwland08b) (1)
	CreateDynamicObject(17090,-4879.7001953,-2948.0000000,35.4000015,0.0000000,359.2419434,282.7276611); //object(cuntwland16b) (1)
	CreateDynamicObject(17098,-4811.2001953,-3110.3994141,15.0000000,355.7427979,357.7423096,329.8205566); //object(cuntwland24b) (1)
	CreateDynamicObject(17098,-4938.3994141,-3133.0996094,12.3999996,1.2448120,354.7487793,321.6107178); //object(cuntwland24b) (2)
	CreateDynamicObject(17091,-4654.8994141,-2879.3994141,28.2999992,0.0000000,359.2419434,282.7276611); //object(cuntwland17_de) (1)
	CreateDynamicObject(17082,-4649.0000000,-2541.0000000,-13.1999998,0.0000000,358.7475586,283.2468262); //object(cuntwland07b) (2)
	CreateDynamicObject(17098,-4689.7998047,-3077.8994141,14.1999998,355.7482910,357.7423096,319.8315430); //object(cuntwland24b) (1)
	CreateDynamicObject(17098,-4555.0000000,-3040.6992188,17.3999996,355.7427979,357.7423096,319.8229980); //object(cuntwland24b) (1)
	CreateDynamicObject(17098,-4506.2001953,-2964.6992188,4.9000001,355.7427979,357.7423096,49.8284912); //object(cuntwland24b) (1)
	CreateDynamicObject(17098,-5100.7998047,-3021.8000488,13.8000002,1.2367249,352.7480469,297.6516113); //object(cuntwland24b) (2)
	CreateDynamicObject(17098,-5102.2001953,-2896.3994141,21.1000004,5.4821777,357.7368164,198.4570312); //object(cuntwland24b) (1)
	CreateDynamicObject(3418,-4875.5000000,-2948.0000000,34.5999985,0.0000000,0.0000000,59.9743652); //object(ce_oldhut02) (1)
	CreateDynamicObject(3415,-4877.0996094,-2967.3994141,32.9000015,0.0000000,0.0000000,115.9991455); //object(ce_loghut1) (1)
	CreateDynamicObject(3414,-4842.0000000,-2989.3994141,35.4000015,0.0000000,0.0000000,189.9975586); //object(ce_oldhut1) (1)
	CreateDynamicObject(1463,-4846.3999023,-2962.8999023,33.0999985,0.0000000,0.0000000,0.0000000); //object(dyn_woodpile2) (1)
	CreateDynamicObject(1463,-4848.3999023,-2962.8999023,33.0999985,0.0000000,0.0000000,0.0000000); //object(dyn_woodpile2) (2)
	CreateDynamicObject(1463,-4847.3999023,-2963.8000488,33.0999985,0.0000000,0.0000000,0.0000000); //object(dyn_woodpile2) (3)
	CreateDynamicObject(1463,-4847.2998047,-2961.8999023,33.0999985,0.0000000,0.0000000,0.0000000); //object(dyn_woodpile2) (4)
	CreateDynamicObject(1463,-4847.2001953,-2962.7998047,33.7000008,0.0000000,0.0000000,0.0000000); //object(dyn_woodpile2) (5)
	CreateDynamicObject(3461,-4847.3999023,-2962.8000488,32.2000008,0.0000000,0.0000000,0.0000000); //object(tikitorch01_lvs) (1)
	CreateDynamicObject(3461,-4847.2998047,-2963.6000977,31.7000008,0.0000000,0.0000000,0.0000000); //object(tikitorch01_lvs) (2)
	CreateDynamicObject(3461,-4847.1000977,-2962.1000977,31.7999992,0.0000000,0.0000000,0.0000000); //object(tikitorch01_lvs) (3)
	CreateDynamicObject(3461,-4846.2998047,-2962.8999023,31.3999996,0.0000000,0.0000000,0.0000000); //object(tikitorch01_lvs) (4)
	CreateDynamicObject(3461,-4848.2998047,-2963.0996094,31.2000008,0.0000000,0.0000000,0.0000000); //object(tikitorch01_lvs) (5)
	CreateDynamicObject(3414,-4726.8999023,-2651.3999023,102.1999969,0.0000000,0.0000000,327.9969482); //object(ce_oldhut1) (2)
	CreateDynamicObject(3425,-4831.8999023,-3003.8000488,44.7999992,0.0000000,0.0000000,7.7500000); //object(nt_windmill) (1)
	CreateDynamicObject(3286,-4884.7998047,-2988.5996094,38.0000000,0.0000000,0.0000000,13.2495117); //object(cxrf_watertwr) (1)
	CreateDynamicObject(3403,-4865.0000000,-2983.3994141,36.0999985,0.0000000,0.0000000,325.9973145); //object(sw_logcover) (1)
	CreateDynamicObject(13206,-4781.7001953,-2963.1999512,33.0000000,0.0000000,0.0000000,54.0000000); //object(cetruth_barn02) (1)
	CreateDynamicObject(17039,-4788.7998047,-2934.8994141,32.5999985,0.0000000,0.0000000,317.9937744); //object(cuntw_weebarn1_) (1)
	CreateDynamicObject(3415,-4809.7001953,-2932.6992188,32.5000000,0.0000000,0.0000000,11.9970703); //object(ce_loghut1) (2)
	CreateDynamicObject(3415,-4796.8994141,-2974.2998047,33.0999985,0.0000000,0.0000000,191.9970551); //object(ce_loghut1) (3)
	CreateDynamicObject(1463,-4801.2001953,-2953.3000488,33.0999985,0.0000000,0.0000000,0.0000000); //object(dyn_woodpile2) (7)
	CreateDynamicObject(1463,-4800.7998047,-2954.6000977,33.0999985,0.0000000,0.0000000,0.0000000); //object(dyn_woodpile2) (8)
	CreateDynamicObject(1463,-4802.2998047,-2953.6999512,33.0999985,0.0000000,0.0000000,0.0000000); //object(dyn_woodpile2) (9)
	CreateDynamicObject(3461,-4801.1000977,-2953.3999023,31.5000000,0.0000000,0.0000000,0.0000000); //object(tikitorch01_lvs) (6)
	CreateDynamicObject(3461,-4802.2001953,-2953.7998047,31.7000008,0.0000000,0.0000000,0.0000000); //object(tikitorch01_lvs) (7)
	CreateDynamicObject(3461,-4800.7998047,-2954.6992188,31.6000004,0.0000000,0.0000000,0.0000000); //object(tikitorch01_lvs) (8)
	CreateDynamicObject(791,-4762.1000977,-3093.8000488,30.7000008,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (1)
	CreateDynamicObject(791,-4722.6000977,-3081.6999512,35.7000008,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (2)
	CreateDynamicObject(791,-4729.8999023,-3130.1000977,34.7000008,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (3)
	CreateDynamicObject(791,-4663.8999023,-3128.6000977,35.4000015,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (4)
	CreateDynamicObject(791,-4650.0000000,-3078.3999023,35.2000008,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (5)
	CreateDynamicObject(791,-4672.2001953,-3046.6000977,34.5000000,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (6)
	CreateDynamicObject(791,-4616.7998047,-3131.8999023,25.7000008,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (7)
	CreateDynamicObject(791,-4605.8999023,-3069.3999023,26.6000004,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (8)
	CreateDynamicObject(791,-4569.8999023,-3105.8000488,33.5999985,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (9)
	CreateDynamicObject(791,-4507.5000000,-3069.6000977,33.7000008,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (10)
	CreateDynamicObject(791,-4454.8999023,-3057.3999023,34.5000000,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (11)
	CreateDynamicObject(791,-4448.7998047,-3018.8000488,20.0000000,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (12)
	CreateDynamicObject(791,-4497.3999023,-3023.6999512,34.0999985,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (13)
	CreateDynamicObject(791,-4542.8999023,-3016.0000000,47.2999992,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (14)
	CreateDynamicObject(791,-4584.2998047,-3018.6999512,40.7999992,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (15)
	CreateDynamicObject(791,-4801.5000000,-3151.3000488,40.0999985,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (16)
	CreateDynamicObject(791,-4812.2998047,-3090.3999023,39.7999992,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (17)
	CreateDynamicObject(791,-4847.6000977,-3118.6999512,36.2000008,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (18)
	CreateDynamicObject(791,-4850.5000000,-3175.8999023,32.0000000,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (19)
	CreateDynamicObject(791,-4905.5000000,-3161.1999512,29.2999992,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (20)
	CreateDynamicObject(791,-4897.2998047,-3114.1000977,34.0999985,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (21)
	CreateDynamicObject(791,-4947.2998047,-3105.5000000,48.5999985,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (22)
	CreateDynamicObject(791,-4947.6000977,-3137.6999512,31.2000008,0.0000000,0.0000000,24.0000000); //object(vbg_fir_copse) (23)
	CreateDynamicObject(791,-5061.0000000,-2999.5000000,43.4000015,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (24)
	CreateDynamicObject(791,-5026.3999023,-3037.6999512,38.7999992,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (25)
	CreateDynamicObject(791,-5000.3999023,-3101.8000488,44.7999992,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (26)
	CreateDynamicObject(791,-4986.2001953,-3058.0000000,40.7000008,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (27)
	CreateDynamicObject(791,-5034.7001953,-3080.3000488,42.4000015,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (28)
	CreateDynamicObject(791,-5109.6000977,-3000.5000000,36.5999985,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (29)
	CreateDynamicObject(791,-5082.7998047,-3034.5000000,31.5000000,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (30)
	CreateDynamicObject(791,-5066.5000000,-3069.5000000,31.3999996,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (31)
	CreateDynamicObject(791,-5136.7998047,-3013.8000488,29.6000004,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (32)
	CreateDynamicObject(791,-5179.2998047,-3012.6999512,32.4000015,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (33)
	CreateDynamicObject(791,-5214.1000977,-2988.1999512,40.4000015,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (34)
	CreateDynamicObject(791,-5077.7998047,-2935.0000000,53.0000000,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (35)
	CreateDynamicObject(791,-5083.2998047,-2886.3000488,42.7999992,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (36)
	CreateDynamicObject(791,-5127.7998047,-2928.3000488,36.2000008,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (37)
	CreateDynamicObject(791,-5153.0000000,-2960.8999023,37.7999992,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (38)
	CreateDynamicObject(791,-5198.3999023,-2951.5000000,36.0000000,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (39)
	CreateDynamicObject(791,-5175.2001953,-2916.1999512,32.9000015,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (40)
	CreateDynamicObject(791,-5130.5000000,-2884.8000488,35.7999992,0.0000000,0.0000000,358.0000000); //object(vbg_fir_copse) (41)
	CreateDynamicObject(791,-4558.8999023,-3060.1999512,38.2000008,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (42)
	CreateDynamicObject(791,-4515.1000977,-2952.3000488,27.6000004,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (43)
	CreateDynamicObject(791,-4490.7001953,-2921.8999023,20.2999992,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (44)
	CreateDynamicObject(791,-4488.8999023,-2877.3999023,24.0000000,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (45)
	CreateDynamicObject(791,-4489.2001953,-2840.1000977,21.2000008,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (46)
	CreateDynamicObject(791,-4536.6000977,-2871.3000488,16.1000004,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (47)
	CreateDynamicObject(791,-4527.8999023,-2908.6000977,21.2000008,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (48)
	CreateDynamicObject(791,-4544.1000977,-2947.5000000,33.2999992,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (49)
	CreateDynamicObject(791,-4474.1000977,-2962.1999512,13.1999998,0.0000000,0.0000000,84.0000000); //object(vbg_fir_copse) (50)
	CreateDynamicObject(791,-4456.0000000,-2898.1999512,16.7000008,0.0000000,0.0000000,83.9959717); //object(vbg_fir_copse) (51)
	CreateDynamicObject(791,-4455.2001953,-2839.3999023,23.6000004,0.0000000,0.0000000,12.0000000); //object(vbg_fir_copse) (52)
	CreateDynamicObject(791,-4872.7001953,-2844.6000977,54.5999985,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (53)
	CreateDynamicObject(791,-4828.5000000,-2844.6999512,59.7999992,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (54)
	CreateDynamicObject(791,-4787.0000000,-2832.6000977,56.9000015,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (55)
	CreateDynamicObject(791,-4744.1000977,-2828.8000488,57.9000015,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (56)
	CreateDynamicObject(791,-4704.8999023,-2826.6999512,57.7000008,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (57)
	CreateDynamicObject(791,-4722.2001953,-2846.1000977,52.4000015,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (58)
	CreateDynamicObject(791,-4674.3999023,-2835.5000000,55.0000000,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (59)
	CreateDynamicObject(791,-4636.5000000,-2822.1000977,46.2999992,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (60)
	CreateDynamicObject(791,-4625.5000000,-2788.5000000,49.2999992,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (61)
	CreateDynamicObject(791,-4634.2998047,-2741.8000488,42.2000008,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (62)
	CreateDynamicObject(791,-4664.7001953,-2774.5000000,71.6999969,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (63)
	CreateDynamicObject(791,-4711.2998047,-2767.8999023,82.0999985,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (64)
	CreateDynamicObject(791,-4751.5000000,-2781.0000000,76.6999969,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (65)
	CreateDynamicObject(791,-4792.7001953,-2787.1000977,73.4000015,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (66)
	CreateDynamicObject(791,-4852.2998047,-2793.8999023,68.1999969,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (67)
	CreateDynamicObject(791,-4864.0000000,-2740.5000000,55.4000015,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (68)
	CreateDynamicObject(791,-4812.1000977,-2737.1999512,61.0000000,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (69)
	CreateDynamicObject(791,-4766.6000977,-2712.3999023,69.4000015,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (70)
	CreateDynamicObject(791,-4705.3999023,-2715.8000488,94.5999985,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (71)
	CreateDynamicObject(791,-4705.2998047,-2678.0000000,93.4000015,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (72)
	CreateDynamicObject(791,-4846.2998047,-2694.5000000,64.1999969,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (73)
	CreateDynamicObject(791,-4841.3999023,-2650.1000977,59.9000015,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (74)
	CreateDynamicObject(791,-4792.8999023,-2674.5000000,64.5000000,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (75)
	CreateDynamicObject(791,-4757.6000977,-2614.1000977,83.4000015,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (76)
	CreateDynamicObject(791,-4713.7001953,-2604.1999512,97.0999985,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (77)
	CreateDynamicObject(791,-4691.2001953,-2628.6999512,84.4000015,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (78)
	CreateDynamicObject(791,-4700.5000000,-2574.8999023,77.4000015,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (79)
	CreateDynamicObject(791,-4722.7998047,-2535.1999512,75.5999985,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (80)
	CreateDynamicObject(791,-4753.2998047,-2579.6000977,70.4000015,0.0000000,0.0000000,0.0000000); //object(vbg_fir_copse) (81)
	CreateDynamicObject(791,-4822.6000977,-2584.1999512,40.9000015,0.0000000,0.0000000,37.9962158); //object(vbg_fir_copse) (82)
	CreateDynamicObject(3415,-4645.1000977,-2967.0000000,33.2999992,0.0000000,0.0000000,247.9970856); //object(ce_loghut1) (4)
	CreateDynamicObject(3414,-4681.5996094,-2983.5000000,35.5999985,0.0000000,0.0000000,189.9975586); //object(ce_oldhut1) (3)
	CreateDynamicObject(3415,-4664.5000000,-2912.1999512,32.5999985,0.0000000,0.0000000,11.9970703); //object(ce_loghut1) (5)
	CreateDynamicObject(3286,-4639.5000000,-2905.3000488,37.2999992,0.0000000,0.0000000,13.2495117); //object(cxrf_watertwr) (2)
	CreateDynamicObject(3286,-4638.2001953,-2911.3000488,37.4000015,0.0000000,0.0000000,13.2495117); //object(cxrf_watertwr) (3)
	CreateDynamicObject(3402,-4730.2001953,-2903.8000488,32.5999985,0.0000000,0.0000000,10.4941406); //object(sw_tempbarn01) (1)
	CreateDynamicObject(3402,-4740.2001953,-2980.1000977,33.2000008,0.0000000,0.0000000,282.7496338); //object(sw_tempbarn01) (2)
	CreateDynamicObject(3419,-4705.0996094,-2962.6992188,33.0999985,0.0000000,0.0000000,55.9973145); //object(ce_logbarn02) (1)
	CreateDynamicObject(12917,-4713.2998047,-3005.1999512,33.5999985,0.0000000,0.0000000,19.5000000); //object(sw_haypile03) (1)
	CreateDynamicObject(12917,-4698.5000000,-2999.1999512,33.5999985,0.0000000,0.0000000,19.4952393); //object(sw_haypile03) (2)
	CreateDynamicObject(12917,-4710.5000000,-2993.6992188,33.5000000,0.0000000,0.0000000,19.4952393); //object(sw_haypile03) (3)
	CreateDynamicObject(13206,-4700.6000977,-2918.1999512,32.5000000,0.0000000,0.0000000,14.0000000); //object(cetruth_barn02) (2)
	CreateDynamicObject(17324,-4637.0000000,-2934.6999512,32.9000015,0.0000000,0.0000000,280.7500000); //object(cw_combbarn) (1)
	CreateDynamicObject(3425,-4634.5000000,-2952.5000000,44.5999985,0.0000000,0.0000000,97.2453613); //object(nt_windmill) (2)
	CreateDynamicObject(3402,-4642.1000977,-2994.6999512,33.7999992,0.0000000,0.0000000,162.7496338); //object(sw_tempbarn01) (3)
	CreateDynamicObject(1463,-4742.6000977,-2994.8000488,33.7000008,0.0000000,0.0000000,0.0000000); //object(dyn_woodpile2) (18)
	CreateDynamicObject(1463,-4743.2001953,-2992.5000000,33.7000008,0.0000000,0.0000000,0.0000000); //object(dyn_woodpile2) (19)
	CreateDynamicObject(1463,-4743.7001953,-2989.6999512,33.7000008,0.0000000,0.0000000,0.0000000); //object(dyn_woodpile2) (20)
	CreateDynamicObject(1463,-4744.3999023,-2986.8999023,33.5999985,0.0000000,0.0000000,0.0000000); //object(dyn_woodpile2) (21)
	CreateDynamicObject(1463,-4745.6000977,-2982.6000977,33.5999985,0.0000000,0.0000000,0.0000000); //object(dyn_woodpile2) (22)
	CreateDynamicObject(1463,-4746.7998047,-2979.8999023,33.5000000,0.0000000,0.0000000,0.0000000); //object(dyn_woodpile2) (23)
	CreateDynamicObject(1463,-4747.2998047,-2976.8000488,33.5000000,0.0000000,0.0000000,0.0000000); //object(dyn_woodpile2) (24)
	CreateDynamicObject(13369,-4778.3999023,-3027.5000000,35.5000000,0.0000000,358.0000000,0.0000000); //object(sw_logs07) (1)
	CreateDynamicObject(13369,-4779.8999023,-3032.0000000,36.0999985,0.0000000,357.9949951,0.0000000); //object(sw_logs07) (5)
	CreateDynamicObject(13369,-4779.6000977,-3034.3000488,38.2999992,0.0000000,357.9949951,0.0000000); //object(sw_logs07) (6)
	CreateDynamicObject(13369,-4780.2998047,-3028.1992188,38.2000008,0.0000000,357.9895020,0.0000000); //object(sw_logs07) (7)
	CreateDynamicObject(1463,-4689.3999023,-2944.5000000,33.2000008,0.0000000,0.0000000,0.0000000); //object(dyn_woodpile2) (25)
	CreateDynamicObject(1463,-4687.6000977,-2943.6000977,33.2000008,0.0000000,0.0000000,0.0000000); //object(dyn_woodpile2) (26)
	CreateDynamicObject(1463,-4687.6000977,-2945.1000977,33.2000008,0.0000000,0.0000000,0.0000000); //object(dyn_woodpile2) (27)
	CreateDynamicObject(1463,-4686.2001953,-2944.3999023,33.2000008,0.0000000,0.0000000,0.0000000); //object(dyn_woodpile2) (28)
	CreateDynamicObject(1463,-4688.7001953,-2943.6000977,33.2000008,0.0000000,0.0000000,0.0000000); //object(dyn_woodpile2) (29)
	CreateDynamicObject(1463,-4688.8999023,-2945.3000488,33.5000000,0.0000000,0.0000000,0.0000000); //object(dyn_woodpile2) (30)
	CreateDynamicObject(1463,-4686.7001953,-2945.1999512,33.7999992,0.0000000,0.0000000,0.0000000); //object(dyn_woodpile2) (31)
	CreateDynamicObject(1463,-4686.8999023,-2943.5000000,33.7999992,0.0000000,0.0000000,0.0000000); //object(dyn_woodpile2) (32)
	CreateDynamicObject(1463,-4688.1000977,-2944.6000977,33.7000008,0.0000000,0.0000000,0.0000000); //object(dyn_woodpile2) (33)
	CreateDynamicObject(17026,-5032.8999023,-2839.3000488,24.5000000,340.0000000,0.0000000,281.9970703); //object(cunt_rockgp2_) (1)
	CreateDynamicObject(17026,-5068.7998047,-2849.6000977,41.2999992,0.0000000,0.0000000,83.9970703); //object(cunt_rockgp2_) (2)
	CreateDynamicObject(17026,-5068.1000977,-2868.1999512,38.9000015,0.0000000,0.0000000,83.9959717); //object(cunt_rockgp2_) (3)
	CreateDynamicObject(17026,-4856.3999023,-2608.6999512,35.5999985,15.6673584,336.5794678,292.6660156); //object(cunt_rockgp2_) (4)
	CreateDynamicObject(17026,-4609.5996094,-2857.2998047,27.8999996,358.0114746,7.9925537,4.2626953); //object(cunt_rockgp2_) (5)
	CreateDynamicObject(17026,-4585.0996094,-2899.2998047,21.3999996,358.0114746,7.9925537,354.2651367); //object(cunt_rockgp2_) (6)
	CreateDynamicObject(3279,-4906.8999023,-2934.1999512,31.3999996,0.0000000,0.0000000,97.9999695); //object(a51_spottower) (1)
	CreateDynamicObject(3279,-4864.5996094,-2903.0996094,31.3999996,0.0000000,0.0000000,179.9945068); //object(a51_spottower) (2)
	CreateDynamicObject(14875,-4733.0000000,-2991.6999512,34.2000008,0.0000000,0.0000000,0.0000000); //object(kylie_hay1) (4)
	CreateDynamicObject(14875,-4734.8999023,-2983.0000000,34.0999985,0.0000000,0.0000000,0.0000000); //object(kylie_hay1) (5)
	CreateDynamicObject(14875,-4735.7001953,-2979.3999023,34.0000000,0.0000000,0.0000000,0.0000000); //object(kylie_hay1) (6)
	CreateDynamicObject(14875,-4736.2001953,-2975.1999512,34.0000000,0.0000000,0.0000000,0.0000000); //object(kylie_hay1) (7)
	CreateDynamicObject(17026,-4573.2998047,-2942.5996094,28.0000000,357.9895020,1.9940186,332.0562744); //object(cunt_rockgp2_) (5)
	CreateDynamicObject(615,-4780.7998047,-2947.7998047,32.7999992,0.0000000,0.0000000,0.0000000); //object(veg_tree3) (1)
	CreateDynamicObject(615,-4880.7998047,-2961.0000000,32.7000008,0.0000000,0.0000000,0.0000000); //object(veg_tree3) (2)
	CreateDynamicObject(615,-4767.2998047,-3005.1000977,33.5999985,0.0000000,0.0000000,0.0000000); //object(veg_tree3) (3)
	CreateDynamicObject(829,-4770.2998047,-3000.6999512,33.7999992,0.0000000,0.0000000,0.0000000); //object(dead_tree_3) (1)
	CreateDynamicObject(829,-4781.7998047,-2950.0000000,33.2000008,0.0000000,0.0000000,0.0000000); //object(dead_tree_3) (2)
	CreateDynamicObject(829,-4783.6000977,-2946.8999023,33.0999985,0.0000000,0.0000000,0.0000000); //object(dead_tree_3) (3)
	CreateDynamicObject(829,-4836.5000000,-2897.6992188,32.2999992,0.0000000,0.0000000,0.0000000); //object(dead_tree_3) (4)
	CreateDynamicObject(829,-4900.3999023,-2949.1000977,32.7999992,0.0000000,0.0000000,0.0000000); //object(dead_tree_3) (5)
	CreateDynamicObject(669,-4799.2998047,-2921.0000000,32.4000015,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (1)
	CreateDynamicObject(669,-4806.0000000,-2907.6999512,32.2000008,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (2)
	CreateDynamicObject(669,-4812.2001953,-2917.6000977,32.2999992,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (3)
	CreateDynamicObject(669,-4678.3999023,-2878.1000977,32.2999992,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (4)
	CreateDynamicObject(669,-4699.0000000,-2883.1000977,32.2999992,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (5)
	CreateDynamicObject(669,-4722.8999023,-2887.0000000,32.2999992,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (6)
	CreateDynamicObject(669,-4652.0996094,-2874.8994141,32.2999992,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (7)
	CreateDynamicObject(669,-4989.1000977,-2647.3999023,25.3999996,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (8)
	CreateDynamicObject(669,-4973.7001953,-2631.8000488,27.5000000,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (9)
	CreateDynamicObject(669,-4970.0000000,-2647.6999512,23.5000000,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (10)
	CreateDynamicObject(669,-4985.8994141,-2663.7998047,19.0000000,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (11)
	CreateDynamicObject(669,-4966.7001953,-2662.6992188,16.8999996,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (12)
	CreateDynamicObject(669,-4952.2998047,-2642.0000000,23.3999996,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (13)
	CreateDynamicObject(669,-4959.6000977,-2628.6000977,26.8999996,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (14)
	CreateDynamicObject(669,-4958.7001953,-2608.3000488,31.8999996,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (15)
	CreateDynamicObject(669,-4942.3999023,-2618.1000977,28.6000004,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (16)
	CreateDynamicObject(669,-5054.2998047,-2749.1999512,15.8999996,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (17)
	CreateDynamicObject(669,-5060.5000000,-2773.1000977,30.2999992,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (18)
	CreateDynamicObject(669,-5040.2998047,-2795.0000000,33.7999992,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (19)
	CreateDynamicObject(669,-5012.7001953,-2788.8000488,21.5000000,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (20)
	CreateDynamicObject(669,-5036.3999023,-2776.6000977,22.2000008,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (21)
	CreateDynamicObject(669,-5078.0000000,-2759.3999023,26.3999996,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (22)
	CreateDynamicObject(16302,-5036.2001953,-2862.0000000,36.5999985,341.0000000,0.0000000,0.0000000); //object(des_gravelpile04) (1)
	CreateDynamicObject(1337,-5045.2402344,-2870.3906250,40.8367386,0.0000000,0.0000000,0.0000000); //object(binnt07_la) (1)
	CreateDynamicObject(16302,-4970.6000977,-3045.1000977,35.9000015,356.9991455,0.0000000,0.0000000); //object(des_gravelpile04) (2)
	CreateDynamicObject(3286,-4887.6000977,-2979.6999512,37.5999985,0.0000000,0.0000000,13.2495117); //object(cxrf_watertwr) (1)
	CreateDynamicObject(3279,-5000.7001953,-2671.6999512,17.5000000,0.0000000,0.0000000,77.9945068); //object(a51_spottower) (2)
	CreateDynamicObject(3279,-5060.0000000,-2764.1999512,24.7999992,0.0000000,0.0000000,221.9919434); //object(a51_spottower) (2)
	CreateDynamicObject(12912,-4748.0996094,-3025.2998047,45.5000000,0.0000000,0.0000000,11.7498779); //object(sw_silo04) (1)
	CreateDynamicObject(1337,-4916.9335938,-2535.6777344,21.3751755,0.0000000,0.0000000,0.0000000); //object(binnt07_la) (3)
	CreateDynamicObject(16134,-4939.7998047,-2823.8999023,27.2999992,0.0000000,4.4989014,39.9957275); //object(des_rockfl1_01) (1)
	CreateDynamicObject(16134,-4957.5000000,-2828.8994141,30.1000004,3.9166260,11.2664795,40.7043457); //object(des_rockfl1_01) (2)
	CreateDynamicObject(16134,-4974.0996094,-2834.1992188,31.2999992,0.0000000,8.4979248,61.9903564); //object(des_rockfl1_01) (3)
	CreateDynamicObject(16134,-4987.8994141,-2838.0000000,29.2000008,0.0000000,8.4979248,61.9903564); //object(des_rockfl1_01) (4)
	CreateDynamicObject(3364,-5132.2998047,-2803.3999023,46.5000000,341.7615051,357.8941650,21.3406677); //object(des_ruin3_) (1)
	CreateDynamicObject(3363,-5004.3999023,-3064.1999512,43.2999992,350.0000000,0.0000000,334.0000000); //object(des_ruin1_) (1)
	CreateDynamicObject(3363,-4689.3999023,-3136.0000000,37.4000015,349.9969482,0.0000000,333.9953613); //object(des_ruin1_) (2)
	CreateDynamicObject(829,-4998.3999023,-2675.1999512,17.0000000,0.0000000,0.0000000,0.0000000); //object(dead_tree_3) (6)
	CreateDynamicObject(829,-5005.1000977,-2676.3999023,16.7999992,0.0000000,0.0000000,0.0000000); //object(dead_tree_3) (7)
	CreateDynamicObject(3362,-4821.5000000,-2650.3000488,66.4000015,0.0000000,0.0000000,0.0000000); //object(des_ruin2_) (1)
	CreateDynamicObject(11428,-4509.1000977,-2842.8999023,20.7999992,0.0000000,0.0000000,330.0000000); //object(des_indruin02) (1)
	CreateDynamicObject(3095,-5071.7001953,-2723.6992188,8.6000004,87.9950562,179.9945068,17.2485352); //object(a51_jetdoor) (1)
	CreateDynamicObject(3095,-5070.5996094,-2727.3994141,15.8000002,0.0000000,0.0000000,16.9958496); //object(a51_jetdoor) (3)
	CreateDynamicObject(3095,-5066.7998047,-2726.1992188,11.8000002,89.7420654,179.9505615,287.0288086); //object(a51_jetdoor) (5)
	CreateDynamicObject(3095,-5074.8994141,-2728.7998047,11.8000002,89.7420654,179.9505615,287.0288086); //object(a51_jetdoor) (6)
	CreateDynamicObject(744,-5078.0000000,-2727.8000488,11.0000000,0.0000000,0.0000000,0.0000000); //object(sm_scrub_rock4) (1)
	CreateDynamicObject(744,-5065.2001953,-2723.8999023,7.9000001,18.0000000,0.0000000,170.0000000); //object(sm_scrub_rock4) (2)
	CreateDynamicObject(744,-5076.7001953,-2734.0000000,11.1000004,0.0000000,0.0000000,0.0000000); //object(sm_scrub_rock4) (3)
	CreateDynamicObject(744,-5063.1000977,-2727.3999023,10.3000002,17.9956055,0.0000000,169.9969482); //object(sm_scrub_rock4) (4)
	CreateDynamicObject(760,-5068.5000000,-2721.1999512,11.8000002,0.0000000,0.0000000,0.0000000); //object(sm_bush_small_1) (1)
	CreateDynamicObject(760,-5070.7998047,-2721.6999512,11.6999998,0.0000000,0.0000000,0.0000000); //object(sm_bush_small_1) (2)
	CreateDynamicObject(760,-5072.7001953,-2722.8000488,11.6999998,0.0000000,0.0000000,0.0000000); //object(sm_bush_small_1) (3)
	CreateDynamicObject(760,-5075.2998047,-2723.1999512,11.6000004,0.0000000,0.0000000,0.0000000); //object(sm_bush_small_1) (4)
	CreateDynamicObject(760,-5065.0000000,-2725.1999512,13.8999996,0.0000000,0.0000000,0.0000000); //object(sm_bush_small_1) (5)
	CreateDynamicObject(760,-5064.7998047,-2722.3999023,13.6999998,0.0000000,0.0000000,0.0000000); //object(sm_bush_small_1) (6)
	CreateDynamicObject(760,-5074.2001953,-2725.0000000,16.3999996,0.0000000,0.0000000,0.0000000); //object(sm_bush_small_1) (7)
	CreateDynamicObject(760,-5071.3999023,-2724.3000488,16.3999996,0.0000000,0.0000000,0.0000000); //object(sm_bush_small_1) (8)
	CreateDynamicObject(760,-5068.7001953,-2723.1000977,16.3999996,0.0000000,0.0000000,0.0000000); //object(sm_bush_small_1) (9)
	CreateDynamicObject(760,-5068.2998047,-2726.1000977,16.3999996,0.0000000,0.0000000,0.0000000); //object(sm_bush_small_1) (10)
	CreateDynamicObject(760,-5070.7001953,-2726.1000977,16.3999996,0.0000000,0.0000000,0.0000000); //object(sm_bush_small_1) (11)
	CreateDynamicObject(760,-5074.0000000,-2726.8000488,16.3999996,0.0000000,0.0000000,0.0000000); //object(sm_bush_small_1) (12)
	CreateDynamicObject(760,-5073.3999023,-2729.3000488,16.3999996,0.0000000,0.0000000,0.0000000); //object(sm_bush_small_1) (13)
	CreateDynamicObject(760,-5071.1000977,-2729.3000488,16.3999996,0.0000000,0.0000000,0.0000000); //object(sm_bush_small_1) (14)
	CreateDynamicObject(760,-5069.5000000,-2728.5000000,16.3999996,0.0000000,0.0000000,0.0000000); //object(sm_bush_small_1) (15)
	CreateDynamicObject(760,-5067.0000000,-2727.8999023,16.3999996,0.0000000,0.0000000,0.0000000); //object(sm_bush_small_1) (16)
	CreateDynamicObject(760,-5066.6000977,-2730.1999512,16.3999996,0.0000000,0.0000000,0.0000000); //object(sm_bush_small_1) (17)
	CreateDynamicObject(760,-5070.2998047,-2730.8999023,16.3999996,0.0000000,0.0000000,0.0000000); //object(sm_bush_small_1) (18)
	CreateDynamicObject(760,-5072.7001953,-2731.3999023,16.3999996,0.0000000,0.0000000,0.0000000); //object(sm_bush_small_1) (19)
	CreateDynamicObject(760,-5069.2998047,-2726.0000000,16.3999996,0.0000000,0.0000000,0.0000000); //object(sm_bush_small_1) (20)
	CreateDynamicObject(762,-4965.7001953,-2949.0000000,57.9000015,0.0000000,0.0000000,0.0000000); //object(new_bushtest) (1)
	CreateDynamicObject(762,-4956.5000000,-2887.0000000,39.7000008,0.0000000,0.0000000,0.0000000); //object(new_bushtest) (2)
	CreateDynamicObject(762,-4875.7998047,-2856.3000488,64.5999985,0.0000000,0.0000000,0.0000000); //object(new_bushtest) (3)
	CreateDynamicObject(762,-5028.7998047,-2812.8999023,39.0999985,0.0000000,0.0000000,0.0000000); //object(new_bushtest) (4)
	CreateDynamicObject(762,-4911.1000977,-2551.1999512,41.5000000,0.0000000,0.0000000,0.0000000); //object(new_bushtest) (5)
	CreateDynamicObject(762,-4880.7998047,-2689.5000000,60.5999985,0.0000000,0.0000000,0.0000000); //object(new_bushtest) (6)
	CreateDynamicObject(762,-4885.6000977,-3055.0000000,39.9000015,0.0000000,0.0000000,0.0000000); //object(new_bushtest) (7)
	CreateDynamicObject(762,-4916.6000977,-3056.1999512,39.7999992,0.0000000,0.0000000,0.0000000); //object(new_bushtest) (8)
	CreateDynamicObject(760,-5064.6000977,-2725.8999023,15.5000000,0.0000000,0.0000000,0.0000000); //object(sm_bush_small_1) (21)
	CreateDynamicObject(818,-5065.1000977,-2723.8000488,15.1999998,0.0000000,0.0000000,0.0000000); //object(genveg_tallgrass02) (1)
	CreateDynamicObject(818,-5077.2998047,-2725.5000000,15.6999998,0.0000000,0.0000000,0.0000000); //object(genveg_tallgrass02) (2)
	CreateDynamicObject(3886,-5059.6000977,-2703.3000488,1.8000000,0.0000000,0.0000000,314.7500000); //object(ws_jettynol_sfx) (1)
	CreateDynamicObject(3886,-5052.3999023,-2696.1999512,1.8000000,0.0000000,0.0000000,314.7473145); //object(ws_jettynol_sfx) (2)
	CreateDynamicObject(3886,-5066.7998047,-2710.6999512,1.0000000,6.8213501,335.3137207,317.8722839); //object(ws_jettynol_sfx) (3)
	CreateDynamicObject(2631,-4844.7001953,-2990.1999512,33.2999992,0.0000000,0.0000000,100.2500000); //object(gym_mat1) (1)
	CreateDynamicObject(2631,-4841.7001953,-2989.6000977,33.2999992,0.0000000,0.0000000,100.2447510); //object(gym_mat1) (2)
	CreateDynamicObject(2631,-4874.5996094,-2949.7998047,32.5999985,0.0000000,0.0000000,149.2382812); //object(gym_mat1) (4)
	CreateDynamicObject(2631,-4873.2001953,-2947.3994141,32.5999985,0.0000000,0.0000000,149.2382812); //object(gym_mat1) (5)
	CreateDynamicObject(1463,-4790.1000977,-2929.3000488,32.9000015,0.0000000,0.0000000,48.0000000); //object(dyn_woodpile2) (10)
	CreateDynamicObject(1463,-4788.2998047,-2930.6000977,32.9000015,0.0000000,0.0000000,47.9992676); //object(dyn_woodpile2) (10)
	CreateDynamicObject(1463,-4791.6000977,-2930.8999023,32.9000015,0.0000000,0.0000000,47.9992676); //object(dyn_woodpile2) (10)
	CreateDynamicObject(1463,-4789.7998047,-2932.3000488,32.9000015,0.0000000,0.0000000,47.9992676); //object(dyn_woodpile2) (10)
	CreateDynamicObject(1463,-4793.2001953,-2932.8000488,32.9000015,0.0000000,0.0000000,47.9992676); //object(dyn_woodpile2) (10)
	CreateDynamicObject(1463,-4791.5000000,-2933.8999023,32.9000015,0.0000000,0.0000000,47.9992676); //object(dyn_woodpile2) (10)
	CreateDynamicObject(1463,-4794.5000000,-2934.1999512,32.9000015,0.0000000,0.0000000,47.9992676); //object(dyn_woodpile2) (10)
	CreateDynamicObject(1463,-4792.8999023,-2935.5000000,32.9000015,0.0000000,0.0000000,47.9992676); //object(dyn_woodpile2) (10)
	CreateDynamicObject(2060,-4845.0000000,-2988.6999512,33.5000000,0.0000000,0.0000000,10.5000000); //object(cj_sandbag) (1)
	CreateDynamicObject(2060,-4842.0000000,-2988.0996094,33.5000000,0.0000000,0.0000000,10.4919434); //object(cj_sandbag) (2)
	CreateDynamicObject(2060,-4873.2998047,-2950.8000488,32.7999992,0.0000000,0.0000000,60.9974365); //object(cj_sandbag) (3)
	CreateDynamicObject(2060,-4871.7998047,-2948.3000488,32.7999992,0.0000000,0.0000000,60.9960938); //object(cj_sandbag) (4)
	CreateDynamicObject(2059,-4846.7001953,-2989.3999023,33.2999992,0.0000000,0.0000000,0.0000000); //object(cj_gunstuff1) (1)
	CreateDynamicObject(2059,-4844.6000977,-2992.6999512,35.5000000,0.0000000,0.0000000,0.0000000); //object(cj_gunstuff1) (2)
	CreateDynamicObject(2059,-4843.5000000,-2988.5000000,33.2999992,0.0000000,0.0000000,0.0000000); //object(cj_gunstuff1) (3)
	CreateDynamicObject(2059,-4843.2001953,-2989.8000488,33.2999992,0.0000000,0.0000000,0.0000000); //object(cj_gunstuff1) (4)
	CreateDynamicObject(2059,-4846.6000977,-2990.1999512,33.2999992,0.0000000,0.0000000,0.0000000); //object(cj_gunstuff1) (5)
	CreateDynamicObject(2228,-4998.7382812,-2721.2822266,8.9730072,0.0000000,0.0000000,0.0000000); //object(cj_shovel) (1)
	CreateDynamicObject(3499,-4949.8999023,-2739.6000977,12.1999998,0.0000000,0.0000000,0.0000000); //object(wdpillar02_lvs) (1)
	CreateDynamicObject(3095,-4952.7998047,-2743.8000488,17.3999996,0.0000000,0.0000000,11.7458496); //object(a51_jetdoor) (3)
	CreateDynamicObject(3095,-4961.2998047,-2745.5996094,17.3999996,0.0000000,0.0000000,11.7388916); //object(a51_jetdoor) (3)
	CreateDynamicObject(3095,-4951.0000000,-2752.3994141,17.3999996,0.0000000,0.0000000,11.7333984); //object(a51_jetdoor) (3)
	CreateDynamicObject(3095,-4959.5000000,-2754.1999512,17.3999996,0.0000000,0.0000000,11.7443848); //object(a51_jetdoor) (3)
	CreateDynamicObject(3499,-4965.5000000,-2742.6000977,12.3000002,0.0000000,0.0000000,0.0000000); //object(wdpillar02_lvs) (2)
	CreateDynamicObject(3499,-4961.8999023,-2758.1999512,12.1999998,0.0000000,0.0000000,0.0000000); //object(wdpillar02_lvs) (3)
	CreateDynamicObject(3499,-4946.7998047,-2754.6999512,12.3000002,0.0000000,0.0000000,0.0000000); //object(wdpillar02_lvs) (4)
	CreateDynamicObject(3095,-4949.2001953,-2761.0000000,16.3999996,13.0000000,0.0000000,11.7443848); //object(a51_jetdoor) (3)
	CreateDynamicObject(3095,-4947.3999023,-2769.6000977,14.3999996,12.9968262,0.0000000,11.7388916); //object(a51_jetdoor) (3)
	CreateDynamicObject(3095,-4957.6000977,-2762.6999512,16.3999996,12.9968262,0.0000000,11.7388916); //object(a51_jetdoor) (3)
	CreateDynamicObject(3095,-4955.7998047,-2771.3000488,14.3999996,12.9968262,0.0000000,11.7388916); //object(a51_jetdoor) (3)
	CreateDynamicObject(3095,-4963.2998047,-2755.1999512,13.3999996,89.7420654,179.9560547,101.7843323); //object(a51_jetdoor) (5)
	CreateDynamicObject(3095,-4965.2001953,-2746.3999023,13.3999996,89.7420654,179.9505615,101.7828369); //object(a51_jetdoor) (5)
	CreateDynamicObject(3095,-4963.2998047,-2755.1999512,5.8000002,89.7418213,179.9505615,101.7828369); //object(a51_jetdoor) (5)
	CreateDynamicObject(3095,-4965.1000977,-2746.3999023,5.5000000,89.7418213,179.9505615,101.7828369); //object(a51_jetdoor) (5)
	CreateDynamicObject(3095,-4947.1000977,-2751.6999512,13.3999996,89.7420654,179.9560547,281.7843018); //object(a51_jetdoor) (5)
	CreateDynamicObject(3095,-4948.8999023,-2743.0000000,13.3999996,89.7420654,179.9505615,281.7828369); //object(a51_jetdoor) (5)
	CreateDynamicObject(3095,-4948.8999023,-2743.0000000,6.9000001,89.7420654,179.9505615,281.7828369); //object(a51_jetdoor) (5)
	CreateDynamicObject(3095,-4947.2001953,-2751.8000488,6.8000002,89.7418213,179.9505615,281.7828369); //object(a51_jetdoor) (5)
	CreateDynamicObject(3095,-4953.6000977,-2739.8999023,11.1000004,89.7418213,179.9450684,11.7828369); //object(a51_jetdoor) (5)
	CreateDynamicObject(3095,-4962.0000000,-2741.6999512,11.1000004,89.2474365,179.9945068,11.7224121); //object(a51_jetdoor) (5)
	CreateDynamicObject(16501,-4959.5000000,-2750.1992188,20.2000008,0.0000000,0.0000000,10.2447510); //object(cn2_savgardr2_) (1)
	CreateDynamicObject(16501,-4952.5000000,-2748.7998047,20.2000008,0.0000000,0.0000000,11.2445068); //object(cn2_savgardr2_) (2)
	CreateDynamicObject(16501,-4956.7001953,-2746.0996094,22.7999992,0.0000000,0.0000000,281.4916992); //object(cn2_savgardr2_) (3)
	CreateDynamicObject(16501,-4956.2998047,-2747.8999023,22.2999992,0.0000000,90.0000000,280.4997559); //object(cn2_savgardr2_) (7)
	CreateDynamicObject(16501,-4955.7998047,-2750.8000488,22.2999992,0.0000000,90.0000000,280.4974365); //object(cn2_savgardr2_) (8)
	CreateDynamicObject(5153,-4958.0996094,-2746.3994141,18.3999996,88.8793335,206.5592651,187.1852722); //object(stuntramp7_las2) (1)
	CreateDynamicObject(5153,-4955.3994141,-2745.8994141,18.3999996,88.8739624,206.5540619,187.1848907); //object(stuntramp7_las2) (2)
	CreateDynamicObject(16134,-4974.0996094,-2751.5000000,4.3000002,3.9166260,11.2664795,0.7086182); //object(des_rockfl1_01) (2)
	CreateDynamicObject(16134,-4967.5000000,-2730.6000977,2.5000000,1.2194824,11.2424011,335.2458191); //object(des_rockfl1_01) (2)
	CreateDynamicObject(16134,-4946.7998047,-2731.7998047,1.4000000,3.9056396,11.2609863,316.7028809); //object(des_rockfl1_01) (2)
	CreateDynamicObject(16134,-4936.0000000,-2748.8999023,2.5000000,3.9819336,0.4857178,245.4461060); //object(des_rockfl1_01) (2)
	CreateDynamicObject(669,-4976.8999023,-2740.1999512,8.3999996,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (11)
	CreateDynamicObject(669,-4958.5996094,-2737.6992188,7.1999998,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (11)
	CreateDynamicObject(669,-4965.2001953,-2759.8000488,8.6999998,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (11)
	CreateDynamicObject(669,-4947.0000000,-2740.3999023,6.5999999,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (11)
	CreateDynamicObject(669,-4933.5000000,-2730.6000977,5.4000001,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (11)
	CreateDynamicObject(2063,-4958.8999023,-2748.8999023,18.8999996,0.0000000,0.0000000,101.5000305); //object(cj_greenshelves) (1)
	CreateDynamicObject(2063,-4958.2998047,-2752.0000000,18.8999996,0.0000000,0.0000000,101.4971924); //object(cj_greenshelves) (2)
	CreateDynamicObject(2063,-4953.2998047,-2747.8000488,18.8999996,0.0000000,0.0000000,101.4971924); //object(cj_greenshelves) (3)
	CreateDynamicObject(2063,-4952.7001953,-2750.8999023,18.8999996,0.0000000,0.0000000,101.4971924); //object(cj_greenshelves) (4)
	CreateDynamicObject(1744,-4958.3994141,-2746.5000000,18.2999992,0.0000000,0.0000000,11.4971924); //object(med_shelf) (1)
	CreateDynamicObject(1744,-4955.8999023,-2746.1000977,18.2999992,0.0000000,0.0000000,11.4971924); //object(med_shelf) (2)
	CreateDynamicObject(1647,-4680.5000000,-2984.1992188,33.9000015,0.0000000,0.0000000,8.2397461); //object(lounge_wood_dn) (3)
	CreateDynamicObject(1647,-4682.1000977,-2984.3999023,33.9000015,0.0000000,0.0000000,8.2397461); //object(lounge_wood_dn) (5)
	CreateDynamicObject(1647,-4683.8999023,-2984.6000977,33.9000015,0.0000000,0.0000000,8.2397461); //object(lounge_wood_dn) (6)
	CreateDynamicObject(1421,-4686.6000977,-2986.3999023,34.4000015,0.0000000,0.0000000,7.0000000); //object(dyn_boxes) (1)
	CreateDynamicObject(1417,-4688.3999023,-2980.3000488,33.7999992,0.0000000,0.0000000,98.0000000); //object(dyn_cupboard) (1)
	CreateDynamicObject(941,-4701.1000977,-2920.5000000,33.2000008,0.0000000,0.0000000,15.5000000); //object(cj_df_worktop_3) (1)
	CreateDynamicObject(1737,-4955.5000000,-2748.6000977,18.0000000,0.0000000,0.0000000,343.5000000); //object(med_dinning_5) (1)
	CreateDynamicObject(1720,-4954.7001953,-2747.6000977,18.0000000,0.0000000,0.0000000,0.0000000); //object(rest_chair) (1)
	CreateDynamicObject(1720,-4701.8999023,-2919.3000488,32.7000008,0.0000000,0.0000000,0.0000000); //object(rest_chair) (2)
	CreateDynamicObject(1720,-4700.6000977,-2919.3000488,32.7000008,0.0000000,0.0000000,16.0000000); //object(rest_chair) (3)
	CreateDynamicObject(1720,-4699.2001953,-2919.8999023,32.7999992,0.0000000,0.0000000,289.9960938); //object(rest_chair) (4)
	CreateDynamicObject(1720,-4701.2998047,-2921.3999023,32.7999992,0.0000000,0.0000000,201.9951172); //object(rest_chair) (5)
	CreateDynamicObject(1720,-4700.0000000,-2921.1999512,32.7999992,0.0000000,0.0000000,193.9946442); //object(rest_chair) (6)
	CreateDynamicObject(1720,-4702.6000977,-2920.8000488,32.7999992,0.0000000,0.0000000,105.9946289); //object(rest_chair) (7)
	CreateDynamicObject(1810,-4872.2998047,-2944.3000488,32.5000000,0.0000000,0.0000000,0.0000000); //object(cj_foldchair) (1)
	CreateDynamicObject(1810,-4873.2001953,-2945.0000000,32.5000000,0.0000000,0.0000000,0.0000000); //object(cj_foldchair) (2)
	CreateDynamicObject(1810,-4838.5996094,-2990.0996094,33.2999992,0.0000000,0.0000000,237.9968262); //object(cj_foldchair) (3)
	CreateDynamicObject(1810,-4839.6000977,-2990.8000488,33.2999992,0.0000000,0.0000000,237.9968262); //object(cj_foldchair) (4)
	CreateDynamicObject(1280,-4842.5000000,-2986.6000977,33.5000000,0.0000000,0.0000000,280.0000000); //object(parkbench1) (1)
	CreateDynamicObject(1280,-4837.3999023,-2986.0000000,33.5000000,0.0000000,0.0000000,279.9975586); //object(parkbench1) (2)
	CreateDynamicObject(1280,-4687.2001953,-2977.1000977,33.9000015,0.0000000,0.0000000,279.9975586); //object(parkbench1) (3)
	CreateDynamicObject(1280,-4694.8999023,-2917.6000977,33.2000008,0.0000000,0.0000000,102.7475891); //object(parkbench1) (4)
	CreateDynamicObject(941,-4866.1000977,-2983.8999023,33.5000000,0.0000000,0.0000000,313.7462158); //object(cj_df_worktop_3) (2)
	CreateDynamicObject(1811,-4864.2998047,-2985.5000000,33.7000008,0.0000000,0.0000000,0.0000000); //object(med_din_chair_5) (1)
	CreateDynamicObject(1811,-4864.5000000,-2983.8000488,33.5999985,0.0000000,0.0000000,46.5000000); //object(med_din_chair_5) (2)
	CreateDynamicObject(1811,-4865.3999023,-2982.6999512,33.5999985,0.0000000,0.0000000,46.4996338); //object(med_din_chair_5) (3)
	CreateDynamicObject(1811,-4867.2998047,-2982.5000000,33.5999985,0.0000000,0.0000000,146.4996338); //object(med_din_chair_5) (4)
	CreateDynamicObject(1811,-4867.0000000,-2984.3000488,33.5999985,0.0000000,0.0000000,228.4971771); //object(med_din_chair_5) (5)
	CreateDynamicObject(1811,-4866.6000977,-2985.3999023,33.7000008,0.0000000,0.0000000,216.4936676); //object(med_din_chair_5) (6)
	CreateDynamicObject(834,-4985.7998047,-2925.1999512,51.0999985,346.5000000,0.0000000,0.0000000); //object(dead_tree_7) (1)
	CreateDynamicObject(834,-5007.7998047,-2884.8000488,46.9000015,346.4978027,0.0000000,0.0000000); //object(dead_tree_7) (2)
	CreateDynamicObject(834,-4792.7998047,-2999.0000000,36.0999985,0.7470703,1.4996338,359.9780273); //object(dead_tree_7) (3)
	CreateDynamicObject(672,-4896.7001953,-2654.3000488,22.5000000,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree5) (1)
	CreateDynamicObject(672,-4907.7001953,-2671.6000977,14.6000004,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree5) (2)
	CreateDynamicObject(905,-4844.8999023,-2960.3999023,33.2999992,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (1)
	CreateDynamicObject(905,-4846.1000977,-2959.8000488,33.2999992,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (2)
	CreateDynamicObject(905,-4847.5000000,-2959.8999023,33.2999992,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (3)
	CreateDynamicObject(905,-4849.2001953,-2960.5000000,33.2999992,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (4)
	CreateDynamicObject(905,-4850.3999023,-2961.8000488,33.2999992,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (5)
	CreateDynamicObject(905,-4843.8999023,-2962.1999512,33.2999992,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (6)
	CreateDynamicObject(905,-4843.7998047,-2964.1000977,33.2999992,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (7)
	CreateDynamicObject(905,-4845.1000977,-2965.3999023,33.2999992,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (8)
	CreateDynamicObject(905,-4846.5996094,-2965.5996094,33.2999992,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (9)
	CreateDynamicObject(905,-4848.5000000,-2966.0000000,33.2999992,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (10)
	CreateDynamicObject(905,-4850.0000000,-2965.1999512,33.2999992,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (11)
	CreateDynamicObject(905,-4850.5000000,-2963.6999512,33.2999992,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (12)
	CreateDynamicObject(905,-4799.1000977,-2952.3000488,33.2999992,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (13)
	CreateDynamicObject(905,-4800.7998047,-2951.6000977,33.2999992,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (14)
	CreateDynamicObject(905,-4802.3999023,-2951.8000488,33.2999992,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (15)
	CreateDynamicObject(905,-4803.7998047,-2952.6992188,33.2999992,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (16)
	CreateDynamicObject(905,-4804.0000000,-2954.3000488,33.2999992,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (17)
	CreateDynamicObject(905,-4803.5000000,-2955.6000977,33.2999992,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (18)
	CreateDynamicObject(905,-4802.2001953,-2956.1999512,33.2999992,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (19)
	CreateDynamicObject(905,-4798.8999023,-2954.3999023,33.2999992,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (20)
	CreateDynamicObject(905,-4799.3999023,-2956.3000488,33.2999992,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (21)
	CreateDynamicObject(905,-4800.7998047,-2956.6000977,33.2999992,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (22)
	CreateDynamicObject(905,-4686.2001953,-2947.3999023,33.5999985,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (23)
	CreateDynamicObject(905,-4685.0000000,-2946.5000000,33.5999985,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (24)
	CreateDynamicObject(905,-4684.3999023,-2944.8000488,33.5999985,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (25)
	CreateDynamicObject(905,-4685.0000000,-2943.1999512,33.5999985,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (26)
	CreateDynamicObject(905,-4685.8999023,-2941.8000488,33.5999985,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (27)
	CreateDynamicObject(905,-4687.3999023,-2941.8000488,33.5999985,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (28)
	CreateDynamicObject(905,-4689.1000977,-2942.0000000,33.5999985,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (29)
	CreateDynamicObject(905,-4690.3999023,-2943.0000000,33.5999985,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (30)
	CreateDynamicObject(905,-4691.2998047,-2944.6000977,33.5999985,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (31)
	CreateDynamicObject(905,-4690.7998047,-2946.3000488,33.5999985,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (32)
	CreateDynamicObject(905,-4689.7001953,-2947.3000488,33.5999985,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (33)
	CreateDynamicObject(905,-4688.2001953,-2947.6000977,33.5999985,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (34)
	CreateDynamicObject(905,-4687.2001953,-2947.6000977,33.5999985,0.0000000,0.0000000,0.0000000); //object(rockbrkq) (35)
	CreateDynamicObject(10985,-4847.2998047,-2963.5000000,31.7000008,0.0000000,357.4951172,56.2445068); //object(rubbled02_sfs) (1)
	CreateDynamicObject(10985,-4801.2001953,-2954.5000000,31.6000004,0.0000000,357.4951172,56.2445068); //object(rubbled02_sfs) (2)
	CreateDynamicObject(10985,-4687.8999023,-2945.1999512,32.0000000,0.0000000,357.4951172,56.2445068); //object(rubbled02_sfs) (3)
	CreateDynamicObject(17000,-4684.2001953,-2899.1999512,32.5000000,0.0000000,0.0000000,0.0000000); //object(wt6suppsxc) (1)
	CreateDynamicObject(1454,-4787.5000000,-2939.8000488,33.5000000,0.0000000,0.0000000,47.0000000); //object(dyn_h_bale2) (1)
	CreateDynamicObject(1454,-4785.8999023,-2937.8000488,33.5000000,0.0000000,0.0000000,46.9995117); //object(dyn_h_bale2) (2)
	CreateDynamicObject(1454,-4784.2001953,-2935.8000488,33.4000015,0.0000000,0.0000000,46.9995117); //object(dyn_h_bale2) (3)
	CreateDynamicObject(1458,-4706.1000977,-2961.8999023,33.2999992,11.2500000,0.0000000,56.0000000); //object(dyn_cart) (1)
	CreateDynamicObject(13367,-4786.7998047,-2986.8994141,45.2999992,0.0000000,0.0000000,13.7493896); //object(sw_watertower01) (1)
	CreateDynamicObject(944,-4847.7998047,-2985.8000488,34.2000008,0.0000000,0.0000000,8.7500000); //object(packing_carates04) (1)
	CreateDynamicObject(942,-4861.5000000,-2985.5000000,35.5000000,0.0000000,0.0000000,64.7479248); //object(cj_df_unit_2) (1)
	CreateDynamicObject(935,-4806.3999023,-2930.8999023,33.0999985,0.0000000,0.0000000,0.0000000); //object(cj_drum) (1)
	CreateDynamicObject(935,-4806.0996094,-2932.0996094,33.0999985,0.0000000,0.0000000,0.0000000); //object(cj_drum) (2)
	CreateDynamicObject(935,-4805.8999023,-2933.1999512,33.0999985,0.0000000,0.0000000,0.0000000); //object(cj_drum) (3)
	CreateDynamicObject(935,-4807.7998047,-2931.1999512,33.0999985,0.0000000,0.0000000,0.0000000); //object(cj_drum) (4)
	CreateDynamicObject(935,-4807.3999023,-2932.3000488,33.0999985,0.0000000,0.0000000,0.0000000); //object(cj_drum) (5)
	CreateDynamicObject(935,-4807.3999023,-2933.3999023,33.0999985,0.0000000,0.0000000,0.0000000); //object(cj_drum) (6)
	CreateDynamicObject(1362,-4876.2998047,-2952.6000977,33.2000008,0.0000000,0.0000000,0.0000000); //object(cj_firebin) (1)
	CreateDynamicObject(3461,-4876.3999023,-2952.6999512,32.0000000,0.0000000,0.0000000,0.0000000); //object(tikitorch01_lvs) (7)
	CreateDynamicObject(1362,-4686.7998047,-2980.6000977,34.2000008,0.0000000,0.0000000,0.0000000); //object(cj_firebin) (2)
	CreateDynamicObject(3461,-4686.7001953,-2980.5000000,32.9000015,0.0000000,0.0000000,0.0000000); //object(tikitorch01_lvs) (8)
	CreateDynamicObject(3093,-4874.1000977,-2953.3999023,33.2000008,0.0000000,0.0000000,330.0000000); //object(cuntgirldoor) (1)
	CreateDynamicObject(3093,-4840.0000000,-2987.0996094,33.9000015,0.0000000,0.0000000,280.2447510); //object(cuntgirldoor) (2)
	CreateDynamicObject(3093,-4679.7001953,-2981.1000977,34.2000008,0.0000000,0.0000000,283.2463379); //object(cuntgirldoor) (3)
	CreateDynamicObject(3095,-5004.5000000,-2900.1999512,49.2999992,89.7420654,179.9505615,251.7788086); //object(a51_jetdoor) (6)
	CreateDynamicObject(3095,-4996.2998047,-2902.6999512,49.2999992,89.7420654,179.9505615,252.5288239); //object(a51_jetdoor) (5)
	CreateDynamicObject(3095,-4998.8999023,-2897.6999512,43.0999985,89.4457397,333.1844482,189.5576172); //object(a51_jetdoor) (1)
	CreateDynamicObject(3095,-5000.1000977,-2901.6000977,53.2000008,0.0000000,0.0000000,342.4958496); //object(a51_jetdoor) (3)
	CreateDynamicObject(669,-4991.7998047,-2898.0000000,45.4000015,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (11)
	CreateDynamicObject(669,-5003.3999023,-2893.6999512,45.5000000,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (11)
	CreateDynamicObject(669,-4990.7001953,-2907.3000488,47.2000008,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (11)
	CreateDynamicObject(669,-5014.1000977,-2874.5000000,40.2999992,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (11)
	CreateDynamicObject(16134,-5060.1000977,-2760.8000488,15.3000002,25.4587097,12.4671021,148.0592041); //object(des_rockfl1_01) (2)
	CreateDynamicObject(669,-4845.0000000,-2512.6999512,30.6000004,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (12)
	CreateDynamicObject(669,-4870.1000977,-2547.8999023,30.2000008,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (12)
	CreateDynamicObject(669,-4888.6000977,-2526.6000977,31.8999996,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (12)
	CreateDynamicObject(669,-4898.1000977,-2578.8999023,32.7999992,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (12)
	CreateDynamicObject(669,-4946.3999023,-2562.3000488,36.4000015,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (12)
	CreateDynamicObject(669,-4932.6000977,-2578.0000000,34.9000015,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (12)
	CreateDynamicObject(669,-4769.5000000,-2505.8999023,42.0000000,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (12)
	CreateDynamicObject(669,-4793.7998047,-2531.8000488,46.9000015,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (12)
	CreateDynamicObject(669,-4806.3999023,-2508.5000000,41.7000008,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (12)
	CreateDynamicObject(669,-4838.2001953,-2522.6999512,34.5000000,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (12)
	CreateDynamicObject(3260,-4843.7998047,-2992.3999023,35.0999985,0.0000000,90.0000000,8.4999695); //object(oldwoodpanel) (1)
	CreateDynamicObject(3260,-4840.7001953,-2991.8999023,35.2000008,0.0000000,90.0000000,8.4999695); //object(oldwoodpanel) (2)
	CreateDynamicObject(3260,-4848.0000000,-2984.5000000,35.2000008,0.0000000,90.0000000,9.7478027); //object(oldwoodpanel) (3)
	CreateDynamicObject(3260,-4875.6000977,-2946.8000488,34.2999992,0.0000000,90.0000000,60.4976196); //object(oldwoodpanel) (4)
	CreateDynamicObject(3260,-4877.2998047,-2949.3999023,34.2999992,0.0000000,90.0000000,60.4962158); //object(oldwoodpanel) (5)
	CreateDynamicObject(3260,-4683.3999023,-2986.6000977,35.0999985,0.0000000,89.7497559,8.9999695); //object(oldwoodpanel) (6)
	CreateDynamicObject(3260,-4680.3999023,-2986.1000977,34.9000015,0.0000000,89.7474365,9.7478027); //object(oldwoodpanel) (7)
	CreateDynamicObject(3260,-4687.7001953,-2978.6000977,35.4000015,0.0000000,270.0000000,190.7498474); //object(oldwoodpanel) (8)
	CreateDynamicObject(16134,-4961.7001953,-2822.1000977,28.8999996,16.7135315,349.2820129,232.5997314); //object(des_rockfl1_01) (2)
	CreateDynamicObject(16501,-4998.2001953,-2897.5996094,51.5000000,0.0000000,0.0000000,253.4875488); //object(cn2_savgardr2_) (3)
	CreateDynamicObject(16501,-4999.3999023,-2897.3000488,51.5000000,0.0000000,0.0000000,253.4875488); //object(cn2_savgardr2_) (3)
	CreateDynamicObject(3276,-4661.7001953,-2877.1999512,33.2000008,0.0000000,0.0000000,12.0000000); //object(cxreffencesld) (2)
	CreateDynamicObject(3276,-4673.1000977,-2879.5000000,33.2000008,0.0000000,0.0000000,10.9970703); //object(cxreffencesld) (3)
	CreateDynamicObject(3276,-4684.3999023,-2881.5000000,33.2000008,0.0000000,0.0000000,10.9918213); //object(cxreffencesld) (4)
	CreateDynamicObject(3276,-4695.7001953,-2883.6999512,33.2000008,0.0000000,0.0000000,10.9918213); //object(cxreffencesld) (5)
	CreateDynamicObject(3276,-4707.1000977,-2886.0000000,33.2000008,0.0000000,0.0000000,10.9918213); //object(cxreffencesld) (6)
	CreateDynamicObject(3276,-4718.5000000,-2888.1999512,33.2000008,0.0000000,0.0000000,10.9918213); //object(cxreffencesld) (7)
	CreateDynamicObject(3276,-4729.7001953,-2890.3999023,33.2000008,0.0000000,0.0000000,10.9918213); //object(cxreffencesld) (8)
	CreateDynamicObject(3276,-4741.5000000,-2892.8000488,33.2000008,0.0000000,0.0000000,10.9918213); //object(cxreffencesld) (9)
	CreateDynamicObject(3276,-4751.7001953,-2894.6999512,33.2000008,0.0000000,0.0000000,10.9918213); //object(cxreffencesld) (10)
	CreateDynamicObject(3276,-4651.1000977,-2878.8999023,33.2999992,0.0000000,0.0000000,329.9970703); //object(cxreffencesld) (11)
	CreateDynamicObject(3276,-4641.7001953,-2885.3999023,33.4000015,0.0000000,0.0000000,318.9962769); //object(cxreffencesld) (12)
	CreateDynamicObject(3276,-4633.2001953,-2892.6999512,33.5000000,0.0000000,0.0000000,318.9935303); //object(cxreffencesld) (13)
	CreateDynamicObject(3276,-4625.2998047,-2901.1000977,33.5999985,0.0000000,0.0000000,308.9935303); //object(cxreffencesld) (14)
	CreateDynamicObject(1463,-4715.7998047,-2906.8999023,32.9000015,0.0000000,0.0000000,3.0000000); //object(dyn_woodpile2) (16)
	CreateDynamicObject(1463,-4718.3999023,-2907.6999512,32.9000015,0.0000000,0.0000000,2.9992676); //object(dyn_woodpile2) (16)
	CreateDynamicObject(1463,-4720.7998047,-2908.3999023,32.9000015,0.0000000,0.0000000,2.9992676); //object(dyn_woodpile2) (16)
	CreateDynamicObject(1463,-4723.5000000,-2908.8999023,32.9000015,0.0000000,0.0000000,2.9992676); //object(dyn_woodpile2) (16)
	CreateDynamicObject(1463,-4726.1000977,-2909.3999023,32.9000015,0.0000000,0.0000000,2.9992676); //object(dyn_woodpile2) (16)
	CreateDynamicObject(1463,-4728.8999023,-2910.1000977,32.9000015,0.0000000,0.0000000,2.9992676); //object(dyn_woodpile2) (16)
	CreateDynamicObject(1463,-4717.0000000,-2904.8000488,32.9000015,0.0000000,0.0000000,2.9992676); //object(dyn_woodpile2) (16)
	CreateDynamicObject(1463,-4720.5000000,-2905.6000977,32.9000015,0.0000000,0.0000000,2.9992676); //object(dyn_woodpile2) (16)
	CreateDynamicObject(1463,-4723.2998047,-2906.3999023,32.9000015,0.0000000,0.0000000,2.9992676); //object(dyn_woodpile2) (16)
	CreateDynamicObject(1463,-4725.8999023,-2907.0000000,32.9000015,0.0000000,0.0000000,2.9992676); //object(dyn_woodpile2) (16)
	CreateDynamicObject(1463,-4728.6000977,-2907.6000977,32.9000015,0.0000000,0.0000000,2.9992676); //object(dyn_woodpile2) (16)
	CreateDynamicObject(14875,-4732.0000000,-2899.3999023,33.4000015,0.0000000,0.0000000,0.0000000); //object(kylie_hay1) (2)
	CreateDynamicObject(14875,-4736.6000977,-2901.1999512,33.4000015,0.0000000,0.0000000,0.0000000); //object(kylie_hay1) (2)
	CreateDynamicObject(14875,-4740.7998047,-2902.5000000,33.4000015,0.0000000,0.0000000,0.0000000); //object(kylie_hay1) (2)
	CreateDynamicObject(669,-4635.7998047,-2885.8999023,32.5000000,0.0000000,0.0000000,0.0000000); //object(sm_veg_tree4) (7)
	CreateDynamicObject(3276,-4763.2998047,-2897.0000000,33.2000008,0.0000000,0.0000000,10.9918213); //object(cxreffencesld) (15)
	CreateDynamicObject(983,-4965.7998047,-2745.1999512,18.6000004,0.0000000,0.0000000,12.0000000); //object(fenceshit3) (1)
	CreateDynamicObject(983,-4964.5000000,-2751.5000000,18.6000004,0.0000000,0.0000000,11.9970703); //object(fenceshit3) (2)
	CreateDynamicObject(983,-4963.5000000,-2756.1999512,18.6000004,0.0000000,0.0000000,11.9970703); //object(fenceshit3) (3)
	CreateDynamicObject(983,-4948.7998047,-2741.6999512,18.6000004,0.0000000,0.0000000,11.9970703); //object(fenceshit3) (4)
	CreateDynamicObject(983,-4947.3999023,-2748.0000000,18.6000004,0.0000000,0.0000000,11.9970703); //object(fenceshit3) (5)
	CreateDynamicObject(983,-4946.3999023,-2752.8000488,18.6000004,0.0000000,0.0000000,11.9970703); //object(fenceshit3) (6)
	CreateDynamicObject(983,-4963.5000000,-2741.5000000,18.6000004,0.0000000,0.0000000,101.7470703); //object(fenceshit3) (7)
	CreateDynamicObject(983,-4957.2001953,-2740.1999512,18.6000004,0.0000000,0.0000000,101.7443848); //object(fenceshit3) (8)
	CreateDynamicObject(983,-4952.5000000,-2739.1999512,18.6000004,0.0000000,0.0000000,101.7443848); //object(fenceshit3) (9)
	CreateDynamicObject(1407,-4784.5000000,-2932.6999512,33.4000015,0.0000000,0.0000000,138.7500000); //object(dyn_f_r_wood_1) (1)
	CreateDynamicObject(1407,-4784.5000000,-2932.6999512,34.7999992,0.0000000,0.0000000,138.2465820); //object(dyn_f_r_wood_1) (2)
	CreateDynamicObject(1407,-4784.5000000,-2932.6999512,36.2000008,0.0000000,0.0000000,138.2465820); //object(dyn_f_r_wood_1) (3)
	CreateDynamicObject(1647,-4877.0000000,-2969.8994141,33.0999985,0.0000000,0.0000000,23.7359619); //object(lounge_wood_dn) (3)
	CreateDynamicObject(1647,-4875.3994141,-2969.1992188,33.0999985,0.0000000,0.0000000,23.7359619); //object(lounge_wood_dn) (3)
	CreateDynamicObject(3066,-4627.6000977,-2933.0000000,34.2000008,0.0000000,0.0000000,9.5000000); //object(ammotrn_obj) (1)
	CreateDynamicObject(3014,-4813.0000000,-2934.3999023,32.7999992,0.0000000,0.0000000,9.2500000); //object(cr_guncrate) (1)
	CreateDynamicObject(3014,-4813.2001953,-2933.5000000,32.7999992,0.0000000,0.0000000,9.2449951); //object(cr_guncrate) (2)
	CreateDynamicObject(3014,-4813.5000000,-2932.6000977,32.7000008,0.0000000,0.0000000,9.2449951); //object(cr_guncrate) (3)
	CreateDynamicObject(3014,-4812.0000000,-2934.1999512,32.7999992,0.0000000,0.0000000,9.2449951); //object(cr_guncrate) (4)
	CreateDynamicObject(3014,-4812.1000977,-2933.3000488,32.7999992,0.0000000,0.0000000,9.2449951); //object(cr_guncrate) (5)
	CreateDynamicObject(3014,-4812.2001953,-2932.5000000,32.7000008,0.0000000,0.0000000,9.2449951); //object(cr_guncrate) (6)
	CreateDynamicObject(2975,-4879.5000000,-2964.3999023,32.9000015,0.0000000,0.0000000,26.7500000); //object(k_cargo3) (1)
	CreateDynamicObject(2975,-4878.0000000,-2963.5996094,32.9000015,0.0000000,0.0000000,26.7462158); //object(k_cargo3) (2)
	CreateDynamicObject(942,-4872.7001953,-2953.7998047,35.0999985,0.0000000,0.0000000,60.4962158); //object(cj_df_unit_2) (1)
	CreateDynamicObject(942,-4795.1000977,-2930.6000977,35.0000000,0.0000000,0.0000000,45.9962158); //object(cj_df_unit_2) (1)
	CreateDynamicObject(1647,-4793.3999023,-2973.6999512,33.2999992,0.0000000,0.0000000,12.4859619); //object(lounge_wood_dn) (3)
	CreateDynamicObject(1647,-4795.3999023,-2974.1000977,33.2999992,0.0000000,0.0000000,12.4859619); //object(lounge_wood_dn) (3)
	CreateDynamicObject(2975,-4800.7998047,-2976.1000977,33.0999985,0.0000000,0.0000000,282.2462158); //object(k_cargo3) (2)
	CreateDynamicObject(2975,-4801.1000977,-2974.3000488,33.0999985,0.0000000,0.0000000,281.9931946); //object(k_cargo3) (2)
	CreateDynamicObject(615,-4735.7998047,-2962.3000488,33.2000008,0.0000000,0.0000000,0.0000000); //object(veg_tree3) (1)
	CreateDynamicObject(615,-4690.8999023,-2980.1000977,33.5999985,0.0000000,0.0000000,0.0000000); //object(veg_tree3) (1)
	CreateDynamicObject(615,-4692.5000000,-2913.1000977,32.7000008,0.0000000,0.0000000,0.0000000); //object(veg_tree3) (1)
	CreateDynamicObject(709,-4764.0000000,-2902.1000977,32.2999992,0.0000000,0.0000000,0.0000000); //object(sm_vegvbbigbrn) (1)
	CreateDynamicObject(5153,-4786.2998047,-2981.5000000,50.2000008,0.0000000,23.7500000,14.2500000); //object(stuntramp7_las2) (3)
	CreateDynamicObject(5153,-4790.5000000,-2982.6000977,50.2000008,0.0000000,23.7469482,14.2470703); //object(stuntramp7_las2) (4)
	CreateDynamicObject(5153,-4782.5000000,-2982.8999023,50.2000008,0.0000000,23.7469482,104.2492676); //object(stuntramp7_las2) (5)
	CreateDynamicObject(5153,-4781.1000977,-2988.5000000,50.0999985,0.0000000,23.7469482,104.2438049); //object(stuntramp7_las2) (6)
	CreateDynamicObject(5153,-4783.7998047,-2991.3999023,50.0999985,0.0000000,23.7469482,14.2492676); //object(stuntramp7_las2) (7)
	CreateDynamicObject(5153,-4788.0000000,-2992.5000000,50.0999985,0.0000000,23.7469482,14.2492676); //object(stuntramp7_las2) (8)
	CreateDynamicObject(5153,-4790.7998047,-2992.1000977,50.2000008,0.6864929,23.7487488,103.9417419); //object(stuntramp7_las2) (9)
	CreateDynamicObject(5153,-4791.8999023,-2987.8000488,50.2000008,0.6811523,23.7469482,103.9416199); //object(stuntramp7_las2) (10)
	CreateDynamicObject(5153,-4792.7001953,-2984.3999023,50.2000008,0.6811523,23.7469482,103.9416199); //object(stuntramp7_las2) (11)
	CreateDynamicObject(5153,-4782.7998047,-2981.8999023,50.2000008,0.0000000,23.7469482,104.2492676); //object(stuntramp7_las2) (12)
	CreateDynamicObject(5153,-4780.7998047,-2989.6000977,50.0999985,0.0000000,23.7469482,104.2438049); //object(stuntramp7_las2) (13)
	CreateDynamicObject(1437,-4780.5000000,-2985.5000000,45.5000000,334.2500000,0.0000000,102.0000000); //object(dyn_ladder_2) (1)
	CreateDynamicObject(1437,-4777.2001953,-2984.8000488,40.7999992,334.2480469,0.0000000,101.9971008); //object(dyn_ladder_2) (5)
	CreateDynamicObject(1437,-4773.7998047,-2984.1000977,36.0000000,334.2480469,0.0000000,101.9971008); //object(dyn_ladder_2) (6)
	CreateDynamicObject(1437,-4770.5000000,-2983.3999023,31.2999992,334.2480469,0.0000000,101.9971008); //object(dyn_ladder_2) (7)
	CreateDynamicObject(846,-4841.1000977,-2964.1000977,28.6000004,90.0000000,180.0095215,179.9904785); //object(dead_tree_18) (1)
	CreateDynamicObject(846,-4842.7998047,-2959.3000488,28.3999996,90.0000000,180.0110016,179.9835205); //object(dead_tree_18) (2)
	CreateDynamicObject(846,-4843.8999023,-2966.8000488,28.3999996,90.0000000,179.9890137,180.0054932); //object(dead_tree_18) (3)
	CreateDynamicObject(846,-4846.3999023,-2957.6999512,28.1000004,90.0000000,179.9835205,180.0054932); //object(dead_tree_18) (4)
	CreateDynamicObject(846,-4847.2998047,-2968.1999512,28.6000004,90.0000000,179.9835205,180.0054932); //object(dead_tree_18) (5)
	CreateDynamicObject(846,-4852.2001953,-2961.6000977,32.7999992,0.0000000,356.0000000,343.7500000); //object(dead_tree_18) (6)
	CreateDynamicObject(846,-4805.7998047,-2953.8999023,28.2999992,90.0000000,180.0054932,179.9890137); //object(dead_tree_18) (8)
	CreateDynamicObject(846,-4804.0000000,-2950.6999512,28.2999992,90.0000000,180.0054932,179.9890137); //object(dead_tree_18) (9)
	CreateDynamicObject(846,-4798.7001953,-2950.1999512,28.1000004,90.0000000,179.9945068,180.0000000); //object(dead_tree_18) (10)
	CreateDynamicObject(846,-4796.7001953,-2954.3999023,28.2000008,90.0000000,180.0054932,179.9835205); //object(dead_tree_18) (11)
	CreateDynamicObject(846,-4803.0000000,-2957.8000488,28.2999992,90.0000000,179.9945068,179.9945068); //object(dead_tree_18) (12)
	CreateDynamicObject(846,-4798.7998047,-2958.1999512,28.2000008,90.0000000,179.9945068,179.9945068); //object(dead_tree_18) (13)
	CreateDynamicObject(846,-4797.2001953,-2952.0000000,28.0000000,90.0000000,179.9945068,179.9945068); //object(dead_tree_18) (14)
	CreateDynamicObject(846,-4797.6000977,-2956.3999023,28.2000008,90.0000000,179.9945068,179.9945068); //object(dead_tree_18) (15)
	CreateDynamicObject(2631,-4683.8999023,-2940.0000000,33.0999985,0.0000000,0.0000000,149.2382812); //object(gym_mat1) (4)
	CreateDynamicObject(2631,-4690.2998047,-2939.1000977,33.0999985,0.0000000,0.0000000,193.2382812); //object(gym_mat1) (4)
	CreateDynamicObject(2631,-4694.6000977,-2943.3000488,33.0999985,0.0000000,0.0000000,253.2330322); //object(gym_mat1) (4)
	CreateDynamicObject(2631,-4682.0000000,-2945.8999023,33.2000008,0.0000000,0.0000000,253.2293701); //object(gym_mat1) (4)
	CreateDynamicObject(2631,-4686.2001953,-2950.8000488,33.2999992,0.0000000,0.0000000,194.7293549); //object(gym_mat1) (4)
	CreateDynamicObject(2631,-4692.1000977,-2949.0000000,33.2000008,0.0000000,0.0000000,138.2271729); //object(gym_mat1) (4)
	CreateDynamicObject(17098,-5146.7001953,-2874.6000977,-5.0000000,345.1093445,352.4937134,238.3014221); //object(cuntwland24b) (1)
	CreateDynamicObject(17098,-5143.7998047,-2814.6000977,-1.9000000,345.1080322,352.4908447,208.2989349); //object(cuntwland24b) (1)
	CreateDynamicObject(6295,-5076.5000000,-2823.3999023,74.5999985,0.0000000,0.0000000,23.9999695); //object(sanpedlithus_law2) (1)
	CreateDynamicObject(16000,-5113.0000000,-2819.0000000,51.2999992,0.0000000,0.0000000,350.5000000); //object(drvin_screen) (1)
	CreateDynamicObject(10357,-4725.7998047,-2649.5000000,185.3000031,0.0000000,0.0000000,120.0000000); //object(transmitter_sfs) (1)
	CreateDynamicObject(3243,-4933.2998047,-3050.3999023,33.7000008,0.0000000,0.0000000,0.0000000); //object(tepee_room_) (1)
	CreateDynamicObject(3243,-4941.7998047,-3046.8999023,33.5999985,0.0000000,0.0000000,308.0000000); //object(tepee_room_) (2)
	CreateDynamicObject(3243,-4924.2001953,-3045.1000977,33.5999985,0.0000000,0.0000000,53.9962158); //object(tepee_room_) (3)
	CreateDynamicObject(3243,-4923.0000000,-3035.6999512,33.5000000,0.0000000,0.0000000,106.7423096); //object(tepee_room_) (4)
	CreateDynamicObject(3243,-4928.7998047,-3025.1999512,33.4000015,0.0000000,0.0000000,158.7376709); //object(tepee_room_) (5)
	CreateDynamicObject(3243,-4945.8999023,-3037.1000977,33.5000000,0.0000000,0.0000000,276.7359619); //object(tepee_room_) (6)
	CreateDynamicObject(3243,-4940.2998047,-3027.3000488,33.4000015,0.0000000,0.0000000,218.7346039); //object(tepee_room_) (7)
	CreateDynamicObject(1463,-4933.2998047,-3036.6999512,33.7999992,0.0000000,0.0000000,0.0000000); //object(dyn_woodpile2) (5)
	CreateDynamicObject(3461,-4933.2001953,-3036.5000000,32.0000000,0.0000000,0.0000000,0.0000000); //object(tikitorch01_lvs) (5)
	CreateDynamicObject(3461,-4933.7001953,-3037.1000977,32.0999985,0.0000000,0.0000000,0.0000000); //object(tikitorch01_lvs) (5)
	CreateDynamicObject(3243,-4654.1000977,-2920.3999023,32.9000015,0.0000000,0.0000000,129.9923096); //object(tepee_room_) (8)
	CreateDynamicObject(3243,-4649.7001953,-2978.6999512,33.7000008,0.0000000,0.0000000,43.9902344); //object(tepee_room_) (9)
	CreateDynamicObject(3243,-4694.8999023,-2978.1999512,33.5000000,0.0000000,0.0000000,321.9892578); //object(tepee_room_) (10)
	CreateDynamicObject(3243,-4805.5000000,-2918.0000000,32.2999992,0.0000000,0.0000000,167.9873047); //object(tepee_room_) (12)
	CreateDynamicObject(3866,-4590.1000977,-2964.3000488,38.5999985,343.9999695,0.0000000,12.5000000); //object(demolish1_sfxrf) (1)
	CreateDynamicObject(3866,-4589.1000977,-2964.0000000,49.2999992,9.9984131,0.0000000,12.4969482); //object(demolish1_sfxrf) (2)
	CreateDynamicObject(3866,-4597.1000977,-2933.1000977,35.7000008,321.9984131,0.0000000,12.4969482); //object(demolish1_sfxrf) (3)
	CreateDynamicObject(3866,-4600.0000000,-2920.6999512,42.9000015,293.6496887,353.1307983,8.4496460); //object(demolish1_sfxrf) (4)
	CreateDynamicObject(3866,-4603.5000000,-2907.1999512,40.2999992,272.7966003,259.6394043,274.3755493); //object(demolish1_sfxrf) (6)
	CreateDynamicObject(3887,-5009.1000977,-2960.1999512,60.7999992,0.0000000,357.2500000,356.0000000); //object(demolish4_sfxrf) (1)
	CreateDynamicObject(17098,-5114.8999023,-2800.1999512,-3.5000000,345.1080322,352.4853516,208.2952881); //object(cuntwland24b) (1)

	/*
	Objects converted: 571
	Vehicles converted: 1
	Vehicle models found: 1
	----------------------
	convertFFS converted your input in 0.15 seconds - Chuck Norris could have done it in 0.0024 seconds!
	*/
	return 1;
}

