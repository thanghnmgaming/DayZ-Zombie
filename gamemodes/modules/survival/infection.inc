// ---------------------------------------------------------------------------
// Infection: caught from zombie hits or severe cold, drains blood until cured.
// ---------------------------------------------------------------------------

#define INFECTION_TICK_MS     10000
#define INFECTION_BLOOD_LOSS  80      // per tick: a full bar lasts about 25 minutes
#define INFECTION_CHANCE      5       // percent per zombie hit
#define INFECTION_CHANCE_BRUTE 12

stock TryInfect(playerid, chance)
{
	if(pInfo[playerid][pInfection] == 1 || random(100) >= chance) return 0;
	pInfo[playerid][pInfection] = 1;
	SendClientMessage(playerid, -1, "*"COL_RED" You have been infected! Find antibiotics.");
	return 1;
}

stock CureInfection(playerid)
{
	if(pInfo[playerid][pInfection] == 0) return SendClientMessage(playerid, -1, "*"COL_RED" You are not infected of any sort!"), 0;
	pInfo[playerid][pInfection] = 0;
	SetPlayerDrunkLevel(playerid, 0);
	RemoveSlotToInventory(playerid, "Antibiotics", 1);
	SendClientMessage(playerid, -1, ""chat" You have used antibiotics. The infection is cured.");
	return 1;
}

forward InfectionTick();
public InfectionTick()
{
	foreach(new playerid : Player)
	{
		if(IsPlayerNPC(playerid) || pInfo[playerid][pInfection] != 1) continue;
		if(pInfo[playerid][pLogged] != 1 || pInfo[playerid][pIsSpawned] != 1 || isPlayerInMenu[playerid]) continue;
		pInfo[playerid][pBlood] -= INFECTION_BLOOD_LOSS;
		GameTextForPlayer(playerid, "~r~infected", 2000, 4);
	}
	return 1;
}

stock SaveInfection(playerid)
{
	new query[128], name[MAX_PLAYER_NAME];
	GetPlayerName(playerid, name, sizeof(name));
	mysql_format(handle, query, sizeof(query), "UPDATE `users` SET `pInfection`=%d WHERE `Username`='%e'", pInfo[playerid][pInfection], name);
	mysql_tquery(handle, query);
	return 1;
}
