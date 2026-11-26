main()
{
	print("\n----------------------------------");
	print(""CName" - "Name" "Version" Loaded");
	print("----------------------------------\n");
	WasteDeAMXersTime();
}


public OnGameModeInit()
{
    WasteDeAMXersTime();
    AntiDeAMX();
    TWD_CreateServerMap();
    DayZ_CreateServerMap();
    DayZ_CreateServerMap1();

	MySQLConnect();
	mysql_log(ERROR | WARNING);
	MapAndreas_Init(MAP_ANDREAS_MODE_FULL);

	for (new i = 0; i < NPC_MAX_NODES; i++)
	{
		if (!NPC_IsNodeOpen(i) && !NPC_OpenNode(i))
		{
			printf("Error: Failed to open node %d from (scriptfiles/FCNPC/nodes/NODES%d.DAT)", i, i);
			return 0;
		}
	}
	

	ZombiesTimer = SetTimer("CreateZombies", 50, true);
	new querystr[1700];

	strcat(querystr,"CREATE TABLE IF NOT EXISTS `users` (`Username` varchar(24) NOT NULL,`Password` varchar(128) NOT NULL,`Headshots` int(11) NOT NULL,`Murders` int(11) NOT NULL,`BanditsKilled` int(11) NOT NULL,`ZombiesKilled` int(11) NOT NULL, `Backpack` int(11) NOT NULL,`BackpackSlots` int(11) NOT NULL,");
	strcat(querystr,"`BackpackSlotsUsed` int(11) NOT NULL,`pAdminLevel` int(11) NOT NULL,`pPremium` int(11) NOT NULL,`pX` float NOT NULL,`pY` float NOT NULL,`pZ` float NOT NULL,`pWeap1` int(11) NOT NULL,`pAmmo1` int(11) NOT NULL,`pWeap2` int(11) NOT NULL,");
	strcat(querystr,"`pAmmo2` int(11) NOT NULL,`pWeap3` int(11) NOT NULL,`pAmmo3` int(11) NOT NULL,`pWeap4` int(11) NOT NULL,`pAmmo4` int(11) NOT NULL,`pWeap5` int(11) NOT NULL,`pAmmo5` int(11) NOT NULL,`pWeap6` int(11) NOT NULL,`pAmmo6` int(11) NOT NULL,`pWeap7` int(11) NOT NULL,");
	strcat(querystr,"`pAmmo7` int(11) NOT NULL,`pWeap8` int(11) NOT NULL,`pAmmo8` int(11) NOT NULL,`pWeap9` int(11) NOT NULL,`pAmmo9` int(11) NOT NULL,`pHour` int(11) NOT NULL,`pMin` int(11) NOT NULL,`pSec` int(11) NOT NULL,`pBlood` int(11) NOT NULL,`pThrist` int(11) NOT NULL,");
	strcat(querystr,"`pHunger` int(11) NOT NULL,`Humanity` int(11) NOT NULL,`pFirstSpawn` int(11) NOT NULL,`pAliveTime` int(11) NOT NULL,`pIsMapOpened` int(11) NOT NULL,`pSkin` int(11) NOT NULL,`Helper` int(11) NOT NULL,`IsPlayerBleeding` int(11) NOT NULL,");
  	strcat(querystr,"`IsPlayerLegBroken` int(11) NOT NULL,`pAmbientEnable` int(11) NOT NULL,`DefaultGender` int(11) NOT NULL, `IP` varchar(16) NOT NULL,`ID` int(11) NOT NULL)");

	mysql_tquery(handle, querystr, "", "");

	new querystr2[600];
	strcat(querystr2,"CREATE TABLE IF NOT EXISTS `statsglobal` (`gStatsID` int(11) NOT NULL,`gZombiesKilled` int(11) NOT NULL,`gBanditsKilled` int(11) NOT NULL,`gSurvivorsKilled` int(11) NOT NULL,");
	strcat(querystr2,"`gHerosKilled` int(11) NOT NULL,`gDeaths` int(11) NOT NULL,`gBulletsFired` int(11) NOT NULL,`gHoursPlayed` int(11) NOT NULL,`gAccounts` int(11) NOT NULL)");
	mysql_tquery(handle, querystr2, "", "");

	new querystr3[340];
	strcat(querystr3,"CREATE TABLE IF NOT EXISTS `samp_ban` (`BanID` int(6) NOT NULL,`user_banned` varchar(24) NOT NULL,`user_banned_ip` varchar(15) NOT NULL,`user_banner` varchar(24) NOT NULL,`ban_reason` varchar(40) NOT NULL,`ban_timestamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,`ban_time` int(10) NOT NULL)");
    mysql_tquery(handle, querystr3, "", "");
	//CreateDynamicObject(18688, -2820.2588,-1530.7047,144.9823-1.47, 0.0, 0.0, 0.0, -1, -1, -1, 1000.0);
	//CreateDynamicObject(841, -2820.2588,-1530.7047,144.9823-0.7, 0.0, 0.0, 0.0, -1, -1, -1, 1000.0);

	new Zskins[] = {
	162,
 	78,
 	79,
  	230
	};

	CreateActor(Zskins[random(4)],198.9749,1891.7914,17.6481,85.7816);
	CreateActor(Zskins[random(4)],202.7016,1876.6431,17.6406,223.7221);
	CreateActor(Zskins[random(4)],227.6428,1875.3048,17.6406,303.6228);
	CreateActor(Zskins[random(4)],239.3173,1926.8015,17.6481,353.7566);
	CreateActor(Zskins[random(4)],212.8972,1921.6523,17.6406,94.0242);
	CreateActor(Zskins[random(4)],212.0003,1871.6669,13.1406,177.9983);
	CreateActor(Zskins[random(4)],162.8060,1917.6990,18.5509,62.0639);
	CreateActor(Zskins[random(4)],116.0383,1904.4347,18.6374,167.6582);
	CreateActor(Zskins[random(4)],93.4290,1925.2581,18.0490,35.7436);
	CreateActor(Zskins[random(4)],88.5337,1904.6166,17.7788,159.8248);
	CreateActor(Zskins[random(4)],53.4174,1892.1516,17.6406,94.0242);
	CreateActor(Zskins[random(4)],56.4878,1961.3083,17.6406,267.2759);
	CreateActor(Zskins[random(4)],132.1463,1948.3929,19.3742,251.6091);
	CreateActor(Zskins[random(4)],127.9250,1995.8269,19.4873,13.8102);
	CreateActor(Zskins[random(4)],158.0960,2036.4771,18.0470,346.2366);
	CreateActor(Zskins[random(4)],165.4146,2086.2070,21.8027,304.0088);
	CreateActor(Zskins[random(4)],215.6034,2039.2439,17.6406,251.6089);
	CreateActor(Zskins[random(4)],222.3624,1986.5726,17.6406,197.7152);
	CreateActor(Zskins[random(4)],273.4265,1972.4921,17.6406,274.7958);
	CreateActor(Zskins[random(4)],283.9616,1954.4507,17.6406,103.0875);
	CreateActor(Zskins[random(4)],295.0269,1925.9137,17.6406,213.3819);
	CreateActor(Zskins[random(4)],319.0655,1884.5758,17.6406,200.2218);
	CreateActor(Zskins[random(4)],314.4778,1816.7428,17.6406,234.0621);

    SetTimer("Airdrop", 480000, true);
	SetGameModeText(""Version" Loading");
	SendRconCommand("hostname "Name" Loading Variables!");
	SendRconCommand("language Zombies: 100");
	SendRconCommand("weburl "Web"");
	AddPlayerClass(29, 1958.3783, 1343.1572, 15.3746, 269.1425, 0, 0, 0, 0, 0, 0);

	startServer();
    Streamer_MaxItems(STREAMER_TYPE_OBJECT,100000);
	SetTimer("AutoSaveAll", AUTOSAVE_INTERVAL, true);
	SetTimer("TimeOnServer", 1000, true);
	SetTimer("CheckPlayerStatusZ", 8000, true);
	SetTimer("UpdatePlayer", 1000, true);
	SetTimer("UpdateServer", 1000, true);
	SetTimer("FuelCheck", 30000, true);
	SetTimer("RespawnGeneral", 2700000, true);
	SetTimer("UpdateWeather", 1200000, true);
	SetWeatherEx(5);
	SetWorldTime(21);
    UsePlayerPedAnims();
   	ShowPlayerMarkers(0);
	ShowNameTags(false);
	SetNameTagDrawDistance(25.0);
	DisableInteriorEnterExits();
	EnableStuntBonusForAll(false);
	EnableStuntBonusForAll(false);
 	CreateBases();
 	DayZSA_CreateObject();
    CreateTDS();
	WeatherUpdate();
    GlobalResetVars();
    DisableNameTagLOS();
	return 1;
}

public OnActorSpawn(actorid)
{
    for(new i; i < actorid; i++)
	{
	    ApplyActorAnimation(actorid, "WUZI", "CS_Dead_Guy", 4.1, false, true, true, true, 0);
	    SetActorInvulnerable(actorid, true);
	}
	return 1;
}

function startServer()
{
	SetGameModeText("DayZ Zombie "Version"");
	SendRconCommand("hostname "Name"");
	SendRconCommand("weburl "Web"");
	SendRconCommand("password 0");
	printf("+---------------------------------+");
    printf("+---------------------------------+");
    printf("+---------------------------------+");
    printf("DayZSA "Version" Sucessfully Loaded!");
    printf("+---------------------------------+");
    printf("+---------------------------------+");
    printf("+---------------------------------+");
    DayZSA_CreateAllVehicles();
    DayZSA_CreateAllLoots();
    DayZSA_CreateVehicleStorage();
	return 1;
 	}

forward FuelCheck();
public FuelCheck()
{
	foreach (new i : Player)
	{
	    CheckVehicleStatusGlobal(i);
	}
	return 1;
}

