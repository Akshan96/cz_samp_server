forward CourierWaitLoad(playerid);
forward CourierWaitUnload(playerid);
forward CourierWaitVanLoad(playerid);
forward CourierWaitVanUnload(playerid);
forward CourierWaitVanComplete(playerid);
forward CourierDistance(playerid);

/*
enum courierMissions
{
	itemType[48],
	storeName[48],
	checkpointPosition[3],
	missionType
}

new courierMissionData[12][courierMissions] =
{
	{"Flowers", "mortuary", {1.0, 2.0, 3.0}, 1},
	{"Number plates", "Wang Cars", {1.0, 2.0, 3.0}, 1},
	{"Statue of Jesus", "the Church", {1.0, 2.0, 3.0}, 1},
	{"Super glue", "Michelle's auto repair", {1.0, 2.0, 3.0}, 1},
	{"Pizza boxes", "Well Stacked Pizza", {1.0, 2.0, 3.0}, 1},
	{"Fresh condoms", "The Pleasure Dome", {1.0, 2.0, 3.0}, 1},
	{"Used needles", "the Hospital", {1.0, 2.0, 3.0}, 1},
	{"Donut filling", "Tuff Nut Donuts", {1.0, 2.0, 3.0}, 1},
	{"Handcuffs", "the CIA HQ", {1.0, 2.0, 3.0}, 1},
	{"RC motors", "Zero's RC Store", {1.0, 2.0, 3.0}, 1},
	{"Steroids", "the gym", {1.0, 2.0, 3.0}, 1},
	{"Fake licenses", "the driving school", {1.0, 2.0, 3.0}, 1}
};
*/

public CourierWaitLoad(playerid)
{
	TogglePlayerControllable(playerid, 1);
	TextDrawHideForPlayer(playerid, TDCourier);
	PlayerPlaySound(playerid, 1149, 0.0, 0.0, 10.0);	
	SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}Cargo is ready to deliver, go to the drop off point.");
}

public CourierWaitUnload(playerid)
{
	TogglePlayerControllable(playerid, 1);
	TextDrawHideForPlayer(playerid, TDCourier2);
	
	PlayerPlaySound(playerid, 1149, 0.0, 0.0, 10.0);
	
	DisablePlayerCheckpoint(playerid);
	playerData[playerid][iscourier] = false;	
	playerData[playerid][playerCourierLevel] = 0;
	playerData[playerid][playerCourierItems] = 0;
	
	new Money;
	Money = randomEx(5000, 15000);
	
	PlayerPlaySound(playerid, 1149, 0.0, 0.0, 10.0);
	playerGiveMoney(playerid, Money);
	playerGiveXP(playerid, 10);
	playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
	SetPlayerScore(playerid, playerData[playerid][playerScore]);
	
	for(new p; p < MAX_PLAYERS; p++)
	{
		new pName[24];
		GetPlayerName(p, pName, sizeof(pName));

		if(!strcmp(pName, playerData[playerid][playerNamee]))
		{
			new Msg[128];
			format(Msg, sizeof(Msg), "{FE9A2E}[SUCCESS] {FFFFFF}You completed the courier mission and received {FFDC2E}$%i", Money);
			SendClientMessage(p, COLOR_WHITE, Msg);
		}
		else
		{
			new MsgAll[128];
			format(MsgAll, sizeof(MsgAll), "{FFDC2E}[COURIER] {FFFFFF}%s(%i) successfully completed a courier mission and received {FFDC2E}$%i", playerData[playerid][playerNamee], playerid, Money);
			SendClientMessage(p, COLOR_WHITE, MsgAll);
		}
	}
}

public CourierDistance(playerid)
{
	new distance[50], Float:fDistance = GetVehicleDistanceFromPoint(GetPlayerVehicleID(playerid), playerData[playerid][CourierX], playerData[playerid][CourierY], playerData[playerid][CourierZ]);
	format(distance, sizeof(distance), "Distance Remaining: %f", fDistance);
	PlayerTextDrawSetString(playerid, playerData[playerid][playerCourierDistanceTD], distance);
}

public CourierWaitVanLoad(playerid)
{
	TogglePlayerControllable(playerid, 1);
	TextDrawHideForPlayer(playerid, TDCourier2);
	
	playerData[playerid][playerCourierItems] = 5;
	
	PlayerPlaySound(playerid, 1149, 0.0, 0.0, 10.0);
	
	new Msg[128];
	format(Msg, sizeof(Msg), "{FFDC2E}[COURIER] {FFFFFF}Your van has been loaded. You have %i items left to deliver.", playerData[playerid][playerCourierItems]);
	SendClientMessage(playerid, COLOR_WHITE, Msg);
	
	TextDrawHideForPlayer(playerid, TDCourier);
	playerData[playerid][playerCourierLevel] = 4;
	DestroyDynamicRaceCP(playerData[playerid][playerLastCourierCP]);
	RemovePlayerMapIcon(playerid, 17 + playerid);
	
	// Random location
	new randomloc = random(11);
	if (randomloc == 0)
	{ 
		playerData[playerid][playerLastCourierCP] = CreateDynamicRaceCP(1, -2010.7465, -28.4315, 35.0699, -2010.7465, -28.4315, 35.0699, 5, -1, -1, playerid, 100.0);
		SetPlayerMapIcon(playerid, MAP_ICON_COURIER_VAN, -2010.7465, -28.4315, 35.0699, 51, 0, MAPICON_GLOBAL);
		SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}Deliver flowers to the mortuary."); 
		//deliveryTD = TextDrawCreate(320.000000, 424.000000, "Deliver ~g~flowers ~w~to ~y~the mortuary");
		
		playerData[playerid][CourierX] = -2010.7465;
		playerData[playerid][CourierY] = -28.4315;
		playerData[playerid][CourierZ] = 35.0699;
		
	}
	if (randomloc == 1)
	{ 
		playerData[playerid][playerLastCourierCP] = CreateDynamicRaceCP(1, -1972.8068, 296.6461, 35.1719, -1972.8068, 296.6461, 35.1719, 5, -1, -1, playerid, 100.0);
		SetPlayerMapIcon(playerid, MAP_ICON_COURIER_VAN, -1972.8068, 296.6461, 35.1719, 51, 0, MAPICON_GLOBAL);
		SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}Deliver number plates to Wang Cars."); 
		//deliveryTD = TextDrawCreate(320.000000, 424.000000, "Deliver ~g~number plates ~w~to ~y~Wang Cars");
		
		playerData[playerid][CourierX] = -1972.8068;
		playerData[playerid][CourierY] = -296.6461;
		playerData[playerid][CourierZ] = 35.1719;
		
	}
	if (randomloc == 2)
	{ 
		playerData[playerid][playerLastCourierCP] = CreateDynamicRaceCP(1, -1981.1639, 1117.7991, 53.123, -1981.1639, 1117.7991, 53.123, 5, -1, -1, playerid, 100.0);
		SetPlayerMapIcon(playerid, MAP_ICON_COURIER_VAN, -1981.1639, 1117.7991, 53.123, 51, 0, MAPICON_GLOBAL);
		SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}Deliver a statue of Jesus to the Church."); 
		//deliveryTD = TextDrawCreate(320.000000, 424.000000, "Deliver ~g~a statue of Jesus ~w~to ~y~the Church");
		
		playerData[playerid][CourierX] = -1981.1639;
		playerData[playerid][CourierY] = 1117.7991;
		playerData[playerid][CourierZ] = 53.123;
		
	}
	if (randomloc == 3)
	{ 
		playerData[playerid][playerLastCourierCP] = CreateDynamicRaceCP(1, -1799.9474, 1198.5742, 25.1194, -1799.9474, 1198.5742, 25.1194, 5, -1, -1, playerid, 100.0);
		SetPlayerMapIcon(playerid, MAP_ICON_COURIER_VAN, -1799.9474, 1198.5742, 25.1194, 51, 0, MAPICON_GLOBAL);
		SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}Deliver super glue to Michelle's auto repair shop."); 
		//deliveryTD = TextDrawCreate(320.000000, 424.000000, "Deliver ~g~super glue ~w~to ~y~Michelle's auto repair shop");
		
		playerData[playerid][CourierX] = -1799.9474;
		playerData[playerid][CourierY] = 1198.5742;
		playerData[playerid][CourierZ] = 25.1194;
		
	}
	if (randomloc == 4)
	{ 
		playerData[playerid][playerLastCourierCP] = CreateDynamicRaceCP(1, -1719.1584, 1367.1101, 7.1875, -1719.1584, 1367.1101, 7.1875, 5, -1, -1, playerid, 100.0);
		SetPlayerMapIcon(playerid, MAP_ICON_COURIER_VAN, -1719.1584, 1367.1101, 7.1875, 51, 0, MAPICON_GLOBAL);
		SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}Deliver pizza boxes to Well Stacked Pizza."); 
		//deliveryTD = TextDrawCreate(320.000000, 424.000000, "Deliver ~g~a pizza boxes ~w~to ~y~Well Stacked Pizza");
		
		playerData[playerid][CourierX] = -1719.1584;
		playerData[playerid][CourierY] = 1367.1101;
		playerData[playerid][CourierZ] = -1719.1584;
		
	}
	if (randomloc == 5)
	{ 
		playerData[playerid][playerLastCourierCP] = CreateDynamicRaceCP(1, -2622.6921, 1401.9629, 7.1016, -2622.6921, 1401.9629, 7.1016, 5, -1, -1, playerid, 100.0);
		SetPlayerMapIcon(playerid, MAP_ICON_COURIER_VAN, -2622.6921, 1401.9629, 7.1016, 51, 0, MAPICON_GLOBAL);
		SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}Deliver fresh condoms to the Pleasure Dome."); 
		//deliveryTD = TextDrawCreate(320.000000, 424.000000, "Deliver ~g~fresh condoms ~w~to ~y~the Pleasure Dome");
		
		playerData[playerid][CourierX] = -2622.6921;
		playerData[playerid][CourierY] = 1401.9629;
		playerData[playerid][CourierZ] = 7.1016;
		
	}
	if (randomloc == 6)
	{ 
		playerData[playerid][playerLastCourierCP] = CreateDynamicRaceCP(1, -2754.7322, 786.7725, 53.8057, -2754.7322, 786.7725, 53.8057, 5, -1, -1, playerid, 100.0);
		SetPlayerMapIcon(playerid, MAP_ICON_COURIER_VAN, -2754.7322, 786.7725, 53.8057, 51, 0, MAPICON_GLOBAL);
		SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}Deliver donut filling to Tuff Nut Donuts."); 
		//deliveryTD = TextDrawCreate(320.000000, 424.000000, "Deliver ~g~donut filling ~w~to ~y~Tuff Nut Donuts");
	
		playerData[playerid][CourierX] = -2754.7322;
		playerData[playerid][CourierY] = 786.7725;
		playerData[playerid][CourierZ] = 53.8057;
		
	}
	if (randomloc == 7)
	{ 
		playerData[playerid][playerLastCourierCP] = CreateDynamicRaceCP(1, -2641.4177, 629.0082, 14.4531, -2641.4177, 629.0082, 14.4531, 5, -1, -1, playerid, 100.0);
		SetPlayerMapIcon(playerid, MAP_ICON_COURIER_VAN, -2641.4177, 629.0082, 14.4531, 51, 0, MAPICON_GLOBAL);
		SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}Deliver used needles to the hospital."); 
		//deliveryTD = TextDrawCreate(320.000000, 424.000000, "Deliver ~g~used needles ~w~to ~y~the hospital");
		
		playerData[playerid][CourierX] = -2641.4177;
		playerData[playerid][CourierY] = 629.0082;
		playerData[playerid][CourierZ] = 14.4531;
		
	}
	if (randomloc == 8)
	{ 
		playerData[playerid][playerLastCourierCP] = CreateDynamicRaceCP(1, -2442.2581, 523.1574, 29.9109, -2442.2581, 523.1574, 29.9109, 5, -1, -1, playerid, 100.0);
		SetPlayerMapIcon(playerid, MAP_ICON_COURIER_VAN, -2442.2581, 523.1574, 29.9109, 51, 0, MAPICON_GLOBAL);
		SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}Deliver handcuffs to the CIA HQ."); 
		//deliveryTD = TextDrawCreate(320.000000, 424.000000, "Deliver ~g~handcuffs ~w~to ~y~CIA HQ");
		
		playerData[playerid][CourierX] = -2442.2581;
		playerData[playerid][CourierY] = 523.1574;
		playerData[playerid][CourierZ] = 29.9109;
		
	}
	if (randomloc == 9)
	{ 
		playerData[playerid][playerLastCourierCP] = CreateDynamicRaceCP(1, -2248.2068, 128.9138, 35.1719, -2248.2068, 128.9138, 35.1719, 5, -1, -1, playerid, 100.0);
		SetPlayerMapIcon(playerid, MAP_ICON_COURIER_VAN, -2248.2068, 128.9138, 35.1719, 51, 0, MAPICON_GLOBAL);
		SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}Deliver RC Motors to Zero's RC store."); 
		//deliveryTD = TextDrawCreate(320.000000, 424.000000, "Deliver ~g~RC Motors ~w~to ~y~Zero's RC store");
		
		playerData[playerid][CourierX] = -2248.2068;
		playerData[playerid][CourierY] = 128.9138;
		playerData[playerid][CourierZ] = 35.1719;
		
	}
	if (randomloc == 10)
	{ 
		playerData[playerid][playerLastCourierCP] = CreateDynamicRaceCP(1, -2263.2197, -156.9953, 35.1719, -2263.2197, -156.9953, 35.1719, 5, -1, -1, playerid, 100.0);
		SetPlayerMapIcon(playerid, MAP_ICON_COURIER_VAN, -2263.2197, -156.9953, 35.1719, 51, 0, MAPICON_GLOBAL);
		SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}Deliver steroids to the gym."); 
		//deliveryTD = TextDrawCreate(320.000000, 424.000000, "Deliver ~g~steroids ~w~to ~y~the gym");
		
		playerData[playerid][CourierX] = -2263.2197;
		playerData[playerid][CourierY] = -156.9953;
		playerData[playerid][CourierZ] = 35.1719;
		
	}
	if (randomloc == 11)
	{ 
		playerData[playerid][playerLastCourierCP] = CreateDynamicRaceCP(1, -2037.2689, -95.3348, 35.1641, -2037.2689, -95.3348, 35.1641, 5, -1, -1, playerid, 100.0);
		SetPlayerMapIcon(playerid, MAP_ICON_COURIER_VAN, -2037.2689, -95.3348, 35.1641, 51, 0, MAPICON_GLOBAL);
		SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}Deliver fake driving licences to the driving school."); 
		//deliveryTD = TextDrawCreate(320.000000, 424.000000, "Deliver ~g~fake driving licences ~w~to ~y~the driving school");
		
		playerData[playerid][CourierX] = -2037.2689;
		playerData[playerid][CourierY] = -95.3348;
		playerData[playerid][CourierZ] = 35.1641;
		
	}
	//TextDrawShowForPlayer(playerid, deliveryTD);
	//playerData[playerid][courierDistance] = SetTimerEx("CourierDistance", 500, true, "i", playerid);
}


public CourierWaitVanUnload(playerid)
{
	TogglePlayerControllable(playerid, 1);
	TextDrawHideForPlayer(playerid, TDCourier2);
	
	playerData[playerid][playerCourierItems] = playerData[playerid][playerCourierItems] - 1;
	PlayerPlaySound(playerid, 1149, 0.0, 0.0, 10.0);
	
	new Msg[128];
	format(Msg, sizeof(Msg), "{FFDC2E}[COURIER] {FFFFFF}You delivered a parcel. You have %i items left to deliver.", playerData[playerid][playerCourierItems]);
	SendClientMessage(playerid, COLOR_WHITE, Msg);
	
	DestroyDynamicRaceCP(playerData[playerid][playerLastCourierCP]);
	RemovePlayerMapIcon(playerid, 17 + playerid);
	
	// Random location
	new randomloc = random(11);
	if (randomloc == 0)
	{ 
		playerData[playerid][playerLastCourierCP] = CreateDynamicRaceCP(1, -2010.7465, -28.4315, 35.0699, -2010.7465, -28.4315, 35.0699, 5, -1, -1, playerid, 100.0);
		SetPlayerMapIcon(playerid, MAP_ICON_COURIER_VAN, -2010.7465, -28.4315, 35.0699, 51, 0, MAPICON_GLOBAL);
		SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}Deliver flowers to the mortuary."); 
		//deliveryTD = TextDrawCreate(320.000000, 424.000000, "Deliver ~g~flowers ~w~to ~y~the mortuary");
		
		playerData[playerid][CourierX] = -2010.7465;
		playerData[playerid][CourierY] = -28.4315;
		playerData[playerid][CourierZ] = 35.0699;
		
	}
	if (randomloc == 1)
	{ 
		playerData[playerid][playerLastCourierCP] = CreateDynamicRaceCP(1, -1972.8068, 296.6461, 35.1719, -1972.8068, 296.6461, 35.1719, 5, -1, -1, playerid, 100.0);
		SetPlayerMapIcon(playerid, MAP_ICON_COURIER_VAN, -1972.8068, 296.6461, 35.1719, 51, 0, MAPICON_GLOBAL);
		SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}Deliver number plates to Wang Cars."); 
		//deliveryTD = TextDrawCreate(320.000000, 424.000000, "Deliver ~g~number plates ~w~to ~y~Wang Cars");
		
		playerData[playerid][CourierX] = -1972.8068;
		playerData[playerid][CourierY] = -296.6461;
		playerData[playerid][CourierZ] = 35.1719;
		
	}
	if (randomloc == 2)
	{ 
		playerData[playerid][playerLastCourierCP] = CreateDynamicRaceCP(1, -1981.1639, 1117.7991, 53.123, -1981.1639, 1117.7991, 53.123, 5, -1, -1, playerid, 100.0);
		SetPlayerMapIcon(playerid, MAP_ICON_COURIER_VAN, -1981.1639, 1117.7991, 53.123, 51, 0, MAPICON_GLOBAL);
		SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}Deliver a statue of Jesus to the Church."); 
		//deliveryTD = TextDrawCreate(320.000000, 424.000000, "Deliver ~g~a statue of Jesus ~w~to ~y~the Church");
		
		playerData[playerid][CourierX] = -1981.1639;
		playerData[playerid][CourierY] = 1117.7991;
		playerData[playerid][CourierZ] = 53.123;
		
	}
	if (randomloc == 3)
	{ 
		playerData[playerid][playerLastCourierCP] = CreateDynamicRaceCP(1, -1799.9474, 1198.5742, 25.1194, -1799.9474, 1198.5742, 25.1194, 5, -1, -1, playerid, 100.0);
		SetPlayerMapIcon(playerid, MAP_ICON_COURIER_VAN, -1799.9474, 1198.5742, 25.1194, 51, 0, MAPICON_GLOBAL);
		SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}Deliver super glue to Michelle's auto repair shop."); 
		//deliveryTD = TextDrawCreate(320.000000, 424.000000, "Deliver ~g~super glue ~w~to ~y~Michelle's auto repair shop");
		
		playerData[playerid][CourierX] = -1799.9474;
		playerData[playerid][CourierY] = 1198.5742;
		playerData[playerid][CourierZ] = 25.1194;
		
	}
	if (randomloc == 4)
	{ 
		playerData[playerid][playerLastCourierCP] = CreateDynamicRaceCP(1, -1719.1584, 1367.1101, 7.1875, -1719.1584, 1367.1101, 7.1875, 5, -1, -1, playerid, 100.0);
		SetPlayerMapIcon(playerid, MAP_ICON_COURIER_VAN, -1719.1584, 1367.1101, 7.1875, 51, 0, MAPICON_GLOBAL);
		SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}Deliver pizza boxes to Well Stacked Pizza."); 
		//deliveryTD = TextDrawCreate(320.000000, 424.000000, "Deliver ~g~a pizza boxes ~w~to ~y~Well Stacked Pizza");
		
		playerData[playerid][CourierX] = -1719.1584;
		playerData[playerid][CourierY] = 1367.1101;
		playerData[playerid][CourierZ] = -1719.1584;
		
	}
	if (randomloc == 5)
	{ 
		playerData[playerid][playerLastCourierCP] = CreateDynamicRaceCP(1, -2622.6921, 1401.9629, 7.1016, -2622.6921, 1401.9629, 7.1016, 5, -1, -1, playerid, 100.0);
		SetPlayerMapIcon(playerid, MAP_ICON_COURIER_VAN, -2622.6921, 1401.9629, 7.1016, 51, 0, MAPICON_GLOBAL);
		SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}Deliver fresh condoms to the Pleasure Dome."); 
		//deliveryTD = TextDrawCreate(320.000000, 424.000000, "Deliver ~g~fresh condoms ~w~to ~y~the Pleasure Dome");
		
		playerData[playerid][CourierX] = -2622.6921;
		playerData[playerid][CourierY] = 1401.9629;
		playerData[playerid][CourierZ] = 7.1016;
		
	}
	if (randomloc == 6)
	{ 
		playerData[playerid][playerLastCourierCP] = CreateDynamicRaceCP(1, -2754.7322, 786.7725, 53.8057, -2754.7322, 786.7725, 53.8057, 5, -1, -1, playerid, 100.0);
		SetPlayerMapIcon(playerid, MAP_ICON_COURIER_VAN, -2754.7322, 786.7725, 53.8057, 51, 0, MAPICON_GLOBAL);
		SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}Deliver donut filling to Tuff Nut Donuts."); 
		//deliveryTD = TextDrawCreate(320.000000, 424.000000, "Deliver ~g~donut filling ~w~to ~y~Tuff Nut Donuts");
	
		playerData[playerid][CourierX] = -2754.7322;
		playerData[playerid][CourierY] = 786.7725;
		playerData[playerid][CourierZ] = 53.8057;
		
	}
	if (randomloc == 7)
	{ 
		playerData[playerid][playerLastCourierCP] = CreateDynamicRaceCP(1, -2641.4177, 629.0082, 14.4531, -2641.4177, 629.0082, 14.4531, 5, -1, -1, playerid, 100.0);
		SetPlayerMapIcon(playerid, MAP_ICON_COURIER_VAN, -2641.4177, 629.0082, 14.4531, 51, 0, MAPICON_GLOBAL);
		SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}Deliver used needles to the hospital."); 
		//deliveryTD = TextDrawCreate(320.000000, 424.000000, "Deliver ~g~used needles ~w~to ~y~the hospital");
		
		playerData[playerid][CourierX] = -2641.4177;
		playerData[playerid][CourierY] = 629.0082;
		playerData[playerid][CourierZ] = 14.4531;
		
	}
	if (randomloc == 8)
	{ 
		playerData[playerid][playerLastCourierCP] = CreateDynamicRaceCP(1, -2442.2581, 523.1574, 29.9109, -2442.2581, 523.1574, 29.9109, 5, -1, -1, playerid, 100.0);
		SetPlayerMapIcon(playerid, MAP_ICON_COURIER_VAN, -2442.2581, 523.1574, 29.9109, 51, 0, MAPICON_GLOBAL);
		SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}Deliver handcuffs to the CIA HQ."); 
		//deliveryTD = TextDrawCreate(320.000000, 424.000000, "Deliver ~g~handcuffs ~w~to ~y~CIA HQ");
		
		playerData[playerid][CourierX] = -2442.2581;
		playerData[playerid][CourierY] = 523.1574;
		playerData[playerid][CourierZ] = 29.9109;
		
	}
	if (randomloc == 9)
	{ 
		playerData[playerid][playerLastCourierCP] = CreateDynamicRaceCP(1, -2248.2068, 128.9138, 35.1719, -2248.2068, 128.9138, 35.1719, 5, -1, -1, playerid, 100.0);
		SetPlayerMapIcon(playerid, MAP_ICON_COURIER_VAN, -2248.2068, 128.9138, 35.1719, 51, 0, MAPICON_GLOBAL);
		SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}Deliver RC Motors to Zero's RC store."); 
		//deliveryTD = TextDrawCreate(320.000000, 424.000000, "Deliver ~g~RC Motors ~w~to ~y~Zero's RC store");
		
		playerData[playerid][CourierX] = -2248.2068;
		playerData[playerid][CourierY] = 128.9138;
		playerData[playerid][CourierZ] = 35.1719;
		
	}
	if (randomloc == 10)
	{ 
		playerData[playerid][playerLastCourierCP] = CreateDynamicRaceCP(1, -2263.2197, -156.9953, 35.1719, -2263.2197, -156.9953, 35.1719, 5, -1, -1, playerid, 100.0);
		SetPlayerMapIcon(playerid, MAP_ICON_COURIER_VAN, -2263.2197, -156.9953, 35.1719, 51, 0, MAPICON_GLOBAL);
		SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}Deliver steroids to the gym."); 
		//deliveryTD = TextDrawCreate(320.000000, 424.000000, "Deliver ~g~steroids ~w~to ~y~the gym");
		
		playerData[playerid][CourierX] = -2263.2197;
		playerData[playerid][CourierY] = -156.9953;
		playerData[playerid][CourierZ] = 35.1719;
		
	}
	if (randomloc == 11)
	{ 
		playerData[playerid][playerLastCourierCP] = CreateDynamicRaceCP(1, -2037.2689, -95.3348, 35.1641, -2037.2689, -95.3348, 35.1641, 5, -1, -1, playerid, 100.0);
		SetPlayerMapIcon(playerid, MAP_ICON_COURIER_VAN, -2037.2689, -95.3348, 35.1641, 51, 0, MAPICON_GLOBAL);
		SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}Deliver fake driving licences to the driving school."); 
		//deliveryTD = TextDrawCreate(320.000000, 424.000000, "Deliver ~g~fake driving licences ~w~to ~y~the driving school");
		
		playerData[playerid][CourierX] = -2037.2689;
		playerData[playerid][CourierY] = -95.3348;
		playerData[playerid][CourierZ] = 35.1641;
		
	}
	//TextDrawShowForPlayer(playerid, deliveryTD);
	KillTimer(playerData[playerid][courierDistance]);
	//playerData[playerid][courierDistance] = SetTimerEx("CourierDistance", 500, false, "i", playerid);
}


public CourierWaitVanComplete(playerid)
{
	TogglePlayerControllable(playerid, 1);
	TextDrawHideForPlayer(playerid, TDCourier2);
	KillTimer(playerData[playerid][courierDistance]);
	PlayerTextDrawSetString(playerid, playerData[playerid][playerCourierDistanceTD], " ");
	
	new Money;
	Money = randomEx(3000, 8000);
	
	playerData[playerid][playerCourierItems] = 0;
	PlayerPlaySound(playerid, 1149, 0.0, 0.0, 10.0);
	playerGiveMoney(playerid, Money);
	playerGiveXP(playerid, 10);
	playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
	SetPlayerScore(playerid, playerData[playerid][playerScore]);
	
	RemovePlayerMapIcon(playerid, MAP_ICON_COURIER_VAN);
	DestroyDynamicRaceCP(playerData[playerid][playerLastCourierCP]);
	playerData[playerid][playerCourierLevel] = 0;
	playerData[playerid][iscourier] = false;

	for(new p; p < MAX_PLAYERS; p++)
	{
		new pName[24];
		GetPlayerName(p, pName, sizeof(pName));

		if(!strcmp(pName, playerData[playerid][playerNamee]))
		{
			new Msg[128];
			format(Msg, sizeof(Msg), "{74DF00}[SUCCESS] {FFFFFF}You successfully delivered 5 packages and received {FFDC2E}$%i", Money);
			SendClientMessage(p, COLOR_WHITE, Msg);
		}
		else
		{
			new MsgAll[128];
			format(MsgAll, sizeof(MsgAll), "{FFDC2E}[COURIER] {FFFFFF}%s(%i) successfully delivered 5 packages and received {FFDC2E}$%i", playerData[playerid][playerNamee], playerid, Money);
			SendClientMessage(p, COLOR_WHITE, MsgAll);
		}
	}
}