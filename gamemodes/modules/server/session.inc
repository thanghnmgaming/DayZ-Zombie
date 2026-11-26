function MySQLConnect()
{
	handle = mysql_connect_file("mysql.ini");
	if(mysql_errno(handle) == 0)
	{
		printf("[DayZ MySQL]: Connection to database was established!");
	}
	else
	{
		printf("[DayZ MySQL]: Connection to database failed! Check mysql.ini and start-database.bat");
	}
	return 1;
}

function DayZSA_ShowMenuForPlayer(playerid)
{
    SelectTextDraw(playerid, 0x00FF00FF);
	PlayerTextDrawShow(playerid, MenuLogo[playerid]);
	PlayerTextDrawShow(playerid, MenuBG[playerid]);

	if(gRegistred[playerid] == 0)
	{
	    PlayerTextDrawSetString(playerid, MenuPlay[playerid], "       START YOUR STORY");
	}

	PlayerTextDrawShow(playerid, MenuPlay[playerid]);
	PlayerTextDrawShow(playerid, MenuOptions[playerid]);
	PlayerTextDrawShow(playerid, MenuPremium[playerid]);
	PlayerTextDrawShow(playerid, MenuCredits[playerid]);
	PlayerTextDrawShow(playerid, MenuURL[playerid]);
	//PlayerTextDrawShow(playerid, MenuBlackLayer1[playerid]);
	//PlayerTextDrawShow(playerid, MenuBlackLayer2[playerid]);
	PlayerTextDrawShow(playerid, GeneralInfo[playerid]);


	PlayAudioStreamForPlayer(playerid, "http://pgagaming.net/dayzmenu.mp3");
	/*SetPlayerCameraLookAt(playerid, -1054.3846,-1157.3766,133.2800);
	SetPlayerCameraPos(playerid, -1054.3846,-1157.3766,133.2800);
	SetPlayerPos_Allow(playerid,-1037.0377,-1318.6061,143.1855);*/

	SetPlayerPos_Allow(playerid, -2820.2588,-1530.7047,144.9823);
	SetPlayerFacingAngle(playerid,299.6856);
	SetPlayerCameraPos(playerid, -2867.5381,-1556.2440,140.2921);
	SetPlayerCameraLookAt(playerid,  -2820.2588,-1530.7047,144.9823);

	SetTimerEx("MeowShow", 1800, false, "i", playerid);

	isPlayerInMenu[playerid] = 1;
	return 1;
}

forward MeowShow(playerid);
public MeowShow(playerid)
{
	SetPlayerPos_Allow(playerid, -2820.2588,-1530.7047,144.9823);
	SetPlayerFacingAngle(playerid,299.6856);
	SetPlayerCameraPos(playerid, -2867.5381,-1556.2440,140.2921);
	SetPlayerCameraLookAt(playerid,  -2820.2588,-1530.7047,144.9823);
	return 1;
}

function DayZSA_HideMenuForPlayer(playerid)
{
	StopAudioStreamForPlayer(playerid);
    CancelSelectTextDraw(playerid);
	PlayerTextDrawHide(playerid, MenuLogo[playerid]);
	PlayerTextDrawHide(playerid, MenuBG[playerid]);
	PlayerTextDrawHide(playerid, MenuPlay[playerid]);
	PlayerTextDrawHide(playerid, MenuOptions[playerid]);
	PlayerTextDrawHide(playerid, MenuPremium[playerid]);
	PlayerTextDrawHide(playerid, MenuCredits[playerid]);
	PlayerTextDrawHide(playerid, MenuURL[playerid]);
	PlayerTextDrawHide(playerid, MenuBlackLayer1[playerid]);
	PlayerTextDrawHide(playerid, MenuBlackLayer2[playerid]);
	PlayerTextDrawHide(playerid, GeneralInfo[playerid]);
	isPlayerInMenu[playerid] = 0;
	return 1;
}

forward loadingSpawn(playerid);
public loadingSpawn(playerid)
{
    SetSpawnInfo(playerid, 0, 285, 0.0, 0.0, 0.0, 0.0, 0,0,0,0,0,0);
    TogglePlayerSpectating(playerid, false);
    return 1;
}

public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
	if(playertextid == MenuPlay[playerid])
    {

        GameTextForPlayer(playerid,"~w~loading...", 2500, 4);
        DayZSA_HideMenuForPlayer(playerid);
        if(pInfo[playerid][DefaultGender] == 0)
        {
            //ShowPlayerDialog(playerid, DIALOG_GENDEROPTION_2, DIALOG_STYLE_MSGBOX, "DayZ - Gender Selection", "Please, select the default gender you wish to spawn with.\n** Please note you can change this anytime via Options Menu **", "Male", "Female");
			pInfo[playerid][DefaultGender] = 1;
		}
   		PlayerTextDrawShow(playerid, PlayerBlood[playerid]);
		PlayerTextDrawShow(playerid, PlayerHunger[playerid]);
		PlayerTextDrawShow(playerid, PlayerThirst[playerid]);
		PlayerTextDrawShow(playerid, PlayerNoise[playerid]);
		PlayerTextDrawShow(playerid, PlayerEye[playerid]);
		PlayerTextDrawShow(playerid, playerBandit[playerid]);
		PlayerTextDrawShow(playerid, PlayerTemp[playerid]);
//		PlayerTextDrawShow(playerid, HudBG_1[playerid]);
		TextDrawShowForPlayer(playerid, DebugBox);
		PlayerTextDrawShow(playerid, DebugMonitor_Text[playerid]);
		PlayerTextDrawShow(playerid, WebsiteLogo[playerid]);
		PlayerTextDrawShow(playerid, Debug_GunInfo[playerid]);
		PlayerTextDrawShow(playerid, Debug_GunIcon[playerid]);
		PlayerTextDrawShow(playerid, DebugInfo[playerid]);
		
		
		SetTimerEx("loadingSpawn", 2500, false, "i", playerid);
    }

   	else if(playertextid == MenuOptions[playerid])
    {
		ShowPlayerDialog(playerid, DIALOG_OPTIONS, DIALOG_STYLE_LIST, "DayZ - Options Menu", "Default Gender Selection\nAmbient Background", "Select", "Cancel");
    }

   	else if(playertextid == MenuPremium[playerid])
    {
    	SendClientMessage(playerid, -1, ""chat" Soon to be added!");
    }

   	else if(playertextid == MenuCredits[playerid])
    {
		SendClientMessage(playerid, -1, ""chat" Soon to be added!");
    }

    else if(playertextid == GeneralInfo[playerid])
    {
		SendClientMessage(playerid, -1, ""chat" Soon to be added!");
	}
    return 1;
}

forward ResetAB_Allow(playerid);
public ResetAB_Allow(playerid)
{
	abAllow[playerid] = 0;
	return 1;
}

stock PreloadAnimLib(playerid, const animlib[]) ApplyAnimation(playerid,animlib,"null",0.0,0,0,0,0,0);

forward ResetAction(playerid,actionid);
public ResetAction(playerid,actionid)
{
	if(actionid == ACTION_ANIMATION)
	{
	    if(!IsPlayerInAnyVehicle(playerid))
	    {
			ClearAnimations(playerid, 1);
			new clearanim = GetPlayerSkin(playerid);
			SetPlayerSkin(playerid, clearanim);
		}
	}

	if(actionid == ACTION_SPECIAL)
	{
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
	}
	return 1;
}

function SetPlayerPos_Allow(playerid, Float:px_ab, Float:py_ab, Float:pz_ab)
{
    AllowTeleport(playerid);
    abAllow[playerid] = 1;
    SetTimerEx("ResetAB_Allow", 2500, false, "i", playerid);
    SetPlayerPos(playerid, px_ab, py_ab, pz_ab);
    return 1;
}

stock SetPlayerLookAt(playerid, Float:x, Float:y)
{
	new Float:Px, Float:Py, Float: Pa;
	GetPlayerPos(playerid, Px, Py, Pa);
	Pa = floatabs(atan((y-Py)/(x-Px)));
	if (x <= Px && y >= Py) Pa = floatsub(180, Pa);
	else if (x < Px && y < Py) Pa = floatadd(Pa, 180);
	else if (x >= Px && y <= Py) Pa = floatsub(360.0, Pa);
	Pa = floatsub(Pa, 90.0);
	if (Pa >= 360.0) Pa = floatsub(Pa, 360.0);
	SetPlayerFacingAngle(playerid, Pa);
}

