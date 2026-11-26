stock GetHelperName(playerid)
{
	new helpername[128];
	switch(pInfo[playerid][Helper])
	{
		case 0: helpername = "Not Helper";
		case 1: helpername = "Helper";
	}
	return helpername;
}
stock PlayerName(playerid)
{
	new ppName[24];
	GetPlayerName(playerid, ppName, 24);
 	return ppName;
}

stock SaveStats(playerid)
{
	if(!IsPlayerConnected(playerid) || pInfo[playerid][pLogged] != 1) return 0;

	// Position, weapons and skin are only valid while alive in the world (not menu, spectating or dead)
	new PLAYER_STATE:playerstate = GetPlayerState(playerid);
	if(pInfo[playerid][pIsSpawned] == 1 && isPlayerInMenu[playerid] == 0 && playerstate != PLAYER_STATE_SPECTATING && playerstate != PLAYER_STATE_WASTED)
	{
		GetPlayerPos(playerid, pInfo[playerid][pX], pInfo[playerid][pY], pInfo[playerid][pZ]);
		pInfo[playerid][pSkin] = GetPlayerSkin(playerid);
		GetPlayerWeaponData(playerid, WEAPON_SLOT:1, WEAPON:pInfo[playerid][pWeap1], pInfo[playerid][pAmmo1]);
		GetPlayerWeaponData(playerid, WEAPON_SLOT:2, WEAPON:pInfo[playerid][pWeap2], pInfo[playerid][pAmmo2]);
		GetPlayerWeaponData(playerid, WEAPON_SLOT:3, WEAPON:pInfo[playerid][pWeap3], pInfo[playerid][pAmmo3]);
		GetPlayerWeaponData(playerid, WEAPON_SLOT:4, WEAPON:pInfo[playerid][pWeap4], pInfo[playerid][pAmmo4]);
		GetPlayerWeaponData(playerid, WEAPON_SLOT:5, WEAPON:pInfo[playerid][pWeap5], pInfo[playerid][pAmmo5]);
		GetPlayerWeaponData(playerid, WEAPON_SLOT:6, WEAPON:pInfo[playerid][pWeap6], pInfo[playerid][pAmmo6]);
		GetPlayerWeaponData(playerid, WEAPON_SLOT:7, WEAPON:pInfo[playerid][pWeap7], pInfo[playerid][pAmmo7]);
		GetPlayerWeaponData(playerid, WEAPON_SLOT:8, WEAPON:pInfo[playerid][pWeap8], pInfo[playerid][pAmmo8]);
		GetPlayerWeaponData(playerid, WEAPON_SLOT:9, WEAPON:pInfo[playerid][pWeap9], pInfo[playerid][pAmmo9]);
	}

	new Query[1100];
	strcat(Query,"UPDATE `users` SET `Headshots` = '%i', `Murders` = '%i', `BanditsKilled` = '%i', `ZombiesKilled` = '%i', `Backpack` = '%i', `BackpackSlots` = '%i', `BackpackSlotsUsed` = '%i', `pAdminLevel` = '%i',");
	strcat(Query,"`pPremium` = '%i', `pX` = '%f', `pY` = '%f', `pZ` = '%f', `pWeap1` = '%i', `pAmmo1` = '%i', `pWeap2` = '%i', `pAmmo2` = '%i', `pWeap3` = '%i', `pAmmo3` = '%i', `pWeap4` = '%i', `pAmmo4` = '%i',");
	strcat(Query,"`pWeap5` = '%i', `pAmmo5` = '%i', `pWeap6` = '%i', `pAmmo6` = '%i', `pWeap7` = '%i', `pAmmo7` = '%i', `pWeap8` = '%i', `pAmmo8` = '%i', `pWeap9` = '%i', `pAmmo9` = '%i', `pHour` = '%i', `pMin` = '%i', `pSec` = '%i',");
	strcat(Query,"`pBlood` = '%i', `pThrist` = '%i', `pHunger` = '%i', `Humanity` = '%i', `pFirstSpawn` = '%i', `pAliveTime` = '%i', `pIsMapOpened` = '%i', `pSkin` = '%i',");
	strcat(Query,"`Helper` = '%i', `IsPlayerBleeding` = '%i', `IsPlayerLegBroken` = '%i', `pAmbientEnable` = '%i', `DefaultGender` = '%i' WHERE `Username` = '%s'");
	format(Query,sizeof(Query),Query,pInfo[playerid][Headshots],
	pInfo[playerid][Murders],
	pInfo[playerid][BanditsKilled],
	pInfo[playerid][ZombiesKilled],
	pInfo[playerid][Backpack],
	pInfo[playerid][BackpackSlots],
	pInfo[playerid][BackpackSlotsUsed],
	pInfo[playerid][pAdminLevel],
	pInfo[playerid][pPremium],
	pInfo[playerid][pX],
	pInfo[playerid][pY],
	pInfo[playerid][pZ],
	pInfo[playerid][pWeap1],
	pInfo[playerid][pAmmo1],
	pInfo[playerid][pWeap2],
	pInfo[playerid][pAmmo2],
	pInfo[playerid][pWeap3],
	pInfo[playerid][pAmmo3],
	pInfo[playerid][pWeap4],
	pInfo[playerid][pAmmo4],
	pInfo[playerid][pWeap5],
	pInfo[playerid][pAmmo5],
	pInfo[playerid][pWeap6],
	pInfo[playerid][pAmmo6],
	pInfo[playerid][pWeap7],
	pInfo[playerid][pAmmo7],
	pInfo[playerid][pWeap8],
	pInfo[playerid][pAmmo8],
	pInfo[playerid][pWeap9],
	pInfo[playerid][pAmmo9],
	pInfo[playerid][pHour],
	pInfo[playerid][pMin],
	pInfo[playerid][pSec],
	pInfo[playerid][pBlood],
	pInfo[playerid][pThrist],
	pInfo[playerid][pHunger],
	pInfo[playerid][Humanity],
	pInfo[playerid][pFirstSpawn],
	pInfo[playerid][pAliveTime],
	pInfo[playerid][pIsMapOpened],
	pInfo[playerid][pSkin],
	pInfo[playerid][Helper],
	pInfo[playerid][IsPlayerBleeding],
	pInfo[playerid][IsPlayerLegBroken],
	pInfo[playerid][pAmbientEnable],
	pInfo[playerid][DefaultGender],
	PlayerName(playerid));
	mysql_tquery(handle, Query, "", "");
	SaveInventory(playerid);
	return 1;
}

stock CheckVersion(playerid)
{
	GetPlayerName(playerid, jNames[playerid], MAX_PLAYER_NAME);
	GetPlayerIp(playerid, jIP[playerid], MAX_PLAYER_IP);
	jBanCheck(playerid);
	return 1;
}

stock GivePlayerWeaponEx(playerid,weaponid,ammo)
{
    PlayerWeapons[playerid][weaponid]=true;
    GivePlayerWeapon(playerid,weaponid,ammo);
}

stock KickPlayer(playerid, reason[])
{
	if(gotBanned[playerid] == 0)
    {
        gotBanned[playerid] = 1;
		new strkick[180];
		format(strkick, sizeof(strkick), ""chat" System has kicked %s (%i) for: %s", PlayerName(playerid), playerid, reason);
		SendClientMessageToAll(-1, strkick);
		KickEx(playerid);
	}
	return 1;
}

public Kick_Load(playerid)
{
    if(IsPlayerNPC(playerid)) return 1;
    if(!IsPlayerNPC(playerid))
    {
		Kick(playerid);
	}
	return 1;
}
public KickEx(playerid)
{
    SetTimerEx("Kick_Load", 1500, 0, "d", playerid);
    return 1;
}

stock ClearChat()
{
	for(new a = 0; a < 20; a++) SendClientMessageToAll(-1, " ");
	return 1;
}

stock ResetVars(playerid)
{
	ViewId[playerid] = 0;
	ViewItem[playerid][0] = EOS;
	pInfo[playerid][IsPlayerGroupOwner] = 0;
	pInfo[playerid][IsPlayerInvited] = 0;
	pInfo[playerid][IsPlayerInvitedGroupID] = 0;
	pInfo[playerid][IsPlayerMuted] = 0;
	pInfo[playerid][pWarnings] = 0;
	pInfo[playerid][pPM] = 0;
	pInfo[playerid][pAmbientEnable] = 0;
	pInfo[playerid][DefaultGender] = 0;
	pInfo[playerid][pUserID] = 0;
	isPlayerInMenu[playerid] = 0;
	gRegistred[playerid] = 0;
	DeathSpam[playerid] = 0;
	LastDeath[playerid] = 0;
	OPRF_Processed[playerid] = false;
	LoginFails[playerid] = 0;
    pInfo[playerid][pTentCreated] = 0;
	IsSpecing[playerid] = 0;
    gotBanned[playerid] = 0;
    globalChat[playerid] = 0;
    giveWeaponAllow[playerid] = 1;
	pInfo[playerid][Username] = 0;
	pInfo[playerid][Password] = 0;
	pInfo[playerid][Headshots] = 0;
	pInfo[playerid][Murders] = 0;
	pInfo[playerid][BanditsKilled] = 0;
	pInfo[playerid][ZombiesKilled] = 0;
	pInfo[playerid][Backpack] = 0;
	pInfo[playerid][BackpackSlots] = 0;
	pInfo[playerid][BackpackSlotsUsed] = 0;
	pInfo[playerid][pAdminLevel] = 0;
	pInfo[playerid][pPremium] = 0;
	pInfo[playerid][pX] = 0.0;
	pInfo[playerid][pY] = 0.0;
	pInfo[playerid][pZ] = 0.0;
	pInfo[playerid][pWeap1] = 0;
	pInfo[playerid][pAmmo1] = 0;
	pInfo[playerid][pWeap2] = 0;
	pInfo[playerid][pAmmo2] = 0;
	pInfo[playerid][pWeap3] = 0;
	pInfo[playerid][pAmmo3] = 0;
	pInfo[playerid][pWeap4] = 0;
	pInfo[playerid][pAmmo4] = 0;
	pInfo[playerid][pWeap5] = 0;
	pInfo[playerid][pAmmo5] = 0;
	pInfo[playerid][pWeap6] = 0;
	pInfo[playerid][pAmmo6] = 0;
	pInfo[playerid][pWeap7] = 0;
	pInfo[playerid][pAmmo7] = 0;
	pInfo[playerid][pWeap8] = 0;
	pInfo[playerid][pAmmo8] = 0;
	pInfo[playerid][pWeap9] = 0;
	pInfo[playerid][pAmmo9] = 0;
	pInfo[playerid][pHour] = 0;
	pInfo[playerid][pMin] = 0;
	pInfo[playerid][pSec] = 0;
	pInfo[playerid][Helper] = 0;
	pInfo[playerid][pBlood] = 0;
	pInfo[playerid][pThrist] = 0;
	pInfo[playerid][pHunger] = 0;
	pInfo[playerid][Humanity] = 0;
	pInfo[playerid][pFirstSpawn] = 0;
	pInfo[playerid][pIsMapOpened] = 0;
	pInfo[playerid][IsPlayerBleeding] = 0;
	pInfo[playerid][pLogged] = 0;
	pInfo[playerid][pInfection] = 0;
	pInfo[playerid][IsPlayerLegBroken] = 0;
	pInfo[playerid][IsPlayerBandit] = 0;
	pInfo[playerid][IsPlayerHero] = 0;
	pInfo[playerid][IsPlayerDrunk] = 0;
	pInfo[playerid][IsPlayerMakingNoise] = 0;
	pInfo[playerid][pIsSpawned] = 0;
	pInfo[playerid][pAliveTime] = 0;
	pInfo[playerid][pProne] = 0;
	pInfo[playerid][pTemp] = 100.0;
	pInfo[playerid][pSpamDrop] = 0;
	pInfo[playerid][pGroupSpam] = 0;
	pInfo[playerid][pSaveSpam] = 0;
	pInfo[playerid][pProneSpam] = 0;
	pInfo[playerid][pSpamAsk] = 0;
	pInfo[playerid][pFade] = 0;
	pInfo[playerid][pAirbreakWarning] = 0;
	pInfo[playerid][pCleoFlyWarning] = 0;
	pInfo[playerid][pSkin] = 0;
	TeleportAllowed[playerid] = 0;
	pInfo[playerid][FirstPerson] = 0;
	pInfo[playerid][pStorageLink] = 0;
	pInfo[playerid][pTentLink] = 0;
	pInfo[playerid][pRadioFreq] = 60.0;
	pInfo[playerid][IsPlayerInGroup] = 0;
	pInfo[playerid][IsPlayerCleoFly] = 0;
	pInfo[playerid][IsPlayerInGroupID] = 0;
 	IsSpecing[playerid] = 0;
	KillTimer(pInfo[playerid][Bleeding]);
	KillTimer(pInfo[playerid][IsPlayerDrunkTimer]);
	PlayerTextDrawHide(playerid, LegBroken[playerid]);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_PISTOL, 1);
	player_Handsup[playerid] = 0;
	return 1;
}

stock ClearChatPlayer(playerid)
{
	for(new a = 0; a < 20; a++) SendClientMessage(playerid,-1, " ");
	return 1;
}

stock UpdateAnnouncement(text[])
{
	new str[256];
	format(str,sizeof(str),"%s",text);
	TextDrawSetString(Announcement,str);
	TextDrawShowForAll(Announcement);
	SetTimer("HideAnnouncement", 6000, false);
    return 1;
}

function HideAnnouncement() return TextDrawHideForAll(Announcement);

stock DeleteTDS()
{
	TextDrawHideForAll(DebugBox);
	TextDrawDestroy(DebugBox);
	TextDrawHideForAll(DebugText);
	TextDrawDestroy(DebugText);
	TextDrawHideForAll(Announcement);
	TextDrawDestroy(Announcement);
	TextDrawHideForAll(DayZSA_Web);
	TextDrawDestroy(DayZSA_Web);
	GangZoneDestroy(BlockMap);
	return 1;
}

stock FadePlayerScreen(playerid)
{
	if(ScreenStatus[playerid] == 0)
    {
        KillTimer( FadeTDTimer [ playerid ] );
        ScreenStatus [ playerid ] = 1;
        TextDrawShowForPlayer( playerid, WholeScreen );
        FadeTDTimer [ playerid ] = SetTimerEx( "FadeTextdraw", 50, true, "i", playerid );
    }
	return 1;
}

