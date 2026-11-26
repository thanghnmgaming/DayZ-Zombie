public OnGameModeExit()
{
	AutoSaveAll();
    DeleteTDS();

    for(new i; i < MAX_PLAYERS; i ++)
    {
    	if(IsPlayerAttachedObjectSlotUsed(i, 1)) RemovePlayerAttachedObject(i, 1);
	}

	for (new i = 0; i < NPC_MAX_NODES; i++) {
		if (NPC_IsNodeOpen(i)) {
			NPC_CloseNode(i);
		}
	}

    DestroyAllDynamicObjects();
    for(new i = 0; i < MAX_LOOTING; i++)
    {
   		DestroyDynamicObject(Loot[i][LootID]);
		DestroyDynamic3DTextLabel(Loot[i][TextID]);
	 	Loot[i][LootID] = 0;
		Loot[i][xLoot] = 0.0;
		Loot[i][yLoot] = 0.0;
		Loot[i][zLoot] = 0.0;
		Loot[i][DropGunX] = 0.0;
		Loot[i][DropGunY] = 0.0;
		Loot[i][DropGunZ] = 0.0;
		Loot[i][xLootdrop] = 0.0;
		Loot[i][yLootdrop] = 0.0;
		Loot[i][zLootdrop] = 0.0;
		Loot[i][zLootDeadBodyX] = 0.0;
		Loot[i][zLootDeadBodyY] = 0.0;
		Loot[i][zLootDeadBodyZ] = 0.0;
	}
	for(new i = 0; i < MAX_PLAYERS; i++) DestroyDynamic3DTextLabel(PlayerLabel[i]);
	mysql_close(handle); // waits for the queued save queries
	return 1;
}

public OnPlayerTakeDamage(playerid, issuerid, Float: amount, WEAPON:weaponid)
{
	if(GodMode[playerid]) return SetPlayerHealth(playerid, 100.0), 1;
    if(issuerid != INVALID_PLAYER_ID && IsPlayerNPC(issuerid))
    {
    	// blood is taken in ZombieAttack; the melee animation must not drain engine health
    	SetPlayerHealth(playerid, 100.0);
    	return 1;
    }

    if(issuerid != INVALID_PLAYER_ID)
    {
	    if(timerdamage[playerid] != 0) KillTimer(timerdamage[playerid]);

	    hit[playerid]++;
	    damage2[playerid] += amount;

	    timerdamage[playerid] = SetTimerEx("DamageReset", 3000, false, "i", playerid);

	    PlayerTextDrawShow(playerid, IndicatorBox[playerid]);
	    PlayerTextDrawShow(playerid, Indicator[playerid]);

	    new str[50];
	    format(str,sizeof(str),"HIT: %d hit(s) %.0f dmg", hit[playerid], damage2[playerid]);
	    PlayerTextDrawSetString(playerid, Indicator[playerid], str);
	}
	{
	new Float:hp;GetPlayerHealth(playerid,hp);
	if(IsPlayerNPC(issuerid))
	{
		SetPlayerHealth(playerid,hp-random(30));
	}

    if(issuerid != INVALID_PLAYER_ID)
    {
    	if(weaponid != 0)
		{
			FadePlayerScreen(playerid);

			if(IsPlayerAimingTargetBodyPart(issuerid, playerid, BODY_PART_LEGS) || IsPlayerAimingTargetBodyPart(playerid, playerid, BODY_PART_LEGS))
			{
			    if(pInfo[playerid][IsPlayerLegBroken] == 0)
			    {
			        pInfo[playerid][IsPlayerLegBroken] = 1;
			        PlayerTextDrawShow(playerid, LegBroken[playerid]);
				}
			}

			if(pInfo[issuerid][pPremium] >= 4)
			{
				if(weaponid == 25)
				{
			  		new Float:px, Float:py,Float:pz,Float:ix,Float:iy,Float:iz;
				    GetPlayerPos(playerid, px, py, pz);
				    GetPlayerPos(issuerid, ix, iy, iz);
				    new Float:h = GetPlayerDistanceFromPoint(issuerid, px, py, pz),Float:c1 = py - iy,Float:c2 = px - ix;
					new Float:vx = c2 / h,Float:vy = c1 / h;
				    SetPlayerVelocity(playerid, 0.35 * vx, 0.35 * vy, 0.1);
				    ApplyAnimation(playerid, "PED", "FALL_back", 4.0, false, true, true, true, 0, 1);
				    SetTimerEx("GetUp", 1000, false, "i", playerid);
				}
			}
		}
	}

	if(issuerid == INVALID_PLAYER_ID)
	{
	    FadePlayerScreen(playerid);
		if(pInfo[playerid][pPremium] >= 3)
		{
		    switch(random(3))
		    {
		        case 1:
		        {
      				switch(random(14))
					{
						case 0: pInfo[playerid][pBlood] -= random(4000);
						case 1: if(pInfo[playerid][IsPlayerBleeding] == 0) { pInfo[playerid][pBlood] -= random(4000), KillTimer(pInfo[playerid][Bleeding]), RemovePlayerAttachedObject(playerid, 2),pInfo[playerid][Bleeding] = SetTimerEx("LoosingBlood",2500,true,"i",playerid),pInfo[playerid][IsPlayerBleeding] = 1; } // Loosing blood ever 2.5 seconds!
						case 2: pInfo[playerid][pBlood] -= random(4000);
						case 3: if(pInfo[playerid][IsPlayerBleeding] == 0) { pInfo[playerid][pBlood] -= random(4000), KillTimer(pInfo[playerid][Bleeding]), RemovePlayerAttachedObject(playerid, 2),pInfo[playerid][Bleeding] = SetTimerEx("LoosingBlood",1000,true,"i",playerid),pInfo[playerid][IsPlayerBleeding] = 1; } // Loosing blood ever 1 second!
						case 4: pInfo[playerid][pBlood] -= random(4000);
						case 5: pInfo[playerid][pBlood] -= random(4000);
						case 6: if(pInfo[playerid][IsPlayerBleeding] == 0) { pInfo[playerid][pBlood] -= random(4000), KillTimer(pInfo[playerid][Bleeding]), RemovePlayerAttachedObject(playerid, 2),pInfo[playerid][Bleeding] = SetTimerEx("LoosingBlood",5000,true,"i",playerid),pInfo[playerid][IsPlayerBleeding] = 1; } // Loosing blood ever 5 seconds!
						case 7: pInfo[playerid][pBlood] -= random(4000);
						case 8: if(pInfo[playerid][IsPlayerBleeding] == 0) { pInfo[playerid][pBlood] -= random(4000), KillTimer(pInfo[playerid][Bleeding]), RemovePlayerAttachedObject(playerid, 2),pInfo[playerid][Bleeding] = SetTimerEx("LoosingBlood",10000,true,"i",playerid),pInfo[playerid][IsPlayerBleeding] = 1; } // Loosing blood ever 10 seconds!
						case 9: pInfo[playerid][pBlood] -= random(4000);
						case 10: if(pInfo[playerid][IsPlayerBleeding] == 0) { pInfo[playerid][pBlood] -= random(4000), KillTimer(pInfo[playerid][Bleeding]), RemovePlayerAttachedObject(playerid, 2),pInfo[playerid][Bleeding] = SetTimerEx("LoosingBlood",5500,true,"i",playerid),pInfo[playerid][IsPlayerBleeding] = 1; } // Loosing blood ever 5.5 seconds!
						case 11: pInfo[playerid][pBlood] -= random(4000);
						case 12: if(pInfo[playerid][IsPlayerBleeding] == 0) { pInfo[playerid][pBlood] -= random(4000), KillTimer(pInfo[playerid][Bleeding]), RemovePlayerAttachedObject(playerid, 2),pInfo[playerid][Bleeding] = SetTimerEx("LoosingBlood",25000,true,"i",playerid),pInfo[playerid][IsPlayerBleeding] = 1; } // Loosing blood ever 25 seconds!
						case 13: pInfo[playerid][pBlood] -= random(4000);
					}
				}
			}
		}
		else
		{
			switch(random(14))
			{
				case 0: pInfo[playerid][pBlood] -= random(4000);
				case 1: if(pInfo[playerid][IsPlayerBleeding] == 0) { pInfo[playerid][pBlood] -= random(4000), KillTimer(pInfo[playerid][Bleeding]), RemovePlayerAttachedObject(playerid, 2),pInfo[playerid][Bleeding] = SetTimerEx("LoosingBlood",2500,true,"i",playerid),pInfo[playerid][IsPlayerBleeding] = 1; } // Loosing blood ever 2.5 seconds!
				case 2: pInfo[playerid][pBlood] -= random(4000);
				case 3: if(pInfo[playerid][IsPlayerBleeding] == 0) { pInfo[playerid][pBlood] -= random(4000), KillTimer(pInfo[playerid][Bleeding]), RemovePlayerAttachedObject(playerid, 2),pInfo[playerid][Bleeding] = SetTimerEx("LoosingBlood",1000,true,"i",playerid),pInfo[playerid][IsPlayerBleeding] = 1; } // Loosing blood ever 1 second!
				case 4: pInfo[playerid][pBlood] -= random(4000);
				case 5: pInfo[playerid][pBlood] -= random(4000);
				case 6: if(pInfo[playerid][IsPlayerBleeding] == 0) { pInfo[playerid][pBlood] -= random(4000), KillTimer(pInfo[playerid][Bleeding]), RemovePlayerAttachedObject(playerid, 2),pInfo[playerid][Bleeding] = SetTimerEx("LoosingBlood",5000,true,"i",playerid),pInfo[playerid][IsPlayerBleeding] = 1; } // Loosing blood ever 5 seconds!
				case 7: pInfo[playerid][pBlood] -= random(4000);
				case 8: if(pInfo[playerid][IsPlayerBleeding] == 0) { pInfo[playerid][pBlood] -= random(4000), KillTimer(pInfo[playerid][Bleeding]), RemovePlayerAttachedObject(playerid, 2),pInfo[playerid][Bleeding] = SetTimerEx("LoosingBlood",10000,true,"i",playerid),pInfo[playerid][IsPlayerBleeding] = 1; } // Loosing blood ever 10 seconds!
				case 9: pInfo[playerid][pBlood] -= random(4000);
				case 10: if(pInfo[playerid][IsPlayerBleeding] == 0) { pInfo[playerid][pBlood] -= random(4000), KillTimer(pInfo[playerid][Bleeding]), RemovePlayerAttachedObject(playerid, 2),pInfo[playerid][Bleeding] = SetTimerEx("LoosingBlood",5500,true,"i",playerid),pInfo[playerid][IsPlayerBleeding] = 1; } // Loosing blood ever 5.5 seconds!
				case 11: pInfo[playerid][pBlood] -= random(4000);
				case 12: if(pInfo[playerid][IsPlayerBleeding] == 0) { pInfo[playerid][pBlood] -= random(4000), KillTimer(pInfo[playerid][Bleeding]), RemovePlayerAttachedObject(playerid, 2),pInfo[playerid][Bleeding] = SetTimerEx("LoosingBlood",25000,true,"i",playerid),pInfo[playerid][IsPlayerBleeding] = 1; } // Loosing blood ever 25 seconds!
				case 13: pInfo[playerid][pBlood] -= random(4000);
			}
		}
	}
}
	return 1;
}

public OnPlayerGiveDamage(playerid, damagedid, Float: amount, WEAPON:weaponid, bodypart)
{
	if(IsPlayerNPC(playerid) || damagedid == INVALID_PLAYER_ID || IsPlayerNPC(damagedid)) return 1;
	if(!IsPlayerConnected(damagedid) || GodMode[damagedid] || pInfo[damagedid][pIsSpawned] != 1 || isPlayerInMenu[damagedid]) return 1;
	if(22 <= _:weaponid <= 38 && !PlayerWeapons[playerid][_:weaponid]) return ReportSuspect(playerid, "damage with a weapon the server never gave"), 1;
	{
		new Float:vx, Float:vy, Float:vz;
		GetPlayerPos(damagedid, vx, vy, vz);
		if(GetPlayerDistanceFromPoint(playerid, vx, vy, vz) > GetWeaponMaxRange(_:weaponid) * 1.3) return ReportSuspect(playerid, "damage beyond the weapon range"), 1;
	}

	if(timerdamage1[playerid] != 0) KillTimer(timerdamage1[playerid]);

	hit1[playerid]++;
	damage1[playerid] += amount;

	timerdamage1[playerid] = SetTimerEx("DamageReset1", 3000, false, "i", playerid);

	PlayerTextDrawShow(playerid, IndicatorBox1[playerid]);
	PlayerTextDrawShow(playerid, Indicator1[playerid]);

	new str[50];
	format(str,sizeof(str)," DAMAGE: %d hit(s) %.0f dmg", hit1[playerid], damage1[playerid]);
	PlayerTextDrawSetString(playerid, Indicator1[playerid], str);


    if(damagedid != INVALID_PLAYER_ID)
	{
	    if(weaponid != 0)
		{
			if(weaponid == 25)
			{
				pInfo[damagedid][pBlood] -= 4500;
				pInfo[damagedid][pTemp] -= 5.0;
			}

			if(weaponid == 30)
			{
				pInfo[damagedid][pBlood] -= 2722;
				pInfo[damagedid][pTemp] -= 6.0;
			}

			if(weaponid == 31)
			{
				pInfo[damagedid][pBlood] -= 3555;
				pInfo[damagedid][pTemp] -= 6.0;
			}

			if(weaponid == 34)
			{
				pInfo[damagedid][pBlood] -= 8000;
				pInfo[damagedid][pTemp] -= 11.0;
			}

			if(weaponid == 33)
			{
				pInfo[damagedid][pBlood] -= 4500;
				pInfo[damagedid][pTemp] -= 7.0;
			}

			if(weaponid == 22)
			{
    			if(pInfo[playerid][pPremium] >= 3)
			    {
                    pInfo[damagedid][pBlood] -= 889;
				}
				else if(pInfo[playerid][pPremium] == 0)
				{
					pInfo[damagedid][pBlood] -= 1500;
				}
				pInfo[damagedid][pTemp] -= 3.0;
			}

			if(weaponid == 27)
			{
				pInfo[damagedid][pBlood] -= 4500;
                pInfo[damagedid][pTemp] -= 3.0;
			}

			if(weaponid == 29)
			{
				pInfo[damagedid][pBlood] -= 889;
				pInfo[damagedid][pTemp] -= 2.0;
			}

			if(weaponid == 5)
			{
				pInfo[damagedid][pBlood] -= 560;
				pInfo[damagedid][pTemp] -= 5.0;
			}

			if(weaponid == 8)
			{
			    if(pInfo[playerid][pPremium] >= 3)
			    {
                    pInfo[damagedid][pBlood] -= 1650;
				}
				else if(pInfo[playerid][pPremium] == 0)
				{
					pInfo[damagedid][pBlood] -= 800;
				}
				pInfo[damagedid][pTemp] -= 8.0;
			}

			if(weaponid == 23)
			{
				pInfo[damagedid][pBlood] -= 1500;
				pInfo[damagedid][pTemp] -= 6.0;
			}
			if(IsPlayerConnected(playerid)) PlayerPlaySound(playerid, 17802, 0.0, 0.0, 0.0);
		}
	}
	return 1;
}

forward GetUp(playerid);
public GetUp(playerid)
{
    ApplyAnimation(playerid, "PED", "getup", 4.0, false, true, true, false, 0, 1);
}

public OnPlayerRequestClass(playerid, classid)
{
    if(IsPlayerNPC(playerid)) {
        return 1;
    }
    TogglePlayerSpectating(playerid,true);
	SetPlayerPos_Allow(playerid, 2372.0027,2243.0608,10.8203);
	SetPlayerFacingAngle(playerid,119.5071);
	SetPlayerCameraPos(playerid, 2365.5837,2238.2991,12.9480);
	SetPlayerCameraLookAt(playerid, 2372.0027,2243.0608,10.8203);
	return 1;
}
public OnPlayerRequestSpawn(playerid)
{
    if(IsPlayerNPC(playerid))
    {
        return 1;
	}
	return 1;
}
forward DamageReset(playerid);
public DamageReset(playerid)
{
    hit[playerid] = 0;
    damage2[playerid] = 0;
    PlayerTextDrawHide(playerid, IndicatorBox[playerid]);
    PlayerTextDrawHide(playerid, Indicator[playerid]);
    KillTimer(timerdamage[playerid]);
    return 1;
}
forward DamageReset1(playerid);
public DamageReset1(playerid)
{
    hit1[playerid] = 0;
    damage1[playerid] = 0;
    PlayerTextDrawHide(playerid, IndicatorBox1[playerid]);
    PlayerTextDrawHide(playerid, Indicator1[playerid]);
    KillTimer(timerdamage1[playerid]);
    return 1;
}
forward OnNPCSpawn();
public OnNPCSpawn()
{
	print("NPC spawned");
	return 1;
}
public OnPlayerAirbreak(playerid)
{
	if(abAllow[playerid] == 0)
	{
	    if(!IsPlayerNPC(playerid))
	    {
			abWarn[playerid]++;
			new strab[250];
			format(strab, sizeof(strab), ""chat""COL_RED" *** WARNING: Player %s(%i) might be airbraking please spectate him! /spec %i", PlayerName(playerid), playerid, playerid);
			SendMessageToAllAdmins(strab, -1);
		}
	}
    return 1;
}

public OnPlayerWeaponShot(playerid, WEAPON:weaponid, BULLET_HIT_TYPE:hittype, hitid, Float:fX, Float:fY, Float:fZ)
{
	if(!CheckShot(playerid, _:weaponid, hittype, hitid)) return 0;
	if(!IsPlayerNPC(playerid))
	{
		new Float:sx, Float:sy, Float:sz;
		GetPlayerPos(playerid, sx, sy, sz);
		AlertZombies(sx, sy, sz, weaponid == WEAPON_SILENCED ? 15.0 : 90.0);
	}
	if(hittype != BULLET_HIT_TYPE_NONE)
  	{
		if(!(-200.0 <= fX <= 200.0 ) || !(-200.0 <= fY <= 200.0) || !(-200.0 <= fZ <= 200.0))
   		{
			return 0;
    	}
  	}

   	if( hittype != BULLET_HIT_TYPE_NONE )
	{
        if( !( -1000.0 <= fX <= 1000.0 ) || !( -1000.0 <= fY <= 1000.0 ) || !( -1000.0 <= fZ <= 1000.0 ) )
		{
		    new str[128];
			format(str, sizeof(str), "** "COL_RED"Possible Bullet Crasher: %s(%i) PLEASE /spec %i",PlayerName(playerid), playerid, playerid);
			SendMessageToAllAdmins(str, -1);
			return 0;
		}
	}
	return 1;
}
public OnPlayerWeaponEmpty(playerid, WEAPON:weaponid)
{
	new wepname[64];
	new Float:fPos[3];
	GetPlayerPos(playerid,fPos[0],fPos[1],fPos[2]);
	switch(GetPlayerWeapon(playerid))
	{
	    case 25: wepname = "Shotgun", SendClientMessage(playerid, -1, ""chat" You ran out ammo! Your weapon has been dropped"), DayZSA_CreateLootsFunction("Shotgun",fPos[0],fPos[1],fPos[2]);
	    case 30: wepname = "AK-47", SendClientMessage(playerid, -1, ""chat" You ran out ammo! Your weapon has been dropped"), DayZSA_CreateLootsFunction("AK-47",fPos[0],fPos[1],fPos[2]);
	    case 31: wepname = "M4", SendClientMessage(playerid, -1, ""chat" You ran out ammo! Your weapon has been dropped"), DayZSA_CreateLootsFunction("M4",fPos[0],fPos[1],fPos[2]);
	    case 34: wepname = "Sniper Rifle", SendClientMessage(playerid, -1, ""chat" You ran out ammo! Your weapon has been dropped"), DayZSA_CreateLootsFunction("Sniper Rifle",fPos[0],fPos[1],fPos[2]);
	    case 33: wepname = "Country Rifle", SendClientMessage(playerid, -1, ""chat" You ran out ammo! Your weapon has been dropped"), DayZSA_CreateLootsFunction("Country Rifle",fPos[0],fPos[1],fPos[2]);
	    case 22: wepname = "Pistol", SendClientMessage(playerid, -1, ""chat" You ran out ammo! Your weapon has been dropped"), DayZSA_CreateLootsFunction("Pistol",fPos[0],fPos[1],fPos[2]);
	    case 27: wepname = "SPAZ-12 Shotgun", SendClientMessage(playerid, -1, ""chat" You ran out ammo! Your weapon has been dropped"), DayZSA_CreateLootsFunction("SPAZ-12 Shotgun",fPos[0],fPos[1],fPos[2]);
	    case 29: wepname = "MP5", SendClientMessage(playerid, -1, ""chat" You ran out ammo! Your weapon has been dropped"), DayZSA_CreateLootsFunction("MP5",fPos[0],fPos[1],fPos[2]);
	    case 23: wepname = "Silenced Pistol", SendClientMessage(playerid, -1, ""chat" You ran out ammo! Your weapon has been dropped"), DayZSA_CreateLootsFunction("Silenced Pistol",fPos[0],fPos[1],fPos[2]);
	    case 43: wepname = "Binoculars", SendClientMessage(playerid, -1, ""chat" You ran out ammo! Your weapon has been dropped"), DayZSA_CreateLootsFunction("Binoculars",fPos[0],fPos[1],fPos[2]);
	}
	return 1;
}

public OnPlayerResume(playerid, time)
{
    new str[48];
    format(str, sizeof(str), ""chat" You've been paused for %d milliseconds.", time);
    return SendClientMessage(playerid, -1, str);
}

