// cnr_explosives

#define MAX_EXPLOSIVES_PER_PLAYER	10
#define MAX_EXPLOSIVES				MAX_PLAYERS * MAX_EXPLOSIVES_PER_PLAYER

enum eData
{
	explosiveID,
	explosiveOwner,
	explosiveTime,
	explosiveObject,
	explosiveSlot,
	Float:explosivePosition[3],
	Text3D:explosiveLabel
}

new explosiveData[MAX_EXPLOSIVES][eData];

forward flushExplosiveData();
public flushExplosiveData()
{
	for(new i = 0; i < MAX_EXPLOSIVES; i++)
	{
		destroyExplosive(i);
	}
}

forward detonateExplosives(playerid);
public detonateExplosives(playerid)
{
	new count = 0;
	for(new i = 0; i < MAX_EXPLOSIVES; i++)
	{
		if(explosiveData[i][explosiveOwner] == playerid)
		{
			detonateExplosive(playerid, explosiveData[i][explosiveSlot]);
			count++;
		}
	}

	if (count != 0)
	{
		if (playerData[playerid][playerJailTime] < 1)
		{
			givePlayerWanted(playerid, 6);
		}
	}
}

forward detonateExplosive(playerid, playerSlot);
public detonateExplosive(playerid, playerSlot)
{
	if (playerData[playerid][playerJailTime] < 1)
	{
		new found = 0;
		for(new i = 0; i < MAX_EXPLOSIVES; i++)
		{
			if(explosiveData[i][explosiveOwner] == playerid)
			{
				if(explosiveData[i][explosiveSlot] == playerSlot)
				{
					CreateExplosion(explosiveData[i][explosivePosition][0], explosiveData[i][explosivePosition][1], explosiveData[i][explosivePosition][2], 12, 1.0);

					if(GetDistanceBetweenPoints(explosiveData[i][explosivePosition][0], explosiveData[i][explosivePosition][1], explosiveData[i][explosivePosition][2], 221.5049, 113.1785, 999.0156) < 20.0)
					{
						if (!found)
						{
							blowJail(playerid);
						}

						found = 1;
					}
					if(GetDistanceBetweenPoints(explosiveData[i][explosivePosition][0], explosiveData[i][explosivePosition][1], explosiveData[i][explosivePosition][2], 195.112930, 168.018463, 1003.023437) < 20.0)
					{
						if (!found)
						{
							blowJail2(playerid);
						}
						found = 1;
					}
					else if(GetDistanceBetweenPoints(explosiveData[i][explosivePosition][0], explosiveData[i][explosivePosition][1], explosiveData[i][explosivePosition][2], 284.2000, 1787.2654, 512.3663) < 5.0)
					{
						if (!serverInfo[bankBlown]) // The problems
						{
							if (!found)
							{
								KillTimer(bankTimer);
								openBankGate();
							}
						}

						found = 1;
					}
					else if(GetDistanceBetweenPoints(explosiveData[i][explosivePosition][0], explosiveData[i][explosivePosition][1], explosiveData[i][explosivePosition][2], 304.4234, 1787.3000, 513.0000) < 5.0)
					{
						if (!serverInfo[bankBlown])
						{
							if (!found)
							{
								openBankVault();
							}
						}

						found = 1;
					}
					else if(GetDistanceBetweenPoints(explosiveData[i][explosivePosition][0], explosiveData[i][explosivePosition][1], explosiveData[i][explosivePosition][2], 2472.043701, 2370.503906, -51.309658) < 5.0)
					{
						if (!serverInfo[bankBlown2])
						{
							if (!found)
							{
								openBankVault2();
							}
						}
						found = 1;
					}

					destroyExplosive(i);
				}
			}
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{FF0000}[ERROR] {FFFFFF}You cannot detonate explosives whilst in jail.");
	}
}

forward checkPlayerExplosives(playerid);
public checkPlayerExplosives(playerid)
{
	new returnValue = 0;

	for(new i = 0; i < MAX_EXPLOSIVES; i++)
	{
		if(explosiveData[i][explosiveOwner] == playerid)
		{
			returnValue++;
		}
	}

	return returnValue;
}

forward destroyPlayersExplosives(playerid);
public destroyPlayersExplosives(playerid)
{
	for(new i = 0; i < MAX_EXPLOSIVES; i++)
	{
		if(explosiveData[i][explosiveOwner] == playerid)
		{
			destroyExplosive(i);
		}
	}
}


forward findExplosiveSlot();
public findExplosiveSlot()
{
	for(new i = 0; i < MAX_EXPLOSIVES; i++)
	{
		if(explosiveData[i][explosiveOwner] == INVALID_PLAYER_ID)
		{
			return i;
		}
	}

	return INVALID_PLAYER_ID;
}

forward destroyExplosive(explosiveEyeD);
public destroyExplosive(explosiveEyeD)
{
	explosiveData[explosiveEyeD][explosiveOwner] 			= INVALID_PLAYER_ID;
	explosiveData[explosiveEyeD][explosiveSlot]				= INVALID_PLAYER_ID;
	explosiveData[explosiveEyeD][explosiveTime] 			= INVALID_PLAYER_ID;
	explosiveData[explosiveEyeD][explosivePosition][0] 		= 0.0000;
	explosiveData[explosiveEyeD][explosivePosition][1] 		= 0.0000;
	explosiveData[explosiveEyeD][explosivePosition][2]		= 0.0000;
	Delete3DTextLabel(explosiveData[explosiveEyeD][explosiveLabel]);
	DestroyDynamicObject(explosiveData[explosiveEyeD][explosiveObject]);

	return 1;
}

COMMAND:usec4(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(!playerData[playerid][isInEvent])
		{
			if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
			{
				if(playerData[playerid][playerJob] == JOB_TERRORIST)
				{
					if(!playerData[playerid][playerIsCuffed])
					{
						if(!playerData[playerid][playerIsTazed])
						{
							if(!playerData[playerid][playerIsTied])
							{
								if (playerData[playerid][playerJailTime] < 1)
								{
									if(playerData[playerid][playerExplosives] > 0)
									{
										if(checkPlayerExplosives(playerid) < MAX_EXPLOSIVES_PER_PLAYER)
										{
											new slotToUse 		= findExplosiveSlot();
											new individualSlot 	= checkPlayerExplosives(playerid);
											new labelText[128];

											format(labelText, sizeof(labelText), "Planted by %s\nID %i", playerData[playerid][playerNamee], individualSlot);

											explosiveData[slotToUse][explosiveOwner] = playerid;
											explosiveData[slotToUse][explosiveSlot] = individualSlot;
											GetPlayerPos(playerid, explosiveData[slotToUse][explosivePosition][0], explosiveData[slotToUse][explosivePosition][1], explosiveData[slotToUse][explosivePosition][2]);
											explosiveData[slotToUse][explosiveObject] = CreateDynamicObject(1252, explosiveData[slotToUse][explosivePosition][0], explosiveData[slotToUse][explosivePosition][1], (explosiveData[slotToUse][explosivePosition][2] - 0.6), 270.00000, 0.00000, 0.00000);
											explosiveData[slotToUse][explosiveLabel] = Create3DTextLabel(labelText, COLOR_YELLOW, explosiveData[slotToUse][explosivePosition][0], explosiveData[slotToUse][explosivePosition][1], (explosiveData[slotToUse][explosivePosition][2] - 0.5), 30, 0, 0);

											playerData[playerid][playerExplosives]--;
											ApplyAnimation(playerid,"BOMBER","BOM_Plant",4.0,0 ,0,0,0,0,1);
											SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You planted C4. To detonate, press Y or use /detonate.");
										}
										else
										{
											SendClientMessage(playerid, COLOR_WHITE, "{FF0000}[ERROR] {FFFFFF}You cannot place anymore explosives, try detonating one.");
										}
									}
									else
									{
										SendClientMessage(playerid, COLOR_WHITE, "{FF0000}[ERROR] {FFFFFF}You do not have any explosives left to use.");
									}
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{FF0000}[ERROR] {FFFFFF}You cannot perform this action while jailed.");
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{FF0000}[ERROR] {FFFFFF}You cannot perform this action while tied.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{FF0000}[ERROR] {FFFFFF}You cannot perform this action while tazed.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{FF0000}[ERROR] {FFFFFF}You cannot perform this action while cuffed.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{FF0000}[ERROR] {FFFFFF}You need to be a terrorist to perform this action.");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{FF0000}[ERROR] {FFFFFF}You need to be a civilian to perform this action");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{FF0000}[ERROR] {FFFFFF}You cannot perform this action while in an event.");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{FF0000}[ERROR] {FFFFFF}You need to be logged in to use commands.");
	}

	return 1;
}

COMMAND:detonate(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(!playerData[playerid][isInEvent])
		{
			if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
			{
				if(playerData[playerid][playerJob] == JOB_TERRORIST)
				{
					if(!playerData[playerid][playerIsCuffed])
					{
						if(!playerData[playerid][playerIsTazed])
						{
							if(!playerData[playerid][playerIsTied])
							{
								new explosivesID, count = 0;
								if(!sscanf(params, "i", explosivesID))
								{
									for(new i = 0; i < MAX_EXPLOSIVES; i++)
									{
										if(explosiveData[i][explosiveOwner] == playerid)
										{
											if(explosiveData[i][explosiveSlot] == explosivesID)
											{
												detonateExplosive(playerid, explosivesID);
												count++;
											}
										}
									}
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"detonate <explosives_id>\"");
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{FF0000}[ERROR] {FFFFFF}You cannot perform this action while tied.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{FF0000}[ERROR] {FFFFFF}You cannot perform this action while tazed.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{FF0000}[ERROR] {FFFFFF}You cannot perform this action while cuffed.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{FF0000}[ERROR] {FFFFFF}You need to be a terrorist to perform this action.");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{FF0000}[ERROR] {FFFFFF}You need to be a civilian to perform this action");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{FF0000}[ERROR] {FFFFFF}You cannot perform this action while in an event.");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{FF0000}[ERROR] {FFFFFF}You need to be logged in to use commands.");
	}

	return 1;
}

COMMAND:defuse(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(!playerData[playerid][isInEvent])
		{
			if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
			{
				if(!playerData[playerid][playerIsCuffed])
				{
					if(!playerData[playerid][playerIsTazed])
					{
						if(!playerData[playerid][playerIsTied])
						{
							new bool:anyLocated = false;
							for(new i = 0; i < MAX_EXPLOSIVES; i++)
							{
								if(IsPlayerInRangeOfPoint(playerid, 5.0, explosiveData[i][explosivePosition][0], explosiveData[i][explosivePosition][1], explosiveData[i][explosivePosition][2]))
								{
									SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You're now attempting to defuse the C4.");
									ApplyAnimation(playerid, "BOMBER", "BOM_PLANT_LOOP", 4.0, 1, 0, 0, 0, -1);
									SetTimerEx("DefuseC4", 3000, false, "ii", playerid, i);
									anyLocated = true;
									playerData[playerid][playerUsingAnim] = true;
									//TogglePlayerControllable(playerid, 0);
									break;
								}
							}

							if(!anyLocated)
							{
								SendClientMessage(playerid, COLOR_WHITE, "{FF0000}[ERROR] {FFFFFF}You are not in the proximity of any C4.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{FF0000}[ERROR] {FFFFFF}You cannot perform this action while tied.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{FF0000}[ERROR] {FFFFFF}You cannot perform this action while tazed.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{FF0000}[ERROR] {FFFFFF}You cannot perform this action while cuffed.");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{FF0000}[ERROR] {FFFFFF}You need to be a civilian to perform this action");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{FF0000}[ERROR] {FFFFFF}You cannot perform this action while in an event.");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{FF0000}[ERROR] {FFFFFF}You need to be logged in to use commands.");
	}

	return 1;
}

forward DefuseC4(playerid, idOfExplosive);
public DefuseC4(playerid, idOfExplosive)
{
	new defuseMessage[256];

	//TogglePlayerControllable(playerid, 1);

	if(playerData[playerid][playerDefuseKit])
	{
		format(defuseMessage, sizeof(defuseMessage), "{B7B7B7}[SERVER] {FFFFFF}You have defused an explosive device belonging to %s", playerData[explosiveData[idOfExplosive][explosiveOwner]][playerNamee]);
		SendClientMessage(playerid, COLOR_WHITE, defuseMessage);
		destroyExplosive(idOfExplosive);

		defuseSuccess(playerid);
	}
	else
	{
		new allahuAkbar = random(3);

		switch(allahuAkbar)
		{
			case 0 .. 1:
			{
				format(defuseMessage, sizeof(defuseMessage), "{B7B7B7}[SERVER] {FFFFFF}Oh no! You cut the wrong wire and %s's explosive blew up in your face.", playerData[explosiveData[idOfExplosive][explosiveOwner]][playerNamee]);
				SendClientMessage(playerid, COLOR_WHITE, defuseMessage);
				detonateExplosive(explosiveData[idOfExplosive][explosiveOwner], explosiveData[idOfExplosive][explosiveSlot]);
			}

			case 2:
			{
				format(defuseMessage, sizeof(defuseMessage), "{B7B7B7}[SERVER] {FFFFFF}You have defused an explosive device belonging to %s", playerData[explosiveData[idOfExplosive][explosiveOwner]][playerNamee]);
				SendClientMessage(playerid, COLOR_WHITE, defuseMessage);
				destroyExplosive(idOfExplosive);

				defuseSuccess(playerid);
			}
		}
	}

	ClearAnimations(playerid);
	playerData[playerid][playerUsingAnim] = false;
}

forward defuseSuccess(playerid);
public defuseSuccess(playerid)
{
	playerData[playerid][bombsDefused]++;

	if (playerData[playerid][bombsDefused] == 1)
	{
		disableAchieve(playerid);
		PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
		PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
		PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
		PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

		PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "Bombs Away");
		PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "You defused your first bomb!");
		PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);

		playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 6000, false, "i", playerid);

		playerGiveXP(playerid, 25);
		playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
		SetPlayerScore(playerid, playerData[playerid][playerScore]);
	}

	if (playerData[playerid][bombsDefused] == 10)
	{
		disableAchieve(playerid);
		PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
		PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
		PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
		PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

		PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "Worth It");
		PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "How many lives were sacrificed to earn this?");
		PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);

		playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 6000, false, "i", playerid);

		playerGiveXP(playerid, 25);
		playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
		SetPlayerScore(playerid, playerData[playerid][playerScore]);
	}
}
forward openBankGate();
public openBankGate()
{
	if (!serverInfo[bankGateBlown])
	{
		SetObjectPos(bankGate, -1968.447753, 518.707641, 1241.303710);
		SetObjectRot(bankGate, 96.100021, -83.099929, 39.400005);

		serverInfo[bankGateBlown] = true;
		serverInfo[bankTime] = 30;
		bankTimer = SetTimer("bankCountdown", 1000, true);
		for (new i=0; i<MAX_PLAYERS; i++)
		{
			if (playerData[i][playerClass] == CLASS_POLICE || playerData[i][playerClass] == CLASS_ARMY || playerData[i][playerClass] == CLASS_CIA || playerData[i][playerClass] == CLASS_FBI)
			{
				new radio[100];
				format(radio, sizeof(radio), "{3E7EFF}<Police Radio> {FFFFFF}ALERT: Oh shit, Guys there are many criminals at the bank!!!");
				SendClientMessage(i, COLOR_WHITE, radio);
			}
		}

		SendClientMessageToAll(COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}The criminals has blowen San Fierro Bank!");
	}
}
forward openBankVault();
public openBankVault()
{
	if (!serverInfo[bankVaultBlown])
	{
		SetObjectPos(bankVault, -480.431610, -190.076736, 973.513061);
		SetObjectRot(bankVault, -0.699994, 0.400000, 40.399925);
		serverInfo[bankVaultBlown] = 1;
        serverInfo[bankBlown] = true; //IK
	}
}

forward openBankVault2();
public openBankVault2()
{
	if (!serverInfo[bankVaultBlown2])
	{
		DestroyDynamicObject(bankVault2);
		SetTimer("checkBank", 30000, false);
		serverInfo[bankVaultBlown2] = 1;
        serverInfo[bankBlown2] = true;
		for (new i=0; i<MAX_PLAYERS; i++)
		{
			if (playerData[i][playerClass] == CLASS_POLICE || playerData[i][playerClass] == CLASS_ARMY || playerData[i][playerClass] == CLASS_CIA || playerData[i][playerClass] == CLASS_FBI)
			{
				new radio[100];
				format(radio, sizeof(radio), "{3E7EFF}<Police Radio> {FFFFFF}ALERT: Oh shit, Guys there are many criminals at the las venturas bank!!!");
				SendClientMessage(i, COLOR_WHITE, radio);
			}
		}
		SendClientMessageToAll(COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}The criminals has blowen Las Venturas Bank, safe your money!");
	}
}

forward checkBank();
public checkBank()
{	
	new found = false;
	if(serverInfo[bankBlown2])
	{
		foreach(new z : Player)
		{
			if(GetPlayerInterior(z) == 69)
				found = true;
		}
		
		if(!found)
		{
			serverInfo[bankVaultBlown2] = false;
			serverInfo[bankBlown2] = false;
			bankVault2 = CreateDynamicObject(2634, 2472.043701, 2370.503906, -51.309658, 0.00000000,0.00000000, 0.00000000, -1, 69);  //object(ab_vaultdoor) (1)
		}
		else
		{
			SetTimer("checkBank", 30000, false);
		}
	}
	else
	{
		return 1;
	}
	return 1;
}

forward closeBankGate();
public closeBankGate()
{
    serverInfo[bankGateBlown] = false;
	SetObjectPos(bankGate, 284.2000, 1787.2654, 512.3663);
	SetObjectRot(bankGate, 0.000000, 0.000000, 90.000000);
}
forward closeBankVault();
public closeBankVault()
{
    serverInfo[bankVaultBlown] = false;
	SetObjectPos(bankVault, 304.4234, 1787.3000, 513.0000);
	SetObjectRot(bankVault, 0.000000, 0.000000, 90.000000);
}
forward bankCountdown();
public bankCountdown()
{
	new bool:found = false;
	if(serverInfo[bankTime] >= 1)
	{
		serverInfo[bankTime]--;
 	}

	if (serverInfo[bankTime] == 0)
	{
		for(new i = 0; i < MAX_PLAYERS; i++)
		{
			if (GetPlayerVirtualWorld(i) == 32)
			{
			    found = true;
			    serverInfo[bankTime] = 30;
			    break;
				/*if (serverInfo[bankTime] != 0)
				{
					// Show TD
					new additNumber[30];
					if (serverInfo[bankTime] < 10)
					{
						additNumber = "0";
					}
					else
					{
						additNumber = "";
					}

					new timeLeft[200];
					format(timeLeft, sizeof(timeLeft), "LOCK DOWN IN ~n~~r~0:%s%i", additNumber, serverInfo[bankTime]);

					TextDrawSetString(bankTD, timeLeft);
					TextDrawShowForPlayer(i, bankTD);
				}*/
			}
		}
	}

 	if (!found && serverInfo[bankTime] == 0)
	{
		print("[DEBUG]Bank Closed Now!!!");
		KillTimer(bankTimer);
		closeBankVault();
		closeBankGate();
		serverInfo[bankBlown] = false;
		serverInfo[bankTime] = 30;
		/*
        openBankTimer = SetTimer("openBank", 2000, true);

		for(new i = 0; i < MAX_PLAYERS; i++)
		{
			TextDrawHideForPlayer(i, bankTD);

			new Float:x, Float:y, Float:z;
			GetPlayerPos(i, x, y, z);

			if (GetPlayerInterior(i) == 3 && playerData[i][lastEnteredID] != 33)
			{
				if (y > -2012.9778 && z < 977.0195)
				{
					// Spawn
					new rand = random(5);
					switch (rand)
					{
						case 0:
						{
							SetPlayerPos(i, -1503.3032, 925.2875, 7.1875);
						}
						case 1:
						{
							SetPlayerPos(i, -1503.5000, 918.5022, 7.1875);
						}
						case 2:
						{
							SetPlayerPos(i, -1503.7100, 911.2618, 7.1875);
						}
						case 3:
						{
							SetPlayerPos(i, -1497.5745, 909.5957, 7.1875);
						}
						case 4:
						{
							SetPlayerPos(i, -1497.5004, 929.4600, 7.1875);
						}
						case 5:
						{
							SetPlayerPos(i, -1501.6885, 936.8543, 7.1875);
						}
					}

					SetPlayerInterior(i, 0);
					SetPlayerVirtualWorld(i, 0);
				}
			}
		}*/
	}
}

COMMAND:openbank(playerid, params[])
{
	if (playerData[playerid][playerLevel] >= 5)
	{
	    if(!serverInfo[bankBlown])
	    {
			KillTimer(openBankTimer);
			openBankGate();
			openBankVault();
			serverInfo[bankBlown] = true;
			serverInfo[bankGateBlown] = true;
			serverInfo[bankVaultBlown] = true;
			SendClientMessage(playerid, COLOR_WHITE, "Bank now robbable again");
		}
		else
		{
		    SendClientMessage(playerid, COLOR_WHITE, "Bank already opened");
		}
	}

	return 1;
}
