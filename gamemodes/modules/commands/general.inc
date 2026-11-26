CMD:flashoff(playerid)
{
	if(PlayerHasItem(playerid, "Flashlight"))
	{
		if(IsPlayerAttachedObjectSlotUsed(playerid,3)) RemovePlayerAttachedObject(playerid,3);
		if(IsPlayerAttachedObjectSlotUsed(playerid,4)) RemovePlayerAttachedObject(playerid,4);
	}
	else return SendClientMessage(playerid, -1, "*"COL_RED" You do not have a flashlight in your inventory");
	return 1;
}

CMD:resetinv(playerid,params[])
{
    if(pInfo[playerid][pAdminLevel] >= 5)
    {
		new targetid,string[128];
		if(sscanf(params, "u", targetid)) return SendClientMessage(playerid,-1,""chat" /resetinv [playerid]");
		if(!IsPlayerConnected(targetid)) return SendClientMessage(playerid,-1,""chat" Player is not online");

		if(!IsPlayerNPC(targetid))
		{
			format(string, sizeof(string), "*"COL_RED" %s %s has reset %s"COL_WHITE" 's Inventory",GetAdminName(playerid),PlayerName(playerid),PlayerName(targetid));
		//	print("string passed");
			SendMessageToAllAdmins(string,-1);
		//	print("message passed");
			ResetPlayerWeapons(targetid);
		//	print("resetwepaons passed");
			ResetPlayerInventory(targetid);
		//	print("reset inv passed");
			AddSlotToInventoryWorld(targetid,"Bandage",1);
		//	print("bandage passed");
		//	print("info passed");
			SendClientMessage(targetid,-1,"*"COL_RED" Your inventory has been reset!");
		//	print("message passed");
		}
		else return SendClientMessage(playerid,-1,"*"COL_RED" You cannot do this to an NPC, this has been logged and sent to the server emergency log list!");
	}
	else {
		SendClientMessage(playerid,-1,"*"COL_RED" You do not have the right admin permissions for this command!");
	}
	return 1;
}


CMD:setscore(playerid, params[])
{
    if(pInfo[playerid][pAdminLevel] >= 5 || IsPlayerAdmin(playerid))
    {
        new string[128], pName[MAX_PLAYER_NAME], name[MAX_PLAYER_NAME], targetid, score;
        if(sscanf(params, "ud", targetid, score)) return SendClientMessage(playerid, -1, " /setscore [playerid] [score]");
        if(targetid == INVALID_PLAYER_ID) return SendClientMessage(playerid, -1, "player is not connected");
        GetPlayerName(playerid, name, sizeof(name));
        GetPlayerName(targetid, pName, sizeof(pName));
        pInfo[targetid][pHour] = score;
        format(string, 128, "%s %s has set your score to %i",GetAdminName(playerid),PlayerName(playerid),score);
        SendClientMessage(targetid, -1, string);
        new str[256];
        format(str, sizeof(str), "*"COL_WHITE"* %s %s has set %s score to %i",GetAdminName(playerid),PlayerName(playerid),PlayerName(targetid),score);
        SendMessageToAllAdmins(str,-1);
        SetPlayerScore(targetid, score);
	}
    return 1;
}

CMD:weaps(playerid, params[])
{
    if(pInfo[playerid][pAdminLevel] >= 1 || IsPlayerAdmin(playerid))
    {
        new count = 0;
        new ammo, weaponid, weapon[24], string[128], id;
        if(!sscanf(params, "u", id))
        {
                for (new c = 0; c < 13; c++)
                {
                    GetPlayerWeaponData(id, c, weaponid, ammo);
                    if (weaponid != 0 && ammo != 0)
                    {
                        count++;
                    }
                }
                SendClientMessage(playerid,-1,"*"COL_ORANGE" ||=============WEAPONS AND AMMO===========||");
                if(count > 0)
                {
                    for (new c = 0; c < 13; c++)
                    {
                        GetPlayerWeaponData(id, c, weaponid, ammo);
                        if (weaponid != 0 && ammo != 0)
                        {
                            GetWeaponName(weaponid, weapon, 24);
                            format(string, sizeof(string), "Weapon: %s  Ammo: %d", weapon, ammo);
                            SendClientMessage(playerid,0x37DB45, string);
                        }
                    }
                }
                else
                {
                    SendClientMessage(playerid,-1,"*"COL_GREY" This player has no weapons!");
                }
                return 1;
        }
        else return SendClientMessage(playerid,-1,"*"COL_WHITE" USAGE: /weaps [ID]");
    }
    else return SendClientMessage(playerid,-1,"*"COL_RED" You do not have the right admin permissions for this command");
}

CMD:h(playerid,params[])
{
    new helperstring[257];
	if(pInfo[playerid][Helper] >= 1)
	{
	    if(!strlen(params))
	    {
	        SendClientMessage(playerid, -1, ""chat" /h [message]");
	        return 1;
		}
		format(helperstring, sizeof(helperstring), ""COL_ORANGE"[Helper Chat] %s %s[%d]: %s",GetHelperName(playerid),PlayerName(playerid), playerid, params);
		SendMessageToAllHelpers(helperstring, -1);
	}
	else {
		SendClientMessage(playerid,-1,"*"COL_RED" You do not have the right helper permissions for this command!");
	}
	return 1;
}


CMD:groupinfo(playerid,params[])
{
	new groupid;
	if(sscanf(params, "i", groupid)) return SendClientMessage(playerid,-1,"*"COL_RED" /groupinfo [groupid]");

	new str[480];
	format(str,sizeof(str),""COL_WHITE"Viewing group:"COL_GREEN" %s\n"COL_WHITE"Group ID: %i\nGroup Members: %i\nGroup Owner: %s",
	Groups[groupid][GroupName],Groups[groupid][GroupID],Groups[groupid][GroupMembers],Groups[groupid][GroupOwner]);
	ShowPlayerDialog(playerid,5472,DIALOG_STYLE_MSGBOX,"DayZ - Viewing Group Info",str,"Close",""); //it's edited here
	return 1;
}

CMD:makegroup(playerid,params[])
{
	new groupnamecmd[16];
	if(sscanf(params, "s[16]", groupnamecmd)) return SendClientMessage(playerid,-1,"*"COL_RED" /makegroup [group name] [16 Characters]");

	if(gettime() - 480 < pInfo[playerid][pGroupSpam]) return SendClientMessage(playerid,-1,"*"COL_RED" Wait eight minutes to create an group again!");
	{
		if(pInfo[playerid][pHour] >= 2)
		{
		    if(pInfo[playerid][IsPlayerInGroup] == 0)
		    {
				if(strlen(params) > 16)
				{
					SendClientMessage(playerid,-1,"*"COL_RED" Group name is to long (MAX CHARACTERS 16)");
				}
				else
				{
					DayZSA_CreateGroup(playerid,groupnamecmd,PlayerName(playerid));
					pInfo[playerid][pGroupSpam] = gettime();
				}
			}
			else return SendClientMessage(playerid,-1,"*"COL_RED" You are already in a group/made one!");
		}
		else return SendClientMessage(playerid,-1,"*"COL_RED" You need +2 hours played!");
	}
	return 1;
}

CMD:invitegroup(playerid,params[])
{
	new targetid;
	if(sscanf(params, "u", targetid)) return SendClientMessage(playerid,-1,"*"COL_RED" /invitegroup [playerid]");

	if(pInfo[targetid][IsPlayerInGroup] == 0)
	{
		if(pInfo[playerid][IsPlayerInGroup] == 1)
		{
		    if(pInfo[playerid][IsPlayerGroupOwner] == 1)
		    {
				new str[256],str2[128];
				format(str,sizeof(str),"*"COL_YELLOW" %s(%i) has invited you to group %s(%i) /acceptgroup, to join the group to deny /denygroup!",PlayerName(playerid),playerid,GetPlayerGroupName(playerid),pInfo[playerid][IsPlayerInGroupID]);
				SendClientMessage(targetid,-1,str);
				format(str2,sizeof(str2),"*"COL_YELLOW" You have sent an invite to %s(%i) to join your group!",PlayerName(targetid),targetid);
				SendClientMessage(playerid,-1,str2);
				pInfo[targetid][IsPlayerInvitedGroupID] = pInfo[playerid][IsPlayerInGroupID];
				pInfo[targetid][IsPlayerInvited] = 1;
			}
			else return SendClientMessage(playerid,-1,"*"COL_RED" You must be the group owner to use this command!");
		}
		else return SendClientMessage(playerid,-1,"*"COL_RED" You must be in a group to use this command!");
	}
	else return SendClientMessage(playerid,-1,"*"COL_RED" The player you are trying to invite is already in a group.");
	return 1;
}

CMD:acceptgroup(playerid)
{
	if(pInfo[playerid][IsPlayerInvited] == 1)
	{
		new str[230];
		pInfo[playerid][IsPlayerInvited] = 0;
		pInfo[playerid][IsPlayerInGroup] = 1;
		pInfo[playerid][IsPlayerInGroupID] = pInfo[playerid][IsPlayerInvitedGroupID];
		pInfo[playerid][IsPlayerInvitedGroupID] = 0;
		Groups[pInfo[playerid][IsPlayerInGroupID]][GroupMembers]++;

		format(str,sizeof(str),"*"COL_YELLOW" Player %s(%i) has joined the group %s(%i)",PlayerName(playerid), playerid, Groups[pInfo[playerid][IsPlayerInGroupID]][GroupName], pInfo[playerid][IsPlayerInGroupID]);
		SendMessageToAllGroups(Groups[pInfo[playerid][IsPlayerInGroupID]][GroupID], str, -1);
	}
	else return SendClientMessage(playerid,-1,"*"COL_RED" You have not been invited to join any groups!");
	return 1;
}


CMD:denygroup(playerid)
{
	if(pInfo[playerid][IsPlayerInvited] == 1)
	{
		pInfo[playerid][IsPlayerInvited] = 0;
		pInfo[playerid][IsPlayerInGroup] = -1;
		pInfo[playerid][IsPlayerInvitedGroupID] = 0;
		SendClientMessage(playerid,-1,"*"COL_YELLOW" You denied to join the group!");
	}
	else return SendClientMessage(playerid,-1,"*"COL_RED" You have not been invited to join any groups!");
	return 1;
}

CMD:version(playerid,params[])
{
	new targetid;
	if(sscanf(params, "u", targetid)) return SendClientMessage(playerid,-1,"*"COL_RED" /version [playerid]");

 	new string[128];
    GetPlayerVersion(targetid, string, sizeof(string));
    format(string, sizeof(string), "*"COL_RED"Player %s SA-MP version"COL_WHITE" %s",PlayerName(targetid),string);
    SendClientMessage(playerid, -1, string);
	return 1;
}

CMD:kickgroup(playerid,params[])
{
	new targetid;
	if(sscanf(params, "u", targetid)) return SendClientMessage(playerid,-1,"*"COL_RED" /kickgroup [playerid]");

	if(pInfo[playerid][IsPlayerInGroup] == 1)
	{
	    if(pInfo[playerid][IsPlayerGroupOwner] == 1)
	    {
			if(pInfo[targetid][IsPlayerInGroupID] == pInfo[playerid][IsPlayerInGroupID])
			{
				new str[180],str2[128];
				format(str,sizeof(str),"*"COL_RED" You were kicked from group %s(%i)",GetPlayerGroupName(targetid),pInfo[targetid][IsPlayerInGroupID]);
				SendClientMessage(targetid,-1,str);
				format(str2,sizeof(str2),"*"COL_RED" You have kicked %s(%i) from your group!",PlayerName(targetid),targetid);
				SendClientMessage(playerid,-1,str2);
			    Groups[pInfo[targetid][IsPlayerInGroupID]][GroupMembers]--;

			    pInfo[targetid][IsPlayerInGroup] = 0;
			    pInfo[targetid][IsPlayerInGroupID] = 0;
			}
			else return SendClientMessage(playerid,-1,"*"COL_RED" That player is not in your group!");
		}
		else return SendClientMessage(playerid,-1,"*"COL_RED" You must be the group owner to use this command!");
	}
	else return SendClientMessage(playerid,-1,"*"COL_RED" You must be in a group to use this command!");
	return 1;
}

CMD:groupfind(playerid,params[])
{
	new targetid;
	if(sscanf(params, "u", targetid)) return SendClientMessage(playerid,-1,"*"COL_RED" /groupfind [playerid]");

	if(pInfo[playerid][IsPlayerInGroup] == 1)
	{
		if(pInfo[targetid][IsPlayerInGroupID] == pInfo[playerid][IsPlayerInGroupID])
		{
			new str[250];
			GetPlayer2DZone(targetid, zonegps, MAX_ZONE_NAME);
			format(stringgps,sizeof(stringgps),"%s", zonegps);
			format(str,sizeof(str),"*"COL_YELLOW" Group member %s(%i) is at %s",PlayerName(targetid),targetid,stringgps);
			SendClientMessage(playerid,-1,str);
		}
		else return SendClientMessage(playerid,-1,"*"COL_RED" The player you are trying to find isn't in your group!");
	}
	else return SendClientMessage(playerid,-1,"*"COL_RED" You must be in a group to use this command!");
	return 1;
}

CMD:leavegroup(playerid)
{
	if(pInfo[playerid][IsPlayerInGroup] == 1)
	{
	    new str[180];
	    format(str,sizeof(str),"*"COL_YELLOW" %s(%i) has left the group!",PlayerName(playerid),playerid);
	    SendMessageToAllGroups(Groups[pInfo[playerid][IsPlayerInGroupID]][GroupID], str, -1);
	    Groups[pInfo[playerid][IsPlayerInGroupID]][GroupMembers]--;
	    pInfo[playerid][IsPlayerInGroup] = 0;
	    pInfo[playerid][IsPlayerInGroupID] = 0;
	}
	else return SendClientMessage(playerid,-1,"*"COL_RED" You must be in a group to use this command!");
	return 1;
}

CMD:destroygroup(playerid,params[])
{
	new reason[105];
	if(sscanf(params, "s[105]", reason)) return SendClientMessage(playerid,-1,"*"COL_RED" /destroygroup [reason]");

	if(pInfo[playerid][IsPlayerInGroup] == 1)
	{
	    if(pInfo[playerid][IsPlayerGroupOwner] == 1)
	    {
			new str[24],gname[16],msg[280];

			format(str,sizeof(str),"Destroyed");
			format(gname,sizeof(gname),"Destroyed");
			format(msg,sizeof(msg),"*"COL_YELLOW" %s(%i) has dis-banded the group %s [Reason: %s]",PlayerName(playerid),playerid, GetPlayerGroupName(playerid), reason);
			SendClientMessageToAll(-1,msg);

			Groups[pInfo[playerid][IsPlayerInGroupID]][GroupOwner] = str;
			Groups[pInfo[playerid][IsPlayerInGroupID]][GroupName] = gname;
			Groups[pInfo[playerid][IsPlayerInGroupID]][GroupMembers] = 0;

			new groupid = pInfo[playerid][IsPlayerInGroupID];
			foreach (new i : Player)
			{
			    if(pInfo[i][IsPlayerInGroup] == 1 && pInfo[i][IsPlayerInGroupID] == groupid)
			    {
    				pInfo[i][IsPlayerInGroup] = 0;
					pInfo[i][IsPlayerInGroupID] = 0;

				}
			}

			pInfo[playerid][IsPlayerInGroup] = 0;
			pInfo[playerid][IsPlayerGroupOwner] = 0;
			pInfo[playerid][IsPlayerInGroupID] = 0;

		}
		else return SendClientMessage(playerid,-1,"*"COL_RED" That player is not in your group!");
	}
	else return SendClientMessage(playerid,-1,"*"COL_RED" You must be the group owner to use this command!");
	return 1;
}

CMD:g(playerid,params[])
{
	new adminstring[280];
	if(pInfo[playerid][IsPlayerInGroup] == 1)
	{
	    if(!strlen(params))
	    {
	        SendClientMessage(playerid, -1, "*"COL_GREEN" /g [message]");
	        return 1;
		}
		format(adminstring, sizeof(adminstring), ""COL_LIGHTBLUE"[Group Chat] %s(%d)"COL_WHITE": %s",PlayerName(playerid), playerid, params);
		SendMessageToAllGroups(Groups[pInfo[playerid][IsPlayerInGroupID]][GroupID], adminstring, -1);
	}
	else {
		SendClientMessage(playerid,-1,"*"COL_RED" You need to be in a group to use this command!");
	}
	return 1;
}

CMD:firstperson(playerid)
{
	if(pInfo[playerid][FirstPerson] == 0)
	{
		firstperson[playerid] = CreateObject(19300, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
		AttachObjectToPlayer(firstperson[playerid],playerid, 0.0, 0.12, 0.7, 0.0, 0.0, 0.0);
		AttachCameraToObject(playerid, firstperson[playerid]);
		pInfo[playerid][FirstPerson] = 1;
		SendClientMessage(playerid,-1,""chat" First person enabled type /firstperson again to disable it!");
	}

	else if(pInfo[playerid][FirstPerson] == 1)
	{
		SetCameraBehindPlayer(playerid);
		DestroyObject(firstperson[playerid]);
		pInfo[playerid][FirstPerson] = 0;
		SendClientMessage(playerid,-1,""chat" First person enabled type /firstperson again to disable it!");
	}
	return 1;
}

CMD:map(playerid)
{
	if(PlayerHasItem(playerid,"Map"))
 	{
		if(pInfo[playerid][pIsMapOpened] == 0)
		{
 			PlayerTextDrawShow(playerid, Map[playerid]);
   			SendClientMessage(playerid,-1,"*"COL_RED" Type /map again to disable it.");
	    	pInfo[playerid][pIsMapOpened] = 1;
		}
		else return pInfo[playerid][pIsMapOpened] = 0,PlayerTextDrawHide(playerid, Map[playerid]);
	}
	return 1;
}

CMD:stopambient(playerid)
{
	StopAudioStreamForPlayer(playerid);
	SendClientMessage(playerid,-1,"*"COL_GREEN" You've stop playing the ambient!");
	return 1;
}

CMD:handsup(playerid)
{
	if(Handup[playerid] == 0)
	{
    	SetPlayerSpecialAction(playerid,SPECIAL_ACTION_HANDSUP);
		Handup[playerid] = 1;
		SendClientMessage(playerid,-1,"*"COL_RED" To disable /handsup!");
	}
	else
	{
	    SetPlayerSpecialAction(playerid,0);
	    ClearAnimations(playerid);
	    Handup[playerid] = 0;
	}
	return 1;
}

CMD:rules(playerid)
{
	new str[600];
	strcat(str,"1. Respect your fellow Players, Administrators, and Moderators.\n2. No offensive language!\n3. Do not use any third party mod!\n\
	4. Do not argue with any staff members!\n5. Do not duplicate loots!\n6. Use common sense. If you are being an ass you will be treated like one.\n7. No Advertising\n");
	strcat(str,"8. Do not abuse or exploit any bugs!\n9. No pausing during playing!\n10. Do not spam or flood the chat\n11. Do not C-Bug or any other SA-MP glitches!");
	ShowPlayerDialog(playerid,2657,DIALOG_STYLE_MSGBOX,"DayZ - Rules",str,"Close","");
	return 1;
}

CMD:stopanim(playerid, params[])
{
	if(GetPVarInt(playerid, "UsingAnim") == 1)
	{
		SendClientMessage(playerid, COLOR_WHITE, ""chat" Your animations were cleared!");
		ClearAnimations(playerid);
		SetPlayerSkin(playerid, GetPlayerSkin(playerid));
		DeletePVar(playerid,"UsingAnim");
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
	}
	else SendClientMessage(playerid, COLOR_WHITE, ""chat" You are currently not using any animation");
	return 1;
}

CMD:sit(playerid, params[])
{
	new choice[32];
	if(sscanf(params, "s[32]", choice))
	{
		SendClientMessage(playerid, -1, ""chat" /sit [1-3]");
		return 1;
	}
	if(strcmp(choice, "1", true) == 0)
	{
		ApplyAnimation(playerid,"INT_OFFICE","OFF_Sit_Type_Loop", 4.0, true, false, false, false, 0);
		SetPVarInt(playerid, "UsingAnim", 1);
		SendClientMessage(playerid, -1, ""chat" To stop the animation type in /stopanim");
	}
	if(strcmp(choice, "2", true) == 0)
	{
		ApplyAnimation(playerid,"BEACH", "ParkSit_M_loop", 4.0, true, false, false, false, 0);
		SetPVarInt(playerid, "UsingAnim", 1);
		SendClientMessage(playerid, -1, ""chat" To stop the animation type in /stopanim");
	}
	if(strcmp(choice, "3", true) == 0)
	{
		ApplyAnimation(playerid,"BEACH", "ParkSit_W_loop", 4.0, true, false, false, false, 0);
		SetPVarInt(playerid, "UsingAnim", 1);
		SendClientMessage(playerid, -1, ""chat" To stop the animation type in /stopanim");
	}
	if(strcmp(choice, "4", true) == 0)
	{
		ApplyAnimation(playerid,"BAR","dnk_stndF_loop", 4.0, true, false, false, false, 0);
		SetPVarInt(playerid, "UsingAnim", 1);
		SendClientMessage(playerid, -1, ""chat" To stop the animation type in /stopanim");
	}
	return 1;
}

CMD:smoke(playerid, params[])
{
	new choice[32];
	if(sscanf(params, "s[32]", choice))
	{
		SendClientMessage(playerid, -1, ""chat" /smoke [1-2]");
		return 1;
	}
	if(strcmp(choice, "1", true) == 0)
	{
		ApplyAnimation(playerid, "SMOKING", "F_smklean_loop", 4.0, true, false, false, false, 0);
		SendClientMessage(playerid, -1, ""chat" To stop the animation type in /stopanim");
		SetPVarInt(playerid, "UsingAnim", 1);
	}
	if(strcmp(choice, "2", true) == 0)
	{
		ApplyAnimation(playerid,"SMOKING", "M_smklean_loop", 4.0, true, false, false, false, 0);
		SendClientMessage(playerid, -1, ""chat" To stop the animation type in /stopanim");
		SetPVarInt(playerid, "UsingAnim", 1);
	}
	return 1;
}

CMD:wave(playerid, params[])
{
	ApplyAnimation(playerid, "ON_LOOKERS", "wave_loop", 4.0, true, false, false, false, 0);
	SendClientMessage(playerid, -1, ""chat" To stop the animation type in /stopanim");
	SetPVarInt(playerid, "UsingAnim", 1);
	return 1;
}

CMD:commands(playerid)
{
    ShowPlayerDialog(playerid,5472,DIALOG_STYLE_LIST,"DayZ - Commands","General Commands\nAnimation Commands\nGroup Commands\n","Select","Close");
	return 1;
}

CMD:acmds(playerid)
{
	if(pInfo[playerid][pAdminLevel] >= 1)
	{
		new str[480];
	    strcat(str,"Level 1: /info, /spec, /specoff, /clearanim, /kick, /mute, /unmute, /warn, /a, /wslap, /getid\n");
		strcat(str,"Level 2: /setweather, /slap, /cc, /unban, /ban, /tban\n");
		strcat(str,"Level 3: /akill, /ann2\n");
		strcat(str,"Level 4: /ip, /ann, /sethelper\n");
		strcat(str,"Level 5: /get, /respawnallcars, /respawncars, /sethumanity\n");
		strcat(str,"Level 6: /makeadmin, /setpremium, /nuke, /changename, /giveallitems");
        ShowPlayerDialog(playerid,8348,DIALOG_STYLE_MSGBOX,"DayZ - Admin Commands",str,"Close","");
	}
	else return SendClientMessage(playerid,-1,"*"COL_RED" You do not have the right admin permissions for this command!");
	return 1;
}

CMD:basickeys(playerid)
{
	new str[480];
	strcat(str,"Press ' Y ' To open inventory\nPress ' N ' To loot\nPress ' LALT (LEFT ALT) ' To loot drop items!\nPress ' C ' To refill cainster\nPress ' N ' to loot dead bodys!\n\
	Hold ' H ' To go prone!\nPress ' NUMPAD 1 ' to view map or use it from inventory!");
	ShowPlayerDialog(playerid,8741,DIALOG_STYLE_MSGBOX,"DayZ - Keys",str,"Close","");
	return 1;
}

CMD:s(playerid, params[]) return pc_cmd_shout(playerid, params);
CMD:l(playerid, params[]) return pc_cmd_local(playerid, params);
CMD:b(playerid, params[]) return pc_cmd_local(playerid, params);
CMD:o(playerid, params[]) return pc_cmd_ooc(playerid, params);
CMD:cmds(playerid, params[]) return pc_cmd_commands(playerid);
CMD:hu(playerid, params[]) return pc_cmd_handsup(playerid);
CMD:inv(playerid) return ShowInventory(playerid);


CMD:help(playerid)
{
    ShowPlayerDialog(playerid, 8341, DIALOG_STYLE_LIST, "DayZ - Help", "General Commands\nSurvival Tips\nZombies & Avoidance\n", "Select", "Close");
	return 1;
}

CMD:me(playerid, params[])
{
    new string[128], action[100];
    if(sscanf(params, "s[100]", action))
    {
        SendClientMessage(playerid, -1, ""chat" /me [action]");
        return 1;
    }
    else
    {
        format(string, sizeof(string), "* %s %s", PlayerName(playerid), action);
        ProxDetector(30, playerid, string, COLOR_GREY);
    }
    return 1;
}

CMD:shout(playerid, params[])
{
    new string[128],shout[100];
    if(sscanf(params, "s[100]", shout))
    {
        SendClientMessage(playerid, -1, ""chat" /(s)hout [message]");
        return 1;
    }
    else
    {
        format(string, sizeof(string), "%s shouts: %s!",PlayerName(playerid),shout);
        ProxDetector(80.0, playerid, string, COLOR_GREY);
    }
    return 1;
}

CMD:local(playerid,params[])
{
    if(isnull(params)) return SendClientMessage(playerid, -1,""chat" /l(ocal) [local ooc chat]");
    new string[128];

    format(string, sizeof(string), "((LOCAL)) %s Says: (( %s ))", PlayerName(playerid), params);
    ProxDetector(20.0, playerid, string, COLOR_GREY);
    return 1;
}

CMD:r(playerid,params[])
{
	if(PlayerHasItem(playerid,"Radio Device"))
	{
	    if(isnull(params)) return SendClientMessage(playerid, -1,""chat" /r [radio chat]");
	    new string[128];

	    format(string, sizeof(string), ""COL_YELLOW"((RADIO TRANSMITTER))"COL_GREY" %s Says: (( %s ))", PlayerName(playerid), params);
	    ProxDetector(pInfo[playerid][pRadioFreq], playerid, string, COLOR_GREY);
	}
	else return SendClientMessage(playerid,-1,""chat" You don't have an radio!");
    return 1;
}

CMD:goff(playerid, params[])
{
	if(globalStatus[playerid] == 0)
	{
	    globalStatus[playerid] = 1;
	    SendClientMessage(playerid, -1, ""chat" Global chat has been disabled to enable, /gon");
	}
	return 1;
}

CMD:gon(playerid, params[])
{
	if(globalStatus[playerid] == 1)
	{
	    globalStatus[playerid] = 0;
	    SendClientMessage(playerid, -1, ""chat" Global chat has been enabled to disable, /goff");
	}
	return 1;
}

CMD:ooc(playerid, params[])
{
	if(PlayerHasItem(playerid,"Radio Device"))
	{
	    if(gettime() - 7 < globalChat[playerid]) return GameTextForPlayer(playerid,"~w~WAIT BEFORE USING GLOBAL CHAT AGAIN!",1000,5);
	    {
	        if(globalStatus[playerid] == 0)
			{
				if(isnull(params)) return SendClientMessage(playerid, -1,""chat" /o(oc) [global chat]");
	    		new string[128];

			    format(string, sizeof(string), "((GLOBAL CHAT)) %s Says: (( %s ))", PlayerName(playerid), params);
			    SendGlobal(9999.0, playerid, string, COLOR_GREY);
			    globalChat[playerid] = gettime();
			}
			else return SendClientMessage(playerid, -1, ""chat" You must have global chat enabled to do this, /gon");
		}
	}
	else return SendClientMessage(playerid,-1,""chat" You don't have an radio!");
	return 1;
}

CMD:report(playerid,params[])
{
	new targetid,reason[105],reportstring[128];
	if(sscanf(params, "us[105]", targetid,reason)) return SendClientMessage(playerid,-1,""chat" /report [playerid] [reason]");
	if(!IsPlayerConnected(targetid)) return SendClientMessage(playerid,-1,"*"COL_RED" Player is not online");
	if(targetid == playerid) return SendClientMessage(playerid,-1,"*"COL_RED" You cannot report yourself!");

	if(!IsPlayerNPC(targetid))
	{
		if(pInfo[playerid][IsPlayerMuted] == 0)
		{
			SendClientMessage(playerid,-1,"*"COL_LGREEN" Your report has been sent to the online admins!");

			format(reportstring,sizeof(reportstring), ""chat""COL_YELLOW" Player %s(%d) reported %s(%d)"COL_WHITE" (Reason: %s)", PlayerName(playerid),playerid,PlayerName(targetid),targetid,reason);
			SendMessageToAllAdmins(reportstring,-1);
		}
		else {
			SendClientMessage(playerid,-1,"*"COL_RED" You cannot report a player while be muted");
		}
	}
	else return SendClientMessage(playerid,-1,"*"COL_RED" You cannot report an NPC");
	return 1;
}

CMD:ask(playerid,params[])
{
	new askstr[256],sendtohelpers[256],helpstr[128];
	if(sscanf(params, "s[128]", askstr)) return SendClientMessage(playerid,-1,"*"COL_LGREEN" /ask [question]");

	if(gettime() - 180 < pInfo[playerid][pSpamAsk]) return SendClientMessage(playerid,-1,"*"COL_RED" Wait three minutes to ask a question again!");
	{
		if(pInfo[playerid][IsPlayerMuted] == 0)
		{
			SendClientMessage(playerid,-1,"*"COL_LGREEN" Your question has been sent to the online helpers!");
			format(sendtohelpers,sizeof(sendtohelpers),"*"COL_YELLOW" Player %s(%i) has asked a question use /respond [id] [answer]",PlayerName(playerid),playerid);
			format(helpstr,sizeof(helpstr),"* [QUESTION] %s",askstr);
			SendMessageToAllHelpers(sendtohelpers,-1);
			SendMessageToAllHelpers(helpstr,-1);
			pInfo[playerid][pSpamAsk] = gettime();
		}
		else {
			SendClientMessage(playerid,-1,"*"COL_RED" You cannot report a player while be muted");
		}
	}
	return 1;
}

CMD:respond(playerid,params[])
{
    if(pInfo[playerid][Helper] >= 1)
    {
		new sendanswer[256],targetid;
		if(sscanf(params, "us[256]",targetid, sendanswer)) return SendClientMessage(playerid,-1,"*"COL_LGREEN" /respond [playerid] [question]");

		new str[256],str2[256],str3[128];
		format(str,sizeof(str),"*"COL_YELLOW" Helper %s(%i) has responded to your question!",PlayerName(playerid), playerid);
		SendClientMessage(targetid,-1,str);
		format(str2,sizeof(str2),"* [ANSWER] %s",sendanswer);
		SendClientMessage(targetid,-1,str2);
		format(str3,sizeof(str3),"*"COL_LGREEN" Helper %s(%i) has responded to %s(%i) question!",PlayerName(playerid), playerid, PlayerName(targetid), targetid);
		SendMessageToAllHelpers(str3,-1);
	}
	else return SendClientMessage(playerid,-1,"*"COL_RED" You are not an helper to use this command!");
	return 1;
}

CMD:admins(playerid, params[])
{
	if(pInfo[playerid][pHour] >= 25)
	{
	    new adminstring[128];
	    if(IsPlayerConnected(playerid))
	    {
	        for (new i = 0; i < MAX_PLAYERS; i++)
	        {
	            if(IsPlayerConnected(i))
	            {
	                if(pInfo[i][pAdminLevel] > 0)
	                {
	                    format(adminstring, sizeof(adminstring),"%s%s: %s\n", adminstring, GetAdminName(i), PlayerName(i));
	                }
	            }
	        }
	        ShowPlayerDialog(playerid,DIALOG_ADMINS,DIALOG_STYLE_MSGBOX,"Online admins",adminstring,"Close","");
		}
 		else return SendClientMessage(playerid,-1,"*"COL_LGREEN" No admins online");
	}
	else return SendClientMessage(playerid,-1,"*"COL_LGREEN" You cannot view admins online (You need 25 hours IG time)");
    return 1;
}

CMD:premiums(playerid, params[])
{
	if(pInfo[playerid][pHour] >= 1)
	{
	    new adminstring[128];
	    if(IsPlayerConnected(playerid))
	    {
	        for (new i = 0; i < MAX_PLAYERS; i++)
	        {
	            if(IsPlayerConnected(i))
	            {
	                if(pInfo[i][pPremium] > 0)
	                {
	                    format(adminstring, sizeof(adminstring),"%sLevel %d: %s\n", adminstring, pInfo[i][pPremium], PlayerName(i));
	                }
	            }
	        }
	        ShowPlayerDialog(playerid,DIALOG_VIPS,DIALOG_STYLE_MSGBOX,"Online Premiums",adminstring,"Close","");
		}
 		else return SendClientMessage(playerid,-1,"*"COL_LGREEN" No premium members online");
	}
	else return SendClientMessage(playerid,-1,"*"COL_LGREEN" You cannot view vips online (You need 1 Hour IG time)");
    return 1;
}

CMD:helpers(playerid, params[])
{
	if(pInfo[playerid][pHour] >= 1)
	{
	    new adminstring[128];
	    if(IsPlayerConnected(playerid))
	    {
	        for (new i = 0; i < MAX_PLAYERS; i++)
	        {
	            if(IsPlayerConnected(i))
	            {
	                if(pInfo[i][Helper] > 0)
	                {
	                    format(adminstring, sizeof(adminstring),"%s %s\n", adminstring, PlayerName(i));
	                }
	            }
	        }
	        ShowPlayerDialog(playerid,DIALOG_VIPS,DIALOG_STYLE_MSGBOX,"Online Helpers",adminstring,"Close","");
		}
 		else return SendClientMessage(playerid,-1,"*"COL_LGREEN" No helpers online at the moment!");
	}
	else return SendClientMessage(playerid,-1,"*"COL_LGREEN" You cannot view helpers online (You need 1 Hour IG time)");
    return 1;
}

CMD:stats(playerid) return pc_cmd_survival(playerid);

CMD:survival(playerid)
{
	new str[128];
	format(str, sizeof(str), "*"COL_WHITE" Blood: %i | Hunger: %i | Thirst: %i", pInfo[playerid][pBlood], pInfo[playerid][pHunger], pInfo[playerid][pThrist]);
	SendClientMessage(playerid, -1, str);
	return 1;
}

CMD:info(playerid,params[])
{
    if(pInfo[playerid][pAdminLevel] >= 1)
    {
        if(IsPlayerConnected(playerid))
        {
            new targetid;
            if(sscanf(params, "u", targetid)) return SendClientMessage(playerid,-1,"*"COL_RED" /info [playerid]");
            if(!IsPlayerConnected(targetid)) return SendClientMessage(playerid,-1,"*"COL_RED" Player is not online");

			new str[1200],Float:fPos[3];
   			new Float:vehhp;
            GetVehicleHealth(GetPlayerVehicleID(targetid),vehhp);
			GetPlayerPos(targetid,fPos[0],fPos[1],fPos[2]);
 			GetPlayer2DZone(targetid, zonegps, MAX_ZONE_NAME);
			format(stringgps,sizeof(stringgps),"%s", zonegps);

			format(str,sizeof(str),""COL_WHITE"Player"COL_GREEN" %s"COL_WHITE"(%i) information!\nPlayer Ping: %i\nPlayer FPS: %d\nX: %f Y: %f Z: %f\nBackpack: %s\nLocation: %s\nAirbreak Warnings: %i\n\
			Admin Warnings: %i\nMuted: %i\nAdmin Status: %s\nPremium Status: %i\nAlive Time: %s\nMurders: %i\nBlood: %i\nHumanity: %i\nSkin: %i\nCurrent Weapon: %s\nCurrent Ammo: %i\nVehicle ID: %i\nVehicle Tires: %i\nVehicle Fuel: %i\nVehicle Engine: %i\nVehicle Health: %0.f",
			PlayerName(targetid),targetid,GetPlayerPing(targetid),FPS2[targetid]-1,fPos[0],fPos[1],fPos[2],GetBackpackName(targetid),stringgps,pInfo[targetid][pAirbreakWarning],
			pInfo[targetid][pWarnings],pInfo[targetid][IsPlayerMuted],GetAdminName(targetid),pInfo[targetid][pPremium],TimeConvert(pInfo[targetid][pAliveTime]),pInfo[targetid][Murders],
			pInfo[targetid][pBlood],pInfo[targetid][Humanity],GetPlayerSkin(targetid),DayZSA_GetWeaponName(targetid),GetPlayerAmmo(targetid),GetPlayerVehicleID(targetid),vInfo[GetPlayerVehicleID(targetid)][vehicleTires],
			vInfo[GetPlayerVehicleID(targetid)][vehicleFuel],vInfo[GetPlayerVehicleID(targetid)][vehicleEngine],vehhp);
			ShowPlayerDialog(playerid,6365,DIALOG_STYLE_MSGBOX,"Viewing player info",str,"Close","");
		}
	}
	else {
		SendClientMessage(playerid,-1,"*"COL_RED" You do not have the right admin permissions for this command!");
	}
	return 1;
}

