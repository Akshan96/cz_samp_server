/*
   Forklift missions 1.0.0
*/

COMMAND:forklift(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
		{
			if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 530)
			{
				if (playerData[playerid][forkliftStatus] < 1)
				{
					//
					// Assign new mission to player
					playerData[playerid][forkliftCP] = CreateDynamicRaceCP(1, -1707.3580, 98.1322, 3.5547, -1665.7355, -75.4942, 3.5667, 5, -1, -1, playerid, 100.0);
					
					//
					// Assign new variables to player
					playerData[playerid][forkliftStatus] = 1;
					
					SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[MISSION] {FFFFFF}Pickup the crate.");
					
					//
					// Remove map icon
					RemovePlayerMapIcon(playerid, 70);
					
					//
					// Set map icon
					SetPlayerMapIcon(playerid, 70, -1707.3580, 98.1322, 3.5547, 56, 0, MAPICON_GLOBAL);
					
					// Record current damage
					new Float:health;
					playerData[playerid][forkliftDamage] = GetVehicleHealth(GetPlayerVehicleID(playerid), health);
					
					playerData[playerid][playerMissionCPTime] = 0;
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You're already on a mission! {FFDC2E}/cancelforklift {FFFFFF}first!");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be in a forklift to start the mission!");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This command can only be used by civilians.");
		}
	}

	return 1;
}

COMMAND:cancelforklift(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
		{
			if (playerData[playerid][forkliftStatus] > 0)
			{
				//
				// Destroy checkpoint
				DestroyDynamicRaceCP(playerData[playerid][forkliftCP]);
				DestroyObject(playerData[playerid][forkliftObject]);
				
				//
				// Remove map icon
				RemovePlayerMapIcon(playerid, 70);
				
				//
				// Set mission status to "delivery"
				playerData[playerid][forkliftStatus] = 0;
				playerData[playerid][forkliftDamage] = 0;
				
				SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[MISSION] {FFFFFF}You cancelled the mission.");				
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You are not on a forklift mission.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This command can only be used by civilians.");
		}
	}
	
	return 1;
}

forward forklift_pickup(playerid);
forklift_pickup(playerid)
{	
	playerData[playerid][forkliftObject] = CreateObject(1271, 0, 0, 0, 0, 0, 0);
	AttachObjectToVehicle(playerData[playerid][forkliftObject], GetPlayerVehicleID(playerid), -0.004999, 0.679999, 0.254999, 0.000000, 0.000000, 0.000000);
	DestroyDynamicRaceCP(playerData[playerid][forkliftCP]);
	playerData[playerid][forkliftCP] = CreateDynamicRaceCP(1, -1665.7355, -75.4942, 3.5667, -1665.7355, -75.4942, 3.5667, 5, -1, -1, playerid, 100.0);
	playerData[playerid][forkliftStatus] = 2;
	
	RemovePlayerMapIcon(playerid, 70);
	SetPlayerMapIcon(playerid, 70, -1665.7355, -75.4942, 3.5667, 56, 0, MAPICON_GLOBAL);
	
	SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[MISSION] {FFFFFF}You picked up a crate. Take it to the drop-off point.");
	
}

forward forklift_dropoff(playerid);
forklift_dropoff(playerid)
{	
	DestroyObject(playerData[playerid][forkliftObject]);
	DestroyDynamicRaceCP(playerData[playerid][forkliftCP]);
	playerData[playerid][forkliftStatus] = 0;
	RemovePlayerMapIcon(playerid, 70);
	
	// calculate earnings
	new Float:health;
	GetVehicleHealth(GetPlayerVehicleID(playerid), health);
	
	new Money, totalEarnings;
	Money = randomEx(1000, 1500);
	
	if (health < playerData[playerid][forkliftDamage])
	{
		totalEarnings = Money - 500;
	}
	else
	{
		totalEarnings = Money;
	}
	
	new Msg[128];
	format(Msg, sizeof(Msg), "{58D3F7}[MISSION] {FFFFFF}You completed the forklift mission and received {FFDC2E}$%s", FormatNumber(totalEarnings));
	SendClientMessage(playerid, COLOR_WHITE, Msg);	
	
	playerData[playerid][forkliftCompleted]++;
	playerGiveMoney(playerid, totalEarnings);
	
	new MsgAll[255];
	
	// Achievements
	if (playerData[playerid][forkliftCompleted] == 1)
	{
		disableAchieve(playerid);
		PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
		PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
		PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
		PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

		PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "Box Mover");
		PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "You moved a box from point A to point B, nice.");
		PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);

		playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 6000, false, "i", playerid);

		playerGiveXP(playerid, 25);
		playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
		SetPlayerScore(playerid, playerData[playerid][playerScore]);
	}
	
	if (playerData[playerid][forkliftCompleted] == 10)
	{
		disableAchieve(playerid);
		PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
		PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
		PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
		PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

		PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "Heavy Lifter");
		PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "You completed 10 forklift missions.");
		PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);

		playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 6000, false, "i", playerid);

		playerGiveXP(playerid, 25);
		playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
		SetPlayerScore(playerid, playerData[playerid][playerScore]);
		
		for(new p; p < MAX_PLAYERS; p++)
		{
			new pName[24];
			GetPlayerName(p, pName, sizeof(pName));

			format(MsgAll, sizeof(MsgAll), "{58D3F7}[DOCK WORKER] {FFFFFF}%s(%i) has just complted their 10th forklift mission.", playerData[playerid][playerNamee], playerid);
			SendClientMessage(p, COLOR_WHITE, MsgAll);
		}
	}
	
	if (playerData[playerid][forkliftCompleted] == 50)
	{
		disableAchieve(playerid);
		PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
		PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
		PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
		PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

		PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "Handling Things");
		PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "You completed 50 forklift missions.");
		PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);

		playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 6000, false, "i", playerid);

		playerGiveXP(playerid, 25);
		playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
		SetPlayerScore(playerid, playerData[playerid][playerScore]);
		
		for(new p; p < MAX_PLAYERS; p++)
		{
			new pName[24];
			GetPlayerName(p, pName, sizeof(pName));

			format(MsgAll, sizeof(MsgAll), "{58D3F7}[DOCK WORKER] {FFFFFF}%s(%i) has just complted their 50th forklift mission.", playerData[playerid][playerNamee], playerid);
			SendClientMessage(p, COLOR_WHITE, MsgAll);
		}
	}
}

COMMAND:debugforklift(playerid, params[])
{
	new whatid[100];
	format(whatid, sizeof(whatid), "Status: %i", playerData[playerid][forkliftStatus]);
	SendClientMessage(playerid, COLOR_WHITE, whatid);
	return 1;
}

/*
   Sweeper missions 1.0.0
*/

COMMAND:sweep(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
		{
			if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 574)
			{
				if (playerData[playerid][sweepStatus] < 1)
				{
					playerData[playerid][sweepRoute] = 1; // Only 1 route for now.
					SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[SWEEPER] {FFFFFF}Follow the route to complete the mission.");
					playerData[playerid][sweepStatus] = 1;
					
					//
					// Set map icon
					SetPlayerMapIcon(playerid, 72, -1968.3679, 938.0129, 44.6896, 53, 0, MAPICON_GLOBAL);	
					playerData[playerid][sweepCP] = CreateDynamicRaceCP(1, -1968.3679, 938.0129, 44.6896, -1907.2632, 940.3490, 34.7426, 5, -1, -1, playerid, 100.0);
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You're already on a mission! {FFDC2E}/cancelsweep {FFFFFF}first!");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be driving a sweeper to start a route.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This command can only be used by civilians.");
		}
	}
	
	return 1;
}

forward nextSweep(playerid);
public nextSweep(playerid)
{
	if (playerData[playerid][sweepStatus] > 0)
	{	
		DestroyDynamicRaceCP(playerData[playerid][sweepCP]);
		playerData[playerid][playerMissionCPTime] = 0;
		
		switch(playerData[playerid][sweepStatus])
		{
			case 1:
			{
				if(IsPlayerInRangeOfPoint(playerid, 7.0, -1968.3679, 938.0129, 44.6896))
				{
					SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[SWEEPER] {FFFFFF}Head to the next waypoint.");
					
					//
					// Set map icon
					SetPlayerMapIcon(playerid, 72, -1907.2632, 940.3490, 34.7426, 53, 0, MAPICON_GLOBAL);	
					playerData[playerid][sweepCP] = CreateDynamicRaceCP(1, -1907.2632, 940.3490, 34.7426, -1901.8882, 998.4641, 36.7511  	, 5, -1, -1, playerid, 100.0);
					
					playerData[playerid][sweepStatus] = 2;
				}
			}
			
			case 2:
			{
				if(IsPlayerInRangeOfPoint(playerid, 7.0, -1907.2632, 940.3490, 34.7426))
				{
					SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[SWEEPER] {FFFFFF}Head to the next waypoint.");
					
					//
					// Set map icon
					SetPlayerMapIcon(playerid, 72, -1901.8882, 998.4641, 36.7511, 53, 0, MAPICON_GLOBAL);	
					playerData[playerid][sweepCP] = CreateDynamicRaceCP(1, -1901.8882, 998.4641, 36.7511, -1894.7258, 1033.3206, 43.6743, 5, -1, -1, playerid, 100.0);
					
					playerData[playerid][sweepStatus] = 3;
				}
			}
			
			case 3:
			{
				if(IsPlayerInRangeOfPoint(playerid, 7.0, -1901.8882, 998.4641, 36.7511))
				{
					SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[SWEEPER] {FFFFFF}Head to the next waypoint.");
					
					//
					// Set map icon
					SetPlayerMapIcon(playerid, 72, -1894.7258, 1033.3206, 43.6743, 53, 0, MAPICON_GLOBAL);	
					playerData[playerid][sweepCP] = CreateDynamicRaceCP(1, -1894.7258, 1033.3206, 43.6743, -1894.5796, 1065.2793, 45.2265, 5, -1, -1, playerid, 100.0);
					
					playerData[playerid][sweepStatus] = 4;
				}
			}
			
			case 4:
			{
				if(IsPlayerInRangeOfPoint(playerid, 7.0, -1894.7258, 1033.3206, 43.6743))
				{
					SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[SWEEPER] {FFFFFF}Head to the next waypoint.");
					
					//
					// Set map icon
					SetPlayerMapIcon(playerid, 72, -1894.5796, 1065.2793, 45.2265, 53, 0, MAPICON_GLOBAL);	
					playerData[playerid][sweepCP] = CreateDynamicRaceCP(1, -1894.5796, 1065.2793, 45.2265, -1894.4907, 1142.2810, 45.1704, 5, -1, -1, playerid, 100.0);
					
					playerData[playerid][sweepStatus] = 5;
				}
			}
			
			case 5:
			{
				if(IsPlayerInRangeOfPoint(playerid, 7.0, -1894.5796, 1065.2793, 45.2265))
				{
					SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[SWEEPER] {FFFFFF}Head to the next waypoint.");
					
					//
					// Set map icon
					SetPlayerMapIcon(playerid, 72, -1894.5796, 1065.2793, 45.2265, 53, 0, MAPICON_GLOBAL);	
					playerData[playerid][sweepCP] = CreateDynamicRaceCP(1, -1894.4907, 1142.2810, 45.1704 , -1894.4907, 1142.2810, 45.1704 , 5, -1, -1, playerid, 100.0);
					
					playerData[playerid][sweepStatus] = 6;
				}
			}
			
/*
	-2062.9275, 945.2324, 59.4731 		// Sweep 13
	-2050.9126, 912.2939, 54.7679 		// Sweep 14
	-1985.6128, 946.6110, 45.1703		// End Sweep
*/

			
			case 6:
			{
				if(IsPlayerInRangeOfPoint(playerid, 7.0, -1894.4907, 1142.2810, 45.1704))
				{
					SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[SWEEPER] {FFFFFF}Head to the next waypoint.");
					
					//
					// Set map icon
					SetPlayerMapIcon(playerid, 72, -1938.7332, 1166.1122, 45.1704, 53, 0, MAPICON_GLOBAL);	
					playerData[playerid][sweepCP] = CreateDynamicRaceCP(1, -1938.7332, 1166.1122, 45.1704, -2017.6100, 1188.4806, 45.1704, 5, -1, -1, playerid, 100.0);
					
					playerData[playerid][sweepStatus] = 7;
				}
			}
			
			case 7:
			{
				if(IsPlayerInRangeOfPoint(playerid, 7.0, -1938.7332, 1166.1122, 45.1704))
				{
					SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[SWEEPER] {FFFFFF}Head to the next waypoint.");
					
					//
					// Set map icon
					SetPlayerMapIcon(playerid, 72, -2017.6100, 1188.4806, 45.1704, 53, 0, MAPICON_GLOBAL);	
					playerData[playerid][sweepCP] = CreateDynamicRaceCP(1, -2017.6100, 1188.4806, 45.1704 , -2107.5056, 1169.5151, 53.9263 , 5, -1, -1, playerid, 100.0);
					
					playerData[playerid][sweepStatus] = 8;
				}
			}
			
			case 8:
			{
				if(IsPlayerInRangeOfPoint(playerid, 7.0, -2017.6100, 1188.4806, 45.1704))
				{
					SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[SWEEPER] {FFFFFF}Head to the next waypoint.");
					
					//
					// Set map icon
					SetPlayerMapIcon(playerid, 72, -2107.5056, 1169.5151, 53.9263, 53, 0, MAPICON_GLOBAL);	
					playerData[playerid][sweepCP] = CreateDynamicRaceCP(1, -2107.5056, 1169.5151, 53.9263, -2135.4534, 1065.0352, 79.5766, 5, -1, -1, playerid, 100.0);
					
					playerData[playerid][sweepStatus] = 9;
				}
			}
			
			case 9:
			{
				if(IsPlayerInRangeOfPoint(playerid, 7.0, -2107.5056, 1169.5151, 53.9263))
				{
					SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[SWEEPER] {FFFFFF}Head to the next waypoint.");
					
					//
					// Set map icon
					SetPlayerMapIcon(playerid, 72, -2119.3408, 918.7676, 79.3286, 53, 0, MAPICON_GLOBAL);	
					playerData[playerid][sweepCP] = CreateDynamicRaceCP(1, -2119.3408, 918.7676, 79.3286, -2100.7493, 941.7407, 73.0554, 5, -1, -1, playerid, 100.0);
					
					playerData[playerid][sweepStatus] = 10;
				}
			}
			
			case 10:
			{
				if(IsPlayerInRangeOfPoint(playerid, 7.0, -2119.3408, 918.7676, 79.3286))
				{
					SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[SWEEPER] {FFFFFF}Head to the next waypoint.");
					
					//
					// Set map icon
					SetPlayerMapIcon(playerid, 72, -2100.7493, 941.7407, 73.0554, 53, 0, MAPICON_GLOBAL);	
					playerData[playerid][sweepCP] = CreateDynamicRaceCP(1, -2100.7493, 941.7407, 73.0554, -2086.8970, 916.3837, 67.6267, 5, -1, -1, playerid, 100.0);
					
					playerData[playerid][sweepStatus] = 11;
				}
			}
			
			case 11:
			{
				if(IsPlayerInRangeOfPoint(playerid, 7.0, -2100.7493, 941.7407, 73.0554))
				{
					SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[SWEEPER] {FFFFFF}Head to the next waypoint.");
					
					//
					// Set map icon
					SetPlayerMapIcon(playerid, 72, -2086.8970, 916.3837, 67.6267, 53, 0, MAPICON_GLOBAL);	
					playerData[playerid][sweepCP] = CreateDynamicRaceCP(1, -2086.8970, 916.3837, 67.6267, -2062.9275, 945.2324, 59.4731, 5, -1, -1, playerid, 100.0);
					
					playerData[playerid][sweepStatus] = 12;
				}
			}
			
			case 12:
			{
				if(IsPlayerInRangeOfPoint(playerid, 7.0, -2086.8970, 916.3837, 67.6267))
				{
					SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[SWEEPER] {FFFFFF}Head to the next waypoint.");
					
					//
					// Set map icon
					SetPlayerMapIcon(playerid, 72, -2062.9275, 945.2324, 59.4731, 53, 0, MAPICON_GLOBAL);	
					playerData[playerid][sweepCP] = CreateDynamicRaceCP(1, -2062.9275, 945.2324, 59.4731, -2050.9126, 912.2939, 54.7679, 5, -1, -1, playerid, 100.0);
					
					playerData[playerid][sweepStatus] = 13;
				}
			}
			
			case 13:
			{
				if(IsPlayerInRangeOfPoint(playerid, 7.0, -2062.9275, 945.2324, 59.4731))
				{
					SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[SWEEPER] {FFFFFF}Head to the next waypoint.");
					
					//
					// Set map icon
					SetPlayerMapIcon(playerid, 72, -2050.9126, 912.2939, 54.7679, 53, 0, MAPICON_GLOBAL);	
					playerData[playerid][sweepCP] = CreateDynamicRaceCP(1, -2050.9126, 912.2939, 54.7679, -1985.6128, 946.6110, 45.1703, 5, -1, -1, playerid, 100.0);
					
					playerData[playerid][sweepStatus] = 14;
				}
			}
			
			case 14:
			{
				new moneyToGive = randomEx(500, 1500);
				playerGiveMoney(playerid, moneyToGive);
				playerGiveXP(playerid, 2);
				
				new finished[300];
				format(finished, sizeof(finished), "{58D3F7}[SWEEPER] {FFFFFF}Finished route and earnt {FFDC2E}$%s", FormatNumber(moneyToGive));
				SendClientMessage(playerid, COLOR_WHITE, finished);
				
				playerData[playerid][sweepStatus] = -1;		
				playerData[playerid][sweepRoute] = -1;
				
				playerData[playerid][sweepCompleted]++;
				
				RemovePlayerMapIcon(playerid, 72);
			}
		}
	}
}

COMMAND:cancelsweep(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
		{
			if (playerData[playerid][sweepStatus] > 0)
			{
				SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[BUS DRIVER] {FFFFFF}Route cancelled.");
				
				playerData[playerid][sweepStatus] = -1;		
				playerData[playerid][sweepRoute] = 1;
				
				RemovePlayerMapIcon(playerid, 72);
				DestroyDynamicRaceCP(playerData[playerid][sweepCP]);
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This command can only be used by civilians.");
		}
	}
	
	return 1;
}

/*
   Bus driver missions 1.0.0
*/

COMMAND:startroute(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
		{
			if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 431)
			{
				if (playerData[playerid][busStatus] < 1)
				{
					playerData[playerid][busRoute] = 1; // Only 1 route for now.
					playerData[playerid][busStatus] = 1;
					
					SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[BUS DRIVER] {FFFFFF}Head to the first bus stop.");
					
					//
					// Set map icon
					SetPlayerMapIcon(playerid, 71, -1719.8501, 764.6696, 24.3028, 53, 0, MAPICON_GLOBAL);	
					playerData[playerid][busCP] = CreateDynamicRaceCP(1, -1719.8501, 764.6696, 24.3028, -1974.4366, 736.9131, 44.8606, 5, -1, -1, playerid, 100.0);
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You're already on a mission! {FFDC2E}/cancelroute {FFFFFF}first!");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be driving a bus to start a route.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This command can only be used by civilians.");
		}
	}
	
	return 1;
}

COMMAND:cancelroute(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
		{
			if (playerData[playerid][busStatus] > 0)
			{
				SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[BUS DRIVER] {FFFFFF}Route cancelled.");
				
				playerData[playerid][busStatus] = -1;		
				playerData[playerid][busRoute] = 1;
				
				RemovePlayerMapIcon(playerid, 71);
				DestroyDynamicRaceCP(playerData[playerid][busCP]);
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This command can only be used by civilians.");
		}
	}
	
	return 1;
}

/*
	AddStaticVehicle(522,-1719.8501, 764.6696, 24.3028,181.2374,179,47); // Bus Stop 1
	AddStaticVehicle(522,-1974.4366, 736.9131, 44.8606,90.5415,179,47); // Bus Stop 2
	AddStaticVehicle(522,-2136.2839, 843.9493, 69.1043,1.1431,179,47); // Bus Stop 3
	AddStaticVehicle(522,-2018.3304, 1170.6965, 44.8687,270.9242,179,47); // Bus Stop 4
	AddStaticVehicle(522,-1899.1992, 976.7847, 34.5887,171.5345,179,47); // Bus Stop 5
*/

forward nextStop(playerid);
public nextStop(playerid)
{
	if (playerData[playerid][busStatus] > 0)
	{	
		DestroyDynamicRaceCP(playerData[playerid][busCP]);
		playerData[playerid][playerMissionCPTime] = 0;
		
		switch(playerData[playerid][busStatus])
		{
			case 1:
			{
				if(IsPlayerInRangeOfPoint(playerid, 7.0, -1719.8501, 764.6696, 24.3028))
				{
					SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[BUS DRIVER] {FFFFFF}Head to the second bus stop.");
					
					//
					// Set map icon
					SetPlayerMapIcon(playerid, 71, -1974.4366, 736.9131, 44.8606, 53, 0, MAPICON_GLOBAL);	
					playerData[playerid][busCP] = CreateDynamicRaceCP(1, -1974.4366, 736.9131, 44.8606, -2136.2839, 843.9493, 69.1043, 5, -1, -1, playerid, 100.0);
					
					playerData[playerid][busStatus] = 2;
				}
			}
			
			case 2:
			{
				if(IsPlayerInRangeOfPoint(playerid, 7.0, -1974.4366, 736.9131, 44.8606))
				{
					SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[BUS DRIVER] {FFFFFF}Head to the third bus stop.");
					
					//
					// Set map icon
					SetPlayerMapIcon(playerid, 71, -2136.2839, 843.9493, 69.1043, 53, 0, MAPICON_GLOBAL);	
					playerData[playerid][busCP] = CreateDynamicRaceCP(1, -2136.2839, 843.9493, 69.1043, -2018.3304, 1170.6965, 44.8687, 5, -1, -1, playerid, 100.0);
					
					playerData[playerid][busStatus] = 3;
				}
			}
			
			case 3:
			{
				if(IsPlayerInRangeOfPoint(playerid, 7.0, -2136.2839, 843.9493, 69.1043))
				{
					SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[BUS DRIVER] {FFFFFF}Head to the fourth bus stop.");
					
					//
					// Set map icon
					SetPlayerMapIcon(playerid, 71, -2018.3304, 1170.6965, 44.8687, 53, 0, MAPICON_GLOBAL);	
					playerData[playerid][busCP] = CreateDynamicRaceCP(1, -2018.3304, 1170.6965, 44.8687, -1899.1992, 976.7847, 34.5887, 5, -1, -1, playerid, 100.0);
					
					playerData[playerid][busStatus] = 4;
				}
			}
			
			case 4:
			{
				if(IsPlayerInRangeOfPoint(playerid, 7.0, -2018.3304, 1170.6965, 44.8687))
				{
					SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[BUS DRIVER] {FFFFFF}Head to the fith bus stop.");
					
					//
					// Set map icon
					SetPlayerMapIcon(playerid, 71, -1899.1992, 976.7847, 34.5887, 53, 0, MAPICON_GLOBAL);	
					playerData[playerid][busCP] = CreateDynamicRaceCP(1, -1899.1992, 976.7847, 34.5887, -1756.3921, 885.6292, 24.6468, 5, -1, -1, playerid, 100.0);
					
					playerData[playerid][busStatus] = 5;
				}
			}
			
			case 5:
			{
				if(IsPlayerInRangeOfPoint(playerid, 7.0, -1899.1992, 976.7847, 34.5887))
				{
					new moneyToGive = randomEx(500, 1500);
					playerGiveMoney(playerid, moneyToGive);
					playerGiveXP(playerid, 2);
					
					new finished[300];
					format(finished, sizeof(finished), "{58D3F7}[BUS DRIVER] {FFFFFF}Finished route and earnt {FFDC2E}$%s", FormatNumber(moneyToGive));
					SendClientMessage(playerid, COLOR_WHITE, finished);
					
					playerData[playerid][busStatus] = -1;		
					playerData[playerid][busRoute] = -1;
					playerData[playerid][busCompleted]++;
					
					RemovePlayerMapIcon(playerid, 71);
				}
			}
		}
	}
}