forward countJailTime(playerid);
forward sendPlayerJail(playerid, amountOfSeconds, leo, isArr);

new Float:RandomCell[][4] =
{
    {219.5126, 110.8304, 999.0156, 1.9761},
    {215.5369, 111.0402, 999.0156, 358.2161},
    {227.3636, 111.2233, 999.0156, 4.1929},
    {223.5596, 111.4195, 999.0156, 359.1796},
    {223.5454, 121.2124, 999.0742, 98.4825}
};

new Float:LVExitPoints[][4] = 
{
	{200.6972, 168.2653, 1003.0234, 89.0391}
};

new Float:LVRandomCell[][4] = 
{
	{198.0651, 176.7253, 1003.0234, 359.4248}, // 2
	{193.8369, 176.7251, 1003.0234, 0.6781}, // 3
	{198.0573, 160.6476, 1003.1533, 178.6532}
};

new Float:ExitPoints[][4] =
{
	{249.4593, 115.0391, 1003.2188, 174.6005},
	{242.2043, 110.1127, 1003.2188, 180.5539},
	{223.8599, 118.8689, 1003.2188, 268.2881},
	{246.1848, 112.9106, 1003.2188, 181.4940}
};

forward EscapeJail(playerid);
public EscapeJail(playerid)
{
	new rand = random(4);
	if(rand == 1 || rand == 2)
	{
		if(playerData[playerid][playerTown] == SF)
		{
			SetPlayerInterior(playerid, 10);
			SetPlayerPos(playerid, 216.8014, 120.5791, 999.0156);
			SetPlayerFacingAngle(playerid, 183.3742);
			SetPlayerVirtualWorld(playerid, 25);
		}
		else
		{
			new rand2 = random(sizeof(LVExitPoints));
			SetPlayerInterior(playerid, 3);
			SetPlayerPos(playerid, LVExitPoints[rand2][0], LVExitPoints[rand2][1],LVExitPoints[rand2][2]);
			SetPlayerFacingAngle(playerid, LVExitPoints[rand2][3]);
			SetPlayerVirtualWorld(playerid, 142);
		}
		SetPlayerHealth(playerid, 100);
		PlayerTextDrawSetString(playerid, playerData[playerid][playerJailTimerTD], " ");
		playerData[playerid][playerBailTo] = -1;
		playerData[playerid][playerBailPrice] = -1;
		playerData[playerid][playerJailTime] = 0;
		KillTimer(playerData[playerid][jailTimer]);
		
		new escapeMsg[300];
		format(escapeMsg, sizeof(escapeMsg), "{FFDC2E}[JAIL ESCAPE] {FFFFFF}%s(%i) escaped from jail!", playerData[playerid][tempAdminName], playerid);
		SendClientMessageToAll(COLOR_WHITE, escapeMsg);
		
		playerData[playerid][playerJailKit]--;	
														
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
		TogglePlayerControllable(playerid, 1);		

		ClearAnimations(playerid);
		playerData[playerid][playerUsingAnim] = false;		
		
		givePlayerWanted(playerid, 6);
		sendWantedMessage(playerid, 6);
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JAIL ESCAPE] {FFFFFF}You failed to escape, the guards are watching you now.");
		playerData[playerid][playerJailKit]--;

		// Cannot escape now
		playerData[playerid][canEscape] = false;
		
		ClearAnimations(playerid);
		playerData[playerid][playerUsingAnim] = false;	
	}
}

public countJailTime(playerid)
{
	if(IsPlayerConnected(playerid))
	{
		if(playerData[playerid][playerLoggedIn])
		{
			if(playerData[playerid][playerJailTime] > 0)
			{	
				new jailString[50];
				
				playerData[playerid][playerJailTime]--;
				
				format(jailString, sizeof(jailString), "%i seconds remaining.", playerData[playerid][playerJailTime]);
				PlayerTextDrawSetString(playerid, playerData[playerid][playerJailTimerTD], jailString);
				
				if(playerData[playerid][playerJailTime] == 0)
				{
					new MsgAll[255], Name[24];
					GetPlayerName(playerid, Name, sizeof(Name));
					
					// Random exit
					if(playerData[playerid][playerTown] == SF)
					{
						new rand = random(sizeof(ExitPoints));
						SetPlayerInterior(playerid, 10);
						SetPlayerPos(playerid, ExitPoints[rand][0], ExitPoints[rand][1],ExitPoints[rand][2]);
						SetPlayerFacingAngle(playerid, ExitPoints[rand][3]);
						SetPlayerVirtualWorld(playerid, 25);
					}
					else
					{
						new rand = random(sizeof(LVExitPoints));
						SetPlayerInterior(playerid, 3);
						SetPlayerPos(playerid, LVExitPoints[rand][0], LVExitPoints[rand][1],LVExitPoints[rand][2]);
						SetPlayerFacingAngle(playerid, LVExitPoints[rand][3]);
						SetPlayerVirtualWorld(playerid, 142);
					}
					
					SetPlayerHealth(playerid, 100);
					PlayerTextDrawSetString(playerid, playerData[playerid][playerJailTimerTD], " ");
					playerData[playerid][playerAdminJailed] = 0;
					playerData[playerid][playerBailTo] = -1;
					playerData[playerid][playerBailPrice] = -1;
					KillTimer(playerData[playerid][jailTimer]);

					for(new p; p < MAX_PLAYERS; p++)
					{
						new pName[24];
						GetPlayerName(p, pName, sizeof(pName));

						if(!strcmp(pName, Name))
						{
							SendClientMessage(p, COLOR_WHITE, "{FFDC2E}[JAIL] {FFFFFF}You have been released from jail {07E08D}[Sentence complete]{FFFFFF}");
						}
						else
						{
							format(MsgAll, sizeof(MsgAll), "{FFDC2E}[JAIL] {FFFFFF}%s(%i) has been released from jail {07E08D}[Sentence complete]{FFFFFF}", Name, playerid);
							SendClientMessage(p, COLOR_WHITE, MsgAll);
						}
					}
				}
			}
		}
	}
}

public sendPlayerJail(playerid, amountOfSeconds, leo, isArr)
{
	if(playerData[playerid][playerTown] == SF)
	{
		new rand = random(sizeof(RandomCell));
		SetPlayerInterior(playerid, 10);
		SetPlayerPos(playerid, RandomCell[rand][0], RandomCell[rand][1],RandomCell[rand][2]);
		SetPlayerFacingAngle(playerid, RandomCell[rand][3]);
		SetPlayerVirtualWorld(playerid, 25);
	}
	else
	{
		new rand = random(sizeof(LVRandomCell));
		SetPlayerInterior(playerid, 3);
		SetPlayerPos(playerid, LVRandomCell[rand][0], LVRandomCell[rand][1],LVRandomCell[rand][2]);
		SetPlayerFacingAngle(playerid, LVRandomCell[rand][3]);
		SetPlayerVirtualWorld(playerid, 142);
	}

    playerData[playerid][playerJailTime] = amountOfSeconds;
    ResetPlayerWeapons(playerid);
    SetPlayerHealth(playerid, 9999999);
	playerData[playerid][canEscape] = true;
	
	new jailedBy[24], Name[24], Msg[250];
	GetPlayerName(leo, jailedBy, sizeof(Name));
	GetPlayerName(playerid, Name, sizeof(Name));
	
	if(playerData[playerid][playerIsTied])
	{
		playerData[playerid][playerIsTied] = false;
		KillTimer(playerData[playerid][untieTimer]);
	}
	
	if(playerData[playerid][playerIsCuffed])
	{
		playerData[playerid][playerIsCuffed] = false;
		KillTimer(playerData[playerid][uncuffTimer]);
	}
	
	if (isArr)
	{
		switch(playerData[leo][playerClass])
		{
			case CLASS_POLICE:
			{
				format(Msg, 250, "{FFDC2E}[JAIL] {FFFFFF}%s(%i) has been arrested by {3E7EFF}%s(%i) {FFFFFF}for %i seconds", Name, playerid, jailedBy, leo, amountOfSeconds);
			}
			case CLASS_FBI:
			{
				format(Msg, 250, "{FFDC2E}[JAIL] {FFFFFF}%s(%i) has been arrested by {1C3EFF}%s(%i) {FFFFFF}for %i seconds", Name, playerid, jailedBy, leo, amountOfSeconds);
			}
			case CLASS_CIA:
			{
				format(Msg, 250, "{FFDC2E}[JAIL] {FFFFFF}%s(%i) has been arrested by {2F205B}%s(%i) {FFFFFF}for %i seconds", Name, playerid, jailedBy, leo, amountOfSeconds);
			}
			case CLASS_SECRETSERVICE:
			{
				format(Msg, 250, "{FFDC2E}[JAIL] {FFFFFF}%s(%i) has been arrested by {2F205B}%s(%i) {FFFFFF}for %i seconds", Name, playerid, jailedBy, leo, amountOfSeconds);
			}
			case CLASS_ARMY:
			{
				format(Msg, 250, "{FFDC2E}[JAIL] {FFFFFF}%s(%i) has been arrested by {944DFF}%s(%i) {FFFFFF}for %i seconds", Name, playerid, jailedBy, leo, amountOfSeconds);
			}
		}
		
		SendClientMessageToAll(COLOR_WHITE, Msg);
	}
	
	KillTimer(playerData[playerid][jailTimer]);
	playerData[playerid][jailTimer] = SetTimerEx("countJailTime", 1000, true, "i", playerid);
	
	if(playerData[playerid][playerTown] == SF)
		playerData[playerid][lastEnteredID] = 23;
	else
		playerData[playerid][lastEnteredID] = 72;
}
