public OnPlayerConnect(playerid)
{
   	if(IsPlayerNPC(playerid)) {
        return 1;
	}
    if(!IsPlayerNPC(playerid))
	{
/*		if(playerid <= 99)
		{
		    SendClientMessage(playerid, -1, ""COL_RED" CONNECTION ERROR OCCURED CONNECTING TO DayZ Link to pGA PLEASE RECONNECT!");
		    Kick(playerid);
		}
		else
		{*/
  		PlayerLabel[playerid] = CreateDynamic3DTextLabel("" , 0xADFF2FAA, 0.0, 0.0, 0.2, 15.0, playerid, INVALID_VEHICLE_ID, 1, -1, -1, -1, 100.0);
   		PlayersAlive++;
   		CreatePlayerTD(playerid);
   		ConnectVars(playerid);
    	ClearChatPlayer(playerid);
    	ResetVars(playerid);
    	CheckVersion(playerid);
		SetPlayerTeam(playerid, 0);
   	}
	return 1;
}

public WhenAccountCheck(playerid, serial)
{
    if(serial != LoginSerial[playerid]) return 1;
    new rows;
    cache_get_row_count(rows);

 	if(rows)
	{
		gRegistred[playerid] = 1;
  	}
  	else
  	{
  	    gRegistred[playerid] = 0;
	}

  	if(pInfo[playerid][pLogged] == 0)
	{
	    if(gRegistred[playerid] == 1)
	    {
			if(rows)
			{
			    new string[256];

	         	format(string,sizeof(string),"{BECBFC}Welcome, {95A3FF}%s{BECBFC}!\nPlease enter your password below to login to your account.",PlayerName(playerid));
				ShowPlayerDialog(playerid, DIALOG_LOGIN ,DIALOG_STYLE_PASSWORD,"DayZ Account Login",string,"Login","Exit");
   			}
     	}
     	else
     	{
     	    ShowPlayerDialog(playerid, DIALOG_REGISTER, DIALOG_STYLE_PASSWORD, "DayZ Register", "DayZ Account Registration\nEnter your password below:", "Register", "Cancel");
   		}
	}

    SetPlayerCameraPos(playerid, 1500.7156,-1778.1880,80.3080);
	SetPlayerCameraLookAt(playerid, 1500.7156,-1778.1880,80.3080);
	SetPlayerPos_Allow(playerid, 1437.6957,-2266.6355,13.5469);
	return 1;
}

public OnPlayerRegister(playerid, password[])
{
	if(IsPlayerConnected(playerid))
	{
		bcrypt_hash(playerid, "OnRegisterHashed", password, BCRYPT_COST, "i", LoginSerial[playerid]);
	}
	return 1;
}

forward OnRegisterHashed(playerid, serial);
public OnRegisterHashed(playerid, serial)
{
	if(!IsPlayerConnected(playerid) || serial != LoginSerial[playerid]) return 1;
	new query[256], hash[BCRYPT_HASH_LENGTH], ip[16];
	bcrypt_get_hash(hash);
	GetPlayerIp(playerid, ip, sizeof(ip));
	mysql_format(handle, query, sizeof(query), "INSERT INTO `users` (Username,Password,IP) VALUES ('%e','%e','%e')", PlayerName(playerid), hash, ip);
	mysql_tquery(handle, query);
	gRegistred[playerid] = 1;
	pInfo[playerid][pFirstSpawn] = 1;
	pInfo[playerid][pHunger] = 2500;
	pInfo[playerid][pThrist] = 1000;
	pInfo[playerid][pBlood] = 12000;
	pInfo[playerid][Humanity] = 2500;
	pInfo[playerid][Backpack] = 0;
	pInfo[playerid][BackpackSlots] = 8;
	pInfo[playerid][BackpackSlotsUsed] = 0;
	ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "DayZ Login", "Please enter your password below to login to your account.", "Login", "Exit");
	return 1;
}

public OnPlayerAccountLogin(playerid, enteredPassword[])
{
	if(!IsPlayerConnected(playerid) || IsPlayerNPC(playerid)) return 1;
	new query[320];
	mysql_format(handle, query, sizeof(query), "SELECT `Password`, `Password` = SHA1('%e') AS `LegacyMatch` FROM `users` WHERE `Username` = '%e' LIMIT 1", enteredPassword, PlayerName(playerid));
	mysql_tquery(handle, query, "OnPasswordRow", "iis", playerid, LoginSerial[playerid], enteredPassword);
	return 1;
}

forward OnPasswordRow(playerid, serial, password[]);
public OnPasswordRow(playerid, serial, password[])
{
	if(!IsPlayerConnected(playerid) || serial != LoginSerial[playerid]) return 1;
	new rows;
	cache_get_row_count(rows);
	if(!rows) return ShowWrongPassword(playerid);

	new stored[129], legacy[4];
	cache_get_value_name(0, "Password", stored);
	if(stored[0] == '$')
	{
		bcrypt_verify(playerid, "OnPasswordVerified", password, stored, "i", serial);
		return 1;
	}
	// Old SHA1 account: accept it once, then store a bcrypt hash instead
	cache_get_value_name(0, "LegacyMatch", legacy);
	if(strval(legacy) != 1) return ShowWrongPassword(playerid);
	bcrypt_hash(playerid, "OnPasswordUpgraded", password, BCRYPT_COST, "i", serial);
	return 1;
}

forward OnPasswordUpgraded(playerid, serial);
public OnPasswordUpgraded(playerid, serial)
{
	if(!IsPlayerConnected(playerid) || serial != LoginSerial[playerid]) return 1;
	new query[256], hash[BCRYPT_HASH_LENGTH];
	bcrypt_get_hash(hash);
	mysql_format(handle, query, sizeof(query), "UPDATE `users` SET `Password` = '%e' WHERE `Username` = '%e'", hash, PlayerName(playerid));
	mysql_tquery(handle, query);
	LoadAccount(playerid);
	return 1;
}

forward OnPasswordVerified(playerid, bool:success, serial);
public OnPasswordVerified(playerid, bool:success, serial)
{
	if(!IsPlayerConnected(playerid) || serial != LoginSerial[playerid]) return 1;
	if(!success) return ShowWrongPassword(playerid);
	LoadAccount(playerid);
	return 1;
}

stock ShowWrongPassword(playerid)
{
	if(++LoginFails[playerid] >= MAX_LOGIN_ATTEMPTS)
	{
		SendClientMessage(playerid, -1, "*"COL_RED" Too many wrong passwords.");
		return KickEx(playerid);
	}
	ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "DayZ Login", "The passwords don't match!\nType your account's password below:", "Login", "Exit");
	return 1;
}

stock LoadAccount(playerid)
{
	new query[128];
	mysql_format(handle, query, sizeof(query), "SELECT * FROM `users` WHERE `Username` = '%e' LIMIT 1", PlayerName(playerid));
	mysql_tquery(handle, query, "WhenPlayerLogin", "ii", playerid, LoginSerial[playerid]);
	return 1;
}
public WhenPlayerLogin(playerid, serial)
{
    if(IsPlayerConnected(playerid) && serial == LoginSerial[playerid] && pInfo[playerid][pLogged] == 0)
	{
	    pInfo[playerid][pHunger] = 2500;
	 	pInfo[playerid][pThrist] = 1000;
	 	pInfo[playerid][pBlood] = 12000;
	 	pInfo[playerid][Humanity] = 2500;

	    new rows;
	    new tmp[128];

	    cache_get_row_count(rows);

		if(rows != 0)
		{
		    cache_get_value_name(0, "Password", tmp),  format(pInfo[playerid][Password], 128, tmp);
		    cache_get_value_name(0, "Headshots", tmp), pInfo[playerid][Headshots] = strval(tmp);
           	cache_get_value_name(0, "Murders", tmp), pInfo[playerid][Murders] = strval(tmp);
	        cache_get_value_name(0, "BanditsKilled", tmp), pInfo[playerid][BanditsKilled] = strval(tmp);
	        cache_get_value_name(0, "ZombiesKilled", tmp), pInfo[playerid][ZombiesKilled] = strval(tmp);
		    cache_get_value_name(0, "Backpack", tmp), pInfo[playerid][Backpack] = strval(tmp);
           	cache_get_value_name(0, "BackpackSlots", tmp), pInfo[playerid][BackpackSlots] = strval(tmp);
	        cache_get_value_name(0, "BackpackSlotsUsed", tmp), pInfo[playerid][BackpackSlotsUsed] = strval(tmp);
	        cache_get_value_name(0, "pAdminLevel", tmp), pInfo[playerid][pAdminLevel] = strval(tmp);
	        cache_get_value_name(0, "pPremium", tmp), pInfo[playerid][pPremium] = strval(tmp);
	        cache_get_value_name_float(0, "pX", pInfo[playerid][pX]);
	        cache_get_value_name_float(0, "pY", pInfo[playerid][pY]);
	        cache_get_value_name_float(0, "pZ", pInfo[playerid][pZ]);
	        cache_get_value_name(0, "pWeap1", tmp), pInfo[playerid][pWeap1] = strval(tmp);
	        cache_get_value_name(0, "pAmmo1", tmp), pInfo[playerid][pAmmo1] = strval(tmp);
	        cache_get_value_name(0, "pWeap2", tmp), pInfo[playerid][pWeap2] = strval(tmp);
	        cache_get_value_name(0, "pAmmo2", tmp), pInfo[playerid][pAmmo2] = strval(tmp);
	        cache_get_value_name(0, "pWeap3", tmp), pInfo[playerid][pWeap3] = strval(tmp);
	        cache_get_value_name(0, "pAmmo3", tmp), pInfo[playerid][pAmmo3] = strval(tmp);
	        cache_get_value_name(0, "pWeap4", tmp), pInfo[playerid][pWeap4] = strval(tmp);
	        cache_get_value_name(0, "pAmmo4", tmp), pInfo[playerid][pAmmo4] = strval(tmp);
	        cache_get_value_name(0, "pWeap5", tmp), pInfo[playerid][pWeap5] = strval(tmp);
	        cache_get_value_name(0, "pAmmo5", tmp), pInfo[playerid][pAmmo5] = strval(tmp);
	        cache_get_value_name(0, "pWeap6", tmp), pInfo[playerid][pWeap6] = strval(tmp);
	        cache_get_value_name(0, "pAmmo6", tmp), pInfo[playerid][pAmmo6] = strval(tmp);
	        cache_get_value_name(0, "pWeap7", tmp), pInfo[playerid][pWeap7] = strval(tmp);
	        cache_get_value_name(0, "pAmmo7", tmp), pInfo[playerid][pAmmo7] = strval(tmp);
	        cache_get_value_name(0, "pWeap8", tmp), pInfo[playerid][pWeap8] = strval(tmp);
	        cache_get_value_name(0, "pAmmo8", tmp), pInfo[playerid][pAmmo8] = strval(tmp);
	        cache_get_value_name(0, "pWeap9", tmp), pInfo[playerid][pWeap9] = strval(tmp);
	        cache_get_value_name(0, "pAmmo9", tmp), pInfo[playerid][pAmmo9] = strval(tmp);
			cache_get_value_name(0, "pHour", tmp), pInfo[playerid][pHour] = strval(tmp);
	        cache_get_value_name(0, "pMin", tmp), pInfo[playerid][pMin] = strval(tmp);
	        cache_get_value_name(0, "pSec", tmp), pInfo[playerid][pSec] = strval(tmp);
	        cache_get_value_name(0, "pBlood", tmp), pInfo[playerid][pBlood] = strval(tmp);
	        cache_get_value_name(0, "pThrist", tmp), pInfo[playerid][pThrist] = strval(tmp);
	        cache_get_value_name(0, "pHunger", tmp), pInfo[playerid][pHunger] = strval(tmp);
	        cache_get_value_name(0, "Humanity", tmp), pInfo[playerid][Humanity] = strval(tmp);
	        cache_get_value_name(0, "pFirstSpawn", tmp), pInfo[playerid][pFirstSpawn] = strval(tmp);
	        cache_get_value_name(0, "pAliveTime", tmp), pInfo[playerid][pAliveTime] = strval(tmp);
	        cache_get_value_name(0, "pIsMapOpened", tmp), pInfo[playerid][pIsMapOpened] = strval(tmp);
	        cache_get_value_name(0, "pSkin", tmp), pInfo[playerid][pSkin] = strval(tmp);
	        cache_get_value_name(0, "Helper", tmp), pInfo[playerid][Helper] = strval(tmp);
	        cache_get_value_name(0, "IsPlayerBleeding", tmp), pInfo[playerid][IsPlayerBleeding] = strval(tmp);
	        cache_get_value_name(0, "IsPlayerLegBroken", tmp), pInfo[playerid][IsPlayerLegBroken] = strval(tmp);
	        cache_get_value_name(0, "pAmbientEnable", tmp), pInfo[playerid][pAmbientEnable] = strval(tmp);
	        cache_get_value_name(0, "DefaultGender", tmp), pInfo[playerid][DefaultGender] = strval(tmp);
	        cache_get_value_name(0, "ID", tmp), pInfo[playerid][pUserID] = strval(tmp);

		}
		else
		{
			ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "DayZ Login", "The passwords don't match!\nType your account's password below:", "Login", "Exit");
	        return 1;
		}

		if(pInfo[playerid][pAmbientEnable] == 0)
		{
		    pInfo[playerid][pAmbientEnable] = 1;
		    SendClientMessage(playerid, -1, ""chat" The ambient has been enabled, you can change this by default in the GAME OPTIONS menu!");
		}

		printf("%s has logged in.", PlayerName(playerid));

		if(pInfo[playerid][pFirstSpawn] == 0)
		{
		    pInfo[playerid][pFirstSpawn] = 1;
		}

	    pInfo[playerid][pLogged] = 1;
	    ClearChatPlayer(playerid);

		LoadInventory(playerid);
		SetPlayerScore(playerid,pInfo[playerid][pHour]);
		DayZSA_ShowMenuForPlayer(playerid);
	}

	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
	LoginSerial[playerid]++;

	if(!IsPlayerNPC(playerid))
	{
	    if(pInfo[playerid][pLogged] == 1) { SaveStats(playerid); }
        DestroyDynamic3DTextLabel(PlayerLabel[playerid]);
 		PlayersAlive--;

 		/*if(pInfo[playerid][IsPlayerBleeding] == 1)
 		{
 		    jBan(playerid, -1, "Bleeding (Ban 5 Minutes)", 5);
 		}*/

		DisconnectVars(playerid);
		ResetVars(playerid);
        DeletePlayerTD(playerid);

  		new log[128];
	    format(log,sizeof(log),"~w~%s~b~ has disconnected",PlayerName(playerid));
	    UpdateAnnouncement(log);

		new str[256];
	  	switch(reason)
	    {
	        case 0: format(str,sizeof(str),"*"COL_GREEN" Player %s(%i) has left the server Reason: Timed Out",PlayerName(playerid),playerid);
	        case 1: format(str,sizeof(str),"*"COL_GREEN" Player %s(%i) has left the server Reason: Leaving",PlayerName(playerid),playerid);
	        case 2: format(str,sizeof(str),"*"COL_GREEN" Player %s(%i) has left the server Reason: Kicked/Banned",PlayerName(playerid),playerid);
	    }
		SendMessageToAllAdmins(str,-1);

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
    }

	return 1;
}
public OnPlayerRapidFire(playerid, WEAPON:weaponid, intervals)
{
    if(OPRF_Processed[playerid] == true) return 0;
    new
    string[128],
    Lname[MAX_PLAYER_NAME];
    GetPlayerName(playerid, Lname, sizeof(Lname));
    format(string, sizeof(string), "AntiCheat : %s (ID:%d) is suspicious , please look! (Reason : Rapid Fire with weapon ID %d in %d milli seconds)", Lname, playerid, weaponid, intervals);
    SendMessageToAllAdmins(string, -1);
    OPRF_Processed[playerid] = true;
	return 0;
}
public OnPlayerEnterCheckpoint(playerid)
{
    return 1;
}

