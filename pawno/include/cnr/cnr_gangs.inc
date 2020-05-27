enum gangInformation
{
	gangID,
	gangName[MAX_GANG_CHARS],
	gangLeader,
	gangColour[6],
	gangMembers[MAX_PLAYERS],
	currentInvites[MAX_PLAYERS]
}

new gangData[MAX_GANGS][gangInformation];

flushGangs()
{
	for(new i = 0; i < MAX_GANGS; i++)
	{
		gangData[i][gangID] = INVALID_GANG_ID;
		gangData[i][gangLeader] = INVALID_PLAYER_ID;
		//gangData[i][gangColour] = "";
		
		for(new j = 0; j < MAX_PLAYERS; j++)
		{
			gangData[i][gangMembers][j] = INVALID_PLAYER_ID;
			gangData[i][currentInvites][j] = INVALID_PLAYER_ID;
		}
		
		format(gangData[i][gangName], MAX_GANG_CHARS, "");
	}
	
	return 1;
}

findNextFreeGangID()
{
	for(new i = 0; i < MAX_GANGS; i++)
	{
		if(gangData[i][gangLeader] == INVALID_PLAYER_ID)
		{
			return i;
		}
	}
	
	return INVALID_GANG_ID;
}

createGang(newGangName[MAX_GANG_CHARS], creatorID)
{
	new newGangID = findNextFreeGangID();

	gangData[newGangID][gangID] = newGangID;
	gangData[newGangID][gangName] = newGangName;
	gangData[newGangID][gangLeader] = creatorID;
	//gangData[newGangID][gangColour] = "FFFFFF";
	gangData[newGangID][gangMembers][creatorID] = 1;
	playerData[creatorID][playerGangID] = newGangID;
	
	return 1;
}

removeGang(gangToRemove)
{	
	gangData[gangToRemove][gangID] = INVALID_GANG_ID;
	gangData[gangToRemove][gangLeader] = INVALID_PLAYER_ID;
	//gangData[gangToRemove][gangColour] = "";
	
	for(new j = 0; j < MAX_PLAYERS; j++)
	{
		gangData[gangToRemove][gangMembers][j] = INVALID_PLAYER_ID;
		gangData[gangToRemove][currentInvites][j] = INVALID_PLAYER_ID;
	}
	
	format(gangData[gangToRemove][gangName], MAX_GANG_CHARS, "");
	
	for(new k = 0; k < MAX_PLAYERS; k++)
	{
		if(playerData[k][playerGangID] == gangToRemove)
		{
			playerData[k][playerGangID] = INVALID_GANG_ID;
		}
	}
	
	return 1;
}

sendMessageToGangMembers(gangToSendTo, messageToSend[])
{
	for(new i = 0; i < MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i))
		{
			if(playerData[i][playerLoggedIn])
			{
				if(playerData[i][playerGangID] == gangToSendTo)
				{
					SendClientMessage(i, COLOR_WHITE, messageToSend);
				}
			}
		}
	}
	
	return 1;
}

COMMAND:g(playerid, params[])
{
	new commandSelection[128];
	
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerClass] == CLASS_CIVILIAN || playerData[playerid][playerGangID] != INVALID_GANG_ID)
		{
			if(!sscanf(params, "s[128] ", commandSelection))
			{
				if(!strcmp(commandSelection, "create", true))
				{
					if(playerData[playerid][playerGangID] == INVALID_GANG_ID)
					{
						new newGangName[MAX_GANG_CHARS];
						
						if(!sscanf(params, "s[128] s[24]", commandSelection, newGangName))
						{
							if (strlen(newGangName) > 0 && strlen(newGangName) <= 24)
							{
								createGang(newGangName, playerid);
								
								new 
									successionMessage[128],
									playersGangID = playerData[playerid][playerGangID];

								format(successionMessage, sizeof(successionMessage), "{39BBEE}[GANG] {FFFFFF}%s has been created.", gangData[playersGangID][gangName]);//playerData[playerid][playerGangID]
								SendClientMessage(playerid, COLOR_WHITE, successionMessage);
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}The gang name should be between 0 and 25 characters long.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: /g(ang) create [GAME_NAME]");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You're already in a gang, you cannot create another.");
					}
				}		
				else if(!strcmp(commandSelection, "invite", true))
				{
					if(playerData[playerid][playerGangID] != INVALID_GANG_ID)
					{
						new playerToInvite;
						
						if(!sscanf(params, "s[128] u", commandSelection, playerToInvite))
						{
							if(IsPlayerConnected(playerToInvite)) // logged in
							{
								if(playerData[playerToInvite][playerLoggedIn]) // logged in
								{
									if(playerid != playerToInvite)
									{
										if(playerData[playerToInvite][playerGangID] == INVALID_GANG_ID)
										{
											new 
												invitingMessage[128],
												playersGangID = playerData[playerid][playerGangID];
											
											gangData[playersGangID][currentInvites][playerToInvite] = 1;
											
											format(invitingMessage, sizeof(invitingMessage), "{39BBEE}[GANG] {FFFFFF}You have invited %s(%i) to join %s.", playerData[playerToInvite][playerNamee], playerToInvite, gangData[playersGangID][gangName]);
											SendClientMessage(playerid, COLOR_WHITE, invitingMessage);
											
											format(invitingMessage, sizeof(invitingMessage), "{39BBEE}[GANG] {FFFFFF}%s(%i) has invited you to join %s, use /g(ang) join %i to join.", playerData[playerid][playerNamee], playerid, gangData[playersGangID][gangName], playersGangID);
											SendClientMessage(playerToInvite, COLOR_WHITE, invitingMessage);
										}
										else
										{
											SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}The player you're trying to invite is already in a gang.");
										}
									}
									else
									{
										SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You're already in this gang, no need to invite yourself.");
									}
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in.");
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not connected.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: /g(ang) invite [PLAYER_ID]");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You need to be in a gang use these commands.");
					}
				}			
				else if(!strcmp(commandSelection, "leader", true))
				{
					if(playerData[playerid][playerGangID] != INVALID_GANG_ID)
					{
						if(gangData[playerData[playerid][playerGangID]][gangLeader] == playerid)
						{
							new newLeaderID;
							
							if(!sscanf(params, "s[300] u", commandSelection, newLeaderID))
							{
								if(IsPlayerConnected(newLeaderID)) // logged in
								{
									if(playerData[newLeaderID][playerLoggedIn]) // logged in
									{
										if(playerid != newLeaderID)
										{
											if(playerData[playerid][playerGangID] == playerData[newLeaderID][playerGangID])
											{
												new successionMessage[128],
													playersGangID = playerData[playerid][playerGangID];
												
												format(successionMessage, sizeof(successionMessage), "{39BBEE}[GANG] {FFFFFF}%s(%i) has been made the leader of %s.", playerData[newLeaderID][playerNamee], newLeaderID, gangData[playersGangID][gangName]);
												sendMessageToGangMembers(playerData[playerid][playerGangID], successionMessage);
												
												gangData[playersGangID][gangLeader] = newLeaderID;
												
											}
											else
											{
												SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This player is not in your gang.");
											}
										}
										else
										{
											SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You're already the leader of this gang.");
										}
									}
									else
									{
										SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in.");
									}
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not connected.");
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: /g(ang) leader [PLAYER_ID]");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You're not the current leader of this gang.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You need to be in a gang use these commands.");
					}				
				}	
				else if(!strcmp(commandSelection, "kick", true))
				{
					if(playerData[playerid][playerGangID] != INVALID_GANG_ID)
					{
						if(gangData[playerData[playerid][playerGangID]][gangLeader] == playerid)
						{
							new playerToKick;
							
							if(!sscanf(params, "s[128] u", commandSelection, playerToKick))
							{
								if(IsPlayerConnected(playerToKick)) // logged in
								{
									if(playerData[playerToKick][playerLoggedIn]) // logged in
									{
										if(playerToKick != playerid)
										{
											if(playerData[playerid][playerGangID] == playerData[playerToKick][playerGangID])
											{
												new kickedMessage[128],
													playersGangID = playerData[playerid][playerGangID];
												
												format(kickedMessage, sizeof(kickedMessage), "{39BBEE}[GANG] {FFFFFF}%s(%i), the leader of %s, has kicked %s(%i).", playerData[playerid][playerNamee], playerid, gangData[playersGangID][gangName], playerData[playerToKick][playerNamee], playerToKick);
												sendMessageToGangMembers(playerData[playerid][playerGangID], kickedMessage);
												
												playerData[playerToKick][playerGangID] = INVALID_GANG_ID;
												gangData[playersGangID][gangMembers][playerToKick] = 0;	
											}
											else
											{
												SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}The player you're trying to kick isn't in your gang.");
											}
										}
										else
										{
											SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot kick yourself from the gang - use /leave.");
										}
									}
									else
									{
										SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not logged in.");
									}
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not connected.");
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: /g(ang) kick [PLAYER_ID]");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You're not the current leader of this gang.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You need to be in a gang use these commands.");
					}	
				}
				else if(!strcmp(commandSelection, "colour", true))
				{
					if(playerData[playerid][playerGangID] != INVALID_GANG_ID)
					{
						if(gangData[playerData[playerid][playerGangID]][gangLeader] == playerid)
						{
							//ShowPlayerDialog(playerid, DIALOG_GANG_COLOUR, DIALOG_STYLE_LIST, "Pick a gang colour", "{FFFFFF}Custom HEX {EDCA00}[VIP]\n\n{85007C}Purple\n{008575}Teal\n{148500}Green\n{855200}Brown\n{E30000}Red\n{F6FF00}Yellow\n{00E1FF}Cyan\n{0011FF}Blue\n{FF7DEB}Pink", "Register", "Cancel");
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You're not the current leader of this gang.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You need to be in a gang use these commands.");
					}	
				}
				else if(!strcmp(commandSelection, "disband", true))
				{
					if(playerData[playerid][playerGangID] != INVALID_GANG_ID)
					{
						if(gangData[playerData[playerid][playerGangID]][gangLeader] == playerid)
						{
							new disbandedMessage[128],
								playersGangID = playerData[playerid][playerGangID];
							
							format(disbandedMessage, sizeof(disbandedMessage), "{39BBEE}[GANG] {FFFFFF}%s(%i), the leader of %s, has disbanded the gang.", playerData[playerid][playerNamee], playerid, gangData[playersGangID][gangName]);
							sendMessageToGangMembers(playersGangID, disbandedMessage);
							removeGang(playersGangID);
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You're not the current leader of this gang.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You need to be in a gang use these commands.");
					}				
				}			
				else if(!strcmp(commandSelection, "leave", true))
				{
					if(playerData[playerid][playerGangID] != INVALID_GANG_ID)
					{
						new 
							playersGangID = playerData[playerid][playerGangID],
							leavingMessage[128],
							newGangLeader,
							bool:foundNewLeader = false;
						
						format(leavingMessage, sizeof(leavingMessage), "{39BBEE}[GANG] {FFFFFF}%s(%i) has left the gang.", playerData[playerid][playerNamee], playerid);
						sendMessageToGangMembers(playersGangID, leavingMessage);
						
						gangData[playersGangID][gangMembers][playerid] = INVALID_PLAYER_ID;
						playerData[playerid][playerGangID] = INVALID_GANG_ID;
						
						if(playerid == gangData[playersGangID][gangLeader])
						{
							for(new i = 0; i < MAX_PLAYERS; i++)
							{
								if(gangData[playersGangID][gangMembers][i] == 1)
								{
									if(!foundNewLeader)
									{
										gangData[playersGangID][gangLeader] = i;
										newGangLeader = i;
										foundNewLeader = true;
									}
								}
							}
							
							if(!foundNewLeader)
							{
								removeGang(playersGangID);
								SendClientMessage(playerid, COLOR_WHITE, "{39BBEE}[GANG] {FFFFFF}There were no other members, the gang has been terminated.");
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{39BBEE}[GANG] {FFFFFF}You have left the gang you were in.");
								format(leavingMessage, sizeof(leavingMessage), "{39BBEE}[GANG] {FFFFFF}%s(%i) is the new gang leader.", playerData[newGangLeader][playerNamee], gangData[playersGangID][gangLeader]);
								sendMessageToGangMembers(playersGangID, leavingMessage);
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{39BBEE}[GANG] {FFFFFF}You have left the gang you were in.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You need to be in a gang use these commands.");
					}
				}			
				else if(!strcmp(commandSelection, "join", true))
				{
					if(playerData[playerid][playerGangID] == INVALID_GANG_ID)
					{
						new gangToJoin;
						
						if(!sscanf(params, "s[128] i", commandSelection, gangToJoin))
						{
							if(gangToJoin < MAX_GANGS)
							{
								if(gangData[gangToJoin][gangLeader] != INVALID_PLAYER_ID)
								{
									if(gangData[gangToJoin][currentInvites][playerid] == 1)
									{
										new joinedMessage[128];
										
										gangData[gangToJoin][currentInvites][playerid] = 0;
										gangData[gangToJoin][gangMembers][playerid] = 1;
										playerData[playerid][playerGangID] = gangToJoin;
										
										format(joinedMessage, sizeof(joinedMessage), "{39BBEE}[GANG] {FFFFFF}%s(%i) has joined %s.", playerData[playerid][playerNamee], playerid, gangData[gangToJoin][gangName]);
										sendMessageToGangMembers(playerData[playerid][playerGangID], joinedMessage);
									}
									else
									{
										SendClientMessage(playerid, COLOR_WHITE, "{39BBEE}[GANG] {FFFFFF}You have not been invited to join this gang.");
									}
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{39BBEE}[GANG] {FFFFFF}The gang you're trying to join doesn't exist.");
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{39BBEE}[GANG] {FFFFFF}The gang you're trying to join doesn't exist.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: /g(ang) join [GANG_ID]");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You're already in a gang, you cannot join another.");
					}
				}
				else if(!strcmp(commandSelection, "help", true))
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}/g(ang) [CREATE/INVITE/LEADER/KICK/DISBAND/LEAVE/JOIN/HELP]");
				}
				else
				{
					if(playerData[playerid][playerGangID] != INVALID_GANG_ID)
					{
						new gangMessage[128];
						format(gangMessage, sizeof(gangMessage), "{39BBEE}[Gang Chat] {FFFFFF}%s: %s", playerData[playerid][playerNamee], params);
						sendMessageToGangMembers(playerData[playerid][playerGangID], gangMessage);
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}/g(ang) [CREATE/INVITE/LEADER/KICK/DISBAND/LEAVE/JOIN/HELP]");
					}
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}/g(ang) [CREATE/INVITE/LEADER/KICK/DISBAND/LEAVE/JOIN/HELP]");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This command can only be used by civilians.");
		}
	}
	else
	{
	
	}
	
	return 1;
}

COMMAND:gang(playerid, params[])
{
	return cmd_g(playerid, params); 
}

COMMAND:ganglist(playerid, params)
{
	new gangCount = 0;
	for(new i = 0; i < MAX_GANGS; i++)
	{
		if(gangData[i][gangID] != INVALID_GANG_ID)
		{
			new msg[128], leaderID = gangData[i][gangLeader];
			format(msg, 128, "Gang ID: {39BBEE}%i {FFFFFF}- Gang Leader: {39BBEE}%s {FFFFFF}- Gang Name: {39BBEE}%s", gangData[i][gangID], playerData[leaderID][playerNamee], gangData[i][gangName]);
			SendClientMessage(playerid, -1, msg);
			
			gangCount++;
		}
	}
	
	if (gangCount < 1)
	{
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}There's currently no gangs at this time.");
	}
	
	return 1;
}