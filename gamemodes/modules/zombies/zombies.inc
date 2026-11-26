// ---------------------------------------------------------------------------
// Zombies.
// A fixed pool of NPCs is created at start-up and kept in a hidden virtual
// world. One manager timer activates them around players, gives them senses
// and behaviour, and puts them away again when nobody is near.
// ---------------------------------------------------------------------------

#define ZOMBIE_TICK_MS          500
#define ZOMBIE_HIDDEN_WORLD     9999
#define ZOMBIES_PER_PLAYER      8       // wanted around each player
#define ZOMBIES_PER_PLAYER_DANGER 14
#define ZOMBIE_HIT_GAP_MS       800     // however many surround a player, one hit lands per gap
#define ZOMBIE_AREA_RADIUS      90.0    // counted as "around" a player
#define ZOMBIE_SPAWN_MIN        45.0    // never appear closer than this
#define ZOMBIE_SPAWN_MAX        80.0
#define ZOMBIE_DESPAWN_RADIUS   130.0
#define ZOMBIE_SPAWNS_PER_PASS  3       // per player, every spawn pass
#define ZOMBIE_SIGHT_STANDING   35.0
#define ZOMBIE_SIGHT_CROUCHED   14.0
#define ZOMBIE_SMELL_RADIUS     5.0     // noticed from any direction
#define ZOMBIE_GUNSHOT_RADIUS   90.0
#define ZOMBIE_SILENCED_RADIUS  15.0
#define ZOMBIE_MEMORY_MS        8000    // how long a lost target is searched for
#define ZOMBIE_CORPSE_MS        20000
#define ZOMBIE_ATTACK_RANGE     1.6
#define ZOMBIE_STEP             6.0     // length of one terrain-following move

enum
{
	ZSTATE_NONE,     // not created
	ZSTATE_HIDDEN,   // in the pool
	ZSTATE_IDLE,
	ZSTATE_ALERT,    // walking to a noise or a last known position
	ZSTATE_CHASE,
	ZSTATE_DEAD
}

enum E_ZOMBIE_TYPE
{
	ztName[12],
	ztChance,                // percent
	ztSkin,
	Float:ztHealth,
	NPC_MOVE_TYPE:ztMove,    // while chasing
	ztDamageMin,             // blood lost per hit
	ztDamageMax,
	ztAttackMs
}

new const ZombieTypes[][E_ZOMBIE_TYPE] =
{
	{"Walker",  35, 162, 100.0, NPC_MOVE_TYPE_JOG,    250,  450, 1300},
	{"Rotter",  35,  29, 100.0, NPC_MOVE_TYPE_JOG,    250,  450, 1300},
	{"Runner",  22,  78,  70.0, NPC_MOVE_TYPE_SPRINT, 150,  300, 1000},
	{"Brute",    8, 230, 320.0, NPC_MOVE_TYPE_WALK,   900, 1400, 2000}
};

enum E_ZOMBIE
{
	zState,
	zType,
	zTarget,
	zSeenAt,          // tick of the last time the target or noise was perceived
	zNextAttack,
	zDiedAt,
	Float:zGoalX,
	Float:zGoalY,
	Float:zGoalZ,
	Float:zStepX,
	Float:zStepY
}

new Zombie[MAX_PLAYERS][E_ZOMBIE];
new const Float:DetourAngles[] = {45.0, -45.0, 90.0, -90.0, 135.0, -135.0};
new ZombiePool[MAX_ZOMBIES];
new ZombiePoolSize;
new ZombieSpawnPass;
new PlayerNextHit[MAX_PLAYERS];

// ---- pool -----------------------------------------------------------------

forward CreateZombies();
public CreateZombies()
{
	if(ZombiePoolSize >= MAX_ZOMBIES)
	{
		KillTimer(ZombiesTimer);
		printf("Zombies creation done! (%d in the pool)", ZombiePoolSize);
		SetTimer("ZombieManager", ZOMBIE_TICK_MS, true);
		return 1;
	}

	new name[MAX_PLAYER_NAME];
	format(name, sizeof(name), "Zombie[%d]", MAX_PLAYERS - ZombiePoolSize);
	new npcid = NPC_Create(name);
	if(npcid == INVALID_PLAYER_ID)
	{
		KillTimer(ZombiesTimer);
		printf("Zombie creation stopped at %d: check max_bots in config.json", ZombiePoolSize);
		if(ZombiePoolSize) SetTimer("ZombieManager", ZOMBIE_TICK_MS, true);
		return 1;
	}

	IsAZombie[npcid] = 1;
	NPC_Spawn(npcid);
	SetPlayerColor(npcid, 0xAA333300);
	HideZombie(npcid);
	ZombiePool[ZombiePoolSize++] = npcid;
	return 1;
}

stock HideZombie(npcid)
{
	Zombie[npcid][zState] = ZSTATE_HIDDEN;
	Zombie[npcid][zTarget] = INVALID_PLAYER_ID;
	NPC_StopMove(npcid);
	NPC_StopMeleeAttack(npcid);
	NPC_SetVirtualWorld(npcid, ZOMBIE_HIDDEN_WORLD);
	NPC_SetInvulnerable(npcid, true);
	NPC_SetPos(npcid, float(npcid % 100) * 3.0, 3500.0, 500.0);
	return 1;
}

stock PickZombieType()
{
	new roll = random(100), sum;
	for(new i; i < sizeof(ZombieTypes); i++)
	{
		sum += ZombieTypes[i][ztChance];
		if(roll < sum) return i;
	}
	return 0;
}

stock ActivateZombie(npcid, Float:x, Float:y, Float:z)
{
	new type = PickZombieType();
	// in danger zones half of the ordinary zombies become runners or brutes
	if(type < 2 && GetDangerZone(x, y) != -1 && random(2) == 0) type = (random(3) == 0) ? 3 : 2;
	Zombie[npcid][zState] = ZSTATE_IDLE;
	Zombie[npcid][zType] = type;
	Zombie[npcid][zTarget] = INVALID_PLAYER_ID;
	Zombie[npcid][zStepX] = 0.0;
	Zombie[npcid][zStepY] = 0.0;

	NPC_SetSkin(npcid, ZombieTypes[type][ztSkin]);
	NPC_SetPos(npcid, x, y, z);
	NPC_SetVirtualWorld(npcid, 0);
	NPC_SetInvulnerable(npcid, false);
	NPC_SetHealth(npcid, ZombieTypes[type][ztHealth]);
	NPC_SetWeapon(npcid, WEAPON:1);
	NPC_ClearAnimations(npcid);
	SetZombieLooks(npcid);
	return 1;
}

stock SetZombieLooks(npcid)
{
	SetPlayerAttachedObject(npcid, 1, 2908, 2, 0.064999, 0.045000, 0.000999, 176.500000, 5.699998, 95.000007, 0.941999, 1.082999, 1.075000);
	SetPlayerAttachedObject(npcid, 2, 2907, 1, 0.038000, 0.051000, 0.027000, -94.999984, -0.299995, 89.399932, 1.0, 0.739000, 1.211000);
	SetPlayerAttachedObject(npcid, 3, 2906, 5, -0.146000, 0.000000, -0.007000, 10.299988, 1.500002, -89.800010, 1.0, 1.0, 1.0);
	SetPlayerAttachedObject(npcid, 4, 2905, 10, -0.176999, 0.082000, 0.005000, 0.000000, 0.000000, -92.700004, 1.067999, 0.662999, 0.998000);
	SetPlayerAttachedObject(npcid, 5, 2804, 8, 0.240999, 0.034000, 0.000000, 0.000000, 0.000000, 91.499977, 0.757999, 1.000000, 1.214999);
	SetPlayerAttachedObject(npcid, 6, 2803, 1, 0.132999, -0.161000, 0.000000, 0.000000, 91.599998, 102.699989, 0.259000, 0.369999, 0.719000);
	return 1;
}

// ---- who can be hunted ------------------------------------------------------

stock bool:IsZombiePrey(playerid)
{
#if defined ZOMBIE_TEST
	if(playerid == ZombieProbe) return ProbeBlood > 0;
#endif
	if(!IsPlayerConnected(playerid) || IsPlayerNPC(playerid)) return false;
	if(pInfo[playerid][pLogged] != 1 || pInfo[playerid][pIsSpawned] != 1 || isPlayerInMenu[playerid]) return false;
	if(pInfo[playerid][pBlood] <= 0 || GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return false;
	new PLAYER_STATE:playerstate = GetPlayerState(playerid);
	return playerstate == PLAYER_STATE_ONFOOT || playerstate == PLAYER_STATE_DRIVER || playerstate == PLAYER_STATE_PASSENGER;
}

// Hearing uses the noise meter, sight needs the player to be in front of the zombie
stock bool:ZombieSenses(npcid, playerid, Float:distance, Float:zx, Float:zy, Float:px, Float:py)
{
	if(distance <= ZOMBIE_SMELL_RADIUS) return true;
	if(distance <= float(pInfo[playerid][IsPlayerMakingNoise]) / 20.0) return true;

	new Float:sight = ZOMBIE_SIGHT_STANDING;
	if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_DUCK) sight = ZOMBIE_SIGHT_CROUCHED;
	if(distance > sight) return false;
	new Float:nx, Float:ny, Float:eyeZ;
	NPC_GetPos(npcid, nx, ny, eyeZ);
	if(FindBlockingStructure(zx, zy, eyeZ, px, py) != -1) return false;
	new Float:preyZ;
	GetPlayerPos(playerid, nx, ny, preyZ);
	if(IsWorldBlocked(zx, zy, eyeZ + 0.6, px, py, preyZ + 0.6)) return false;
	if(Zombie[npcid][zTarget] == playerid) return true;

	new Float:facing;
	NPC_GetFacingAngle(npcid, facing);
	new Float:off = atan2(py - zy, px - zx) - 90.0 - facing;
	while(off > 180.0) off -= 360.0;
	while(off < -180.0) off += 360.0;
	return floatabs(off) <= 100.0;
}

// A noise at a position draws idle zombies towards it
public AlertZombies(Float:x, Float:y, Float:z, Float:radius)
{
	for(new i; i < ZombiePoolSize; i++)
	{
		new npcid = ZombiePool[i];
		if(Zombie[npcid][zState] != ZSTATE_IDLE && Zombie[npcid][zState] != ZSTATE_ALERT) continue;
		new Float:zx, Float:zy, Float:zz;
		NPC_GetPos(npcid, zx, zy, zz);
		if(VectorSize(x - zx, y - zy, z - zz) > radius) continue;
		Zombie[npcid][zState] = ZSTATE_ALERT;
		Zombie[npcid][zSeenAt] = GetTickCount();
		Zombie[npcid][zGoalX] = x;
		Zombie[npcid][zGoalY] = y;
		Zombie[npcid][zGoalZ] = z;
	}
	return 1;
}

// ---- movement ---------------------------------------------------------------

// Moves one short step towards the goal, following the ground where the map data fits
stock ZombieStepTowards(npcid, Float:zx, Float:zy, Float:zz, Float:gx, Float:gy, Float:gz, NPC_MOVE_TYPE:movetype)
{
	new Float:dx = gx - zx, Float:dy = gy - zy, Float:length = floatsqroot(dx * dx + dy * dy);
	if(length < 0.8) return 0;

	new Float:step = ZOMBIE_STEP;
	if(length < step) step = length;
	new Float:x = zx + dx / length * step, Float:y = zy + dy / length * step;
	new Float:z = zz + (gz - zz) * (step / length), Float:ground;
	MapAndreas_FindZ_For2DCoord(x, y, ground);
	// MapAndreas reports the highest surface; ignore it under roofs, bridges and indoors
	if(ground > 0.0 && floatabs(ground + 1.0 - z) < 3.0) z = ground + 1.0;
	if(FindFloor(x, y, zz, ground)) z = ground + 1.0;

	// something solid in the way: try to go around it
	if(IsWorldBlocked(zx, zy, zz, x, y, z))
	{
		new Float:heading = atan2(dy, dx), bool:found = false;
		for(new i; i < sizeof(DetourAngles) && !found; i++)
		{
			new Float:tx = zx + floatcos(heading + DetourAngles[i], degrees) * 3.0, Float:ty = zy + floatsin(heading + DetourAngles[i], degrees) * 3.0, Float:tz = zz;
			if(FindFloor(tx, ty, zz, tz)) tz += 1.0;
			if(IsWorldBlocked(zx, zy, zz, tx, ty, tz) || FindBlockingStructure(zx, zy, zz, tx, ty) != -1) continue;
			x = tx, y = ty, z = tz;
			found = true;
		}
		if(!found) return NPC_StopMove(npcid), 1;
	}

	// look a little past the step so the body does not poke through
	new wall = FindBlockingStructure(zx, zy, zz, x + dx / length * 0.7, y + dy / length * 0.7);
	if(wall != -1)
	{
		NPC_StopMove(npcid);
		new tick = GetTickCount();
		if(tick >= Zombie[npcid][zNextAttack])
		{
			Zombie[npcid][zNextAttack] = tick + ZombieTypes[Zombie[npcid][zType]][ztAttackMs];
			NPC_MeleeAttack(npcid, 600);
			DamageStructure(wall, ZOMBIE_WALL_DAMAGE);
		}
		return 1;
	}

	// Do not restart an almost identical move
	if(NPC_IsMoving(npcid) && floatabs(x - Zombie[npcid][zStepX]) < 1.0 && floatabs(y - Zombie[npcid][zStepY]) < 1.0) return 1;
	Zombie[npcid][zStepX] = x;
	Zombie[npcid][zStepY] = y;
	NPC_Move(npcid, x, y, z, movetype);
	return 1;
}

// ---- behaviour --------------------------------------------------------------

stock ZombieThink(npcid, const prey[], preyCount, tick)
{
	new Float:zx, Float:zy, Float:zz, Float:px, Float:py, Float:pz;
	NPC_GetPos(npcid, zx, zy, zz);

	new target = INVALID_PLAYER_ID, Float:best = 100000.0, Float:closest = 100000.0;
	for(new i; i < preyCount; i++)
	{
		new playerid = prey[i];
		GetPlayerPos(playerid, px, py, pz);
		new Float:distance = VectorSize(px - zx, py - zy, pz - zz);
		if(distance < closest) closest = distance;
		if(distance < best && ZombieSenses(npcid, playerid, distance, zx, zy, px, py))
		{
			best = distance;
			target = playerid;
		}
	}

	if(closest > ZOMBIE_DESPAWN_RADIUS) return HideZombie(npcid);

	if(target != INVALID_PLAYER_ID)
	{
		Zombie[npcid][zState] = ZSTATE_CHASE;
		Zombie[npcid][zTarget] = target;
		Zombie[npcid][zSeenAt] = tick;
		GetPlayerPos(target, px, py, pz);
		Zombie[npcid][zGoalX] = px;
		Zombie[npcid][zGoalY] = py;
		Zombie[npcid][zGoalZ] = pz;

		if(VectorSize(px - zx, py - zy, 0.0) <= ZOMBIE_ATTACK_RANGE && floatabs(pz - zz) <= 1.5 && FindBlockingStructure(zx, zy, zz, px, py) == -1 && !IsWorldBlocked(zx, zy, zz, px, py, pz))
			return ZombieAttack(npcid, target, tick);

		NPC_StopMeleeAttack(npcid);
		return ZombieStepTowards(npcid, zx, zy, zz, px, py, pz, ZombieTypes[Zombie[npcid][zType]][ztMove]);
	}

	switch(Zombie[npcid][zState])
	{
		case ZSTATE_CHASE:
		{
			// lost the target: go to where it was last noticed
			Zombie[npcid][zState] = ZSTATE_ALERT;
			Zombie[npcid][zTarget] = INVALID_PLAYER_ID;
			NPC_StopMeleeAttack(npcid);
		}
		case ZSTATE_ALERT:
		{
			if(tick - Zombie[npcid][zSeenAt] > ZOMBIE_MEMORY_MS ||
			   !ZombieStepTowards(npcid, zx, zy, zz, Zombie[npcid][zGoalX], Zombie[npcid][zGoalY], Zombie[npcid][zGoalZ], NPC_MOVE_TYPE_JOG))
				Zombie[npcid][zState] = ZSTATE_IDLE;
		}
		case ZSTATE_IDLE:
		{
			// wander now and then
			if(!NPC_IsMoving(npcid) && random(14) == 0)
			{
				new Float:x = zx + float(random(17) - 8), Float:y = zy + float(random(17) - 8), Float:ground;
				MapAndreas_FindZ_For2DCoord(x, y, ground);
				if(ground > 0.5 && floatabs(ground + 1.0 - zz) < 3.0 && FindBlockingStructure(zx, zy, zz, x, y) == -1 && !IsWorldBlocked(zx, zy, zz, x, y, ground + 1.0)) NPC_Move(npcid, x, y, ground + 1.0, NPC_MOVE_TYPE_WALK);
			}
		}
	}
	return 1;
}

stock ZombieAttack(npcid, playerid, tick)
{
	NPC_StopMove(npcid);
	NPC_SetAngleToPlayer(npcid, playerid);
	if(tick < Zombie[npcid][zNextAttack]) return 1;

	new type = Zombie[npcid][zType];
	new damage = ZombieTypes[type][ztDamageMin] + random(ZombieTypes[type][ztDamageMax] - ZombieTypes[type][ztDamageMin] + 1);
	Zombie[npcid][zNextAttack] = tick + ZombieTypes[type][ztAttackMs];
	NPC_MeleeAttack(npcid, 600);
	if(tick < PlayerNextHit[playerid] && PlayerNextHit[playerid] - tick <= ZOMBIE_HIT_GAP_MS) return 1;
	PlayerNextHit[playerid] = tick + ZOMBIE_HIT_GAP_MS;
#if defined ZOMBIE_TEST
	if(playerid == ZombieProbe)
	{
		ProbeBlood -= damage;
		return 1;
	}
#endif
	if(GodMode[playerid]) return 1;
	// This is the only place where a zombie takes blood
	pInfo[playerid][pBlood] -= damage;
	TryInfect(playerid, (type == sizeof(ZombieTypes) - 1) ? INFECTION_CHANCE_BRUTE : INFECTION_CHANCE);
	return 1;
}

// ---- manager ----------------------------------------------------------------

stock SpawnZombiesAround(playerid, const prey[], preyCount)
{
	new Float:px, Float:py, Float:pz, Float:x, Float:y, Float:z, around;
	GetPlayerPos(playerid, px, py, pz);

	for(new i; i < ZombiePoolSize; i++)
	{
		new npcid = ZombiePool[i];
		if(Zombie[npcid][zState] < ZSTATE_IDLE || Zombie[npcid][zState] == ZSTATE_DEAD) continue;
		NPC_GetPos(npcid, x, y, z);
		if(VectorSize(x - px, y - py, z - pz) <= ZOMBIE_AREA_RADIUS) around++;
	}

	new wanted = ((GetDangerZone(px, py) == -1) ? ZOMBIES_PER_PLAYER : ZOMBIES_PER_PLAYER_DANGER) - around, spawned, slot;
	if(wanted > ZOMBIE_SPAWNS_PER_PASS) wanted = ZOMBIE_SPAWNS_PER_PASS;

	for(new attempt; attempt < wanted * 6 && spawned < wanted; attempt++)
	{
		new Float:angle = float(random(360)), Float:range = ZOMBIE_SPAWN_MIN + float(random(floatround(ZOMBIE_SPAWN_MAX - ZOMBIE_SPAWN_MIN)));
		x = px + range * floatsin(angle, degrees);
		y = py + range * floatcos(angle, degrees);
		MapAndreas_FindZ_For2DCoord(x, y, z);
		// skip water, roofs and cliffs
		if(z <= 0.5 || floatabs(z + 1.0 - pz) > 10.0) continue;

		new bool:tooClose = false;
		for(new i; i < preyCount; i++)
			if(IsPlayerInRangeOfPoint(prey[i], ZOMBIE_SPAWN_MIN - 5.0, x, y, z + 1.0)) tooClose = true;
		if(tooClose) continue;

		while(slot < ZombiePoolSize && Zombie[ZombiePool[slot]][zState] != ZSTATE_HIDDEN) slot++;
		if(slot >= ZombiePoolSize) break;
		ActivateZombie(ZombiePool[slot], x, y, z + 1.0);
		spawned++;
	}
	return spawned;
}

forward ZombieManager();
public ZombieManager()
{
	new prey[MAX_PLAYERS], preyCount, tick = GetTickCount(), alive;
	foreach(new playerid : Player)
		if(IsZombiePrey(playerid)) prey[preyCount++] = playerid;
#if defined ZOMBIE_TEST
	if(ZombieProbe != INVALID_PLAYER_ID && IsZombiePrey(ZombieProbe)) prey[preyCount++] = ZombieProbe;
#endif

	for(new i; i < ZombiePoolSize; i++)
	{
		new npcid = ZombiePool[i];
		switch(Zombie[npcid][zState])
		{
			case ZSTATE_DEAD:
			{
				if(tick - Zombie[npcid][zDiedAt] >= ZOMBIE_CORPSE_MS)
				{
					NPC_Respawn(npcid);
					HideZombie(npcid);
				}
			}
			case ZSTATE_IDLE, ZSTATE_ALERT, ZSTATE_CHASE:
			{
				ZombieThink(npcid, prey, preyCount, tick);
				if(Zombie[npcid][zState] >= ZSTATE_IDLE) alive++;
			}
		}
	}

	// new zombies appear every two seconds
	if(++ZombieSpawnPass >= 2000 / ZOMBIE_TICK_MS)
	{
		ZombieSpawnPass = 0;
		for(new i; i < preyCount; i++) SpawnZombiesAround(prey[i], prey, preyCount);
	}
	ZombiesAlive = alive;
	return 1;
}

// ---- events -----------------------------------------------------------------

forward OnNPCDeath(npcid, killerid, WEAPON:reason);
public OnNPCDeath(npcid, killerid, WEAPON:reason)
{
	if(!IsAZombie[npcid] || Zombie[npcid][zState] == ZSTATE_DEAD) return 1;
	Zombie[npcid][zState] = ZSTATE_DEAD;
	Zombie[npcid][zDiedAt] = GetTickCount();
	NPC_ApplyAnimation(npcid, "PED", "BIKE_fall_off", 4.1, false, true, true, true, 0);

	new Float:x, Float:y, Float:z;
	NPC_GetPos(npcid, x, y, z);
	DayZSA_CreateZLoot(x, y, z);

	if(0 <= killerid < MAX_PLAYERS && IsPlayerConnected(killerid))
	{
		pInfo[killerid][ZombiesKilled]++;
		MissionZombieKilled(killerid, GetDangerZone(x, y) != -1);
		if(IsPlayerAimingTargetBodyPart(killerid, npcid, BODY_PART_HEAD))
		{
			GameTextForPlayer(killerid, "~r~~h~Headshot!", 3000, 3);
			pInfo[killerid][Headshots]++;
		}
		SendDeathMessage(killerid, npcid, reason);
	}
	return 1;
}

forward OnNPCTakeDamage(npcid, issuerid, Float:amount, WEAPON:weaponid, bodypart);
public OnNPCTakeDamage(npcid, issuerid, Float:amount, WEAPON:weaponid, bodypart)
{
	if(!IsAZombie[npcid]) return 1;
	if(weaponid == WEAPON_SNIPER) NPC_SetHealth(npcid, NPC_GetHealth(npcid) - 120.0);
	// being hit tells the zombie where the attacker is
	if((Zombie[npcid][zState] == ZSTATE_IDLE || Zombie[npcid][zState] == ZSTATE_ALERT) && 0 <= issuerid < MAX_PLAYERS && IsPlayerConnected(issuerid))
	{
		Zombie[npcid][zState] = ZSTATE_ALERT;
		Zombie[npcid][zSeenAt] = GetTickCount();
		GetPlayerPos(issuerid, Zombie[npcid][zGoalX], Zombie[npcid][zGoalY], Zombie[npcid][zGoalZ]);
	}
	return 1;
}

function DayZSA_CreateZLoot(Float:pXX,Float:pYX,Float:pZX)
{
	AllocLoot();
	Loot[lootCount][xLoot] = pXX;
	Loot[lootCount][yLoot] = pYX;
	Loot[lootCount][zLoot] = pZX;

	// low 6 in 16, medium 7 in 16, high 3 in 16; danger zones never drop low loot
	switch((GetDangerZone(pXX, pYX) == -1) ? random(16) : 6 + random(10))
	{
		case 0..5: DayZSA_LootSetupLow();
		case 6..12: DayZSA_LootSetupMedium();
		default: DayZSA_LootSetupHigh();
	}

	Loot[lootCount][AntiDup] = 1;
	Loot[lootCount][LootID] = CreateDynamicObject(Loot[lootCount][ModelID],pXX,pYX,pZX-0.9,Loot[lootCount][LootRotX],Loot[lootCount][LootRotY],Loot[lootCount][LootRotZ],-1,-1,-1,1000.0);
	Loot[lootCount][TextID] = CreateDynamic3DTextLabel(""COL_GREEN"GEAR\n"COL_GREY"Press N to pick up zombie loot!",-1,pXX,pYX,pZX-0.9,8.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1,-1,-1,-1, 8.0);
	return 1;
}

stock Float:frandom(Float:max)
{
	return floatdiv(float(random(0)), floatdiv(float(cellmax), max));
}

function Float:floatrand(Float:min, Float:max) //By Alex "Y_Less" Cole
{
	new imin = floatround(min);
	return floatdiv(float(random((floatround(max)-imin)*100)+(imin*100)),100.0);
}

#if defined ZOMBIE_TEST
// Developer harness: an ordinary NPC stands in for a player so the behaviour can be checked
forward ZombieProbeStart();
public ZombieProbeStart()
{
	new npcid = NPC_Create("Probe");
	NPC_Spawn(npcid);
	new Float:z;
	MapAndreas_FindZ_For2DCoord(-300.0, -100.0, z);
	NPC_SetPos(npcid, -300.0, -100.0, z + 1.0);
	ZombieProbe = npcid;
	SetTimer("ZombieProbeReport", 5000, true);
	return 1;
}

forward ZombieProbeReport();
public ZombieProbeReport()
{
	new count[6], Float:nearest = 1000.0, Float:x, Float:y, Float:z;
	for(new i; i < ZombiePoolSize; i++)
	{
		new npcid = ZombiePool[i];
		count[Zombie[npcid][zState]]++;
		if(Zombie[npcid][zState] < ZSTATE_IDLE) continue;
		NPC_GetPos(npcid, x, y, z);
		new Float:d = GetPlayerDistanceFromPoint(ZombieProbe, x, y, z);
		if(d < nearest) nearest = d;
	}
	printf("[ZTEST] hidden=%d idle=%d alert=%d chase=%d dead=%d nearest=%.1f probeBlood=%d", count[1], count[2], count[3], count[4], count[5], nearest, ProbeBlood);
	static step;
	if(++step == 4)
	{
		GetPlayerPos(ZombieProbe, x, y, z);
		AlertZombies(x, y, z, 200.0);
		print("[ZTEST] gunshot");
	}
	return 1;
}
#endif
