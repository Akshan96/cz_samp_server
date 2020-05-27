COMMAND:animlist(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[ANIM] {FFFFFF}/sit /lay /wave /dance /laugh /wank /slapass");
		SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[ANIM] {FFFFFF}/piss /handsup /hide /kiss /imdead /sex");
	}
	return 1;
}
	
COMMAND:stopanim(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (!playerData[playerid][playerIsCuffed])
		{
			if (!playerData[playerid][playerIsTazed])
			{
				if (!playerData[playerid][playerIsTied])
				{
					if (!IsPlayerInAnyVehicle(playerid))
					{
						if (playerData[playerid][playerRobTime] < 1)
						{
							if(playerData[playerid][playerUsingAnim])
							{
								// Stop the animation
								ClearAnimations(playerid);
								
								// Anims Stopped
								playerData[playerid][playerUsingAnim] = false;
								
								// Clear special actions
								SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
							}
							else
							{	
								// Not using a command animation
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You're not performing an animation.");
							}
						}
						else
						{
							// Robbing
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use/stop animations whilst robbing a store.");
						}
					}
					else
					{
						// In a vehicle
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst in a vehicle.");
					}
				}
				else
				{
					// Tied
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst tied.");
				}
			}
			else
			{
				// Tazed
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst tazed.");
			}
		}
		else
		{
			// Cuffed
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst cuffed.");
		}
	}
	
	return 1;
}

COMMAND:handsup(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (!playerData[playerid][playerIsCuffed])
		{
			if (!playerData[playerid][playerIsTazed])
			{
				if (!playerData[playerid][playerIsTied])
				{
					if (!IsPlayerInAnyVehicle(playerid))
					{
						if (playerData[playerid][playerRobTime] < 1)
						{
							// Apply the animation
							if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) 
							{
								SetPlayerSpecialAction(playerid, SPECIAL_ACTION_HANDSUP);
							}
							
							if (!playerData[playerid][playerUsingAnim])
							{
								SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[ANIM] {FFFFFF}To stop the animation, type /stopanim");
								playerData[playerid][playerUsingAnim] = true;
							}
						}
						else
						{
							// Robbing
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use/stop animations whilst robbing a store.");
						}
					}
					else
					{
						// In a vehicle
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst in a vehicle.");
					}
				}
				else
				{
					// Tied
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst tied.");
				}
			}
			else
			{
				// Tazed
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst tazed.");
			}
		}
		else
		{
			// Cuffed
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst cuffed.");
		}
	}
	
	return 1;
}

COMMAND:sex(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (!playerData[playerid][playerIsCuffed])
		{
			if (!playerData[playerid][playerIsTazed])
			{
				if (!playerData[playerid][playerIsTied])
				{
					if (!IsPlayerInAnyVehicle(playerid))
					{
						if (playerData[playerid][playerRobTime] < 1)
						{
							// Apply the animation
							if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) 
							{
								ApplyAnimation(playerid, "BLOWJOBZ", "BJ_STAND_LOOP_W", 4.0, 1, 0, 0, 0, 0);
							}
							
							if (!playerData[playerid][playerUsingAnim])
							{
								SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[ANIM] {FFFFFF}To stop the animation, type /stopanim");
								playerData[playerid][playerUsingAnim] = true;
							}
						}
						else
						{
							// Robbing
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use/stop animations whilst robbing a store.");
						}
					}
					else
					{
						// In a vehicle
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst in a vehicle.");
					}
				}
				else
				{
					// Tied
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst tied.");
				}
			}
			else
			{
				// Tazed
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst tazed.");
			}
		}
		else
		{
			// Cuffed
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst cuffed.");
		}
	}
	
	return 1;
}

COMMAND:kiss(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (!playerData[playerid][playerIsCuffed])
		{
			if (!playerData[playerid][playerIsTazed])
			{
				if (!playerData[playerid][playerIsTied])
				{
					if (!IsPlayerInAnyVehicle(playerid))
					{
						if (playerData[playerid][playerRobTime] < 1)
						{
							// Apply the animation
							if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) 
							{
								ApplyAnimation(playerid,"KISSING","Grlfrd_Kiss_02", 4.0, 1, 0, 0, 0, 0);
							}
							
							if (!playerData[playerid][playerUsingAnim])
							{
								SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[ANIM] {FFFFFF}To stop the animation, type /stopanim");
								playerData[playerid][playerUsingAnim] = true;
							}
						}
						else
						{
							// Robbing
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use/stop animations whilst robbing a store.");
						}
					}
					else
					{
						// In a vehicle
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst in a vehicle.");
					}
				}
				else
				{
					// Tied
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst tied.");
				}
			}
			else
			{
				// Tazed
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst tazed.");
			}
		}
		else
		{
			// Cuffed
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst cuffed.");
		}
	}
	
	return 1;
}

COMMAND:imdead(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (!playerData[playerid][playerIsCuffed])
		{
			if (!playerData[playerid][playerIsTazed])
			{
				if (!playerData[playerid][playerIsTied])
				{
					if (!IsPlayerInAnyVehicle(playerid))
					{
						if (playerData[playerid][playerRobTime] < 1)
						{
							// Apply the animation
							if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) 
							{
								ApplyAnimation(playerid,"CRACK","crckdeth2", 4.0, 1, 0, 0, 0, 0);
							}
							
							if (!playerData[playerid][playerUsingAnim])
							{
								SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[ANIM] {FFFFFF}To stop the animation, type /stopanim");
								playerData[playerid][playerUsingAnim] = true;
							}
						}
						else
						{
							// Robbing
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use/stop animations whilst robbing a store.");
						}
					}
					else
					{
						// In a vehicle
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst in a vehicle.");
					}
				}
				else
				{
					// Tied
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst tied.");
				}
			}
			else
			{
				// Tazed
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst tazed.");
			}
		}
		else
		{
			// Cuffed
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst cuffed.");
		}
	}
	
	return 1;
}

COMMAND:piss(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (!playerData[playerid][playerIsCuffed])
		{
			if (!playerData[playerid][playerIsTazed])
			{
				if (!playerData[playerid][playerIsTied])
				{
					if (!IsPlayerInAnyVehicle(playerid))
					{
						if (playerData[playerid][playerRobTime] < 1)
						{
							// Apply the animation
							SetPlayerSpecialAction(playerid, 68);
							
							if (!playerData[playerid][playerUsingAnim])
							{
								SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[ANIM] {FFFFFF}To stop the animation, type /stopanim");
								playerData[playerid][playerUsingAnim] = true;
							}
						}
						else
						{
							// Robbing
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use/stop animations whilst robbing a store.");
						}
					}
					else
					{
						// In a vehicle
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst in a vehicle.");
					}
				}
				else
				{
					// Tied
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst tied.");
				}
			}
			else
			{
				// Tazed
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst tazed.");
			}
		}
		else
		{
			// Cuffed
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst cuffed.");
		}
	}
	
	return 1;
}

COMMAND:slapass(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (!playerData[playerid][playerIsCuffed])
		{
			if (!playerData[playerid][playerIsTazed])
			{
				if (!playerData[playerid][playerIsTied])
				{
					if (!IsPlayerInAnyVehicle(playerid))
					{
						if (playerData[playerid][playerRobTime] < 1)
						{
							// Apply the animation
							ApplyAnimation(playerid, "SWEET", "sweet_ass_slap", 4.0, 0, 0, 0, 0, 0);
							
							if (!playerData[playerid][playerUsingAnim])
							{
								SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[ANIM] {FFFFFF}To stop the animation, type /stopanim");
								playerData[playerid][playerUsingAnim] = true;
							}
						}
						else
						{
							// Robbing
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use/stop animations whilst robbing a store.");
						}
					}
					else
					{
						// In a vehicle
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst in a vehicle.");
					}
				}
				else
				{
					// Tied
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst tied.");
				}
			}
			else
			{
				// Tazed
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst tazed.");
			}
		}
		else
		{
			// Cuffed
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst cuffed.");
		}
	}
	
	return 1;
}

COMMAND:wank(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (!playerData[playerid][playerIsCuffed])
		{
			if (!playerData[playerid][playerIsTazed])
			{
				if (!playerData[playerid][playerIsTied])
				{
					if (!IsPlayerInAnyVehicle(playerid))
					{
						if (playerData[playerid][playerRobTime] < 1)
						{
							// Apply the animation
							ApplyAnimation(playerid, "PAULNMAC", "wank_loop", 4.0, 0, 0, 0, 0, 0);
							
							if (!playerData[playerid][playerUsingAnim])
							{
								SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[ANIM] {FFFFFF}To stop the animation, type /stopanim");
								playerData[playerid][playerUsingAnim] = true;
							}
						}
						else
						{
							// Robbing
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use/stop animations whilst robbing a store.");
						}
					}
					else
					{
						// In a vehicle
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst in a vehicle.");
					}
				}
				else
				{
					// Tied
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst tied.");
				}
			}
			else
			{
				// Tazed
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst tazed.");
			}
		}
		else
		{
			// Cuffed
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst cuffed.");
		}
	}
	
	return 1;
}

COMMAND:laugh(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (!playerData[playerid][playerIsCuffed])
		{
			if (!playerData[playerid][playerIsTazed])
			{
				if (!playerData[playerid][playerIsTied])
				{
					if (!IsPlayerInAnyVehicle(playerid))
					{
						if (playerData[playerid][playerRobTime] < 1)
						{
							// Apply the animation
							ApplyAnimation(playerid, "RAPPING", "Laugh_01", 4.0, 0, 0, 0, 0, 0);
							
							if (!playerData[playerid][playerUsingAnim])
							{
								SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[ANIM] {FFFFFF}To stop the animation, type /stopanim");
								playerData[playerid][playerUsingAnim] = true;
							}
						}
						else
						{
							// Robbing
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use/stop animations whilst robbing a store.");
						}
					}
					else
					{
						// In a vehicle
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst in a vehicle.");
					}
				}
				else
				{
					// Tied
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst tied.");
				}
			}
			else
			{
				// Tazed
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst tazed.");
			}
		}
		else
		{
			// Cuffed
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst cuffed.");
		}
	}
	
	return 1;
}

COMMAND:lay(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (!playerData[playerid][playerIsCuffed])
		{
			if (!playerData[playerid][playerIsTazed])
			{
				if (!playerData[playerid][playerIsTied])
				{
					if (!IsPlayerInAnyVehicle(playerid))
					{
						if (playerData[playerid][playerRobTime] < 1)
						{
							// Apply the animation
							ApplyAnimation(playerid, "BEACH", "bather", 4.0, 1, 0, 0, 0, 0);
							
							if (!playerData[playerid][playerUsingAnim])
							{
								SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[ANIM] {FFFFFF}To stop the animation, type /stopanim");
								playerData[playerid][playerUsingAnim] = true;
							}
						}
						else
						{
							// Robbing
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use/stop animations whilst robbing a store.");
						}
					}
					else
					{
						// In a vehicle
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst in a vehicle.");
					}
				}
				else
				{
					// Tied
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst tied.");
				}
			}
			else
			{
				// Tazed
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst tazed.");
			}
		}
		else
		{
			// Cuffed
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst cuffed.");
		}
	}
	
	return 1;
}


COMMAND:wave(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (!playerData[playerid][playerIsCuffed])
		{
			if (!playerData[playerid][playerIsTazed])
			{
				if (!playerData[playerid][playerIsTied])
				{
					if (!IsPlayerInAnyVehicle(playerid))
					{
						if (playerData[playerid][playerRobTime] < 1)
						{
							// Apply the animation
							ApplyAnimation(playerid, "ON_LOOKERS", "wave_loop", 4.0, 1, 0, 0, 0, 0);
							
							if (!playerData[playerid][playerUsingAnim])
							{
								SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[ANIM] {FFFFFF}To stop the animation, type /stopanim");
								playerData[playerid][playerUsingAnim] = true;
							}
						}
						else
						{
							// Robbing
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use/stop animations whilst robbing a store.");
						}
					}
					else
					{
						// In a vehicle
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst in a vehicle.");
					}
				}
				else
				{
					// Tied
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst tied.");
				}
			}
			else
			{
				// Tazed
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst tazed.");
			}
		}
		else
		{
			// Cuffed
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst cuffed.");
		}
	}
	
	return 1;
}

COMMAND:sit(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (!playerData[playerid][playerIsCuffed])
		{
			if (!playerData[playerid][playerIsTazed])
			{
				if (!playerData[playerid][playerIsTied])
				{
					if (!IsPlayerInAnyVehicle(playerid))
					{
						if (playerData[playerid][playerRobTime] < 1)
						{
							// Apply the animation
							ApplyAnimation(playerid, "BEACH", "ParkSit_M_loop", 4.0, 1, 0, 0, 0, 0);
							
							if (!playerData[playerid][playerUsingAnim])
							{
								SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[ANIM] {FFFFFF}To stop the animation, type /stopanim");
								playerData[playerid][playerUsingAnim] = true;
							}
						}
						else
						{
							// Robbing
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use/stop animations whilst robbing a store.");
						}
					}
					else
					{
						// In a vehicle
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst in a vehicle.");
					}
				}
				else
				{
					// Tied
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst tied.");
				}
			}
			else
			{
				// Tazed
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst tazed.");
			}
		}
		else
		{
			// Cuffed
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst cuffed.");
		}
	}
	
	return 1;
}

COMMAND:dance(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (!playerData[playerid][playerIsCuffed])
		{
			if (!playerData[playerid][playerIsTazed])
			{
				if (!playerData[playerid][playerIsTied])
				{
					if (!IsPlayerInAnyVehicle(playerid))
					{
						if (playerData[playerid][playerRobTime] < 1)
						{
							new anim;
							if(sscanf(params, "i", anim))
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"dance <1-5>\"");
							}
							else
							{
								if (anim > 0 && anim < 6)
								{
									switch(anim)
									{
										case 1:
										{
											ApplyAnimation(playerid, "DANCING", "dnce_M_a", 4.0, 1, 0, 0, 0, 0);
										}
										case 2:
										{
											ApplyAnimation(playerid, "DANCING", "dnce_M_b", 4.0, 1, 0, 0, 0, 0);
										}
										case 3:
										{
											ApplyAnimation(playerid, "DANCING", "dnce_M_c", 4.0, 1, 0, 0, 0, 0);
										}
										case 4:
										{
											ApplyAnimation(playerid, "DANCING", "dnce_M_d", 4.0, 1, 0, 0, 0, 0);
										}
										case 5:
										{
											ApplyAnimation(playerid, "DANCING", "dnce_M_e", 4.0, 1, 0, 0, 0, 0);
										}
										default:
										{
											ApplyAnimation(playerid, "DANCING", "dnce_M_a", 4.0, 1, 0, 0, 0, 0);
										}
									}
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"dance <1-5>\"");
								}
								
								if (!playerData[playerid][playerUsingAnim])
								{
									SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[ANIM] {FFFFFF}To stop the animation, type /stopanim");
									playerData[playerid][playerUsingAnim] = true;
								}
							}
						}
						else
						{
							// Robbing
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use/stop animations whilst robbing a store.");
						}
					}
					else
					{
						// In a vehicle
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst in a vehicle.");
					}
				}
				else
				{
					// Tied
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst tied.");
				}
			}
			else
			{
				// Tazed
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst tazed.");
			}
		}
		else
		{
			// Cuffed
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst cuffed.");
		}
	}
	
	return 1;
}

COMMAND:hide(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (!playerData[playerid][playerIsCuffed])
		{
			if (!playerData[playerid][playerIsTazed])
			{
				if (!playerData[playerid][playerIsTied])
				{
					if (!IsPlayerInAnyVehicle(playerid))
					{
						if (playerData[playerid][playerRobTime] < 1)
						{
							// Apply the animation
							ApplyAnimation(playerid, "PED", "cower", 4.0, 1, 0, 0, 0, 0);

							if (!playerData[playerid][playerUsingAnim])
							{
								SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[ANIM] {FFFFFF}To stop the animation, type /stopanim");
								playerData[playerid][playerUsingAnim] = true;
							}
						}
						else
						{
							// Robbing
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot use/stop animations whilst robbing a store.");
						}
					}
					else
					{
						// In a vehicle
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst in a vehicle.");
					}
				}
				else
				{
					// Tied
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst tied.");
				}
			}
			else
			{
				// Tazed
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst tazed.");
			}
		}
		else
		{
			// Cuffed
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot perform an animation whilst cuffed.");
		}
	}

	return 1;
}
