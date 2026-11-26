
#define MAX_VEHICLE_MOVE_RADIUS 2.0 // The distance a vehicle can move by for passengers to warp inside

enum E_GBUG
{
	Float:gbug_playerpos[3],
	Float:gbug_vehpos[3],
	gbug_playerenteringveh,
	gbug_pentervtick
	
}
new gBugPlayerData[MAX_PLAYERS][E_GBUG];

stock gbug_OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	if(!ispassenger || gBugPlayerData[playerid][gbug_playerenteringveh] != 0) return 1;
	gBugPlayerData[playerid][gbug_pentervtick] = GetTickCount();
	GetPlayerPos(playerid, gBugPlayerData[playerid][gbug_playerpos][0], gBugPlayerData[playerid][gbug_playerpos][1], gBugPlayerData[playerid][gbug_playerpos][2]);
	GetVehiclePos(vehicleid, gBugPlayerData[playerid][gbug_vehpos][0], gBugPlayerData[playerid][gbug_vehpos][1], gBugPlayerData[playerid][gbug_vehpos][2]);
	gBugPlayerData[playerid][gbug_playerenteringveh] = 1;
	//SendClientMessage(playerid, -1, "Starting to enter vehicle..");
	return 1;
}

stock gbug_OnPlayerStateChange(playerid, newstate, oldstate)
{
	#pragma unused oldstate
	if(newstate == 3) // Entered vehicle
	{
		if((gBugPlayerData[playerid][gbug_playerenteringveh] == 1 || gBugPlayerData[playerid][gbug_playerenteringveh] == 2) && GetVehicleDistanceFromPoint(GetPlayerVehicleID(playerid), gBugPlayerData[playerid][gbug_vehpos][0], gBugPlayerData[playerid][gbug_vehpos][1], gBugPlayerData[playerid][gbug_vehpos][2]) > MAX_VEHICLE_MOVE_RADIUS)
		{
			SetPlayerPos(playerid, gBugPlayerData[playerid][gbug_playerpos][0], gBugPlayerData[playerid][gbug_playerpos][1], gBugPlayerData[playerid][gbug_playerpos][2]);
			gBugPlayerData[playerid][gbug_playerenteringveh] = 0;
			//SendClientMessage(playerid, -1, "Entry denied");
			//GameTextForPlayer(playerid, "~R~entry denied", 3000, 3);
		}
		else
		{
			gBugPlayerData[playerid][gbug_playerenteringveh] = 0;
			//SendClientMessage(playerid, -1, "Entry accepted");
		}
	}
	return 1;
}

stock gbug_PutPlayerInVehicle(playerid, vehicleid, seatid)
{
	gBugPlayerData[playerid][gbug_playerenteringveh] = 0;
	PutPlayerInVehicle(playerid, vehicleid, seatid);
	return 1;
}

#if defined _ALS_PutPlayerInVehicle
	#undef PutPlayerInVehicle
#else
	#define _ALS_PutPlayerInVehicle
#endif


stock gbug_OnPlayerUpdate(playerid)
{
	if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_ENTER_VEHICLE && gBugPlayerData[playerid][gbug_playerenteringveh] == 0) // OnPlayerEnterVehicle wasn't called, tsk tsk tsk
	{
		gBugPlayerData[playerid][gbug_pentervtick] = GetTickCount();
		GetPlayerPos(playerid, gBugPlayerData[playerid][gbug_playerpos][0], gBugPlayerData[playerid][gbug_playerpos][1], gBugPlayerData[playerid][gbug_playerpos][2]);
		gBugPlayerData[playerid][gbug_playerenteringveh] = 1;
		//SendClientMessage(playerid, -1, "Starting to enter vehicle..");
		return 1;
	}

	if(gBugPlayerData[playerid][gbug_playerenteringveh] == 0) return 1; // Not handling
	
	if(GetPlayerSpecialAction(playerid) != SPECIAL_ACTION_ENTER_VEHICLE && gBugPlayerData[playerid][gbug_playerenteringveh] != 3 && GetTickCount()-gBugPlayerData[playerid][gbug_pentervtick] > 321)
	{
		{
			gBugPlayerData[playerid][gbug_playerenteringveh] = 0;
			//SendClientMessage(playerid, -1, "Cancelled entry while running to door: special action");
		}
		return 1;
	}

	new Float:x, Float:y, Float:z;
	GetPlayerVelocity(playerid, x, y, z);

	if(gBugPlayerData[playerid][gbug_playerenteringveh] == 3 && GetPlayerSpecialAction(playerid) != SPECIAL_ACTION_ENTER_VEHICLE)
	{
		gBugPlayerData[playerid][gbug_playerenteringveh] = 0;
		//SendClientMessage(playerid, -1, "Cancelled entry while stepping in (special action)");
		return 1;
	}
	
	if(x == 0 && y == 0 && z == 0) // Standing still, did they get in?
	{
		if(gBugPlayerData[playerid][gbug_playerenteringveh] != 3)
		{
			if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_ENTER_VEHICLE && GetTickCount()-gBugPlayerData[playerid][gbug_pentervtick] > 321)
			{
				if(gBugPlayerData[playerid][gbug_playerenteringveh] == 2) // Stepping in
				{
					gBugPlayerData[playerid][gbug_playerenteringveh] = 3;
					//SendClientMessage(playerid, -1, "Stepping in");
				}
				else
				{
					gBugPlayerData[playerid][gbug_playerenteringveh] = 2; // Stepping in?
					//SendClientMessage(playerid, -1, "Stepping in?");
					gBugPlayerData[playerid][gbug_pentervtick] = GetTickCount();
				}
			}
			else if(GetTickCount()-gBugPlayerData[playerid][gbug_pentervtick] > 321) // Cancelled entry
			{
				gBugPlayerData[playerid][gbug_playerenteringveh] = 0;
				//SendClientMessage(playerid, -1, "Cancelled entry while running to door (special action)");
			}
		}
	}
	return 1;
}

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	gbug_OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
	#if defined gbug2_OnPlayerEnterVehicle
		return gbug2_OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerEnterVehicle
	#undef OnPlayerEnterVehicle
#else
	#define _ALS_OnPlayerEnterVehicle
#endif
#define OnPlayerEnterVehicle gbug2_OnPlayerEnterVehicle
#if defined gbug2_OnPlayerEnterVehicle
	forward gbug2_OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
#endif


public OnPlayerStateChange(playerid, PLAYER_STATE:newstate, PLAYER_STATE:oldstate)
{
	gbug_OnPlayerStateChange(playerid, newstate, oldstate);
	#if defined gbug2_OnPlayerStateChange
		return gbug2_OnPlayerStateChange(playerid, newstate, oldstate);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerStateChange
	#undef OnPlayerStateChange
#else
	#define _ALS_OnPlayerStateChange
#endif
#define OnPlayerStateChange gbug2_OnPlayerStateChange
#if defined gbug2_OnPlayerStateChange
	forward gbug2_OnPlayerStateChange(playerid, PLAYER_STATE:newstate, PLAYER_STATE:oldstate);
#endif


public OnPlayerUpdate(playerid)
{
	gbug_OnPlayerUpdate(playerid);
	#if defined gbug2_OnPlayerUpdate
		return gbug2_OnPlayerUpdate(playerid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerUpdate
	#undef OnPlayerUpdate
#else
	#define _ALS_OnPlayerUpdate
#endif
#define OnPlayerUpdate gbug2_OnPlayerUpdate
#if defined gbug2_OnPlayerUpdate
	forward gbug2_OnPlayerUpdate(playerid);
#endif
