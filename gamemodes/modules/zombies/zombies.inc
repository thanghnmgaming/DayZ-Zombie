// Zombies

forward OnNPCChangeNode(npcid, newnodeid, oldnodeid);
public OnNPCChangeNode(npcid, newnodeid, oldnodeid)
{
	// Validate the node zone
 	return IsValidZone(newnodeid) ? 1 : 0;
}

stock IsValidZone(zoneid)
{
#if defined SAN_ANDREAS
	return zoneid > 0 && zoneid < NPC_MAX_NODES;
#elseif defined LOS_SANTOS
	return (zoneid >= 5 && zoneid <= 7) || (zoneid >= 12 && zoneid <= 15) || (zoneid >= 20 && zoneid <= 23);
#elseif defined SAN_FIERRO
	return zoneid == 17 || (zoneid >= 24 && zoneid <= 26) || (zoneid >= 32 && zoneid <= 24)  || (zoneid >= 40 && zoneid <= 41);
#elseif defined LAS_VENTURAS
	return (zoneid >= 38 && zoneid <= 39) || (zoneid >= 45 && zoneid <= 47) || (zoneid >= 53 && zoneid <= 55) || (zoneid >= 61 && zoneid <= 63);
#else
	return false;
#endif
}

stock ZombieSpawnAt(npcid, skinid, Float:x, Float:y, Float:z)
{
	NPC_SetSkin(npcid, skinid);
	NPC_SetPos(npcid, x, y, z);
	if(!NPC_IsSpawned(npcid) || NPC_IsDead(npcid)) NPC_Spawn(npcid);
	return 1;
}

stock Float:frandom(Float:max)
{
	return floatdiv(float(random(0)), floatdiv(float(cellmax), max));
}

forward CreateZombies();
public CreateZombies()
{
	new str[50]; //objects[7];
	//new Random = random(sizeof(ZombieSpawns));
	new nodeid, point, pednodes, vehnodes, navinodes;
	if(SpawnedZombies < MAX_ZOMBIES)
	{

		new thenpc_;
		format(str,sizeof(str),"Zombie[%d]",MAX_PLAYERS-(SpawnedZombies));
		thenpc_ = NPC_Create(str);
		if(thenpc_ == INVALID_PLAYER_ID)
		{
			KillTimer(ZombiesTimer);
			printf("Zombie creation stopped at %d: check max_bots in config.json", SpawnedZombies);
			return 1;
		}
		/*ZombieLabel[thenpc_] = Create3DTextLabel("Zombie\nHP: 100", -1, 30.0, 40.0, 50.0, 60.0, -1, 0);
		Attach3DTextLabelToPlayer(ZombieLabel[thenpc_], thenpc_, 0.0, 0.0, 0.4);*/

		new skinidl;
		switch(random(2))
		{
		    case 0: skinidl = 162;
		    case 1: skinidl = 29;
		}
		NPC_ClearAnimations(thenpc_);
		NPC_ApplyAnimation(thenpc_, "PED", "WALK_DRUNK", 4.1, 1, 1,  1,  0,  0);
		
		

		do
		{
			nodeid = random(NPC_MAX_NODES);
		} while (!IsValidZone(nodeid));
        NPC_GetNodeInfo(nodeid, vehnodes, pednodes, navinodes);
        new Float:posNodes[3];
        if (random(2) == 1 && pednodes != 0)
		{
			point = random(pednodes - 1) + vehnodes + 1;
			NPC_SetNodePoint(nodeid, point);
			NPC_GetNodePointPosition(nodeid, posNodes[0], posNodes[1], posNodes[2]);
			ZombieSpawnAt(thenpc_, skinidl, posNodes[0], posNodes[1], posNodes[2]);
		}
		else
		{
			point = random(vehnodes - 1);
			NPC_SetNodePoint(nodeid, point);
			NPC_GetNodePointPosition(nodeid, posNodes[0], posNodes[1], posNodes[2]);
			ZombieSpawnAt(thenpc_, skinidl, posNodes[0], posNodes[1], posNodes[2]);
		}
		NPC_SetWeapon(thenpc_, 1);
		NPC_SetHealth(thenpc_, 100);
		NPC_ClearAnimations(thenpc_);
		NPC_ApplyAnimation(thenpc_, "PED", "WALK_DRUNK", 4.1, 1, 1,  1,  0,  0);
		ZombieTimer[thenpc_] = SetTimerEx("ZombieMove", 500, true, "i", thenpc_);
		SetPlayerColor(thenpc_,0xAA333300);
		IsAZombie[thenpc_] = 1;
		SetPlayerAttachedObject( thenpc_, 1, 2908, 2, 0.064999,0.045000,0.000999, 176.500000, 5.699998, 95.000007, 0.941999, 1.082999, 1.075000 );
		SetPlayerAttachedObject( thenpc_, 2, 2907, 1, 0.038000,0.051000,0.027000,-94.999984, -0.299995, 89.399932, 1.0, 0.739000, 1.211000 );
		SetPlayerAttachedObject( thenpc_, 3, 2906, 5, -0.146000,0.000000,-0.007000,10.299988,1.500002, -89.800010, 1.0, 1.0, 1.0 );
		SetPlayerAttachedObject( thenpc_, 4, 2905, 10, -0.176999,0.082000,0.005000, 0.000000, 0.000000, -92.700004,1.067999, 0.662999, 0.998000 );
		SetPlayerAttachedObject( thenpc_, 5, 2804, 8, 0.240999,0.034000,0.000000, 0.000000, 0.000000,91.499977, 0.757999, 1.000000, 1.214999 );
		SetPlayerAttachedObject( thenpc_, 6, 2803, 1,0.132999,-0.161000,0.000000, 0.000000,91.599998,102.699989, 0.259000,0.369999, 0.719000 );
		SpawnedZombies++;

	}
	else
	{
		KillTimer(ZombiesTimer);
		printf("Zombies creation done!");
	}
	return 1;
}
forward OnNPCDeath(npcid, killerid, WEAPON:reason);
public OnNPCDeath(npcid, killerid, WEAPON:reason)
{
	if(!IsAZombie[npcid]) return 1;
	ZombieAttackPlayer[npcid] = 0;
	NPC_ApplyAnimation(npcid, "PED", "BIKE_fall_off", 4.1, false, true, true, true, 0);
	CallLocalFunction("OnPlayerKillZombie","ii",killerid,npcid);

	new Float:fPos[3];

	NPC_GetPos(npcid,fPos[0],fPos[1],fPos[2]);
	DayZSA_CreateZLoot(fPos[0],fPos[1],fPos[2]);

	if(0 <= killerid < MAX_PLAYERS && IsPlayerConnected(killerid))
	{
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
	if(weaponid == WEAPON_SNIPER) NPC_SetHealth(npcid, NPC_GetHealth(npcid) - 120.0);
	return 1;
}

forward ZombieMove(zombieid);
public ZombieMove(zombieid)
{
	new Float:xa,Float:ya,Float:za;
	if(NPC_IsDead(zombieid)) return 1;
	foreach (new playerid : Player)
	{
		if(IsPlayerNPC(playerid)) continue;
		GetPlayerPos(playerid,xa,ya,za);
		MapAndreas_SetZ_For2DCoord(xa,ya,za);
		if(IsPlayerInRangeOfPoint(zombieid,1.2,xa,ya,za))// here playerid not zombieid
		{
		    NPC_StopMove(zombieid);
			ZombieAttackPlayer[zombieid] = 2;
			NPC_MeleeAttack(zombieid,100);
			pInfo[playerid][pBlood] -= random(35);
			if(pInfo[playerid][pBlood] <= 0)
			{
			    NPC_StopMove(zombieid);
			    NPC_StopMeleeAttack(zombieid);
			    ZombieAttackPlayer[zombieid] = 1;
			    NPC_ResumePlayingNode(zombieid);
			}
			break;
		}
		else if(IsPlayerInRangeOfPoint(zombieid,30.0,xa,ya,za))
		{
			if(ZombieAttackPlayer[zombieid] == 2)
			{
				NPC_StopMove(zombieid);
				NPC_StopMeleeAttack(zombieid);
			}
			ZombieAttackPlayer[zombieid] = 1;
			NPC_Move(zombieid, xa, ya, za);
			break;
		}
		else if(IsPlayerInRangeOfPoint(zombieid,35.0,xa,ya,za))
		{
			if(ZombieAttackPlayer[zombieid] == 2)
			{
				NPC_StopMove(zombieid);
				NPC_StopMeleeAttack(zombieid);
			}
			ZombieAttackPlayer[zombieid] = 1;
			break;
		}
		else
		{
			ZombieAttackPlayer[zombieid] = 0;
		}
	}
	return 1;
}

forward OnPlayerKillZombie(playerid, zombieid);
public OnPlayerKillZombie(playerid,zombieid)
{
	if(0 <= playerid < MAX_PLAYERS && IsPlayerConnected(playerid)) pInfo[playerid][ZombiesKilled]++;
	ZombiesAlive--;
	SetTimerEx("RespawnZ", 45000, false, "i", zombieid);
	return 1;
}

forward RespawnZ(zombieid);
public RespawnZ(zombieid)
{
    NPC_Respawn(zombieid);
	return 1;
}

forward OnNPCRespawn(npcid);
public OnNPCRespawn(npcid)
{
    new nodeid, point, pednodes, vehnodes, navinodes;
	new skinidl;
	switch(random(2))
	{
		case 0: skinidl = 162;
		case 1: skinidl = 29;
	}


	do
	{
		nodeid = random(NPC_MAX_NODES);
	} while (!IsValidZone(nodeid));
	NPC_GetNodeInfo(nodeid, vehnodes, pednodes, navinodes);
	new Float:posNodes[3];
	if (random(2) == 1 && pednodes != 0)
	{
		point = random(pednodes - 1) + vehnodes + 1;
		NPC_SetNodePoint(nodeid, point);
		NPC_GetNodePointPosition(nodeid, posNodes[0], posNodes[1], posNodes[2]);
		ZombieSpawnAt(npcid, skinidl, posNodes[0], posNodes[1], posNodes[2]);
	}
	else
	{
		point = random(vehnodes - 1);
		NPC_SetNodePoint(nodeid, point);
		NPC_GetNodePointPosition(nodeid, posNodes[0], posNodes[1], posNodes[2]);
		ZombieSpawnAt(npcid, skinidl, posNodes[0], posNodes[1], posNodes[2]);
	}
	NPC_StopMeleeAttack(npcid);
	NPC_SetWeapon(npcid,1);
	NPC_ApplyAnimation(npcid, "PED", "WALK_DRUNK", 4.1, 1, 1,  1,  0,  0);
	NPC_SetAmmo(npcid,1);
	ZombiesAlive++;
	return 1;
}

function DayZSA_CreateZLoot(Float:pXX,Float:pYX,Float:pZX)
{
	new strt[128];
	lootCount += 1;
	Loot[lootCount][xLoot] = pXX;
	Loot[lootCount][yLoot] = pYX;
	Loot[lootCount][zLoot] = pZX;

	switch(random(16))
	{
		case 0: DayZSA_LootSetupLow();
		case 1: DayZSA_LootSetupMedium();
		case 2: DayZSA_LootSetupHigh();
		case 3: DayZSA_LootSetupLow();
		case 4: DayZSA_LootSetupMedium();
		case 5: DayZSA_LootSetupHigh();
		case 6: DayZSA_LootSetupMedium();
		case 7: DayZSA_LootSetupHigh();
		case 8: DayZSA_LootSetupMedium();
		case 9: DayZSA_LootSetupLow();
		case 10: DayZSA_LootSetupLow();
		case 11: DayZSA_LootSetupMedium();
		case 12: DayZSA_LootSetupMedium();
		case 13: DayZSA_LootSetupLow();
		case 14: DayZSA_LootSetupMedium();
		case 15: DayZSA_LootSetupLow();
	}

    Loot[lootCount][AntiDup] = 1;
	Loot[lootCount][LootID] = CreateDynamicObject(Loot[lootCount][ModelID],pXX,pYX,pZX-0.9,Loot[lootCount][LootRotX],Loot[lootCount][LootRotY],Loot[lootCount][LootRotZ],-1,-1,-1,1000.0);
	format(strt,sizeof(strt),""COL_GREEN"GEAR\n"COL_GREY"Press N to pick up zombie loot!");
    Loot[lootCount][TextID] = CreateDynamic3DTextLabel(strt,-1,pXX,pYX,pZX-0.9,8.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1,-1,-1,-1, 8.0);
	return 1;
}

function Float:floatrand(Float:min, Float:max) //By Alex "Y_Less" Cole
{
	new imin = floatround(min);
	return floatdiv(float(random((floatround(max)-imin)*100)+(imin*100)),100.0);
}

