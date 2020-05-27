// Author :- Zap(Akshan Patel) and Wolverine aka Striker (Akshay Patel)
#include <a_samp>
#include <a_sampdb>
#include <mysql>
#include <a_http>
#include <required/crashdetect>
#include <streamer>
#include <progress>
#include <required/zcmd>
#include <required/sscanf2>
#include <required/explode>
#include <required/mSelection>
#include <required/fuckCleo>
#include <required/SII>
#include <required/formatex>
#include <required/uf>
#include <required/fixes>
#include <required/acuf>
#include <required/FloodControl>
#include <required/OPA>
#include <required/dldialog>
#include <required/line>

#include <cnr/cnr_defines>
#include <cnr/cnr_mysqlFunctions>
#include <required/cnr_mysqlresponse>
#include <cnr/cnr_robberyCheckpoints>
#include <cnr/cnr_anticheat>
#include <cnr/cnr_dynamiccps>
#include <cnr/cnr_textdraws>
#include <cnr/cnr_zones>
#include <cnr/cnr_functions>
#include <cnr/cnr_rappeling>
#include <cnr/cnr_houses>
#include <cnr/cnr_admincommands>
#include <cnr/cnr_policecommands>
#include <cnr/cnr_commands>
#include <cnr/cnr_jail>
// #include <cnr/cnr_businesses>
#include <cnr/cnr_animations>
#include <cnr/cnr_courier>
#include <cnr/cnr_gangs>
// #include <cnr/test>
#include <cnr/cnr_trucking>
#include <cnr/cnr_newMissions>
#include <cnr/cnr_toys>
#include <cnr/cnr_vehicles>
#include <cnr/cnr_dealership>
#include <cnr/vehicle_system>
#include <cnr/cnr_dialogresponse>
#include <cnr/cnr_explosives>
#include <cnr/cnr_moneybag>
#include <cnr/cnr_roadblocks>
#include <cnr/cnr_spike>
#include <cnr/cnr_gates>
#include <cnr/cnr_factionzones>
#include <cnr/cnr_dmevent>
#include <cnr/cnr_medic>
#include <cnr/cnr_glassevent>
#include <cnr/cnr_fallout>
#include <cnr/cnr_profiles>
#include <cnr/cnr_vehicleAC>
#pragma unused DMGate
#pragma unused pFPS
#pragma unused at
#pragma unused xmasDay

main()
{
	print("\n-----------------------------------");
	print("Cops and Robbers, by Zap(Akshan Patel) and Wolverine aka Striker (Akshay Patel)");
	print("Credits to Saest for bringing awesome CnR Gamemode!!");
	print("------------------------------------\n");
}

public OnGameModeInit()
{
    profileStuff();
	connection = mysql_init(LOG_ONLY_ERRORS, 1);
	
	//mysql_connect("localhost", "DB_USER", "DB_PASS", "DB_NAME", connection, 1);
 	mysql_connect("127.0.0.1", "akp","akp", "czcnr", connection, 1);

	// Databases
	//VEHICLEDB = db_open("dbs/Vehicles.db");
	HOUSEDB = db_open("dbs/Houses.db");
	GATESDB = db_open("dbs/Gates.db");
	VEHICLESDB = db_open("dbs/newvehicles.db");

	SetGameModeText("Cops and Robbers/DM");
	SendRconCommand("mapname San Fierro");

	// Skydive Pickup
	pickup_chute = CreatePickup(371, 1, -1813.0156, 576.6133, 234.8906, 0);
	
	// Secret Service Pickup
	pickup_ss = CreatePickup(371, 1, -1737.6863, 787.3431, 167.6535, 0);
	
	// VIP Health Pickup (for all VIPs)
	pickup_vhealth = CreatePickup(1240, 1, 1208.5283, -6.4214, 1001.3281, 80);
	pickup_vhealth2 = CreatePickup(1240, 1, 942.3300, 4.0157, 1000.9297, 81);

	// VIP Armour Pickup (for crim/top VIPs)
	pickup_varmour = CreatePickup(1242, 1, 1217.9944, -6.6420, 1001.3281, 80);
	pickup_varmour2 = CreatePickup(1242, 1, 938.5811, 4.0508, 1000.9297, 81);

	// Stop stunt rewards
	EnableStuntBonusForAll(0);

	// Use standard CJ anims
	UsePlayerPedAnims();

	// Disable the default interior yellow markers for enter/exit
	DisableInteriorEnterExits();

	// Place robbery checkpoints all around the map
	placeAllCheckpoints();
	loadMapIcons();

	// Place the class vehicles all around the map
	placeAllClassCars();
	placeExtraCars();

	// Add the custom objects
	addWorldObjects();

	// Textdraws
	buildTextDraws();

	// Houses
	load_houses();
	
	// Gates
	load_gates();

	// Businesses
	//	load_businesses();

	// Vehicles
	//load_oVehicles();
	Load_Vehicles();
	
	// Zones
	load_zones();

	// Flush gangs
	flushGangs();

	// Flush explosives
	flushExplosiveData();

	// Set server weather
	SetWeather(4);

	// Timers
	SetTimer("countMuteTime", 1000, true);
	SetTimer("countRobTime", 1000, true);
	SetTimer("highPing", 2000, true);
	SetTimer("armourCheck", 5000, true); // also caters for DM arena checks
	SetTimer("checkJetpack", 2000, true);
	SetTimer("gameTip", 600000, true);
	SetTimer("vipCheck", 300000, true);
	SetTimer("Zones_Update", 1000, true);
	SetTimer("classCheck", 10000, true);
	SetTimer("autoMoneyBag", 1200000, true);
	SetTimer("swapMOTD", 300000, true);

	for(new i = 0; i < MAX_PLAYERS; i++)
	{
		Zones[i] = TextDrawCreate(86.000000, 320.000000, "_");
		TextDrawBackgroundColor(Zones[i], 255);
		TextDrawFont(Zones[i], 1);
		TextDrawLetterSize(Zones[i], 0.300000, 1.200000);
		TextDrawColor(Zones[i], -1);
		TextDrawSetOutline(Zones[i], 0);
		TextDrawSetProportional(Zones[i], 1);
		TextDrawSetShadow(Zones[i], 1);
		TextDrawUseBox(Zones[i], 0);
		TextDrawAlignment(Zones[i], 2);
	}

	alog[1] = " ";
	alog[2] = " ";
	alog[3] = " ";
	alog[4] = " ";
	alog[5] = " ";
	
	new
		motd1[128] = "Welcome to CZCNR! Have fun!",
		motd2[128] = "If you need help use /ask!",
		motd3[128] = "Donate to the server and help us out! www.underprogress.ml"
	;
	
	serverInfo[MOTD1] = motd1;
	serverInfo[MOTD2] = motd2;
	serverInfo[MOTD3] = motd3;
	
	serverInfo[enableMOTD] = true;
	SetTimer("swapMOTD", 10000, false);

	drawGamemodeInitTextdraws();

	serverInfo[maxPing] = 1024;
	serverInfo[kickWarp] = 1;
	N11 = 11 * 60;
	gtime = N11 + 59;

	serverInfo[jailblown] = 0;
	serverInfo[jailblown2] = 0;
	serverInfo[moneybagid] = 1;
	serverInfo[rfAnticheat] = 1;
	serverInfo[abAnticheat] = 0;
	serverInfo[carAnticheat] = 0;
	serverInfo[cbAnticheat] = 0; // ANTICBUG DISABLED IF THIS IS SET TO 0
	
	// Set up several player classes
	AddPlayerClass(23, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);		// Class ID 	0	=	Civilian
	AddPlayerClass(119, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	1	=	Civilian
	AddPlayerClass(34, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	    // Class ID 	2	=	Civilian
	AddPlayerClass(191, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	3	=	Civilian
	AddPlayerClass(289, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	4	=	Civilian
	AddPlayerClass(13, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);		// Class ID 	5	=	Civilian
	AddPlayerClass(18, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);		// Class ID 	6	=	Civilian
	AddPlayerClass(45, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);		// Class ID 	7	=	Civilian
	AddPlayerClass(66, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);		// Class ID 	8	=	Civilian
	AddPlayerClass(106, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	9	=	Civilian
	AddPlayerClass(242, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	10	=	Civilian
	AddPlayerClass(261, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	11	=	Civilian
	AddPlayerClass(271, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	12	=	Civilian
	AddPlayerClass(293, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	13	=	Civilian
	AddPlayerClass(296, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	14	=	Civilian
	AddPlayerClass(12, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);		// Class ID 	15	=   Civilian
	AddPlayerClass(13, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);		// Class ID 	16	=   Civilian
	AddPlayerClass(31, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);		// Class ID 	17	=   Civilian
	AddPlayerClass(41, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);		// Class ID 	18	=   Civilian
	AddPlayerClass(92, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);		// Class ID 	19	=   Civilian
	AddPlayerClass(105, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	20	=   Civilian
	AddPlayerClass(106, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	21	=   Civilian
	AddPlayerClass(107, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	22	=   Civilian
	AddPlayerClass(108, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	23	=   Civilian
	AddPlayerClass(109, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	24	=   Civilian
	AddPlayerClass(110, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	25	=   Civilian
	AddPlayerClass(115, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	26	=   Civilian
	AddPlayerClass(130, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	27	=   Civilian
	AddPlayerClass(139, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	28	=   Civilian
	AddPlayerClass(195, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	29	=   Civilian
	AddPlayerClass(211, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	30	=   Civilian
	AddPlayerClass(216, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	31	=   Civilian
	AddPlayerClass(215, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	32	=   Civilian
	AddPlayerClass(219, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	33	=   Civilian
	AddPlayerClass(249, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	34	=   Civilian

    AddPlayerClass(267, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID     36	=	Police
    AddPlayerClass(266, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID     37	=	Police
    AddPlayerClass(265, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID     38	=	Police
	AddPlayerClass(281, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID     39	=	Police
	AddPlayerClass(280, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	40	=	Police
	AddPlayerClass(282, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	41	=	Police
	AddPlayerClass(283, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	42	=	Police
	AddPlayerClass(284, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	43	=	Police
    AddPlayerClass(93, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);		// Class ID 	44	=	Police

	AddPlayerClass(287, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	45	=   Army
	AddPlayerClass(191, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	46	=   Army

	AddPlayerClass(163, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	47	=   CIA
	AddPlayerClass(164, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	48	=   CIA
	AddPlayerClass(165, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	49	=   CIA
	AddPlayerClass(166, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	50	=   CIA

	AddPlayerClass(285, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	51	=   FBI
	AddPlayerClass(286, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	52	=   FBI

    AddPlayerClass(274, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	53	=   Medic
    AddPlayerClass(275, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	54	=   Medic
    AddPlayerClass(276, -1505.5410, 920.3940, 7.1875, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	55	=   Medic

	AddPlayerClass(165, -1763.6486, 795.1059, 167.6563, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	56	=   Secret Service
	AddPlayerClass(169, -1763.6486, 795.1059, 167.6563, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	57	=   Secret Service
	AddPlayerClass(227, -1763.6486, 795.1059, 167.6563, 90, 0, 0, 0, 0, 0, 0);	// Class ID 	58	=   Secret Service

	serverInfo[falloutOpen] = false;
	return 1;
}

public OnGameModeExit()
{
	mysql_close(connection);
    db_close(VEHICLESDB);
    db_close(HOUSEDB);
    
	return 1;
}

forward OnIncomingConnection( playerid, ip_address[ ], port );
public OnIncomingConnection( playerid, ip_address[ ], port ) {
    SendRconCommand( "reloadbans" );
}

public OnPlayerFloodControl(playerid, iCount, iTimeSpan) {
    if(iCount > 4 && iTimeSpan < 8000) {
        Ban(playerid);
    }
}

public OnPlayerRequestClass(playerid, classid)
{
	if (playerData[playerid][isInDM])
	{
		playerData[playerid][isInDM] = false;
		playerData[playerid][isInEvent] = false;

		for (new i=0; i<MAX_PLAYERS; i++)
		{
			if(playerData[i][isInDM])
			{
				new dmLeave[100];
				format(dmLeave, sizeof(dmLeave), "{FAAC58}%s(%i) {FFFFFF}left the arena.", playerData[playerid][playerNamee], playerid);
				SendClientMessage(i, COLOR_WHITE, dmLeave);
			}
		}
	}
	
	playerData[playerid][selectingClass] = true;
    TextDrawHideForPlayer(playerid, Text:URLTD);
    PlayerTextDrawSetString(playerid, playerData[playerid][wantedStars], " ");

	if(playerData[playerid][playerBanned] != 1)
	{

		ClearAnimations(playerid);
  		ApplyAnimation(playerid, "ROB_BANK", "CAT_Safe_Rob", 1, 1, 0, 0, 0, 0, 1);
		ApplyAnimation(playerid, "BOMBER", "BOM_PLANT_LOOP", 4.0, 1, 0, 0, 0, -1);
		ClearAnimations(playerid);
		
		switch(classid)
		{
		    // Civilian classes
		    case 0 .. 35:
		    {
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][2], "~w~Civilian Class");
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][3], "Cruise around San Fierro with your dick out, maybe.");
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][4], "Commit crimes to earn XP and rule the streets.");
    			PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][7], " ");
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][6], "0 XP REQUIRED");
				
				playerData[playerid][playerClass] = CLASS_CIVILIAN;
				SetPlayerColor(playerid, CLASS_CIVILIAN_COLOUR);

    			SetPlayerPos(playerid, -1940.6138,149.7429,41.0000);
				SetPlayerFacingAngle(playerid, 1.4989);
      			SetPlayerCameraPos(playerid, -1940.5756,154.3810,41.0000);
				SetPlayerCameraLookAt(playerid,  -1940.6138,149.7429,41.0000);
		    }

		    // Police classes
		    case 36 .. 44:
		    {
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][2], "Police Class");
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][3], "Bring criminals to justice using an array of tools.");
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][4], "Hunt down and arrest criminals for cash and XP.");
    			PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][7], " ");
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][6], "0 XP REQUIRED");
				
				playerData[playerid][playerClass] = CLASS_POLICE;
				SetPlayerColor(playerid, CLASS_POLICE_COLOUR);

            	SetPlayerPos(playerid, -1587.0164, 721.8500, -4.9063);
				SetPlayerFacingAngle(playerid, 239.8802);
				SetPlayerCameraPos(playerid, -1581.4075, 718.5963, -5.2422);
				SetPlayerCameraLookAt(playerid, -1587.0164, 721.8500, -4.9063);
		    }

			// Army class
		    case 45, 46:
		    {
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][2], "~p~Army Class");
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][3], "Don't feel man enough? Join the Army!");
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][4], "Access powerful weaponry & machinery");
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][7], "to kill those criminal bastards.");
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][6], "20,000 XP REQUIRED");

				playerData[playerid][playerClass] = CLASS_ARMY;
				SetPlayerColor(playerid, CLASS_ARMY_COLOUR);

            	SetPlayerPos(playerid, -1403.1262, 490.1483, 18.2294);
				SetPlayerFacingAngle(playerid, 77.3216);
				SetPlayerCameraPos(playerid, -1408.0873, 491.7008, 18.2294);
				SetPlayerCameraLookAt(playerid, -1403.1262, 490.1483, 18.2294);
			}

			// CIA class
		    case 47 .. 50:
		    {
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][2], "Central Intelligence Agency");
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][3], "Bring criminals to justice using an array of tools.");
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][4], "Gain the ability to locate and EMP criminals.");
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][7], " ");
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][6], "10,000 XP REQUIRED");
				
				playerData[playerid][playerClass] = CLASS_CIA;
				SetPlayerColor(playerid, CLASS_CIA_COLOUR);

          		SetPlayerPos(playerid, -2439.5608, 503.9104, 29.9403);
				SetPlayerFacingAngle(playerid, 108.6551);
				SetPlayerCameraPos(playerid, -2445.3594, 501.9529, 30.0897);
				SetPlayerCameraLookAt(playerid, -2439.5608, 503.9104, 29.9403);
			}

			// FBI class
		    case 51, 52:
		    {
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][2], "Federal Bureau of Investigation");
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][3], "Bring criminals to justice using an array of tools.");
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][4], "Gain the ability to force entry to any property that");
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][7], "isn't highly secure.");
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][6], "5,000 XP REQUIRED");
				
				playerData[playerid][playerClass] = CLASS_FBI;
				SetPlayerColor(playerid, CLASS_FBI_COLOUR);

            	SetPlayerPos(playerid, -2439.5608, 503.9104, 29.9403);
				SetPlayerFacingAngle(playerid, 108.6551);
				SetPlayerCameraPos(playerid, -2445.3594, 501.9529, 30.0897);
				SetPlayerCameraLookAt(playerid, -2439.5608, 503.9104, 29.9403);
			}

			// Medic class
		    case 53 .. 55:
		    {
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][2], "~p~Medic Class");
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][3], "Heal player injuries or cure their STDs");
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][4], "for cash and XP.");
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][7], " ");
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][6], "0 XP REQUIRED");
				
				SetPlayerColor(playerid, CLASS_MEDIC_COLOUR);
				playerData[playerid][playerClass] = CLASS_MEDIC;

            	SetPlayerPos(playerid, -2644.3481, 618.6160, 14.4531);
				SetPlayerFacingAngle(playerid, 236.1596);
				SetPlayerCameraPos(playerid, -2637.7776, 614.2100, 14.453);
				SetPlayerCameraLookAt(playerid, -2644.3481, 618.6160, 14.4531);
			}

			// Secret Service Class
		    case 56 .. 58:
		    {
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][2], "San Fierro Secret Service");
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][3], "Bring criminals to justice using an array of tools.");
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][4], "Become incognito and hide in the shadows.");
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][7], " ");
				PlayerTextDrawSetString(playerid, playerData[playerid][classSelect][6], "VIP MEMBERSHIP REQUIRED");
				
				SetPlayerColor(playerid, CLASS_SECRETSERVICE_COLOUR);
				playerData[playerid][playerClass] = CLASS_SECRETSERVICE;

          		SetPlayerPos(playerid, -1763.6486, 795.1059, 167.6563);
				SetPlayerFacingAngle(playerid, 37.2926);
				SetPlayerCameraPos(playerid, -1767.7225, 800.5792, 167.6563);
				SetPlayerCameraLookAt(playerid, -1763.6486, 795.1059, 167.6563);
				
			}
		}
 	}
 	PlayerTextDrawShow(playerid, playerData[playerid][classSelect][1]);
	PlayerTextDrawShow(playerid, playerData[playerid][classSelect][2]);
	PlayerTextDrawShow(playerid, playerData[playerid][classSelect][3]);
	PlayerTextDrawShow(playerid, playerData[playerid][classSelect][4]);
	PlayerTextDrawShow(playerid, playerData[playerid][classSelect][6]);
	PlayerTextDrawShow(playerid, playerData[playerid][classSelect][7]);

	return 1;
}

public OnPlayerConnect(playerid)
{
	for(new x = 0; x < MAX_OSLOTS; x++)
	{
		playerData[playerid][toyStatus][x] = false;
		if(IsPlayerAttachedObjectSlotUsed(playerid, x))
		{
			RemovePlayerAttachedObject(playerid, x);
		}
	}
	new namez[MAX_PLAYER_NAME];
	GetPlayerName(playerid, namez, MAX_PLAYER_NAME);
	if(FindIP(namez))
	{
	    Kick(playerid);
	    return 1;
	}
	for(new xxx = 0; xxx < 100; xxx++)
		SendClientMessage(playerid, -1, " ");
	SendClientMessage(playerid, -1, "Welcome to {061F72}CZCNR {FFFFFF}, {F07E21}Enjoy Your Stay, {9E1FF2}Have FUN!");
	
    ac_OnPlayerConnect(playerid);
    
	PreloadAnimLib(playerid,"BOMBER");
	PreloadAnimLib(playerid,"RAPPING");
    PreloadAnimLib(playerid,"SHOP");
	PreloadAnimLib(playerid,"BEACH");
    PreloadAnimLib(playerid,"SMOKING");
	PreloadAnimLib(playerid,"FOOD");
    PreloadAnimLib(playerid,"ON_LOOKERS");
	PreloadAnimLib(playerid,"DEALER");
    PreloadAnimLib(playerid,"CRACK");
	PreloadAnimLib(playerid,"CARRY");
    PreloadAnimLib(playerid,"COP_AMBIENT");
	PreloadAnimLib(playerid,"PARK");
    PreloadAnimLib(playerid,"INT_HOUSE");
	PreloadAnimLib(playerid,"PED");
    PreloadAnimLib(playerid,"MISC");
	PreloadAnimLib(playerid,"OTB");
    PreloadAnimLib(playerid,"BD_Fire");
	PreloadAnimLib(playerid,"BENCHPRESS");
    PreloadAnimLib(playerid,"KISSING");
	PreloadAnimLib(playerid,"BSKTBALL");
    PreloadAnimLib(playerid,"MEDIC");
	PreloadAnimLib(playerid,"SWORD");
    PreloadAnimLib(playerid,"POLICE");
	PreloadAnimLib(playerid,"SUNBATHE");
    PreloadAnimLib(playerid,"FAT");
	PreloadAnimLib(playerid,"WUZI");
    PreloadAnimLib(playerid,"SWEET");
	PreloadAnimLib(playerid,"ROB_BANK");
    PreloadAnimLib(playerid,"GANGS");
	PreloadAnimLib(playerid,"RIOT");
    PreloadAnimLib(playerid,"GYMNASIUM");
	PreloadAnimLib(playerid,"CAR");
    PreloadAnimLib(playerid,"CAR_CHAT");
	PreloadAnimLib(playerid,"GRAVEYARD");
    PreloadAnimLib(playerid,"POOL");
    
	for(new i= 0; i < 47; i++)
	{
		PlayerWeapons[playerid][i] = false;
	}

    SetPlayerColor(playerid, 0xFFFFFFFF);
 	ApplyAnimation(playerid, "ROB_BANK", "CAT_Safe_Rob", 1, 1, 0, 0, 0, 0, 1);
	ClearAnimations(playerid);
	TogglePlayerSpectating(playerid, true);
	ResetPlayerWeapons(playerid);

	// Setup local variables
    new query[200], ban_query[200], playerName[24], playersName[24], playersIP[16];
    GetPlayerName(playerid, playerName, 24);

	format(query, sizeof(query), "SELECT `playerName` FROM `playerdata` WHERE playerName = '%s' LIMIT 1", playerName);
    mysql_query(query, MYSQL_RESULT_CHECK, playerid, connection);

	GetPlayerName(playerid, playersName, sizeof(playersName));
	GetPlayerIp(playerid, playersIP, sizeof(playersIP));

	// Ban-checking system
	format(ban_query, sizeof(ban_query), "SELECT * FROM `playerbans` WHERE `player_banned` = '%s' OR `player_ip` = '%s' LIMIT 1", playersName, playersIP);
    mysql_query(ban_query, MYSQL_QUERY_BANNED, playerid, connection);

	clearWorldObjects(playerid);
	// loadMapIcons(playerid);

	playerData[playerid][CheckSpeed] = SetTimerEx("speedCheck", 2000, true, "i", playerid);
	
	/****************************************************************************
	// remove boject for fun park
    RemoveBuildingForPlayer(playerid, 705, -2351.5625, 244.2109, 34.2969, 0.25);
    RemoveBuildingForPlayer(playerid, 708, -2362.1328, 166.4688, 34.6328, 0.25);
    RemoveBuildingForPlayer(playerid, 705, -2322.8594, 266.7813, 30.0000, 0.25);
    RemoveBuildingForPlayer(playerid, 705, -2315.7344, 296.1406, 34.5938, 0.25);
    RemoveBuildingForPlayer(playerid, 708, -2273.2656, 282.6406, 34.6328, 0.25);
    RemoveBuildingForPlayer(playerid, 708, -2305.5234, 241.9375, 34.6328, 0.25);
    RemoveBuildingForPlayer(playerid, 1412, -2314.6094, 214.3828, 35.5859, 0.25);
    RemoveBuildingForPlayer(playerid, 1412, -2319.9297, 214.3828, 35.5859, 0.25);
    RemoveBuildingForPlayer(playerid, 1412, -2325.2422, 214.3828, 35.5859, 0.25);
    RemoveBuildingForPlayer(playerid, 3819, -2333.3594, 222.3750, 35.3125, 0.25);
    RemoveBuildingForPlayer(playerid, 672, -2330.0703, 238.7656, 35.2344, 0.25);
    RemoveBuildingForPlayer(playerid, 672, -2342.6563, 272.9453, 34.8047, 0.25);
    RemoveBuildingForPlayer(playerid, 9808, -2678.7422, 811.5781, 49.2969, 0.25);
    RemoveBuildingForPlayer(playerid, 9734, -2678.7422, 811.5781, 49.2969, 0.25);
    
    //remove for cz base
    RemoveBuildingForPlayer(playerid, 1341, -2384.4077, -584.46405, 131.89117, 0.25);
	RemoveBuildingForPlayer(playerid, 10675, -2529.1875, -705.03906, 141.57031, 0.25);
	RemoveBuildingForPlayer(playerid, 1595, -2538.9297, -648.64062, 152.21875, 0.25);
	RemoveBuildingForPlayer(playerid, 1595, -2538.9297, -660.90625, 152.21875, 0.25);
	RemoveBuildingForPlayer(playerid, 1596, -2517.5937, -671.00781, 149.46094, 0.25);
	RemoveBuildingForPlayer(playerid, 1695, -2529.6641, -643.32812, 147.52344, 0.25);
	RemoveBuildingForPlayer(playerid, 1695, -2529.6641, -652.64844, 147.52344, 0.25);
	RemoveBuildingForPlayer(playerid, 1695, -2529.6641, -661.97656, 147.52344, 0.25);
	RemoveBuildingForPlayer(playerid, 1695, -2529.6641, -671.30469, 147.52344, 0.25);
	RemoveBuildingForPlayer(playerid, 1695, -2529.6641, -634, 147.52344, 0.25);
	RemoveBuildingForPlayer(playerid, 1694, -2518.4297, -632.19531, 155.67188, 0.25);
    
    //new
    RemoveBuildingForPlayer(playerid, 3865, -2063.2422, 258.7500, 35.7422, 0.25);
	RemoveBuildingForPlayer(playerid, 3869, -2123.2891, 269.5313, 41.8516, 0.25);
	RemoveBuildingForPlayer(playerid, 3869, -2126.2109, 231.9766, 41.6875, 0.25);
	RemoveBuildingForPlayer(playerid, 3869, -2116.6797, 131.0078, 42.1484, 0.25);
	RemoveBuildingForPlayer(playerid, 3865, -2063.0156, 247.9453, 35.7422, 0.25);
	RemoveBuildingForPlayer(playerid, 3865, -2057.7500, 249.9531, 35.5938, 0.25);
	RemoveBuildingForPlayer(playerid, 3865, -2057.7031, 229.8047, 35.3516, 0.25);
	RemoveBuildingForPlayer(playerid, 3865, -2059.5313, 256.5234, 37.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 11372, -2076.4375, -107.9297, 36.9688, 0.25);
	RemoveBuildingForPlayer(playerid, 3888, -2128.1797, 171.4609, 42.4297, 0.25);
	RemoveBuildingForPlayer(playerid, 3888, -2066.3594, 301.9141, 42.1719, 0.25);
	RemoveBuildingForPlayer(playerid, 3887, -2066.3594, 301.9141, 42.1719, 0.25);
	RemoveBuildingForPlayer(playerid, 792, -2056.6094, 326.6094, 34.2734, 0.25);
	RemoveBuildingForPlayer(playerid, 792, -2036.4844, 460.5078, 34.2734, 0.25);
	RemoveBuildingForPlayer(playerid, 11099, -2056.9922, -184.5469, 34.4141, 0.25);
	RemoveBuildingForPlayer(playerid, 11014, -2076.4375, -107.9297, 36.9688, 0.25);
	RemoveBuildingForPlayer(playerid, 3887, -2128.1797, 171.4609, 42.4297, 0.25);
	RemoveBuildingForPlayer(playerid, 3866, -2116.6797, 131.0078, 42.1484, 0.25);
	RemoveBuildingForPlayer(playerid, 3864, -2082.5391, 153.5469, 40.1016, 0.25);
	RemoveBuildingForPlayer(playerid, 3872, -2079.8203, 159.6719, 40.8906, 0.25);
	RemoveBuildingForPlayer(playerid, 3864, -2111.8828, 172.4688, 40.1953, 0.25);
	RemoveBuildingForPlayer(playerid, 3872, -2116.7500, 177.0781, 40.9844, 0.25);
	RemoveBuildingForPlayer(playerid, 3872, -2064.2109, 210.1406, 41.2578, 0.25);
	RemoveBuildingForPlayer(playerid, 3872, -2107.0313, 226.0391, 40.8438, 0.25);
	RemoveBuildingForPlayer(playerid, 10984, -2126.1563, 238.6172, 35.2656, 0.25);
	RemoveBuildingForPlayer(playerid, 3864, -2102.2109, 230.7031, 40.0547, 0.25);
	RemoveBuildingForPlayer(playerid, 3866, -2126.2109, 231.9766, 41.6875, 0.25);
	RemoveBuildingForPlayer(playerid, 10986, -2130.0547, 275.5625, 35.3750, 0.25);
	RemoveBuildingForPlayer(playerid, 10987, -2137.8203, 264.2813, 35.7813, 0.25);
	RemoveBuildingForPlayer(playerid, 3866, -2123.2891, 269.5313, 41.8516, 0.25);
	RemoveBuildingForPlayer(playerid, 3864, -2113.3125, 268.5078, 40.5703, 0.25);
	RemoveBuildingForPlayer(playerid, 3872, -2118.1328, 263.8438, 41.3594, 0.25);
	RemoveBuildingForPlayer(playerid, 10985, -2099.2734, 292.9141, 35.0703, 0.25);
	RemoveBuildingForPlayer(playerid, 3864, -2059.3438, 205.5313, 40.4688, 0.25);
	RemoveBuildingForPlayer(playerid, 3872, -2048.4531, 265.0938, 41.6563, 0.25);
	RemoveBuildingForPlayer(playerid, 3864, -2041.7500, 265.1016, 40.8672, 0.25);
	RemoveBuildingForPlayer(playerid, 733, -2027.0313, 609.2109, 36.8984, 0.25);
    
    //remove for admin house
    RemoveBuildingForPlayer(playerid, 11372, -2076.4375, -107.9297, 36.9688, 0.25);
	RemoveBuildingForPlayer(playerid, 11014, -2076.4375, -107.9297, 36.9688, 0.25);
    
    //santa flora
    RemoveBuildingForPlayer(playerid, 9682, -2554.7031, 616.3203, 13.4688, 0.25);
    RemoveBuildingForPlayer(playerid, 3805, -2599.3594, 616.3828, 18.5703, 0.25);
    playerData[playerid][isInDuel] = false;
    *******************************************************************************/

	// Easter
	//TextDrawHideForPlayer(playerid, easterSunday);
	
	// Rapid fire
	playerData[playerid][shotTime] = 0;
 	playerData[playerid][shot] = 0;
 	playerData[playerid][shotWarnings] = 0;

	// Car warp
	playerData[playerid][ctpImmune] = true;
	playerData[playerid][abImmune] = true;
	
	Rappel[playerid] = 0;
    IsRappelling[playerid] = 0;
    
	return 1;
}

public OnPlayerDisconnect(playerid, reason) //can use 1? check again
{
	new namez[MAX_PLAYER_NAME];
	if(IsValidLineSegment(Rope[playerid])) DestroyLineSegment(Rope[playerid]);
    Rappel[playerid] = 0;
    IsRappelling[playerid] = 0;
    KillTimer(LandingChecker[playerid]);
	KillTimer(playerData[playerid][skydiveTimer]);
    GetPlayerName(playerid, namez, MAX_PLAYER_NAME);
	if(FindIP(namez))
	{
	    return 1;
	}
    SetPlayerColor(playerid, 0xFFFFFFFF);
	if(playerData[playerid][playerLoggedIn])
    {
        savePlayerStats(playerid);
    }

	if(reason == 1) // Manual game-quit.
	{
		new administratorAlert[128];

		if(playerData[playerid][playerIsTazed])
		{
			format(administratorAlert, sizeof(administratorAlert), "{C73E3E}[AVOID-DETECTION] {FFFFFF}%s(%i) quit the game while tazed.", playerData[playerid][playerNamee], playerid);
			adminchat(COLOR_WHITE, administratorAlert);
		}
		else if(playerData[playerid][playerIsCuffed])
		{
			format(administratorAlert, sizeof(administratorAlert), "{C73E3E}[AVOID-DETECTION] {FFFFFF}%s(%i) quit the game while cuffed.", playerData[playerid][playerNamee], playerid);
			adminchat(COLOR_WHITE, administratorAlert);
		}
		else if(playerData[playerid][playerIsTied])
		{
			format(administratorAlert, sizeof(administratorAlert), "{C73E3E}[AVOID-DETECTION] {FFFFFF}%s(%i) quit the game while tied.", playerData[playerid][playerNamee], playerid);
			adminchat(COLOR_WHITE, administratorAlert);
		}
	}

	if(playerData[playerid][playerGangID] != INVALID_GANG_ID)
	{
		cmd_g(playerid, "leave");
	}

	ClearStats(playerid);
	removePlayerRoadblocks(playerid);
	destroyPlayersExplosives(playerid);

	// Delete labels
	Delete3DTextLabel(playerData[playerid][playerAdminLabel]);

	// Destroy timers
	KillTimer(playerData[playerid][unfreezeTimer]);
	KillTimer(playerData[playerid][arrestTimer]);
	KillTimer(playerData[playerid][untieTimer]);
	KillTimer(playerData[playerid][uncuffTimer]);
	KillTimer(playerData[playerid][recuffTimer]);
	KillTimer(playerData[playerid][retazeTimer]);
	KillTimer(playerData[playerid][fixTimer]);
	KillTimer(playerData[playerid][nosTimer]);
	KillTimer(playerData[playerid][mechREMPTimer]);
	KillTimer(playerData[playerid][reactivateRapeStatus]);
	KillTimer(playerData[playerid][reactivateRobStatus]);
	KillTimer(playerData[playerid][hcpTimer]);
	KillTimer(playerData[playerid][courierTimer]);
	KillTimer(playerData[playerid][playerCanKidnap]);
	KillTimer(playerData[playerid][rapedTimer]);
	KillTimer(playerData[playerid][jailTimer]);
	KillTimer(playerData[playerid][spawnPlayerTimer]);
	KillTimer(playerData[playerid][truckExitTimer]);
	KillTimer(playerData[playerid][breakCuffsTimer]);
	KillTimer(playerData[playerid][achieveTimer]);
	KillTimer(playerData[playerid][spamTimer]);
	KillTimer(playerData[playerid][CheckSpeed]);
	KillTimer(playerData[playerid][retruckTimer]);
	KillTimer(playerData[playerid][saveStatsTimer]);
	KillTimer(playerData[playerid][rehealTimer]);
	KillTimer(playerData[playerid][recureTimer]);
	KillTimer(playerData[playerid][breakinTimer]);
	KillTimer(playerData[playerid][houseTimer]);
	
	playerData[playerid][shotTime] = 0;
 	playerData[playerid][shot] = 0;
 	playerData[playerid][shotWarnings] = 0;

	// Reset weapons for next player
	ResetPlayerWeapons(playerid);
    SendDeathMessage(INVALID_PLAYER_ID, playerid, 201);
    
    // Vehicles
 	/*for(new v = 0; v < MAX_SCRIPT_VEHICLES; v++)
	{
		if (oVehicle[v][vehicle_id] != -1)
		{
			if(!strcmp(oVehicle[v][vehicle_owner], playerData[playerid][playerNamee], true))
			{
				DestroyVehicle(oVehicle[v][vehicle_sid]);
			}
		}
	}*/
	
	for(new i; i < MAX_SAVED_VEHICLES; i++)
	{
	    if(VehicleInfo[i][vOwner] != playerData[playerid][actualID]) continue;
	    DestroyVehicle(VehicleInfo[i][vehicleID]);
	    VehicleInfo[i][vehicleID] = INVALID_VEHICLE_ID;
	}

	return 1;
}

public OnPlayerAirbreak(playerid)
{
	ac_AirBrake(playerid);
    return 1;
}

public OnVehicleSpawn(vehicleid)
{
	if (!vWarped[vehicleid][Spawned])
	{
		new Float: oldPos[4];

		GetVehiclePos(vehicleid, oldPos[0], oldPos[1], oldPos[2]);
		GetVehicleZAngle(vehicleid, oldPos[3]);

	    vWarped[vehicleid][theVehicle] = vehicleid;
		vWarped[vehicleid][vehiclePositionX] = oldPos[0];
		vWarped[vehicleid][vehiclePositionY] = oldPos[1];
		vWarped[vehicleid][vehiclePositionZ] = oldPos[2];
		vWarped[vehicleid][vehiclePositionA] = oldPos[3];

	 	vWarped[vehicleid][Spawned] = true;
 	}

	vWarped[vehicleid][Spawning] = false; //try
	vWarped[vehicleid][wasOccupied] = false;
	/*if(IsValidDynamicObject(VehicleInfo[vehicleID][neon][1]))
	{
		DestroyDynamicObject(VehicleInfo[vehicleID][neon][1]);
		DestroyDynamicObject(VehicleInfo[vehicleID][neon][2]);
	}*/
	for(new i; i < MAX_SAVED_VEHICLES; i++)
	{
		if (vehicleid != VehicleInfo[i][vehicleID]) continue;

		ModVehicle(VehicleInfo[i][vehicleID]);
		ChangeVehiclePaintjob(VehicleInfo[i][vehicleID], VehicleInfo[i][vPaintjob]);
		
		print("Modded");

		break;
	}
	
    return 1;
}

public OnPlayerWeaponShot( playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ )
{
    if( hittype == BULLET_HIT_TYPE_PLAYER ) // Bullet Crashing uses just this hittype
	{
        if( !( -20.0 <= fX <= 20.0 ) || !( -20.0 <= fY <= 20.0 ) || !( -20.0 <= fZ <= 20.0 ) ) // a valid offset, it's impossible that a offset bigger than 20 is legit (less than 0 is impossible, but still, let's check for it, just for the future)
		{
		    new administratorAlert[256];
			format(administratorAlert, sizeof(administratorAlert), "{C73E3E}[BULLET-CRASHER] {FFFFFF}%s(%i) trying to use bullet crasher.", playerData[playerid][playerNamee], playerid);
			adminchat(COLOR_WHITE, administratorAlert);
			return 0; // let's desynchronize that bullet, so players won't crash
		}
	}
    return 1;
}

public OnPlayerRequestSpawn(playerid)
{
	if(!playerData[playerid][playerLoggedIn])
	{
        SendClientMessage(playerid, COLOR_RED, "{B7B7B7}[SERVER] {FFFFFF}You must login before spawning!");
		return 0;
	}

	switch(playerData[playerid][playerClass])
	{
  		case CLASS_POLICE:
    	{
      		/*if (playerData[playerid][playerXP] < 0)
      		{
		        SendClientMessage(playerid, COLOR_RED, "{B7B7B7}[SERVER] {FFFFFF}You must have 50 XP to join this class.");
			    return 0;
      		}*/
			if (playerData[playerid][playerWantedLevel] >= 1)
			{
		        SendClientMessage(playerid, COLOR_RED, "{B7B7B7}[SERVER] {FFFFFF}You cannot spawn as a LEO with a civilian wanted level!");
			    return 0;
			}
			if (playerData[playerid][playerCopBanned] == 1)
			{
		        SendClientMessage(playerid, COLOR_RED, "{B7B7B7}[SERVER] {FFFFFF}You are cop banned!");
			    return 0;
			}
		}

  		case CLASS_ARMY:
    	{
    	    if (playerData[playerid][playerXP] < 20000)
    	    {
		        SendClientMessage(playerid, COLOR_RED, "{B7B7B7}[SERVER] {FFFFFF}You must have 20,000 XP to join this class.");
			    return 0;
			}
			if (playerData[playerid][playerWantedLevel] >= 1)
			{
		        SendClientMessage(playerid, COLOR_RED, "{B7B7B7}[SERVER] {FFFFFF}You cannot spawn as a LEO with a civilian wanted level!");
			    return 0;
			}
			if (playerData[playerid][playerArmyBanned] == 1)
			{
		        SendClientMessage(playerid, COLOR_RED, "{B7B7B7}[SERVER] {FFFFFF}You are army banned!");
			    return 0;
			}
		}

  		case CLASS_CIA:
    	{
    	    if (playerData[playerid][playerXP] < 10000)
    	    {
		        SendClientMessage(playerid, COLOR_RED, "{B7B7B7}[SERVER] {FFFFFF}You must have 10,000 XP to join this class.");
			    return 0;
			}
			if (playerData[playerid][playerWantedLevel] >= 1)
			{
		        SendClientMessage(playerid, COLOR_RED, "{B7B7B7}[SERVER] {FFFFFF}You cannot spawn as a LEO with a civilian wanted level!");
			    return 0;
			}
			if (playerData[playerid][playerCopBanned] == 1)
			{
		        SendClientMessage(playerid, COLOR_RED, "{B7B7B7}[SERVER] {FFFFFF}You are cop banned!");
			    return 0;
			}
		}

  		case CLASS_FBI:
    	{
    	    if (playerData[playerid][playerXP] < 5000)
    	    {
		        SendClientMessage(playerid, COLOR_RED, "{B7B7B7}[SERVER] {FFFFFF}You must have 5,000 XP to join this class.");
			    return 0;
			}
			if (playerData[playerid][playerWantedLevel] >= 1)
			{
		        SendClientMessage(playerid, COLOR_RED, "{B7B7B7}[SERVER] {FFFFFF}You cannot spawn as a LEO with a civilian wanted level!");
			    return 0;
			}
			if (playerData[playerid][playerCopBanned] == 1)
			{
		        SendClientMessage(playerid, COLOR_RED, "{B7B7B7}[SERVER] {FFFFFF}You are cop banned!");
			    return 0;
			}
		}
		
  		case CLASS_SECRETSERVICE:
    	{
    	    if (playerData[playerid][playerVIPLevel] < 1)
    	    {
		        SendClientMessage(playerid, COLOR_RED, "{B7B7B7}[SERVER] {FFFFFF}You must be a VIP to join this class.");
			    return 0;
			}
			if (playerData[playerid][playerWantedLevel] >= 1)
			{
		        SendClientMessage(playerid, COLOR_RED, "{B7B7B7}[SERVER] {FFFFFF}You cannot spawn as a LEO with a civilian wanted level!");
			    return 0;
			}
			if (playerData[playerid][playerCopBanned] == 1)
			{
		        SendClientMessage(playerid, COLOR_RED, "{B7B7B7}[SERVER] {FFFFFF}You are cop banned!");
			    return 0;
			}
		}
	}

	return 1;
}

public OnPlayerSpawn(playerid)
{
	KillTimer(playerData[playerid][skydiveTimer]);
	/*if(playerData[playerid][playerTown] == NO_TOWN)
	{
		ShowPlayerDialog(playerid, DIALOG_TOWN, DIALOG_STYLE_LIST, "Choose Spawn Town", "San Fierro \nLas Venturas", "Choose", "");
		TogglePlayerSpectating(playerid, true);
		return 1;
	}*/

	playerData[playerid][playerTown] = SF;
	for(new x = 0; x < MAX_OSLOTS; x++)
	{
		if(playerData[playerid][toyStatus][x])
		{
			if(!IsPlayerAttachedObjectSlotUsed(playerid, x))
			{
				SetPlayerAttachedObject(playerid, x, playerData[playerid][toyID][x], playerData[playerid][toyBone][x], playerData[playerid][toyPosX][x], playerData[playerid][toyPosY][x], playerData[playerid][toyPosZ][x], playerData[playerid][toyRotX][x], playerData[playerid][toyRotY][x], playerData[playerid][toyRotZ][x], playerData[playerid][toyScaleX][x], playerData[playerid][toyScaleY][x], playerData[playerid][toyScaleZ][x]);
			}
		}
	}
	
	TextDrawHideForPlayer(playerid, vSpawns[0]);
	TextDrawHideForPlayer(playerid, vSpawns[1]);
	
	// Car teleport
	playerData[playerid][ctpImmune] = true;
	playerData[playerid][abImmune] = true;
	
	// Mask
	playerData[playerid][mask] = false;
	
	// Apply custom skin
    if (playerData[playerid][playerCustomSkin] != -1)
    {
        SetPlayerSkin(playerid, playerData[playerid][playerCustomSkin]);
	}
	
	if (playerData[playerid][hasBackpack])
	{
	    SetPlayerAttachedObject( playerid, 9, 371, 1, 0.048503, -0.112052, -0.021527, 356.659484, 85.123565, 0.000000, 0.919283, 1.000000, 1.000000 ); // gun_para - aest 44
	}
	
	if (playerData[playerid][hasParrot])
	{
	    SetPlayerAttachedObject( playerid, 8, 19078, 3, -0.025633, 0.071474, -0.042353, 152.483703, 170.041259, 353.874603, 1.000000, 1.000000, 1.000000 ); // TheParrot1 - aest 5
	}
	
	TextDrawHideForPlayer(playerid, bankTD);
	PlayerTextDrawHide(playerid, playerData[playerid][classSelect][0]);
	PlayerTextDrawHide(playerid, playerData[playerid][classSelect][1]);
	PlayerTextDrawHide(playerid, playerData[playerid][classSelect][2]);
	PlayerTextDrawHide(playerid, playerData[playerid][classSelect][3]);
	PlayerTextDrawHide(playerid, playerData[playerid][classSelect][4]);
	PlayerTextDrawHide(playerid, playerData[playerid][classSelect][5]);
	PlayerTextDrawHide(playerid, playerData[playerid][classSelect][6]);
	PlayerTextDrawHide(playerid, playerData[playerid][classSelect][7]);
	
	TextDrawHideForPlayer(playerid, dmBox[0]);
	TextDrawHideForPlayer(playerid, dmBox[1]);
	TextDrawHideForPlayer(playerid, dmBox[2]);
	TextDrawHideForPlayer(playerid, dmBox[3]);
	TextDrawHideForPlayer(playerid, dmBox[4]);
	TextDrawHideForPlayer(playerid, dmBox[5]);
	TextDrawHideForPlayer(playerid, dmBox[6]);
	
	PlayerTextDrawHide(playerid, playerData[playerid][dmArena][0]);
	PlayerTextDrawHide(playerid, playerData[playerid][dmArena][1]);
	PlayerTextDrawHide(playerid, playerData[playerid][dmArena][2]);
	PlayerTextDrawHide(playerid, playerData[playerid][dmArena][3]);

	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerIsSpectating] || playerData[playerid][isInDuel] || playerData[playerid][isInFallout])
		{
			// Fix for weapons with unlimited ammo not working correctly after specoff
		    ResetPlayerWeapons(playerid);
		    
			for (new i = 0; i < 13; i++)
			{
				if(playerData[playerid][previousWeapons][i])
				{
					GivePlayerWeaponEx(playerid, playerData[playerid][previousWeapons][i], playerData[playerid][previousAmmoLots][i]);
				}
			}

			SetPlayerVirtualWorld(playerid, playerData[playerid][previousVirtualWorld]);
			SetPlayerInterior(playerid, playerData[playerid][previousInteriorWorld]);

			SetPlayerPos(playerid, playerData[playerid][previousX], playerData[playerid][previousY], playerData[playerid][previousZ]);

			SetPlayerHealth(playerid, playerData[playerid][previousHealth]);
			SetPlayerArmour(playerid, playerData[playerid][previousArmour]);

			// Disable admin duty
			if(playerData[playerid][playerAdminDuty])
			{
			    SendClientMessage(playerid, COLOR_WHITE, "{07E08D}[ADMIN] {FFFFFF}You're now an off duty administrator.");
				playerData[playerid][playerAdminDuty] = false;
				SetPlayerHealth(playerid, 100);
				newPlayerColour(playerid);
				TextDrawHideForPlayer(playerid, Text:AdminDuty);
				Delete3DTextLabel(playerData[playerid][playerAdminLabel]);
			}
            playerData[playerid][isInDuel] = false;
			playerData[playerid][playerIsSpectating] = false;
			playerData[playerid][isInFallout] = false;
			playerData[playerid][isInEvent] = false;
		}
		else
		{
		    if (!playerData[playerid][hasSpawned])
		    {
		        if (!playerData[playerid][isInDM])
		        {
					// Reset some vars
					playerData[playerid][hasSpawned] = true;
			        SetPlayerVirtualWorld(playerid, 0);
					SetPlayerInterior(playerid, 0);
					ResetPlayerWeapons(playerid);
					SetPlayerHealth(playerid, 100.0);
					playerData[playerid][playerLastTicket] = -1;
					playerData[playerid][pEnterHouse] = true;
					playerData[playerid][pEnterBusiness] = true;
					playerData[playerid][selectingClass] = false;
			        playerData[playerid][canUseCommands] = true;
					playerData[playerid][canBreakCuffs] = true;
					playerData[playerid][adminWeapon] = false;
					playerData[playerid][playerIsCuffed] = false;
					playerData[playerid][canBreakIn] = true;
					playerData[playerid][isInEvent] = false;

					// Show textdraws
					TextDrawShowForPlayer(playerid, Text:URLTD);
					TextDrawShowForPlayer(playerid, Text:MOTDTD);

					// Untie on spawn
					if (playerData[playerid][playerIsTied])
					{
						playerData[playerid][playerIsTied] = false;
						SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
						KillTimer(playerData[playerid][untieTimer]);
						
						// Delete the kidnapped label
						if (playerData[playerid][kidnappedLabel])
						{
							Delete3DTextLabel(playerData[playerid][kidnappedLabel]);
						}
					}

					// Apply custom skin
			        if (playerData[playerid][playerCustomSkin] != -1)
			        {
			            SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SKIN] {FFFFFF}You have spawned with a custom skin. Type {FFDC2E}/resetskin {FFFFFF}to remove the custom skin.");
			            SetPlayerSkin(playerid, playerData[playerid][playerCustomSkin]);
					}

					switch(playerData[playerid][playerClass])
					{

				  		case CLASS_CIVILIAN:
				    	{
			   				SetPlayerColor(playerid, CLASS_CIVILIAN_COLOUR);
				     		SetPlayerWantedLevel(playerid, playerData[playerid][playerWantedLevel]);
				     		SetPlayerTeam(playerid, NO_TEAM);

							newPlayerColour(playerid);
							playerData[playerid][playerCanRape] = true;
							playerData[playerid][playerCanRob] = true;

							switch(playerData[playerid][playerJob])
							{
								case -1:
								{
									new jobList[500];
									format(jobList, sizeof(jobList), "%s\n{D87C3E}Kidnapper {FFFFFF}- Kidnap players for a ransom and XP.", jobList);
									format(jobList, sizeof(jobList), "%s\n{D87C3E}Mechanic {FFFFFF}- Upgrade or repair player vehicles.", jobList);
									format(jobList, sizeof(jobList), "%s\n{D87C3E}Gun Dealer {FFFFFF}- Sell weapons to players for cash.", jobList);
									format(jobList, sizeof(jobList), "%s\n{D87C3E}Rapist {FFFFFF}- Rape players and give them STDs.", jobList);
									format(jobList, sizeof(jobList), "%s\n{D87C3E}Hitman {FFFFFF}Complete hit contracts for cash.", jobList);
                                    format(jobList, sizeof(jobList), "%s\n{D87C3E}Drug Dealer {FFFFFF}Sell weed to players for cash.", jobList);
                                    format(jobList, sizeof(jobList), "%s\n{D87C3E}Terrorist {FFFFFF}- Blow up the jail cells / bank.", jobList);
                                    
									ShowPlayerDialog(playerid, DIALOG_JOBSELECT, DIALOG_STYLE_LIST, "Job Selection", jobList, "Choose", "Close");
								}
								case JOB_MECHANIC:
								{
									playerData[playerid][playerCanRepair] = true;
									playerData[playerid][playerCanFlip] = true;
									playerData[playerid][playerCanNOS] = true;
									playerData[playerid][playerCanREMP] = true;

						     		// weapons
									GivePlayerWeaponEx(playerid, 22, 250); // Pistol
									GivePlayerWeaponEx(playerid, 25, 250); // Shotgun
									GivePlayerWeaponEx(playerid, 29, 250); // mp5
									GivePlayerWeaponEx(playerid, 2, 1); // golf stick

									SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}Use {FFDC2E}/mech {FFFFFF}to see a list of available commands.");
								}
								case JOB_KIDNAPPER:
								{
									playerData[playerid][playerCanKidnap] = true;

						     		// weapons
									GivePlayerWeaponEx(playerid, 22, 250); // Pistol
									GivePlayerWeaponEx(playerid, 25, 250); // Shotgun
									GivePlayerWeaponEx(playerid, 29, 250); // mp5
									GivePlayerWeaponEx(playerid, 2, 1); // golf stick

									SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}Tie players and {FFDC2E}/kidnap {FFFFFF}them to earn XP and even a ransom!");
								}
								case JOB_HITMAN:
								{
									// Disable tracker
									PlayerTextDrawHide(playerid, PlayerText:playerData[playerid][playerTracker]);
									playerData[playerid][playerIsTracking] = false;
									KillTimer(playerData[playerid][playerHitmanTrackerTimer]);

						     		// weapons
									GivePlayerWeaponEx(playerid, 22, 250); // Pistol
									GivePlayerWeaponEx(playerid, 25, 250); // Shotgun
									GivePlayerWeaponEx(playerid, 29, 250); // mp5
									GivePlayerWeaponEx(playerid, 2, 1); // golf stick

									SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}Use {FFDC2E}/track {FFFFFF}to track players on the {FFDC2E}/hitlist{FFFFFF}.");
								}
								case JOB_PROSTITUTE: // Prostitute
								{
									playerData[playerid][playerJob] = JOB_PROSTITUTE;

						     		// weapons
									GivePlayerWeaponEx(playerid, 22, 250); // Pistol
									GivePlayerWeaponEx(playerid, 25, 250); // Shotgun
									GivePlayerWeaponEx(playerid, 29, 250); // mp5
									GivePlayerWeaponEx(playerid, 2, 1); // golf stick
								}
								case JOB_WEAPONDEALER:
								{
						     		// weapons
									GivePlayerWeaponEx(playerid, 22, 250); // Pistol
									GivePlayerWeaponEx(playerid, 25, 250); // Shotgun
									GivePlayerWeaponEx(playerid, 29, 250); // mp5
									GivePlayerWeaponEx(playerid, 2, 1); // golf stick

									SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}Use {FFDC2E}/sellgun {FFFFFF}to offer weapons to players.");
								}
								case JOB_DRUGDEALER:
								{
						     		// weapons
									GivePlayerWeaponEx(playerid, 22, 250); // Pistol
									GivePlayerWeaponEx(playerid, 25, 250); // Shotgun
									GivePlayerWeaponEx(playerid, 29, 250); // mp5
									GivePlayerWeaponEx(playerid, 2, 1); // golf stick
									
									SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}Use {FFDC2E}/sellweed {FFFFFF}whilst in an ice cream truck to sell drugs to players.");
								}
								case JOB_RAPIST:
								{
						     		// weapons
						     		GivePlayerWeaponEx(playerid, 10, 1); // Dildo
									GivePlayerWeaponEx(playerid, 22, 250); // Pistol
									GivePlayerWeaponEx(playerid, 25, 250); // Shotgun
									GivePlayerWeaponEx(playerid, 29, 250); // mp5
									GivePlayerWeaponEx(playerid, 2, 1); // golf stick

									SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}Use {FFDC2E}/rape {FFFFFF}to infect players with an STD.");
								}
								case JOB_TERRORIST:
								{
						     		// weapons
									GivePlayerWeaponEx(playerid, 22, 250); // Pistol
									GivePlayerWeaponEx(playerid, 25, 250); // Shotgun
									GivePlayerWeaponEx(playerid, 29, 250); // mp5
									GivePlayerWeaponEx(playerid, 2, 1); // golf stick
									
								}
							}
						}

					    case CLASS_MEDIC:
					    {
					        newPlayerColour(playerid);
			                SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}Use {FFDC2E}/cure {FFFFFF}to remove STDs from players and {FFDC2E}/heal {FFFFFF}to give health to a player.");

			                KillTimer(playerData[playerid][rehealTimer]);
			                KillTimer(playerData[playerid][recureTimer]);

			                playerData[playerid][canHeal] = true;
			                playerData[playerid][canCure] = true;

		                	SetPlayerTeam(playerid, NO_TEAM);
					    }

						case CLASS_POLICE:
				  		{
				  		    PlayerTextDrawSetString(playerid, playerData[playerid][wantedStars], " ");

				  		    if(playerData[playerid][playerCopTutorial] != 1)
				  		    {
				  		        SetPlayerVirtualWorld(playerid, 2);
								SetPlayerCameraPos(playerid, -1581.7755, 749.6948, 30.6389);
								SetPlayerCameraLookAt(playerid, -1605.5656, 717.6979, 11.9861);

								// Part 1 of the tutorial
								new string[600];
								format(string, sizeof(string), "%s{98B0CD}Police Classes \n", string);
			 					format(string, sizeof(string), "%s{FFFFFF}Playing as a law enforcement officer on this server is similar to other CNR game modes.\n", string);
			 					format(string, sizeof(string), "%s{FFFFFF}For those who aren't familiar with the commands, please see /commands after this tutorial\n", string);
			 					format(string, sizeof(string), "%s{FFFFFF}has concluded. This tutorial will act as a simple guide on how to act whilst playing as a cop.\n\n", string);

			 					format(string, sizeof(string), "%s{FFFFFF}There are 4 LEO classes. These include cop, CIA, FBI and army, \nthough army has seperate rules.", string);
			 					format(string, sizeof(string), "%s{FFFFFF}Each class requires an increased amount of XP,\nwhich can be seen when trying to spawn to a class.\n", string);

								ShowPlayerDialog(playerid, POLICE_TUTORIAL_1, DIALOG_STYLE_MSGBOX, "Police Tutorial - Introduction", string, "Next", "");
				  		    }

				    	    SetPlayerColor(playerid, CLASS_POLICE_COLOUR);
					        SetPlayerWantedLevel(playerid, 0);
					        playerData[playerid][playerCanTaze] = true;
					        playerData[playerid][playerCanArrest] = true;
			         	    playerData[playerid][playerCanCuff] = true;

			         	    // weapons
			         	    GivePlayerWeaponEx(playerid, 3, 1); // Night stick
			         	    GivePlayerWeaponEx(playerid, 22, 250); // Pistol
			         	    GivePlayerWeaponEx(playerid, 25, 250); // Shotgun
			         	    GivePlayerWeaponEx(playerid, 31, 250); // M4
			         	    GivePlayerWeaponEx(playerid, 41, 250); // Spray

							SetPlayerTeam(playerid, TEAM_LEO);
				    	}

						case CLASS_ARMY:
						{
							SetPlayerColor(playerid, CLASS_ARMY_COLOUR);
							SetPlayerWantedLevel(playerid, 0);
					        playerData[playerid][playerCanTaze] = true;
					        playerData[playerid][playerCanArrest] = true;
			         	    playerData[playerid][playerCanCuff] = true;

			         	    // weapons
			         	    GivePlayerWeaponEx(playerid, 3, 1); // Night stick
			         	    GivePlayerWeaponEx(playerid, 22, 250); // Pistol
			         	    GivePlayerWeaponEx(playerid, 25, 250); // Shotgun
			         	    GivePlayerWeaponEx(playerid, 31, 250); // M4
			         	    GivePlayerWeaponEx(playerid, 16, 5); // Grenades
			         	    GivePlayerWeaponEx(playerid, 41, 250); // Spray

							SetPlayerTeam(playerid, TEAM_LEO);
						}

						case CLASS_FBI:
						{
							SetPlayerColor(playerid, CLASS_FBI_COLOUR);
							SetPlayerWantedLevel(playerid, 0);
					        playerData[playerid][playerCanTaze] = true;
					        playerData[playerid][playerCanArrest] = true;
			         	    playerData[playerid][playerCanCuff] = true;

			         	    // weapons
			         	    GivePlayerWeaponEx(playerid, 3, 1); // Night stick
			         	    GivePlayerWeaponEx(playerid, 22, 250); // Pistol
			         	    GivePlayerWeaponEx(playerid, 25, 250); // Shotgun
			         	    GivePlayerWeaponEx(playerid, 31, 250); // M4
			         	    GivePlayerWeaponEx(playerid, 41, 250); // Spray

							SetPlayerTeam(playerid, TEAM_LEO);
						}

						case CLASS_CIA:
						{
							SetPlayerColor(playerid, CLASS_CIA_COLOUR);
							SetPlayerWantedLevel(playerid, 0);
					        playerData[playerid][playerCanTaze] = true;
					        playerData[playerid][playerCanArrest] = true;
			         	    playerData[playerid][playerCanCuff] = true;
			         	    playerData[playerid][playerCanEMP] = true;

			         	    // weapons
			         	    GivePlayerWeaponEx(playerid, 27, 250); // Shotgun
			         	    GivePlayerWeaponEx(playerid, 31, 250); // M4
			         	    GivePlayerWeaponEx(playerid, 23, 250); // Silenced Pistol
			         	    GivePlayerWeaponEx(playerid, 41, 250); // Spray

							SetPlayerTeam(playerid, TEAM_LEO);
						}

						case CLASS_SECRETSERVICE:
						{
							SetPlayerColor(playerid, CLASS_SECRETSERVICE_COLOUR);
							SetPlayerWantedLevel(playerid, 0);
					        playerData[playerid][playerCanTaze] = true;
					        playerData[playerid][playerCanArrest] = true;
			         	    playerData[playerid][playerCanCuff] = true;
			         	    playerData[playerid][playerCanEMP] = true;

			         	    // weapons
			         	    GivePlayerWeaponEx(playerid, 27, 250); // Shotgun
			         	    GivePlayerWeaponEx(playerid, 31, 250); // M4
			         	    GivePlayerWeaponEx(playerid, 23, 250); // Silenced Pistol
			         	    GivePlayerWeaponEx(playerid, 41, 250); // Spray

							SetPlayerTeam(playerid, TEAM_LEO);
						}

			  		}

			  		// Check if the player should be jailed
			  		if (playerData[playerid][playerJailTime] > 0)
			  		{
			  		    // Send player back to jail
			            new MsgAll[255], Name[24];
			            GetPlayerName(playerid, Name, sizeof(Name));
			            sendPlayerJail(playerid, playerData[playerid][playerJailTime], playerid, 0);

			            for(new p; p < MAX_PLAYERS; p++)
			            {
			                new pName[24];
			                GetPlayerName(p, pName, sizeof(pName));

			                if(!strcmp(pName, Name))
			                {
			                    SendClientMessage(p, COLOR_WHITE, "{FFDC2E}[JAIL] {FFFFFF}You have been returned to jail {07E08D}[Sentence incomplete]");
			                }
			                else
			                {
			                    format(MsgAll, sizeof(MsgAll), "{FFDC2E}[JAIL] {FFFFFF}%s(%i) has been returned to jail {07E08D}[Sentence incomplete]", Name, playerid);
			                    SendClientMessage(p, COLOR_WHITE, MsgAll);
			                }
						}
			    	}
			    	else
			    	{
			    	    if (playerData[playerid][spawnHouse] != -1)
			    	    {
							SpawnInHouse(playerid);
			    	    }
			    	    else
			    	    {
							new Float:bX, Float:bY, Float:bZ, Float:bA;

							if(playerData[playerid][playerTown] == SF)
							{
								switch(playerData[playerid][playerClass])
								{
									case CLASS_CIVILIAN:
									{
										new rand = random(10);

										switch(rand)
										{
											case 0: // Downtown
											{
												bX = -1753.0121;
												bY = 959.8522;
												bZ = 24.8828;
												bA = 178.4489;
											}
											case 1: // Financial (previously Jizzy's)
											{
												bX = -2613.6169;
												bY = 1394.1506;
												bZ = 7.1016;
												bA = 234.9960;
											}
											case 2: // Queens
											{
												bX = -2515.1592;
												bY = -25.7249;
												bZ = 25.6172;
												bA = 270.9635;
											}
											case 3: // front of station
											{
												bX = -2026.9011;
												bY = 156.6973;
												bZ = 29.0391;
												bA = 268.3445;
											}
											case 4: // Wang Cars
											{
												bX = -1973.4545;
												bY = 285.1178;
												bZ = 35.1719;
												bA = 90.7997;
											}
											case 5: // Downtown
											{
												bX = -1753.0121;
												bY = 959.8522;
												bZ = 24.8828;
												bA = 178.4489;
											}
											case 6: // New Burger Shot
											{
												bX = -1737.5981;
												bY = 1088.2644;
												bZ = 45.4453;
												bA = 92.5431;
											}
											case 7: // Opposite Hotel
											{
												bX = -1761.2441;
												bY = 886.1064;
												bZ = 25.0859;
												bA = 1.1142;
											}
											case 8: // supa
											{
												bX = -2408.3848;
												bY = 722.6746;
												bZ = 38.2734;
												bA = 183.2269;
											}
											case 9: // Mini games
											{
												bX = -1559.0730;
												bY = 1183.0647;
												bZ = 7.1875;
												bA = 91.3203;
											}
										}
									}

									case CLASS_MEDIC:
									{
										new rand = random(2);

										switch (rand)
										{
											case 0:
											{
												bX = -2656.0061;
												bY = 635.7116;
												bZ = 14.4531;
												bA = 183.0843;
											}

											case 1:
											{
												bX = -1992.5721;
												bY = 1041.8290;
												bZ = 55.7122;
												bA = 290.5727;
											}
										}
									}

									case CLASS_POLICE:
									{
										bX = -1587.1221;
										bY = 721.9797;
										bZ = -4.9063;
										bA = 213.6375;
									}

									case CLASS_FBI:
									{
										bX = -2428.3577;
										bY = 502.9266;
										bZ = 30.0781;
										bA = 20.7292;
									}

									case CLASS_CIA:
									{
										bX = -2428.3577;
										bY = 502.9266;
										bZ = 30.0781;
										bA = 20.7292;
									}

									case CLASS_ARMY:
									{
										bX = -1605.8867;
										bY = 285.6808;
										bZ = 7.1875;
										bA = 7.2846;
									}

									case CLASS_SECRETSERVICE:
									{
										bX = -1757.6335;
										bY = 786.7766;
										bZ = 167.6563;
										bA = 269.0399;
									}
								}
							}
							else
							{
								new places;
								switch(playerData[playerid][playerClass])
								{
									case CLASS_ARMY:
									{
										places = random(sizeof(ArmySpawns));
										bX = ArmySpawns[places][0];
										bY = ArmySpawns[places][1];
										bZ = ArmySpawns[places][2];
										bA = ArmySpawns[places][3];
									}
									case CLASS_FBI, CLASS_CIA:
									{
										places = random(sizeof(CIASpawns));
										bX = CIASpawns[places][0];
										bY = CIASpawns[places][1];
										bZ = CIASpawns[places][2];
										bA = CIASpawns[places][3];
									}
									case CLASS_CIVILIAN:
									{
										places = random(sizeof(CivSpawns));
										bX = CivSpawns[places][0];
										bY = CivSpawns[places][1];
										bZ = CivSpawns[places][2];
										bA = CivSpawns[places][3];
									}
									case CLASS_MEDIC:
									{
										places = random(sizeof(MedicSpawns));
										bX = MedicSpawns[places][0];
										bY = MedicSpawns[places][1];
										bZ = MedicSpawns[places][2];
										bA = MedicSpawns[places][3];
									}
									case CLASS_POLICE:
									{
										places = random(sizeof(CopSpawns));
										bX = CopSpawns[places][0];
										bY = CopSpawns[places][1];
										bZ = CopSpawns[places][2];
										bA = CopSpawns[places][3];
									}
									case CLASS_SECRETSERVICE:
									{
										places = random(sizeof(SecretSpawns));
										bX = SecretSpawns[places][0];
										bY = SecretSpawns[places][1];
										bZ = SecretSpawns[places][2];
										bA = SecretSpawns[places][3];
									}
								}
							}

					  		SetPlayerPos(playerid, bX, bY, bZ);
					  		SetPlayerFacingAngle(playerid, bA);
						}
					}

					// Remove player from gang when swapping from civi to leo
					if(playerData[playerid][playerClass] != CLASS_CIVILIAN && playerData[playerid][playerGangID] != INVALID_GANG_ID)
					{
						cmd_g(playerid, "leave");
					}

					// Disable admin duty on spawn
					if(playerData[playerid][playerAdminDuty])
					{
					    SendClientMessage(playerid, COLOR_WHITE, "{07E08D}[ADMIN] {FFFFFF}You're now an off duty administrator.");
						playerData[playerid][playerAdminDuty] = false;
						SetPlayerHealth(playerid, 100);
						newPlayerColour(playerid);
						TextDrawHideForPlayer(playerid, Text:AdminDuty);
						Delete3DTextLabel(playerData[playerid][playerAdminLabel]);
					}

					if (playerData[playerid][playerVIPLevel] >= 2)
					{
						if (playerData[playerid][playerVIPLevel] == 2)
						{
					    	SetPlayerArmour(playerid, 50); // Silver
						}
						else
						{
						    SetPlayerArmour(playerid, 99); // Gold
						}
					}

					if (playerData[playerid][playerVIPLevel] >= 2)
					{
					    if (playerData[playerid][vipWeapon] == 0)
					    {
					        SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[VIP WEAPON] {FFFFFF}You haven't selected a spawn weapon, to do so type {FFDC2E}/vipweapon{FFFFFF}!");
						}
						else
						{
						    switch(playerData[playerid][vipWeapon])
						    {
								case 24: // Deagle
								{
									GivePlayerWeaponEx(playerid, 24, 99999);
									playerData[playerid][vipWeapon] = 24;
								}
								case 31: // M4
								{
									GivePlayerWeaponEx(playerid, 31, 99999);
									playerData[playerid][vipWeapon] = 31;
								}
								case 34: // Sniper
								{
									GivePlayerWeaponEx(playerid, 34, 99999);
									playerData[playerid][vipWeapon] = 34;
								}
								case 26: // Sawnoff
								{
									GivePlayerWeaponEx(playerid, 26, 99999);
									playerData[playerid][vipWeapon] = 26;
								}
								case 9: // Chainsaw
								{
									GivePlayerWeaponEx(playerid, 9, 1);
									playerData[playerid][vipWeapon] = 9;
								}
								case 29: // MP5
								{
									GivePlayerWeaponEx(playerid, 29, 99999);
									playerData[playerid][vipWeapon] = 29;
								}
								case 27: // Combat Shotgun
								{
									GivePlayerWeaponEx(playerid, 27, 99999);
									playerData[playerid][vipWeapon] = 27;
								}
								case 28: // Micro SMG
								{
									GivePlayerWeaponEx(playerid, 28, 99999);
									playerData[playerid][vipWeapon] = 28;
								}
							}
						}
					}

					// Not dead
					playerData[playerid][playerDied] = false;

					// Double XP textdraw
					if(serverInfo[doubleXP])
					{
					    TextDrawShowForPlayer(playerid, doubleXPTD);
					}
					
					// Weapon Skills
					if (playerData[playerid][weaponSkill] == 1)
					{
                        SetPlayerSkillLevel(playerid, WEAPONSKILL_SAWNOFF_SHOTGUN, 999);
					}
					else
					{
					    SetPlayerSkillLevel(playerid, WEAPONSKILL_SAWNOFF_SHOTGUN, 0);
					}

					// Easter
					if(serverInfo[huntOn] == 5)
					{
					    TextDrawShowForPlayer(playerid, easterSunday);
					    PlayerTextDrawShow(playerid, playerData[playerid][Eggs][0]);
					    PlayerTextDrawShow(playerid, playerData[playerid][Eggs][1]);
					    PlayerTextDrawShow(playerid, playerData[playerid][Eggs][2]);
					}

					// Remove some labels
					Delete3DTextLabel(playerData[playerid][weedLabel]);

					// Anti-spawn kill
					if (playerData[playerid][playerJailTime] < 1)
					{
						SetPlayerHealth(playerid, 5000.0);
						playerData[playerid][spawnLabel] = Create3DTextLabel("JUST SPAWNED", 0xFFDC2EFF, 30.0, 40.0, 50.0, 60.0, -1, 1);
		        		Attach3DTextLabelToPlayer(playerData[playerid][spawnLabel], playerid, 0.0, 0.0, 0.4);
		        		SetTimerEx("AntiSpawnkill", 5000, 0, "i", playerid);
					}

	        		// Money
	        		ResetPlayerMoney(playerid);
	        		GivePlayerMoney(playerid, playerData[playerid][playerMoney]);

	        		// Trucking
					playerData[playerid][canTruck] = true;
					KillTimer(playerData[playerid][retruckTimer]);
				}
				else // is in a dm event
				{
					SetPlayerHealth(playerid, 10000.0);
					Delete3DTextLabel(playerData[playerid][spawnLabel]);
					playerData[playerid][spawnLabel] = Create3DTextLabel("SPAWN PROTECTED", 0xFFDC2EFF, 30.0, 40.0, 50.0, 40.0, 0);
	        		Attach3DTextLabelToPlayer(playerData[playerid][spawnLabel], playerid, 0.0, 0.0, 0.4);
	        		SetTimerEx("AntiSpawnkill", 1500, 0, "i", playerid);
				    
					new randSpawn = random(8);
					switch(randSpawn)
					{
						case 0:
						{
							SetPlayerPos(playerid, -1129.8909, 1057.5424, 1346.4141);
						}
						case 1:
						{
							SetPlayerPos(playerid, -974.1805, 1077.0630, 1344.9895);
						}
						case 2:
						{
							SetPlayerPos(playerid, -997.8885, 1096.0400, 1342.6517);
						}
						case 3:
						{
							SetPlayerPos(playerid, -1036.1115, 1024.3964, 1343.3551);
						}
						case 4:
						{
							SetPlayerPos(playerid, -1075.6144, 1032.7413, 1342.7317);
						}
						case 5:
						{
							SetPlayerPos(playerid, -1085.2362, 1053.7657, 1343.3536);
						}
						case 6:
						{
							SetPlayerPos(playerid, -1101.0815, 1084.6434, 1341.8438);
						}
						case 7:
						{
							SetPlayerPos(playerid, -1093.1536, 1058.8173, 1341.3516);
						}
					}
					
					// No team during DM
					SetPlayerTeam(playerid, NO_TEAM);
					
					SetPlayerInterior(playerid, 10);
					SetPlayerVirtualWorld(playerid, 169);

					playerData[playerid][isInDM] = true; // Prevent scores etc - also respawn
					playerData[playerid][isInEvent] = true;
					playerData[playerid][adminWeapon] = true; // Prevent anti-cheat kick
					GivePlayerWeaponEx(playerid, 31, 50000);

					TextDrawShowForPlayer(playerid, dmBox[0]);
					TextDrawShowForPlayer(playerid, dmBox[1]);
					TextDrawShowForPlayer(playerid, dmBox[2]);
					TextDrawShowForPlayer(playerid, dmBox[3]);
					TextDrawShowForPlayer(playerid, dmBox[4]);
					TextDrawShowForPlayer(playerid, dmBox[5]);
					TextDrawShowForPlayer(playerid, dmBox[6]);
					
					PlayerTextDrawShow(playerid, playerData[playerid][dmArena][0]);
					PlayerTextDrawShow(playerid, playerData[playerid][dmArena][1]);
					PlayerTextDrawShow(playerid, playerData[playerid][dmArena][2]);
					PlayerTextDrawShow(playerid, playerData[playerid][dmArena][3]);
					
					dmStats(playerid);
					
					SendClientMessage(playerid, COLOR_RED, "{58D3F7}[MINIGAME] {FFFFFF}You've respawned into the DM event type {FFDC2E}/leavedm {FFFFFF}to leave the arena.");

				    newPlayerColour(playerid);
				    playerData[playerid][hasSpawned] = true;
				    playerData[playerid][playerDied] = false;
				}
			}
		}
	}
	else // Must login before spawning
	{
        SendClientMessage(playerid, COLOR_RED, "{B7B7B7}[SERVER] {FFFFFF}You cannot spawn without logging in!");
	    return 0;
	}

	return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
	KillTimer(playerData[playerid][skydiveTimer]);
	for(new x = 0; x < MAX_OSLOTS; x++)
	{
		if(playerData[playerid][toyStatus][x])
		{
			if(IsPlayerAttachedObjectSlotUsed(playerid, x))
			{
				RemovePlayerAttachedObject(playerid, x);
			}
		}
	}
	
    ApplyAnimation(playerid, "PED", "KO_shot_front",4.1,0,1,1,1,1);

    playerData[playerid][hasSpawned] = false;
	playerData[playerid][ctpImmune] = true;
	playerData[playerid][abImmune] = true;
    
    // Easter
    PlayerTextDrawHide(playerid, playerData[playerid][Eggs][0]);
    PlayerTextDrawHide(playerid, playerData[playerid][Eggs][1]);
    PlayerTextDrawHide(playerid, playerData[playerid][Eggs][2]);
    
    if (playerData[playerid][isInDM] || playerData[playerid][isInDuel])
    {
        playerData[playerid][isInDuel] = false;
		playerData[playerid][hasSpawned] = false;
		playerData[playerid][suicide] = false;
		
		if (killerid != INVALID_PLAYER_ID)
		{
		    playerData[killerid][dmKills]++;
		    playerData[killerid][dmStreak]++;
		    dmStats(killerid);
		    
			new randDeath = random(21), randomDeath[200];
			switch(randDeath)
			{
			    case 0:
			    {
					format(randomDeath, sizeof(randomDeath), "eliminated");
				}
				case 1:
				{
				    format(randomDeath, sizeof(randomDeath), "fucked up");
				}
				case 2:
				{
				    format(randomDeath, sizeof(randomDeath), "raped");
				}
				case 3:
				{
				    format(randomDeath, sizeof(randomDeath), "put some lead into");
				}
				case 4:
				{
				    format(randomDeath, sizeof(randomDeath), "gave a lead tattoo to");
				}
				case 5:
				{
				    format(randomDeath, sizeof(randomDeath), "delivered some bullets to");
				}
	  			case 6:
				{
				    format(randomDeath, sizeof(randomDeath), "said hello to");
				}
	  			case 7:
				{
				    format(randomDeath, sizeof(randomDeath), "delivered some bullets first class to");
				}
	  			case 8:
				{
				    format(randomDeath, sizeof(randomDeath), "slayed");
				}
	  			case 9:
				{
				    format(randomDeath, sizeof(randomDeath), "mortalized");
				}
	  			case 10:
				{
				    format(randomDeath, sizeof(randomDeath), "dropped");
				}
	  			case 11:
				{
				    format(randomDeath, sizeof(randomDeath), "pwn3d");
				}
	  			case 12:
				{
				    format(randomDeath, sizeof(randomDeath), "unleashed the pain on");
				}
	  			case 13:
				{
				    format(randomDeath, sizeof(randomDeath), "avada kedavra'd");
				}
	  			case 14:
				{
				    format(randomDeath, sizeof(randomDeath), "humiliated");
				}
	  			case 15:
				{
				    format(randomDeath, sizeof(randomDeath), "broke");
				}
	  			case 16:
				{
				    format(randomDeath, sizeof(randomDeath), "popped");//wait
				}
	  			case 17:
				{
				    format(randomDeath, sizeof(randomDeath), "sends their regards to");
				}
	  			case 18:
				{
				    format(randomDeath, sizeof(randomDeath), "now owns");
				}
	  			case 19:
				{
				    format(randomDeath, sizeof(randomDeath), "used a classified move on");
				}
	  			case 20:
				{
				    format(randomDeath, sizeof(randomDeath), "ended");
				}
			}

            if(playerData[killerid][isInDuel])
		    {
		        new duelMSG[256];
				//playerData[killerid][isInDuel] = false;
				SpawnPlayer(killerid);
				//SetPlayerInterior(killerid, playerData[killerid][previousVirtualWorld]);
				//SetPlayerVirtualWorld(killerid, playerData[killerid][previousInteriorWorld]);
				//SetPlayerPos(killerid,  playerData[killerid][previousX], playerData[killerid][previousY], playerData[killerid][previousZ]); // Done
		        format(duelMSG, sizeof(duelMSG), "{061F72}[DUEL]{FAAC58} %s(%i) {FFFFFF}%s {FAAC58}%s(%i)", playerData[killerid][playerNamee], killerid, randomDeath, playerData[playerid][playerNamee], playerid);
		        SendClientMessageToAll(COLOR_WHITE, duelMSG);
		    }
		    
			for (new i=0; i<MAX_PLAYERS; i++)
			{
				if(playerData[i][isInDM])
				{
					new dmKill[100];
					format(dmKill, sizeof(dmKill), "{FAAC58}%s(%i) {FFFFFF}%s {FAAC58}%s(%i)", playerData[killerid][playerNamee], killerid, randomDeath, playerData[playerid][playerNamee], playerid);
					SendClientMessage(i, COLOR_WHITE, dmKill);
				}
			}
		}
		
	    playerData[playerid][dmDeaths]++;
	    playerData[playerid][dmStreak] = 0;
		KillTimer(playerData[playerid][streakTimer]);
		disableStreak(playerid);
	    dmStats(playerid);
    }
    else
    {
		if(!playerData[playerid][playerDied])
		{
			new vid = GetPlayerVehicleID(killerid);

	        if (killerid != INVALID_PLAYER_ID && GetPlayerWeapon(killerid) != reason && reason != 54 && reason != 50 && reason != 53 && !playerData[playerid][suicide] && GetVehicleModel(vid) != 520 && GetVehicleModel(vid) != 447)
	        {
	            if (reason == 49 && IsPlayerInAnyVehicle(killerid))
	            {
					return 1;
				}

	            else if (reason == 51 && IsPlayerInAnyVehicle(playerid))
	            {
					return 1;
				}
				
				else
				{
					new string[600];

					format(string, sizeof(string), "%s{98B0CD}Invalid Death Detected \n", string);
					format(string, sizeof(string), "%s{FFFFFF}The server does not recognise the reason for your death. \n", string);
					format(string, sizeof(string), "%s{FFFFFF}To prevent stat loss, we have an anti-fake kill system in place. \n\n", string);
					format(string, sizeof(string), "%s{FFFFFF}If you have respawned at the bank with no weapons, click respawn. \n\n", string);

					ShowPlayerDialog(playerid, DIALOG_FORCE_RESPAWN, DIALOG_STYLE_MSGBOX, "", string, "RESPAWN", "CANCEL");
					
					return 0;
				}
	        }

		    SendDeathMessage(killerid, playerid, reason);

		    if(playerData[playerid][playerLoggedIn])
			{
			    if(playerData[playerid][isInEvent])
			    {
			        playerData[playerid][isInEvent] = false;
			        playerData[playerid][hasSpawned] = false;
			        newPlayerColour(playerid);
		 			playerData[playerid][playerDeaths]++;
			    	playerData[playerid][playerWantedLevel] = 0;
			    	SetPlayerWantedLevel(playerid, 0);
			    	playerData[playerid][hasSTD] = false;
			    	KillTimer(playerData[playerid][rapedTimer]);
				}
				else
				{
			        if(IsPlayerConnected(killerid))
			        {
			            if(playerData[killerid][playerLoggedIn])
			            {
			                playerData[killerid][playerKills] = playerData[killerid][playerKills] + 1;
							playerData[killerid][playerScore] = playerData[killerid][playerScore] + 1;
							SetPlayerScore(killerid, playerData[killerid][playerScore]);

							playerGiveXP(playerid, 5);

							if (playerData[killerid][playerKills] == 1)
							{
							    disableAchieve(killerid);
								PlayerTextDrawShow(killerid, playerData[killerid][Achieve1]);
								PlayerTextDrawShow(killerid, playerData[killerid][Achieve2]);
								PlayerTextDrawShow(killerid, playerData[killerid][Achieve3]);
								PlayerTextDrawShow(killerid, playerData[killerid][Achieve4]);

								PlayerTextDrawSetString(killerid, playerData[killerid][Achieve3], "First Kill");
								PlayerTextDrawSetString(killerid, playerData[killerid][Achieve4], "You killed your first victim. Well done.");
								PlayerPlaySound(killerid, 1183 ,0.0, 0.0, 0.0);

								playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 8000, false, "i", killerid);

								// XP/SCORE AWARD
								playerGiveXP(playerid, 50);
								playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
								SetPlayerScore(playerid, playerData[playerid][playerScore]);
							}
							else if (playerData[killerid][playerKills] == 50)
							{
							    disableAchieve(killerid);
								PlayerTextDrawShow(killerid, playerData[killerid][Achieve1]);
								PlayerTextDrawShow(killerid, playerData[killerid][Achieve2]);
								PlayerTextDrawShow(killerid, playerData[killerid][Achieve3]);
								PlayerTextDrawShow(killerid, playerData[killerid][Achieve4]);

								PlayerTextDrawSetString(killerid, playerData[killerid][Achieve3], "San Fierro Killer");
								PlayerTextDrawSetString(killerid, playerData[killerid][Achieve4], "You've killed 50 players! Nice!");
								PlayerPlaySound(killerid, 1183 ,0.0, 0.0, 0.0);

								playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 8000, false, "i", killerid);

								// XP/SCORE AWARD
								playerGiveXP(playerid, 50);
								playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
								SetPlayerScore(playerid, playerData[playerid][playerScore]);
							}
							else if (playerData[killerid][playerKills] == 500)
							{
							    disableAchieve(killerid);
								PlayerTextDrawShow(killerid, playerData[killerid][Achieve1]);
								PlayerTextDrawShow(killerid, playerData[killerid][Achieve2]);
								PlayerTextDrawShow(killerid, playerData[killerid][Achieve3]);
								PlayerTextDrawShow(killerid, playerData[killerid][Achieve4]);

								PlayerTextDrawSetString(killerid, playerData[killerid][Achieve3], "Mass Murderer");
								PlayerTextDrawSetString(killerid, playerData[killerid][Achieve4], "500 kills attained. You require medical assistance.");
								PlayerPlaySound(killerid, 1183 ,0.0, 0.0, 0.0);

								playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 8000, false, "i", killerid);

								// XP/SCORE AWARD
								playerGiveXP(playerid, 50);
								playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
								SetPlayerScore(playerid, playerData[playerid][playerScore]);
							}

							if(playerData[killerid][playerClass] == CLASS_CIVILIAN || playerData[killerid][playerClass] == CLASS_MEDIC)
							{
								new message[128];
								playerData[killerid][playerWantedLevel] = playerData[killerid][playerWantedLevel] + 12;
								SetPlayerWantedLevel(killerid, playerData[killerid][playerWantedLevel] + 12);
								format(message, sizeof(message), "{FFDC2E}[MURDER] {FFFFFF}You have just killed %s(%i)!", playerData[playerid][playerNamee], playerid, playerData[killerid][playerWantedLevel]);
								SendClientMessage(killerid, COLOR_WHITE, message);
								sendWantedMessage(killerid, 12);
								newPlayerColour(killerid);

								if(playerData[killerid][playerJob] == JOB_HITMAN && playerData[killerid][playerClass] != CLASS_MEDIC)
								{
									if(playerData[playerid][playerHitValue] > 0)
									{
									    playerData[killerid][hitsCompleted] = playerData[killerid][hitsCompleted] + 1;
										playerGiveMoney(killerid, playerData[playerid][playerHitValue]);
										format(message, sizeof(message), "{FFDC2E}[CONTRACT] {FFFFFF}%s(%i) has completed the contract on %s(%i) and earnt {FFDC2E}$%s", playerData[killerid][playerNamee], killerid, playerData[playerid][playerNamee], playerid, FormatNumber(playerData[playerid][playerHitValue]));
										SendClientMessageToAll(COLOR_WHITE, message);

										new loggingString[256];
										format(loggingString, sizeof(loggingString), "%s completed the contract on %s for %d.", playerData[killerid][playerNamee], playerData[playerid][playerNamee], playerData[playerid][playerHitValue]);
										writeInLog("contractLog.html", loggingString);

										playerData[playerid][playerHitValue] = 0;

										if (playerData[killerid][hitsCompleted] == 1)
										{
										    disableAchieve(killerid);
											PlayerTextDrawShow(killerid, playerData[killerid][Achieve1]);
											PlayerTextDrawShow(killerid, playerData[killerid][Achieve2]);
											PlayerTextDrawShow(killerid, playerData[killerid][Achieve3]);
											PlayerTextDrawShow(killerid, playerData[killerid][Achieve4]);

											PlayerTextDrawSetString(killerid, playerData[killerid][Achieve3], "Contract Killer");
											PlayerTextDrawSetString(killerid, playerData[killerid][Achieve4], "You completed your first hit contract!");
											PlayerPlaySound(killerid, 1183 ,0.0, 0.0, 0.0);

											playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 8000, false, "i", killerid);

											// XP/SCORE AWARD
											playerGiveXP(playerid, 50);
											playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
											SetPlayerScore(playerid, playerData[playerid][playerScore]);
										}

										if (playerData[killerid][hitsCompleted] == 20)
										{
										    disableAchieve(killerid);
											PlayerTextDrawShow(killerid, playerData[killerid][Achieve1]);
											PlayerTextDrawShow(killerid, playerData[killerid][Achieve2]);
											PlayerTextDrawShow(killerid, playerData[killerid][Achieve3]);
											PlayerTextDrawShow(killerid, playerData[killerid][Achieve4]);

											PlayerTextDrawSetString(killerid, playerData[killerid][Achieve3], "Professional Hitman");
											PlayerTextDrawSetString(killerid, playerData[killerid][Achieve4], "You completed 20 hit contracts!");
											PlayerPlaySound(killerid, 1183 ,0.0, 0.0, 0.0);

											playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 8000, false, "i", killerid);

											// XP/SCORE AWARD
											playerGiveXP(playerid, 50);
											playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
											SetPlayerScore(playerid, playerData[playerid][playerScore]);
										}
									}
								}

								playerData[killerid][playerLastKill] = GetTickCount();
				           	}

							if(playerData[playerid][playerClass] == CLASS_CIVILIAN || playerData[playerid][playerClass] == CLASS_MEDIC)
							{
							    newPlayerColour(playerid);
							}

				           	if(playerData[killerid][playerClass] == CLASS_POLICE || playerData[killerid][playerClass] == CLASS_ARMY || playerData[killerid][playerClass] == CLASS_CIA || playerData[killerid][playerClass] == CLASS_FBI || playerData[killerid][playerClass] == CLASS_SECRETSERVICE)
				           	{
				           	    if(playerData[playerid][playerWantedLevel] == 0)
								{
									if (!playerData[playerid][suicide])
									{
										if (playerData[killerid][playerClass] == CLASS_POLICE || playerData[killerid][playerClass] == CLASS_FBI || playerData[killerid][playerClass] == CLASS_CIA || playerData[killerid][playerClass] == CLASS_SECRETSERVICE)
										{
										    playerData[killerid][innocentKills]++;

										    if (playerData[killerid][innocentKills] > 2)
										    {
										        playerGiveMoney(killerid, -5000);
											}

										    if (playerData[killerid][innocentKills] == 5)
										    {
										        // Cop class ban

												ForceClassSelection(killerid);
												TogglePlayerSpectating(killerid, true);
												TogglePlayerSpectating(killerid, false);

										        playerData[killerid][playerCopBanned] = 1;

	  								        }
											else
											{
											    SetPlayerHealth(killerid, 0.0);
											}

											print("cop");
										}

										if (playerData[killerid][playerClass] == CLASS_ARMY)
										{
										    playerData[killerid][aInnocentKills]++;
										    playerGiveMoney(killerid, -5000);

										    if (playerData[killerid][aInnocentKills] == 3)
										    {
										        // Army class ban

												ForceClassSelection(killerid);
												TogglePlayerSpectating(killerid, true);
												TogglePlayerSpectating(killerid, false);

										        playerData[killerid][playerArmyBanned] = 1;

											}
											else
											{
											    SetPlayerHealth(killerid, 0.0);
											}

											print("army");
										}

										closeDialogs(killerid);

										PlayerTextDrawShow(killerid, playerData[killerid][InnocentKill1]);
										PlayerTextDrawShow(killerid, playerData[killerid][InnocentKill2]);
										PlayerTextDrawShow(killerid, playerData[killerid][InnocentKill3]);
										PlayerTextDrawShow(killerid, playerData[killerid][InnocentKill4]);
										PlayerTextDrawShow(killerid, playerData[killerid][InnocentKill5]);
										PlayerTextDrawShow(killerid, playerData[killerid][InnocentKill6]);
										PlayerTextDrawShow(killerid, playerData[killerid][InnocentKill7]);
										PlayerTextDrawShow(killerid, playerData[killerid][InnocentKill8]);
									}
				           	    }
				           	    else if(playerData[playerid][playerWantedLevel] > 0)
				           	    {
									new message[128], earnings;
									earnings = (playerData[playerid][playerWantedLevel] * 200);
									format(message, sizeof(message), "{FFDC2E}[KILL] {FFFFFF}You killed %s(%i) who had a wanted level of %i, you earnt {FFDC2E}$%s!", playerData[playerid][playerNamee], playerid, playerData[playerid][playerWantedLevel], FormatNumber(earnings));
				           	        SendClientMessage(killerid, COLOR_WHITE, message);
									playerGiveMoney(killerid, earnings);

									playerGiveXP(killerid, 5);
									playerData[killerid][copKills] = playerData[killerid][copKills] + 1;

									new loggingString[256];
									format(loggingString, sizeof(loggingString), "%s killed %s for %d.", playerData[killerid][playerNamee], playerData[playerid][playerNamee], earnings);
									writeInLog("copKillLog.html", loggingString);
				           	    }
				           	}
						}
					}

					if(playerData[playerid][iscourier])
					{
						SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}You died, the mission was cancelled.");
						playerData[playerid][iscourier] = false;
						playerData[playerid][playerCourierLevel] = 0;
						DisablePlayerCheckpoint(playerid);
					}

					if (playerData[playerid][truckingStatus] > 0)
					{
						return cmd_canceltrucking(playerid, "");
					}

					if (playerData[playerid][forkliftStatus] > 0)
					{
						return cmd_cancelforklift(playerid, "");
					}

					if (playerData[playerid][busStatus] > 0)
					{
						return cmd_cancelroute(playerid, "");
					}

					playerData[playerid][playerDeaths]++;
					playerData[playerid][playerDied] = true;
			    	playerData[playerid][playerWantedLevel] = 0;
			    	SetPlayerWantedLevel(playerid, 0);
			    	playerData[playerid][hasSTD] = false;
		            KillTimer(playerData[playerid][rapedTimer]);
		            KillTimer(playerData[playerid][uncuffTimer]);
					playerData[playerid][playerIsTied] = false;
					SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
					KillTimer(playerData[playerid][untieTimer]);
					playerData[playerid][hasSpawned] = false;
					playerData[playerid][suicide] = false;

					if (!playerData[playerid][healthInsurance])
					{
						taxplayer(playerid);
					}
			    }
		    }
		}
	}
	
	return 1;
}

public OnPlayerText(playerid, text[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(text[0] == '@' && playerData[playerid][playerLevel] >= 1)
		{
	 	    new string[128];
	 		GetPlayerName(playerid, string, sizeof(string));
	        format(string, sizeof(string), "{07E08D}<Admin Chat> {FFFFFF}%s: %s", string, text[1]);
			adminchat(COLOR_WHITE, string);
	        return 0;
	    }
	    else if(text[0] == '#' && playerData[playerid][playerHelper] == 1)
		{
	 	    new string[128];
	 		GetPlayerName(playerid, string, sizeof(string));
	        format(string, sizeof(string), "{A5DF00}[Helper Chat] {FFFFFF}%s: %s", string, text[1]);
			helperchat(COLOR_WHITE, string);
	        return 0;
	    }
	    else
	    {
			if (playerData[playerid][playerMuteTime] != 0)
			{
			    new message[128];
				format(message, sizeof(message), "{FFDC2E}[MUTED] {FFFFFF}You are muted for another {FFDC2E}%i {FFFFFF}seconds and cannot talk!", playerData[playerid][playerMuteTime]);
				SendClientMessage(playerid, COLOR_WHITE, message);
				return 0;
			}
			else
			{
			    if (FindIP(text))
			    {
		            SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[SPAM] {FFFFFF}Advert detected! If this occurs frequently, you will be kicked.");
		            playerData[playerid][adDetected]++;
                    new administratorAlert[256];
					format(administratorAlert, sizeof(administratorAlert), "{C73E3E}[ADVERTISING] {FFFFFF}%s(%d): %s", playerData[playerid][playerNamee], playerid, text);
					adminchat(COLOR_WHITE, administratorAlert);
		            if (playerData[playerid][adDetected] == 2)
		            {
		                // Kick
		                KickWithMessage(playerid, "You have been kicked for advertising.");
		            }

		            return 0;
				}
				

	    		if(strfind(text, "hacker", true) != -1 || strfind(text, "aimbot", true) != -1 || strfind(text, "hack", true) != -1)
			    {
		            SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HELP] {FFFFFF}Please use /report to report any rulebreaker.");
		            return 0;
			    }
			    
			    if (playerData[playerid][messageCount] != 3)
			    {
					new chat[400], color[20];

					switch(playerData[playerid][playerClass])
					{
						case 0, 6:
						{
							if(playerData[playerid][playerWantedLevel] == 0)
							{
								if (playerData[playerid][vipColour])
								{
									color = "58D3F7";
								}
								else
								{
									if(playerData[playerid][playerClass] == CLASS_MEDIC)
									{
										// Medic Colour
									    color = "F78181";
									}
									else
									{
										// White Wanted Level
										color = "FFFFFF";
									}
								}
							}

							if (playerData[playerid][playerWantedLevel] >= 1)
							{
								// Yellow Wanted Level
								color = "FFEC41";
							}

							if(playerData[playerid][playerWantedLevel] >= 6)
							{
								// Orange Wanted Level
								color = "DF802D";
							}

							if(playerData[playerid][playerWantedLevel] >= 25)
							{
								// Red Wanted Level
							    color = "D92C3C";
							}
						}

						case 1: // Police
						{
							if (playerData[playerid][vipColour])
							{
								color = "58D3F7";
							}
							else
							{
								color = "3E7EFF";
							}
						}
						case 2: // FBI
						{
							if (playerData[playerid][vipColour])
							{
								color = "58D3F7";
							}
							else
							{
								color = "8F48F5";
							}
						}
						case 3: // CIA
						{
							if (playerData[playerid][vipColour])
							{
								color = "58D3F7";
							}
							else
							{
								color = "2F205B";
							}
						}
						case 4: // Army
						{
							if (playerData[playerid][vipColour])
							{
								color = "58D3F7";
							}
							else
							{
								color = "1C3EFF";
							}
						}
						case 7: // Secret Service
						{
							if (playerData[playerid][vipColour])
							{
								color = "58D3F7";
							}
							else
							{
								color = "2F205B";
							}
						}
					}

					if (playerData[playerid][playerAdminDuty]) // Admin On Duty
					{
					    color = "07E08D";
					}
					
					if (playerData[playerid][useAdminName])
					{
					    format(chat, sizeof(chat),"{%s}%s(%i): {FFFFFF}%s", color, playerData[playerid][tempAdminName], playerid, text);
					}
					else
					{
						format(chat, sizeof(chat),"{%s}%s(%i): {FFFFFF}%s", color, playerData[playerid][playerNamee], playerid, text);
					}
					
					SendClientMessageToAll(COLOR_WHITE, chat);

					playerData[playerid][messageCount]++;
					KillTimer(playerData[playerid][spamTimer]);
					playerData[playerid][spamTimer] = SetTimerEx("StopSpam", 3000, false, "i", playerid);
				}
				else
				{
				    SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[SPAM] {FFFFFF}Please wait a moment before sending another message.");
				}
		    }
		}
	}
	return 0;
}

stock adminchat(color, const msg[])
{
    for (new i=0; i<MAX_PLAYERS; i++)
    {
        if (playerData[i][playerLevel] >= 1)
	    {
	        SendClientMessage(i, color, msg);
	    }
    }
}

stock helperchat(color, const msg[])
{
    for (new i=0; i<MAX_PLAYERS; i++)
    {
        if (playerData[i][playerHelper] == 1)
	    {
	        SendClientMessage(i, color, msg);
	    }
    }
}

stock policechat(color, const msg[])
{
    for (new i=0; i<MAX_PLAYERS; i++)
    {
        if (playerData[i][playerClass] == CLASS_POLICE  || playerData[i][playerClass] == CLASS_ARMY || playerData[i][playerClass] == CLASS_CIA || playerData[i][playerClass] == CLASS_FBI)
	    {
	        SendClientMessage(i, color, msg);
	    }
    }
}

public OnPlayerCommandReceived(playerid, cmdtext[])
{
    if(playerData[playerid][canUseCommands] || playerData[playerid][playerLevel] >= 1)
    {
		if(playerData[playerid][hasSpawned] || playerData[playerid][playerLevel] >= 1)
		{
		    playerData[playerid][canUseCommands] = false;
		    playerData[playerid][commandTimer] = SetTimerEx("command", 1020, false, "i", playerid);

			new loggingString[256];
			format(loggingString, sizeof(loggingString), "%s used command: %s", playerData[playerid][playerNamee], cmdtext);
			writeInLog("commandLog.html", loggingString);

		    return 1;
		}
		else
		{
		    SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use commands while you're not spawned.");
	        return 0;
		}
	}
	else
	{
 		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Please wait before using another command.");
 		return 0;
	}
}

public OnPlayerCommandPerformed(playerid, cmdtext[], success){
    if (!success) return SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Unknown command. Type {FFDC2E}/cmds {FFFFFF}for a list of commands or {FFDC2E}/help {FFFFFF}for guides.");
    return 1;
}

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    ac_OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
    
	if(playerData[playerid][playerPreviousVehicles][0] && playerData[playerid][playerPreviousVehicles][1] && playerData[playerid][playerPreviousVehicles][2])
	{
		new totalTime =

		(playerData[playerid][playerPreviousVehicles][2] - playerData[playerid][playerPreviousVehicles][1]) +
		(playerData[playerid][playerPreviousVehicles][1] - playerData[playerid][playerPreviousVehicles][0]) +
		(playerData[playerid][playerPreviousVehicles][0] - GetTickCount());

		if(totalTime < 2000)
		{
			for(new i = 0; i < MAX_PLAYERS; i++)
			{
				if(IsPlayerConnected(i) && playerData[i][playerLevel] >= 1)
				{
					new message[200];
					format(message, sizeof(message), "{DF0101}[CHEAT REPORT] {FFFFFF}%s(%i) is suspected of car warping.", playerData[playerid][playerNamee], playerid);
					SendClientMessage(i, COLOR_WHITE, message);
				}
			}

			KickWithMessage(playerid, "You have been kicked due to car warping.");
		}
	}

	if (playerData[playerid][truckingStatus] > 0)
	{
	    if(GetVehicleModel(vehicleid) == 515 || GetVehicleModel(vehicleid) == 414)
	    {
			// Player re-entered truck
            KillTimer(playerData[playerid][truckExitTimer]);

			PlayerTextDrawSetString(playerid, playerData[playerid][playerTruckingWaitTD], " ");
			PlayerTextDrawSetString(playerid, playerData[playerid][playerTruckingTD], " ");
			playerData[playerid][truckCounter] = 10;
		}
	}

	if(playerData[playerid][playerPreviousVehicles][1])
	{
		playerData[playerid][playerPreviousVehicles][1] = playerData[playerid][playerPreviousVehicles][2];
	}

	if(playerData[playerid][playerPreviousVehicles][0])
	{
		playerData[playerid][playerPreviousVehicles][0] = playerData[playerid][playerPreviousVehicles][1];
	}

	playerData[playerid][playerPreviousVehicles][0] = GetTickCount();
	playerData[playerid][playerLastVehicleID] = vehicleid;
	
	//enterVehicle(playerid, playerData[playerid][actualID], vehicleid);

    return 1;
}

public OnPlayerExitVehicle(playerid, vehicleid)
{
	if(playerData[playerid][iscourier])
	{
		// Cancel the job
		SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}You left your vehicle, mission cancelled.");
		playerData[playerid][iscourier] = false;
		playerData[playerid][playerCourierLevel] = 0;
		RemovePlayerMapIcon(playerid, 90);
		DestroyDynamicRaceCP(playerData[playerid][playerLastCourierCP]);
		TextDrawHideForPlayer(playerid, TDCourier2);
		TextDrawHideForPlayer(playerid, TDCourier);
		KillTimer(playerData[playerid][courierTimer]);
		TogglePlayerControllable(playerid, 1);
		DisablePlayerCheckpoint(playerid);
		KillTimer(playerData[playerid][courierDistance]);
		PlayerTextDrawSetString(playerid, playerData[playerid][playerCourierDistanceTD], " ");
	}
	else if (playerData[playerid][forkliftStatus] > 0)
	{
	    return cmd_cancelforklift(playerid, "");
	}
	else if (playerData[playerid][busStatus] > 0)
	{
	    return cmd_cancelroute(playerid, "");
	}
	
	new Float: oldPos[4];

	GetVehiclePos(vehicleid, oldPos[0], oldPos[1], oldPos[2]);
	GetVehicleZAngle(vehicleid, oldPos[3]);

    vWarped[vehicleid][theVehicle] = vehicleid;
	vWarped[vehicleid][vehiclePositionX] = oldPos[0];
	vWarped[vehicleid][vehiclePositionY] = oldPos[1];
	vWarped[vehicleid][vehiclePositionZ] = oldPos[2];
	vWarped[vehicleid][vehiclePositionA] = oldPos[3];
	vWarped[vehicleid][wasOccupied] = true;

	return 1;
}

public OnPlayerCleoDetected( playerid, cleoid )
{
    switch( cleoid )
    {
        case CLEO_CARSWING:
        {
            ac_CarSwing(playerid);
        }
        case CLEO_CAR_PARTICLE_SPAM:
        {
            ac_CarSpam(playerid);
        }
    }
    return 1;
}

new p_CarWarpTime[MAX_PLAYERS];
new p_CarWarpVehicleID[MAX_PLAYERS];

public OnPlayerStateChange(playerid, newstate, oldstate)
{
    ac_OnPlayerStateChange(playerid, newstate, oldstate);
    
    checkTheft(playerid, newstate, oldstate);
    
    if(newstate == PLAYER_STATE_DRIVER)
    {
        SetPlayerArmedWeapon(playerid, 0);
        if( GetPlayerVehicleID(playerid) != p_CarWarpVehicleID[playerid])
        {
            if( p_CarWarpTime[playerid] > gettime())
            {
				for(new i = 0; i < MAX_PLAYERS; i++)
				{
					if(IsPlayerConnected(i) && playerData[i][playerLevel] >= 1)
					{
					    new messageContent[128];
						format(messageContent, sizeof(messageContent), "{FFDC2E}[CHEAT ALERT] {FFFFFF}%s(%i) is suspected of car warping", playerData[i][playerNamee], i);
						SendClientMessage(i, COLOR_WHITE, messageContent);
					}
				}
            }

            p_CarWarpTime[playerid] = gettime() + 1;
            p_CarWarpVehicleID[playerid] = GetPlayerVehicleID(playerid);
        }

        new vehicleid = GetPlayerVehicleID(playerid);
		enterVehicle(playerid, playerData[playerid][actualID], vehicleid);
    }
    
    if (newstate == PLAYER_STATE_ONFOOT)
    {
		if(playerData[playerid][iscourier])
		{
			// Cancel the job
			SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}You left your vehicle, mission cancelled.");
			playerData[playerid][iscourier] = false;
			playerData[playerid][playerCourierLevel] = 0;
			RemovePlayerMapIcon(playerid, 90);
			DestroyDynamicRaceCP(playerData[playerid][playerLastCourierCP]);
			TextDrawHideForPlayer(playerid, TDCourier2);
			TextDrawHideForPlayer(playerid, TDCourier);
			KillTimer(playerData[playerid][courierTimer]);
			TogglePlayerControllable(playerid, 1);
			DisablePlayerCheckpoint(playerid);
			KillTimer(playerData[playerid][courierDistance]);
			PlayerTextDrawSetString(playerid, playerData[playerid][playerCourierDistanceTD], " ");
		}
		else if (playerData[playerid][truckingStatus] > 0)
		{
			// Player has 10 seconds to re-enter the truck
			KillTimer(playerData[playerid][truckExitTimer]);
			playerData[playerid][truckExitTimer] = SetTimerEx("exitTruck", 1000, true, "i", playerid);
			playerData[playerid][truckCounter] = 10;
		}
		else if (playerData[playerid][forkliftStatus] > 0)
		{
		    return cmd_cancelforklift(playerid, "");
		}
		else if (playerData[playerid][busStatus] > 0)
		{
		    return cmd_cancelroute(playerid, "");
		}
		else if (playerData[playerid][sweepStatus] > 0)
		{
		    return cmd_cancelsweep(playerid, "");
		}
		else if (playerData[playerid][medicStatus] > 0)
		{
		    return cmd_cancelmedic(playerid, "");
		}
    }

	if(newstate == PLAYER_STATE_PASSENGER)
	{
		SetPlayerArmedWeapon(playerid, 0);
	}

    if(newstate == PLAYER_STATE_DRIVER)
    {
        // New Medic
		if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 416)
		{
		    if(playerData[playerid][playerClass] != CLASS_MEDIC)
		    {
			    if(playerData[playerid][playerLevel] != 6)
			    {
		            SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This job can only be used by medics.");
		            RemovePlayerFromVehicle(playerid);
				}
		    }
		    else
		    {
		        SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[MEDIC] {FFFFFF}To begin a mission, type {E6BD1A}/medic {FFFFFF}or press {E6BD1A}2");
		        GameTextForPlayer(playerid, "Type /medic or press 2 to start a mission.", 5000, 5);
		    }
		}
		
		if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 431)
		{
		    if(playerData[playerid][playerClass] != CLASS_CIVILIAN)
		    {
			    if(playerData[playerid][playerLevel] != 6)
			    {
		            SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This job can only be used by civilians.");
		            RemovePlayerFromVehicle(playerid);
				}
		    }
		    else
		    {
		        SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[BUS DRIVER] {FFFFFF}To begin a bus route, type {E6BD1A}/startroute {FFFFFF}or press {E6BD1A}2");
		        GameTextForPlayer(playerid, "Type /startroute or press 2 to start a mission.", 5000, 5);
		    }
		}
		
		if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 574)
		{
		    if(playerData[playerid][playerClass] != CLASS_CIVILIAN)
		    {
			    if(playerData[playerid][playerLevel] != 6)
			    {
		            SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This job can only be used by civilians.");
		            RemovePlayerFromVehicle(playerid);
				}
		    }
		    else
		    {
		        SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[SWEEPER] {FFFFFF}To begin a sweeper mission, type {E6BD1A}/sweep {FFFFFF}or press {E6BD1A}2");
		        GameTextForPlayer(playerid, "Type /sweep or press 2 to start a mission.", 5000, 5);
		    }
		}
		
    	for(new i; i < MAX_CLASS_CAR; i++)
    	{
			new checkCar = GetPlayerVehicleID(playerid);

	 		if(checkCar == classCarIndex[i])
	  		{
	  		    if(classCars[i][classID] == CLASS_CIVILIAN)
	  		    {
					if(GetVehicleModel(checkCar) == 423)
					{
					    if(playerData[playerid][playerJob] != JOB_DRUGDEALER)
					    {
						    if(playerData[playerid][playerLevel] != 6)
						    {
					            SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This vehicle can only be used by drug dealers.");
					            RemovePlayerFromVehicle(playerid);
							}
					    }
					}

					if(GetVehicleModel(checkCar) == 515 || GetVehicleModel(checkCar) == 414)
					{
					    if(playerData[playerid][playerClass] != CLASS_CIVILIAN)
					    {
						    if(playerData[playerid][playerLevel] != 6)
						    {
					            SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This job can only be used by civilians.");
					            RemovePlayerFromVehicle(playerid);
							}
					    }
					    else
					    {
					        SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[TRUCKING] {FFFFFF}To begin trucking, attach a trailer and type {E6BD1A}/trucking {FFFFFF}or press {E6BD1A}2");
					        GameTextForPlayer(playerid, "Type /trucking or press 2 to start a mission.", 5000, 5);
					    }
					}

					if(GetVehicleModel(checkCar) == 530)
					{
					    if(playerData[playerid][playerClass] != CLASS_CIVILIAN)
					    {
				            SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This job can only be used by civilians.");
				            RemovePlayerFromVehicle(playerid);
					    }
					    else
					    {
					        SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[DOCK WORKER] {FFFFFF}To begin this job, type {E6BD1A}/forklift {FFFFFF}or press {E6BD1A}2");
					        GameTextForPlayer(playerid, "Type /forklift or press 2 to start a mission.", 5000, 5);
					    }
					}
	  		    }
	  		    else if(classCars[i][classID] == CLASS_POLICE)
	  		    {
	   	    		if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
	        		{
			  		    if(playerData[playerid][playerLastLEO] != checkCar)
			  		    {
			  		        if (!playerData[playerid][mask])
			  		        {
			        		    SendClientMessage(playerid, COLOR_WHITE, "{E6BD1A}[CRIME] {FFFFFF}You stole a LEO vehicle and received {E6BD1A}3 {FFFFFF}wanted!");
			        		    playerData[playerid][playerLastLEO] = checkCar;
			        		    givePlayerWanted(playerid, 3);
							}
						}
					}
				}
				else if(classCars[i][classID] == CLASS_ARMY)
				{
				    if(playerData[playerid][playerClass] != CLASS_ARMY)
				    {
				        if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
				        {
				  		    if(playerData[playerid][playerLastLEO] != checkCar)
				  		    {
				  		        if (!playerData[playerid][mask])
				  		        {
						            SendClientMessage(playerid, COLOR_WHITE, "{E6BD1A}[CRIME] {FFFFFF}You tried to steal an army vehicle and received {E6BD1A}3 {FFFFFF}wanted!");
						            playerData[playerid][playerLastLEO] = checkCar;
						            givePlayerWanted(playerid, 3);
								}
							}
				        }

				        RemovePlayerFromVehicle(playerid);

				    }
				}
				else if(classCars[i][classID] == CLASS_FBI)
				{
			        if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
			        {
			  		    if(playerData[playerid][playerLastLEO] != checkCar)
			  		    {
			  		        if (!playerData[playerid][mask])
			  		        {
					            SendClientMessage(playerid, COLOR_WHITE, "{E6BD1A}[CRIME] {FFFFFF}You stole a LEO vehicle and received {E6BD1A}3 {FFFFFF}wanted!");
								playerData[playerid][playerLastLEO] = checkCar;
					            givePlayerWanted(playerid, 3);
					            playerData[playerid][playerLastLEO] = checkCar;
							}
						}
			        }
				}
				else if(classCars[i][classID] == CLASS_SECRETSERVICE)
				{
				    if(playerData[playerid][playerClass] != CLASS_SECRETSERVICE)
				    {
				        if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
				        {
				  		    if(playerData[playerid][playerLastLEO] != checkCar)
				  		    {
				  		        if (!playerData[playerid][mask])
				  		        {
						            SendClientMessage(playerid, COLOR_WHITE, "{E6BD1A}[CRIME] {FFFFFF}You tried to steal a secret service vehicle and received {E6BD1A}3 {FFFFFF}wanted!");
						            playerData[playerid][playerLastLEO] = checkCar;
						            givePlayerWanted(playerid, 3);
								}
							}
				        }

				        RemovePlayerFromVehicle(playerid);

				    }
				}
			}
		}

		return 1;
	}

    return 1;
}

stock strmatch(const String1[], const String2[])
{
    if ((strcmp(String1, String2, true, strlen(String2)) == 0) && (strlen(String2) == strlen(String1)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

public OnPlayerPickUpPickup(playerid, pickupid)
{
    if(pickupid == pickup_chute)
    {
        GivePlayerWeaponEx(playerid, 46, 1);
    }
    else if(pickupid == pickup_ss)
    {
        GivePlayerWeaponEx(playerid, 46, 1);
    }
    else if(pickupid == pickup_vhealth || pickupid == pickup_vhealth2)
    {
        // If VIP
		if (playerData[playerid][playerVIPLevel] >= 1)
		{
			SetPlayerHealth(playerid, 100);
		}
	}
	else if (pickupid == pickup_varmour || pickupid == pickup_varmour2)
	{
	    // If crim/top vip
        if (playerData[playerid][playerVIPLevel] == 1)
		{
		    SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be at-least Silver VIP to refill your armour.");
		}
		
        if (playerData[playerid][playerVIPLevel] == 2)
		{
		    SetPlayerArmour(playerid, 50);
		}
		
        if (playerData[playerid][playerVIPLevel] == 3)
		{
		    SetPlayerArmour(playerid, 99);
		}
		
		if (playerData[playerid][playerVIPLevel] == 4)
		{
		    SetPlayerArmour(playerid, 99);
		}
	}

	return 1;
}

public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
{
	if(newinteriorid == 90)
		SendClientMessage(playerid, COLOR_WHITE, "{FFFF00}[SUPA SAVE] {FFFFFF}Use /shop to buy items from Supa Save!");
	if(newinteriorid == 207)
		SendClientMessage(playerid, COLOR_WHITE, "{FFFF00}[THE SUPA] {FFFFFF}Use /shop to buy items from The Supa!");
	return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if((newkeys & KEY_WALK) && !(oldkeys & KEY_WALK))
	{
	    beginRobbery(playerid);
	}

    if((newkeys & KEY_JUMP) && !(oldkeys & KEY_JUMP) || (newkeys & KEY_SPRINT) && !(oldkeys & KEY_SPRINT))
	{
	    if (playerData[playerid][playerUsingAnim])
	    {
			ClearAnimations(playerid);
			SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
			playerData[playerid][playerUsingAnim] = false;
 	    }
	}

    if((newkeys & KEY_WALK) && !(oldkeys & KEY_WALK))
	{
	    new world = GetPlayerVirtualWorld(playerid);

	    if(world < 1)
	    {
			intoHouse(playerid);
			// intoBus(playerid);
 		}
	}

    if((newkeys & KEY_FIRE) && !(oldkeys & KEY_FIRE))
    {
        checkWeapons(playerid);
    }

    if((newkeys & KEY_WALK) && !(oldkeys & KEY_WALK))
	{
	   	leaveHouse(playerid, playerData[playerid][playerInsideHouse]);
	   	//leaveBus(playerid, playerData[playerid][playerInsideBusiness]);
	}

	if((newkeys & KEY_CROUCH) && !(oldkeys & KEY_CROUCH))
	{
		cancelRobbery(playerid);
	}

	if((newkeys & KEY_YES) && !(oldkeys & KEY_YES))
	{
		if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
		{
		    if(playerData[playerid][playerJob] == JOB_TERRORIST)
		    {
		        detonateExplosives(playerid);
		  	}
		}
	}

	if((newkeys & KEY_SUBMISSION) && !(oldkeys & KEY_SUBMISSION))
	{
		if(playerData[playerid][playerClass] == CLASS_ARMY || playerData[playerid][playerClass] == CLASS_SECRETSERVICE)
		{
			if(IsPlayerInAnyVehicle(playerid))
			{
				new vehid = GetVehicleModel(GetPlayerVehicleID(playerid)), Float:xx, Float:xy, Float:xz;
				if((vehid == 487 || vehid == 447 || vehid == 469 || vehid == 487  || vehid == 488 || vehid == 497 || vehid == 548) && (GetPlayerVehicleSeat(playerid) != 0))
				{
					GetVehiclePos(GetPlayerVehicleID(playerid), xx, xy, xz);
					if(xz > 500.0)
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}It's too high to start rappeling.");
						return 1;
					}
					if(GetVehicleSpeed(GetPlayerVehicleID(playerid)) < 50)
					{
						RemovePlayerFromVehicle(playerid);
						Rappel[playerid] = 1;
						SetTimerEx("DeActivateRappel", 5000, 0, "i", playerid);
					}
					else
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You can't start rappeling, this heli is too fast.");
				}
			}
		}
		if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
		{
			if(IsPlayerInAnyVehicle(playerid))
			{
			    // Trucking
		 		if (GetVehicleModel(GetPlayerVehicleID(playerid)) == 515 || GetVehicleModel(GetPlayerVehicleID(playerid)) == 414)
				{
                    return cmd_trucking(playerid, "");
				}
				
			    // Bus Driver
		 		if (GetVehicleModel(GetPlayerVehicleID(playerid)) == 431)
				{
                    return cmd_startroute(playerid, "");
				}
				
		 		if (GetVehicleModel(GetPlayerVehicleID(playerid)) == 574)
				{
                    return cmd_sweep(playerid, "");
				}

				// Forklift
				if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 530)
				{
                    return cmd_forklift(playerid, "");
				}
			}
		}

		if(playerData[playerid][playerClass] == CLASS_MEDIC)
		{
			if(IsPlayerInAnyVehicle(playerid))
			{
				// Medic
				if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 416)
				{
	                return cmd_medic(playerid, "");
				}
			}
		}
	}

    if(newkeys & KEY_JUMP && !(oldkeys & KEY_JUMP) && GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_CUFFED) ApplyAnimation(playerid, "GYMNASIUM", "gym_jog_falloff",4.1,0,1,1,0,0);
    
    cbugKeys(playerid, newkeys, oldkeys);

	return 1;
}

public OnRconLoginAttempt(ip[], password[], success)
{
	if(!strcmp(ip, "83.183.17.204", true) || !strcmp(ip, "82.30.157.229") || !strcmp(ip, "82.3.86.182") || !strcmp(ip, "83.226.34.213", true) || !strcmp(ip, "127.0.0.1", true))
	{
		if(!success)
	    {
			for(new i = 0; i < MAX_PLAYERS; i++)
			{
				if(IsPlayerConnected(i) && playerData[i][playerLevel] >= 5)
				{
				    new messageContent[128];
					format(messageContent, sizeof(messageContent), "{FFDC2E}[RCON ALERT] {FFFFFF}Failed RCON login attempt by {FFDC2E}%s.", ip);
					SendClientMessage(i, COLOR_WHITE, messageContent);

					return 0;
				}
			}
		}

		return 1;
	}
	else
	{
		for(new i = 0; i < MAX_PLAYERS; i++)
		{
			if(IsPlayerConnected(i) && playerData[i][playerLevel] >= 5)
			{
			    new messageContent[128];
				format(messageContent, sizeof(messageContent), "{FFDC2E}[RCON ALERT] {FFFFFF}Unknown IP address {FFDC2E}%s {FFFFFF}attempted to login to RCON.", ip);
				SendClientMessage(i, COLOR_WHITE, messageContent);
			}
		}

		return 0;
	}
}

/*PRIVATE: GetXYZInFrontOfPlayer(playerid, &Float: x, &Float: y, &Float: z, Float: distance)
{
	new Float: a;

	GetPlayerPos (playerid, x, y, z);
	GetPlayerFacingAngle (playerid, a);

	x += (distance * floatsin (-a, degrees));
	y += (distance * floatcos (-a, degrees));
}*/

public OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat)
{
	//ac_CarTeleport(playerid, vehicleid);
	
    /*if (GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && GetVehicleDistanceFromPoint (vehicleid, vWarped[vehicleid][vehiclePositionX], vWarped[vehicleid][vehiclePositionY], vWarped[vehicleid][vehiclePositionZ]) > 20.0)
    {
        new Float: x, Float: y, Float: z;

        GetXYZInFrontOfPlayer(playerid, x, y, z, 5.0);
        if (GetVehicleDistanceFromPoint (vehicleid, x, y, z) < 10.0)
        {
            SetVehicleToRespawn(vehicleid);
        }
    }*/

	return 1;
}

public OnPlayerUpdate(playerid)
{
    if(ac_OnPlayerUpdate(playerid) == 0) return 0;
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		for(new i = 0; i < sizeof(Spikes); i++)
		{
			if(Spikes[i][spCreated] == 1)
            {
				if(IsPlayerInRangeOfPoint(playerid, 2.0, Spikes[i][spX], Spikes[i][spY], Spikes[i][spZ]))
				{
					new panels, doors, lights, tires, idVeh;
					idVeh = GetPlayerVehicleID(playerid);
					GetVehicleDamageStatus(idVeh, panels, doors, lights, tires);
					UpdateVehicleDamageStatus(idVeh, panels, doors, lights, 15);
				}
			}
		}
	}
	
    new anim = GetPlayerAnimationIndex(playerid);
    //Check if the animation applied is CAR_getin_LHS/RHS
    if(anim == 1026 || anim == 1027)
    {
        g_EnterAnim{playerid} = true;
    }
    
	if(playerData[playerid][isInFallout])
	{
		new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
		if(z < 2.0)
		{
   			SetCameraBehindPlayer(playerid);
			SpawnPlayer(playerid);
		}
	}
	updateCbug(playerid);
	if(Rappel[playerid] == 0) return 1;
    if(GetPlayerAnimationIndex(playerid) && (IsRappelling[playerid] == 0))
    {
        new animlib[32];
        new animname[32];
        GetAnimationName(GetPlayerAnimationIndex(playerid),animlib,32,animname,32);
        if((!strcmp(animlib, "PED", true, 3)) && (!strcmp(animname, "FALL_fall", true, 9)))
        {
           RappelPlayer(playerid);
           IsRappelling[playerid] = 1;
           GetPlayerHealth(playerid, PlayerHealth[playerid]);
           SetPlayerHealth(playerid, 999999.0);
           LandingChecker[playerid] = SetTimerEx("FallingChecker",500,1,"i",playerid);
        }
    }
    return 1;
}


public OnPlayerEnterCheckpoint(playerid)
{
    if(playerData[playerid][playerCourierLevel] == 1 && GetVehicleModel(GetPlayerVehicleID(playerid)) == 593)
	{
        // Assign a random pick-up location
		TogglePlayerControllable(playerid, 0);
        TextDrawShowForPlayer(playerid, TDCourier);

        playerData[playerid][courierTimer] = SetTimerEx("CourierWaitLoad", 3000, false, "i", playerid);

        new rand = random(4);

        if (rand == 0)
        {
            // Drop-off location 1
            SetPlayerCheckpoint(playerid, -1159.2885, -1115.1556, 128.2656, 10);
		}
		else if(rand == 1)
		{
		    // Drop-off location 2
		    SetPlayerCheckpoint(playerid, 1613.6582, -2629.8169, 13.5469, 10);
		}
		else if(rand == 2)
		{
		    // Drop-off location 3
		    SetPlayerCheckpoint(playerid, -1378.5120, -1466.8733, 101.8131, 10);
		}
		else if(rand == 3)
		{
		    // Drop-off location 4
		    SetPlayerCheckpoint(playerid, -1108.9940, -1653.5695, 76.3672, 10);
		}
		else if(rand == 4)
		{
		    // Drop-off location 5
		    SetPlayerCheckpoint(playerid, -368.9295, -1048.7743, 59.3404, 10);
		}

		playerData[playerid][playerCourierLevel] = 2;

	}
	else if(playerData[playerid][playerCourierLevel] == 2 && GetVehicleModel(GetPlayerVehicleID(playerid)) == 593)
	{
		// Unloading
		TogglePlayerControllable(playerid, 0);
        TextDrawShowForPlayer(playerid, TDCourier2);
		playerData[playerid][courierTimer] = SetTimerEx("CourierWaitUnload", 3000, false, "i", playerid);
	}
	return 1;
}

public OnPlayerEnterDynamicRaceCP(playerid, checkpointid)
{
	if (playerData[playerid][truckingStatus]) // Player is currently trucking
	{
		//
		// Check mission type
		if (GetVehicleModel(GetPlayerVehicleID(playerid)) == 515 || GetVehicleModel(GetPlayerVehicleID(playerid)) == 414)
		{
		    if(GetVehicleTrailer(GetPlayerVehicleID(playerid)) || GetVehicleModel(GetPlayerVehicleID(playerid)) == 414)
			{
				new tickCountResult = GetTickCount(), reducedValue;
				reducedValue = tickCountResult - playerData[playerid][playerMissionCPTime];

                if(reducedValue > 20000)
                {
					//
					// Check mission status
					if (playerData[playerid][truckingStatus] == 1)
					{
						//
						// Pickup - Wait 5 seconds for pick-up
						TogglePlayerControllable(playerid, 0);

						// Gametext
	                    PlayerTextDrawSetString(playerid, playerData[playerid][playerTruckingTD], "LOADING CARGO");
						PlayerTextDrawSetString(playerid, playerData[playerid][playerTruckingWaitTD], "please wait");

						//
						// Initiate 5 second wait timer
						playerData[playerid][truckLoadTimer] = SetTimerEx("loadTrailer", 3000, false, "i", playerid);
					}
					else
					{
						//
						// Deliver
						TogglePlayerControllable(playerid, 0);

						// Gametext
	                    PlayerTextDrawSetString(playerid, playerData[playerid][playerTruckingTD], "UNLOADING CARGO");
						PlayerTextDrawSetString(playerid, playerData[playerid][playerTruckingWaitTD], "please wait");

						//
						// Initiate 5 second wait timer
						playerData[playerid][truckLoadTimer] = SetTimerEx("loadTrailer", 3000, false, "i", playerid);
					}
				}
			}
			else
			{
			    SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be towing a trailer to pickup/dropoff cargo.");
			}
		}
	}
	
	if (playerData[playerid][medicStatus] > 0)
	{
		if (GetVehicleModel(GetPlayerVehicleID(playerid)) == 416)
		{
			medicProgress(playerid);
		}
	}
	
	if(playerData[playerid][busStatus] > 0)
	{
		if (GetVehicleModel(GetPlayerVehicleID(playerid)) == 431)
		{
			new tickCountResult = GetTickCount(), reducedValue;
			reducedValue = tickCountResult - playerData[playerid][playerMissionCPTime];

            if(reducedValue > 8000)
            {
				nextStop(playerid);
			}
		}
	}
	
	if(playerData[playerid][sweepStatus] > 0)
	{
		if (GetVehicleModel(GetPlayerVehicleID(playerid)) == 574)
		{
			new tickCountResult = GetTickCount(), reducedValue;
			reducedValue = tickCountResult - playerData[playerid][playerMissionCPTime];

            if(reducedValue > 8000)
            {
				nextSweep(playerid);
			}
		}
	}

	if(playerData[playerid][forkliftStatus] > 0)
	{
		if (GetVehicleModel(GetPlayerVehicleID(playerid)) == 530)
		{
			new tickCountResult = GetTickCount(), reducedValue;
			reducedValue = tickCountResult - playerData[playerid][playerMissionCPTime];

            if(reducedValue > 8000)
            {
				//
				// Check mission status
				if (playerData[playerid][forkliftStatus] == 1)
				{
					// Pickup
					forklift_pickup(playerid);

					playerData[playerid][playerMissionCPTime] = GetTickCount();
				}
				else
				{
					// Dropoff
					forklift_dropoff(playerid);

					playerData[playerid][playerMissionCPTime] = GetTickCount();
				}
			}
		}
	}
	else
	{
		if(playerData[playerid][playerCourierLevel] == 3 && GetVehicleModel(GetPlayerVehicleID(playerid)) == 482)
		{
		    // Load parcels onto van
			TogglePlayerControllable(playerid, 0);
	        TextDrawShowForPlayer(playerid, TDCourier);
			playerData[playerid][courierTimer] = SetTimerEx("CourierWaitVanLoad", 3000, false, "i", playerid);
		}
		else if(playerData[playerid][playerCourierLevel] == 4 && GetVehicleModel(GetPlayerVehicleID(playerid)) == 482)
		{
		    // Unload parcels from van
		    if(playerData[playerid][playerCourierItems] > 1)
		    {
	 			TogglePlayerControllable(playerid, 0);
	            TextDrawShowForPlayer(playerid, TDCourier2);
				playerData[playerid][courierTimer] = SetTimerEx("CourierWaitVanUnload", 3000, false, "i", playerid);
			}
			else
			{
	 			TogglePlayerControllable(playerid, 0);
	            TextDrawShowForPlayer(playerid, TDCourier2);
				playerData[playerid][courierTimer] = SetTimerEx("CourierWaitVanComplete", 3000, false, "i", playerid);
			}
		}
 	}

	return 1;
}

public OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
{
    if(IsPlayerAdmin(playerid))
    {
        SetPlayerPosFindZ(playerid, fX, fY, fZ);
        return 1;
    }

    return 1;
}

public OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid)
{
    if(issuerid != INVALID_PLAYER_ID && playerData[issuerid][isInDM])
    {
        return 0;
	}
	
    if(issuerid != INVALID_PLAYER_ID && playerData[issuerid][isInEvent])
    {
        return 0;
	}
	
	if (playerData[playerid][isInDM])
	{
 		return 0;
 	}
 	
 	if (playerData[playerid][isInEvent])
	{
 		return 0;
 	}

    if(issuerid != INVALID_PLAYER_ID)
    {
		if(playerData[issuerid][playerHitmarker])
		{
			new string[128];

			format(string, sizeof(string), "%0.2f damage", amount);
			PlayerTextDrawSetString(issuerid, playerData[issuerid][playerHitmarkerTD], string);
			SetTimerEx("hideHitmarkerTD", 2000, false, "i", issuerid);
			PlayerPlaySound(issuerid, 17802, 0.0, 0.0, 0.0);
		}

		if(playerData[issuerid][playerClass] == CLASS_CIVILIAN || playerData[issuerid][playerClass] == CLASS_FIREFIGHTER || playerData[issuerid][playerClass] == CLASS_MEDIC)
		{
			if(playerData[playerid][playerClass] == CLASS_ARMY || playerData[playerid][playerClass] == CLASS_POLICE || playerData[playerid][playerClass] == CLASS_CIA || playerData[playerid][playerClass] == CLASS_FBI || playerData[playerid][playerClass] == CLASS_SECRETSERVICE)
			{
				if(playerData[issuerid][playerWantedLevel] == 0)
				{
					if(playerData[playerid][playerJailTime] <= 0)
					{
						givePlayerWanted(issuerid, 6);
						sendWantedMessage(issuerid, 6);
						newPlayerColour(issuerid);
					}
				}
			}
		}
		else if(playerData[issuerid][playerClass] == CLASS_POLICE || playerData[issuerid][playerClass] == CLASS_ARMY || playerData[issuerid][playerClass] == CLASS_CIA  || playerData[issuerid][playerClass] == CLASS_FBI || playerData[issuerid][playerClass] == CLASS_SECRETSERVICE)
		{
		    if(playerData[playerid][playerClass] == CLASS_CIVILIAN || playerData[playerid][playerClass] == CLASS_FIREFIGHTER || playerData[playerid][playerClass] == CLASS_MEDIC)
		    {
		        if (playerData[playerid][playerWantedLevel] == 0)
		        {
					new Float:theirHealth;
	            	GetPlayerHealth(playerid, theirHealth);
	            	SetPlayerHealth(playerid, theirHealth - 0);
				}
		    }
		}
		else if (playerData[issuerid][playerAdminDuty])
		{
		    GameTextForPlayer(issuerid, "You're AoD! Do not harm players!", 3000, 4);
		}
	}

    return 1;
}

// System for vip verification
forward check_vip(index, response_code, data[]);
public check_vip(index, response_code, data[])
{
    if(response_code == 200)
    {
        new get_data[20], string[500];
        format(get_data, sizeof(get_data), "%s", data);

		new redeem = strval(get_data);
		switch(redeem)
		{
		    case 1: // Premium Redemption
		    {
			    playerData[index][vipExpires] = gettime() + 2592000;
				playerData[index][playerVIPLevel] = 1;
				savePlayerStats(index);
				
				format(string, sizeof(string), "%s{98B0CD}Online Code Redemption Service\n\n", string);
				format(string, sizeof(string), "%s{FFFFFF}{58D3F7}Successfully Redeemed! \n\n", string);
				format(string, sizeof(string), "%s{FFFFFF}Your code has been redeemed and your membership is now active.\n\n", string);
				format(string, sizeof(string), "%s{FFFFFF}Type {58D3F7}/viphelp{FFFFFF} to view a list of commands that are\n", string);
				format(string, sizeof(string), "%s{FFFFFF}presently available to you.\n\n", string);
				format(string, sizeof(string), "%s{FFFFFF}Thanks for supporting the server!", string);
				
				ShowPlayerDialog(index, DIALOG_VIP_ALREADY, DIALOG_STYLE_MSGBOX, "Code Redemption", string, "OK", "");
				SendClientMessage(index, COLOR_WHITE, "{58D3F7}[VIP AWARDED] {FFFFFF}Your VIP purchase has been activated. /viphelp to view a list of VIP content.");
		    }


		    case 101: // Code already redeemed
		    {
				format(string, sizeof(string), "%s{98B0CD}CNRSF Code Redemption Service\n\n", string);
				format(string, sizeof(string), "%s{FFFFFF}{58D3F7}This code has already been redeemed. \n\n", string);
				format(string, sizeof(string), "%s{FFFFFF}This code was already redeemed by a player.\n", string);
				format(string, sizeof(string), "%s{FFFFFF}If you believe this to be an error, please contact a shop admin.\n\n", string);

				format(string, sizeof(string), "%s{58D3F7}http://shop.sfcnr.in", string);

				ShowPlayerDialog(index, DIALOG_VIP_ALREADY, DIALOG_STYLE_MSGBOX, "Code Redemption", string, "OK", "");
		    }

		    case 102: // Code doesn't exist
		    {
				format(string, sizeof(string), "%s{98B0CD}CNRSF Code Redemption Service\n\n", string);
				format(string, sizeof(string), "%s{FFFFFF}{58D3F7}Unable to find the redemption code. \n\n", string);
				format(string, sizeof(string), "%s{FFFFFF}The redemption code you entered is invalid.\n", string);
				format(string, sizeof(string), "%s{FFFFFF}Try entering it again, or contact a shop admin for assistance.\n\n", string);

				format(string, sizeof(string), "%s{58D3F7}http://shop.sfcnr.in", string);

				ShowPlayerDialog(index, DIALOG_VIP_ALREADY, DIALOG_STYLE_MSGBOX, "Code Redemption", string, "OK", "");
		    }
		}
    }
    else // Error whilst attempting to redeem code from store
    {
        SendClientMessage(index, COLOR_WHITE, "HTTP Error - Please try again later.");
    }
}

forward check_code(index, response_code, data[]);
public check_code(index, response_code, data[])
{
    if(response_code == 200)
    {
        new get_data[20], string[500];
        format(get_data, sizeof(get_data), "%s", data);

		new redeem = strval(get_data);
		switch(redeem)
		{
		    case 3: // Easy Stretch
		    {
		        if (playerData[index][playerJailTime] > 20)
		        {
					// Release from jail
					SetPlayerInterior(index, 10);
					SetPlayerPos(index, 216.8014, 120.5791, 999.0156);
					SetPlayerFacingAngle(index, 183.3742);
					SetPlayerVirtualWorld(index, 25);
					SetPlayerHealth(index, 100);
					PlayerTextDrawSetString(index, playerData[index][playerJailTimerTD], " ");
					playerData[index][playerJailTime] = 0;
					KillTimer(playerData[index][jailTimer]);

					new Name[24], MsgAll[200];
					GetPlayerName(index, Name, sizeof(Name));

					for(new p; p < MAX_PLAYERS; p++)
					{
						new pName[24];
						GetPlayerName(p, pName, sizeof(pName));

						if(!strcmp(pName, Name))
						{
							SendClientMessage(p, COLOR_WHITE, "{58D3F7}[EASY STRETCH] {FFFFFF}You have been released from jail.");
						}
						else
						{
							format(MsgAll, sizeof(MsgAll), "{FFDC2E}[JAIL] {FFFFFF}%s(%i) has been released from jail {58D3F7}[Easy Stretch]{FFFFFF}", Name, index);
							SendClientMessage(p, COLOR_WHITE, MsgAll);
						}
					}

					savePlayerStats(index);

					disableAchieve(index);
					PlayerTextDrawShow(index, playerData[index][Achieve1]);
					PlayerTextDrawShow(index, playerData[index][Achieve2]);
					PlayerTextDrawShow(index, playerData[index][Achieve3]);
					PlayerTextDrawShow(index, playerData[index][Achieve4]);

					PlayerTextDrawSetString(index, playerData[index][Achieve3], "Redeemed Shop Item");
					PlayerTextDrawSetString(index, playerData[index][Achieve4], "You redeemed an item, thanks!");
					PlayerPlaySound(index, 1183 ,0.0, 0.0, 0.0);

					playerData[index][achieveTimer] = SetTimerEx("disableAchieve", 6000, false, "i", index);
				}
				else
				{
				    SendClientMessage(index, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot redeem this code right now.");
				}
		    }
		    
		    case 4: // XP/Score
		    {
		        if (serverInfo[doubleXP])
		        {
		        	playerGiveXP(index, 2500);
				}
				else
				{
				    playerGiveXP(index, 5000);
				}
				
				playerData[index][playerScore] = playerData[index][playerScore] + 1000;
				SetPlayerScore(index, playerData[index][playerScore]);
		        
		        savePlayerStats(index);
		        
		        SendClientMessage(index, COLOR_WHITE, "{58D3F7}[XP/SCORE PACK] {FFFFFF}XP and score has been added to your account.");
		        
				disableAchieve(index);
				PlayerTextDrawShow(index, playerData[index][Achieve1]);
				PlayerTextDrawShow(index, playerData[index][Achieve2]);
				PlayerTextDrawShow(index, playerData[index][Achieve3]);
				PlayerTextDrawShow(index, playerData[index][Achieve4]);

				PlayerTextDrawSetString(index, playerData[index][Achieve3], "Redeemed Shop Item");
				PlayerTextDrawSetString(index, playerData[index][Achieve4], "You redeemed an item, thanks!");
				PlayerPlaySound(index, 1183 ,0.0, 0.0, 0.0);

				playerData[index][achieveTimer] = SetTimerEx("disableAchieve", 6000, false, "i", index);
		    }
		    
		    case 101: // Code already redeemed
		    {
				format(string, sizeof(string), "%s{98B0CD}CNRSF Code Redemption Service\n\n", string);
				format(string, sizeof(string), "%s{FFFFFF}{58D3F7}This code has already been redeemed. \n\n", string);
				format(string, sizeof(string), "%s{FFFFFF}This code was already redeemed by a player.\n", string);
				format(string, sizeof(string), "%s{FFFFFF}If you believe this to be an error, please contact a shop admin.\n\n", string);

				format(string, sizeof(string), "%s{58D3F7}http://shop.underprogress.com", string);

				ShowPlayerDialog(index, DIALOG_VIP_ALREADY, DIALOG_STYLE_MSGBOX, "Code Redemption", string, "OK", "");
		    }

		    case 102: // Code doesn't exist
		    {
				format(string, sizeof(string), "%s{98B0CD}CNRSF Code Redemption Service\n\n", string);
				format(string, sizeof(string), "%s{FFFFFF}{58D3F7}Unable to find the redemption code. \n\n", string);
				format(string, sizeof(string), "%s{FFFFFF}The redemption code you entered is invalid.\n", string);
				format(string, sizeof(string), "%s{FFFFFF}Try entering it again, or contact a shop admin for assistance.\n\n", string);

				format(string, sizeof(string), "%s{58D3F7}http://shop.underprogress.com", string);

				ShowPlayerDialog(index, DIALOG_VIP_ALREADY, DIALOG_STYLE_MSGBOX, "Code Redemption", string, "OK", "");
		    }
		}
    }
    else // Error whilst attempting to redeem code from store
    {
        SendClientMessage(index, COLOR_WHITE, "HTTP Error - Please try again later.");
    }
}
