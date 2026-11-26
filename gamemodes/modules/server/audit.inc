// ---------------------------------------------------------------------------
// Audit log (admin commands and security events) and server-side checks.
// The checks reject or report; they never ban on their own.
// ---------------------------------------------------------------------------

#define COMMANDS_PER_WINDOW   6
#define COMMAND_WINDOW_MS     2000
#define ALERT_INTERVAL_MS     10000
#define TELEPORT_DISTANCE     90.0    // on foot, between two one-second checks
#define TELEPORT_GRACE_MS     3000

new const AdminCommands[][] =
{
	"ban", "tban", "unbanip", "unbanname", "cc", "giveallitems", "makeadmin", "thanghnm", "setpremium", "sethelper", "slap",
	"spawncratem", "wslap", "ann", "ann2", "warn", "saveall", "setweather", "ip", "akill", "nuke", "get", "spec", "specoff",
	"gotop", "sethumanity", "mute", "unmute", "respawnallcars", "respawncars", "kick", "clearanim", "resetinv", "setscore",
	"lootres", "tentres", "logs", "veh", "delveh", "gun", "god"
};

new Float:LastPos[MAX_PLAYERS][3];

stock CreateAuditTable()
{
	mysql_tquery(handle, "CREATE TABLE IF NOT EXISTS `audit_log` (`ID` int NOT NULL AUTO_INCREMENT, `Time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP, `Actor` varchar(24) NOT NULL, `Level` int NOT NULL, `IP` varchar(16) NOT NULL, `Action` varchar(32) NOT NULL, `Detail` varchar(144) NOT NULL, PRIMARY KEY (`ID`))");
	return 1;
}

stock WriteAudit(playerid, const action[], const detail[])
{
	new query[512], name[MAX_PLAYER_NAME], ip[16];
	GetPlayerName(playerid, name, sizeof(name));
	GetPlayerIp(playerid, ip, sizeof(ip));
	mysql_format(handle, query, sizeof(query), "INSERT INTO `audit_log` (`Actor`,`Level`,`IP`,`Action`,`Detail`) VALUES ('%e',%d,'%e','%e','%.144e')", name, pInfo[playerid][pAdminLevel], ip, action, detail);
	mysql_tquery(handle, query);
	return 1;
}

// Records a suspicious event and tells the admins, at most once per interval for each player
stock ReportSuspect(playerid, const reason[])
{
	new tick = GetTickCount();
	if(LastAlert[playerid] && tick - LastAlert[playerid] < ALERT_INTERVAL_MS) return 0;
	LastAlert[playerid] = tick;

	new msg[144];
	format(msg, sizeof(msg), "*"COL_RED" Check %s(%d): %s", PlayerName(playerid), playerid, reason);
	SendMessageToAllAdmins(msg, -1);
	WriteAudit(playerid, "suspect", reason);
	return 1;
}

public OnPlayerCommandReceived(playerid, cmd[], params[], flags)
{
	new tick = GetTickCount();
	if(tick - CommandWindow[playerid] > COMMAND_WINDOW_MS)
	{
		CommandWindow[playerid] = tick;
		CommandsInWindow[playerid] = 0;
	}
	if(++CommandsInWindow[playerid] > COMMANDS_PER_WINDOW)
	{
		SendClientMessage(playerid, -1, ""chat" You are sending commands too fast.");
		return 0;
	}
	for(new i; i < sizeof(AdminCommands); i++)
	{
		if(strcmp(cmd, AdminCommands[i], true)) continue;
		WriteAudit(playerid, cmd, params);
		break;
	}
	return 1;
}

CMD:logs(playerid)
{
	if(pInfo[playerid][pLogged] != 1 || pInfo[playerid][pAdminLevel] < 5) return SendClientMessage(playerid, -1, "*"COL_RED" You do not have the right admin permissions for this command!");
	mysql_tquery(handle, "SELECT DATE_FORMAT(`Time`,'%d/%m %H:%i') AS `T`, `Actor`, `Action`, `Detail` FROM `audit_log` ORDER BY `ID` DESC LIMIT 20", "OnAuditLoaded", "ii", playerid, LoginSerial[playerid]);
	return 1;
}

forward OnAuditLoaded(playerid, serial);
public OnAuditLoaded(playerid, serial)
{
	if(!IsPlayerConnected(playerid) || serial != LoginSerial[playerid]) return 1;
	new rows, list[3600] = "Time\tPlayer\tAction\tDetail\n", line[200], time_[16], actor[MAX_PLAYER_NAME], action[32], detail[64];
	cache_get_row_count(rows);
	for(new row; row < rows; row++)
	{
		cache_get_value_name(row, "T", time_);
		cache_get_value_name(row, "Actor", actor);
		cache_get_value_name(row, "Action", action);
		cache_get_value_name(row, "Detail", detail);
		format(line, sizeof(line), "%s\t%s\t%s\t%s\n", time_, actor, action, detail);
		strcat(list, line);
	}
	ShowPlayerDialog(playerid, 5002, DIALOG_STYLE_TABLIST_HEADERS, "DayZ - Audit log", list, "Close", "");
	return 1;
}

// ---- checks -----------------------------------------------------------------

stock Float:GetWeaponMaxRange(weaponid)
{
	switch(weaponid)
	{
		case 22..24: return 50.0;
		case 25..27: return 55.0;
		case 28, 29, 32: return 65.0;
		case 30, 31: return 110.0;
		case 33: return 120.0;
		case 34: return 350.0;
	}
	return 320.0;
}

// Returns false when a shot must be ignored
public bool:CheckShot(playerid, weaponid, BULLET_HIT_TYPE:hittype, hitid)
{
	if(IsPlayerNPC(playerid)) return true;
	if(22 <= weaponid <= 38 && !PlayerWeapons[playerid][weaponid])
	{
		ReportSuspect(playerid, "shot with a weapon the server never gave");
		return false;
	}
	if(hittype == BULLET_HIT_TYPE_PLAYER && IsPlayerConnected(hitid))
	{
		new Float:x, Float:y, Float:z;
		GetPlayerPos(hitid, x, y, z);
		// a margin covers lag between both positions
		if(GetPlayerDistanceFromPoint(playerid, x, y, z) > GetWeaponMaxRange(weaponid) * 1.3)
		{
			ReportSuspect(playerid, "hit beyond the weapon range");
			return false;
		}
	}
	return true;
}

stock AllowTeleport(playerid)
{
	HasLastPos[playerid] = false;
	TeleportGrace[playerid] = GetTickCount();
	return 1;
}

forward MovementCheck();
public MovementCheck()
{
	new tick = GetTickCount();
	foreach(new playerid : Player)
	{
		if(IsPlayerNPC(playerid) || pInfo[playerid][pLogged] != 1 || pInfo[playerid][pIsSpawned] != 1 || pInfo[playerid][pAdminLevel] > 0 ||
		   GetPlayerState(playerid) != PLAYER_STATE_ONFOOT || tick - TeleportGrace[playerid] < TELEPORT_GRACE_MS)
		{
			HasLastPos[playerid] = false;
			continue;
		}
		new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
		// horizontal distance only, so long falls are not reported
		if(HasLastPos[playerid] && VectorSize(x - LastPos[playerid][0], y - LastPos[playerid][1], 0.0) > TELEPORT_DISTANCE)
			ReportSuspect(playerid, "possible teleport on foot");
		LastPos[playerid][0] = x;
		LastPos[playerid][1] = y;
		LastPos[playerid][2] = z;
		HasLastPos[playerid] = true;
	}
	return 1;
}
