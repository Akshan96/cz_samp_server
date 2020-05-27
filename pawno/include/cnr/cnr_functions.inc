forward enablearrest(playerid);
forward isPlayerInRangeOfPlayer(playerid, otherid, Float:cRadius);
forward updatePlayerRobbingProgress(playerid, robberyTime);
forward forceRobberyCancel(playerid);
forward givePlayerWanted(playerid, amount);
forward playerGiveMoney(playerid, amount);
forward playerTakeMoney(playerid, amount);
forward playerTakeBankMoney(playerid, amount);
forward playerGiveBankMoney(playerid, amount);
forward playerSetMoney(playerid, amount);
forward sendMessageAdmins(message);
forward cancelRobbery(playerid);
forward beginRobbery(playerid);
forward Unfreeze(playerid);
forward randomEx(min, max);
forward Retaze(playerid);
forward recuff(playerid);
forward checkDriveB(playerid);
forward untie(playerid);
forward uncuff(playerid);
forward reFix(playerid);
forward reFlip(playerid);
forward reNOS(playerid);
forward reEMP(playerid);
forward pHouseCP(playerid);
forward mechReEmp(playerid);
forward resetEMP(vehicleID);
forward arrest(playerid);
forward countRobTime();
forward countMuteTime();
forward GetClosestPlayer(playerid);
forward clearWorldObjects(playerid);
forward checkNameStatus(playerName[]);
forward updateExperienceCounter(playerid);
forward newPlayerColour(playerid);
forward addWorldObjects();
forward getVehicleModelFromName(vname[]);
forward checkSeatStatus(vehicleid, seatid);
forward GetClosestPlayerToPlayer(playerid);
forward reactivateRob(playerid);
forward reactivateRape(playerid);
forward sendWantedMessage(playerid, amountAdded);
forward playerGiveXP(playerid, amount);
forward hideAddedXP(playerid);
forward hideHitmarkerTD(playerid);
forward highPing();
forward Timer();
forward speedhack(playerid);
forward KickPublic(playerid);
forward kickWithDelay(playerid);
forward secretHideout(elevationState);
forward hideAnnouncement();
forward reKidnap(playerid);
forward playerHitmanTracker(playerid, otherPlayer);
forward raped(playerid);
forward taxplayer(playerid);
forward gameTip();
forward command(playerid);
forward saveStats();
forward randomWeather();
forward blowJail(playerid);
forward blowJail2(playerid);
forward resetJailTimer();
forward resetJailTimer2();
forward spawnPlayer(playerid);
forward rebreakcuffs(playerid);
forward AntiSpawnkill(playerid);
forward disableAchieve(playerid);
forward weedExpire(playerid);
forward StopSpam(playerid);
forward retruck(playerid);
forward canSaveStats(playerid);
forward reHeal(playerid);
forward reCure(playerid);
forward classCheck();
forward closeDialogs(playerid);
forward reBreakin(playerid);
forward loadObjects(playerid);
forward objectsLoaded(playerid);
forward dmStats(playerid);
forward disableStreak(playerid);
forward swapMOTD();
forward Countdown();
new hidden[MAX_PLAYERS];
new at[MAX_PLAYERS];
new cl[MAX_PLAYERS];
new bo[MAX_PLAYERS];
new pFPS[MAX_PLAYERS];
new CountDownTimer;
new CountDownVar = 0;
public swapMOTD()
{
	if (serverInfo[enableMOTD])
	{
		new pick = random(3);
		new formatPick[128];

		switch (pick)
		{
			case 0:
			{
				format(formatPick, sizeof(formatPick), "MOTD: ~w~%s", serverInfo[MOTD1]);
				TextDrawSetString(Text:MOTDTD, formatPick);
			}

			case 1:
			{
				format(formatPick, sizeof(formatPick), "MOTD: ~w~%s", serverInfo[MOTD2]);
				TextDrawSetString(Text:MOTDTD, formatPick);
			}

			case 2:
			{
				format(formatPick, sizeof(formatPick), "MOTD: ~w~%s", serverInfo[MOTD3]);
				TextDrawSetString(Text:MOTDTD, formatPick);
			}
		}
	}
	else
	{
		TextDrawSetString(Text:MOTDTD, " ");
	}
}

public enablearrest(playerid)
{
    playerData[playerid][playerCanArrest] = true;
}

public disableStreak(playerid)
{
	TextDrawHideForPlayer(playerid, streakBox[0]);
	TextDrawHideForPlayer(playerid, streakBox[1]);
	TextDrawHideForPlayer(playerid, streakBox[2]);

	PlayerTextDrawHide(playerid, playerData[playerid][killStreak]);
}

public dmStats(playerid)
{
	new
		kills[15],
		deaths[15],
		ratioString[100],
		myStreak[15]
	;

	new Float:ratio = float(playerData[playerid][dmKills]) / float(playerData[playerid][dmDeaths]);

	if (playerData[playerid][dmKills] == 0 && playerData[playerid][dmDeaths] == 0)
	{
		format(ratioString, sizeof(ratioString), "N/A");
	}
	else
	{
		format(ratioString, sizeof(ratioString), "%0.2f", ratio);
	}

	format(kills, sizeof(kills), "%i", playerData[playerid][dmKills]);
	format(deaths, sizeof(deaths), "%i", playerData[playerid][dmDeaths]);
	format(myStreak, sizeof(myStreak), "%i", playerData[playerid][dmStreak]);

	PlayerTextDrawSetString(playerid, playerData[playerid][dmArena][0], kills);
	PlayerTextDrawSetString(playerid, playerData[playerid][dmArena][1], deaths);
	PlayerTextDrawSetString(playerid, playerData[playerid][dmArena][2], ratioString);
	PlayerTextDrawSetString(playerid, playerData[playerid][dmArena][3], myStreak);

	switch(playerData[playerid][dmStreak])
	{
		case 3:
		{
			PlayerTextDrawSetString(playerid, playerData[playerid][killStreak], "~r~3 Kill Streak~w~~n~Desert Eagle Received");

			TextDrawShowForPlayer(playerid, streakBox[0]);
			TextDrawShowForPlayer(playerid, streakBox[1]);
			TextDrawShowForPlayer(playerid, streakBox[2]);

			PlayerTextDrawShow(playerid, playerData[playerid][killStreak]);

			GivePlayerWeaponEx(playerid, 24, 50000);
			playerData[playerid][streakTimer] = SetTimerEx("disableStreak", 3000, false, "i", playerid);

			for (new i=0; i<MAX_PLAYERS; i++)
			{
				if(playerData[i][isInDM])
				{
					new dmLeave[100];
					format(dmLeave, sizeof(dmLeave), "{58D3F7}[MINIGAME] {FFFFFF}%s(%i) is on a 3 kill streak!", playerData[playerid][playerNamee], playerid);
					SendClientMessage(i, COLOR_WHITE, dmLeave);
				}
			}
		}

		case 6:
		{
			PlayerTextDrawSetString(playerid, playerData[playerid][killStreak], "~r~6 Kill Streak~w~~n~Rockets Received");

			TextDrawShowForPlayer(playerid, streakBox[0]);
			TextDrawShowForPlayer(playerid, streakBox[1]);
			TextDrawShowForPlayer(playerid, streakBox[2]);

			PlayerTextDrawShow(playerid, playerData[playerid][killStreak]);

			GivePlayerWeaponEx(playerid, 35, 50000);
			playerData[playerid][streakTimer] = SetTimerEx("disableStreak", 3000, false, "i", playerid);

			for (new i=0; i<MAX_PLAYERS; i++)
			{
				if(playerData[i][isInDM])
				{
					new dmLeave[100];
					format(dmLeave, sizeof(dmLeave), "{58D3F7}[MINIGAME] {FFFFFF}%s(%i) {FFFFFF}is on a 6 kill streak!", playerData[playerid][playerNamee], playerid);
					SendClientMessage(i, COLOR_WHITE, dmLeave);
				}
			}
		}

		case 10:
		{
			PlayerTextDrawSetString(playerid, playerData[playerid][killStreak], "~r~10 Kill Streak~w~~n~Minigun Received");

			TextDrawShowForPlayer(playerid, streakBox[0]);
			TextDrawShowForPlayer(playerid, streakBox[1]);
			TextDrawShowForPlayer(playerid, streakBox[2]);

			PlayerTextDrawShow(playerid, playerData[playerid][killStreak]);

			GivePlayerWeaponEx(playerid, 38, 50000);
			playerData[playerid][streakTimer] = SetTimerEx("disableStreak", 3000, false, "i", playerid);

			for (new i=0; i<MAX_PLAYERS; i++)
			{
				if(playerData[i][isInDM])
				{
					new dmLeave[100];
					format(dmLeave, sizeof(dmLeave), "{58D3F7}[MINIGAME] {FFFFFF}%s(%i) {FFFFFF}is on a 10 kill streak!", playerData[playerid][playerNamee], playerid);
					SendClientMessage(i, COLOR_WHITE, dmLeave);
				}
			}
		}
	}
}

public loadObjects(playerid)
{
	new Float:resetHealth;

	if(!playerData[playerid][playerAdminDuty])
	{
		GetPlayerHealth(playerid, resetHealth);
		playerData[playerid][savedHealth] = resetHealth;
	}
	playerData[playerid][hasSpawned] = false;
	TogglePlayerControllable(playerid, 0);

	PlayerTextDrawShow(playerid, playerData[playerid][objects][0]);
	PlayerTextDrawShow(playerid, playerData[playerid][objects][1]);
	PlayerTextDrawShow(playerid, playerData[playerid][objects][2]);
	PlayerTextDrawShow(playerid, playerData[playerid][objects][3]);

	if(!playerData[playerid][playerAdminDuty])
	{
		SetPlayerHealth(playerid, 1000);
	}
	playerData[playerid][objectsTimer] = SetTimerEx("objectsLoaded", 1500, false, "i", playerid);
}

public objectsLoaded(playerid)
{
	PlayerTextDrawHide(playerid, playerData[playerid][objects][0]);
	PlayerTextDrawHide(playerid, playerData[playerid][objects][1]);
	PlayerTextDrawHide(playerid, playerData[playerid][objects][2]);
	PlayerTextDrawHide(playerid, playerData[playerid][objects][3]);
	if(!playerData[playerid][playerAdminDuty])
	{
		SetPlayerHealth(playerid, playerData[playerid][savedHealth]);
	}
	playerData[playerid][hasSpawned] = true;
	TogglePlayerControllable(playerid, 1);
}

public reBreakin(playerid)
{
	playerData[playerid][canBreakIn] = true;
}

public closeDialogs(playerid)
{
	// Welcome Box
	PlayerTextDrawHide(playerid, playerData[playerid][Welcome1]);
	PlayerTextDrawHide(playerid, playerData[playerid][Welcome2]);
	PlayerTextDrawHide(playerid, playerData[playerid][Welcome3]);
	PlayerTextDrawHide(playerid, playerData[playerid][Welcome4]);
	PlayerTextDrawHide(playerid, playerData[playerid][Welcome5]);
	PlayerTextDrawHide(playerid, playerData[playerid][Welcome6]);
	PlayerTextDrawHide(playerid, playerData[playerid][Welcome7]);
	PlayerTextDrawHide(playerid, playerData[playerid][Welcome8]);

	// Innocent Kill Box
	PlayerTextDrawHide(playerid, playerData[playerid][InnocentKill1]);
	PlayerTextDrawHide(playerid, playerData[playerid][InnocentKill2]);
	PlayerTextDrawHide(playerid, playerData[playerid][InnocentKill3]);
	PlayerTextDrawHide(playerid, playerData[playerid][InnocentKill4]);
	PlayerTextDrawHide(playerid, playerData[playerid][InnocentKill5]);
	PlayerTextDrawHide(playerid, playerData[playerid][InnocentKill6]);
	PlayerTextDrawHide(playerid, playerData[playerid][InnocentKill7]);
	PlayerTextDrawHide(playerid, playerData[playerid][InnocentKill8]);

	// Stats
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][0]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][1]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][2]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][3]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][4]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][5]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][6]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][7]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][8]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][9]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][10]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][11]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][12]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][13]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][14]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][15]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][16]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][17]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][18]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][19]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][20]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][21]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][22]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][23]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][24]);

	TextDrawHideForPlayer(playerid, TopTD[0]);
	TextDrawHideForPlayer(playerid, TopTD[1]);
	TextDrawHideForPlayer(playerid, TopTD[2]);
	TextDrawHideForPlayer(playerid, TopTD[3]);
	TextDrawHideForPlayer(playerid, TopTD[4]);
	TextDrawHideForPlayer(playerid, TopTD[5]);
	TextDrawHideForPlayer(playerid, TopTD[6]);
	TextDrawHideForPlayer(playerid, TopTD[7]);
	TextDrawHideForPlayer(playerid, TopTD[8]);
	TextDrawHideForPlayer(playerid, TopTD[9]);
	TextDrawHideForPlayer(playerid, TopTD[10]);
	TextDrawHideForPlayer(playerid, TopTD[11]);
	TextDrawHideForPlayer(playerid, TopTD[12]);
	TextDrawHideForPlayer(playerid, TopTD[13]);
	TextDrawHideForPlayer(playerid, TopTD[14]);
	TextDrawHideForPlayer(playerid, TopTD[15]);
	TextDrawHideForPlayer(playerid, TopTD[16]);
	TextDrawHideForPlayer(playerid, TopTD[17]);
	TextDrawHideForPlayer(playerid, TopTD[18]);
	TextDrawHideForPlayer(playerid, TopTD[19]);
	TextDrawHideForPlayer(playerid, TopTD[20]);
	TextDrawHideForPlayer(playerid, TopTD[21]);
	TextDrawHideForPlayer(playerid, TopTD[22]);
	TextDrawHideForPlayer(playerid, TopTD[23]);
	TextDrawHideForPlayer(playerid, TopTD[24]);
	TextDrawHideForPlayer(playerid, TopTD[25]);
	TextDrawHideForPlayer(playerid, TopTD[26]);
	TextDrawHideForPlayer(playerid, TopTD[27]);
	TextDrawHideForPlayer(playerid, TopTD[28]);
	TextDrawHideForPlayer(playerid, TopTD[29]);
	TextDrawHideForPlayer(playerid, TopTD[30]);
	TextDrawHideForPlayer(playerid, TopTD[31]);
	TextDrawHideForPlayer(playerid, TopTD[32]);
	TextDrawHideForPlayer(playerid, TopTD[33]);
	TextDrawHideForPlayer(playerid, TopTD[34]);
	TextDrawHideForPlayer(playerid, TopTD[35]);
	TextDrawHideForPlayer(playerid, TopTD[36]);
	TextDrawHideForPlayer(playerid, TopTD[37]);
	TextDrawHideForPlayer(playerid, TopTD[38]);
	TextDrawHideForPlayer(playerid, TopTD[39]);
	TextDrawHideForPlayer(playerid, TopTD[40]);
	TextDrawHideForPlayer(playerid, TopTD[41]);
	
	// Welcome Box
	PlayerTextDrawHide(playerid, playerData[playerid][Welcome1]);
	PlayerTextDrawHide(playerid, playerData[playerid][Welcome2]);
	PlayerTextDrawHide(playerid, playerData[playerid][Welcome3]);
	PlayerTextDrawHide(playerid, playerData[playerid][Welcome4]);
	PlayerTextDrawHide(playerid, playerData[playerid][Welcome5]);
	PlayerTextDrawHide(playerid, playerData[playerid][Welcome6]);
	PlayerTextDrawHide(playerid, playerData[playerid][Welcome7]);
	PlayerTextDrawHide(playerid, playerData[playerid][Welcome8]);

	// Innocent Kill Box
	PlayerTextDrawHide(playerid, playerData[playerid][InnocentKill1]);
	PlayerTextDrawHide(playerid, playerData[playerid][InnocentKill2]);
	PlayerTextDrawHide(playerid, playerData[playerid][InnocentKill3]);
	PlayerTextDrawHide(playerid, playerData[playerid][InnocentKill4]);
	PlayerTextDrawHide(playerid, playerData[playerid][InnocentKill5]);
	PlayerTextDrawHide(playerid, playerData[playerid][InnocentKill6]);
	PlayerTextDrawHide(playerid, playerData[playerid][InnocentKill7]);
	PlayerTextDrawHide(playerid, playerData[playerid][InnocentKill8]);

	// Stats
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][0]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][1]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][2]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][3]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][4]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][5]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][6]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][7]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][8]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][9]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][10]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][11]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][12]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][13]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][14]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][15]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][16]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][17]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][18]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][19]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][20]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][21]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][22]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][23]);
	PlayerTextDrawHide(playerid, playerData[playerid][PlayerStats][24]);
}

public classCheck()
{
	for(new i = 0; i < MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i) && playerData[i][playerLoggedIn])
		{
			if (playerData[i][hasSpawned])
			{
				switch(playerData[i][playerClass])
				{
					case CLASS_CIA:
					{
						// XP check
						if (playerData[i][playerXP] < 10000)
						{
							// Not allowed in this class
							ForceClassSelection(i);
							SetPlayerHealth(i, 0.0);
						}
					}

					case CLASS_FBI:
					{
						// XP check
						if (playerData[i][playerXP] < 5000)
						{
							// Not allowed in this class
							ForceClassSelection(i);
							SetPlayerHealth(i, 0.0);
						}
					}

					case CLASS_ARMY:
					{
						// XP check
						if (playerData[i][playerXP] < 20000)
						{
							// Not allowed in this class
							ForceClassSelection(i);
							SetPlayerHealth(i, 0.0);
						}
					}

					case CLASS_SECRETSERVICE:
					{
						// XP check
						if (playerData[i][playerVIPLevel] < 1)
						{
							// Not allowed in this class
							ForceClassSelection(i);
							SetPlayerHealth(i, 0.0);
						}
					}
				}
			}
		}
	}
}

public reCure(playerid)
{
	playerData[playerid][canCure] = true;
}

public reHeal(playerid)
{
	playerData[playerid][canHeal] = true;
}

public canSaveStats(playerid)
{
	playerData[playerid][playerCanSaveStats] = true;
}

public retruck(playerid)
{
	playerData[playerid][canTruck] = true;
}

public StopSpam(playerid)
{
	playerData[playerid][messageCount] = 0;
}

public weedExpire(playerid)
{
    playerData[playerid][canWeed] = true;
	Delete3DTextLabel(playerData[playerid][weedLabel]);
	return 1;
}

public disableAchieve(playerid)
{
	PlayerTextDrawHide(playerid, playerData[playerid][Achieve1]);
	PlayerTextDrawHide(playerid, playerData[playerid][Achieve2]);
	PlayerTextDrawHide(playerid, playerData[playerid][Achieve3]);
	PlayerTextDrawHide(playerid, playerData[playerid][Achieve4]);
	PlayerPlaySound(playerid,1184,0.0,0.0,0.0);
}

public AntiSpawnkill(playerid)
{
	if (!playerData[playerid][playerAdminDuty])
	{
		SetPlayerHealth(playerid, 100.0);
	}

	Delete3DTextLabel(playerData[playerid][spawnLabel]);
	playerData[playerid][ctpImmune] = false;
	playerData[playerid][abImmune] = false;
	return 1;
}

public spawnPlayer(playerid)
{
	if (!playerData[playerid][selectingClass])
	{
		SpawnPlayer(playerid);
	}
}

public resetJailTimer()
{
	serverInfo[jailblown] = 0;
}

public resetJailTimer2()
{
	serverInfo[jailblown2] = 0;
}

public blowJail(playerid)
{
	if (serverInfo[jailblown] == 0)
	{
		for(new p; p < MAX_PLAYERS; p++)
		{
			new pName[24];
			GetPlayerName(p, pName, sizeof(pName));

			if(!strcmp(pName, playerData[playerid][playerNamee]))
			{
				SendClientMessage(p, COLOR_WHITE, "{FFDC2E}[JAIL BLOWN] {FFFFFF}You blew up the San Fierro jail cells and freed everyone inside.");
			}
			else
			{
				new jailm[200];
				format(jailm, sizeof(jailm), "{FFDC2E}[JAIL BLOWN] {FFFFFF}%s(%i) has blown the San Fierro jail and freed the criminals!", playerData[playerid][playerNamee], playerid);
				SendClientMessage(p, COLOR_WHITE, jailm);
			}
		}

		for(new i = 0; i < MAX_PLAYERS; i++)
		{
			if(IsPlayerConnected(i) && playerData[i][playerJailTime] > 1)
			{
				if (playerData[i][playerAdminJailed] != 1)
				{
					if(playerData[i][playerTown] == SF)
					{
						SetPlayerInterior(i, 10);
						SetPlayerPos(i, 216.8014, 120.5791, 999.0156);
						SetPlayerFacingAngle(i, 183.3742);
						SetPlayerVirtualWorld(i, 25);
						SetPlayerHealth(i, 100);
						PlayerTextDrawSetString(i, playerData[i][playerJailTimerTD], " ");
						playerData[i][playerBailTo] = -1;
						playerData[i][playerBailPrice] = -1;
						playerData[i][playerJailTime] = 0;
						KillTimer(playerData[i][jailTimer]);

						SendClientMessage(i, COLOR_WHITE, "{FFDC2E}[JAIL BLOWN] {FFFFFF}You escaped from jail.");
					}
				}
			}
		}

		serverInfo[jailblown] = GetTickCount();
		SetTimer("resetJailTimer", 300000, false);
		givePlayerWanted(playerid, 12);
		playerGiveXP(playerid, 40);
		sendWantedMessage(playerid, 12);
		playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
		SetPlayerScore(playerid, playerData[playerid][playerScore]);
		newPlayerColour(playerid);
	}
}

public blowJail2(playerid)
{
	if (serverInfo[jailblown2] == 0)
	{
		for(new p; p < MAX_PLAYERS; p++)
		{
			new pName[24];
			GetPlayerName(p, pName, sizeof(pName));

			if(!strcmp(pName, playerData[playerid][playerNamee]))
			{
				SendClientMessage(p, COLOR_WHITE, "{FFDC2E}[JAIL BLOWN] {FFFFFF}You blew up the Las Venturas jail cells and freed everyone inside.");
			}
			else
			{
				new jailm[200];
				format(jailm, sizeof(jailm), "{FFDC2E}[JAIL BLOWN] {FFFFFF}%s(%i) has blown the Las Venturas jail and freed the criminals!", playerData[playerid][playerNamee], playerid);
				SendClientMessage(p, COLOR_WHITE, jailm);
			}
		}

		for(new i = 0; i < MAX_PLAYERS; i++)
		{
			if(IsPlayerConnected(i) && playerData[i][playerJailTime] > 1)
			{
				if (playerData[i][playerAdminJailed] != 1)
				{
					if(playerData[i][playerTown] == LV)
					{
						SetPlayerInterior(playerid, 3);
						SetPlayerPos(playerid, 200.6972, 168.2653, 1003.0234);
						SetPlayerFacingAngle(playerid, 89.0391);
						SetPlayerVirtualWorld(playerid, 142);
						SetPlayerHealth(i, 100);
						PlayerTextDrawSetString(i, playerData[i][playerJailTimerTD], " ");
						playerData[i][playerBailTo] = -1;
						playerData[i][playerBailPrice] = -1;
						playerData[i][playerJailTime] = 0;
						KillTimer(playerData[i][jailTimer]);
					}
					SendClientMessage(i, COLOR_WHITE, "{FFDC2E}[JAIL BLOWN] {FFFFFF}You escaped from jail.");
				}
			}
		}

		serverInfo[jailblown2] = GetTickCount();
		SetTimer("resetJailTimer2", 300000, false);
		givePlayerWanted(playerid, 12);
		playerGiveXP(playerid, 40);
		sendWantedMessage(playerid, 12);
		playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
		SetPlayerScore(playerid, playerData[playerid][playerScore]);
		newPlayerColour(playerid);
	}
}

public randomWeather()
{
	new weather = random(6);

	switch(weather)
	{
		case 0: // Sunny
		{
			SetWeather(4);
		}
		case 1: // Sunny
		{
			SetWeather(4);
		}
		case 2: // Sunny
		{
			SetWeather(4);
		}
		case 3: // Cloudy
		{
			SetWeather(7);
		}
		case 4: // Sunny
		{
			SetWeather(4);
		}
		case 5: // Storm
		{
			SetWeather(4);
		}
	}
}

IsVehicleOccupied(vehiclesID)
{
    for(new i = 0; i < MAX_PLAYERS; i++)
	{
        if(IsPlayerConnected(i))
		{
            if(IsPlayerInVehicle(i, vehiclesID))
			{
				return 1;
			}
        }
    }
    return 0;
}

PreloadAnimLib(playerid, animlib[])
{
	ApplyAnimation(playerid,animlib,"null",0.0,0,0,0,0,0);
}

public saveStats()
{
	for(new i = 0; i < MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i) && playerData[i][playerLoggedIn])
		{
			savePlayerStats(i);
		}
	}
}

public command(playerid)
{
	playerData[playerid][canUseCommands] = true;
}

public gameTip()
{
	// Random tip
	new message = random(10);
	switch(message)
	{
		case 0:
		{
			SendClientMessageToAll(COLOR_WHITE, "{58D3F7}[TIP] {FFFFFF}Type /cmds to view a list of server commands!");
		}
		case 1:
		{
			SendClientMessageToAll(COLOR_WHITE, "{58D3F7}[TIP] {FFFFFF}Spotted a cheat? /report them!");
		}
		case 2:
		{
			SendClientMessageToAll(COLOR_WHITE, "{58D3F7}[TIP] {FFFFFF}Found a bug or an exploit? Report it on www.CZCNR.ml");
		}
		case 3:
		{
			SendClientMessageToAll(COLOR_WHITE, "{58D3F7}[TIP] {FFFFFF}You can type /pc to view a list of the player colours.");
		}
		case 4:
		{
			SendClientMessageToAll(COLOR_WHITE, "{58D3F7}[TIP] {FFFFFF}Got a question? Use /ask to ask our server helpers!");
		}
		case 5:
		{
			SendClientMessageToAll(COLOR_WHITE, "{58D3F7}[TIP] {FFFFFF}Want to change your job? Head to the Job Centre (/gps)!");
		}
		case 6:
		{
			SendClientMessageToAll(COLOR_WHITE, "{58D3F7}[TIP] {FFFFFF}Save your stats using /savestats regularly to avoid stat loss!");
		}
		case 7:
		{
			SendClientMessageToAll(COLOR_WHITE, "{58D3F7}[TIP] {FFFFFF}Wish to donate to the server? Visit www.CZCNR.ml");
		}
		case 8:
		{
			SendClientMessageToAll(COLOR_WHITE, "{58D3F7}[TIP] {FFFFFF}Having trouble finding a location? Type /gps");
		}
		case 9:
		{
			SendClientMessageToAll(COLOR_WHITE, "{58D3F7}[TIP] {FFFFFF}Want to change spawn city? Type /selecttown");
		}
	}
}

public taxplayer(playerid)
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerVIPLevel] < 1)
		{
			if(playerData[playerid][playerMoney] >= 5000)
			{
				if(playerData[playerid][playerJailTime] < 10)
				{
					new takeValue = floatround(playerData[playerid][playerMoney] * 0.030, floatround_round);

					playerTakeMoney(playerid, takeValue);

					// Send tax info
					SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[TAX] {FFFFFF}The server tax has been deducted from your account balance.");
				}
			}

			/*if(playerData[playerid][playerBank] >= 500000)
			{
				if(playerData[playerid][playerJailTime] < 10)
				{
					new takeValue = floatround(playerData[playerid][playerBank] * 0.001, floatround_round);

					playerTakeBankMoney(playerid, takeValue);
				}
			}*/
		}
	}
}

public raped(playerid)
{
	if(playerData[playerid][hasSTD])
	{
		playerData[playerid][suicide] = true;

		new Float:health;
		GetPlayerHealth(playerid, health);
		SetPlayerHealth(playerid, health - 3);
	}
	else
	{
		KillTimer(playerData[playerid][rapedTimer]);
	}
}

public playerHitmanTracker(playerid, otherPlayer)
{
	if(playerData[playerid][playerJailTime] > 1)
	{
		// Disable tracker
		playerData[playerid][playerIsTracking] = false;
		KillTimer(playerData[playerid][playerHitmanTrackerTimer]);
	}
	else
	{
		new Float:otherPlayerX, Float:otherPlayerY, Float:otherPlayerZ;
		GetPlayerPos(otherPlayer, otherPlayerX, otherPlayerY, otherPlayerZ);
		new Float:distance = GetPlayerDistanceFromPoint(playerid, otherPlayerX, otherPlayerY, otherPlayerZ);

		new trackString[100];
		format(trackString, sizeof(trackString), "%.0f Metres", distance);
		PlayerTextDrawSetString(playerid, playerData[playerid][playerTracker], trackString);
	}
}

public reKidnap(playerid)
{
	playerData[playerid][playerCanKidnap] = true;
	KillTimer(playerData[playerid][kidnapTimer]);
	return 1;
}

public hideAnnouncement()
{
	TextDrawHideForAll(AnnounceTD);
	return 1;
}

public KickPublic(playerid)
{
    Kick(playerid);
}

stock KickWithMessage(playerid, message[])
{
    SendClientMessage(playerid, COLOR_RED, message);
    SetTimerEx("KickPublic", 1000, 0, "d", playerid);
}

stock SoundForAll(sound)
{
	for (new i = 0; i != MAX_PLAYERS; ++i)
	{
		PlayerPlaySound(i,sound,0.0,0.0,0.0);
	}
}
public kickWithDelay(playerid)
{
	SetTimer("KickPublic", 500, false);
}

public Timer()
{
 	new timestring[256], daystring[256], gseconds = gtime % 60, gminutes = (gtime - gseconds) / 60;
	gtime ++;

	format(timestring, sizeof (timestring), "   %02d:%02d", gminutes, gseconds);
	TextDrawSetString(gTime, timestring);
	TextDrawShowForAll(gTime);
	format(daystring, sizeof (daystring), "%s", GetDayName());
	TextDrawSetString(gDay, daystring);
	TextDrawShowForAll(gDay);

	if(gday == 6 && gtime == 1440)
	{
		gday = 0;
		gtime = 0;
	}

	if(gtime == 1440)
	{
		gday++;
		gtime=0;
		format(daystring, sizeof (daystring), "   00:00");
		TextDrawSetString(gTime,daystring);
	}

	for(new i=0; i<MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i))
		{
			SetPlayerTime(i, gminutes, gseconds);
			if(gtime == 0)
			{
				// Tax players
				taxplayer(i);

				// award LEO players $800
				if (playerData[i][playerClass] == CLASS_POLICE || playerData[i][playerClass] == CLASS_CIA || playerData[i][playerClass] == CLASS_FBI)
				{
					if (playerData[i][playerJailTime] == 0)
					{
						SendClientMessage(i, COLOR_WHITE, "{58D3F7}[PAYMENT] {FFFFFF}You have received {FFDC2E}$800 {FFFFFF}in wages from the city.");
						playerGiveMoney(i, 800);
					}
				}

				if (playerData[i][playerClass] == CLASS_MEDIC)
				{
					if (playerData[i][playerJailTime] == 0)
					{
						SendClientMessage(i, COLOR_WHITE, "{58D3F7}[PAYMENT] {FFFFFF}You have received {FFDC2E}$500 {FFFFFF}in wages from the city.");
						playerGiveMoney(i, 500);
					}
				}

				if (playerData[i][hasSpawned])
				{
					if(playerData[i][houseCount] > 0)
					{
						new chousetax;
						chousetax = 1200 * playerData[i][houseCount];
						playerTakeMoney(i, chousetax);
					}
				}
			}
		}
	}

	return 1;
}

SendAdminText(playerid, text[])
{
	if (playerData[playerid][playerLevel] < 7)
	{
		// Setup local variables
		new Name[24], Msg[250];

		// Get the player's name
		GetPlayerName(playerid, Name, sizeof(Name));
		// Send the given text to the admin
		format(Msg, sizeof(Msg), "%s", text);

		alog[5] = alog[4];
		alog[4] = alog[3];
		alog[3] = alog[2];
		alog[2] = alog[1];
		alog[1] = Msg;

		TextDrawSetString(alog1, Msg);
		TextDrawSetString(alog2, alog[2]);
		TextDrawSetString(alog3, alog[3]);
		TextDrawSetString(alog4, alog[4]);
		TextDrawSetString(alog5, alog[5]);

		// Also log all used commands in the server.log file
		format(Msg, 128, "%s used: %s", Name, text);
		print(Msg);
	}
}

public highPing()
{
    for(new i=0; i < MAX_PLAYERS; i++)
    {
		if(playerData[i][playerLoggedIn])
		{
			if (playerData[i][playerLevel] < 1)
			{
				if(!playerData[i][playerPingImmune])
				{
					if(GetPlayerPing(i) > serverInfo[maxPing] && GetPlayerPing(i) != 65535)
					{
						new messageContent[128];
						format(messageContent, sizeof(messageContent), "{FFDC2E}[ANTI-CHEAT] {FFFFFF}%s(%i) has been kicked for high ping [%i/%i]", playerData[i][playerNamee], i, GetPlayerPing(i), serverInfo[maxPing]);
						SendClientMessageToAll(COLOR_WHITE, messageContent);
						KickWithMessage(i, "You have been kicked due to your ping being over the limit.");
					}
				}
			}
		}
	}

    return 1;
}

public reactivateRob(playerid)
{
	if(IsPlayerConnected(playerid))
	{
		if(playerData[playerid][playerLoggedIn])
		{
			playerData[playerid][playerCanRob] = true;
			KillTimer(playerData[playerid][reactivateRobStatus]);
		}
	}
}

public reactivateRape(playerid)
{
	if(IsPlayerConnected(playerid))
	{
		if(playerData[playerid][playerLoggedIn])
		{
			playerData[playerid][playerCanRape] = true;
			KillTimer(playerData[playerid][reactivateRapeStatus]);
		}
	}
}

public GetClosestPlayerToPlayer(playerid)
{
    new Float:dist = 1000.0;
    new targetid = INVALID_PLAYER_ID;
    new Float:x1,Float:y1,Float:z1;
    new Float:x2,Float:y2,Float:z2;
    new Float:tmpdis;
    GetPlayerPos(playerid,x1,y1,z1);
    for(new i=0;i<MAX_PLAYERS;i++)
    {
		if (playerData[i][playerLoggedIn])
		{
			if(i == playerid)
				continue;

			if (playerData[i][playerIsSpectating])
				continue;

			GetPlayerPos(i,x2,y2,z2);
			tmpdis = floatsqroot(floatpower(floatabs(floatsub(x2,x1)),2)+floatpower(floatabs(floatsub(y2,y1)),2)+floatpower(floatabs(floatsub(z2,z1)),2));

			if(tmpdis < dist)
			{
				dist = tmpdis;
				targetid = i;
			}
		}
    }
    return targetid;
}

public playerGiveXP(playerid, amount)
{
	if(IsPlayerConnected(playerid))
	{
		if(playerData[playerid][playerLoggedIn])
		{
			new tdMessage[50], finalAmount;

			if (serverInfo[doubleXP] == 1 || playerData[playerid][playerVIPLevel] >= 2)
			{
			    finalAmount = amount * 2;
			}
			else
			{
				finalAmount = amount;
			}

			new oldXP = playerData[playerid][playerXP];

			format(tdMessage, sizeof(tdMessage), "+ %i XP", finalAmount);

			playerData[playerid][playerXP] = playerData[playerid][playerXP] + finalAmount;
			updateExperienceCounter(playerid);
			PlayerTextDrawSetString(playerid, playerData[playerid][playerAddedXPTD], tdMessage);
			SetTimerEx("hideAddedXP", 2000, false, "i", playerid);

			if (playerData[playerid][playerXP] >= 1000 && oldXP < 1000)
			{
				disableAchieve(playerid);
				PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
				PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
				PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
				PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

				PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "XP Prostitute");
				PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "You earnt 1,000 XP! Well done!");
				PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);

				playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 6000, false, "i", playerid);

				playerGiveXP(playerid, 25);
				playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
				SetPlayerScore(playerid, playerData[playerid][playerScore]);
			}
			else if (playerData[playerid][playerXP] >= 5000 && oldXP < 5000)
			{
				disableAchieve(playerid);
				PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
				PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
				PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
				PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

				PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "XP Hoarder");
				PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "You earnt 5,000 XP! FBI class unlocked!");
				PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);
				savePlayerStats(playerid);

				playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 6000, false, "i", playerid);

				playerGiveXP(playerid, 25);
				playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
				SetPlayerScore(playerid, playerData[playerid][playerScore]);
			}
			else if (playerData[playerid][playerXP] >= 10000 && oldXP < 10000)
			{
				disableAchieve(playerid);
				PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
				PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
				PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
				PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

				PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "XP Boss");
				PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "You earnt 10,000 XP! CIA class unlocked!");
				PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);

				playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 6000, false, "i", playerid);

				playerGiveXP(playerid, 25);
				playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
				SetPlayerScore(playerid, playerData[playerid][playerScore]);
			}
			else if (playerData[playerid][playerXP] >= 20000 && oldXP < 20000)
			{
				disableAchieve(playerid);
				PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
				PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
				PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
				PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

				PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "XP God");
				PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "You earnt 20,000 XP! Army class unlocked!");
				PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);

				playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 6000, false, "i", playerid);

				playerGiveXP(playerid, 25);
				playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
				SetPlayerScore(playerid, playerData[playerid][playerScore]);
			}
		}
	}
}

public hideAddedXP(playerid)
{
	if(IsPlayerConnected(playerid))
	{
		if(playerData[playerid][playerLoggedIn])
		{
			PlayerTextDrawSetString(playerid, playerData[playerid][playerAddedXPTD], " ");
		}
	}
}

public hideHitmarkerTD(playerid)
{
	if(IsPlayerConnected(playerid))
	{
		if(playerData[playerid][playerLoggedIn])
		{
			PlayerTextDrawSetString(playerid, playerData[playerid][playerHitmarkerTD], " ");
		}
	}
}

public Countdown()
{
	new msg[56];
	if(serverInfo[VIPcount] > 0)
	{
		foreach(new i : Player)
		{
			PlayerPlaySound(i, 1057, 0.0, 0.0, 0.0);
		}
		format(msg, sizeof(msg), "~r~%d", serverInfo[VIPcount]);
		GameTextForAll(msg, 1000, 3);
		serverInfo[VIPcount]--;
	}
	else
	{
		KillTimer(serverInfo[countTimer]);
		foreach(new i : Player)
		{
			PlayerPlaySound(i, 1058, 0.0, 0.0, 0.0);
		}
		GameTextForAll("~r~GO!!! ~g~GO!!! ~b~GO!!!", 1000, 3);
	}
	return 1;
}

public updateExperienceCounter(playerid)
{
	if(IsPlayerConnected(playerid))
	{
		if(playerData[playerid][playerLoggedIn])
		{
			new nextXP, Float:xpProgress;
			if (playerData[playerid][playerXP] < 1000)
			{
				nextXP = 1000;
			}
			else if (playerData[playerid][playerXP] < 5000)
			{
				nextXP = 5000;
			}
			else if (playerData[playerid][playerXP] < 10000)
			{
				nextXP = 10000;
			}
			else if (playerData[playerid][playerXP] < 15000)
			{
				nextXP = 15000;
			}
			else if (playerData[playerid][playerXP] < 20000)
			{
				nextXP = 20000;
			}

			new finalExperience[250];
			//format(finalExperience, sizeof(finalExperience), "%08i", playerData[playerid][playerXP]);

			if (playerData[playerid][playerXP] < 20000)
			{
				xpProgress = floatdiv(playerData[playerid][playerXP], nextXP);
				xpProgress = floatmul(xpProgress, 100);
				format(finalExperience, sizeof(finalExperience), "%i / %i XP", playerData[playerid][playerXP], nextXP);
			}
			else
			{
				format(finalExperience, sizeof(finalExperience), "%i XP", playerData[playerid][playerXP]);
			}

			PlayerTextDrawSetString(playerid, playerData[playerid][playerExperience], finalExperience);
			SetProgressBarValue(playerData[playerid][xpBar], xpProgress);
			ShowProgressBarForPlayer(playerid, playerData[playerid][xpBar]);
		}
	}
}

public countMuteTime()
{
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerConnected(i))
        {
			if(playerData[i][playerMuteTime] >= 1)
			{
				playerData[i][playerMuteTime] = playerData[i][playerMuteTime] - 1;

				if(playerData[i][playerMuteTime] == 0)
				{
					SendClientMessage(i, COLOR_WHITE, "{FFDC2E}[UNMUTED] {FFFFFF}You have been unmuted!");
				}
			}
        }
    }
}

public checkNameStatus(playerName[])
{
	for(new i = 0; i < MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i))
		{
			new playerName2[24];
			GetPlayerName(i, playerName2, sizeof(playerName2));
			if(strcmp(playerName2, playerName, true, strlen(playerName)) == 0)
			{
				return i;
			}
		}
	}

	return INVALID_PLAYER_ID;
}

public givePlayerWanted(playerid, amount)
{
	new newWantedLevel;

	if (playerData[playerid][mask])
	{
		newWantedLevel = playerData[playerid][playerWantedLevel] + amount / 2;
	}
	else
	{
		newWantedLevel = playerData[playerid][playerWantedLevel] + amount;
	}

	playerData[playerid][playerWantedLevel] = newWantedLevel;
	SetPlayerWantedLevel(playerid, newWantedLevel);
	newPlayerColour(playerid);
}

public sendMessageAdmins(message)
{
    new messageContent[128];
    format(messageContent, sizeof(messageContent), "%s", message);
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerConnected(i))
        {
            if(playerData[i][playerLoggedIn])
            {
                if(playerData[i][playerLevel] > 0)
                {
                    format(messageContent, sizeof(messageContent), "{FF00FF}[CHEAT ALERT] {FFFFFF}%s", messageContent);
                    SendClientMessage(i, COLOR_WHITE, messageContent);
                }
            }
        }
    }
}

public randomEx(min, max)
{
    new rand = random (max - min) + min;
    return rand;
}

public playerGiveMoney(playerid, amount)
{
	playerData[playerid][playerMoney] = playerData[playerid][playerMoney] + amount;
	GivePlayerMoney(playerid, amount);

	savePlayerStats(playerid);
}

public playerTakeMoney(playerid, amount)
{
	playerData[playerid][playerMoney] = playerData[playerid][playerMoney] - amount;
	GivePlayerMoney(playerid, - amount);

	savePlayerStats(playerid);
}

public playerGiveBankMoney(playerid, amount)
{
	playerData[playerid][playerBank] = playerData[playerid][playerBank] + amount;

	savePlayerStats(playerid);
}

public playerTakeBankMoney(playerid, amount)
{
	playerData[playerid][playerBank] = playerData[playerid][playerBank] - amount;

	savePlayerStats(playerid);
}

public playerSetMoney(playerid, amount)
{
	ResetPlayerMoney(playerid);
	GivePlayerMoney(playerid, amount);
	playerData[playerid][playerMoney] = amount;
	savePlayerStats(playerid);
}

public beginRobbery(playerid)
{
	new message[128];
	for(new i; i < MAX_ROB_CHECKPOINT; i++)
	{
		if(IsPlayerInDynamicCP(playerid, checkpointIndex[i][2]))
		{
			new lastRobbedTime;

			lastRobbedTime = GetTickCount() - checkpointData[i][lastRobbed];

			if(lastRobbedTime > 120000 || checkpointData[i][lastRobbed] == 0)
			{
				if(checkpointData[i][storeStatus] == 1)
				{
					if (playerData[playerid][playerClass] == 0)
					{
						new Float:pX, Float:pY, Float:pZ, Float:vA, intWorld, virWorld;

						playerData[playerid][playerStoreID] = checkpointData[i][storeID];
						playerData[playerid][playerCheckID] = checkpointIndex[i][2];
						playerData[playerid][playerRobTime] = 15;
						checkpointData[i][storeStatus] = 0;

						ClearAnimations(playerid);
           				ApplyAnimation(playerid,"ROB_BANK","CAT_Safe_Rob", 1, 1, 0, 0, 0, 0, 1);
						SetPlayerAttachedObject(playerid, 0, 1550, 1, 0.158482, -0.203833, 0.000000, 167.302505, 79.854949, 342.084838, 1.000000, 1.000000, 1.000000);

						new tdStoreName[100];
						format(tdStoreName, sizeof(tdStoreName), "Robbing: ~w~%s", checkpointData[i][storeName]);
						PlayerTextDrawSetString(playerid, playerData[playerid][robTD][0], tdStoreName);

						PlayerTextDrawShow(playerid, playerData[playerid][robTD][0]);
						PlayerTextDrawShow(playerid, playerData[playerid][robTD][1]);
						PlayerTextDrawShow(playerid, playerData[playerid][robTD][2]);
						PlayerTextDrawShow(playerid, playerData[playerid][robTD][3]);

						GetPlayerPos(playerid, pX, pY, pZ);
						GetPlayerFacingAngle(playerid, vA);

						virWorld = GetPlayerVirtualWorld(playerid);
						intWorld = GetPlayerInterior(playerid);

						playerData[playerid][playerSafeObj] = CreateDynamicObject(1829, pX + (0.55 * floatsin(-vA, degrees)), pY + (0.55 * floatcos(-vA, degrees)), pZ - 0.5, 0, 0, vA, virWorld, intWorld, playerid, 100.0);
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Only civilians can rob this store");
					}
				}
				else
				{
					format(message, sizeof(message), "{B7B7B7}[SERVER] {FFFFFF}%s is currently being robbed", checkpointData[i][storeName]);
					SendClientMessage(playerid, COLOR_WHITE, message);
				}
			}
			else
			{
				format(message, sizeof(message), "{B7B7B7}[SERVER] {FFFFFF}%s has already been robbed, please wait!", checkpointData[i][storeName]);
				SendClientMessage(playerid, COLOR_WHITE, message);
			}
		}
	}
}

public updatePlayerRobbingProgress(playerid, robberyTime)
{
	new timeRemaining = robberyTime;

	if(timeRemaining == 1) PlayerTextDrawSetString(playerid, playerData[playerid][robTD][2], "l");
	else if(timeRemaining == 2) PlayerTextDrawSetString(playerid, playerData[playerid][robTD][2], "ll");
	else if(timeRemaining == 3) PlayerTextDrawSetString(playerid, playerData[playerid][robTD][2], "lll");
	else if(timeRemaining == 4) PlayerTextDrawSetString(playerid, playerData[playerid][robTD][2], "llll");
	else if(timeRemaining == 5) PlayerTextDrawSetString(playerid, playerData[playerid][robTD][2], "lllll");
	else if(timeRemaining == 6) PlayerTextDrawSetString(playerid, playerData[playerid][robTD][2], "llllll");
	else if(timeRemaining == 7) PlayerTextDrawSetString(playerid, playerData[playerid][robTD][2], "lllllll");
	else if(timeRemaining == 8) PlayerTextDrawSetString(playerid, playerData[playerid][robTD][2], "llllllll");
	else if(timeRemaining == 9) PlayerTextDrawSetString(playerid, playerData[playerid][robTD][2], "lllllllll");
	else if(timeRemaining == 10) PlayerTextDrawSetString(playerid, playerData[playerid][robTD][2], "llllllllll");
	else if(timeRemaining == 11) PlayerTextDrawSetString(playerid, playerData[playerid][robTD][2], "lllllllllll");
	else if(timeRemaining == 12) PlayerTextDrawSetString(playerid, playerData[playerid][robTD][2], "llllllllllll");
	else if(timeRemaining == 13) PlayerTextDrawSetString(playerid, playerData[playerid][robTD][2], "lllllllllllll");
	else if(timeRemaining == 14) PlayerTextDrawSetString(playerid, playerData[playerid][robTD][2], "llllllllllllll");
	if(timeRemaining == 0)
	{
		PlayerTextDrawHide(playerid, playerData[playerid][robTD][0]);
		PlayerTextDrawHide(playerid, playerData[playerid][robTD][1]);
		PlayerTextDrawHide(playerid, playerData[playerid][robTD][2]);
		PlayerTextDrawHide(playerid, playerData[playerid][robTD][3]);
	}

}

public cancelRobbery(playerid)
{
	for(new i; i < MAX_ROB_CHECKPOINT; i++)
	{
		if(IsPlayerInDynamicCP(playerid, checkpointIndex[i][2]))
		{
			if(playerData[playerid][playerStoreID] > 0)
			{
				if(playerData[playerid][playerRobTime] > 0)
				{
					playerData[playerid][playerRobTime] = -1;
					checkpointData[i][storeStatus] = 1;
					playerData[playerid][playerStoreID] = -1;
					ClearAnimations(playerid);
					RemovePlayerAttachedObject(playerid, 0);
					DestroyDynamicObject(playerData[playerid][playerSafeObj]);
					updatePlayerRobbingProgress(playerid, 0);
					TextDrawHideForPlayer(playerid, newRob);
					HideProgressBarForPlayer(playerid, playerData[playerid][robbery]);
				}
			}
		}
	}
}

public forceRobberyCancel(playerid)
{
	if(playerData[playerid][playerStoreID] > 0)
	{
		if(playerData[playerid][playerRobTime] > 0)
		{
			if(playerData[playerid][playerCheckID] > 0)
			{
				new msg[128], pStoreID = playerData[playerid][playerStoreID] - 1;

				SendClientMessage(playerid, COLOR_WHITE, msg);
				checkpointData[pStoreID][storeStatus] = 1;
				playerData[playerid][playerRobTime] = -1;
				playerData[playerid][playerCheckID] = -1;
				playerData[playerid][playerStoreID] = -1;
				ClearAnimations(playerid);
				RemovePlayerAttachedObject(playerid, 0);
				DestroyDynamicObject(playerData[playerid][playerSafeObj]);
				updatePlayerRobbingProgress(playerid, 0);
				TextDrawHideForPlayer(playerid, newRob);
			}
		}
	}
}

public newPlayerColour(playerid)
{
	if(playerData[playerid][playerAdminDuty] == false)
	{
		if (playerData[playerid][isInDM])
		{
			SetPlayerColor(playerid, 0xFAAC58FF);
		}
		else
		{
			switch(playerData[playerid][playerClass])
			{
				case 0, 6:
				{
					if(playerData[playerid][playerWantedLevel] == 0)
					{
						if (playerData[playerid][vipColour])
						{
							SetPlayerColor(playerid, 0x58D3F7FF);
						}
						else
						{
							if(playerData[playerid][playerClass] == CLASS_MEDIC)
							{
								// Medic Colour
								SetPlayerColor(playerid, CLASS_MEDIC_COLOUR);
							}
							else
							{
								// White Wanted Level
								SetPlayerColor(playerid, CLASS_CIVILIAN_COLOUR);
							}
						}
					}

					if (playerData[playerid][playerWantedLevel] >= 1)
					{
						// Yellow Wanted Level
						SetPlayerColor(playerid, CLASS_CIVILIAN_YELLOW);
					}

					if(playerData[playerid][playerWantedLevel] >= 6)
					{
						// Orange Wanted Level
						SetPlayerColor(playerid, CLASS_CIVILIAN_ORANGE);
					}

					if(playerData[playerid][playerWantedLevel] >= 25)
					{
						// Red Wanted Level
						SetPlayerColor(playerid, CLASS_CIVILIAN_RED);
					}

					if(playerData[playerid][playerWantedLevel] > 0)
					{
						if (playerData[playerid][playerClass] == CLASS_CIVILIAN)
						{
							new wantedText[200];
							format(wantedText, sizeof(wantedText), "%i Stars", playerData[playerid][playerWantedLevel]);
							PlayerTextDrawSetString(playerid, playerData[playerid][wantedStars], wantedText);
						}
						else
						{
							PlayerTextDrawSetString(playerid, playerData[playerid][wantedStars], " ");
						}
					}
					else
					{
						PlayerTextDrawSetString(playerid, playerData[playerid][wantedStars], " ");
					}
				}
				case 1:
				{
					if (playerData[playerid][vipColour])
					{
						SetPlayerColor(playerid, COLOR_PURPLE);
					}
					else
					{
						SetPlayerColor(playerid, CLASS_POLICE_COLOUR);
					}
				}
				case 2:
				{
					if (playerData[playerid][vipColour])
					{
						SetPlayerColor(playerid, COLOR_PURPLE);
					}
					else
					{
						SetPlayerColor(playerid, CLASS_ARMY_COLOUR);
					}
				}
				case 3:
				{
					if (playerData[playerid][vipColour])
					{
						SetPlayerColor(playerid, COLOR_PURPLE);
					}
					else
					{
						SetPlayerColor(playerid, CLASS_CIA_COLOUR);
					}
				}
				case 4:
				{
					if (playerData[playerid][vipColour])
					{
						SetPlayerColor(playerid, COLOR_PURPLE);
					}
					else
					{
						SetPlayerColor(playerid, CLASS_FBI_COLOUR);
					}
				}
				case 7:
				{
					if (playerData[playerid][vipColour])
					{
						SetPlayerColor(playerid, COLOR_PURPLE);
					}
					else
					{
						SetPlayerColor(playerid, CLASS_SECRETSERVICE_COLOUR);
					}
				}
			}
		}
	}
	else
	{
		SetPlayerColor(playerid, 0x6AEE39FF);
	}
}

public countRobTime()
{
	for(new i = 0; i < MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i))
		{
			if(playerData[i][playerLoggedIn])
			{
				if(playerData[i][playerRobTime] > 0)
				{
					if(playerData[i][playerStoreID] > 0)
					{
						if(IsPlayerInDynamicCP(i, playerData[i][playerCheckID]))
						{
							playerData[i][playerRobTime]--;
							updatePlayerRobbingProgress(i, playerData[i][playerRobTime]);

							if(playerData[i][playerRobTime] == 0)
							{
							    new moneyToGive, message2[328], playerName[24], currentStoreID, robberyBonus;
							    new randomNum = random(4);
							    if (randomNum != 0 || playerData[i][luckyCharm] || playerData[i][playerRobberies] < 5)
							    {
    								currentStoreID = playerData[i][playerStoreID] - 1;

									if (playerData[i][playerBiggerPockets])
									{
										// $500 bonus
										moneyToGive = randomEx(checkpointData[currentStoreID][lowestCash], checkpointData[currentStoreID][highestCash]);
										robberyBonus = (moneyToGive / 2);
									}
									else
									{
										// No bonuses
										moneyToGive = randomEx(checkpointData[currentStoreID][lowestCash], checkpointData[currentStoreID][highestCash]);
									}

    								checkpointData[currentStoreID][lastRobbed] = GetTickCount();
    								checkpointData[currentStoreID][storeStatus] = 1;

    								playerData[i][playerRobTime] = -1;
    								playerData[i][playerRobberies]++;
    								playerGiveMoney(i, moneyToGive);
									playerGiveMoney(i, robberyBonus);
    								GetPlayerName(i, playerName, sizeof(playerName));
    								ClearAnimations(i);
    								RemovePlayerAttachedObject(i, 0);
    								DestroyDynamicObject(playerData[i][playerSafeObj]);

									if (playerData[i][playerBiggerPockets])
									{
										// Has a bonus
										format(message2, sizeof(message2), "{FF0000}[ROBBERY] {FFFFFF}%s(%i) robbed %s and received {FFDC2E}$%s {FFFFFF}({58D3F7}+$%s{FFFFFF})", playerName, i, checkpointData[currentStoreID][storeName], FormatNumber(moneyToGive), FormatNumber(robberyBonus));
									}
									else
									{
										// No bonus
										format(message2, sizeof(message2), "{FF0000}[ROBBERY] {FFFFFF}%s(%i) robbed %s and received {FFDC2E}$%s {FFFFFF}", playerName, i, checkpointData[currentStoreID][storeName], FormatNumber(moneyToGive));
									}

									if (playerData[i][mask])
									{
										SendClientMessage(i, COLOR_WHITE, message2);
									}
									else
									{
										SendClientMessageToAll(COLOR_WHITE, message2);
									}

    								givePlayerWanted(i, 6);
									playerGiveXP(i, 20);
    								sendWantedMessage(i, 6);
									playerData[i][playerScore] = playerData[i][playerScore] + 1;
									SetPlayerScore(i, playerData[i][playerScore]);
									TextDrawHideForPlayer(i, newRob);
									newPlayerColour(i);

									if (playerData[i][playerRobberies] == 1)
									{
										disableAchieve(i);
										PlayerTextDrawShow(i, playerData[i][Achieve1]);
										PlayerTextDrawShow(i, playerData[i][Achieve2]);
										PlayerTextDrawShow(i, playerData[i][Achieve3]);
										PlayerTextDrawShow(i, playerData[i][Achieve4]);

										PlayerTextDrawSetString(i, playerData[i][Achieve3], "Cat Burgler");
										PlayerTextDrawSetString(i, playerData[i][Achieve4], "You robbed your first store!");
										PlayerPlaySound(i, 1183 ,0.0, 0.0, 0.0);

										playerData[i][achieveTimer] = SetTimerEx("disableAchieve", 6000, false, "i", i);

										playerGiveXP(i, 50);
										playerData[i][playerScore] = playerData[i][playerScore] + 2;
										SetPlayerScore(i, playerData[i][playerScore]);
										savePlayerStats(i);
									}
									else if (playerData[i][playerRobberies] == 50)
									{
										disableAchieve(i);
										PlayerTextDrawShow(i, playerData[i][Achieve1]);
										PlayerTextDrawShow(i, playerData[i][Achieve2]);
										PlayerTextDrawShow(i, playerData[i][Achieve3]);
										PlayerTextDrawShow(i, playerData[i][Achieve4]);

										PlayerTextDrawSetString(i, playerData[i][Achieve3], "Established Thief");
										PlayerTextDrawSetString(i, playerData[i][Achieve4], "You robbed 50 stores!");
										PlayerPlaySound(i, 1183 ,0.0, 0.0, 0.0);

										playerData[i][achieveTimer] = SetTimerEx("disableAchieve", 6000, false, "i", i);

										playerGiveXP(i, 50);
										playerData[i][playerScore] = playerData[i][playerScore] + 2;
										SetPlayerScore(i, playerData[i][playerScore]);
										savePlayerStats(i);
									}
									else if (playerData[i][playerRobberies] == 100)
									{
										disableAchieve(i);
										PlayerTextDrawShow(i, playerData[i][Achieve1]);
										PlayerTextDrawShow(i, playerData[i][Achieve2]);
										PlayerTextDrawShow(i, playerData[i][Achieve3]);
										PlayerTextDrawShow(i, playerData[i][Achieve4]);

										PlayerTextDrawSetString(i, playerData[i][Achieve3], "Master Thief");
										PlayerTextDrawSetString(i, playerData[i][Achieve4], "You robbed 100 stores!");
										PlayerPlaySound(i, 1183 ,0.0, 0.0, 0.0);

										playerData[i][achieveTimer] = SetTimerEx("disableAchieve", 6000, false, "i", i);

										playerGiveXP(i, 50);
										playerData[i][playerScore] = playerData[i][playerScore] + 2;
										SetPlayerScore(i, playerData[i][playerScore]);
										savePlayerStats(i);
									}
									else if (playerData[i][playerRobberies] == 200)
									{
										disableAchieve(i);
										PlayerTextDrawShow(i, playerData[i][Achieve1]);
										PlayerTextDrawShow(i, playerData[i][Achieve2]);
										PlayerTextDrawShow(i, playerData[i][Achieve3]);
										PlayerTextDrawShow(i, playerData[i][Achieve4]);

										PlayerTextDrawSetString(i, playerData[i][Achieve3], "The Heist");
										PlayerTextDrawSetString(i, playerData[i][Achieve4], "Lucky Charm unlocked!");
										PlayerPlaySound(i, 1183 ,0.0, 0.0, 0.0);

										playerData[i][achieveTimer] = SetTimerEx("disableAchieve", 6000, false, "i", i);

										playerGiveXP(i, 50);
										playerData[i][playerScore] = playerData[i][playerScore] + 2;
										SetPlayerScore(i, playerData[i][playerScore]);
										savePlayerStats(i);
									}
                                }
                                else
                                {
    								currentStoreID = playerData[i][playerStoreID] - 1;
    								moneyToGive = randomEx(checkpointData[currentStoreID][lowestCash], checkpointData[currentStoreID][highestCash]);

    								checkpointData[currentStoreID][lastRobbed] = GetTickCount();
    								checkpointData[currentStoreID][storeStatus] = 1;

    								playerData[i][playerRobTime] = -1;
    								playerData[i][playerRobberies]++;
    								GetPlayerName(i, playerName, sizeof(playerName));
    								ClearAnimations(i);
    								RemovePlayerAttachedObject(i, 0);
    								DestroyDynamicObject(playerData[i][playerSafeObj]);

    								format(message2, sizeof(message2), "{FF0000}[ROBBERY] {FFFFFF}%s(%i) attempted to rob %s and failed", playerName, i, checkpointData[currentStoreID][storeName]);

    								SendClientMessageToAll(COLOR_WHITE, message2);

    								// Add to player's wanted level
    								givePlayerWanted(i, 6);
    								sendWantedMessage(i, 6);
									TextDrawHideForPlayer(i, newRob);
									newPlayerColour(i);
                                }
							}
						}
						else
						{
							forceRobberyCancel(i);
						}
					}
				}
			}
		}
	}
}

public arrest(playerid)
{
	playerData[playerid][playerCanArrest] = true;
	KillTimer(playerData[playerid][arrestTimer]);
    return 1;
}

public reFix(playerid)
{
	playerData[playerid][playerCanRepair] = true;
	KillTimer(playerData[playerid][fixTimer]);
    return 1;
}

public reFlip(playerid)
{
	playerData[playerid][playerCanFlip] = true;
	KillTimer(playerData[playerid][flipTimer]);
    return 1;
}

public reNOS(playerid)
{
	playerData[playerid][playerCanNOS] = true;
	KillTimer(playerData[playerid][nosTimer]);
    return 1;
}

public reEMP(playerid)
{
	playerData[playerid][playerCanEMP] = true;
	KillTimer(playerData[playerid][reEMPTimer]);
    return 1;
}

public mechReEmp(playerid)
{
	playerData[playerid][playerCanREMP] = true;
	KillTimer(playerData[playerid][mechREMPTimer]);
    return 1;
}

public resetEMP(vehicleID)
{
    new engine, lights, alarm, doors, bonnet, boot, objective;
	GetVehicleParamsEx(vehicleID, engine, lights, alarm, doors, bonnet, boot, objective);
	SetVehicleParamsEx(vehicleID, 1, lights, alarm, doors, bonnet, boot, objective);
	KillTimer(resetEMPTimer[vehicleID]);
    return 1;
}

public untie(playerid)
{
	ClearAnimations(playerid);
	playerData[playerid][playerIsTied] = false;

    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
	KillTimer(playerData[playerid][untieTimer]);
	TogglePlayerControllable(playerid, true);

	for(new i = 0; i < MAX_PLAYERS; i++)
	{
		new message[128], playerName[24];
		if(IsPlayerConnected(i))
		{
			if(playerData[i][playerLoggedIn])
			{
				if(i == playerid)
				{
					SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[ANTI-ABUSE] {FFFFFF}You have been un-tied by the anti-abuse system.");
					Delete3DTextLabel(playerData[playerid][kidnappedLabel]);
				}
				else
				{
					GetPlayerName(playerid, playerName, sizeof(playerName));
					format(message, sizeof(message), "{FFDC2E}[ANTI-ABUSE] {FFFFFF}%s(%i) has been un-tied by the anti-abuse system.", playerName, playerid);
					SendClientMessage(i, COLOR_WHITE, message);
				}
			}
		}
	}

    return 1;
}

public uncuff(playerid)
{
	ClearAnimations(playerid);
	playerData[playerid][playerIsCuffed] = false;
	TogglePlayerControllable(playerid, 1);

    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);

	KillTimer(playerData[playerid][uncuffTimer]);

	for(new i = 0; i < MAX_PLAYERS; i++)
	{
		new message[128], playerName[24];
		if(IsPlayerConnected(i))
		{
			if(playerData[i][playerLoggedIn])
			{
				if(i == playerid)
				{
					SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[ANTI-ABUSE] {FFFFFF}You have been uncuffed by the anti-abuse system.");
				}
				else
				{
					GetPlayerName(playerid, playerName, sizeof(playerName));
					format(message, sizeof(message), "{FFDC2E}[ANTI-ABUSE] {FFFFFF}%s(%i) has been uncuffed by the anti-abuse system.", playerName, playerid);
					SendClientMessage(i, COLOR_WHITE, message);
				}
			}
		}
	}

    return 1;
}

public rebreakcuffs(playerid)
{
	playerData[playerid][canBreakCuffs] = true;
	KillTimer(playerData[playerid][breakCuffsTimer]);
    return 1;
}

public recuff(playerid)
{
	playerData[playerid][playerCanCuff] = true;
	KillTimer(playerData[playerid][recuffTimer]);
    return 1;
}

public Unfreeze(playerid)
{
	ClearAnimations(playerid);
    TogglePlayerControllable(playerid, 1);
	playerData[playerid][playerIsTazed] = false;
	KillTimer(playerData[playerid][unfreezeTimer]);
    return 1;
}

public Retaze(playerid)
{
	playerData[playerid][playerCanTaze] = true;
	KillTimer(playerData[playerid][retazeTimer]);
    return 1;
}

public pHouseCP(playerid)
{
	playerData[playerid][pEnterHouse] = true;
	KillTimer(playerData[playerid][hcpTimer]);
    return 1;
}

public isPlayerInRangeOfPlayer(playerid, otherid, Float:cRadius)
{
    new Float:cX, Float:cY, Float:cZ;

    GetPlayerPos(otherid, cX, cY, cZ);

    if(IsPlayerInRangeOfPoint(playerid, cRadius, cX, cY, cZ))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

public clearWorldObjects(playerid)
{
	RemoveBuildingForPlayer(playerid, 1411, -1656.14331, -10.63583, 5.05489, 5.38907289505);
	RemoveBuildingForPlayer(playerid, 1411, -1662.51416, -4.41222, 5.21241, 5.38907289505);
	RemoveBuildingForPlayer(playerid, 1411, -1668.75586, 1.87025, 5.1631, 5.38907289505);
	RemoveBuildingForPlayer(playerid, 967, -1674.96094, 5.55469, 2.51563, 4.1212320327759);
	RemoveBuildingForPlayer(playerid, 966, -1676.25781, 4.65625, 2.51563, 6.0111284255981);
	RemoveBuildingForPlayer(playerid, 968, -1676.22656, 4.625, 3.24219, 5.5763330459595);
	RemoveBuildingForPlayer(playerid, 1411, -1676.03296, 9.0714, 5.25612, 5.38907289505);
	RemoveBuildingForPlayer(playerid, 1278, -1706.11719, 33.16406, 16.61719, 16.251438140869);
	RemoveBuildingForPlayer(playerid, 10831, -1706.47656, 13.01563, 7.40625, 30.153728485107);
	RemoveBuildingForPlayer(playerid, 10840, -1666.1250, -62.0781, 10.9453, 0.25);
	RemoveBuildingForPlayer(playerid, 10912, -1666.1250, -62.0781, 10.9453, 0.25);
	RemoveBuildingForPlayer(playerid, 10914, -1706.4766, 13.0156, 7.4063, 0.25);
	RemoveBuildingForPlayer(playerid, 10831, -1706.4766, 13.0156, 7.4063, 0.25);

	// 1.2.1
	RemoveBuildingForPlayer(playerid, 9900, -1753.7109, 884.3906, 159.9766, 0.25);
	RemoveBuildingForPlayer(playerid, 9933, -1753.6250, 884.4531, 179.2656, 0.25);
	RemoveBuildingForPlayer(playerid, 9936, -1753.7109, 884.3906, 159.9766, 0.25);
	RemoveBuildingForPlayer(playerid, 10165, -1753.7813, 884.3906, 35.1172, 0.25);
	RemoveBuildingForPlayer(playerid, 10235, -1753.7813, 884.3906, 35.1172, 0.25);
	RemoveBuildingForPlayer(playerid, 10260, -1753.7422, 884.3984, 25.3438, 0.25);
	RemoveBuildingForPlayer(playerid, 1496, -1618.6016, 680.9141, 6.1719, 0.25);

	RemoveBuildingForPlayer(playerid, 3924, -1086.0938, 1061.1875, 1360.5703, 0.25);
	RemoveBuildingForPlayer(playerid, 3932, -1131.9453, 1029.1406, 1346.4063, 0.25);
	RemoveBuildingForPlayer(playerid, 3936, -974.5547, 1059.4609, 1344.7734, 0.25);
	RemoveBuildingForPlayer(playerid, 3937, -1130.9219, 1059.4609, 1345.4688, 0.25);
	RemoveBuildingForPlayer(playerid, 3939, -975.0469, 1089.6563, 1345.6563, 0.25);
	RemoveBuildingForPlayer(playerid, 3958, -1142.0078, 1001.9141, 1348.4219, 0.25);
	RemoveBuildingForPlayer(playerid, 3959, -1061.8906, 1057.3125, 1369.3359, 0.25);
	RemoveBuildingForPlayer(playerid, 1596, -1132.6953, 1073.9922, 1354.7500, 0.25);
	RemoveBuildingForPlayer(playerid, 1596, -973.5625, 1046.0703, 1353.9688, 0.25);

	// Fire station
	RemoveBuildingForPlayer(playerid, 11245, -2023.7109, 83.9688, 37.8750, 0.25);
	RemoveBuildingForPlayer(playerid, 11272, -2037.5391, 79.9297, 34.1094, 0.25);
	RemoveBuildingForPlayer(playerid, 11008, -2037.5391, 79.9297, 34.1094, 0.25);

	//Custom Mappings
    RemoveBuildingForPlayer(playerid, 3339, 1297.2813, 173.5781, 19.4609, 0.25);
	RemoveBuildingForPlayer(playerid, 3340, 1308.3984, 168.1406, 19.4063, 0.25);
	RemoveBuildingForPlayer(playerid, 3341, 1281.2266, 158.0938, 19.3438, 0.25);
	RemoveBuildingForPlayer(playerid, 3343, 1295.9844, 158.7422, 19.3828, 0.25);
	RemoveBuildingForPlayer(playerid, 3343, 1305.0391, 184.9141, 19.3438, 0.25);
	RemoveBuildingForPlayer(playerid, 3345, 1298.6094, 194.2656, 19.3281, 0.25);
	RemoveBuildingForPlayer(playerid, 3345, 1305.2656, 152.7734, 19.2969, 0.25);
	RemoveBuildingForPlayer(playerid, 3344, 1299.7109, 138.7344, 19.3438, 0.25);
	RemoveBuildingForPlayer(playerid, 3344, 1313.9688, 179.8438, 19.3594, 0.25);
	RemoveBuildingForPlayer(playerid, 3594, 1265.5703, 153.3828, 19.4609, 0.25);
	RemoveBuildingForPlayer(playerid, 769, 1267.9141, 146.8203, 19.1953, 0.25);
	RemoveBuildingForPlayer(playerid, 3170, 1281.2266, 158.0938, 19.3438, 0.25);
	RemoveBuildingForPlayer(playerid, 3594, 1280.9297, 147.3125, 20.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 3168, 1295.9844, 158.7422, 19.3828, 0.25);
	RemoveBuildingForPlayer(playerid, 3171, 1299.7109, 138.7344, 19.3438, 0.25);
	RemoveBuildingForPlayer(playerid, 3172, 1305.2656, 152.7734, 19.2969, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1301.2578, 147.3828, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 780, 1301.5938, 154.5078, 19.3281, 0.25);
	RemoveBuildingForPlayer(playerid, 3594, 1271.3125, 163.3906, 19.4375, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1264.5469, 172.2188, 23.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1281.5156, 165.5313, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1440, 1297.0703, 179.2266, 19.9453, 0.25);
	RemoveBuildingForPlayer(playerid, 1440, 1293.5547, 163.8828, 19.9453, 0.25);
	RemoveBuildingForPlayer(playerid, 3168, 1305.0391, 184.9141, 19.3438, 0.25);
	RemoveBuildingForPlayer(playerid, 3169, 1297.2813, 173.5781, 19.4609, 0.25);
	RemoveBuildingForPlayer(playerid, 775, 1301.2734, 164.2656, 19.3516, 0.25);
	RemoveBuildingForPlayer(playerid, 764, 1303.6328, 173.3984, 18.9375, 0.25);
	RemoveBuildingForPlayer(playerid, 3171, 1313.9688, 179.8438, 19.3594, 0.25);
	RemoveBuildingForPlayer(playerid, 3167, 1308.3984, 168.1406, 19.4063, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1308.2656, 174.2891, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1440, 1313.3203, 167.0313, 19.9453, 0.25);
	RemoveBuildingForPlayer(playerid, 3172, 1298.6094, 194.2656, 19.3281, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1274.1875, 191.4609, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1438, 1276.1172, 190.2266, 18.6094, 0.25);
	RemoveBuildingForPlayer(playerid, 617, 1324.7266, 187.3516, 17.7813, 0.25);
	RemoveBuildingForPlayer(playerid, 1440, 1318.3828, 196.0547, 19.6094, 0.25);
	RemoveBuildingForPlayer(playerid, 705, 1290.4766, 198.6797, 18.7656, 0.25);
	RemoveBuildingForPlayer(playerid, 13441, 1338.0625, 198.7344, 30.0234, 0.25);

	// Sweeper
	RemoveBuildingForPlayer(playerid, 1283, -2007.8828, 945.3906, 47.5234, 0.25);
	RemoveBuildingForPlayer(playerid, 1283, -2000.7578, 903.7891, 47.5234, 0.25);
	RemoveBuildingForPlayer(playerid, 1284, -1990.9922, 931.7031, 47.6094, 0.25);
	RemoveBuildingForPlayer(playerid, 1232, -1552.7578, 1231.6094, 8.8047, 0.25);

	// Jail
	RemoveBuildingForPlayer(playerid, 1771, 216.6484, 108.4219, 998.6719, 0.25);
	RemoveBuildingForPlayer(playerid, 1771, 220.5703, 108.4219, 998.6719, 0.25);
	RemoveBuildingForPlayer(playerid, 1771, 224.5625, 108.4219, 998.6719, 0.25);
	RemoveBuildingForPlayer(playerid, 2165, 223.0703, 120.0625, 998.0156, 0.25);
	RemoveBuildingForPlayer(playerid, 2165, 223.0703, 122.0469, 998.0156, 0.25);
	RemoveBuildingForPlayer(playerid, 1806, 223.3984, 120.4219, 998.0000, 0.25);
	RemoveBuildingForPlayer(playerid, 2356, 224.2031, 121.7266, 997.9922, 0.25);
	RemoveBuildingForPlayer(playerid, 1771, 228.7031, 108.4219, 998.6719, 0.25);
	RemoveBuildingForPlayer(playerid, 1806, 226.7500, 119.2578, 998.0000, 0.25);
	RemoveBuildingForPlayer(playerid, 2165, 227.1094, 118.9297, 998.0156, 0.25);
	RemoveBuildingForPlayer(playerid, 14895, 234.7031, 122.0625, 1004.3203, 0.25);
}

public addWorldObjects()
{
	// Car Spawn Points
	/*
	CreateObject(1216, -1754.24011, 957.25983, 24.54695,   0.00000, 0.00000, -0.48000); // d
	CreateObject(1216, -1493.71191, 907.27802, 6.75172,   0.00000, 0.00000, -90.59999); // d
	CreateObject(1216, -1998.18066, 119.40524, 27.31461,   0.00000, 0.00000, 0.00000); // d
	CreateObject(1216, -1551.81201, 1183.52417, 6.83623,   0.00000, 0.00000, -88.14010); // d
	CreateObject(1216, -1772.55579, 1083.62207, 45.07680,   0.00000, 0.00000, 178.31992); // d
	CreateObject(1216, -2515.02759, -16.88707, 25.19635,   0.00000, 0.00000, 30.60000); // d
	CreateObject(1216, -2016.23254, 901.00342, 45.13615,   0.00000, 0.00000, 90.06001); // d
	CreateObject(1216, -1600.57239, 729.24384, -5.29116,   0.00000, 0.00000, 177.90007); // d
	CreateObject(1216, -1977.40125, 239.38686, 34.82018,   0.00000, 0.00000, 180.65994); // d*/


	// Extras for Hotel
	CreateObject(983, -1764.73621, 945.00238, 24.58348,   0.00000, 0.00000, 90.35999);
	CreateObject(983, -1758.29346, 945.01251, 24.58348,   0.00000, 0.00000, 90.35999);
	CreateObject(983, -1751.85120, 945.00293, 24.58348,   0.00000, 0.00000, 90.35999);
	CreateObject(983, -1745.43066, 945.00909, 24.58348,   0.00000, 0.00000, 90.35999);

	// DM Event
	CreateObject(974, 1420.12732, 3.91563, 1002.60620,   0.00000, 0.00000, -89.63999);
	CreateObject(974, 1417.88525, 8.06394, 1007.80536,   0.00000, 0.00000, -2.33998);
	CreateObject(987, 1358.55530, -3.70630, 999.91003,   0.00000, 0.00000, -0.18000);
	CreateObject(987, 1370.47339, -3.69328, 999.91003,   0.00000, 0.00000, -0.18000);
	CreateObject(987, 1382.44592, -3.69561, 999.91003,   0.00000, 0.00000, -0.18000);
	CreateObject(987, 1394.33105, -3.79411, 999.91003,   0.00000, 0.00000, -0.18000);
	CreateObject(987, 1408.13281, -3.93247, 999.91003,   0.00000, 0.00000, -0.18000);
	CreateObject(3577, 1370.41125, -36.27421, 1000.66425,   0.00000, 0.00000, 32.57999);
	CreateObject(2935, 1367.51648, -12.74950, 1001.38940,   0.00000, 0.00000, -19.02000);
	CreateObject(2935, 1367.16479, -22.07234, 1001.38940,   0.00000, 0.00000, 15.00000);
	CreateObject(2935, 1366.19897, -17.32412, 1004.23248,   0.00000, 0.00000, 1.02000);
	CreateObject(2932, 1410.40845, -28.02611, 1001.38281,   0.00000, 0.00000, -26.10000);
	CreateObject(2932, 1411.01514, -21.86369, 1001.38281,   0.00000, 0.00000, 56.93999);
	CreateObject(2932, 1363.99768, -42.70890, 1001.38281,   0.00000, 0.00000, -125.10001);
	CreateObject(18260, 1389.77393, -21.32626, 1001.42792,   0.00000, 0.00000, 0.00000);
	CreateObject(18260, 1393.37720, -15.09205, 1001.42792,   0.00000, 0.00000, 93.96000);
	CreateObject(18260, 1390.32092, -13.69360, 1001.42792,   0.00000, 0.00000, 191.69994);

	// DM Event Gate Closed
	DMGate = CreateObject(19302, 1407.14392, -3.92782, 1001.14203,   0.00000, 0.00000, 0.00000);
	//CreateObject(19302, 1405.93884, -3.15653, 1001.14203,   0.00000, 0.00000, 108.05999); - OPEN

	// Jail
	CreateObject(2930, 224.56384, 116.61489, 1000.74719,   0.00000, 0.00000, 90.71999);
	CreateObject(2930, 223.01932, 116.59758, 1000.74719,   0.00000, 0.00000, 90.71999);
	CreateObject(2930, 221.39159, 116.61296, 1000.74719,   0.00000, 0.00000, 90.71999);
	CreateObject(2930, 219.96480, 116.59406, 1000.74719,   0.00000, 0.00000, 90.71999);
	CreateObject(3036, 219.92622, 117.58105, 999.39130,   0.00000, 0.00000, 90.00004);
	CreateObject(19302, 216.39316, 117.38087, 999.25421,   0.00000, 0.00000, 123.48003);
	CreateObject(2588, 213.69853, 109.09761, 999.71503,   0.00000, 0.00000, 87.23993);
	CreateObject(2587, 213.68849, 110.34654, 1000.10175,   0.00000, 0.00000, 91.37996);
	CreateObject(2816, 224.58386, 107.61146, 998.01508,   0.00000, 0.00000, 0.00000);
	CreateObject(2716, 219.50577, 107.06760, 1000.24072,   0.00000, 0.00000, 0.00000);
	CreateObject(2587, 229.35185, 110.03686, 999.92389,   0.00000, 0.00000, -89.51999);
	CreateObject(2855, 228.86404, 107.58269, 998.01495,   0.00000, 0.00000, 0.00000);
	CreateObject(1647, 220.82088, 108.46875, 998.17493,   0.00000, 0.00000, 0.00000);
	CreateObject(1647, 222.21758, 108.25808, 998.17493,   0.00000, 0.00000, 0.00000);
	CreateObject(1647, 216.97357, 108.39111, 998.17493,   0.00000, 0.00000, 0.00000);
	CreateObject(1647, 226.12830, 108.32042, 998.17493,   0.00000, 0.00000, 0.00000);
	CreateObject(1647, 226.39137, 124.30331, 998.18237,   0.00000, 0.00000, 91.38004);
	CreateObject(1647, 226.40892, 121.88379, 998.18237,   0.00000, 0.00000, 91.38004);
	CreateObject(1647, 226.39352, 119.47002, 998.18237,   0.00000, 0.00000, 91.38004);
	CreateObject(14604, 220.81860, 124.10445, 998.98724,   0.00000, 0.00000, -123.90001);
	CreateObject(2582, 220.37807, 118.33850, 998.88843,   0.00000, 0.00000, 91.91994);
	CreateObject(321, 226.55919, 108.76790, 997.96417,   28.80000, -66.18002, -364.14005);
	CreateObject(1569, 233.10779, 119.22845, 1002.21490,   0.00000, 0.00000, 0.00000);
	CreateObject(1569, 236.81975, 119.26270, 1002.21490,   0.00000, 0.00000, 0.00000);

	// New Spawn
	CreateObject(983, -1553.18311, 1176.58264, 6.86165,   0.00000, 0.00000, 89.22002);
	CreateObject(983, -1553.22656, 1160.84521, 6.86165,   0.00000, 0.00000, 89.22002);
	CreateObject(983, -1556.32678, 1173.48108, 6.86165,   0.00000, 0.00000, 0.78001);
	CreateObject(983, -1556.43103, 1164.09363, 6.86165,   0.00000, 0.00000, 0.78001);
	CreateObject(1280, -1556.78528, 1173.70593, 6.49590,   0.00000, 0.00000, 1.32000);
	CreateObject(1280, -1556.83826, 1163.93359, 6.49590,   0.00000, 0.00000, 1.32000);
	CreateObject(6965, -1561.75574, 1211.30042, 9.80104,   0.00000, 0.00000, 0.00000);
	CreateObject(1280, -1561.53198, 1200.88269, 6.49590,   0.00000, 0.00000, 88.91995);
	CreateObject(1280, -1571.90430, 1209.03662, 6.49590,   0.00000, 0.00000, 13.97994);
	CreateObject(14400, -1583.55872, 1232.11169, 6.85934,   0.00000, 0.00000, 0.00000);
	CreateObject(14400, -1578.57056, 1231.79761, 6.85934,   0.00000, 0.00000, 0.00000);
	CreateObject(14400, -1574.22864, 1231.68896, 6.85934,   0.00000, 0.00000, 0.00000);
	CreateObject(14400, -1569.19751, 1232.01758, 6.85934,   0.00000, 0.00000, 0.00000);
	CreateObject(14400, -1563.83325, 1231.60095, 6.85934,   0.00000, 0.00000, 0.00000);
	CreateObject(14400, -1559.42847, 1231.82874, 6.85934,   0.00000, 0.00000, 0.00000);
	CreateObject(14400, -1553.48071, 1232.35693, 6.85934,   0.00000, 0.00000, 0.00000);

	// Sweeper
	CreateObject(983, -1991.66077, 955.08270, 45.11189,   0.00000, 0.00000, 0.00000);
	CreateObject(983, -1991.67676, 948.67700, 45.11189,   0.00000, 0.00000, 0.00000);
	CreateObject(1331, -1977.88867, 953.69049, 45.30152,   0.00000, 0.00000, -91.79997);
	CreateObject(1331, -1978.00684, 950.31219, 45.30152,   0.00000, 0.00000, -91.79997);

	// New "Car Park"
	CreateObject(4639, -2020.67773, 97.02160, 28.64478,   0.00000, 0.00000, 0.00000);
	CreateObject(8406, -2067.61157, 72.35013, 32.48693,   0.00000, 0.00000, 87.41998);
	CreateObject(703, -2068.73267, 51.03067, 26.30458,   0.00000, 0.00000, 35.70000);
	CreateObject(708, -2073.47168, 95.74867, 27.36075,   0.00000, 0.00000, 0.00000);

	// 1.2.1
	CreateObject(1256,-1963.7000000,1343.2000000,6.8000000,0.0000000,0.0000000,90.0000000); //object(stonebench1) (1)
	CreateObject(1256,-1944.7000000,1343.2000000,6.8000000,0.0000000,0.0000000,90.0000000); //object(stonebench1) (2)
	CreateObject(8210,-1560.6000000,287.9000000,9.3000000,0.0000000,0.0000000,269.5000000); //object(vgsselecfence12) (1)
	CreateObject(7522,-1635.3000000,334.5000000,10.7000000,0.0000000,0.0000000,0.0000000); //object(vgnhsegate1) (1)
	CreateObject(987,-1660.2000000,328.3000000,6.2000000,0.0000000,0.0000000,136.0000000); //object(elecfence_bar) (3)
	CreateObject(987,-1622.3000000,327.7000000,6.2000000,0.0000000,0.0000000,0.0000000); //object(elecfence_bar) (4)
	CreateObject(987,-1648.3000000,328.1000000,6.2000000,0.0000000,0.0000000,179.4950000); //object(elecfence_bar) (5)
	CreateObject(987,-1598.4000000,328.1000000,6.2000000,0.0000000,0.0000000,182.7500000); //object(elecfence_bar) (6)
	CreateObject(968,-1632.5000000,327.8000000,6.2000000,0.0000000,0.0000000,0.0000000); //object(barrierturn) (1)
	CreateObject(968,-1646.0000000,327.9004000,6.2000000,0.0000000,0.0000000,0.0000000); //object(barrierturn) (2)
	CreateObject(3109,-1607.1000000,317.0000000,7.4000000,0.0000000,0.0000000,271.0000000); //object(imy_la_door) (1)
	CreateObject(3109,-1562.2000000,328.6000000,22.8000000,0.0000000,0.0000000,0.0000000); //object(imy_la_door) (3)
	CreateObject(3263,-1869.5000000,1424.2000000,6.3000000,0.0000000,0.0000000,44.0000000); //object(privatesign2) (1)
	CreateObject(1280,-1979.8000000,1041.8000000,55.1000000,0.0000000,0.0000000,270.0000000); //object(parkbench1) (1)
	CreateObject(1280,-1983.6000000,1041.8000000,55.1000000,0.0000000,0.0000000,270.0000000); //object(parkbench1) (2)
	CreateObject(7037,-1755.1000000,1075.5000000,49.7000000,0.0000000,0.0000000,270.0000000); //object(vgnwalburger1) (1)
	CreateObject(1594,-1745.9000000,1087.1000000,44.9000000,0.0000000,0.0000000,0.0000000); //object(chairsntable) (4)
	CreateObject(1594,-1750.3000000,1087.1000000,44.9000000,0.0000000,0.0000000,0.0000000); //object(chairsntable) (5)
	CreateObject(1594,-1755.0000000,1087.1000000,44.9000000,0.0000000,0.0000000,0.0000000); //object(chairsntable) (6)
	CreateObject(2754,-1764.6999500,1084.0000000,45.3000000,0.0000000,0.0000000,270.0000000); //object(otb_machine) (1)
	CreateObject(2735,-1735.9000000,1083.3000000,47.1000000,0.0000000,0.0000000,180.0000000); //object(cj_zip_post_4) (1)
	CreateObject(2733,-1735.9000000,1083.3000000,48.9000000,0.0000000,0.0000000,180.0000000); //object(cj_zip_post_1) (1)
	CreateObject(3578,-1623.1000000,334.5000000,7.0000000,0.0000000,0.0000000,270.0000000); //object(dockbarr1_la) (1)
	CreateObject(3578,-1647.4000000,334.5000000,7.0000000,0.0000000,0.0000000,270.0000000); //object(dockbarr1_la) (2)
	CreateObject(1569,-1667.9000000,1202.1000000,6.3000000,0.0000000,0.0000000,0.0000000); //object(adam_v_door) (1)
	CreateObject(2001,-1666.1000000,1202.6000000,6.3000000,0.0000000,0.0000000,0.0000000); //object(nu_plant_ofc) (1)

	// Ammunation
	CreateObject(10631, -1981.17065, 884.16187, 48.64270,   0.00000, 0.00000, 89.99982);
	CreateObject(3029, -1990.18420, 885.66058, 44.28278,   0.00000, 0.00000, 181.26007);
	CreateObject(1368, -1992.32764, 897.21362, 45.11667,   0.00000, 0.00000, -89.33998);
	CreateObject(1368, -1992.27917, 891.54681, 45.11667,   0.00000, 0.00000, -89.33998);
	CreateObject(2641, -1989.70874, 887.25305, 45.52656,   0.00000, 0.00000, -89.76000);
	CreateObject(11245, -1029.99158, 1063.85510, 1344.59241,   1.13998, -77.09993, 47.46001);
	CreateObject(2935, -1000.44318, 1040.65662, 1342.67822,   0.00000, 0.00000, 41.64000);
	CreateObject(3577, -1078.24036, 1075.39648, 1341.47546,   1.32000, -1.67997, 0.00000);
	CreateObject(3043, -1071.60852, 1057.09814, 1344.47852,   -2.34000, -3.48000, 0.00000);
	CreateObject(4724, -1079.67383, 1027.19653, 1344.19153,   0.00000, 0.00000, 1.86001);
	CreateObject(19398, -996.09991, 1086.99548, 1342.60583,   0.00000, 0.00000, 0.00000);
	CreateObject(19371, -995.00531, 1089.71106, 1342.58984,   0.00000, 0.00000, 135.72002);
	CreateObject(19371, -994.89148, 1084.41858, 1342.58984,   0.00000, 0.00000, 230.76003);
	CreateObject(2048, -995.01208, 1084.38049, 1343.45630,   0.00000, 0.00000, -39.72000);


	// Sex Shop
	CreateObject(1498, -1671.42822, 902.62646, 23.82669,   0.00000, 0.00000, 0.00000);
	CreateObject(2580, -1672.32434, 902.79974, 25.58323,   0.00000, 0.00000, 179.87997);
	CreateObject(14672, 1157.20154, -3919.53809, 18.18112,   0.00000, 0.00000, 0.00000);
	CreateObject(1498, 1164.01587, -3928.70801, 16.17027,   0.00000, 0.00000, 0.00000);
	CreateObject(2599, -1669.39307, 903.42358, 24.31651,   0.00000, 0.00000, 0.00000);
	CreateObject(2714, -1670.63806, 902.76349, 26.73600,   0.00000, 0.00000, -178.13998);
	CreateObject(7305, -1726.65271, 675.91815, 37.20449,   0.00000, 0.00000, 136.02007);
	CreateObject(971, -1642.60535, 688.45624, 9.46652,   0.00000, 0.00000, -179.40005);
	CreateObject(971, -1618.48511, 688.36389, 9.46652,   0.00000, 0.00000, 1.25997);
	CreateObject(2604, -1593.43958, 708.27991, -5.42587,   0.00000, 0.00000, 92.52001);
	CreateObject(2611, -1594.01782, 707.65314, -3.97016,   0.00000, 0.00000, 90.00003);
	CreateObject(1569, -1618.64221, 680.93909, 6.12940,   0.00000, 0.00000, 89.63999);

	// Bus Stops
	CreateObject(1257, -1723.54846, 765.10748, 25.19175,   0.00000, 0.00000, -180.72009);
	CreateObject(1229, -1722.74658, 768.33453, 25.46908,   0.00000, 0.00000, 83.27997);
	CreateObject(1257, -1704.93713, 815.55725, 25.19313,   0.00000, 0.00000, 0.00000);
	CreateObject(1229, -1705.50049, 812.56970, 25.29590,   0.00000, 0.00000, -97.44000);
	CreateObject(1257, -1974.17163, 740.63861, 45.68918,   0.00000, 0.00000, 89.87997);
	CreateObject(1229, -1971.11328, 739.78052, 45.89279,   0.00000, 0.00000, 0.00000);
	CreateObject(1257, -1929.37366, 721.80133, 45.68676,   0.00000, 0.00000, -90.18005);
	CreateObject(1229, -1932.32813, 722.56000, 45.91112,   0.00000, 0.00000, 179.40018);
	CreateObject(1257, -2132.32275, 843.50446, 69.71516,   0.00000, 0.00000, 0.00000);
	CreateObject(1229, -2132.88354, 840.67554, 69.92036,   0.00000, 0.00000, -91.31995);
	CreateObject(1257, -2153.60718, 959.90515, 80.29284,   0.00000, 0.00000, -178.55991);
	CreateObject(1229, -2153.49536, 963.02911, 80.30704,   0.00000, 0.00000, 91.38001);
	CreateObject(1257, -2230.02124, 1099.92761, 80.22085,   0.00000, 0.00000, 90.11996);
	CreateObject(1229, -2226.94360, 1099.38904, 80.32484,   0.00000, 0.00000, 0.00000);
	CreateObject(1257, -2197.26758, 1086.60071, 80.18259,   0.00000, 0.00000, -88.07997);
	CreateObject(1229, -2200.19604, 1087.27783, 80.30644,   0.00000, 0.00000, 185.15994);
	CreateObject(1257, -2018.34424, 1166.45056, 45.69162,   0.00000, 0.00000, -89.57999);
	CreateObject(1229, -2021.40125, 1166.82751, 45.88551,   0.00000, 0.00000, 192.95990);
	CreateObject(1257, -2042.80652, 1187.84863, 45.66860,   0.00000, 0.00000, 89.76000);
	CreateObject(1229, -2039.63525, 1187.23486, 45.75120,   0.00000, 0.00000, 0.00000);
	CreateObject(1257, -1902.86768, 977.39917, 35.42737,   0.00000, 0.00000, 170.99998);
	CreateObject(1229, -1902.97998, 980.42627, 35.49848,   0.00000, 0.00000, 89.57996);
	CreateObject(1257, -1886.80017, 964.69214, 35.33593,   0.00000, 0.00000, -7.74000);
	CreateObject(1229, -1887.42871, 961.66235, 35.49875,   0.00000, 0.00000, -101.69998);

	// Fences
	CreateObject(1653, -1518.79492, 536.31647, 6.83761,   0.60000, -0.12000, -90.24003);
	CreateObject(1653, -1518.87610, 523.50671, 6.83761,   0.60000, -0.12000, -90.24003);
	CreateObject(1653, -1518.89160, 510.66281, 6.83761,   0.60000, -0.12000, -90.24003);
	CreateObject(1653, -1518.93323, 497.75497, 6.83761,   0.60000, -0.12000, -90.24003);
	CreateObject(1653, -1518.74475, 549.10974, 6.83761,   0.60000, -0.12000, -90.24003);
	CreateObject(1653, -1518.74365, 560.32086, 6.83761,   0.60000, -0.12000, -88.98007);
	CreateObject(1653, -1522.18628, 572.16595, 6.83761,   0.60000, -0.12000, -58.20001);
	CreateObject(1653, -1527.30115, 580.32391, 6.83761,   0.60000, -0.12000, -57.84003);

	// Building Removal
	CreateObject(17038, -1745.83142, 881.76532, 24.05454,   0.00000, 0.00000, 0.00000);
	CreateObject(1368, -1750.33594, 880.03473, 24.75560,   0.66000, -0.42000, -91.08004);
	CreateObject(1368, -1750.33826, 884.29468, 24.75560,   0.66000, -0.42000, -91.08004);
	CreateObject(1368, -1750.17761, 893.16870, 24.75560,   0.66000, -0.42000, -91.08004);
	CreateObject(1368, -1750.25769, 888.74286, 24.75560,   0.66000, -0.42000, -91.08004);

	// Bank Vault
	bankVault = CreateObject(2634, 304.4234, 1787.3000, 513.0000, 0.000000, 0.000000, 90.000000);
	bankGate = CreateObject(971, 284.2000, 1787.2654, 512.3663, 0.000000, 0.000000, 90.000000);

	// Forklift
	CreateObject(18257,-1713.6999500,101.4000000,2.6000000,0.0000000,0.0000000,224.0000000); //object(crates) (1)
	CreateObject(2935,-1703.0000000,107.8000000,4.0000000,0.0000000,0.0000000,0.0000000); //object(kmb_container_yel) (1)
	CreateObject(1271,-1710.5000000,98.8000000,2.9000000,0.0000000,0.0000000,0.0000000); //object(gunbox) (1)
	CreateObject(1271,-1709.9000200,101.7000000,2.9000000,0.0000000,0.0000000,280.0000000); //object(gunbox) (2)
	CreateObject(1271,-1709.8000500,100.2000000,2.9000000,0.0000000,0.0000000,26.0000000); //object(gunbox) (3)
	CreateObject(2932,-1714.1999500,65.1000000,4.0000000,0.0000000,0.0000000,300.0000000); //object(kmb_container_blue) (1)
	CreateObject(2478,-1706.4000200,105.0000000,2.8000000,0.0000000,0.0000000,0.0000000); //object(model_box6) (1)
	CreateObject(3576,-1690.9000200,100.7000000,4.0000000,0.0000000,0.0000000,348.0000000); //object(dockcrates2_la) (1)
	CreateObject(2935,-1685.0000000,97.5000000,4.0000000,0.0000000,0.0000000,50.0000000); //object(kmb_container_yel) (2)
	CreateObject(8886,-1723.0999800,70.7000000,6.0000000,0.0000000,0.0000000,44.0000000); //object(vgsefrght04) (1)
	CreateObject(3633,-1731.0999800,81.6000000,3.0000000,0.0000000,0.0000000,270.0000000); //object(imoildrum4_las) (1)
	CreateObject(3633,-1729.0996100,71.0996100,3.0000000,0.0000000,0.0000000,0.0000000); //object(imoildrum4_las) (2)
	CreateObject(3633,-1727.5000000,73.0000000,3.0000000,0.0000000,0.0000000,309.9960000); //object(imoildrum4_las) (3)
	CreateObject(7025,-1685.4000200,-94.6000000,6.0000000,0.0000000,0.0000000,316.0000000); //object(plantbox1) (1)
	CreateObject(3575,-1692.5999800,-74.6000000,5.3000000,0.0000000,0.0000000,226.0000000); //object(lasdkrt05) (1)
	CreateObject(3571,-1676.0000000,-79.4000000,3.9000000,0.0000000,0.0000000,0.0000000); //object(lasdkrt3) (1)
	CreateObject(3566,-1682.1999500,-70.4000000,5.2000000,0.0000000,0.0000000,240.0000000); //object(lasntrk1) (1)
	CreateObject(3576,-1672.8000500,-91.7000000,4.1000000,0.0000000,0.0000000,0.0000000); //object(dockcrates2_la) (2)
	CreateObject(5269,-1675.5999800,-94.3000000,4.9000000,0.0000000,0.0000000,16.0000000); //object(las2dkwar05) (1)
	CreateObject(3573,-1665.0000000,-29.9000000,5.3000000,0.0000000,0.0000000,226.0000000); //object(lasdkrtgrp1) (1)
	CreateObject(3569,-1644.5999800,-34.6000000,5.2000000,0.0000000,0.0000000,44.0000000); //object(lasntrk3) (1)
	CreateObject(3565,-1656.0999800,-33.6000000,3.9000000,0.0000000,0.0000000,316.0000000); //object(lasdkrt1_la01) (1)
	CreateObject(2934,-1651.4000200,-41.1000000,4.0000000,0.0000000,0.0000000,260.0000000); //object(kmb_container_red) (1)
	CreateObject(2935,-1651.8000500,-45.2000000,4.0000000,0.0000000,0.0000000,270.0000000); //object(kmb_container_yel) (3)
	CreateObject(922,-1660.6999500,-37.5000000,3.4000000,0.0000000,0.0000000,0.0000000); //object(packing_carates1) (1)
	CreateObject(942,-1672.5000000,-39.1000000,5.0000000,0.0000000,0.0000000,0.0000000); //object(cj_df_unit_2) (1)
	CreateObject(12934,-1635.6999500,-54.0000000,5.9000000,0.0000000,0.0000000,100.0000000); //object(sw_trailer03) (1)
	CreateObject(3565,-1660.0999800,-46.2000000,3.9000000,0.0000000,0.0000000,0.0000000); //object(lasdkrt1_la01) (2)
	CreateObject(3630,-1668.5000000,-72.0000000,4.1000000,0.0000000,0.0000000,226.0000000); //object(crdboxes2_las) (1)

	// ATM Machines
	CreateObject(2754,-1867.3000500,943.2000100,35.1000000,0.0000000,0.0000000,90.0000000); //object(otb_machine) (1)
	CreateObject(2754,-1622.0999800,716.7000100,14.5000000,0.0000000,0.0000000,270.0000000); //object(otb_machine) (2)
	CreateObject(2754,-1493.0999800,930.9000200,7.1000000,0.0000000,0.0000000,0.0000000); //object(otb_machine) (3)
	CreateObject(2754,-2450.1999500,755.5999800,35.1000000,0.0000000,0.0000000,90.0000000); //object(otb_machine) (4)
	CreateObject(2754,-2727.4678,388.9789,4.3672,0.0000000,0.0000000,90.0000000); //object(otb_machine) (5)
	CreateObject(2754,-2638.0537,635.3692,14.4531,0.0000000,0.0000000,0.0000000); //object(otb_machine) (6)
	CreateObject(2754,-1939.57678, 265.36545, 40.64025,0.0000000,0.0000000,180.0); //object(otb_machine) (7)
	CreateObject(2754, 1969.25671, 1722.71265, 10.71143,   0.00000, 0.00000, 91.08002);//8
	CreateObject(2754, 2195.41089, 961.21271, 10.96878,   0.00000, 0.00000, -88.26001);//9
	CreateObject(2754, 2486.87891, 1022.75305, 10.69436,   0.00000, 0.00000, 91.08000);//10
	CreateObject(2754, 2409.42529, 1543.84131, 10.71838,   0.00000, 0.00000, 88.80000);//11
	CreateObject(2754, 2293.27783, 1883.73120, 10.69659,   0.00000, 0.00000, -89.04005);//12
	CreateObject(2754, 2511.44580, 2062.79199, 10.70864,   0.00000, 0.00000, 87.23997);//13
	CreateObject(2754, 2182.51538, 2462.66919, 10.64280,   0.00000, 0.00000, 89.81999);//14
	CreateObject(2754, 2096.98071, 2711.66553, 10.65754,   0.00000, 0.00000, 0.00000);//15
	CreateObject(2754, 1705.71313, 1852.42419, 10.68405,   0.00000, 0.00000, -90.90001);//16


	// Supa Save
	CreateObject(10966, 2849.3515625, 2454.2802734375, 1796.7916259766, 270, 180, 180);
	CreateObject(19460, 2842.083984375, 2444.373046875, 1783.9499511719, 0, 0, 0);
	CreateObject(19460, 2837.3024902344, 2453.7451171875, 1783.9499511719, 0, 0, 0);
	CreateObject(19460, 2837.2951660156, 2463.3776855469, 1783.9499511719, 0, 0, 0);
	CreateObject(19460, 2842.1691894531, 2449.0207519531, 1783.9499511719, 0, 0, 90);
	CreateObject(19460, 2831.2434082031, 2459.2973632813, 1783.9499511719, 0, 0, 90);
	CreateObject(19460, 2840.8200683594, 2459.2973632813, 1783.9499511719, 0, 0, 90);
	CreateObject(19460, 2826.5087890625, 2464.0244140625, 1783.9499511719, 0, 0, 0);
	CreateObject(19460, 2821.6533203125, 2467.4045410156, 1783.9499511719, 0, 0, 90);
	CreateObject(19460, 2812.0319824219, 2467.4113769531, 1783.9499511719, 0, 0, 90);
	CreateObject(19460, 2837.2092285156, 2440.6469726563, 1783.9499511719, 0, 0, 90);
	CreateObject(19460, 2827.6118164063, 2440.6457519531, 1783.9499511719, 0, 0, 90);
	CreateObject(19176, 2842.0478515625, 2444.720703125, 1786.9649658203, 0.3955078125, 0, 90);
	CreateObject(19460, 2843.73046875, 2446.5092773438, 1783.7572021484, 90, 270, 0);
	CreateObject(19460, 2843.73046875, 2442.9130859375, 1783.7572021484, 90, 269.99450683594, 0);
	CreateObject(19368, 2843.7316894531, 2444.8884277344, 1788.4859619141, 0, 270, 0);
	CreateObject(19368, 2843.7316894531, 2444.5910644531, 1788.4859619141, 0, 269.99450683594, 0);
	CreateObject(997, 2828.9438476563, 2448.9797363281, 1785.4809570313, 0, 0, 270);
	CreateObject(997, 2832.2048339844, 2448.9409179688, 1785.4809570313, 0, 0, 180);
	CreateObject(1349, 2830.6010742188, 2441.3681640625, 1786.0516357422, 0, 0, 179.99572753906);
	CreateObject(1349, 2830.0285644531, 2441.3447265625, 1786.0516357422, 0, 0, 179.99450683594);
	CreateObject(1349, 2830.1420898438, 2442.3579101563, 1786.0516357422, 0, 0, 157.99450683594);
	CreateObject(1885, 2829.7084960938, 2443.3666992188, 1785.4809570313, 0, 0, 42.247924804688);
	CreateObject(1885, 2829.6135253906, 2447.4978027344, 1785.4809570313, 0, 0, 348.24792480469);
	CreateObject(2754, 2839.6223144531, 2448.6276855469, 1786.3831787109, 0, 0, 90);
	CreateObject(2754, 2838.7680664063, 2448.640625, 1786.3831787109, 0, 0, 90);
	CreateObject(1330, 2840.5222167969, 2448.4565429688, 1785.9072265625, 0, 0, 342);
	CreateObject(949, 2841.6860351563, 2442.587890625, 1786.1174316406, 0, 0, 0);
	CreateObject(949, 2841.658203125, 2446.8225097656, 1786.1174316406, 0, 0, 0);
	CreateObject(2197, 2839.0922851563, 2441.8000488281, 1785.4809570313, 0, 0, 180);
	CreateObject(2197, 2838.4187011719, 2441.8000488281, 1785.4809570313, 0, 0, 179.99450683594);
	CreateObject(2197, 2837.7448730469, 2441.8000488281, 1785.4809570313, 0, 0, 179.99450683594);
	CreateObject(2197, 2837.0661621094, 2441.8000488281, 1785.4809570313, 0, 0, 179.99450683594);
	CreateObject(2197, 2839.091796875, 2441.7998046875, 1787.1400146484, 0, 0, 179.99450683594);
	CreateObject(2197, 2838.41796875, 2441.7998046875, 1787.1400146484, 0, 0, 179.99450683594);
	CreateObject(2197, 2837.744140625, 2441.7998046875, 1787.1400146484, 0, 0, 179.99450683594);
	CreateObject(19329, 2834.3852539063, 2440.7329101563, 1788.390625, 0, 0, 0);
	CreateObject(997, 2828.8999023438, 2443.9348144531, 1785.4809570313, 0, 0, 270);
	CreateObject(1349, 2829.9526367188, 2448.208984375, 1786.0516357422, 0, 0, 165.74572753906);
	CreateObject(997, 2837.2060546875, 2448.9636230469, 1785.4809570313, 0, 0, 179.99450683594);
	CreateObject(1885, 2829.7080078125, 2443.3662109375, 1785.9063720703, 0, 0, 42.247924804688);
	CreateObject(1885, 2829.3771972656, 2446.4743652344, 1785.4809570313, 0, 0, 268.24462890625);
	CreateObject(19460, 2817.986328125, 2440.6455078125, 1783.9499511719, 0, 0, 90);
	CreateObject(1984, 2829.5764160156, 2451.7495117188, 1785.4809570313, 0, 0, 0);
	CreateObject(1984, 2829.5764160156, 2456.8178710938, 1785.4809570313, 0, 0, 0);
	CreateObject(997, 2832.1381835938, 2452.23046875, 1785.4809570313, 0, 0, 270);
	CreateObject(997, 2832.1184082031, 2457.3193359375, 1785.4809570313, 0, 0, 270);
	CreateObject(997, 2832.2087402344, 2454.0554199219, 1785.4809570313, 0, 0, 179.99450683594);
	CreateObject(1806, 2831.3071289063, 2455.453125, 1785.4809570313, 0, 0, 320);
	CreateObject(1806, 2831.3913574219, 2450.4020996094, 1785.4809570313, 0, 0, 19.998779296875);
	CreateObject(1885, 2830.037109375, 2456.0383300781, 1785.4809570313, 0, 0, 348.24462890625);
	CreateObject(1349, 2830.3630371094, 2448.0969238281, 1786.0516357422, 0, 0, 165.74523925781);
	CreateObject(1349, 2830.8759765625, 2447.1928710938, 1786.0516357422, 0, 0, 195.74523925781);
	CreateObject(2197, 2836.3916015625, 2441.7998046875, 1785.4809570313, 0, 0, 179.99450683594);
	CreateObject(1702, 2836.6613769531, 2456.7463378906, 1785.4809570313, 0, 0, 270);
	CreateObject(15038, 2836.6896972656, 2457.5700683594, 1786.0981445313, 0, 0, 0);
	CreateObject(15038, 2836.6896972656, 2450.3999023438, 1786.0981445313, 0, 0, 0);
	CreateObject(2370, 2836.64453125, 2451.462890625, 1785.4809570313, 0, 0, 0);
	CreateObject(2370, 2836.6457519531, 2453.1557617188, 1785.4809570313, 0, 0, 0);
	CreateObject(1716, 2835.5134277344, 2449.7143554688, 1785.4809570313, 0, 0, 0);
	CreateObject(1886, 2836.4526367188, 2458.5627441406, 1795.2008056641, 20, 0, 313);
	CreateObject(2362, 2829.2434082031, 2456.2048339844, 1786.4272460938, 0, 0, 180);
	CreateObject(2490, 2830.0541992188, 2456.6203613281, 1786.5592041016, 0, 0, 180);
	CreateObject(2489, 2829.5217285156, 2451.5290527344, 1786.5594482422, 0, 0, 180);
	CreateObject(2495, 2830.1791992188, 2451.513671875, 1786.5563964844, 0, 0, 180);
	CreateObject(19460, 2808.4165039063, 2440.6442871094, 1783.9499511719, 0, 0, 90);
	CreateObject(19460, 2809.8193359375, 2464.0690917969, 1783.9499511719, 0, 0, 0);
	CreateObject(19460, 2809.8193359375, 2444.9020996094, 1783.9499511719, 0, 0, 0);
	CreateObject(19460, 2809.8193359375, 2454.4775390625, 1783.9499511719, 0, 0, 0);
	CreateObject(9527, 2832.052734375, 2459.9187011719, 1789.9001464844, 0, 0, 0);
	CreateObject(19326, 2837.2116699219, 2451.8759765625, 1788.1075439453, 0, 0, 90);
	CreateObject(18100, 2836.4140625, 2447.400390625, 1785.5, 0, 0, 20);
	CreateObject(2690, 2839.8725585938, 2440.7944335938, 1786.29296875, 0, 0, 180);
	CreateObject(1891, 2821.8000488281, 2447.4833984375, 1785.4809570313, 0, 0, 0);
	CreateObject(1890, 2815.4440917969, 2447.8359375, 1785.4809570313, 0, 0, 90);
	CreateObject(1889, 2815.4445800781, 2444.7844238281, 1785.4809570313, 0, 0, 90);
	CreateObject(1887, 2821.1188964844, 2455.599609375, 1785.4809570313, 0, 0, 90);
	CreateObject(1884, 2824.9118652344, 2447.4833984375, 1785.4809570313, 0, 0, 0);
	CreateObject(1883, 2821.4450683594, 2462.0690917969, 1785.4809570313, 0, 0, 0);
	CreateObject(1850, 2820.0832519531, 2466.919921875, 1785.4809570313, 0, 0, 0);
	CreateObject(1849, 2810.2727050781, 2460.6638183594, 1785.4809570313, 0, 0, 90);
	CreateObject(1848, 2816.537109375, 2454.6013183594, 1785.4809570313, 0, 0, 90);
	CreateObject(1847, 2823.8596191406, 2466.7534179688, 1785.4809570313, 0, 0, 0);
	CreateObject(1845, 2824.9375, 2453.654296875, 1785.4809570313, 0, 0, 0);
	CreateObject(1844, 2816.7849121094, 2466.7900390625, 1785.4809570313, 0, 0, 0);
	CreateObject(1843, 2810.3747558594, 2464.6760253906, 1785.4809570313, 0, 0, 90);
	CreateObject(1842, 2818.4384765625, 2462.0615234375, 1785.9483642578, 0, 0, 0);
	CreateObject(1983, 2813, 2466.8459472656, 1787.0999755859, 0, 0, 0);
	CreateObject(1983, 2812, 2466.845703125, 1787.0999755859, 0, 0, 0);
	CreateObject(1848, 2820.0458984375, 2454.6081542969, 1785.4809570313, 0, 0, 270);
	CreateObject(1847, 2815.4440917969, 2454.6103515625, 1785.4809570313, 0, 0, 270);
	CreateObject(1981, 2810.3908691406, 2450.669921875, 1785.4809570313, 0, 0, 90);
	CreateObject(1981, 2810.390625, 2452.6630859375, 1785.4809570313, 0, 0, 90);
	CreateObject(1981, 2810.390625, 2451.669921875, 1785.4809570313, 0, 0, 90);
	CreateObject(2871, 2823.3229980469, 2441.2177734375, 1786.6528320313, 0, 0, 180);
	CreateObject(2871, 2824.322265625, 2441.2177734375, 1786.6528320313, 0, 0, 179.99450683594);
	CreateObject(2583, 2827.34765625, 2458.9497070313, 1786.3486328125, 0, 0, 0);
	CreateObject(2542, 2822.2858886719, 2441.2177734375, 1786.6528320313, 0, 0, 180);
	CreateObject(2541, 2825.6999511719, 2441.2177734375, 1786.6528320313, 0, 0, 180);
	CreateObject(2536, 2810.34765625, 2443.2309570313, 1785.4809570313, 0, 0, 90);
	CreateObject(2535, 2810.3486328125, 2444.220703125, 1785.4809570313, 0, 0, 90);
	CreateObject(2539, 2810.3408203125, 2445.2106933594, 1785.4809570313, 0, 0, 90);
	CreateObject(2538, 2810.3386230469, 2446.1892089844, 1785.4809570313, 0, 0, 90);
	CreateObject(2537, 2810.3801269531, 2449.7255859375, 1785.4809570313, 0, 0, 90);
	CreateObject(2536, 2810.3852539063, 2448.7373046875, 1785.4809570313, 0, 0, 90);
	CreateObject(1996, 2818.9992675781, 2441.2260742188, 1785.4809570313, 0, 0, 180);
	CreateObject(1996, 2810.38671875, 2453.66015625, 1785.4809570313, 0, 0, 90);
	CreateObject(1991, 2819.9909667969, 2441.2287597656, 1785.4809570313, 0, 0, 180);
	CreateObject(1993, 2810.3317871094, 2456.1987304688, 1785.4809570313, 0, 0, 90);
	CreateObject(1994, 2810.30078125, 2457.2084960938, 1785.4809570313, 0, 0, 270);
	CreateObject(1995, 2810.2990722656, 2455.2067871094, 1785.4809570313, 0, 0, 270);
	CreateObject(2541, 2825.962890625, 2463.0961914063, 1786.8907470703, 0, 0, 270);
	CreateObject(2541, 2825.962890625, 2464.0827636719, 1786.8907470703, 0, 0, 269.98901367188);
	CreateObject(1988, 2814, 2466.8459472656, 1787.0999755859, 0, 0, 0);
	CreateObject(1983, 2813.3979492188, 2441.2177734375, 1787.7856445313, 0, 0, 180);
	CreateObject(1987, 2814.3979492188, 2441.2177734375, 1787.7856445313, 0, 0, 180);
	CreateObject(1987, 2810.3923339844, 2455.75, 1787.5124511719, 0, 0, 90);
	CreateObject(1988, 2810.3923339844, 2456.75, 1787.5124511719, 0, 0, 90);
	CreateObject(1988, 2812.3984375, 2441.2177734375, 1787.7856445313, 0, 0, 179.99450683594);
	CreateObject(2804, 2810.2768554688, 2455.3195800781, 1786.3756103516, 0, 0, 0);
	CreateObject(2804, 2810.4467773438, 2455.4560546875, 1786.3756103516, 0, 0, 198);
	CreateObject(2806, 2810.310546875, 2456.2607421875, 1786.3668212891, 0, 0, 3);
	CreateObject(2804, 2810.4826660156, 2457.3017578125, 1786.3756103516, 0, 0, 197.99560546875);
	CreateObject(1209, 2820.888671875, 2453.4406738281, 1785.4809570313, 0, 0, 90);
	CreateObject(1776, 2826.0593261719, 2460.7253417969, 1786.5804443359, 0, 0, 270);
	CreateObject(1775, 2810.3010253906, 2447.5808105469, 1786.5782470703, 0, 0, 90);
	CreateObject(2663, 2836.8146972656, 2453.9580078125, 1786.5826416016, 0, 0, 40);
	CreateObject(1776, 2817.8935546875, 2441.17578125, 1786.5804443359, 0, 0, 179.99450683594);
	CreateObject(1886, 2810.5607910156, 2466.5046386719, 1795.2264404297, 19.9951171875, 0, 43.744995117188);
	CreateObject(1886, 2810.4194335938, 2441.3022460938, 1795.2531738281, 19.989624023438, 0, 137.74203491211);
	CreateObject(1845, 2824.9521484375, 2456.6181640625, 1785.4809570313, 0, 0, 180);
	CreateObject(8710, 2803.6101074219, 2491.5998535156, 1766.9392089844, 0, 0, 0);
	CreateObject(8710, 2785.669921875, 2438.8532714844, 1766.9392089844, 0, 0, 90);
	CreateObject(8710, 2850.6010742188, 2488.9499511719, 1766.9392089844, 0, 0, 270);
	CreateObject(8710, 2861.3962402344, 2478.6650390625, 1766.9392089844, 0, 0, 270);
	CreateObject(8710, 2866.1787109375, 2467.2573242188, 1766.9392089844, 0, 0, 270);
	CreateObject(8710, 2830.6586914063, 2410.9499511719, 1766.9392089844, 0, 0, 90);
	CreateObject(6989, 2886.0209960938, 2447.4331054688, 1873.279296875, 0, 270, 0);
	CreateObject(1892, 2832.5703125, 2448.6364746094, 1785.4809570313, 0, 0, 0);
	CreateObject(14439, 2834.4116210938, 2448.1572265625, 1795.5, 0, 0, 270);
	CreateObject(14439, 2818.33984375, 2448.13671875, 1795.5, 0, 0, 270);
	CreateObject(9186, 2817.2431640625, 2466.6611328125, 1797.0516357422, 0, 0, 7.75);
	CreateObject(8326, 2809.8044433594, 2451.6799316406, 1792.4576416016, 0, 0, 180);
	CreateObject(4729, 2821.2099609375, 2440.7229003906, 1791.3382568359, 0, 0, 110);
	
	//office
	CreateObject(19378, -648.44, 1595.52, 1027.20,   0.00, 90.00, 0.00);
	CreateObject(19454, -653.58, 1595.52, 1029.02,   0.00, 0.00, 0.00);
	CreateObject(19454, -648.78, 1590.80, 1026.92,   0.00, 0.00, 90.00);
	CreateObject(19439, -651.81, 1591.60, 1028.00,   0.00, 90.00, 0.00);
	CreateObject(19439, -648.33, 1591.60, 1028.00,   0.00, 90.00, 0.00);
	CreateObject(19439, -644.85, 1591.60, 1028.00,   0.00, 90.00, 0.00);
	CreateObject(19435, -646.65, 1592.32, 1027.28,   90.00, 0.00, 90.00);
	CreateObject(19435, -650.14, 1592.32, 1027.28,   90.00, 0.00, 90.00);
	CreateObject(19435, -644.10, 1592.32, 1029.02,   0.00, 0.00, 90.00);
	CreateObject(19435, -644.82, 1591.52, 1029.02,   0.00, 0.00, 0.00);
	CreateObject(19435, -653.72, 1600.42, 1029.02,   0.00, 0.00, 90.00);
	CreateObject(19435, -651.97, 1591.52, 1029.02,   0.00, 0.00, 0.00);
	CreateObject(19325, -648.39, 1590.88, 1028.93,   0.00, 0.00, 90.00);
	CreateObject(19439, -652.51, 1590.80, 1030.42,   0.00, 0.00, 90.00);
	CreateObject(19439, -644.27, 1590.80, 1028.82,   0.00, 0.00, 90.00);
	CreateObject(19325, -648.39, 1590.78, 1028.93,   0.00, 0.00, 90.00);
	CreateObject(19325, -648.39, 1590.71, 1028.93,   0.00, 0.00, 90.00);
	CreateObject(19439, -650.91, 1590.80, 1032.30,   0.00, 0.00, 90.00);
	CreateObject(19439, -649.31, 1590.80, 1032.30,   0.00, 0.00, 90.00);
	CreateObject(19439, -647.71, 1590.80, 1032.30,   0.00, 0.00, 90.00);
	CreateObject(19439, -646.12, 1590.80, 1032.30,   0.00, 0.00, 90.00);
	CreateObject(19439, -644.52, 1590.80, 1032.30,   0.00, 0.00, 90.00);
	CreateObject(19377, -648.44, 1595.52, 1030.85,   0.00, 90.00, 0.00);
	CreateObject(19439, -643.22, 1593.12, 1029.02,   0.00, 0.00, 0.00);
	CreateObject(19366, -643.22, 1598.73, 1029.02,   0.00, 0.00, 0.00);
	CreateObject(19391, -643.22, 1595.52, 1029.02,   0.00, 0.00, 0.00);
	CreateObject(2270, -643.81, 1593.10, 1028.93,   0.00, 0.00, 270.00);
	CreateObject(2267, -647.15, 1600.31, 1029.19,   0.00, 0.00, 0.00);
	CreateObject(948, -651.60, 1591.71, 1028.08,   0.00, 0.00, 0.00);
	CreateObject(2119, -653.36, 1595.20, 1027.28,   0.00, 0.00, 90.00);
	CreateObject(2251, -653.43, 1595.75, 1028.91,   0.00, 0.00, 0.00);
	CreateObject(948, -643.79, 1593.08, 1027.29,   0.00, 0.00, 0.00);
	CreateObject(19454, -648.10, 1600.42, 1029.02,   0.00, 0.00, 90.00);
	CreateObject(19435, -652.70, 1592.32, 1029.02,   0.00, 0.00, 90.00);
	CreateObject(19366, -645.05, 1598.74, 1030.84,   0.00, 90.00, 180.00);
	CreateObject(19366, -648.55, 1598.74, 1030.84,   0.00, 90.00, 180.00);
	CreateObject(19366, -652.04, 1598.74, 1030.84,   0.00, 90.00, 180.00);
	CreateObject(19439, -645.04, 1593.11, 1030.84,   0.00, 90.00, 0.00);
	CreateObject(19439, -648.54, 1593.11, 1030.84,   0.00, 90.00, 0.00);
	CreateObject(19439, -652.04, 1593.11, 1030.84,   0.00, 90.00, 0.00);
	CreateObject(957, -645.47, 1591.45, 1030.73,   0.00, 0.00, 0.00);
	CreateObject(957, -648.36, 1591.45, 1030.73,   0.00, 0.00, 0.00);
	CreateObject(957, -651.30, 1591.45, 1030.73,   0.00, 0.00, 0.00);
	CreateObject(957, -646.59, 1595.57, 1030.72,   0.00, 0.00, 0.00);
	CreateObject(957, -652.64, 1595.57, 1030.73,   0.00, 0.00, 0.00);
	CreateObject(957, -643.88, 1595.57, 1030.73,   0.00, 0.00, 0.00);
	CreateObject(957, -649.65, 1595.57, 1030.73,   0.00, 0.00, 0.00);
	CreateObject(2205, -650.25, 1596.27, 1027.28,   0.00, 0.00, 270.00);
	CreateObject(1714, -651.37, 1596.26, 1027.28,   0.00, 0.00, 45.00);
	CreateObject(2204, -653.41, 1597.87, 1027.28,   0.00, 0.00, 90.00);
	CreateObject(1727, -645.78, 1599.63, 1027.29,   0.00, 0.00, 320.00);
	CreateObject(1727, -648.47, 1597.06, 1027.25,   0.00, 0.00, 300.00);
	CreateObject(1727, -649.31, 1598.98, 1027.29,   0.00, 0.00, 40.00);
	CreateObject(2271, -652.99, 1595.70, 1029.09,   0.00, 0.00, 90.00);
	CreateObject(2110, -647.62, 1600.12, 1027.04,   0.00, 0.00, 0.00);
	CreateObject(1670, -647.06, 1599.94, 1027.85,   0.00, 0.00, 0.00);
	CreateObject(1665, -650.54, 1594.64, 1028.23,   0.00, 0.00, 0.00);
	CreateObject(19466, -653.02, 1599.21, 1028.07,   0.00, 0.00, 0.00);
	CreateObject(1666, -653.21, 1599.93, 1028.41,   0.00, 0.00, 0.00);
	CreateObject(1667, -653.26, 1600.02, 1028.41,   0.00, 0.00, 0.00);
	CreateObject(1664, -653.26, 1599.75, 1028.49,   0.00, 0.00, 0.00);
	CreateObject(1665, -650.03, 1596.48, 1028.23,   0.00, 0.00, 0.00);
	CreateObject(2190, -650.12, 1594.90, 1028.21,   0.00, 0.00, 230.00);
	CreateObject(2257, -643.33, 1598.60, 1029.09,   0.00, 0.00, 270.00);
	CreateObject(2119, -643.28, 1598.07, 1027.28,   0.00, 0.00, 90.00);
	CreateObject(2251, -643.61, 1598.58, 1028.91,   0.00, 0.00, 0.00);
	CreateObject(1569, -643.25, 1594.79, 1027.27,   0.00, 0.00, 90.00);

	// Bank fence
	CreateObject(970,-1498.5000000,919.9000200,6.7000000,0.0000000,0.0000000,270.0000000); //object(fencesmallb) (1)
	CreateObject(970,-1495.5999800,923.2000100,6.7000000,0.0000000,0.0000000,180.0000000); //object(fencesmallb) (2)
	CreateObject(970,-1495.5999800,917.0000000,6.7000000,0.0000000,0.0000000,179.9950000); //object(fencesmallb) (3)


	// Admin Lounge
	CreateObject(16150,2030.0000000,-768.4000200,1933.3000500,0.0000000,0.0000000,0.0000000); //object(ufo_barinterior) (1)
	CreateObject(18553,2026.1999500,-772.9000200,1934.5999800,0.0000000,0.0000000,0.0000000); //object(count_ammundoor) (1)
	CreateObject(2964,2030.0000000,-767.0999800,1933.3000500,0.0000000,0.0000000,0.0000000); //object(k_pooltablesm) (1)
	CreateObject(3102,2029.3000500,-767.0000000,1934.2399900,0.0000000,0.0000000,8.0000000); //object(k_poolballspt04) (1)
	CreateObject(2999,2030.1999500,-766.9000200,1934.2399900,0.0000000,0.0000000,0.0000000); //object(k_poolballstp05) (1)
	CreateObject(338,2030.4000200,-767.7999900,1933.6999500,0.0000000,350.2500000,234.0000000); //object(1)
	CreateObject(1712,2029.1999500,-763.0999800,1933.3000500,0.0000000,0.0000000,0.0000000); //object(kb_couch05) (1)
	CreateObject(14806,2030.0999800,-781.5999800,1935.0000000,0.0000000,0.0000000,178.2500000); //object(bdupshifi) (1)
	CreateObject(14384,2035.1999500,-770.9000200,1934.8000500,0.0000000,0.0000000,270.0000000); //object(kitchen_bits) (1)
	CreateObject(2754,2026.6999500, -769.7999900, 1934.1999500, 0.0000000,0.0000000,180.0000000); //object(otb_machine) (1)
	CreateObject(18553,2033.8000500,-770.5999800,1934.5999800,0.0000000,0.0000000,359.0000000); //object(count_ammundoor) (3)
	CreateDynamicObject(14602,2464.00000000,2376.80004883,-35.00000000,0.00000000,0.00000000,180.75000000, -1, 69);  //object(paperchase01) (1)
	CreateDynamicObject(14596,2476.39990234,2359.69995117,-29.70000076,0.00000000,0.00000000,0.49707031, -1, 69);  //object(paperchase_stairs) (3)
	CreateDynamicObject(14576,2472.00000000,2378.10009766,-44.90000153,0.00000000,0.00000000,180.75000000, -1, 69);  //object(vault_door) (2)
	CreateDynamicObject(3117,2468.00000000,2391.80004883,-40.50000000,0.00000000,0.00000000,0.00000000, -1, 69);  //object(a51_ventcoverb) (1)
	CreateDynamicObject(3117,2469.00000000,2391.80004883,-39.20000076,0.00000000,270.00000000,0.75003052, -1, 69);  //object(a51_ventcoverb) (2)
	CreateDynamicObject(3117,2470.00000000,2390.80004883,-39.20000076,0.00000000,270.00000000,90.99630737, -1, 69);  //object(a51_ventcoverb) (3)
	CreateDynamicObject(3117,2468.00000000,2391.80004883,-37.29999924,0.50000000,180.00000000,180.75000000, -1, 69);  //object(a51_ventcoverb) (4)
	CreateDynamicObject(3117,2467.30004883,2391.69995117,-39.20000076,0.00000000,270.00000000,180.24645996, -1, 69);  //object(a51_ventcoverb) (5)
	CreateDynamicObject(3117,2466.30004883,2390.69995117,-39.20000076,0.00000000,270.00000000,90.99426270, -1, 69);  //object(a51_ventcoverb) (6)
	CreateDynamicObject(1523,2467.39990234,2390.89990234,-40.40000153,0.00000000,0.00000000,0.00000000, -1, 69);  //object(gen_doorext10) (1)
	CreateDynamicObject(3117,2468.30004883,2391.00000000,-36.09999847,0.00000000,270.00000000,90.99426270, -1, 69);  //object(a51_ventcoverb) (7)
	CreateDynamicObject(1536,2466.89990234,2392.80004883,-44.70000076,0.00000000,0.00000000,1.00000000, -1, 69);  //object(gen_doorext15) (1)
	CreateDynamicObject(3117,2467.60009766,2392.69995117,-43.59999847,0.00000000,270.00000000,270.49353027, -1, 69);  //object(a51_ventcoverb) (8)
	CreateDynamicObject(3117,2466.00000000,2394.60009766,-43.70000076,0.00000000,270.00000000,180.24169922, -1, 69);  //object(a51_ventcoverb) (9)
	CreateDynamicObject(1536,2466.10009766,2395.30004883,-44.70000076,0.00000000,0.00000000,270.99975586, -1, 69);  //object(gen_doorext15) (4)
	//CreateDynamicObject(2634,2471.80004883,2371.30004883,-51.40000153,0.00000000,0.00000000,46.50000000, -1, 69);  //object(ab_vaultdoor) (1)
	bankVault2 = CreateDynamicObject(2634, 2472.043701, 2370.503906, -51.309658, 0.00000000,0.00000000, 0.00000000, -1, 69);  //object(ab_vaultdoor) (1)
	CreateDynamicObject(2886,2473.50000000,2370.60009766,-51.50000000,0.00000000,0.00000000,179.25000000, -1, 69);  //object(sec_keypad) (1)
	CreateDynamicObject(1886,2472.19995117,2354.69995117,-48.09999847,0.00000000,0.00000000,182.00000000, -1, 69);  //object(shop_sec_cam) (1)
	CreateDynamicObject(1616,2468.80004883,2370.89990234,-49.00000000,0.00000000,0.00000000,274.00000000, -1, 69);  //object(nt_securecam1_01) (1)
	CreateDynamicObject(1622,2472.39990234,2371.19995117,-48.90000153,21.44152832,323.63153076,249.06671143, -1, 69);  //object(nt_securecam2_01) (1)
	CreateDynamicObject(2921,2479.60009766,2374.39990234,-50.09999847,0.00000000,0.00000000,0.00000000, -1, 69);  //object(kmb_cam) (1)
	CreateDynamicObject(3265,2469.89990234,2370.60009766,-53.00000000,0.00000000,0.00000000,178.25000000, -1, 69);  //object(privatesign4) (1)
	CreateDynamicObject(1522,2449.50000000,2377.30004883,-40.40000153,0.00000000,0.00000000,270.49996948, -1, 69);  //object(gen_doorshop3) (1)
	CreateDynamicObject(2921,2466.30004883,2373.19995117,-37.09999847,0.00000000,0.00000000,0.00000000, -1, 69);  //object(kmb_cam) (2)
	CreateDynamicObject(1892,2460.30004883,2374.39990234,-40.29999924,0.00000000,0.00000000,90.75000000, -1, 69);  //object(security_gatsh) (2)
	CreateDynamicObject(1892,2460.30004883,2376.00000000,-40.29999924,0.00000000,0.00000000,90.74707031, -1, 69);  //object(security_gatsh) (3)
	CreateDynamicObject(1892,2460.30004883,2377.60009766,-40.29999924,0.00000000,0.00000000,90.74707031, -1, 69);  //object(security_gatsh) (4)
	CreateDynamicObject(3095,2460.69995117,2369.60009766,-40.40000153,0.00000000,269.49993896,0.00000000, -1, 69);  //object(a51_jetdoor) (1)
	CreateDynamicObject(3095,2460.69995117,2383.39990234,-40.40000153,0.00000000,269.49462891,0.00000000, -1, 69);  //object(a51_jetdoor) (2)
	CreateDynamicObject(3095,2488.30004883,2379.89990234,-40.40000153,0.00000000,269.49450684,89.74996948, -1, 69);  //object(a51_jetdoor) (4)
	CreateDynamicObject(3095,2488.30004883,2379.80004883,-31.50000000,0.00000000,269.48913574,89.74731445, -1, 69);  //object(a51_jetdoor) (5)
	CreateDynamicObject(3095,2488.39990234,2374.50000000,-40.40000153,0.00000000,269.48907471,269.74731445, -1, 69);  //object(a51_jetdoor) (6)
	CreateDynamicObject(3095,2488.39990234,2374.60009766,-31.39999962,0.00000000,269.48364258,269.74182129, -1, 69);  //object(a51_jetdoor) (7)
	CreateDynamicObject(3095,2484.30004883,2383.89990234,-33.79999924,0.00000000,269.49462891,0.00000000, -1, 69);  //object(a51_jetdoor) (8)
	CreateDynamicObject(3095,2484.30004883,2392.69995117,-33.79999924,0.00000000,269.49462891,0.00000000, -1, 69);  //object(a51_jetdoor) (9)
	CreateDynamicObject(3095,2484.39990234,2370.60009766,-33.79999924,0.00000000,269.49462891,0.00000000, -1, 69);  //object(a51_jetdoor) (10)
	CreateDynamicObject(3095,2484.39990234,2361.60009766,-33.79999924,0.00000000,269.49462891,0.00000000, -1, 69);  //object(a51_jetdoor) (11)
	CreateDynamicObject(1649,2484.00000000,2362.50000000,-38.70000076,0.00000000,0.00000000,270.75000000, -1, 69);  //object(wglasssmash) (1)
	CreateDynamicObject(1649,2483.89990234,2367.60009766,-38.70000076,0.00000000,0.00000000,270.24707031, -1, 69);  //object(wglasssmash) (2)
	CreateDynamicObject(1649,2483.89990234,2372.89990234,-38.70000076,0.00000000,0.00000000,269.99707031, -1, 69);  //object(wglasssmash) (3)
	CreateDynamicObject(13007,2461.80004883,2356.19995117,-32.79999924,0.00000000,0.00000000,270.50000000, -1, 69);  //object(sw_bankbits) (1)
	CreateDynamicObject(3117,2470.00000000,2365.50000000,-33.09999847,0.00000000,270.00000000,0.74707031, -1, 69);  //object(a51_ventcoverb) (10)
	CreateDynamicObject(3117,2469.89990234,2361.30004883,-33.09999847,0.00000000,270.00000000,0.74707031, -1, 69);  //object(a51_ventcoverb) (11)
	CreateDynamicObject(3117,2472.30004883,2360.80004883,-38.90000153,0.00000000,270.00000000,93.74365234, -1, 69);  //object(a51_ventcoverb) (12)
	CreateDynamicObject(3117,2476.00000000,2360.89990234,-38.90000153,0.00000000,270.00000000,90.99426270, -1, 69);  //object(a51_ventcoverb) (13)
	CreateDynamicObject(3117,2474.30004883,2360.80004883,-36.79999924,270.25024414,271.20373535,91.68957520, -1, 69);  //object(a51_ventcoverb) (14)
	CreateDynamicObject(1649,2483.80004883,2381.60009766,-38.70000076,0.00000000,0.00000000,269.99450684, -1, 69);  //object(wglasssmash) (4)
	CreateDynamicObject(1649,2483.80004883,2386.80004883,-38.70000076,0.00000000,0.00000000,269.99450684, -1, 69);  //object(wglasssmash) (5)
	CreateDynamicObject(1649,2483.80004883,2391.89990234,-38.70000076,0.00000000,0.00000000,269.99450684, -1, 69);  //object(wglasssmash) (6)
	CreateDynamicObject(2775,2483.50000000,2365.10009766,-37.79999924,0.00000000,0.00000000,269.99996948, -1, 69);  //object(cj_airprt_mon) (1)
	CreateDynamicObject(2775,2483.50000000,2370.19995117,-37.79999924,0.00000000,0.00000000,269.99450684, -1, 69);  //object(cj_airprt_mon) (2)
	CreateDynamicObject(2775,2483.39990234,2384.19995117,-37.79999924,0.00000000,0.00000000,269.99450684, -1, 69);  //object(cj_airprt_mon) (3)
	CreateDynamicObject(2775,2483.50000000,2389.39990234,-37.79999924,0.00000000,0.00000000,269.99450684, -1, 69);  //object(cj_airprt_mon) (4)
	CreateDynamicObject(2308,2484.39990234,2365.89990234,-40.29999924,0.00000000,0.00000000,0.00000000, -1, 69);  //object(med_office4_desk_4) (1)
	CreateDynamicObject(2193,2485.60009766,2361.89990234,-40.40000153,0.00000000,0.00000000,91.00000000, -1, 69);  //object(med_office2_desk_2) (1)
	CreateDynamicObject(2205,2485.89990234,2364.10009766,-40.40000153,0.00000000,0.00000000,181.25000000, -1, 69);  //object(med_office8_desk_1) (1)
	CreateDynamicObject(2190,2484.50000000,2366.00000000,-39.50000000,0.00000000,0.00000000,1.75000000, -1, 69);  //object(pc_1) (1)
	CreateDynamicObject(1671,2485.19995117,2362.80004883,-39.90000153,0.00000000,0.00000000,258.00000000, -1, 69);  //object(swivelchair_a) (1)
	CreateDynamicObject(1514,2484.39990234,2366.30004883,-39.29999924,0.00000000,0.00000000,270.50000000, -1, 69);  //object(dyn_ff_till) (1)
	CreateDynamicObject(2362,2484.10009766,2364.10009766,-39.40000153,0.00000000,0.00000000,269.25000000, -1, 69);  //object(cj_sweetie_tray_1) (1)
	CreateDynamicObject(2614,2483.80004883,2365.00000000,-36.40000153,0.00000000,0.00000000,269.75000000, -1, 69);  //object(cj_us_flag) (1)
	CreateDynamicObject(2614,2483.80004883,2370.30004883,-36.40000153,0.00000000,0.00000000,269.74731445, -1, 69);  //object(cj_us_flag) (2)
	CreateDynamicObject(2614,2483.69995117,2384.19995117,-36.40000153,0.00000000,0.00000000,269.74731445, -1, 69);  //object(cj_us_flag) (3)
	CreateDynamicObject(2614,2483.69995117,2389.39990234,-36.40000153,0.00000000,0.00000000,269.74731445, -1, 69);  //object(cj_us_flag) (4)
	CreateDynamicObject(2611,2487.10009766,2365.30004883,-38.90000153,0.00000000,0.00000000,271.25000000, -1, 69);  //object(police_nb1) (1)
	CreateDynamicObject(2193,2485.60009766,2367.89990234,-40.40000153,0.00000000,0.00000000,90.24975586, -1, 69);  //object(med_office2_desk_2) (2)
	CreateDynamicObject(2816,2485.30004883,2364.30004883,-39.40000153,0.00000000,0.00000000,0.00000000, -1, 69);  //object(gb_bedmags01) (1)
	CreateDynamicObject(2828,2484.60009766,2364.10009766,-39.50000000,0.00000000,0.00000000,347.00000000, -1, 69);  //object(gb_ornament02) (1)
	CreateDynamicObject(2253,2483.39990234,2363.00000000,-39.20000076,0.00000000,0.00000000,0.00000000, -1, 69);  //object(plant_pot_22) (1)
	CreateDynamicObject(2252,2483.00000000,2367.50000000,-39.09999847,0.00000000,0.00000000,0.00000000, -1, 69);  //object(plant_pot_21) (1)
	CreateDynamicObject(2251,2484.39990234,2366.80004883,-38.70000076,0.00000000,0.00000000,0.00000000, -1, 69);  //object(plant_pot_20) (1)
	CreateDynamicObject(2245,2483.00000000,2381.60009766,-39.09999847,0.00000000,0.00000000,0.00000000, -1, 69);  //object(plant_pot_11) (1)
	CreateDynamicObject(2244,2483.19995117,2372.89990234,-39.20000076,0.00000000,0.00000000,0.00000000, -1, 69);  //object(plant_pot_9) (1)
	CreateDynamicObject(2240,2483.00000000,2386.89990234,-38.79999924,0.00000000,0.00000000,0.00000000, -1, 69);  //object(plant_pot_8) (1)
	CreateDynamicObject(2194,2483.00000000,2391.39990234,-39.09999847,0.00000000,0.00000000,0.00000000, -1, 69);  //object(plant_pot_2) (1)
	CreateDynamicObject(2308,2484.50000000,2371.19995117,-40.29999924,0.00000000,0.00000000,0.00000000, -1, 69);  //object(med_office4_desk_4) (2)
	CreateDynamicObject(2362,2484.10009766,2369.19995117,-39.40000153,0.00000000,0.00000000,269.24743652, -1, 69);  //object(cj_sweetie_tray_1) (2)
	CreateDynamicObject(2190,2484.60009766,2371.39990234,-39.50000000,0.00000000,0.00000000,1.74682617, -1, 69);  //object(pc_1) (2)
	CreateDynamicObject(1514,2484.39990234,2371.69995117,-39.29999924,0.00000000,0.00000000,270.49987793, -1, 69);  //object(dyn_ff_till) (2)
	CreateDynamicObject(2811,2484.30004883,2372.30004883,-39.70000076,0.00000000,0.00000000,0.00000000, -1, 69);  //object(gb_romanpot01) (1)
	CreateDynamicObject(2611,2487.00000000,2370.30004883,-38.90000153,0.00000000,0.00000000,271.24694824, -1, 69);  //object(police_nb1) (2)
	CreateDynamicObject(2181,2486.60009766,2374.10009766,-40.40000153,0.00000000,0.00000000,270.75000000, -1, 69);  //object(med_office5_desk_2) (1)
	CreateDynamicObject(1714,2485.89990234,2373.60009766,-40.40000153,0.00000000,0.00000000,86.00000000, -1, 69);  //object(kb_swivelchair1) (1)
	CreateDynamicObject(1671,2485.39990234,2368.69995117,-39.90000153,0.00000000,0.00000000,257.99743652, -1, 69);  //object(swivelchair_a) (3)
	CreateDynamicObject(2773,2481.69995117,2364.39990234,-39.79999924,0.00000000,0.00000000,271.50000000, -1, 69);  //object(cj_airprt_bar) (1)
	CreateDynamicObject(2773,2481.69995117,2365.69995117,-39.79999924,0.00000000,0.00000000,271.49963379, -1, 69);  //object(cj_airprt_bar) (2)
	CreateDynamicObject(2773,2481.50000000,2369.39990234,-39.79999924,0.00000000,0.00000000,271.49963379, -1, 69);  //object(cj_airprt_bar) (3)
	CreateDynamicObject(2773,2481.50000000,2370.89990234,-39.79999924,0.00000000,0.00000000,271.49963379, -1, 69);  //object(cj_airprt_bar) (4)
	CreateDynamicObject(2773,2478.30004883,2368.30004883,-39.79999924,0.00000000,0.00000000,271.49963379, -1, 69);  //object(cj_airprt_bar) (5)
	CreateDynamicObject(2773,2478.30004883,2366.89990234,-39.79999924,0.00000000,0.00000000,271.49963379, -1, 69);  //object(cj_airprt_bar) (6)
	CreateDynamicObject(2773,2477.30004883,2369.19995117,-39.79999924,0.00000000,0.00000000,1.24963379, -1, 69);  //object(cj_airprt_bar) (7)
	CreateDynamicObject(2773,2477.39990234,2365.89990234,-39.79999924,0.00000000,0.00000000,1.24694824, -1, 69);  //object(cj_airprt_bar) (8)
	CreateDynamicObject(2773,2476.10009766,2365.80004883,-39.79999924,0.00000000,0.00000000,1.24694824, -1, 69);  //object(cj_airprt_bar) (9)
	CreateDynamicObject(2773,2476.10009766,2367.69995117,-39.79999924,0.00000000,0.00000000,1.24694824, -1, 69);  //object(cj_airprt_bar) (10)
	CreateDynamicObject(2773,2476.00000000,2369.60009766,-39.79999924,0.00000000,0.00000000,1.24694824, -1, 69);  //object(cj_airprt_bar) (11)
	CreateDynamicObject(2193,2485.60009766,2380.50000000,-40.40000153,0.00000000,0.00000000,90.99975586, -1, 69);  //object(med_office2_desk_2) (3)
	CreateDynamicObject(2362,2483.80004883,2383.19995117,-39.40000153,0.00000000,0.00000000,269.24743652, -1, 69);  //object(cj_sweetie_tray_1) (3)
	CreateDynamicObject(2362,2483.80004883,2388.50000000,-39.40000153,0.00000000,0.00000000,269.24743652, -1, 69);  //object(cj_sweetie_tray_1) (4)
	CreateDynamicObject(2308,2484.19995117,2385.19995117,-40.29999924,0.00000000,0.00000000,0.00000000, -1, 69);  //object(med_office4_desk_4) (3)
	CreateDynamicObject(2190,2484.30004883,2385.30004883,-39.50000000,0.00000000,0.00000000,1.74682617, -1, 69);  //object(pc_1) (3)
	CreateDynamicObject(1514,2484.10009766,2385.60009766,-39.29999924,0.00000000,0.00000000,270.49987793, -1, 69);  //object(dyn_ff_till) (3)
	CreateDynamicObject(2894,2483.30004883,2365.69995117,-39.40000153,0.00000000,0.00000000,0.00000000, -1, 69);  //object(kmb_rhymesbook) (1)
	CreateDynamicObject(2894,2483.19995117,2371.10009766,-39.40000153,0.00000000,0.00000000,0.00000000, -1, 69);  //object(kmb_rhymesbook) (2)
	CreateDynamicObject(2894,2483.10009766,2384.89990234,-39.40000153,0.00000000,0.00000000,0.00000000, -1, 69);  //object(kmb_rhymesbook) (3)
	CreateDynamicObject(2894,2482.89990234,2390.30004883,-39.40000153,0.00000000,0.00000000,0.00000000, -1, 69);  //object(kmb_rhymesbook) (4)
	CreateDynamicObject(1964,2485.39990234,2370.10009766,-39.40000153,0.00000000,0.00000000,0.00000000, -1, 69);  //object(est_dsk_stuf) (2)
	CreateDynamicObject(2205,2485.50000000,2369.89990234,-40.50000000,0.00000000,0.00000000,181.24694824, -1, 69);  //object(med_office8_desk_1) (2)
	CreateDynamicObject(2205,2485.50000000,2382.50000000,-40.50000000,0.00000000,0.00000000,181.24694824, -1, 69);  //object(med_office8_desk_1) (3)
	CreateDynamicObject(1964,2485.39990234,2382.69995117,-39.40000153,0.00000000,0.00000000,0.00000000, -1, 69);  //object(est_dsk_stuf) (3)
	CreateDynamicObject(2193,2485.39990234,2387.19995117,-40.40000153,0.00000000,0.00000000,90.49975586, -1, 69);  //object(med_office2_desk_2) (5)
	CreateDynamicObject(2308,2484.30004883,2390.39990234,-40.29999924,0.00000000,0.00000000,0.00000000, -1, 69);  //object(med_office4_desk_4) (4)
	CreateDynamicObject(2190,2484.39990234,2390.50000000,-39.50000000,0.00000000,0.00000000,1.74682617, -1, 69);  //object(pc_1) (4)
	CreateDynamicObject(1514,2484.19995117,2390.80004883,-39.29999924,0.00000000,0.00000000,270.49987793, -1, 69);  //object(dyn_ff_till) (4)
	CreateDynamicObject(14705,2485.19995117,2386.30004883,-38.29999924,0.00000000,0.00000000,0.00000000, -1, 69);  //object(int2vase) (1)
	CreateDynamicObject(2246,2484.19995117,2386.30004883,-39.59999847,0.00000000,0.00000000,0.00000000, -1, 69);  //object(plant_pot_14) (1)
	CreateDynamicObject(2249,2484.10009766,2386.30004883,-38.90000153,0.00000000,0.00000000,0.00000000, -1, 69);  //object(plant_pot_18) (2)
	CreateDynamicObject(2773,2481.30004883,2383.30004883,-39.79999924,0.00000000,0.00000000,271.49963379, -1, 69);  //object(cj_airprt_bar) (12)
	CreateDynamicObject(2773,2481.30004883,2384.69995117,-39.79999924,0.00000000,0.00000000,271.49963379, -1, 69);  //object(cj_airprt_bar) (13)
	CreateDynamicObject(2773,2481.19995117,2388.39990234,-39.79999924,0.00000000,0.00000000,271.49963379, -1, 69);  //object(cj_airprt_bar) (14)
	CreateDynamicObject(2773,2481.19995117,2389.89990234,-39.79999924,0.00000000,0.00000000,271.49963379, -1, 69);  //object(cj_airprt_bar) (15)
	CreateDynamicObject(2773,2477.19995117,2387.39990234,-39.79999924,0.00000000,0.00000000,271.49963379, -1, 69);  //object(cj_airprt_bar) (17)
	CreateDynamicObject(2773,2477.19995117,2386.00000000,-39.79999924,0.00000000,0.00000000,271.49963379, -1, 69);  //object(cj_airprt_bar) (18)
	CreateDynamicObject(2773,2476.19995117,2385.00000000,-39.79999924,0.00000000,0.00000000,358.74963379, -1, 69);  //object(cj_airprt_bar) (19)
	CreateDynamicObject(2773,2474.89990234,2385.00000000,-39.79999924,0.00000000,0.00000000,358.74755859, -1, 69);  //object(cj_airprt_bar) (20)
	CreateDynamicObject(2773,2475.50000000,2386.69995117,-39.79999924,0.00000000,0.00000000,316.74758911, -1, 69);  //object(cj_airprt_bar) (21)
	CreateDynamicObject(3921,2476.30004883,2392.10009766,-39.79999924,0.00000000,0.00000000,90.50003052, -1, 69);  //object(lib_counchs) (1)
	CreateDynamicObject(3921,2472.39990234,2388.10009766,-39.79999924,0.00000000,0.00000000,180.74987793, -1, 69);  //object(lib_counchs) (2)
	CreateDynamicObject(2239,2472.10009766,2392.19995117,-40.40000153,0.00000000,0.00000000,0.00000000, -1, 69);  //object(cj_mlight16) (1)
	CreateDynamicObject(1741,2471.69995117,2383.19995117,-40.40000153,0.00000000,0.00000000,0.50000000, -1, 69);  //object(low_cabinet_1) (1)
	CreateDynamicObject(1741,2481.19995117,2392.00000000,-40.40000153,0.00000000,0.00000000,90.24987793, -1, 69);  //object(low_cabinet_1) (2)
	CreateDynamicObject(2007,2486.50000000,2392.30004883,-40.40000153,0.00000000,0.00000000,270.75000000, -1, 69);  //object(filing_cab_nu01) (1)
	CreateDynamicObject(16780,2482.00000000,2377.39990234,-34.79999924,0.00000000,0.00000000,0.00000000, -1, 69);  //object(ufo_light03) (1)
	CreateDynamicObject(2596,2475.89990234,2381.10009766,-37.29999924,0.00000000,0.00000000,186.75000000, -1, 69);  //object(cj_sex_tv) (1)
	CreateDynamicObject(2754,2475.30004883,2373.10009766,-39.59999847,0.00000000,0.00000000,0.00000000, -1, 69);  //object(otb_machine) (1)
	CreateDynamicObject(2754,2475.19995117,2380.69995117,-39.59999847,0.00000000,0.00000000,0.00000000, -1, 69);  //object(otb_machine) (2)
	CreateDynamicObject(2754,2479.89990234,2377.10009766,-39.70000076,0.00000000,0.00000000,181.00000000, -1, 69);  //object(otb_machine) (3)
	CreateDynamicObject(3437,2487.30004883,2378.69995117,-34.50000000,0.00000000,0.00000000,86.25000000, -1, 69);  //object(ballypllr01_lvs) (1)
	CreateDynamicObject(3437,2487.39990234,2375.89990234,-34.50000000,0.00000000,0.00000000,86.24816895, -1, 69);  //object(ballypllr01_lvs) (3)
	CreateDynamicObject(3437,2487.30004883,2377.19995117,-30.50000000,0.00000000,0.00000000,86.24816895, -1, 69);  //object(ballypllr01_lvs) (4)
	CreateDynamicObject(1742,2487.19995117,2377.30004883,-40.40000153,0.00000000,0.00000000,272.00000000, -1, 69);  //object(med_bookshelf) (1)
	CreateDynamicObject(2190,2480.10009766,2378.10009766,-39.59999847,0.00000000,0.00000000,71.25000000, -1, 69);  //object(pc_1) (5)
	CreateDynamicObject(2190,2480.00000000,2376.50000000,-39.59999847,0.00000000,0.00000000,103.24633789, -1, 69);  //object(pc_1) (6)
	CreateDynamicObject(1671,2481.30004883,2377.50000000,-39.90000153,0.00000000,0.00000000,250.00000000, -1, 69);  //object(swivelchair_a) (4)
	CreateDynamicObject(1671,2481.30004883,2376.69995117,-39.90000153,0.00000000,0.00000000,289.99938965, -1, 69);  //object(swivelchair_a) (5)
	CreateDynamicObject(1776,2461.80004883,2380.60009766,-39.29999924,0.00000000,0.00000000,0.00000000, -1, 69);  //object(cj_candyvendor) (1)
	CreateDynamicObject(1775,2461.69995117,2373.00000000,-39.29999924,0.00000000,0.00000000,180.75000000, -1, 69);  //object(cj_sprunk1) (1)
	CreateDynamicObject(3851,2471.69995117,2365.50000000,-39.00000000,0.00000000,0.00000000,0.75000000, -1, 69);  //object(carshowwin_sfsx) (2)
	CreateDynamicObject(3851,2463.50000000,2371.10009766,-39.00000000,0.00000000,0.00000000,90.74707031, -1, 69);  //object(carshowwin_sfsx) (3)
	CreateDynamicObject(2008,2469.89990234,2363.39990234,-40.40000153,0.00000000,0.00000000,0.00000000, -1, 69);  //object(officedesk1) (1)
	CreateDynamicObject(1998,2468.00000000,2362.39990234,-40.40000153,0.00000000,0.00000000,0.00000000, -1, 69);  //object(officedesk1l) (1)
	CreateDynamicObject(2186,2467.80004883,2370.39990234,-40.40000153,0.00000000,0.00000000,0.00000000, -1, 69);  //object(photocopier_1) (1)
	CreateDynamicObject(1705,2465.69995117,2370.30004883,-40.40000153,0.00000000,0.00000000,0.00000000, -1, 69);  //object(kb_chair04) (1)
	CreateDynamicObject(1705,2464.50000000,2370.30004883,-40.40000153,0.00000000,0.00000000,0.00000000, -1, 69);  //object(kb_chair04) (2)
	CreateDynamicObject(1705,2463.30004883,2370.30004883,-40.40000153,0.00000000,0.00000000,0.00000000, -1, 69);  //object(kb_chair04) (3)
	CreateDynamicObject(1998,2463.50000000,2362.30004883,-40.40000153,0.00000000,0.00000000,0.00000000, -1, 69);  //object(officedesk1l) (2)
	CreateDynamicObject(2008,2465.39990234,2363.30004883,-40.40000153,0.00000000,0.00000000,0.00000000, -1, 69);  //object(officedesk1) (2)
	CreateDynamicObject(1714,2464.30004883,2362.10009766,-40.40000153,0.00000000,0.00000000,177.50000000, -1, 69);  //object(kb_swivelchair1) (2)
	CreateDynamicObject(1714,2466.39990234,2362.00000000,-40.40000153,0.00000000,0.00000000,180.24511719, -1, 69);  //object(kb_swivelchair1) (3)
	CreateDynamicObject(1714,2468.80004883,2362.19995117,-40.40000153,0.00000000,0.00000000,180.24169922, -1, 69);  //object(kb_swivelchair1) (4)
	CreateDynamicObject(1714,2471.00000000,2362.10009766,-40.40000153,0.00000000,0.00000000,180.24169922, -1, 69);  //object(kb_swivelchair1) (5)
	CreateDynamicObject(1721,2463.69995117,2364.50000000,-40.40000153,0.00000000,0.00000000,231.99998474, -1, 69);  //object(est_chair1) (1)
	CreateDynamicObject(1721,2465.00000000,2364.60009766,-40.40000153,0.00000000,0.00000000,144.99832153, -1, 69);  //object(est_chair1) (2)
	CreateDynamicObject(1721,2465.60009766,2364.60009766,-40.40000153,0.00000000,0.00000000,224.99755859, -1, 69);  //object(est_chair1) (3)
	CreateDynamicObject(1721,2466.80004883,2364.60009766,-40.40000153,0.00000000,0.00000000,140.99450684, -1, 69);  //object(est_chair1) (4)
	CreateDynamicObject(1721,2467.80004883,2364.60009766,-40.40000153,0.00000000,0.00000000,224.99450684, -1, 69);  //object(est_chair1) (5)
	CreateDynamicObject(1721,2469.10009766,2364.60009766,-40.40000153,0.00000000,0.00000000,130.99450684, -1, 69);  //object(est_chair1) (6)
	CreateDynamicObject(1721,2469.80004883,2364.60009766,-40.40000153,0.00000000,0.00000000,228.99002075, -1, 69);  //object(est_chair1) (7)
	CreateDynamicObject(1721,2471.10009766,2364.60009766,-40.40000153,0.00000000,0.00000000,130.98803711, -1, 69);  //object(est_chair1) (8)
	CreateDynamicObject(2332,2465.39990234,2360.89990234,-39.90000153,0.00000000,0.00000000,181.00000000, -1, 69);  //object(kev_safe) (1)
	CreateDynamicObject(2067,2463.60009766,2361.50000000,-40.20000076,0.00000000,0.00000000,89.75000000, -1, 69);  //object(cj_m_fileing3) (1)
	CreateDynamicObject(2126,2463.10009766,2367.89990234,-40.40000153,0.00000000,0.00000000,269.99996948, -1, 69);  //object(coffee_swank_5) (1)
	CreateDynamicObject(2855,2464.00000000,2367.30004883,-40.09999847,0.00000000,0.00000000,0.00000000, -1, 69);  //object(gb_bedmags05) (1)
	CreateDynamicObject(2852,2463.80004883,2367.30004883,-39.90000153,0.00000000,0.00000000,0.00000000, -1, 69);  //object(gb_bedmags02) (1)
	CreateDynamicObject(2195,2463.89990234,2366.19995117,-39.70000076,0.00000000,0.00000000,0.00000000, -1, 69);  //object(plant_pot_3) (1)
	CreateDynamicObject(1808,2471.30004883,2367.50000000,-40.40000153,0.00000000,0.00000000,270.00000000, -1, 69);  //object(cj_watercooler2) (1)
	CreateDynamicObject(2002,2481.30004883,2392.10009766,-40.40000153,0.00000000,0.00000000,0.00000000, -1, 69);  //object(water_coolnu) (1)
	CreateDynamicObject(1814,2475.69995117,2387.39990234,-40.40000153,0.00000000,0.00000000,24.00000000, -1, 69);  //object(coffee_med_1) (1)
	CreateDynamicObject(2852,2475.89990234,2388.10009766,-39.90000153,0.00000000,0.00000000,0.00000000, -1, 69);  //object(gb_bedmags02) (2)
	CreateDynamicObject(2254,2463.19995117,2369.30004883,-37.59999847,0.00000000,0.00000000,90.75000000, -1, 69);  //object(frame_clip_1) (1)
	CreateDynamicObject(2287,2463.69995117,2365.60009766,-38.00000000,0.00000000,0.00000000,91.00000000, -1, 69);  //object(frame_4) (1)
	CreateDynamicObject(2280,2463.69995117,2363.00000000,-38.09999847,0.00000000,0.00000000,89.50000000, -1, 69);  //object(frame_thick_1) (1)
	CreateDynamicObject(2276,2465.00000000,2361.69995117,-38.00000000,0.00000000,0.00000000,180.75000000, -1, 69);  //object(frame_fab_3) (1)
	CreateDynamicObject(2269,2468.00000000,2361.69995117,-37.90000153,0.00000000,0.00000000,181.25000000, -1, 69);  //object(frame_wood_4) (1)
	CreateDynamicObject(2265,2470.00000000,2361.69995117,-37.90000153,0.00000000,0.00000000,186.00000000, -1, 69);  //object(frame_slim_6) (1)
	CreateDynamicObject(3117,2470.00000000,2363.60009766,-31.20000076,270.25024414,269.99942017,180.74627686, -1, 69);  //object(a51_ventcoverb) (15)
	CreateDynamicObject(2186,2464.89990234,2364.39990234,-34.59999847,0.00000000,0.00000000,0.00000000, -1, 69);  //object(photocopier_1) (2)
	CreateDynamicObject(2949,2459.69995117,2346.69995117,-34.79999924,0.00000000,0.00000000,269.99996948, -1, 69);  //object(kmb_lockeddoor) (1)
	CreateDynamicObject(948,2467.89990234,2359.39990234,-33.59999847,0.00000000,0.00000000,0.00000000, -1, 69);  //object(plant_pot_10) (1)
	CreateDynamicObject(950,2461.30004883,2358.89990234,-33.00000000,0.00000000,0.00000000,90.00000000, -1, 69);  //object(plant_pot_12) (1)
	CreateDynamicObject(14593,2456.19995117,2356.60009766,-26.50000000,0.00000000,0.00000000,90.50000000, -1, 69);  //object(paperchase04) (1)
	CreateDynamicObject(3117,2470.00000000,2361.69995117,-27.50000000,0.00000000,270.00000000,0.74707031, -1, 69);  //object(a51_ventcoverb) (16)
	CreateDynamicObject(3117,2470.00000000,2365.19995117,-27.50000000,0.00000000,270.00000000,0.74707031, -1, 69);  //object(a51_ventcoverb) (17)
	CreateDynamicObject(2180,2448.19995117,2355.30004883,-28.79999924,0.00000000,0.00000000,90.00000000, -1, 69);  //object(med_office5_desk_3) (1)
	CreateDynamicObject(2180,2448.39990234,2356.60009766,-28.79999924,0.00000000,0.00000000,23.74731445, -1, 69);  //object(med_office5_desk_3) (5)
	CreateDynamicObject(2180,2449.30004883,2354.50000000,-28.79999924,0.00000000,0.00000000,152.74694824, -1, 69);  //object(med_office5_desk_3) (7)
	CreateDynamicObject(2180,2451.00000000,2354.30004883,-28.79999924,0.00000000,0.00000000,179.99291992, -1, 69);  //object(med_office5_desk_3) (10)
	CreateDynamicObject(2180,2452.89990234,2354.30004883,-28.79999924,0.00000000,0.00000000,179.98901367, -1, 69);  //object(med_office5_desk_3) (12)
	CreateDynamicObject(2180,2454.80004883,2354.30004883,-28.79999924,0.00000000,0.00000000,179.98901367, -1, 69);  //object(med_office5_desk_3) (13)
	CreateDynamicObject(2180,2456.69995117,2354.30004883,-28.79999924,0.00000000,0.00000000,179.98901367, -1, 69);  //object(med_office5_desk_3) (14)
	CreateDynamicObject(2180,2450.10009766,2357.10009766,-28.79999924,0.00000000,0.00000000,359.98901367, -1, 69);  //object(med_office5_desk_3) (15)
	CreateDynamicObject(2180,2452.00000000,2357.10009766,-28.79999924,0.00000000,0.00000000,359.98352051, -1, 69);  //object(med_office5_desk_3) (20)
	CreateDynamicObject(2180,2453.89990234,2357.10009766,-28.79999924,0.00000000,0.00000000,359.98352051, -1, 69);  //object(med_office5_desk_3) (21)
	CreateDynamicObject(2180,2455.80004883,2357.10009766,-28.79999924,0.00000000,0.00000000,359.98352051, -1, 69);  //object(med_office5_desk_3) (22)
	CreateDynamicObject(2180,2458.39990234,2356.10009766,-28.79999924,0.00000000,0.00000000,269.75000000, -1, 69);  //object(med_office5_desk_3) (23)
	CreateDynamicObject(2180,2457.39990234,2357.00000000,-28.79999924,0.00000000,0.00000000,327.98352051, -1, 69);  //object(med_office5_desk_3) (24)
	CreateDynamicObject(2180,2458.19995117,2354.80004883,-28.79999924,0.00000000,0.00000000,202.48039246, -1, 69);  //object(med_office5_desk_3) (25)
	CreateDynamicObject(2180,2457.60009766,2356.10009766,-28.79999924,0.00000000,0.00000000,269.74731445, -1, 69);  //object(med_office5_desk_3) (26)
	CreateDynamicObject(2180,2456.80004883,2356.19995117,-28.79999924,0.00000000,0.00000000,269.74731445, -1, 69);  //object(med_office5_desk_3) (27)
	CreateDynamicObject(2180,2456.00000000,2356.19995117,-28.79999924,0.00000000,0.00000000,269.74731445, -1, 69);  //object(med_office5_desk_3) (28)
	CreateDynamicObject(2180,2455.19995117,2356.19995117,-28.79999924,0.00000000,0.00000000,269.74731445, -1, 69);  //object(med_office5_desk_3) (29)
	CreateDynamicObject(2180,2454.39990234,2356.19995117,-28.79999924,0.00000000,0.00000000,269.74731445, -1, 69);  //object(med_office5_desk_3) (30)
	CreateDynamicObject(2180,2453.60009766,2356.19995117,-28.79999924,0.00000000,0.00000000,269.74731445, -1, 69);  //object(med_office5_desk_3) (31)
	CreateDynamicObject(2180,2452.80004883,2356.19995117,-28.79999924,0.00000000,0.00000000,269.74731445, -1, 69);  //object(med_office5_desk_3) (32)
	CreateDynamicObject(2180,2452.00000000,2356.19995117,-28.79999924,0.00000000,0.00000000,269.74731445, -1, 69);  //object(med_office5_desk_3) (33)
	CreateDynamicObject(2180,2451.19995117,2356.19995117,-28.79999924,0.00000000,0.00000000,269.74731445, -1, 69);  //object(med_office5_desk_3) (34)
	CreateDynamicObject(2180,2450.39990234,2356.19995117,-28.79999924,0.00000000,0.00000000,269.74731445, -1, 69);  //object(med_office5_desk_3) (35)
	CreateDynamicObject(2180,2449.60009766,2356.19995117,-28.79999924,0.00000000,0.00000000,269.74731445, -1, 69);  //object(med_office5_desk_3) (36)
	CreateDynamicObject(2180,2449.00000000,2356.19995117,-28.79999924,0.00000000,0.00000000,269.74731445, -1, 69);  //object(med_office5_desk_3) (37)
	CreateDynamicObject(1714,2446.50000000,2355.69995117,-28.79999924,0.00000000,0.00000000,90.49475098, -1, 69);  //object(kb_swivelchair1) (7)
	CreateDynamicObject(1714,2448.19995117,2353.39990234,-28.79999924,0.00000000,0.00000000,152.49438477, -1, 69);  //object(kb_swivelchair1) (8)
	CreateDynamicObject(1714,2450.60009766,2352.89990234,-28.79999924,0.00000000,0.00000000,181.24023438, -1, 69);  //object(kb_swivelchair1) (9)
	CreateDynamicObject(1714,2452.39990234,2352.89990234,-28.79999924,0.00000000,0.00000000,179.73596191, -1, 69);  //object(kb_swivelchair1) (10)
	CreateDynamicObject(1714,2454.39990234,2352.89990234,-28.79999924,0.00000000,0.00000000,179.73083496, -1, 69);  //object(kb_swivelchair1) (11)
	CreateDynamicObject(1714,2456.19995117,2352.89990234,-28.79999924,0.00000000,0.00000000,179.73083496, -1, 69);  //object(kb_swivelchair1) (12)
	CreateDynamicObject(1714,2458.39990234,2353.39990234,-28.79999924,0.00000000,0.00000000,203.73083496, -1, 69);  //object(kb_swivelchair1) (13)
	CreateDynamicObject(1714,2458.60009766,2357.89990234,-28.79999924,0.00000000,0.00000000,327.73046875, -1, 69);  //object(kb_swivelchair1) (14)
	CreateDynamicObject(1714,2456.19995117,2358.50000000,-28.79999924,0.00000000,0.00000000,0.72766113, -1, 69);  //object(kb_swivelchair1) (15)
	CreateDynamicObject(1714,2454.30004883,2358.50000000,-28.79999924,0.00000000,0.00000000,0.72509766, -1, 69);  //object(kb_swivelchair1) (16)
	CreateDynamicObject(1714,2452.50000000,2358.50000000,-28.79999924,0.00000000,0.00000000,0.72509766, -1, 69);  //object(kb_swivelchair1) (17)
	CreateDynamicObject(1714,2450.60009766,2358.50000000,-28.79999924,0.00000000,0.00000000,0.72509766, -1, 69);  //object(kb_swivelchair1) (18)
	CreateDynamicObject(1714,2448.39990234,2358.00000000,-28.79999924,0.00000000,0.00000000,28.72509766, -1, 69);  //object(kb_swivelchair1) (19)
	CreateDynamicObject(1491,2470.00000000,2364.19995117,-28.79999924,0.00000000,0.00000000,270.00000000, -1, 69);  //object(gen_doorint01) (1)
	CreateDynamicObject(3117,2470.10009766,2363.69995117,-25.29999924,89.10256958,326.13626099,303.10235596, -1, 69);  //object(a51_ventcoverb) (18)
	CreateDynamicObject(1491,2463.60009766,2364.10009766,-28.79999924,0.00000000,0.00000000,269.99450684, -1, 69);  //object(gen_doorint01) (2)
	CreateDynamicObject(2755,2449.60009766,2361.60009766,-27.10000038,0.00000000,0.00000000,0.00000000, -1, 69);  //object(dojo_wall) (1)
	CreateDynamicObject(2755,2446.89990234,2361.60009766,-27.10000038,0.00000000,0.00000000,0.00000000, -1, 69);  //object(dojo_wall) (2)
	CreateDynamicObject(2755,2455.00000000,2361.60009766,-27.10000038,0.00000000,0.00000000,0.00000000, -1, 69);  //object(dojo_wall) (3)
	CreateDynamicObject(2755,2457.69995117,2361.60009766,-27.10000038,0.00000000,0.00000000,0.00000000, -1, 69);  //object(dojo_wall) (4)
	CreateDynamicObject(2755,2457.80004883,2350.10009766,-27.10000038,0.00000000,0.00000000,0.00000000, -1, 69);  //object(dojo_wall) (5)
	CreateDynamicObject(2755,2455.10009766,2350.10009766,-27.10000038,0.00000000,0.00000000,0.00000000, -1, 69);  //object(dojo_wall) (6)
	CreateDynamicObject(2755,2449.69995117,2350.10009766,-27.10000038,0.00000000,0.00000000,0.00000000, -1, 69);  //object(dojo_wall) (7)
	CreateDynamicObject(2755,2447.00000000,2350.10009766,-27.10000038,0.00000000,0.00000000,0.00000000, -1, 69);  //object(dojo_wall) (8)
	CreateDynamicObject(2755,2445.50000000,2351.60009766,-27.10000038,0.00000000,0.00000000,269.75000000, -1, 69);  //object(dojo_wall) (9)
	CreateDynamicObject(2755,2445.50000000,2354.39990234,-27.10000038,0.00000000,0.00000000,269.74731445, -1, 69);  //object(dojo_wall) (10)
	CreateDynamicObject(2755,2445.50000000,2357.19995117,-27.10000038,0.00000000,0.00000000,269.74731445, -1, 69);  //object(dojo_wall) (11)
	CreateDynamicObject(2755,2452.30004883,2361.60009766,-27.10000038,0.00000000,0.00000000,0.00000000, -1, 69);  //object(dojo_wall) (12)
	CreateDynamicObject(2755,2460.19995117,2361.60009766,-27.10000038,0.00000000,0.00000000,0.00000000, -1, 69);  //object(dojo_wall) (13)
	CreateDynamicObject(2755,2445.50000000,2360.00000000,-27.10000038,0.00000000,0.00000000,269.74731445, -1, 69);  //object(dojo_wall) (14)
	CreateDynamicObject(2755,2452.39990234,2350.10009766,-27.10000038,0.00000000,0.00000000,0.00000000, -1, 69);  //object(dojo_wall) (15)
	CreateDynamicObject(2755,2460.50000000,2350.10009766,-27.10000038,0.00000000,0.00000000,0.00000000, -1, 69);  //object(dojo_wall) (16)
	CreateDynamicObject(2755,2461.69995117,2360.00000000,-27.10000038,0.00000000,0.00000000,269.74731445, -1, 69);  //object(dojo_wall) (17)
	CreateDynamicObject(2755,2461.69995117,2357.19995117,-27.10000038,0.00000000,0.00000000,269.74731445, -1, 69);  //object(dojo_wall) (18)
	CreateDynamicObject(2755,2461.69995117,2354.39990234,-27.10000038,0.00000000,0.00000000,269.74731445, -1, 69);  //object(dojo_wall) (19)
	CreateDynamicObject(3851,2456.10009766,2361.60009766,-27.50000000,0.00000000,0.00000000,90.00000000, -1, 69);  //object(carshowwin_sfsx) (5)
	CreateDynamicObject(3851,2451.00000000,2361.60009766,-27.50000000,0.00000000,0.00000000,90.00000000, -1, 69);  //object(carshowwin_sfsx) (6)
	CreateDynamicObject(3851,2451.00000000,2350.10009766,-27.50000000,0.00000000,0.00000000,90.00000000, -1, 69);  //object(carshowwin_sfsx) (7)
	CreateDynamicObject(3851,2456.30004883,2350.10009766,-27.50000000,0.00000000,0.00000000,90.00000000, -1, 69);  //object(carshowwin_sfsx) (8)
	CreateDynamicObject(3851,2445.50000000,2355.80004883,-27.50000000,0.00000000,0.00000000,180.00000000, -1, 69);  //object(carshowwin_sfsx) (9)
	CreateDynamicObject(3077,2460.50000000,2355.60009766,-28.89999962,0.00000000,0.00000000,90.00000000, -1, 69);  //object(nf_blackboard) (1)
	CreateDynamicObject(1808,2462.10009766,2365.39990234,-28.79999924,0.00000000,0.00000000,0.00000000, -1, 69);  //object(cj_watercooler2) (2)
	CreateDynamicObject(2253,2453.39990234,2355.69995117,-27.70000076,0.00000000,0.00000000,0.00000000, -1, 69);  //object(plant_pot_22) (2)
	CreateDynamicObject(2010,2460.00000000,2360.39990234,-28.79999924,0.00000000,0.00000000,0.00000000, -1, 69);  //object(nu_plant3_ofc) (1)
	CreateDynamicObject(2010,2446.60009766,2360.39990234,-28.79999924,0.00000000,0.00000000,0.00000000, -1, 69);  //object(nu_plant3_ofc) (2)
	CreateDynamicObject(2010,2446.19995117,2351.00000000,-28.79999924,0.00000000,0.00000000,0.00000000, -1, 69);  //object(nu_plant3_ofc) (3)
	CreateDynamicObject(2605,2468.39990234,2362.30004883,-28.39999962,0.00000000,0.00000000,0.00000000, -1, 69);  //object(polce_desk1) (1)
	CreateDynamicObject(1671,2468.39990234,2361.39990234,-28.39999962,0.00000000,0.00000000,180.00000000, -1, 69);  //object(swivelchair_a) (6)
	CreateDynamicObject(14597,2457.50000000,2363.10009766,-21.00000000,0.00000000,0.00000000,0.25000000, -1, 69);  //object(paperchase07) (1)
	CreateDynamicObject(14819,2473.89990234,2361.00000000,-21.79999924,0.00000000,0.00000000,0.00000000, -1, 69);  //object(og_door) (1)
	CreateDynamicObject(2205,2468.19995117,2368.39990234,-23.00000000,0.00000000,0.00000000,180.00000000, -1, 69);  //object(med_office8_desk_1) (4)
	CreateDynamicObject(3095,2465.60009766,2371.30004883,-22.29999924,0.00000000,269.49450684,90.00000000, -1, 69);  //object(a51_jetdoor) (12)
	CreateDynamicObject(2205,2463.80004883,2368.39990234,-23.00000000,0.00000000,0.00000000,179.99450684, -1, 69);  //object(med_office8_desk_1) (5)
	CreateDynamicObject(14632,2459.60009766,2361.30004883,-21.50000000,0.00000000,0.00000000,270.25000000, -1, 69);  //object(paperchase_bits2b) (1)
	CreateDynamicObject(2066,2467.60009766,2370.50000000,-23.00000000,0.00000000,0.00000000,181.25000000, -1, 69);  //object(cj_m_fileing2) (1)
	CreateDynamicObject(2066,2468.39990234,2370.10009766,-23.00000000,0.00000000,0.00000000,0.24694824, -1, 69);  //object(cj_m_fileing2) (2)
	CreateDynamicObject(2186,2465.80004883,2370.30004883,-23.00000000,0.00000000,0.00000000,0.00000000, -1, 69);  //object(photocopier_1) (3)
	CreateDynamicObject(2187,2464.80004883,2368.30004883,-23.00000000,0.00000000,0.00000000,0.00000000, -1, 69);  //object(partition2) (1)
	CreateDynamicObject(2187,2466.80004883,2368.30004883,-23.00000000,0.00000000,0.00000000,0.00000000, -1, 69);  //object(partition2) (2)
	CreateDynamicObject(2191,2464.10009766,2370.10009766,-23.20000076,0.00000000,0.00000000,0.00000000, -1, 69);  //object(med_office2_cab) (1)
	CreateDynamicObject(2197,2462.00000000,2369.50000000,-23.00000000,0.00000000,0.00000000,0.00000000, -1, 69);  //object(filling_cabinet) (1)
	CreateDynamicObject(2190,2467.60009766,2368.30004883,-22.10000038,0.00000000,0.00000000,181.25000000, -1, 69);  //object(pc_1) (7)
	CreateDynamicObject(2190,2455.50000000,2357.19995117,-22.20000076,0.00000000,0.00000000,90.74694824, -1, 69);  //object(pc_1) (8)
	CreateDynamicObject(1806,2467.39990234,2369.50000000,-23.00000000,0.00000000,0.00000000,182.00000000, -1, 69);  //object(med_office_chair) (1)
	CreateDynamicObject(1806,2463.19995117,2369.60009766,-23.00000000,0.00000000,0.00000000,181.99951172, -1, 69);  //object(med_office_chair) (2)
	CreateDynamicObject(1811,2468.30004883,2367.19995117,-22.39999962,0.00000000,0.00000000,0.00000000, -1, 69);  //object(med_din_chair_5) (1)
	CreateDynamicObject(1811,2461.89990234,2367.30004883,-22.39999962,0.00000000,0.00000000,180.00000000, -1, 69);  //object(med_din_chair_5) (2)
	CreateDynamicObject(1964,2467.60009766,2368.60009766,-22.00000000,0.00000000,0.00000000,0.00000000, -1, 69);  //object(est_dsk_stuf) (4)
	CreateDynamicObject(2205,2446.60009766,2363.89990234,-23.00000000,0.00000000,0.00000000,269.99450684, -1, 69);  //object(med_office8_desk_1) (6)
	CreateDynamicObject(1964,2446.39990234,2363.30004883,-21.89999962,0.00000000,0.00000000,90.00000000, -1, 69);  //object(est_dsk_stuf) (5)
	CreateDynamicObject(2190,2446.80004883,2363.80004883,-22.10000038,0.00000000,0.00000000,274.00000000, -1, 69);  //object(pc_1) (9)
	CreateDynamicObject(1714,2445.10009766,2363.10009766,-23.00000000,0.00000000,0.00000000,90.49438477, -1, 69);  //object(kb_swivelchair1) (20)
	CreateDynamicObject(1704,2452.30004883,2361.60009766,-23.00000000,0.00000000,0.00000000,270.00000000, -1, 69);  //object(kb_chair03) (1)
	CreateDynamicObject(1704,2452.30004883,2365.39990234,-23.00000000,0.00000000,0.00000000,269.99450684, -1, 69);  //object(kb_chair03) (2)
	CreateDynamicObject(1827,2449.30004883,2363.00000000,-23.00000000,0.00000000,0.00000000,0.00000000, -1, 69);  //object(man_sdr_tables) (1)
	CreateDynamicObject(2811,2449.19995117,2363.00000000,-22.70000076,0.00000000,0.00000000,0.00000000, -1, 69);  //object(gb_romanpot01) (2)
	CreateDynamicObject(1550,2445.89990234,2363.89990234,-22.60000038,0.00000000,0.00000000,0.00000000, -1, 69);  //object(cj_money_bag) (1)
	CreateDynamicObject(1491,2453.10009766,2363.80004883,-23.20000076,0.00000000,0.00000000,269.99450684, -1, 69);  //object(gen_doorint01) (3)
	CreateDynamicObject(3117,2453.00000000,2364.80004883,-21.29999924,0.00000000,270.00000000,0.74707031, -1, 69);  //object(a51_ventcoverb) (19)
	CreateDynamicObject(3117,2453.00000000,2361.10009766,-21.29999924,0.00000000,270.00000000,0.74707031, -1, 69);  //object(a51_ventcoverb) (20)
	CreateDynamicObject(3117,2453.00000000,2361.10009766,-17.79999924,0.00000000,270.00000000,0.74707031, -1, 69);  //object(a51_ventcoverb) (21)
	CreateDynamicObject(3117,2453.00000000,2362.60009766,-18.89999962,0.00000000,270.00000000,0.74707031, -1, 69);  //object(a51_ventcoverb) (22)
	CreateDynamicObject(3117,2453.00000000,2364.19995117,-18.89999962,0.00000000,270.00000000,0.74707031, -1, 69);  //object(a51_ventcoverb) (23)
	CreateDynamicObject(3117,2453.00000000,2365.69995117,-18.89999962,0.00000000,270.00000000,0.74707031, -1, 69);  //object(a51_ventcoverb) (24)
	CreateDynamicObject(1736,2444.69995117,2363.00000000,-20.29999924,0.00000000,0.00000000,90.00000000, -1, 69);  //object(cj_stags_head) (1)
	CreateDynamicObject(358,2445.60009766,2365.89990234,-20.70000076,0.00000000,0.00000000,0.00000000, -1, 69);  //object(2)
	CreateDynamicObject(357,2445.10009766,2360.39990234,-20.39999962,0.00000000,0.00000000,0.00000000, -1, 69);  //object(3)
	CreateDynamicObject(2061,2447.10009766,2360.39990234,-20.20000076,0.00000000,0.00000000,0.00000000, -1, 69);  //object(cj_shells1) (1)
	CreateDynamicObject(1581,2448.19995117,2365.89990234,-20.60000038,0.00000000,0.00000000,0.00000000, -1, 69);  //object(keycard) (1)
	CreateDynamicObject(14455,2447.89990234,2360.19995117,-21.50000000,0.00000000,0.00000000,0.00000000, -1, 69);  //object(gs_bookcase) (1)
	CreateDynamicObject(2256,2450.80004883,2365.89990234,-20.70000076,0.00000000,0.00000000,0.00000000, -1, 69);  //object(frame_clip_3) (1)
	CreateDynamicObject(2257,2452.80004883,2365.00000000,-20.79999924,0.00000000,0.00000000,269.25000000, -1, 69);  //object(frame_clip_4) (1)
	CreateDynamicObject(2193,2462.89990234,2356.10009766,-23.00000000,0.00000000,0.00000000,180.00000000, -1, 69);  //object(med_office2_desk_2) (7)
	CreateDynamicObject(2193,2461.89990234,2353.19995117,-23.00000000,0.00000000,0.00000000,0.00000000, -1, 69);  //object(med_office2_desk_2) (8)
	CreateDynamicObject(2193,2461.89990234,2351.30004883,-23.00000000,0.00000000,0.00000000,0.00000000, -1, 69);  //object(med_office2_desk_2) (9)
	CreateDynamicObject(2193,2465.50000000,2355.10009766,-23.00000000,0.00000000,0.00000000,90.00000000, -1, 69);  //object(med_office2_desk_2) (11)
	CreateDynamicObject(2193,2464.50000000,2353.19995117,-23.00000000,0.00000000,0.00000000,0.00000000, -1, 69);  //object(med_office2_desk_2) (12)
	CreateDynamicObject(2193,2464.50000000,2351.30004883,-23.00000000,0.00000000,0.00000000,0.00000000, -1, 69);  //object(med_office2_desk_2) (13)
	CreateDynamicObject(2193,2468.19995117,2355.10009766,-23.00000000,0.00000000,0.00000000,90.25000000, -1, 69);  //object(med_office2_desk_2) (14)
	CreateDynamicObject(2193,2467.19995117,2354.19995117,-23.00000000,0.00000000,0.00000000,270.24719238, -1, 69);  //object(med_office2_desk_2) (15)
	CreateDynamicObject(2193,2467.19995117,2352.30004883,-23.00000000,0.00000000,0.00000000,270.24719238, -1, 69);  //object(med_office2_desk_2) (16)
	CreateDynamicObject(2067,2461.89990234,2349.80004883,-23.00000000,0.00000000,0.00000000,89.50000000, -1, 69);  //object(cj_m_fileing3) (2)
	CreateDynamicObject(2067,2461.89990234,2350.50000000,-23.00000000,0.00000000,0.00000000,89.49462891, -1, 69);  //object(cj_m_fileing3) (3)
	CreateDynamicObject(2067,2468.30004883,2350.50000000,-23.00000000,0.00000000,0.00000000,271.49462891, -1, 69);  //object(cj_m_fileing3) (4)
	CreateDynamicObject(2067,2468.30004883,2349.89990234,-23.00000000,0.00000000,0.00000000,270.49414062, -1, 69);  //object(cj_m_fileing3) (5)
	CreateDynamicObject(2202,2467.00000000,2350.00000000,-23.00000000,0.00000000,0.00000000,180.00000000, -1, 69);  //object(photocopier_2) (1)
	CreateDynamicObject(2186,2464.60009766,2350.00000000,-23.00000000,0.00000000,0.00000000,180.25000000, -1, 69);  //object(photocopier_1) (4)
	CreateDynamicObject(1806,2462.00000000,2356.19995117,-23.00000000,0.00000000,0.00000000,177.99951172, -1, 69);  //object(med_office_chair) (3)
	CreateDynamicObject(1806,2462.60009766,2353.50000000,-23.00000000,0.00000000,0.00000000,71.99441528, -1, 69);  //object(med_office_chair) (4)
	CreateDynamicObject(1806,2462.39990234,2351.89990234,-23.00000000,0.00000000,0.00000000,345.99340820, -1, 69);  //object(med_office_chair) (5)
	CreateDynamicObject(1806,2465.10009766,2351.69995117,-23.00000000,0.00000000,0.00000000,345.99243164, -1, 69);  //object(med_office_chair) (6)
	CreateDynamicObject(1806,2465.30004883,2353.19995117,-23.00000000,0.00000000,0.00000000,25.99243164, -1, 69);  //object(med_office_chair) (7)
	CreateDynamicObject(1806,2465.30004883,2355.50000000,-23.00000000,0.00000000,0.00000000,173.98815918, -1, 69);  //object(med_office_chair) (8)
	CreateDynamicObject(1806,2468.10009766,2355.69995117,-23.00000000,0.00000000,0.00000000,67.98498535, -1, 69);  //object(med_office_chair) (9)
	CreateDynamicObject(1811,2468.10009766,2359.19995117,-22.39999962,0.00000000,0.00000000,88.75000000, -1, 69);  //object(med_din_chair_5) (3)
	CreateDynamicObject(1811,2467.30004883,2359.19995117,-22.39999962,0.00000000,0.00000000,90.49755859, -1, 69);  //object(med_din_chair_5) (4)
	CreateDynamicObject(1811,2462.10009766,2359.10009766,-22.39999962,0.00000000,0.00000000,90.49438477, -1, 69);  //object(med_din_chair_5) (5)
	CreateDynamicObject(1811,2463.10009766,2359.10009766,-22.39999962,0.00000000,0.00000000,90.49438477, -1, 69);  //object(med_din_chair_5) (6)
	CreateDynamicObject(1811,2464.10009766,2359.10009766,-22.39999962,0.00000000,0.00000000,90.49438477, -1, 69);  //object(med_din_chair_5) (7)
	CreateDynamicObject(2011,2464.50000000,2356.80004883,-23.00000000,0.00000000,0.00000000,0.00000000, -1, 69);  //object(nu_plant2_ofc) (1)
	CreateDynamicObject(2011,2467.10009766,2356.80004883,-23.00000000,0.00000000,0.00000000,0.00000000, -1, 69);  //object(nu_plant2_ofc) (2)
	CreateDynamicObject(2183,2458.30004883,2353.00000000,-23.00000000,0.00000000,0.00000000,270.50000000, -1, 69);  //object(med_office3_desk_09) (1)
	CreateDynamicObject(2183,2458.30004883,2358.10009766,-23.00000000,0.00000000,0.00000000,270.49987793, -1, 69);  //object(med_office3_desk_09) (3)
	CreateDynamicObject(2183,2454.80004883,2358.10009766,-23.00000000,0.00000000,0.00000000,270.49987793, -1, 69);  //object(med_office3_desk_09) (4)
	CreateDynamicObject(2183,2454.80004883,2352.89990234,-23.00000000,0.00000000,0.00000000,270.49987793, -1, 69);  //object(med_office3_desk_09) (5)
	CreateDynamicObject(1671,2457.69995117,2357.39990234,-22.50000000,0.00000000,0.00000000,90.00000000, -1, 69);  //object(swivelchair_a) (7)
	CreateDynamicObject(1671,2457.60009766,2355.80004883,-22.50000000,0.00000000,0.00000000,90.00000000, -1, 69);  //object(swivelchair_a) (8)
	CreateDynamicObject(1671,2457.80004883,2350.80004883,-22.50000000,0.00000000,0.00000000,90.00000000, -1, 69);  //object(swivelchair_a) (9)
	CreateDynamicObject(1671,2457.80004883,2352.30004883,-22.50000000,0.00000000,0.00000000,90.00000000, -1, 69);  //object(swivelchair_a) (10)
	CreateDynamicObject(1671,2454.10009766,2350.60009766,-22.50000000,0.00000000,0.00000000,90.00000000, -1, 69);  //object(swivelchair_a) (11)
	CreateDynamicObject(1671,2454.10009766,2352.30004883,-22.50000000,0.00000000,0.00000000,90.00000000, -1, 69);  //object(swivelchair_a) (12)
	CreateDynamicObject(1671,2454.10009766,2355.89990234,-22.50000000,0.00000000,0.00000000,90.00000000, -1, 69);  //object(swivelchair_a) (13)
	CreateDynamicObject(1671,2454.10009766,2357.30004883,-22.50000000,0.00000000,0.00000000,90.00000000, -1, 69);  //object(swivelchair_a) (14)
	CreateDynamicObject(1671,2460.19995117,2357.50000000,-22.50000000,0.00000000,0.00000000,272.00000000, -1, 69);  //object(swivelchair_a) (15)
	CreateDynamicObject(1671,2460.50000000,2355.80004883,-22.50000000,0.00000000,0.00000000,271.99951172, -1, 69);  //object(swivelchair_a) (16)
	CreateDynamicObject(1671,2460.19995117,2352.39990234,-22.50000000,0.00000000,0.00000000,271.99951172, -1, 69);  //object(swivelchair_a) (17)
	CreateDynamicObject(1671,2460.19995117,2350.60009766,-22.50000000,0.00000000,0.00000000,271.99951172, -1, 69);  //object(swivelchair_a) (18)
	CreateDynamicObject(2190,2463.39941406,2368.19921875,-22.10000038,0.00000000,0.00000000,181.24694824, -1, 69);  //object(pc_1) (10)
	CreateDynamicObject(1671,2456.60009766,2357.30004883,-22.50000000,0.00000000,0.00000000,271.99951172, -1, 69);  //object(swivelchair_a) (19)
	CreateDynamicObject(1671,2456.60009766,2355.80004883,-22.50000000,0.00000000,0.00000000,271.99951172, -1, 69);  //object(swivelchair_a) (20)
	CreateDynamicObject(1671,2456.60009766,2352.30004883,-22.50000000,0.00000000,0.00000000,271.99951172, -1, 69);  //object(swivelchair_a) (21)
	CreateDynamicObject(1671,2456.60009766,2350.50000000,-22.50000000,0.00000000,0.00000000,271.99951172, -1, 69);  //object(swivelchair_a) (22)
	CreateDynamicObject(2190,2455.50000000,2355.30004883,-22.20000076,0.00000000,0.00000000,90.74157715, -1, 69);  //object(pc_1) (11)
	CreateDynamicObject(2190,2455.50000000,2352.00000000,-22.20000076,0.00000000,0.00000000,90.74157715, -1, 69);  //object(pc_1) (12)
	CreateDynamicObject(2190,2455.50000000,2350.19995117,-22.20000076,0.00000000,0.00000000,90.74157715, -1, 69);  //object(pc_1) (13)
	CreateDynamicObject(2190,2455.50000000,2350.69995117,-22.20000076,0.00000000,0.00000000,270.74157715, -1, 69);  //object(pc_1) (14)
	CreateDynamicObject(2190,2455.39990234,2352.60009766,-22.20000076,0.00000000,0.00000000,270.73608398, -1, 69);  //object(pc_1) (15)
	CreateDynamicObject(2190,2455.39990234,2356.00000000,-22.20000076,0.00000000,0.00000000,270.73608398, -1, 69);  //object(pc_1) (16)
	CreateDynamicObject(2190,2455.39990234,2357.80004883,-22.20000076,0.00000000,0.00000000,270.73608398, -1, 69);  //object(pc_1) (17)
	CreateDynamicObject(2190,2458.89990234,2357.80004883,-22.20000076,0.00000000,0.00000000,270.73608398, -1, 69);  //object(pc_1) (18)
	CreateDynamicObject(2190,2458.89990234,2356.00000000,-22.20000076,0.00000000,0.00000000,270.73608398, -1, 69);  //object(pc_1) (19)
	CreateDynamicObject(2190,2458.89990234,2352.80004883,-22.20000076,0.00000000,0.00000000,270.73608398, -1, 69);  //object(pc_1) (20)
	CreateDynamicObject(2190,2458.89990234,2350.89990234,-22.20000076,0.00000000,0.00000000,270.73608398, -1, 69);  //object(pc_1) (21)
	CreateDynamicObject(2190,2459.10009766,2350.39990234,-22.20000076,0.00000000,0.00000000,90.74157715, -1, 69);  //object(pc_1) (22)
	CreateDynamicObject(2190,2459.10009766,2352.10009766,-22.20000076,0.00000000,0.00000000,90.74157715, -1, 69);  //object(pc_1) (23)
	CreateDynamicObject(2190,2459.00000000,2355.39990234,-22.20000076,0.00000000,0.00000000,90.74157715, -1, 69);  //object(pc_1) (24)
	CreateDynamicObject(2190,2459.10009766,2357.30004883,-22.20000076,0.00000000,0.00000000,90.74157715, -1, 69);  //object(pc_1) (25)
	CreateDynamicObject(2011,2460.50000000,2359.39990234,-23.00000000,0.00000000,0.00000000,0.00000000, -1, 69);  //object(nu_plant2_ofc) (3)
	CreateDynamicObject(2011,2454.10009766,2359.39990234,-23.00000000,0.00000000,0.00000000,0.00000000, -1, 69);  //object(nu_plant2_ofc) (4)
	CreateDynamicObject(1726,2460.10009766,2369.50000000,-23.00000000,0.00000000,0.00000000,270.00000000, -1, 69);  //object(mrk_seating2) (1)
	CreateDynamicObject(3095,2456.80004883,2371.30004883,-22.29999924,0.00000000,269.48913574,90.00000000, -1, 69);  //object(a51_jetdoor) (13)
	CreateDynamicObject(1726,2454.30004883,2367.50000000,-23.00000000,0.00000000,0.00000000,90.00000000, -1, 69);  //object(mrk_seating2) (2)
	CreateDynamicObject(1726,2456.19995117,2370.10009766,-23.00000000,0.00000000,0.00000000,0.00000000, -1, 69);  //object(mrk_seating2) (3)
	CreateDynamicObject(1815,2456.60009766,2367.60009766,-23.00000000,0.00000000,0.00000000,0.00000000, -1, 69);  //object(coffee_low_2) (2)
	CreateDynamicObject(2854,2457.10009766,2368.10009766,-22.50000000,0.00000000,0.00000000,0.00000000, -1, 69);  //object(gb_bedmags04) (1)
	CreateDynamicObject(2001,2459.80004883,2370.10009766,-23.00000000,0.00000000,0.00000000,0.00000000, -1, 69);  //object(nu_plant_ofc) (1)
	CreateDynamicObject(2001,2455.10009766,2370.30004883,-23.00000000,0.00000000,0.00000000,0.00000000, -1, 69);  //object(nu_plant_ofc) (2)
	CreateDynamicObject(1209,2461.19995117,2365.80004883,-23.00000000,0.00000000,0.00000000,0.00000000, -1, 69);  //object(vendmach) (1)
	CreateDynamicObject(1775,2469.89990234,2365.80004883,-22.00000000,0.00000000,0.00000000,0.00000000, -1, 69);  //object(cj_sprunk1) (2)
	CreateDynamicObject(1808,2464.80004883,2359.50000000,-23.00000000,0.00000000,0.00000000,0.00000000, -1, 69);  //object(cj_watercooler2) (4)
	CreateDynamicObject(1776,2470.19995117,2361.30004883,-21.89999962,0.00000000,0.00000000,270.00000000, -1, 69);  //object(cj_candyvendor) (2)



	
	CreateDynamicObject(14597,1862.4023438,2418.7119141,21.8237915,0.0000000,0.0000000,0.0000000, -1, 11); //object(paperchase07) (1)
	CreateDynamicObject(14598,1871.8502197,2430.5322266,17.9791908,0.0000000,0.0000000,0.0000000, -1, 11); //object(paperchase_glass) (1)
	CreateDynamicObject(14599,1865.8554688,2418.7148438,21.7466087,0.0000000,0.0000000,0.0000000, -1, 11); //object(paperchase08) (1)
	CreateDynamicObject(14638,1875.5644531,2417.4355469,19.6781273,0.0000000,0.0000000,0.0000000, -1, 11); //object(ab_mafsuitedoor) (1)
	CreateDynamicObject(14638,1875.5609131,2420.4377441,19.6781273,0.0000000,0.0000000,179.9945068, -1, 11); //object(ab_mafsuitedoor) (2)
	CreateDynamicObject(16637,1877.4202881,2417.4765625,21.1860046,0.0000000,0.0000000,270.0000000, -1, 11); //object(ghostgardoor) (1)
	CreateDynamicObject(16637,1877.3958740,2420.3981934,21.1860046,0.0000000,0.0000000,270.0000000, -1, 11); //object(ghostgardoor) (2)
	CreateDynamicObject(16637,1877.4206543,2418.9509277,22.7109928,0.0000000,90.0000000,270.0000000, -1, 11); //object(ghostgardoor) (3)
	CreateDynamicObject(16637,1875.6445312,2418.9169922,21.1859894,0.0000000,0.0000000,179.9945068, -1, 11); //object(ghostgardoor) (4)
	CreateDynamicObject(2010,1866.0786133,2421.3417969,19.8094025,0.0000000,0.0000000,50.0000000, -1, 11); //object(nu_plant3_ofc) (1)
	CreateDynamicObject(2010,1866.0786133,2416.1154785,19.8094025,0.0000000,0.0000000,49.9987793, -1, 11); //object(nu_plant3_ofc) (2)
	CreateDynamicObject(2010,1858.6374512,2421.4396973,19.8094025,0.0000000,0.0000000,0.0000000, -1, 11); //object(nu_plant3_ofc) (3)
	CreateDynamicObject(2010,1858.6374512,2415.9643555,19.8094025,0.0000000,0.0000000,0.0000000, -1, 11); //object(nu_plant3_ofc) (4)
	CreateDynamicObject(2166,1867.2802734,2412.4208984,19.8389320,0.0000000,0.0000000,270.0000000, -1, 11); //object(med_office_desk_2) (1)
	CreateDynamicObject(2163,1872.5820312,2405.1250000,19.8389320,0.0000000,0.0000000,179.9945068, -1, 11); //object(med_office_unit_2) (1)
	CreateDynamicObject(2163,1868.1318359,2405.1250000,19.8389320,0.0000000,0.0000000,179.9945068, -1, 11); //object(med_office_unit_2) (2)
	CreateDynamicObject(2162,1868.1279297,2405.1103516,20.7444954,0.0000000,0.0000000,179.9945068, -1, 11); //object(med_office_unit_1) (1)
	CreateDynamicObject(2167,1873.5397949,2406.4311523,19.8316040,0.0000000,0.0000000,270.0000000, -1, 11); //object(med_office_unit_7) (1)
	CreateDynamicObject(2165,1868.2812500,2410.4531250,19.8389320,0.0000000,0.0000000,270.0000000, -1, 11); //object(med_office_desk_1) (2)
	CreateDynamicObject(2165,1871.6025391,2410.9472656,19.8389320,0.0000000,0.0000000,90.0000000, -1, 11); //object(med_office_desk_1) (3)
	CreateDynamicObject(2166,1872.5898438,2408.9716797,19.8389320,0.0000000,0.0000000,90.0000000, -1, 11); //object(med_office_desk_2) (3)
	CreateDynamicObject(2164,1866.2470703,2406.5224609,19.8406010,0.0000000,0.0000000,90.0000000, -1, 11); //object(med_office_unit_5) (2)
	CreateDynamicObject(2163,1866.2832031,2408.6289062,19.8316040,0.0000000,0.0000000,90.0000000, -1, 11); //object(med_office_unit_2) (3)
	CreateDynamicObject(2201,1872.3994141,2405.1103516,20.7644863,0.0000000,0.0000000,270.0000000, -1, 11); //object(printer_1) (1)
	CreateDynamicObject(2202,1870.5029297,2405.6279297,19.8316040,0.0000000,0.0000000,179.9945068, -1, 11); //object(photocopier_2) (1)
	CreateDynamicObject(2161,1873.6406250,2414.0800781,19.8316040,0.0000000,0.0000000,270.0000000, -1, 11); //object(med_office_unit_4) (1)
	CreateDynamicObject(2167,1866.2666016,2413.5781250,19.8389320,0.0000000,0.0000000,90.0000000, -1, 11); //object(med_office_unit_7) (2)
	CreateDynamicObject(2010,1873.8776855,2421.3417969,19.8094025,0.0000000,0.0000000,49.9987793, -1, 11); //object(nu_plant3_ofc) (5)
	CreateDynamicObject(2010,1873.8781738,2416.1154785,19.8094025,0.0000000,0.0000000,49.9987793, -1, 11); //object(nu_plant3_ofc) (6)
	CreateDynamicObject(1808,1866.4648438,2414.5761719,19.8116436,0.0000000,0.0000000,90.0000000, -1, 11); //object(cj_watercooler2) (1)
	CreateDynamicObject(1714,1866.8049316,2410.8056641,19.8389320,0.0000000,0.0000000,91.9951172, -1, 11); //object(kb_swivelchair1) (1)
	CreateDynamicObject(1714,1873.0020752,2410.6784668,19.8389320,0.0000000,0.0000000,265.9874268, -1, 11); //object(kb_swivelchair1) (2)
	CreateDynamicObject(1502,1869.9548340,2415.3593750,19.8316040,0.0000000,0.0000000,0.0000000, -1, 11); //object(gen_doorint04) (1)
	CreateDynamicObject(1502,1860.5872803,2415.3596191,19.8316040,0.0000000,0.0000000,0.0000000, -1, 11); //object(gen_doorint04) (2)
	CreateDynamicObject(2165,1862.3959961,2409.7106934,19.8389320,0.0000000,0.0000000,0.0000000, -1, 11); //object(med_office_desk_1) (1)
	CreateDynamicObject(2166,1860.4429932,2408.7075195,19.8316040,0.0000000,0.0000000,0.0000000, -1, 11); //object(med_office_desk_2) (2)
	CreateDynamicObject(2164,1860.0045166,2405.1250000,19.8406010,0.0000000,0.0000000,180.0000000, -1, 11); //object(med_office_unit_5) (2)
	CreateDynamicObject(2163,1861.9798584,2405.1250000,19.8389320,0.0000000,0.0000000,179.9945068, -1, 11); //object(med_office_unit_2) (1)
	CreateDynamicObject(2163,1863.8793945,2405.1250000,19.8389320,0.0000000,0.0000000,179.9945068, -1, 11); //object(med_office_unit_2) (1)
	CreateDynamicObject(2167,1865.1136475,2405.1250000,19.8316040,0.0000000,0.0000000,180.0000000, -1, 11); //object(med_office_unit_7) (1)
	CreateDynamicObject(2163,1858.4716797,2406.8344727,19.8389320,0.0000000,0.0000000,90.0000000, -1, 11); //object(med_office_unit_2) (1)
	CreateDynamicObject(2162,1858.4682617,2406.8303223,20.7444954,0.0000000,0.0000000,89.9945068, -1, 11); //object(med_office_unit_1) (1)
	CreateDynamicObject(2164,1865.8193359,2407.5539551,19.8406010,0.0000000,0.0000000,269.9945068, -1, 11); //object(med_office_unit_5) (2)
	CreateDynamicObject(2202,1858.9277344,2411.1164551,19.8316040,0.0000000,0.0000000,89.9945068, -1, 11); //object(photocopier_2) (1)
	CreateDynamicObject(2163,1858.4304199,2409.1608887,19.8389320,0.0000000,0.0000000,90.0000000, -1, 11); //object(med_office_unit_2) (1)
	CreateDynamicObject(1819,1863.1473389,2412.3161621,19.8316040,0.0000000,0.0000000,0.0000000, -1, 11); //object(coffee_swank_4) (1)
	CreateDynamicObject(1703,1865.1640625,2413.9497070,19.8316040,0.0000000,0.0000000,270.0000000, -1, 11); //object(kb_couch02) (1)
	CreateDynamicObject(1724,1863.1478271,2414.6437988,19.8316040,0.0000000,0.0000000,0.0000000, -1, 11); //object(mrk_seating1b) (1)
	CreateDynamicObject(1714,1862.1549072,2408.3337402,19.8316040,0.0000000,0.0000000,179.9969482, -1, 11); //object(kb_swivelchair1) (3)
	CreateDynamicObject(2161,1858.5039062,2413.5429688,19.8316040,0.0000000,0.0000000,90.0000000, -1, 11); //object(med_office_unit_4) (1)
	CreateDynamicObject(2201,1858.4123535,2409.3305664,20.7644863,0.0000000,0.0000000,180.0000000, -1, 11); //object(printer_1) (1)
	CreateDynamicObject(2852,1863.5915527,2412.7890625,20.3472652,0.0000000,0.0000000,0.0000000, -1, 11); //object(gb_bedmags02) (1)
	CreateDynamicObject(1502,1860.5880127,2422.0307617,19.8316040,0.0000000,0.0000000,0.0000000, -1, 11); //object(gen_doorint04) (3)
	CreateDynamicObject(1502,1869.9548340,2422.0366211,19.8316040,0.0000000,0.0000000,0.0000000, -1, 11); //object(gen_doorint04) (4)
	CreateDynamicObject(2258,1853.7572021,2421.5979004,21.9297428,0.0000000,0.0000000,0.0000000, -1, 11); //object(frame_clip_5) (1)
	CreateDynamicObject(2257,1865.8037109,2410.1379395,21.9399815,0.0000000,0.0000000,270.0000000, -1, 11); //object(frame_clip_4) (1)
	CreateDynamicObject(2261,1854.8947754,2416.3588867,21.3507805,0.0000000,0.0000000,180.0000000, -1, 11); //object(frame_slim_2) (1)
	CreateDynamicObject(2262,1851.7586670,2416.3388672,21.4509964,0.0000000,0.0000000,180.0000000, -1, 11); //object(frame_slim_3) (1)
	CreateDynamicObject(2166,1872.5898438,2425.2094727,19.8389320,0.0000000,0.0000000,90.0000000, -1, 11); //object(med_office_desk_2) (3)
	CreateDynamicObject(2165,1871.6025391,2427.1777344,19.8389320,0.0000000,0.0000000,90.0000000, -1, 11); //object(med_office_desk_1) (3)
	CreateDynamicObject(2167,1873.6245117,2424.0144043,19.8316040,0.0000000,0.0000000,270.0000000, -1, 11); //object(med_office_unit_7) (2)
	CreateDynamicObject(1808,1865.5537109,2422.7233887,19.8316040,0.0000000,0.0000000,270.0000000, -1, 11); //object(cj_watercooler2) (1)
	CreateDynamicObject(2165,1868.2812500,2426.4831543,19.8389320,0.0000000,0.0000000,270.0000000, -1, 11); //object(med_office_desk_1) (2)
	CreateDynamicObject(2166,1867.2802734,2428.4399414,19.8389320,0.0000000,0.0000000,270.0000000, -1, 11); //object(med_office_desk_2) (1)
	CreateDynamicObject(2163,1873.6378174,2429.1469727,19.8316040,0.0000000,0.0000000,270.0000000, -1, 11); //object(med_office_unit_2) (3)
	CreateDynamicObject(2164,1873.6070557,2431.2333984,19.8406010,0.0000000,0.0000000,270.0000000, -1, 11); //object(med_office_unit_5) (2)
	CreateDynamicObject(2163,1871.7414551,2432.3027344,19.8316040,0.0000000,0.0000000,0.0000000, -1, 11); //object(med_office_unit_2) (3)
	CreateDynamicObject(2162,1858.4704590,2425.0405273,19.8316040,0.0000000,0.0000000,89.9945068, -1, 11); //object(med_office_unit_1) (1)
	CreateDynamicObject(2202,1869.4068604,2431.8442383,19.8316040,0.0000000,0.0000000,0.0000000, -1, 11); //object(photocopier_2) (1)
	CreateDynamicObject(2163,1867.3916016,2432.3266602,19.8316040,0.0000000,0.0000000,0.0000000, -1, 11); //object(med_office_unit_2) (3)
	CreateDynamicObject(2167,1873.5534668,2407.6547852,19.8316040,0.0000000,0.0000000,270.0000000, -1, 11); //object(med_office_unit_7) (1)
	CreateDynamicObject(2167,1866.2924805,2431.2321777,19.8389320,0.0000000,0.0000000,90.0000000, -1, 11); //object(med_office_unit_7) (2)
	CreateDynamicObject(2167,1866.2814941,2429.8591309,19.8389320,0.0000000,0.0000000,90.0000000, -1, 11); //object(med_office_unit_7) (2)
	CreateDynamicObject(2201,1867.9317627,2431.8588867,20.7644863,0.0000000,0.0000000,270.0000000, -1, 11); //object(printer_1) (1)
	CreateDynamicObject(2161,1866.2918701,2423.2778320,19.8316040,0.0000000,0.0000000,90.0000000, -1, 11); //object(med_office_unit_4) (1)
	CreateDynamicObject(1714,1866.8437500,2426.7275391,19.8389320,0.0000000,0.0000000,89.9951172, -1, 11); //object(kb_swivelchair1) (1)
	CreateDynamicObject(1714,1872.8962402,2426.6562500,19.8389320,0.0000000,0.0000000,267.9876709, -1, 11); //object(kb_swivelchair1) (2)
	CreateDynamicObject(2207,1861.2113037,2429.5856934,19.8389320,0.0000000,0.0000000,0.0000000, -1, 11); //object(med_office7_desk_1) (1)
	CreateDynamicObject(2208,1862.1151123,2429.1794434,19.7389336,0.0000000,0.0000000,270.0000000, -1, 11); //object(med_office7_unit_1) (1)
	CreateDynamicObject(1714,1862.1422119,2431.6743164,19.8316040,0.0000000,0.0000000,0.0000000, -1, 11); //object(kb_swivelchair1) (6)
	CreateDynamicObject(1714,1862.1143799,2424.1518555,19.8316040,0.0000000,0.0000000,180.0000000, -1, 11); //object(kb_swivelchair1) (7)
	CreateDynamicObject(2207,1863.0496826,2426.1154785,19.8389320,0.0000000,0.0000000,180.0000000, -1, 11); //object(med_office7_desk_1) (2)
	CreateDynamicObject(1671,1863.5537109,2428.9948730,20.2918186,0.0000000,0.0000000,276.7500000, -1, 11); //object(swivelchair_a) (1)
	CreateDynamicObject(1671,1863.5355225,2427.9648438,20.2918186,0.0000000,0.0000000,270.0000000, -1, 11); //object(swivelchair_a) (2)
	CreateDynamicObject(1671,1863.5416260,2426.8881836,20.2918186,0.0000000,0.0000000,262.0000000, -1, 11); //object(swivelchair_a) (3)
	CreateDynamicObject(1671,1860.7662354,2426.8693848,20.2918186,0.0000000,0.0000000,95.9964600, -1, 11); //object(swivelchair_a) (4)
	CreateDynamicObject(1671,1860.7607422,2429.0422363,20.2918186,0.0000000,0.0000000,77.9930420, -1, 11); //object(swivelchair_a) (5)
	CreateDynamicObject(1671,1860.7296143,2427.9433594,20.2918186,0.0000000,0.0000000,87.9919434, -1, 11); //object(swivelchair_a) (6)
	CreateDynamicObject(2163,1865.8071289,2431.5397949,19.8316040,0.0000000,0.0000000,270.0000000, -1, 11); //object(med_office_unit_2) (3)
	CreateDynamicObject(2167,1865.8255615,2428.1477051,19.8316040,0.0000000,0.0000000,269.9945068, -1, 11); //object(med_office_unit_7) (2)
	CreateDynamicObject(2164,1865.8217773,2426.8708496,19.8406010,0.0000000,0.0000000,270.0000000, -1, 11); //object(med_office_unit_5) (2)
	CreateDynamicObject(2163,1865.8154297,2424.6325684,19.8316040,0.0000000,0.0000000,270.0000000, -1, 11); //object(med_office_unit_2) (3)
	CreateDynamicObject(2162,1865.8316650,2424.6320801,20.7444954,0.0000000,0.0000000,270.0000000, -1, 11); //object(med_office_unit_1) (1)
	CreateDynamicObject(2167,1865.8320312,2429.3447266,19.8316040,0.0000000,0.0000000,269.9945068, -1, 11); //object(med_office_unit_7) (2)
	CreateDynamicObject(1808,1873.4384766,2422.8593750,19.8116436,0.0000000,0.0000000,270.0000000, -1, 11); //object(cj_watercooler2) (1)
	CreateDynamicObject(2163,1859.6759033,2432.2702637,19.8316040,0.0000000,0.0000000,0.0000000, -1, 11); //object(med_office_unit_2) (3)
	CreateDynamicObject(2164,1858.4881592,2430.2514648,19.8406010,0.0000000,0.0000000,90.0000000, -1, 11); //object(med_office_unit_5) (2)
	CreateDynamicObject(2167,1858.4539795,2428.8947754,19.8389320,0.0000000,0.0000000,90.0000000, -1, 11); //object(med_office_unit_7) (2)
	CreateDynamicObject(2167,1858.4550781,2427.3935547,19.8389320,0.0000000,0.0000000,90.0000000, -1, 11); //object(med_office_unit_7) (2)
	CreateDynamicObject(2162,1871.7500000,2432.3203125,20.7444954,0.0000000,0.0000000,359.9890137, -1, 11); //object(med_office_unit_1) (1)
	CreateDynamicObject(2161,1858.4804688,2423.1499023,19.8316040,0.0000000,0.0000000,90.0000000, -1, 11); //object(med_office_unit_4) (1)
	CreateDynamicObject(2201,1860.2430420,2431.7919922,20.7330189,0.0000000,0.0000000,270.0000000, -1, 11); //object(printer_1) (1)
	CreateDynamicObject(2184,1855.5429688,2417.7097168,19.8316040,0.0000000,0.0000000,90.0000000, -1, 11); //object(med_office6_desk_2) (1)
	CreateDynamicObject(2190,1855.4465332,2419.3056641,20.6073418,0.0000000,0.0000000,260.0000000, -1, 11); //object(pc_1) (1)
	CreateDynamicObject(2894,1855.0969238,2418.7485352,20.6073418,0.0000000,0.0000000,90.0000000, -1, 11); //object(kmb_rhymesbook) (1)
	CreateDynamicObject(2196,1854.8723145,2418.3234863,20.6073418,0.0000000,0.0000000,120.0000000, -1, 11); //object(work_lamp1) (1)
	CreateDynamicObject(2855,1854.9245605,2417.8454590,20.6073418,0.0000000,0.0000000,220.0000000, -1, 11); //object(gb_bedmags05) (1)
	CreateDynamicObject(1714,1853.6146240,2418.7363281,19.8389320,0.0000000,0.0000000,89.9969482, -1, 11); //object(kb_swivelchair1) (3)
	CreateDynamicObject(1715,1861.3294678,2411.4863281,19.8389320,0.0000000,0.0000000,14.0000000, -1, 11); //object(kb_swivelchair2) (1)
	CreateDynamicObject(1715,1862.9056396,2411.4191895,19.8316040,0.0000000,0.0000000,346.0000000, -1, 11); //object(kb_swivelchair2) (2)
	CreateDynamicObject(14548,1673.670043, 1447.932861, 1200.784775,0.0000000,0.0000000,0.000000, -1, 9); //object(kb_swivelchair2) (2)
}


forward SkydiveInteriorChanger(playerid);
public SkydiveInteriorChanger(playerid)
{
	if(!IsPlayerConnected(playerid))
	{
		KillTimer(playerData[playerid][skydiveTimer]);
	}
	else
	{
		if(GetPlayerInterior(playerid) == 9)
		{
			if(!IsPlayerInRangeOfPoint(playerid, 100.0, 1673.670043, 1447.932861, 1200.784775))
			{
				SetPlayerInterior(playerid, 0);
				KillTimer(playerData[playerid][skydiveTimer]);
			}
		}
		else
		{
			KillTimer(playerData[playerid][skydiveTimer]);
		}
	}
	return 1;
}

public getVehicleModelFromName(vname[])
{
	for(new i = 0; i < 213; i++)
	{
		if(strfind(vehicleNames[i], vname, true) != -1)
		{
			return i + 400;
		}
	}

	return -1;
}

public checkSeatStatus(vehicleid, seatid)
{
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(GetPlayerVehicleID(i) == vehicleid && GetPlayerVehicleSeat(i) == seatid)
		{
			return 0;
		}
    }

    return 1;
}
forward CountDown();
public CountDown()
{
     CountDownVar--;
     new str[128];

     format(str, sizeof(str), "%d", CountDownVar);
     GameTextForAll(str, 1500, 3);
     SoundForAll(1056);

	 if(CountDownVar == 0)
	 {
        KillTimer(CountDownTimer);
        SoundForAll(1057);
        GameTextForAll("~y~~h~~h~GO!", 2000, 3);
        CountDownVar = 0;
        for (new i = 0; i<MAX_PLAYERS; i++)
    	{
        	if(IsPlayerConnected(i))
        	{
        		TogglePlayerControllable(i, true);
			}
		}
	 }

     return 1;
}
public sendWantedMessage(playerid, amountAdded)
{
	new message[128];
	format(message, sizeof(message), "{FFDC2E}[WANTED] {FFFFFF}Your wanted level has increased by %i! Your wanted level is now %i!", amountAdded, playerData[playerid][playerWantedLevel]);
	SendClientMessage(playerid, COLOR_WHITE, message);
}

writeInLog(const destinationFile[], stringToWrite[])
{

	new
		logFile[32] = "logs/";

	strcat(logFile, destinationFile);

    if(!fexist(logFile))
    {
        new
			File:fileToCreate = fopen(logFile, io_write);

        fclose(fileToCreate);
    }

    new
        logYear,
        logMonth,
		logDay,

		logHour,
		logMinute,
		logSecond,

		stringForLogging[256];

    getdate(logYear, logMonth, logDay);
    gettime(logHour, logMinute, logSecond);

    format(stringForLogging, 300, "<div id=\"sex\">[%d/%d/%d - %02d:%02d:%d] %s</div>\r\n", logDay, logMonth, logYear, logHour, logMinute, logSecond, stringToWrite);

    new
		File:fileToAppend = fopen(logFile, io_append);

    fwrite(fileToAppend, stringForLogging);
    fclose(fileToAppend);

    return 1;
}

stock FormatNumber(iNum, const szChar[] = ",")
{
    new
        szStr[16]
    ;
    format(szStr, sizeof(szStr), "%d", iNum);

    for(new iLen = strlen(szStr) - 3; iLen > 0; iLen -= 3)
    {
        strins(szStr, szChar, iLen);
    }
    return szStr;
}

stock strtolower(text[])
{
    for(new i; i< 32; i++)
    {
        text[i] = tolower(text[i]);
    }
    return text;
}

stock ClearStats(playerid)
{
	if (playerData[playerid][playerLoggedIn])
	{
		forceRobberyCancel(playerid);

		// Reset main stats
		playerData[playerid][playerLevel] 			= 0;
		playerData[playerid][playerMoney]			= 0;
		playerData[playerid][playerBank]			= 0;
		playerData[playerid][playerScore]			= 0;
		playerData[playerid][playerXP]				= 0;
		playerData[playerid][playerIP]				= 0;
		playerData[playerid][playerInterior]		= 0;
		playerData[playerid][playerVWorld]			= 0;
		playerData[playerid][playerJailTime] 		= 0;
		playerData[playerid][playerMuteTime] 		= 0;
		playerData[playerid][playerCheckpointTime]	= 0;
		playerData[playerid][playerRobTime]			= 0;
		playerData[playerid][playerSafeObj]			= 0;
		playerData[playerid][playerClass]			= 0;
		playerData[playerid][playerWantedLevel]     = 0;
		playerData[playerid][playerVIPLevel]		= 0;
		playerData[playerid][playerRope]			= 0;
		playerData[playerid][playerJailKit]			= 0;
		playerData[playerid][playerScissors]		= 0;
		playerData[playerid][playerButtPlug]		= 0;
		playerData[playerid][playerBiggerPockets]	= 0;
		playerData[playerid][playerSecureWallet]	= 0;
		playerData[playerid][playerCourierLevel]    = 0;
		playerData[playerid][playerBanned]          = 0;
		playerData[playerid][playerLastVehicleID]   = 0;
		playerData[playerid][playerWarnings]        = 0;
		playerData[playerid][playerHelper]			= 0;
		playerData[playerid][playerWeed]			= 0;
		playerData[playerid][playerExplosives]		= 0;
		playerData[playerid][vipWeapon]             = 0;
		playerData[playerid][innocentKills]			= 0;
		playerData[playerid][aInnocentKills]		= 0;
		playerData[playerid][healthInsurance]		= 0;

		// Reset stats
		playerData[playerid][playerKills]			= 0;
		playerData[playerid][playerDeaths]			= 0;
		playerData[playerid][playerRobberies]		= 0;
		playerData[playerid][playerTimesJailed]		= 0;
		playerData[playerid][copArrests]			= 0;
		playerData[playerid][rulesRead]				= 0;
		playerData[playerid][streetRobberies] 		= 0;
		playerData[playerid][streetRapes] 			= 0;
		playerData[playerid][playersTied] 			= 0;
		playerData[playerid][playersKidnapped] 		= 0;
		playerData[playerid][copDetains]			= 0;
		playerData[playerid][copKills]				= 0;
		playerData[playerid][forkliftCompleted]		= 0;
		playerData[playerid][bankRobs]				= 0;
		playerData[playerid][bombsDefused]			= 0;

		// Reset Jobs
		playerData[playerid][lastCarDrop]			= -1;
		playerData[playerid][playerJob]				= -1;

		// Reset ID systems
		playerData[playerid][playerLastTicket] 		= -1;
		playerData[playerid][playerBailTo] 			= -1;
		playerData[playerid][playerBailPrice] 		= -1;
		playerData[playerid][playerAdminJailed] 	= -1;
		playerData[playerid][playerGunOffer] 		= -1;
		playerData[playerid][playerGunDealer] 		= -1;
		playerData[playerid][playerHousePass]       = -1;
		playerData[playerid][lastRecipient]         = -1;
		playerData[playerid][playerCustomSkin]		= -1;
		playerData[playerid][vehicleMenu]			= -1;
		playerData[playerid][playerStoreID]			= 0;
		playerData[playerid][playerCheckID]         = 0;
		playerData[playerid][playerInsideHouse]     = 0;
		playerData[playerid][playerInsideBusiness]  = 0;
		playerData[playerid][adDetected]			= 0;
		playerData[playerid][shotWarnings]			= 0;
		playerData[playerid][cbugWarnings]			= 0;
		playerData[playerid][carSwing]				= 0;

		// Reset Trucking
		if (playerData[playerid][truckingStatus] > 0)
		{
			DestroyDynamicRaceCP(playerData[playerid][truckingCheckpoint]);
		}

		playerData[playerid][truckingStatus]        = -1;
		playerData[playerid][truckingMission]       = -1;

		playerData[playerid][playerMissionCPTime] 	= 0;

		// Reset Forklift
		if (playerData[playerid][forkliftStatus] > 0)
		{
			DestroyObject(playerData[playerid][forkliftObject]);
		}

		playerData[playerid][forkliftStatus]		= -1;
		playerData[playerid][forkliftDamage]		= -1;

		// Reset Bus

		if (playerData[playerid][busStatus] > 0)
		{
			DestroyDynamicRaceCP(playerData[playerid][busCP]);
		}

		playerData[playerid][busStatus] 			= -1;

		// Reset Sweeper

		if (playerData[playerid][sweepStatus] > 0)
		{
			DestroyDynamicRaceCP(playerData[playerid][sweepCP]);
		}

		// Reset medic
		if (playerData[playerid][medicStatus] > 0)
		{
			playerData[playerid][medicStatus] = -1;
			playerData[playerid][medicMission] = -1;

			RemovePlayerMapIcon(playerid, 69);
			DestroyDynamicRaceCP(playerData[playerid][medicCheckpoint]);
		}

		playerData[playerid][sweepStatus] 			= -1;

		// Reset DM
		playerData[playerid][dmStreak] 			= 0;

		// Reset booleans
		playerData[playerid][playerGangID]			= INVALID_GANG_ID;
		playerData[playerid][hasSTD] 				= false;
		playerData[playerid][isInEvent]             = false;
		playerData[playerid][playerPingImmune]      = false;
		playerData[playerid][hasSpawned]            = false;
		playerData[playerid][playerLoggedIn] 		= false;
		playerData[playerid][playerAdminDuty]		= false;
		playerData[playerid][playerCanTaze]			= false;
		playerData[playerid][playerCanCuff]			= false;
		playerData[playerid][playerCanArrest]		= false;
		playerData[playerid][playerCanEMP]			= false;
		playerData[playerid][playerIsTazed]			= false;
		playerData[playerid][playerIsCuffed]		= false;
		playerData[playerid][playerIsInHouse]		= false;
		playerData[playerid][playerHitmarker]		= false;
		playerData[playerid][playerCanRape]			= false;
		playerData[playerid][playerCanRob]			= false;
		playerData[playerid][playerCanRepair]		= false;
		playerData[playerid][adminWeapon]			= false;
		playerData[playerid][pEnterHouse]			= false;
		playerData[playerid][showALog]              = false;
		playerData[playerid][iscourier]             = false;
		playerData[playerid][pmSpy]            		= false;
		playerData[playerid][isBanned]              = false;
		playerData[playerid][playerBeenBanned]      = false;
		playerData[playerid][playerDied]	        = false;
		playerData[playerid][suicide] 				= false;
		playerData[playerid][vipColour]				= false;
		playerData[playerid][isInDM]				= false;
		playerData[playerid][hasBackpack] 			= false;
		playerData[playerid][hasParrot] 			= false;
		playerData[playerid][luckyCharm] 			= false;
		playerData[playerid][weaponSkill]			= false;
		playerData[playerid][playerDefuseKit]		= false;
		playerData[playerid][allowSpec]				= true;
		playerData[playerid][canEscape]				= true;

		playerData[playerid][canAsk] 				= true;
		playerData[playerid][canReport] 			= true;
		playerData[playerid][useAdminName]			= false;

		if (playerData[playerid][vSellTo] != -1)
		{
			// Remove the sale
			new sellto = playerData[playerid][vSellTo];
			playerData[sellto][vBuyFrom] = -1;
			SendClientMessage(sellto, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}The vehicle offer has expired, the seller has quit.");
		}

		if (playerData[playerid][vBuyFrom] != -1)
		{
			// Remove the sale
			new buyfrom = playerData[playerid][vBuyFrom];
			playerData[buyfrom][vSellTo] = -1;
			SendClientMessage(buyfrom, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}The vehicle offer has expired, the buyer has quit.");
		}

		// Progress Bars
		if (GetProgressBarValue(playerData[playerid][breakin]) != INVALID_BAR_VALUE)
		{
			DestroyProgressBar(playerData[playerid][breakin]);
		}

		DestroyProgressBar(playerData[playerid][robbery]);
	}
}

stock randomString(strDest[], strLen = 10)
{
    while(strLen--)
        strDest[strLen] = random(2) ? (random(26) + (random(2) ? 'a' : 'A')) : (random(10) + '0');
}

stock GetVehicleSpeed(vehicleid)
{
    new Float:xPos[3];
    GetVehicleVelocity(vehicleid, xPos[0], xPos[1], xPos[2]);
    return floatround(floatsqroot(xPos[0] * xPos[0] + xPos[1] * xPos[1] + xPos[2] * xPos[2]) * 170.00);
}

stock FindIP(text[])
{
	new strR[255];
	new is1=0;
 	new r=0;
 	while(strlen(text[is1]))
 	{
  	if('0'<=text[is1]<='9')
  	{
 	new is2=is1+1;
  	new p=0;
   	while(p==0)
  	{
   	if('0'<=text[is2]<='9'&&strlen(text[is2])) is2++;
 	else
  	{
   	strmid(strR[r],text,is1,is2,255);
   	if(strval(strR[r])<255) r++;
    is1=is2;
    p=1;
    }
    }
    }
    is1++;
 	}
 	if(r>=4)
 	{
		return true;
 	}
	else
	{
		return false;
	}
}
function GetINIString(file[], result[])
{
    new File:inifile, line[512];
    inifile = fopen(file, io_read);
    if(!inifile)
    {
        printf("Fatal Error: Couldn't open \"%s\"!", file);
        return 0;
    }
    while(fread(inifile, line)) format(result, sizeof(line), "%s", line);
    fclose(inifile);
    return 0;
}

function WriteNIString(file[], string[])
{
    new File:inifile;
    inifile = fopen(file, io_write);
    if(!inifile)
    {
        printf("Fatal Error: Couldn't open \"%s\"!", file);
        return 0;
    }
    fwrite(inifile, string);
    fclose(inifile);
    return 0;
}
stock isNumber(const string[])
{
	for (new i = 0, z = strlen(string); i < z; i++)
	{
		if (string[i] > '9' || string[i] < '0') return 0;
	}
	return 1;
}
stock IsNum(textchar) // Short function to find if a char is a num or not.
{
    if(textchar == '0') return 1;
    if(textchar == '1') return 1;
    if(textchar == '2') return 1;
    if(textchar == '3') return 1;
    if(textchar == '4') return 1;
    if(textchar == '5') return 1;
    if(textchar == '6') return 1;
    if(textchar == '7') return 1;
    if(textchar == '8') return 1;
    if(textchar == '9') return 1;
    return 0;
}

public checkDriveB(playerid)//wait
{
	if(IsPlayerInAnyVehicle(playerid))
	{
		SetPlayerArmedWeapon(playerid, 0);
	}
	return 1;
}
