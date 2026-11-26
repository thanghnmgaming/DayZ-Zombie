/* Ban System */

stock jBan(player_banned, player_banner, reason[], time = 0, system = 0)
{
	if(system == 0)
	{
		if(strlen(reason) > MAX_REASON_LENGTH) return SendClientMessage(player_banner, 0xFFFFFF, ""chat" Sorry, the maximum reason length is "#MAX_REASON_LENGTH" characters!");

		if(gotBanned[player_banned] == 0)
		{
		    gotBanned[player_banned] = 1;
			mysql_format(handle, jQuery, MAX_QUERY_LENGTH, "INSERT INTO `"#J_TABLE"` (user_banned, user_banned_ip, user_banner, ban_reason, ban_timestamp, ban_time) VALUES ('%e', '%e', 'System', '%e', CURRENT_TIMESTAMP, %d)", jNames[player_banned], jIP[player_banned], reason, time);
			mysql_tquery(handle, jQuery, "", "");
			gotBanned[player_banned] = 1;
			new strkick[180];
			format(strkick, sizeof(strkick), ""chat" System has banned %s (%i) for: %s", PlayerName(player_banned), player_banned, reason);
			SendClientMessageToAll(-1, strkick);
            SendClientMessage(player_banned, -1, ""chat""COL_WHITE" If you feel this is a mistake please, visit www.pgagaming.net under DayZ boards -> Unban Requests");

			KickEx(player_banned);
			print(jQuery);
		}
	}
	else
	{
		if(strlen(reason) > MAX_REASON_LENGTH) return SendClientMessage(player_banner, 0xFFFFFF, ""chat" Sorry, the maximum reason length is "#MAX_REASON_LENGTH" characters!");

		if(gotBanned[player_banned] == 0)
		{
		    gotBanned[player_banned] = 1;
			mysql_format(handle, jQuery, MAX_QUERY_LENGTH, "INSERT INTO `"#J_TABLE"` (user_banned, user_banned_ip, user_banner, ban_reason, ban_timestamp, ban_time) VALUES ('%e', '%e', '%e', '%e', CURRENT_TIMESTAMP, %d)", jNames[player_banned], jIP[player_banned], jNames[player_banner], reason, time);
			mysql_tquery(handle, jQuery, "", "");

			new strkick[180];
			format(strkick, sizeof(strkick), ""chat""COL_WHITE" %s has banned you for: %s", GetAdminName(player_banner), reason);
			SendClientMessage(player_banned, -1, strkick);
			SendClientMessage(player_banned, -1, ""chat""COL_WHITE" If you feel this is a mistake please, visit www.pgagaming.net under DayZ boards -> Unban Requests");
			print(jQuery);
			KickEx(player_banned);
		}
	}
	return 1;
}

stock jBanCheck(playerid)
{
	mysql_format(handle, jQuery, MAX_QUERY_LENGTH, "SELECT user_banner, ban_reason, TIMESTAMPDIFF(MINUTE, NOW(), DATE_ADD(ban_timestamp, INTERVAL ban_time MINUTE)) FROM `"#J_TABLE"` WHERE ( `user_banned` = '%e' OR user_banned_ip = '%e' ) AND (NOW() <= DATE_ADD(ban_timestamp, INTERVAL ban_time MINUTE) OR ban_time = 0)", PlayerName(playerid), jIP[playerid]);
	mysql_tquery(handle, jQuery, "jban_OnQueryFinish", "ii", playerid, LoginSerial[playerid]);
	return 1;
}

stock jUnbanName(name[])
{
	if(strlen(name) > MAX_PLAYER_NAME) return 0;
	mysql_format(handle, jQuery, MAX_QUERY_LENGTH, "DELETE FROM `"#J_TABLE"` WHERE user_banned = '%e'", name);

	mysql_tquery(handle, jQuery, "", "");
	return 1;
}

stock jUnbanIP(IP[])
{
	if(strlen(IP) > MAX_PLAYER_IP) return 0;
	mysql_format(handle, jQuery, MAX_QUERY_LENGTH, "DELETE FROM `"#J_TABLE"` WHERE user_banned_ip = '%e'", IP);

	mysql_tquery(handle, jQuery, "", "");
	return 1;
}

function jban_OnQueryFinish(extraid, serial)
{
	if(serial != LoginSerial[extraid]) return 1;
	new rows;
	cache_get_row_count(rows);

	if(rows)
	{
		SendClientMessage(extraid, -1, ""COL_RED" *** YOU ARE CURRENTLY BANNED FROM THIS SERVER");
		SendClientMessage(extraid, -1, ""COL_RED" *** POST YOUR APPEAL AT "COL_WHITE"WWW.PGAGAMING.NET");

		Kick(extraid);
	}
	else
	{
		new query[256];
		mysql_format(handle, query, sizeof(query), "SELECT * FROM `users` WHERE `Username` = '%e'", PlayerName(extraid));
		mysql_tquery(handle, query, "WhenAccountCheck", "ii", extraid, serial);
	}
	return 1;
}

