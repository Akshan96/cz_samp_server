#define MAX_BAG_LOCATIONS 39

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
	{1, 30000, 1, {-1610.3921, 897.7698, 9.2266}, "Downtown San Fierro"},
	{2, 30000, 1, {-1615.2655, 1097.5190, 7.1875}, "Downtown San Fierro"},
	{3, 30000, 1, {-1397.9623, 440.2689, 7.1875}, "Easter Basin"},
	{4, 30000, 1, {-1329.4808, -341.3519, 14.1484}, "Easter Bay Airport"},
	{5, 30000, 1, {-1134.2330, -353.3854, 14.1484}, "Easter Bay Airport"},
	{6, 30000, 1, {-1196.0983, -88.5810, 14.1440}, "Easter Bay Airport"},
	{7, 30000, 1, {-1257.1660, 36.7188, 14.1402}, "Easter Bay Airport"},
	{8, 30000, 1, {-1666.1808, -303.8878, 14.1440}, "Easter Bay Airport"},
	{9, 30000, 1, {-2381.3374, -586.5721, 132.1117}, "Missionary Hill"},
	{10, 30000, 1, {-2539.5930, -622.1962, 132.7109}, "Missionary Hill"},
	{11, 30000, 1, {-2537.1924, -690.8735, 139.3203}, "Missionary Hill"},
	{12, 30000, 1, {-1731.2070, 1242.4445, 7.5469}, "Downtown San Fierro"},
	{13, 30000, 1, {-1696.8915, 1011.2025, 45.2109}, "Downtown San Fierro"},
	{14, 30000, 1, {-2772.4697, 318.9152, 4.4973}, "City Hall"},
	{15, 30000, 1, {-2701.2756, 376.2411, 4.9714}, "City Hall"},
	{16, 30000, 1, {-2580.9321, 310.0680, 5.1856}, "Queens"},
	{17, 30000, 1, {-2709.5879, 591.4570, 14.4531}, "Santa Flora"},
	{18, 30000, 1, {-2666.3938, 697.9611, 27.9141}, "Santa Flora"},
	{19, 30000, 1, {-2690.0032, 509.6320, 8.1138}, "Santa Flora"},
	{20, 30000, 1, {-2492.2290, 382.6849, 27.7656}, "Queens"},
	{21, 30000, 1, {-2503.5049, 522.6312, 30.0721}, "Queens"},
	{22, 30000, 1, {-2509.9875, 477.7537, 19.5799}, "Queens"},
	{23, 30000, 1, {-2207.4805, 691.6300, 50.7107}, "Chinatown"},
	{24, 30000, 1, {-2178.7991, 608.0864, 35.1641}, "Chinatown"},
	{25, 30000, 1, {-2513.1812, 744.9207, 35.0156}, "Juniper Hill"},
	{26, 30000, 1, {-2537.8447, 819.8224, 49.9844}, "Juniper Hill"},
	{27, 30000, 1, {-2474.7837, 1026.5109, 59.8243}, "Juniper Hollow"},
	{28, 30000, 1, {-2483.1089, 1062.3678, 60.5710}, "Juniper Hollow"},
	{29, 30000, 1, {-2440.5713, 936.6457, 45.4208}, "Juniper Hollow"},
	{30, 30000, 1, {-2323.7312, 1007.5217, 50.6953}, "Juniper Hollow"},
	{31, 30000, 1, {-1480.1875, 1081.4640, 7.1846}, "Esplanade East"},
	{32, 30000, 1, {-1421.0746, 887.9710, 7.1875}, "Esplanade East"},
	{33, 30000, 1, {-1904.4598, 288.8323, 41.0469}, "Downtown"},
	{34, 30000, 1, {-1904.9045, 219.7438, 35.1504}, "Downtown"},
	{35, 30000, 1, {-1959.0493, 103.1213, 26.2734}, "Cranberry Station"},
	{36, 30000, 1, {-1969.2363, 152.2529, 27.6875}, "Cranberry Station"},
	{37, 30000, 1, {-2043.3934, -33.0418, 35.4254}, "Doherty"},
	{38, 30000, 1, {-2151.1548, -102.4534, 35.3203}, "Doherty"},
	{39, 30000, 1, {-2238.3506, -102.8241, 35.3203}, "Garcia"}
	//{40, 40000, 1, {1918.715698, 1311.942138, 9.257812}, "The High Roller"},
	//{41, 40000, 1, {2103.442626, 1002.029174, 11.048305}, "Come-A-Lot"},
	//{42, 40000, 1, {2005.812133, 1076.936035, 11.070202}, "The Four Dragons Casino"},
	//{43, 40000, 1, {1604.183349, 1157.920654, 10.812500}, "Las Venturas Airport"},
	//{44, 40000, 1, {1645.757690, 1349.336791, 10.799027}, "Las Venturas Airport"},
	//{45, 40000, 1, {1669.532592, 2036.920410, 11.367187}, "Redsands West"},
	//{46, 40000, 1, {1636.607910, 2224.634765, 11.062500}, "Redsands West"},
	//{47, 40000, 1, {2275.400146, 2267.694824, 10.820312}, "Roca Escalante"},
	//{48, 40000, 1, {2401.107177, 2526.143798, 10.820312}, "Roca Escalante"},
	//{49, 40000, 1, {2109.749267, 2329.810302, 11.742187}, "The Emerald Isle"},
	//{50, 40000, 1, {2019.337646, 2350.670654, 10.820312}, "The Emerald Isle"},
	//{51, 40000, 1, {1874.943969, 2389.542724, 10.820312}, "Redsands East"},
	//{52, 40000, 1, {1843.580932, 2564.750488, 11.023437}, "Julius Thruway North"},
	//{53, 40000, 1, {2148.466796, 2716.021728, 10.820312}, "Spinybed"}
};

forward autoMoneyBag();
public autoMoneyBag()
{
	if (serverInfo[moneybagid] != -1)
	{
		// Remove the money bag, no one found it!
		new MoneybagID = serverInfo[moneybagid];
		DestroyDynamicObject(moneyBagInfo[MoneybagID][bagID]);
		Delete3DTextLabel(moneyBagInfo[MoneybagID][bagLabel]);
		serverInfo[moneybagid] = -1;
		SendClientMessageToAll(COLOR_WHITE, "{58D3F7}[MONEY BAG] {FFFFFF}Ooo No! The event has ended, no one found the money bag.");
	}
	else
	{
		// Place a random money bag
		new randomBag = random(MAX_BAG_LOCATIONS);
		
		moneyBagInfo[randomBag][bagID] = CreateDynamicObject(1550, moneyBagInfo[randomBag][bagXYZ][0], moneyBagInfo[randomBag][bagXYZ][1], (moneyBagInfo[randomBag][bagXYZ][2] - 0.6), 270.00000, 0.00000, 0.00000);
		moneyBagInfo[randomBag][bagLabel] = Create3DTextLabel("/pickup", COLOR_YELLOW, moneyBagInfo[randomBag][bagXYZ][0], moneyBagInfo[randomBag][bagXYZ][1], (moneyBagInfo[randomBag][bagXYZ][2] - 0.5), 10, 0, 0);
		
		serverInfo[moneybagid] = randomBag;			
		
		new bagInfo[200];
		format(bagInfo, sizeof(bagInfo), "{58D3F7}[MONEY BAG] {FFFFFF}Come On! A money bag has been hidden in {FFDC2E}%s{FFFFFF}! Type /pickup if you find it!", moneyBagInfo[randomBag][bagTitle]);
		SendClientMessageToAll(COLOR_WHITE, bagInfo);
	}
}

COMMAND:startmoneybag(playerid, params[])
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
				SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[MONEY BAG] {FFFFFF}Oops! The event has ended, no one found the money bag.");
			}
			else
			{
				// Place a random money bag
				new randomBag = random(MAX_BAG_LOCATIONS);
				
				moneyBagInfo[randomBag][bagID] = CreateDynamicObject(1550, moneyBagInfo[randomBag][bagXYZ][0], moneyBagInfo[randomBag][bagXYZ][1], (moneyBagInfo[randomBag][bagXYZ][2] - 0.6), 270.00000, 0.00000, 0.00000);
				moneyBagInfo[randomBag][bagLabel] = Create3DTextLabel("/pickup", COLOR_YELLOW, moneyBagInfo[randomBag][bagXYZ][0], moneyBagInfo[randomBag][bagXYZ][1], (moneyBagInfo[randomBag][bagXYZ][2] - 0.5), 10, 0, 0);
				
				serverInfo[moneybagid] = randomBag;			
				
				new bagInfo[200];
				format(bagInfo, sizeof(bagInfo), "{58D3F7}[MONEY BAG] {FFFFFF}A money bag has been hidden in {FFDC2E}%s{FFFFFF}! Type /pickup if you find it!", moneyBagInfo[randomBag][bagTitle]);
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

COMMAND:gotomoneybag(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			if (serverInfo[moneybagid] == -1)
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}There is no money bag active.");
			}
			else
			{
				// Go to bag
				new gotobag = serverInfo[moneybagid];
				SetPlayerPos(playerid, moneyBagInfo[gotobag][bagXYZ][0], moneyBagInfo[gotobag][bagXYZ][1], moneyBagInfo[gotobag][bagXYZ][2] + 1.0);
				SetPlayerVirtualWorld(playerid, 0);
				SetPlayerInterior(playerid, 0);
				
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You teleported to the money bag.");
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

COMMAND:moneybag(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (serverInfo[moneybagid] != -1)
		{
			// Show money bag location
			new MoneybagID = serverInfo[moneybagid];
			
			new bagInfo[200];
			format(bagInfo, sizeof(bagInfo), "{58D3F7}[MONEY BAG] {FFFFFF}The money bag is hidden in {FFDC2E}%s{FFFFFF}!", moneyBagInfo[MoneybagID][bagTitle]);
			SendClientMessage(playerid, COLOR_WHITE, bagInfo);
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

COMMAND:pickup(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (serverInfo[moneybagid] != -1)
		{
			// Show money bag location
			new MoneybagID = serverInfo[moneybagid];
			
			if(IsPlayerInRangeOfPoint(playerid, 5.0, moneyBagInfo[MoneybagID][bagXYZ][0], moneyBagInfo[MoneybagID][bagXYZ][1], moneyBagInfo[MoneybagID][bagXYZ][2]))
			{
				// Player found money bag
				for(new p; p < MAX_PLAYERS; p++)
				{
					new pName[24];
					GetPlayerName(p, pName, sizeof(pName));

					if(!strcmp(pName, playerData[playerid][playerNamee]))
					{
						new moneybagmsg[200];
						format(moneybagmsg, sizeof(moneybagmsg), "{58D3F7}[MONEY BAG] {FFFFFF}Well done! You found a money bag worth {FFDC2E}$%s{FFFFFF}.", FormatNumber(moneyBagInfo[MoneybagID][bagValue]));
						SendClientMessage(p, COLOR_WHITE, moneybagmsg);
					}
					else
					{
						new moneybagmsg[200];
						format(moneybagmsg, sizeof(moneybagmsg), "{58D3F7}[MONEY BAG] {FFFFFF}%s(%i) found a money bag worth {FFDC2E}$%s{FFFFFF}!", playerData[playerid][playerNamee], playerid, FormatNumber(moneyBagInfo[MoneybagID][bagValue]));
						SendClientMessage(p, COLOR_WHITE, moneybagmsg);
					}
				}
				
				playerGiveMoney(playerid, moneyBagInfo[MoneybagID][bagValue]);
				playerGiveXP(playerid, 20);
				
				DestroyDynamicObject(moneyBagInfo[MoneybagID][bagID]);
				Delete3DTextLabel(moneyBagInfo[MoneybagID][bagLabel]);
				serverInfo[moneybagid] = -1;
				playerData[playerid][moneyBags] = playerData[playerid][moneyBags] + 1;
				
				if(playerData[playerid][moneyBags] == 1)
				{
					disableAchieve(playerid);
					PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
					PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
					PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
					PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

					PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "Easy Money");
					PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "You found and claimed your first money bag.");
					PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);

					playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 8000, false, "i", playerid);
				}
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
