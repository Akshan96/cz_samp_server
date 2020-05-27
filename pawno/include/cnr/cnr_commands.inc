COMMAND:wl(playerid, params[])
{
	new msg[1000], count = 1;
	foreach(new i : Player)
	{
		if(playerData[i][playerWantedLevel] > 3)
		{
			format(msg, sizeof(msg), "%s%d. %s( %d Star(s) )\n", msg, count, playerData[i][playerNamee], playerData[i][playerWantedLevel]);
			count++;
		}
	}
	if(count != 1)
	{
		ShowPlayerDialog(playerid, 200, DIALOG_STYLE_MSGBOX, "Wanted List", msg, "Close", "");
	}
	else
	{
		ShowPlayerDialog(playerid, 200, DIALOG_STYLE_MSGBOX, "Wanted List", "There are no wanted players present.", "Close", "");
	}
	return 1;
}

COMMAND:selecttown(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		playerData[playerid][playerTown] = SF;
	}
	return 1;
}

COMMAND:viewtop(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		ShowPlayerDialog(playerid, DIALOG_TOP, DIALOG_STYLE_LIST, "Select Option", "Top Killer \nBest Robbers \nTop Players \nTop Truckers \nTop Moneybag Hunters \nBest Cop \nRichest Player", "Select", "Back");
    }
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
	return 1;
}

COMMAND:breakout(playerid, params[])//lol
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerJailTime] >= 20)
		{
			if (!playerData[playerid][playerAdminJailed])
			{
				if(playerData[playerid][playerJailKit] > 0)
				{
					if (playerData[playerid][canEscape])
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You're now attempting to escape from jail.");
						ApplyAnimation(playerid, "BOMBER", "BOM_PLANT_LOOP", 4.0, 1, 0, 0, 0, -1);
						SetTimerEx("EscapeJail", 5000, false, "ii", playerid);
						playerData[playerid][playerUsingAnim] = true;
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You screwed up the escape attempt and can no longer escape from jail.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Your escape methods are outdated, purchase another Escapist Guide when you get out.");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You are admin jailed.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR}{FFFFFF}You are not cuffed.");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
	}
	return 1;
}

/*COMMAND:updates(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
	    new string[20264];
		format(string, sizeof(string), "%s{98B0CD}http://cnrsf.net\n", string);
		
		ShowPlayerDialog(playerid, DIALOG_RULES, DIALOG_STYLE_MSGBOX, "Server Updates", string, "OK", "");
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
		}

	return 1;
}*/

COMMAND:moviemode(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(hidden[playerid] == 0)
		{
			hidden[playerid] =1;
			PlayerTextDrawHide(playerid, playerData[playerid][wantedStars]);
			PlayerTextDrawHide(playerid, playerData[playerid][playerTracker]);
			PlayerTextDrawHide(playerid, playerData[playerid][playerExperience]);
			PlayerTextDrawHide(playerid, playerData[playerid][cnrLogo]);
			TextDrawHideForPlayer(playerid, URLTD);
			TextDrawHideForPlayer(playerid, MOTDTD);
			TextDrawHideForPlayer(playerid, gDay);
			TextDrawHideForPlayer(playerid, gTime);
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You have enabled your moviemode.");

		}
		else
		{
			hidden[playerid] =0;
			PlayerTextDrawShow(playerid, playerData[playerid][wantedStars]);
			PlayerTextDrawShow(playerid, playerData[playerid][playerTracker]);
			PlayerTextDrawShow(playerid, playerData[playerid][playerExperience]);
			PlayerTextDrawShow(playerid, playerData[playerid][cnrLogo]);
			TextDrawShowForPlayer(playerid, URLTD);
			TextDrawShowForPlayer(playerid, MOTDTD);
			TextDrawShowForPlayer(playerid, gDay);
			TextDrawShowForPlayer(playerid, gTime);

			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You have disabled your moviemode");
		}

	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
	}
	return 1;
}

COMMAND:music(playerid, params[])
{
    if (playerData[playerid][playerLoggedIn])
    {
        ShowPlayerDialog(playerid, DIALOG_MUSIC, DIALOG_STYLE_LIST, "Music Selection", "Green Day - American Idiot \nGreen Day - Jesus of Suburbia \nGreen Day - Homecoming \nGreen Day - 21st Century Breakdown \nA7X - So Far Away \nA7X - Missing in Action \nA7X - Dear God \nA7X - Burn it Down", "Go", "Cancel");
    }
    else
    {
        SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
    }
    return 1;
}

COMMAND:controlsettings(playerid,params[])
{
	new string[300];
	new s_2[60];
	new s_3[60];
	new s_4[60];
	new s_5[60];
	new s_6[60];
	//Connection Log
	if(cl[playerid] == 0) { format(s_2,sizeof(s_2),"{FF0000}"); }
	if(cl[playerid] == 1) { format(s_2,sizeof(s_2),"{00FF00}"); }
	//Event Teleports
	if(at[playerid] == 0) { format(s_3,sizeof(s_3),"{FF0000}"); }
	if(at[playerid] == 1) { format(s_3,sizeof(s_3),"{00FF00}"); }
	//recieving Messages
	if(!playerData[playerid][playerBlockPMs]) { format(s_4,sizeof(s_4),"{FF0000}"); }
	if(playerData[playerid][playerBlockPMs]) { format(s_4,sizeof(s_4),"{00FF00}"); }
	//Bail Offers
	if(bo[playerid] == 0) { format(s_5,sizeof(s_5),"{FF0000}"); }
	if(bo[playerid] == 1) { format(s_5,sizeof(s_5),"{00FF00}"); }
	//Hitmarker
	if(!playerData[playerid][playerHitmarker]) { format(s_6,sizeof(s_6),"{FF0000}"); }
	if(playerData[playerid][playerHitmarker]) { format(s_6,sizeof(s_6),"{00FF00}"); }

	format(string,sizeof(string),"Connection Log %s\nEvent Teleports %s\nRecieving Private Messages %s\nBail Offers %s\nHitmarker %s", s_2, s_3, s_4, s_5, s_6);
	ShowPlayerDialog(playerid, DIALOG_CS, DIALOG_STYLE_LIST, "Control Settings", string, "Select", "Cancel");
	return 1;
}
COMMAND:cs(playerid,params[])
{
	return cmd_controlsettings(playerid,params);
}
COMMAND:pl(playerid, params[])
{
	new string[128];
	if(playerData[playerid][playerLoggedIn])
	{
		format(string,sizeof(string),"{B7B7B7}[PACKETLOSS] {FFFFFF}Your packets loss: %.2f percent.",NetStats_PacketLossPercent(playerid));
		SendClientMessage(playerid,-1,string);
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
	}
	return 1;
}
COMMAND:escape(playerid, params[])
{
	return cmd_breakout(playerid, params);
}

COMMAND:tokens(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		new tokens[200];
		format(tokens, sizeof(tokens), "{FFDC2E}[TOKENS] {FFFFFF}You have {FFDC2E}%i {FFFFFF}tokens to spend.", playerData[playerid][rTokens]);
		SendClientMessage(playerid, COLOR_WHITE, tokens);
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
	}
	return 1;
}
COMMAND:parrot(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (playerData[playerid][playerVIPLevel] >= 1)
		{
			if (playerData[playerid][hasParrot])
			{
				if(IsPlayerAttachedObjectSlotUsed(playerid, 8)) RemovePlayerAttachedObject(playerid, 8);
				playerData[playerid][hasParrot] = false;

				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You removed the parrot from your shoulder.");
			}
			else
			{
				SetPlayerAttachedObject( playerid, 8, 19078, 3, -0.025633, 0.071474, -0.042353, 152.483703, 170.041259, 353.874603, 1.000000, 1.000000, 1.000000 ); // TheParrot1 - aest 5
				playerData[playerid][hasParrot] = true;

				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You have placed a parrot onto your shoulder.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be a Premium player to use this command.");
		}
	}


	return 1;
}

COMMAND:backpack(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (playerData[playerid][playerBackpack] == 1)
		{
			if (playerData[playerid][hasBackpack])
			{
				if(IsPlayerAttachedObjectSlotUsed(playerid, 9)) RemovePlayerAttachedObject(playerid, 9);
				playerData[playerid][hasBackpack] = false;

				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You removed your backpack.");
			}
			else
			{
				SetPlayerAttachedObject( playerid, 9, 371, 1, 0.048503, -0.112052, -0.021527, 356.659484, 85.123565, 0.000000, 0.919283, 1.000000, 1.000000 ); // gun_para - aest 44
				playerData[playerid][hasBackpack] = true;

				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You put your backpack on.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You don't have a backpack! Buy one from Supa Save.");
		}
	}


	return 1;
}

COMMAND:leavedm(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (playerData[playerid][isInDM])
		{
			TextDrawHideForPlayer(playerid, dmBox[0]);
			TextDrawHideForPlayer(playerid, dmBox[1]);
			TextDrawHideForPlayer(playerid, dmBox[2]);
			TextDrawHideForPlayer(playerid, dmBox[3]);
			TextDrawHideForPlayer(playerid, dmBox[4]);
			TextDrawHideForPlayer(playerid, dmBox[5]);
			TextDrawHideForPlayer(playerid, dmBox[6]);

			PlayerTextDrawHide(playerid, playerData[playerid][dmArena][0]);
			PlayerTextDrawHide(playerid, playerData[playerid][dmArena][1]);
			PlayerTextDrawHide(playerid, playerData[playerid][dmArena][2]);
			PlayerTextDrawHide(playerid, playerData[playerid][dmArena][3]);

			ResetPlayerWeapons(playerid);
			playerData[playerid][isInDM] = false;
			playerData[playerid][isInEvent] = false;

			SetPlayerVirtualWorld(playerid, 0);
			SetPlayerInterior(playerid, 0);

			playerData[playerid][hasSpawned] = false;
			SpawnPlayer(playerid);

			for (new i=0; i<MAX_PLAYERS; i++)
			{
				if(playerData[i][isInDM])
				{
					new dmLeave[100];
					format(dmLeave, sizeof(dmLeave), "{FAAC58}%s(%i) {FFFFFF}left the arena.", playerData[playerid][playerNamee], playerid);
					SendClientMessage(i, COLOR_WHITE, dmLeave);

				}
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You're not in a DM event.");
		}
	}

	return 1;
}

COMMAND:breakin(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (playerData[playerid][playerClass] == CLASS_CIVILIAN || playerData[playerid][playerClass] == CLASS_MEDIC)
		{
			closeDialogs(playerid);

			if (playerData[playerid][canBreakIn])
			{
				houseBreakin(playerid);
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}Please wait before breaking into another property.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}This command can only be used by civilians.");
		}
	}

	return 1;
}

COMMAND:openrobbery(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		closeDialogs(playerid);

		PlayerTextDrawShow(playerid, playerData[playerid][robTD][0]);
		PlayerTextDrawShow(playerid, playerData[playerid][robTD][1]);
		PlayerTextDrawShow(playerid, playerData[playerid][robTD][2]);
		PlayerTextDrawShow(playerid, playerData[playerid][robTD][3]);
	}

	return 1;
}

/*COMMAND:openwelcome(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		closeDialogs(playerid);

		PlayerTextDrawShow(playerid, playerData[playerid][Welcome1]);
		PlayerTextDrawShow(playerid, playerData[playerid][Welcome2]);
		PlayerTextDrawShow(playerid, playerData[playerid][Welcome3]);
		PlayerTextDrawShow(playerid, playerData[playerid][Welcome4]);
		PlayerTextDrawShow(playerid, playerData[playerid][Welcome5]);
		PlayerTextDrawShow(playerid, playerData[playerid][Welcome6]);
		PlayerTextDrawShow(playerid, playerData[playerid][Welcome7]);
		PlayerTextDrawShow(playerid, playerData[playerid][Welcome8]);
	}

	return 1;
}*/

COMMAND:openik(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		closeDialogs(playerid);

		PlayerTextDrawShow(playerid, playerData[playerid][InnocentKill1]);
		PlayerTextDrawShow(playerid, playerData[playerid][InnocentKill2]);
		PlayerTextDrawShow(playerid, playerData[playerid][InnocentKill3]);
		PlayerTextDrawShow(playerid, playerData[playerid][InnocentKill4]);
		PlayerTextDrawShow(playerid, playerData[playerid][InnocentKill5]);
		PlayerTextDrawShow(playerid, playerData[playerid][InnocentKill6]);
		PlayerTextDrawShow(playerid, playerData[playerid][InnocentKill7]);
		PlayerTextDrawShow(playerid, playerData[playerid][InnocentKill8]);
	}

	return 1;
}

COMMAND:stats(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		closeDialogs(playerid);

		// Set stat strings
		new
			kills[15],
			deaths[15],
			sRobberies[15],
			pRobberies[15],
			pRapes[15],
			scopArrests[15],
			scopKills[15],
			scopDetains[15],
			ratioString[100]
		;

		new Float:ratio = float(playerData[playerid][playerKills]) / float(playerData[playerid][playerDeaths]);

		format(ratioString, sizeof(ratioString), "~y~%0.2f", ratio);
		format(kills, sizeof(kills), "~y~%i", playerData[playerid][playerKills]);
		format(deaths, sizeof(deaths), "~y~%i", playerData[playerid][playerDeaths]);
		format(sRobberies, sizeof(sRobberies), "~y~%i", playerData[playerid][playerRobberies]);
		format(pRobberies, sizeof(pRobberies), "~y~%i", playerData[playerid][streetRobberies]);
		format(pRapes, sizeof(pRapes), "~y~%i", playerData[playerid][streetRapes]);
		format(scopArrests, sizeof(scopArrests), "~y~%i", playerData[playerid][copArrests]);
		format(scopKills, sizeof(scopKills), "~y~%i", playerData[playerid][copKills]);
		format(scopDetains, sizeof(scopDetains), "~y~%i", playerData[playerid][copDetains]);

		PlayerTextDrawSetString(playerid, playerData[playerid][PlayerStats][15], kills);
		PlayerTextDrawSetString(playerid, playerData[playerid][PlayerStats][16], deaths);
		PlayerTextDrawSetString(playerid, playerData[playerid][PlayerStats][17], sRobberies);
		PlayerTextDrawSetString(playerid, playerData[playerid][PlayerStats][18], pRobberies);
		PlayerTextDrawSetString(playerid, playerData[playerid][PlayerStats][19], pRapes);
		PlayerTextDrawSetString(playerid, playerData[playerid][PlayerStats][20], ratioString);
		PlayerTextDrawSetString(playerid, playerData[playerid][PlayerStats][22], scopArrests);
		PlayerTextDrawSetString(playerid, playerData[playerid][PlayerStats][23], scopKills);
		PlayerTextDrawSetString(playerid, playerData[playerid][PlayerStats][24], scopDetains);

		PlayerTextDrawShow(playerid, playerData[playerid][PlayerStats][0]);
		PlayerTextDrawShow(playerid, playerData[playerid][PlayerStats][1]);
		PlayerTextDrawShow(playerid, playerData[playerid][PlayerStats][2]);
		PlayerTextDrawShow(playerid, playerData[playerid][PlayerStats][3]);
		PlayerTextDrawShow(playerid, playerData[playerid][PlayerStats][4]);
		PlayerTextDrawShow(playerid, playerData[playerid][PlayerStats][5]);
		PlayerTextDrawShow(playerid, playerData[playerid][PlayerStats][6]);
		PlayerTextDrawShow(playerid, playerData[playerid][PlayerStats][7]);
		PlayerTextDrawShow(playerid, playerData[playerid][PlayerStats][8]);
		PlayerTextDrawShow(playerid, playerData[playerid][PlayerStats][9]);
		PlayerTextDrawShow(playerid, playerData[playerid][PlayerStats][10]);
		PlayerTextDrawShow(playerid, playerData[playerid][PlayerStats][11]);
		PlayerTextDrawShow(playerid, playerData[playerid][PlayerStats][12]);
		PlayerTextDrawShow(playerid, playerData[playerid][PlayerStats][13]);
		PlayerTextDrawShow(playerid, playerData[playerid][PlayerStats][14]);
		PlayerTextDrawShow(playerid, playerData[playerid][PlayerStats][15]);
		PlayerTextDrawShow(playerid, playerData[playerid][PlayerStats][16]);
		PlayerTextDrawShow(playerid, playerData[playerid][PlayerStats][17]);
		PlayerTextDrawShow(playerid, playerData[playerid][PlayerStats][18]);
		PlayerTextDrawShow(playerid, playerData[playerid][PlayerStats][19]);
		PlayerTextDrawShow(playerid, playerData[playerid][PlayerStats][20]);
		PlayerTextDrawShow(playerid, playerData[playerid][PlayerStats][22]);
		PlayerTextDrawShow(playerid, playerData[playerid][PlayerStats][23]);
		PlayerTextDrawShow(playerid, playerData[playerid][PlayerStats][24]);
	}

	return 1;
}

COMMAND:closehelp(playerid, params[])
{
	closeDialogs(playerid);

	return 1;
}

COMMAND:richlist(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		new
			richList[256],
			richPlayers[5] = {INVALID_PLAYER_ID, INVALID_PLAYER_ID, INVALID_PLAYER_ID, INVALID_PLAYER_ID, INVALID_PLAYER_ID},
			highestValue = -1,
			timesRan = 0,
			playerCount = 0,
			loopAmount = 0;

		for(new j = 0; j < MAX_PLAYERS; j++)
		{
			if(IsPlayerConnected(j))
			{
				playerCount++;
			}
		}

		if(playerCount >= 5)
		{
			loopAmount = 5;
		}
		else
		{
			loopAmount = playerCount;
		}

		while(timesRan < loopAmount)
		{
			highestValue = 0;

			for(new i = 0; i < MAX_PLAYERS; i++)
			{
				if(IsPlayerConnected(i))
				{
					if(playerData[i][playerLoggedIn])
					{
						if(playerData[i][playerMoney] > highestValue)
						{
							if(i != richPlayers[0] && i != richPlayers[1] && i != richPlayers[2] && i != richPlayers[3] && i != richPlayers[4])
							{
								highestValue = playerData[i][playerMoney];
								richPlayers[i] = i;
							}
						}
					}
				}
			}

			timesRan++;
		}

		for(new k = 0; k < sizeof(richPlayers); k++)
		{
			if(richPlayers[k] != INVALID_PLAYER_ID)
			{
				if(IsPlayerConnected(richPlayers[k]))
				{
					if(playerData[richPlayers[k]][playerLoggedIn])
					{
						format(richList, sizeof(richList), "#%i - %s: $%s", richPlayers[k], playerData[richPlayers[k]][playerNamee], FormatNumber(playerData[richPlayers[k]][playerMoney]));
						SendClientMessage(playerid, COLOR_WHITE, richList);
					}
				}
			}
		}

	}

	return 1;
}

COMMAND:resetskin(playerid, params[])
{
	new otherID;
	if(!sscanf(params, "d", otherID))
	{
	    if(playerData[playerid][playerLevel] >= 4)
	    {
	        if(!playerData[otherID][playerLoggedIn])
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in.");
			}
			else
			{
			    SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Command succesfully executed.");
            	SendClientMessage(otherID, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Your custom skin has removed by administrator.");
				playerData[otherID][playerCustomSkin] = -1;
			}
	    }
	    else
	    {
	        cmd_resetskin(playerid, "");
	    }
	}
	else
	{
		if(playerData[playerid][playerLoggedIn])
		{
			if (playerData[playerid][playerCustomSkin] != -1)
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Your custom skin will be reset when you next spawn.");
				playerData[playerid][playerCustomSkin] = -1;
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You don't have a custom skin.");
			}
		}
 	}

	return 1;
}

/*COMMAND:me(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		new message[100];

		if(sscanf(params, "s[100]", message))
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"me <message>\"");
		}
		else
		{
			if (playerData[playerid][messageCount] != 3)
			{
				if (playerData[playerid][playerMuteTime] != 0)
				{
					return 0;
				}
				else
				{
					format(message, sizeof(message), "{FE9A2E}* %s %s", playerData[playerid][playerNamee], message);
					SendClientMessageToAll(COLOR_WHITE, message);

					playerData[playerid][messageCount]++;
					KillTimer(playerData[playerid][spamTimer]);
					playerData[playerid][spamTimer] = SetTimerEx("StopSpam", 3000, false, "i", playerid);
				}
			}
		}
	}

	return 1;
}*/

COMMAND:idof(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		new message[250], otherPlayer;

		if(sscanf(params, "u", otherPlayer))
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"id <id/name>\"");
		}
		else
		{
			// Check if player is connected
			if(IsPlayerConnected(otherPlayer))
			{
				if (playerData[otherPlayer][useAdminName])
				{
					format(message, sizeof(message), "{B7B7B7}[SERVER] {FFFFFF}%s(%i)", playerData[otherPlayer][tempAdminName], otherPlayer);
				}
				else
				{
					format(message, sizeof(message), "{B7B7B7}[SERVER] {FFFFFF}%s(%i)", playerData[otherPlayer][playerNamee], otherPlayer);
				}

				SendClientMessage(playerid, COLOR_WHITE, message);
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}That ID is not connected.");
			}
		}
	}

	return 1;
}

COMMAND:myjob(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerJob] == JOB_KIDNAPPER)
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[KIDNAPPER] {FFFFFF}Use {FFDC2E}/kidnap {FFFFFF}to kidnap players.");
		}
		else if(playerData[playerid][playerJob] == JOB_MECHANIC)
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[MECHANIC] {FFFFFF}Use {FFDC2E}/mech {FFFFFF}to view available job commands.");
		}
		else if(playerData[playerid][playerJob] == JOB_WEAPONDEALER)
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[WEAPON DEALER] {FFFFFF}Use {FFDC2E}/sellgun {FFFFFF}to offer weapons to players.");
		}
		else if(playerData[playerid][playerJob] == JOB_HITMAN)
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[HITMAN] {FFFFFF}Use {FFDC2E}/track {FFFFFF}to locate players. Use {FFDC2E}/hitlist {FFFFFF}to view players with a bounty on them.");
		}
		else if(playerData[playerid][playerJob] == JOB_RAPIST)
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[RAPIST] {FFFFFF}Use {FFDC2E}/rape {FFFFFF}to infect players with an STD.");
		}
		else if(playerData[playerid][playerJob] == JOB_DRUGDEALER)
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[DRUG DEALER] {FFFFFF}Use {FFDC2E}/sellweed {FFFFFF}whilst in an ice cream truck to sell drugs to players.");
		}
		else if(playerData[playerid][playerJob] == JOB_TERRORIST)
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[TERRORIST] {FFFFFF}Use {FFDC2E}/usec4 {FFFFFF}whilst in possession of explosives to blow up objectives such as the bank vault, or the jail.");
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[JOB] {FFFFFF}You don't have a job yet.");
		}
	}

	return 1;
}

COMMAND:achievements(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		new
			count, sRules[60], fiftyKills[60], firstKill[60], kills2[60], thousandXP[60], thousandXP2[60], thousandXP3[60], thousandXP4[60],
			firstRobbery[60], robberies[60], robberies2[60], robberies3[60], arrests1[60], arrests2[60], arrests3[60], arrests4[60], amoneyBag[60],
			contracts1[60], contracts2[60], sRobberies1[60], sRobberies2[60], sRobberies3[60], sRape1[60], sRape2[60], sRape3[60], sKidnap1[60], sKidnap2[60], sKidnap3[60],
			dock1[60], dock2[60], dock3[60], defuse1[60], defuse2[60]
		;

		count = 0;

		// read the server rules
		if (playerData[playerid][rulesRead]) { format(sRules, sizeof(sRules), "{58D3F7}(Y)"); count++; } else { format(sRules, sizeof(sRules), "{FE9A2E}(N)"); }

		// find and claim a money bag
		if (playerData[playerid][moneyBags] >= 1) { format(amoneyBag, sizeof(amoneyBag), "{58D3F7}(Y)"); count++; } else { format(amoneyBag, sizeof(amoneyBag), "{FE9A2E}(N)"); }

		// first kill achievement
		if (playerData[playerid][playerKills] >= 1) { format(firstKill, sizeof(firstKill), "{58D3F7}(Y)"); count++; } else { format(firstKill, sizeof(firstKill), "{FE9A2E}(N)"); }

		// 50 kills achievement
		if (playerData[playerid][playerKills] >= 50) { format(fiftyKills, sizeof(fiftyKills), "{58D3F7}(Y)"); count++; } else { format(fiftyKills, sizeof(fiftyKills), "{FE9A2E}(N)"); }

		// 100 kills achievement
		if (playerData[playerid][playerKills] >= 500) { format(kills2, sizeof(kills2), "{58D3F7}(Y)"); count++; } else { format(kills2, sizeof(kills2), "{FE9A2E}(N)"); }

		// 1000 xp achievement
		if (playerData[playerid][playerXP] >= 1000) { format(thousandXP, sizeof(thousandXP), "{58D3F7}(Y)"); count++; } else { format(thousandXP, sizeof(thousandXP), "{FE9A2E}(N)"); }

		// 5000 xp achievement
		if (playerData[playerid][playerXP] >= 5000) { format(thousandXP2, sizeof(thousandXP2), "{58D3F7}(Y)"); count++; } else { format(thousandXP2, sizeof(thousandXP2), "{FE9A2E}(N)"); }

		// 10000 xp achievement
		if (playerData[playerid][playerXP] >= 10000) { format(thousandXP3, sizeof(thousandXP3), "{58D3F7}(Y)"); count++; } else { format(thousandXP3, sizeof(thousandXP3), "{FE9A2E}(N)"); }

		// 20000 xp achievement
		if (playerData[playerid][playerXP] >= 20000) { format(thousandXP4, sizeof(thousandXP4), "{58D3F7}(Y)"); count++; } else { format(thousandXP4, sizeof(thousandXP4), "{FE9A2E}(N)"); }

		// first robbery
		if (playerData[playerid][playerRobberies] >= 1) { format(firstRobbery, sizeof(firstRobbery), "{58D3F7}(Y)"); count++; } else { format(firstRobbery, sizeof(firstRobbery), "{FE9A2E}(N)"); }

		// 20 robberies
		if (playerData[playerid][playerRobberies] >= 20) { format(robberies, sizeof(robberies), "{58D3F7}(Y)"); count++; } else { format(robberies, sizeof(robberies), "{FE9A2E}(N)"); }

		// 50 robberies
		if (playerData[playerid][playerRobberies] >= 50) { format(robberies2, sizeof(robberies2), "{58D3F7}(Y)"); count++; } else { format(robberies2, sizeof(robberies2), "{FE9A2E}(N)"); }

		// 100 robberies
		if (playerData[playerid][playerRobberies] >= 100) { format(robberies3, sizeof(robberies3), "{58D3F7}(Y)"); count++; } else { format(robberies3, sizeof(robberies3), "{FE9A2E}(N)"); }

		// 1 arrest
		if (playerData[playerid][copArrests] >= 1) { format(arrests1, sizeof(arrests1), "{58D3F7}(Y)"); count++; } else { format(arrests1, sizeof(arrests1), "{FE9A2E}(N)"); }

		// 20 arrests
		if (playerData[playerid][copArrests] >= 20) { format(arrests2, sizeof(arrests2), "{58D3F7}(Y)"); count++; } else { format(arrests2, sizeof(arrests2), "{FE9A2E}(N)"); }

		// 50 arrests
		if (playerData[playerid][copArrests] >= 50) { format(arrests3, sizeof(arrests3), "{58D3F7}(Y)"); count++; } else { format(arrests3, sizeof(arrests3), "{FE9A2E}(N)"); }

		// 100 arrests
		if (playerData[playerid][copArrests] >= 100) { format(arrests4, sizeof(arrests4), "{58D3F7}(Y)"); count++; } else { format(arrests4, sizeof(arrests4), "{FE9A2E}(N)"); }

		// 1 contract kill
		if (playerData[playerid][hitsCompleted] == 1) { format(contracts1, sizeof(contracts1), "{58D3F7}(Y)"); count++; } else { format(contracts1, sizeof(contracts1), "{FE9A2E}(N)"); }

		// 20 contract kills
		if (playerData[playerid][hitsCompleted] >= 20) { format(contracts2, sizeof(contracts2), "{58D3F7}(Y)"); count++; } else { format(contracts2, sizeof(contracts2), "{FE9A2E}(N)"); }

		// 1 Street Robbery
		if (playerData[playerid][streetRobberies] >= 1) { format(sRobberies1, sizeof(sRobberies1), "{58D3F7}(Y)"); count++; } else { format(sRobberies1, sizeof(sRobberies1), "{FE9A2E}(N)"); }

		// 10 Street Robberies
		if (playerData[playerid][streetRobberies] >= 10) { format(sRobberies2, sizeof(sRobberies2), "{58D3F7}(Y)"); count++; } else { format(sRobberies2, sizeof(sRobberies2), "{FE9A2E}(N)"); }

		// 50 Street Robberies
		if (playerData[playerid][streetRobberies] >= 50) { format(sRobberies3, sizeof(sRobberies3), "{58D3F7}(Y)"); count++; } else { format(sRobberies3, sizeof(sRobberies3), "{FE9A2E}(N)"); }

		// 1 Street Rape
		if (playerData[playerid][streetRapes] >= 1) { format(sRape1, sizeof(sRape1), "{58D3F7}(Y)"); count++; } else { format(sRape1, sizeof(sRape1), "{FE9A2E}(N)"); }

		// 10 Street Rapes
		if (playerData[playerid][streetRapes] >= 10) { format(sRape2, sizeof(sRape2), "{58D3F7}(Y)"); count++; } else { format(sRape2, sizeof(sRape2), "{FE9A2E}(N)"); }

		// 50 Street Rapes
		if (playerData[playerid][streetRapes] >= 50) { format(sRape3, sizeof(sRape3), "{58D3F7}(Y)"); count++; } else { format(sRape3, sizeof(sRape3), "{FE9A2E}(N)"); }

		// 1 Street Kidnaps
		if (playerData[playerid][playersKidnapped] >= 1) { format(sKidnap1, sizeof(sKidnap1), "{58D3F7}(Y)"); count++; } else { format(sKidnap1, sizeof(sKidnap1), "{FE9A2E}(N)"); }

		// 10 Street Kidnaps
		if (playerData[playerid][playersKidnapped] >= 10) { format(sKidnap2, sizeof(sKidnap2), "{58D3F7}(Y)"); count++; } else { format(sKidnap2, sizeof(sKidnap2), "{FE9A2E}(N)"); }

		// 50 Street Kidnaps
		if (playerData[playerid][playersKidnapped] >= 50) { format(sKidnap3, sizeof(sKidnap3), "{58D3F7}(Y)"); count++; } else { format(sKidnap3, sizeof(sKidnap3), "{FE9A2E}(N)"); }

		// 1 forklift mission
		if (playerData[playerid][forkliftCompleted] >= 1) { format(dock1, sizeof(dock1), "{58D3F7}(Y)"); count++; } else { format(dock1, sizeof(dock1), "{FE9A2E}(N)"); }

		// 10 forklift missions
		if (playerData[playerid][forkliftCompleted] >= 10) { format(dock2, sizeof(dock2), "{58D3F7}(Y)"); count++; } else { format(dock2, sizeof(dock2), "{FE9A2E}(N)"); }

		// 50 forklift missions
		if (playerData[playerid][forkliftCompleted] >= 50) { format(dock3, sizeof(dock3), "{58D3F7}(Y)"); count++; } else { format(dock3, sizeof(dock3), "{FE9A2E}(N)"); }

		// 1 bomb defusal
		if (playerData[playerid][bombsDefused] >= 1) { format(defuse1, sizeof(defuse1), "{58D3F7}(Y)"); count++; } else { format(defuse1, sizeof(defuse1), "{FE9A2E}(N)"); }

		// 10 bomb defusal
		if (playerData[playerid][bombsDefused] >= 10) { format(defuse2, sizeof(defuse2), "{58D3F7}(Y)"); count++; } else { format(defuse2, sizeof(defuse2), "{FE9A2E}(N)"); }

		new aList[1600];

		// General
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Read the /rules", aList, sRules);
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Find and claim a money bag", aList, amoneyBag);

		// Kills
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Kill 1 Player", aList, firstKill);
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Kill 50 Players", aList, fiftyKills);
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Kill 500 Players", aList, kills2);

		// XP
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Earn 1,000 XP", aList, thousandXP);
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Earn 5,000 XP", aList, thousandXP2);
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Earn 10,000 XP", aList, thousandXP3);
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Earn 20,000 XP", aList, thousandXP4);

		// Robberies
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Rob 1 Store", aList, firstRobbery);
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Rob 20 Stores", aList, robberies);
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Rob 50 Stores", aList, robberies2);
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Rob 100 Stores", aList, robberies3);

		// Arrests
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Arrest 1 Criminal", aList, arrests1);
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Arrest 20 Criminals", aList, arrests2);
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Arrest 50 Criminals", aList, arrests3);
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Arrest 100 Criminals", aList, arrests4);

		// Hit Contracts
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Complete 1 Hit Contract", aList, contracts1);
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Complete 20 Hit Contracts", aList, contracts2);

		// Street Robberies
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Complete 1 Street Robbery", aList, sRobberies1);
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Complete 10 Street Robberies", aList, sRobberies2);
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Complete 50 Street Robberies", aList, sRobberies3);

		// Street Rapes
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Rape 1 Player", aList, sRape1);
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Rape 10 Players", aList, sRape2);
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Rape 20 Players", aList, sRape3);

		// Street Kidnaps
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Kidnap 1 Player", aList, sKidnap1);
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Kidnap 10 Players", aList, sKidnap2);
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Kidnap 20 Players", aList, sKidnap3);

		// Forklift Missions
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Complete 1 Forklift Mission", aList, dock1);
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Complete 10 Forklift Missions", aList, dock2);
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Complete 20 Forklift Missions", aList, dock3);

		// Bomb Defusal
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Defuse 1 Bomb", aList, defuse1);
		format(aList, sizeof(aList), "%s\n%s {FFFFFF}Defuse 10 Bombs", aList, defuse2);

		new aTitle[100];
		format(aTitle, sizeof(aTitle), "Achievements %i/32", count);

		ShowPlayerDialog(playerid, DIALOG_ACHIEVEMENTS, DIALOG_STYLE_LIST, aTitle, aList, "OK", "Close");
	}

	return 1;
}

/*COMMAND:redeemvip(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		ShowPlayerDialog(playerid, DIALOG_REDEMPTION, DIALOG_STYLE_LIST, "CNRSF Shop", "Redeem VIP \nRedeem Other", "Next", "Cancel");
	}
	else
	{
	    SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
	}

	return 1;
}*/

COMMAND:cardrop(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
		{
			new time = GetTickCount() - playerData[playerid][lastCarDrop];
			if(time > 300000 || playerData[playerid][lastCarDrop] == -1)
			{
				if(IsPlayerInRangeOfPoint(playerid, -1734.0756, 190.9162, 3.5547, 2.0) || IsPlayerInDynamicCP(playerid, CardropCP))
				{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}This vehicle cannot be dropped off.");
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You are not in a vehicle.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You're not near the car drop checkpoint.");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You've already dropped off a vehicle recently, come back later.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}Only civilians may drop-off vehicles.");
		}
	}
	else
	{
	    SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
	}

	return 1;
}

COMMAND:pc(playerid, params[])
{
	if (playerData[playerid][playerLoggedIn])
	{
		new string[600];

		format(string, sizeof(string), "%s{98B0CD}Player Colours \n", string);
		format(string, sizeof(string), "%s{FFFFFF}The following colour list shows all in-game colours for players. \n", string);
		format(string, sizeof(string), "%s{FFFFFF}LEOs should take note of the wanted level colours. \n\n", string);

		format(string, sizeof(string), "%s{FFFFFF}Civilian\n", string);
		format(string, sizeof(string), "%s{FFEC41}Low Level Wanted\n", string);
		format(string, sizeof(string), "%s{DF802D}Wanted\n", string);
		format(string, sizeof(string), "%s{D92C3C}Most Wanted\n", string);
		format(string, sizeof(string), "%s{3E7EFF}Police\n", string);
		format(string, sizeof(string), "%s{8F48F5}Army\n", string);
		format(string, sizeof(string), "%s{2F205B}CIA\n", string);
		format(string, sizeof(string), "%s{1C3EFF}FBI\n", string);
		format(string, sizeof(string), "%s{F78181}Medic\n", string);
		format(string, sizeof(string), "%s{07E08D}Admin on Duty\n", string);
		format(string, sizeof(string), "%s{58D3F7}Premium Player\n", string);

		ShowPlayerDialog(playerid, DIALOG_PLAYER_COLOURS, DIALOG_STYLE_MSGBOX, "Player Colours", string, "OK", "");
	}
	else
	{
	    SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
	}

	return 1;
}

COMMAND:blockpms(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerBlockPMs])
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You will now receive private messages.");
			playerData[playerid][playerBlockPMs] = false;
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You will no longer receive private messages.");
			playerData[playerid][playerBlockPMs] = true;
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
	}
	return 1;
}

COMMAND:getmytax(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerVIPLevel] < 1)
		{
			if(playerData[playerid][playerMoney] >= 5000)
			{
				new takeValue = floatround(playerData[playerid][playerMoney] * 0.030, floatround_round);

				// Send tax info
				new taxInfo[200];
				format(taxInfo, sizeof(taxInfo), "{FFDC2E}[TAX] {FFFFFF}Your tax is {FFDC2E}$%s {FFFFFF}per game day.", FormatNumber(takeValue));
				SendClientMessage(playerid, COLOR_WHITE, taxInfo);

				if(playerData[playerid][houseCount] > 0)
				{
					new houseTax[200], chousetax;

					chousetax = 1200 * playerData[playerid][houseCount];

					format(houseTax, sizeof(houseTax), "{FFDC2E}[HOUSE TAX] {FFFFFF}Your house tax is {FFDC2E}$%s {FFFFFF}per game day.", FormatNumber(chousetax));
					SendClientMessage(playerid, COLOR_WHITE, houseTax);
				}

			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[TAX] {FFFFFF}You have less than $5,000 therefore you're exempt from tax.");
			}
		}
		else
		{
			// No tax
			SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[TAX] {FFFFFF}You're exempt from tax.");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
	}
	return 1;
}

COMMAND:cuttie(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerIsTied])
		{
			if(playerData[playerid][playerScissors] > 0)
			{
				new rand = random(3);
				if(rand == 1 || rand == 2)
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[CUT TIE] {FFFFFF}You successfully cut the tie and escaped.");
					playerData[playerid][playerScissors] = playerData[playerid][playerScissors] - 1;

					playerData[playerid][playerIsTied] = false;

					SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
					KillTimer(playerData[playerid][untieTimer]);

					TogglePlayerControllable(playerid, 1);
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[CUT TIE] {FFFFFF}You failed to cut the tie.");
					playerData[playerid][playerScissors] = playerData[playerid][playerScissors] - 1;
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You don't have any scissors.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You are not tied.");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
	}
	return 1;
}

COMMAND:breakcuffs(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerIsCuffed])
		{
			if(playerData[playerid][playerBobbyPins] > 0)
			{
				if (playerData[playerid][canBreakCuffs])
				{
					new rand = random(3);
					if(rand == 1 || rand == 2)
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[BREAK CUFFS] {FFFFFF}You have successfully broken your cuffs and escaped.");
						playerData[playerid][playerBobbyPins]--;

						playerData[playerid][playerIsCuffed] = false;

						SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
						KillTimer(playerData[playerid][uncuffTimer]);

						TogglePlayerControllable(playerid, 1);
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[BREAK CUFFS] {FFFFFF}You failed to break your cuffs.");
						playerData[playerid][playerBobbyPins]--;

						playerData[playerid][breakCuffsTimer] = SetTimerEx("rebreakcuffs", 30000, false, "i", playerid);

						// Cannot cuff for 30 seconds
						playerData[playerid][canBreakCuffs] = false;
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}Please wait before attempting to break free again.");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You don't have any bobby pins.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR} {FFFFFF}You are not cuffed.");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
	}
	return 1;
}

COMMAND:bc(playerid, params[])
{
	return cmd_breakcuffs(playerid, params);
}

COMMAND:admins(playerid, params[])
{
	if (playerData[playerid][playerScore] >= 100)
	{
		new count = 1, string[828];
		for(new i = 0; i < MAX_PLAYERS; i++)
		{
			if(IsPlayerConnected(i) && playerData[i][playerLevel] >= 1 && playerData[i][playerLevel] < 7)
			{
				// If admin level is higher than 1, here it goes...
				format(string, sizeof(string), "%s%s(%i) - Level: %i\n", string, playerData[i][tempAdminName], i, playerData[i][playerLevel]);
				count ++;
			}
		}

		if(count != 1)
		{
			// Show admins that are presently online, along with their rank
			ShowPlayerDialog(playerid, 200, DIALOG_STYLE_MSGBOX, "Online Administrators", string, "OK", "");
		}
		else
		{
			// No admins online - Either this or nothing, either way the user will know admins are offline...
			ShowPlayerDialog(playerid, 200, DIALOG_STYLE_MSGBOX, "Online Admins", "There are no administrators present.", "OK", "");
		}
	}
	else
	{
	    SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must have at least 100 score to view the admin list.");
	}

	return 1;
}

COMMAND:jaillist(playerid, params[])
{
    new count = 1, name[24], string[828];
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerConnected(i) && playerData[i][playerJailTime] >= 1)
        {
			// If jail time is higher than 1
            GetPlayerName(i, name, sizeof(name));
            format(string, sizeof(string), "%s%s(%i)\n", string, name, i);
            count ++;
        }
    }

    if(count != 1)
    {
        ShowPlayerDialog(playerid, 200, DIALOG_STYLE_MSGBOX, "Jailed Players", string, "OK", "");
    }
	else
	{
	    ShowPlayerDialog(playerid, 200, DIALOG_STYLE_MSGBOX, "Jailed Players", "No players are jailed.", "OK", "");
	}

	return 1;

}

COMMAND:hitlist(playerid, params[])
{
    new count = 1, name[24], string[828];
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerConnected(i) && playerData[i][playerHitValue] >= 1000)
        {
            GetPlayerName(i, name, sizeof(name));
            format(string, sizeof(string), "%s%s(%i) - Hit Value: $%s\n", string, name, i, FormatNumber(playerData[i][playerHitValue]));
            count ++;
        }
    }

    if(count != 1)
    {
        ShowPlayerDialog(playerid, 200, DIALOG_STYLE_MSGBOX, "Hit List", string, "OK", "");
    }
	else
	{
	    ShowPlayerDialog(playerid, 200, DIALOG_STYLE_MSGBOX, "Hit List", "No players have a bounty on their head.", "OK", "");
	}

	return 1;
}

COMMAND:helpers(playerid, params[])
{
    new count = 1, name[24], string[528];
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerConnected(i) && playerData[i][playerHelper] >= 1)
        {
			if (playerData[i][playerHelper] > 2)
			{
				playerData[i][playerHelper] = 0;
			}

            GetPlayerName(i, name, sizeof(name));
            format(string, sizeof(string), "%s%s(%i) - Level: %i\n", string, name, i, playerData[i][playerHelper]);
            count ++;
        }
    }

    if(count != 1)
    {
        ShowPlayerDialog(playerid, 200, DIALOG_STYLE_MSGBOX, "Helpers", string, "OK", "");
    }
	else
	{
	    ShowPlayerDialog(playerid, 200, DIALOG_STYLE_MSGBOX, "Helpers", "There are no helpers online.", "OK", "");
	}

	return 1;
}

COMMAND:viplist(playerid, params[])
{
    new count = 1, name[24], string[200], level[100];
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerConnected(i) && playerData[i][playerVIPLevel] > 0)
        {
			// If VIPLevel is higher than 1
            GetPlayerName(i, name, sizeof(name));

			if(playerData[i][playerVIPLevel] >= 1)
			{
				switch(playerData[i][playerVIPLevel])
				{
					case 1:
					{
						level = "Standard VIP";
					}
					case 2:
					{
						level = "Silver VIP";
					}
					case 3:
					{
						level = "Gold VIP";
					}
					case 4:
					{
						level = "Gold+ VIP";
					}
				}

				format(string, sizeof(string), "%s%s(%i) - %s\n", string, name, i, level);
			}

			count ++;

        }
    }

    if(count != 1)
    {
        ShowPlayerDialog(playerid, 200, DIALOG_STYLE_MSGBOX, "VIP List", string, "OK", "");
    }
	else
	{
	    ShowPlayerDialog(playerid, 200, DIALOG_STYLE_MSGBOX, "VIP List", "There are no Premium players online.", "OK", "");
	}

	return 1;
}

COMMAND:r(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		new input[120], message[250], message2[250];

		if(sscanf(params, "s[100]", input))
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"r <message>\"");
		}
		else
		{
			if (playerData[playerid][lastRecipient] == -1)
			{
				// No recipient
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}There is no one to quickly respond to. Use /pm!");
			}
			else
			{
				new replyto = playerData[playerid][lastRecipient];
				// Check if player is connected
				if(IsPlayerConnected(replyto))
				{
					if(playerData[replyto][playerLoggedIn])
					{
						if(!playerData[replyto][playerBlockPMs])
						{
							new from[24], otherName[24];
							GetPlayerName(replyto, otherName, sizeof(otherName));
							format(message, sizeof(message), "{FFBF00}[PM] {FFFFFF}To %s(%i): %s", otherName, replyto, input);
							SendClientMessage(playerid, COLOR_WHITE, message);

							GetPlayerName(playerid, from, sizeof(from));
							format(message2, sizeof(message2), "{FFBF00}[PM] {FFFFFF}From %s(%i): %s", from, playerid, input);
							SendClientMessage(replyto, COLOR_WHITE, message2);
							PlayerPlaySound(replyto, 1085,0.0,0.0,0.0);

							for(new i = 0; i <= MAX_PLAYERS; i++)
							{
								if(IsPlayerConnected(i))
								{
									if(playerData[i][playerLoggedIn])
									{
										if (playerData[i][playerLevel] > 4)
										{
											if (playerData[i][pmSpy])
											{
												new spyText[200];
												format(spyText, sizeof(spyText), "{FFBF00}[PM SPY] {FFFFFF}From %s(%i) to %s(%i): %s", playerData[playerid][playerNamee], playerid, playerData[replyto][playerNamee], replyto, input);
												SendClientMessage(i, COLOR_WHITE, spyText);
											}
										}
									}
								}
							}

							new loggingString[256];
							format(loggingString, sizeof(loggingString), "%s PM'd %s: %s", playerData[playerid][playerNamee], playerData[replyto][playerNamee], input);
							writeInLog("privateMessages.html", loggingString);
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}The player your trying to PM has disabled private messages.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}The player your trying to PM is not logged in.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}The player your trying to PM isn't connected.");
				}
			}
		}
	}
	return 1;
}

COMMAND:pm(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		new input[120], message[250], message2[250], otherPlayer;

		if(sscanf(params, "us[100]", otherPlayer, input))
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"pm <player> <message>\"");
		}
		else
		{
			if (playerid == otherPlayer)
			{
				// Cannot send yourself a PM
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot send yourself a PM.");
			}
			else
			{
				// Check if player is connected
				if(IsPlayerConnected(otherPlayer))
				{
					if(playerData[otherPlayer][playerLoggedIn])
					{
						if(!playerData[otherPlayer][playerBlockPMs] || playerData[otherPlayer][playerBlockPMs] && playerData[playerid][playerLevel] >= 1)
						{
							new from[24], otherName[24];
							GetPlayerName(otherPlayer, otherName, sizeof(otherName));
							format(message, sizeof(message), "{FFBF00}[PM] {FFFFFF}To %s(%i): %s", otherName, otherPlayer, input);
							SendClientMessage(playerid, COLOR_WHITE, message);

							GetPlayerName(playerid, from, sizeof(from));
							format(message2, sizeof(message2), "{FFBF00}[PM] {FFFFFF}From %s(%i): %s", from, playerid, input);
							SendClientMessage(otherPlayer, COLOR_WHITE, message2);
       						PlayerPlaySound(otherPlayer, 1139,0.0,0.0,0.0);

							playerData[playerid][lastRecipient] = otherPlayer;

							for(new i = 0; i <= MAX_PLAYERS; i++)
							{
								if(IsPlayerConnected(i))
								{
									if(playerData[i][playerLoggedIn])
									{
										if (playerData[i][playerLevel] >= 4)
										{
											if (playerData[i][pmSpy])
											{
												new spyText[200];
												format(spyText, sizeof(spyText), "{FFBF00}[PM SPY] {FFFFFF}From %s(%i) to %s(%i): %s", playerData[playerid][playerNamee], playerid, playerData[otherPlayer][playerNamee], otherPlayer, input);
												SendClientMessage(i, COLOR_WHITE, spyText);
											}
										}
									}
								}
							}

							new loggingString[256];
							format(loggingString, sizeof(loggingString), "%s PM'd %s: %s", playerData[playerid][playerNamee], playerData[otherPlayer][playerNamee], input);
							writeInLog("privateMessages.html", loggingString);
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}The player your trying to PM has disabled private messages.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}The player your trying to PM is not logged in.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}The player your trying to PM isn't connected.");
				}
			}
		}
	}
	return 1;
}

COMMAND:whisper(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		new string[250];

		if (sscanf(params, "s[250]", string))
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"/(w)hisper <message>\"");
		}
		else
		{
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid,x,y,z);

			new string2[250];
			format(string2, sizeof(string2), "{B76767}[WHISPER] {FFFFFF}%s(%i): %s", playerData[playerid][playerNamee], playerid, string);

			for(new i = 0; i <= MAX_PLAYERS; i++)
			{
				if(IsPlayerInRangeOfPoint(i, 15.0, x, y, z))
				{
					SendClientMessage(i, COLOR_WHITE, string2);
					PlayerPlaySound(i, 1085,0.0,0.0,0.0);
				}
			}
		}
	}
	return 1;
}

COMMAND:cw(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		new string[250];

		if (sscanf(params, "s[250]", string))
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"/cw <message>\"");
		}
		else
		{
			if(IsPlayerInAnyVehicle(playerid))
			{
				new vehicleID = GetPlayerVehicleID(playerid);

				new string2[250];
				format(string2, sizeof(string2), "{FE9A2E}[CAR WHISPER] {FFFFFF}%s(%i): %s", playerData[playerid][playerNamee], playerid, string);

				for(new i = 0; i <= MAX_PLAYERS; i++)
				{
					if(IsPlayerInVehicle(i, vehicleID))
					{
						SendClientMessage(i, COLOR_WHITE, string2);
					}
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You are not in a vehicle.");
			}
		}
	}
	return 1;
}

COMMAND:eject(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		new otherID;

		if (sscanf(params, "u", otherID))
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"/eject <player>\"");
		}
		else
		{
			if(playerid != otherID)
			{
				if(IsPlayerInAnyVehicle(playerid))
				{
					if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
					{
						new vehicleID = GetPlayerVehicleID(playerid);
						if(IsPlayerConnected(otherID))
						{
							if(IsPlayerInAnyVehicle(otherID))
							{
								if(GetPlayerVehicleID(otherID) == vehicleID)
								{
									RemovePlayerFromVehicle(otherID);

									SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[EJECTED] {FFFFFF}The player has been ejected from your vehicle.");
									SendClientMessage(otherID, COLOR_WHITE, "{B7B7B7}[EJECTED] {FFFFFF}You have been ejected from the vehicle.");
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}The player is not in your vehicle.");
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}The player is not in your vehicle.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}The player your trying to eject isn't connected.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be the driver to eject players.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You are not in a vehicle.");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot eject yourself.");
			}
		}
	}
	return 1;
}

COMMAND:w(playerid, params[])
{
	return cmd_whisper(playerid, params);
}

COMMAND:payticket(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (playerData[playerid][playerLastTicket] == -1)
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}There are no tickets to pay.");
		}
		else
		{
			new message[250];
			new status = checkNameStatus(playerData[playerid][playerLastTicket]);
			if(status == -1)
			{
				// Pay cash to state
				SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[TICKET] {FFFFFF}You have paid your ticket.");
				playerTakeMoney(playerid, 2500);

				SetPlayerWantedLevel(playerid, playerData[playerid][playerWantedLevel] - 3);
				playerData[playerid][playerWantedLevel] = playerData[playerid][playerWantedLevel] - 3;
				newPlayerColour(playerid);
				playerData[playerid][playerLastTicket] = -1;
			}
			else
			{
				// Pay cash to ID
				playerGiveMoney(status, 2500);
				playerTakeMoney(playerid, 2500);

				SetPlayerWantedLevel(playerid, playerData[playerid][playerWantedLevel] - 3);
				playerData[playerid][playerWantedLevel] = playerData[playerid][playerWantedLevel] - 3;
				playerData[playerid][playerLastTicket] = -1;
				newPlayerColour(playerid);

				// Send message to player
				SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[TICKET] {FFFFFF}You have paid your ticket.");

				// Send message to cop
				format(message, sizeof(message), "{FFDC2E}[TICKET PAID] {FFFFFF}You received {FFDC2E}$2,500 {FFFFFF}from %s(%i)", playerData[playerid][playerNamee], playerid);
				SendClientMessage(status, COLOR_WHITE, message);
			}
		}
	}
	return 1;
}

COMMAND:acceptbail(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (playerData[playerid][playerJailTime] > 1)
		{
			if (playerData[playerid][playerBailTo] == -1)
			{
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}There are no bail offers.");
			}
			else
			{
				if (playerData[playerid][playerMoney] >= playerData[playerid][playerBailPrice])
				{
					new message[250];
					new bailID = playerData[playerid][playerBailTo];
					if (playerid != bailID)
					{
						if(IsPlayerConnected(bailID))
						{
							if(playerData[bailID][playerClass] == CLASS_POLICE || playerData[bailID][playerClass] == CLASS_ARMY || playerData[bailID][playerClass] == CLASS_CIA || playerData[bailID][playerClass] == CLASS_FBI) // offer gone
							{
								// Pay cash to ID
								playerGiveMoney(bailID, playerData[playerid][playerBailPrice]);
								playerTakeMoney(playerid, playerData[playerid][playerBailPrice]);

								// Send message to cop
								format(message, sizeof(message), "{58D3F7}[BAIL PAID] {FFFFFF}You received {FFDC2E}$%s {FFFFFF}from %s(%i)", FormatNumber(playerData[playerid][playerBailPrice]), playerData[playerid][playerNamee], playerid);
								SendClientMessage(bailID, COLOR_WHITE, message);
								playerGiveXP(bailID, 5);

								new loggingString[256];
								format(loggingString, sizeof(loggingString), "%s bailed %s for $%s.", playerData[bailID][playerNamee], playerData[playerid][playerNamee], FormatNumber(playerData[playerid][playerBailPrice]));
								writeInLog("bailTransactions.html", loggingString);

								playerData[playerid][playerBailTo] = 0;
								playerData[playerid][playerBailPrice] = 0;

								// Release from jail
								SetPlayerInterior(playerid, 10);
								SetPlayerPos(playerid, 249.4593, 115.0391, 1003.2188);
								SetPlayerFacingAngle(playerid, 183.3742);
								SetPlayerVirtualWorld(playerid, 25);
								SetPlayerHealth(playerid, 100);
								PlayerTextDrawSetString(playerid, playerData[playerid][playerJailTimerTD], " ");
								playerData[playerid][playerJailTime] = 0;
								KillTimer(playerData[playerid][jailTimer]);

								new Name[24], MsgAll[200];
								GetPlayerName(playerid, Name, sizeof(Name));

								for(new p; p < MAX_PLAYERS; p++)
								{
									new pName[24];
									GetPlayerName(p, pName, sizeof(pName));

									if(!strcmp(pName, Name))
									{
										SendClientMessage(p, COLOR_WHITE, "{58D3F7}[BAIL] {FFFFFF}You have been released on bail.");
									}
									else
									{
										format(MsgAll, sizeof(MsgAll), "{FFDC2E}[JAIL] {FFFFFF}%s(%i) has been released from jail {58D3F7}[Paid Bail]{FFFFFF}", Name, playerid);
										SendClientMessage(p, COLOR_WHITE, MsgAll);
									}
								}
							}
							else
							{
								// Cop offline
								SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}The bail offer is no longer available.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}The bail offer is no longer available. (2)");
						}
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cant afford this offer.");
				}
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You aren't jailed.");
		}
	}

	return 1;
}

COMMAND:report(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (playerData[playerid][canReport])
		{
			new input[120], message[250];

			if(sscanf(params, "s[100]", input))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"report <message>\"");
			}
			else
			{
				for(new i = 0; i < MAX_PLAYERS; i++)
				{
					if(IsPlayerConnected(i) && playerData[i][playerLevel] >= 1)
					{
						format(message, sizeof(message), "{DF0101}[REPORT] {FFFFFF}From %s(%i): %s", playerData[playerid][playerNamee], playerid, input);
						SendClientMessage(i, COLOR_WHITE, message);
					}
				}

				SendClientMessage(playerid, COLOR_WHITE, "{DF0101}[REPORT] {FFFFFF}Your report has been sent to the online administrators.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You have been blocked from using report by an administrator.");
		}
	}
	return 1;
}

COMMAND:ask(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (playerData[playerid][canAsk])
		{
			new input[120], message[250];

			if(sscanf(params, "s[100]", input))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"ask <message>\"");
			}
			else
			{
				for(new i = 0; i < MAX_PLAYERS; i++)
				{
					if(IsPlayerConnected(i) && playerData[i][playerLevel] >= 1 || playerData[i][playerHelper] == 1)
					{
						format(message, sizeof(message), "{FE9A2E}[QUESTION] {FFFFFF}From %s(%i): %s", playerData[playerid][playerNamee], playerid, input);
						SendClientMessage(i, COLOR_WHITE, message);
					}
				}

				SendClientMessage(playerid, COLOR_WHITE, "{FE9A2E}[QUESTION] {FFFFFF}Your question has been sent to the online helpers.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You have been blocked from using ask by an administrator.");
		}
	}
	return 1;
}

COMMAND:answer(playerid, params[])
{
	return cmd_ans(playerid, params);
}

COMMAND:radio(playerid, params[])
{
    if (playerData[playerid][playerLoggedIn])
    {
 	    new string[3000];

    	strcat(string,"{FCFCFF}Country\n");
 		strcat(string,"{FCFCFF}Drum n' Bass\n");
 		strcat(string,"{FCFCFF}Electronic\n");
 		strcat(string,"{FCFCFF}Metal\n");
 		strcat(string,"{FCFCFF}Hip - Hop\n");
		strcat(string,"{FCFCFF}Pop\n");
		strcat(string,"{FCFCFF}Rap\n");
		strcat(string,"{FCFCFF}Raggae\n");
		strcat(string,"{FCFCFF}Rock\n");
		strcat(string,"{FCFCFF}Trance\n");
		strcat(string,"{FCFCFF}Techno\n");
		strcat(string,"{FCFCFF}House\n");
		strcat(string,"{FCFCFF}SKY.FM Hits\n");
		strcat(string,"{FCFCFF}Party 181.FM\n");
		strcat(string,"{FCFCFF}Top 40 181.FM\n");
		strcat(string,"{FCFCFF}977 Hits.\n");

		ShowPlayerDialog(playerid, DIALOG_RADIO, DIALOG_STYLE_LIST,"Radio",string,"Select","Cancel");

		return 1;
    }
    else
    {
        SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
    }
    return 1;
}

COMMAND:stopradio(playerid, params[])
{
    if (playerData[playerid][playerLoggedIn])
    {
        StopAudioStreamForPlayer(playerid); // Stop the audio stream
	}
    else
    {
        SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
    }
    return 1;
}

COMMAND:help(playerid, params[])
{
    if (playerData[playerid][playerLoggedIn])
    {
		ShowPlayerDialog(playerid, DIALOG_HELP, DIALOG_STYLE_LIST, "CZCNR Help", "Player Commands\nServer Admins\nHosted Events\nPlayer Houses\nStore Robberies\nTokens", "Go", "Cancel");
    }
    else
    {
        SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
    }
    return 1;
}

COMMAND:vipcmds(playerid, params[])
{
    if (playerData[playerid][playerLoggedIn])
    {
		if(playerData[playerid][playerVIPLevel] > 0)
		{
		new string[1200];
		format(string, sizeof(string), "%s{98B0CD}1. {FFFFFF}/viphat \n", string);
		format(string, sizeof(string), "%s{98B0CD}2. {FFFFFF}/vipskin \n", string);
		format(string, sizeof(string), "%s{98B0CD}3. {FFFFFF}/vmod \n", string);
		format(string, sizeof(string), "%s{98B0CD}4. {FFFFFF}/toys \n", string);
		format(string, sizeof(string), "%s{98B0CD}5. {FFFFFF}/vipweapon \n", string);
		format(string, sizeof(string), "%s{98B0CD}6. {FFFFFF}/vsay \n", string);
		format(string, sizeof(string), "%s{98B0CD}6. {FFFFFF}/parrot \n", string);
		format(string, sizeof(string), "%s{98B0CD}7. {FFFFFF}/countdown \n", string);
		ShowPlayerDialog(playerid, 188, DIALOG_STYLE_MSGBOX, "VIP Commands", string, "OK", "Leave");
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be a VIP member to use this command.");
		}
    }
    else
    {
        SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
    }
    return 1;
}

COMMAND:vmod(playerid, params[])
{
    if (playerData[playerid][playerLoggedIn])
    {
		if(playerData[playerid][playerVIPLevel] >= 2)
		{
			if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
			{
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be the driver of a vehicle to use this command.");
			}
			else
			{
				new vehiclemodel = GetVehicleModel(GetPlayerVehicleID(playerid));
				if(vehiclemodel < 400 || vehiclemodel > 611)
				{
					SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}This vehicle can't be modified.");
				}
				else
				{
					new string[2048], component, title[80];
					ccount[playerid] = 1;

					while(GetVehicleCompatibleUpgrades(vehiclemodel, ccount[playerid], component))
					{
						if(ccount[playerid] <= MAX_COMP)
						{
							if(ccount[playerid] == 1) format(string, sizeof(string), "%s", GetComponentName(component));
							else format(string, sizeof(string), "%s\n%s", string, GetComponentName(component));
							componentsid[playerid][ccount[playerid]-1] = component;
							ccount[playerid]++;
						}
						else
						{
							break;
						}
					}

					format(title, sizeof(title), "VIP Mod Menu", vehiclemodel);
					ShowPlayerDialog(playerid, DIALOG_MODMENU, DIALOG_STYLE_LIST, title, string, "Apply", "Cancel");
				}
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be at-least Silver VIP to use this command.");
		}
    }
    else
    {
        SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
    }

    return 1;
}

COMMAND:viphat(playerid, params[])
{
    if (playerData[playerid][playerLoggedIn])
    {
		if(playerData[playerid][playerVIPLevel] >= 1)
		{
			ShowPlayerDialog(playerid, DIALOG_VIPHAT, DIALOG_STYLE_LIST, "VIP HATS", "Hat 1\nHat 2\nHat 3\nHat 4\nHat 5\nHat 6 \nHat 7\nHat 8\n{D87C3E}Remove Hat", "Wear", "Close");
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be a VIP to use this command.");
		}
    }
    else
    {
        SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
    }

    return 1;
}

COMMAND:commands(playerid, params[])
{
    if (playerData[playerid][playerLoggedIn])
    {
		ShowPlayerDialog(playerid, DIALOG_COMMANDS, DIALOG_STYLE_LIST, "Commands", "General Commands\nTrucker Commands\nAnimation Commands\nPolice Commands\nJob Commands\nHouse Commands\nVehicle Commands", "Go", "Cancel");
    }
    else
    {
        SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
    }
    return 1;
}

COMMAND:cmds(playerid, params[])
{
	return cmd_commands(playerid, params);
}

COMMAND:rules(playerid, params[])
{
    if (playerData[playerid][playerLoggedIn])
    {
		new string[1200];
		format(string, sizeof(string), "%s{98B0CD}1. {FFFFFF}Respect players and admins. \n", string);
		format(string, sizeof(string), "%s{98B0CD}2. {FFFFFF}Do not flood the chat, or advertise other servers. \n", string);
		format(string, sizeof(string), "%s{98B0CD}3. {FFFFFF}Hacking/Cheating will get you banned. \n", string);
		format(string, sizeof(string), "%s{98B0CD}4. {FFFFFF}LEO players must not kill innocent civilians. \n", string);
		format(string, sizeof(string), "%s{98B0CD}5. {FFFFFF}Team killing is not allowed. \n", string);
		format(string, sizeof(string), "%s{98B0CD}6. {FFFFFF}Do not tie abuse (leaving a player once tied) \n", string);
		format(string, sizeof(string), "%s{98B0CD}7. {FFFFFF}If you are a LEO, do not assist criminals. \n", string);
		format(string, sizeof(string), "%s{98B0CD}8. {FFFFFF}Do not EMP vehicles if there are no wanted players inside. \n", string);
		format(string, sizeof(string), "%s{98B0CD}9. {FFFFFF}Do not quit or pause to avoid anything. You will be jailed for this.\n", string);
		format(string, sizeof(string), "%s{98B0CD}10. {FFFFFF}Park your owned vehicle in a sensible spot, preferably at your home. \n", string);
		format(string, sizeof(string), "%s{98B0CD}11. {FFFFFF}Farming score/xp/money is unacceptable, you will be banned for this. \n", string);
		format(string, sizeof(string), "%s{98B0CD}12. {FFFFFF}Do not drive-by without a driver. \n", string);
		format(string, sizeof(string), "%s{98B0CD}13. {FFFFFF}The scam limit is $8,000. \n", string);
		format(string, sizeof(string), "%s{98B0CD}14. {FFFFFF}Do not question administrative actions. \n", string);
		format(string, sizeof(string), "%s{98B0CD}15. {FFFFFF}Bugs should be reported, not exploited. \n", string);
		format(string, sizeof(string), "%s{98B0CD}16. {FFFFFF}Keybinds are not allowed. \n", string);
		format(string, sizeof(string), "%s{98B0CD}17. {FFFFFF}Roadblock and Spike Strip abuse are not allowed. \n", string);

		if (!playerData[playerid][rulesRead])

		{
			disableAchieve(playerid);
			PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
			PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
			PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
			PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

			PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "Book Worm");
			PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "You read the server rules, great!");
			PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);

			playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 6000, false, "i", playerid);

			playerGiveXP(playerid, 25);
			playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
			playerData[playerid][rulesRead] = 1;
			SetPlayerScore(playerid, playerData[playerid][playerScore]);
			savePlayerStats(playerid);
		}

		ShowPlayerDialog(playerid, DIALOG_RULES, DIALOG_STYLE_MSGBOX, "Rules", string, "OK", "");
    }
    else
    {
        SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
    }
    return 1;
}

COMMAND:vip(playerid, params[])
{
    if (playerData[playerid][playerLoggedIn])
    {
		new string[2200];
		format(string, sizeof(string), "{FFDC2E}Standard VIP [$4.00 USD]\n\n", string);
		format(string, sizeof(string), "%s{FFFFFF}- Receive 500,000 in-game cash.\n", string);
		format(string, sizeof(string), "%s{FFFFFF}- Receive 1,050 in-game XP.\n", string);
		format(string, sizeof(string), "%s{FFFFFF}- Gets access to VIP louge for health refills.\n", string);
		format(string, sizeof(string), "%s{FFFFFF}- Get access to: /vsay, /viphelp, /parrot, /vipcolour, /viphat, /vcolour\n", string);
		format(string, sizeof(string), "%s{FFFFFF}- Get a 30.5% success rate, on asking an admin for an event and them saying yes.\n", string);
		format(string, sizeof(string), "%s{FFFFFF}- Get 1 FREE VIP House, of any location!\n", string);

		format(string, sizeof(string), "%s{FFFFFF}-------------------------------------------------------------------\n\n", string);

		format(string, sizeof(string), "%s{FFDC2E}Silver VIP [$7.00 USD]{FFFFFF}\n\n", string);
		format(string, sizeof(string), "%s{FFFFFF}- Receive 2 million in-game cash.\n", string);
		format(string, sizeof(string), "%s{FFFFFF}- Receive 16,000 in-game XP.\n", string);
		format(string, sizeof(string), "%s{FFFFFF}- Gets access to VIP louge for 50 percent armour refills.\n", string);
		format(string, sizeof(string), "%s{FFFFFF}- Get access to: /vmod, /vipweapon\n", string);
		format(string, sizeof(string), "%s{FFFFFF}- Connect/Spawn with 50 percent armour.\n", string);
		format(string, sizeof(string), "%s{FFFFFF}- Get 3 Tokens, each token is valid for a vehicle.\n", string);
		format(string, sizeof(string), "%s{FFFFFF}- Get a 70.5% success rate, on asking an admin for an event and them saying yes.\n", string);
		format(string, sizeof(string), "%s{FFFFFF}- Get 1 FREE VIP House, of any location!\n", string);
		format(string, sizeof(string), "%s{FFFFFF}- Get all of the things from Standard VIP.\n", string);

		format(string, sizeof(string), "%s{FFFFFF}-------------------------------------------------------------------\n\n", string);

		format(string, sizeof(string), "%s{FFDC2E}Gold VIP [$10.00 USD]{FFFFFF}\n\n", string);
		format(string, sizeof(string), "%s{FFFFFF}- Receive 5 million in-game cash.\n", string);
		format(string, sizeof(string), "%s{FFFFFF}- Receive 30,000 in-game XP.\n", string);
		format(string, sizeof(string), "%s{FFFFFF}- Gets access to VIP louge for 100 percent armour refills.\n", string);
		format(string, sizeof(string), "%s{FFFFFF}- Get access to: /toys, /vipskin\n", string);
		format(string, sizeof(string), "%s{FFFFFF}- Connect/Spawn with 100 percent armour.\n", string);
		format(string, sizeof(string), "%s{FFFFFF}- Get 7 Tokens, each token is valid for a vehicle.\n", string);
		format(string, sizeof(string), "%s{FFFFFF}- Get a 99.5% success rate, on asking an admin for an event and them saying yes.\n", string);
		format(string, sizeof(string), "%s{FFFFFF}- Get 2 FREE VIP Houses, of any location!\n", string);
		format(string, sizeof(string), "%s{FFFFFF}- Get all of the things from Silver VIP & Standard VIP.\n", string);

		ShowPlayerDialog(playerid, DIALOG_RULES, DIALOG_STYLE_MSGBOX, "V.I.P Packages", string, "OK", "");
    }
    else
    {
        SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
    }
    return 1;
}

COMMAND:shop(playerid, params[])
{
    if (playerData[playerid][playerLoggedIn])
    {
        new curint = GetPlayerInterior(playerid);
        if (curint == 90 || curint == 207)
        {
			if (!playerData[playerid][playerIsTied] && !playerData[playerid][playerIsCuffed])
			{
				new supaSave[1000];
				format(supaSave, sizeof(supaSave), "%s\n{D87C3E}$1,000      {FFFFFF}1x Rope {FFBF00}(Saves)", supaSave);
				format(supaSave, sizeof(supaSave), "%s\n{D87C3E}$2,500      {FFFFFF}1x Scissors {FFBF00}(Saves)", supaSave);
				format(supaSave, sizeof(supaSave), "%s\n{D87C3E}$2,000      {FFFFFF}1x Bobby Pins {FFBF00}(Saves)", supaSave);
				format(supaSave, sizeof(supaSave), "%s\n{D87C3E}$2,000      {FFFFFF}4x Bobby Pins {FFBF00}(Saves)", supaSave);
				format(supaSave, sizeof(supaSave), "%s\n{D87C3E}$15,000    {FFFFFF}Backpack {FFBF00}(Saves)", supaSave);
				format(supaSave, sizeof(supaSave), "%s\n{D87C3E}$5,000      {FFFFFF}Bigger Pockets", supaSave);
				format(supaSave, sizeof(supaSave), "%s\n{D87C3E}$5,000      {FFFFFF}Secure Wallet", supaSave);
				format(supaSave, sizeof(supaSave), "%s\n{D87C3E}$5,000      {FFFFFF}1x Butt Plug", supaSave);
				format(supaSave, sizeof(supaSave), "%s\n{D87C3E}$25,000    {FFFFFF}Lucky Charm", supaSave);
				format(supaSave, sizeof(supaSave), "%s\n{D87C3E}$20,000    {FFFFFF}Mask {FFBF00}(Removed on death)", supaSave);
				format(supaSave, sizeof(supaSave), "%s\n{D87C3E}$10,000    {FFFFFF}Bomb Defusal Kit", supaSave);
   				format(supaSave, sizeof(supaSave), "%s\n{D87C3E}$5,000      {FFFFFF}1x Escapists Guide", supaSave);
   				format(supaSave, sizeof(supaSave), "%s\n{D87C3E}$20,000     {FFFFFF}Toy System", supaSave);

				ShowPlayerDialog(playerid, DIALOG_SUPASAVE, DIALOG_STYLE_LIST, "Shop", supaSave, "Buy", "Close");
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot do this whilst tied/cuffed.");
			}
		}
        else
        {
            SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You're not inside Supa Save.");
        }
    }
    else
    {
        SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
    }
    return 1;
}

COMMAND:xpmarket(playerid, params[])
{
    if (playerData[playerid][playerLoggedIn])
    {
		if (!playerData[playerid][playerIsTied] && !playerData[playerid][playerIsCuffed])
		{
			new xpSHOP[500];
			format(xpSHOP, sizeof(xpSHOP), "%s\n{D87C3E}100 XP       {FFFFFF}Gives you $1000 in cash.", xpSHOP);

			ShowPlayerDialog(playerid, DIALOG_XPSHOP, DIALOG_STYLE_LIST, "XP Shop", xpSHOP, "Buy", "Close");
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot do this whilst tied/cuffed.");
		}
    }
    else
    {
        SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
    }
    return 1;
}

COMMAND:kill(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
	    if (playerData[playerid][playerWantedLevel] == 0)
	    {
		    if(playerData[playerid][playerJailTime] <= 0)
			{
				if(!playerData[playerid][playerIsTied])
				{
					playerData[playerid][suicide] = true;
					SetPlayerHealth(playerid, 0.0);
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot use this command whilst you are tied!");
				}
			}
			else
			{
			    SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot use this command whilst you are jailed!");
			}
	    }
	    else
	    {
            SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot use this command whilst you have a wanted level!");
        }
	}
	return 1;
}

COMMAND:newclass(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
	    if (playerData[playerid][playerWantedLevel] == 0)
	    {
		    if(playerData[playerid][playerJailTime] <= 0)
			{
				if(!playerData[playerid][playerIsTied])
				{
					ForceClassSelection(playerid);
					SetPlayerHealth(playerid, 0.0);
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot use this command whilst you are tied!");
				}
			}
			else
			{
			    SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot use this command whilst you are jailed!");
			}
	    }
	    else
	    {
            SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot use this command whilst you have a wanted level!");
        }
	}
	return 1;
}

COMMAND:robstore(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		beginRobbery(playerid);
	}
	return 1;
}

COMMAND:cancelrob(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerStoreID] > 0)
		{
			cancelRobbery(playerid);
		}
	}
	return 1;
}

COMMAND:cancel(playerid, params[])
{
	return cmd_cancelrob(playerid, params);
}


COMMAND:arenas(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 2)
		{
            ShowPlayerDialog(playerid, DIALOG_ARENAS, DIALOG_STYLE_LIST, "Arenas", "Dirt Track \n8 Track Arena \nKickstart \nBloodbowl \nVice Stadium \nWarehouse \nDerby arena", "Go", "Cancel");
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You do not have the correct permissions to use this command.");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
	}

	return 1;
}

COMMAND:inventory(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		new inventory[500];

		format(inventory, sizeof(inventory), "%s\n{58D3F7}%i {FFFFFF}Weed", inventory, playerData[playerid][playerWeed]);
		format(inventory, sizeof(inventory), "%s\n{58D3F7}%i {FFFFFF}Ropes", inventory, playerData[playerid][playerRope]);
		format(inventory, sizeof(inventory), "%s\n{58D3F7}%i {FFFFFF}Scissors", inventory, playerData[playerid][playerScissors]);
		format(inventory, sizeof(inventory), "%s\n{58D3F7}%i {FFFFFF}Bobby Pins", inventory, playerData[playerid][playerBobbyPins]);
		format(inventory, sizeof(inventory), "%s\n{58D3F7}%i {FFFFFF}Explosives", inventory, playerData[playerid][playerExplosives]);
		format(inventory, sizeof(inventory), "%s\n{58D3F7}%i {FFFFFF}Bigger Pockets", inventory, playerData[playerid][playerBiggerPockets]);
		format(inventory, sizeof(inventory), "%s\n{58D3F7}%i {FFFFFF}Secure Wallet", inventory, playerData[playerid][playerSecureWallet]);
		format(inventory, sizeof(inventory), "%s\n{58D3F7}%i {FFFFFF}Mask", inventory, playerData[playerid][mask]);
		format(inventory, sizeof(inventory), "%s\n{58D3F7}%i {FFFFFF}Bomb Defusal Kit", inventory, playerData[playerid][playerDefuseKit]);

		ShowPlayerDialog(playerid, DIALOG_ACHIEVEMENTS, DIALOG_STYLE_LIST, "Inventory", inventory, "OK", "Close");
	}

	return 1;
}

COMMAND:allstats(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
        ShowPlayerDialog(playerid, DIALOG_STATS, DIALOG_STYLE_LIST, "Game Statistics", "Player Statistics \nPolice Statistics \nCrime Statistics \nMission Statistics \nMy Inventory", "View", "Cancel");

	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
	}

	return 1;
}

COMMAND:jailtime(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		new timeMessage[150];
		format(timeMessage, sizeof(timeMessage), "Time Remaining: %i seconds", playerData[playerid][playerJailTime]);
		SendClientMessage(playerid, COLOR_ORANGE, timeMessage);
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
	}

	return 1;
}

COMMAND:savestats(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (playerData[playerid][playerCanSaveStats])
		{
			savePlayerStats(playerid);

			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Your stats have been saved.");

			playerData[playerid][playerCanSaveStats] = false;
			playerData[playerid][saveStatsTimer] = SetTimerEx("canSaveStats", 120000, false, "i", playerid);
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}Please wait before attempting to save your stats again.");
		}
    }
    else
    {
       SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
    }

    return 1;
}


COMMAND:sendmoney(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		new otherID, amount, message[128], message2[128], loggingString[256];

		if(sscanf(params, "ui", otherID, amount))
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"sendmoney <otherID> <amount>\"");
		}
		else
		{
			if(IsPlayerConnected(otherID))
			{
				if(playerData[otherID][playerLoggedIn])
				{
					if (otherID != playerid)
					{
						if (playerData[playerid][playerMoney] >= amount && amount > 0)
						{
							playerGiveMoney(otherID, amount);
							playerTakeMoney(playerid, amount);
							format(message, sizeof(message), "{B7B7B7}[CASH] {FFFFFF}You have given {FFDC2E}$%s {FFFFFF}to %s(%i)", FormatNumber(amount), playerData[otherID][playerNamee], otherID);
							SendClientMessage(playerid, COLOR_WHITE, message);

							format(message2, sizeof(message2), "{B7B7B7}[CASH] {FFFFFF}You have received {FFDC2E}$%s {FFFFFF}from %s(%i)", FormatNumber(amount), playerData[playerid][playerNamee], playerid);
							SendClientMessage(otherID, COLOR_WHITE, message2);
							PlayerPlaySound(otherID, 1149, 0.0, 0.0, 10.0);

							format(loggingString, sizeof(loggingString), "%s sent %s $%s.", playerData[playerid][playerNamee], playerData[otherID][playerNamee], FormatNumber(amount));
							writeInLog("moneyTransactions.html", loggingString);
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You don't have enough money to complete this transaction.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot send money to yourself.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}That player is not logged in!");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}That player is not online!");
			}
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
	}

	return 1;
}

COMMAND:countdown(playerid, params[])
{
	if(!playerData[playerid][playerLoggedIn])
	{
		return 0;
	}
	new msg[256];
	if(playerData[playerid][playerVIPLevel] >= 1)
	{
		if(serverInfo[VIPcount] == 0)
		{
		    KillTimer(serverInfo[countTimer]);
			format(msg, sizeof(msg), "{58D3F7}[VIP] %s{FFFFFF} started countdown!", playerData[playerid][playerNamee]);
			SendClientMessageToAll(0xFFFFFF, msg);
			serverInfo[VIPcount] = 5;
			serverInfo[countTimer] = SetTimer("Countdown", 1000, true);			
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}Another countdown on progress.");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}This command only for VIP.");
	}
	return 1;
}

COMMAND:sm(playerid, params[])
{
	return cmd_sendmoney(playerid, params);
}


COMMAND:rob(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(!playerData[playerid][isInEvent])
		{
			if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
			{
				if(playerData[playerid][playerCanRob])
				{
					new otherPlayer = GetClosestPlayerToPlayer(playerid);

					new message[128];
					if(IsPlayerConnected(otherPlayer))
					{
						if(playerData[otherPlayer][playerLoggedIn])
						{
							new Float:lX, Float:lY, Float:lZ;
							GetPlayerPos(otherPlayer, lX, lY, lZ);
							if(IsPlayerInRangeOfPoint(playerid, 4.0, lX, lY, lZ))
							{
								if(playerData[playerid][playerJailTime] <= 0)
								{
									if(playerData[otherPlayer][playerJailTime] <= 0)
									{
										if(!IsPlayerInAnyVehicle(otherPlayer))
										{
											if(!IsPlayerInAnyVehicle(playerid))
											{
												if(!playerData[otherPlayer][playerAdminDuty])
												{
													if(!playerData[playerid][playerIsCuffed])
													{
														if(!playerData[playerid][playerIsTazed])
														{
															if(!playerData[playerid][playerIsTied])
															{
																if(playerData[otherPlayer][playerMoney] >= 5000)
																{
																	if(playerData[otherPlayer][playerSecureWallet] == 0)
																	{
																		new determinator = random(4);
																		switch(determinator)
																		{
																			case 0, 1, 2:
																			{
																				new robberyAmount = randomEx(250, 3000);
																				playerGiveMoney(playerid, robberyAmount);
																				playerGiveMoney(otherPlayer, -robberyAmount);

																				format(message, sizeof(message), "{E6BD1A}[CRIME] {FFFFFF}You successfully robbed %s(%i) and received {FFDC2E}$%s ", playerData[otherPlayer][playerNamee], otherPlayer, FormatNumber(robberyAmount));
																				SendClientMessage(playerid, COLOR_WHITE, message);

																				format(message, sizeof(message), "{E6BD1A}[CRIME] {FFFFFF}You were robbed by %s(%i) they stole {FFDC2E}$%s ", playerData[playerid][playerNamee], playerid, FormatNumber(robberyAmount));
																				SendClientMessage(otherPlayer, COLOR_WHITE, message);

																				playerGiveXP(playerid, 10);
																				playerData[playerid][playerScore] = playerData[playerid][playerScore] + 1;
																				SetPlayerScore(playerid, playerData[playerid][playerScore]);

																				playerData[playerid][streetRobberies] = playerData[playerid][streetRobberies] + 1;

																				if (playerData[playerid][streetRobberies] == 1)
																				{
																					disableAchieve(playerid);
																					PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
																					PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
																					PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
																					PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

																					PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "Pocket Chaser");
																					PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "You robbed a player for the first time!");
																					PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);

																					playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 6000, false, "i", playerid);

																					playerGiveXP(playerid, 25);
																					playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
																					SetPlayerScore(playerid, playerData[playerid][playerScore]);
																				}

																				if (playerData[playerid][streetRobberies] == 10)
																				{
																					disableAchieve(playerid);
																					PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
																					PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
																					PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
																					PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

																					PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "Oliver Twist");
																					PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "You stole from 10 players!");
																					PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);

																					playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 6000, false, "i", playerid);

																					playerGiveXP(playerid, 25);
																					playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
																					SetPlayerScore(playerid, playerData[playerid][playerScore]);
																				}

																				if (playerData[playerid][streetRobberies] == 50)
																				{
																					disableAchieve(playerid);
																					PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
																					PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
																					PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
																					PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

																					PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "Invisible");
																					PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "You stole from 50 players, nice!");
																					PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);

																					playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 6000, false, "i", playerid);

																					playerGiveXP(playerid, 25);
																					playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
																					SetPlayerScore(playerid, playerData[playerid][playerScore]);
																				}
																			}
																			case 3:
																			{
																				format(message, sizeof(message), "{E6BD1A}[CRIME] {FFFFFF}You attempted to rob %s(%i) and failed!", playerData[otherPlayer][playerNamee], otherPlayer);
																				SendClientMessage(playerid, COLOR_WHITE, message);
																				format(message, sizeof(message), "{B7B7B7}[SERVER] {FFFFFF}%s(%i) tried to rob you but failed!", playerData[playerid][playerNamee], playerid);
																				SendClientMessage(otherPlayer, COLOR_WHITE, message);
																			}
																		}
																	}
																	else
																	{
																		format(message, sizeof(message), "{E6BD1A}[CRIME] {FFFFFF}You attempted to rob %s(%i) and failed!", playerData[otherPlayer][playerNamee], otherPlayer);
																		SendClientMessage(playerid, COLOR_WHITE, message);
																		format(message, sizeof(message), "{B7B7B7}[SERVER] {FFFFFF}%s(%i) tried to rob you but failed due to your secure wallet!", playerData[playerid][playerNamee], playerid);
																		SendClientMessage(otherPlayer, COLOR_WHITE, message);
																	}

																	playerData[playerid][playerCanRob] = false;
																	playerData[playerid][reactivateRobStatus] = SetTimerEx("reactivateRob", 120000, false, "i", playerid);
																	givePlayerWanted(playerid, 6);
																	sendWantedMessage(playerid, 6);

																}
																else
																{
																	SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}This player cannot afford to be robbed.");
																}
															}
															else
															{
																SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot do this whilst tied.");
															}
														}
														else
														{
															SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot do this whilst tazed.");
														}
													}
													else
													{
														SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot do this whilst cuffed.");
													}
												}
												else
												{
													SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot rob administrators who are on duty.");
												}
											}
											else
											{
												SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot rob people while you are in a vehicle.");
											}
										}
										else
										{
											SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}The player you're trying to rob is in a vehicle.");
										}
									}
									else
									{
										SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot rob players who are in jail.");
									}
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot rob players while you are in jail.");
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You are not close enough to that player.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}The player your trying to rob is not logged in.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}The player your trying to rob isn't connected.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You need to wait before robbing another player.");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}This command can only be used by civilians.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot rob players whilst in an event.");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
	}

	return 1;
}

COMMAND:rape(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(!playerData[playerid][isInEvent])
		{
			if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
			{
				if(playerData[playerid][playerCanRape])
				{
					if(!playerData[playerid][playerIsCuffed])
					{
						if(!playerData[playerid][playerIsTazed])
						{
							if(!playerData[playerid][playerIsTied])
							{
								new otherPlayer = GetClosestPlayerToPlayer(playerid);

								new message[128];
								if(IsPlayerConnected(otherPlayer))
								{
									if(playerData[otherPlayer][playerLoggedIn])
									{
										new Float:lX, Float:lY, Float:lZ;
										GetPlayerPos(otherPlayer, lX, lY, lZ);
										if(IsPlayerInRangeOfPoint(playerid, 4.0, lX, lY, lZ))
										{
											if(playerData[playerid][playerJailTime] <= 0)
											{
												if(playerData[otherPlayer][playerJailTime] <= 0)
												{
													if(!IsPlayerInAnyVehicle(otherPlayer))
													{
														if(!IsPlayerInAnyVehicle(playerid))
														{
															if(!playerData[otherPlayer][playerAdminDuty])
															{
																if(playerData[otherPlayer][playerButtPlug] == 0)
																{
																	new determinator = random(4);
																	switch(determinator)
																	{
																		case 0, 1, 2:
																		{
																			new Float:oldHealth;
																			format(message, sizeof(message), "{E6BD1A}[CRIME] {FFFFFF}You successfully raped %s(%i)!", playerData[otherPlayer][playerNamee], otherPlayer);
																			SendClientMessage(playerid, COLOR_WHITE, message);
																			format(message, sizeof(message), "{E6BD1A}[CRIME] {FFFFFF}You were raped by %s(%i)!", playerData[playerid][playerNamee], playerid);
																			SendClientMessage(otherPlayer, COLOR_WHITE, message);
																			GetPlayerHealth(otherPlayer, oldHealth);
																			SetPlayerHealth(otherPlayer, (oldHealth - 25.0));
																			playerGiveXP(playerid, 10);
																			playerData[playerid][playerScore] = playerData[playerid][playerScore] + 1;
																			SetPlayerScore(playerid, playerData[playerid][playerScore]);

																			if(playerData[playerid][playerJob] == JOB_RAPIST)
																			{
																				new rapeChance = random(4);

																				switch (rapeChance)
																				{
																					case 0, 1:
																					{
																						// Infect the player with an STD
																						playerData[otherPlayer][rapedTimer] = SetTimerEx("raped", 3000, true, "i", otherPlayer);
																						SendClientMessage(otherPlayer, COLOR_WHITE, "{F78181}[STD] {FFFFFF}You have contracted an STD.");
																						playerData[otherPlayer][hasSTD] = true;
																					}
																				}
																			}

																			playerData[playerid][streetRapes] = playerData[playerid][streetRapes] + 1;

																			if (playerData[playerid][streetRapes] == 1)
																			{
																				disableAchieve(playerid);
																				PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
																				PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
																				PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
																				PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

																				PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "Devilishly Horny");
																				PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "You raped a poor, innocent player.");
																				PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);

																				playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 6000, false, "i", playerid);

																				playerGiveXP(playerid, 25);
																				playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
																				SetPlayerScore(playerid, playerData[playerid][playerScore]);
																			}

																			if (playerData[playerid][streetRapes] == 10)
																			{
																				disableAchieve(playerid);
																				PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
																				PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
																				PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
																				PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

																				PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "Dildo Fanatic");
																				PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "You raped 10 players.");
																				PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);

																				playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 6000, false, "i", playerid);

																				playerGiveXP(playerid, 25);
																				playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
																				SetPlayerScore(playerid, playerData[playerid][playerScore]);
																			}

																			if (playerData[playerid][streetRobberies] == 50)
																			{
																				disableAchieve(playerid);
																				PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
																				PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
																				PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
																				PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

																				PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "Dick Slap");
																				PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "You raped 50 players.");
																				PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);

																				playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 6000, false, "i", playerid);

																				playerGiveXP(playerid, 25);
																				playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
																				SetPlayerScore(playerid, playerData[playerid][playerScore]);
																			}
																		}
																		case 3:
																		{
																			format(message, sizeof(message), "{E6BD1A}[CRIME] {FFFFFF}You attempted to rape %s(%i) and failed!", playerData[otherPlayer][playerNamee], otherPlayer);
																			SendClientMessage(playerid, COLOR_WHITE, message);
																			format(message, sizeof(message), "{B7B7B7}[SERVER] {FFFFFF}%s(%i) tried to rape you but failed!", playerData[playerid][playerNamee], playerid);
																			SendClientMessage(otherPlayer, COLOR_WHITE, message);
																		}
																	}
																}
																else
																{
																	format(message, sizeof(message), "{E6BD1A}[CRIME] {FFFFFF}You attempted to rape %s(%i) and failed!", playerData[otherPlayer][playerNamee], otherPlayer);
																	SendClientMessage(playerid, COLOR_WHITE, message);
																	format(message, sizeof(message), "{B7B7B7}[SERVER] {FFFFFF}%s(%i) tried to rape you but failed due to your buttplug!", playerData[playerid][playerNamee], playerid);
																	SendClientMessage(otherPlayer, COLOR_WHITE, message);
																}

																playerData[playerid][playerCanRape] = false;

																if(playerData[playerid][playerJob] == JOB_RAPIST)
																{
																	playerData[playerid][reactivateRapeStatus] = SetTimerEx("reactivateRape", 30000, false, "i", playerid);
																}
																else
																{
																	playerData[playerid][reactivateRapeStatus] = SetTimerEx("reactivateRape", 120000, false, "i", playerid);
																}

																givePlayerWanted(playerid, 6);
																sendWantedMessage(playerid, 6);

															}
															else
															{
																SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot rape administrators who are on duty.");
															}
														}
														else
														{
															SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot rape people while you are in a vehicle.");
														}
													}
													else
													{
														SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}The player you're trying to rape is in a vehicle.");
													}
												}
												else
												{
													SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot rape players who are in jail.");
												}
											}
											else
											{
												SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot rape players while you are in jail.");
											}
										}
										else
										{
											SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You are not close to any players.");
										}
									}
									else
									{
										SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}The player your trying to rape is not logged in.");
									}
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}The player your trying to rape isn't connected.");
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot do this whilst tied.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot do this whilst tazed.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot do this whilst cuffed.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You need to wait before raping another player.");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}This command can only be used by civilians.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot rape players whilst in an event.");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
	}

	return 1;
}

// COMMANDS FOR PLAYER JOBS


CMD:blowjob(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn]) // logged in
	{
		if(!playerData[playerid][isInEvent])
		{
			if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
			{
				if(playerData[playerid][playerJob] == JOB_PROSTITUTE)
				{
					new otherPlayer;
					if(sscanf(params, "u", otherPlayer))
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"blowjob <playerid>\"");
					}
					else
					{
						if(otherPlayer != playerid)
						{
							if(IsPlayerConnected(otherPlayer)) // logged in
							{
								if(isPlayerInRangeOfPlayer(playerid, otherPlayer, 4.0))
								{
									// Invite the other user to buy a weapon
									playerData[otherPlayer][playerBJOffer] = playerData[playerid][playerNamee];

									// Send the invite
									new offer[200];
									format(offer, sizeof(offer), "{FE9A2E}[BLOWJOB OFFER] {FFFFFF}%s(%i) wishes to give you a blowjob for $800, nice - /acceptblowjob", playerData[playerid][playerNamee], playerid);
									SendClientMessage(otherPlayer, 0xFF0000FF, offer);

									new to[200];
									format(to, sizeof(to), "{FE9A2E}[OFFER SENT] {FFFFFF}You offered to give %s(%i) a blowjob!", playerData[otherPlayer][playerNamee], otherPlayer);
									SendClientMessage(playerid, 0xFF0000FF, to);
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You're not close enough to that player.");
								}
							}
							else
							{
								// Offline
								SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}That player is not online.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot give a blowjob to yourself.");
						}
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}Only prostitutes can this command.");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be a civilian to use this command.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot do this whilst in an event.");
		}
	}
	return 1;
}

COMMAND:acceptblowjob(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(!playerData[playerid][isInEvent])
		{
			if (playerData[playerid][playerBJOffer] == -1)
			{
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}There are no blowjob offers.");
			}
			else
			{
				new status = checkNameStatus(playerData[playerid][playerBJOffer]);
				if(status == -1)
				{
					// Prostitute offline
					SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}The prostitute is no longer available.");
				}
				else
				{
					// Check radius (a little larger this time)
					if(isPlayerInRangeOfPlayer(playerid, status, 2.0))
					{
						// Tell the prostitute the player accepted
						new accept[200];
						format(accept, sizeof(accept), "{FE9A2E}[OFFER ACCEPTED] {FFFFFF}%s(%i) has accepted your offer.", playerData[playerid][playerNamee], playerid);
						SendClientMessage(status, 0xFF0000FF, accept);

						SetPlayerHealth(playerid, 100);

						// Take player money
						playerTakeMoney(playerid, 800);
						playerGiveMoney(status, 800);

						// Give XP bonus
						playerGiveXP(status, 5);

						// Give Score
						playerData[status][playerScore] = playerData[status][playerScore] + 1;
						SetPlayerScore(status, playerData[status][playerScore]);

						// Blowjob animation
						ApplyAnimation(status, "BLOWJOBZ", "BJ_STAND_LOOP_W", 4.0, 1, 1, 1, 1, 0);
						playerData[status][playerUsingAnim] = true;
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}The prostitute is no longer available.");
					}
				}
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot do this whilst in an event.");
		}
	}
	return 1;
}

CMD:sellgun(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn]) // logged in
	{
		if(!playerData[playerid][isInEvent])
		{
			if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
			{
				if(playerData[playerid][playerJob] == JOB_WEAPONDEALER)
				{
					new otherPlayer;
					if(sscanf(params, "u", otherPlayer))
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"sellgun <playerid>\"");
					}
					else
					{
						if(otherPlayer != playerid)
						{
							if(IsPlayerConnected(otherPlayer)) // logged in
							{
								if(isPlayerInRangeOfPlayer(playerid, otherPlayer, 4.0))
								{
									if(playerData[otherPlayer][playerJailTime] < 1)
									{
										// Invite the other user to buy a weapon
										playerData[otherPlayer][playerGunOffer] = playerid;

										// Send the invite
										new offer[200];
										format(offer, sizeof(offer), "{FE9A2E}[WEAPON OFFER] {FFFFFF}%s(%i) wishes to sell you some weapons - /buygun", playerData[playerid][playerNamee], playerid);
										SendClientMessage(otherPlayer, 0xFF0000FF, offer);

										new to[200];
										format(to, sizeof(to), "{FE9A2E}[OFFER SENT] {FFFFFF}You offered to sell weapons to %s(%i)", playerData[otherPlayer][playerNamee], otherPlayer);
										SendClientMessage(playerid, 0xFF0000FF, to);
									}
									else
									{
										SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[WEAPON DEALER] {FFFFFF}That player is in jail and cannot buy weapons.");
									}
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[WEAPON DEALER] {FFFFFF}You're not close enough to that player.");
								}
							}
							else
							{
								// Offline
								SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}That player is not online.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot sell weapons to yourself.");
						}
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}Only weapon dealers can this command.");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be a civilian to use this command.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot do this whilst in an event.");
		}
	}
	return 1;
}

COMMAND:buygun(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(!playerData[playerid][isInEvent])
		{
			if (playerData[playerid][playerJailTime] < 1)
			{
				if (playerData[playerid][playerGunOffer] == -1)
				{
					SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}There are no weapon offers.");
				}
				else
				{
					new dealerID = playerData[playerid][playerGunOffer];
					if (playerid != dealerID)
					{
						if(!IsPlayerConnected(dealerID)) // logged in
						{
							// Dealer offline
							SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}The weapon dealer is no longer available.");
						}
						else
						{
							// Check radius (a little larger this time)
							if(isPlayerInRangeOfPlayer(playerid, dealerID, 20.0))
							{
								// Tell the dealer the player accepted
								new accept[200];
								format(accept, sizeof(accept), "{FE9A2E}[OFFER ACCEPTED] {FFFFFF}%s(%i) has accepted your request and is browsing your items.", playerData[playerid][playerNamee], playerid);
								SendClientMessage(dealerID, 0xFF0000FF, accept);

								// Show dialog to the player
								playerData[playerid][playerGunDealer] = dealerID;
								ShowPlayerDialog(playerid, DIALOG_GUNDEAL, DIALOG_STYLE_LIST, "Weapon Dealer", "MP5 {D87C3E}$1,500{FFFFFF} \nCombat Shotgun {D87C3E}$3,000{FFFFFF} \nSawnoff Shotgun {D87C3E}$5,000{FFFFFF}\nDesert Eagle {D87C3E}$3,500{FFFFFF}", "Go", "Cancel");
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}The weapon dealer is no longer in range.");
							}
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot buy your own weapons.");
					}
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot do this whilst jailed.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot do this whilst in an event.");
		}
	}
	return 1;
}

CMD:track(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn]) // logged in
	{
		if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
		{
			if(playerData[playerid][playerJob] == JOB_HITMAN)
			{
				if(playerData[playerid][playerIsTracking])
				{
					// Disable tracker
					PlayerTextDrawHide(playerid, PlayerText:playerData[playerid][playerTracker]);
					playerData[playerid][playerIsTracking] = false;
					KillTimer(playerData[playerid][playerHitmanTrackerTimer]);
				}
				else
				{
					new otherPlayer;
					if(sscanf(params, "u", otherPlayer))
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"track <playerid>\"");
					}
					else
					{
						if(otherPlayer != playerid)
						{
							if(IsPlayerConnected(otherPlayer)) // logged in
							{
								if(playerData[otherPlayer][playerHitValue] >= 1000)
								{
									playerData[playerid][playerHitmanTrackerTimer] = SetTimerEx("playerHitmanTracker", 1000, true, "ii", playerid, otherPlayer);
									playerData[playerid][playerIsTracking] = true;
									PlayerTextDrawShow(playerid, PlayerText:playerData[playerid][playerTracker]);
									SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[TRACKING] {FFFFFF}Tracker started.");
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[TRACKING] {FFFFFF}That player does not have a high enough hit value.");
								}
							}
							else
							{
								// Offline
								SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}That player is not online.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cant track yourself..");
						}
					}
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}Only hitmen can this command.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be a civilian to use this command.");
		}
	}
	return 1;
}

COMMAND:mech(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(!playerData[playerid][isInEvent])
		{
			if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
			{
				if(playerData[playerid][playerJob] == JOB_MECHANIC)
				{
					if(IsPlayerInAnyVehicle(playerid))
					{
						ShowPlayerDialog(playerid, DIALOG_MECHANIC, DIALOG_STYLE_LIST, "Mechanic", "Repair Vehicle {D87C3E}$300{FFFFFF} \nAdd Nitro {D87C3E}$1,500{FFFFFF} \nRemove EMP {D87C3E}$2,000{FFFFFF} \nFlip Vehicle {D87C3E}$500{FFFFFF}", "Go", "Cancel");
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be in a vehicle to use this command.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You are not a mechanic.");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}Only civilians can use this command.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot do this whilst in an event.");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
	}

	return 1;
}

COMMAND:kidnap(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(!playerData[playerid][isInEvent])
		{
			if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
			{
				if(playerData[playerid][playerJob] == JOB_KIDNAPPER)
				{
					// Kidnap a victim >=)
					new otherPlayer, pKidnapped[250], lKidnapped[250];
					if(sscanf(params, "u", otherPlayer))
					{
						// Invalid command syntax
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"kidnap <playerID>\"");
					}
					else
					{
						if(!playerData[playerid][playerIsTied])
						{
							if(playerid != otherPlayer)
							{
								if(IsPlayerConnected(otherPlayer))
								{
									if(playerData[otherPlayer][playerLoggedIn])
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
														// If PLAYER is NOT in a vehicle
														if(!IsPlayerInAnyVehicle(playerid))
														{
															if(playerData[otherPlayer][playerIsTied])
															{
																if(playerData[playerid][playerCanKidnap])
																{
																	if(IsValidVehicle(playerData[playerid][playerLastVehicleID]))
																	{
																		new FreeSlot = GetEmptySeat(playerData[playerid][playerLastVehicleID]);
																		if (FreeSlot != INVALID_SEAT_ID)
																		{
																			SetPlayerInterior(otherPlayer, 0);
																			SetPlayerVirtualWorld(otherPlayer, 0);

																			// Kidnap player
																			PutPlayerInVehicle(otherPlayer, playerData[playerid][playerLastVehicleID], FreeSlot);

																			format(pKidnapped, sizeof(pKidnapped), "{B7B7B7}[KIDNAP] {FFFFFF}You have been kidnapped by %s(%i)", playerData[playerid][playerNamee], playerid);
																			SendClientMessage(otherPlayer, 0xFF0000FF, pKidnapped);

																			//Delete3DTextLabel(playerData[otherPlayer][kidnappedLabel]);
																			playerData[otherPlayer][kidnappedLabel] = Create3DTextLabel("", 0xFFDC2EFF, 30.0, 40.0, 50.0, 60.0, -1, 1);
																			Attach3DTextLabelToPlayer(playerData[otherPlayer][kidnappedLabel], otherPlayer, 0.0, 0.0, 0.4);

																			format(lKidnapped, sizeof(lKidnapped), "{B7B7B7}[KIDNAP] {FFFFFF}You have kidnapped %s(%i)", playerData[otherPlayer][playerNamee], otherPlayer);
																			SendClientMessage(playerid, COLOR_WHITE, lKidnapped);

																			playerData[playerid][kidnapTimer] = SetTimerEx("reKidnap", 60000, false, "i", playerid);
																			playerData[playerid][playerCanKidnap] = false;

																			givePlayerWanted(playerid, 6);
																			sendWantedMessage(playerid, 6);
																			playerGiveXP(playerid, 10);

																			TogglePlayerControllable(otherPlayer, false);

																			playerData[playerid][playersKidnapped] = playerData[playerid][playersKidnapped] + 1;

																			if (playerData[playerid][playersKidnapped] == 1)
																			{
																				disableAchieve(playerid);
																				PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
																				PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
																				PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
																				PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

																				PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "Get In My Van");
																				PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "You kidnapped a player. Have fun!");
																				PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);

																				playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 6000, false, "i", playerid);

																				playerGiveXP(playerid, 25);
																				playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
																				SetPlayerScore(playerid, playerData[playerid][playerScore]);
																			}

																			if (playerData[playerid][playersKidnapped] == 10)
																			{
																				disableAchieve(playerid);
																				PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
																				PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
																				PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
																				PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

																				PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "I Need A Bigger Basement");
																				PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "You kidnapped 10 players!");
																				PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);

																				playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 6000, false, "i", playerid);

																				playerGiveXP(playerid, 25);
																				playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
																				SetPlayerScore(playerid, playerData[playerid][playerScore]);
																			}

																			if (playerData[playerid][playersKidnapped] == 50)
																			{
																				disableAchieve(playerid);
																				PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
																				PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
																				PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
																				PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

																				PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "Want Some Candy?");
																				PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "You kidnapped 50 players.");
																				PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);

																				playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 6000, false, "i", playerid);

																				playerGiveXP(playerid, 25);
																				playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
																				SetPlayerScore(playerid, playerData[playerid][playerScore]);
																			}
																		}
																		else
																		{
																			// No car seats available
																			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}There is no room in your vehicle to kidnap this player.");
																		}
																	}
																	else
																	{
																		SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You don't have a vehicle to put this player in.");
																	}
																}
																else
																{
																	// Player cannot kidnap
																	SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must wait before kidnapping another victim..");
																}
															}
															else
															{
																// Player isn't tied
																SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must tie your victim before you can kidnap them.");
															}
														}
														else
														{
															// Player is in vehicle
															SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot kidnap people while you are in a vehicle.");
														}
													}
													else
													{
														// Other player is in a vehicle
														SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}The player you're trying to kidnap is in a vehicle.");
													}
												}
												else
												{
													// Cannot kidnap an admin on duty
													SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}That player is currently performing admin duties and cannot be kidnapped!");
												}
											}
											else
											{
												// Not in range of player
												SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You are not close enough to that player.");
											}
										}
										else
										{
											// Player is in jail
											SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot kidnap people when they are jailed or when you are jailed.");
										}
									}
									else
									{
										// Cannot kidnap players who are not logged in.
										SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot kidnap players who are not logged in.");
									}
								}
								else
								{
									// Cannot kidnap players who are not connected.
									SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}That player is not connected.");
								}
							}
							else
							{
								// Cannot tie yourself
								SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot kidnap yourself.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot do this whilst tied.");
						}
					}
				}
				else
				{
					// Player is not a kidnapper
					SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}Only kidnappers can use this command.");
				}
			}
			else
			{
				// Player is not civilian
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}Only civilians can use this command.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot do this whilst in an event.");
		}
    }
    else
    {
        SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
    }
    return 1;
}

COMMAND:payransom(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (playerData[playerid][playerIsTied])
		{
			if (playerData[playerid][playerRansomTo] == -1)
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}There are no ransom offers.");
			}
			else
			{
				if (playerData[playerid][playerMoney] >= playerData[playerid][playerRansomPrice])
				{
					new message[250];
					new ransomID = playerData[playerid][playerRansomTo];
					if (playerid != ransomID)
					{
						if(IsPlayerConnected(ransomID))
						{
							if(playerData[ransomID][playerJob] == JOB_KIDNAPPER) // offer gone
							{
								// Pay cash to ID
								playerGiveMoney(ransomID, playerData[playerid][playerRansomPrice]);
								playerTakeMoney(playerid, playerData[playerid][playerRansomPrice]);

								// Send message to cop
								format(message, sizeof(message), "{58D3F7}[RANSOM PAID] {FFFFFF}You received {FFDC2E}$%s {FFFFFF}from %s(%i)", FormatNumber(playerData[playerid][playerRansomPrice]), playerData[playerid][playerNamee], playerid);
								SendClientMessage(ransomID, COLOR_WHITE, message);
								playerGiveXP(ransomID, 5);

								playerData[playerid][playerRansomTo] = 0;
								playerData[playerid][playerRansomPrice] = 0;

								ClearAnimations(playerid);
								playerData[playerid][playerIsTied] = false;

								SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
								KillTimer(playerData[playerid][untieTimer]);
								TogglePlayerControllable(playerid, true);

								Delete3DTextLabel(playerData[playerid][kidnappedLabel]);

								SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[RANSOM PAID] {FFFFFF}You have been released, run piggy!");
							}
							else
							{
								// Cop offline
								SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}The ransom offer is no longer available.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}The ransom offer is no longer available. (2)");
						}
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cant afford this offer.");
				}
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You aren't kidnapped.");
		}
	}

	return 1;
}

COMMAND:ransom(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
  	    if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
  	    {
            // Command for ransom
            new otherPlayer, price, message[200];
            if(sscanf(params, "ui", otherPlayer, price))
            {
                // Invalid command syntax
                SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"ransom <playerID> <price>\"");
            }
            else
            {
				if(IsPlayerConnected(otherPlayer))
				{
					if(playerData[otherPlayer][playerLoggedIn])
					{
						if(otherPlayer != playerid)
						{
							if (price > 1000 && price < 50000)
							{
								new kidnapperVID, kidnappedVID;

								kidnapperVID = GetPlayerVehicleID(playerid);
								kidnappedVID = GetPlayerVehicleID(otherPlayer);

								if (kidnapperVID == kidnappedVID)
								{
									if (playerData[otherPlayer][playerIsTied])
									{
										// Set-up some variables (reset on spawn)
										playerData[otherPlayer][playerRansomTo] = playerid;
										playerData[otherPlayer][playerRansomPrice] = price;

										format(message, sizeof(message), "{58D3F7}[RANSOM] {FFFFFF}%s(%i) requests you pay {FFDC2E}$%s {FFFFFF}for your safe release (/payransom)", playerData[playerid][playerNamee], playerid, FormatNumber(price));
										SendClientMessage(otherPlayer, COLOR_WHITE, message);

										SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[RANSOM] {FFFFFF}Your ransom offer has been sent.");
									}
									else
									{
										SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}That player is not tied.");
									}
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}That player is not in your vehicle.");
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}Ransom price must be between $1,000 and $50,000");
							}
						}
					}
					else
					{
						// Player is not logged in
						SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}This player is not logged in.");
					}
				}
				else
				{
					// Player is not online
					SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}This player is not online.");
				}
			}
        }
        else
        {
            // Player is not police
            SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}This command can only be used by civilians.");
        }
    }
    else
    {
        SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
    }

	return 1;
}

COMMAND:tie(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(!playerData[playerid][isInEvent])
		{
			if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
			{
				// Tie a victim >=)
				new otherPlayer, tiedBy[24], Name[24], pTied[250], lTied[250];
				if(sscanf(params, "u", otherPlayer))
				{
					// Invalid command syntax
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"tie <playerID>\"");
				}
				else
				{
					if(!playerData[playerid][playerIsCuffed])
					{
						if(!playerData[playerid][playerIsTazed])
						{
							if(!playerData[playerid][playerIsTied])
							{
								if(playerid != otherPlayer)
								{
									if(IsPlayerConnected(otherPlayer))
									{
										if(playerData[otherPlayer][playerLoggedIn])
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
															// If PLAYER is in a vehicle
															if(!IsPlayerInAnyVehicle(playerid))
															{
																// Check if the player is already tazed
																if(!playerData[otherPlayer][playerIsTied])
																{
																	if (!playerData[otherPlayer][playerIsCuffed])
																	{
																		// Check if player has enough rope
																		if (playerData[playerid][playerRope] >= 1)
																		{
																			// Freeze the other player
																			SetPlayerSpecialAction(otherPlayer, SPECIAL_ACTION_CUFFED);

																			ClearAnimations(otherPlayer);

																			GetPlayerName(playerid, tiedBy, sizeof(Name));
																			GetPlayerName(otherPlayer, Name, sizeof(Name));

																			// Tie player
																			format(pTied, sizeof(pTied), "{B7B7B7}[TIED] {FFFFFF}You have been tied by %s(%i)", tiedBy, playerid);
																			SendClientMessage(otherPlayer, 0xFF0000FF, pTied);

																			format(lTied, sizeof(lTied), "{B7B7B7}[TIED] {FFFFFF}You have tied %s(%i)", Name, otherPlayer);
																			SendClientMessage(playerid, COLOR_WHITE, lTied);

																			// Set timer to expire and unfreeze player (60 seconds)
																			playerData[otherPlayer][untieTimer] = SetTimerEx("untie", 120000, false, "i", otherPlayer);

																			// Set the otherPlayer's isTied to 1
																			playerData[otherPlayer][playerIsTied] = true;

																			givePlayerWanted(playerid, 6);
																			sendWantedMessage(playerid, 6);
																			playerGiveXP(playerid, 5);

																			playerData[playerid][playerRope] = playerData[playerid][playerRope] - 1;
																		}
																		else
																		{
																			// Not enough rope
																			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You don't have any rope.");
																		}
																	}
																	else
																	{
																		SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot tie this player.");
																	}
																}
																else
																{
																	// The player is already tied
																	SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}That player is already tied.");
																}
															}
															else
															{
																// Player is in vehicle
																SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot tie people while you are in a vehicle.");
															}
														}
														else
														{
															// Other player is in a vehicle
															SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}The player you're trying to tie is in a vehicle.");
														}
													}
													else
													{
														// Cannot tie an admin on duty
														SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}That player is currently performing admin duties and cannot be tied!");
													}
												}
												else
												{
													// Not in range of player
													SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You are not close enough to that player.");
												}
											}
											else
											{
												// Player is in jail
												SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot tie people when they are jailed or when you are jailed.");
											}
										}
										else
										{
											// Cannot tie players who are not logged in.
											SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot tie players who are not logged in.");
										}
									}
									else
									{
										// Cannot tie players who are not connected.
										SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}That player is not connected.");
									}
								}
								else
								{
									// Cannot tie yourself
									SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot tie yourself.");
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot do this whilst tied.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot do this whilst tazed.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot do this whilst cuffed.");
					}
				}
			}
			else
			{
				// Player is not civilian
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}Only civilians can use this command.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot do this whilst in an event.");
		}
    }
    else
    {
        SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
    }
    return 1;
}

COMMAND:untie(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(!playerData[playerid][isInEvent])
		{
			new otherID, otherName[24];

			if(sscanf(params, "u", otherID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"untie <playername/id>\"");
			}
			else
			{
				if(playerid != otherID)
				{
					if(IsPlayerConnected(otherID))
					{
						if(playerData[otherID][playerLoggedIn])
						{
							if(!IsPlayerInAnyVehicle(otherID))
							{
								if(playerData[otherID][playerIsTied])
								{
									if(isPlayerInRangeOfPlayer(playerid, otherID, 4.0))
									{
										if (!playerData[playerid][playerIsTied])
										{
											GetPlayerName(otherID, otherName, sizeof(otherName));
											new message[128], message2[128];
											format(message, sizeof(message), "{B7B7B7}[UN-TIED] {FFFFFF}You have untied %s(%i)!", otherName, otherID);
											SendClientMessage(playerid, COLOR_WHITE, message);

											format(message2, sizeof(message2), "{B7B7B7}[UN-TIED] {FFFFFF}You have been untied by %s(%i)!", playerData[playerid][playerNamee], playerid);
											SendClientMessage(otherID, COLOR_WHITE, message2);

											playerData[otherID][playerIsTied] = false;

											SetPlayerSpecialAction(otherID, SPECIAL_ACTION_NONE);
											KillTimer(playerData[otherID][untieTimer]);

											TogglePlayerControllable(otherID, 1);
										}
										else
										{
											SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot do this whilst tied.");
										}
									}
									else
									{
										SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You are not close enough to that player.");
									}
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}That player is not tied.");
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}That player is not logged in!");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You are not close enough to that player.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}That player is not online!");
					}
				}
				else
				{
					// Cannot un-tie yourself
					SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot un-tie yourself.");
				}
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot do this whilst in an event.");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
	}

	return 1;
}

// Courier job begin
COMMAND:courier(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
		{
			if(playerData[playerid][iscourier])
			{
				SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}You're already on a mission. Type /cancelcourier to end the mission!");
			}
			else
			{
				new vehicleid;
				vehicleid = GetPlayerVehicleID(playerid);
				if(GetVehicleModel(vehicleid) == 593)
				{
					// Plane Courier
					ShowPlayerDialog(playerid, DIALOG_COURIER_START, DIALOG_STYLE_LIST, "Courier Mission", "Los Santos \nSan Fierro \nLas Venturas", "Go", "Cancel");
				}
				else if(GetVehicleModel(vehicleid) == 482)
				{
					// Van Courier
					//SetPlayerCheckpoint(playerid, -2521.4011, -618.5956, 132.5698, 10);
					playerData[playerid][playerLastCourierCP] = CreateDynamicRaceCP(1, -2521.4011, -618.5956, 132.5698, -2521.4011, -618.5956, 132.5698, 5, -1, -1, playerid, 100.0);
					SetPlayerMapIcon(playerid, MAP_ICON_COURIER_VAN, -2521.4011, -618.5956, 132.5698, 51, -1);
					SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}Pick-up the packages from the delievery HQ.");
					playerData[playerid][iscourier] = true;
					playerData[playerid][playerCourierLevel] = 3;

					//deliveryTD = TextDrawCreate(320.000000, 424.000000, "Pick-up ~g~boxes ~w~from ~y~delivery HQ");
					//TextDrawShowForPlayer(playerid, deliveryTD);
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be inside a courier vehicle to start the courier mission.");
				}
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be a civilian to start courier missions.");
		}
	}
	return 1;
}

COMMAND:cancelcourier(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
		{
			if(playerData[playerid][iscourier])
			{
				// Cancel the job
				SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}You cancelled the courier mission.");
				playerData[playerid][iscourier] = false;
				playerData[playerid][playerCourierLevel] = 0;
				RemovePlayerMapIcon(playerid, MAP_ICON_COURIER_VAN);
				DestroyDynamicRaceCP(playerData[playerid][playerLastCourierCP]);
				TextDrawHideForPlayer(playerid, TDCourier2);
				TextDrawHideForPlayer(playerid, TDCourier);
				KillTimer(playerData[playerid][courierTimer]);
				TogglePlayerControllable(playerid, 1);
				DisablePlayerCheckpoint(playerid);
				KillTimer(playerData[playerid][courierDistance]);
				PlayerTextDrawSetString(playerid, playerData[playerid][playerCourierDistanceTD], " ");
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You're not on a mission.");
			}
		}
	}
	return 1;
}

// Drug Dealer commands
COMMAND:sellweed(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(!playerData[playerid][isInEvent])
		{
			if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
			{
				if(playerData[playerid][playerJob] == JOB_DRUGDEALER)
				{
					new otherID, amount;

					if(sscanf(params, "ud", otherID, amount))
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"sellweed <playername/id> <value>\"");
					}
					else
					{
						if(amount < 1 || amount > 100)
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Please insert 1 - 100.");
						}
						if(playerid != otherID)
						{
							if(IsPlayerConnected(otherID))
							{
								if(playerData[otherID][playerLoggedIn])
								{
									if(isPlayerInRangeOfPlayer(playerid, otherID, 12.0))
									{
										if(IsPlayerInAnyVehicle(playerid))
										{
											new checkCar = GetPlayerVehicleID(playerid);
											if(GetVehicleModel(checkCar) == 423)
											{
												new takes = amount * 500;
												if (playerData[playerid][playerMoney] >= takes)
												{
													// Sell them the weed
													playerData[otherID][playerWeed] = playerData[otherID][playerWeed] + amount;

													// Take player money
													playerTakeMoney(playerid, takes);

													// Give XP bonus
													playerGiveXP(playerid, 5 * amount);

													new accept[200], forplayer[200];
													format(accept, sizeof(accept), "{FE9A2E}[WEED] {FFFFFF}You sold drugs to %s(%i).", playerData[playerid][playerNamee], playerid);
													SendClientMessage(playerid, 0xFF0000FF, accept);

													format(forplayer, sizeof(forplayer), "{FE9A2E}[WEED] {FFFFFF}You received drugs from %s(%i). /useweed to restore health.", playerData[playerid][playerNamee], playerid);
													SendClientMessage(otherID, 0xFF0000FF, forplayer);
												}
												else
												{
													SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You don't have enough money to purchase stock.");
												}
											}
											else
											{
												SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be in an ice cream truck to sell weed.");
											}
										}
										else
										{
											SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be in an ice cream truck to sell weed.");
										}
									}
									else
									{
										SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You're not close enough to that player.");
									}
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}That player is not logged in.");
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}That player is not connected.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot sell weed to yourself.");
						}
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be a drug dealer to use this command.");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}Only civilians can use this command.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot do this whilst in an event.");
		}
	}
	return 1;
}

COMMAND:useweed(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(!playerData[playerid][isInEvent])
		{
			if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
			{
				if (playerData[playerid][playerWeed] > 0)
				{
					new Float:health;
					GetPlayerHealth(playerid, health);

					if (health < 80)
					{
						if(!playerData[playerid][canWeed])
					    {
					        SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Wait before using another weed ROFL, are you gonna die?.");
					        return 1;
					    }
						// Add 20 health to the player
						SetPlayerHealth(playerid, health + 20);

						// Take 1 weed
						playerData[playerid][playerWeed] = playerData[playerid][playerWeed] - 1;

						// Info
						new info[200];
						format(info, sizeof(info), "{FE9A2E}[WEED] {FFFFFF}You smoked some weed. Weed Remaining: %i", playerData[playerid][playerWeed]);
						SendClientMessage(playerid, 0xFF0000FF, info);

						Delete3DTextLabel(playerData[playerid][weedLabel]);
						playerData[playerid][canWeed] = false;
						playerData[playerid][weedLabel] = Create3DTextLabel("USED WEED", 0xFFDC2EFF, 30.0, 40.0, 50.0, 40.0, 0);
						Attach3DTextLabelToPlayer(playerData[playerid][weedLabel], playerid, 0.0, 0.0, 0.4);
						SetTimerEx("weedExpire", 3000, 0, "i", playerid);
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}This command can only be used if you have less than 80 percent health.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You have no weed left.");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}Only civilians can use this command.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot do this whilst in an event.");
		}
	}
	return 1;
}

COMMAND:cure(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(!playerData[playerid][isInEvent])
		{
			if(playerData[playerid][playerClass] == CLASS_MEDIC)
			{
				new otherID, price;

				if(sscanf(params, "ui", otherID, price))
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"cure <playername/id> <price>\"");
				}
				else
				{
					if(playerid != otherID)
					{
						if(IsPlayerConnected(otherID))
						{
							if(playerData[otherID][playerLoggedIn])
							{
								if(!IsPlayerInAnyVehicle(otherID))
								{
									if(isPlayerInRangeOfPlayer(playerid, otherID, 4.0))
									{
										if (price >= 500 && price <= 5000)
										{
											if (playerData[playerid][canCure])
											{
												if(playerData[otherID][hasSTD])
												{
													playerData[otherID][playerCureOffer] = playerid;
													playerData[otherID][playerCurePrice] = price;

													// Send the invite
													new offer[200];
													format(offer, sizeof(offer), "{FE9A2E}[MEDIC OFFER] {FFFFFF}%s(%i) wishes to cure you for {FFDC2E}%s {FFFFFF}- /acceptcure", playerData[playerid][playerNamee], playerid, FormatNumber(price));
													SendClientMessage(otherID, 0xFF0000FF, offer);

													new to[200];
													format(to, sizeof(to), "{FE9A2E}[OFFER SENT] {FFFFFF}You offered to cure %s(%i) for {FFDC2E}$%s", playerData[otherID][playerNamee], otherID, FormatNumber(price));
													SendClientMessage(playerid, 0xFF0000FF, to);
												}
												else
												{
													SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}That player doesn't need curing.");
												}
											}
											else
											{
												SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}Please wait before curing another player.");
											}
										}
										else
										{
											SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}The price must be between $500 and $5000.");
										}
									}
									else
									{
										SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You're not close enough to that player.");
									}
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}That player is in a vehicle.");
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}That player is not logged in.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}That player is not connected.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot cure yourself.");
					}
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}Only medics can use this command.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot do this whilst in an event.");
		}
	}
	return 1;
}

COMMAND:heal(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(!playerData[playerid][isInEvent])
		{
			if(playerData[playerid][playerClass] == CLASS_MEDIC)
			{
				new otherID, price;

				if(sscanf(params, "ui", otherID, price))
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"heal <playername/id> <price>\"");
				}
				else
				{
					if(playerid != otherID)
					{
						if(IsPlayerConnected(otherID))
						{
							if(playerData[otherID][playerLoggedIn])
							{
								if(!IsPlayerInAnyVehicle(otherID))
								{
									if(isPlayerInRangeOfPlayer(playerid, otherID, 4.0))
									{
										if (price >= 500 && price <= 5000)
										{
											new Float:health;
											GetPlayerHealth(otherID, health);

											if (playerData[playerid][canHeal])
											{
												if(health < 100)
												{
													playerData[otherID][playerHealOffer] = playerid;
													playerData[otherID][playerHealPrice] = price;

													// Send the invite
													new offer[200];
													format(offer, sizeof(offer), "{FE9A2E}[MEDIC OFFER] {FFFFFF}%s(%i) wishes to heal you for {FFDC2E}%s {FFFFFF}- /acceptheal", playerData[playerid][playerNamee], playerid, FormatNumber(price));
													SendClientMessage(otherID, 0xFF0000FF, offer);

													new to[200];
													format(to, sizeof(to), "{FE9A2E}[OFFER SENT] {FFFFFF}You offered to heal %s(%i) for {FFDC2E}$%s", playerData[otherID][playerNamee], otherID, FormatNumber(price));
													SendClientMessage(playerid, 0xFF0000FF, to);
												}
												else
												{
													SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}That player doesn't need healing.");
												}
											}
											else
											{
												SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}Please wait before healing another player.");
											}
										}
										else
										{
											SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}The price must be between $500 and $5000.");
										}
									}
									else
									{
										SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You're not close enough to that player.");
									}
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}That player is in a vehicle.");
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}That player is not logged in.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}That player is not connected.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot heal yourself.");
					}
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}Only medics can use this command.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot do this whilst in an event.");
		}
	}
	return 1;
}

COMMAND:acceptcure(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(!playerData[playerid][isInEvent])
		{
			if (playerData[playerid][playerJailTime] < 1)
			{
				if (playerData[playerid][playerCureOffer] == -1)
				{
					SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}There are no medic offers.");
				}
				else
				{
					new dealerID = playerData[playerid][playerCureOffer];
					if (playerid != dealerID)
					{
						if(!IsPlayerConnected(dealerID)) // logged in
						{
							// Dealer offline
							SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}The medic is no longer available.");
						}
						else
						{
							// Check radius (a little larger this time)
							if(isPlayerInRangeOfPlayer(playerid, dealerID, 20.0))
							{
								if (playerData[playerid][playerMoney] >= playerData[playerid][playerCurePrice])
								{
									// Tell the dealer the player accepted
									new accept[200];
									format(accept, sizeof(accept), "{FE9A2E}[OFFER ACCEPTED] {FFFFFF}%s(%i) has accepted your request and has been cured for {FFDC2E}$%s", playerData[playerid][playerNamee], playerid, FormatNumber(playerData[playerid][playerCurePrice]));
									SendClientMessage(dealerID, 0xFF0000FF, accept);

									playerTakeMoney(playerid, playerData[playerid][playerCurePrice]);
									playerGiveMoney(dealerID, playerData[playerid][playerCurePrice]);
									playerGiveXP(dealerID, 5);

									playerData[playerid][hasSTD] = false;
									KillTimer(playerData[playerid][rapedTimer]);

									SendClientMessage(playerid, COLOR_WHITE, "{FE9A2E}[OFFER ACCEPTED] {FFFFFF}You are cured.");
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot afford this.");
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}The medic is no longer in range.");
							}
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot cure yourself.");
					}
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot do this whilst jailed.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot do this whilst in an event.");
		}
	}
	return 1;
}

COMMAND:acceptheal(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(!playerData[playerid][isInEvent])
		{
			if (playerData[playerid][playerJailTime] < 1)
			{
				if (playerData[playerid][playerHealOffer] == -1)
				{
					SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}There are no medic offers.");
				}
				else
				{
					new dealerID = playerData[playerid][playerHealOffer];
					if (playerid != dealerID)
					{
						if(!IsPlayerConnected(dealerID)) // logged in
						{
							// Dealer offline
							SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}The medic is no longer available.");
						}
						else
						{
							// Check radius (a little larger this time)
							if(isPlayerInRangeOfPlayer(playerid, dealerID, 20.0))
							{
								if (playerData[playerid][playerMoney] >= playerData[playerid][playerHealPrice])
								{
									// Tell the dealer the player accepted
									new accept[200];
									format(accept, sizeof(accept), "{FE9A2E}[OFFER ACCEPTED] {FFFFFF}%s(%i) has accepted your request and has been healed for {FFDC2E}$%s", playerData[playerid][playerNamee], playerid, FormatNumber(playerData[playerid][playerHealPrice]));
									SendClientMessage(dealerID, 0xFF0000FF, accept);

									playerTakeMoney(playerid, playerData[playerid][playerHealPrice]);
									playerGiveMoney(dealerID, playerData[playerid][playerHealPrice]);
									playerGiveXP(dealerID, 5);

									SetPlayerHealth(playerid, 100.0);

									SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You were healed.");
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot afford this.");
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}The medic is no longer in range.");
							}
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot heal yourself.");
					}
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot do this whilst jailed.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot do this whilst in an event.");
		}
	}
	return 1;
}

// End job commands

COMMAND:placehit(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerClass] == CLASS_CIVILIAN)
		{
			new otherPlayer, hitAmount, message[300];
			if(sscanf(params, "ui", otherPlayer, hitAmount))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"placehit <playerID> <amount>\"");
			}
			else
			{
				if(playerid != otherPlayer)
				{
					if(IsPlayerConnected(otherPlayer))
					{
						if(playerData[otherPlayer][playerLoggedIn])
						{
							if(playerData[playerid][playerJob] != JOB_HITMAN)
							{
								if(hitAmount > 999)
								{
									if (playerData[playerid][playerMoney] >= hitAmount)
									{
										if(playerData[otherPlayer][playerHitValue] > 0)
										{
											playerData[otherPlayer][playerHitValue] = playerData[otherPlayer][playerHitValue] + hitAmount;
										}
										else
										{
											playerData[otherPlayer][playerHitValue] = hitAmount;
										}

										format(message, sizeof(message), "{FFDC2E}[CONTRACT] {FFFFFF}%s(%i) has placed a contract on %s(%i) for {FFDC2E}$%s{FFFFFF}! Type {FFDC2E}/hitlist{FFFFFF} to select your prey.", playerData[playerid][playerNamee], playerid, playerData[otherPlayer][playerNamee], otherPlayer, FormatNumber(hitAmount));
										SendClientMessageToAll(COLOR_WHITE, message);

										playerTakeMoney(playerid, hitAmount);
									}
									else
									{
										SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You don't have enough money to place a hit of that size.");
									}
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You need to place at least $1,000 on the players head.");
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot place hits when you're a hitman.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot place hits on those who are not logged in.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}That player is not connected.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You cannot place a hit upon yourself.");
				}
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}Only civilians can use this command.");
		}
    }
    else
    {
        SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
    }
    return 1;
}


// VIP Commands
COMMAND:vipcolor(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerVIPLevel] >= 1)
		{
			if (playerData[playerid][vipColour])
			{
				// Disable Colour
				playerData[playerid][vipColour] = false;
				SendClientMessage(playerid, COLOR_WHITE, "{FE9A2E}[VIP] {FFFFFF}Your VIP name colour has been disabled.");
			}
			else
			{
				// Enable Colour
				playerData[playerid][vipColour] = true;
				SendClientMessage(playerid, COLOR_WHITE, "{FE9A2E}[VIP] {FFFFFF}Your VIP name colour has been enabled.");
			}

			newPlayerColour(playerid);
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}This command can only be used by VIPs.");
		}
	}

	return 1;
}

COMMAND:vipskin(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerVIPLevel] >= 2)
		{
			new skinID;

			if(sscanf(params, "i", skinID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"vipskin <skin_id>\"");
			}
			else
			{
				if(skinID < 1 || skinID > 311)
				{
					return SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Skin ID should be 1-311");
				}
				else
				{
					new message[128];
					SetPlayerSkin(playerid, skinID);
					format(message, sizeof(message), "{FE9A2E}[VIP] {FFFFFF}Your custom skin has been set.");
					SendClientMessage(playerid, COLOR_WHITE, message);
					playerData[playerid][playerCustomSkin] = skinID;
					
					SetTimerEx("checkDriveB", 2000, false, "d", playerid);
				}
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}This command can only be used by Standard VIP members.");
		}
	}

	return 1;
}

COMMAND:vcolor(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerVIPLevel] >= 1)
		{
			if (IsPlayerInAnyVehicle(playerid))
			{
				new
					colour1,
					colour2
				;

				if(sscanf(params, "ii", colour1, colour2))
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"vcolour <colour 1> <colour 2>\"");
				}
				else
				{
					if (colour1 >= 0 && colour1 <= 255 && colour2 >= 0 && colour2 <= 255)
					{
						ChangeVehicleColor(GetPlayerVehicleID(playerid), colour1, colour2);
						SendClientMessage(playerid, COLOR_WHITE, "{FE9A2E}[VIP] {FFFFFF}Vehicle colour changed.");
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Colour ID should be between 0 and 255.");
					}
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be in a vehicle to use this command.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}This command can only be used by VIPs.");
		}
	}

	return 1;
}

COMMAND:vsay(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerVIPLevel] >= 1)
		{
			new message[100];

			if(sscanf(params, "s[100]", message))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"vsay <message>\"");
			}
			else
			{
				format(message, sizeof(message), "{58D3F7}(VIP) %s: {FFFFFF}%s", playerData[playerid][playerNamee], message);
				SendClientMessageToAll(COLOR_WHITE, message);
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}This command can only be used by VIPs.");
		}
	}

	return 1;
}

COMMAND:vipweapon(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerVIPLevel] >= 2)
		{
			// Select a spawn weapon
			ShowPlayerDialog(playerid, DIALOG_VIPGUN, DIALOG_STYLE_LIST, "VIP Spawn Weapon", "Deagle \nM4 \nSniper Rifle \nSawnoff Shotgun \nChainsaw \nMP5 \nCombat Shotgun \nMicro SMG", "Go", "Cancel");
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}This command can only be used by VIPs.");
		}
	}

	return 1;
}

// COMMAND:exitvipstore(playerid, params[])
// {
	// if(playerData[playerid][playerLoggedIn])
	// {
  	    // if(playerData[playerid][playerVIPLevel] == 3)
  	    // {
			// if(GetPlayerInterior(playerid) == 0)
			// {
				// playerData[playerid][playerCheckpointTime] = GetTickCount();

				// SetPlayerPos(playerid, -1493.1566, 920.1319, 7.1875);
				// SetPlayerInterior(playerid, 0);
				// SetPlayerVirtualWorld(playerid, 0);
			// }
			// else
			// {
				// SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You are not inside the V.I.P Store.");
			// }
		// }
		// else
		// {
			// return 0;
		// }
	// }
	// else
	// {
		// SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
	// }

	// return 1;
// }

// COMMAND:exitstore(playerid, params[])
// {
	// if(playerData[playerid][playerLoggedIn])
	// {
  	    // if(playerData[playerid][playerVIPLevel] == 3)
  	    // {
			// if(GetPlayerInterior(playerid) == 0)
			// {
				// playerData[playerid][playerCheckpointTime] = GetTickCount();

				// SetPlayerPos(playerid, -1494.9318, 920.0157, 7.1875);
				// SetPlayerInterior(playerid, 0);
				// SetPlayerVirtualWorld(playerid, 0);
			// }
			// else
			// {
				// SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You are not inside the V.I.P Store.");
			// }
		// }
		// else
		// {
			// return 0;
		// }
	// }
	// else
	// {
		// SendClientMessage(playerid, COLOR_WHITE, "{E81919}[ERROR] {FFFFFF}You must be logged in to use commands.");
	// }

	// return 1;
// }

COMMAND:hitmarker(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerHitmarker])
		{
			playerData[playerid][playerHitmarker] = false;
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You have disabled the hitmarker.");
		}
		else
		{
			playerData[playerid][playerHitmarker] = true;
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You have enabled the hitmarker.");
		}
	}
	return 1;
}
