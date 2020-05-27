#define MYSQL_RESULT_LOGIN		 1
#define MYSQL_RESULT_REGISTER 	 2
#define MYSQL_RESULT_CHECK		 3
#define MYSQL_IMPORT_DATA		 4
#define MYSQL_SAVE_DATA		 	 5
#define MYSQL_QUERY_BANNED		 6
#define MYSQL_ADD_BAN			 7
#define MYSQL_REMOVE_BAN		 8
#define MYSQL_TOP_KILLER		 9
forward savePlayerStats(spareid);
public savePlayerStats(spareid)
{
	new
		statSave[2000]
	;

	format(statSave, sizeof(statSave), "%s playerScore=%d,", statSave, playerData[spareid][playerScore]);
	format(statSave, sizeof(statSave), "%s playerXP=%d,", statSave, playerData[spareid][playerXP]);
	format(statSave, sizeof(statSave), "%s playerMoney=%d,", statSave, playerData[spareid][playerMoney]);
	format(statSave, sizeof(statSave), "%s playerLevel=%d,", statSave, playerData[spareid][playerLevel]);
	format(statSave, sizeof(statSave), "%s playerKills=%d,", statSave, playerData[spareid][playerKills]);
	format(statSave, sizeof(statSave), "%s playerDeaths=%d,", statSave, playerData[spareid][playerDeaths]);
	format(statSave, sizeof(statSave), "%s playerRobberies=%d,", statSave, playerData[spareid][playerRobberies]);
	format(statSave, sizeof(statSave), "%s playerJailTime=%d,", statSave, playerData[spareid][playerJailTime]);
	format(statSave, sizeof(statSave), "%s playerTimesJailed=%d,", statSave, playerData[spareid][playerTimesJailed]);
	format(statSave, sizeof(statSave), "%s playerWantedLevel=%d,", statSave, playerData[spareid][playerWantedLevel]);
	format(statSave, sizeof(statSave), "%s playerVIP=%d,", statSave, playerData[spareid][playerVIPLevel]);
	format(statSave, sizeof(statSave), "%s playerMuteTime=%d,", statSave, playerData[spareid][playerMuteTime]);
	format(statSave, sizeof(statSave), "%s playerJob=%d,", statSave, playerData[spareid][playerJob]);
	format(statSave, sizeof(statSave), "%s playerCopBanned=%d,", statSave, playerData[spareid][playerCopBanned]);
	format(statSave, sizeof(statSave), "%s playerArmyBanned=%d,", statSave, playerData[spareid][playerArmyBanned]);
	format(statSave, sizeof(statSave), "%s playerFightStyle=%d,", statSave, playerData[spareid][playerFightStyle]);
	format(statSave, sizeof(statSave), "%s playerHitValue=%d,", statSave, playerData[spareid][playerHitValue]);
	format(statSave, sizeof(statSave), "%s playerAdminJailed=%d,", statSave, playerData[spareid][playerAdminJailed]);
	format(statSave, sizeof(statSave), "%s playerBank=%d,", statSave, playerData[spareid][playerBank]);
	format(statSave, sizeof(statSave), "%s copTutorial=%d,", statSave, playerData[spareid][playerCopTutorial]);
	format(statSave, sizeof(statSave), "%s lastLogged=%d,", statSave, playerData[spareid][playerLastLogged]);
	format(statSave, sizeof(statSave), "%s playerHelper=%d,", statSave, playerData[spareid][playerHelper]);
	format(statSave, sizeof(statSave), "%s playerWeed=%d,", statSave, playerData[spareid][playerWeed]);
	format(statSave, sizeof(statSave), "%s vipExpires=%d,", statSave, playerData[spareid][vipExpires]);
	format(statSave, sizeof(statSave), "%s statTrucks=%d,", statSave, playerData[spareid][truckStat]);
	format(statSave, sizeof(statSave), "%s vipWeapon=%d,", statSave, playerData[spareid][vipWeapon]);

	format(statSave, sizeof(statSave), "%s forkliftCompleted=%d,", statSave, playerData[spareid][forkliftCompleted]);
	format(statSave, sizeof(statSave), "%s arrestStat=%d,", statSave, playerData[spareid][copArrests]);
	format(statSave, sizeof(statSave), "%s copDetains=%d,", statSave, playerData[spareid][copDetains]);
	format(statSave, sizeof(statSave), "%s copKills=%d,", statSave, playerData[spareid][copKills]);
	format(statSave, sizeof(statSave), "%s moneybagStat=%d,", statSave, playerData[spareid][moneyBags]);
	format(statSave, sizeof(statSave), "%s rules_read=%d,", statSave, playerData[spareid][rulesRead]);
	format(statSave, sizeof(statSave), "%s spawnHouse=%d,", statSave, playerData[spareid][spawnHouse]);
	format(statSave, sizeof(statSave), "%s streetRobberies=%d,", statSave, playerData[spareid][streetRobberies]);
	format(statSave, sizeof(statSave), "%s streetRapes=%d,", statSave, playerData[spareid][streetRapes]);
	format(statSave, sizeof(statSave), "%s playersTied=%d,", statSave, playerData[spareid][playersTied]);
	format(statSave, sizeof(statSave), "%s playersKidnapped=%d,", statSave, playerData[spareid][playersKidnapped]);
	format(statSave, sizeof(statSave), "%s playerRope=%d,", statSave, playerData[spareid][playerRope]);
	format(statSave, sizeof(statSave), "%s playerBobbyPins=%d,", statSave, playerData[spareid][playerBobbyPins]);
	format(statSave, sizeof(statSave), "%s playerScissors=%d,", statSave, playerData[spareid][playerScissors]);
	format(statSave, sizeof(statSave), "%s playerExplosives=%d,", statSave, playerData[spareid][playerExplosives]);
	format(statSave, sizeof(statSave), "%s bankRobs=%d,", statSave, playerData[spareid][bankRobs]);
	format(statSave, sizeof(statSave), "%s busCompleted=%d,", statSave, playerData[spareid][busCompleted]);
	format(statSave, sizeof(statSave), "%s sweepCompleted=%d,", statSave, playerData[spareid][sweepCompleted]);
	format(statSave, sizeof(statSave), "%s dm_kills=%d,", statSave, playerData[spareid][dmKills]);
	format(statSave, sizeof(statSave), "%s dm_deaths=%d,", statSave, playerData[spareid][dmDeaths]);
	format(statSave, sizeof(statSave), "%s cookies=%d,", statSave, playerData[spareid][cookies]);
	format(statSave, sizeof(statSave), "%s backpack=%d,", statSave, playerData[spareid][playerBackpack]);

	format(statSave, sizeof(statSave), "%s innocentKills=%d,", statSave, playerData[spareid][innocentKills]);
	format(statSave, sizeof(statSave), "%s aInnocentKills=%d,", statSave, playerData[spareid][aInnocentKills]);
	format(statSave, sizeof(statSave), "%s customSkin=%d,", statSave, playerData[spareid][playerCustomSkin]);

	format(statSave, sizeof(statSave), "%s playerIP='%s',", statSave, playerData[spareid][playerIP]);

	format(statSave, sizeof(statSave), "%s bombsDefused='%d',", statSave, playerData[spareid][bombsDefused]);
	format(statSave, sizeof(statSave), "%s town='%d',", statSave, playerData[spareid][playerTown]);
	format(statSave, sizeof(statSave), "%s weaponSkill='%d',", statSave, playerData[spareid][weaponSkill]);
	new z = 0;
	for(new x = 0; x < MAX_OSLOTS; x++)
	{
		if(playerData[spareid][toyStatus][x])
		{
			format(statSave, sizeof(statSave), "%s `toy%d` = '%d;%d;%f;%f;%f;%f;%f;%f;%f;%f;%f',", statSave, z, playerData[spareid][toyID][x], playerData[spareid][toyBone][x], playerData[spareid][toyPosX][x], playerData[spareid][toyPosY][x], playerData[spareid][toyPosZ][x], playerData[spareid][toyRotX][x], playerData[spareid][toyRotY][x], playerData[spareid][toyRotZ][x], playerData[spareid][toyScaleX][x], playerData[spareid][toyScaleY][x], playerData[spareid][toyScaleZ][x]);
		}
		else
		{
			format(statSave, sizeof(statSave), "%s `toy%d` = '-1',", statSave, z);
		}
		z++;
	}
	format(statSave, sizeof(statSave), "%s rTokens='%d'", statSave, playerData[spareid][rTokens]);

	new query[3000];
	format(query, sizeof(query), "UPDATE playerdata SET %s WHERE playerName='%s'", statSave, playerData[spareid][playerNamee]);
	mysql_query(query, MYSQL_SAVE_DATA, spareid, connection);
}

public OnMysqlQuery(resultid, spareid, MySQL:handle)
{
	switch (resultid)
	{
		case MYSQL_RESULT_LOGIN:
		{
			mysql_store_result();
			new
				rows = mysql_num_rows(),
				query[300],
				playerName[24]
			;

            if(rows > 0)
			{
				/*
					format(query, sizeof(query), "SELECT * FROM `playerdata` WHERE `playerName` = '%s'", playerName);
					mysql_query(query);
					mysql_store_result();
					mysql_fetch_row(row, "|");
					explode(row, field, "|");
					mysql_free_result();
				*/

				GetPlayerName(spareid, playerName, 24);
				format(query, sizeof(query), "SELECT * FROM `playerdata` WHERE playerName = '%s' LIMIT 0,1", playerName);
				mysql_query(query, MYSQL_IMPORT_DATA, spareid, connection);
			}
			else
			{
                ShowPlayerDialog(spareid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Login {58D3F7}Incorrect password entered.{FFFFFF}", "{FFFFFF}Your username is registered. Please login with your password below.", "Login", "Cancel");
            }

            mysql_free_result();
		}

		case MYSQL_IMPORT_DATA:
		{
			new
				row[1000],
				field[67][125],
				myIPAddress[16],
				password[56]
			;

			mysql_store_result();
			mysql_fetch_row(row, "|", connection);
			explode(row, field, "|");

			new Seconds = gettime();
			format(playerData[spareid][playerNamee], 24, "%s", field[0]);
			format(playerData[spareid][tempAdminName], 24, "%s", field[0]);
			format(password, sizeof(password), "%s", field[1]);
			GetPlayerIp(spareid, myIPAddress, sizeof(myIPAddress));

			playerData[spareid][playerScore] 			= strval(field[2]);
			playerData[spareid][playerMoney]			= strval(field[3]);
			playerData[spareid][playerIP]				= myIPAddress;
			playerData[spareid][playerLevel]			= strval(field[5]);
			playerData[spareid][playerKills]			= strval(field[6]);
			playerData[spareid][playerDeaths]			= strval(field[7]);
			playerData[spareid][playerRobberies]		= strval(field[8]);
			playerData[spareid][playerJailTime] 		= strval(field[9]);
			playerData[spareid][playerTimesJailed]		= strval(field[10]);
			playerData[spareid][playerWantedLevel]		= strval(field[11]);
			playerData[spareid][playerVIPLevel]			= strval(field[12]);
			playerData[spareid][playerMuteTime]			= strval(field[13]);
			playerData[spareid][playerXP]	 	    	= strval(field[14]);
			playerData[spareid][playerJob]				= strval(field[15]);
			playerData[spareid][playerCopBanned]		= strval(field[16]);
			playerData[spareid][playerArmyBanned]		= strval(field[17]);
			playerData[spareid][playerFightStyle]		= strval(field[18]);
			playerData[spareid][actualID]				= strval(field[19]);
			playerData[spareid][playerHitValue]			= strval(field[20]);
			playerData[spareid][playerAdminJailed]		= strval(field[21]);
			playerData[spareid][playerBank]				= strval(field[22]);
			playerData[spareid][playerCopTutorial]		= strval(field[23]);
			playerData[spareid][playerHelper]			= strval(field[25]);
			playerData[spareid][playerWeed]				= strval(field[26]);
			playerData[spareid][vipExpires]				= strval(field[28]);
			playerData[spareid][truckStat]				= strval(field[29]);
			playerData[spareid][vipWeapon]				= strval(field[30]);
			playerData[spareid][copArrests]				= strval(field[31]);
			playerData[spareid][moneyBags] 				= strval(field[32]);
			playerData[spareid][rulesRead] 				= strval(field[33]);
			playerData[spareid][spawnHouse] 			= strval(field[34]);
			playerData[spareid][hitsCompleted] 			= strval(field[35]);
			playerData[spareid][streetRobberies] 		= strval(field[36]);
			playerData[spareid][streetRapes] 			= strval(field[37]);
			playerData[spareid][playersTied] 			= strval(field[38]);
			playerData[spareid][playersKidnapped] 		= strval(field[39]);
			playerData[spareid][copDetains]				= strval(field[40]);
			playerData[spareid][copKills]				= strval(field[41]);
			playerData[spareid][playerRope]				= strval(field[42]);
			playerData[spareid][playerBobbyPins]		= strval(field[43]);
			playerData[spareid][playerScissors]			= strval(field[44]);
			playerData[spareid][playerExplosives]		= strval(field[45]);
			playerData[spareid][forkliftCompleted]		= strval(field[46]);
			playerData[spareid][bankRobs]				= strval(field[47]);
			playerData[spareid][innocentKills]			= strval(field[48]);
			playerData[spareid][aInnocentKills]			= strval(field[49]);
			playerData[spareid][playerCustomSkin]		= strval(field[50]);
			playerData[spareid][busCompleted]			= strval(field[51]);
			playerData[spareid][dmKills]				= strval(field[52]);
			playerData[spareid][dmDeaths]				= strval(field[53]);
			playerData[spareid][cookies]				= strval(field[54]);
			playerData[spareid][playerBackpack]			= strval(field[55]);
			playerData[spareid][sweepCompleted]			= strval(field[56]);
			playerData[spareid][weaponSkill]			= strval(field[57]);
			playerData[spareid][bombsDefused]			= strval(field[58]);
			playerData[spareid][rTokens]				= strval(field[59]);
			playerData[spareid][playerTown]				= strval(field[66]);
			new fieldnya = 60, tempString[256], modelid, boneid, Float:fOffsetX, Float:fOffsetY, Float:fOffsetZ,Float:fRotX, Float:fRotY, Float:fRotZ,Float:fScaleX, Float:fScaleY, Float:fScaleZ;
			for(new index = 0; index < MAX_OSLOTS; index++)
			{
				format(tempString, 256, "%s", field[fieldnya]);
				if(sscanf(tempString, "p<;>ddfffffffff", modelid, boneid,fOffsetX, fOffsetY, fOffsetZ,fRotX, fRotY, fRotZ,fScaleX, fScaleY, fScaleZ))
					playerData[spareid][toyStatus][index] = false;
				else
				{
					playerData[spareid][toyID][index] = modelid;
					playerData[spareid][toyBone][index] = boneid;
					playerData[spareid][toyPosX][index] = fOffsetX;
					playerData[spareid][toyPosY][index] = fOffsetY;
					playerData[spareid][toyPosZ][index] = fOffsetZ;
					playerData[spareid][toyRotX][index] = fRotX;
					playerData[spareid][toyRotY][index] = fRotY;
					playerData[spareid][toyRotZ][index] = fRotZ;
					playerData[spareid][toyScaleX][index] = fScaleX;
					playerData[spareid][toyScaleY][index] = fScaleY;
					playerData[spareid][toyScaleZ][index] = fScaleZ;
					playerData[spareid][toyStatus][index] = true;
				}
				fieldnya++;
			}

			playerData[spareid][playerLastTicket] 		= -1;
			playerData[spareid][lastCarDrop] 			= -1;
			playerData[spareid][lastRecipient]          = -1;
			playerData[spareid][playerGunOffer] 		= -1;
			playerData[spareid][playerHousePass]        = -1;
			playerData[spareid][playerVehicleLocating]  = -1;

			playerData[spareid][messageCount]			= 0;
			playerData[spareid][spamCount]				= 0;
			playerData[spareid][medicStatus]			= 0;
			playerData[spareid][cbugWarnings]			= 0;
			playerData[spareid][shot]					= 0;
			playerData[spareid][carSwing]				= 0;

			playerData[spareid][playerGangID]			= INVALID_GANG_ID;
			playerData[spareid][playerCheckpointTime]   = GetTickCount();
			playerData[spareid][playerLastLogged]		= Seconds;
			playerData[spareid][playerLoggedIn] 		= true;
			playerData[spareid][canWeed] 				= true;
			playerData[spareid][playerCanSaveStats] 	= true;
			playerData[spareid][canAsk] 				= true;
			playerData[spareid][canReport] 				= true;
			playerData[spareid][isInDM]					= false;
			playerData[spareid][isInFallout]			= false;
			playerData[spareid][useAdminName]			= false;
			playerData[spareid][vSellTo]				= -1;
			playerData[spareid][vBuyFrom]				= -1;

			SetPlayerFightingStyle(spareid, playerData[spareid][playerFightStyle]);
			GivePlayerMoney(spareid, playerData[spareid][playerMoney]);
			SetPlayerScore(spareid, playerData[spareid][playerScore]);
			SetPlayerWantedLevel(spareid, playerData[spareid][playerWantedLevel]);

			/*
			   VIP Info
			*/

			if (playerData[spareid][playerVIPLevel] >= 1)
			{
				// Check expiry date
				if (Seconds > playerData[spareid][vipExpires])
				{
					// VIP has expired
					SendClientMessage(spareid, COLOR_WHITE, "{58D3F7}[VIP EXPIRED] {FFFFFF}Your VIP membership has now expired.");
					playerData[spareid][playerVIPLevel] = 0;
				}
			}

			// Spectate
			if (playerData[spareid][playerLevel] >= 5)
			{
				playerData[spareid][allowSpec] = false;
			}
			else
			{
				playerData[spareid][allowSpec] = true;
			}

			if (playerData[spareid][playerLevel] > 0)
			{
				//svCheats_SetPlayerSecurityLevel(spareid, 1);
			}

			TextDrawHideForPlayer(spareid, loginDialog[0]);
			TextDrawHideForPlayer(spareid, loginDialog[1]);
			TextDrawHideForPlayer(spareid, loginDialog[2]);
			TextDrawHideForPlayer(spareid, loginDialog[3]);
			TextDrawHideForPlayer(spareid, loginDialog[4]);
			TextDrawHideForPlayer(spareid, loginDialog[5]);

			LoginTextDraws(spareid);
			updateExperienceCounter(spareid);

			TogglePlayerSpectating(spareid, false);

			// Progress bars
			playerData[spareid][robbery] = CreateProgressBar(248.00, 209.00, 141.50, 13.20, 0xFAAC58FF, 100.0);

			// Vehicles
			Vehicle_SpawnPlayerVehicle(spareid, playerData[spareid][actualID]);
			mysql_free_result();
		}

		case MYSQL_SAVE_DATA:
		{

			// Save player statistics
		}

		case MYSQL_RESULT_CHECK:
		{
			mysql_store_result();
			new
				rows = mysql_num_rows(),
				loginMessage[200],
				registerMessage[200],
				playerName[24]
			;

			GetPlayerName(spareid, playerName, 24);

			/*TextDrawShowForPlayer(spareid, loginDialog[0]);
			TextDrawShowForPlayer(spareid, loginDialog[1]);
			TextDrawShowForPlayer(spareid, loginDialog[2]);
			TextDrawShowForPlayer(spareid, loginDialog[3]);
			TextDrawShowForPlayer(spareid, loginDialog[4]);
			TextDrawShowForPlayer(spareid, loginDialog[5]);*/

			InterpolateCameraPos(spareid, -1469.4580, 874.2636, 73.0779, -2284.2354, 262.7178, 87.8268, 10000);
			InterpolateCameraPos(spareid, -1470.1146, 873.5102, 72.7629, -2284.8943, 261.9659, 87.5568, 12000);
			if(rows > 0)
			{
				format(loginMessage, sizeof(loginMessage), "{98B0CD}%s {FFFFFF}is a registered username, please login by entering your password below.", playerName);
				ShowPlayerDialog(spareid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Login", loginMessage, "Login", "Leave");
			}
			else
			{
				format(registerMessage, sizeof(registerMessage), "{98B0CD}%s {FFFFFF}is not a registered username, please create a password below.", playerName);
				ShowPlayerDialog(spareid, DIALOG_REGISTER, DIALOG_STYLE_INPUT, "Register", registerMessage, "Register", "Leave");
			}

			mysql_free_result();
		}

		case MYSQL_RESULT_REGISTER:
		{
			new
				Seconds = gettime(),
				myIPAddress[16]
			;

			GetPlayerIp(spareid, myIPAddress, sizeof(myIPAddress));

			SendClientMessage(spareid, COLOR_WHITE, "Welcome to San Fierro Cops and Robbers! To view a list of commands, type /commands");

			playerData[spareid][playerLevel] 			= 0;
			playerData[spareid][actualID] 				= -1;
			playerData[spareid][playerMoney]			= 0;
			playerData[spareid][playerScore]			= 0;
			playerData[spareid][playerIP]				= myIPAddress;
			playerData[spareid][playerStoreID]			= 0;
			playerData[spareid][playerCheckID]         	= 0;
			playerData[spareid][playerKills]			= 0;
			playerData[spareid][playerDeaths]			= 0;
			playerData[spareid][playerRobberies]		= 0;
			playerData[spareid][playerInterior]			= 0;
			playerData[spareid][playerVWorld]			= 0;
			playerData[spareid][playerJailTime] 		= 0;
			playerData[spareid][playerMuteTime] 		= 0;
			playerData[spareid][playerTimesJailed]		= 0;
			playerData[spareid][playerCheckpointTime]   = GetTickCount();
			playerData[spareid][playerRobTime]			= 0;
			playerData[spareid][playerSafeObj]			= 0;
			playerData[spareid][playerClass]			= 0;
			playerData[spareid][playerWantedLevel]     	= 0;
			playerData[spareid][playerInsideHouse]    	= 0;
			playerData[spareid][playerInsideBusiness]  	= 0;
			playerData[spareid][playerVIPLevel]			= 0;
			playerData[spareid][playerRope]				= 0;
			playerData[spareid][playerScissors]			= 0;
			playerData[spareid][playerButtPlug]			= 0;
			playerData[spareid][playerBiggerPockets]	= 0;
			playerData[spareid][playerSecureWallet]		= 0;
			playerData[spareid][playerCustomSkin]		= -1;
			playerData[spareid][playerXP]				= 0;
			playerData[spareid][playerJob]				= -1;
			playerData[spareid][playerLastLogged]		= Seconds;

			playerData[spareid][playerLoggedIn] 		= true;

			playerData[spareid][playerAdminDuty]		= false;
			playerData[spareid][playerCanTaze]			= false;
			playerData[spareid][playerCanCuff]			= false;
			playerData[spareid][playerCanArrest]		= false;
			playerData[spareid][playerCanEMP]			= false;
			playerData[spareid][playerIsTazed]			= false;
			playerData[spareid][playerIsCuffed]			= false;
			playerData[spareid][playerIsInHouse]		= false;
			playerData[spareid][playerHitmarker]		= false;
			playerData[spareid][playerCanRape]			= false;
			playerData[spareid][playerCanRob]			= false;
			playerData[spareid][playerCanRepair]		= false;
			playerData[spareid][adminWeapon]			= false;
			playerData[spareid][pEnterHouse]			= false;
			playerData[spareid][showALog]             	= false;
			playerData[spareid][iscourier]             	= false;
			playerData[spareid][hasSTD] 				= false;
			playerData[spareid][isInEvent]             	= false;
			playerData[spareid][playerPingImmune]      	= false;
			playerData[spareid][hasSpawned]            	= false;
			playerData[spareid][isBanned]              	= false;

			playerData[spareid][playerCourierLevel]    	= 0;
			playerData[spareid][playerBanned]          	= 0;
			playerData[spareid][playerLastVehicleID]   	= 0;
			playerData[spareid][playerWarnings]        	= 0;
			playerData[spareid][playerBank]				= 0;
			playerData[spareid][playerHelper]			= 0;
			playerData[spareid][playerWeed]				= 0;
			playerData[spareid][playerExplosives]		= 0;
			playerData[spareid][playerExplosives]		= 0;
			playerData[spareid][truckStat]         		= 0;
			playerData[spareid][vipWeapon] 				= 0;
			playerData[spareid][copArrests] 			= 0;
			playerData[spareid][moneyBags] 				= 0;
			playerData[spareid][playerFightStyle]      	= 4;
			playerData[spareid][rulesRead]				= 0;
			playerData[spareid][houseCount]				= 0;
			playerData[spareid][messageCount]			= 0;
			playerData[spareid][spamCount]				= 0;
			playerData[spareid][streetRobberies] 		= 0;
			playerData[spareid][streetRapes] 			= 0;
			playerData[spareid][playersTied] 			= 0;
			playerData[spareid][playersKidnapped] 		= 0;
			playerData[spareid][copDetains]				= 0;
			playerData[spareid][copKills]				= 0;
			playerData[spareid][forkliftCompleted]		= 0;
			playerData[spareid][busCompleted]			= 0;
			playerData[spareid][sweepCompleted]			= 0;
			playerData[spareid][bankRobs]				= 0;

			playerData[spareid][playerGangID]			= INVALID_GANG_ID;
			playerData[spareid][lastRecipient]         	= -1;
			playerData[spareid][playerHousePass]       	= -1;
			playerData[spareid][spawnHouse]				= -1;
			playerData[spareid][playerLastTicket] 		= -1;
			playerData[spareid][playerBailTo] 			= -1;
			playerData[spareid][playerBailPrice] 		= -1;
			playerData[spareid][playerAdminJailed] 		= -1;
			playerData[spareid][playerGunOffer] 		= -1;
			playerData[spareid][playerGunDealer] 		= -1;
			playerData[spareid][lastCarDrop]			= -1;
			playerData[spareid][playerVehicleLocating] 	= -1;
			playerData[spareid][dmKills]				= 0;
			playerData[spareid][dmDeaths]				= 0;
			playerData[spareid][cookies]				= 0;
			playerData[spareid][playerBackpack]			= 0;
			playerData[spareid][medicStatus]			= 0;
			playerData[spareid][cbugWarnings]			= 0;
			playerData[spareid][shot]					= 0;
			playerData[spareid][weaponSkill]			= 0;
			playerData[spareid][bombsDefused]			= 0;
			playerData[spareid][rTokens]				= 0;
			playerData[spareid][carSwing]				= 0;
			playerData[spareid][playerTown]				= NO_TOWN;

			playerData[spareid][playerCanSaveStats] 	= true;
			playerData[spareid][canWeed] 				= true;
			playerData[spareid][canAsk] 				= true;
			playerData[spareid][canReport] 				= true;
			playerData[spareid][isInDM]					= false;
			playerData[spareid][isInFallout]			= false;
			playerData[spareid][useAdminName]			= false;
			playerData[spareid][vSellTo]				= -1;
			playerData[spareid][vBuyFrom]				= -1;

			new myName[24];
			GetPlayerName(spareid, myName, sizeof(myName));
			format(playerData[spareid][playerNamee], 24, "%s", myName);
			format(playerData[spareid][tempAdminName], 24, "%s", myName);
			TogglePlayerSpectating(spareid, false);

			LoginTextDraws(spareid);

			updateExperienceCounter(spareid);
			ResetPlayerWeapons(spareid);

			// Progress bars
			playerData[spareid][robbery] = CreateProgressBar(248.00, 209.00, 141.50, 13.20, 0xFAAC58FF, 100.0);

			closeDialogs(spareid);

			TextDrawHideForPlayer(spareid, loginDialog[0]);
			TextDrawHideForPlayer(spareid, loginDialog[1]);
			TextDrawHideForPlayer(spareid, loginDialog[2]);
			TextDrawHideForPlayer(spareid, loginDialog[3]);
			TextDrawHideForPlayer(spareid, loginDialog[4]);
			TextDrawHideForPlayer(spareid, loginDialog[5]);
			mysql_free_result();
		}

		case MYSQL_QUERY_BANNED:
		{
			mysql_store_result();

			new
				brow[300],
				banValues[5][24],
				playerName[24]
			;

			GetPlayerName(spareid, playerName, 24);

			if(mysql_num_rows())
			{
				mysql_fetch_row(brow, "|", connection);
				explode(brow, banValues, "|");

				mysql_fetch_row(banValues[1], "banned_by");
				mysql_fetch_row(banValues[2], "banned_for");
				mysql_fetch_row(banValues[3], "player_banned");
				mysql_fetch_row(banValues[4], "player_ip");

				new bannedMSG[512];
				format(bannedMSG, sizeof(bannedMSG), "{FFFFFF}You are banned from this server.\n\nBAN INFORMATION:\n{B52222}Username: {FFFFFF}%s\n{B52222}IP Address: {FFFFFF}%s\n{B52222}Banned by: {FFFFFF}%s\n{B52222}Reason: {FFFFFF}%s\n\nTo appeal this ban, please visit {98B0CD}www.CZCNR.ml", banValues[3], banValues[4], banValues[1], banValues[2]);
				ShowPlayerDialog(spareid, DIALOG_BANNED, DIALOG_STYLE_MSGBOX, "Banned", bannedMSG, "Close", "");

				playerData[spareid][isBanned] = true;

				KickWithMessage(spareid, "You have been kicked.");

			}

			SendDeathMessage(INVALID_PLAYER_ID, spareid, 200);
			mysql_free_result();
		}

		case MYSQL_ADD_BAN:
		{
			return 1;
		}

		case MYSQL_REMOVE_BAN:
		{
			mysql_store_result();

			new
				banrow[100],
				otherID[48],
				dataValues[5][24]
			;

			if(!mysql_num_rows())
			{
				SendClientMessage(spareid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}The player is not banned or doesn't exist.");
				mysql_free_result();
			}
			else
			{
				mysql_fetch_row(banrow, "|", connection);
				explode(banrow, dataValues, "|");

				mysql_fetch_row(banrow, "|", connection);
				explode(banrow, dataValues, "|");

				mysql_fetch_row(dataValues[1], "banned_by");
				mysql_fetch_row(dataValues[2], "banned_for");
				mysql_fetch_row(dataValues[3], "player_banned");
				mysql_fetch_row(dataValues[4], "player_ip");

				otherID = dataValues[3];

				new update[200];
				format(update, sizeof(update), "DELETE FROM `playerbans` WHERE `player_banned` = '%s'", otherID);
				mysql_query(update, -1, -1, connection);

				// Show message
				new message[200];
				format(message, sizeof(message), "{A9C4E4}%s has been unbanned from the server.", otherID);
				SendClientMessageToAll(COLOR_WHITE, message);

				new log[250];
				format(log, sizeof(log), "%s(%i) has unbanned %s.", playerData[spareid][playerNamee], spareid, otherID);
				SendAdminText(spareid, log);

			}

			mysql_free_result();
		}

		case MYSQL_TOP_KILLER:
		{
			new baris[300], pnama[128], pkil, TDnow, TDnow2, looping, string[300], tambah[300];
			mysql_store_result();
			if(!mysql_num_rows())
			{
				closeDialogs(spareid);
				SendClientMessage(spareid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}There is no player in top list.");
				mysql_free_result();
			}
			else
			{
				closeDialogs(spareid);
				GetPVarString(spareid, "tambahan", tambah, 300);
				TDnow = 14;
				TDnow2 = 24;
				looping = 1;
				while(mysql_fetch_row(baris, "|", connection))
				{
					sscanf(baris, "p<|>s[128]d", pnama, pkil);
					TextDrawSetString(TopTD[TDnow], pnama);
					format(string, sizeof(string), "%i %s", pkil, tambah);
					TextDrawSetString(TopTD[TDnow2], string);
					TDnow++;
					TDnow2++;
					looping++;
				}
				for(; looping <= 10; looping++)
				{
					TextDrawSetString(TopTD[TDnow], "-");
					TextDrawSetString(TopTD[TDnow2], "-");
					TDnow++;
					TDnow2++;
				}
				TextDrawShowForPlayer(spareid, TopTD[0]);
				TextDrawShowForPlayer(spareid, TopTD[1]);
				TextDrawShowForPlayer(spareid, TopTD[2]);
				TextDrawShowForPlayer(spareid, TopTD[3]);
				TextDrawShowForPlayer(spareid, TopTD[4]);
				TextDrawShowForPlayer(spareid, TopTD[5]);
				TextDrawShowForPlayer(spareid, TopTD[6]);
				TextDrawShowForPlayer(spareid, TopTD[7]);
				TextDrawShowForPlayer(spareid, TopTD[8]);
				TextDrawShowForPlayer(spareid, TopTD[9]);
				TextDrawShowForPlayer(spareid, TopTD[10]);
				TextDrawShowForPlayer(spareid, TopTD[11]);
				TextDrawShowForPlayer(spareid, TopTD[12]);
				TextDrawShowForPlayer(spareid, TopTD[13]);
				TextDrawShowForPlayer(spareid, TopTD[14]);
				TextDrawShowForPlayer(spareid, TopTD[15]);
				TextDrawShowForPlayer(spareid, TopTD[16]);
				TextDrawShowForPlayer(spareid, TopTD[17]);
				TextDrawShowForPlayer(spareid, TopTD[18]);
				TextDrawShowForPlayer(spareid, TopTD[19]);
				TextDrawShowForPlayer(spareid, TopTD[20]);
				TextDrawShowForPlayer(spareid, TopTD[21]);
				TextDrawShowForPlayer(spareid, TopTD[22]);
				TextDrawShowForPlayer(spareid, TopTD[23]);
				TextDrawShowForPlayer(spareid, TopTD[24]);
				TextDrawShowForPlayer(spareid, TopTD[25]);
				TextDrawShowForPlayer(spareid, TopTD[26]);
				TextDrawShowForPlayer(spareid, TopTD[27]);
				TextDrawShowForPlayer(spareid, TopTD[28]);
				TextDrawShowForPlayer(spareid, TopTD[29]);
				TextDrawShowForPlayer(spareid, TopTD[30]);
				TextDrawShowForPlayer(spareid, TopTD[31]);
				TextDrawShowForPlayer(spareid, TopTD[32]);
				TextDrawShowForPlayer(spareid, TopTD[33]);
				TextDrawShowForPlayer(spareid, TopTD[34]);
				TextDrawShowForPlayer(spareid, TopTD[35]);
				TextDrawShowForPlayer(spareid, TopTD[36]);
				TextDrawShowForPlayer(spareid, TopTD[37]);
				TextDrawShowForPlayer(spareid, TopTD[38]);
				TextDrawShowForPlayer(spareid, TopTD[39]);
				TextDrawShowForPlayer(spareid, TopTD[40]);
				TextDrawShowForPlayer(spareid, TopTD[41]);
			}
			mysql_free_result();
		}
	}

	return 1;
}
