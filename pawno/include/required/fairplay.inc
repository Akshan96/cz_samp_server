//----------------------------------------------------------------------------------------------------------------.
//																												 //
//	FairPlay 																					   Version 1.2	//
//																								   			   //
//------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
//																									        //
//	Credits																							       //
//	- Scripting: Ricky Phelps (SuperViper)																  //
//	- Testing: Chriham3/Alex Shock								 										 //
//																								        //
//-----------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------//
// ============================================ SETTINGS =========================================== //

/* Unfair play list (comment the line of anything you don't want to be detected) */
#define FP_HIGH_PING				(1)
#define FP_WEAPON_HACK				(2)
#define FP_VEHICLE_SPEED_HACK		(3)
#define FP_JETPACK_HACK				(4)
#define FP_DRIVER_DRIVEBY			(5) // Commenting this will ENABLE driver driveby
#define FP_DRIVEBY_WEAPONS_RESTRICT	(6)
#define FP_SWEARING					(7)
#define FP_FLY_HACK					(8)
#define FP_CHAT_SPAM				(9)
#define FP_AFK						(10)
#define FP_TABBING					(11)
#define FP_NINJA_JACK				(12)
#define FP_CAR_RAM					(13)
#define FP_HELIBLADE				(14)
#define FP_VEHICLE_MOD_HACK			(15)
#define FP_SERVER_AD				(16)
#define FP_FAKE_KILL				(17)
#define FP_TELEPORT_HACK			(18)

#if defined FP_MASTER
	/* This is the interval of the timer which checks for fair play */
	#define FP_TIMER_INTERVAL		(1250)

	/* The maximum ping allowed on the server (will be ignored if high ping detection is disabled) */
	#define FP_MAX_PING				(500)

	/* The weapons which are allowed for drivebys (separate with space - will be ignored if driveby weapons restriction is disabled) */
	#define FP_DRIVEBY_WEAPONS		"28 29 32"

	/* The IP address of your server (will be ignored if server advertisement detection is disabled) */
	#define FP_SERVER_IP			"127.0.0.1"

	/* The domain of your server (will be ignored if server advertisement detection is disabled) */
	#define FP_SERVER_DOMAIN		"samp.servername.com"

	/* Curse words (will be ignored if swearing detection is disabled) */
	new FP_CurseWords[][] =
	{
		"ass", "bitch", "cunt", "fuck", "nigga", "nigger", "shit", "whore"
	};
#endif

// ================================================================================================= //
// =============================== DO NOT TOUCH ANYTHING BELOW THIS =============================== //
// =============================================================================================== //

#define FAIRPLAY_INCLUDED

#if !defined sscanf
	#tryinclude <sscanf2>
#endif

forward public FP_Detection(playerid);
forward public OnPlayerUnfairPlay(playerid, playType);

forward public FP_ReduceChatCounter(playerid);
forward public FP_VehicleJackCheck(playerid);

forward public FP_OnPlayerConnect(playerid);
forward public FP_OnPlayerDisconnect(playerid, reason);
forward public FP_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
forward public FP_OnPlayerDeath(playerid, killerid, reason);
forward public FP_OnPlayerSpawn(playerid);
forward public FP_OnPlayerStateChange(playerid, newstate, oldstate);
forward public FP_OnPlayerText(playerid, text[]);
forward public FP_OnPlayerCommandText(playerid, cmdtext[]);
forward public FP_OnPlayerUpdate(playerid);
forward public FP_OnPlayerTakeDamage(playerid, issuerid, Float: amount, weaponid);
forward public FP_OnVehicleMod(playerid, vehicleid, componentid);
forward public FP_OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);

new FP_WeaponSlots[47] =
{
	0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 10, 10,
	10, 10, 10, 10, 8, 8, 8, -1, -1, -1,
	2, 2, 2, 3, 3, 3, 4, 4, 5, 5, 4, 6,
	6, 7, 7, 7, 7, 8, 12, 9, 9, 9, 11,
	11, 11
};

#if defined FP_MASTER
	stock SetPlayerFairPlayImmune(playerid, immune)
	{
		return SetPVarInt(playerid, "FP_Immune", immune);
	}

	FP_GetVehicleSpeed(vehicleID)
	{
		new Float: vehiclesVelocity[3];
		GetVehicleVelocity(vehicleID, vehiclesVelocity[0], vehiclesVelocity[1], vehiclesVelocity[2]);
		return floatround(floatsqroot((vehiclesVelocity[0] * vehiclesVelocity[1] + vehiclesVelocity[2] * vehiclesVelocity[2])) * 100 * 1.6);
	}

	FP_GetHighestWaterLevel(playerid)
	{
		if(IsPlayerInRangeOfPoint(playerid, 50.0, 1962.15, -1198.71, 17.45)) return 19;
		if(IsPlayerInRangeOfPoint(playerid, 100.0, -1127.58, 2764.43, 40.00)) return 43;
		if(IsPlayerInRangeOfPoint(playerid, 100.0, -988.19, 2486.89, 40.00)) return 43;
		if(IsPlayerInRangeOfPoint(playerid, 100.0, -924.33, 2306.59, 40.00)) return 43;
		if(IsPlayerInRangeOfPoint(playerid, 100.0, -1104.15, 2175.83, 40.00)) return 43;
		if(IsPlayerInRangeOfPoint(playerid, 100.0, -1307.06, 2119.33, 40.00)) return 43;
		if(IsPlayerInRangeOfPoint(playerid, 100.0, -831.85, 2122.23, 40.00)) return 43;
		if(IsPlayerInRangeOfPoint(playerid, 100.0, -595.76, 2138.34, 40.00)) return 43;
		if(IsPlayerInRangeOfPoint(playerid, 100.0, -569.24, 2274.40, 40.00)) return 43;
		if(IsPlayerInRangeOfPoint(playerid, 12.0, 1095.800, -674.950, 111.908)) return 113;
	 	if(IsPlayerInRangeOfPoint(playerid, 12.0, 224.500, -1185.725, 73.908)) return 76;
	  	if(IsPlayerInRangeOfPoint(playerid, 12.0, 193.700, -1230.608, 76.603)) return 79;
	   	if(IsPlayerInRangeOfPoint(playerid, 12.0, 1277.500, -805.200, 86.581)) return 88;
	    if(IsPlayerInRangeOfPoint(playerid, 12.0, 2582.0, 2387.0, 16.0)) return 18;
		return 10;
	}

	public FP_Detection(playerid)
	{
		if(!GetPVarInt(playerid, "FP_Immune"))
		{
			new Float: playersPosition[3], playersState = GetPlayerState(playerid);
			GetPlayerPos(playerid, playersPosition[0], playersPosition[1], playersPosition[2]);

			#if defined FP_TELEPORT_HACK
				if(playersState == PLAYER_STATE_ONFOOT || playersState == PLAYER_STATE_DRIVER || playersState == PLAYER_STATE_PASSENGER || playersState == PLAYER_STATE_SPAWNED)
				{
					if(tickcount() - GetPVarInt(playerid, "FP_LastPositionSet") > FP_TIMER_INTERVAL * 5)
					{
						if(GetPVarFloat(playerid, "FP_LastPositionZ"))
						{
							if(!IsPlayerInAnyVehicle(playerid) && !GetPlayerInterior(playerid) && GetPlayerSurfingVehicleID(playerid) == INVALID_VEHICLE_ID)
							{
								if(!IsPlayerInRangeOfPoint(playerid, 100, GetPVarFloat(playerid, "FP_LastPositionX"), GetPVarFloat(playerid, "FP_LastPositionY"), GetPVarFloat(playerid, "FP_LastPositionZ")))
								{
									CallLocalFunction("OnPlayerUnfairPlay", "dd", playerid, FP_TELEPORT_HACK);
								}
							}
						}
					}
				}
			#endif

			if(playersPosition[0] != GetPVarFloat(playerid, "FP_LastPositionX") || playersPosition[1] != GetPVarFloat(playerid, "FP_LastPositionY") || playersPosition[2] != GetPVarFloat(playerid, "FP_LastPositionZ"))
			{
				SetPVarFloat(playerid, "FP_LastPositionX", playersPosition[0]), SetPVarFloat(playerid, "FP_LastPositionY", playersPosition[1]), SetPVarFloat(playerid, "FP_LastPositionZ", playersPosition[2]);
				SetPVarInt(playerid, "FP_LastUpdate", tickcount());
			}

			SetPVarInt(playerid, "FP_TabbedUpdates", GetPVarInt(playerid, "FP_TabbedUpdates") + 1);

			#if defined FP_HIGH_PING
				if(GetPlayerPing(playerid) >= FP_MAX_PING)
				{
					SetPVarInt(playerid, "FP_PingWarnings", GetPVarInt(playerid, "FP_PingWarnings") + 1);

					if(GetPVarInt(playerid, "FP_PingWarnings") >= 3)
					{
						SetPVarInt(playerid, "FP_PingWarnings", 0);
						CallLocalFunction("OnPlayerUnfairPlay", "dd", playerid, FP_HIGH_PING);
					}
				}
			#endif

			#if defined FP_VEHICLE_SPEED_HACK
				new playersVehicle = GetPlayerVehicleID(playerid);

				if(playersVehicle)
				{
					new playersSpeed = FP_GetVehicleSpeed(playersVehicle), vehicleModel = GetVehicleModel(playersVehicle);

					if((playersSpeed >= 550 && vehicleModel != 460 && vehicleModel != 476 && (vehicleModel < 511 || vehicleModel > 513) && vehicleModel != 519 && vehicleModel != 520 && vehicleModel != 553 && vehicleModel != 577 && vehicleModel != 592 && vehicleModel != 593) || (playersSpeed >= 200 && vehicleModel != 448 && (vehicleModel < 461 || vehicleModel > 463) && vehicleModel != 468 && (vehicleModel < 521 || vehicleModel > 523) && vehicleModel != 581 && vehicleModel != 586) || playersSpeed >= 1250)
					{
						CallLocalFunction("OnPlayerUnfairPlay", "dd", playerid, FP_VEHICLE_SPEED_HACK);
					}
				}
			#endif

			#if defined FP_JETPACK_HACK
				if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USEJETPACK)
				{
					if(!GetPVarInt(playerid, "FP_PlayerJetpack"))
					{
						CallLocalFunction("OnPlayerUnfairPlay", "dd", playerid, FP_JETPACK_HACK);
					}
				}
				else
				{
					SetPVarInt(playerid, "FP_PlayerJetpack", 0);
				}
			#endif

			#if defined FP_FLY_HACK
				new animationIndex = GetPlayerAnimationIndex(playerid);

				if(animationIndex >= 1538 && animationIndex <= 1544 && animationIndex != 1542 && !GetPlayerInterior(playerid))
				{
					if(playersPosition[2] >= FP_GetHighestWaterLevel(playerid))
					{
						CallLocalFunction("OnPlayerUnfairPlay", "dd", playerid, FP_FLY_HACK);
					}
				}
			#endif

			#if defined FP_AFK
				if(tickcount() - GetPVarInt(playerid, "FP_LastUpdate") >= 300000)
				{
					CallLocalFunction("OnPlayerUnfairPlay", "dd", playerid, FP_AFK);
				}
			#endif

			#if defined FP_TABBING
				if(GetPVarInt(playerid, "FP_TabbedUpdates") >= 3)
				{
					if(playersState == PLAYER_STATE_ONFOOT || playersState == PLAYER_STATE_DRIVER || playersState == PLAYER_STATE_PASSENGER || playersState == PLAYER_STATE_SPAWNED)
					{
						CallLocalFunction("OnPlayerUnfairPlay", "dd", playerid, FP_TABBING);
					}
				}
			#endif
		}

		return 1;
	}

	public FP_ReduceChatCounter(playerid)
	{
		SetPVarInt(playerid, "FP_ChatCounter", GetPVarInt(playerid, "FP_ChatCounter") - 1);
		return 1;
	}

	public FP_VehicleJackCheck(playerid)
	{
		SetPVarInt(playerid, "FP_VehicleJacker", INVALID_PLAYER_ID);
		return 1;
	}

	public OnPlayerConnect(playerid)
	{
		for(new weaponIndex, variableName[20]; weaponIndex < 13; weaponIndex++)
		{
			format(variableName, sizeof(variableName), "FP_PlayerWeapon%d", weaponIndex);
			SetPVarInt(playerid, variableName, 0);
		}

		SetPVarInt(playerid, "FP_PingWarnings", 0);

		SetPVarInt(playerid, "FP_PlayerJetpack", 0);

		SetPVarInt(playerid, "FP_ChatCounter", 0);

		SetPVarInt(playerid, "FP_LastUpdate", tickcount());

		SetPVarInt(playerid, "FP_TabbedUpdates", 0);

		SetPVarInt(playerid, "FP_VehicleJacker", INVALID_PLAYER_ID);
		SetPVarInt(playerid, "FP_VehicleJackTimer", -1);

		SetPVarInt(playerid, "FP_PlayerAlive", 0);

		SetPVarInt(playerid, "FP_LastPositionSet", tickcount());

		SetPVarInt(playerid, "FP_PlayerDetectionTimer", SetTimerEx("FP_Detection", FP_TIMER_INTERVAL, true, "d", playerid));
		return (funcidx("FP_OnPlayerConnect") == -1) ? 1 : CallLocalFunction("FP_OnPlayerConnect", "d", playerid);
	}

	#if defined _ALS_OnPlayerConnect
		#undef OnPlayerConnect
	#else
		#define _ALS_OnPlayerConnect
	#endif

	#define OnPlayerConnect FP_OnPlayerConnect

	public OnPlayerDisconnect(playerid, reason)
	{
		KillTimer(GetPVarInt(playerid, "FP_PlayerDetectionTimer"));

		if(GetPVarInt(playerid, "FP_VehicleJackTimer") != -1)
		{
			KillTimer(GetPVarInt(playerid, "FP_VehicleJackTimer"));
		}

		return (funcidx("FP_OnPlayerDisconnect") == -1) ? 1 : CallLocalFunction("FP_OnPlayerDisconnect", "dd", playerid, reason);
	}

	#if defined _ALS_OnPlayerDisconnect
		#undef OnPlayerDisconnect
	#else
		#define _ALS_OnPlayerDisconnect
	#endif

	#define OnPlayerDisconnect FP_OnPlayerDisconnect

	public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
	{
		if(!GetPVarInt(playerid, "FP_Immune"))
		{
			#if defined FP_WEAPON_HACK
				if(newkeys & KEY_FIRE && !IsPlayerInAnyVehicle(playerid))
				{
					new playersWeapon = GetPlayerWeapon(playerid);

					if(playersWeapon && playersWeapon != 40 && playersWeapon != 46)
					{
						new variableName[20];
						format(variableName, sizeof(variableName), "FP_PlayerWeapon%d", FP_WeaponSlots[playersWeapon]);

						if(GetPVarInt(playerid, variableName) != playersWeapon)
						{
							CallLocalFunction("OnPlayerUnfairPlay", "dd", playerid, FP_WEAPON_HACK);
						}
					}
				}
			#endif
		}

		return (funcidx("FP_OnPlayerKeyStateChange") == -1) ? 1 : CallLocalFunction("FP_OnPlayerKeyStateChange", "ddd", playerid, newkeys, oldkeys);
	}

	#if defined _ALS_OnPlayerKeyStateChange
		#undef OnPlayerKeyStateChange
	#else
		#define _ALS_OnPlayerKeyStateChange
	#endif

	#define OnPlayerKeyStateChange FP_OnPlayerKeyStateChange

	public OnPlayerDeath(playerid, killerid, reason)
	{
		new playerAlive = GetPVarInt(playerid, "FP_PlayerAlive");

		switch(playerAlive)
		{
			case 0, 1:
			{
				SetPVarInt(playerid, "FP_PlayerAlive", (playerAlive) ? 0 : 2);
			}

			case 2:
			{
				CallLocalFunction("OnPlayerUnfairPlay", "dd", playerid, FP_FAKE_KILL);
			}
		}

		SetPVarInt(playerid, "FP_PlayerJetpack", 0);

		if(!GetPVarInt(playerid, "FP_Immune"))
		{
			#if defined FP_NINJA_JACK
				if(GetPVarInt(playerid, "FP_VehicleJacker") != INVALID_PLAYER_ID)
				{
					CallLocalFunction("OnPlayerUnfairPlay", "dd", GetPVarInt(playerid, "FP_VehicleJacker"), FP_NINJA_JACK);
				}
			#endif

			#if defined FP_FAKE_KILL
				if(killerid != INVALID_PLAYER_ID && !IsPlayerNPC(playerid) && !IsPlayerNPC(killerid))
				{
					new Float: playersHealth;
					GetPlayerHealth(playerid, playersHealth);

					if(playersHealth)
					{
						CallLocalFunction("OnPlayerUnfairPlay", "dd", playerid, FP_FAKE_KILL);
					}
				}
			#endif
		}

		SetPVarInt(playerid, "FP_LastPositionSet", tickcount());
		return (funcidx("FP_OnPlayerDeath") == -1) ? 1 : CallLocalFunction("FP_OnPlayerDeath", "ddd", playerid, killerid, reason);
	}

	#if defined _ALS_OnPlayerDeath
		#undef OnPlayerDeath
	#else
		#define _ALS_OnPlayerDeath
	#endif

	#define OnPlayerDeath FP_OnPlayerDeath

	public OnPlayerSpawn(playerid)
	{
		SetPVarInt(playerid, "FP_PlayerJetpack", 0);
		SetPVarInt(playerid, "FP_LastPositionSet", tickcount());
		SetPVarInt(playerid, "FP_PlayerAlive", 1);
		return (funcidx("FP_OnPlayerSpawn") == -1) ? 1 : CallLocalFunction("FP_OnPlayerSpawn", "d", playerid);
	}

	#if defined _ALS_OnPlayerSpawn
		#undef OnPlayerSpawn
	#else
		#define _ALS_OnPlayerSpawn
	#endif

	#define OnPlayerSpawn FP_OnPlayerSpawn

	public OnPlayerStateChange(playerid, newstate, oldstate)
	{
		if(!GetPVarInt(playerid, "FP_Immune"))
		{
			#if defined FP_DRIVER_DRIVEBY
				if(newstate == PLAYER_STATE_DRIVER)
				{
					SetPlayerArmedWeapon(playerid, 0);
				}
			#endif

			#if defined FP_DRIVEBY_WEAPONS_RESTRICT
				if(newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER)
				{
					new playersWeapon = GetPlayerWeapon(playerid), allowedWeapons[15], bool: playerValidWeapon;
					sscanf(FP_DRIVEBY_WEAPONS, "a<i>[15]", allowedWeapons);

					for(new weaponIndex; weaponIndex < sizeof(allowedWeapons); weaponIndex++)
					{
						if((allowedWeapons[weaponIndex] && playersWeapon == allowedWeapons[weaponIndex]) || !playersWeapon)
						{
							playerValidWeapon = true;
							break;
						}
					}

					if(!playerValidWeapon)
					{
						SetPlayerArmedWeapon(playerid, 0);
					}
				}
			#endif

			#if defined FP_NINJA_JACK
				if(newstate == PLAYER_STATE_DRIVER)
				{
					for(new playerIndex; playerIndex < MAX_PLAYERS; playerIndex++)
					{
						if(GetPVarInt(playerIndex, "FP_VehicleJacker") == playerid)
						{
							SetTimerEx("FP_VehicleJackCheck", 1000, 0, "i", playerIndex);

							KillTimer(GetPVarInt(playerIndex, "FP_VehicleJackTimer"));
							SetPVarInt(playerIndex, "FP_VehicleJackTimer", -1);
							break;
						}
					}
				}
			#endif
		}

		return (funcidx("FP_OnPlayerStateChange") == -1) ? 1 : CallLocalFunction("FP_OnPlayerStateChange", "ddd", playerid, newstate, oldstate);
	}

	#if defined _ALS_OnPlayerStateChange
		#undef OnPlayerStateChange
	#else
		#define _ALS_OnPlayerStateChange
	#endif

	#define OnPlayerStateChange FP_OnPlayerStateChange

	public OnPlayerText(playerid, text[])
	{
		if(!GetPVarInt(playerid, "FP_Immune"))
		{
			#if defined FP_SWEARING
				new wordLocation, bool: playerSwearing;

				for(new wordIndex; wordIndex < sizeof(FP_CurseWords); wordIndex++)
				{
					wordLocation = strfind(text, FP_CurseWords[wordIndex], true);

					while(wordLocation > -1)
					{
						playerSwearing = true;

						for(new textIndex = wordLocation; textIndex < wordLocation + strlen(FP_CurseWords[wordIndex]); textIndex++)
						{
							text[textIndex] = '*';
						}

						wordLocation = strfind(text, FP_CurseWords[wordIndex], true, wordLocation);
					}
				}

				if(playerSwearing)
				{
					CallLocalFunction("OnPlayerUnfairPlay", "dd", playerid, FP_SWEARING);
				}
			#endif

			#if defined FP_CHAT_SPAM
				SetPVarInt(playerid, "FP_ChatCounter", GetPVarInt(playerid, "FP_ChatCounter") + 1);

				if(GetPVarInt(playerid, "FP_ChatCounter") >= 4)
				{
					SetPVarInt(playerid, "FP_ChatCounter", 0);
					CallLocalFunction("OnPlayerUnfairPlay", "dd", playerid, FP_CHAT_SPAM);
				}
				else
				{
					SetTimerEx("FP_ReduceChatCounter", 850, 0, "d", playerid);
				}
			#endif

			#if defined FP_SERVER_AD
				new dotCount, colonCount, portCount;

				for(new stringIndex, stringLength = strlen(text); stringIndex < stringLength; stringIndex++)
				{
					if(text[stringIndex] == '.')
					{
						dotCount++;
					}
					else if(text[stringIndex] == ':')
					{
						colonCount++;
					}
					else if(stringIndex + 3 < stringLength)
					{
						if('0' <= text[stringIndex] <= '9' && '0' <= text[stringIndex + 1] <= '9' && '0' <= text[stringIndex + 2] <= '9' && '0' <= text[stringIndex + 3] <= '9')
						{
							portCount++;
						}
					}
				}

				if(dotCount >= 2 && (colonCount || portCount) && strfind(text, FP_SERVER_IP) == -1 && strfind(text, FP_SERVER_DOMAIN, true) == -1)
				{
					CallLocalFunction("OnPlayerUnfairPlay", "dd", playerid, FP_SERVER_AD);
					return 0;
				}
			#endif
		}

		SetPVarInt(playerid, "FP_LastUpdate", tickcount());
		return (funcidx("FP_OnPlayerText") == -1) ? 1 : CallLocalFunction("FP_OnPlayerText", "ds", playerid, text);
	}

	#if defined _ALS_OnPlayerText
		#undef OnPlayerText
	#else
		#define _ALS_OnPlayerText
	#endif

	#define OnPlayerText FP_OnPlayerText

	public OnPlayerCommandText(playerid, cmdtext[])
	{
		if(!GetPVarInt(playerid, "FP_Immune"))
		{
			#if defined FP_SWEARING
				new wordLocation, bool: playerSwearing;

				for(new wordIndex; wordIndex < sizeof(FP_CurseWords); wordIndex++)
				{
					wordLocation = strfind(cmdtext, FP_CurseWords[wordIndex], true);

					while(wordLocation > -1)
					{
						playerSwearing = true;

						for(new textIndex = wordLocation; textIndex < wordLocation + strlen(FP_CurseWords[wordIndex]); textIndex++)
						{
							cmdtext[textIndex] = '*';
						}

						wordLocation = strfind(cmdtext, FP_CurseWords[wordIndex], true, wordLocation);
					}
				}

				if(playerSwearing)
				{
					CallLocalFunction("OnPlayerUnfairPlay", "dd", playerid, FP_SWEARING);
				}
			#endif

			#if defined FP_CHAT_SPAM
				SetPVarInt(playerid, "FP_ChatCounter", GetPVarInt(playerid, "FP_ChatCounter") + 1);

				if(GetPVarInt(playerid, "FP_ChatCounter") >= 4)
				{
					SetPVarInt(playerid, "FP_ChatCounter", 0);
					CallLocalFunction("OnPlayerUnfairPlay", "dd", playerid, FP_CHAT_SPAM);
				}
				else
				{
					SetTimerEx("FP_ReduceChatCounter", 850, 0, "d", playerid);
				}
			#endif

			#if defined FP_SERVER_AD
				new dotCount, colonCount, portCount;

				for(new stringIndex, stringLength = strlen(cmdtext); stringIndex < stringLength; stringIndex++)
				{
					if(cmdtext[stringIndex] == '.')
					{
						dotCount++;
					}
					else if(cmdtext[stringIndex] == ':')
					{
						colonCount++;
					}
					else if(stringIndex + 3 < stringLength)
					{
						if('0' <= cmdtext[stringIndex] <= '9' && '0' <= cmdtext[stringIndex + 1] <= '9' && '0' <= cmdtext[stringIndex + 2] <= '9' && '0' <= cmdtext[stringIndex + 3] <= '9')
						{
							portCount++;
						}
					}
				}

				if(dotCount >= 2 && (colonCount || portCount) && strfind(cmdtext, FP_SERVER_IP) == -1 && strfind(cmdtext, FP_SERVER_DOMAIN, true) == -1)
				{
					CallLocalFunction("OnPlayerUnfairPlay", "dd", playerid, FP_SERVER_AD);
					return 0;
				}
			#endif
		}

		SetPVarInt(playerid, "FP_LastUpdate", tickcount());
		return (funcidx("FP_OnPlayerCommandText") == -1) ? 1 : CallLocalFunction("FP_OnPlayerCommandText", "ds", playerid, cmdtext);
	}

	#if defined _ALS_OnPlayerCommandText
		#undef OnPlayerCommandText
	#else
		#define _ALS_OnPlayerCommandText
	#endif

	#define OnPlayerCommandText FP_OnPlayerCommandText

	public OnPlayerUpdate(playerid)
	{
		SetPVarInt(playerid, "FP_TabbedUpdates", 0);
		return (funcidx("FP_OnPlayerUpdate") == -1) ? 1 : CallLocalFunction("FP_OnPlayerUpdate", "d", playerid);
	}

	#if defined _ALS_OnPlayerUpdate
		#undef OnPlayerUpdate
	#else
		#define _ALS_OnPlayerUpdate
	#endif

	#define OnPlayerUpdate FP_OnPlayerUpdate

	public OnPlayerTakeDamage(playerid, issuerid, Float: amount, weaponid)
	{
		if(!GetPVarInt(issuerid, "FP_Immune"))
		{
			#if defined FP_CAR_RAM
				if(weaponid == 49)
				{
					CallLocalFunction("OnPlayerUnfairPlay", "dd", issuerid, FP_CAR_RAM);
				}
			#endif

			#if defined FP_HELIBLADE
				if(weaponid == 50)
				{
					CallLocalFunction("OnPlayerUnfairPlay", "dd", issuerid, FP_HELIBLADE);
				}
			#endif
		}

		return (funcidx("FP_OnPlayerTakeDamage") == -1) ? 1 : CallLocalFunction("FP_OnPlayerTakeDamage", "ddfd", playerid, issuerid, amount, weaponid);
	}

	#if defined _ALS_OnPlayerTakeDamage
		#undef OnPlayerTakeDamage
	#else
		#define _ALS_OnPlayerTakeDamage
	#endif

	#define OnPlayerTakeDamage FP_OnPlayerTakeDamage

	public OnVehicleMod(playerid, vehicleid, componentid)
	{
		if(!GetPVarInt(playerid, "FP_Immune"))
		{
			#if defined FP_VEHICLE_MOD_HACK
				if(!GetPlayerInterior(playerid))
				{
					CallLocalFunction("OnPlayerUnfairPlay", "dd", playerid, FP_VEHICLE_MOD_HACK);
					return 0;
				}
			#endif
		}

		return (funcidx("FP_OnVehicleMod") == -1) ? 1 : CallLocalFunction("FP_OnVehicleMod", "ddd", playerid, vehicleid, componentid);
	}

	#if defined _ALS_OnVehicleMod
		#undef OnVehicleMod
	#else
		#define _ALS_OnVehicleMod
	#endif

	#define OnVehicleMod FP_OnVehicleMod

	public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
	{
		if(!GetPVarInt(playerid, "FP_Immune"))
		{
			#if defined FP_NINJA_JACK
				if(!ispassenger)
				{
					for(new playerIndex; playerIndex < MAX_PLAYERS; playerIndex++)
					{
						if(IsPlayerInVehicle(playerIndex, vehicleid) && !GetPlayerVehicleSeat(playerIndex))
						{
							SetPVarInt(playerIndex, "FP_VehicleJacker", playerid);
							SetPVarInt(playerIndex, "FP_VehicleJackTimer", SetTimerEx("FP_VehicleJackCheck", 10000, 0, "d", playerIndex));
							break;
						}
					}
				}
			#endif
		}

		return (funcidx("FP_OnPlayerEnterVehicle") == -1) ? 1 : CallLocalFunction("FP_OnPlayerEnterVehicle", "ddd", playerid, vehicleid, ispassenger);
	}

	#if defined _ALS_OnPlayerEnterVehicle
		#undef OnPlayerEnterVehicle
	#else
		#define _ALS_OnPlayerEnterVehicle
	#endif

	#define OnPlayerEnterVehicle FP_OnPlayerEnterVehicle
#endif

stock FP_GivePlayerWeapon(playerid, weaponid, ammo)
{
	new variableName[20];
	format(variableName, sizeof(variableName), "FP_PlayerWeapon%d", FP_WeaponSlots[weaponid]);
	SetPVarInt(playerid, variableName, weaponid);
	return GivePlayerWeapon(playerid, weaponid, ammo);
}

#if defined _ALS_GivePlayerWeapon
	#undef GivePlayerWeapon
#else
	#define _ALS_GivePlayerWeapon
#endif

#define GivePlayerWeapon FP_GivePlayerWeapon

stock FP_ResetPlayerWeapons(playerid)
{
	for(new weaponIndex, variableName[20]; weaponIndex < 13; weaponIndex++)
	{
		format(variableName, sizeof(variableName), "FP_PlayerWeapon%d", weaponIndex);
		SetPVarInt(playerid, variableName, 0);
	}

	return ResetPlayerWeapons(playerid);
}

#if defined _ALS_ResetPlayerWeapons
	#undef ResetPlayerWeapons
#else
	#define _ALS_ResetPlayerWeapons
#endif

#define ResetPlayerWeapons FP_ResetPlayerWeapons

stock FP_SetPlayerAmmo(playerid, weapon, ammo)
{
	if(!ammo)
	{
		new variableName[20];
		format(variableName, sizeof(variableName), "FP_PlayerWeapon%d", FP_WeaponSlots[weapon]);
		SetPVarInt(playerid, variableName, 0);
	}

	return SetPlayerAmmo(playerid, weapon, ammo);
}

#if defined _ALS_SetPlayerAmmo
	#undef SetPlayerAmmo
#else
	#define _ALS_SetPlayerAmmo
#endif

#define SetPlayerAmmo FP_SetPlayerAmmo

stock FP_SetPlayerSpecialAction(playerid, actionid)
{
	if(actionid == SPECIAL_ACTION_USEJETPACK)
	{
		SetPVarInt(playerid, "FP_PlayerJetpack", 1);
	}
	else if(actionid == SPECIAL_ACTION_NONE)
	{
		SetPVarInt(playerid, "FP_PlayerJetpack", 0);
	}

	return SetPlayerSpecialAction(playerid, actionid);
}

#if defined _ALS_SetPlayerSpecialAction
	#undef SetPlayerSpecialAction
#else
	#define _ALS_SetPlayerSpecialAction
#endif

#define SetPlayerSpecialAction FP_SetPlayerSpecialAction

stock FP_SetPlayerPos(playerid, Float: x, Float: y, Float: z)
{
	SetPVarInt(playerid, "FP_LastPositionSet", tickcount());
	return SetPlayerPos(playerid, x, y, z);
}

#if defined _ALS_SetPlayerPos
	#undef SetPlayerPos
#else
	#define _ALS_SetPlayerPos
#endif

#define SetPlayerPos FP_SetPlayerPos

stock FP_SetPlayerPosFindZ(playerid, Float: x, Float: y, Float: z)
{
	SetPVarInt(playerid, "FP_LastPositionSet", tickcount());
	return SetPlayerPosFindZ(playerid, x, y, z);
}

#if defined _ALS_SetPlayerPosFindZ
	#undef SetPlayerPosFindZ
#else
	#define _ALS_SetPlayerPosFindZ
#endif

#define SetPlayerPosFindZ FP_SetPlayerPosFindZ

stock FP_SetPlayerVelocity(playerid, Float: x, Float: y, Float: z)
{
	SetPVarInt(playerid, "FP_LastPositionSet", tickcount());
	return SetPlayerVelocity(playerid, x, y, z);
}

#if defined _ALS_SetPlayerVelocity
	#undef SetPlayerVelocity
#else
	#define _ALS_SetPlayerVelocity
#endif

#define SetPlayerVelocity FP_SetPlayerVelocity