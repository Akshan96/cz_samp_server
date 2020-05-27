native IsValidVehicle(vehicleid);

/*COMMAND:fakechat(playerid, params[])
{
    if(playerData[playerid][playerLevel] >= 5)
	{
		new
			otherID,
			message[128]
		;

		if(sscanf(params, "us", otherID, message))
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"fakechat <playerid> <message>\"");
		}
		else
		{
		    CallLocalFunction("OnPlayerText", "ds", otherID, message);
		}

		return 1;
	}
	return 0;
}*/

COMMAND:cleardeath(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 2)
		{
		    for(new i = 0; i < 10; i++)
		    {
		        SendDeathMessage(1337, 1338, 255);
		    }
			return 1;
		}
 	}
 	return 0;
}
COMMAND:duel(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 2)
		{
			new otherID, otherID2, weapon;
			if(sscanf(params, "uud", otherID, otherID2, weapon))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"duel <player1> <player2> <weaponid>\"");
			}
			else
			{
				if(otherID != otherID2)
				{
					if(playerData[otherID][playerLoggedIn] && playerData[otherID2][playerLoggedIn])
					{
					    for (new i = 0; i < 13; i++)
						{
							GetPlayerWeaponData(otherID, i, playerData[otherID][previousWeapons][i], playerData[otherID][previousAmmoLots][i]);
							GetPlayerWeaponData(otherID2, i, playerData[otherID2][previousWeapons][i], playerData[otherID2][previousAmmoLots][i]);
						}
						playerData[otherID][previousVirtualWorld] = GetPlayerVirtualWorld(otherID);
						playerData[otherID][previousInteriorWorld] = GetPlayerInterior(otherID);
						playerData[otherID2][previousVirtualWorld] = GetPlayerVirtualWorld(otherID2);
						playerData[otherID2][previousInteriorWorld] = GetPlayerInterior(otherID2);
						
						SetPlayerInterior(otherID, 1);
						SetPlayerInterior(otherID2, 1);
						SetPlayerVirtualWorld(otherID, 520);
						SetPlayerVirtualWorld(otherID2, 520);

						GetPlayerHealth(otherID, playerData[otherID][previousHealth]);
						GetPlayerHealth(otherID2, playerData[otherID2][previousHealth]);
						GetPlayerArmour(otherID, playerData[otherID][previousArmour]);
						GetPlayerArmour(otherID2, playerData[otherID2][previousArmour]);
						GetPlayerPos(otherID, playerData[otherID][previousX], playerData[otherID][previousY], playerData[otherID][previousZ]);
						GetPlayerPos(otherID2, playerData[otherID2][previousX], playerData[otherID2][previousY], playerData[otherID2][previousZ]);
						SetPlayerPos(otherID, 3219.1270,1689.3604,15.0357);
						SetPlayerPos(otherID2, 3196.9441,1764.4182,15.0357);
						// No team during DM
						SetPlayerTeam(otherID, NO_TEAM);
						SetPlayerTeam(otherID2, NO_TEAM);

						playerData[otherID][isInDuel] = true;
						playerData[otherID2][isInDuel] = true;
						TogglePlayerControllable(otherID, 0);
						TogglePlayerControllable(otherID2, 0);

						// Remove armour
						SetPlayerArmour(otherID, 0);
						SetPlayerHealth(otherID, 100);
						SetPlayerArmour(otherID2, 0);
						SetPlayerHealth(otherID2, 100);

						ResetPlayerWeapons(otherID);
						ResetPlayerWeapons(otherID2);
						playerData[otherID][adminWeapon] = true;
						playerData[otherID2][adminWeapon] = true;
						GivePlayerWeaponEx(otherID, weapon, 5000);
						GivePlayerWeaponEx(otherID2, weapon, 5000);

						GameTextForPlayer(otherID, "THE DUEL WILL START SHORTLY!~n~~r~You are temporarily frozen", 10000, 5);
						GameTextForPlayer(otherID2, "THE DUEL WILL START SHORTLY!~n~~r~You are temporarily frozen", 10000, 5);

						SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[DUEL] {FFFFFF}To start the duel, type /startduel.");
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[DUEL] {FFFFFF}Player not logged in.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[DUEL] {FFFFFF}Failed to start duel.");
				}
			}
			return 1;
		}
	}
	return 0;
}

COMMAND:startduel(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 2)
		{
			for(new i = 0; i < MAX_PLAYERS; i++)
			{
				if(IsPlayerConnected(i) && playerData[i][playerLoggedIn])
				{
					if (playerData[i][isInDuel])
					{
						TogglePlayerControllable(i, 1);
						GameTextForPlayer(i, "DUEL STARTED!", 5000, 5);
					}
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
	return 1;
}

COMMAND:givetoken(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 6)
		{
			new
				otherID,
				message[128],
				message2[128]
			;
			
			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"givetoken <playerid>\"");
			}
			else
			{	
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{			
						playerData[otherID][rTokens]++;
						
						format(message, sizeof(message), "{B7B7B7}[RCON] {FFFFFF}You awarded {FFDC2E}%s(%i) {FFFFFF}with 1 token.", playerData[otherID][playerNamee], otherID);
						SendClientMessage(playerid, COLOR_WHITE, message);
						
						format(message2, sizeof(message2), "{B7B7B7}[INFO] {FFFFFF}You have received a token from {FFDC2E}%s(%i)", playerData[playerid][tempAdminName], playerid);
						SendClientMessage(otherID, COLOR_WHITE, message2);
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
				}
			}
		}
	}
	
	return 1;
}

COMMAND:playertokens(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 3)
		{
			new
				otherID,
				message[128]
			;
			
			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"playertokens <playerid>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{					
						format(message, sizeof(message), "{B7B7B7}[INFO] {FFFFFF}%s(%i) has {FFDC2E}%i {FFFFFF}tokens.", playerData[otherID][playerNamee], otherID, playerData[otherID][rTokens]);
						SendClientMessage(playerid, COLOR_WHITE, message);
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
				}
			}
		}
		else
		{
			return 0;
		}
	}
	
	return 1;
}

COMMAND:playerjob(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 3)
		{
			new
				otherID
			;
			
			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"playerjob <playerid>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{					
						switch(playerData[otherID][playerJob])
						{
							case JOB_KIDNAPPER:
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[PLAYER JOB] {FFFFFF}That player is a kidnapper.");
							}
							case JOB_MECHANIC:
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[PLAYER JOB] {FFFFFF}That player is a mechanic.");
							}
							case JOB_WEAPONDEALER:
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[PLAYER JOB] {FFFFFF}That player is a weapon dealer.");
							}
							case JOB_HITMAN:
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[PLAYER JOB] {FFFFFF}That player is a hitman.");
							}
							case JOB_RAPIST:
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[PLAYER JOB] {FFFFFF}That player is a rapist.");
							}
							case JOB_DRUGDEALER:
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[PLAYER JOB] {FFFFFF}That player is a drug dealer.");
							}
							case JOB_TERRORIST:
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[PLAYER JOB] {FFFFFF}That player is a terrorist.");
							}
							default:
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[PLAYER JOB] {FFFFFF}That player has no job.");
							}
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
				}
			}
		}
		else
		{
			return 0;
		}
	}
	
	return 1;
}

COMMAND:playerjailtime(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 1)
		{
			new
				otherID,
				message[128]
			;
			
			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"playerjailtime <playerid>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{					
						format (message, sizeof(message), "{B7B7B7}[JAIL TIME] {FFFFFF}That player has %i seconds remaining in jail.", playerData[otherID][playerJailTime]);
						SendClientMessage(playerid, COLOR_WHITE, message);
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
				}
			}
		}
		else
		{
			return 0;
		}
	}
	
	return 1;
}

COMMAND:allowspec(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			if (playerData[playerid][allowSpec])
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Admins with a level less than 5 can no longer spectate you.");
				playerData[playerid][allowSpec] = false;
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}All admins can now spectate you.");
				playerData[playerid][allowSpec] = true;
			}
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

COMMAND:adminname(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			new newName[24];

			if(sscanf(params, "s[24]", newName))
			{
				SendClientMessage(playerid, COLOR_ORANGE, "Usage: \"adminname <temporary name>\"");
			}
			else
			{	
				new tempName[24];
				format(tempName, sizeof(tempName), "%s", newName);
				SetPlayerName(playerid, tempName);
				
				playerData[playerid][tempAdminName] = newName;
				playerData[playerid][useAdminName] = true;
				
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[ADMIN NAME] {FFFFFF}Your name has been set. Use /removename to revert to your actual username.");
			}
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

COMMAND:removename(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			new revertName[24];
			format(revertName, sizeof(revertName), "%s", playerData[playerid][playerNamee]);
			
			SetPlayerName(playerid, playerData[playerid][playerNamee]);
			playerData[playerid][tempAdminName] = revertName;
			playerData[playerid][useAdminName] = false;
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[ADMIN NAME] {FFFFFF}Your admin name has been reset.");
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


COMMAND:exitlounge(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
  	    if(playerData[playerid][playerLevel] >= 1)
  	    {
			if(GetPlayerInterior(playerid) == 69)
			{
				playerData[playerid][playerCheckpointTime] = GetTickCount();
			
				SetPlayerPos(playerid, -2036.5284, 1196.7173, 46.2395);
				SetPlayerInterior(playerid, 0);
				SetPlayerVirtualWorld(playerid, 0);
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You are not inside the admin lounge.");
			}
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

COMMAND:blockreport(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 1)
		{
			new otherID, message[200], message2[200];
		
			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"blockreport <playername/id>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
						if(playerData[otherID][canReport])
						{
							playerData[otherID][canReport] = false;
							
							format(message, sizeof(message), "{FE9A2E}[ADMIN] {FFFFFF}You have blocked to %s(%i) from using /report", playerData[otherID][playerNamee], otherID);
							SendClientMessage(playerid, COLOR_WHITE, message);
							
							format(message2, sizeof(message2), "{FE9A2E}[ADMIN] {FFFFFF}You have been blocked from using /report by %s(%i)", playerData[playerid][tempAdminName], playerid);
							SendClientMessage(otherID, COLOR_WHITE, message2);
							
							new log[250];
							format(log, sizeof(log), "%s(%i) has blocked %s(%i) from /report", playerData[playerid][tempAdminName], playerid, playerData[otherID][playerNamee], otherID);
							SendAdminText(playerid, log);										
						}
						else
						{
							playerData[otherID][canReport] = true;
							
							format(message, sizeof(message), "{FE9A2E}[ADMIN] {FFFFFF}You have unblocked to %s(%i) from using /report", playerData[otherID][playerNamee], otherID);
							SendClientMessage(playerid, COLOR_WHITE, message);
							
							format(message2, sizeof(message2), "{FE9A2E}[ADMIN] {FFFFFF}You have been unblocked from using /report by %s(%i)", playerData[playerid][tempAdminName], playerid);
							SendClientMessage(otherID, COLOR_WHITE, message2);
							
							new log[250];
							format(log, sizeof(log), "%s(%i) has unblocked %s(%i) from /report", playerData[playerid][tempAdminName], playerid, playerData[otherID][playerNamee], otherID);
							SendAdminText(playerid, log);								
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:blockask(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 1)
		{
			new otherID, message[200], message2[200];
		
			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"blockask <playername/id>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
						if(playerData[otherID][canAsk])
						{
							playerData[otherID][canAsk] = false;
							
							format(message, sizeof(message), "{FE9A2E}[ADMIN] {FFFFFF}You have blocked to %s(%i) from using /ask", playerData[otherID][playerNamee], otherID);
							SendClientMessage(playerid, COLOR_WHITE, message);
							
							format(message2, sizeof(message2), "{FE9A2E}[ADMIN] {FFFFFF}You have been blocked from using /report by %s(%i)", playerData[playerid][tempAdminName], playerid);
							SendClientMessage(otherID, COLOR_WHITE, message2);
							
							new log[250];
							format(log, sizeof(log), "%s(%i) has blocked %s(%i) from /ask", playerData[playerid][tempAdminName], playerid, playerData[otherID][playerNamee], otherID);
							SendAdminText(playerid, log);										
						}
						else
						{
							playerData[otherID][canAsk] = true;
							
							format(message, sizeof(message), "{FE9A2E}[ADMIN] {FFFFFF}You have unblocked to %s(%i) from using /ask", playerData[otherID][playerNamee], otherID);
							SendClientMessage(playerid, COLOR_WHITE, message);
							
							format(message, sizeof(message2), "{FE9A2E}[ADMIN] {FFFFFF}You have been unblocked from using /ask by %s(%i)", playerData[playerid][tempAdminName], playerid);
							SendClientMessage(otherID, COLOR_WHITE, message2);
							
							new log[250];
							format(log, sizeof(log), "%s(%i) has unblocked %s(%i) from /ask", playerData[playerid][tempAdminName], playerid, playerData[otherID][playerNamee], otherID);
							SendAdminText(playerid, log);								
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:gotoloc(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
  	    if(playerData[playerid][playerLevel] >= 6)
  	    {
			new
				Float:x,
				Float:y,
				Float:z
			;
			
            if(sscanf(params, "fff", x, y, z))
            {
                // Invalid command syntax
                SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"gotoloc <x> <y> <z>\"");
            }
            else
            {
				SetPlayerPos(playerid, x, y, z);		
			}
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

COMMAND:a(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
  	    if(playerData[playerid][playerLevel] >= 1)
  	    {
            // Command for police to arrest
            new message[280];
            if(sscanf(params, "s[280]", message))
            {
                // Invalid command syntax
                SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"a <message>\"");
            }
            else
            {
				for (new i=0; i<MAX_PLAYERS; i++)
				{
					if (playerData[i][playerLevel] >= 1)
					{
						new achat[300];
						format(achat, sizeof(achat), "{07E08D}<Admin Chat> {8FFF8B}%s: %s", playerData[playerid][tempAdminName], message);
						SendClientMessage(i, COLOR_WHITE, achat);
					}
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
	return 1;
}

COMMAND:b(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
  	    if(playerData[playerid][playerLevel] >= 6)
  	    {
            new message[200];
            if(sscanf(params, "s[200]", message))
            {
                // Invalid command syntax
                SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"b <message>\"");
            }
            else
            {
				for (new i=0; i<MAX_PLAYERS; i++)
				{
					if (playerData[i][playerLevel] >= 6)
					{
						new achat[200];
						format(achat, sizeof(achat), "{FE9A2E}<Baws Chat> {FFFFFF}%s: %s", playerData[playerid][tempAdminName], message);
						SendClientMessage(i, COLOR_WHITE, achat);
					}
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
	return 1;
}

COMMAND:ans(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
        if (playerData[playerid][playerLevel] >= 1 || playerData[playerid][playerHelper] == 1)
        {
            new input[120], message[250], message2[350], otherPlayer;

            if(sscanf(params, "us[100]", otherPlayer, input))
            {
                SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"(ans)wer <player> <message>\"");
            }
            else
            {
                // Check if player is connected
                if(IsPlayerConnected(otherPlayer))
                {
                    if(playerData[otherPlayer][playerLoggedIn])
                    {
                        for(new i = 0; i < MAX_PLAYERS; i++)
                        {
                            if(IsPlayerConnected(i) && playerData[i][playerLevel] >= 1 || playerData[i][playerHelper] == 1)
                            {
                                format(message, sizeof(message), "{FE9A2E}[ANSWER] {FFFFFF}%s(%i) => %s(%i): %s", playerData[playerid][tempAdminName], playerid, playerData[otherPlayer][playerNamee], otherPlayer, input);
                                SendClientMessage(i, COLOR_WHITE, message);
                            }
                        }

                        format(message2, sizeof(message2), "{FE9A2E}[ANSWER] {FFFFFF}From %s(%i): %s", playerData[playerid][tempAdminName], playerid, input);
                        SendClientMessage(otherPlayer, COLOR_WHITE, message2);
                        PlayerPlaySound(otherPlayer, 1149, 0.0, 0.0, 10.0);						
                    }
                    else
                    {
                        SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}The player your trying to PM is not logged in.");
                    }
                }
                else
                {
                    SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}The player your trying to PM isn't connected.");
                }
            }
        }
		else
		{
			return 0;
		}
	}
	return 1;
}

COMMAND:arules(playerid, params[])
{
    if (playerData[playerid][playerLoggedIn])
    {
		if (playerData[playerid][playerLevel] >= 1)
		{
			new string[1200];
			format(string, sizeof(string), "%s{98B0CD}1. {FFFFFF}Do not spawn players without reason. \n", string);
			format(string, sizeof(string), "%s{98B0CD}2. {FFFFFF}Slaying is used as a last resort, use /spawn primarily. \n", string);
			format(string, sizeof(string), "%s{98B0CD}3. {FFFFFF}Abusing /announce is disallowed. \n", string);
			format(string, sizeof(string), "%s{98B0CD}4. {FFFFFF}When dealing with players, correct grammar is required. \n", string);
			format(string, sizeof(string), "%s{98B0CD}5. {FFFFFF}Do not abuse admin duty. Doing so will result in a demotion. \n", string);
			format(string, sizeof(string), "%s{98B0CD}6. {FFFFFF}You are still a player, respect the server rules. \n", string);
			format(string, sizeof(string), "%s{98B0CD}7. {FFFFFF}Do not be abusive towards players, no matter how they are towards you. \n", string);
			format(string, sizeof(string), "%s{98B0CD}8. {FFFFFF}Destroy your spawned vehicles when finished. \n", string);
			format(string, sizeof(string), "%s{98B0CD}9. {FFFFFF}/clearchat must be used for clearing advertisements. Do not abuse this command. \n", string);
			format(string, sizeof(string), "%s{98B0CD}10. {FFFFFF}If a player requests a skin, deny them. VIPs can set a custom skin. \n", string);
			format(string, sizeof(string), "%s{98B0CD}11. {FFFFFF}Spectation must not be used as an in-game advantage. \n", string);
			
			ShowPlayerDialog(playerid, DIALOG_RULES, DIALOG_STYLE_MSGBOX, "Admin Guidelines", string, "OK", "");
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

COMMAND:ahelp(playerid, params[])
{
    if (playerData[playerid][playerLoggedIn])
    {
		if (playerData[playerid][playerLevel] >= 1)
		{
			new string[3000];
			format(string, sizeof(string), "%s{98B0CD}Muting Players{FFFFFF}\n", string);
			format(string, sizeof(string), "%sPlayers who spam or flood the chat should be muted. 300 seconds is recommended though this\n", string);
			format(string, sizeof(string), "%scan be doubled for second offenses. Players who advertise servers should be banned, not muted.\n\n", string);
			
			format(string, sizeof(string), "%s{98B0CD}Kicking Players{FFFFFF}\n", string);
			format(string, sizeof(string), "%sPlayers who continuously break the rules and have been warned several times may be kicked.\n", string);
			format(string, sizeof(string), "%sYou may also kick players who are bugged. If you spot a hacker, and there are no level 3\n", string);
			format(string, sizeof(string), "%sadmins present, jail the player and kick them.\n\n", string);
			
			format(string, sizeof(string), "%s{98B0CD}Banning Players{FFFFFF}\n", string);
			format(string, sizeof(string), "%sBan players who are hacking the game. You may also ban players who visit the server and\n", string);
			format(string, sizeof(string), "%sadvertise other servers. Furthermore, players who ban evade may also be banned.\n\n", string);
			
			format(string, sizeof(string), "%s{98B0CD}Jailing Players{FFFFFF}\n", string);
			format(string, sizeof(string), "%sThe jail command should be used on players who quit to avoid death or arrest. The recommended\n", string);
			format(string, sizeof(string), "%stime is 100 seconds for this offense, doubled if a repeat offense. Players who constantly\n", string);
			format(string, sizeof(string), "%savoid may be banned in some cases.\n\n", string);
			
			format(string, sizeof(string), "%s{98B0CD}Spawning Players{FFFFFF}\n", string);
			format(string, sizeof(string), "%sPlayers may be spawned if they're stuck inside an interior or object. However, if a player\n", string);
			format(string, sizeof(string), "%shas a wanted level and wishes to be spawned, unless they are clearly stuck they must not be\n", string);
			format(string, sizeof(string), "%sspawned.\n\n", string);
			
			format(string, sizeof(string), "%s{98B0CD}Slaying Players{FFFFFF}\n", string);
			format(string, sizeof(string), "%sThe slay command is a last resort if the player requires a death to continue, but cannot /kill!\n", string);
			format(string, sizeof(string), "%sThis command should not be used before /spawn, as it will reset their wanted level and tax them.\n\n", string);
			
			format(string, sizeof(string), "%s{98B0CD}Example Command Reasons{FFFFFF}\n", string);
			format(string, sizeof(string), "%s{98B0CD}(Ban) {FFFFFF}The player has cheated using a program such as sobeit. \n", string);
			format(string, sizeof(string), "%s{98B0CD}(Ban) {FFFFFF}The player is known to be farming, and you have evidence of this. \n", string);
			format(string, sizeof(string), "%s{98B0CD}(Jail) {FFFFFF}The player quits to avoid an arrest or death. \n", string);
			format(string, sizeof(string), "%s{98B0CD}(Jail/Kick) {FFFFFF}The player is hacking, and you're a level 1 or 2 admin. \n", string);
			format(string, sizeof(string), "%s{98B0CD}(Spawn) {FFFFFF}The player has become stuck. \n", string);
			
			ShowPlayerDialog(playerid, DIALOG_RULES, DIALOG_STYLE_MSGBOX, "Admin Guidelines", string, "OK", "");
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

COMMAND:teleport(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 6)
		{
          ShowPlayerDialog(playerid, DIALOG_ATELEPORT, DIALOG_STYLE_LIST, "Admin Teleport", "Bank \nSFPD \nSFPD Parking Lot \nArmy Spawn \nCIA/FBI Spawn \nAmmunation \nAirport \nHospital \nSupa Save \nChurch \nSuburban \nGym \nLS Airport \nVan Courier \nVIP Lounge \nCar Drop \nBomb Shop \nJob Centre \nTrucking \nAdmin Lounge \nVehicle Dealership \nForklift Mission \nMinigames", "Go", "Cancel");
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

COMMAND:announce(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 4)
		{
			new message[80];
			if(sscanf(params, "s[80]", message))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"announce <message>\"");
			}
			else
			{
				TextDrawSetString(AnnounceTD, message);
				TextDrawHideForAll(AnnounceTD);
				TextDrawShowForAll(AnnounceTD);
				
				SetTimer("hideAnnouncement", 5000, false);
				
				new log[250];
				format(log, sizeof(log), "%s(%i) announced \"%s\"", playerData[playerid][tempAdminName], playerid, message);
				SendAdminText(playerid, log);			
			}
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

COMMAND:ann(playerid, params[])
{
	return cmd_announce(playerid, params); 
}

COMMAND:extendvip(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(IsPlayerAdmin(playerid))
		{
			new
				otherID,
				message[128],
				message2[128]
			;
			
			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"extendvip <playerid>\"");
			}
			else
			{		
				playerData[otherID][vipExpires] = gettime() + 2592000;
				
				format(message, sizeof(message), "{B7B7B7}[RCON] {FFFFFF}You extended {FFDC2E}%s(%i)'s {FFFFFF}VIP time by 1 month.", playerData[otherID][playerNamee], otherID);
				SendClientMessage(playerid, COLOR_WHITE, message);
				
				format(message2, sizeof(message2), "{B7B7B7}[INFO] {FFFFFF}Your VIP time has been extended 1 month by {FFDC2E}%s(%i)", playerData[playerid][tempAdminName], playerid);
				SendClientMessage(otherID, COLOR_WHITE, message2);
			}
		}
	}
	
	return 1;
}

COMMAND:standardvip(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 6)
		{
			new
				otherID,
				message[128],
				message2[128]
			;
			
			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"standardvip <playerid>\"");
			}
			else
			{			
				playerData[otherID][playerVIPLevel] = 1;
				playerData[otherID][vipExpires] = gettime() + 2592000;
				playerGiveMoney(otherID, 500000);
				
				if (serverInfo[doubleXP])
				{
					playerGiveXP(otherID, 500);
				}
				else
				{
					playerGiveXP(otherID, 1000);
				}
				
				format(message, sizeof(message), "{B7B7B7}[RCON] {FFFFFF}You awarded {FFDC2E}%s(%i) {FFFFFF}with 1 month of Standard VIP.", playerData[otherID][playerNamee], otherID);
				SendClientMessage(playerid, COLOR_WHITE, message);
				
				format(message2, sizeof(message2), "{B7B7B7}[INFO] {FFFFFF}You have received Standard VIP from {FFDC2E}%s(%i)", playerData[playerid][tempAdminName], playerid);
				SendClientMessage(otherID, COLOR_WHITE, message2);
				
				disableAchieve(otherID);
				PlayerTextDrawShow(otherID, playerData[otherID][Achieve1]);
				PlayerTextDrawShow(otherID, playerData[otherID][Achieve2]);
				PlayerTextDrawShow(otherID, playerData[otherID][Achieve3]);
				PlayerTextDrawShow(otherID, playerData[otherID][Achieve4]);

				PlayerTextDrawSetString(otherID, playerData[otherID][Achieve3], "You're VIP!");
				PlayerTextDrawSetString(otherID, playerData[otherID][Achieve4], "You are now a VIP member, nice!");
				PlayerPlaySound(otherID, 1183 ,0.0, 0.0, 0.0);

				playerData[otherID][achieveTimer] = SetTimerEx("disableAchieve", 6000, false, "i", otherID);
				
				playerGiveXP(otherID, 25);
				playerData[otherID][playerScore] = playerData[otherID][playerScore] + 2;
				SetPlayerScore(otherID, playerData[otherID][playerScore]);
			}
		}
	}
	
	return 1;
}

COMMAND:silvervip(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 6)
		{
			new
				otherID,
				message[128],
				message2[128]
			;
			
			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"silvervip <playerid>\"");
			}
			else
			{		
				playerData[otherID][playerVIPLevel] = 2;
				playerData[otherID][vipExpires] = gettime() + 2592000;
				playerGiveMoney(otherID, 2000000);
				
				if (serverInfo[doubleXP])
				{
					playerGiveXP(otherID, 4000);
				}
				else
				{
					playerGiveXP(otherID, 8000);
				}
				
				playerData[otherID][rTokens] = playerData[otherID][rTokens] + 3;
				
				format(message, sizeof(message), "{B7B7B7}[RCON] {FFFFFF}You awarded {FFDC2E}%s(%i) {FFFFFF}with 1 month of Silver VIP.", playerData[otherID][playerNamee], otherID);
				SendClientMessage(playerid, COLOR_WHITE, message);
				
				format(message2, sizeof(message2), "{B7B7B7}[INFO] {FFFFFF}You have received Silver VIP from {FFDC2E}%s(%i) {FFFFFF}(+3 Tokens)", playerData[playerid][tempAdminName], playerid);
				SendClientMessage(otherID, COLOR_WHITE, message2);
				
				disableAchieve(otherID);
				PlayerTextDrawShow(otherID, playerData[otherID][Achieve1]);
				PlayerTextDrawShow(otherID, playerData[otherID][Achieve2]);
				PlayerTextDrawShow(otherID, playerData[otherID][Achieve3]);
				PlayerTextDrawShow(otherID, playerData[otherID][Achieve4]);

				PlayerTextDrawSetString(otherID, playerData[otherID][Achieve3], "You're VIP!");
				PlayerTextDrawSetString(otherID, playerData[otherID][Achieve4], "You are now a VIP member, nice!");
				PlayerPlaySound(otherID, 1183 ,0.0, 0.0, 0.0);

				playerData[otherID][achieveTimer] = SetTimerEx("disableAchieve", 6000, false, "i", otherID);
				
				playerGiveXP(otherID, 25);
				playerData[otherID][playerScore] = playerData[otherID][playerScore] + 2;
				SetPlayerScore(otherID, playerData[otherID][playerScore]);
			}
		}
	}
	
	return 1;
}

COMMAND:goldvip(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 6)
		{
			new
				otherID,
				message[128],
				message2[128]
			;
			
			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"goldvip <playerid>\"");
			}
			else
			{		
				playerData[otherID][playerVIPLevel] = 3;
				playerData[otherID][vipExpires] = gettime() + 2592000;
				playerGiveMoney(otherID, 5000000);
				
				if (serverInfo[doubleXP])
				{
					playerGiveXP(otherID, 7500);
				}
				else
				{
					playerGiveXP(otherID, 15000);
				}
				
				playerData[otherID][rTokens] = playerData[otherID][rTokens] + 7;
				
				format(message, sizeof(message), "{B7B7B7}[RCON] {FFFFFF}You awarded {FFDC2E}%s(%i) {FFFFFF}with 1 month of Gold VIP.", playerData[otherID][playerNamee], otherID);
				SendClientMessage(playerid, COLOR_WHITE, message);
				
				format(message2, sizeof(message2), "{B7B7B7}[INFO] {FFFFFF}You have received Gold VIP from {FFDC2E}%s(%i) {FFFFFF}(+7 Tokens)", playerData[playerid][tempAdminName], playerid);
				SendClientMessage(otherID, COLOR_WHITE, message2);
				
				disableAchieve(otherID);
				PlayerTextDrawShow(otherID, playerData[otherID][Achieve1]);
				PlayerTextDrawShow(otherID, playerData[otherID][Achieve2]);
				PlayerTextDrawShow(otherID, playerData[otherID][Achieve3]);
				PlayerTextDrawShow(otherID, playerData[otherID][Achieve4]);

				PlayerTextDrawSetString(otherID, playerData[otherID][Achieve3], "You're VIP!");
				PlayerTextDrawSetString(otherID, playerData[otherID][Achieve4], "You are now a VIP member, nice!");
				PlayerPlaySound(otherID, 1183 ,0.0, 0.0, 0.0);

				playerData[otherID][achieveTimer] = SetTimerEx("disableAchieve", 6000, false, "i", otherID);
				
				playerGiveXP(otherID, 25);
				playerData[otherID][playerScore] = playerData[otherID][playerScore] + 2;
				SetPlayerScore(otherID, playerData[otherID][playerScore]);
			}
		}
	}
	
	return 1;
}

COMMAND:goldplusvip(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 6)
		{
			new
				otherID,
				message[128],
				message2[128]
			;

			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"goldplusvip <playerid>\"");
			}
			else
			{
				playerData[otherID][playerVIPLevel] = 4;
				playerData[otherID][vipExpires] = gettime() + 2592000;
				playerGiveMoney(otherID, 10000000);

				if (serverInfo[doubleXP])
				{
					playerGiveXP(otherID, 7500);
				}
				else
				{
					playerGiveXP(otherID, 15000);
				}

				playerData[otherID][rTokens] = playerData[otherID][rTokens] + 10;

				format(message, sizeof(message), "{B7B7B7}[RCON] {FFFFFF}You awarded {FFDC2E}%s(%i) {FFFFFF}with 1 month of Goldplus VIP.", playerData[otherID][playerNamee], otherID);
				SendClientMessage(playerid, COLOR_WHITE, message);

				format(message2, sizeof(message2), "{B7B7B7}[INFO] {FFFFFF}You have received Gold VIP from {FFDC2E}%s(%i) {FFFFFF}(+10 Tokens)", playerData[playerid][tempAdminName], playerid);
				SendClientMessage(otherID, COLOR_WHITE, message2);

				disableAchieve(otherID);
				PlayerTextDrawShow(otherID, playerData[otherID][Achieve1]);
				PlayerTextDrawShow(otherID, playerData[otherID][Achieve2]);
				PlayerTextDrawShow(otherID, playerData[otherID][Achieve3]);
				PlayerTextDrawShow(otherID, playerData[otherID][Achieve4]);

				PlayerTextDrawSetString(otherID, playerData[otherID][Achieve3], "You're VIP!");
				PlayerTextDrawSetString(otherID, playerData[otherID][Achieve4], "You are now a VIP member, nice!");
				PlayerPlaySound(otherID, 1183 ,0.0, 0.0, 0.0);

				playerData[otherID][achieveTimer] = SetTimerEx("disableAchieve", 6000, false, "i", otherID);

				playerGiveXP(otherID, 25);
				playerData[otherID][playerScore] = playerData[otherID][playerScore] + 2;
				SetPlayerScore(otherID, playerData[otherID][playerScore]);
			}
		}
	}

	return 1;
}


COMMAND:set(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(IsPlayerAdmin(playerid))
		{
			new otherID, otherName[24], message[128], selection[5], amount, message2[128];
		
			if(sscanf(params, "us[20] i", otherID, selection, amount))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"set <player> <score/money/kills/deaths/level/jailtime/wanted/xp/job/vip/helper> <amount>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
						GetPlayerName(otherID, otherName, sizeof(otherName));

						if(!strcmp(selection, "score", true))
						{
							playerData[otherID][playerScore] = amount;
							SetPlayerScore(otherID, playerData[otherID][playerScore]);
							format(message, sizeof(message), "{B7B7B7}[RCON] {FFFFFF}You set {FFDC2E}%s's {FFFFFF}score to {FFDC2E}%i", otherName, amount);
							SendClientMessage(playerid, COLOR_WHITE, message);
							
							format(message2, sizeof(message), "{B7B7B7}[INFO] {FFFFFF}Your score has been set to {FFDC2E}%i", amount);
							SendClientMessage(otherID, COLOR_WHITE, message2);
							
							if (playerData[playerid][playerLevel] != 7)
							{
								new log[250];
								format(log, sizeof(log), "%s(%i) set %s(%i)'s score to %i", playerData[playerid][tempAdminName], playerid, otherName, otherID, amount);
								SendAdminText(playerid, log);	
							}
						}
						else if(!strcmp(selection, "money", true))
						{
							playerSetMoney(otherID, amount);
							format(message, sizeof(message), "{B7B7B7}[RCON] {FFFFFF}You set {FFDC2E}%s's {FFFFFF}money to {FFDC2E}$%s", otherName, FormatNumber(amount));
							SendClientMessage(playerid, COLOR_WHITE, message);
							
							format(message2, sizeof(message), "{B7B7B7}[INFO] {FFFFFF}Your money has been set to {FFDC2E}$%s", FormatNumber(amount));
							SendClientMessage(otherID, COLOR_WHITE, message2);
							
							if (playerData[playerid][playerLevel] != 7)
							{
								new log[250];
								format(log, sizeof(log), "%s(%i) set %s(%i)'s money to %s", playerData[playerid][tempAdminName], playerid, otherName, otherID, FormatNumber(amount));
								SendAdminText(playerid, log);	
							}
						}
						else if(!strcmp(selection, "kills", true))
						{
							playerData[otherID][playerKills] = amount;
							format(message, sizeof(message), "{B7B7B7}[RCON] {FFFFFF}You set {FFDC2E}%s's {FFFFFF}kills to {FFDC2E}%i", otherName, amount);
							SendClientMessage(playerid, COLOR_WHITE, message);
							
							format(message2, sizeof(message), "{B7B7B7}[INFO] {FFFFFF}Your kill count has been set to {FFDC2E}%i", amount);
							SendClientMessage(otherID, COLOR_WHITE, message2);
							
							new log[250];
							format(log, sizeof(log), "%s(%i) set %s(%i)'s kill count to %i", playerData[playerid][tempAdminName], playerid, otherName, otherID, amount);
							SendAdminText(playerid, log);	
						}
						else if(!strcmp(selection, "deaths", true))
						{
							playerData[otherID][playerDeaths] = amount;
							format(message, sizeof(message), "{B7B7B7}[RCON] {FFFFFF}You set {FFDC2E}%s's {FFFFFF}deaths to {FFDC2E}%i", otherName, amount);
							SendClientMessage(playerid, COLOR_WHITE, message);
							
							format(message2, sizeof(message), "{B7B7B7}[INFO] {FFFFFF}Your death count has been set to {FFDC2E}%i", amount);
							SendClientMessage(otherID, COLOR_WHITE, message2);
							
							new log[250];
							format(log, sizeof(log), "%s(%i) set %s(%i)'s death count to %i", playerData[playerid][tempAdminName], playerid, otherName, otherID, amount);
							SendAdminText(playerid, log);	
						}
						else if(!strcmp(selection, "jailtime", true))
						{
							playerData[otherID][playerJailTime] = amount;
							format(message, sizeof(message), "{B7B7B7}[RCON] {FFFFFF}You set {FFDC2E}%s's {FFFFFF}jail time to {FFDC2E}%i", otherName, amount);
							SendClientMessage(playerid, COLOR_WHITE, message);
							
							if (playerData[playerid][playerLevel] != 7)
							{
								new log[250];
								format(log, sizeof(log), "%s(%i) set %s(%i)'s jail time to %i", playerData[playerid][tempAdminName], playerid, otherName, otherID, amount);
								SendAdminText(playerid, log);	
							}
						}
						else if(!strcmp(selection, "wanted", true))
						{
							playerData[otherID][playerWantedLevel] = amount;
							format(message, sizeof(message), "{B7B7B7}[RCON] {FFFFFF}You set {FFDC2E}%s's {FFFFFF}wanted level to {FFDC2E}%i", otherName, amount);
							SendClientMessage(playerid, COLOR_WHITE, message);
							SetPlayerWantedLevel(otherID, amount);
							newPlayerColour(otherID);
							
							format(message2, sizeof(message), "{B7B7B7}[INFO] {FFFFFF}Your wanted level has been set to {FFDC2E}%i", amount);
							SendClientMessage(otherID, COLOR_WHITE, message2);
							
							new log[250];
							format(log, sizeof(log), "%s(%i) set %s(%i)'s wanted level to %i", playerData[playerid][tempAdminName], playerid, otherName, otherID, amount);
							SendAdminText(playerid, log);	
						}
						else if(!strcmp(selection, "level", true))
						{
							if(amount < 8)
							{
								playerData[otherID][playerLevel] = amount;
								format(message, sizeof(message), "{B7B7B7}[RCON] {FFFFFF}You set {FFDC2E}%s's {FFFFFF}level to {FFDC2E}%i", otherName, amount);
								SendClientMessage(playerid, COLOR_WHITE, message);
								
								format(message2, sizeof(message), "{B7B7B7}[INFO] {FFFFFF}Your admin level has been set to {FFDC2E}%i", amount);
								SendClientMessage(otherID, COLOR_WHITE, message2);
								
								new log[250];
								format(log, sizeof(log), "%s(%i) set %s(%i)'s admin level to %i", playerData[playerid][tempAdminName], playerid, otherName, otherID, amount);
								SendAdminText(playerid, log);	
							}
							else
							{
								format(message, sizeof(message), "{B7B7B7}[SERVER] {FFFFFF}The highest level is 7.");
								SendClientMessage(playerid, COLOR_WHITE, message);
							}
						}
						else if(!strcmp(selection, "slevel", true))
						{
							if(amount < 8)
							{
								playerData[otherID][playerLevel] = amount;
								format(message, sizeof(message), "{B7B7B7}[RCON] {FFFFFF}You set {FFDC2E}%s's {FFFFFF}level to {FFDC2E}%i", otherName, amount);
								SendClientMessage(playerid, COLOR_WHITE, message);
								
								format(message2, sizeof(message), "{B7B7B7}[INFO] {FFFFFF}Your admin level has been set to {FFDC2E}%i {FFFFFF}by {FFDC2E}%s(%i)", amount, playerData[playerid][tempAdminName], playerid);
								SendClientMessage(otherID, COLOR_WHITE, message2);
							}
							else
							{
								format(message, sizeof(message), "{B7B7B7}[SERVER] {FFFFFF}The highest level is 7.");
								SendClientMessage(playerid, COLOR_WHITE, message);
							}
						}
						else if(!strcmp(selection, "vip", true))
						{
							if(amount < 5)
							{
								playerData[otherID][playerVIPLevel] = amount;
								format(message, sizeof(message), "{B7B7B7}[RCON] {FFFFFF}You set {FFDC2E}%s's {FFFFFF}VIP level to {FFDC2E}%i", otherName, amount);
								SendClientMessage(playerid, COLOR_WHITE, message);
								
								format(message2, sizeof(message), "{B7B7B7}[INFO] {FFFFFF}Your V.I.P level has been set to {FFDC2E}%i", amount);
								SendClientMessage(otherID, COLOR_WHITE, message2);
								
								new log[250];
								format(log, sizeof(log), "%s(%i) set %s(%i)'s VIP level to %i", playerData[playerid][tempAdminName], playerid, otherName, otherID, amount);
								SendAdminText(playerid, log);	
							}
							else
							{
								format(message, sizeof(message), "{B7B7B7}[SERVER] {FFFFFF}The highest level is 4.");
								SendClientMessage(playerid, COLOR_WHITE, message);
							}
						}
						else if(!strcmp(selection, "helper", true))
						{
							if(amount == 1)
							{
								playerData[otherID][playerHelper] = amount;
								format(message, sizeof(message), "{B7B7B7}[RCON] {FFFFFF}You promoted {FFDC2E}%s {FFFFFF}to a helper.", otherName);
								SendClientMessage(playerid, COLOR_WHITE, message);
								
								format(message2, sizeof(message), "{B7B7B7}[INFO] {FFFFFF}You have been promoted to a {FFDC2E}helper {FFFFFF}by {FFDC2E}%s(%i)", playerData[playerid][tempAdminName], playerid);
								SendClientMessage(otherID, COLOR_WHITE, message2);
								
								new log[250];
								format(log, sizeof(log), "%s(%i) promoted %s(%i) to a helper", playerData[playerid][tempAdminName], playerid, otherName, otherID);
								SendAdminText(playerid, log);	
							}
							if(amount == 2)
							{
								playerData[otherID][playerHelper] = amount;
								format(message, sizeof(message), "{B7B7B7}[RCON] {FFFFFF}You promoted {FFDC2E}%s {FFFFFF}to a head helper.", otherName);
								SendClientMessage(playerid, COLOR_WHITE, message);
								
								format(message2, sizeof(message), "{B7B7B7}[INFO] {FFFFFF}You have been promoted to a {FFDC2E}head helper {FFFFFF}by {FFDC2E}%s(%i)", playerData[playerid][tempAdminName], playerid);
								SendClientMessage(otherID, COLOR_WHITE, message2);
								
								new log[250];
								format(log, sizeof(log), "%s(%i) promoted %s(%i) to a head helper", playerData[playerid][tempAdminName], playerid, otherName, otherID);
								SendAdminText(playerid, log);	
							}
							else if(amount == 0)
							{
								playerData[otherID][playerHelper] = amount;
								format(message, sizeof(message), "{B7B7B7}[RCON] {FFFFFF}You have removed {FFDC2E}%s's {FFFFFF}helper status.", otherName);
								SendClientMessage(playerid, COLOR_WHITE, message);
								
								format(message2, sizeof(message), "{B7B7B7}[INFO] {FFFFFF}You are no longer a helper.");
								SendClientMessage(otherID, COLOR_WHITE, message2);
								
								new log[250];
								format(log, sizeof(log), "%s(%i) removed %s(%i)'s helper status", playerData[playerid][tempAdminName], playerid, otherName, otherID);
								SendAdminText(playerid, log);	
							}
							else
							{
								format(message, sizeof(message), "{B7B7B7}[SERVER] {FFFFFF}You may only promote (1) or demote (0)");
								SendClientMessage(playerid, COLOR_WHITE, message);
							}
						}
						else if(!strcmp(selection, "job", true))
						{
							if(amount < 7)
							{
								playerData[otherID][playerJob] = amount;
								format(message, sizeof(message), "{B7B7B7}[RCON] {FFFFFF}You set {FFDC2E}%s's {FFFFFF}job to {FFDC2E}%i", otherName, amount);
								SendClientMessage(playerid, COLOR_WHITE, message);
								
								format(message2, sizeof(message), "{B7B7B7}[INFO] {FFFFFF}Your job ID has been set to {FFDC2E}%i", amount);
								SendClientMessage(otherID, COLOR_WHITE, message2);
								
								new log[250];
								format(log, sizeof(log), "%s(%i) set %s(%i)'s job id to %i", playerData[playerid][tempAdminName], playerid, otherName, otherID, amount);
								SendAdminText(playerid, log);	
							}
							else
							{
								format(message, sizeof(message), "{B7B7B7}[SERVER] {FFFFFF}The highest job is 6.");
								SendClientMessage(playerid, COLOR_WHITE, message);
							}
						}
						else if(!strcmp(selection, "xp", true))
						{
							playerData[otherID][playerXP] = amount;
							format(message, sizeof(message), "{B7B7B7}[RCON] {FFFFFF}You set {FFDC2E}%s's {FFFFFF}XP to {FFDC2E}%i", otherName, amount);
							SendClientMessage(playerid, COLOR_WHITE, message);
							
							format(message2, sizeof(message), "{B7B7B7}[INFO] {FFFFFF}Your XP has been set to {FFDC2E}%i", amount);
							SendClientMessage(otherID, COLOR_WHITE, message2);
							
							playerGiveXP(otherID, 0);
							
							if (playerData[playerid][playerLevel] != 7)
							{
								new log[250];
								format(log, sizeof(log), "%s(%i) set %s(%i)'s XP to %i", playerData[playerid][tempAdminName], playerid, otherName, otherID, amount);
								SendAdminText(playerid, log);	
							}
						}
						else
						{
							format(message, sizeof(message), "[{B7B7B7}[SERVER] {FFFFFF}You have made an invalid selection, please choose either Score, Money, Kills, Death or Level.");
							SendClientMessage(playerid, COLOR_WHITE, message); 
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:data(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			new otherID;

			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"data <playername/id>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
						new 
							title[100],
							listing[2000]
						;
						
						// FFBF00
						
						format(listing, sizeof(listing), "{FFBF00}Main Stats{FFFFFF}");
						format(listing, sizeof(listing), "%s\n{FE9A2E}Player Level: {FFFFFF}%i", listing, playerData[otherID][playerLevel]);
						format(listing, sizeof(listing), "%s\n{FE9A2E}Player Money: {FFFFFF}%s", listing, FormatNumber(playerData[otherID][playerMoney]));
						format(listing, sizeof(listing), "%s\n{FE9A2E}Player Score: {FFFFFF}%s", listing, FormatNumber(playerData[otherID][playerScore]));
						format(listing, sizeof(listing), "%s\n{FE9A2E}Player XP: {FFFFFF}%s", listing, FormatNumber(playerData[otherID][playerXP]));
						format(listing, sizeof(listing), "%s\n{FE9A2E}Wanted Level: {FFFFFF}%i", listing, playerData[otherID][playerWantedLevel]);
						
						format(listing, sizeof(listing), "%s\n  ", listing);
						format(listing, sizeof(listing), "%s\n\n{FFBF00}Server Data{FFFFFF}", listing);
						format(listing, sizeof(listing), "%s\n{FE9A2E}Interior ID: {FFFFFF}%i", listing, playerData[otherID][playerInterior]);
						format(listing, sizeof(listing), "%s\n{FE9A2E}Virtual World: {FFFFFF}%i", listing, playerData[otherID][playerVWorld]);
						format(listing, sizeof(listing), "%s\n{FE9A2E}Mute Time: {FFFFFF}%i", listing, playerData[otherID][playerMuteTime]);
						format(listing, sizeof(listing), "%s\n{FE9A2E}Admin Duty: {FFFFFF}%i", listing, playerData[otherID][playerAdminDuty]);
						format(listing, sizeof(listing), "%s\n{FE9A2E}Can See Alog: {FFFFFF}%i", listing, playerData[otherID][showALog]);
						format(listing, sizeof(listing), "%s\n{FE9A2E}Inside Event: {FFFFFF}%i", listing, playerData[otherID][isInEvent]);
						format(listing, sizeof(listing), "%s\n{FE9A2E}Has Spawned: {FFFFFF}%i", listing, playerData[otherID][hasSpawned]);
						format(listing, sizeof(listing), "%s\n{FE9A2E}Custom Skin ID: {FFFFFF}%i", listing, playerData[otherID][playerCustomSkin]);
						format(listing, sizeof(listing), "%s\n{FE9A2E}Job ID: {FFFFFF}%i", listing, playerData[otherID][playerJob]);
						
						format(listing, sizeof(listing), "%s\n   ", listing);
						format(listing, sizeof(listing), "%s\n\n{FFBF00}Basic Inventory{FFFFFF}", listing);
						format(listing, sizeof(listing), "%s\n{FE9A2E}Rope: {FFFFFF}%i", listing, playerData[otherID][playerRope]);
						format(listing, sizeof(listing), "%s\n{FE9A2E}Scissors: {FFFFFF}%i", listing, playerData[otherID][playerScissors]);
						format(listing, sizeof(listing), "%s\n{FE9A2E}Butt Plugs: {FFFFFF}%i", listing, playerData[otherID][playerButtPlug]);
						format(listing, sizeof(listing), "%s\n{FE9A2E}Bigger Pockets (1/0): {FFFFFF}%i", listing, playerData[otherID][playerBiggerPockets]);
						format(listing, sizeof(listing), "%s\n{FE9A2E}Secure Wallet (1/0): {FFFFFF}%i", listing, playerData[otherID][playerSecureWallet]);
						format(listing, sizeof(listing), "%s\n   ", listing);
						format(listing, sizeof(listing), "%s\n   ", listing);
						
						format(title, sizeof(title), "%s's Stats", playerData[otherID][playerNamee]);
						ShowPlayerDialog(playerid, DIALOG_ACHIEVEMENTS, DIALOG_STYLE_LIST, title, listing, "OK", "Close");
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
				}
			}
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
	
	return 1;
}

COMMAND:playerstats(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 1)
		{
			new otherID;

			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"playerstats <playername/id>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
						playerData[playerid][playerGetStats] = otherID;

						new 
							lookAt,
							title[100]
						;
						
						lookAt = playerData[playerid][playerGetStats];
						
						format(title, sizeof(title), "%s's Statistics", playerData[lookAt][playerNamee]);
						ShowPlayerDialog(playerid, DIALOG_ADMINSTATS, DIALOG_STYLE_LIST, title, "Player Statistics \nPolice Statistics \nCrime Statistics \nMission Statistics", "View", "Cancel");
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
				}
			}
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
	return 1;
}

COMMAND:acmds(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 1)
		{
			new string[1400];
            format(string, sizeof(string), "%s{98B0CD}LEVEL 1 COMMANDS{B4DAD9}\n/goto /aod /kick /jail /asay /spawn /slap /warn\n/(un)freeze /playerstats /spec /specoff /rarb\n\n", string);
			format(string, sizeof(string), "%s{98B0CD}LEVEL 2 COMMANDS{B4DAD9}\n/alog /explode /vrespawn /Duel /(un)mute\n/playerweapons /arenas /blockask /blockreport\n\n", string);
			format(string, sizeof(string), "%s{98B0CD}LEVEL 3 COMMANDS{B4DAD9}\n/ban /vc(create) /setskin /vdestroy /get /vgoto /vbring /resetweapons\n/forcerules /forcecoptutorial /clearchat\n/aheal /playertokens /playervehicles /playertokens \n/playerjailtime /playerjob\n\n", string);
			format(string, sizeof(string), "%s{98B0CD}LEVEL 4 COMMANDS{B4DAD9}\n//unban /un)copban /resetskin <player id> /getip /respawnalluv /(un)armyban /destroyallav \n/announce /pmspy /dmevent /startdm /glassevent\n/startglass /destroyglass /falloutevent /startfallout /destroyfallout /adkill /uncuff\n\n", string);
			format(string, sizeof(string), "%s{98B0CD}LEVEL 5 COMMANDS{B4DAD9}\n/ahealall /giveallweapon /createhouse /deletehouse  /giveweapon /respawnallv /resetallweapons \n/pingimmune /gotomoneybag /startmoneybag /houseinfo\n\n", string);
			format(string, sizeof(string), "%s{98B0CD}LEVEL 6 COMMANDS{B4DAD9}\n/teleport /doublexp /motd /motd(1-3) /ping /fine \n/playerhouses /standardvip \n/silvervip /goldvip /givetoken /givecash \n/givexp /b", string);
			
			ShowPlayerDialog(playerid, 200, DIALOG_STYLE_MSGBOX, "Admin Commands", string, "OK", "");
			
			return 1;
		}
	}
	return 0;
}

COMMAND:hcmds(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerHelper] >= 1)
		{
			new string[1400];
            format(string, sizeof(string), "%s{98B0CD}LEVEL 1 COMMANDS{B4DAD9}\n/h /hgoto /hbring /ans /hsay\n\n", string);
			format(string, sizeof(string), "%s{98B0CD}LEVEL 2 COMMANDS{B4DAD9}\n/hpromote /hdemote", string);
			
			ShowPlayerDialog(playerid, 200, DIALOG_STYLE_MSGBOX, "Helper Commands", string, "OK", "");
			
			return 1;
		}
	}
	return 0;
}

// Helper Commands
COMMAND:h(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
  	    if(playerData[playerid][playerLevel] >= 1 || playerData[playerid][playerHelper] >= 1)
  	    {
            new message[280];
            if(sscanf(params, "s[280]", message))
            {
                // Invalid command syntax
                SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"h <message>\"");
            }
            else
            {
				for (new i=0; i<MAX_PLAYERS; i++)
				{
					if (playerData[i][playerLevel] >= 1 || playerData[i][playerHelper] >= 1)
					{
						new achat[300];
						format(achat, sizeof(achat), "{FFBF00}<Helper Chat> {FFFFFF}%s: %s", playerData[playerid][tempAdminName], message);
						SendClientMessage(i, COLOR_WHITE, achat);
					}
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
	return 1;
}

COMMAND:hsay(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerHelper] >= 1)
		{
			new message[100];
		
			if(sscanf(params, "s[100]", message))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"hsay <message>\"");
			}
			else
			{
				if (playerData[playerid][playerHelper] == 1)
				{
					format(message, sizeof(message), "{FFBF00}(Helper) %s(%i): {FFFFFF}%s", playerData[playerid][tempAdminName], playerid, message);
					SendClientMessageToAll(COLOR_WHITE, message);		
				}
				else if (playerData[playerid][playerHelper] == 2)
				{
					format(message, sizeof(message), "{FFBF00}(Head Helper) %s(%i): {FFFFFF}%s", playerData[playerid][tempAdminName], playerid, message);
					SendClientMessageToAll(COLOR_WHITE, message);		
				}				
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This command can only be used by server helpers.");
		}
	}

	return 1;
}

COMMAND:hgoto(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerHelper] >= 1)
		{
			new Float:x, Float:y, Float:z, otherID, otherName[24], message[128], iWorld, vWorld;
		
			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"hgoto <playername/id>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
						
						GetPlayerPos(otherID, x, y, z);
						iWorld = GetPlayerInterior(otherID);
						vWorld = GetPlayerVirtualWorld(otherID);
						
						SetPlayerPos(playerid, x - 3.0, y - 3.0, z + 1.0);
						SetPlayerVirtualWorld(playerid, vWorld);
						SetPlayerInterior(playerid, iWorld);
						
						GetPlayerName(otherID, otherName, sizeof(otherName));
						format(message, sizeof(message), "{FFBF00}[HELPER] {FFFFFF}You have teleported to %s!", otherName);
						SendClientMessage(playerid, COLOR_WHITE, message);
						
						new log[250];
						format(log, sizeof(log), "(HELPER) %s(%i) has teleported to %s(%i)", playerData[playerid][tempAdminName], playerid, otherName, otherID);
						SendAdminText(playerid, log);
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:hbring(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerHelper] >= 1)
		{
			new Float:x, Float:y, Float:z, otherID, otherName[24], message[128], iWorld, vWorld;

			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"hbring <playername/id>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
					    if(playerData[playerid][playerLevel] >= playerData[otherID][playerLevel])
						{
							if (playerData[otherID][playerWantedLevel] == 0)
							{
								GetPlayerPos(playerid, x, y, z);
								iWorld = GetPlayerInterior(playerid);
								vWorld = GetPlayerVirtualWorld(playerid);
								
								SetPlayerPos(otherID, x - 3.0, y - 3.0, z + 1.0);
								SetPlayerVirtualWorld(otherID, vWorld);
								SetPlayerInterior(otherID, iWorld);
								
								GetPlayerName(otherID, otherName, sizeof(otherName));
								format(message, sizeof(message), "{FFBF00}[HELPER] {FFFFFF}%s has been teleported to you!", otherName);
								SendClientMessage(playerid, COLOR_WHITE, message);
								
								new log[250];
								format(log, sizeof(log), "(HELPER) %s(%i) has brought %s(%i)", playerData[playerid][tempAdminName], playerid, otherName, otherID);
								SendAdminText(playerid, log);
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot bring wanted players.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use this command on that player.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:hpromote(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerHelper] >= 2)
		{
			new otherID, message[128], message2[128];

			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"hpromote <playername/id>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
						if (playerData[otherID][playerHelper] == 0)
						{
							playerData[otherID][playerHelper] = 1;

							format(message, sizeof(message), "{FFBF00}[HELPER] {FFFFFF}You promoted %s(%i) to a helper.", playerData[otherID][playerNamee], otherID);
							SendClientMessage(playerid, COLOR_WHITE, message);
							
							format(message2, sizeof(message2), "{FFBF00}[HELPER] {FFFFFF}%s(%i) promoted you to a helper.", playerData[playerid][tempAdminName], playerid);
							SendClientMessage(otherID, COLOR_WHITE, message);
							
							new log[250];
							format(log, sizeof(log), "(HELPER) %s(%i) has promoted %s(%i) to helper.", playerData[playerid][tempAdminName], playerid, playerData[otherID][playerNamee], otherID);
							SendAdminText(playerid, log);
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is already a helper!");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:hdemote(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerHelper] >= 2)
		{
			new otherID, message[128], message2[128];

			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"hdemote <playername/id>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
						if (playerData[otherID][playerHelper] == 1)
						{
							playerData[otherID][playerHelper] = 0;

							format(message, sizeof(message), "{FFBF00}[HELPER] {FFFFFF}You removed %s(%i) from the server helpers.", playerData[otherID][playerNamee], otherID);
							SendClientMessage(playerid, COLOR_WHITE, message);
							
							format(message2, sizeof(message2), "{FFBF00}[HELPER] {FFFFFF}%s(%i) has removed you from the server helpers.", playerData[playerid][tempAdminName], playerid);
							SendClientMessage(otherID, COLOR_WHITE, message);
							
							new log[250];
							format(log, sizeof(log), "(HELPER) %s(%i) has demoted %s(%i) to a player.", playerData[playerid][tempAdminName], playerid, playerData[otherID][playerNamee], otherID);
							SendAdminText(playerid, log);
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player cannot be demoted.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

// End helper commands

COMMAND:aod(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 1)
		{
			// If AdminDuty is 1
			if (!playerData[playerid][playerAdminDuty])
			{
				SendClientMessage(playerid, COLOR_WHITE, "{FE9A2E}[ADMIN] {FFFFFF}You're now an on duty administrator.");
				playerData[playerid][playerAdminDuty] = true;
				playerData[playerid][playerAdminLabel] = Create3DTextLabel("Admin on Duty", 0x47476Bff, 30.0, 40.0, 50.0, 60.0, -1, 1);
				Attach3DTextLabelToPlayer(playerData[playerid][playerAdminLabel], playerid, 0.0, 0.0, 0.4);

				// Give them infinite health.
				SetPlayerHealth(playerid, 99999999);
				SetPlayerColor(playerid, 0x47476B);
				TextDrawShowForPlayer(playerid, Text:AdminDuty);
			}
			else
			{
				// Admin is already on duty, so we'll now put them off duty
				SendClientMessage(playerid, COLOR_WHITE, "{FE9A2E}[ADMIN] {FFFFFF}You're now an off duty administrator.");
				playerData[playerid][playerAdminDuty] = false;
				Delete3DTextLabel(playerData[playerid][playerAdminLabel]);
			
				// Give them default health
				SetPlayerHealth(playerid, 100);
				newPlayerColour(playerid);
				TextDrawHideForPlayer(playerid, Text:AdminDuty);
			}
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

COMMAND:saveallstats(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			for(new i = 0; i < MAX_PLAYERS; i++)
			{
				if(IsPlayerConnected(i))
				{
					if(playerData[i][playerLoggedIn])
					{
						savePlayerStats(i);
					}
				}
			}
			
			SendClientMessage(playerid, COLOR_WHITE, "Saved all.");
		}
    }
    
    return 1;
}

COMMAND:asay(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 1)
		{
			new input[100], message[250];

			if(sscanf(params, "s[100]", input))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"asay <message>\"");
			}
			else
			{
				format(message, sizeof(message), "{FE9A2E}[ADMIN] {FFFFFF}%s", input);
				SendClientMessageToAll(COLOR_WHITE, message);		

				new log[250];
				format(log, sizeof(log), "%s(%i) used /asay", playerData[playerid][tempAdminName], playerid);
				SendAdminText(playerid, log);				
			}
		}
	}
	return 1;
}

COMMAND:faketip(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			new input[100], message[250];

			if(sscanf(params, "s[100]", input))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"faketip <message>\"");
			}
			else
			{
				format(message, sizeof(message), "{FE9A2E}[TIP] {FFFFFF}%s", input);
				SendClientMessageToAll(COLOR_WHITE, message);		

				new log[250];
				format(log, sizeof(log), "%s(%i) used /faketip", playerData[playerid][tempAdminName], playerid);
				SendAdminText(playerid, log);				
			}
		}
	}
	return 1;
}

COMMAND:motd(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			if (serverInfo[enableMOTD])
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}MOTD disabled.");
				serverInfo[enableMOTD] = false;
				swapMOTD();
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}MOTD enabled.");
				serverInfo[enableMOTD] = true;
				swapMOTD();
			}
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

COMMAND:swapmotd(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			if (serverInfo[enableMOTD])
			{
				swapMOTD();
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}MOTD is not enabled, type /motd first.");
			}
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

COMMAND:motd1(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			new input[128];

			if(sscanf(params, "s[100]", input))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"motd1 <message>\"");
			}
			else
			{
				serverInfo[MOTD1] = input;
				swapMOTD(); 
			}
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

COMMAND:motd2(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			new input[128];

			if(sscanf(params, "s[100]", input))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"motd2 <message>\"");
			}
			else
			{
				serverInfo[MOTD2] = input;
				swapMOTD();
			}
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

COMMAND:motd3(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			new input[128];

			if(sscanf(params, "s[100]", input))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"motd3 <message>\"");
			}
			else
			{
				serverInfo[MOTD3] = input;
				swapMOTD();
			}
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

COMMAND:ping(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 6)
		{
			new input, message[350];

			if(sscanf(params, "i", input))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"ping <max>\"");
			}
			else
			{
				format(message, sizeof(message), "{FE9A2E}[PING LIMIT] {FFFFFF}Maximum ping limit increased to %i.", input);
				SendClientMessageToAll(COLOR_WHITE, message);		
				serverInfo[maxPing] = input;
				
				new log[250];
				format(log, sizeof(log), "%s(%i) set the max ping to %i", playerData[playerid][tempAdminName], playerid, input);
				SendAdminText(playerid, log);
			}
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

COMMAND:pingimmune(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			new otherID, message[350], message2[350];

			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"pingimmune <playerid>\"");
			}
			else
			{
				format(message, sizeof(message), "{FE9A2E}[PING IMMUNE] {FFFFFF}An administrator has made you immune to high ping kicks.");
				SendClientMessage(otherID, COLOR_WHITE, message);		
				
				format(message2, sizeof(message2), "{FE9A2E}[PING IMMUNE] {FFFFFF}You have made %s(%i) immune to high ping kicks.", playerData[otherID][playerNamee], otherID);
				SendClientMessage(playerid, COLOR_WHITE, message2);		
				
				playerData[otherID][playerPingImmune] = true;
				
				new log[250];
				format(log, sizeof(log), "%s(%i) made %s(%i) ping immune.", playerData[playerid][tempAdminName], playerid, playerData[otherID][playerNamee], otherID);
				SendAdminText(playerid, log);
			}
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

COMMAND:alog(playerid, params[])
{
	if(playerData[playerid][playerLevel] >= 2)
	{
		if(playerData[playerid][showALog])
		{
			TextDrawHideForPlayer(playerid, alog1);
			TextDrawHideForPlayer(playerid, alog2);
			TextDrawHideForPlayer(playerid, alog3);
			TextDrawHideForPlayer(playerid, alog4);
			TextDrawHideForPlayer(playerid, alog5);
			playerData[playerid][showALog] = false;
			SendClientMessage(playerid, COLOR_WHITE, "{FE9A2E}[ADMIN] {FFFFFF}You have disabled the admin log.");
		}
		else
		{
			TextDrawShowForPlayer(playerid, alog1);
			TextDrawShowForPlayer(playerid, alog2);
			TextDrawShowForPlayer(playerid, alog3);
			TextDrawShowForPlayer(playerid, alog4);
			TextDrawShowForPlayer(playerid, alog5);
			SendClientMessage(playerid, COLOR_WHITE, "{FE9A2E}[ADMIN] {FFFFFF}You have enabled the admin log.");
			playerData[playerid][showALog] = true;
		}
		return 1;
	}
	return 0;
}

COMMAND:clearchat(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 3)
		{
			for(new i = 0; i < 50; i++) 
			{
			    SendClientMessageToAll(COLOR_WHITE," ");
			}
			
			SendClientMessageToAll(COLOR_WHITE, "{A9C4E4}An administrator has cleared the chat.");	

			new log[250];
			format(log, sizeof(log), "%s(%i) cleared the chat", playerData[playerid][tempAdminName], playerid);
			SendAdminText(playerid, log);			
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

COMMAND:cc(playerid, params[])
{
	return cmd_clearchat(playerid, params);
}

COMMAND:forcerules(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 3)
		{
			new otherID;
			
			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"forcerules <playername/id>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
						if(playerData[playerid][playerLevel] >= playerData[otherID][playerLevel])
						{
							new string[1200], message2[200];
							format(string, sizeof(string), "%s{98B0CD}1. {FFFFFF}Respect players and admins. \n", string);
							format(string, sizeof(string), "%s{98B0CD}2. {FFFFFF}Do not heli-blade. \n", string);
							format(string, sizeof(string), "%s{98B0CD}3. {FFFFFF}Do not flood the chat, or advertise other servers. \n", string);
							format(string, sizeof(string), "%s{98B0CD}4. {FFFFFF}Hacking/Cheating will get you banned. \n", string);
							format(string, sizeof(string), "%s{98B0CD}5. {FFFFFF}LEO players must not kill innocent civilians. \n", string);
							format(string, sizeof(string), "%s{98B0CD}6. {FFFFFF}Team killing is not allowed. \n", string);
							format(string, sizeof(string), "%s{98B0CD}7. {FFFFFF}Do not tie abuse (leaving a player once tied) \n", string);
							format(string, sizeof(string), "%s{98B0CD}8. {FFFFFF}If you are a LEO, do not assist criminals. \n", string);
							format(string, sizeof(string), "%s{98B0CD}9. {FFFFFF}Do not EMP vehicles if there are no wanted players inside. \n", string);
							format(string, sizeof(string), "%s{98B0CD}10. {FFFFFF}Do not quit or pause to avoid anything. You will be jailed for this.\n", string);
							format(string, sizeof(string), "%s{98B0CD}11. {FFFFFF}Park your owned vehicle in a sensible spot, preferably at your home. \n", string);
							format(string, sizeof(string), "%s{98B0CD}12. {FFFFFF}Farming score/xp/money is unacceptable, you will be banned for this. \n", string);
							format(string, sizeof(string), "%s{98B0CD}13. {FFFFFF}Do not drive-by without a driver. \n", string);
							format(string, sizeof(string), "%s{98B0CD}14. {FFFFFF}The scam limit is $8,000. \n", string);
							format(string, sizeof(string), "%s{98B0CD}15. {FFFFFF}Do not question administrative actions. \n", string);
							format(string, sizeof(string), "%s{98B0CD}16. {FFFFFF}Bugs should be reported, not exploited. \n", string);
							
							ShowPlayerDialog(otherID, DIALOG_RULES, DIALOG_STYLE_MSGBOX, "Rules", string, "OK", "");
							
							// SCM
							SendClientMessage(otherID, COLOR_WHITE, "{A9C4E4}An administrator has shown you the rules.");
							
							format(message2, sizeof(message2), "{FE9A2E}[ADMIN] {FFFFFF}You have shown the rules to %s(%i)!", playerData[otherID][playerNamee], otherID);
							SendClientMessage(playerid, COLOR_WHITE, message2);
							
							new log[250];
							format(log, sizeof(log), "%s(%i) has shown %s(%i) the rules", playerData[playerid][tempAdminName], playerid, playerData[otherID][playerNamee], otherID);
							SendAdminText(playerid, log);
						}
						else
						{
						    SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use this command on that player.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
	
	return 1;
}

COMMAND:forcecoptutorial(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 3)
		{
			new otherID;
			
			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"forcecoptutorial <playername/id>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
						if(playerData[playerid][playerLevel] >= playerData[otherID][playerLevel])
						{
							SetPlayerVirtualWorld(otherID, 2);
							SetPlayerCameraPos(otherID, -1581.7755, 749.6948, 30.6389);
							SetPlayerCameraLookAt(otherID, -1605.5656, 717.6979, 11.9861);
							
							// Part 1 of the tutorial
							new string[600], message2[200];
							format(string, sizeof(string), "%s{98B0CD}Police Classes \n", string);
							format(string, sizeof(string), "%s{FFFFFF}Playing as a law enforcement officer on this server is similar to other CNR game modes.\n", string);
							format(string, sizeof(string), "%s{FFFFFF}For those who aren't familiar with the commands, please see /commands after this tutorial\n", string);
							format(string, sizeof(string), "%s{FFFFFF}has concluded. This tutorial will act as a simple guide on how to act whilst playing as a cop.\n\n", string);
							
							format(string, sizeof(string), "%s{FFFFFF}There are 4 LEO classes. These include cop, CIA, FBI and army, \nthough army has seperate rules.", string);
							format(string, sizeof(string), "%s{FFFFFF}Each class requires an increased amount of XP,\nwhich can be seen when trying to spawn to a class.\n", string);

							ShowPlayerDialog(otherID, POLICE_TUTORIAL_1, DIALOG_STYLE_MSGBOX, "Police Tutorial - Introduction", string, "Next", "");
							
							SendClientMessage(otherID, COLOR_WHITE, "{A9C4E4}An administrator has forced you to read the police tutorial.");
							
							format(message2, sizeof(message2), "{FE9A2E}[ADMIN] {FFFFFF}You have forced %s(%i) to view the police tutorial!", playerData[otherID][playerNamee], otherID);
							SendClientMessage(playerid, COLOR_WHITE, message2);
							
							new log[250];
							format(log, sizeof(log), "%s(%i) has forced %s(%i) to view the police tutorial!", playerData[playerid][tempAdminName], playerid, playerData[otherID][playerNamee], otherID);
							SendAdminText(playerid, log);
						}
						else
						{
						    SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use this command on that player.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
	
	return 1;
}

COMMAND:freeze(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 1)
		{
			new otherID, otherName[24];

			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"freeze <playername/id>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
					    if(playerData[playerid][playerLevel] >= playerData[otherID][playerLevel])
						{
							GetPlayerName(otherID, otherName, sizeof(otherName));
							
							new message[128];
							format(message, sizeof(message), "{FE9A2E}[ADMIN] {FFFFFF}You have frozen %s(%i)!", otherName, otherID);
							SendClientMessage(playerid, COLOR_WHITE, message);
							
							SendClientMessage(otherID, COLOR_WHITE, "{A9C4E4}An administrator has frozen you.");
							
							TogglePlayerControllable(otherID, 0);
							
							new log[250];
							format(log, sizeof(log), "%s(%i) has frozen %s(%i)", playerData[playerid][tempAdminName], playerid, otherName, otherID);
							SendAdminText(playerid, log);
						}
						else
						{
						    SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use this command on that player.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:unfreeze(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 1)
		{
			new otherID, otherName[24];

			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"unfreeze <playername/id>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
					    if(playerData[playerid][playerLevel] >= playerData[otherID][playerLevel])
						{
							GetPlayerName(otherID, otherName, sizeof(otherName));
							
							new message[128];
							format(message, sizeof(message), "{FE9A2E}[ADMIN] {FFFFFF}You have unfrozen %s(%i)!", otherName, otherID);
							SendClientMessage(playerid, COLOR_WHITE, message);
							
							SendClientMessage(otherID, COLOR_WHITE, "{A9C4E4}An administrator has unfrozen you.");
							
							TogglePlayerControllable(otherID, 1);
							
							new log[250];
							format(log, sizeof(log), "%s(%i) has unfrozen %s(%i)", playerData[playerid][tempAdminName], playerid, otherName, otherID);
							SendAdminText(playerid, log);
						}
						else
						{
						    SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use this command on that player.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:adkill(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 4)
		{
			new otherID, otherName[24];

			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"adkill <playername/id>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
					    if(playerData[playerid][playerLevel] >= playerData[otherID][playerLevel])
						{
							GetPlayerName(otherID, otherName, sizeof(otherName));
							
							new message[128];
							format(message, sizeof(message), "{FE9A2E}[ADMIN] {FFFFFF}You have slain %s(%i)!", otherName, otherID);
							SendClientMessage(playerid, COLOR_WHITE, message);
							
							SendClientMessage(otherID, COLOR_WHITE, "{A9C4E4}An administrator has killed you.");
							
							playerData[otherID][suicide] = true;
							SetPlayerHealth(otherID, 0);
							
							new log[250];
							format(log, sizeof(log), "%s(%i) has slain %s(%i)", playerData[playerid][tempAdminName], playerid, otherName, otherID);
							SendAdminText(playerid, log);
						}
						else
						{
						    SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use this command on that player.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:get(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 3)
		{
			new Float:x, Float:y, Float:z, otherID, otherName[24], message[128], iWorld, vWorld;

			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"get <playername/id>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
						if (!playerData[otherID][playerIsSpectating])
						{
							if(playerData[playerid][playerLevel] >= playerData[otherID][playerLevel])
							{
								GetPlayerPos(playerid, x, y, z);
								iWorld = GetPlayerInterior(playerid);
								vWorld = GetPlayerVirtualWorld(playerid);
								
								SetPlayerPos(otherID, x - 3.0, y - 3.0, z + 1.0);
								SetPlayerVirtualWorld(otherID, vWorld);
								SetPlayerInterior(otherID, iWorld);
								
								GetPlayerName(otherID, otherName, sizeof(otherName));
								format(message, sizeof(message), "{FE9A2E}[ADMIN] {FFFFFF}%s has been teleported to you!", otherName);
								SendClientMessage(playerid, COLOR_WHITE, message);
								
								new log[250];
								format(log, sizeof(log), "%s(%i) has brought %s(%i)", playerData[playerid][tempAdminName], playerid, otherName, otherID);
								SendAdminText(playerid, log);
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is spectating someone!");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use this command on that player.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:goto(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 1)
		{
			new Float:x, Float:y, Float:z, otherID, otherName[24], message[128], iWorld, vWorld;
		
			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"goto <playername/id>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
						if (!playerData[otherID][playerIsSpectating])
						{
							GetPlayerPos(otherID, x, y, z);
							iWorld = GetPlayerInterior(otherID);
							vWorld = GetPlayerVirtualWorld(otherID);
							
							SetPlayerPos(playerid, x - 3.0, y - 3.0, z + 1.0);
							SetPlayerVirtualWorld(playerid, vWorld);
							SetPlayerInterior(playerid, iWorld);
							
							GetPlayerName(otherID, otherName, sizeof(otherName));
							format(message, sizeof(message), "{FE9A2E}[ADMIN] {FFFFFF}You have teleported to %s!", otherName);
							SendClientMessage(playerid, COLOR_WHITE, message);
							
							new log[250];
							format(log, sizeof(log), "%s(%i) has teleported to %s(%i)", playerData[playerid][tempAdminName], playerid, otherName, otherID);
							SendAdminText(playerid, log);
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is spectating someone!");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:circleall(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 6)
		{
			new pClass, iWorld, vWorld;
		
			if(sscanf(params, "i", pClass))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"circleall <0/1>\"");
			}
			else
			{
				iWorld = GetPlayerInterior(playerid);
				vWorld = GetPlayerVirtualWorld(playerid);
				
				new Float:lastPosition[3];
				GetPlayerPos(playerid, lastPosition[0], lastPosition[1], lastPosition[2]);
				
				switch(pClass)
				{
					case 0: // Bring only civilian players
					{
						for(new i = 0; i < MAX_PLAYERS; i++)
						{
							if(IsPlayerConnected(i) && playerData[i][playerLoggedIn] && playerData[i][playerClass] == CLASS_CIVILIAN && !playerData[i][playerStopEvents] && playerData[i][playerJailTime] < 1)
							{
								lastPosition[0] += 3;
								lastPosition[1] += 3;
								
								SetPlayerPos(i, lastPosition[0], lastPosition[1], lastPosition[2] + 1.0);
								SetPlayerVirtualWorld(i, vWorld);
								SetPlayerInterior(i, iWorld);
								playerData[i][isInEvent] = true;
							}
						}
					}
					
					case 1: // Bring both civilian players & leos
					{
						for(new i = 0; i < MAX_PLAYERS; i++)
						{
							if(IsPlayerConnected(i) && playerData[i][playerLoggedIn] && !playerData[i][playerStopEvents] && playerData[i][playerJailTime] < 1)
							{
								lastPosition[0] += 3;
								lastPosition[1] += 3;
								
								SetPlayerPos(i, lastPosition[0], lastPosition[1], lastPosition[2] + 1.0);
								SetPlayerVirtualWorld(i, vWorld);
								SetPlayerInterior(i, iWorld);
								playerData[i][isInEvent] = true;
							}
						}						
					}
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:jail(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 1)
		{
			// Set-up our variables etc
			new PlayerToJail, JailTime, Reason[128], Msg[328], Name[24], jailedBy[24], MsgAll[328];

			if (sscanf(params, "uis[128]", PlayerToJail, JailTime, Reason)) 
			{
				// Incorrect params used
				SendClientMessage(playerid, COLOR_ORANGE, "Usage: \"jail <PlayerToJail> <JailTime> <Reason>\"");
			}
			else
			{
				if (IsPlayerConnected(PlayerToJail)) // If the player is a valid playerid (he's connected)
				{
					if(playerData[PlayerToJail][playerLoggedIn])
					{
						if(playerData[playerid][playerLevel] >= playerData[PlayerToJail][playerLevel])
						{
							if(JailTime >= 1)
							{
								// Get the name of the player who jailed the player
								GetPlayerName(playerid, jailedBy, sizeof(jailedBy));
								
								// Get the name of the player who's being sent to jail
								GetPlayerName(PlayerToJail, Name, sizeof(Name));

								for(new p; p < MAX_PLAYERS; p++)
								{
									new pName[24];
									GetPlayerName(p, pName, sizeof(pName));
		
									if(!strcmp(pName, Name))
									{
										// Send the jailed player a message who jailed him, why he's been jailed and how long
										format(Msg, sizeof(Msg), "{A9C4E4}An administrator has jailed you for %i seconds {FE9A2E}[REASON: %s]{FFFFFF}", JailTime, Reason);
										SendClientMessage(p, COLOR_WHITE, Msg);
									}
									else
									{
										format(MsgAll, sizeof(MsgAll), "{A9C4E4}An administrator has sent %s(%i) to jail.", Name, PlayerToJail);
										SendClientMessage(p, COLOR_WHITE, MsgAll);
									}
								}
								
								new aMsg[300];
								for (new i=0; i<MAX_PLAYERS; i++)
								{
									if (playerData[i][playerLevel] >= 1)
									{
										format(aMsg, sizeof(aMsg), "{FE9A2E}[ADMIN] {FFFFFF}%s(%i) has jailed %s(%i) for %i seconds {FE9A2E}[REASON: %s]{FFFFFF}", playerData[playerid][playerNamee], playerid, playerData[PlayerToJail][playerNamee], PlayerToJail, JailTime, Reason);
										SendClientMessage(i, COLOR_WHITE, aMsg);
									}
								}		

								// Call jail function
								sendPlayerJail(PlayerToJail, JailTime, playerid, 0);
								playerData[PlayerToJail][playerAdminJailed] = 1;
								
								ShowPlayerDialog(PlayerToJail, 91827, DIALOG_STYLE_MSGBOX, "Admin Jailed", "You have been sent to jail by an administrator.", "OK", "");	
								
								new log[250];
								format(log, sizeof(log), "%s(%i) has jailed %s(%i) for %i seconds", playerData[playerid][tempAdminName], playerid, Name, PlayerToJail, JailTime);
								SendAdminText(playerid, log);
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use this command on that player.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Jail time must be at least 1 second.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}

	return 1;
}

COMMAND:copban(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 4)
		{
			new otherID, otherName[24], reason[300];

			if(sscanf(params, "u, s[200]", otherID, reason))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"copban <playername/id> <reason>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
					    if(playerData[playerid][playerLevel] >= playerData[otherID][playerLevel])
						{
							if (playerData[otherID][playerCopBanned] != 1)
							{
								GetPlayerName(otherID, otherName, sizeof(otherName));
								
								new message[328], message2[328];
								format(message, sizeof(message), "{FE9A2E}[ADMIN] {FFFFFF}You have banned %s(%i) from the LEO classes!  {FE9A2E}[REASON: %s]{FFFFFF}", otherName, otherID, reason);
								SendClientMessage(playerid, COLOR_WHITE, message);
								
								format(message2, sizeof(message2), "{A9C4E4}An administrator has banned you from the LEO classes. {FE9A2E}[REASON: %s]{FFFFFF}", reason);
								SendClientMessage(otherID, COLOR_WHITE, message2);
								
								if(playerData[otherID][playerClass] == CLASS_POLICE || playerData[otherID][playerClass] == CLASS_CIA || playerData[otherID][playerClass] == CLASS_FBI)
								{
									ForceClassSelection(otherID);
									TogglePlayerSpectating(otherID, true);
									TogglePlayerSpectating(otherID, false);
								}
								
								playerData[otherID][playerCopBanned] = 1;
								
								new log[250];
								format(log, sizeof(log), "%s(%i) has cop banned %s(%i)", playerData[playerid][tempAdminName], playerid, otherName, otherID);
								SendAdminText(playerid, log);
								
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is already cop banned.");
							}
						}
						else
						{
						    SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use this command on that player.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:uncopban(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 4)
		{
			new otherID, otherName[24];

			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"uncopban <playername/id>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
					    if(playerData[playerid][playerLevel] >= playerData[otherID][playerLevel])
						{
							if(playerData[otherID][playerCopBanned] == 1)
							{
								GetPlayerName(otherID, otherName, sizeof(otherName));
								
								new message[328];
								format(message, sizeof(message), "{FE9A2E}[ADMIN] {FFFFFF}You have unbanned %s(%i) from the LEO classes!", otherName, otherID);
								SendClientMessage(playerid, COLOR_WHITE, message);

								SendClientMessage(otherID, COLOR_WHITE, "{A9C4E4}An administrator has unbanned you from the LEO classes.");
								
								playerData[otherID][playerCopBanned] = 0;
								playerData[otherID][innocentKills] = 0;
								
								new log[250];
								format(log, sizeof(log), "%s(%i) has un-cop banned %s(%i)", playerData[playerid][tempAdminName], playerid, otherName, otherID);
								SendAdminText(playerid, log);
								
								
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not cop banned.");
							}
						}
						else
						{
						    SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use this command on that player.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:armyban(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 4)
		{
			new otherID, otherName[24], reason[200];

			if(sscanf(params, "u, s[200]", otherID, reason))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"armyban <playername/id> <reason>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
					    if(playerData[playerid][playerLevel] >= playerData[otherID][playerLevel])
						{
							if (playerData[otherID][playerArmyBanned] != 1)
							{
								GetPlayerName(otherID, otherName, sizeof(otherName));
								
								new message[128], message2[128];
								format(message, sizeof(message), "{FE9A2E}[ADMIN] {FFFFFF}You have banned %s(%i) from the army class {FE9A2E}[REASON: %s]{FFFFFF}", otherName, otherID, reason);
								SendClientMessage(playerid, COLOR_WHITE, message);
								
								format(message2, sizeof(message2), "{A9C4E4}An administrator has banned you from the army class. {FE9A2E}[REASON: %s]{FFFFFF}", reason);
								SendClientMessage(otherID, COLOR_WHITE, message2);
								
								if(playerData[otherID][playerClass] == CLASS_ARMY)
								{
									ForceClassSelection(otherID);
									SetPlayerHealth(otherID, 0);
								}
								
								playerData[otherID][playerArmyBanned] = 1;
								
								new log[250];
								format(log, sizeof(log), "%s(%i) has army banned %s(%i)", playerData[playerid][tempAdminName], playerid, otherName, otherID);
								SendAdminText(playerid, log);
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is already army banned.");
							}
						}
						else
						{
						    SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use this command on that player.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:unarmyban(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 4)
		{
			new otherID, otherName[24];

			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"unarmyban <playername/id>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
					    if(playerData[playerid][playerLevel] >= playerData[otherID][playerLevel])
						{
							if(playerData[otherID][playerArmyBanned] == 1)
							{
								GetPlayerName(otherID, otherName, sizeof(otherName));
								
								new message[128];
								format(message, sizeof(message), "{FE9A2E}[ADMIN] {FFFFFF}You have unbanned %s(%i) from the army class!", otherName, otherID);
								SendClientMessage(playerid, COLOR_WHITE, message);

								SendClientMessage(otherID, COLOR_WHITE, "{A9C4E4}An administrator has unbanned you from the army class.");
								
								playerData[otherID][playerArmyBanned] = 0;
								playerData[otherID][aInnocentKills] = 0;
								
								new log[250];
								format(log, sizeof(log), "%s(%i) has un-army banned %s(%i)", playerData[playerid][tempAdminName], playerid, otherName, otherID);
								SendAdminText(playerid, log);
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not army banned.");
							}
						}
						else
						{
						    SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use this command on that player.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:resetiks(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 4)
		{
			new otherID, message[200];
		
			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"resetiks <playername/id>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
						playerData[otherID][innocentKills] = 0;
						playerData[otherID][aInnocentKills] = 0;
						
						format(message, sizeof(message), "{FE9A2E}[ADMIN] {FFFFFF}You have reset %s(%i)'s innocent kill count.", playerData[otherID][playerNamee], otherID);
						SendClientMessage(playerid, COLOR_WHITE, message);
						
						new log[250];
						format(log, sizeof(log), "%s(%i) has reset %s(%i)'s innocent kills.", playerData[playerid][tempAdminName], playerid, playerData[otherID][playerNamee], otherID);
						SendAdminText(playerid, log);
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:resetallweapons(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			for(new i=0; i < MAX_PLAYERS; i++)
			{
				if(IsPlayerConnected(i))
				{
					if(playerData[i][playerLoggedIn])
					{
						ResetPlayerWeapons(i);
						playerData[i][adminWeapon] = false;
					}
				}
			}
			
			SendClientMessageToAll(COLOR_WHITE, "{A9C4E4}An administrator has reset all player weapons.");
			
			new log[250];
			format(log, sizeof(log), "%s(%i) has reset all player weapons", playerData[playerid][tempAdminName], playerid);
			SendAdminText(playerid, log);
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

COMMAND:resetweapons(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 3)
		{
			new otherID, otherName[24];

			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"resetweapons <playername/id>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
					    if(playerData[playerid][playerLevel] >= playerData[otherID][playerLevel])
						{
							GetPlayerName(otherID, otherName, sizeof(otherName));
							
							new message[128];
							format(message, sizeof(message), "{FE9A2E}[ADMIN] {FFFFFF}You have reset %s(%i)'s weapons!", otherName, otherID);
							SendClientMessage(playerid, COLOR_WHITE, message);
							
							SendClientMessage(otherID, COLOR_WHITE, "{A9C4E4}An administrator has reset your weapons.");
							
							ResetPlayerWeapons(otherID);
							playerData[otherID][adminWeapon] = false;
							
							new log[250];
							format(log, sizeof(log), "%s(%i) has reset %s(%i)'s weapons", playerData[playerid][tempAdminName], playerid, otherName, otherID);
							SendAdminText(playerid, log);
						}
						else
						{
						    SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use this command on that player.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:fine(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 6)
		{
			new otherID, amount, message2[228], reason[200];

			if(sscanf(params, "uis[200]", otherID, amount, reason))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"fine <otherID> <amount> <reason>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
						if (amount > 0)
						{
							playerGiveMoney(otherID, -amount);
							
							format(message2, sizeof(message2), "{FE2E2E}[FINE] {FFFFFF}An administrator fined you {FFDC2E}$%s {FFFFFF}fine. {FE9A2E}[REASON: %s]", FormatNumber(amount), reason);
							SendClientMessage(otherID, COLOR_WHITE, message2);	
							
							new aMsg[300];
							for (new i=0; i<MAX_PLAYERS; i++)
							{
								if (playerData[i][playerLevel] >= 1)
								{
									format(aMsg, sizeof(aMsg), "{FE2E2E}[FINE] {FFFFFF}%s(%i) has fined {FFDC2E}$%s {FE9A2E}[REASON: %s] {FFFFFF}", playerData[playerid][playerNamee], playerid, playerData[otherID][playerNamee], otherID, reason);
									SendClientMessage(i, COLOR_WHITE, aMsg);
								}
							}		
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}The amount must be greater than 0.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:givecash(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 6)
		{
			new otherID, amount, message[128], message2[128];

			if(sscanf(params, "ui", otherID, amount))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"givecash <otherID> <amount>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
						if (amount > 0)
						{
							playerGiveBankMoney(otherID, amount);
							format(message, sizeof(message), "{B7B7B7}[GIFT] {FFFFFF}You have given {FFDC2E}$%s {FFFFFF}to %s(%i)", FormatNumber(amount), playerData[otherID][playerNamee], otherID);
							SendClientMessage(playerid, COLOR_WHITE, message);	
							
							format(message2, sizeof(message2), "{B7B7B7}[GIFT] {FFFFFF}An administrator has awarded you {FFDC2E}$%s {FFFFFF}- it has been added to your bank balance.", FormatNumber(amount));
							SendClientMessage(otherID, COLOR_WHITE, message2);	
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}The amount must be greater than 0.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:givemoney(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(IsPlayerAdmin(playerid))
		{
			new otherID, amount, message[128], message2[128];

			if(sscanf(params, "ui", otherID, amount))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"givemoney <otherID> <amount>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
						if (amount > 0)
						{
							playerGiveMoney(otherID, amount);
							format(message, sizeof(message), "{B7B7B7}[GIFT] {FFFFFF}You have given {FFDC2E}$%s {FFFFFF}to %s(%i)", FormatNumber(amount), playerData[otherID][playerNamee], otherID);
							SendClientMessage(playerid, COLOR_WHITE, message);

							format(message2, sizeof(message2), "{B7B7B7}[GIFT] {FFFFFF}An administrator has awarded you {FFDC2E}$%s{FFFFFF}.", FormatNumber(amount));
							SendClientMessage(otherID, COLOR_WHITE, message2);
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}The amount must be greater than 0.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}

	return 1;
}


COMMAND:giveallcash(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(IsPlayerAdmin(playerid))
		{
			new amount, message[128];

			if(sscanf(params, "i", amount))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"giveallcash <amount>\"");
			}
			else
			{
				if (amount > 0)
				{
					for(new i = 0; i < MAX_PLAYERS; i++)
					{
						if(IsPlayerConnected(i) && playerData[i][playerLoggedIn])
						{
							playerGiveMoney(i, amount);
						}
					}
					
					format(message, sizeof(message), "{A9C4E4}All players have been given {FFFFFF}$%s", FormatNumber(amount), playerData[playerid][tempAdminName], playerid);
					SendClientMessageToAll(COLOR_WHITE, message);				
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}The amount must be greater than 0.");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:givexp(playerid, params[])
{
	if(playerData[playerid][playerLevel] >= 6)
	{
		if(IsPlayerAdmin(playerid))
		{
			new otherID, amount, message[128], message2[128];

			if(sscanf(params, "ui", otherID, amount))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"givexp <otherID> <amount>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
						if (amount > 0)
						{
							playerGiveXP(otherID, amount);
							format(message, sizeof(message), "{B7B7B7}[GIFT] {FFFFFF}You have given {FFDC2E}%i {FFFFFF}XP to %s(%i)", amount, playerData[otherID][playerNamee], otherID);
							SendClientMessage(playerid, COLOR_WHITE, message);	
							
							format(message2, sizeof(message2), "{A9C4E4}An administrator has awarded you {FFFFFF}%i {A9C4E4}XP", amount);
							SendClientMessage(otherID, COLOR_WHITE, message2);	

							new log[250];
							format(log, sizeof(log), "%s(%i) has given %s(%i) %i XP", playerData[playerid][tempAdminName], playerid, playerData[otherID][playerNamee], otherID, amount);
							SendAdminText(playerid, log);		
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}The amount must be greater than 0.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:giveallxp(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(IsPlayerAdmin(playerid))
		{
			new amount, actualAmount, message[128];

			if(sscanf(params, "i", amount))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"giveallxp <amount>\"");
			}
			else
			{
				if (amount > 0)
				{
					if (serverInfo[doubleXP])
					{
						actualAmount = amount / 2;
					}
					else
					{
						actualAmount = amount;
					}
					
					for(new i = 0; i < MAX_PLAYERS; i++)
					{
						if(IsPlayerConnected(i) && playerData[i][playerLoggedIn])
						{
							playerGiveXP(i, actualAmount);
						}
					}
					
					format(message, sizeof(message), "{A9C4E4}All players have been given {FFFFFF}%i {A9C4E4}XP.", amount);
					SendClientMessageToAll(COLOR_WHITE, message);	

					new log[250];
					format(log, sizeof(log), "%s(%i) has given everyone %i XP", playerData[playerid][tempAdminName], playerid, amount);
					SendAdminText(playerid, log);					
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}The amount must be greater than 0.");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}
	
COMMAND:giveallweapon(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			new weapID, weapAmmo, message[128];

			if(sscanf(params, "ii", weapID, weapAmmo))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"giveallweapon <weaponID> <weaponAmmo>\"");
			}
			else
			{
				if(weapID < 1 || weapID > 46)  
				{
					return SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Weapon ID should be between 1 and 46.");
				}
				else
				{
					if(weapAmmo < 1 || weapAmmo > 600)  
					{
						return SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Weapon ammo should be between 1 and 600.");
					}
					else
					{
						switch(weapID)
						{
							case 16, 35, 36, 37, 38, 39, 40, 43, 44, 45:
							{
								return SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot give this weapon to all players.");
							}
						}
						
						for(new i = 0; i < MAX_PLAYERS; i++)
						{
							if(IsPlayerConnected(i) && playerData[i][playerLoggedIn])
							{
								GivePlayerWeaponEx(i, weapID, weapAmmo);
							}
						}
						
						format(message, sizeof(message), "{A9C4E4}An administrator has given everyone a %W with %i ammo.", weapID, weapAmmo, playerData[playerid][tempAdminName], playerid);
						SendClientMessageToAll(COLOR_WHITE, message);	

						new log[250];
						format(log, sizeof(log), "%s(%i) has given everyone a %W with %i ammo", playerData[playerid][tempAdminName], playerid, weapID, weapAmmo);
						SendAdminText(playerid, log);											
					}
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:giveweapon(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			new otherID, weapID, weapAmmo, message[128];

			if(sscanf(params, "uii", otherID, weapID, weapAmmo))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"giveweapon <playername/id> <weaponID> <weaponAmmo>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
						if(weapID < 1 || weapID > 46)  
						{
							return SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Weapon ID should be between 1 and 46.");
						}
						else
						{
							if(weapAmmo < 1 || weapAmmo > 600)  
							{
								return SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Weapon ammo should be between 1 and 600.");
							}
							else
							{
								switch(weapID)
								{
									case 16, 35, 36, 37, 38, 39, 40, 43, 44, 45:
									{	
										if (playerData[playerid][playerLevel] < 6)
										{
										    return SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot give this weapon to players.");
										}
									}
								}
								
								format(message, sizeof(message), "{A9C4E4}An administrator has given you a %W with %i ammo!", weapID, weapAmmo);
								SendClientMessage(otherID, COLOR_WHITE, message);
								
								format(message, sizeof(message), "{FE9A2E}[ADMIN] {FFFFFF}You have given %s a %W with %i ammo!", playerData[otherID][playerNamee], weapID, weapAmmo);
								SendClientMessage(playerid, COLOR_WHITE, message);
								
								playerData[otherID][adminWeapon] = true;
								GivePlayerWeaponEx(otherID, weapID, weapAmmo);
								
								new otherName[24];
								GetPlayerName(otherID, otherName, sizeof(otherName));
								
								new log[250];
								format(log, sizeof(log), "%s(%i) has given %s(%i) a %W with %i ammo", playerData[playerid][tempAdminName], playerid, otherName, otherID, weapID, weapAmmo);
								SendAdminText(playerid, log);
							}
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:doublexp(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 6)
		{
			switch(serverInfo[doubleXP])
			{
			    case 0:
				{
				    GameTextForAll("Double XP enabled!", 3000, 5);
					serverInfo[doubleXP] = 1;
					
					for(new p; p < MAX_PLAYERS; p++)
					{
						if(playerData[p][playerLoggedIn])
						{
							TextDrawShowForPlayer(p, doubleXPTD);
						}
					}
	
				}
				case 1:
				{
				    GameTextForAll("Double XP disabled!", 3000, 5);
					serverInfo[doubleXP] = 0;
					
					for(new p; p < MAX_PLAYERS; p++)
					{
						if(playerData[p][playerLoggedIn])
						{
							TextDrawHideForPlayer(p, doubleXPTD);
						}
					}
					
				}
			}
			new log[250];
			format(log, sizeof(log), "%s(%i) enabled double XP", playerData[playerid][tempAdminName], playerid);
			SendAdminText(playerid, log);
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

COMMAND:kickwarp(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 6)
		{
			switch(serverInfo[kickWarp])
			{
			    case 0:
				{
					serverInfo[kickWarp] = 1;
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Car warp detection enabled.");
				}
				case 1:
				{
					serverInfo[kickWarp] = 0;
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Car warp detection disabled.");
				}
			}
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

COMMAND:rapidfire(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 6)
		{
			switch(serverInfo[rfAnticheat])
			{
			    case 0:
				{
					serverInfo[rfAnticheat] = 1;
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Rapid fire detection enabled.");
				}
				case 1:
				{
					serverInfo[rfAnticheat] = 0;
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Rapid fire detection disabled.");
				}
			}
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

COMMAND:airbrake(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 6)
		{
			switch(serverInfo[abAnticheat])
			{
			    case 0:
				{
					serverInfo[abAnticheat] = 1;
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Airbrake detection enabled.");
				}
				case 1:
				{
					serverInfo[abAnticheat] = 0;
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Airbrake detection disabled.");
				}
			}
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

COMMAND:carwarp(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 6)
		{
			switch(serverInfo[carAnticheat])
			{
			    case 0:
				{
					serverInfo[carAnticheat] = 1;
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Car warp detection enabled.");
				}
				case 1:
				{
					serverInfo[carAnticheat] = 0;
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Car warp detection disabled.");
				}
			}
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

COMMAND:cbug(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 6)
		{
			switch(serverInfo[cbAnticheat])
			{
			    case 0:
				{
					serverInfo[cbAnticheat] = 1;
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}C-bug detection enabled.");
				}
				case 1:
				{
					serverInfo[cbAnticheat] = 0;
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}C-bug detection disabled.");
				}
			}
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

COMMAND:poptyres(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 6)
		{
		
			new otherPlayer, panels, doors, lights, tires, vehicleID, message[128], ptName[24];

			if(!sscanf(params, "u", otherPlayer))
			{
				if(IsPlayerConnected(otherPlayer))
				{
					if(playerData[otherPlayer][playerLoggedIn])
					{				
						if(IsPlayerInAnyVehicle(otherPlayer))
						{
							vehicleID = GetPlayerVehicleID(otherPlayer);
							GetVehicleDamageStatus(vehicleID, panels, doors, lights, tires);
							UpdateVehicleDamageStatus(vehicleID, panels, doors, lights, 15);
							GetPlayerName(otherPlayer, ptName, sizeof(ptName));
							
							format(message, sizeof(message), "{FE9A2E}[ADMIN] {FFFFFF}You have blown out all the tyres of %s(%i).", ptName, otherPlayer);
							SendClientMessage(playerid, COLOR_WHITE, message);
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Target player is not inside a vehicle.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"poptires <player>\"");
			}
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

COMMAND:ban(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 3)
		{
			new otherID, playersIP[24], playerName[24], adminName[24], message[248], reason[300];

			if(sscanf(params, "us[300]", otherID, reason))
			{
				SendClientMessage(playerid, COLOR_ORANGE, "Usage: \"ban <playername/id> <reason>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
						if(playerData[playerid][playerLevel] >= playerData[otherID][playerLevel])
						{
							// Send message to game
							GetPlayerName(otherID, playerName, sizeof(playerName));
							GetPlayerName(playerid, adminName, sizeof(adminName));
							GetPlayerIp(otherID, playersIP, sizeof(playersIP));
							
							format(message, sizeof(message), "{A9C4E4}%s(%i) has been banned from the server.", playerName, otherID);
							SendClientMessageToAll(COLOR_WHITE, message);
							
							new aMsg[300];
							for (new i=0; i<MAX_PLAYERS; i++)
							{
								if (playerData[i][playerLevel] >= 1)
								{
									format(aMsg, sizeof(aMsg), "{FE9A2E}[ADMIN] {FFFFFF}%s(%i) has banned %s(%i) {FE9A2E}[REASON: %s]{FFFFFF}", playerData[playerid][playerNamee], playerid, playerData[otherID][playerNamee], otherID, reason);
									SendClientMessage(i, COLOR_WHITE, aMsg);
								}
							}		
							
							new log[250];
							format(log, sizeof(log), "%s(%i) has banned %s(%i)", playerData[playerid][tempAdminName], playerid, playerName, otherID);
							SendAdminText(playerid, log);
							
							new banreason[350];
							format(banreason, sizeof(banreason), "INSERT INTO `playerbans` (`banned_by`, `banned_for`, `player_banned`, `player_ip`) VALUES ('%s', '%s', '%s', '%s')", adminName, reason, playerName, playersIP);
							mysql_query(banreason, MYSQL_ADD_BAN, playerid, connection);
							
							KickWithMessage(otherID, "[BANNED] You have been banned. You may appeal on www.czcnr.ml");
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use this command on that player.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:unban(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 4)
		{
			new otherID[40];

			if(sscanf(params, "s[40]", otherID))
			{
				SendClientMessage(playerid, COLOR_ORANGE, "Usage: \"unban <playername/id>\"");
			}
			else
			{
				new unban[200];
				
				// Query
				format(unban, sizeof(unban), "SELECT * FROM `playerbans` WHERE `player_banned` = '%s'", otherID);
				mysql_query(unban, MYSQL_REMOVE_BAN, playerid, connection);
			}
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

COMMAND:changename(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 6)
		{
			new otherID, newName[24];

			if(sscanf(params, "us[24]", otherID, newName))
			{
				SendClientMessage(playerid, COLOR_ORANGE, "Usage: \"changename <playername/id> <new name>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
						new checkName[200], nameQuery[200];
						
						// Query
						format(checkName, sizeof(checkName), "SELECT `playerName` FROM `playerdata` WHERE `playerName` = '%s'", newName);
						mysql_query(checkName);
						mysql_store_result();
						
						if(mysql_num_rows() == 0)
						{
							// Notices
							new nameNew[200];
							format(nameNew, sizeof(nameNew), "{FE9A2E}[ADMIN] {FFFFFF}%s(%i) has changed your name to %s", playerData[playerid][tempAdminName], playerid, newName);
							SendClientMessage(otherID, COLOR_WHITE, nameNew);
							
							new nameNewAdmin[200];
							format(nameNewAdmin, sizeof(nameNewAdmin), "{FE9A2E}[ADMIN] {FFFFFF}You have changed %s(%i)'s name to %s", playerData[otherID][playerNamee], otherID, newName);
							SendClientMessage(playerid, COLOR_WHITE, nameNewAdmin);
							
							new log[250];
							format(log, sizeof(log), "%s(%i) has changed %s(%i) name to %s", playerData[playerid][tempAdminName], playerid, playerData[otherID][playerNamee], otherID, newName);
							SendAdminText(playerid, log);
							
							// Set new name
							format(nameQuery, sizeof(nameQuery), "UPDATE `playerdata` SET `playerName` = '%s' WHERE `playerName` = '%s'", newName, playerData[otherID][playerNamee]);
							mysql_query(nameQuery);
							mysql_free_result();
							
							new
								query[300];
		
							format(query, sizeof(query), "UPDATE `house_data` SET `house_owner` = '%s' WHERE `house_owner` = '%s'", newName, playerData[otherID][playerNamee]);
							db_query(DB: HOUSEDB, query);
							reloadHouses();
							
							// Set name in-game
							playerData[otherID][playerNamee] = newName;
							SetPlayerName(otherID, newName);
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That name is already in use.");
						}
					}
					else
					{
						// Not logged
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not connected.");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:kick(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 1)
		{
			new otherID, playerName[24], adminName[24], message[248], reason[128];

			if(sscanf(params, "us[40]", otherID, reason))
			{
				SendClientMessage(playerid, COLOR_ORANGE, "Usage: \"kick <playername/id> <reason>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
						if(playerData[playerid][playerLevel] >= playerData[otherID][playerLevel])
						{
							// Kick the player
							new kickReason[200];
							format(kickReason, sizeof(kickReason), "Kicked for %s", reason);
							KickWithMessage(otherID, kickReason);	

							// Send message to game
							GetPlayerName(otherID, playerName, sizeof(playerName));
							GetPlayerName(playerid, adminName, sizeof(adminName));
							format(message, sizeof(message), "{A9C4E4}%s(%i) has been kicked from the server.", playerName, otherID);
							SendClientMessageToAll(COLOR_WHITE, message);
							
							new aMsg[300];
							for (new i=0; i<MAX_PLAYERS; i++)
							{
								if (playerData[i][playerLevel] >= 1)
								{
									format(aMsg, sizeof(aMsg), "{FE9A2E}[ADMIN] {FFFFFF}%s(%i) has kicked %s(%i) {FE9A2E}[REASON: %s]{FFFFFF}", playerData[playerid][playerNamee], playerid, playerData[otherID][playerNamee], otherID, reason);
									SendClientMessage(i, COLOR_WHITE, aMsg);
								}
							}		
						
							new log[250];
							format(log, sizeof(log), "%s(%i) has kicked %s(%i)", playerData[playerid][tempAdminName], playerid, playerName, otherID);
							SendAdminText(playerid, log);
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use this command on that player.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

/*COMMAND:kickall(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
  		if(playerData[playerid][playerLevel] >= 6)
		{
			new message[248], reason[30];

			if(sscanf(params, "s[40]", reason))
			{
				SendClientMessage(playerid, COLOR_ORANGE, "Usage: \"kickall <reason>\"");
			}
			else
			{
				// Kick the player
				for(new i = 0; i < MAX_PLAYERS; i++)
				{
					if(IsPlayerConnected(i) && playerData[i][playerLevel] != 6)
					{
						KickWithMessage(i, "{A9C4E4}Everyone has been kicked by an administrator.");	
					}
				}

				// Send message to game
				format(message, sizeof(message), "{FE9A2E}[ADMIN] {FFFFFF}%s(%i) has kicked everyone {FE9A2E}[REASON: %s]", playerData[playerid][tempAdminName], playerid, reason);
				SendClientMessageToAll(COLOR_WHITE, message);
				
				new log[250];
				format(log, sizeof(log), "%s(%i) has kicked everyone", playerData[playerid][tempAdminName], playerid);
				SendAdminText(playerid, log);
			}
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
}*/

/*
COMMAND:checkIfOnline(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		new playerToCheck[24], message[128], status;

		if(sscanf(params, "s[24]", playerToCheck))
		{
			SendClientMessage(playerid, COLOR_ORANGE, "Usage: \"checkIfOnline <name to check>\"");
		}
		else
		{
			status = checkNameStatus(playerToCheck);
			if(status == -1)
			{
				SendClientMessage(playerid, COLOR_WHITE, "Not online...");
			}
			else
			{
				format(message, sizeof(message), "Player is online... there ID is %i", status);
				SendClientMessage(playerid, COLOR_WHITE, message);
			}
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}*/

COMMAND:vc(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 3)
		{
			new message[128], vehName[16], vehID, Float:jX, Float:jY, Float:jZ, Float:jA;

			if(!sscanf(params, "s[16]", vehName))
			{
				vehID = getVehicleModelFromName(vehName);
				
				if(vehID < 400 || vehID > 612)
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Unknown vehicle name provided!");
				}
				else
				{
					GetPlayerFacingAngle(playerid, jA);
					GetPlayerPos(playerid, jX, jY, jZ);
					
					if(vehID == 612)
					{
						if(playerData[playerid][playerLevel] >= 6)
						{
							SetPlayerSpecialAction(playerid, SPECIAL_ACTION_USEJETPACK);
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Due to the anti-cheat method this server uses, you're unable to spawn a jetpack.");
						}
					}
					else
					{
						for(new v = 0; v < MAX_ADMIN_SPAWNED_VEHICLES; v++)
						{
							if(!adminSpawnedVehicles[v])
							{
								adminSpawnedVehicles[v] = CreateVehicle(vehID, jX, jY, jZ, jA, random(255), random(255), 12000);
								LinkVehicleToInterior(adminSpawnedVehicles[v], GetPlayerInterior(playerid));
								SetVehicleVirtualWorld(adminSpawnedVehicles[v], GetPlayerVirtualWorld(playerid));
								ac_PutPlayerInVehicle(playerid, adminSpawnedVehicles[v], 0);
								format(message, sizeof(message), "{FE9A2E}[ADMIN] {FFFFFF}You have spawned a %s", vehicleNames[vehID - 400]);
								SendClientMessage(playerid, COLOR_WHITE, message);
								
								break;
							}
							
							if(v == (MAX_ADMIN_SPAWNED_VEHICLES - 1))
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Too many administrator vehicles have been spawned, remove some before trying again.");
							}
						}
					}
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"vc <vehicle name>\"");
			}
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

COMMAND:destroyallav(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 3)
		{
			new bool:foundOne = false;
			for(new v = 0; v < MAX_ADMIN_SPAWNED_VEHICLES; v++)
			{
				if(strlen(adminSpawnedVehicles[v]))
				{
					foundOne = true;
					DestroyVehicle(adminSpawnedVehicles[v]);
					adminSpawnedVehicles[v] = 0;
				}
			}
			
			if(foundOne)
			{
				SendClientMessage(playerid, COLOR_WHITE, "{FE9A2E}[ADMIN] {FFFFFF}You have destroyed all administrator spawned vehicles.");

				new log[250];
				format(log, sizeof(log), "%s(%i) destroyed all admin vehicles", playerData[playerid][tempAdminName], playerid);
				SendAdminText(playerid, log);
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}No administrator spawned vehicles are currently in rotation.");
	        }
		}
        else
        {
            // No permission
            return 0;
        }
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
	
	return 1;
}
	
COMMAND:vdestroy(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 3)
		{
			if(IsPlayerInAnyVehicle(playerid))
			{			
				for(new v = 0; v < MAX_ADMIN_SPAWNED_VEHICLES; v++)
				{
					if(strlen(adminSpawnedVehicles[v]))
					{
						if(adminSpawnedVehicles[v] == GetPlayerVehicleID(playerid))
						{
							DestroyVehicle(adminSpawnedVehicles[v]);
							SendClientMessage(playerid, COLOR_WHITE, "{FE9A2E}[ADMIN] {FFFFFF}You deleted the vehicle");
							
							adminSpawnedVehicles[v] = 0;
						}
					}
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{FE9A2E}[ADMIN] {FFFFFF}You need to be in an admin spawned vehicle to use this command.");
			}
        }
        else
        {
            // No permission
            return 0;
        }
    }
    return 1;
}

COMMAND:vrespawn(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 2)
		{
			new vehicleid;
		
			if(sscanf(params, "i", vehicleid))
			{
			    SendClientMessage(playerid, COLOR_ORANGE, "Usage: \"vrespawn <vehicle id>\"");
            }
            else
            {
				if(IsValidVehicle(vehicleid))
				{
					SetVehicleToRespawn(vehicleid);
					SendClientMessage(playerid, COLOR_WHITE, "{FE9A2E}[ADMIN] {FFFFFF}You respawned the vehicle.");
					
					vWarped[vehicleid][Spawned] = false;
					vWarped[vehicleid][wasOccupied] = false;

				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Invalid vehicle ID provided.");
				}
				
           	}
      	}
  	}
  	return 1;
}

COMMAND:respawnalluv(playerid, params[])
{
    if(IsPlayerConnected(playerid))
    {
        if(playerData[playerid][playerLevel] >= 4)
        {
            for(new i = 0; i < MAX_VEHICLES; i++)
            {
                if(IsVehicleOccupied(i) == 0)
                {
                    SetVehicleToRespawn(i);
					
					vWarped[i][Spawned] = false;
					vWarped[i][wasOccupied] = false;
                }
            }
			
            SendClientMessageToAll(COLOR_WHITE, "{A9C4E4}An administrator has respawned unoccupied vehicles.");
			
			new log[250];
			format(log, sizeof(log), "%s(%i) respawned all unoccupied vehicles", playerData[playerid][tempAdminName], playerid);
			SendAdminText(playerid, log);
			
		}
	}
	return 1;
}

COMMAND:respawnallv(playerid, params[])
{
    if(IsPlayerConnected(playerid))
    {
        if(playerData[playerid][playerLevel] >= 5)
        {
            for(new i = 0; i < MAX_VEHICLES; i++)
            {
                if(IsValidVehicle(i))
                {
                    SetVehicleToRespawn(i);
					
					vWarped[i][Spawned] = false;
					vWarped[i][wasOccupied] = false;
                }
            }
			
            SendClientMessageToAll(COLOR_WHITE, "{A9C4E4}An administrator has respawned server vehicles.");
			
			new log[250];
			format(log, sizeof(log), "%s(%i) has respawned all vehicles", playerData[playerid][tempAdminName], playerid);
			SendAdminText(playerid, log);
		}
	}
	return 1;
}

COMMAND:explode(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 2)
		{
			
			new otherPlayer;
		
			if(!sscanf(params, "u", otherPlayer))
			{
				if(IsPlayerConnected(otherPlayer))
				{
					if(playerData[otherPlayer][playerLoggedIn])
					{
						if(playerData[playerid][playerLevel] >= playerData[otherPlayer][playerLevel])
						{
							new Float:dX, Float:dY, Float:dZ;
							
							GetPlayerPos(otherPlayer, dX, dY, dZ);								
							CreateExplosion(dX, dY, dZ, 12, 1.0);
							
							new otherName[24];
							GetPlayerName(otherPlayer, otherName, sizeof(otherName));
							
							new log[250];
							format(log, sizeof(log), "%s(%i) has exploded %s(%i)", playerData[playerid][tempAdminName], playerid, otherName, otherPlayer);
							SendAdminText(playerid, log);
							
							new loggingString[200];
							format(loggingString, sizeof(loggingString), "%s exploded %s.", playerData[playerid][tempAdminName], playerData[otherPlayer][playerNamee]);
							writeInLog("adminCommands.html", loggingString);
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use this command on that player.");	
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"explode <player>\"");
			}
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

COMMAND:spawn(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 1)
		{
			new otherPlayer;
		
			if(!sscanf(params, "u", otherPlayer))
			{
				if(IsPlayerConnected(otherPlayer))
				{
					if(playerData[otherPlayer][playerLoggedIn])
					{
						if(playerData[playerid][playerLevel] >= playerData[otherPlayer][playerLevel])
						{
							SetPlayerVirtualWorld(otherPlayer, 0);
							SetPlayerInterior(otherPlayer, 0);
							
							playerData[otherPlayer][hasSpawned] = false;
							SpawnPlayer(otherPlayer);
							
							new forAdmin[128], pName[24], aName[24];
							GetPlayerName(otherPlayer, pName, sizeof(pName));
							GetPlayerName(playerid, aName, sizeof(aName));
							
							format(forAdmin, sizeof(forAdmin), "{FE9A2E}[ADMIN] {FFFFFF}You have spawned %s(%i)", pName, otherPlayer);
							SendClientMessage(playerid, COLOR_WHITE, forAdmin);

							SendClientMessage(otherPlayer, COLOR_WHITE, "{A9C4E4}You have been spawned by an administrator.");
							
							new log[250];
							format(log, sizeof(log), "%s(%i) has spawned %s(%i)", playerData[playerid][tempAdminName], playerid, pName, otherPlayer);
							SendAdminText(playerid, log);
							
							new loggingString[200];
							format(loggingString, sizeof(loggingString), "%s set spawned %s.", playerData[playerid][tempAdminName], playerData[otherPlayer][playerNamee]);
							writeInLog("adminCommands.html", loggingString);
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use this command on that player.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"spawn <player>\"");
			}
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

COMMAND:setskin(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 3)
		{
			new otherPlayer, skinID;
		
			if(sscanf(params, "ui", otherPlayer, skinID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"setskin <player> <skin_id>\"");
			}
			else
			{
				if(IsPlayerConnected(otherPlayer))
				{
					if(playerData[otherPlayer][playerLoggedIn])
					{
						if(playerData[playerid][playerLevel] >= playerData[otherPlayer][playerLevel])
						{
							if(skinID < 1 || skinID > 311)
							{
								return SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Skin ID should be 1-311");
							}
							else
							{
								new message[128], message2[128];
							    SetPlayerSkin(otherPlayer, skinID);
								format(message, sizeof(message), "{A9C4E4}An administrator set your skin to ID %i", skinID);
								SendClientMessage(otherPlayer, COLOR_WHITE, message);
								
								format(message2, sizeof(message2), "{FE9A2E}[ADMIN] {FFFFFF}You set %s(%i)'s skin ID to %i", playerData[otherPlayer][playerNamee], otherPlayer, skinID);
								SendClientMessage(playerid, COLOR_WHITE, message2);
								
								playerData[otherPlayer][playerCustomSkin] = skinID;
								
								new loggingString[200];
								format(loggingString, sizeof(loggingString), "%s set %s's skin ID to %i.", playerData[playerid][tempAdminName], playerData[otherPlayer][playerNamee], skinID);
								writeInLog("adminCommands.html", loggingString);
								
								SetTimerEx("checkDriveB", 2000, false, "d", otherPlayer);
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use this command on that player.");		
						}
					}
				}
			}
		}
	}
	return 1;
}

COMMAND:unmute(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 1)
		{
			new otherPlayer;
		
			if(!sscanf(params, "u", otherPlayer))
			{
				if(IsPlayerConnected(otherPlayer))
				{
					if(playerData[otherPlayer][playerLoggedIn])
					{
						if(playerData[playerid][playerLevel] >= playerData[otherPlayer][playerLevel])
						{
							if (playerData[otherPlayer][playerMuteTime] > 1)
							{
								playerData[otherPlayer][playerMuteTime] = 0;
								
								new otherName[24];
								GetPlayerName(otherPlayer, otherName, sizeof(otherName));
								
								SendClientMessage(otherPlayer, COLOR_WHITE, "{A9C4E4}You have been unmuted by an administrator.");
								
								new log[250];
								format(log, sizeof(log), "%s(%i) has unmuted %s(%i)", playerData[playerid][tempAdminName], playerid, otherName, otherPlayer);
								SendAdminText(playerid, log);
								
								new loggingString[200];
								format(loggingString, sizeof(loggingString), "%s unmuted %s.", playerData[playerid][tempAdminName], playerData[otherPlayer][playerNamee]);
								writeInLog("adminCommands.html", loggingString);
							}
							else
							{
							    SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not muted.");		
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use this command on that player.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"unmute <player>\"");
			}
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

COMMAND:mute(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 1)
		{
			// Set-up our variables etc
			new PlayerToMute, muteFor, Reason[128], Msg[328], Name[24], mutedBy[24];

			if (sscanf(params, "uis[128]", PlayerToMute, muteFor, Reason)) 
			{
				// Incorrect params used
				SendClientMessage(playerid, COLOR_ORANGE, "Usage: \"mute <player> <seconds> <reason>\"");
			}
			else
			{
				if (IsPlayerConnected(PlayerToMute)) // If the player is a valid playerid (he's connected)
				{
					if(playerData[PlayerToMute][playerLoggedIn])
					{
						if (playerData[playerid][playerLevel] >= playerData[PlayerToMute][playerLevel])
						{
							if(muteFor >= 10)
							{
								GetPlayerName(playerid, mutedBy, sizeof(mutedBy));
								
								// Get the name of the player who's being sent to jail
								GetPlayerName(PlayerToMute, Name, sizeof(Name));

								format(Msg, sizeof(Msg), "{A9C4E4}An administrator has muted you for %i seconds {FE9A2E}[REASON: %s]", muteFor, Reason);
								SendClientMessage(PlayerToMute, COLOR_WHITE, Msg);
								
								new aMsg[300];
								for (new i=0; i<MAX_PLAYERS; i++)
								{
									if (playerData[i][playerLevel] >= 1)
									{
										format(aMsg, sizeof(aMsg), "{FE9A2E}[ADMIN] {FFFFFF}%s(%i) has muted %s(%i) for %i seconds {FE9A2E}[REASON: %s]{FFFFFF}", playerData[playerid][playerNamee], playerid, playerData[PlayerToMute][playerNamee], PlayerToMute, muteFor, Reason);
										SendClientMessage(i, COLOR_WHITE, aMsg);
									}
								}		
								
								playerData[PlayerToMute][playerMuteTime] = muteFor;
								
								new log[250];
								format(log, sizeof(log), "%s(%i) has muted %s(%i) for %i seconds", playerData[playerid][tempAdminName], playerid, Name, PlayerToMute, muteFor);
								SendAdminText(playerid, log);
								
								new loggingString[200];
								format(loggingString, sizeof(loggingString), "%s muted %s for %i seconds", playerData[playerid][tempAdminName], playerData[PlayerToMute][playerNamee], muteFor);
								writeInLog("adminCommands.html", loggingString);
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Mute time must be at least 10 seconds.");
							}
						}
						else
						{
						    SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use this command on that player.");	
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}

   // Return 1
	return 1;
}

COMMAND:slap(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 1)
		{
			new otherPlayer;
		
			if(!sscanf(params, "u", otherPlayer))
			{
				if(IsPlayerConnected(otherPlayer))
				{
					if(playerData[otherPlayer][playerLoggedIn])
					{
						if(playerData[playerid][playerLevel] >= playerData[otherPlayer][playerLevel])
						{
							
							new Float:dX, Float:dY, Float:dZ;
							
							GetPlayerPos(otherPlayer, dX, dY, dZ);
							SetPlayerPos(otherPlayer, dX, dY, (dZ + 8.0));
							
							new otherName[24];
							GetPlayerName(otherPlayer, otherName, sizeof(otherName));
							
							new log[250];
							format(log, sizeof(log), "%s(%i) has slapped %s(%i)", playerData[playerid][tempAdminName], playerid, otherName, otherPlayer);
							SendAdminText(playerid, log);
							
							new loggingString[200];
							format(loggingString, sizeof(loggingString), "%s slapped %s", playerData[playerid][tempAdminName], playerData[otherPlayer][playerNamee]);
							writeInLog("adminCommands.html", loggingString);
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use this command on that player.");		
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"slap <player>\"");
			}
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

COMMAND:bigslap(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 6)
		{
			new otherPlayer;
		
			if(!sscanf(params, "u", otherPlayer))
			{
				if(IsPlayerConnected(otherPlayer))
				{
					if(playerData[otherPlayer][playerLoggedIn])
					{
						if(playerData[playerid][playerLevel] >= playerData[otherPlayer][playerLevel])
						{
							
							new Float:dX, Float:dY, Float:dZ;
							
							GetPlayerPos(otherPlayer, dX, dY, dZ);
							SetPlayerPos(otherPlayer, dX, dY, (dZ + 100.0));
							
							new otherName[24];
							GetPlayerName(otherPlayer, otherName, sizeof(otherName));
							
							new loggingString[200];
							format(loggingString, sizeof(loggingString), "%s big slapped %s", playerData[playerid][tempAdminName], playerData[otherPlayer][playerNamee]);
							writeInLog("adminCommands.html", loggingString);
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use this command on that player.");		
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"bigslap <player>\"");
			}
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

COMMAND:aarmour(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 6)
		{
			new otherPlayer, message[200];
		
			if(!sscanf(params, "u", otherPlayer))
			{
				if(IsPlayerConnected(otherPlayer))
				{
					if(playerData[otherPlayer][playerLoggedIn])
					{
						if(playerData[playerid][playerLevel] >= playerData[otherPlayer][playerLevel])
						{
							if (playerData[otherPlayer][playerVIPLevel] > 0)
							{
								SetPlayerHealth(otherPlayer, 100);
								
								format(message, sizeof(message), "{FE9A2E}[ADMIN] {FFFFFF}You gave armour to %s(%i).", playerData[otherPlayer][playerNamee], otherPlayer);
								SendClientMessage(playerid, COLOR_WHITE, message);
								
								SendClientMessage(otherPlayer, COLOR_WHITE, "{A9C4E4}An administrator has refilled your armour.");
								
								new log[250];
								format(log, sizeof(log), "%s(%i) has given armour to %s(%i)", playerData[playerid][tempAdminName], playerid, playerData[otherPlayer][playerNamee], otherPlayer);
								SendAdminText(playerid, log);
								
								new loggingString[200];
								format(loggingString, sizeof(loggingString), "%s gave armour to %s", playerData[playerid][tempAdminName], playerData[otherPlayer][playerNamee]);
								writeInLog("adminCommands.html", loggingString);
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use this command on that player.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use this command on that player.");		
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"heal <player>\"");
			}
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

COMMAND:aheal(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 3)
		{
			new otherPlayer, message[200];
		
			if(!sscanf(params, "u", otherPlayer))
			{
				if(IsPlayerConnected(otherPlayer))
				{
					if(playerData[otherPlayer][playerLoggedIn])
					{
						if(playerData[playerid][playerLevel] >= playerData[otherPlayer][playerLevel])
						{
							SetPlayerHealth(otherPlayer, 100);
							
							format(message, sizeof(message), "{FE9A2E}[ADMIN] {FFFFFF}You healed %s(%i).", playerData[otherPlayer][playerNamee], otherPlayer);
							SendClientMessage(playerid, COLOR_WHITE, message);
							
							SendClientMessage(otherPlayer, COLOR_WHITE, "{A9C4E4}An administrator has healed you.");
							
							new log[250];
							format(log, sizeof(log), "%s(%i) has healed %s(%i)", playerData[playerid][tempAdminName], playerid, playerData[otherPlayer][playerNamee], otherPlayer);
							SendAdminText(playerid, log);
							
							new loggingString[200];
							format(loggingString, sizeof(loggingString), "%s healed %s", playerData[playerid][tempAdminName], playerData[otherPlayer][playerNamee]);
							writeInLog("adminCommands.html", loggingString);
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use this command on that player.");		
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"heal <player>\"");
			}
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
COMMAND:getip(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 4)
		{
			new
				otherID,
				message[128],
				pIP[20]
			;

			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"getip <playerid>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
					    GetPlayerIp(otherID, pIP, sizeof(pIP));
						format (message, sizeof(message), "{B7B7B7}[IP ADDRESS] {FFFFFF}%s(%d)'s IP Address: %s.", playerData[otherID][playerNamee], otherID, pIP);
						SendClientMessage(playerid, COLOR_WHITE, message);
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
				}
			}
		}
		else
		{
			return 0;
		}
	}

	return 1;
}

COMMAND:ahealall(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			foreach(new i: Player)
			{
				if(IsPlayerConnected(i))
				{
					if(playerData[i][playerLoggedIn])
					{
						SetPlayerHealth(i, 100);
					}
				}
			}
			SendClientMessageToAll(COLOR_WHITE, "{A9C4E4}An administrator has healed everyone.");

			new log[250];
			format(log, sizeof(log), "%s(%i) has healed all", playerData[playerid][tempAdminName], playerid);
			SendAdminText(playerid, log);

			new loggingString[200];
			format(loggingString, sizeof(loggingString), "%s healed everyone", playerData[playerid][tempAdminName]);
			writeInLog("adminCommands.html", loggingString);
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
COMMAND:vgoto(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 3)
		{
			
			new vehicleID;
		
			if(!sscanf(params, "i", vehicleID))
			{
				if(IsValidVehicle(vehicleID))
				{
					new Float:eX, Float:eY, Float:eZ, message[128];
								
					GetVehiclePos(vehicleID, eX, eY, eZ);
					SetPlayerPos(playerid, eX, eY, (eZ + 3.0));
					
					format(message, sizeof(message), "{FE9A2E}[ADMIN] {FFFFFF}You teleported to the vehicle %i.", vehicleID);
					SendClientMessage(playerid, COLOR_WHITE, message);
					
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Invalid vehicle ID provided.");
				}
				
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"vgoto <vehicle id>\"");
			}
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

COMMAND:vbring(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 3)
		{
			
			new vehicleID;
		
			if(!sscanf(params, "i", vehicleID))
			{
				if(IsValidVehicle(vehicleID))
				{
					new Float:fX, Float:fY, Float:fZ, message[128];
								
					GetPlayerPos(playerid, fX, fY, fZ);
					SetVehiclePos(vehicleID, fX, fY, fZ);
					SetPlayerPos(playerid, fX, fY, (fZ + 3.0));
					
					new log[250];
					format(log, sizeof(log), "%s(%i) has teleported vehicle id %i to them", playerData[playerid][tempAdminName], playerid, vehicleID);
					SendAdminText(playerid, log);
					
					format(message, sizeof(message), "{FE9A2E}[ADMIN] {FFFFFF}You teleported the vehicle %i to your current location.", vehicleID);
					SendClientMessage(playerid, COLOR_WHITE, message);
					
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Invalid vehicle ID provided.");
				}
				
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"vbring <vehicle id>\"");
			}
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

COMMAND:forcepassenger(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 6)
		{
		
			new otherPlayer, vehicleID, seatID, playerName[24], message[128];

			if(!sscanf(params, "uii", otherPlayer, vehicleID, seatID))
			{
				if(IsPlayerConnected(otherPlayer))
				{
					if(playerData[otherPlayer][playerLoggedIn])
					{				
						if(IsValidVehicle(vehicleID))
						{
							if(checkSeatStatus(vehicleID, seatID) == 1)
							{
								if(IsPlayerInAnyVehicle(otherPlayer))
								{
									RemovePlayerFromVehicle(otherPlayer);
								}
								
								ac_PutPlayerInVehicle(otherPlayer, vehicleID, seatID);
								GetPlayerName(otherPlayer, playerName, sizeof(playerName));
								
								format(message, sizeof(message), "{FE9A2E}[ADMIN] {FFFFFF}You have forced %s(%i) into seat %i of vehicle: %i", playerName, otherPlayer, seatID, vehicleID);
								SendClientMessage(playerid, COLOR_WHITE, message);
								
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Seat doesn't exist, or is currently occupied.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Invalid vehicle ID supplied.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"forcepassenger <player> <vehicle id> <seat id>\"");
			}
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

COMMAND:debug(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(IsPlayerAdmin(playerid))
		{
			ShowPlayerDialog(playerid, DIALOG_DEBUG, DIALOG_STYLE_LIST, "Admin Debug", "Full Health\nWeapon Packs\nRepair Vehicle\nAdd NOS\nRemove EMP", "Select", "Cancel");
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

COMMAND:playerweapons(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 2)
		{
			
			new otherPlayer;
		
			if(!sscanf(params, "u", otherPlayer))
			{
				if(IsPlayerConnected(otherPlayer))
				{
					if(playerData[otherPlayer][playerLoggedIn])
					{
						new playerWeapon[13][2], dialogValues[500], weaponsIndexed, captionText[64];
						for (new i = 0; i < 13; i++)
						{
							GetPlayerWeaponData(otherPlayer, i, playerWeapon[i][0], playerWeapon[i][1]);
							if(playerWeapon[i][0])
							{
								if(weaponsIndexed == 0)
								{
									format(dialogValues, sizeof(dialogValues), "%W (%i)", playerWeapon[i][0], playerWeapon[i][1]);
									weaponsIndexed++;
								}
								else
								{
									format(dialogValues, sizeof(dialogValues), "%s\n%W (%i)", dialogValues, playerWeapon[i][0], playerWeapon[i][1]);
								}
							}
						}
						
						if(weaponsIndexed != 0)
						{
							format(captionText, sizeof(captionText), "%s's Weapons", playerData[otherPlayer][playerNamee]);
							ShowPlayerDialog(playerid, DIALOG_WEAPCHECK, DIALOG_STYLE_LIST, captionText, dialogValues, "Okay", "Close");
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player does not currently have any weapons.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"playerweapons <player>\"");
			}
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

COMMAND:warn(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 1)
		{
			new otherID, message[256], reason[30];

			if(sscanf(params, "us[40]", otherID, reason))
			{
				SendClientMessage(playerid, COLOR_ORANGE, "Usage: \"warn <playername/id> <reason>\"");
			}
			else
			{
				if(IsPlayerConnected(otherID))
				{
					if(playerData[otherID][playerLoggedIn])
					{
						if(playerData[playerid][playerLevel] >= playerData[otherID][playerLevel])
						{
							if(playerData[otherID][playerWarnings] <= 2)
							{
								playerData[otherID][playerWarnings]++;	
								
								format(message, sizeof(message), "{A9C4E4}You have been warned! {FE9A2E}[REASON: %s] {FFFFFF}[%i/3]", reason, playerData[otherID][playerWarnings]);
								SendClientMessage(otherID, COLOR_WHITE, message);
								
								for (new i=0; i<MAX_PLAYERS; i++)
								{
									if (playerData[i][playerLevel] >= 1)
									{
										format(message, sizeof(message), "{FE9A2E}[ADMIN] {FFFFFF}%s(%i) has been warned by %s(%i) {FE9A2E}[REASON: %s]", playerData[otherID][playerNamee], otherID, playerData[playerid][tempAdminName], playerid, reason);
										SendClientMessage(i, COLOR_WHITE, message);
									}
								}		
								
								new log[250];
								format(log, sizeof(log), "%s(%i) has warned %s(%i) [%i/3]", playerData[playerid][tempAdminName], playerid, playerData[otherID][playerNamee], otherID, playerData[otherID][playerWarnings]);
								SendAdminText(playerid, log);
								
								if(playerData[otherID][playerWarnings] == 3)
								{
									format(message, sizeof(message), "{FE9A2E}[ADMIN] {FFFFFF}%s(%i) has been kicked {FE9A2E}[REASON: Excessive warnings] {FFFFFF}", playerData[otherID][playerNamee], otherID);
									SendClientMessageToAll(COLOR_WHITE, message);
									KickWithMessage(otherID, "You have been kicked for excessive warnings!");	
								}
								
								ShowPlayerDialog(otherID, 91827, DIALOG_STYLE_MSGBOX, "Warning", "You have been warned by an administrator!", "OK", "");	
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use this command on that player.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
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
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
		
	return 1;
}

COMMAND:spec(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 1)
		{
			new otherPlayer, message[128];
			if(!sscanf(params, "u", otherPlayer))
			{
				if(IsPlayerConnected(otherPlayer))
				{
					if(playerData[otherPlayer][playerLoggedIn])
					{
						if (!playerData[otherPlayer][playerIsSpectating])
						{
							if (playerData[otherPlayer][allowSpec] || playerData[playerid][playerLevel] >= playerData[otherPlayer][playerLevel])
							{
								if(!playerData[playerid][playerIsSpectating])
								{
									for (new i = 0; i < 13; i++)
									{
										GetPlayerWeaponData(playerid, i, playerData[playerid][previousWeapons][i], playerData[playerid][previousAmmoLots][i]);
									}
									
									playerData[playerid][previousVirtualWorld] = GetPlayerVirtualWorld(playerid);
									playerData[playerid][previousInteriorWorld] = GetPlayerInterior(playerid);
									
									GetPlayerPos(playerid, playerData[playerid][previousX], playerData[playerid][previousY], playerData[playerid][previousZ]);
									
									GetPlayerHealth(playerid, playerData[playerid][previousHealth]);
									GetPlayerArmour(playerid, playerData[playerid][previousArmour]);
									
									format(message, sizeof(message), "{FE9A2E}[ADMIN] {FFFFFF}You have begun to spectate %s.", playerData[otherPlayer][playerNamee]);
									SendClientMessage(playerid, COLOR_WHITE, message);
									
									playerData[playerid][playerIsSpectating] = true;
								}
								
								SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(otherPlayer));
								SetPlayerInterior(playerid, GetPlayerInterior(otherPlayer));
								TogglePlayerSpectating(playerid, 1);
								
								// Default
								if(IsPlayerInAnyVehicle(otherPlayer))
								{
									new vehicle = GetPlayerVehicleID(otherPlayer);
									PlayerSpectateVehicle(playerid, vehicle);
								}
								else
								{
									PlayerSpectatePlayer(playerid, otherPlayer);
								}
					
								new log[250];
								format(log, sizeof(log), "%s(%i) is spectating %s(%i)", playerData[playerid][tempAdminName], playerid, playerData[otherPlayer][playerNamee], otherPlayer);
								SendAdminText(playerid, log);
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Unable to spectate that player.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is spectating someone!");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"/spec [PLAYER]\"");
			}
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

COMMAND:silentspec(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 6)
		{
			new otherPlayer, message[128];
			if(!sscanf(params, "u", otherPlayer))
			{
				if(IsPlayerConnected(otherPlayer))
				{
					if(playerData[otherPlayer][playerLoggedIn])
					{
						if(!playerData[playerid][playerIsSpectating])
						{
							for (new i = 0; i < 13; i++)
							{
								GetPlayerWeaponData(playerid, i, playerData[playerid][previousWeapons][i], playerData[playerid][previousAmmoLots][i]);
							}
							
							playerData[playerid][previousVirtualWorld] = GetPlayerVirtualWorld(playerid);
							playerData[playerid][previousInteriorWorld] = GetPlayerInterior(playerid);
							
							GetPlayerPos(playerid, playerData[playerid][previousX], playerData[playerid][previousY], playerData[playerid][previousZ]);
							
							GetPlayerHealth(playerid, playerData[playerid][previousHealth]);
							GetPlayerArmour(playerid, playerData[playerid][previousArmour]);
							
							format(message, sizeof(message), "{FE9A2E}[ADMIN] {FFFFFF}You have begun to spectate %s.", playerData[otherPlayer][playerNamee]);
							SendClientMessage(playerid, COLOR_WHITE, message);
							
							playerData[playerid][playerIsSpectating] = true;
						}
						
                        SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(otherPlayer));
                        SetPlayerInterior(playerid, GetPlayerInterior(otherPlayer));
						TogglePlayerSpectating(playerid, 1);
						
						// Default
						if(IsPlayerInAnyVehicle(otherPlayer))
						{
							new vehicle = GetPlayerVehicleID(otherPlayer);
							PlayerSpectateVehicle(playerid, vehicle);
						}
						else
						{
							PlayerSpectatePlayer(playerid, otherPlayer);
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not online!");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"/silentspec [PLAYER]\"");
			}
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

COMMAND:specoff(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 1)
		{
			if(playerData[playerid][playerIsSpectating])
			{
				TogglePlayerSpectating(playerid, 0);
				SpawnPlayer(playerid);
				SendClientMessage(playerid, COLOR_WHITE, "{FE9A2E}[ADMIN] {FFFFFF}Your spectation session has come to an end.");
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You're not currently spectating anyone.");
			}
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


COMMAND:settime(playerid, params[])
{
    new N1, N2, pname[24];
	GetPlayerName(playerid,pname,sizeof(pname));
	
	if(!IsPlayerAdmin(playerid))
	{
	    return 1;
	}
	if(sscanf(params, "ii", N1, N2))
	{
	    SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"settime <hour> <minute>\"");
	    return 1;
	}
	if(N1 < 0 || N1 > 23)
	{
        SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Value must be between 0 and 23.");
	    return 1;
	}
	if(N2 < 0 || N2 > 59)
	{
	    SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Value must be between 0 and 59.");
	    return 1;
	}
	
	N11 = N1 * 60;
	gtime = N11 + N2;
	return 1;
}

COMMAND:setday(playerid, params[])
{
    new N1, pname[24];
    
	GetPlayerName(playerid,pname,sizeof(pname));
	
	if(!IsPlayerAdmin(playerid))
	{
	    return 1;
	}
	if(sscanf(params, "i", N1))
	{
	    SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"setday <1-6>\"");
	    return 1;
	}
	if(N1 < 0 || N1 > 6)
	{
	    SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Value must be between 1 and 6.");
	    return 1;
	}
	
	gday = N1;
	return 1;
}

COMMAND:weather(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			new type;

			if(sscanf(params, "i", type))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"weather <id>\"");
			}
			else
			{
				SetWeather(type);
			}
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

COMMAND:resetjailtimer(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			serverInfo[jailblown] = 0;
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Jail timer reset.");
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

COMMAND:testshow(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			if (serverInfo[testShow])
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Test Show Disabled!");
				serverInfo[testShow] = 0;
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Test Show Enabled!");
				serverInfo[testShow] = 1;
			}
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

COMMAND:pmspy(playerid, params[])
{
    if(IsPlayerConnected(playerid))
    {
        if(playerData[playerid][playerLevel] >= 4)
        {
			if (playerData[playerid][pmSpy])
			{
				playerData[playerid][pmSpy] = false;
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You are no longer spying on private messages.");
			}
			else
			{
				playerData[playerid][pmSpy] = true;
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You are now spying on private messages.");
			}
		}
	}
	return 1;
}
