// Weapon anti-cheat
new
	bool:PlayerWeapons[MAX_PLAYERS][47]
;

stock checkWeapons(playerid)
{
	if (!playerData[playerid][adminWeapon])
	{
		if(!playerData[playerid][playerBeenBanned])
		{
			switch(GetPlayerWeapon(playerid))
			{
				case 38, 42, 35, 36, 44, 45, 17, 37, 39, 40:
				{
					new messageContent[300];
					format(messageContent, sizeof(messageContent), "{FFAB4A}[ANTI-CHEAT] {FFFFFF}%s(%i) has been banned for Weapon Hacking", playerData[playerid][playerNamee], playerid);
					SendClientMessageToAll(COLOR_WHITE, messageContent);

					new
						banreason[250],
						playersIP[24]
					;

					GetPlayerIp(playerid, playersIP, sizeof(playersIP));

					format(banreason, sizeof(banreason), "INSERT INTO `playerbans` (`banned_by`, `banned_for`, `player_banned`, `player_ip`) VALUES ('Anti-Cheat', 'Weapon Hacks', '%s', '%s')", playerData[playerid][playerNamee], playersIP);
					mysql_query(banreason);

					playerData[playerid][playerBeenBanned] = true;

					KickWithMessage(playerid, "Banned for weapon hacking.");
				}

				case 16:
				{
					if (playerData[playerid][playerClass] != CLASS_ARMY)
					{
						new messageContent[128];
						format(messageContent, sizeof(messageContent), "{FFAB4A}[ANTI-CHEAT] {FFFFFF}%s(%i) has been kicked for possible weapon hacks.", playerData[playerid][playerNamee], playerid);
						SendClientMessageToAll(COLOR_WHITE, messageContent);
						KickWithMessage(playerid, "You have been kicked from the server for weapon hacking.");
					}
				}
			}

			new
				weapon = GetPlayerWeapon(playerid)
			;

			if(weapon != 0 && !PlayerWeapons[playerid][weapon] && weapon != 40 && weapon != 46)
			{
				if (playerData[playerid][hasSpawned])
				{
					KickWithMessage(playerid, "Kicked for weapon hacking.");
					playerData[playerid][playerBeenBanned] = true;

					// Possible weapon hack
					for(new i = 0; i < MAX_PLAYERS; i++)
					{
						if(IsPlayerConnected(i) && playerData[i][playerLevel] >= 1)
						{
							new message[200];
							format(message, sizeof(message), "{FFAB4A}[CHEAT REPORT] {FFFFFF}%s(%i) has been kicked for suspected weapon hacking.", playerData[playerid][playerNamee], playerid);
							SendClientMessage(i, COLOR_WHITE, message);
						}
					}
				}
			}
		}
	}
}

stock GivePlayerWeaponEx(playerid, weaponid, ammo)
{
    PlayerWeapons[playerid][weaponid] = true;
    GivePlayerWeapon(playerid, weaponid, ammo);
}

// Car throw anti-cheat
new bool:g_EnterAnim[MAX_PLAYERS char];

stock checkTheft(playerid, theirState, oldState)
{
	if (playerData[playerid][playerLevel] < 1)
	{
		if(!playerData[playerid][playerBeenBanned])
		{
			if (theirState == PLAYER_STATE_DRIVER && oldState == PLAYER_STATE_DRIVER)
			{
				// Possible car warp
				
				{

				}
			}
		}
	}
}

// Jetpack hacks
forward checkJetpack(playerid);
public checkJetpack(playerid)
{
	if(playerData[playerid][playerLevel] < 1)
	{
		if(!playerData[playerid][playerBeenBanned])
		{
			if (GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USEJETPACK)
			{
				// jetpack
				new administratorAlert[250];
				format(administratorAlert, sizeof(administratorAlert), "{FFAB4A}[CHEAT-DETECTION] {FFFFFF}%s(%i) has been automatically kicked for jetpack hacking.", playerData[playerid][playerNamee], playerid);
				adminchat(COLOR_WHITE, administratorAlert);

				new loggingString[256];
				format(loggingString, sizeof(loggingString), "%s was kicked for jetpack hacks", playerData[playerid][playerNamee]);
				writeInLog("cheatLog.html", loggingString);

				playerData[playerid][playerBeenBanned] = true;
				KickWithMessage(playerid, "[KICKED] You have been kicked for jetpack hacking.");
			}
		}
	}
}

// Speed hacks
forward speedCheck(playerid);
public speedCheck(playerid)
{
	if (GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		if(playerData[playerid][playerLevel] < 1)
		{
			if(!playerData[playerid][playerBeenBanned])
			{
				if(GetVehicleSpeed(GetPlayerVehicleID(playerid)) > 280)
				{
					if (GetVehicleModel(GetPlayerVehicleID(playerid)) != 520 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 519)
					{
						new administratorAlert[250];
						format(administratorAlert, sizeof(administratorAlert), "{FFAB4A}[CHEAT-DETECTION] {FFFFFF}%s(%i) has been automatically kicked for suspected speed hacks.", playerData[playerid][playerNamee], playerid);
						adminchat(COLOR_WHITE, administratorAlert);

						new theirSpeed = GetVehicleSpeed(GetPlayerVehicleID(playerid));

						new loggingString[256];
						format(loggingString, sizeof(loggingString), "%s was kicked for speed hacking - Speed: %i", playerData[playerid][playerNamee], theirSpeed);
						writeInLog("cheatLog.html", loggingString);

						playerData[playerid][playerBeenBanned] = true;
						KickWithMessage(playerid, "[KICKED] You have been kicked for speed hacking.");
					}
				}
			}
		}
	}
}

// Airbrake
forward ac_AirBrake(playerid);
public ac_AirBrake(playerid)
{
	if (serverInfo[abAnticheat])
	{
		if (!playerData[playerid][playerBeenBanned])
		{
			if (!playerData[playerid][abImmune])
			{
				if(playerData[playerid][playerLevel] < 1)
				{
					if (playerData[playerid][playerScore] < 2000)
					{
						new surf = GetPlayerSurfingVehicleID(playerid);
						if(surf == INVALID_VEHICLE_ID)
						{
							playerData[playerid][airbreakWarn]++;

							if (playerData[playerid][airbreakWarn] == 3)
							{
								// Kick
								new administratorAlert[250];
								format(administratorAlert, sizeof(administratorAlert), "{FFAB4A}[CHEAT-DETECTION] {FFFFFF}%s(%i) has been automatically kicked for air breaking.", playerData[playerid][playerNamee], playerid);
								adminchat(COLOR_WHITE, administratorAlert);

								new loggingString[256];
								format(loggingString, sizeof(loggingString), "%s was kicked for air breaking", playerData[playerid][playerNamee]);
								writeInLog("cheatLog.html", loggingString);

								playerData[playerid][playerBeenBanned] = true;
								KickWithMessage(playerid, "[KICKED] You have been kicked for air breaking.");
							}
							else
							{
								if (playerData[playerid][airbreakWarn] == 1)
								{
									new administratorAlert[200];
									format(administratorAlert, sizeof(administratorAlert), "{FFAB4A}[CHEAT-DETECTION] {FFFFFF}%s(%i) is suspected of air braking and has been warned.", playerData[playerid][playerNamee], playerid);
									adminchat(COLOR_WHITE, administratorAlert);

									ShowPlayerDialog(playerid, 91827, DIALOG_STYLE_MSGBOX, "Warning", "Air brake has been detected. Continuing to use the cheat will result in a ban.", "OK", "");
								}
							}
						}
					}
				}
			}
		}
	}
}

enum warpedVehicles
{
	theVehicle,
	Float:vehiclePositionX,
	Float:vehiclePositionY,
	Float:vehiclePositionZ,
	Float:vehiclePositionA,
	bool:Spawning,
	bool:Spawned,
	bool:wasOccupied
}

new vWarped[MAX_VEHICLES][warpedVehicles];


// Car teleport
forward ac_CarTeleport(playerid, vehicleid);
public ac_CarTeleport(playerid, vehicleid)
{
	if (serverInfo[carAnticheat])
	{
		if (!vWarped[vehicleid][Spawning])
		{
			if (!IsVehicleOccupied(vehicleid))
			{
				new Float: distance = GetVehicleDistanceFromPoint(vehicleid, vWarped[vehicleid][vehiclePositionX], vWarped[vehicleid][vehiclePositionY], vWarped[vehicleid][vehiclePositionZ]);

				if (distance > 10.00)
				{
					if (vWarped[vehicleid][wasOccupied])
					{
						if (!IsVehicleOccupied(vehicleid))
						{
							SetVehiclePos(vehicleid, vWarped[vehicleid][vehiclePositionX], vWarped[vehicleid][vehiclePositionY], vWarped[vehicleid][vehiclePositionZ]);
							SetVehicleZAngle(vehicleid, vWarped[vehicleid][vehiclePositionA]);
						}
					}
					else
					{
						SetVehicleToRespawn(vehicleid);
					}

					vWarped[vehicleid][Spawning] = true;
				}
			}
		}
	}
}

// Armour hacks
forward armourCheck(playerid);
public armourCheck(playerid)
{
	for(new i = 0; i < MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i) && playerData[i][playerLoggedIn])
		{
			if(!playerData[i][playerBeenBanned])
			{
				if (playerData[i][playerVIPLevel] <= 0)
				{
					new Float:armour, administratorAlert[250];
					GetPlayerArmour(i, armour);

					if (armour >= 5)
					{
						playerData[i][playerBeenBanned] = true;
						SetPlayerArmour(i, 0);

						format(administratorAlert, sizeof(administratorAlert), "{FFAB4A}[CHEAT-DETECTION] {FFFFFF}%s(%i) has been automatically kicked for armour hacks.", playerData[i][playerNamee], i);
						adminchat(COLOR_WHITE, administratorAlert);

						new loggingString[256];
						format(loggingString, sizeof(loggingString), "%s was kicked for armour hacking - Armour: %i", playerData[i][playerNamee], armour);
						writeInLog("cheatLog.html", loggingString);

						KickWithMessage(i, "[KICKED] You have been kicked for armour hacking.");
					}
				}
			}
		}
	}
}

// Anti c-bug
forward cbugKeys(playerid, newkeys, oldkeys);
public cbugKeys(playerid, newkeys, oldkeys)
{
    if((newkeys & KEY_FIRE) && (oldkeys & KEY_CROUCH) && !((oldkeys & KEY_FIRE) || (newkeys & KEY_HANDBRAKE)) || (oldkeys & KEY_FIRE) && (newkeys & KEY_CROUCH) && !((newkeys & KEY_FIRE) || (newkeys & KEY_HANDBRAKE)) )
	{
        switch(GetPlayerWeapon(playerid))
		{
		    case 23..25, 27, 29..34, 41:
			{
		        if(playerData[playerid][Ammo][GetPlayerWeapon(playerid)] > GetPlayerAmmo(playerid))
				{
					OnPlayerCBug(playerid);
				}
			}
		}
	}

	if(playerData[playerid][CheckCrouch] == 1)
	{
		switch(playerData[playerid][WeaponID])
		{
		    case 23, 24, 27, 29..34, 41: {
		    	if((newkeys & KEY_CROUCH) && !((newkeys & KEY_FIRE) || (newkeys & KEY_HANDBRAKE)) && GetPlayerSpecialAction(playerid) != SPECIAL_ACTION_DUCK ) {
		    		if(playerData[playerid][Ammo][GetPlayerWeapon(playerid)] > GetPlayerAmmo(playerid)) {
						OnPlayerCBug(playerid);
					}
		    	}
		    }
		}
	}

	else if(((newkeys & KEY_FIRE) && (newkeys & KEY_HANDBRAKE) && !((newkeys & KEY_SPRINT) || (newkeys & KEY_JUMP))) ||
	(newkeys & KEY_FIRE) && !((newkeys & KEY_SPRINT) || (newkeys & KEY_JUMP)) ||
	(playerData[playerid][NotMoving] && (newkeys & KEY_FIRE) && (newkeys & KEY_HANDBRAKE)) ||
	(playerData[playerid][NotMoving] && (newkeys & KEY_FIRE)) ||
	(newkeys & KEY_FIRE) && (oldkeys & KEY_CROUCH) && !((oldkeys & KEY_FIRE) || (newkeys & KEY_HANDBRAKE)) ||
	(oldkeys & KEY_FIRE) && (newkeys & KEY_CROUCH) && !((newkeys & KEY_FIRE) || (newkeys & KEY_HANDBRAKE)) )
	{
		SetTimerEx("CrouchCheck", 3000, 0, "d", playerid);
		playerData[playerid][CheckCrouch] = 1;
		playerData[playerid][WeaponID] = GetPlayerWeapon(playerid);
		playerData[playerid][Ammo][GetPlayerWeapon(playerid)] = GetPlayerAmmo(playerid);
	}

	return 1;
}

forward OnPlayerCBug(playerid);
public OnPlayerCBug(playerid)
{
	if (serverInfo[cbAnticheat])
	{
		if(!playerData[playerid][playerBeenBanned])
		{
			playerData[playerid][CheckCrouch] = 0;

			if (playerData[playerid][cbugWarnings] < 5)
			{
				playerData[playerid][cbugWarnings]++;
			}
			else
			{
				ResetPlayerWeapons(playerid);
				SendClientMessage(playerid, COLOR_WHITE, "{FFAB4A}[WARNING] {FFFFFF}c-bugging is not allowed on this server. Your weapons have been reset.");
				playerData[playerid][cbugWarnings] = 0;
			}

			if (playerData[playerid][cbugWarnings] == 1 || playerData[playerid][cbugWarnings] == 3 || playerData[playerid][cbugWarnings] == 5)
			{
				SendClientMessage(playerid, COLOR_WHITE, "{FFAB4A}[WARNING] {FFFFFF}c-bugging is not allowed on this server. Your weapons will be reset if you continue.");
			}
		}
	}

	return 0;
}

forward CrouchCheck(playerid);
public CrouchCheck(playerid)
{
	playerData[playerid][CheckCrouch] = 0;

	return 1;
}

forward updateCbug(playerid);
public updateCbug(playerid)
{
	new Keys, ud, lr;
	GetPlayerKeys(playerid, Keys, ud, lr);
	if(playerData[playerid][CheckCrouch] == 1)
	{
		switch(playerData[playerid][WeaponID])
		{
		    case 23..25, 27, 29..34, 41:
			{
		    	if((Keys & KEY_CROUCH) && !((Keys & KEY_FIRE) || (Keys & KEY_HANDBRAKE)) && GetPlayerSpecialAction(playerid) != SPECIAL_ACTION_DUCK )
				{
		    		if(playerData[playerid][Ammo][GetPlayerWeapon(playerid)] > GetPlayerAmmo(playerid))
					{
						OnPlayerCBug(playerid);
					}
		    	}
		    }
		}
	}

	if(!ud && !lr) {
		playerData[playerid][NotMoving] = 1;
	}
	else
	{
		playerData[playerid][NotMoving] = 0;
	}

	return 1;
}

// Cleo

forward ac_CarSwing(playerid);
public ac_CarSwing(playerid)
{
	if (serverInfo[carAnticheat])
	{
		if (!playerData[playerid][playerBeenBanned])
		{
			if(!playerData[playerid][playerBeenBanned])
			{
				if (playerData[playerid][carSwing] != 2)
				{
					playerData[playerid][carSwing]++;

					new administratorAlert[200];
					format(administratorAlert, sizeof(administratorAlert), "{FFAB4A}[CHEAT-DETECTION] {FFFFFF}%s(%i) is suspected of car particle swinging.", playerData[playerid][playerNamee], playerid);
					adminchat(COLOR_WHITE, administratorAlert);
				}
				else
				{
					playerData[playerid][playerBeenBanned] = true;

					new administratorAlert[200];
					format(administratorAlert, sizeof(administratorAlert), "{FFAB4A}[CHEAT-DETECTION] {FFFFFF}%s(%i) has been kicked for car particle swinging.", playerData[playerid][playerNamee], playerid);
					adminchat(COLOR_WHITE, administratorAlert);

					KickWithMessage(playerid, "[KICKED] You have been kicked for vehicle hacks.");
				}
			}
		}
	}

	return 1;
}

forward ac_CarSpam(playerid);
public ac_CarSpam(playerid)
{
	if (serverInfo[carAnticheat])
	{
		if (!playerData[playerid][playerBeenBanned])
		{
			if(!playerData[playerid][playerBeenBanned])
			{
				if (playerData[playerid][carSwing] != 2)
				{
					playerData[playerid][carSwing]++;

					new administratorAlert[200];
					format(administratorAlert, sizeof(administratorAlert), "{FFAB4A}[CHEAT-DETECTION] {FFFFFF}%s(%i) is suspected of car particle spamming.", playerData[playerid][playerNamee], playerid);
					adminchat(COLOR_WHITE, administratorAlert);
				}
				else
				{
					playerData[playerid][playerBeenBanned] = true;

					new administratorAlert[200];
					format(administratorAlert, sizeof(administratorAlert), "{FFAB4A}[CHEAT-DETECTION] {FFFFFF}%s(%i) has been kicked for car particle spamming.", playerData[playerid][playerNamee], playerid);
					adminchat(COLOR_WHITE, administratorAlert);

					KickWithMessage(playerid, "[KICKED] You have been kicked for vehicle hacks.");
				}
			}
		}
	}

	return 1;
}

// Other

forward ac_Teleport(playerid);
public ac_Teleport(playerid)
{
	if(playerData[playerid][playerLevel] < 1)
	{
		if(!playerData[playerid][playerBeenBanned])
		{
			//playerData[playerid][playerBeenBanned] = true;

			new administratorAlert[200];
			format(administratorAlert, sizeof(administratorAlert), "{FFAB4A}[CHEAT-DETECTION] {FFFFFF}%s(%i) his suspected of teleporting.", playerData[playerid][playerNamee], playerid);
			adminchat(COLOR_WHITE, administratorAlert);
		}
	}

	return 1;
}

forward ac_FakeKill(playerid);
public ac_FakeKill(playerid)
{
	if(!playerData[playerid][playerBeenBanned])
	{
		//playerData[playerid][playerBeenBanned] = true;

		new administratorAlert[200];
		format(administratorAlert, sizeof(administratorAlert), "{FFAB4A}[CHEAT-DETECTION] {FFFFFF}%s(%i) his suspected of fake-killing.", playerData[playerid][playerNamee], playerid);
		adminchat(COLOR_WHITE, administratorAlert);
	}

	return 1;
}

forward ac_FlyHack(playerid);
public ac_FlyHack(playerid)
{
	if (serverInfo[flyAnticheat])
	{
		if(!playerData[playerid][playerBeenBanned])
		{
			new Float:animX, Float:animY, Float:animZ;
			new anim = GetPlayerAnimationIndex(playerid);
			GetPlayerPos(playerid, animX, animY, animZ);
			if((anim >= 1538) && (anim <= 1542) && animZ > 5)
			{
				playerData[playerid][playerBeenBanned] = true;

				new administratorAlert[200];
				format(administratorAlert, sizeof(administratorAlert), "{FFAB4A}[CHEAT-DETECTION] {FFFFFF}%s(%i) is suspected of flying.", playerData[playerid][playerNamee], playerid);
				adminchat(COLOR_WHITE, administratorAlert);

				KickWithMessage(playerid, "[KICKED] You have been kicked for fly hacks.");
			}
		}
	}

	return 1;
}
