// ---------------------------------------------------------------------------
// Danger zones, supply airdrops and missions.
// ---------------------------------------------------------------------------

#define AIRDROP_INTERVAL_MS   480000
#define MISSION_COOLDOWN      300     // seconds

enum E_ZONE
{
	dzName[32],
	Float:dzX,
	Float:dzY,
	Float:dzRadius
}

// More and nastier zombies, better loot
new const DangerZones[][E_ZONE] =
{
	{"Area 51",                  213.0,  1900.0, 220.0},
	{"San Fierro Naval Base",  -1400.0,   450.0, 220.0},
	{"Downtown Los Santos",     1480.0, -1650.0, 250.0},
	{"Las Venturas Strip",      2100.0,  1700.0, 250.0}
};

new DangerGangZone[sizeof(DangerZones)];

stock GetDangerZone(Float:x, Float:y)
{
	for(new i; i < sizeof(DangerZones); i++)
		if(VectorSize(x - DangerZones[i][dzX], y - DangerZones[i][dzY], 0.0) <= DangerZones[i][dzRadius]) return i;
	return -1;
}

forward ZoneTick();
public ZoneTick()
{
	foreach(new playerid : Player)
	{
		if(IsPlayerNPC(playerid) || pInfo[playerid][pLogged] != 1 || pInfo[playerid][pIsSpawned] != 1) continue;
		new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
		new zone = GetDangerZone(x, y) + 1;
		if(PlayerZone[playerid] == -1)
		{
			for(new i; i < sizeof(DangerZones); i++) GangZoneShowForPlayer(playerid, DangerGangZone[i], 0xB4000055);
			PlayerZone[playerid] = 0;
		}
		if(zone != PlayerZone[playerid])
		{
			new msg[128];
			if(zone) format(msg, sizeof(msg), "*"COL_RED" Danger zone: %s. More zombies, better loot.", DangerZones[zone - 1][dzName]);
			else format(msg, sizeof(msg), ""chat" You left the danger zone.");
			SendClientMessage(playerid, -1, msg);
			PlayerZone[playerid] = zone;
		}
	}
	return 1;
}

// ---- supply airdrops --------------------------------------------------------

enum E_DROP
{
	adName[32],
	Float:adX,
	Float:adY,
	Float:adZ
}

new const AirdropSites[][E_DROP] =
{
	{"the Area 51 runway",      306.4262,  2026.7247, 16.7366},
	{"Grove Street",           2486.3821, -1662.7250, 13.3359},
	{"the San Fierro docks",  -1631.7996,  1419.6204,  7.1875}
};

new EventCrate, Float:EventCrateX, EventCrateIcon;

forward Airdrop();
public Airdrop()
{
	new bool:anyone = false;
	foreach(new i : Player)
		if(!IsPlayerNPC(i) && pInfo[i][pLogged] == 1) anyone = true;
	if(!anyone) return 1;

	// remove the previous event crate (its slot may have been reused after a loot respawn)
	if(EventCrate && Loot[EventCrate][xAir] == EventCrateX && EventCrateX != 0.0)
		FreeLoot(EventCrate);
	if(EventCrateIcon) DestroyDynamicMapIcon(EventCrateIcon);

	new site = random(sizeof(AirdropSites)), msg[144];
	DayZSA_CreateAirdrop(AirdropSites[site][adX] + 3.0, AirdropSites[site][adY] + 3.0, AirdropSites[site][adZ]);
	EventCrate = lootCount;
	EventCrateX = Loot[EventCrate][xAir];
	EventCrateIcon = CreateDynamicMapIcon(AirdropSites[site][adX], AirdropSites[site][adY], AirdropSites[site][adZ], 5, 0, -1, -1, -1, 6000.0, MAPICON_GLOBAL);
	format(msg, sizeof(msg), "*"COL_GREEN" A supply crate has been dropped near %s!", AirdropSites[site][adName]);
	SendClientMessageToAll(-1, msg);
	AlertZombies(AirdropSites[site][adX], AirdropSites[site][adY], AirdropSites[site][adZ], 120.0);
	return 1;
}

// ---- missions ---------------------------------------------------------------

new const MissionRewards[][ITEM_NAME_SIZE] =
{
	"Medical Kit", "Blood Bag", "Antibiotics", "Assault Ammo", "Sniper Ammo", "Wooden Wall", "Toolbox", "M4"
};


CMD:mission(playerid)
{
	if(pInfo[playerid][pLogged] != 1 || pInfo[playerid][pIsSpawned] != 1) return 1;
	new msg[144];
	if(!MissionGoal[playerid])
	{
		if(gettime() < MissionNext[playerid])
		{
			format(msg, sizeof(msg), ""chat" Next mission in %d seconds.", MissionNext[playerid] - gettime());
			return SendClientMessage(playerid, -1, msg);
		}
		MissionInDanger[playerid] = random(3) == 0;
		MissionGoal[playerid] = MissionInDanger[playerid] ? 5 : 5 + 5 * random(3);
		MissionKills[playerid] = 0;
	}
	format(msg, sizeof(msg), ""chat" Mission: kill %d zombies%s. Progress %d/%d.", MissionGoal[playerid],
		MissionInDanger[playerid] ? (" inside a danger zone") : (""), MissionKills[playerid], MissionGoal[playerid]);
	SendClientMessage(playerid, -1, msg);
	return 1;
}

stock MissionZombieKilled(playerid, bool:inDanger)
{
	if(!MissionGoal[playerid] || (MissionInDanger[playerid] && !inDanger)) return 0;
	if(MissionKills[playerid] < MissionGoal[playerid]) MissionKills[playerid]++;
	if(MissionKills[playerid] < MissionGoal[playerid]) return 1;

	new reward = random(sizeof(MissionRewards)), msg[128];
	// a full backpack keeps the mission open until the next kill
	if(!AddSlotToInventoryWorld(playerid, MissionRewards[reward], 1)) return 1;
	format(msg, sizeof(msg), "*"COL_GREEN" Mission complete! Reward: %s", MissionRewards[reward]);
	SendClientMessage(playerid, -1, msg);
	MissionGoal[playerid] = 0;
	MissionNext[playerid] = gettime() + MISSION_COOLDOWN;
	return 1;
}

stock StartSurvivalSystems()
{
	for(new i; i < sizeof(DangerZones); i++)
		DangerGangZone[i] = GangZoneCreate(DangerZones[i][dzX] - DangerZones[i][dzRadius], DangerZones[i][dzY] - DangerZones[i][dzRadius],
			DangerZones[i][dzX] + DangerZones[i][dzRadius], DangerZones[i][dzY] + DangerZones[i][dzRadius]);
	mysql_tquery(handle, "ALTER TABLE `users` ADD COLUMN IF NOT EXISTS `pInfection` int NOT NULL DEFAULT 0");
	mysql_tquery(handle, "ALTER TABLE `users` ADD COLUMN IF NOT EXISTS `pMissionGoal` int NOT NULL DEFAULT 0");
	mysql_tquery(handle, "ALTER TABLE `users` ADD COLUMN IF NOT EXISTS `pMissionKills` int NOT NULL DEFAULT 0");
	mysql_tquery(handle, "ALTER TABLE `users` ADD COLUMN IF NOT EXISTS `pMissionDanger` int NOT NULL DEFAULT 0");
	mysql_tquery(handle, "ALTER TABLE `users` ADD COLUMN IF NOT EXISTS `pMissionNext` int NOT NULL DEFAULT 0");
	LoadStructures();
	SetTimer("GodModeTick", 250, true);
	CreateAuditTable();
	mysql_tquery(handle, "ALTER TABLE `samp_ban` MODIFY `user_banned_ip` varchar(45) NOT NULL");
	mysql_tquery(handle, "ALTER TABLE `users` ADD UNIQUE INDEX IF NOT EXISTS `uq_username` (`Username`)");
	SetTimer("MovementCheck", 1000, true);
	SetTimer("ZoneTick", 3000, true);
	SetTimer("InfectionTick", INFECTION_TICK_MS, true);
	SetTimer("Airdrop", AIRDROP_INTERVAL_MS, true);
	return 1;
}
