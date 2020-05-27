COMMAND:bruteforce(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
  	    if(playerData[playerid][playerClass] == CLASS_FBI)
  	    {
			closeDialogs(playerid);

			if (playerData[playerid][canBreakIn])
			{
				houseBreakin(playerid);
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}Please wait before breaking into another property.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}This command can only be used by the FBI class!");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}

	return 1;
}
COMMAND:uncuff(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerClass] == CLASS_POLICE || playerData[playerid][playerClass] == CLASS_ARMY || playerData[playerid][playerClass] == CLASS_CIA || playerData[playerid][playerClass] == CLASS_FBI || playerData[playerid][playerClass] == CLASS_SECRETSERVICE || playerData[playerid][playerClass] == CLASS_SECRETSERVICE)
		{
			new
				otherID,
				message[128],
				message2[128]
			;

			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}Usage: \"uncuff <playerid>\"");
			}
			else
			{
				if (playerData[otherID][playerIsCuffed])
				{
					format(message, sizeof(message), "{2BBBFB}[SERVER] {FFFFFF}You have un-cuffed {FFDC2E}%s(%i).", playerData[otherID][playerNamee], otherID);
					SendClientMessage(playerid, COLOR_WHITE, message);

					format(message2, sizeof(message2), "{2BBBFB}[INFO] {FFFFFF}You have been uncuffed by {FFDC2E}%s(%i).", playerData[playerid][playerNamee], playerid);
					SendClientMessage(otherID, COLOR_WHITE, message2);

					playerData[otherID][playerIsCuffed] = false;

					SetPlayerSpecialAction(otherID, SPECIAL_ACTION_NONE);
					KillTimer(playerData[otherID][uncuffTimer]);
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}That player is not cuffed.");
				}
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}This command can only be used by LEO classes.");
	}

	return 1;
}
COMMAND:p(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
  	    if(playerData[playerid][playerClass] == CLASS_POLICE || playerData[playerid][playerClass] == CLASS_ARMY || playerData[playerid][playerClass] == CLASS_CIA || playerData[playerid][playerClass] == CLASS_FBI || playerData[playerid][playerClass] == CLASS_SECRETSERVICE || playerData[playerid][playerClass] == CLASS_SECRETSERVICE)
  	    {
            // Command for police to arrest
            new message[120];
            if(sscanf(params, "s[60]", message))
            {
                // Invalid command syntax
                SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}Usage: \"p <message>\"");
            }
            else
            {
				for (new i=0; i<MAX_PLAYERS; i++)
				{
					if (playerData[i][playerClass] == CLASS_POLICE || playerData[i][playerClass] == CLASS_ARMY || playerData[i][playerClass] == CLASS_CIA || playerData[i][playerClass] == CLASS_FBI || playerData[i][playerClass] == CLASS_SECRETSERVICE)
					{
						new radio[100];
						format(radio, sizeof(radio), "{3E7EFF}<Police Radio> {FFFFFF}%s(%i): %s", playerData[playerid][playerNamee], playerid, message);
						SendClientMessage(i, COLOR_WHITE, radio);
					}
				}
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}This command can only be used by LEO classes.");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
	return 1;
}

COMMAND:army(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
  	    if(playerData[playerid][playerClass] == CLASS_ARMY)
  	    {
            new message[120];
            if(sscanf(params, "s[60]", message))
            {
                // Invalid command syntax
                SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}Usage: \"army <message>\"");
            }
            else
            {
				for (new i=0; i < MAX_PLAYERS; i++)
				{
					if (playerData[i][playerClass] == CLASS_ARMY)
					{
						new radio[100];
						format(radio, sizeof(radio), "{31B404}<Army Radio> {FFFFFF}%s(%i): %s", playerData[playerid][playerNamee], playerid, message);
						SendClientMessage(i, COLOR_WHITE, radio);
					}
				}
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}This command can only be used by LEO classes.");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
	return 1;
}

COMMAND:locate(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
  	    if(playerData[playerid][playerClass] == CLASS_CIA)
  	    {
            // Command for police to locate
            new otherPlayer;
            if(sscanf(params, "u", otherPlayer))
            {
                // Invalid command syntax
                SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}Usage: \"locate <playerID>\"");
            }
            else
            {
				if(IsPlayerConnected(otherPlayer))
				{
					if(playerData[otherPlayer][playerLoggedIn])
					{
						if(playerData[otherPlayer][playerClass] == CLASS_CIVILIAN || playerData[otherPlayer][playerClass] == CLASS_MEDIC)
						{
							if (GetPlayerInterior(otherPlayer) == 0)
							{
								if (playerData[otherPlayer][hasSpawned])
								{
									new zone[MAX_ZONE_NAME], string[300];
									GetPlayer2DZone(otherPlayer, zone, MAX_ZONE_NAME);

									format(string, sizeof(string), "{FFDC2E}[LOCATE] {FFFFFF}%s(%i) is presently near {FFDC2E}%s", playerData[otherPlayer][playerNamee], otherPlayer, zone);
									SendClientMessage(playerid, COLOR_WHITE, string);
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}That player hasn't spawned yet.");
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}That player is currently inside a building.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You cannot locate a law enforcement officer.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}The player your trying to warrant is not logged in.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}The player your trying to ticket isn't connected.");
				}
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}This command can only be used by the CIA class!");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}

	return 1;
}

COMMAND:undercover(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
  	    if(playerData[playerid][playerClass] == CLASS_POLICE)
  	    {
			if(IsPlayerInDynamicCP(playerid, PoliceCP[0]) || IsPlayerInDynamicCP(playerid, PoliceCP[1]))
			{
				if(playerData[playerid][playerXP] >= 2500)
				{
					// Dialog
					ShowPlayerDialog(playerid, DIALOG_UNDERCOVER, DIALOG_STYLE_LIST, "Undercover Skin Selector", "Male Skin 1 \nMale Skin 2 \nMale Skin 3 \nFemale Skin 1 \nFemale Skin 2 \nFemale Skin 3", "Go", "Cancel");
					playerData[playerid][playerCustomSkin] = GetPlayerSkin(playerid);
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You need 2,500 XP to become an undercover LEO.");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You must be inside the checkpoint inside the SFPD garage.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}This command can only be used by the police class!");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
	return 1;
}

COMMAND:iw(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
  	    SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}This command has been removed. Players automatically gain a wanted level upon shooting you.");
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}

    return 1;
}


COMMAND:issuewarrant(playerid, params[])
{
	return cmd_iw(playerid, params);
}

COMMAND:bail(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
  	    if(playerData[playerid][playerClass] == CLASS_POLICE || playerData[playerid][playerClass] == CLASS_ARMY || playerData[playerid][playerClass] == CLASS_CIA || playerData[playerid][playerClass] == CLASS_FBI || playerData[playerid][playerClass] == CLASS_SECRETSERVICE || playerData[playerid][playerClass] == CLASS_SECRETSERVICE)
  	    {
            // Command for police to arrest
            new otherPlayer, message[200];
            if(sscanf(params, "u", otherPlayer))
            {
                // Invalid command syntax
                SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}Usage: \"bail <playerID>\"");
            }
            else
            {
				if(IsPlayerConnected(otherPlayer))
				{
					if(playerData[otherPlayer][playerLoggedIn])
					{
						if(playerData[otherPlayer][playerJailTime] > 1)
						{
							if(otherPlayer != playerid)
							{
									if(playerData[otherPlayer][playerAdminJailed] != 1)
									{
										if(bo[playerid] != 1)
										{
											// Calculate the bail price
											new bail = playerData[otherPlayer][playerJailTime] * 100;

											// Set-up some variables (reset on spawn)
											playerData[otherPlayer][playerBailTo] = playerid;
											playerData[otherPlayer][playerBailPrice] = playerData[otherPlayer][playerJailTime] * 100;

											// Send the player a message with the bail amount enclosed
											format(message, sizeof(message), "{58D3F7}[BAIL] {FFFFFF}%s(%i) has offered to give you bail for {FFDC2E}$%s {FFFFFF}(/acceptbail)", playerData[playerid][playerNamee], playerid, FormatNumber(bail));
											SendClientMessage(otherPlayer, COLOR_WHITE, message);

											// Send the LEO a message
											SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[BAIL] {FFFFFF}Your bail offer has been sent.");
										}
										else
										{
											// The has disabled bail offers
											SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}This player has disabled bail offers, you cannot bail them.");
										}
								   }
						    	   else
								   {
									// The player is admin jailed and cannot be bailed
									SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}This player has been admin jailed and cannot be bailed.");
								  }
							}
							else
							{
								// Cant send a bail offer to yourself
								SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You cannot send a bail offer to yourself.");
							}
						}
						else
						{
							// Jail time is less than 10 seconds
							SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}This player is not jailed.");
						}
					}
					else
					{
						// Player is not logged in
						SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}This player is not logged in.");
					}
				}
				else
				{
					// Player is not online
					SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}This player is not online.");
				}
			}
        }
        else
        {
            // Player is not police
            SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}This command can only be used by the LEO classes.");
        }
    }
    else
    {
        SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You must be logged in to use commands.");
    }

	return 1;
}

COMMAND:arrest(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
  	    if(playerData[playerid][playerClass] == CLASS_POLICE || playerData[playerid][playerClass] == CLASS_ARMY || playerData[playerid][playerClass] == CLASS_CIA || playerData[playerid][playerClass] == CLASS_FBI || playerData[playerid][playerClass] == CLASS_SECRETSERVICE || playerData[playerid][playerClass] == CLASS_SECRETSERVICE)
  	    {
            // Command for police to arrest
            new otherPlayer, jailedBy[24], Name[24], payout[128];
            if(sscanf(params, "u", otherPlayer))
            {
                // Invalid command syntax
                SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}Usage: \"arrest <playerID>\"");
            }
            else
            {
				if(IsPlayerConnected(otherPlayer))
				{
					if(playerData[otherPlayer][playerLoggedIn])
					{
						if(playerData[otherPlayer][playerClass] == CLASS_CIVILIAN || playerData[otherPlayer][playerClass] == CLASS_MEDIC)
						{
							// Check if the other player has a wanted level
							if(playerData[otherPlayer][playerWantedLevel] >= 6)
							{
								// Check if the player is in jail
								if(playerData[otherPlayer][playerJailTime] == 0 && playerData[playerid][playerJailTime] == 0)
								{
									if(isPlayerInRangeOfPlayer(playerid, otherPlayer, 4.0))
									{
										// If the player is not performing administrative duties
										if (!playerData[otherPlayer][playerAdminDuty])
										{
											// If OTHER player is in a vehicle
											if(!IsPlayerInAnyVehicle(otherPlayer))
											{
												// If POLICEMAN is in a vehicle
												if(!IsPlayerInAnyVehicle(playerid))
												{
													// Check if the player is cuffed
													if(playerData[otherPlayer][playerIsCuffed])
													{
														// Check if the player can arrest someone
														if(playerData[playerid][playerCanArrest])
														{
															if(!playerData[playerid][playerIsTied])
															{
																ClearAnimations(otherPlayer);

																GetPlayerName(playerid, jailedBy, sizeof(Name));
																GetPlayerName(otherPlayer, Name, sizeof(Name));

																new totalTime = playerData[otherPlayer][playerWantedLevel] * 5 / 2;

																// Police cannot arrest for 5 seconds
																playerData[playerid][playerCanArrest] = true;

																// Set the otherPlayer's isCuffed to 0
																playerData[otherPlayer][playerIsCuffed] = false;
																KillTimer(playerData[otherPlayer][uncuffTimer]);

																// Now we'll calculate the LEO's earnings
																new totalEarnings = playerData[otherPlayer][playerWantedLevel] * 110;

																// Disable special action
																SetPlayerSpecialAction(otherPlayer, SPECIAL_ACTION_NONE);

																// Toggle controllable
																TogglePlayerControllable(otherPlayer, true);

																// Remove wanted level
																SetPlayerWantedLevel(otherPlayer, 0);
																playerData[otherPlayer][playerWantedLevel] = 0;
																playerData[otherPlayer][playerTimesJailed] = playerData[otherPlayer][playerTimesJailed] + 1;

																// Jail the player
																sendPlayerJail(otherPlayer, totalTime, playerid, 1);
																newPlayerColour(otherPlayer);

																// Show LEO their earnings
																format(payout, sizeof(payout), "{FFDC2E}[ARREST] {FFFFFF}You earnt {FFDC2E}$%s {FFFFFF}for arresting %s(%i)", FormatNumber(totalEarnings), Name, otherPlayer);
																SendClientMessage(playerid, COLOR_WHITE, payout);
																playerGiveMoney(playerid, totalEarnings);
																playerGiveXP(playerid, 10);
																playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
																SetPlayerScore(playerid, playerData[playerid][playerScore]);
																playerData[playerid][copArrests] = playerData[playerid][copArrests] + 1;

																if (playerData[playerid][copArrests] == 1)
																{
																	disableAchieve(playerid);
																	PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
																	PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
																	PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
																	PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

																	PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "Fresh Out Of The Academy");
																	PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "You arrested your first crook.");
																	PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);

																	playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 8000, false, "i", playerid);

																	playerGiveXP(playerid, 25);
																	playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
																	SetPlayerScore(playerid, playerData[playerid][playerScore]);
																}
																else if (playerData[playerid][copArrests] == 20)
																{
																	disableAchieve(playerid);
																	PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
																	PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
																	PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
																	PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

																	PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "Deputy Dog");
																	PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "You arrested 20 crooks.");
																	PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);

																	playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 8000, false, "i", playerid);

																	playerGiveXP(playerid, 25);
																	playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
																	SetPlayerScore(playerid, playerData[playerid][playerScore]);
																}
																else if (playerData[playerid][copArrests] == 50)
																{
																	disableAchieve(playerid);
																	PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
																	PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
																	PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
																	PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

																	PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "Detective Inspector");
																	PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "You arrested 50 crooks.");
																	PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);

																	playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 8000, false, "i", playerid);

																	playerGiveXP(playerid, 25);
																	playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
																	SetPlayerScore(playerid, playerData[playerid][playerScore]);
																}
																else if (playerData[playerid][copArrests] == 100)
																{
																	disableAchieve(playerid);
																	PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
																	PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
																	PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
																	PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

																	PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "Police Sergeant");
																	PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "You arrested 100 crooks.");
																	PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);

																	playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 8000, false, "i", playerid);

																	playerGiveXP(playerid, 25);
																	playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
																	SetPlayerScore(playerid, playerData[playerid][playerScore]);
																}

																// XP/SCORE AWARD
																playerGiveXP(playerid, 20);
																playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
																SetPlayerScore(playerid, playerData[playerid][playerScore]);

																new loggingString[256];
																format(loggingString, sizeof(loggingString), "%s arrested %s for $%s .", playerData[playerid][playerNamee], playerData[otherPlayer][playerNamee], FormatNumber(totalEarnings));
																writeInLog("arrestLog.html", loggingString);
															}
															else
															{
																SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You cannot do this whilst tied.");
															}
														}
														else
														{
															// Cannot cuff again yet...
															SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}Please wait before arresting.");
														}
													}
													else
													{
														// The player is already cuffed
														SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You must /cuff the player before attempting to /arrest.");
													}
												}
												else
												{
													// Player is in vehicle
													SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You cannot arrest people while you are in a vehicle.");
												}
											}
											else
											{
												// Other player is in a vehicle
												SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}The player you're trying to arrest is in a vehicle.");
											}
										}
										else
										{
											// Cannot arrest an admin on duty
											SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}That player is currently performing admin duties and cannot be arrested!");
										}
									}
									else
									{
										// Not in range of player
										SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You are not close enough to that player.");
									}
								}
								else
								{
									// Player is in jail
									SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You cannot arrest people when they're already jailed or when you are jailed.");
								}
							}
							else
							{
								// Cannot cuff a cop/cia/fbi
								SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}This player does not have a high enough wanted level.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You cannot arrest law enforcement officers.");
						}
					}
					else
					{
						// Cannot cuff players who are not logged in.
						SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You cannot cuff players who are not logged in.");
					}
				}
				else
				{
					// Cannot cuff players who are not connected.
					SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}That player is not connected.");
				}
            }
        }
        else
        {
            // Player is not police
            SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}This command can only be used by the LEO classes.");
        }
    }
    else
    {
        SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You must be logged in to use commands.");
    }
    return 1;
}

COMMAND:ar(playerid, params[])
{
	return cmd_arrest(playerid, params);
}

COMMAND:cuff(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
  	    if(playerData[playerid][playerClass] == CLASS_POLICE || playerData[playerid][playerClass] == CLASS_ARMY || playerData[playerid][playerClass] == CLASS_CIA || playerData[playerid][playerClass] == CLASS_FBI || playerData[playerid][playerClass] == CLASS_SECRETSERVICE)
  	    {
            // Command for police to cuff
            new otherPlayer, cuffedBy[24], Name[24], pCuff[250], lCuff[250];
            if(sscanf(params, "u", otherPlayer))
            {
                // Invalid command syntax
                SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}Usage: \"cuff <playerID>\"");
            }
            else
            {
				if(IsPlayerConnected(otherPlayer))
				{
					if(playerData[otherPlayer][playerLoggedIn])
					{
						if(playerData[otherPlayer][playerClass] == CLASS_CIVILIAN || playerData[otherPlayer][playerClass] == CLASS_MEDIC)
						{
							// Check if the other player has a wanted level
							if(playerData[otherPlayer][playerWantedLevel] >= 6)
							{
								// Check if the player is in jail
								if (playerData[playerid][playerJailTime] == 0 && playerData[otherPlayer][playerJailTime] == 0)
								{
									if(isPlayerInRangeOfPlayer(playerid, otherPlayer, 4.0))
									{
										// If the player is not performing administrative duties
										if (!playerData[otherPlayer][playerAdminDuty])
										{
											// If OTHER player is in a vehicle
											if(!IsPlayerInAnyVehicle(otherPlayer))
											{
												// If POLICEMAN is in a vehicle
												if(!IsPlayerInAnyVehicle(playerid))
												{
													// Check if the player is already cuffed
													if(!playerData[otherPlayer][playerIsCuffed])
													{
														// Check if the player can cuff someone
														if(playerData[playerid][playerCanCuff])
														{
															if(!playerData[playerid][playerIsTied])
															{
																ClearAnimations(otherPlayer);

																GetPlayerName(playerid, cuffedBy, sizeof(Name));
																GetPlayerName(otherPlayer, Name, sizeof(Name));

																// Cuff player
																format(pCuff, sizeof(pCuff), "{FFDC2E}[CUFFED] {FFFFFF}You have been cuffed by %s(%i)", cuffedBy, playerid);
																SendClientMessage(otherPlayer, COLOR_WHITE, pCuff);

																format(lCuff, sizeof(lCuff), "{FFDC2E}[CUFFED] {FFFFFF}You have placed cuffs on %s(%i)", Name, otherPlayer);
																SendClientMessage(playerid, COLOR_WHITE, lCuff);

																SetPlayerSpecialAction(otherPlayer, SPECIAL_ACTION_CUFFED);

																// Set timer to expire and uncuff player (10 seconds)
																playerData[otherPlayer][uncuffTimer] = SetTimerEx("uncuff", 60000, false, "i", otherPlayer);
																playerData[playerid][recuffTimer] = SetTimerEx("recuff", 5000, false, "i", playerid);
																SetTimerEx("enablearrest", 1000, false, "d", playerid);
																playerData[playerid][playerCanArrest] = false;

																// Police cannot cuff for 5 seconds
																playerData[playerid][playerCanCuff] = false;

																// Set the otherPlayer's isCuffed to 1
																playerData[otherPlayer][playerIsCuffed] = true;

																if (playerData[otherPlayer][playerIsTied])
																{
																	playerData[otherPlayer][playerIsTied] = false;
																	KillTimer(playerData[otherPlayer][untieTimer]);
																}
															}
															else
															{
																SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You cannot do this whilst tied.");
															}
														}
														else
														{
															// Cannot cuff again yet...
															SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}Please wait before cuffing a player again.");
														}
													}
													else
													{
														// The player is already cuffed
														SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}That player is already cuffed.");
													}
												}
												else
												{
													// Player is in vehicle
													SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You cannot cuff people while you are in a vehicle.");
												}
											}
											else
											{
												// Other player is in a vehicle
												SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}The player you're trying to cuff is in a vehicle.");
											}
										}
										else
										{
											// Cannot cuff an admin on duty
											SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}That player is currently performing admin duties and cannot be cuffed!");
										}
									}
									else
									{
										// Not in range of player
										SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You are not close enough to that player.");
									}
								}
								else
								{
									// Player is in jail
									SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You cannot cuff people when they're jailed or when you are jailed.");
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}This player does not have a high enough wanted level.");
							}
						}
						else
						{
							// Cannot cuff a cop/cia/fbi
							SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You cannot cuff law enforcement players.");
						}
					}
					else
					{
						// Cannot cuff players who are not logged in.
						SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You cannot cuff players who are not logged in.");
					}
				}
				else
				{
					// Cannot cuff players who are not connected.
					SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}That player is not connected.");
				}
            }
        }
        else
        {
            // Player is not police
            SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}This command can only be used by the LEO classes.");
        }
    }
    else
    {
        SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You must be logged in to use commands.");
    }

    return 1;
}
COMMAND:detain(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
  	    if(playerData[playerid][playerClass] == CLASS_POLICE || playerData[playerid][playerClass] == CLASS_ARMY || playerData[playerid][playerClass] == CLASS_CIA || playerData[playerid][playerClass] == CLASS_FBI || playerData[playerid][playerClass] == CLASS_SECRETSERVICE)
  	    {
            // Command for police to arrest
            new otherPlayer;
            if(sscanf(params, "u", otherPlayer))
            {
                // Invalid command syntax
                SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}Usage: \"detain <playerID>\"");
            }
            else
            {
				if(IsPlayerConnected(otherPlayer))
				{
					if(playerid != otherPlayer)
					{
						if(playerData[otherPlayer][playerClass] == CLASS_CIVILIAN)
						{
							// Check if the other player has a wanted level
							if(playerData[otherPlayer][playerWantedLevel] >= 12)
							{
								// Check if the player is in jail
								if(playerData[otherPlayer][playerJailTime] == 0 && playerData[playerid][playerJailTime] == 0)
								{
									if(isPlayerInRangeOfPlayer(playerid, otherPlayer, 4.0))
									{
										// If the player is not performing administrative duties
										if (!playerData[otherPlayer][playerAdminDuty])
										{
											// If OTHER player is in a vehicle
											if(!IsPlayerInAnyVehicle(otherPlayer))
											{
												// If POLICEMAN is in a vehicle
												if(!IsPlayerInAnyVehicle(playerid))
												{
													// Check if the player is cuffed
													if(playerData[otherPlayer][playerIsCuffed])
													{
														// Check if the player can arrest someone
														if(playerData[playerid][playerCanArrest])
														{
															new FreeSlot = GetEmptySeat(playerData[playerid][playerLastVehicleID]);
															if (FreeSlot != INVALID_SEAT_ID)
															{
																KillTimer(playerData[otherPlayer][unfreezeTimer]);
																playerData[otherPlayer][playerIsTazed] = false;

																SetPlayerInterior(otherPlayer, 0);
																SetPlayerVirtualWorld(otherPlayer, 0);

																PutPlayerInVehicle(otherPlayer, playerData[playerid][playerLastVehicleID], FreeSlot);

																// Freeze player
																TogglePlayerControllable(otherPlayer, 0);

																// Detain player
																new detained[200];
																format(detained, sizeof(detained), "{FFDC2E}[DETAINED] {FFFFFF}You have been detained by %s(%i)", playerData[playerid][playerNamee], playerid);
																SendClientMessage(otherPlayer, COLOR_WHITE, detained);

																new ydetained[200];
																format(ydetained, sizeof(ydetained), "{FFDC2E}[DETAINED] {FFFFFF}You have detained %s(%i), take them to the drop-off point!", playerData[otherPlayer][playerNamee], otherPlayer);
																SendClientMessage(playerid, COLOR_WHITE, ydetained);

																// Reset the cuff timer
																KillTimer(playerData[otherPlayer][uncuffTimer]);
																playerData[otherPlayer][uncuffTimer] = SetTimerEx("uncuff", 180000, false, "i", otherPlayer);

																playerGiveXP(playerid, 5);

																playerData[playerid][copDetains] = playerData[playerid][copDetains] + 1;
															}
															else
															{
																// No car seats available
																SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}There is no room in your vehicle to detain this player.");
															}
														}
														else
														{
															// Player cannot kidnap
															SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You must wait before arresting another player.");
														}
													}
													else
													{
														// Player isn't cuffed
														SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You must cuff the criminal before you can detain them.");
													}
												}
												else
												{
													// Player is in vehicle
													SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You cannot detain people while you are in a vehicle.");
												}
											}
											else
											{
												// Other player is in a vehicle
												SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}The player you're trying to detain is in a vehicle.");
											}
										}
										else
										{
											// Cannot kidnap an admin on duty
											SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}That player is currently performing admin duties and cannot be detained!");
										}
									}
									else
									{
										// Not in range of player
										SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You are not close enough to that player.");
									}
								}
								else
								{
									// Player is in jail
									SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You cannot detain people when they are jailed or when you are jailed.");
								}
							}
							else
							{
								// Incorrect wanted
								SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}This player does not have a high enough wanted level.");
							}
						}
						else
						{
							// Cannot kidnap players who are not connected.
							SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}That player is not connected.");
						}
					}
					else
					{
						// Cannot detain yourself
						SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You cannot detain yourself.");
					}
				}
			}
		}
		else
		{
			// Player is not civilian
			SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}Only LEO classes can use this command.");
		}
    }
    else
    {
        SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You must be logged in to use commands.");
    }
    return 1;
}

COMMAND:dropoff(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
  	    if(playerData[playerid][playerClass] == CLASS_POLICE || playerData[playerid][playerClass] == CLASS_FBI || playerData[playerid][playerClass] == CLASS_SECRETSERVICE || playerData[playerid][playerClass] == CLASS_CIA || playerData[playerid][playerClass] == CLASS_ARMY)
  	    {
			if(IsPlayerInRangeOfPoint(playerid, 2.0, -2441.1772, 523.7015, 29.9075) || IsPlayerInDynamicCP(playerid, Dropoff1CP) || IsPlayerInRangeOfPoint(playerid, 2.0, -1606.5209, 674.1558, -5.2422) || IsPlayerInDynamicCP(playerid, Dropoff2CP) || IsPlayerInDynamicCP(playerid, Dropoff4CP) || IsPlayerInRangeOfPoint(playerid, 2.0, 962.809814, 1757.652954, 8.648437) || IsPlayerInDynamicCP(playerid, Dropoff5CP) || IsPlayerInRangeOfPoint(playerid, 2.0, 2291.119873, 2474.975585, 10.820312))
			{
				new vehicleID = GetPlayerVehicleID(playerid);
				new count = 0;
				new total = 0;

				for(new i = 0; i <= MAX_PLAYERS; i++)
				{
					if(IsPlayerInVehicle(i, vehicleID))
					{
						// Check if they're wanted
						if(playerData[i][playerWantedLevel] >= 12)
						{
							// Player can be arrested
							count++;

							ClearAnimations(i);

							new totalTime = playerData[i][playerWantedLevel] * 5 / 2;

							// Set the otherPlayer's isCuffed to 0
							playerData[i][playerIsCuffed] = false;
							KillTimer(playerData[i][uncuffTimer]);

							// Now we'll calculate the LEO's earnings
							new totalEarnings = playerData[i][playerWantedLevel] * 110;
							total = total + totalEarnings;

							// Disable special action
							SetPlayerSpecialAction(i, SPECIAL_ACTION_NONE);

							// Toggle controllable
							TogglePlayerControllable(i, true);

							// Remove wanted level
							SetPlayerWantedLevel(i, 0);
							playerData[i][playerWantedLevel] = 0;
							playerData[i][playerTimesJailed] = playerData[i][playerTimesJailed] + 1;

							// Jail the player
							sendPlayerJail(i, totalTime, playerid, 1);
							newPlayerColour(i);
						}
					}
				}

				if(count >= 1)
				{
					// Show LEO their earnings
					new payout[200];
					format(payout, sizeof(payout), "{FFDC2E}[ARREST] {FFFFFF}You earnt {FFDC2E}$%s {FFFFFF}for arresting %i player(s)!", FormatNumber(total), count);
					SendClientMessage(playerid, COLOR_WHITE, payout);
					playerGiveMoney(playerid, total);
					playerGiveXP(playerid, 5);
					playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
					SetPlayerScore(playerid, playerData[playerid][playerScore]);
				}
				else
				{
					// No earnings - no arrests
					SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}There are no players in your vehicle to drop-off.");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You must be near a drop-off checkpoint.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}This command can only be used by LEO classes.");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
	return 1;
}

COMMAND:helidropoff(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
  	    if(playerData[playerid][playerClass] == CLASS_POLICE || playerData[playerid][playerClass] == CLASS_FBI || playerData[playerid][playerClass] == CLASS_SECRETSERVICE || playerData[playerid][playerClass] == CLASS_CIA || playerData[playerid][playerClass] == CLASS_ARMY)
  	    {
			if(IsPlayerInRangeOfPoint(playerid, -1687.4637, 705.8870, 30.6016, 2.0) || IsPlayerInDynamicCP(playerid, Dropoff3CP))
			{
				new vehicleID = GetPlayerVehicleID(playerid);
				new count = 0;
				new total = 0;

				if(GetVehicleModel(vehicleID) == 497)
				{
					for(new i = 0; i <= MAX_PLAYERS; i++)
					{
						if(IsPlayerInVehicle(i, vehicleID))
						{
							// Check if they're wanted
							if(playerData[i][playerWantedLevel] >= 12)
							{
								// Player can be arrested
								count++;

								ClearAnimations(i);

								new totalTime = playerData[i][playerWantedLevel] * 5 / 2;

								// Set the otherPlayer's isCuffed to 0
								playerData[i][playerIsCuffed] = false;
								KillTimer(playerData[i][uncuffTimer]);

								// Now we'll calculate the LEO's earnings
								new totalEarnings = playerData[i][playerWantedLevel] * 110;
								total = total + totalEarnings;

								// Disable special action
								SetPlayerSpecialAction(i, SPECIAL_ACTION_NONE);

								// Toggle controllable
								TogglePlayerControllable(i, true);

								// Remove wanted level
								SetPlayerWantedLevel(i, 0);
								playerData[i][playerWantedLevel] = 0;
								playerData[i][playerTimesJailed] = playerData[i][playerTimesJailed] + 1;

								// Jail the player
								sendPlayerJail(i, totalTime, playerid, 1);
								newPlayerColour(i);
							}
						}
					}

					if(count >= 1)
					{
						// Show LEO their earnings
						new payout[200];
						format(payout, sizeof(payout), "{FFDC2E}[ARREST] {FFFFFF}You earnt {FFDC2E}$%s {FFFFFF}for arresting %i player(s)!", FormatNumber(total), count);
						SendClientMessage(playerid, COLOR_WHITE, payout);

						playerGiveMoney(playerid, total);
						playerGiveXP(playerid, 5);
						playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
						SetPlayerScore(playerid, playerData[playerid][playerScore]);
					}
					else
					{
						// No earnings - no arrests
						SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}There are no players in your vehicle to drop-off.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You must be in a Police Maverick to use this checkpoint.");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You must be near a drop-off checkpoint.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}This command can only be used by LEO classes.");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
	return 1;
}

COMMAND:taze(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
  	    if(playerData[playerid][playerClass] == CLASS_POLICE || playerData[playerid][playerClass] == CLASS_ARMY || playerData[playerid][playerClass] == CLASS_CIA || playerData[playerid][playerClass] == CLASS_FBI || playerData[playerid][playerClass] == CLASS_SECRETSERVICE)
  	    {
            // Command for police to taze
            new otherPlayer, tazedBy[24], Name[24], pTazed[250], lTazed[250];
            if(sscanf(params, "u", otherPlayer))
            {
                // Invalid command syntax
                SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}Usage: \"taze <playerID>\"");
            }
            else
            {
				if(IsPlayerConnected(otherPlayer))
				{
					if(playerData[otherPlayer][playerLoggedIn])
					{
						if(playerData[otherPlayer][playerClass] == CLASS_CIVILIAN || playerData[otherPlayer][playerClass] == CLASS_MEDIC)
						{
							// Check if the other player has a wanted level
							if(playerData[otherPlayer][playerWantedLevel] >= 6)
							{
								// Check if the player is in jail
								if (playerData[playerid][playerJailTime] == 0 && playerData[otherPlayer][playerJailTime] == 0)
								{
									if(isPlayerInRangeOfPlayer(playerid, otherPlayer, 4.0))
									{
										// If the player is not performing administrative duties
										if (!playerData[otherPlayer][playerAdminDuty])
										{
											// If OTHER player is in a vehicle
											if(!IsPlayerInAnyVehicle(otherPlayer))
											{
												// If POLICEMAN is in a vehicle
												if(!IsPlayerInAnyVehicle(playerid))
												{
													// Check if the player is already tazed
													if(!playerData[otherPlayer][playerIsTazed])
													{
														// Check if the player can taze someone
														if(playerData[playerid][playerCanTaze])
														{
															if(!playerData[playerid][playerIsTied])
															{
																// Freeze the other player
																TogglePlayerControllable(otherPlayer, 0);

																ClearAnimations(otherPlayer);
																ApplyAnimation(otherPlayer, "PED", "FLOOR_hit_f", 4.0, 1, 0, 0, 0, 0);

																GetPlayerName(playerid, tazedBy, sizeof(Name));
																GetPlayerName(otherPlayer, Name, sizeof(Name));

																// Taze player
																format(pTazed, sizeof(pTazed), "{FFDC2E}[TAZED] {FFFFFF}You have been tazed by %s(%i) for 3 seconds", tazedBy, playerid);
																SendClientMessage(otherPlayer, 0xFF0000FF, pTazed);

																format(lTazed, sizeof(lTazed), "{FFDC2E}[TAZED] {FFFFFF}You have tazed %s(%i) for 3 seconds", Name, otherPlayer);
																SendClientMessage(playerid, COLOR_WHITE, lTazed);

																// Set timer to expire and unfreeze player (3 seconds)
																playerData[otherPlayer][unfreezeTimer] = SetTimerEx("Unfreeze", 3000, false, "i", otherPlayer);
																playerData[playerid][retazeTimer] = SetTimerEx("Retaze", 5000, false, "i", playerid);

																// Police cannot taze for 8 seconds
																playerData[playerid][playerCanTaze] = false;

																// Set the otherPlayer's isTazed to 1
																playerData[otherPlayer][playerIsTazed] = true;

																forceRobberyCancel(otherPlayer);
															}
															else
															{
																SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You cannot do this whilst tied.");
															}
														}
														else
														{
															// Cannot taze again yet...
															SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}Please wait before tazing a player again.");
														}
													}
													else
													{
														// The player is already tazed
														SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}That player is already tazed.");
													}
												}
												else
												{
													// Player is in vehicle
													SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You cannot taze people while you are in a vehicle.");
												}
											}
											else
											{
												// Other player is in a vehicle
												SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}The player you're trying to taze is in a vehicle.");
											}
										}
										else
										{
											// Cannot taze an admin on duty
											SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}That player is currently performing admin duties and cannot be tazed!");
										}
									}
									else
									{
										// Not in range of player
										SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You are not close enough to that player.");
									}
								}
								else
								{
									// Player is in jail
									SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You cannot taze people when they are jailed or when you are jailed.");
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}This player does not have a high enough wanted level.");
							}
						}
						else
						{
							// Cannot taze a cop/cia/fbi
							SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You cannot taze law enforcement players.");
						}
					}
					else
					{
						// Cannot taze players who are not logged in.
						SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You cannot taze players who are not logged in.");
					}
				}
				else
				{
					// Cannot taze players who are not connected.
					SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}That player is not connected.");
				}
            }
        }
        else
        {
            // Player is not police
            SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}This command can only be used by the LEO classes.");
        }
    }
    else
    {
        SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You must be logged in to use commands.");
    }
    return 1;
}

COMMAND:emp(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerClass] == CLASS_CIA)
		{
		    if (playerData[playerid][playerCanEMP])
			{
				new otherPlayer, vehicleID, empBy[24], ptName[24], message[250], message2[250], engine, lights, alarm, doors, bonnet, boot, objective;

				if(!sscanf(params, "u", otherPlayer))
				{
					if(IsPlayerConnected(otherPlayer))
					{
						if(playerData[otherPlayer][playerLoggedIn])
						{
							if(IsPlayerInAnyVehicle(otherPlayer))
							{
							    if(GetPlayerState(otherPlayer) == PLAYER_STATE_DRIVER)
								{
								    if(isPlayerInRangeOfPlayer(playerid, otherPlayer, 30.0))
									{
									    if(playerData[otherPlayer][playerClass] == CLASS_CIVILIAN)
										{
											vehicleID = GetPlayerVehicleID(otherPlayer);

											if (vehicleID >= 222)
											{
												SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You cannot EMP private vehicles.");
											}
											else
											{
												vehicleID = GetPlayerVehicleID(otherPlayer);
												GetPlayerName(otherPlayer, ptName, sizeof(ptName));
												GetPlayerName(playerid, empBy, sizeof(empBy));

												GetVehicleParamsEx(vehicleID, engine, lights, alarm, doors, bonnet, boot, objective);
												SetVehicleParamsEx(vehicleID, 0, lights, alarm, doors, bonnet, boot, objective);

												playerData[playerid][reEMPTimer] = SetTimerEx("reEMP", 60000, false, "i", playerid);

												resetEMPTimer[vehicleID] = SetTimerEx("resetEMP", 20000, false, "i", vehicleID);

												playerData[playerid][playerCanEMP] = false;

												format(message, sizeof(message), "{FFDC2E}[EMP] {FFFFFF}You have activated an EMP and fried %s(%i)'s engine for 10 seconds.", ptName, otherPlayer);
												SendClientMessage(playerid, COLOR_WHITE, message);

												format(message2, sizeof(message2), "{FFDC2E}[EMP] {FFFFFF}%s(%i) has activated an EMP and fried your engine for 10 seconds.", empBy, playerid);
												SendClientMessage(otherPlayer, COLOR_WHITE, message2);
											}
										}
										else
										{
										    SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You can only EMP civilian players.");
										}
									}
									else
									{
									    SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You're not close enough to the player's vehicle to EMP it.");
									}
								}
								else
								{
								    SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}Target player is not the driver of a vehicle.");
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}Target player is not inside a vehicle.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}That player is not logged in!");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}That player is not online!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}Usage: \"emp <playerID>\"");
				}
			}
			else
			{
			    SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}Please wait before trying to EMP a vehicle again.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}This command can only be used by the CIA class.");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{2BBBFB}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}

	return 1;
}
