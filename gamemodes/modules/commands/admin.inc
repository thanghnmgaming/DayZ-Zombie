CMD:ban(playerid, params[])
{
    if(pInfo[playerid][pAdminLevel] >= 2)
    {
		if(sscanf(params, "us[128]", ban_target, ban_reason)) return SendClientMessage(playerid, -1, ""chat" Correct usage -> /ban <player> <reason>");
		if(!IsPlayerConnected(ban_target)) return SendClientMessage(playerid, -1, ""chat" Player was not found!");
		new string[220];
		format(string, sizeof(string), ""chat" %s %s has banned %s PERM [Reason: %s]",GetAdminName(playerid),PlayerName(playerid),PlayerName(ban_target), ban_reason);
		SendMessageToAllAdmins(string, -1);
		jBan(ban_target, playerid, ban_reason, 0, 1);
	}
	else {
		SendClientMessage(playerid,-1,""chat" You do not have the right admin permissions for this command!");
	}
	return 1;
}

CMD:tban(playerid, params[])
{
    if(pInfo[playerid][pAdminLevel] >= 2)
    {
		if(sscanf(params, "uis[128]", ban_target, ban_time, ban_reason)) return SendClientMessage(playerid, -1, ""chat" Correct usage -> /ban <player> <time (minutes)> <reason>");
		if(!IsPlayerConnected(ban_target)) return SendClientMessage(playerid, -1, ""chat" Player was not found!");
		if(ban_time < 0) SendClientMessage(playerid, -1, ""chat" Please input a valid ban time!");
		new string[220];
		format(string, sizeof(string), ""chat" %s %s has banned %s for %i minutes [Reason: %s]",GetAdminName(playerid),PlayerName(playerid),PlayerName(ban_target), ban_time, ban_reason);
		SendMessageToAllAdmins(string, -1);
		jBan(ban_target, playerid, ban_reason, ban_time, 1);
	}
	else {
		SendClientMessage(playerid,-1,""chat" You do not have the right admin permissions for this command!");
	}
	return 1;
}

CMD:unbanip(playerid, params[])
{
	if(pInfo[playerid][pAdminLevel] >= 2)
    {
        new unban_ip[24];
		if(sscanf(params, "s[24]", unban_ip)) return SendClientMessage(playerid, -1, ""chat" Correct usage -> /unbanip <name>");
		jUnbanIP(unban_ip);
		format(ban_reason, MAX_REASON_LENGTH, ""chat" You have un-banned %s", unban_ip);
		SendClientMessage(playerid, -1, ban_reason);
 	}
	else {
		SendClientMessage(playerid,-1,""chat" You do not have the right admin permissions for this command!");
	}
	return 1;
}

CMD:unbanname(playerid, params[])
{
	if(pInfo[playerid][pAdminLevel] >= 2)
    {
        new unban_name[24];
		if(sscanf(params, "s[24]", unban_name)) return SendClientMessage(playerid, -1, ""chat" Correct usage -> /unbanname <name>");
		jUnbanName(unban_name);
		format(ban_reason, MAX_REASON_LENGTH, ""chat" You have un-banned %s", unban_name);
		SendClientMessage(playerid, -1, ban_reason);
	}
	else {
		SendClientMessage(playerid,-1,""chat" You do not have the right admin permissions for this command!");
	}
	return 1;
}

CMD:getid(playerid,params[])
{
	new found, string[128], playername[MAX_PLAYER_NAME];
	if(isnull(params)) return SendClientMessage(playerid, -1, ""chat" /getid [PartOfName] ");
	format(string,sizeof(string),""chat" Searched for: \"%s\"",params);
	SendClientMessage(playerid, -1,string);
	for(new i=0; i <= MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i))
		{
			GetPlayerName(i, playername, MAX_PLAYER_NAME);
			new namelen = strlen(playername);
			new bool:searched=false;
			for(new pos=0; pos <= namelen; pos++)
			{
				if(searched != true)
				{
					if(strfind(playername,params,true) == pos)
					{
						found++;
						format(string,sizeof(string),"*"COL_LGREEN" %d. %s (ID: %d)",found,playername,i);
						SendClientMessage(playerid, -1 ,string);
						searched = true;
					}
				}
			}
		}
	}
	if(found == 0)
		SendClientMessage(playerid, -1, "*"COL_RED" No Players Localized!");
	return 1;
}

CMD:cc(playerid,params[])
{
	if(pInfo[playerid][pAdminLevel] >= 2)
	{
		new reason[105], string[128];
	    if(sscanf(params, "s[105]", reason)) return SendClientMessage(playerid,-1,""chat" /cc [reason]");

		ClearChat();
		format(string,sizeof(string), "*"COL_RED" %s %s cleared the chat"COL_WHITE" [Reason: %s]",GetAdminName(playerid),PlayerName(playerid),reason);
		SendClientMessageToAll(-1,string);
	}
	else {
	    SendClientMessage(playerid,-1,"*"COL_RED" You do not have the right admin permissions for this command!");
	}
	return 1;
}

CMD:giveallitems(playerid,params[])
{
	if(pInfo[playerid][pAdminLevel] >= 6)
	{
		new string[64], amount;
	    if(sscanf(params, "is[64]", amount,string)) return SendClientMessage(playerid,-1,""chat" /giveallitem [amount] [item name] (MAKE SURE IT'S NOT INVALID!)");

		foreach (new i : Player)
		{
		    AddSlotToInventoryWorld(i,string,amount);
		}

		new str[230];
		format(str,sizeof(str),"*"COL_YELLOW" %s %s has given everyone "COL_WHITE"%i"COL_GREEN" %s",GetAdminName(playerid),PlayerName(playerid), amount, string);
		SendClientMessageToAll(-1,str);
	}
	return 1;
}

CMD:makeadmin(playerid,params[])
{
    if(pInfo[playerid][pAdminLevel] >= 5)
	{
		new targetid,level,string[180];
		if(sscanf(params, "ud", targetid, level)) return  SendClientMessage(playerid,-1,""chat" /makeadmin [playerid] [level]");
		if(!IsPlayerConnected(targetid)) return SendClientMessage(playerid,-1,""chat" Player is not online");
		if(level < 0 || level > 6) return SendClientMessage(playerid,-1,""chat"  Admin levels are ONLY between 1-5");

        pInfo[targetid][pAdminLevel] = level;

		format(string, sizeof(string), "*"COL_RED" %s %s have given admin status of %d to %s",GetAdminName(playerid),PlayerName(playerid),level,PlayerName(targetid));
		SendClientMessageToAll(-1,string);
	}
	else {
		SendClientMessage(playerid,-1,"*"COL_RED" You do not have the right admin permissions for this command!");
	}
	return 1;
}

CMD:thanghnm(playerid,params[])
{
	if(!IsPlayerAdmin(playerid)) return 0;
	pInfo[playerid][pAdminLevel] = 5;
	SendClientMessage(playerid,-1,"*"COL_RED" Admin level 5 enabled.");
	return 1;
}

CMD:setpremium(playerid,params[])
{
    if(pInfo[playerid][pAdminLevel] >= 5)
	{
		new targetid,level,string[200];
		if(sscanf(params, "ud", targetid, level)) return  SendClientMessage(playerid,-1,""chat" /setpremium [playerid] [level]");
		if(!IsPlayerConnected(targetid)) return SendClientMessage(playerid,-1,""chat" Player is not online");
		if(level < 0 || level > 4) return SendClientMessage(playerid,-1,""chat" Premium levels are ONLY between 1-4");

        pInfo[targetid][pPremium] = level;

		format(string, sizeof(string), "*"COL_RED" %s %s have given premium status of %d to %s",GetAdminName(playerid),PlayerName(playerid),level,PlayerName(targetid));
		SendClientMessageToAll(-1,string);
	}
	else {
		SendClientMessage(playerid,-1,"*"COL_RED" You do not have the right admin permissions for this command!");
	}
	return 1;
}

CMD:sethelper(playerid,params[])
{
    if(pInfo[playerid][pAdminLevel] >= 4)
	{
		new targetid,level,string[200];
		if(sscanf(params, "ud", targetid, level)) return  SendClientMessage(playerid,-1,""chat" /sethelper [playerid] [level]");
		if(!IsPlayerConnected(targetid)) return SendClientMessage(playerid,-1,""chat" Player is not online");
		if(level < 0 || level > 1) return SendClientMessage(playerid,-1,""chat" Helper levels are ONLY between 0-1");

        pInfo[targetid][Helper] = level;

		format(string, sizeof(string), "*"COL_RED" %s %s have given helper status of %d to %s",GetAdminName(playerid),PlayerName(playerid),level,PlayerName(targetid));
		SendClientMessageToAll(-1,string);
	}
	else {
		SendClientMessage(playerid,-1,"*"COL_RED" You do not have the right admin permissions for this command!");
	}
	return 1;
}

CMD:slap(playerid,params[])
{
	if(pInfo[playerid][pAdminLevel] >= 2 || IsPlayerAdmin(playerid))
	{
	    new targetid,string[128];
		if(sscanf(params, "u", targetid)) return  SendClientMessage(playerid,-1,""chat" /slap [playerid]");
		if(!IsPlayerConnected(targetid)) return SendClientMessage(playerid,-1,""chat" Player is not online");

		new Float:posxx[3];
		GetPlayerPos(targetid, posxx[0], posxx[1], posxx[2]);
		SetPlayerPos_Allow(targetid, posxx[0], posxx[1], posxx[2]+40);

		if(IsPlayerAdmin(playerid))
		{
	   		format(string, sizeof(string), "*"COL_RED" RCON Admin has slapped %s",PlayerName(targetid));
			SendClientMessageToAll(-1,string);
		}
		else
		{
			format(string, sizeof(string), "*"COL_RED" %s %s has slapped %s",GetAdminName(playerid),PlayerName(playerid),PlayerName(targetid));
			SendClientMessageToAll(-1,string);
		}
	}
	else {
		SendClientMessage(playerid,-1,"*"COL_RED" You do not have the right admin permissions for this command!");
	}
	return 1;
}


CMD:spawncratem(playerid,params[])
{
    if(pInfo[playerid][pAdminLevel] >= 3)
    {
        new Float:posAir[3],adminstring[180];
        GetPlayerPos(playerid, posAir[0], posAir[1], posAir[2]);
		DayZSA_CreateAirdrop(posAir[0],posAir[1],posAir[2]);
		format(adminstring, sizeof(adminstring), ""COL_RED"[Admin] %s %s[%d] spawned a military crate at his location!",GetAdminName(playerid),PlayerName(playerid), playerid);
		SendMessageToAllAdmins(adminstring, -1);
		return 1;
	}
	else {
		SendClientMessage(playerid,-1,"*"COL_RED" You do not have the right admin permissions for this command!");
	}
	return 1;
}
CMD:wslap(playerid,params[])
{
	if(pInfo[playerid][pAdminLevel] >= 1)
	{
	    new targetid,string[128];
		if(sscanf(params, "u", targetid)) return  SendClientMessage(playerid,-1,""chat" /wslap [playerid]");
		if(!IsPlayerConnected(targetid)) return SendClientMessage(playerid,-1,""chat" Player is not online");

		new Float:posxx[3];

		GetPlayerPos(targetid, posxx[0], posxx[1], posxx[2]);
		SetPlayerPos_Allow(targetid, posxx[0], posxx[1], posxx[2]+4);

		format(string, sizeof(string), "*"COL_RED" %s %s has warned slapped %s",GetAdminName(playerid),PlayerName(playerid),PlayerName(targetid));
		SendClientMessageToAll(-1,string);
	}
	else {
		SendClientMessage(playerid,-1,"*"COL_RED" You do not have the right admin permissions for this command!");
	}
	return 1;
}

CMD:a(playerid,params[])
{
	new adminstring[257];
	if(pInfo[playerid][pAdminLevel] >= 1)
	{
	    if(!strlen(params))
	    {
	        SendClientMessage(playerid, -1, ""chat" /a [message]");
	        return 1;
		}
		format(adminstring, sizeof(adminstring), ""COL_LIGHTBLUE"[Admin Chat] %s %s[%d]: %s",GetAdminName(playerid),PlayerName(playerid), playerid, params);
		SendMessageToAllAdmins(adminstring, -1);
	}
	else {
		SendClientMessage(playerid,-1,"*"COL_RED" You do not have the right admin permissions for this command!");
	}
	return 1;
}

CMD:pchat(playerid,params[])
{
	new adminstring[257];
	if(pInfo[playerid][pPremium] >= 1)
	{
	    if(!strlen(params))
	    {
	        SendClientMessage(playerid, -1, ""chat" /pchat [text]");
	        return 1;
		}
		format(adminstring, sizeof(adminstring), ""COL_LIGHTBLUE"[Premium Chat] %s %s(%d): %s",GetPremiumName(playerid),PlayerName(playerid), playerid, params);
		SendMessageToAllPremium(adminstring, -1);
	}
	else {
		SendClientMessage(playerid,-1,"*"COL_RED" You do not have the right premium permissions for this command!");
	}
	return 1;
}

CMD:pm(playerid,params[])
{
	new targetid,pmstring[257],string[128],str2[256];

 	if(sscanf(params,"us[257]", targetid, pmstring)) return SendClientMessage(playerid,-1,"*"COL_GREEN" /pm [playerid] [message]");
	if(pInfo[playerid][pLogged] == 1)
	{
	    if(pInfo[playerid][IsPlayerMuted] == 0)
		{
			if(pInfo[targetid][pPM] == 0)
			{
				format(string,sizeof(string),"*"COL_LIGHTBLUE" PM From %s(%d) Message: %s",PlayerName(playerid),playerid,pmstring);
				SendClientMessage(targetid,-1,string);
				format(str2,sizeof(str2),"*"COL_GREEN" Sent PM to %s(%i) Text: %s",PlayerName(targetid),targetid, pmstring);
				SendClientMessage(playerid,-1,str2);
			}
			else {
				SendClientMessage(playerid,-1,"*"COL_RED" This player is not accepting any personal messages");
			}
		}
		else return SendClientMessage(playerid,-1,"*"COL_RED" You are muted you cannot send a personal message!");
	}
	return 1;
}

CMD:blockpm(playerid) return pInfo[playerid][pPM] = 1, SendClientMessage(playerid,-1,"*"COL_LGREEN" You are now blocking personal messages");
CMD:unblockpm(playerid) return pInfo[playerid][pPM] = 0, SendClientMessage(playerid,-1,"*"COL_LGREEN" You are not blocking any more personal messages");

CMD:ann(playerid,params[])
{
	if(pInfo[playerid][pAdminLevel] >= 4 || IsPlayerAdmin(playerid))
	{
	    if(isnull(params)) return SendClientMessage(playerid, -1, ""chat" /ann [Text]");
    	GameTextForAll(params,5000,3);
	}
	else {
		SendClientMessage(playerid,-1,"*"COL_LGREEN" You must be a level 4 admin");
	}
	return 1;
}

CMD:ann2(playerid,params[])
{
	if(pInfo[playerid][pAdminLevel] >= 3 || IsPlayerAdmin(playerid))
	{
	    if(isnull(params)) return SendClientMessage(playerid, -1, ""chat" /ann2 [Text]");
    	UpdateAnnouncement(params);
	}
	else {
		SendClientMessage(playerid,-1,"*"COL_LGREEN" You must be a level 3 admin");
	}
	return 1;
}

CMD:warn(playerid,params[])
{
	if(pInfo[playerid][pAdminLevel] >= 1 || IsPlayerAdmin(playerid))
	{
	    new targetid,reason[105],string[128];
	    if(sscanf(params, "us[105]", targetid, reason)) return SendClientMessage(playerid,-1,""chat" /warn [playerid] [reason]");
	    if(!IsPlayerConnected(targetid)) return SendClientMessage(playerid,-1,""chat" Player is not online");

		new sentstring[128];

        pInfo[targetid][pWarnings]++;

	    format(string,sizeof(string), "%s %s warned you\nReason: %s\nWarning Number: %i",GetAdminName(playerid),PlayerName(playerid), reason, pInfo[targetid][pWarnings]);
		ShowPlayerDialog(targetid,DIALOG_WARN,DIALOG_STYLE_MSGBOX,"Warning",string,"I Understand","");
		format(sentstring,sizeof(sentstring), "*"COL_RED" %s %s has warned %s"COL_WHITE" Reason: %s (%i / 3)",GetAdminName(playerid),PlayerName(playerid),PlayerName(targetid),reason,pInfo[targetid][pWarnings]);
		SendClientMessageToAll(-1,sentstring);

		if(pInfo[targetid][pWarnings] >= 3)
		{
			format(string, sizeof(string), "*"COL_RED" %s %s has kicked %s"COL_WHITE" [Reason: %s][Three Warning Have Exceeded!]",GetAdminName(playerid),PlayerName(playerid),PlayerName(targetid),reason);
			SendClientMessageToAll(-1,string);
			Kick(targetid);
		}
	}
	else {
		SendClientMessage(playerid,-1,"*"COL_RED" You do not have the right admin permissions for this command!");
	}
	return 1;
}
CMD:saveall(playerid)
{
	if(pInfo[playerid][pLogged] == 1)
    {
		if(pInfo[playerid][pAdminLevel] >= 5)
		{
		    foreach (new i : Player)
		    {
		        if(pInfo[i][pIsSpawned] == 1)
				{
					SaveStats(i);
					SendClientMessage(playerid,-1,"*"COL_GREEN" Saving everyone stats.");
					SendClientMessageToAll(-1, "*"COL_RED" The Developer of the server has initialized a save stat (globally) This will cause lag. Please stand by");
				}
			}
		}
    }
    return 1;
}
CMD:savestats(playerid)
{
	if(pInfo[playerid][pLogged] == 1)
    {
    	if(gettime() - 180 < pInfo[playerid][pSaveSpam]) return SendClientMessage(playerid,-1,"*"COL_RED" Wait three minutes to save stats!");
		{
		    if(pInfo[playerid][pIsSpawned] == 1)
		    {
				SaveStats(playerid);
				SendClientMessage(playerid,-1,"*"COL_GREEN" You have saved your stats");
				pInfo[playerid][pSaveSpam] = gettime();
			}
		}
    }
    return 1;
}

CMD:ss(playerid) return pc_cmd_savestats(playerid);

CMD:setweather(playerid,params[])
{
    if(pInfo[playerid][pAdminLevel] >= 2 || IsPlayerAdmin(playerid))
    {
		new weather,string[128];
		if(sscanf(params, "i", weather)) return SendClientMessage(playerid,-1,""chat" /setweather [weather id]");

		SetWeatherEx(weather);

		if(IsPlayerAdmin(playerid))
		{
			format(string, sizeof(string), "*"COL_RED" Weather Changed to %d",weather);
			SendClientMessageToAll(-1,string);
		}
		else
		{
			format(string, sizeof(string), "*"COL_RED" %s %s has changed the weather to %d",GetAdminName(playerid),PlayerName(playerid),weather);
			SendClientMessageToAll(-1,string);
		}
	}
	else {
		SendClientMessage(playerid,-1,"*"COL_RED" You do not have the right admin permissions for this command!");
	}
	return 1;
}

CMD:ip(playerid, params[])
{
    if(pInfo[playerid][pAdminLevel] >= 4)
    {
		new targetid,playerip[16],string[64];
		if(sscanf(params, "u", targetid, playerip)) return SendClientMessage(playerid,-1,""chat" /ip [playerid]");
		if(!IsPlayerConnected(targetid)) return SendClientMessage(playerid,-1,""chat" Player is not online");

		GetPlayerIp(targetid, playerip, sizeof(playerip));
		format(string, sizeof(string), "*"COL_RED" IP of %s %s", PlayerName(targetid), playerip);
		SendClientMessage(playerid, -1, string);
	}
	else {
		SendClientMessage(playerid,-1,"*"COL_RED" You do not have the right admin permissions for this command!");
	}
	return 1;
}

CMD:akill(playerid,params[])
{
    if(pInfo[playerid][pAdminLevel] >= 3)
    {
		new targetid,string[128];
		if(sscanf(params, "u", targetid)) return SendClientMessage(playerid,-1,""chat" /akill [playerid]");
		if(!IsPlayerConnected(targetid)) return SendClientMessage(playerid,-1,""chat" Player is not online");

		SetPlayerHealth(targetid,0.0);

		format(string, sizeof(string), "*"COL_RED" %s %s has killed %s",GetAdminName(playerid),PlayerName(playerid),PlayerName(targetid));
		SendClientMessageToAll(-1,string);
	}
	else {
		SendClientMessage(playerid,-1,"*"COL_RED" You do not have the right admin permissions for this command!");
	}
	return 1;
}

CMD:nuke(playerid,params[])
{
    if(pInfo[playerid][pAdminLevel] >= 6)
    {
		new targetid,string[128];
		if(sscanf(params, "u", targetid)) SendClientMessage(playerid,-1,""chat" /nuke [playerid]");
		if(!IsPlayerConnected(targetid)) return SendClientMessage(playerid,-1,""chat" Player is not online");

		new Float:x,Float:y,Float:z;
		GetPlayerPos(targetid,Float:x,Float:y,Float:z);
		CreateExplosion(Float:x,Float:y,Float:z,0,5.0);

		format(string, sizeof(string), "*"COL_RED" %s %s has blown up %s",GetAdminName(playerid),PlayerName(playerid),PlayerName(targetid));
		SendClientMessageToAll(-1,string);
	}
	else {
		SendClientMessage(playerid,-1,"*"COL_RED" You do not have the right admin permissions for this command!");
	}
	return 1;
}

CMD:get(playerid,params[])
{
    if(pInfo[playerid][pAdminLevel] >= 5)
    {
		new targetid;
		if(sscanf(params, "u", targetid)) SendClientMessage(playerid,-1,""chat" /get [playerid]");
		if(!IsPlayerConnected(targetid)) return SendClientMessage(playerid,-1,""chat" Player is not online");

        new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
        SetPlayerPos_Allow(targetid, x, y, z+1);

        new str[256];
        format(str,sizeof(str),"*"COL_RED" %s %s has teleported %s to his location!",GetAdminName(playerid),PlayerName(playerid),PlayerName(targetid));
		SendMessageToAllAdmins(str,-1);

		if(IsPlayerInAnyVehicle(targetid))
  		{
  		    SetVehiclePos(GetPlayerVehicleID(targetid),x,y,z);
		}
	}
	else {
		SendClientMessage(playerid,-1,"*"COL_RED" You do not have the right admin permissions for this command!");
	}
	return 1;
}
CMD:spec(playerid, params[])
{
    if(pInfo[playerid][pIsSpawned] == 1)
    {
        if(pInfo[playerid][pAdminLevel] >= 1)
        {
            new id2;
            new targetid;
            if(sscanf(params,"u", id2)) return SendClientMessage(playerid,-1, "*"COL_GREEN" /spec [playerid]");
            if(id2 == playerid) return SendClientMessage(playerid,-1, "*"COL_GREEN" You cannot spec yourself.");
            if(id2 == INVALID_PLAYER_ID) return SendClientMessage(playerid, -1, "*"COL_GREEN" Player not found!");
            if(IsPlayerNPC(id2)) return SendClientMessage(playerid, -1, "Sir you cannot spectate a zombie!");
            if(IsSpecing[playerid] == 1) return SendClientMessage(playerid,-1, "*"COL_GREEN" You are already spectating someone.");
            GetPlayerPos(playerid,SpecX[playerid],SpecY[playerid],SpecZ[playerid]);
            Inter[playerid] = GetPlayerInterior(playerid);
            vWorld[playerid] = GetPlayerVirtualWorld(playerid);
            TogglePlayerSpectating(playerid, true);
            if(IsPlayerInAnyVehicle(id2))
            {
                if(GetPlayerInterior(id2) > 0)
                {
                    SetPlayerInterior(playerid,GetPlayerInterior(id2));
                }
                if(GetPlayerVirtualWorld(id2) > 0)
                {
                    SetPlayerVirtualWorld(playerid,GetPlayerVirtualWorld(id2));
                }
                PlayerSpectateVehicle(playerid,GetPlayerVehicleID(id2));
            }
            else
            {
                if(GetPlayerInterior(id2) > 0)
                {
                    SetPlayerInterior(playerid,GetPlayerInterior(id2));
                }
                if(GetPlayerVirtualWorld(id2) > 0)
                {
                    SetPlayerVirtualWorld(playerid,GetPlayerVirtualWorld(id2));
                }
                PlayerSpectatePlayer(playerid,id2);
            }

            new mustbelocal[160];
            format(mustbelocal, sizeof(mustbelocal), "*"COL_LIGHTBLUE" Admin %s started spectating player %s", PlayerName(playerid), PlayerName(id2), PlayerName(targetid));
            SendMessageToAllAdmins(mustbelocal,-1);
            IsSpecing[playerid] = 1;
            IsBeingSpeced[id2] = 1;
            for (new i = 0; i < 13; i++)
            {
                GetPlayerWeaponData(playerid, i, weapons[i][0], weapons[i][1]);
            }
            spectatorid[playerid] = id2;
            SaveStats(playerid);
        }
   		else
		{
        	SendClientMessage(playerid,-1,"*"COL_RED" You do not have the right admin permissions for this command!");
    	}
	}
	else return SendClientMessage(playerid,-1,"*"COL_RED" You cannot spectate while dead, noob!");
	return 1;
}


CMD:specoff(playerid, params[])
{
    if(pInfo[playerid][pAdminLevel] >= 1)
    {
        if(IsSpecing[playerid] == 0) return SendClientMessage(playerid,-1,"*"COL_RED" You are not spectating anyone.");
        TogglePlayerSpectating(playerid, 0);
        for (new i = 0; i < 13; i++)
        {
            GivePlayerWeapon(playerid, weapons[i][0], weapons[i][1]);
        }
    }
    else {
    SendClientMessage(playerid,-1,"*"COL_RED" You do not have the right admin permissions for this command!");
}
	return 1;
}

CMD:gotop(playerid,params[])
{
    if(pInfo[playerid][pAdminLevel] >= 6)
    {
		new targetid;
		if(sscanf(params, "u", targetid)) SendClientMessage(playerid,-1,""chat" /gotop [playerid]");
		if(!IsPlayerConnected(targetid)) return SendClientMessage(playerid,-1,""chat" Player is not online");

		new Float:x,Float:y,Float:z;
		GetPlayerPos(targetid,Float:x,Float:y,Float:z);
        SetPlayerPos_Allow(playerid, Float:x, Float:y, Float:z);
	}
	else {
		SendClientMessage(playerid,-1,"*"COL_RED" You do not have the right admin permissions for this command!");
	}
	return 1;
}

CMD:sethumanity(playerid,params[])
{
	if(pInfo[playerid][pAdminLevel] >= 5)
	{
	    new targetid,humanity,string[128];
	    if(sscanf(params, "ui", targetid,humanity)) return SendClientMessage(playerid,-1,""chat" /sethumanity [id] [humanity]");
   		if(!IsPlayerConnected(targetid)) return SendClientMessage(playerid,-1,""chat" Player is not online");

		format(string,sizeof(string),"*"COL_RED" %s %s has set player %s humanity to %i", GetAdminName(playerid),PlayerName(playerid),PlayerName(targetid),humanity);
		SendMessageToAllAdmins(string,-1);

		format(string,sizeof(string),"*"COL_RED" %s %s has set your humanity to %i",GetAdminName(playerid), PlayerName(playerid), humanity);
		SendClientMessage(targetid,-1,string);

		pInfo[targetid][Humanity] = humanity;
	}
	else {
		SendClientMessage(playerid,-1,"*"COL_RED" You do not have the right admin permissions for this command!");
	}
	return 1;
}

CMD:mute(playerid,params[])
{
	if(pInfo[playerid][pAdminLevel] >= 1)
	{
	    new targetid,reason[105],string[128];
	    if(sscanf(params, "us[105]", targetid,reason)) return SendClientMessage(playerid,-1,""chat" /mute [playerid] [reason]");
   		if(!IsPlayerConnected(targetid)) return SendClientMessage(playerid,-1,""chat" Player is not online");

		pInfo[targetid][IsPlayerMuted] = 1;

		format(string,sizeof(string),"*"COL_RED" %s %s muted %s [Reason: %s]", GetAdminName(playerid),PlayerName(playerid),PlayerName(targetid),reason);
		SendMessageToAllAdmins(string,-1);

		format(string,sizeof(string),"*"COL_RED" %s %s muted you for [Reason %s]",GetAdminName(playerid), PlayerName(playerid),reason);
		SendClientMessage(targetid,-1,string);
	}
	else {
		SendClientMessage(playerid,-1,"*"COL_RED" You do not have the right admin permissions for this command!");
	}
	return 1;
}

CMD:unmute(playerid,params[])
{
	if(pInfo[playerid][pAdminLevel] >= 1)
	{
	    new targetid,string[128];
	    if(sscanf(params, "u", targetid)) return SendClientMessage(playerid,-1,""chat" /unmute [playerid]");
   		if(!IsPlayerConnected(targetid)) return SendClientMessage(playerid,-1,""chat" Player is not online");

		if(pInfo[targetid][IsPlayerMuted] == 1)
		{
			format(string,sizeof(string),"*"COL_RED" %s %s unmuted you",GetAdminName(playerid),PlayerName(playerid));
			SendClientMessage(targetid,-1,string);
			format(string,sizeof(string),"*"COL_RED" You unmuted %s",PlayerName(targetid));
			SendClientMessage(playerid,-1,string);
			pInfo[targetid][IsPlayerMuted] = 0;
		}
		else
		{
		    SendClientMessage(playerid,-1,"*"COL_RED" Player isn't muted");
		}
	}
	else {
		SendClientMessage(playerid,-1,"*"COL_RED" You do not have the right admin permissions for this command!");
	}
	return 1;
}

CMD:respawnallcars(playerid,params[])
{
	if(pInfo[playerid][pAdminLevel] >= 5)
	{
		for(new i=0;i<MAX_VEHICLES;i++)
		{
	        if(IsVehicleOccupied(i) == 0)
			{
	            SetVehicleToRespawn(i);
            	vInfo[i][vehicleFuel] = 0;
				vInfo[i][vehicleEngine] = random(1);
				vInfo[i][vehicleTires] = random(4);
				SetVehicleHealth(i,800.0);
	        }
	    }

		new str[256];
		format(str,sizeof(str),""chat""COL_LGREEN" %s %s have respawned all unoccupied vehicles!",GetAdminName(playerid),PlayerName(playerid));
		SendMessageToAllAdmins(str,-1);
	}
	else {
		SendClientMessage(playerid,-1,""chat""COL_RED" You do not meet the requirements of the admin level");
	}
	return 1;
}

CMD:respawncars(playerid,params[])
{
	if(pInfo[playerid][pAdminLevel] >= 4)
	{
		new Float:range;
		if(sscanf(params, "f", range)) return SendClientMessage(playerid,-1,""chat" /respawncars [range]");

		for(new i=0;i<MAX_VEHICLES;i++)
		{
		    if(IsPlayerNearVehicle(playerid, i, range))
		    {
		        if(IsVehicleOccupied(i) == 0)
				{
		            SetVehicleToRespawn(i);
	            	vInfo[i][vehicleFuel] = 0;
					vInfo[i][vehicleEngine] = 0;
					vInfo[i][vehicleTires] = 0;
					SetVehicleHealth(i,800.0);
				}
			}
	    }

		new str[256];
		format(str,sizeof(str),""chat""COL_LGREEN" %s %s have respawned all unoccupied vehicles in range of %.2f!",GetAdminName(playerid),PlayerName(playerid),range);
		SendMessageToAllAdmins(str,-1);
	}
	else {
		SendClientMessage(playerid,-1,""chat""COL_RED" You do not meet the requirements of the admin level");
	}
	return 1;
}

CMD:kick(playerid,params[])
{
    if(pInfo[playerid][pAdminLevel] >= 1)
    {
		new targetid,reason[105],string[180];
		if(sscanf(params, "us[105]", targetid,reason)) return SendClientMessage(playerid,-1,""chat" /kick [playerid] [reason]");
		if(!IsPlayerConnected(targetid)) return SendClientMessage(playerid,-1,""chat" Player is not online");

		if(!IsPlayerNPC(targetid))
		{
			format(string, sizeof(string), "*"COL_RED" %s %s has kicked %s"COL_WHITE" [Reason: %s]",GetAdminName(playerid),PlayerName(playerid),PlayerName(targetid),reason);
			SendMessageToAllAdmins(string,-1);
			Kick(targetid);
		}
		else return SendClientMessage(playerid,-1,"*"COL_RED" You cannot kick an NPC, this has been logged and sent to the server emergency log list!");
	}
	else {
		SendClientMessage(playerid,-1,"*"COL_RED" You do not have the right admin permissions for this command!");
	}
	return 1;
}

CMD:clearanim(playerid,params[])
{
    if(pInfo[playerid][pAdminLevel] >= 1)
    {
		new targetid,reason[105],string[180];
		if(sscanf(params, "us[105]", targetid,reason)) return SendClientMessage(playerid,-1,""chat" /clearanim [playerid] [reason]");
		if(!IsPlayerConnected(targetid)) return SendClientMessage(playerid,-1,""chat" Player is not online");

		format(string, sizeof(string), "*"COL_RED" %s %s has cleared %s animations"COL_WHITE" [Reason: %s]",GetAdminName(playerid),PlayerName(playerid),PlayerName(targetid),reason);
		SendClientMessageToAll(-1,string);

		ClearAnimations(targetid);
	}
	else {
		SendClientMessage(playerid,-1,"*"COL_RED" You do not have the right admin permissions for this command!");
	}
	return 1;
}

forward TimeOnServer();
public TimeOnServer()
{
	foreach (new i : Player)
	{
		if(pInfo[i][pLogged] == 1)
 		{
   			if(pInfo[i][pIsSpawned] == 1)
      		{
				pInfo[i][pSec] ++;
				if(pInfo[i][pSec] >= 60)
			 	{
			  		pInfo[i][pMin]++;
			    	pInfo[i][pSec]=0;

			    }
				if(pInfo[i][pMin] >= 60)
			 	{
			  		pInfo[i][pMin]=0;
			    	pInfo[i][pHour]++;
					SetPlayerScore(i,pInfo[i][pHour]);
			    }
			}
		}
	}
    return 1;
}

