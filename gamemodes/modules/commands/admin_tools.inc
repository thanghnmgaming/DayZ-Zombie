// ---------------------------------------------------------------------------
// Admin tools: spawn vehicles and weapons, god mode.
// ---------------------------------------------------------------------------

#define ADMIN_TOOLS_LEVEL 5

stock bool:HasAdminTools(playerid)
{
	if(pInfo[playerid][pLogged] == 1 && pInfo[playerid][pAdminLevel] >= ADMIN_TOOLS_LEVEL) return true;
	SendClientMessage(playerid, -1, "*"COL_RED" You do not have the right admin permissions for this command!");
	return false;
}

CMD:veh(playerid, params[])
{
	if(!HasAdminTools(playerid)) return 1;
	if(GetPlayerInterior(playerid) != 0 || IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, -1, ""chat" Get out of your vehicle and go outside first.");

	new text[32];
	if(sscanf(params, "s[32]", text)) return SendClientMessage(playerid, -1, ""chat" /veh [model 400-611 or part of the name]");
	new model = strval(text);
	if(model < 400 || model > 611)
	{
		model = 0;
		for(new i; i < sizeof(VehicleNames); i++)
		{
			if(strfind(VehicleNames[i], text, true) == -1) continue;
			model = 400 + i;
			break;
		}
		if(!model) return SendClientMessage(playerid, -1, ""chat" Unknown vehicle.");
	}

	new Float:x, Float:y, Float:z, Float:angle;
	GetPlayerPos(playerid, x, y, z);
	GetPlayerFacingAngle(playerid, angle);
	new id = CreateVehicle(model, x, y, z + 0.5, angle, -1, -1, -1);
	if(id == INVALID_VEHICLE_ID || id >= MAX_VEHICLES) return SendClientMessage(playerid, -1, ""chat" The vehicle could not be created.");

	// ready to drive; admin vehicles are not saved to the database
	AdminVehicle[id] = true;
	vInfo[id][vX] = x;
	vInfo[id][vY] = y;
	vInfo[id][vZ] = z;
	vInfo[id][vehicleFuel] = 100;
	vInfo[id][vehicleEngine] = 1;
	vInfo[id][vehicleTires] = 8;    // trimmed to the model's wheel count below
	vInfo[id][vehicleSlots] = 4;
	for(new slot; slot < MAX_VEHICLE_SLOTS; slot++) format(VehicleSlots[id][slot], 64, EMPTY_SLOT);

	AllowTeleport(playerid);
	PutPlayerInVehicle(playerid, id, 0);
	SetTimerEx("TrimAdminVehicle", 1000, false, "i", playerid);

	new msg[128];
	format(msg, sizeof(msg), ""chat" Created %s (model %d, id %d). /delveh removes it.", VehicleNames[model - 400], model, id);
	SendClientMessage(playerid, -1, msg);
	return 1;
}

forward TrimAdminVehicle(playerid);
public TrimAdminVehicle(playerid)
{
	if(IsPlayerConnected(playerid)) UpdateVehicleParts(playerid);
	return 1;
}

CMD:delveh(playerid)
{
	if(!HasAdminTools(playerid)) return 1;
	new id = GetPlayerVehicleID(playerid);
	if(!id) id = GetVehicleNearID(playerid);
	if(id <= 0 || !AdminVehicle[id]) return SendClientMessage(playerid, -1, ""chat" Only vehicles made with /veh can be removed. Sit in it or stand next to it.");
	DestroyVehicle(id);
	AdminVehicle[id] = false;
	vInfo[id][vX] = 0.0;
	vInfo[id][vY] = 0.0;
	vInfo[id][vZ] = 0.0;
	SendClientMessage(playerid, -1, ""chat" Vehicle removed.");
	return 1;
}

CMD:gun(playerid, params[])
{
	if(!HasAdminTools(playerid)) return 1;
	new weaponid, ammo;
	if(sscanf(params, "iI(500)", weaponid, ammo) || !(1 <= weaponid <= 46) || weaponid == 19 || weaponid == 20 || weaponid == 21 || ammo < 1 || ammo > 9999)
		return SendClientMessage(playerid, -1, ""chat" /gun [weapon id 1-46] [ammo 1-9999] - e.g. /gun 31 500 (M4), 34 (sniper), 24 (deagle)");
	GivePlayerWeaponEx(playerid, weaponid, ammo);
	new msg[96], name[32];
	GetWeaponName(WEAPON:weaponid, name, sizeof(name));
	format(msg, sizeof(msg), ""chat" You received %s with %d ammo.", name, ammo);
	SendClientMessage(playerid, -1, msg);
	return 1;
}

CMD:god(playerid)
{
	if(!HasAdminTools(playerid)) return 1;
	GodMode[playerid] = !GodMode[playerid];
	SendClientMessage(playerid, -1, GodMode[playerid] ? (""chat" God mode ON.") : (""chat" God mode OFF."));
	return 1;
}

forward GodModeTick();
public GodModeTick()
{
	foreach(new playerid : Player)
	{
		if(!GodMode[playerid] || pInfo[playerid][pIsSpawned] != 1) continue;
		SetPlayerHealth(playerid, 100.0);
		pInfo[playerid][pBlood] = 12000;
		pInfo[playerid][pHunger] = 2500;
		pInfo[playerid][pThrist] = 1000;
		pInfo[playerid][pTemp] = 100.0;
		pInfo[playerid][pInfection] = 0;
		if(pInfo[playerid][IsPlayerBleeding] == 1)
		{
			StopTimer(pInfo[playerid][Bleeding]);
			pInfo[playerid][IsPlayerBleeding] = 0;
			RemovePlayerAttachedObject(playerid, 2);
		}
		if(pInfo[playerid][IsPlayerLegBroken] == 1)
		{
			pInfo[playerid][IsPlayerLegBroken] = 0;
			PlayerTextDrawHide(playerid, LegBroken[playerid]);
		}
	}
	return 1;
}
