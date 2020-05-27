#define MAX_TRUCKING_LOCS 14

enum truckingLocs
{
	missionID,
	missionStart[50],
	missionEnd[50],
	Float:missionXYZ[3],
	Float:missionEndXYZ[3],
	missionCargo,
	missionCount,
	missionLowest,
	missionPickup[60]
}

new truckingData[MAX_TRUCKING_LOCS][truckingLocs] =
{
	/*
	    - missionID		- The unique ID of the mission
		- missionStart	- Title of the starting location (ie: San Fierro Port)
		- missionEnd 	- Title of the end location (ie: Las Venturas Airport)
		- missionXYZ	- Starting point (pick-up)
		- missionEndXYZ - End point (drop-off)
		- missionCargo 	- Cargo type
		- missionCount 	- Cargo amount (maxiumum payout)
		- missionLowest - Lowest cargo amount (minimum payout)
		- missionPickup - What to pickup
	*/
	
	// Missions
	{1, "San Fierro Port", "Logging Camp", {-1694.9314, 47.0134, 3.5495}, {-511.2433, -82.2270, 62.1826}, 2, 20000, 8000, "Logging Equipment"},
	{2, "Albert's Farm", "Las Barrancas General Store", {-1101.9417, -1115.3895, 128.2656}, {-793.1586, 1484.5839, 21.9627}, 2, 10000, 5000, "Produce"},
	{3, "LV Freight Depot", "Valle Ocultado Motel", {1420.8026, 1049.8127, 10.8203}, {-768.2923, 2754.5247, 45.7642}, 2, 15000, 5000, "Used Metal Beds"},
	{4, "Boneyard", "LV Warehouse", {385.6648, 2538.6738, 16.5391}, {1634.7003, 2326.8889, 10.8203}, 2, 15000, 5000, "Unknown Items"},
	{5, "LV Warehouse", "Turning Tricks", {1634.7003, 2326.8889, 10.8203}, {1140.1058, 1370.9803, 10.6719}, 2, 8000, 5000, "Spare Tyres"},
	{6, "San Fierro Port", "LV Stadium", {-1694.9314, 47.0134, 3.5495}, {1491.9788, 2149.4170, 10.8203}, 2, 25000, 5000, "Sporting Equipment"},
	{7, "Bayside Marina", "Tierra Robada Cluckin' Bell", {-2262.5273, 2310.3110, 4.8202}, {-1209.2661, 1823.9042, 41.7188}, 2, 8000, 5000, "Fresh Fish"},
	{8, "Boneyard", "San Fierro Port", {385.6648, 2538.6738, 16.5391}, {-1694.9314, 47.0134, 3.5495}, 2, 12000, 5000, "Fishing Equipment"},
	{9, "Logging Camp", "Angel Pine Sawmill", {-511.2433, -82.2270, 62.1826}, {-2003.6364, -2415.0054, 30.6250}, 2, 12000, 5000, "Logs"},
	{10, "San Fierro Port", "Angel Pine Cluckin' Bell", {-1694.9314, 47.0134, 3.5495}, {-2163.7959, -2463.0210, 30.6250}, 2, 15000, 5000, "Fresh Juice"},
	{11, "Blueberry Warehouse", "Blueberry Pizza Stack", {53.8677, -262.8119, 1.5895}, {204.1641, -174.7780, 1.5781}, 2, 8000, 2500, "Pizza Boxes"},
	{12, "Blueberry Warehouse", "Dillimore Pay N Spray", {53.8677, -262.8119, 1.5895}, {707.9683, -448.8955 ,16.3359}, 2, 10000, 5000, "Paint Cans"},
	{13, "San Fierro Port", "El Quebrados Medical Center", {-1694.9314, 47.0134, 3.5495}, {-1514.4918, 2533.4717, 55.6918}, 2, 15000, 5000, "Used Needles"},
	{14, "San Fierro Port", "Ammunation", {-1694.9314, 47.0134, 3.5495}, {-2623.4092, 215.2678, 4.5394}, 2, 5000, 2500, "Rocket Propelled Grenades"}
};

forward exitTruck(playerid);
public exitTruck(playerid)
{
	if (playerData[playerid][truckingStatus] > 0)
	{
		if (GetVehicleModel(GetPlayerVehicleID(playerid)) == 515 || GetVehicleModel(GetPlayerVehicleID(playerid)) == 414)
		{
			// Player re-entered truck
			KillTimer(playerData[playerid][truckExitTimer]);

			PlayerTextDrawSetString(playerid, playerData[playerid][playerTruckingWaitTD], " ");
			PlayerTextDrawSetString(playerid, playerData[playerid][playerTruckingTD], " ");
			playerData[playerid][truckCounter] = 10;		
		}
		else
		{
			new truckCountdown[50];
			
			if (playerData[playerid][truckCounter] != 0)
			{	
				playerData[playerid][truckCounter]--;
				
				format(truckCountdown, sizeof(truckCountdown), "%i seconds left", playerData[playerid][truckCounter]);
				PlayerTextDrawSetString(playerid, playerData[playerid][playerTruckingWaitTD], truckCountdown);		
				PlayerTextDrawSetString(playerid, playerData[playerid][playerTruckingTD], "GET INTO YOUR TRUCK");	
			}
			else
			{
				// Cancel trucking mission
				KillTimer(playerData[playerid][truckExitTimer]);
				
				PlayerTextDrawSetString(playerid, playerData[playerid][playerTruckingWaitTD], " ");		
				PlayerTextDrawSetString(playerid, playerData[playerid][playerTruckingTD], " ");	
				
				//
				// Destroy checkpoint
				DestroyDynamicRaceCP(playerData[playerid][truckingCheckpoint]);
				
				//
				// Remove map icon
				RemovePlayerMapIcon(playerid, 69);
				
				//
				// Set mission status to "delivery"
				playerData[playerid][truckingStatus] = 0;
				
				SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[TRUCKING] {FFFFFF}You've left your truck, the mission has been cancelled!");
			}
		}
	}	
}

forward loadTrailer(playerid);
public loadTrailer(playerid)
{
	//
	// Check Truck type
	if (GetVehicleModel(GetPlayerVehicleID(playerid)) == 515 || GetVehicleModel(GetPlayerVehicleID(playerid)) == 414)
	{
		if (playerData[playerid][truckingStatus] == 1) // Pickup
		{
			//
			// Destroy checkpoint
			DestroyDynamicRaceCP(playerData[playerid][truckingCheckpoint]);
			
			//
			// Create dropoff checkpoint
			new MissionID = playerData[playerid][truckingMission];
			playerData[playerid][truckingCheckpoint] = CreateDynamicRaceCP(1, truckingData[MissionID][missionEndXYZ][0], truckingData[MissionID][missionEndXYZ][1], truckingData[MissionID][missionEndXYZ][2], truckingData[MissionID][missionEndXYZ][0], truckingData[MissionID][missionEndXYZ][1], truckingData[MissionID][missionEndXYZ][2], 5, -1, -1, playerid, 100.0);
			
			//
			// Remove map icon
			RemovePlayerMapIcon(playerid, 69);
			
			// Hide TDs
			PlayerTextDrawSetString(playerid, playerData[playerid][playerTruckingTD], " ");
			PlayerTextDrawSetString(playerid, playerData[playerid][playerTruckingWaitTD], " ");
	
			//
			// Set map icon
			SetPlayerMapIcon(playerid, 69, truckingData[MissionID][missionEndXYZ][0], truckingData[MissionID][missionEndXYZ][1], truckingData[MissionID][missionEndXYZ][2], 51, 0, MAPICON_GLOBAL);
			
			//
			// Set mission status to "delivery"
			playerData[playerid][truckingStatus] = 2;
			
			//
			// Controllable once more...
			TogglePlayerControllable(playerid, 1);
			
			new missionText[200];
			format(missionText, sizeof(missionText), "{58D3F7}[TRUCKING] {FFFFFF}Deliver {FFDC2E}%s {FFFFFF}to {FFDC2E}%s {FFFFFF}", truckingData[MissionID][missionPickup], truckingData[MissionID][missionEnd]);
			SendClientMessage(playerid, COLOR_WHITE, missionText);
			
		}
		else if (playerData[playerid][truckingStatus] == 2) // Drop-off
		{
			//
			// Destroy checkpoint
			DestroyDynamicRaceCP(playerData[playerid][truckingCheckpoint]);
			
			//
			// Remove map icon
			RemovePlayerMapIcon(playerid, 69);
			
			//
			// Set mission status to "delivery"
			playerData[playerid][truckingStatus] = 0;
			
			//
			// Controllable once more...
			TogglePlayerControllable(playerid, 1);
			
			new MissionID = playerData[playerid][truckingMission];
			new moneyToGive = randomEx(truckingData[MissionID][missionLowest], truckingData[MissionID][missionCount]);
			
			playerGiveMoney(playerid, moneyToGive);
			playerGiveXP(playerid, 40);
			
			PlayerTextDrawSetString(playerid, playerData[playerid][playerTruckingTD], " ");
			PlayerTextDrawSetString(playerid, playerData[playerid][playerTruckingWaitTD], " ");
			
			playerData[playerid][truckStat] = playerData[playerid][truckStat] + 1;
			playerData[playerid][playerScore] = playerData[playerid][playerScore] + 1;
			SetPlayerScore(playerid, playerData[playerid][playerScore]);			
			
			new truckingComplete[380];
			format(truckingComplete, sizeof(truckingComplete), "{58D3F7}[TRUCKING] {FFFFFF}%s(%i) delivered {FFDC2E}%s {FFFFFF}to {FFDC2E}%s{FFFFFF} and earnt {FFDC2E}$%s", playerData[playerid][playerNamee], playerid, truckingData[MissionID][missionPickup], truckingData[MissionID][missionEnd], FormatNumber(moneyToGive));
			SendClientMessageToAll(COLOR_WHITE, truckingComplete);
		}
	}
}

COMMAND:trucking(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
		{
			if(GetVehicleTrailer(GetPlayerVehicleID(playerid)) || GetVehicleModel(GetPlayerVehicleID(playerid)) == 414)
			{
				if (playerData[playerid][truckingStatus] < 1)
				{
					if (playerData[playerid][canTruck])
					{
						//
						// Timer
						playerData[playerid][truckCounter] = 10;
						
						//
						// Assign new mission to player
						new RandomMission = random(MAX_TRUCKING_LOCS);
						playerData[playerid][truckingCheckpoint] = CreateDynamicRaceCP(1, truckingData[RandomMission][missionXYZ][0], truckingData[RandomMission][missionXYZ][1], truckingData[RandomMission][missionXYZ][2], truckingData[RandomMission][missionEndXYZ][0], truckingData[RandomMission][missionEndXYZ][1], truckingData[RandomMission][missionEndXYZ][2], 5, -1, -1, playerid, 100.0);
						
						//
						// Assign new variables to player
						playerData[playerid][truckingMission] = RandomMission;
						playerData[playerid][truckingStatus]  = 1;
						
						new missionText[200];
						format(missionText, sizeof(missionText), "{58D3F7}[TRUCKING] {FFFFFF}Pickup {FFDC2E}%s {FFFFFF}from {FFDC2E}%s {FFFFFF}", truckingData[RandomMission][missionPickup], truckingData[RandomMission][missionStart]);
						SendClientMessage(playerid, COLOR_WHITE, missionText);
						
						//
						// Remove map icon
						RemovePlayerMapIcon(playerid, 69);
						
						//
						// Set map icon
						SetPlayerMapIcon(playerid, 69, truckingData[RandomMission][missionXYZ][0], truckingData[RandomMission][missionXYZ][1], truckingData[RandomMission][missionXYZ][2], 51, 0, MAPICON_GLOBAL);
						
						playerData[playerid][playerMissionCPTime] = 0;
						playerData[playerid][canTruck] = false;
						playerData[playerid][retruckTimer] = SetTimerEx("retruck", 30000, false, "i", playerid);
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You've recently finished a trucking mission. Please wait before starting another.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You're already on a mission! {FFDC2E}/canceltrucking {FFFFFF}first!");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be towing a trailer to start a trucking mission.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This command can only be used by civilians.");
		}
	}

	return 1;
}

COMMAND:canceltrucking(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
		{
			if (playerData[playerid][truckingStatus] > 0)
			{
				// Cancel trucking mission
				KillTimer(playerData[playerid][truckExitTimer]);
				
				PlayerTextDrawSetString(playerid, playerData[playerid][playerTruckingWaitTD], " ");		
				PlayerTextDrawSetString(playerid, playerData[playerid][playerTruckingTD], " ");	
				
				//
				// Destroy checkpoint
				DestroyDynamicRaceCP(playerData[playerid][truckingCheckpoint]);
				
				//
				// Remove map icon
				RemovePlayerMapIcon(playerid, 69);
				
				//
				// Set mission status to "delivery"
				playerData[playerid][truckingStatus] = 0;
				TogglePlayerControllable(playerid, 1);
				
				SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[TRUCKING] {FFFFFF}You cancelled the mission.");				
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You are not on a trucking mission.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This command can only be used by civilians.");
		}
	}
	
	return 1;
}

COMMAND:t(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		new vehicle;
		vehicle = GetPlayerVehicleID(playerid);
  	    if(GetVehicleModel(vehicle) == 515 || GetVehicleModel(vehicle) == 414)
  	    {
            new message[120];
            if(sscanf(params, "s[120]", message))
            {
                // Invalid command syntax
                SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"t <message>\"");
            }
            else
            {
				for (new i=0; i<MAX_PLAYERS; i++)
				{
					new vehicles;
					vehicles = GetPlayerVehicleID(i);
					if(GetVehicleModel(vehicles) == 515)
					{
						new radio[100];
						format(radio, sizeof(radio), "{FAAC58}<Trucker Radio> {FFFFFF}%s(%i): %s", playerData[playerid][playerNamee], playerid, message);
						SendClientMessage(i, COLOR_WHITE, radio);
					}
				}				
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You only can use this command inside of your truck!");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
	return 1;
}