// DM Event

COMMAND:dmevent(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 4)
		{
			if (serverInfo[DMEvent])
			{
				// Close Event
				serverInfo[DMEvent] = 0;
				SendClientMessageToAll(COLOR_WHITE, "{58D3F7}[EVENT CLOSED] {FFFFFF}An administrator has closed the deathmatch event.");
			}
			else
			{
				new 
					weapID
				;

				if(sscanf(params, "i", weapID))
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"dmevent <weapon id>\"");
				}
				else
				{
					// Open Event
					serverInfo[DMEvent] = 1;
					serverInfo[DMWeapon] = weapID;
					
					SendClientMessageToAll(COLOR_WHITE, "{58D3F7}[EVENT OPENED] {FFFFFF}An administrator has started a deathmatch event! Type {FFDC2E}/joindm{FFFFFF} to participate.");
					SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[EVENT HELP] {FFFFFF}To start the event, first type /dmevent again to close entry, then type /startdm to unfreeze players.");
					
					GameTextForPlayer(playerid, "EVENT OPENED!", 5000, 5);
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

COMMAND:startdm(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 4)
		{
			for(new i = 0; i < MAX_PLAYERS; i++)
			{
				if(IsPlayerConnected(i) && playerData[i][playerLoggedIn])
				{
					if (playerData[i][isInEvent])
					{
						TogglePlayerControllable(i, 1);
						GameTextForPlayer(i, "EVENT STARTED!", 5000, 5);
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

COMMAND:joindm(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (playerData[playerid][playerWantedLevel] == 0)
		{
			if (playerData[playerid][playerJailTime] < 1)
			{
				if (!playerData[playerid][isInDM])
				{
					if (serverInfo[DMEvent])
					{
						// Can join event
						new randSpawn = random(8);
						switch(randSpawn)
						{
							case 0:
							{
								SetPlayerPos(playerid, 3482.4971, 1241.6937, 30.8687);
							}
							case 1:
							{
								SetPlayerPos(playerid, 3517.7058, 1197.3563, 30.8687);
							}
							case 2:
							{
								SetPlayerPos(playerid, 3595.6094, 1232.2844, 30.8687);
							}
							case 3:
							{
								SetPlayerPos(playerid, 3566.5476, 1282.5114, 30.8687);
							}
							case 4:
							{
								SetPlayerPos(playerid, 3543.1704, 1245.0923, 30.8687);
							}
							case 5:
							{
								SetPlayerPos(playerid, 3540.1433, 1193.4580, 30.8687);
							}
							case 6:
							{
								SetPlayerPos(playerid, 3543.1914, 1234.9987, 30.8687);
							}
							case 7:
							{
								SetPlayerPos(playerid, 3539.0188, 1286.2709, 30.8687);
							}
						}
						
						// No team during DM
						SetPlayerTeam(playerid, NO_TEAM);
						
						SetPlayerInterior(playerid, 10);
						SetPlayerVirtualWorld(playerid, 520);
						
						playerData[playerid][isInEvent] = true;
						TogglePlayerControllable(playerid, 0);
						
						// Remove armour
						SetPlayerArmour(playerid, 0);
						SetPlayerHealth(playerid, 100);
						
						ResetPlayerWeapons(playerid);
						playerData[playerid][adminWeapon] = true;
						GivePlayerWeaponEx(playerid, serverInfo[DMWeapon], 5000);
						
						GameTextForPlayer(playerid, "THE EVENT WILL START SHORTLY!~n~~r~You are temporarily frozen", 10000, 5);
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}There is no DM event open right now.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Please leave the minigames arena before joining the DM event.");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot join events whilst jailed.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot join events if you have a wanted level.");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
	
	return 1;
}
