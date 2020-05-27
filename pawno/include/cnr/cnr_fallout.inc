new
	Iterator:fallObject<MAX_GLASS>;
new Float:gCoords[MAX_GLASS][3] = {
	{ -5309.198120,-199.052383,22.593704 },
	{ -5309.198120,-195.786071,22.593704 },
	{ -5309.198120,-192.510620,22.593704 },
	{ -5309.198120,-189.250564,22.593704 },
	{ -5309.198120,-185.987960,22.593704 },
	{ -5309.198120,-182.727081,22.593704 },
	{ -5309.198120,-179.463394,22.593704 },
	{ -5309.198120,-176.205261,22.593704 },
	{ -5304.841796,-176.205261,22.593704 },
	{ -5304.841796,-179.468795,22.593704 },
	{ -5304.841796,-182.737884,22.593704 },
	{ -5304.841796,-185.989654,22.593704 },
	{ -5304.841796,-189.259185,22.593704 },
	{ -5304.841796,-192.518615,22.593704 },
	{ -5304.841796,-195.785491,22.593704 },
	{ -5304.841796,-199.054733,22.593704 },
	{ -5300.489990,-199.054733,22.593704 },
	{ -5300.489990,-195.782165,22.593704 },
	{ -5300.489990,-192.531250,22.593704 },
	{ -5300.489990,-189.274765,22.593704 },
	{ -5300.489990,-186.003005,22.593704 },
	{ -5300.489990,-182.735229,22.593704 },
	{ -5300.489990,-179.471069,22.593704 },
	{ -5300.489990,-176.208007,22.593704 },
	{ -5296.138061,-176.208007,22.593704 },
	{ -5296.138061,-179.479248,22.593704 },
	{ -5296.138061,-182.744735,22.593704 },
	{ -5296.138061,-186.002944,22.593704 },
	{ -5296.138061,-189.274505,22.593704 },
	{ -5296.138061,-192.533691,22.593704 },
	{ -5296.138061,-195.788970,22.593704 },
	{ -5296.138061,-199.048782,22.593704 },
	{ -5291.776000,-199.050140,22.593704 },
	{ -5291.776000,-195.790634,22.593704 },
	{ -5291.776000,-192.542922,22.593704 },
	{ -5291.776000,-189.277542,22.593704 },
	{ -5291.776000,-186.013275,22.593704 },
	{ -5291.776000,-182.742355,22.593704 },
	{ -5291.776000,-179.475021,22.593704 },
	{ -5291.776000,-176.215805,22.593704 },
	{ -5287.432250,-176.215805,22.593704 },
	{ -5287.432250,-179.485168,22.593704 },
	{ -5287.432250,-182.739608,22.593704 },
	{ -5287.432250,-186.016723,22.593704 },
	{ -5287.432250,-189.277816,22.593704 },
	{ -5287.432250,-192.539001,22.593704 },
	{ -5287.432250,-195.796325,22.593704 },
	{ -5287.432250,-199.053771,22.593704 },
	{ -5287.431274,-202.320648,22.593704 },
	{ -5291.781616,-202.320648,22.593704 },
	{ -5296.136718,-202.320648,22.593704 },
	{ -5300.493652,-202.320648,22.593704 },
	{ -5304.848876,-202.320648,22.593704 },
	{ -5309.201660,-202.320648,22.593704 }
};

COMMAND:falloutevent(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 4)
		{
			new msg[512];
			if (serverInfo[falloutOpen])
			{
				format(msg, sizeof(msg), "{FF00FF}[FALLOUT]{FFffFF} Falout event has been closed.");
				SendClientMessageToAll(COLOR_WHITE, msg);
				serverInfo[falloutOpen] = false;
			}
			else
			{
				format(msg, sizeof(msg), "{FF00FF}[FALLOUT]{FFffFF} Fallout event has been started, type {00FFFF}/joinfallout{FFffFF} to join event.");
				SendClientMessageToAll(COLOR_WHITE, msg);
				serverInfo[falloutOpen] = true;
				for( new i; i < MAX_GLASS; i++ )
				{
     				serverInfo[falloutGlass][i] = CreateDynamicObject( 1649, gCoords[i][0], gCoords[i][1], gCoords[i][2], -90.000000, 0.000000, 0.000000, 182);
					Iter_Add(fallObject, i);
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

COMMAND:startfallout(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 4)
		{
		    new bool:found = false;
			for(new i = 0; i < MAX_PLAYERS; i++)
			{
				if(IsPlayerConnected(i) && playerData[i][playerLoggedIn])
				{
					if (playerData[i][isInFallout])
					{
					    found = true;
						TogglePlayerControllable(i, 1);
						GameTextForPlayer(i, "EVENT STARTED!", 5000, 5);
					}
				}
			}
			for( new i; i < MAX_GLASS; i++ )
			{
				Iter_Add(fallObject, i);
			}
			KillTimer(serverInfo[falloutTimer]);
			if(found)
				serverInfo[falloutTimer] = SetTimer("MinigameUpdate", 2500, 1 );
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

COMMAND:joinfallout(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (playerData[playerid][playerWantedLevel] == 0)
		{
			if (playerData[playerid][playerJailTime] < 1)
			{
				new msg[512];
				if (!playerData[playerid][isInFallout])
				{
					if (serverInfo[falloutOpen])
					{
						for (new i = 0; i < 13; i++)
						{
							GetPlayerWeaponData(playerid, i, playerData[playerid][previousWeapons][i], playerData[playerid][previousAmmoLots][i]);
						}
						playerData[playerid][previousVirtualWorld] = GetPlayerVirtualWorld(playerid);
						playerData[playerid][previousInteriorWorld] = GetPlayerInterior(playerid);

						GetPlayerHealth(playerid, playerData[playerid][previousHealth]);
						GetPlayerArmour(playerid, playerData[playerid][previousArmour]);
						GetPlayerPos(playerid, playerData[playerid][previousX], playerData[playerid][previousY], playerData[playerid][previousZ]);
						SetPlayerInterior(playerid, 0);
						SetPlayerVirtualWorld(playerid, 182);
						ResetPlayerWeapons(playerid);
						TogglePlayerControllable(playerid, false);
           				SetPlayerCameraPos(playerid, -5298.4814,-218.4391,42.1386);
						SetPlayerCameraLookAt(playerid, -5298.1616,-189.6903,23.6564);
						new spot = Iter_Random(fallObject);
						SetPlayerPos(playerid, gCoords[spot][0], gCoords[spot][1], gCoords[spot][2] +0.5 );
						Iter_Remove(fallObject, spot );
						format(msg, sizeof(msg), "{FF00FF}[FALLOUT]{FFffFF} You joined fallout event.");
						GameTextForPlayer(playerid, "~r~THE EVENT WILL START SHORTLY!!!", 10000, 5);
						SendClientMessage(playerid, COLOR_WHITE, msg);
						playerData[playerid][isInEvent] = true;
						playerData[playerid][isInFallout] = true;
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}There is no fallout event open right now.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Please leave the minigames arena before joining the fallout event.");
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

COMMAND:destroyfallout(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 4)
		{
			for( new i; i < MAX_GLASS; i++ )
			{
				DestroyDynamicObject(serverInfo[falloutGlass][i]);
				Iter_Clear(fallObject);
			}
			KillTimer(serverInfo[falloutTimer]);
			foreach(new i : Player)
			{
				if(playerData[i][isInFallout])
				{
					playerData[i][isInEvent] = false;
					playerData[i][isInFallout] = false;
				}
			}
		}
	}
	return 1;
}

forward MinigameUpdate();
public MinigameUpdate()
{
	new objectid = Iter_Random(fallObject), Float:ObjectX, Float:ObjectY, Float:ObjectZ;
	GetDynamicObjectPos(serverInfo[falloutGlass][objectid], ObjectX, ObjectY, ObjectZ );
	SetTimerEx("SpeedUp", 500, 0, "ifff", objectid, ObjectX, ObjectY, ObjectZ);
	MoveDynamicObject(serverInfo[falloutGlass][objectid], ObjectX, ObjectY, ObjectZ -5, 1 );
	Iter_Remove(fallObject, objectid );
	return 1;
}

forward SpeedUp( object, Float:x, Float:y, Float:z );
public SpeedUp( object, Float:x, Float:y, Float:z )
{
	MoveDynamicObject(serverInfo[falloutGlass][object], x, y, z -150, 20 );
	return 1;
}
