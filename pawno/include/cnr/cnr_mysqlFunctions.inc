#define MAX_OSLOTS  				6
enum playerInformation
{
	actualID,
	bool:isInDuel,
	tempAdminName[24],
	playerNamee[24],
	playerLevel,			// Holds the players administration level
	playerMoney,			// Holds the players current on-hand money
	playerBank,				// Holds the players bank balance
	playerScore,			// Holds the players score
	playerIP[16],			// Holds the players IP address
	playerStoreID,			// Holds the current store ID the player is inside
	playerCheckID,			//
	playerKills,			// Holds the players amount of kills
	playerDeaths,			// Holds the players amount of deaths
	playerRobberies,		// Holds the players amount of robberies
	playerInterior,			// Holds the players current interior world
	playerVWorld,			// Holds the players current virtual world
	playerJailTime,			// Holds the players time they have in jail
	playerMuteTime,			// Holds the players time they are muted for
	playerTimesJailed,		// Holds the players count of how many times they've been jailed
	playerCheckpointTime,	// Holds the last time the player entered a checkpoint
	playerRobTime,			// Holds the time the player has left til completed robbing checkpoint
	playerSafeObj,			// Holds the safe object for when they player begins a robbery
	playerClass,			// Holds the players current class
	playerWantedLevel,		// Holds the players current wanted level
	playerXP,				// Holds the players XP
	playerVIPLevel,			// Holds the players VIP level
	playerFightStyle,
	playerJob,
	playerGetStats,
	playerCopBanned,
	playerArmyBanned,
	playerBanReason[300],
	playerBanned,
	playerCourierLevel,
	playerCourierItems,
	playerLastCourierCP,
	playerCourierMap,
	playerLastVehicleID,
	playerHitValue,
	playerWarnings,
	playerLastTicket[100],
	playerBailPrice,
	playerBailTo[100],
	playerGunOffer,
	playerHealOffer,
	playerHealPrice,
	playerCureOffer,
	playerCurePrice,
	playerBJOffer[100],
	playerGunDealer,
	playerAdminJailed,
	playerCopTutorial,
	playerLastCommand,
	playerLastLEO,
	playerPreviousVehicles[3],
	playerLastKill,
	playerGangID,
	playerLastLogged,
	playerHelper,
	lastCarDrop,
	playerWeed,
	vipExpires,
	lastRecipient,
	truckingCheckpoint,
	truckingStatus,
	truckingMission,
	truckStat,
	canTruck,
	vipWeapon,
	copArrests,
	moneyBags,
	rulesRead,
	spawnHouse,
	hitsCompleted,
	vehicleMenu,
	houseMenu,
	houseCount,
	playerVehicleLocating,
	Float:playerHouseLocating[3],
	houseFindIteration,
	playerBackpack,
	healthInsurance,
	weaponSkill,
	
	// Tokens
	rTokens,
	
	// Allow to be spectated
	bool:allowSpec,
	
	// Ransom
	playerRansomTo,
	playerRansomPrice,
	
	// Bus Driver
	busStatus,
	busRoute,
	busCP,
	busCompleted,
	
	// Sweeper
	sweepStatus,
	sweepRoute,
	sweepCP,
	sweepCompleted,
	
	// Medic
	medicStatus,
	medicCheckpoint,
	medicMission,
	
	// Easter specific
	myEggs[10],
	
	// Vehicle spawning
	Float:playerSpawnPoint[4],
	
	// Forklift
	forkliftStatus,
	forkliftCompleted,
	forkliftCP,
	forkliftObject,
	forkliftDamage,
	
	// New stats
	streetRobberies,
	streetRapes,
	playersKidnapped,
	playersTied,
	copDetains,
	copKills,
	bankRobs,
	bombsDefused,
	
	// DM Arena
	dmKills,
	dmDeaths,
	dmStreak,
	cookies,
	
	// Anti-cheat to prevent CP teleportation
	playerMissionCPTime,
	
	// Car warp
	bool:ctpImmune,
	
	// Air break
	bool:abImmune,
	airbreakWarn,
	
	// C-bug
	NotMoving,
	WeaponID,
	CheckCrouch,
	Ammo[48],
	cbugWarnings,
	
	// Anti Save Stats Spam
	playerCanSaveStats,
	
	// Mute warnings
	muteWarnings,
	
	// Innocent kill count
	innocentKills,
	aInnocentKills,
	
	// Storing an admin set skin for the session
	playerCustomSkin,
	
	// Inventory
	playerRope,             // INVENTORY ITEM ( rope )
	playerScissors,         // INVENTORY ITEM ( scissors )
	playerButtPlug,         // INVENTORY ITEM ( butt plug )
	playerBiggerPockets,    // INVENTORY ITEM ( bigger pockets )
	playerSecureWallet,
	playerBobbyPins,
	playerExplosives,
	playerDefuseKit,
	playerJailKit,
	canEscape,

	playerInsideHouse,		// Holds the current house the player is in
	playerInsideBusiness,
	playerHousePass, 		// Password ID holder
	
	Float:CourierX,
	Float:CourierY,
	Float:CourierZ,
	
	// Timers
	
	unfreezeTimer, 
	retazeTimer, 
	uncuffTimer,
	recuffTimer,
	arrestTimer,
	untieTimer,
	reEMPTimer,
	fixTimer,
	flipTimer,
	nosTimer,
	mechREMPTimer,
	reactivateRapeStatus,
	reactivateRobStatus,
	hcpTimer,
	speedTimer,
	courierTimer,
	courierDistance,
	courierIcon,
	kidnapTimer,
	derbyHeightTimer,
	playerHitmanTrackerTimer,
	rapedTimer,
	jailTimer,
	commandTimer,
	spawnPlayerTimer,
	truckExitTimer,
	truckCounter,
	truckLoadTimer,
	breakCuffsTimer,
	achieveTimer,
	spamTimer,
	CheckSpeed,
	checkFly,
	retruckTimer,
	saveStatsTimer,
	rehealTimer,
	recureTimer,
	breakinTimer,
	reBreakinTimer,
	objectsTimer,
	streakTimer,
	houseTimer,
	
	// Anti-ad
	adDetected,
	
	// Anti-rapid fire
	shotTime,
	shot,
	shotWarnings,
	
	// Car swing
	carSwing,
	
	// Exit building fix
	lastEnteredID,
	
	// Spectating variables
	previousWeapons[13],
	previousAmmoLots[13],
	previousVirtualWorld,
	previousInteriorWorld,
	
	Float:previousX,
	Float:previousY,
	Float:previousZ,
	Float:previousHealth,
	Float:previousArmour,
	
	// Booleans
	bool:playerLoggedIn,	// Holds the players logged in status
	bool:playerAdminDuty,	// Holds the players admin duty status
	bool:playerCanTaze,		// Holds the players ability to taze status
	bool:playerCanCuff,		// Holds the players ability to cuff status
	bool:playerCanArrest,	// Holds the players ability to arrest status
	bool:playerCanEMP,	    // Holds the players ability to EMP players
	bool:playerIsTazed,		// Holds the players taze status
	bool:playerIsCuffed,	// Holds the players cuff status
	bool:playerIsTied,		// Holds the players tied status
	bool:playerIsInHouse,	// Holds the players inside house status
	bool:playerHitmarker,	// Holds the status of the players hitmarker 	
	bool:playerCanRape,		// Holds the players ability to rape players
	bool:playerCanRob, 		// Holds the players ability to rob players
	bool:playerCanRepair,	// Holds the players ability to repair player vehicles
	bool:playerCanFlip,		// Holds the players ability to flip player vehicles
	bool:playerCanNOS,		// Holds the players ability to add nos to player vehicles
	bool:playerCanREMP,		// Holds the players ability to add remp player vehicles
	bool:adminWeapon,		// Without this the player will be banned for weapon hacks
	bool:pEnterHouse,		// Determines whether a play can enter/exit a house (to stop falling through world)
	bool:pEnterBusiness,
	bool:showALog,			// Enable/disable admin log
	bool:iscourier,			// Is/not courier
	bool:playerCanKidnap,	// Can/cannot kidnap
	bool:playerUsingAnim,
	bool:playerIsTracking,
	bool:hasSTD,
	bool:isInEvent,
	bool:playerIsSpectating,
	bool:playerStopEvents,
	bool:playerPingImmune,
	bool:hasSpawned,
	bool:selectingClass,
	bool:canUseCommands,
	bool:isBanned,
	bool:playerBlockPMs,
	bool:playerBeenBanned,
	bool:canBreakCuffs,
	bool:pmSpy,
	bool:playerDied,
	bool:suicide,
	bool:canHeal,
	bool:isInFallout,
	bool:canCure,
	bool:canBreakIn,
	bool:vipColour,
	bool:isInDM,
	bool:useAdminName,
	bool:hasBackpack,
	bool:hasParrot,
	bool:luckyCharm,
	bool:mask,
	bool:canWeed,
	
	// Textdraws
	PlayerText:playerExperience,
	PlayerText:townTD,
	PlayerText:playerHitmarkerTD,
	PlayerText:playerJailTimerTD,
	PlayerText:playerTruckingTD,
	PlayerText:playerTruckingWaitTD,
	PlayerText:playerCourierDistanceTD,
	PlayerText:playerAddedXPTD,
	PlayerText:wantedStars,
	PlayerText:playerTracker,
	PlayerText:cnrLogo,
	PlayerText:Achieve1,
	PlayerText:Achieve2,
	PlayerText:Achieve3,
	PlayerText:Achieve4,
	PlayerText:MM1,
	PlayerText:MM2,
	PlayerText:MM3,
	PlayerText:MM4,
	
	PlayerText:Welcome1,
	PlayerText:Welcome2,
	PlayerText:Welcome3,
	PlayerText:Welcome4,
	PlayerText:Welcome5,
	PlayerText:Welcome6,
	PlayerText:Welcome7,
	PlayerText:Welcome8,
	
	PlayerText:InnocentKill1,
	PlayerText:InnocentKill2,
	PlayerText:InnocentKill3,
	PlayerText:InnocentKill4,
	PlayerText:InnocentKill5,
	PlayerText:InnocentKill6,
	PlayerText:InnocentKill7,
	PlayerText:InnocentKill8,
	
	PlayerText:PlayerStats[25],
	PlayerText:BaE[7],
	PlayerText:robTD[4],
	PlayerText:objects[4],
	PlayerText:classSelect[8],
	PlayerText:dmArena[4],
	PlayerText:killStreak,
	PlayerText:Eggs[3],
	
	// 3D labels
	Text3D:playerAdminLabel,
	Text3D:spawnLabel,
	Text3D:weedLabel,
	Text3D:kidnappedLabel,
	
	// Anti-spam
	messageCount,
	spamCount,
	
	// Progress bars
	Bar:breakin,
	breakinProgress,
	breakinID,
	breakinCPID,
	breakinRenter,
	
	// New Robbery Bars
	Bar:robbery,
	Bar:xpBar,
	
	// Objects Loading
	Float:savedHealth,
	
	// Ask / Report
	canAsk,
	canReport,
	
	// Buy vehicles from players
	vSellPrice,
	skydiveTimer,
	vSellTo,
	vBuyFrom,
	vBuyPrice,
	vSellID,
	vBuyID,
	playerTown,
	toyStatus[MAX_OSLOTS],
	toyID[MAX_OSLOTS],
	toyBone[MAX_OSLOTS],
	Float:toyPosX[MAX_OSLOTS],
	Float:toyPosY[MAX_OSLOTS],
	Float:toyPosZ[MAX_OSLOTS],
	Float:toyRotX[MAX_OSLOTS],
	Float:toyRotY[MAX_OSLOTS],
	Float:toyRotZ[MAX_OSLOTS],
	Float:toyScaleX[MAX_OSLOTS],
	Float:toyScaleY[MAX_OSLOTS],
	Float:toyScaleZ[MAX_OSLOTS]
}

enum serverData
{
    doubleXP,
	bool:derbyEvent,
	enableMOTD,
	MOTD1[128],
	MOTD2[128],
	MOTD3[128],
	maxPing,
	jailblown,
	jailblown2,
	bankBlown,
	bankBlown2,
	bankGateBlown,
	bankVaultBlown,
	bankVaultBlown2,
	bankTime,
	testShow,
	moneybagid,
	kickWarp,
	glassEvent,
	VIPcount,
	countTimer,
	DMGateStatus,
	DMEvent,
	DMWeapon,
	eggHunt,
	huntOn,
	GlassEvent,
	rfAnticheat,
	abAnticheat,
	carAnticheat,
	cbAnticheat,
	flyAnticheat,
	serverTax,
	bool:falloutOpen,
	falloutTimer,
	falloutGlass[MAX_GLASS]
}

new serverInfo[serverData];
new playerData[MAX_PLAYERS][playerInformation];
new Text:TopTD[42];
