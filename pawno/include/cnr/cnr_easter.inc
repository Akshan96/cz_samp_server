#define MAX_BAG_LOCATIONS 25

enum moneyBag
{
	bagID,
	bagValue,
	bagType,
	Float:bagXYZ[3],
	bagTitle[25],
	Text3D:bagLabel
}

new moneyBagInfo[MAX_BAG_LOCATIONS][moneyBag] =
{
	/*
	    - bagID		    - The unique ID of the bag
		- bagValue		- Value of the bag
		- XP/MONEY 		- 1 for money, 2 for XP
		- bagXYZ		- Location
		- bagTitle		- The title (Downtown San Fierro)
	*/
	
	// Missions
	{1, 1, 1, {-1494.1268, 911.7745, 7.1853 }, "Downtown San Fierro"},
	{2, 1, 1, {-1584.8687, 873.4046, 9.2298 }, "Downtown San Fierro"},
	{3, 1, 1, {-1614.9561, 873.4895, 9.2298 }, "Downtown San Fierro"},
	{4, 1, 1, {-1613.8804, 806.9777, 6.6094 }, "Downtown San Fierro"},
	{5, 1, 1, {-1616.1606, 683.1149, 7.1875 }, "Downtown San Fierro"},
	{6, 1, 1, {-1573.9510, 647.7454, 7.1875 }, "Downtown San Fierro"},
	{7, 1, 1, {-1572.7195, 657.4495, 7.1875 }, "Downtown San Fierro"},
	{8, 1, 1, {-1519.5889, 673.6328, 7.1875 }, "Downtown San Fierro"},
	{9, 1, 1, {-1480.2639, 717.9940, 6.9922 }, "Downtown San Fierro"},
	{10, 1, 1, {-1420.4127, 842.8577, 7.1875 }, "Downtown San Fierro"},
	{11, 1, 1, {-1589.5576, 1015.9662, 7.2656 }, "Downtown San Fierro"},
	{12, 1, 1, {-1535.5751, 1108.8309, 7.1875 }, "Esplande East"},
	{13, 1, 1, {-1521.9249, 1114.5906, 7.1875 }, "Esplande East"},
	{14, 1, 1, {-1686.6980, 944.2634, 24.8906 }, "Financial"},
	{15, 1, 1, {-1744.6017, 964.2456, 29.0625 }, "Financial"},
	{16, 1, 1, {-1754.7079, 964.4924, 29.0625 }, "Financial"},
	{17, 1, 1, {-1746.4530, 809.3837, 24.8906 }, "Financial"},
	{18, 1, 1, {-1778.7826, 960.8868, 25.5078 }, "Financial"},
	{19, 1, 1, {-1987.8734, 903.9367, 45.2097 }, "Calton Heights"},
	{20, 1, 1, {-1944.4148, 790.3761, 55.7204 }, "Downtown San Fierro"},
	{21, 1, 1, {-1828.0718, 715.2733, 37.9698 }, "Downtown San Fierro"},
	{22, 1, 1, {-1624.9502, 717.2540, 14.6094 }, "Downtown San Fierro"},
	{23, 1, 1, {-1696.6426, 1011.0380, 45.2109 }, "Financial"},
	{24, 1, 1, {-1820.7449, 1116.7661, 46.2321 }, "Financial"},
	{25, 1, 1, {-1886.5935, 966.2076, 35.1706 }, "Downtown San Fierro"}
};

COMMAND:starthunt(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 6)
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}The easter egg hunt has been started!");
			
			for(new p; p < MAX_PLAYERS; p++)
			{
				if(playerData[p][playerLoggedIn])
				{
					TextDrawShowForPlayer(p, easterSunday);
					PlayerTextDrawShow(p, playerData[p][Eggs][0]);
					PlayerTextDrawShow(p, playerData[p][Eggs][1]);
					PlayerTextDrawShow(p, playerData[p][Eggs][2]);
				}
			}
			
			serverInfo[huntOn] = 5;
			
			autoMoneyBag();
		}
		else
		{
			return 0;
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:stophunt(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 6)
		{
			KillTimer(serverInfo[eggHunt]);
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}The easter hunt has been stopped.");
			
			for(new p; p < MAX_PLAYERS; p++)
			{
				if(playerData[p][playerLoggedIn])
				{
					TextDrawHideForPlayer(p, easterSunday);
					PlayerTextDrawHide(p, playerData[p][Eggs][0]);
					PlayerTextDrawHide(p, playerData[p][Eggs][1]);
					PlayerTextDrawHide(p, playerData[p][Eggs][2]);
				}
			}
			
			serverInfo[huntOn] = 0;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

forward autoMoneyBag();
public autoMoneyBag()
{
	if (serverInfo[huntOn])
	{
		if (serverInfo[moneybagid] != -1)
		{
			// Remove the money bag, no one found it!
			new MoneybagID = serverInfo[moneybagid];
			DestroyDynamicObject(moneyBagInfo[MoneybagID][bagID]);
			Delete3DTextLabel(moneyBagInfo[MoneybagID][bagLabel]);
			serverInfo[moneybagid] = -1;
			SendClientMessageToAll(COLOR_WHITE, "{58D3F7}[EASTER EGG] {FFFFFF}The egg has been eaten, another one will be hidden shortly.");
		}
		else
		{
			// Place a random money bag
			new randomBag = random(MAX_BAG_LOCATIONS);
			new randomObj = random(5);
			
			switch (randomObj)
			{
				case 0:
				{
					moneyBagInfo[randomBag][bagID] = CreateDynamicObject(19341, moneyBagInfo[randomBag][bagXYZ][0], moneyBagInfo[randomBag][bagXYZ][1], (moneyBagInfo[randomBag][bagXYZ][2] - 0.6), 270.00000, 0.00000, 0.00000);
				}
				case 1:
				{
					moneyBagInfo[randomBag][bagID] = CreateDynamicObject(19342, moneyBagInfo[randomBag][bagXYZ][0], moneyBagInfo[randomBag][bagXYZ][1], (moneyBagInfo[randomBag][bagXYZ][2] - 0.6), 270.00000, 0.00000, 0.00000);
				}
				case 2:
				{
					moneyBagInfo[randomBag][bagID] = CreateDynamicObject(19343, moneyBagInfo[randomBag][bagXYZ][0], moneyBagInfo[randomBag][bagXYZ][1], (moneyBagInfo[randomBag][bagXYZ][2] - 0.6), 270.00000, 0.00000, 0.00000);
				}
				case 3:
				{
					moneyBagInfo[randomBag][bagID] = CreateDynamicObject(19344, moneyBagInfo[randomBag][bagXYZ][0], moneyBagInfo[randomBag][bagXYZ][1], (moneyBagInfo[randomBag][bagXYZ][2] - 0.6), 270.00000, 0.00000, 0.00000);
				}
				case 4:
				{
					moneyBagInfo[randomBag][bagID] = CreateDynamicObject(19345, moneyBagInfo[randomBag][bagXYZ][0], moneyBagInfo[randomBag][bagXYZ][1], (moneyBagInfo[randomBag][bagXYZ][2] - 0.6), 270.00000, 0.00000, 0.00000);
				}
			}
			
			moneyBagInfo[randomBag][bagLabel] = Create3DTextLabel("/pickup", COLOR_YELLOW, moneyBagInfo[randomBag][bagXYZ][0], moneyBagInfo[randomBag][bagXYZ][1], (moneyBagInfo[randomBag][bagXYZ][2] - 0.5), 10, 0, 0);
			serverInfo[moneybagid] = randomBag;			
			
			new bagInfo[200];
			format(bagInfo, sizeof(bagInfo), "{58D3F7}[EASTER EGG] {FFFFFF}The Easter Egg has been hidden in {FFDC2E}%s{FFFFFF}! Type /pickup if you find it for a prize!", moneyBagInfo[randomBag][bagTitle]);
			SendClientMessageToAll(COLOR_WHITE, bagInfo);
		}
	}
}

COMMAND:startegg(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			if (serverInfo[moneybagid] != -1)
			{
				// Remove the money bag, no one found it!
				new MoneybagID = serverInfo[moneybagid];
				DestroyDynamicObject(moneyBagInfo[MoneybagID][bagID]);
				Delete3DTextLabel(moneyBagInfo[MoneybagID][bagLabel]);
				serverInfo[moneybagid] = -1;
				SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[EASTER EGG] {FFFFFF}The Easter Egg has been eaten by the bunny, another will appear shortly!");
			}
			else
			{
				// Place a random money bag
				new randomBag = random(MAX_BAG_LOCATIONS);
				new randomObj = random(5);
				
				switch (randomObj)
				{
					case 0:
					{
						moneyBagInfo[randomBag][bagID] = CreateDynamicObject(19341, moneyBagInfo[randomBag][bagXYZ][0], moneyBagInfo[randomBag][bagXYZ][1], (moneyBagInfo[randomBag][bagXYZ][2] - 0.6), 270.00000, 0.00000, 0.00000);
					}
					case 1:
					{
						moneyBagInfo[randomBag][bagID] = CreateDynamicObject(19342, moneyBagInfo[randomBag][bagXYZ][0], moneyBagInfo[randomBag][bagXYZ][1], (moneyBagInfo[randomBag][bagXYZ][2] - 0.6), 270.00000, 0.00000, 0.00000);
					}
					case 2:
					{
						moneyBagInfo[randomBag][bagID] = CreateDynamicObject(19343, moneyBagInfo[randomBag][bagXYZ][0], moneyBagInfo[randomBag][bagXYZ][1], (moneyBagInfo[randomBag][bagXYZ][2] - 0.6), 270.00000, 0.00000, 0.00000);
					}
					case 3:
					{
						moneyBagInfo[randomBag][bagID] = CreateDynamicObject(19344, moneyBagInfo[randomBag][bagXYZ][0], moneyBagInfo[randomBag][bagXYZ][1], (moneyBagInfo[randomBag][bagXYZ][2] - 0.6), 270.00000, 0.00000, 0.00000);
					}
					case 4:
					{
						moneyBagInfo[randomBag][bagID] = CreateDynamicObject(19345, moneyBagInfo[randomBag][bagXYZ][0], moneyBagInfo[randomBag][bagXYZ][1], (moneyBagInfo[randomBag][bagXYZ][2] - 0.6), 270.00000, 0.00000, 0.00000);
					}
				}
				
				moneyBagInfo[randomBag][bagLabel] = Create3DTextLabel("/pickup", COLOR_YELLOW, moneyBagInfo[randomBag][bagXYZ][0], moneyBagInfo[randomBag][bagXYZ][1], (moneyBagInfo[randomBag][bagXYZ][2] - 0.5), 10, 0, 0);
				serverInfo[moneybagid] = randomBag;			
				
				new bagInfo[200];
				format(bagInfo, sizeof(bagInfo), "{58D3F7}[EASTER EGG] {FFFFFF}The Easter Egg has been hidden in {FFDC2E}%s{FFFFFF}! Type /pickup if you find it for a prize!", moneyBagInfo[randomBag][bagTitle]);
				SendClientMessageToAll(COLOR_WHITE, bagInfo);
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not have the correct permissions to use this command.");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:gotoegg(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			if (serverInfo[moneybagid] == -1)
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}There is no egg active.");
			}
			else
			{
				// Go to bag
				new gotobag = serverInfo[moneybagid];
				SetPlayerPos(playerid, moneyBagInfo[gotobag][bagXYZ][0], moneyBagInfo[gotobag][bagXYZ][1], moneyBagInfo[gotobag][bagXYZ][2] + 1.0);
				SetPlayerVirtualWorld(playerid, 0);
				SetPlayerInterior(playerid, 0);
				
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You teleported to the egg.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not have the correct permissions to use this command.");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:easteregg(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (serverInfo[moneybagid] != -1)
		{
			// Show egg location
			new MoneybagID = serverInfo[moneybagid];
			
			new bagInfo[200];
			format(bagInfo, sizeof(bagInfo), "{58D3F7}[EASTER EGG] {FFFFFF}The Easter Egg is currently hidden in {FFDC2E}%s{FFFFFF}!", moneyBagInfo[MoneybagID][bagTitle]);
			SendClientMessage(playerid, COLOR_WHITE, bagInfo);
		}
		else
		{
			// No egg exists
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}There is no egg hidden.");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:pickup(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (serverInfo[moneybagid] != -1)
		{
			// Show egg location
			new MoneybagID = serverInfo[moneybagid];
			
			if(IsPlayerInRangeOfPoint(playerid, 5.0, moneyBagInfo[MoneybagID][bagXYZ][0], moneyBagInfo[MoneybagID][bagXYZ][1], moneyBagInfo[MoneybagID][bagXYZ][2]))
			{
				// Player found egg
				new randomPrize = random(20);
				
				switch (randomPrize)
				{
					case 0 .. 10:
					{
						new moneybagmsg[200];
						format(moneybagmsg, sizeof(moneybagmsg), "{58D3F7}[EASTER EGG] {FFFFFF}%s(%i) found an egg worth {FFDC2E}$35,000{FFFFFF}!", playerData[playerid][playerNamee], playerid);
						SendClientMessageToAll(COLOR_WHITE, moneybagmsg);
						
						disableAchieve(playerid);
						PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
						PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
						PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
						PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

						PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "Easter Egg");
						PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "You found an easter egg worth $35,000");
						PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);

						playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 8000, false, "i", playerid);
						
						playerGiveMoney(playerid, 35000);
					}
					
					case 11:
					{
						new moneybagmsg[200];
						format(moneybagmsg, sizeof(moneybagmsg), "{58D3F7}[EASTER EGG] {FFFFFF}%s(%i) found an egg worth {FFDC2E}500 XP{FFFFFF}!", playerData[playerid][playerNamee], playerid);
						SendClientMessageToAll(COLOR_WHITE, moneybagmsg);
						
						disableAchieve(playerid);
						PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
						PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
						PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
						PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

						PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "Easter Egg");
						PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "You found an easter egg worth 500 XP!");
						PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);

						playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 8000, false, "i", playerid);
						
						playerGiveXP(playerid, 500);
					}
					
					case 12:
					{
						new moneybagmsg[200];
						format(moneybagmsg, sizeof(moneybagmsg), "{58D3F7}[EASTER EGG] {FFFFFF}%s(%i) found an egg worth {FFDC2E}10 XP{FFFFFF}!", playerData[playerid][playerNamee], playerid);
						SendClientMessageToAll(COLOR_WHITE, moneybagmsg);
						
						disableAchieve(playerid);
						PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
						PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
						PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
						PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

						PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "Easter Egg");
						PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "You found an easter egg worth 10 XP!");
						PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);

						playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 8000, false, "i", playerid);
						
						playerGiveMoney(playerid, 10);
					}
					
					case 13:
					{
						new moneybagmsg[200];
						format(moneybagmsg, sizeof(moneybagmsg), "{58D3F7}[EASTER EGG] {FFFFFF}%s(%i) found an egg worth {FFDC2E}1 MONTH PREMIUM PACKAGE{FFFFFF}!", playerData[playerid][playerNamee], playerid);
						SendClientMessageToAll(COLOR_WHITE, moneybagmsg);
						
						playerData[playerid][vipExpires] = gettime() + 2592000;
						playerData[playerid][playerVIPLevel] = 1;
						savePlayerStats(playerid);
						
						disableAchieve(playerid);
						PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
						PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
						PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
						PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

						PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "Easter Egg");
						PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "You found an easter egg worth 1 month of premium!");
						PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);

						playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 8000, false, "i", playerid);

						SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[VIP AWARDED] {FFFFFF}Your VIP purchase has been activated. /viphelp to view a list of VIP content.");
						SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[VIP NOTICE] {FFFFFF}This package DOES NOT include a free house/vehicle.");
					}
					
					case 14:
					{
						new moneybagmsg[200];
						format(moneybagmsg, sizeof(moneybagmsg), "{58D3F7}[EASTER EGG] {FFFFFF}%s(%i) found an egg worth {FFDC2E}nothing >=){FFFFFF}!", playerData[playerid][playerNamee], playerid);
						SendClientMessageToAll(COLOR_WHITE, moneybagmsg);
						
						disableAchieve(playerid);
						PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
						PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
						PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
						PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

						PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "Easter Egg");
						PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "You found an easter egg worth nothing!");
						PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);

						playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 8000, false, "i", playerid);
					}
					
					case 15:
					{
						new moneybagmsg[200];
						format(moneybagmsg, sizeof(moneybagmsg), "{58D3F7}[EASTER EGG] {FFFFFF}%s(%i) found an egg worth {FFDC2E}A MINIGUN{FFFFFF}!", playerData[playerid][playerNamee], playerid);
						SendClientMessageToAll(COLOR_WHITE, moneybagmsg);
						
						disableAchieve(playerid);
						PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
						PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
						PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
						PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

						PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "Easter Egg");
						PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "You found an easter egg worth a minigun!");
						PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);

						playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 8000, false, "i", playerid);
						
						GivePlayerWeaponEx(playerid, 38, 100);
						playerData[playerid][adminWeapon] = true;
					}
					
					case 16 .. 19:
					{
						new moneybagmsg[200];
						format(moneybagmsg, sizeof(moneybagmsg), "{58D3F7}[EASTER EGG] {FFFFFF}%s(%i) found an egg worth {FFDC2E}$5,000{FFFFFF}!", playerData[playerid][playerNamee], playerid);
						SendClientMessageToAll(COLOR_WHITE, moneybagmsg);
						
						disableAchieve(playerid);
						PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
						PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
						PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
						PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

						PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "Easter Egg");
						PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "You found an easter egg worth $5,000");
						PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);

						playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 8000, false, "i", playerid);
						
						playerGiveMoney(playerid, 5000);
					}
				}
			
				
				DestroyDynamicObject(moneyBagInfo[MoneybagID][bagID]);
				Delete3DTextLabel(moneyBagInfo[MoneybagID][bagLabel]);
				serverInfo[moneybagid] = -1;
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You're not close enough to a money bag.");
			}
		}
		else
		{
			// No money bag exists
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}There is no money bag hidden.");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}