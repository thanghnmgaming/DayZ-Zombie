-- DayZ Survival: database structure (MariaDB 10.5+). Contains no data.
-- The server creates these tables itself on first start, so importing this file is optional:
--   mariadb -u <user> -p <database> < database.sql

SET NAMES utf8mb4;

CREATE TABLE IF NOT EXISTS `users` (
  `Username` varchar(24) NOT NULL,
  `Password` varchar(128) NOT NULL DEFAULT '',
  `Headshots` int NOT NULL DEFAULT 0,
  `Murders` int NOT NULL DEFAULT 0,
  `BanditsKilled` int NOT NULL DEFAULT 0,
  `ZombiesKilled` int NOT NULL DEFAULT 0,
  `Backpack` int NOT NULL DEFAULT 0,
  `BackpackSlots` int NOT NULL DEFAULT 0,
  `BackpackSlotsUsed` int NOT NULL DEFAULT 0,
  `pAdminLevel` int NOT NULL DEFAULT 0,
  `pPremium` int NOT NULL DEFAULT 0,
  `pX` float NOT NULL DEFAULT 0,
  `pY` float NOT NULL DEFAULT 0,
  `pZ` float NOT NULL DEFAULT 0,
  `pWeap1` int NOT NULL DEFAULT 0,
  `pAmmo1` int NOT NULL DEFAULT 0,
  `pWeap2` int NOT NULL DEFAULT 0,
  `pAmmo2` int NOT NULL DEFAULT 0,
  `pWeap3` int NOT NULL DEFAULT 0,
  `pAmmo3` int NOT NULL DEFAULT 0,
  `pWeap4` int NOT NULL DEFAULT 0,
  `pAmmo4` int NOT NULL DEFAULT 0,
  `pWeap5` int NOT NULL DEFAULT 0,
  `pAmmo5` int NOT NULL DEFAULT 0,
  `pWeap6` int NOT NULL DEFAULT 0,
  `pAmmo6` int NOT NULL DEFAULT 0,
  `pWeap7` int NOT NULL DEFAULT 0,
  `pAmmo7` int NOT NULL DEFAULT 0,
  `pWeap8` int NOT NULL DEFAULT 0,
  `pAmmo8` int NOT NULL DEFAULT 0,
  `pWeap9` int NOT NULL DEFAULT 0,
  `pAmmo9` int NOT NULL DEFAULT 0,
  `pHour` int NOT NULL DEFAULT 0,
  `pMin` int NOT NULL DEFAULT 0,
  `pSec` int NOT NULL DEFAULT 0,
  `pBlood` int NOT NULL DEFAULT 0,
  `pThrist` int NOT NULL DEFAULT 0,
  `pHunger` int NOT NULL DEFAULT 0,
  `Humanity` int NOT NULL DEFAULT 0,
  `pFirstSpawn` int NOT NULL DEFAULT 0,
  `pAliveTime` int NOT NULL DEFAULT 0,
  `pIsMapOpened` int NOT NULL DEFAULT 0,
  `pSkin` int NOT NULL DEFAULT 0,
  `Helper` int NOT NULL DEFAULT 0,
  `IsPlayerBleeding` int NOT NULL DEFAULT 0,
  `IsPlayerLegBroken` int NOT NULL DEFAULT 0,
  `pAmbientEnable` int NOT NULL DEFAULT 0,
  `DefaultGender` int NOT NULL DEFAULT 0,
  `IP` varchar(16) NOT NULL DEFAULT '',
  `ID` int NOT NULL DEFAULT 0,
  `pInfection` int NOT NULL DEFAULT 0,
  `pMissionGoal` int NOT NULL DEFAULT 0,
  `pMissionKills` int NOT NULL DEFAULT 0,
  `pMissionDanger` int NOT NULL DEFAULT 0,
  `pMissionNext` int NOT NULL DEFAULT 0,
  UNIQUE KEY `uq_username` (`Username`)
) DEFAULT CHARSET=utf8mb4;

CREATE TABLE IF NOT EXISTS `samp_ban` (
  `BanID` int NOT NULL AUTO_INCREMENT PRIMARY KEY,
  `user_banned` varchar(24) NOT NULL,
  `user_banned_ip` varchar(45) NOT NULL,
  `user_banner` varchar(24) NOT NULL,
  `ban_reason` varchar(40) NOT NULL,
  `ban_timestamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `ban_time` int(10) NOT NULL
) DEFAULT CHARSET=utf8mb4;

CREATE TABLE IF NOT EXISTS `statsglobal` (
  `gStatsID` int(11) NOT NULL,
  `gZombiesKilled` int(11) NOT NULL,
  `gBanditsKilled` int(11) NOT NULL,
  `gSurvivorsKilled` int(11) NOT NULL,
  `gHerosKilled` int(11) NOT NULL,
  `gDeaths` int(11) NOT NULL,
  `gBulletsFired` int(11) NOT NULL,
  `gHoursPlayed` int(11) NOT NULL,
  `gAccounts` int(11) NOT NULL
) DEFAULT CHARSET=utf8mb4;

CREATE TABLE IF NOT EXISTS `inventory` (
  `Username` varchar(24) NOT NULL,
  `Slot` int NOT NULL,
  `Item` varchar(64) NOT NULL,
  `Amount` int NOT NULL,
  PRIMARY KEY (`Username`,`Slot`)
) DEFAULT CHARSET=utf8mb4;

CREATE TABLE IF NOT EXISTS `tents` (
  `ID` int NOT NULL,
  `Owner` varchar(24) NOT NULL,
  `X` float NOT NULL,
  `Y` float NOT NULL,
  `Z` float NOT NULL,
  PRIMARY KEY (`ID`)
) DEFAULT CHARSET=utf8mb4;

CREATE TABLE IF NOT EXISTS `vehicle_state` (
  `ID` int NOT NULL,
  `Model` int NOT NULL,
  `Fuel` int NOT NULL,
  `Engine` int NOT NULL,
  `Tires` int NOT NULL,
  PRIMARY KEY (`ID`)
) DEFAULT CHARSET=utf8mb4;

CREATE TABLE IF NOT EXISTS `storage_items` (
  `Kind` int NOT NULL,
  `Container` int NOT NULL,
  `Slot` int NOT NULL,
  `Item` varchar(64) NOT NULL,
  PRIMARY KEY (`Kind`,`Container`,`Slot`)
) DEFAULT CHARSET=utf8mb4;

CREATE TABLE IF NOT EXISTS `structures` (
  `ID` int NOT NULL,
  `Type` int NOT NULL,
  `Owner` varchar(24) NOT NULL,
  `X` float NOT NULL,
  `Y` float NOT NULL,
  `Z` float NOT NULL,
  `Angle` float NOT NULL,
  `Health` int NOT NULL DEFAULT 1500,
  PRIMARY KEY (`ID`)
) DEFAULT CHARSET=utf8mb4;

CREATE TABLE IF NOT EXISTS `audit_log` (
  `ID` int NOT NULL AUTO_INCREMENT,
  `Time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `Actor` varchar(24) NOT NULL,
  `Level` int NOT NULL,
  `IP` varchar(16) NOT NULL,
  `Action` varchar(32) NOT NULL,
  `Detail` varchar(144) NOT NULL,
  PRIMARY KEY (`ID`)
) DEFAULT CHARSET=utf8mb4;
