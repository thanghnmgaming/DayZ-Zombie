/*
 Navicat Premium Dump SQL

 Source Server         : gta
 Source Server Type    : MySQL
 Source Server Version : 100432 (10.4.32-MariaDB)
 Source Host           : localhost:3306
 Source Schema         : gta

 Target Server Type    : MySQL
 Target Server Version : 100432 (10.4.32-MariaDB)
 File Encoding         : 65001

 Date: 19/03/2026 23:42:00
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for samp_ban
-- ----------------------------
DROP TABLE IF EXISTS `samp_ban`;
CREATE TABLE `samp_ban`  (
  `BanID` int NOT NULL,
  `user_banned` varchar(24) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `user_banned_ip` varchar(15) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `user_banner` varchar(24) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `ban_reason` varchar(40) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `ban_timestamp` timestamp NOT NULL DEFAULT current_timestamp ON UPDATE CURRENT_TIMESTAMP,
  `ban_time` int NOT NULL
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of samp_ban
-- ----------------------------

-- ----------------------------
-- Table structure for statsglobal
-- ----------------------------
DROP TABLE IF EXISTS `statsglobal`;
CREATE TABLE `statsglobal`  (
  `gStatsID` int NOT NULL,
  `gZombiesKilled` int NOT NULL,
  `gBanditsKilled` int NOT NULL,
  `gSurvivorsKilled` int NOT NULL,
  `gHerosKilled` int NOT NULL,
  `gDeaths` int NOT NULL,
  `gBulletsFired` int NOT NULL,
  `gHoursPlayed` int NOT NULL,
  `gAccounts` int NOT NULL
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of statsglobal
-- ----------------------------

-- ----------------------------
-- Table structure for users
-- ----------------------------
DROP TABLE IF EXISTS `users`;
CREATE TABLE `users`  (
  `Username` varchar(24) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `Password` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `Headshots` int NOT NULL,
  `Murders` int NOT NULL,
  `BanditsKilled` int NOT NULL,
  `ZombiesKilled` int NOT NULL,
  `Backpack` int NOT NULL,
  `BackpackSlots` int NOT NULL,
  `BackpackSlotsUsed` int NOT NULL,
  `pAdminLevel` int NOT NULL,
  `pPremium` int NOT NULL,
  `pX` float NOT NULL,
  `pY` float NOT NULL,
  `pZ` float NOT NULL,
  `pWeap1` int NOT NULL,
  `pAmmo1` int NOT NULL,
  `pWeap2` int NOT NULL,
  `pAmmo2` int NOT NULL,
  `pWeap3` int NOT NULL,
  `pAmmo3` int NOT NULL,
  `pWeap4` int NOT NULL,
  `pAmmo4` int NOT NULL,
  `pWeap5` int NOT NULL,
  `pAmmo5` int NOT NULL,
  `pWeap6` int NOT NULL,
  `pAmmo6` int NOT NULL,
  `pWeap7` int NOT NULL,
  `pAmmo7` int NOT NULL,
  `pWeap8` int NOT NULL,
  `pAmmo8` int NOT NULL,
  `pWeap9` int NOT NULL,
  `pAmmo9` int NOT NULL,
  `pHour` int NOT NULL,
  `pMin` int NOT NULL,
  `pSec` int NOT NULL,
  `pBlood` int NOT NULL,
  `pThrist` int NOT NULL,
  `pHunger` int NOT NULL,
  `Humanity` int NOT NULL,
  `pFirstSpawn` int NOT NULL,
  `pAliveTime` int NOT NULL,
  `pIsMapOpened` int NOT NULL,
  `pSkin` int NOT NULL,
  `Helper` int NOT NULL,
  `IsPlayerBleeding` int NOT NULL,
  `IsPlayerLegBroken` int NOT NULL,
  `pAmbientEnable` int NOT NULL,
  `DefaultGender` int NOT NULL,
  `IP` varchar(16) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `ID` int NOT NULL
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of users
-- ----------------------------
INSERT INTO `users` VALUES ('thang_minh', '70352f41061eda4ff3c322094af068ba70c3b38b', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '192.168.183.1', 0);

SET FOREIGN_KEY_CHECKS = 1;
