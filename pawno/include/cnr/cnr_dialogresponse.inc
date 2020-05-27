public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	if(dialogid == DIALOG_TOWN)
	{
		if(response)
		{
			playerData[playerid][playerTown] = listitem;
			TogglePlayerSpectating(playerid, false);
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You have selected a town to spawn, type /selecttown to select town.");
			SpawnPlayer(playerid);
		}
		else
			ShowPlayerDialog(playerid, DIALOG_TOWN, DIALOG_STYLE_LIST, "Choose Spawn Town", "San Fierro \nLas Venturas", "Choose", "");
	}
    /*if(dialogid == DIALOG_NEON && response)
	{
		new vid = GetPlayerVehicleID(playerid);
		if(listitem == 0)
		{
			for(new i; i < MAX_SAVED_VEHICLES; i++)
			{
				if (vid != VehicleInfo[i][vehicleID]) continue;

				DestroyDynamicObject(VehicleInfo[i][neon][1]);
				DestroyDynamicObject(VehicleInfo[i][neon][2]);
				VehicleInfo[i][neon][1] = CreateDynamicObject(18648,0,0,0,0,0,0);
				VehicleInfo[i][neon][2] = CreateDynamicObject(18648,0,0,0,0,0,0);
				AttachDynamicObjectToVehicle(VehicleInfo[i][neon][2], vid, -0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
				AttachDynamicObjectToVehicle(VehicleInfo[i][neon][1], vid, 0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
				break;
			}
			SendClientMessage(playerid, COLOR_WHITE, "{FE9A2E}[NEON] {FFFFFF}Blue Neon has been added to your vehicle.");
		}
		if(listitem == 1)
		{
			for(new i; i < MAX_SAVED_VEHICLES; i++)
			{
				if (vid != VehicleInfo[i][vehicleID]) continue;

				DestroyDynamicObject(VehicleInfo[i][neon][1]);
				DestroyDynamicObject(VehicleInfo[i][neon][2]);
				VehicleInfo[i][neon][1] = CreateDynamicObject(18649,0,0,0,0,0,0);
				VehicleInfo[i][neon][2] = CreateDynamicObject(18649,0,0,0,0,0,0);
				AttachDynamicObjectToVehicle(VehicleInfo[i][neon][2], vid, -0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
				AttachDynamicObjectToVehicle(VehicleInfo[i][neon][1], vid, 0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
				break;
			}
			SendClientMessage(playerid, COLOR_WHITE, "{FE9A2E}[NEON] {FFFFFF}Green Neon has been added to your vehicle.");
		}
		if(listitem == 2)
		{
			for(new i; i < MAX_SAVED_VEHICLES; i++)
			{
				if (vid != VehicleInfo[i][vehicleID]) continue;

				DestroyDynamicObject(VehicleInfo[i][neon][1]);
				DestroyDynamicObject(VehicleInfo[i][neon][2]);
				VehicleInfo[i][neon][1] = CreateDynamicObject(18650,0,0,0,0,0,0);
				VehicleInfo[i][neon][2] = CreateDynamicObject(18650,0,0,0,0,0,0);
				AttachDynamicObjectToVehicle(VehicleInfo[i][neon][2], vid, -0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
				AttachDynamicObjectToVehicle(VehicleInfo[i][neon][1], vid, 0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
				break;
			}
			SendClientMessage(playerid, COLOR_WHITE, "{FE9A2E}[NEON] {FFFFFF}Yellow Neon has been added to your vehicle.");
		}
		if(listitem == 3)
		{
			for(new i; i < MAX_SAVED_VEHICLES; i++)
			{
				if (vid != VehicleInfo[i][vehicleID]) continue;

				DestroyDynamicObject(VehicleInfo[i][neon][1]);
				DestroyDynamicObject(VehicleInfo[i][neon][2]);
				VehicleInfo[i][neon][1] = CreateDynamicObject(18652,0,0,0,0,0,0);
				VehicleInfo[i][neon][2] = CreateDynamicObject(18652,0,0,0,0,0,0);
				AttachDynamicObjectToVehicle(VehicleInfo[i][neon][2], vid, -0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
				AttachDynamicObjectToVehicle(VehicleInfo[i][neon][1], vid, 0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
				break;
			}
			SendClientMessage(playerid, COLOR_WHITE, "{FE9A2E}[NEON] {FFFFFF}White Neon has been added to your vehicle.");
		}
		if(listitem == 4)
		{
			for(new i; i < MAX_SAVED_VEHICLES; i++)
			{
				if (vid != VehicleInfo[i][vehicleID]) continue;

				DestroyDynamicObject(VehicleInfo[i][neon][1]);
				DestroyDynamicObject(VehicleInfo[i][neon][2]);
				VehicleInfo[i][neon][1] = CreateDynamicObject(18651,0,0,0,0,0,0);
				VehicleInfo[i][neon][2] = CreateDynamicObject(18651,0,0,0,0,0,0);
				AttachDynamicObjectToVehicle(VehicleInfo[i][neon][2], vid, -0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
				AttachDynamicObjectToVehicle(VehicleInfo[i][neon][1], vid, 0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
				break;
			}
			SendClientMessage(playerid, COLOR_WHITE, "{FE9A2E}[NEON] {FFFFFF}Pink Neon has been added to your vehicle.");
		}
		if(listitem == 5)
		{
			for(new i; i < MAX_SAVED_VEHICLES; i++)
			{
				if (vid != VehicleInfo[i][vehicleID]) continue;

				DestroyDynamicObject(VehicleInfo[i][neon][1]);
				DestroyDynamicObject(VehicleInfo[i][neon][2]);
				break;
			}
			SendClientMessage(playerid, COLOR_WHITE, "{FE9A2E}[NEON] {FFFFFF}Neon was removed from your vehicle.");
		}
		return 1;
	}*/

    if(dialogid == DIALOG_TOP && response)
	{
		new query[3000];
		switch(listitem)
		{
			case 0: //Noob Destroyer
			{
				TextDrawSetString(TopTD[2], "Top Killer");
				SetPVarString(playerid, "tambahan", "Kills");
				format(query, sizeof(query), "SELECT `playerName`,`playerKills` FROM `playerdata` where `playerKills` > 10 order by `playerKills` desc LIMIT 0,10");
				mysql_query(query, MYSQL_TOP_KILLER, playerid, connection);
			}
			case 1: //Best Robbers
			{
				TextDrawSetString(TopTD[2], "Best Robbers");
				SetPVarString(playerid, "tambahan", "Robberies");
				format(query, sizeof(query), "SELECT `playerName`,`playerRobberies` FROM `playerdata` where `playerRobberies` > 10 order by `playerRobberies` desc LIMIT 0,10");
				mysql_query(query, MYSQL_TOP_KILLER, playerid, connection);
			}
			case 2: //Top Players
			{
				TextDrawSetString(TopTD[2], "Top Players");
				SetPVarString(playerid, "tambahan", "Score");
				format(query, sizeof(query), "SELECT `playerName`,`playerScore` FROM `playerdata` where `playerScore` > 100 order by `playerScore` desc LIMIT 0,10");
				mysql_query(query, MYSQL_TOP_KILLER, playerid, connection);
			}
			case 3: //Top Truckers
			{
				TextDrawSetString(TopTD[2], "Top Truckers");
				SetPVarString(playerid, "tambahan", "Missions");
				format(query, sizeof(query), "SELECT `playerName`,`statTrucks` FROM `playerdata` where `statTrucks` > 10 order by `statTrucks` desc LIMIT 0,10");
				mysql_query(query, MYSQL_TOP_KILLER, playerid, connection);
			}
			case 4: //Top Moneybag Hunters
			{
				TextDrawSetString(TopTD[2], "Top Moneybag Hunters");
				SetPVarString(playerid, "tambahan", "Moneybags");
				format(query, sizeof(query), "SELECT `playerName`,`moneybagStat` FROM `playerdata` where `moneybagStat` > 10 order by `moneybagStat` desc LIMIT 0,10");
				mysql_query(query, MYSQL_TOP_KILLER, playerid, connection);
			}
			case 5: //Best Cop
			{
				TextDrawSetString(TopTD[2], "Best Cop");
				SetPVarString(playerid, "tambahan", "Arrests");
				format(query, sizeof(query), "SELECT `playerName`,`arrestStat` FROM `playerdata` where `arrestStat` > 10 order by `arrestStat` desc LIMIT 0,10");
				mysql_query(query, MYSQL_TOP_KILLER, playerid, connection);
			}
			case 6: //Richest Player
			{
				TextDrawSetString(TopTD[2], "Richest Player");
				SetPVarString(playerid, "tambahan", "$");
				format(query, sizeof(query), "SELECT `playerName`,`playerBank` FROM `playerdata` where `playerBank` > 100000 order by `playerBank` desc LIMIT 0,10");
				mysql_query(query, MYSQL_TOP_KILLER, playerid, connection);
			}
		}
	}
	// Registration dialog
	if(dialogid == DIALOG_REGISTER)
    {
        // If the user clicked the register button
        if(response)
        {
            // Check if the password is within 1 and 100 characters
            if(!strlen(inputtext) || strlen(inputtext) > 24)
            {
                // Re-show the dialog
                ShowPlayerDialog(playerid, DIALOG_REGISTER, DIALOG_STYLE_PASSWORD, "Register {58D3F7}Password length should be between 0 and 24.{FFFFFF}", "{FFFFFF}Your username is not registered! Please register with a password below.", "Register", "Cancel");
            }
            else if(strlen(inputtext) > 0 && strlen(inputtext) < 24)
            {
                // Password was a valid length
                new
					escapedPass[100],
					query[200],
					playerName[28],
					Seconds = gettime(),
					myIPAddress[16]
				;

				GetPlayerIp(playerid, myIPAddress, sizeof(myIPAddress));
				GetPlayerName(playerid, playerName, 24);

                // Clean the string before inserting to the MySQL database
                mysql_real_escape_string(inputtext, escapedPass);

				format(query, sizeof(query), "INSERT INTO playerdata (playerName, playerPass, firstLogged, playerIP) VALUES('%s', SHA1('%s'), '%i', '%s')", playerName, escapedPass, Seconds, myIPAddress);
				mysql_query(query, MYSQL_RESULT_REGISTER, playerid, connection);
            }
        }
        if(!response)
        {
			ShowPlayerDialog(playerid, DIALOG_REGISTER, DIALOG_STYLE_PASSWORD, "Register {58D3F7}Password length should be between 0 and 24.{FFFFFF}", "{FFFFFF}Your username is not registered! Please register with a password below.", "Register", "Cancel");
        }
    }

    // Login dialog
    if(dialogid == DIALOG_LOGIN)
    {
		new
			loginMessage[200],
			playerName[28]
		;

		GetPlayerName(playerid, playerName, 24);
		format(loginMessage, sizeof(loginMessage), "{98B0CD}%s {FFFFFF}is a registered username, please login by entering your password below.", playerName);

        // If user presses the cancel button
        if(!response)
        {
            Kick(playerid);
        }

		// If user presses the login button
        if(response)
        {
            // Set-up variables for the query
            new query[200], escapedPass[100];

            // Find the player's name
            GetPlayerName(playerid, playerName, 24);

            // Escape the MySQL string to stop SQLi
            mysql_real_escape_string(inputtext, escapedPass);

            // Query the database
			format(query, sizeof(query), "SELECT `playerName` FROM `playerdata` WHERE playerName = '%s' AND playerPass = SHA1('%s')", playerName, escapedPass);
			mysql_query(query, MYSQL_RESULT_LOGIN, playerid, connection);
        }
    }

    // Cop tutorial 2
   	if(dialogid == POLICE_TUTORIAL_1)
   	{
   	    if(response || !response)
   	    {
			// Part 2 of the tutorial
			new string[600];
			format(string, sizeof(string), "%s{98B0CD}Tickets & Warrants \n", string);
			format(string, sizeof(string), "%s{FFFFFF}Tickets may be issued if a player has committed a crime,\n", string);
			format(string, sizeof(string), "%sor there is a crime in progress that you have witnessed.\n\n", string);

            format(string, sizeof(string), "%s{98B0CD}(Valid Ticket/Warrant) {FFFFFF}- Assaulting an officer \n", string);
            format(string, sizeof(string), "%s{98B0CD}(Valid Ticket/Warrant) {FFFFFF}- Robbery in progress \n", string);
            format(string, sizeof(string), "%s{98B0CD}(Valid Ticket/Warrant) {FFFFFF}- Assaulting a player \n\n", string);
            format(string, sizeof(string), "%s{FE642E}(Invalid Ticket/Warrant) {FFFFFF}- Holding a weapon \n", string);
            format(string, sizeof(string), "%s{FE642E}(Invalid Ticket/Warrant) {FFFFFF}- You suck. \n\n", string);

            format(string, sizeof(string), "%sWarrants are very similar, though after a warrant is issued you are free\n", string);
            format(string, sizeof(string), "%sto arrest the criminal.", string);

			ShowPlayerDialog(playerid, POLICE_TUTORIAL_2, DIALOG_STYLE_MSGBOX, "Police Tutorial - Tickets & Warrants", string, "Next", "");
   	    }
	}

    // Cop tutorial 3
   	if(dialogid == POLICE_TUTORIAL_2)
   	{
   	    if(response || !response)
   	    {
			// Part 2 of the tutorial
			new string[600];
            format(string, sizeof(string), "%s{98B0CD}Criminals & Innocents \n", string);
			format(string, sizeof(string), "%s{FFFFFF}One of the most common things in a CNR game-mode is cops\n", string);
			format(string, sizeof(string), "%skilling innocent civilians. By killing an innocent player (see /pc),\n", string);
			format(string, sizeof(string), "%syou will be jailed. Killing innocents constantly may lead to a cop ban.\n", string);
			format(string, sizeof(string), "%sThe cop ban can last until you appeal it and get approved by a reviewer.\n", string);
			format(string, sizeof(string), "%sTo prevent receiving a cop ban, please refer to /pc as previously stated.\n\n", string);

			format(string, sizeof(string), "%sThough not related to the cop ban system, \n", string);
			format(string, sizeof(string), "%skilling players whilst an army player may lead to a\n", string);
			format(string, sizeof(string), "%slengthy army ban if using vehicles such as the hunter or tank.", string);

			ShowPlayerDialog(playerid, POLICE_TUTORIAL_3, DIALOG_STYLE_MSGBOX, "Police Tutorial - Criminals & Innocents", string, "Next", "");
   	    }
	}

    // Cop tutorial 4
   	if(dialogid == POLICE_TUTORIAL_3)
   	{
   	    if(response || !response)
   	    {
			// Part 2 of the tutorial
			new string[1200];

			format(string, sizeof(string), "%s{98B0CD}Commands \n", string);
			format(string, sizeof(string), "%s{FFFFFF}Take a look at the following LEO commands.\n", string);
			format(string, sizeof(string), "%sYou can view these at anytime by typing /commands\n\n", string);

            format(string, sizeof(string), "%s{98B0CD}/ticket {FFFFFF}- Give a ticket to a player \n", string);
            format(string, sizeof(string), "%s{98B0CD}/iw {FFFFFF}- Issue a warrant to a player \n", string);
            format(string, sizeof(string), "%s{98B0CD}/cuff {FFFFFF}- Cuff a player \n", string);
            format(string, sizeof(string), "%s{98B0CD}/taze {FFFFFF}- Taze a player \n", string);
            format(string, sizeof(string), "%s{98B0CD}/(ar)rest {FFFFFF}- Arrest a player \n", string);
            format(string, sizeof(string), "%s{98B0CD}/emp {FFFFFF}- Temporarily disable a player's vehicle \n", string);
            format(string, sizeof(string), "%s{98B0CD}/bail {FFFFFF}- Offer bail to a player \n", string);
            format(string, sizeof(string), "%s{98B0CD}/detain {FFFFFF}- Detain a criminal to your last vehicle \n", string);
            format(string, sizeof(string), "%s{98B0CD}/dropoff {FFFFFF}- Drop-off a criminal at a drop-off point \n", string);
            format(string, sizeof(string), "%s{98B0CD}/p {FFFFFF}- Chat on the police radio \n", string);
			format(string, sizeof(string), "%s{98B0CD}/locate {FFFFFF}- Locate a criminal \n", string);
			format(string, sizeof(string), "%s{98B0CD}/placerb {FFFFFF}- Place a Roadblock \n", string);
			format(string, sizeof(string), "%s{98B0CD}/placesp {FFFFFF}- Place a Spike Strip \n", string);

			ShowPlayerDialog(playerid, POLICE_TUTORIAL_4, DIALOG_STYLE_MSGBOX, "Police Tutorial - Commands", string, "Finish", "");
   	    }
	}

    // Cop tutorial End
   	if(dialogid == POLICE_TUTORIAL_4)
   	{
   	    if(response || !response)
   	    {
			playerData[playerid][playerCopTutorial] = 1;
			SetPlayerVirtualWorld(playerid, 0);
			SpawnPlayer(playerid);
   	    }
	}


    // Stats dialog
    if(dialogid == DIALOG_STATS)
    {
        // If the user clicked on a stat category
        if(response)
        {
  			switch(listitem)
    		{
    			case 0: // General user statistics
     			{
					new
						money[128],
						bank[128],
						kills[128],
						deaths[128],
						KD[128],
						level[128],
						vlevel[128],
						showstats[500]
					;

					new Float:ratio = float(playerData[playerid][playerKills]) / float(playerData[playerid][playerDeaths]);

					format(level, sizeof(level), "{FFFFFF}Admin Level: {98B0CD}%s", FormatNumber(playerData[playerid][playerLevel]));
					format(vlevel, sizeof(vlevel), "{FFFFFF}V.I.P Level: {98B0CD}%s", FormatNumber(playerData[playerid][playerVIPLevel]));
					format(money, sizeof(money), "{FFFFFF}Total Money: {98B0CD}$%s", FormatNumber(playerData[playerid][playerMoney]));
					format(bank, sizeof(bank), "{FFFFFF}Bank Money: {98B0CD}$%s", FormatNumber(playerData[playerid][playerBank]));
					format(kills, sizeof(kills), "{FFFFFF}Total Players Killed: {98B0CD}%s", FormatNumber(playerData[playerid][playerKills]));
					format(deaths, sizeof(deaths), "{FFFFFF}Total Deaths: {98B0CD}%s", FormatNumber(playerData[playerid][playerDeaths]));
					format(KD, sizeof(KD), "{FFFFFF}K/D Ratio: {98B0CD}%0.2f", ratio);

					format(showstats, sizeof showstats, "%s \n%s \n%s \n%s \n%s \n%s \n%s", level, vlevel, money, bank, kills, deaths, KD);
					ShowPlayerDialog(playerid, DIALOG_STATS_MSGBOX, DIALOG_STYLE_MSGBOX, "Player Statistics", showstats, "OK", "Close");
    			}

 	    		case 1: // Police Statistics
  	    		{
					new
						arrests[128],
						detains[128],
						kills[128],
						showstats[500]
					;

					format(arrests, sizeof(arrests), "{FFFFFF}Criminals Arrested: {98B0CD}%i", playerData[playerid][copArrests]);
					format(detains, sizeof(detains), "{FFFFFF}Criminals Detained: {98B0CD}%i", playerData[playerid][copDetains]);
					format(kills, sizeof(kills), "{FFFFFF}Criminals Killed: {98B0CD}%i", playerData[playerid][copKills]);

					format(showstats, sizeof showstats, "%s \n%s \n%s", arrests, detains, kills);
					ShowPlayerDialog(playerid, DIALOG_STATS_MSGBOX, DIALOG_STYLE_MSGBOX, "Police Statistics", showstats, "OK", "Close");
   	   	 		}

     	    	case 2: // Crime statistics
     	    	{
					new
						sRobberies[128],
						pRobberies[128],
						pRapes[128],
						pTies[128],
						pKidnaps[128],
						tJailed[128],
						bRobs[128],
						showstats[500]
					;

					format(sRobberies, sizeof(sRobberies), "{FFFFFF}Store Robberies Completed: {98B0CD}%s", FormatNumber(playerData[playerid][playerRobberies]));
					format(pRobberies, sizeof(pRobberies), "{FFFFFF}Total Players Robbed: {98B0CD}%s", FormatNumber(playerData[playerid][streetRobberies]));
					format(pRapes, sizeof(pRapes), "{FFFFFF}Total Players Raped: {98B0CD}%s", FormatNumber(playerData[playerid][streetRapes]));
					format(pTies, sizeof(pTies), "{FFFFFF}Total Players Tied: {98B0CD}%s", FormatNumber(playerData[playerid][playersTied]));
					format(pKidnaps, sizeof(pKidnaps), "{FFFFFF}Total Players Kidnapped: {98B0CD}%s", FormatNumber(playerData[playerid][playersKidnapped]));
					format(tJailed, sizeof(tJailed), "{FFFFFF}Total Jail Sentences: {98B0CD}%s", FormatNumber(playerData[playerid][playerTimesJailed]));
					format(bRobs, sizeof(bRobs), "{FFFFFF}Bank Robberies Completed: {98B0CD}%s", FormatNumber(playerData[playerid][bankRobs]));

					format(showstats, sizeof showstats, "%s \n%s \n%s \n%s \n%s \n%s \n%s", sRobberies, pRobberies, pRapes, pTies, pKidnaps, tJailed, bRobs);
					ShowPlayerDialog(playerid, DIALOG_STATS_MSGBOX, DIALOG_STYLE_MSGBOX, "Criminal Statistics", showstats, "OK", "Close");
     	    	}

     	    	case 3: // Mission Stats
     	    	{
					new
						trucking[200],
						hits[200],
						forklift[200],
						bus[200],
						sweeps[200],
						showstats[500]
					;

					format(trucking, sizeof(trucking), "{FFFFFF}Trucking Missions Completed: {98B0CD}%s", FormatNumber(playerData[playerid][truckStat]));
					format(hits, sizeof(hits), "{FFFFFF}Hitman Contracts Completed: {98B0CD}%s", FormatNumber(playerData[playerid][hitsCompleted]));
					format(bus, sizeof(bus), "{FFFFFF}Bus Missions Completed: {98B0CD}%s", FormatNumber(playerData[playerid][busCompleted]));
					format(forklift, sizeof(forklift), "{FFFFFF}Forklift Missions Completed: {98B0CD}%s", FormatNumber(playerData[playerid][forkliftCompleted]));
					format(sweeps, sizeof(sweeps), "{FFFFFF}Sweeper Routes Completed: {98B0CD}%s", FormatNumber(playerData[playerid][sweepCompleted]));

					format(showstats, sizeof showstats, "%s \n%s  \n%s \n%s \n%s", trucking, hits, forklift, bus, sweeps);
					ShowPlayerDialog(playerid, DIALOG_STATS_MSGBOX, DIALOG_STYLE_MSGBOX, "Mission Statistics", showstats, "OK", "Close");
     	    	}

				case 4: // Inventory
				{
					return cmd_inventory(playerid, "");
				}

				case 5: // Achievements
				{
					return cmd_achievements(playerid, "");
				}
       		}
   		}
   	}

    // Admin Stats dialog
    if(dialogid == DIALOG_ADMINSTATS)
    {
		new lookAt;
		lookAt = playerData[playerid][playerGetStats];

        // If the user clicked on a stat category
        if(response)
        {
  			switch(listitem)
    		{
    			case 0: // General user statistics
     			{
					new
						money[128],
						bank[128],
						kills[128],
						deaths[128],
						KD[128],
						showstats[500]
					;

					new Float:ratio = float(playerData[lookAt][playerKills]) / float(playerData[lookAt][playerDeaths]);

					format(money, sizeof(money), "{FFFFFF}Total Money: {98B0CD}$%s", FormatNumber(playerData[lookAt][playerMoney]));
					format(bank, sizeof(bank), "{FFFFFF}Bank Money: {98B0CD}$%s", FormatNumber(playerData[lookAt][playerBank]));
					format(kills, sizeof(kills), "{FFFFFF}Total Players Killed: {98B0CD}%s", FormatNumber(playerData[lookAt][playerKills]));
					format(deaths, sizeof(deaths), "{FFFFFF}Total Deaths: {98B0CD}%s", FormatNumber(playerData[lookAt][playerDeaths]));
					format(KD, sizeof(KD), "{FFFFFF}K/D Ratio: {98B0CD}%0.2f", ratio);

					format(showstats, sizeof showstats, "%s \n%s \n%s \n%s \n%s", money, bank, kills, deaths, KD);

					new title[100];
					format(title, sizeof(title), "%s's Player Statistics", playerData[lookAt][playerNamee]);
					ShowPlayerDialog(playerid, DIALOG_ADMINSTATS, DIALOG_STYLE_MSGBOX, title, showstats, "OK", "Close");
    			}

 	    		case 1: // Police Statistics
  	    		{
					new
						arrests[128],
						detains[128],
						kills[128],
						showstats[500]
					;

					format(arrests, sizeof(arrests), "{FFFFFF}Criminals Arrested: {98B0CD}%i", playerData[lookAt][copArrests]);
					format(detains, sizeof(detains), "{FFFFFF}Criminals Detained: {98B0CD}%i", playerData[lookAt][copDetains]);
					format(kills, sizeof(kills), "{FFFFFF}Criminals Killed: {98B0CD}%i", playerData[lookAt][copKills]);

					format(showstats, sizeof showstats, "%s \n%s \n%s", arrests, detains, kills);
					new title[100];
					format(title, sizeof(title), "%s's Police Statistics", playerData[lookAt][playerNamee]);
					ShowPlayerDialog(playerid, DIALOG_ADMINSTATS, DIALOG_STYLE_MSGBOX, title, showstats, "OK", "Close");
   	   	 		}

     	    	case 2: // Crime statistics
     	    	{
					new
						sRobberies[128],
						pRobberies[128],
						pRapes[128],
						pTies[128],
						pKidnaps[128],
						tJailed[128],
						bRobs[128],
						showstats[500]
					;

					format(sRobberies, sizeof(sRobberies), "{FFFFFF}Store Robberies Completed: {98B0CD}%s", FormatNumber(playerData[lookAt][playerRobberies]));
					format(pRobberies, sizeof(pRobberies), "{FFFFFF}Total Players Robbed: {98B0CD}%s", FormatNumber(playerData[lookAt][streetRobberies]));
					format(pRapes, sizeof(pRapes), "{FFFFFF}Total Players Raped: {98B0CD}%s", FormatNumber(playerData[lookAt][streetRapes]));
					format(pTies, sizeof(pTies), "{FFFFFF}Total Players Tied: {98B0CD}%s", FormatNumber(playerData[lookAt][playersTied]));
					format(pKidnaps, sizeof(pKidnaps), "{FFFFFF}Total Players Kidnapped: {98B0CD}%s", FormatNumber(playerData[lookAt][playersKidnapped]));
					format(tJailed, sizeof(tJailed), "{FFFFFF}Total Jail Sentences: {98B0CD}%s", FormatNumber(playerData[lookAt][playerTimesJailed]));
					format(bRobs, sizeof(bRobs), "{FFFFFF}Bank Robberies Completed: {98B0CD}%s", FormatNumber(playerData[lookAt][bankRobs]));

					format(showstats, sizeof showstats, "%s \n%s \n%s \n%s \n%s \n%s \n%s", sRobberies, pRobberies, pRapes, pTies, pKidnaps, tJailed, bRobs);
					new title[100];
					format(title, sizeof(title), "%s's Criminal Statistics", playerData[lookAt][playerNamee]);
					ShowPlayerDialog(playerid, DIALOG_ADMINSTATS, DIALOG_STYLE_MSGBOX, title, showstats, "OK", "Close");
     	    	}

     	    	case 3: // Mission Stats
     	    	{
					new
						trucking[200],
						hits[200],
						forklift[200],
						bus[200],
						sweeps[200],
						showstats[500]
					;

					format(trucking, sizeof(trucking), "{FFFFFF}Trucking Missions Completed: {98B0CD}%s", FormatNumber(playerData[lookAt][truckStat]));
					format(hits, sizeof(hits), "{FFFFFF}Hitman Contracts Completed: {98B0CD}%s", FormatNumber(playerData[lookAt][hitsCompleted]));
					format(forklift, sizeof(forklift), "{FFFFFF}Forklift Missions Completed: {98B0CD}%s", FormatNumber(playerData[lookAt][forkliftCompleted]));
					format(bus, sizeof(bus), "{FFFFFF}Bus Routes Completed: {98B0CD}%s", FormatNumber(playerData[lookAt][busCompleted]));
					format(sweeps, sizeof(sweeps), "{FFFFFF}Sweeper Routes Completed: {98B0CD}%s", FormatNumber(playerData[lookAt][sweepCompleted]));

					format(showstats, sizeof showstats, "%s \n%s  \n%s \n%s \n%s", trucking, hits, forklift, bus, sweeps);

					new title[100];
					format(title, sizeof(title), "%s's Mission Statistics", playerData[lookAt][playerNamee]);
					ShowPlayerDialog(playerid, DIALOG_ADMINSTATS, DIALOG_STYLE_MSGBOX, title, showstats, "OK", "Close");
     	    	}
       		}
   		}
   	}

   	if(dialogid == DIALOG_ADMINSTATS_MSGBOX)
   	{
   	    if(response || !response)
   	    {
			new
				lookAt,
				title[100]
			;

			lookAt = playerData[playerid][playerGetStats];

			format(title, sizeof(title), "%s's Statistics", playerData[lookAt][playerNamee]);
   	    	ShowPlayerDialog(playerid, DIALOG_ADMINSTATS, DIALOG_STYLE_LIST, title, "Player Statistics \nPolice Statistics \nCrime Statistics \nMission Statistics", "View", "Cancel");
   	    }
	}

   	if(dialogid == DIALOG_STATS_MSGBOX)
   	{
   	    if(response || !response)
   	    {
   	    	ShowPlayerDialog(playerid, DIALOG_STATS, DIALOG_STYLE_LIST, "Game Statistics", "Player Statistics \nPolice Statistics \nCrime Statistics \nMission Statistics \nMy Inventory \nMy Achievements", "View", "Cancel");
   	    }
	}

    // Arenas dialog
    if(dialogid == DIALOG_ARENAS)
    {
        // If the user clicked on a teleport location
        if(response)
        {
  			switch(listitem)
    		{
    			case 0: // Teleport to Dirt Track
     			{
					// -1444.6455, -664.5260, 1053.5730
					SetPlayerPos(playerid, -1444.6455, -664.5260, 1053.5730);
					SetPlayerInterior(playerid, 4);
					SetPlayerVirtualWorld(playerid, 50);
    			}
 	    		case 1: // Teleport to 8 Track
  	    		{
					// -1398.0653, -217.0289, 1051.1158
					SetPlayerPos(playerid, -1398.0653, -217.0289, 1051.1158);
					SetPlayerInterior(playerid, 7);
					SetPlayerVirtualWorld(playerid, 50);
   	   	 		}
     	    	case 2: // Teleport to Kickstart
     	    	{
					// -1465.2687, 1557.8683, 1052.5313
					SetPlayerPos(playerid, -1465.2687, 1557.8683, 1052.5313);
					SetPlayerInterior(playerid, 14);
					SetPlayerVirtualWorld(playerid, 50);
     	    	}
     	    	case 3: // Teleport to Bloodbowl
     	    	{
					// -1398.0636, 937.9134, 1036.4858
					SetPlayerPos(playerid, -1398.0636, 937.9134, 1036.4858);
					SetPlayerInterior(playerid, 15);
					SetPlayerVirtualWorld(playerid, 50);
     	    	}
     	    	case 4: // Teleport to Vice Stadium
     	    	{
					// -1398.7865, 106.9005, 1032.2734
					SetPlayerPos(playerid, -1398.7865, 106.9005, 1032.2734);
					SetPlayerInterior(playerid, 1);
					SetPlayerVirtualWorld(playerid, 50);
     	    	}
     	    	case 5: // Teleport to Warehouse
     	    	{
					// 1412.5952, -2.1127, 1000.9244
					SetPlayerPos(playerid, 1412.5952, -2.1127, 1000.9244);
					SetPlayerInterior(playerid, 1);
					SetPlayerVirtualWorld(playerid, 50);
     	    	}
     	    	case 6: // Teleport to derby event
     			{
					// 2897.8269,529.6500,2.5237
					SetPlayerPos(playerid, 2897.8269,529.6500,2.5237);
					SetPlayerInterior(playerid, 4);
					SetPlayerVirtualWorld(playerid, 50);
    			}
       		}
   		}
   	}

    // Bank dialog
    if(dialogid == DIALOG_BANK)
    {
        // If the user clicked on an option
        if(response)
        {
  			switch(listitem)
    		{
    			case 0: // Account
     			{
					new cash[48], bank[68], showstats[500];
					format(bank, sizeof bank, "Bank Balance: $%s", FormatNumber(playerData[playerid][playerBank]));
					format(cash, sizeof cash, "Cash Balance: $%s", FormatNumber(playerData[playerid][playerMoney]));
					format(showstats, sizeof showstats, "%s\n%s", bank, cash);

					// Show dialog containing stats
					ShowPlayerDialog(playerid, 150, DIALOG_STYLE_MSGBOX, "Bank Account Information", showstats, "Okay", "Close");
    			}
     	    	case 1: // Withdraw
     	    	{
                    ShowPlayerDialog(playerid, DIALOG_BANK_WITHDRAW, DIALOG_STYLE_INPUT, "Cash Withdrawal", "Enter the amount you wish to withdraw.", "Withdraw", "Cancel");
     	    	}
 	    		case 2: // Deposit
  	    		{
                    ShowPlayerDialog(playerid, DIALOG_BANK_DEPOSIT, DIALOG_STYLE_INPUT, "Cash Deposit", "Enter the amount you wish to deposit.", "Deposit", "Cancel");
   	   	 		}
       		}
   		}
   	}

   	if(dialogid == 150)
   	{
   	    if(response || !response)
   	    {
   	    	ShowPlayerDialog(playerid, DIALOG_BANK, DIALOG_STYLE_LIST, "Bank of San Fierro", "Account Information \nWithdraw Cash \nDeposit Cash", "Go", "Cancel");
   	    }
	}

	if(dialogid == DIALOG_BANK_WITHDRAW)
	{
	    if(!response)
	    {
	        ShowPlayerDialog(playerid, DIALOG_BANK, DIALOG_STYLE_LIST, "Bank of San Fierro", "Account Information \nWithdraw Cash \nDeposit Cash", "Go", "Cancel");
	 	}
	 	else
	 	{
	 	    // Check the input
	 	    new cash = strval(inputtext);
	        if (cash < 1)
	        {
	            // Lower than 1
	            ShowPlayerDialog(playerid, DIALOG_BANK_WITHDRAW, DIALOG_STYLE_INPUT, "Cash Withdrawal", "{FE642E}You cannot withdraw this amount.\n{FFFFFF}Enter the amount you wish to withdraw.", "Withdraw", "Cancel");
			}
			else
			{
				if (cash <= playerData[playerid][playerBank])
				{
				    // User can withdraw this amount.
				    playerGiveMoney(playerid, cash);
				    playerTakeBankMoney(playerid, cash);

					// Completed
                    ShowPlayerDialog(playerid, DIALOG_BANK_WITHDRAW, DIALOG_STYLE_INPUT, "Cash Withdrawal", "{58D3F7}The money has been withdrawn.\n{FFFFFF}Enter the amount you wish to withdraw.", "Withdraw", "Cancel");
				}
				else
				{
				    // User cannot withdraw this amount.
				    ShowPlayerDialog(playerid, DIALOG_BANK_WITHDRAW, DIALOG_STYLE_INPUT, "Cash Withdrawal", "{FE642E}You cannot withdraw this amount.\n{FFFFFF}Enter the amount you wish to withdraw.", "Withdraw", "Cancel");
				}
			}
		}
	}

	if(dialogid == DIALOG_BANK_DEPOSIT)
	{
	    if(!response)
	    {
	        ShowPlayerDialog(playerid, DIALOG_BANK, DIALOG_STYLE_LIST, "Bank of San Fierro", "Account Information \nWithdraw Cash \nDeposit Cash", "Go", "Cancel");
	 	}
	 	else
	 	{
	 	    // Check the input
	 	    new cash = strval(inputtext);
	        if (cash < 1)
	        {
	            // Lower than 1
	            ShowPlayerDialog(playerid, DIALOG_BANK_DEPOSIT, DIALOG_STYLE_INPUT, "Cash Deposit", "{FE642E}You cannot deposit this amount.\n{FFFFFF}Enter the amount you wish to deposit.", "Deposit", "Cancel");
			}
			else
			{
				if (cash <= playerData[playerid][playerMoney])
				{
				    // User can deposit this amount.
				    playerTakeMoney(playerid, cash);
				    playerGiveBankMoney(playerid, cash);

					// Completed
				    ShowPlayerDialog(playerid, DIALOG_BANK_DEPOSIT, DIALOG_STYLE_INPUT, "Cash Deposit", "{58D3F7}The money has been deposited.\n{FFFFFF}Enter the amount you wish to deposit.", "Deposit", "Cancel");
				}
				else
				{
				    // User cannot deposit this amount.
                    ShowPlayerDialog(playerid, DIALOG_BANK_DEPOSIT, DIALOG_STYLE_INPUT, "Cash Deposit", "{FE642E}You cannot deposit this amount.\n{FFFFFF}Enter the amount you wish to deposit.", "Deposit", "Cancel");
				}
			}
		}
	}

    // Weapon dealer dialog
    if(dialogid == DIALOG_GUNDEAL)
    {
        // If the user clicked on a gun item
        if(response)
        {
			if(isPlayerInRangeOfPlayer(playerid, playerData[playerid][playerGunDealer], 20.0))
			{
				switch(listitem)
				{
					case 0: // MP5 29
					{
						if (playerData[playerid][playerMoney] >= 1500)
						{
							SendClientMessage(playerid, COLOR_WHITE, "{FE9A2E}[DEAL] {FFFFFF}You have purchased an {FFDC2E}MP5{FFFFFF}.");
							playerTakeMoney(playerid, 1500);
							GivePlayerWeaponEx(playerid, 29, 99999);

							// Pay Dealer
							playerGiveMoney(playerData[playerid][playerGunDealer], 1500);

							if(IsPlayerInAnyVehicle(playerid))
							{
								SetPlayerArmedWeapon(playerid, 0);
							}
						}
						else
						{
						   SendClientMessage(playerid, COLOR_WHITE, "{FE9A2E}[DEAL] {FFFFFF}You cannot afford this.");
						}
					}
					case 1: // Combat Shotgun 27
					{
						if (playerData[playerid][playerMoney] >= 3000)
						{
							SendClientMessage(playerid, COLOR_WHITE, "{FE9A2E}[DEAL] {FFFFFF}You have purchased a {FFDC2E}Combat Shotgun{FFFFFF}.");
							playerTakeMoney(playerid, 3000);
							GivePlayerWeaponEx(playerid, 27, 99999);

							// Pay Dealer
							playerGiveMoney(playerData[playerid][playerGunDealer], 3000);

							if(IsPlayerInAnyVehicle(playerid))
							{
								SetPlayerArmedWeapon(playerid, 0);
							}
						}
						else
						{
						   SendClientMessage(playerid, COLOR_WHITE, "{FE9A2E}[DEAL] {FFFFFF}You cannot afford this.");
						}
					}
					case 2: // Sawnoff Shotgun 26
					{
						if (playerData[playerid][playerMoney] >= 5000)
						{
							SendClientMessage(playerid, COLOR_WHITE, "{FE9A2E}[DEAL] {FFFFFF}You have purchased a {FFDC2E}Sawnoff Shotgun{FFFFFF}.");
							playerTakeMoney(playerid, 5000);
							GivePlayerWeaponEx(playerid, 26, 99999);

							// Pay Dealer
							playerGiveMoney(playerData[playerid][playerGunDealer], 5000);

							if(IsPlayerInAnyVehicle(playerid))
							{
								SetPlayerArmedWeapon(playerid, 0);
							}
						}
						else
						{
						   SendClientMessage(playerid, COLOR_WHITE, "{FE9A2E}[DEAL] {FFFFFF}You cannot afford this.");
						}
					}
					case 3: // Desert Eagle 24
					{
						if (playerData[playerid][playerMoney] >= 3500)
						{
							SendClientMessage(playerid, COLOR_WHITE, "{FE9A2E}[DEAL] {FFFFFF}You have purchased a {FFDC2E}Desert Eagle{FFFFFF}.");
							playerTakeMoney(playerid, 3500);
							GivePlayerWeaponEx(playerid, 24, 99999);

							// Pay Dealer
							playerGiveMoney(playerData[playerid][playerGunDealer], 3500);

							if(IsPlayerInAnyVehicle(playerid))
							{
								SetPlayerArmedWeapon(playerid, 0);
							}
						}
						else
						{
						   SendClientMessage(playerid, COLOR_WHITE, "{FE9A2E}[DEAL] {FFFFFF}You cannot afford this.");
						}
					}
				}

				ShowPlayerDialog(playerid, DIALOG_GUNDEAL, DIALOG_STYLE_LIST, "Weapon Dealer", "MP5 {D87C3E}$1,500{FFFFFF} \nCombat Shotgun {D87C3E}$3,000{FFFFFF} \nSawnoff Shotgun {D87C3E}$5,000{FFFFFF}\nDesert Eagle {D87C3E}$3,500{FFFFFF}", "Go", "Cancel");
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}The weapon dealer is no longer in range.");
			}
		}

		if(!response)
		{
		    // Deal closed
			new ended[200];
			format(ended, sizeof(ended), "{FE9A2E}[DEAL COMPLETE] {FFFFFF}%s(%i) has finished browsing your weapons.", playerData[playerid][playerNamee], playerid);
			SendClientMessage(playerData[playerid][playerGunDealer], COLOR_WHITE, ended);
			playerData[playerid][playerGunOffer] = -1;
		}
   	}

    // Commands dialog
    if(dialogid == DIALOG_COMMANDS)
    {
        // If the user clicked on a document
		if(response)
        {
  			switch(listitem)
    		{
    			case 0: // General Commands
     			{
					new string[1900];

					format(string, sizeof(string), "%s{98B0CD}/jaillist {FFFF00}- View a list of jailed players \n", string);
					format(string, sizeof(string), "%s{98B0CD}/viplist {FFFF00}- View a list of donors \n", string);
					format(string, sizeof(string), "%s{98B0CD}/pm {FFFF00}- Send a private message \n", string);
					format(string, sizeof(string), "%s{98B0CD}/w(hisper) {FFFF00}- Sends a message to players close to you \n", string);
					format(string, sizeof(string), "%s{98B0CD}/cw {FFFF00}- Sends a message to players in your vehicle \n", string);
					format(string, sizeof(string), "%s{98B0CD}/kill {FFFF00}- Commit suicide \n", string);
					format(string, sizeof(string), "%s{98B0CD}/radio {FFFF00}- Choose a radio station \n", string);
					format(string, sizeof(string), "%s{98B0CD}/stopradio {FFFF00}- Stop the radio \n", string);
					format(string, sizeof(string), "%s{98B0CD}/stats {FFFF00}- View your stats \n", string);
					format(string, sizeof(string), "%s{98B0CD}/allstats {FFFF00}- View your stats \n", string);
					format(string, sizeof(string), "%s{98B0CD}/sendmoney {FFFF00}- Send money to a player \n", string);
					format(string, sizeof(string), "%s{98B0CD}/acceptbail {FFFF00}- Accept a bail offer \n", string);
					format(string, sizeof(string), "%s{98B0CD}/ask {FFFF00}- Ask a question \n", string);
					format(string, sizeof(string), "%s{98B0CD}/report {FFFF00}- Report a player \n", string);
					format(string, sizeof(string), "%s{98B0CD}/payticket {FFFF00}- Pay a ticket \n", string);
					format(string, sizeof(string), "%s{98B0CD}/eject {FFFF00}- Eject a player from your vehicle \n", string);
					format(string, sizeof(string), "%s{98B0CD}/animlist {FFFF00}- View a list of available animations \n", string);
					format(string, sizeof(string), "%s{98B0CD}/shop {FFFF00}- To be used whilst inside Supa Save  \n", string);
					format(string, sizeof(string), "%s{98B0CD}/stopevents {FFFF00}- Enable/disable event telports \n", string);
					format(string, sizeof(string), "%s{98B0CD}/pc {FFFF00}- View a list of player colours \n", string);
					format(string, sizeof(string), "%s{98B0CD}/getmytax {FFFF00}- View your current tax rate \n", string);
					format(string, sizeof(string), "%s{98B0CD}/blockpms {FFFF00}- When enabled, members cannot PM you \n", string);
					format(string, sizeof(string), "%s{98B0CD}/cuttie {FFFF00}- Attempt to cut the rope you're tied with (requires scissors) \n", string);
					format(string, sizeof(string), "%s{98B0CD}/(g)ang {FFFF00}- View a list of gang related commands \n", string);
					format(string, sizeof(string), "%s{98B0CD}/moneybag {FFFF00}- View info about the current money bag \n", string);
					format(string, sizeof(string), "%s{98B0CD}/gps {FFFF00}- Find locations easily \n", string);
					format(string, sizeof(string), "%s{98B0CD}/newclass {FFFF00}- Choose a new class \n", string);
					format(string, sizeof(string), "%s{98B0CD}/defuse {FFFF00}- Defuse C4 \n", string);
					format(string, sizeof(string), "%s{98B0CD}/selecttown {FFFF00}- Select spawn city \n", string);

					ShowPlayerDialog(playerid, 125, DIALOG_STYLE_MSGBOX, "General Commands", string, "OK", "");
				}
    			case 1: // Trucking Commands
     			{
					new string[1200];
                    format(string, sizeof(string), "%s{98B0CD}/trucking {FFFF00}- Starts the trucking mission \n", string);
                    format(string, sizeof(string), "%s{98B0CD}/canceltrucking {FFFF00}- Cancels the trucking mission \n", string);
                    format(string, sizeof(string), "%s{98B0CD}/t <message> {FFFF00}- Trucker chat\n", string);

					ShowPlayerDialog(playerid, 125, DIALOG_STYLE_MSGBOX, "Trucker Commands", string, "OK", "");
				}
				case 2:
				{
					return cmd_animlist(playerid, " ");
				}
    			case 3: // Police Commands
     			{
					new string[1200];
                    format(string, sizeof(string), "%s{98B0CD}/ticket {FFFF00}- Give a ticket to a player \n", string);
                    format(string, sizeof(string), "%s{98B0CD}/iw {FFFF00}- Issue a warrant to a player \n", string);
                    format(string, sizeof(string), "%s{98B0CD}/cuff {FFFF00}- Cuff a player \n", string);
                    format(string, sizeof(string), "%s{98B0CD}/taze {FFFF00}- Taze a player \n", string);
					format(string, sizeof(string), "%s{98B0CD}/arrest {FFFF00}- Arrest a player (send to jail) \n", string);
                    format(string, sizeof(string), "%s{98B0CD}/(ar)rest {FFFF00}- Arrest a player \n", string);
                    format(string, sizeof(string), "%s{98B0CD}/emp {FFFF00}- Temporarily disable a player's vehicle \n", string);
                    format(string, sizeof(string), "%s{98B0CD}/bail {FFFF00}- Offer bail to a player \n", string);
                    format(string, sizeof(string), "%s{98B0CD}/detain {FFFF00}- Detain a criminal to your last vehicle \n", string);
                    format(string, sizeof(string), "%s{98B0CD}/dropoff {FFFF00}- Drop-off a criminal at a drop-off point \n", string);
					format(string, sizeof(string), "%s{98B0CD}/helidropoff {FFFF00}- Drop-off a criminal at a helicopter drop-off point \n", string);
					format(string, sizeof(string), "%s{98B0CD}/locate {FFFF00}- Find a criminal's current location \n", string);
                    format(string, sizeof(string), "%s{98B0CD}/p {FFFF00}- Chat on the police radio \n", string);
					format(string, sizeof(string), "%s{98B0CD}/army {FFFF00}- Chat on the army radio \n", string);
					format(string, sizeof(string), "%s{98B0CD}/placerb {FFFF00}- Place a Roadblock \n", string);
					format(string, sizeof(string), "%s{98B0CD}/placesp {FFFF00}- Place a Spike Strip \n", string);

					ShowPlayerDialog(playerid, 125, DIALOG_STYLE_MSGBOX, "Police Commands", string, "OK", "");
				}
    			case 4: // Job Commands
     			{
					new string[1400];
					format(string, sizeof(string), "%s{D8D8D8}Mechanic Commands \n", string);
					format(string, sizeof(string), "%s{98B0CD}/mech fix {FFFF00}- Fixes a vehicle for {FFDC2E}$300 \n{98B0CD}/mech remp {FFFFFF}- Removes an EMP for {FFDC2E}$2,000 \n", string);
					format(string, sizeof(string), "%s{98B0CD}/mech nos {FFFF00}- Adds nos a vehicle for {FFDC2E}$1,000 \n{98B0CD}/mech color {FFFFFF}- Vehicle color change for {FFDC2E}$500 \n\n", string);

					format(string, sizeof(string), "%s{D8D8D8}Kidnapper Commands \n", string);
					format(string, sizeof(string), "%s{98B0CD}/kidnap {FFFF00}- Places your victim into a free seat of your vehicle (/tie firstrly) \n\n", string);

					format(string, sizeof(string), "%s{D8D8D8}Hitman Commands \n", string);
					format(string, sizeof(string), "%s{98B0CD}{98B0CD}/track {FFFF00}- Tracks a player \n", string);
					format(string, sizeof(string), "%s{98B0CD}{98B0CD}/hitlist {FFFF00}- View a list of players with a bounty \n\n", string);

					format(string, sizeof(string), "%s{D8D8D8}Weapon Dealer Commands \n", string);
					format(string, sizeof(string), "%s{98B0CD}{98B0CD}/sellgun {FFFF00}- Offers to sell weapons to a player \n\n", string);

					format(string, sizeof(string), "%s{D8D8D8}Drug Dealer Commands \n", string);
					format(string, sizeof(string), "%s{98B0CD}{98B0CD}/sellweed {FFFF00}- Offers to sell weed to a player for {FFDC2E}$500 \n\n", string);

					format(string, sizeof(string), "%s{D8D8D8}Rapist Commands \n", string);
					format(string, sizeof(string), "%s{98B0CD}/rape {FFFF00}- Rapes the cloest person to you \n\n", string);

					format(string, sizeof(string), "%s{D8D8D8}Medic Commands \n", string);
					format(string, sizeof(string), "%s{98B0CD}/heal {FFFF00}- Heals a player for {FFDC2E}$300 \n", string);
					format(string, sizeof(string), "%s{98B0CD}/cure {FFFF00}- Cures a player of STDs for {FFDC2E}$1,000 \n\n", string);

					format(string, sizeof(string), "%s{D8D8D8}Terrorist Commands \n", string);
					format(string, sizeof(string), "%s{98B0CD}/usec4 {FFFF00}- Plants C4 on the ground \n", string);
					format(string, sizeof(string), "%s{98B0CD}/detonate <id> {FFFF00}- Detonates the specified explosive \n", string);
					format(string, sizeof(string), "%s{98B0CD}\"Y\" Key <id> {FFFF00}- Detonates all explosives \n\n", string);

					format(string, sizeof(string), "%s{98B0CD}/myjob {FFFF00}- Find out your current job", string);

					ShowPlayerDialog(playerid, 125, DIALOG_STYLE_MSGBOX, "Job Commands", string, "OK", "");
				}
				case 5: // House Commands
				{
					new string[600];
					format(string, sizeof(string), "%s{D8D8D8}House Commands \n", string);
					format(string, sizeof(string), "%s{98B0CD}/buyhouse <id> {FFFF00}- Allows you to purchase a house for sale. \n", string);
					format(string, sizeof(string), "%s{98B0CD}/housemenu {FFFF00}- Allows you to access the house menu. \n", string);
					format(string, sizeof(string), "%s{98B0CD}/myhouses {FFFF00}- View a list of your houses. \n", string);
					format(string, sizeof(string), "%s{98B0CD}/removespawn {FFFF00}- Removes your house spawn. \n", string);
					format(string, sizeof(string), "%s{98B0CD}/housesforsale {FFFF00}- Shows a list of current houses for sale. \n", string);

					ShowPlayerDialog(playerid, 125, DIALOG_STYLE_MSGBOX, "House Commands", string, "OK", "");
				}
				case 6: // Vehicle Commands
				{
					new string[600];
					format(string, sizeof(string), "%s{D8D8D8}Vehicle Commands \n", string);
					format(string, sizeof(string), "%s{98B0CD}/vsell <playerid> <price> {FFFF00}- Sell the vehicle to a player. \n", string);
					format(string, sizeof(string), "%s{98B0CD}/colour1 <colour id>{FFFF00}- Choose the first colour. \n", string);
					format(string, sizeof(string), "%s{98B0CD}/colour2 <colour id>{FFFF00}- Choose the second colour. \n", string);
					format(string, sizeof(string), "%s{98B0CD}/lock {FFFF00}- Lock/Unlock your vehicle. \n", string);
					format(string, sizeof(string), "%s{98B0CD}/park {FFFF00}- Park the vehicle (set the respawn point). \n", string);
					format(string, sizeof(string), "%s{98B0CD}/myveh {FFFF00}- View your vehicles. \n", string);

					ShowPlayerDialog(playerid, 125, DIALOG_STYLE_MSGBOX, "Vehicle Commands", string, "OK", "");
				}
				/*case 7: // VIP commands
				{
					return cmd_viphelp(playerid, " ");
				}*/
			}
		}
	}

   	if(dialogid == 125)
   	{
   	    if(response || !response)
   	    {
   	    	ShowPlayerDialog(playerid, DIALOG_COMMANDS, DIALOG_STYLE_LIST, "Commands", "General Commands\nTrucker Commands\nAnimation Commands\nPolice Commands\nJob Commands\nHouse Commands\nVehicle Commands", "Go", "Cancel");
   	    }
	}

    // Help dialog
    if(dialogid == DIALOG_HELP)
    {
        // If the user clicked on a document
		if(response)
        {
  			switch(listitem)
    		{
    		    case 0: // Commands
    		    {
    		        ShowPlayerDialog(playerid, DIALOG_COMMANDS, DIALOG_STYLE_LIST, "Commands", "General Commands\nTrucker Commands\nAnimation Commands\nPolice Commands\nJob Commands\nHouse Commands\nVehicle Commands", "Go", "Cancel");
    		    }
    			case 1: // Admin Information
     			{
					new string[1200];
		            format(string, sizeof(string), "%s{98B0CD}What admins do{FFFFFF}\nOur administrators perform a variety of tasks. The main task being cheat prevention\n", string);
                    format(string, sizeof(string), "%sand rule enforcement. Our main priority is keeping the game a fair and friendly place.\n\n", string);

		            format(string, sizeof(string), "%s{98B0CD}Admin Levels{FFFFFF}\nThere are 5 levels in total, each level giving the admin more and more responsibility.\n", string);
                    format(string, sizeof(string), "%sLevel 1 administrators might handle reports for example, whereas a level 5 might handle \naccount issues.\n\n", string);

		            format(string, sizeof(string), "%s{98B0CD}Becoming an admin{FFFFFF}\nAdmins are hand picked by the server owners. Users who ask for admin are\n", string);
                    format(string, sizeof(string), "%smost likely never going to get it. The admin rank is not everything, \nplease don't come into the game expecting it.", string);
					ShowPlayerDialog(playerid, 123, DIALOG_STYLE_MSGBOX, "Admin Information", string, "OK", "");
				}
    			case 2: // Event Information
     			{
					new string[1200];
					format(string, sizeof(string), "%s{98B0CD}Server Events{FFFFFF}\nServer events are created by our higher ranked administrators and often include a prize.\n", string);
					format(string, sizeof(string), "%sEvents can be anything from demolition derby, to deathmatch and even more.\n\n", string);

					format(string, sizeof(string), "%s{98B0CD}Event Frequency{FFFFFF}\nWe like to create events when possible, but they aren't our main priority and therefore\n", string);
					format(string, sizeof(string), "%sare a priverlage. However, events are created at the discretion of the online administrator(s).\n\n", string);

					format(string, sizeof(string), "%s{98B0CD}Prizes{FFFFFF}\nA prize may be given to the event winner. Unless a server owner is managing the event,\n", string);
					format(string, sizeof(string), "%sthe prize will almost always be cash.\nThis is due to the fact only RCON administrators can set player statistics.", string);
					ShowPlayerDialog(playerid, 123, DIALOG_STYLE_MSGBOX, "Event Information", string, "OK", "");
    			}
    			case 3: // House Information
     			{
					new string[1200];
					format(string, sizeof(string), "%s{98B0CD}Player Houses{FFFFFF}\nPlayer houses allow you to have somewhere you can call your own. \n", string);
					format(string, sizeof(string), "%sHouses are excellent places to hide from the police or chat with your friends. \n\n", string);

					format(string, sizeof(string), "%s{98B0CD}Pricing{FFFFFF}\nAt this time, houses will be available for a low price due to the server \n", string);
					format(string, sizeof(string), "%sbeing new. Over time, the prices will increase to prevent them from being obtainable too easily.\n", string);
					format(string, sizeof(string), "%sDonors may receive a free vehicle, depending on the donor package they choose.\n\n", string);

					format(string, sizeof(string), "%s{98B0CD}House Creation{FFFFFF}\nHouses can only be created by our head administrator and above. \n", string);
					format(string, sizeof(string), "%sPlayers who donate will be able to request a house wherever they wish, within reason.", string);
					ShowPlayerDialog(playerid, 123, DIALOG_STYLE_MSGBOX, "House Information", string, "OK", "");
    			}
    			case 4: // How to rob a store
     			{
					new string[1200];
					format(string, sizeof(string), "%s{98B0CD}Robbing Stores{FFFFFF}\nTo rob a store, enter its marker. There's usually an icon above the store too.\n", string);
					format(string, sizeof(string), "%sStores may be unavailable to rob for a short time after the previous robbery.\n\n", string);

					format(string, sizeof(string), "%sOnce in-store, find the robbery marker. This is clearly marked \"ROBBERY\". \n", string);
					format(string, sizeof(string), "%sThese are usually by the store's counter, however they can also be found in \nback rooms.\n\n", string);

					format(string, sizeof(string), "%sTo begin robbing the store, press your walk key (ALT by default) or type \n{FFDC2E}/robstore{FFFFFF} whilst inside the robbery marker.\n\n", string);
					format(string, sizeof(string), "%sStay in the marker until the robbery completes, and you'll get \nmoney/XP.", string);
					ShowPlayerDialog(playerid, 123, DIALOG_STYLE_MSGBOX, "Store Robberies", string, "OK", "");
    			}
    			case 5: // Tokens
     			{
					new string[1200];
					format(string, sizeof(string), "%s{98B0CD}Tokens{FFFFFF}\nTokens are given to players by administrators. They can be exchanged\n", string);
					format(string, sizeof(string), "%sfor vehicles and houses.\n\n", string);
					ShowPlayerDialog(playerid, 123, DIALOG_STYLE_MSGBOX, "Tokens", string, "OK", "");
    			}
       		}
   		}
   	}

   	if(dialogid == 123)
   	{
   	    if(response || !response)
   	    {
   	    	ShowPlayerDialog(playerid, DIALOG_HELP, DIALOG_STYLE_LIST, "CZCNR Help", "Player Commands\nServer Admins\nHosted Events\nPlayer Houses\nStore Robberies\nTokens", "Go", "Cancel");
   	    }
	}

    // Mechanic vehicle colour dialog
    if(dialogid == DIALOG_MECHCOLOUR)
    {
        new currentVehID = GetPlayerVehicleID(playerid);
        // If the user clicked on an item
        if(response)
        {
  			switch(listitem)
    		{
    			case 0: // Dark Grey
     			{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}You re-coloured the vehicle for {FFDC2E}$500");
					PlayerPlaySound(playerid, 1134, 0.0, 0.0, 0.0);
					playerTakeMoney(playerid, 500);

					ChangeVehicleColor(currentVehID, 252, 252);
    			}
 	    		case 1: // White
  	    		{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}You re-coloured the vehicle for {FFDC2E}$500");
					PlayerPlaySound(playerid, 1134, 0.0, 0.0, 0.0);
					playerTakeMoney(playerid, 500);

					ChangeVehicleColor(currentVehID, 1, 1);
   	   	 		}
     	    	case 2: // Yellow
     	    	{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}You re-coloured the vehicle for {FFDC2E}$500");
					PlayerPlaySound(playerid, 1134, 0.0, 0.0, 0.0);
					playerTakeMoney(playerid, 500);

					ChangeVehicleColor(currentVehID, 194, 194);
     	    	}
     	    	case 3: // Red
     	    	{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}You re-coloured the vehicle for {FFDC2E}$500");
					PlayerPlaySound(playerid, 1134, 0.0, 0.0, 0.0);
					playerTakeMoney(playerid, 500);

					ChangeVehicleColor(currentVehID, 181, 181);
     	    	}
     	    	case 4: // Bubble Gum Pink
     	    	{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}You re-coloured the vehicle for {FFDC2E}$500");
					PlayerPlaySound(playerid, 1134, 0.0, 0.0, 0.0);
					playerTakeMoney(playerid, 500);

                    ChangeVehicleColor(currentVehID, 146, 146);
     	    	}
     	    	case 5: // Purple
     	    	{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}You re-coloured the vehicle for {FFDC2E}$500");
					PlayerPlaySound(playerid, 1134, 0.0, 0.0, 0.0);
					playerTakeMoney(playerid, 500);

					ChangeVehicleColor(currentVehID, 233, 233);
     	    	}
     	    	case 6: // Blue
     	    	{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}You re-coloured the vehicle for {FFDC2E}$500");
					PlayerPlaySound(playerid, 1134, 0.0, 0.0, 0.0);
					playerTakeMoney(playerid, 500);

					ChangeVehicleColor(currentVehID, 162, 162);
     	    	}
       		}
   		}
   	}

    // Hospital dialog
    if(dialogid == DIALOG_HOSPITAL)
    {
        // If the user clicked on a hospital item
        if(response)
        {
  			switch(listitem)
    		{
    			case 0: // Full HP - $1,000
     			{
     			    if (playerData[playerid][playerMoney] >= 1000)
     			    {
						SetPlayerHealth(playerid, 100.0);
						SendClientMessage(playerid, COLOR_WHITE, "{F78181}[HOSPITAL] {FFFFFF}You have been healed.");
						playerTakeMoney(playerid, 1000);
					}
					else
					{
					   SendClientMessage(playerid, COLOR_WHITE, "{F78181}[HOSPITAL] {FFFFFF}You cannot afford this.");
					}
    			}
    			case 1: // Cure STDs - $2,000
     			{
     			    if (playerData[playerid][playerMoney] >= 2000)
     			    {
						SetPlayerHealth(playerid, 100.0);
						SendClientMessage(playerid, COLOR_WHITE, "{F78181}[HOSPITAL] {FFFFFF}You have been cured.");
						playerTakeMoney(playerid, 3000);
						playerData[playerid][hasSTD] = false;
						KillTimer(playerData[playerid][rapedTimer]);
					}
					else
					{
					   SendClientMessage(playerid, COLOR_WHITE, "{F78181}[HOSPITAL] {FFFFFF}You cannot afford this.");
					}
    			}
    			case 2: // Health Insurance - $20,000
     			{
     			    if (playerData[playerid][playerMoney] >= 20000)
     			    {
						if (!playerData[playerid][healthInsurance])
						{
							SendClientMessage(playerid, COLOR_WHITE, "{F78181}[HOSPITAL] {FFFFFF}You now have health insurance.");
							playerTakeMoney(playerid, 20000);

							playerData[playerid][healthInsurance] = 1;
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{F78181}[HOSPITAL] {FFFFFF}You already have health insurance.");
						}
					}
					else
					{
					   SendClientMessage(playerid, COLOR_WHITE, "{F78181}[HOSPITAL] {FFFFFF}You cannot afford this.");
					}
    			}
       		}
   		}
   	}

    // Undercover Police Dialog
    if(dialogid == DIALOG_UNDERCOVER)
    {
        // If the user clicked on askin
        if(response)
        {
  			switch(listitem)
    		{
    			case 0: // Male 1
     			{
					SetPlayerSkin(playerid, 6);
				}
    			case 1: // Male 2
     			{
                    SetPlayerSkin(playerid, 17);
    			}
    			case 2: // Male 3
     			{
                    SetPlayerSkin(playerid, 21);
    			}
    			case 3: // Female 1
     			{
                    SetPlayerSkin(playerid, 41);
    			}
    			case 4: // Female 2
     			{
                    SetPlayerSkin(playerid, 56);
    			}
    			case 5: // Female 3
     			{
                    SetPlayerSkin(playerid, 91);
    			}
       		}
       		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[UNDERCOVER] {FFFFFF}You're now an undercover cop. Your name color is not affected by this status.");
   		}
   	}

    // Ammunation dialog
    if(dialogid == DIALOG_AMMU)
    {
        // If the user clicked on a gun item
        if(response)
        {
			if(GetPlayerInterior(playerid) == 7 || GetPlayerInterior(playerid) == 6 || GetPlayerInterior(playerid) == 1)
			{
				switch(listitem)
				{
					case 0: // Melee weapons
					{
						ShowPlayerDialog(playerid, DIALOG_AMMU_MELEE, DIALOG_STYLE_LIST, "Ammunation - Melee weapons", "Brass knuckles\nGolf club\nKnife\nBaseball  bat\nShovel\nPool cue\nChainsaw\nPurple dildo\nCamera", "Purchase", "Cancel");
					}

					case 1: // Handguns
					{
						ShowPlayerDialog(playerid, DIALOG_AMMU_HANDGUNS, DIALOG_STYLE_LIST, "Ammunation - Handguns", "Colt .45\nSilenced 9mm\nDesert Eagle",  "Purchase", "Cancel");
					}

					case 2: // Sub-machine guns
					{
						ShowPlayerDialog(playerid, DIALOG_AMMU_SUBMACHINES, DIALOG_STYLE_LIST, "Ammunation - Sub-machine guns", "Micro Uzi\nTec-9\nMP5", "Purchase",  "Cancel");
					}

					case 3: // Shotguns
					{
						ShowPlayerDialog(playerid, DIALOG_AMMU_SHOTGUNS, DIALOG_STYLE_LIST, "Ammunation - Shotguns", "Pump-action shotgun\nSawn-off shotgun\nCombat  shotgun", "Purchase", "Cancel");
					}

					case 4: // Assault rifles
					{
						ShowPlayerDialog(playerid, DIALOG_AMMU_ASSAULTRIFLES, DIALOG_STYLE_LIST, "Ammunation - Assault rifles", "AK-47\nM4", "Purchase", "Cancel");
					}

					case 5: // Rifles
					{
						ShowPlayerDialog(playerid, DIALOG_AMMU_RIFLES, DIALOG_STYLE_LIST, "Ammunation - Rifles (long range)", "Country rifle\nSniper rifle",  "Purchase", "Cancel");
					}

					case 6: // Weapon skill
					{
						if (playerData[playerid][weaponSkill] != 1)
						{
							if (playerData[playerid][playerMoney] >= 10000)
							{
								SetPlayerSkillLevel(playerid, WEAPONSKILL_SAWNOFF_SHOTGUN, 999);
								playerData[playerid][weaponSkill] = 1;
								playerTakeMoney(playerid, 10000);
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You have upgraded your weapon skill.");
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You cannot afford this.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You already have the maximum skill available.");
						}
					}
				}
			}
		}
   	}

    if(dialogid == DIALOG_AMMU_MELEE)
    {
        if(response)
        {
			if(GetPlayerInterior(playerid) == 7 || GetPlayerInterior(playerid) == 6 || GetPlayerInterior(playerid) == 1)
			{
				switch(listitem)
				{
					case 0: // Brass knuckles
					{
						if (playerData[playerid][playerMoney] >= WEAPONPRICES_BRASSKNUCKLES)
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You have purchased {FFDC2E}Brass knuckles{FFFFFF}.");
							playerTakeMoney(playerid, WEAPONPRICES_BRASSKNUCKLES);
							GivePlayerWeaponEx(playerid, 1, 1);
						}
						else
						{
						   SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You cannot afford this.");
						}
					}

					case 1: // Golf club
					{
						if (playerData[playerid][playerMoney] >= WEAPONPRICES_GOLFCLUB)
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You have purchased a {FFDC2E}Golf club{FFFFFF}.");
							playerTakeMoney(playerid, WEAPONPRICES_GOLFCLUB);
							GivePlayerWeaponEx(playerid, 2, 1);
						}
						else
						{
						   SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You cannot afford this.");
						}
					}

					case 2: // Knife
					{
						if (playerData[playerid][playerMoney] >= WEAPONPRICES_KNIFE)
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You have purchased a {FFDC2E}Knife{FFFFFF}.");
							playerTakeMoney(playerid, WEAPONPRICES_KNIFE);
							GivePlayerWeaponEx(playerid, 4, 1);
						}
						else
						{
						   SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You cannot afford this.");
						}
					}

					case 3: // Baseball bat
					{
						if (playerData[playerid][playerMoney] >= WEAPONPRICES_BASEBALLBAT)
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You have purchased a {FFDC2E}Baseball bat{FFFFFF}.");
							playerTakeMoney(playerid, WEAPONPRICES_BASEBALLBAT);
							GivePlayerWeaponEx(playerid, 5, 1);
						}
						else
						{
						   SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You cannot afford this.");
						}
					}

					case 4: // Shovel
					{
						if (playerData[playerid][playerMoney] >= WEAPONPRICES_SHOVEL)
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You have purchased a {FFDC2E}Shovel{FFFFFF}.");
							playerTakeMoney(playerid, WEAPONPRICES_SHOVEL);
							GivePlayerWeaponEx(playerid, 6, 1);
						}
						else
						{
						   SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You cannot afford this.");
						}
					}

					case 5: // Pool cue
					{
						if (playerData[playerid][playerMoney] >= WEAPONPRICES_POOLCUE)
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You have purchased a {FFDC2E}Pool cue{FFFFFF}.");
							playerTakeMoney(playerid, WEAPONPRICES_POOLCUE);
							GivePlayerWeaponEx(playerid, 7, 1);
						}
						else
						{
						   SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You cannot afford this.");
						}
					}

					case 6: // Chainsaw
					{
						if (playerData[playerid][playerMoney] >= WEAPONPRICES_CHAINSAW)
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You have purchased a {FFDC2E}Chainsaw{FFFFFF}.");
							playerTakeMoney(playerid, 750);
							GivePlayerWeaponEx(playerid, 9, 1);
						}
						else
						{
						   SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You cannot afford this.");
						}
					}

					case 7: // Purple dildo
					{
						if (playerData[playerid][playerMoney] >= WEAPONPRICES_PURPLEDILDO)
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You have purchased a {FFDC2E}Purple dildo{FFFFFF}.");
							playerTakeMoney(playerid, 250);
							GivePlayerWeaponEx(playerid, 10, 1);
						}
						else
						{
						   SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You cannot afford this.");
						}
					}

					case 8: // Camera
					{
						if (playerData[playerid][playerMoney] >= WEAPONPRICES_CAMERA)
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You have purchased a {FFDC2E}Camera{FFFFFF}.");
							playerTakeMoney(playerid, 100);
							GivePlayerWeaponEx(playerid, 43, 20);
						}
						else
						{
						   SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You cannot afford this.");
						}
					}
				}

				ShowPlayerDialog(playerid, DIALOG_AMMU_MELEE, DIALOG_STYLE_LIST, "Ammunation - Melee weapons", "Brass knuckles\nGolf club\nKnife\nBaseball bat\nShovel\nPool  cue\nChainsaw\nPurple dildo\nCamera", "Purchase", "Cancel");
			}
		}
		else
		{
			if(GetPlayerInterior(playerid) == 7 || GetPlayerInterior(playerid) == 6 || GetPlayerInterior(playerid) == 1)
			{
				ShowPlayerDialog(playerid, DIALOG_AMMU, DIALOG_STYLE_LIST, "Ammunation", "Melee\nHandguns\nSub-machine guns\nShotguns\nAssault rifles\nRifles\n {D87C3E}$10,000  {FFFFFF}Weapon Skills {FFBF00}(Permanent)", "Go", "Cancel");
			}
		}
   	}

    if(dialogid == DIALOG_AMMU_HANDGUNS)
    {
        if(response)
        {
			if(GetPlayerInterior(playerid) == 7 || GetPlayerInterior(playerid) == 6 || GetPlayerInterior(playerid) == 1)
			{
				switch(listitem)
				{
					case 0:
					{
						if (playerData[playerid][playerMoney] >= WEAPONPRICES_COLT45)
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You have purchased a {FFDC2E}Colt .45{FFFFFF}.");
							playerTakeMoney(playerid, WEAPONPRICES_COLT45);
							GivePlayerWeaponEx(playerid, 22, 500);
						}
						else
						{
						   SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You cannot afford this.");
						}
					}
					case 1:
					{
						if (playerData[playerid][playerMoney] >= WEAPONPRICES_SILENCED9MM)
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You have purchased a {FFDC2E}Silenced 9mm{FFFFFF}.");
							playerTakeMoney(playerid, WEAPONPRICES_SILENCED9MM);
							GivePlayerWeaponEx(playerid, 23, 500);
						}
						else
						{
						   SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You cannot afford this.");
						}
					}
					case 2:
					{
						if (playerData[playerid][playerMoney] >= WEAPONPRICES_DESERTEAGLE)
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You have purchased a {FFDC2E}Desert Eagle{FFFFFF}.");
							playerTakeMoney(playerid, WEAPONPRICES_DESERTEAGLE);
							GivePlayerWeaponEx(playerid, 24, 500);
						}
						else
						{
						   SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You cannot afford this.");
						}
					}
				}

				ShowPlayerDialog(playerid, DIALOG_AMMU_HANDGUNS, DIALOG_STYLE_LIST, "Ammunation - Handguns", "Colt .45\nSilenced 9mm\nDesert Eagle", "Purchase", "Cancel");
			}
		}
		else
		{
			if(GetPlayerInterior(playerid) == 7 || GetPlayerInterior(playerid) == 6 || GetPlayerInterior(playerid) == 1)
			{
				ShowPlayerDialog(playerid, DIALOG_AMMU, DIALOG_STYLE_LIST, "Ammunation", "Melee\nHandguns\nSub-machine guns\nShotguns\nAssault rifles\nRifles\n {D87C3E}$10,000    {FFFFFF}Weapon Skills {FFBF00}(Permanent)", "Go", "Cancel");
			}
		}
   	}

    if(dialogid == DIALOG_AMMU_SUBMACHINES)
    {
        if(response)
        {
			if(GetPlayerInterior(playerid) == 7 || GetPlayerInterior(playerid) == 6 || GetPlayerInterior(playerid) == 1)
			{
				switch(listitem)
				{
					case 0:
					{
						if (playerData[playerid][playerMoney] >= WEAPONPRICES_MICROUZI)
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You have purchased a {FFDC2E}Micro Uzi{FFFFFF}.");
							playerTakeMoney(playerid, WEAPONPRICES_MICROUZI);
							GivePlayerWeaponEx(playerid, 28, 750);
						}
						else
						{
						   SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You cannot afford this.");
						}
					}
					case 1:
					{
						if (playerData[playerid][playerMoney] >= WEAPONPRICES_TEC9)
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You have purchased a {FFDC2E}Tec-9{FFFFFF}.");
							playerTakeMoney(playerid, WEAPONPRICES_TEC9);
							GivePlayerWeaponEx(playerid, 32, 750);
						}
						else
						{
						   SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You cannot afford this.");
						}
					}
					case 2:
					{
						if (playerData[playerid][playerMoney] >= WEAPONPRICES_MP5)
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You have purchased a {FFDC2E}MP5{FFFFFF}.");
							playerTakeMoney(playerid, WEAPONPRICES_MP5);
							GivePlayerWeaponEx(playerid, 29, 750);
						}
						else
						{
						   SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You cannot afford this.");
						}
					}
				}

				ShowPlayerDialog(playerid, DIALOG_AMMU_SUBMACHINES, DIALOG_STYLE_LIST, "Ammunation - Sub-machine guns", "Micro Uzi\nTec-9\nMP5", "Purchase", "Cancel");
			}
		}
		else
		{
			if(GetPlayerInterior(playerid) == 7 || GetPlayerInterior(playerid) == 6 || GetPlayerInterior(playerid) == 1)
			{
				ShowPlayerDialog(playerid, DIALOG_AMMU, DIALOG_STYLE_LIST, "Ammunation", "Melee\nHandguns\nSub-machine guns\nShotguns\nAssault rifles\nRifles\n {D87C3E}$10,000    {FFFFFF}Weapon Skills {FFBF00}(Permanent)", "Go", "Cancel");
			}
		}
   	}

    if(dialogid == DIALOG_AMMU_SHOTGUNS)
    {
        if(response)
        {
			if(GetPlayerInterior(playerid) == 7 || GetPlayerInterior(playerid) == 6 || GetPlayerInterior(playerid) == 1)
			{
				switch(listitem)
				{
					case 0:
					{
						if (playerData[playerid][playerMoney] >= WEAPONPRICES_PUMPACTION)
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You have purchased a {FFDC2E}Pump-action Shotgun{FFFFFF}.");
							playerTakeMoney(playerid, WEAPONPRICES_PUMPACTION);
							GivePlayerWeaponEx(playerid, 25, 500);
						}
						else
						{
						   SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You cannot afford this.");
						}
					}
					case 1:
					{
						if (playerData[playerid][playerMoney] >= WEAPONPRICES_SAWNOFF)
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You have purchased a {FFDC2E}Sawn-off Shotgun{FFFFFF}.");
							playerTakeMoney(playerid, WEAPONPRICES_SAWNOFF);
							GivePlayerWeaponEx(playerid, 26, 500);
						}
						else
						{
						   SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You cannot afford this.");
						}
					}
					case 2:
					{
						if (playerData[playerid][playerMoney] >= WEAPONPRICES_COMBATSHOTGUN)
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You have purchased a {FFDC2E}Combat Shotgun{FFFFFF}.");
							playerTakeMoney(playerid, WEAPONPRICES_COMBATSHOTGUN);
							GivePlayerWeaponEx(playerid, 27, 500);
						}
						else
						{
						   SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You cannot afford this.");
						}
					}
				}

				ShowPlayerDialog(playerid, DIALOG_AMMU_SHOTGUNS, DIALOG_STYLE_LIST, "Ammunation - Shotguns", "Pump-action shotgun\nSawn-off shotgun\nCombat shotgun",  "Purchase", "Cancel");
			}
		}
		else
		{
			if(GetPlayerInterior(playerid) == 7 || GetPlayerInterior(playerid) == 6 || GetPlayerInterior(playerid) == 1)
			{
				ShowPlayerDialog(playerid, DIALOG_AMMU, DIALOG_STYLE_LIST, "Ammunation", "Melee\nHandguns\nSub-machine guns\nShotguns\nAssault rifles\nRifles\n {D87C3E}$10,000    {FFFFFF}Weapon Skills {FFBF00}(Permanent)", "Go", "Cancel");
			}
		}
   	}

	if(dialogid == DIALOG_AMMU_ASSAULTRIFLES)
	{
		if(response)
		{
			if(GetPlayerInterior(playerid) == 7 || GetPlayerInterior(playerid) == 6 || GetPlayerInterior(playerid) == 1)
			{
				switch(listitem)
				{
					case 0:
					{
						if (playerData[playerid][playerMoney] >= WEAPONPRICES_AK47)
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You have purchased an {FFDC2E}AK-47{FFFFFF}.");
							playerTakeMoney(playerid, WEAPONPRICES_AK47);
							GivePlayerWeaponEx(playerid, 30, 1000);
						}
						else
						{
						   SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You cannot afford this.");
						}
					}
					case 1:
					{
						if (playerData[playerid][playerMoney] >= WEAPONPRICES_M4)
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You have purchased a {FFDC2E}M4{FFFFFF}.");
							playerTakeMoney(playerid, WEAPONPRICES_M4);
							GivePlayerWeaponEx(playerid, 31, 1000);
						}
						else
						{
						   SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You cannot afford this.");
						}
					}
				}

				ShowPlayerDialog(playerid, DIALOG_AMMU_ASSAULTRIFLES, DIALOG_STYLE_LIST, "Ammunation - Assault rifles", "AK-47\nM4", "Purchase", "Cancel");
			}
		}
		else
		{
			if(GetPlayerInterior(playerid) == 7 || GetPlayerInterior(playerid) == 6 || GetPlayerInterior(playerid) == 1)
			{
				ShowPlayerDialog(playerid, DIALOG_AMMU, DIALOG_STYLE_LIST, "Ammunation", "Melee\nHandguns\nSub-machine guns\nShotguns\nAssault rifles\nRifles\n {D87C3E}$10,000    {FFFFFF}Weapon Skills {FFBF00}(Permanent)", "Go", "Cancel");
			}
		}
	}

    if(dialogid == DIALOG_AMMU_RIFLES)
    {
        if(response)
        {
			if(GetPlayerInterior(playerid) == 7 || GetPlayerInterior(playerid) == 6 || GetPlayerInterior(playerid) == 1)
			{
				switch(listitem)
				{
					case 0:
					{
						if (playerData[playerid][playerMoney] >= WEAPONPRICES_COUNTRYRIFLE)
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You have purchased a {FFDC2E}Country Rifle{FFFFFF}.");
							playerTakeMoney(playerid, WEAPONPRICES_COUNTRYRIFLE);
							GivePlayerWeaponEx(playerid, 33, 250);
						}
						else
						{
						   SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You cannot afford this.");
						}
					}
					case 1:
					{
						if (playerData[playerid][playerMoney] >= WEAPONPRICES_SNIPERRIFLE)
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You have purchased a {FFDC2E}Sniper Rifle{FFFFFF}.");
							playerTakeMoney(playerid, WEAPONPRICES_SNIPERRIFLE);
							GivePlayerWeaponEx(playerid, 34, 250);
						}
						else
						{
						   SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[AMMUNATION] {FFFFFF}You cannot afford this.");
						}
					}
				}

				ShowPlayerDialog(playerid, DIALOG_AMMU_RIFLES, DIALOG_STYLE_LIST, "Ammunation - Rifles (long range)", "Country rifle\nSniper rifle", "Purchase", "Cancel");
			}
		}
		else
		{
			if(GetPlayerInterior(playerid) == 7 || GetPlayerInterior(playerid) == 6 || GetPlayerInterior(playerid) == 1)
			{
				ShowPlayerDialog(playerid, DIALOG_AMMU, DIALOG_STYLE_LIST, "Ammunation", "Melee\nHandguns\nSub-machine guns\nShotguns\nAssault rifles\nRifles\n {D87C3E}$10,000    {FFFFFF}Weapon Skills {FFBF00}(Permanent)", "Go", "Cancel");
			}
		}
   	}

    // City Hall dialog
    if(dialogid == DIALOG_CITYHALL)
    {
        // If the user clicked on a task
        if(response)
        {
  			switch(listitem)
    		{
    			case 0: // Job Change
     			{
					if(playerData[playerid][playerMoney] >= 2000)
					{
					    playerTakeMoney(playerid, 2000);
						new jobList[250];
						format(jobList, sizeof(jobList), "Kidnapper\nMechanic\nWeapon dealer\nRapist\nHitman\nDrug Dealer\nTerrorist");
						ShowPlayerDialog(playerid, DIALOG_JOBCHANGE, DIALOG_STYLE_LIST, "Choose your job", jobList, "Select", "Close");
					}
					else
					{
					    SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[CITY HALL] {FFFFFF}You cannot afford this.");
					}
     			}
			}
		}
	}

	if(dialogid == DIALOG_JOBCHANGE)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0: // Kidnapper
				{
					playerData[playerid][playerJob] = JOB_KIDNAPPER;
					playerData[playerid][playerCanKidnap] = true;

					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[CITY HALL] {FFFFFF}You're now a kidnapper.");
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}Use {FFDC2E}/kidnap {FFFFFF}to kidnap players.");
				}
				case 1: // Mechanic
				{
					playerData[playerid][playerJob] = JOB_MECHANIC;
					playerData[playerid][playerCanRepair] = true;
					playerData[playerid][playerCanFlip] = true;
					playerData[playerid][playerCanNOS] = true;
					playerData[playerid][playerCanREMP] = true;

					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[CITY HALL] {FFFFFF}You're now a mechanic.");
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}Use {FFDC2E}/mech {FFFFFF}to view available job commands.");
				}
				case 2: // Weapon dealer
				{
					playerData[playerid][playerJob] = JOB_WEAPONDEALER;

					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[CITY HALL] {FFFFFF}You're now a weapon dealer.");
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}Use {FFDC2E}/sellgun {FFFFFF}to offer weapons to players.");
				}
				case 3: // Rapist
				{
					playerData[playerid][playerJob] = JOB_RAPIST;

					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[CITY HALL] {FFFFFF}You're now a rapist.");
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}Use {FFDC2E}/rape {FFFFFF}to infect players with an STD.");
				}
				case 4: // Hitman
				{
					playerData[playerid][playerJob] = JOB_HITMAN;

					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[CITY HALL] {FFFFFF}You're now a hitman.");
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}Use {FFDC2E}/track {FFFFFF}to locate players. Use {FFDC2E}/hitlist {FFFFFF}to view players with a bounty on them.");
				}
				case 5: // Drug Dealer
				{
					playerData[playerid][playerJob] = JOB_DRUGDEALER;

					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[CITY HALL] {FFFFFF}You're now a drug dealer.");
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}Use {FFDC2E}/sellweed {FFFFFF}whilst in an ice cream truck to sell drugs to players.");
				}
				case 6: // Terrorist
				{
					playerData[playerid][playerJob] = JOB_TERRORIST;

					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[CITY HALL] {FFFFFF}You're now a terrorist.");
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}Use {FFDC2E}/usec4 {FFFFFF}whilst in possession of explosives to blow up objectives such as the bank vault, or the jail.");
				}
			}
		}
	}

   	// Gym dialog
    if(dialogid == DIALOG_GYM)
    {
        // If the user clicked on a hospital item
        if(response)
        {
  			switch(listitem)
    		{
    			case 0: // Default - 4
     			{
 			        SetPlayerFightingStyle(playerid, 4);
 			        playerData[playerid][playerFightStyle] = 4;
 			        SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[GYM] {FFFFFF}You have learnt the default fight style.");
				}
    			case 1: // Boxing 20k - 5
     			{
     			    if (playerData[playerid][playerMoney] >= 20000)
     			    {
     			        SetPlayerFightingStyle(playerid, 5);
     			        playerData[playerid][playerFightStyle] = 5;
						playerTakeMoney(playerid, 20000);
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[GYM] {FFFFFF}You have learnt the art of boxing.");
					}
    			}
    			case 2: // Kungfu 15k - 6
     			{
     			    if (playerData[playerid][playerMoney] >= 15000)
     			    {
	 			        SetPlayerFightingStyle(playerid, 6);
	 			        playerData[playerid][playerFightStyle] = 6;
						playerTakeMoney(playerid, 15000);
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[GYM] {FFFFFF}You have learnt the art of Kungfu");
					}
    			}
    			case 3: // Knee-head 12k - 7
     			{
     			    if (playerData[playerid][playerMoney] >= 12000)
     			    {
	 			        SetPlayerFightingStyle(playerid, 7);
	 			        playerData[playerid][playerFightStyle] = 7;
						playerTakeMoney(playerid, 12000);
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[GYM] {FFFFFF}You have learnt the art of putting your knee to someone's head.");
					}
    			}
    			case 4: // Grab-kick 10k - 15
     			{
     			    if (playerData[playerid][playerMoney] >= 10000)
     			    {
	 			        SetPlayerFightingStyle(playerid, 15);
	 			        playerData[playerid][playerFightStyle] = 15;
						playerTakeMoney(playerid, 10000);
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[GYM] {FFFFFF}You have learnt the art of grabbing and kicking someone, hard.");
					}
    			}
    			case 5: // Elbow 8k - 16
     			{
     			    if (playerData[playerid][playerMoney] >= 8000)
     			    {
	 			        SetPlayerFightingStyle(playerid, 16);
	 			        playerData[playerid][playerFightStyle] = 16;
						playerTakeMoney(playerid, 8000);
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[GYM] {FFFFFF}BAM! Elbow to the face! You can do this now.");
					}
    			}
       		}
   		}
   	}

    // Teleport dialog
    if(dialogid == DIALOG_ATELEPORT)
    {
        // If the user clicked on a teleport location
        if(response)
        {
  			switch(listitem)
    		{
    			case 0: // Teleport to Bank
     			{
					// -1509.1115, 920.4254, 7.1875
					SetPlayerPos(playerid, -1509.1115, 920.4254, 7.1875);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);
    			}
 	    		case 1: // Teleport to SFPD
  	    		{
					// -1605.7467, 713.4993, 13.4357
					SetPlayerPos(playerid, -1605.7467, 713.4993, 13.4357);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);
   	   	 		}
     	    	case 2: // Teleport to SFPD Parking Lot
     	    	{
					// -1606.8942, 662.3884, 7.1875
					SetPlayerPos(playerid, -1606.8942, 662.3884, 7.1875);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);
     	    	}
     	    	case 3: // Teleport to Army Spawn
     	    	{
					// -1253.1248, 458.0851, 7.1875
					SetPlayerPos(playerid, -1253.1248, 458.0851, 7.1875);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);
     	    	}
     	    	case 4: // Teleport to CIA/FBI Spawn
     	    	{
					// -2442.1868, 499.2131, 30.0924
					SetPlayerPos(playerid, -2442.1868, 499.2131, 30.0924);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);
     	    	}
				case 5: // Teleport to Ammunation
				{
					// -2628.7629, 214.2198, 4.3952
					SetPlayerPos(playerid, -2628.7629, 214.2198, 4.3952);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);
				}
				case 6: // Teleport to Airport
				{
					// -1315.6328, -227.7303, 14.1484
					SetPlayerPos(playerid, -1315.6328, -227.7303, 14.1484);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);
				}
				case 7: // Teleport to Hosital
				{
					// -2647.6118, 625.6426, 14.4531
					SetPlayerPos(playerid, -2647.6118, 625.6426, 14.4531);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);
				}
				case 8: // Teleport to Supa Save
				{
					// -2442.5156, 749.2994, 35.178
					SetPlayerPos(playerid, -2442.5156, 749.2994, 35.178);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);
				}
				case 9: // Teleport to Church
				{
					// -1982.1945, 1117.7213, 53.1233
					SetPlayerPos(playerid, -1982.1945, 1117.7213, 53.1233);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);
				}
				case 10: // Teleport to Suburban
				{
					// -2515.1592, -25.7249, 25.6172
					SetPlayerPos(playerid, -2515.1592, -25.7249, 25.6172);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);
				}
				case 11: // Teleport to Gym
				{
					// -2267.0471, -161.5091, 35.3203
					SetPlayerPos(playerid, -2267.0471, -161.5091, 35.3203);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);
				}
				case 12: // Teleport to LS Airport
				{
				    // 1875.0139, -2612.8547, 13.5469
					SetPlayerPos(playerid, 1875.0139, -2612.8547, 13.5469);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);
				}
				case 13: // Teleport to Van Courier Job
				{
				    // -2499.7781, -614.3375, 132.5625
					SetPlayerPos(playerid, -2499.7781, -614.3375, 132.5625);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);
				}
				case 14: // Teleport to VIP Lounge
				{
				    // -1790.8135, 572.1437, 35.1641
					SetPlayerPos(playerid, -1790.8135, 572.1437, 35.16415);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);
				}
				case 15: // Car Drop
				{
				    // -1734.0756, 190.9162, 3.5547
					SetPlayerPos(playerid, -1734.0756, 190.9162, 3.5547);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);
				}
				case 16: // Bomb Shop
				{
				    // -1780.5876, 1205.9221 25.1250
					SetPlayerPos(playerid, -1780.5876, 1205.9221, 25.1250);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);
				}
				case 17: // Job Centre
				{
				    // -1885.1152, 826.8466, 35.1728
					SetPlayerPos(playerid, -1885.1152, 826.8466, 35.1728);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);
				}
				case 18: // Trucking
				{
					SetPlayerPos(playerid, -1838.5251, 146.5409, 15.1172);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);
				}
				case 19: // Admin Lounge
				{
					SetPlayerPos(playerid, -2035.9037, 1183.0739, 45.2969);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);
				}
				case 20: // Dealership
				{
					SetPlayerPos(playerid, -1929.2322, 265.5342, 41.0469);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);
				}
				case 21: // Forklift
				{
					SetPlayerPos(playerid, -1703.7598, 90.9923, 3.5547);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);
				}
				case 22: // Minigames
				{
					SetPlayerPos(playerid, -1551.0940, 1168.6372, 7.1875);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);
				}
       		}
   		}
   	}

	if(dialogid == 699)
	{
		if(response)
		{
			showDealershipDialogCategory(playerid, listitem);
		}
	}

	if(dialogid == 701)
	{
		if(response)
		{
			for(new d = 0; d < sizeof(dealershipData); d++)
			{
				if(dealershipData[d][vehicle_type] == category_choice[playerid])
				{
					if(dealershipData[d][response_id] == listitem)
					{
						if(playerData[playerid][playerMoney] >= dealershipData[d][vehicle_price] && dealershipData[d][vehicle_price] != 0 || playerData[playerid][rTokens] >= dealershipData[d][token_price])
						{
							new
								pQuery[200],
								maxVehicles,
								Float:x,
								Float:y,
								Float:z,
								Float:a
							;

							if(playerData[playerid][playerTown] == SF)
							{
								if (dealershipData[d][vehicle_type] != DEALERSHIP_AIR)
								{
									x = -1932.7546;
									y = 245.3903;
									z = 40.7497;
									a = 90.0;
								}
								else
								{
									x = -1951.5084;
									y = 262.6088;
									z = 47.7156;
									a = 0.9163;
								}
							}
							else
							{
								x = 1736.789916;
								y = 1861.472778;
								z = 10.820312;
								a = 0.0000;
							}

							format(pQuery, sizeof(pQuery), "SELECT * FROM `vehicles` WHERE `owner` = '%i'", playerData[playerid][actualID]);

							new DBResult:presult, pcount = 0;
							presult = db_query(DB: VEHICLESDB, pQuery);
							pcount = db_num_rows(presult);

							if (playerData[playerid][playerVIPLevel] >= 1)
							{
								maxVehicles = VIP_MAX_VEHICLES;
							}
							else
							{
								maxVehicles = PLAYER_MAX_VEHICLES;
							}

							if (pcount != maxVehicles)
							{
								SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[VEHICLE] {FFFFFF}Please wait, your vehicle is being created.");

								Vehicle_Create(dealershipData[d][vehicle_model], playerData[playerid][actualID], x, y, z, a, playerid);

								if (playerData[playerid][rTokens] >= dealershipData[d][token_price])
								{
									// Use tokens
									playerData[playerid][rTokens] = playerData[playerid][rTokens] - dealershipData[d][token_price];
								}
								else
								{
									playerTakeMoney(playerid, dealershipData[d][vehicle_price]);
								}


								SetTimerEx("dealershipSpawn", 1000, false, "i", playerid);
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You have too many vehicles. Sell a vehicle first.");
							}

							db_free_result(presult);
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot afford this.");
						}
					}
				}
			}
		}
		else
		{
			showDealershipDialogTypes(playerid);
		}
	}

    // House Menu
    if(dialogid == DIALOG_HOUSEMENU)
    {
        // If the user clicked on an option
        if(response)
        {
  			switch(listitem)
    		{
    			case 0: // Upgrade interior
     			{
					new interiorList[600];
					format(interiorList, sizeof(interiorList), "%s\nSmall Interior 1 {D87C3E}$125,000{FFFFFF}", interiorList);
					format(interiorList, sizeof(interiorList), "%s\nSmall Interior 2 {D87C3E}$125,000{FFFFFF}", interiorList);
					format(interiorList, sizeof(interiorList), "%s\nSmall Interior 3 {D87C3E}$125,000{FFFFFF}", interiorList);

					format(interiorList, sizeof(interiorList), "%s\nMedium Interior 1 {D87C3E}$150,000{FFFFFF}", interiorList);
					format(interiorList, sizeof(interiorList), "%s\nMedium Interior 2 {D87C3E}$150,000{FFFFFF}", interiorList);

					format(interiorList, sizeof(interiorList), "%s\nLarge Interior 1 {D87C3E}$250,000{FFFFFF}", interiorList);
					format(interiorList, sizeof(interiorList), "%s\nLarge Interior 2 {D87C3E}$250,000{FFFFFF}", interiorList);
					format(interiorList, sizeof(interiorList), "%s\nLarge Interior 3 {D87C3E}$250,000{FFFFFF}", interiorList);
					format(interiorList, sizeof(interiorList), "%s\nLarge Interior 4 {D87C3E}$250,000{FFFFFF}", interiorList);
					format(interiorList, sizeof(interiorList), "%s\nLarge Interior 5 {D87C3E}$250,000{FFFFFF}", interiorList);

					format(interiorList, sizeof(interiorList), "%s\nSex Chamber {D87C3E}$125,000{FFFFFF}", interiorList);

					format(interiorList, sizeof(interiorList), "%s\nMansion Interior {D87C3E}$1,000,000{FFFFFF}", interiorList);

					ShowPlayerDialog(playerid, DIALOG_HOUSEMENU_INT, DIALOG_STYLE_LIST, "Interior Upgrade", interiorList, "OK", "Close");
				}
    			/*case 1: // Upgrade house
     			{
                    ShowPlayerDialog(playerid, DIALOG_HOUSEMENU_FEATURES, DIALOG_STYLE_LIST, "House Features", "House Safe {D87C3E}$125,000{FFFFFF}\nSecure Lock {D87C3E}$250,000{FFFFFF}", "Go", "Cancel");
    			}*/
   	   	 		case 1: // House title
				{
        			ShowPlayerDialog(playerid, DIALOG_HOUSEMENU_TITLE, DIALOG_STYLE_INPUT, "House Title", "{FFFFFF}Create a house title. Type {58D3F7}none {FFFFFF}to remove the title.", "Save", "Cancel");
				}
				case 2: // House password
				{
					ShowPlayerDialog(playerid, DIALOG_HOUSEMENU_PASSWORD, DIALOG_STYLE_INPUT, "House Password", "{FFFFFF}Create a house password. Type {58D3F7}none {FFFFFF}to remove the password.", "Save", "Cancel");
				}
				case 3: // Set house as spawn
				{
					new
						houseid
					;

					houseid = playerData[playerid][playerInsideHouse];
					playerData[playerid][spawnHouse] = houseStuff[houseid][house_id];

					SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}You will now spawn at your house. Type /removespawn to disable this.");
				}
				case 4: // House Upgrades
				{
					new upgradeList[600];
					format(upgradeList, sizeof(upgradeList), "%s\nHouse Alarm {D87C3E}$25,000{FFFFFF}", upgradeList);
					format(upgradeList, sizeof(upgradeList), "%s\nSecure Lock {D87C3E}$50,000{FFFFFF}", upgradeList);
					format(upgradeList, sizeof(upgradeList), "%s\nZapper Lock {D87C3E}$125,000{FFFFFF}", upgradeList);
					//format(upgradeList, sizeof(upgradeList), "%s\nSemtex Keyhole (x2) {D87C3E}$500,000{FFFFFF}", upgradeList);

					ShowPlayerDialog(playerid, DIALOG_HOUSEMENU_UPGRADE, DIALOG_STYLE_LIST, "House Upgrade", upgradeList, "OK", "Close");
				}
     	    	case 5: // Sell House
     	    	{
					new
						houseid,
						priceInfo[200],
						newPrice
					;

					houseid = playerData[playerid][playerInsideHouse];
					newPrice = houseStuff[houseid][house_price] / 2;

					format(priceInfo, sizeof(priceInfo), "{FFFFFF}Are you sure you wish to sell your house? \nYou will receive {FFDC2E}$%s.", FormatNumber(newPrice));
					ShowPlayerDialog(playerid, DIALOG_HOUSEMENU_SELL, DIALOG_STYLE_MSGBOX, "Sell House", priceInfo, "Sell House", "Cancel");
     	    	}
       		}
   		}
   	}

    if(dialogid == DIALOG_HOUSEMENU_UPGRADE)
    {
        // If the user clicked on an option
        if(response)
        {
			if(playerData[playerid][playerInsideHouse] != -1)
			{
				new
					houseID = playerData[playerid][playerInsideHouse],
					query[300]
				;

				if(!strcmp(houseStuff[houseID][house_owner], playerData[playerid][playerNamee], true))
				{
					switch(listitem)
					{
						case 0: // House Alarm
						{
							if (houseStuff[houseID][houseAlarm])
							{
								// House is already alarmed
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This house already has an alarm.");
							}
							else
							{
								if (playerData[playerid][playerMoney] >= 25000)
								{
									format(query, sizeof(query), "UPDATE `house_data` SET `houseAlarm` = '1' WHERE `house_id` = '%i'", houseStuff[houseID][house_id]);
									db_query(DB: HOUSEDB, query);

									houseStuff[houseID][houseAlarm] = 1;

									SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}You have purchased a {58D3F7}house alarm{FFFFFF} for this house.");
									playerTakeMoney(playerid, 25000);
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You don't have enough cash to purchase this upgrade.");
								}
							}
						}

						case 1: // Secure Lock
						{
							if (houseStuff[houseID][houseLock] == 1)
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This house already has a secure lock.");
							}
							else
							{
								if (playerData[playerid][playerMoney] >= 25000)
								{
									format(query, sizeof(query), "UPDATE `house_data` SET `lockType` = '1' WHERE `house_id` = '%i'", houseStuff[houseID][house_id]);
									db_query(DB: HOUSEDB, query);

									houseStuff[houseID][houseLock] = 1;

									SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}You have purchased a {58D3F7}secure lock{FFFFFF} for this house.");
									playerTakeMoney(playerid, 25000);
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You don't have enough cash to purchase this upgrade.");
								}
							}
						}

						case 2: // Zapper Lock
						{
							if (houseStuff[houseID][houseLock] == 2)
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This house already has an zapper lock.");
							}
							else
							{
								if (playerData[playerid][playerMoney] >= 125000)
								{
									format(query, sizeof(query), "UPDATE `house_data` SET `lockType` = '2' WHERE `house_id` = '%i'", houseStuff[houseID][house_id]);
									db_query(DB: HOUSEDB, query);

									houseStuff[houseID][houseLock] = 2;

									SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}You have purchased a {58D3F7}zapper lock{FFFFFF} for this house.");
									playerTakeMoney(playerid, 125000);
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You don't have enough cash to purchase this upgrade.");
								}
							}
						}

						case 69: // Semtex Keyhole
						{
							if (houseStuff[houseID][houseLock] == 3)
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This house already has a semtex keyhole.");
							}
							else
							{
								format(query, sizeof(query), "UPDATE `house_data` SET `lockType` = '3' WHERE `house_id` = '%i'", houseStuff[houseID][house_id]);
								db_query(DB: HOUSEDB, query);

								houseStuff[houseID][houseLock] = 3;

								SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}You have purchased a {58D3F7}semtex keyhole{FFFFFF} for this house.");
							}
						}
					}
				}
			}
		}
	}

    if(dialogid == DIALOG_HOUSEMENU_INT)
    {
        // If the user clicked on an option
        if(response)
        {
			if(playerData[playerid][playerInsideHouse] != -1)
			{
				new
					houseID = playerData[playerid][playerInsideHouse],
					Float:intX,
					Float:intY,
					Float:intZ,
					Float:intA,
					intID,
					query[300]
				;

				if(!strcmp(houseStuff[houseID][house_owner], playerData[playerid][playerNamee], true))
				{
					switch(listitem)
					{
						case 0: // Small interior 1
						{
							if (houseStuff[houseID][interiorID] == 1)
							{
								ShowPlayerDialog(playerid, DIALOG_HOUSEMENU_LOCK, DIALOG_STYLE_MSGBOX, "Interior Upgrade", "This interior is already in use.", "Close", "");
							}
							else
							{
								if (playerData[playerid][playerMoney] >= 125000)
								{
									intX = 223.0755;
									intY = 1287.6292;
									intZ = 1082.1406;
									intA = 0.7696;
									intID = 1;

									houseStuff[houseID][interiorX] = intX;
									houseStuff[houseID][interiorY] = intY;
									houseStuff[houseID][interiorZ] = intZ;
									houseStuff[houseID][interiorID] = intID;


									format(query, sizeof(query), "UPDATE `house_data` SET `interiorID` = '%i', interiorX = '%f', interiorY = '%f', interiorZ = '%f' WHERE `house_id` = '%i'", intID, intX, intY, intZ, houseStuff[houseID][house_id]);
									db_query(DB: HOUSEDB, query);

									SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}You purchased the {58D3F7}Small Interior 1{FFFFFF} interior.");

									playerTakeMoney(playerid, 125000);

									intoHouseEx(playerid, houseID, 1);
									reloadHouses();
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You don't have enough cash to purchase this upgrade.");
								}
							}
						}
						case 1: // Small interior 2
						{
							if (houseStuff[houseID][interiorID] == 5)
							{
								ShowPlayerDialog(playerid, DIALOG_HOUSEMENU_LOCK, DIALOG_STYLE_MSGBOX, "Interior Upgrade", "This interior is already in use.", "Close", "");
							}
							else
							{
								if (playerData[playerid][playerMoney] >= 125000)
								{
									intX = 2233.6758;
									intY = -1114.4069;
									intZ = 1050.8828;
									intA = 2.3127;
									intID = 5;

									houseStuff[houseID][interiorX] = intX;
									houseStuff[houseID][interiorY] = intY;
									houseStuff[houseID][interiorZ] = intZ;
									houseStuff[houseID][interiorA] = intZ;
									houseStuff[houseID][interiorID] = intID;


									format(query, sizeof(query), "UPDATE `house_data` SET `interiorID` = '%i', interiorX = '%f', interiorY = '%f', interiorZ = '%f', interiorAngle = '%f' WHERE `house_id` = '%i'", intID, intX, intY, intZ, intA, houseStuff[houseID][house_id]);
									db_query(DB: HOUSEDB, query);

									SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}You purchased the {58D3F7}Small Interior 2{FFFFFF} interior.");

									playerTakeMoney(playerid, 125000);

									intoHouseEx(playerid, houseID, 1);
									reloadHouses();
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You don't have enough cash to purchase this upgrade.");
								}
							}
						}
						case 2: // Small Interior 3
						{
							if (houseStuff[houseID][interiorID] == 1)
							{
								ShowPlayerDialog(playerid, DIALOG_HOUSEMENU_LOCK, DIALOG_STYLE_MSGBOX, "Interior Upgrade", "This interior is already in use.", "Close", "");
							}
							else
							{
								if (playerData[playerid][playerMoney] >= 125000)
								{
									intX = 244.7782;
									intY = 304.9087;
									intZ = 999.1484;
									intA = 268.4808;
									intID = 1;

									houseStuff[houseID][interiorX] = intX;
									houseStuff[houseID][interiorY] = intY;
									houseStuff[houseID][interiorZ] = intZ;
									houseStuff[houseID][interiorID] = intID;


									format(query, sizeof(query), "UPDATE `house_data` SET `interiorID` = '%i', interiorX = '%f', interiorY = '%f', interiorZ = '%f', interiorAngle = '%f' WHERE `house_id` = '%i'", intID, intX, intY, intZ, intA, houseStuff[houseID][house_id]);
									db_query(DB: HOUSEDB, query);

									SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}You purchased the {58D3F7}Small Interior 3{FFFFFF} interior.");

									playerTakeMoney(playerid, 125000);

									intoHouseEx(playerid, houseID, 1);
									reloadHouses();
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}Your do not have enough money to upgrade to this interior!");
								}
							}
						}

						case 3: // Medium interior 1
						{
							if (houseStuff[houseID][interiorID] == 9)
							{
								ShowPlayerDialog(playerid, DIALOG_HOUSEMENU_LOCK, DIALOG_STYLE_MSGBOX, "Interior Upgrade", "This interior is already in use.", "Close", "");
							}
							else
							{
								if (playerData[playerid][playerMoney] >= 150000)
								{
									intX = 260.6848;
									intY = 1238.0388;
									intZ = 1084.2578;
									intA = 354.7931;
									intID = 9;

									houseStuff[houseID][interiorX] = intX;
									houseStuff[houseID][interiorY] = intY;
									houseStuff[houseID][interiorZ] = intZ;
									houseStuff[houseID][interiorID] = intID;


									format(query, sizeof(query), "UPDATE `house_data` SET `interiorID` = '%i', interiorX = '%f', interiorY = '%f', interiorZ = '%f', interiorAngle = '%f' WHERE `house_id` = '%i'", intID, intX, intY, intZ, intA, houseStuff[houseID][house_id]);
									db_query(DB: HOUSEDB, query);

									SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}You purchased the {58D3F7}Medium Interior 1{FFFFFF} interior.");

									playerTakeMoney(playerid, 150000);

									intoHouseEx(playerid, houseID, 1);
									reloadHouses();
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}Your do not have enough money to upgrade to this interior!");
								}
							}
						}
						case 4: // Medium interior 2
						{
							if (houseStuff[houseID][interiorID] == 3)
							{
								ShowPlayerDialog(playerid, DIALOG_HOUSEMENU_LOCK, DIALOG_STYLE_MSGBOX, "Interior Upgrade", "This interior is already in use.", "Close", "");
							}
							else
							{
								if (playerData[playerid][playerMoney] >= 150000)
								{
									intX = 2495.9863;
									intY = -1692.8761;
									intZ = 1014.7422;
									intA = 183.8799;
									intID = 3;

									houseStuff[houseID][interiorX] = intX;
									houseStuff[houseID][interiorY] = intY;
									houseStuff[houseID][interiorZ] = intZ;
									houseStuff[houseID][interiorID] = intID;


									format(query, sizeof(query), "UPDATE `house_data` SET `interiorID` = '%i', interiorX = '%f', interiorY = '%f', interiorZ = '%f', interiorAngle = '%f' WHERE `house_id` = '%i'", intID, intX, intY, intZ, intA, houseStuff[houseID][house_id]);
									db_query(DB: HOUSEDB, query);

									SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}You purchased the {58D3F7}Medium Interior 2{FFFFFF} interior.");

									playerTakeMoney(playerid, 150000);

									intoHouseEx(playerid, houseID, 1);
									reloadHouses();
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}Your do not have enough money to upgrade to this interior!");
								}
							}
						}
						case 5: // Large Interior 1
						{
							if (houseStuff[houseID][interiorID] == 6)
							{
								ShowPlayerDialog(playerid, DIALOG_HOUSEMENU_LOCK, DIALOG_STYLE_MSGBOX, "Interior Upgrade", "This interior is already in use.", "Close", "");
							}
							else
							{
								if (playerData[playerid][playerMoney] >= 250000)
								{
									intX = 234.1213;
									intY = 1065.1451;
									intZ = 1084.2102;
									intA = 357.2526;
									intID = 6;

									houseStuff[houseID][interiorX] = intX;
									houseStuff[houseID][interiorY] = intY;
									houseStuff[houseID][interiorZ] = intZ;
									houseStuff[houseID][interiorID] = intID;


									format(query, sizeof(query), "UPDATE `house_data` SET `interiorID` = '%i', interiorX = '%f', interiorY = '%f', interiorZ = '%f', interiorAngle = '%f' WHERE `house_id` = '%i'", intID, intX, intY, intZ, intA, houseStuff[houseID][house_id]);
									db_query(DB: HOUSEDB, query);

									SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}You purchased the {58D3F7}Large Interior 1{FFFFFF} interior.");

									playerTakeMoney(playerid, 250000);

									intoHouseEx(playerid, houseID, 1);
									reloadHouses();
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}Your do not have enough money to upgrade to this interior!");
								}
							}
						}
						case 6: // Large Interior 2
						{
							if (houseStuff[houseID][interiorID] == 5)
							{
								ShowPlayerDialog(playerid, DIALOG_HOUSEMENU_LOCK, DIALOG_STYLE_MSGBOX, "Interior Upgrade", "This interior is already in use.", "Close", "");
							}
							else
							{
								if (playerData[playerid][playerMoney] >= 250000)
								{
									intX = 227.4404;
									intY = 1114.2830;
									intZ = 1080.9988;
									intA = 269.7102;
									intID = 5;

									houseStuff[houseID][interiorX] = intX;
									houseStuff[houseID][interiorY] = intY;
									houseStuff[houseID][interiorZ] = intZ;
									houseStuff[houseID][interiorID] = intID;


									format(query, sizeof(query), "UPDATE `house_data` SET `interiorID` = '%i', interiorX = '%f', interiorY = '%f', interiorZ = '%f', interiorAngle = '%f' WHERE `house_id` = '%i'", intID, intX, intY, intZ, intA, houseStuff[houseID][house_id]);
									db_query(DB: HOUSEDB, query);

									SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}You purchased the {58D3F7}Large Interior 2{FFFFFF} interior.");

									playerTakeMoney(playerid, 250000);

									intoHouseEx(playerid, houseID, 1);
									reloadHouses();
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}Your do not have enough money to upgrade to this interior!");
								}
							}
						}
						case 7: // Large Interior 3
						{
							if (houseStuff[houseID][interiorID] == 9)
							{
								ShowPlayerDialog(playerid, DIALOG_HOUSEMENU_LOCK, DIALOG_STYLE_MSGBOX, "Interior Upgrade", "This interior is already in use.", "Close", "");
							}
							else
							{
								if (playerData[playerid][playerMoney] >= 250000)
								{
									intX = 83.0223;
									intY = 1323.1655;
									intZ = 1083.8662;
									intA = 359.9978;
									intID = 9;

									houseStuff[houseID][interiorX] = intX;
									houseStuff[houseID][interiorY] = intY;
									houseStuff[houseID][interiorZ] = intZ;
									houseStuff[houseID][interiorID] = intID;

									format(query, sizeof(query), "UPDATE `house_data` SET `interiorID` = '%i', interiorX = '%f', interiorY = '%f', interiorZ = '%f', interiorAngle = '%f' WHERE `house_id` = '%i'", intID, intX, intY, intZ, intA, houseStuff[houseID][house_id]);
									db_query(DB: HOUSEDB, query);

									SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}You purchased the {58D3F7}Large Interior 3{FFFFFF} interior.");

									playerTakeMoney(playerid, 250000);

									intoHouseEx(playerid, houseID, 1);
									reloadHouses();
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}Your do not have enough money to upgrade to this interior!");
								}
							}
						}
						case 8: // Large Interior 4
						{
							if (houseStuff[houseID][interiorID] == 3)
							{
								ShowPlayerDialog(playerid, DIALOG_HOUSEMENU_LOCK, DIALOG_STYLE_MSGBOX, "Interior Upgrade", "This interior is already in use.", "Close", "");
							}
							else
							{
								if (playerData[playerid][playerMoney] >= 250000)
								{
									intX = 235.2573;
									intY = 1187.6976;
									intZ = 1080.2578;
									intA = 359.9980;
									intID = 3;

									houseStuff[houseID][interiorX] = intX;
									houseStuff[houseID][interiorY] = intY;
									houseStuff[houseID][interiorZ] = intZ;
									houseStuff[houseID][interiorID] = intID;

									format(query, sizeof(query), "UPDATE `house_data` SET `interiorID` = '%i', interiorX = '%f', interiorY = '%f', interiorZ = '%f', interiorAngle = '%f' WHERE `house_id` = '%i'", intID, intX, intY, intZ, intA, houseStuff[houseID][house_id]);
									db_query(DB: HOUSEDB, query);

									SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}You purchased the {58D3F7}Large Interior 4{FFFFFF} interior.");

									playerTakeMoney(playerid, 250000);

									intoHouseEx(playerid, houseID, 1);
									reloadHouses();
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}Your do not have enough money to upgrade to this interior!");
								}
							}
						}
						case 9: // Large Interior 5
						{
							if (houseStuff[houseID][interiorID] == 12)
							{
								ShowPlayerDialog(playerid, DIALOG_HOUSEMENU_LOCK, DIALOG_STYLE_MSGBOX, "Interior Upgrade", "This interior is already in use.", "Close", "");
							}
							else
							{
								if (playerData[playerid][playerMoney] >= 250000)
								{
									intX = 2324.5037;
									intY = -1147.3666;
									intZ = 1050.7101;
									intA = 4.1933;
									intID = 12;

									houseStuff[houseID][interiorX] = intX;
									houseStuff[houseID][interiorY] = intY;
									houseStuff[houseID][interiorZ] = intZ;
									houseStuff[houseID][interiorID] = intID;

									format(query, sizeof(query), "UPDATE `house_data` SET `interiorID` = '%i', interiorX = '%f', interiorY = '%f', interiorZ = '%f', interiorAngle = '%f' WHERE `house_id` = '%i'", intID, intX, intY, intZ, intA, houseStuff[houseID][house_id]);
									db_query(DB: HOUSEDB, query);

									SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}You purchased the {58D3F7}Large Interior 5{FFFFFF} interior.");

									playerTakeMoney(playerid, 250000);

									intoHouseEx(playerid, houseID, 1);
									reloadHouses();
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}Your do not have enough money to upgrade to this interior!");
								}
							}
						}
						case 10: // Sex Chamber
						{
							if (houseStuff[houseID][interiorID] == 12)
							{
								ShowPlayerDialog(playerid, DIALOG_HOUSEMENU_LOCK, DIALOG_STYLE_MSGBOX, "Interior Upgrade", "This interior is already in use.", "Close", "");
							}
							else
							{
								if (playerData[playerid][playerMoney] >= 125000)
								{
									intX = 344.8157;
									intY = 305.0943;
									intZ = 999.1484;
									intA = 275.2059;
									intID = 6;

									houseStuff[houseID][interiorX] = intX;
									houseStuff[houseID][interiorY] = intY;
									houseStuff[houseID][interiorZ] = intZ;
									houseStuff[houseID][interiorID] = intID;

									format(query, sizeof(query), "UPDATE `house_data` SET `interiorID` = '%i', interiorX = '%f', interiorY = '%f', interiorZ = '%f', interiorAngle = '%f' WHERE `house_id` = '%i'", intID, intX, intY, intZ, intA, houseStuff[houseID][house_id]);
									db_query(DB: HOUSEDB, query);

									SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}You purchased the {58D3F7}Sex Chamber{FFFFFF} interior.");

									playerTakeMoney(playerid, 125000);

									intoHouseEx(playerid, houseID, 1);
									reloadHouses();
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}Your do not have enough money to upgrade to this interior!");
								}
							}
						}
						case 11: // Mansion
						{
							if (houseStuff[houseID][interiorID] == 5)
							{
								ShowPlayerDialog(playerid, DIALOG_HOUSEMENU_LOCK, DIALOG_STYLE_MSGBOX, "Interior Upgrade", "This interior is already in use.", "Close", "");
							}
							else
							{
								if (playerData[playerid][playerMoney] >= 1000000)
								{
									intX = 1262.3013;
									intY = -785.4304;
									intZ = 1091.9063;
									intA = 266.2875;
									intID = 5;

									houseStuff[houseID][interiorX] = intX;
									houseStuff[houseID][interiorY] = intY;
									houseStuff[houseID][interiorZ] = intZ;
									houseStuff[houseID][interiorID] = intID;

									format(query, sizeof(query), "UPDATE `house_data` SET `interiorID` = '%i', interiorX = '%f', interiorY = '%f', interiorZ = '%f', interiorAngle = '%f' WHERE `house_id` = '%i'", intID, intX, intY, intZ, intA, houseStuff[houseID][house_id]);
									db_query(DB: HOUSEDB, query);

									SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}You purchased the {58D3F7}Mansion{FFFFFF} interior.");

									playerTakeMoney(playerid, 1000000);

									intoHouseEx(playerid, houseID, 1);
									reloadHouses();
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}Your do not have enough money to upgrade to this interior!");
								}
							}
						}
					}
				}
			}
   		}
   	}

   	if(dialogid == DIALOG_HOUSEMENU_TITLE)
   	{
		if(response)
		{
			if(strlen(inputtext) > 0 && strlen(inputtext) < 25)
			{
				new
					cleanTitle[100],
					query[300],
					message[300],
					houseID
				;

				houseID = playerData[playerid][playerInsideHouse];

				mysql_real_escape_string(inputtext, cleanTitle);


				format(query, sizeof(query), "UPDATE `house_data` SET `house_title` = '%s' WHERE `house_id` = '%i'", cleanTitle, houseStuff[houseID][house_id]);
				db_query(DB: HOUSEDB, query);

				format(houseStuff[houseID][house_title], 48, cleanTitle);

				format(message, sizeof(message), "{FFDC2E}[HOUSE] {FFFFFF}Your house title has been set to {58D3F7}%s{FFFFFF}.", cleanTitle);
				SendClientMessage(playerid, COLOR_WHITE, message);
			}
		}
		else
		{
			ShowPlayerDialog(playerid, DIALOG_HOUSEMENU_TITLE, DIALOG_STYLE_INPUT, "House Title", "{FE642E}You cannot set this as your title.\n{FFFFFF}Configure your house title below.", "Save", "Cancel");
		}
   	}

   	if(dialogid == DIALOG_ENTER_PASSWORD)
   	{
	    if(response)
	    {
			if(strlen(inputtext) > 0 && strlen(inputtext) < 25)
			{
				new enteredPW[25], houseID = playerData[playerid][playerHousePass];

				format(enteredPW, sizeof(enteredPW), "%s", inputtext);

				if(!strcmp(houseStuff[houseID][house_password], enteredPW, true)) // Correct
				{
					intoHouseEx(playerid, houseID, 0);
					playerData[playerid][playerHousePass] = -1;
				}
				else // Incorrect
				{
					ShowPlayerDialog(playerid, DIALOG_ENTER_PASSWORD, DIALOG_STYLE_INPUT, "House Password {58D3F7}Bad password.{FFFFFF}", "Enter the password below to enter this property.", "Enter", "Cancel");
				}
			}
		}
	}

   	if(dialogid == DIALOG_HOUSEMENU_PASSWORD)
   	{
	    if(response)
	    {
			if(strlen(inputtext) < 25)
			{
				new
					cleanPassword[100],
					query[300],
					message[300],
					houseID
				;

				houseID = playerData[playerid][playerInsideHouse];

				if(!strcmp(inputtext, "none", true))
				{
					SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}Your house password has been {58D3F7}removed{FFFFFF}.");


					format(query, sizeof(query), "UPDATE `house_data` SET `house_password` = 'none' WHERE `house_id` = '%i'", houseStuff[houseID][house_id]);
					db_query(DB: HOUSEDB, query);

					format(houseStuff[houseID][house_password], 48, cleanPassword);
				}
				else
				{
					mysql_real_escape_string(inputtext, cleanPassword);


					format(query, sizeof(query), "UPDATE `house_data` SET `house_password` = '%s' WHERE `house_id` = '%i'", cleanPassword, houseStuff[houseID][house_id]);
					db_query(DB: HOUSEDB, query);

					format(houseStuff[houseID][house_password], 48, cleanPassword);

					format(message, sizeof(message), "{FFDC2E}[HOUSE] {FFFFFF}Your house password has been set to {58D3F7}%s{FFFFFF}.", cleanPassword);
					SendClientMessage(playerid, COLOR_WHITE, message);
				}
			}
			else
			{
				ShowPlayerDialog(playerid, DIALOG_HOUSEMENU_PASSWORD, DIALOG_STYLE_INPUT, "House Password", "{FE642E}You cannot set this as your password.\n{FFFFFF}Configure your house password below.", "Save", "Cancel");
			}
		}
   	}

    if(dialogid == DIALOG_HOUSEMENU_SELL)
    {
        // If the user clicked on an option
        if(response)
        {
			new
				houseID,
				sellValue,
				Float:intX,
				Float:intY,
				Float:intZ,
				intID,
				query[340]
			;


			houseID = playerData[playerid][playerInsideHouse];
			sellValue = houseStuff[houseID][house_price] / 2;

			intX = 223.1495;
			intY = 1287.6683;
			intZ = 1082.199951;
			intID = 1;

			houseStuff[houseID][interiorX] = intX;
			houseStuff[houseID][interiorY] = intY;
			houseStuff[houseID][interiorZ] = intZ;
			houseStuff[houseID][interiorID] = intID;

			format(query, sizeof(query), "UPDATE `house_data` SET `house_bought` = '0', `house_owner` = 'CZCNR', `house_password` = 'none', `house_title` = 'none', `interiorX` = '223.043991', `interiorY` = '1287.6683', `interiorZ` = '1082.199951', `interiorID` = '1' WHERE `house_id` = '%i'", houseStuff[houseID][house_id]);
			db_query(DB: HOUSEDB, query);

			leaveHouseEx(playerid, houseID);
			reloadHouses();

			ShowPlayerDialog(playerid, 9583, DIALOG_STYLE_MSGBOX, "House Sold", "Your house has been sold.", "Close", "");
			playerGiveMoney(playerid, sellValue);

			playerData[playerid][houseCount] = playerData[playerid][houseCount] - 1;

			new loggingString[256];
			format(loggingString, sizeof(loggingString), "%s sold their house.", playerData[playerid][playerNamee]);
			writeInLog("actionLog.html", loggingString);
		}
	}

    if(dialogid == DIALOG_MUSIC)
    {
        // If the user clicked on an option
        if(response)
        {
  			switch(listitem)
    		{
    		    case 0:
    		    {
    		        PlayAudioStreamForPlayer(playerid, "http://czcnr.ml/American-Idiot.mp3");
    		        SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[MUSIC] {FFFFFF}Now listening to American Idiot by Green Day - to stop the music, use /stopradio");
    		    }
    		    case 1: // All Saints - Pure Shores - http://dl.dropbox.com/u/85807099/All%20Saints%20-%20Pure%20Shores.mp3
    		    {
    		        PlayAudioStreamForPlayer(playerid, "http://czcnr.ml/JOS.mp3");
    		        SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[MUSIC] {FFFFFF}Now listening to Jesus of Suburbia by Green Day - to stop the music, use /stopradio");
    		    }
    		    case 2: // Clean Bandit - Mozart's House - https://dl.dropbox.com/u/85807099/Mozart%27s%20House.mp3
				{
    		        PlayAudioStreamForPlayer(playerid, "http://czcnr.ml/Homecoming.mp3");
    		        SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[MUSIC] {FFFFFF}Now listening to Homecoming by Green Day - to stop the music, use /stopradio");
				}
				case 3:
				{
					PlayAudioStreamForPlayer(playerid, "http://czcnr.ml/21st.mp3");
    		        SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[MUSIC] {FFFFFF}Now listening to 21st Century Breakdown by Green Day - to stop the music, use /stopradio");
				}
				case 4:
				{
					PlayAudioStreamForPlayer(playerid, "http://czcnr.ml/SFA.mp3");
    		        SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[MUSIC] {FFFFFF}Now listening to So Far Away by Avenged Sevenfold - to stop the music, use /stopradio");
				}
				case 5:
				{
					PlayAudioStreamForPlayer(playerid, "http://czcnr.ml/MIA.mp3");
    		        SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[MUSIC] {FFFFFF}Now listening to Missing in Action by Avenged Sevenfold - to stop the music, use /stopradio");
				}
				case 6:
				{
					PlayAudioStreamForPlayer(playerid, "http://czcnr.ml/DearGod.mp3");
    		        SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[MUSIC] {FFFFFF}Now listening to Dear God by Avenged Sevenfold - to stop the music, use /stopradio");
				}
				case 7:
				{
					PlayAudioStreamForPlayer(playerid, "http://czcnr.ml/BID.mp3");
    		        SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[MUSIC] {FFFFFF}Now listening to Burn it Down by Avenged Sevenfold - to stop the music, use /stopradio");
				}
			}
	    }
    }

    if(dialogid == DIALOG_RADIO)
    {
        // If the user clicked on an option
        if(response)
        {
            if(listitem == 0)
			{
				StopAudioStreamForPlayer(playerid);
 			}
 			if(listitem == 1)
  			{
				PlayAudioStreamForPlayer(playerid, "http://yp.shoutcast.com/sbin/tunein-station.pls?id=1283896");
  			}
  			if(listitem == 2)
  			{
				PlayAudioStreamForPlayer(playerid, "http://yp.shoutcast.com/sbin/tunein-station.pls?id=35402");
  			}
  			if(listitem == 3)
  			{
				PlayAudioStreamForPlayer(playerid, "http://yp.shoutcast.com/sbin/tunein-station.pls?id=508962");
  			}
  			if(listitem == 4)
  			{
				PlayAudioStreamForPlayer(playerid, "http://yp.shoutcast.com/sbin/tunein-station.pls?id=297243");
  			}
            if(listitem == 5)
  			{
				PlayAudioStreamForPlayer(playerid, "http://yp.shoutcast.com/sbin/tunein-station.pls?id=1283687");
  			}
			if(listitem == 6)
  			{
				PlayAudioStreamForPlayer(playerid, "http://yp.shoutcast.com/sbin/tunein-station.pls?id=248370");
  			}
  			if(listitem == 7)
			{
				PlayAudioStreamForPlayer(playerid, "http://yp.shoutcast.com/sbin/tunein-station.pls?id=520036");
 			}
  			if(listitem == 8)
			{
				PlayAudioStreamForPlayer(playerid, "http://yp.shoutcast.com/sbin/tunein-station.pls?id=203280");
 			}
  			if(listitem == 9)
  			{
				PlayAudioStreamForPlayer(playerid, "http://yp.shoutcast.com/sbin/tunein-station.pls?id=914897");
  			}
  			if(listitem == 10)
  			{
				PlayAudioStreamForPlayer(playerid, "http://yp.shoutcast.com/sbin/tunein-station.pls?id=210158");
  			}
			if(listitem == 11)
			{
				PlayAudioStreamForPlayer(playerid, "http://yp.shoutcast.com/sbin/tunein-station.pls?id=86433");
 			}
 			if(listitem == 12)
  			{
				PlayAudioStreamForPlayer(playerid, "http://yp.shoutcast.com/sbin/tunein-station.pls?id=467000");
  			}
  			if(listitem == 13)
  			{
				PlayAudioStreamForPlayer(playerid, "http://cnr-radio.com/listen.m3u");
  			}
  			if(listitem == 14)
  			{
				PlayAudioStreamForPlayer(playerid, "http://yp.shoutcast.com/sbin/tunein-station.pls?id=721890");
  			}
  			if(listitem == 15)
  			{
				PlayAudioStreamForPlayer(playerid, "http://yp.shoutcast.com/sbin/tunein-station.pls?id=31903");
  			}
  			if(listitem == 16)
  			{
				PlayAudioStreamForPlayer(playerid, "http://yp.shoutcast.com/sbin/tunein-station.pls?id=35899");
  			}
  			if(listitem == 17)
  			{
				PlayAudioStreamForPlayer(playerid, "http://www.dubstep.fm/listen.pls");
  			}
  			if(listitem == 18)
  			{
				PlayAudioStreamForPlayer(playerid, "http://servers.internet-radio.com/tools/playlistgenerator/?u=http://www.partyvibe.com:8006/listen.pls&t=.pls");
  			}
  			if(listitem == 19)
  			{
				PlayAudioStreamForPlayer(playerid, "http://servers.internet-radio.com/tools/playlistgenerator/?u=http://92.48.107.35:8004/listen.pls&t=.pls");
  			}
  			if(listitem == 20)
  			{
				PlayAudioStreamForPlayer(playerid, "http://servers.internet-radio.com/tools/playlistgenerator/?u=http://sc1.christiannetcast.com:9138/listen.pls&t=.pls");
  			}

    		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[RADIO] {FFFFFF}If the stream doesn't start, it may be offline - to stop the radio, use /stopradio");
		}
	}

    if(dialogid == DIALOG_SUPASAVE)
    {
        // If the user clicked on an option
        if(response)
        {
  			switch(listitem)
    		{
    			case 0: // Rope - Costs: $1000
     			{
					// Check player cash
					if (playerData[playerid][playerMoney] >= 1000)
					{
						// Player can buy rope
						playerSetMoney(playerid, playerData[playerid][playerMoney] - 1000);
						playerData[playerid][playerRope] = playerData[playerid][playerRope] + 1;
						SendClientMessage(playerid, COLOR_WHITE, "{FFFF00}[SUPA SAVE] {FFFFFF}You have purchased 1 rope.");
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot afford that item.");
					}
     			}

     			case 1: // Scissors - Costs: $2,500
     			{
					// Check player cash
					if (playerData[playerid][playerMoney] >= 2500)
					{
						// Player can buy scissors
						playerSetMoney(playerid, playerData[playerid][playerMoney] - 2500);
						playerData[playerid][playerScissors] = playerData[playerid][playerScissors] + 1;
						SendClientMessage(playerid, COLOR_WHITE, "{FFFF00}[SUPA SAVE] {FFFFFF}You have purchased 1 pair of scissors!");
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot afford that item.");
					}
     			}

				case 2: // Bobby pins - Costs: $2,000
				{
					if(playerData[playerid][playerMoney] >= 2000)
					{
						playerTakeMoney(playerid, 2000);
						playerData[playerid][playerBobbyPins]++;
						SendClientMessage(playerid, COLOR_WHITE, "{FFFF00}[SUPA SAVE] {FFFFFF}You have purchased a bobby pin!");
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot afford that item.");
					}
				}

				case 3: // Bobby pins - Costs: $6000
				{
					if(playerData[playerid][playerMoney] >= 6000)
					{
						playerSetMoney(playerid, playerData[playerid][playerMoney] - 6000);
						playerData[playerid][playerBobbyPins] = playerData[playerid][playerBobbyPins] + 4;
						SendClientMessage(playerid, COLOR_WHITE, "{FFFF00}[SUPA SAVE] {FFFFFF}You have purchased 4 bobby pin!");
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot afford that item.");
					}
				}

				case 4: // Backpack - Costs: $15,000
				{
					if (playerData[playerid][playerBackpack] != 1)
					{
						if(playerData[playerid][playerMoney] >= 15000)
						{
							playerTakeMoney(playerid, 15000);
							playerData[playerid][playerBackpack] = 1;
							SendClientMessage(playerid, COLOR_WHITE, "{FFFF00}[SUPA SAVE] {FFFFFF}You have purchased a backpack! Type /backpack to put it on.");
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot afford that item.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You already own a backpack.");
					}
				}

     			case 5: // Bigger Pockets - Costs: $5,000
     			{
					// Check player cash
					if (playerData[playerid][playerMoney] >= 5000)
					{
					    // Check if player already owns bigger pockets
					    if (playerData[playerid][playerBiggerPockets] == 1)
					    {
							// Cannot purchase again
							SendClientMessage(playerid, COLOR_WHITE, "{FFFF00}[SUPA SAVE] {FFFFFF}You already own bigger pockets, this item cannot be stacked!");
						}
						else
						{
							// Player can buy bigger pockets
							playerSetMoney(playerid, playerData[playerid][playerMoney] - 5000);
							playerData[playerid][playerBiggerPockets] = playerData[playerid][playerBiggerPockets] + 1;
							SendClientMessage(playerid, COLOR_WHITE, "{FFFF00}[SUPA SAVE] {FFFFFF}You have purchased bigger pockets!");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot afford that item.");
					}
     			}
     			case 6: // Secure wallet - Costs: $5,000
     			{
					// Check player cash
					if (playerData[playerid][playerMoney] >= 5000)
					{
						if (playerData[playerid][playerSecureWallet] == 1)
					    {
							// Cannot purchase again
							SendClientMessage(playerid, COLOR_WHITE, "{FFFF00}[SUPA SAVE] {FFFFFF}You already own a secure wallet, this item cannot be stacked!");
						}
						else
						{
							// Player can buy a secure wallet
							playerGiveMoney(playerid, -5000);
							playerData[playerid][playerSecureWallet]++;
							SendClientMessage(playerid, COLOR_WHITE, "{FFFF00}[SUPA SAVE] {FFFFFF}You have purchased a secure wallet!");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot afford that item.");
					}
     			}

     			case 7: // Butt Plug - Costs: $5,000
     			{
					// Check player cash
					if (playerData[playerid][playerMoney] >= 5000)
					{
						// Player can buy a butt plug
						playerSetMoney(playerid, playerData[playerid][playerMoney] - 5000);
						playerData[playerid][playerButtPlug] = playerData[playerid][playerButtPlug] + 1;
						SendClientMessage(playerid, COLOR_WHITE, "{FFFF00}[SUPA SAVE] {FFFFFF}You have purchased 1 butt plug!");
					}
     			}

     			case 8: // Lucky Charm - Costs: $25,000
     			{
					if (!playerData[playerid][luckyCharm])
					{
						// Check player cash
						if (playerData[playerid][playerMoney] >= 25000)
						{
							if (playerData[playerid][playerRobberies] >= 200)
							{
								// Player can buy a lucky charm
								playerSetMoney(playerid, playerData[playerid][playerMoney] - 25000);
								SendClientMessage(playerid, COLOR_WHITE, "{FFFF00}[SUPA SAVE] {FFFFFF}You have purchased a lucky charm!");

								playerData[playerid][luckyCharm] = true;
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You need to rob 200 stores before you unlock this item.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot afford that item.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You already have a lucky charm.");
					}
     			}

     			case 9: // Mask - Costs: $20,000
     			{
					if (!playerData[playerid][mask])
					{
						// Check player cash
						if (playerData[playerid][playerMoney] >= 20000)
						{
							// Player can buy a mask
							playerSetMoney(playerid, playerData[playerid][playerMoney] - 20000);
							SendClientMessage(playerid, COLOR_WHITE, "{FFFF00}[SUPA SAVE] {FFFFFF}You have purchased a mask!");

							playerData[playerid][mask] = true;
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot afford that item.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You already have a mask.");
					}
     			}

     			case 10: // Bomb defusal kit - Costs: $10,000
     			{
					if (!playerData[playerid][playerDefuseKit])
					{
						// Check player cash
						if (playerData[playerid][playerMoney] >= 10000)
						{
							// Player can buy a kit
							playerSetMoney(playerid, playerData[playerid][playerMoney] - 10000);
							SendClientMessage(playerid, COLOR_WHITE, "{FFFF00}[SUPA SAVE] {FFFFFF}You have purchased a Bomb Defusal Kit!");

							playerData[playerid][playerDefuseKit] = true;
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot afford that item.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You already have a Bomb Defusal Kit.");
					}
     			}

     			case 11: // Escapists Guide - Costs: $5,000
     			{
					// Check player cash
					if (playerData[playerid][playerMoney] >= 5000)
					{
						// Player can buy a kit
						playerSetMoney(playerid, playerData[playerid][playerMoney] - 5000);
						SendClientMessage(playerid, COLOR_WHITE, "{FFFF00}[SUPA SAVE] {FFFFFF}You have purchased an Escapists Guide!");

						playerData[playerid][playerJailKit]++;
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot afford that item.");
					}
     			}
				
				case 12:
				{
					if (playerData[playerid][playerMoney] >= 20000)
					{
						playerSetMoney(playerid, playerData[playerid][playerMoney] - 20000);
						new string[128];
						for(new x = 0;x<1;x++)
						{
							if(IsPlayerAttachedObjectSlotUsed(playerid, x))
							{
								format(string, sizeof(string), "%sSlot Used\n", string);
							}
							else
							{
								format(string, sizeof(string), "%sFree Slot\n", string);
							}
						}
						ShowPlayerDialog(playerid, DIALOG_ATTACH_INDEX_SELECTION, DIALOG_STYLE_LIST, "Toy System", string, "Select", "Close");
						return 1;
					}
				}

			}

			new supaSave[1000];
			format(supaSave, sizeof(supaSave), "%s\n{D87C3E}$1,000      {FFFFFF}1x Rope {FFBF00}(Saves)", supaSave);
			format(supaSave, sizeof(supaSave), "%s\n{D87C3E}$2,500      {FFFFFF}1x Scissors {FFBF00}(Saves)", supaSave);
			format(supaSave, sizeof(supaSave), "%s\n{D87C3E}$2,000      {FFFFFF}1x Bobby Pins {FFBF00}(Saves)", supaSave);
			format(supaSave, sizeof(supaSave), "%s\n{D87C3E}$6,000      {FFFFFF}4x Bobby Pins {FFBF00}(Saves)", supaSave);
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
	}

	if(dialogid == DIALOG_XPSHOP)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0: // Convert 100 XP to 1000 cash
				{
					// Check player XP
					if (playerData[playerid][playerXP] >= 100)
					{
						// Player can exchange
						playerGiveXP(playerid, -100);
						playerGiveMoney(playerid, 1000);

						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You exchanged 100 XP for $1000!");
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cant afford that.");
					}
				}
				case 1: // Convert 50,000 XP to 15 days VIP
				{
					new string[600];
					format(string, sizeof(string), "%s{98B0CD}15 Days VIP Membership \n", string);
					format(string, sizeof(string), "%s{FFFFFF}You're about to purchase a 15 day membership to our Standard\n", string);
					format(string, sizeof(string), "%svip package. This package does not include armour, money, houses\n", string);
					format(string, sizeof(string), "%sor vehicles. You will not receive a \"Premium\" tag on our forums.\n\n", string);
					format(string, sizeof(string), "%sThis package grants you tax immunity, access to the Standard VIP commands,\n", string);
					format(string, sizeof(string), "%saccess to the awesome Secret Service class and of course, the VIP lounge.\n\n", string);

					format(string, sizeof(string), "%sThis is a non-refundable item, and by clicking confirm you will lose \n", string);
					format(string, sizeof(string), "%s15,000 XP. This item can be redeemed instantly.\n", string);

					ShowPlayerDialog(playerid, DIALOG_VIPCONFIRM, DIALOG_STYLE_MSGBOX, "15 DAYS VIP MEMBERSHIP", string, "CONFIRM", "");
				}
			}
		}
	}

	if (dialogid == DIALOG_VIPCONFIRM)
	{
		if (response)
		{
			// Check player XP
			if (playerData[playerid][playerXP] >= 15000)
			{
				// Player can buy VIP
				playerGiveXP(playerid, -15000);

				if (playerData[playerid][playerVIPLevel] < 1) // If already VIP, don't set to 1
				{
					playerData[playerid][playerVIPLevel] = 1;
				}

				playerData[playerid][vipExpires] = playerData[playerid][vipExpires] + 1296000; // 15 days

				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You bought 15 days of VIP!");

				disableAchieve(playerid);
				PlayerTextDrawShow(playerid, playerData[playerid][Achieve1]);
				PlayerTextDrawShow(playerid, playerData[playerid][Achieve2]);
				PlayerTextDrawShow(playerid, playerData[playerid][Achieve3]);
				PlayerTextDrawShow(playerid, playerData[playerid][Achieve4]);

				PlayerTextDrawSetString(playerid, playerData[playerid][Achieve3], "You're VIP!");
				PlayerTextDrawSetString(playerid, playerData[playerid][Achieve4], "You are now a VIP member, nice!");
				PlayerPlaySound(playerid, 1183 ,0.0, 0.0, 0.0);

				playerData[playerid][achieveTimer] = SetTimerEx("disableAchieve", 6000, false, "i", playerid);

				playerGiveXP(playerid, 25);
				playerData[playerid][playerScore] = playerData[playerid][playerScore] + 2;
				SetPlayerScore(playerid, playerData[playerid][playerScore]);

				savePlayerStats(playerid);
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cant afford that.");
			}
		}
		else
		{
			//return cmd_xpshop(playerid, "");
		}
	}

	if(dialogid == DIALOG_DEBUG)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0: // Health
				{
					SetPlayerHealth(playerid, 100.0);
					SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[DEBUG] {FFFFFF}You have healed yourself.");

					ShowPlayerDialog(playerid, DIALOG_DEBUG, DIALOG_STYLE_LIST, "Admin Debug", "Full Health\nWeapon Packs\nRepair Vehicle\nAdd NOS\nRemove EMP", "Select", "Cancel");
				}
				case 1: // Weapon packs
				{
					ShowPlayerDialog(playerid, DIALOG_WEAPONPACKS, DIALOG_STYLE_LIST, "Choose your weapon pack", "Deagle | Combat | MP5 | M4 | Sniper Rifle\nSilenced | Sawn-offs | Micro UZI | AK-47 | Country Rifle \nRocket | Grenades | Combat Shotgun", "Acquire", "Cancel");
				}
				case 2: // Vehicle repair
				{
					if(IsPlayerInAnyVehicle(playerid))
					{
						RepairVehicle(GetPlayerVehicleID(playerid));
						PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
						SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[DEBUG] {FFFFFF}You have repaired your vehicle.");

						ShowPlayerDialog(playerid, DIALOG_DEBUG, DIALOG_STYLE_LIST, "Admin Debug", "Full Health\nWeapon Packs\nRepair Vehicle\nAdd NOS\nRemove EMP", "Select", "Cancel");
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be in a vehicle to repair it!");
					}
				}
				case 3: // Vehicle NOS
				{
					if(IsPlayerInAnyVehicle(playerid))
					{
						AddVehicleComponent(GetPlayerVehicleID(playerid), 1010);
						PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
						SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[DEBUG] {FFFFFF}You have added NOS to your vehicle.");

						ShowPlayerDialog(playerid, DIALOG_DEBUG, DIALOG_STYLE_LIST, "Admin Debug", "Full Health\nWeapon Packs\nRepair Vehicle\nAdd NOS\nRemove EMP", "Select", "Cancel");
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be in a vehicle to add NOS to it!");
					}
				}
				case 4: // Remove EMP
				{
					if(IsPlayerInAnyVehicle(playerid))
					{
						new engine, lights, alarm, doors, bonnet, boot, objective;
						GetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, lights, alarm, doors, bonnet, boot, objective);

						if(engine == 0)
						{
							SetVehicleParamsEx(GetPlayerVehicleID(playerid), 1, lights, alarm, doors, bonnet, boot, objective);
							SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[DEBUG] {FFFFFF}You have removed EMP from your vehicle.");
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Your vehicle engine works perfectly fine.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be in a vehicle to remove the EMP from it.");
					}
				}
			}
		}
	}

	if(dialogid == DIALOG_WEAPONPACKS)
	{
		if(response)
		{
			if(playerData[playerid][playerLevel] >= 6)
			{
				switch(listitem)
				{
					case 0:
					{
						GivePlayerWeaponEx(playerid, 24, 15000);
						GivePlayerWeaponEx(playerid, 27, 15000);
						GivePlayerWeaponEx(playerid, 29, 15000);
						GivePlayerWeaponEx(playerid, 31, 15000);
						GivePlayerWeaponEx(playerid, 34, 15000);
						playerData[playerid][adminWeapon] = true;
					}
					case 1:
					{
						GivePlayerWeaponEx(playerid, 23, 15000);
						GivePlayerWeaponEx(playerid, 26, 15000);
						GivePlayerWeaponEx(playerid, 28, 15000);
						GivePlayerWeaponEx(playerid, 30, 15000);
						GivePlayerWeaponEx(playerid, 33, 15000);
						playerData[playerid][adminWeapon] = true;
					}
					case 2:
					{
						GivePlayerWeaponEx(playerid, 27, 15000);
						GivePlayerWeaponEx(playerid, 35, 15000);
						GivePlayerWeaponEx(playerid, 16, 15000);
						playerData[playerid][adminWeapon] = true;
					}
				}
				playerData[playerid][adminWeapon] = true;

				ShowPlayerDialog(playerid, DIALOG_DEBUG, DIALOG_STYLE_LIST, "Admin Debug", "Full Health\nWeapon Packs\nRepair Vehicle\nAdd NOS\nRemove EMP", "Select", "Cancel");
			}

			ShowPlayerDialog(playerid, DIALOG_WEAPONPACKS, DIALOG_STYLE_LIST, "Choose your weapon pack", "Deagle | Combat | MP5 | M4 | Sniper Rifle\nSilenced | Sawn-offs | Micro UZI | AK-47 | Country Rifle \nRocket | Grenades | Combat Shotgun", "Acquire", "Cancel");

		}
		else
		{
            ShowPlayerDialog(playerid, DIALOG_DEBUG, DIALOG_STYLE_LIST, "Admin Debug", "Full Health\nWeapon Packs\nRepair Vehicle\nAdd NOS\nRemove EMP", "Select", "Cancel");
		}
	}

	if(dialogid == DIALOG_JOBSELECT)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0: // Kidnapper
				{
					playerData[playerid][playerJob] = JOB_KIDNAPPER;
					playerData[playerid][playerCanKidnap] = true;
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}Use {FFDC2E}/kidnap {FFFFFF}to kidnap players.");

		     		// weapons
					GivePlayerWeaponEx(playerid, 22, 250); // Pistol
					GivePlayerWeaponEx(playerid, 25, 250); // Shotgun
					GivePlayerWeaponEx(playerid, 29, 250); // mp5
					GivePlayerWeaponEx(playerid, 2, 1); // golf stick
				}
				case 1: // Mechanic
				{
					playerData[playerid][playerJob] = JOB_MECHANIC;
					playerData[playerid][playerCanRepair] = true;
					playerData[playerid][playerCanFlip] = true;
					playerData[playerid][playerCanNOS] = true;
					playerData[playerid][playerCanREMP] = true;
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}Use {FFDC2E}/mech {FFFFFF}to view available job commands.");

		     		// weapons
					GivePlayerWeaponEx(playerid, 22, 250); // Pistol
					GivePlayerWeaponEx(playerid, 25, 250); // Shotgun
					GivePlayerWeaponEx(playerid, 29, 250); // mp5
					GivePlayerWeaponEx(playerid, 2, 1); // golf stick
				}
				case 2: // Weapon dealer
				{
					playerData[playerid][playerJob] = JOB_WEAPONDEALER;
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}Use {FFDC2E}/sellgun {FFFFFF}to offer weapons to players.");

		     		// weapons
					GivePlayerWeaponEx(playerid, 22, 250); // Pistol
					GivePlayerWeaponEx(playerid, 25, 250); // Shotgun
					GivePlayerWeaponEx(playerid, 29, 250); // mp5
					GivePlayerWeaponEx(playerid, 2, 1); // golf stick
				}
				case 3: // Rapist
				{
					playerData[playerid][playerJob] = JOB_RAPIST;
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}Use {FFDC2E}/rape {FFFFFF}to infect players with an STD.");

		     		// weapons
					GivePlayerWeaponEx(playerid, 22, 250); // Pistol
					GivePlayerWeaponEx(playerid, 25, 250); // Shotgun
					GivePlayerWeaponEx(playerid, 29, 250); // mp5
					GivePlayerWeaponEx(playerid, 2, 1); // golf stick
				}
				case 4: // Hitman
				{
					playerData[playerid][playerJob] = JOB_HITMAN;
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}Use {FFDC2E}/track {FFFFFF}to locate players. Use {FFDC2E}/hitlist {FFFFFF}to view players with a bounty on them.");

					GivePlayerWeaponEx(playerid, 22, 250); // Pistol
					GivePlayerWeaponEx(playerid, 25, 250); // Shotgun
					GivePlayerWeaponEx(playerid, 29, 250); // mp5
					GivePlayerWeaponEx(playerid, 2, 1); // golf stick
				}
				case 5: // Drug Dealer
				{
					playerData[playerid][playerJob] = JOB_DRUGDEALER;
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}Use {FFDC2E}/sellweed {FFFFFF}whilst in an ice cream truck to sell drugs to players.");
					GivePlayerWeaponEx(playerid, 22, 250); // Pistol
					GivePlayerWeaponEx(playerid, 25, 250); // Shotgun
					GivePlayerWeaponEx(playerid, 29, 250); // mp5
					GivePlayerWeaponEx(playerid, 2, 1); // golf stick
				}
				case 6: // Terrorist
				{
					playerData[playerid][playerJob] = JOB_TERRORIST;
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}Use {FFDC2E}/usec4 {FFFFFF}to plant explosives. You have received 5 free explosives.");

					playerData[playerid][playerExplosives] = playerData[playerid][playerExplosives] + 5;
					
					GivePlayerWeaponEx(playerid, 22, 250); // Pistol
					GivePlayerWeaponEx(playerid, 25, 250); // Shotgun
					GivePlayerWeaponEx(playerid, 29, 250); // mp5
					GivePlayerWeaponEx(playerid, 2, 1); // golf stick
				}
			}
		}
		else
		{
			new jobList[500];
			format(jobList, sizeof(jobList), "%s\n{D87C3E}Kidnapper {FFFFFF}- Kidnap players for a ransom and XP.", jobList);
			format(jobList, sizeof(jobList), "%s\n{D87C3E}Mechanic {FFFFFF}- Upgrade or repair player vehicles.", jobList);
			format(jobList, sizeof(jobList), "%s\n{D87C3E}Gun Dealer {FFFFFF}- Sell weapons to players for cash.", jobList);
			format(jobList, sizeof(jobList), "%s\n{D87C3E}Rapist {FFFFFF}- Rape players and give them STDs.", jobList);
			format(jobList, sizeof(jobList), "%s\n{D87C3E}Hitman {FFFFFF}Complete hit contracts for cash.", jobList);
			format(jobList, sizeof(jobList), "%s\n{D87C3E}Drug Dealer {FFFFFF}Sell weed to players for cash.", jobList);
			format(jobList, sizeof(jobList), "%s\n{D87C3E}Terrorist {FFFFFF}- Blow up the jail cells / bank.", jobList);

			ShowPlayerDialog(playerid, DIALOG_JOBSELECT, DIALOG_STYLE_LIST, "Job Selection", jobList, "Choose", "Close");
		}
	}

    if(dialogid == DIALOG_COURIER_START)
    {
        // If the user clicked on an option
        if(response)
        {
            new rand = random(1);
            playerData[playerid][playerCourierLevel] = 1;
            playerData[playerid][iscourier] = true;

  			switch(listitem)
    		{
    		    case 0: // Los Santos
    		    {
    		        if (rand == 0)
    		        {
    		            // Pick-up 1
    		            SetPlayerCheckpoint(playerid, 1875.0139, -2612.8547, 13.5469, 10);
					}
					else
					{
					    // Pickup 2
    		            SetPlayerCheckpoint(playerid, 1627.8134,-2444.4290,13.5547, 10);
					}
					SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}Pick-up the cargo from Los Santos (/cancelcourier to end the mission)");
    		    }
    		    case 1: // San Fierro
    		    {
    		        if (rand == 0)
    		        {
    		            // Pick-up 1
    		            SetPlayerCheckpoint(playerid, -1333.3374, -265.4836, 14.1484, 10);
					}
					else
					{
					    // Pickup 2
    		            SetPlayerCheckpoint(playerid, -1204.7883, 8.4982, 14.1484, 10);
					}
					SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}Pick-up the cargo from San Fierro (/cancelcourier to end the mission)");
    		    }
    		    case 2: // Las Venturas
    		    {
    		        if (rand == 0)
    		        {
    		            // Pick-up 1
    		            SetPlayerCheckpoint(playerid, 1311.4384, 1324.6191, 10.8203, 10);
					}
					else
					{
					    // Pickup 2
    		            SetPlayerCheckpoint(playerid, 1605.1602, 1605.0518, 10.8203, 10);
					}
					SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[COURIER] {FFFFFF}Pick-up the cargo from Las Venturas (/cancelcourier to end the mission)");
    		    }
			}
	    }
    }

	if(dialogid == DIALOG_VEHICLE_LOCATE)
	{
		/*
		if(response)
		{
			new Float:currentVehPos[3];
			switch(listitem)
			{
				case 0:
				{
					if(playerData[playerid][playerVehicles][0] != -1)
					{
						playerData[playerid][playerVehicleLocating] = vehicleCount[playerData[playerid][playerVehicles][0]];
						GetVehiclePos(vehicleCount[playerData[playerid][playerVehicles][0]], currentVehPos[0], currentVehPos[1], currentVehPos[2]);
						SetPlayerMapIcon(playerid, MAP_ICON_VEHICLE_LOCATE, currentVehPos[0], currentVehPos[1], currentVehPos[2], 55, 0, MAPICON_GLOBAL);
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}A blue car has been placed on your map, this will lead you to your vehicle.");
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not own a vehicle in this slot.");
					}
				}
				case 1:
				{
					if(playerData[playerid][playerVehicles][1] != -1)
					{
						playerData[playerid][playerVehicleLocating] = vehicleCount[playerData[playerid][playerVehicles][1]];
						GetVehiclePos(vehicleCount[playerData[playerid][playerVehicles][1]], currentVehPos[0], currentVehPos[1], currentVehPos[2]);
						SetPlayerMapIcon(playerid, MAP_ICON_VEHICLE_LOCATE, currentVehPos[0], currentVehPos[1], currentVehPos[2], 55, 0, MAPICON_GLOBAL);
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}A blue car has been placed on your map, this will lead you to your vehicle.");
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not own a vehicle in this slot.");
					}
				}
				case 2:
				{
					if(playerData[playerid][playerVehicles][2] != -1)
					{
						playerData[playerid][playerVehicleLocating] = vehicleCount[playerData[playerid][playerVehicles][2]];
						GetVehiclePos(vehicleCount[playerData[playerid][playerVehicles][2]], currentVehPos[0], currentVehPos[1], currentVehPos[2]);
						SetPlayerMapIcon(playerid, MAP_ICON_VEHICLE_LOCATE, currentVehPos[0], currentVehPos[1], currentVehPos[2], 55, 0, MAPICON_GLOBAL);
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}A blue car has been placed on your map, this will lead you to your vehicle.");
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not own a vehicle in this slot.");
					}
				}
				case 3:
				{
					if(playerData[playerid][playerVehicles][3] != -1)
					{
						playerData[playerid][playerVehicleLocating] = vehicleCount[playerData[playerid][playerVehicles][3]];
						GetVehiclePos(vehicleCount[playerData[playerid][playerVehicles][3]], currentVehPos[0], currentVehPos[1], currentVehPos[2]);
						SetPlayerMapIcon(playerid, MAP_ICON_VEHICLE_LOCATE, currentVehPos[0], currentVehPos[1], currentVehPos[2], 55, 0, MAPICON_GLOBAL);
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}A blue car has been placed on your map, this will lead you to your vehicle.");
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not own a vehicle in this slot.");
					}
				}
			}
		}*/
	}

	/*if(dialogid == DIALOG_VEHICLE_RESPAWN)
	{
		if(response)
		{
			new message[128];
			switch(listitem)
			{
				case 0:
				{
					if(playerData[playerid][playerVehicles][0] != -1)
					{
						format(message, sizeof(message), "{B7B7B7}[SERVER] {FFFFFF}You have respawned your %s.", vehicleNames[vehicleData[playerData[playerid][playerVehicles][0]][vehicleModel] - 400]);
						SendClientMessage(playerid, COLOR_WHITE, message);
						respawnVehicle(playerData[playerid][playerVehicles][0]);
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not own a vehicle in this slot.");
					}
				}
				case 1:
				{
					if(playerData[playerid][playerVehicles][1] != -1)
					{
						format(message, sizeof(message), "{B7B7B7}[SERVER] {FFFFFF}You have respawned your %s.", vehicleNames[vehicleData[playerData[playerid][playerVehicles][1]][vehicleModel] - 400]);
						SendClientMessage(playerid, COLOR_WHITE, message);
						respawnVehicle(playerData[playerid][playerVehicles][1]);
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not own a vehicle in this slot.");
					}
				}
				case 2:
				{
					if(playerData[playerid][playerVehicles][2] != -1)
					{
						format(message, sizeof(message), "{B7B7B7}[SERVER] {FFFFFF}You have respawned your %s.", vehicleNames[vehicleData[playerData[playerid][playerVehicles][2]][vehicleModel] - 400]);
						SendClientMessage(playerid, COLOR_WHITE, message);
						respawnVehicle(playerData[playerid][playerVehicles][2]);
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not own a vehicle in this slot.");
					}
				}
				case 3:
				{
					if(playerData[playerid][playerVehicles][3] != -1)
					{
						format(message, sizeof(message), "{B7B7B7}[SERVER] {FFFFFF}You have respawned your %s.", vehicleNames[vehicleData[playerData[playerid][playerVehicles][3]][vehicleModel] - 400]);
						SendClientMessage(playerid, COLOR_WHITE, message);
						respawnVehicle(playerData[playerid][playerVehicles][3]);
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not own a vehicle in this slot.");
					}
				}
			}
		}
	}*/

	if(dialogid == DIALOG_MODMENU)
	{
		if(response)
		{
			for(new i=0;i<=ccount[playerid];i++)
			{
				if(listitem == i)
				{
					if(IsVehicleUpgradeCompatible(GetVehicleModel(GetPlayerVehicleID(playerid)),componentsid[playerid][i])) //just a verification
					{
						AddVehicleComponent(GetPlayerVehicleID(playerid), componentsid[playerid][i]);
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Vehicle successfully modified.");

						return cmd_vmod(playerid, " ");
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You can't add mod that to this vehicle.");
					}
				}
			}
		}
	}

	if(dialogid == DIALOG_VIPHAT)
	{
		if(response)
		{
			if(listitem == 0)
			{
				SetPlayerAttachedObject( playerid, 6, 18926, 2, 0.094485, 0.007215, 0.0, 0.000000, 0.000000, 0.000000, 1.200000, 1.200000, 1.200000  );
				EditAttachedObject(playerid, 6);
			}
			if(listitem == 1)
			{
				SetPlayerAttachedObject( playerid, 6, 18927, 2, 0.094485, 0.007215, 0.0, 0.000000, 0.000000, 0.000000, 1.200000, 1.200000, 1.200000  );
				EditAttachedObject(playerid, 6);
			}
			if(listitem == 2)
			{
				SetPlayerAttachedObject( playerid, 6, 18928, 2, 0.094485, 0.007215, 0.0, 0.000000, 0.000000, 0.000000, 1.200000, 1.200000, 1.200000  );
				EditAttachedObject(playerid, 6);
			}
			if(listitem == 3)
			{
				SetPlayerAttachedObject( playerid, 6, 18929, 2, 0.094485, 0.007215, 0.0, 0.000000, 0.000000, 0.000000, 1.200000, 1.200000, 1.200000  );
				EditAttachedObject(playerid, 6);
			}
			if(listitem == 4)
			{
				SetPlayerAttachedObject( playerid, 6, 18930, 2, 0.094485, 0.007215, 0.0, 0.000000, 0.000000, 0.000000, 1.200000, 1.200000, 1.200000  );
				EditAttachedObject(playerid, 6);
			}
			if(listitem == 5)
			{
				SetPlayerAttachedObject( playerid, 6, 18931, 2, 0.094485, 0.007215, 0.0, 0.000000, 0.000000, 0.000000, 1.200000, 1.200000, 1.200000  );
				EditAttachedObject(playerid, 6);
			}
			if(listitem == 6)
			{
				SetPlayerAttachedObject( playerid, 6, 18932, 2, 0.094485, 0.007215, 0.0, 0.000000, 0.000000, 0.000000, 1.200000, 1.200000, 1.200000  );
				EditAttachedObject(playerid, 6);
			}
			if(listitem == 7)
			{
				SetPlayerAttachedObject( playerid, 6, 18933, 2, 0.094485, 0.007215, 0.0, 0.000000, 0.000000, 0.000000, 1.200000, 1.200000, 1.200000  );
				EditAttachedObject(playerid, 6);
			}
			if(listitem == 8)
			{
				if (IsPlayerAttachedObjectSlotUsed( playerid, 6))
				{
					RemovePlayerAttachedObject( playerid, 6 );
				}
			}
		}
	}

	if(dialogid == DIALOG_VIPGUN)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0: // Deagle
				{
					playerData[playerid][vipWeapon] = 24;

					SendClientMessage(playerid, COLOR_YELLOW, "{58D3F7}[VIP WEAPON] {FFFFFF}Next time you spawn, you will spawn with a Deagle.");
				}
				case 1: // M4
				{
					playerData[playerid][vipWeapon] = 31;

					SendClientMessage(playerid, COLOR_YELLOW, "{58D3F7}[VIP WEAPON] {FFFFFF}Next time you spawn, you will spawn with an M4.");
				}
				case 2: // Sniper
				{
					playerData[playerid][vipWeapon] = 34;

					SendClientMessage(playerid, COLOR_YELLOW, "{58D3F7}[VIP WEAPON] {FFFFFF}Next time you spawn, you will spawn with a Sniper Rifle.");
				}
				case 3: // Sawnoff
				{
					playerData[playerid][vipWeapon] = 26;

					SendClientMessage(playerid, COLOR_YELLOW, "{58D3F7}[VIP WEAPON] {FFFFFF}Next time you spawn, you will spawn with a Sawnoff Shotgun.");
				}
				case 4: // Chainsaw
				{
					playerData[playerid][vipWeapon] = 9;

					SendClientMessage(playerid, COLOR_YELLOW, "{58D3F7}[VIP WEAPON] {FFFFFF}Next time you spawn, you will spawn with a Chainsaw.");
				}
				case 5: // MP5
				{
					playerData[playerid][vipWeapon] = 29;

					SendClientMessage(playerid, COLOR_YELLOW, "{58D3F7}[VIP WEAPON] {FFFFFF}Next time you spawn, you will spawn with an MP5.");
				}
				case 6: // Combat Shotgun
				{
					playerData[playerid][vipWeapon] = 27;

					SendClientMessage(playerid, COLOR_YELLOW, "{58D3F7}[VIP WEAPON] {FFFFFF}Next time you spawn, you will spawn with a Combat Shotgun.");
				}
				case 7: // micro smg
				{
					playerData[playerid][vipWeapon] = 28;

					SendClientMessage(playerid, COLOR_YELLOW, "{58D3F7}[VIP WEAPON] {FFFFFF}Next time you spawn, you will spawn with a Micro SMG.");
					
				}
			}
		}
	}

	if(dialogid == DIALOG_EXPLOSIVE_STORE)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					if (playerData[playerid][playerMoney] >= 1000)
					{
						playerData[playerid][playerExplosives] = playerData[playerid][playerExplosives] + 1;
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[BOMB SHOP] {FFFFFF}You purchased 1 explosive.");

						playerGiveMoney(playerid, -1000);
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[BOMB SHOP] {FFFFFF}You can't afford that.");
					}
				}

				case 1:
				{
					if (playerData[playerid][playerMoney] >= 2000)
					{
						playerData[playerid][playerExplosives] = playerData[playerid][playerExplosives] + 2;
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[BOMB SHOP] {FFFFFF}You purchased 2 explosives.");

						playerGiveMoney(playerid, -2000);
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[BOMB SHOP] {FFFFFF}You can't afford that.");
					}
				}

				case 2:
				{
					if (playerData[playerid][playerMoney] >= 5000)
					{
						playerData[playerid][playerExplosives] = playerData[playerid][playerExplosives] + 5;
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[BOMB SHOP] {FFFFFF}You purchased 5 explosives.");

						playerGiveMoney(playerid, -5000);
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[BOMB SHOP] {FFFFFF}You can't afford that.");
					}
				}

				case 3:
				{
					if (playerData[playerid][playerMoney] >= 10000)
					{
						playerData[playerid][playerExplosives] = playerData[playerid][playerExplosives] + 10;
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[BOMB SHOP] {FFFFFF}You purchased 10 explosives.");

						playerGiveMoney(playerid, -10000);
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[BOMB SHOP] {FFFFFF}You can't afford that.");
					}
				}

				case 4:
				{
					if (playerData[playerid][playerExplosives] >= 1)
					{
						playerData[playerid][playerExplosives] = playerData[playerid][playerExplosives] - 1;
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[BOMB SHOP] {FFFFFF}You sold 1 explosive.");

						playerGiveMoney(playerid, 500);
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[BOMB SHOP] {FFFFFF}You don't have any explosives to sell.");
					}
				}
			}

			ShowPlayerDialog(playerid, DIALOG_EXPLOSIVE_STORE, DIALOG_STYLE_LIST, "CZCNR Bomb Shop", "1x Explosive {D87C3E}$1,000{FFFFFF} \n2x Explosives {D87C3E}$2,000{FFFFFF} \n5x Explosives {D87C3E}$5,000{FFFFFF} \n10x Explosives {D87C3E}$10,000{FFFFFF} \nSell explosives {D87C3E}$500{FFFFFF} each", "Select", "Cancel");
		}
	}

	if(dialogid == DIALOG_ATTACH_INDEX_SELECTION)
	{
		if(response)
		{
			if(IsPlayerAttachedObjectSlotUsed(playerid, listitem))
			{
				ShowPlayerDialog(playerid, DIALOG_ATTACH_EDITREPLACE, DIALOG_STYLE_MSGBOX, \
				"Toy System - Delete/Edit", "{FFFFFF}Do you wish to edit the attachment in that slot, or delete it?", "Edit", "Delete");
			}
			else
			{
				ShowPlayerDialog(playerid,DIALOG_ATTACH_OBJECT_SELECTION,DIALOG_STYLE_LIST,"Toy System - Select Object","Server Objects Menu\nCustom Object","Next","Back");
			}
			SetPVarInt(playerid, "AttachmentIndexSel", listitem);
		}

		return 1;
	}

	if(dialogid == DIALOG_ATTACH_OBJECT_SELECTION)
	{
		if(!response)
		{
			cmd_toys(playerid,"");
		}
		if(response)
		{
			if(listitem==0) ShowModelSelectionMenuEx(playerid, AttachmentObjectsList, 228+38, "Toy System", DIALOG_ATTACH_MODEL_SELECTION, 0.0, 0.0, 0.0, 1.0, 0x00000099, 0x000000EE, 0xACCBF1FF);
			if(listitem==1) 
			{
				if(playerData[playerid][playerVIPLevel] == 3)
					ShowPlayerDialog(playerid,DIALOG_ATTACH_OBJECT2_SELECTION,DIALOG_STYLE_INPUT,"Toy System - Insert objectid","{FFFFFF}Put your custom objectid below, You can also take help from ''http://wiki.sa-mp.com''.","Edit","Back");
				else
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] Only gold VIPs can use this feature.");
			}
		}
	}
	
	if(dialogid == DIALOG_ATTACH_OBJECT2_SELECTION)
	{
		if(!response)
		{   ShowPlayerDialog(playerid,DIALOG_ATTACH_OBJECT_SELECTION,DIALOG_STYLE_LIST,"Toy System - Select Object","Server Objects Menu\nCustom Object","Next","Back");    }
		if(response)
		{
			if(!strlen(inputtext))return SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] You can't leave the coloumn blank."),ShowPlayerDialog(playerid,DIALOG_ATTACH_OBJECT2_SELECTION,DIALOG_STYLE_INPUT,"Toy System - Insert objectid","{FFFFFF}Put your custom objectid below, You can also take help from ''http://wiki.sa-mp.com''.","Edit","Back");
			if(!isNumber(inputtext)) return SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] You can't fill a object name, only object id's allowed."),ShowPlayerDialog(playerid,DIALOG_ATTACH_OBJECT2_SELECTION,DIALOG_STYLE_INPUT,"Toy System - Insert objectid","{FFFFFF}Put your custom objectid below, You can also take help from ''http://wiki.sa-mp.com''.","Edit","Back");
			new obj;
			if(!sscanf(inputtext, "i", obj))
			{
				if(GetPVarInt(playerid, "AttachmentUsed") == 1) EditAttachedObject(playerid, obj);
				else
				{
					SetPVarInt(playerid, "AttachmentModelSel", obj);
					new string[256+1];
					new dialog[500];
					for(new x;x<sizeof(AttachmentBones);x++)
					{
						format(string, sizeof(string), "Bone %s\n", AttachmentBones[x]);
						strcat(dialog,string);
					}
					ShowPlayerDialog(playerid, DIALOG_ATTACH_BONE_SELECTION, DIALOG_STYLE_LIST, \
					"Toy System - Bone Selection", dialog, "Select", "Cancel");
				}
			}
		}
	}
	
	if(dialogid == DIALOG_ATTACH_EDITREPLACE)
	{
		if(response) EditAttachedObject(playerid, GetPVarInt(playerid, "AttachmentIndexSel"));
		else
		{
			RemovePlayerAttachedObject(playerid, GetPVarInt(playerid, "AttachmentIndexSel"));
			playerData[playerid][toyStatus][GetPVarInt(playerid, "AttachmentIndexSel")] = false;
			DeletePVar(playerid, "AttachmentIndexSel");
		}
	}

	if(dialogid == DIALOG_ATTACH_BONE_SELECTION)
	{
		if(response)
            {
                SetPlayerAttachedObject(playerid, GetPVarInt(playerid, "AttachmentIndexSel"), GetPVarInt(playerid, "AttachmentModelSel"), listitem+1);
                EditAttachedObject(playerid, GetPVarInt(playerid, "AttachmentIndexSel"));
                SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You can also hold SPACE and use MOUSE to view from either sides.");
            }
            DeletePVar(playerid, "AttachmentIndexSel");
            DeletePVar(playerid, "AttachmentModelSel");
            return 1;
	}

	if(dialogid == DIALOG_MECHANIC)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0: // Repair
				{
					if(playerData[playerid][playerCanRepair])
					{
						if(playerData[playerid][playerMoney] >= 300)
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}You repaired the vehicle for {FFDC2E}$300");
							RepairVehicle(GetPlayerVehicleID(playerid));
							PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);

							playerData[playerid][fixTimer] = SetTimerEx("reFix", 60000, false, "i", playerid);
							playerData[playerid][playerCanRepair] = false;
							playerTakeMoney(playerid, 300);
							playerGiveXP(playerid, 5);
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot afford this.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Please wait before using this command again.");
					}
				}
				case 1: // Add Nitro
				{
					if(playerData[playerid][playerCanNOS])
					{
						if(playerData[playerid][playerMoney] >= 1000)
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}You added nos to the vehicle for {FFDC2E}$1000");
							AddVehicleComponent(GetPlayerVehicleID(playerid), 1010);
							PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);

							playerData[playerid][nosTimer] = SetTimerEx("reNOS", 60000, false, "i", playerid);
							playerData[playerid][playerCanNOS] = false;
							playerTakeMoney(playerid, 1000);
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot afford this.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Please wait before using this command again.");
					}
				}
				case 2: // Remove EMP
				{
					if(playerData[playerid][playerCanREMP])
					{
						if(playerData[playerid][playerMoney] >= 2000)
						{
							new tvehicleID = GetPlayerVehicleID(playerid);
							new engine, lights, alarm, doors, bonnet, boot, objective;
							GetVehicleParamsEx(tvehicleID, engine, lights, alarm, doors, bonnet, boot, objective);

							if(engine == 0)
							{
								SetVehicleParamsEx(tvehicleID, 1, lights, alarm, doors, bonnet, boot, objective);
								KillTimer(resetEMPTimer[tvehicleID]);

								playerData[playerid][mechREMPTimer] = SetTimerEx("mechReEmp", 300000, false, "i", playerid);
								playerData[playerid][playerCanREMP] = false;
								playerTakeMoney(playerid, 2000);

								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}You fixed the engine for {FFDC2E}$2000");
								PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
								PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
								playerGiveXP(playerid, 10);
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This vehicle does not have a broken engine.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot afford this.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Please wait before using this command again.");
					}
				}
				case 3: // Flip
				{
					if(playerData[playerid][playerCanFlip])
					{
						if(playerData[playerid][playerMoney] >= 500)
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[JOB] {FFFFFF}You flipped the vehicle for {FFDC2E}$500");

							new currentveh,
								Float:angle
							;

							currentveh = GetPlayerVehicleID(playerid);
							GetVehicleZAngle(currentveh, angle);
							SetVehicleZAngle(currentveh, angle);

							playerData[playerid][flipTimer] = SetTimerEx("reFlip", 30000, false, "i", playerid);
							playerData[playerid][playerCanFlip] = false;
							playerTakeMoney(playerid, 500);
							playerGiveXP(playerid, 5);
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot afford this.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Please wait before using this command again.");
					}
				}
			}
		}
	}

	if (dialogid == DIALOG_REDEMPTION)
	{
		if (response)
		{
			switch(listitem)
			{
				case 0: // Redeem VIP
				{
					if (playerData[playerid][playerVIPLevel] > 0)
					{
						new string[500];
						format(string, sizeof(string), "%s{98B0CD}CNRSF Code Redemption Service\n\n", string);
						format(string, sizeof(string), "%s{FFFFFF}{58D3F7}You already have a VIP membership. \n\n", string);
						format(string, sizeof(string), "%s{FFFFFF}At this time, you're unable to redeem this code.\n", string);
						format(string, sizeof(string), "%s{FFFFFF}Please wait until it expires or contact a shop admin for assistance.\n\n", string);

						format(string, sizeof(string), "%s{58D3F7}www.czcnr.ml", string);

						ShowPlayerDialog(playerid, DIALOG_VIP_ALREADY, DIALOG_STYLE_MSGBOX, "VIP Redemption", string, "OK", "");
					}
					else
					{
						ShowPlayerDialog(playerid, DIALOG_REDEEM_VIP, DIALOG_STYLE_INPUT, "VIP Redemption Code", "{FFFFFF}Enter the redemption code as seen on www.czcnr.ml", "Redeem", "Cancel");
					}
				}

				case 1: // Redeem Other Item
				{
					ShowPlayerDialog(playerid, DIALOG_PRODUCT, DIALOG_STYLE_INPUT, "Product Redemption Code", "{FFFFFF}Enter the redemption code as seen on shop.sfcnr.in", "Redeem", "Cancel");
				}
			}
		}
	}

	if (dialogid == DIALOG_REDEEM_VIP)
	{
		if (response)
		{
			new
				redemptionCode[250]
			;

			format(redemptionCode, sizeof(redemptionCode), "cnrsfshop.com/api/redeem_vip.php?redeem=%s&user=%s", inputtext, playerData[playerid][playerNamee]);
			HTTP(playerid, HTTP_GET, redemptionCode, "", "check_vip");
		}
	}

	if (dialogid == DIALOG_PRODUCT)
	{
		new
			redemptionCode[250]
		;

		format(redemptionCode, sizeof(redemptionCode), "cnrsfshop.com/api/redeem_product.php?redeem=%s&user=%s&jailtime=%i", inputtext, playerData[playerid][playerNamee], playerData[playerid][playerJailTime]);
		HTTP(playerid, HTTP_GET, redemptionCode, "", "check_code");
	}

	if (dialogid == DIALOG_FORCE_RESPAWN)
	{
		if (response)
		{
			// Force respawn
			SetPlayerVirtualWorld(playerid, 0);
			SetPlayerInterior(playerid, 0);

			playerData[playerid][hasSpawned] = false;
			SpawnPlayer(playerid);
		}
	}

	if (dialogid == DIALOG_MINIGAMES)
	{
		if (response)
		{
			switch (listitem)
			{
				case 0: // Minigun DM
				{
					new randSpawn = random(8);
					switch(randSpawn)
					{
						case 0:
						{
							SetPlayerPos(playerid, -1129.8909, 1057.5424, 1346.4141);
						}
						case 1:
						{
							SetPlayerPos(playerid, -974.1805, 1077.0630, 1344.9895);
						}
						case 2:
						{
							SetPlayerPos(playerid, -997.8885, 1096.0400, 1342.6517);
						}
						case 3:
						{
							SetPlayerPos(playerid, -1036.1115, 1024.3964, 1343.3551);
						}
						case 4:
						{
							SetPlayerPos(playerid, -1075.6144, 1032.7413, 1342.7317);
						}
						case 5:
						{
							SetPlayerPos(playerid, -1085.2362, 1053.7657, 1343.3536);
						}
						case 6:
						{
							SetPlayerPos(playerid, -1101.0815, 1084.6434, 1341.8438);
						}
						case 7:
						{
							SetPlayerPos(playerid, -1093.1536, 1058.8173, 1341.3516);
						}
					}

					newPlayerColour(playerid);
					SetPlayerTeam(playerid, NO_TEAM);
					ResetPlayerWeapons(playerid);

					SetPlayerInterior(playerid, 10);
					SetPlayerVirtualWorld(playerid, 169);

					playerData[playerid][isInDM] = true; // Prevent scores etc - also respawn
					playerData[playerid][isInEvent] = true;
					playerData[playerid][adminWeapon] = true; // Prevent anti-cheat kick
					GivePlayerWeaponEx(playerid, 31, 50000);

					TextDrawShowForPlayer(playerid, dmBox[0]);
					TextDrawShowForPlayer(playerid, dmBox[1]);
					TextDrawShowForPlayer(playerid, dmBox[2]);
					TextDrawShowForPlayer(playerid, dmBox[3]);
					TextDrawShowForPlayer(playerid, dmBox[4]);
					TextDrawShowForPlayer(playerid, dmBox[5]);
					TextDrawShowForPlayer(playerid, dmBox[6]);

					PlayerTextDrawHide(playerid, playerData[playerid][Eggs][0]);
					PlayerTextDrawHide(playerid, playerData[playerid][Eggs][1]);
					PlayerTextDrawHide(playerid, playerData[playerid][Eggs][2]);

					dmStats(playerid);

					PlayerTextDrawShow(playerid, playerData[playerid][dmArena][0]);
					PlayerTextDrawShow(playerid, playerData[playerid][dmArena][1]);
					PlayerTextDrawShow(playerid, playerData[playerid][dmArena][2]);
					PlayerTextDrawShow(playerid, playerData[playerid][dmArena][3]);

					for (new i=0; i<MAX_PLAYERS; i++)
					{
						if(playerData[i][isInDM])
						{
							new dmJoin[100];
							format(dmJoin, sizeof(dmJoin), "{FAAC58}%s(%i) {FFFFFF}joined the arena.", playerData[playerid][playerNamee], playerid);
							SendClientMessage(i, COLOR_WHITE, dmJoin);
						}
					}
				}
			}
		}
	}

	if (dialogid == DIALOG_CONFIRMSALE)
	{
		if (response)
		{
			new otherPlayer = playerData[playerid][vSellTo];
			playerData[otherPlayer][vBuyFrom] = playerid;
			playerData[otherPlayer][vBuyPrice] = playerData[playerid][vSellPrice];
			playerData[otherPlayer][vBuyID] = playerData[playerid][vSellID];

			new offer[300];
			format(offer, sizeof(offer), "{FE9A2E}[VEHICLE TRADE] {FFFFFF}%s(%i) wishes to trade you their vehicle for {FFDC2E}$%s {FFFFFF}- type /buyvehicle <%i> to accept!", playerData[playerid][playerNamee], playerid, FormatNumber(playerData[playerid][vSellPrice]), playerid);
			SendClientMessage(otherPlayer, 0xFF0000FF, offer);

			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}We've sent your request to the player, please wait for them to accept.");
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cancelled the trade.");
		}
	}

	if (dialogid == DIALOG_CONFIRMSALESERVER)
	{
		if (response)
		{
			new i = playerData[playerid][vehicleMenu];

			for(new v = 0; v < sizeof(dealershipData); v++)
			{
				if(dealershipData[v][vehicle_model] == VehicleInfo[i][vModelID])
				{
					new
						sellPrice = dealershipData[v][vehicle_price] / 2,
						query[300]
					;

					format(query, sizeof(query), "DELETE FROM `vehicles` WHERE `id` = '%d'", i); //Here's the problem, syntax problem
					db_query(DB: VEHICLESDB, query);

					playerGiveMoney(playerid, sellPrice);
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Your vehicle has been sold.");

					VehicleInfo[i][vModelID] = -1;
					VehicleInfo[i][vOwner] = -1;
					VehicleInfo[i][vLocked] = true;
					VehicleInfo[i][vX] = 0.0;
					VehicleInfo[i][vY] =0.0;
					VehicleInfo[i][vZ] = 0.0;
					VehicleInfo[i][vAngle] = 0.0;
					VehicleInfo[i][vColor1] = -1;
					VehicleInfo[i][vColor2] = -1;
					VehicleInfo[i][vPaintjob] =-1;
					VehicleInfo[i][vHealth] = 0;
					DestroyVehicle(VehicleInfo[i][vehicleID]);
					VehicleInfo[i][vehicleID] = INVALID_VEHICLE_ID;
					db_query(DB: VEHICLESDB, query);
					printf("Vehicle ID : %d has been deleted from DB", i); // Debug, check the ID mate, exist on DB or not!
					break;
				}
				else
				{
					continue;
				}
			}

		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cancelled the sale.");
		}
	}

	if(dialogid == DIALOG_VEHICLEOPTIONS)
	{
		if (response)
		{
			new i = playerData[playerid][vehicleMenu];
			switch(listitem)
			{
				case 0: // Locate Vehicle
				{
					new Float:vehx, Float:vehy, Float:vehz;
					GetVehiclePos(VehicleInfo[i][vehicleID], vehx, vehy, vehz);

					playerData[playerid][playerVehicleLocating] = VehicleInfo[i][vehicleID];
					SetPlayerMapIcon(playerid, MAP_ICON_VEHICLE_LOCATE, vehx, vehy, vehz, 41, 0, MAPICON_GLOBAL);
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}A red waypoint icon has been placed on your map, this will lead you to your vehicle.");
				}

				case 1: // Respawn Vehicle
				{
					DestroyVehicle(VehicleInfo[i][vehicleID]);
					OwnedVehicleRespawn(i);

					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Your vehicle has been respawned.");
				}

				case 2: // Sell to server
				{
					for(new v = 0; v < sizeof(dealershipData); v++)
					{
						if(dealershipData[v][vehicle_model] == VehicleInfo[i][vModelID])
						{
							new
								sellPrice = dealershipData[v][vehicle_price] / 2
							;

							// Ask the seller to confirm this before offering it to the buyer
							new string[1400];
							format(string, sizeof(string), "%sAre you sure you wish to sell your vehicle to the server?\n\n", string);

							format(string, sizeof(string), "%s{98B0CD}Vehicle: {FFFFFF}%s\n", string, vehicleNames[dealershipData[v][vehicle_model] - 400]);
							format(string, sizeof(string), "%s{98B0CD}Sell To: {FFFFFF}czcnr\n", string);
							format(string, sizeof(string), "%s{98B0CD}You Will Receive: {FFFFFF}$%s\n\n", string, FormatNumber(sellPrice));

							format(string, sizeof(string), "%s{FFFFFF}This action is irreversible. The vehicle will be deleted from the server.", string);

							ShowPlayerDialog(playerid, DIALOG_CONFIRMSALESERVER, DIALOG_STYLE_MSGBOX, "Sell Vehicle", string, "Confirm", "Cancel");

							break;
						}
						else
						{
							continue;
						}
					}
				}
			}
		}
		else
		{
			//return cmd_myvehicles(playerid, "");
		}
	}

	if(dialogid == DIALOG_OPTIONSLIST)
	{
		if (response)
		{
			new
				DBResult:locatingResult,
				locatingQuery[128],
				resultCount,
				idstring[48],
				bool:found,
				dialogtitle[60]
			;

			format(locatingQuery, sizeof(locatingQuery), "SELECT * FROM `vehicles` WHERE `owner` = '%i' LIMIT %i, 1", playerData[playerid][actualID], listitem);
			locatingResult = db_query(DB: VEHICLESDB, locatingQuery);
			resultCount = db_num_rows(locatingResult);

			if(resultCount > 0)
			{
				db_get_field_assoc(locatingResult, "id", idstring, 3);
				new tvehicleID = strval(idstring);

				db_get_field_assoc(locatingResult, "modelid", idstring, 3);
				new vehicleModel = strval(idstring);

				for(new i; i < MAX_SAVED_VEHICLES; i++)
				{
					if (tvehicleID != i) continue;

					if(i == tvehicleID)
					{
						found = true;

						playerData[playerid][vehicleMenu] = i;

						format(dialogtitle, sizeof(dialogtitle), "Vehicle: %s", vehicleNames[vehicleModel - 400]);
						ShowPlayerDialog(playerid, DIALOG_VEHICLEOPTIONS, DIALOG_STYLE_LIST, dialogtitle, "Locate Vehicle \nRespawn Vehicle \nSell Vehicle", "OK", "Close");

						break;
					}
				}

				if(!found)
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Unable to find information about that vehicle. Please use /ask for more information.");
				}
			}
		}
	}

	if(dialogid == DIALOG_ADMINVEHICLEOPTIONS)
	{
		if (response)
		{
			new i = playerData[playerid][vehicleMenu];
			switch(listitem)
			{
				case 0: // Bring
				{
					new Float:fX, Float:fY, Float:fZ, message[128];

					GetPlayerPos(playerid, fX, fY, fZ);
					SetVehiclePos(VehicleInfo[i][vehicleID], fX, fY, fZ);
					SetPlayerPos(playerid, fX, fY, (fZ + 3.0));

					new log[250];
					format(log, sizeof(log), "%s(%i) has teleported owned vehicle id %i to them", playerData[playerid][tempAdminName], playerid, VehicleInfo[i][vehicleID]);
					SendAdminText(playerid, log);

					format(message, sizeof(message), "{FE9A2E}[ADMIN] {FFFFFF}You teleported the vehicle %i to your current location.", VehicleInfo[i][vehicleID]);
					SendClientMessage(playerid, COLOR_WHITE, message);
				}
			}
		}
		else
		{
			//return cmd_myvehicles(playerid, "");
		}
	}

	if(dialogid == DIALOG_ADMINOPTIONSLIST)
	{
		if (response)
		{
			new
				DBResult:locatingResult,
				locatingQuery[128],
				resultCount,
				idstring[48],
				bool:found,
				dialogtitle[60],
				playerwho = playerData[playerid][playerGetStats]
			;

			format(locatingQuery, sizeof(locatingQuery), "SELECT * FROM `vehicles` WHERE `owner` = '%i' LIMIT %i, 1", playerData[playerwho][actualID], listitem);
			locatingResult = db_query(DB: VEHICLESDB, locatingQuery);
			resultCount = db_num_rows(locatingResult);

			if(resultCount > 0)
			{
				db_get_field_assoc(locatingResult, "id", idstring, 3);
				new tvehicleID = strval(idstring);

				db_get_field_assoc(locatingResult, "modelid", idstring, 3);
				new vehicleModel = strval(idstring);

				for(new i; i < MAX_SAVED_VEHICLES; i++)
				{
					if (tvehicleID != i) continue;

					if(i == tvehicleID)
					{
						found = true;

						playerData[playerid][vehicleMenu] = DLParam;

						format(dialogtitle, sizeof(dialogtitle), "%s's Vehicle: %s", playerData[playerwho][playerNamee], vehicleNames[vehicleModel - 400]);
						ShowPlayerDialog(playerid, DIALOG_ADMINVEHICLEOPTIONS, DIALOG_STYLE_LIST, dialogtitle, "Bring Vehicle", "OK", "Close");

						break;
					}
				}

				if(!found)
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Unable to find information about that vehicle. This is caused by a bad query to the database.");
				}
			}
		}
	}

	if(dialogid == DIALOG_HOUSEOPTIONS)
	{
		if (response)
		{
			new i = playerData[playerid][houseMenu];
			switch(listitem)
			{
				case 0: // Set as spawn
				{
					playerData[playerid][spawnHouse] = houseStuff[i][house_id];
					SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}You will now spawn at your house. Type /removespawn to disable this.");
				}
			}
		}
		else
		{
			//return cmd_myvehicles(playerid, "");
		}
	}

	if(dialogid == DIALOG_HOUSELIST)
	{
		if (response)
		{
			new
				DBResult:locatingResult,
				locatingQuery[128],
				resultCount,
				bool:found,
				dialogtitle[60]
			;

			format(locatingQuery, sizeof(locatingQuery), "SELECT * FROM `house_data` WHERE `house_owner` = '%s' LIMIT %i, 1", playerData[playerid][playerNamee], listitem);
			locatingResult = db_query(DB: HOUSEDB, locatingQuery);
			resultCount = db_num_rows(locatingResult);

			if(resultCount > 0)
			{
				new houseTitle[48], houseID, temporaryString[54];

				db_get_field_assoc(locatingResult, "house_id", temporaryString, 3);
				houseID = strval(temporaryString);

				db_get_field_assoc(locatingResult, "house_title", temporaryString, 48); // House Title
				format(houseTitle, 48, temporaryString);

				for(new i; i < MAX_SCRIPT_HOUSES; i++)
				{
					if (houseStuff[i][house_id] != houseID) continue;

					if(houseStuff[i][house_id] == houseID)
					{
						found = true;

						playerData[playerid][houseMenu] = i;

						format(dialogtitle, sizeof(dialogtitle), "House ID %i", houseID);
						ShowPlayerDialog(playerid, DIALOG_HOUSEOPTIONS, DIALOG_STYLE_LIST, dialogtitle, "Set as spawn", "OK", "Close");

						break;
					}
				}

				if(!found)
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Unable to find information about that house. Please use /ask for more information.");
				}
			}
		}
	}

	if(dialogid == DIALOG_ADMINHOUSEOPTIONS)
	{
		if (response)
		{
			new i = playerData[playerid][houseMenu];
			switch(listitem)
			{
				case 0: // Teleport to
				{
					new
						Float:x,
						Float:y,
						Float:z
					;

					x = houseStuff[i][houseX];
					y = houseStuff[i][houseY];
					z = houseStuff[i][houseZ];

					SetPlayerPos(playerid, x, y, z);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);
				}
			}
		}
	}

	if(dialogid == DIALOG_ADMINHOUSELIST)
	{
		if (response)
		{
			new
				DBResult:locatingResult,
				locatingQuery[128],
				resultCount,
				bool:found,
				dialogtitle[60],
				playerwho = playerData[playerid][playerGetStats]
			;

			format(locatingQuery, sizeof(locatingQuery), "SELECT * FROM `house_data` WHERE `house_owner` = '%s' LIMIT %i, 1", playerData[playerwho][playerNamee], listitem);
			locatingResult = db_query(DB: HOUSEDB, locatingQuery);
			resultCount = db_num_rows(locatingResult);

			if(resultCount > 0)
			{
				new houseTitle[48], houseID, temporaryString[54];

				db_get_field_assoc(locatingResult, "house_id", temporaryString, 3);
				houseID = strval(temporaryString);

				db_get_field_assoc(locatingResult, "house_title", temporaryString, 48); // House Title
				format(houseTitle, 48, temporaryString);

				for(new i; i < MAX_SCRIPT_HOUSES; i++)
				{
					if (houseStuff[i][house_id] != houseID) continue;

					if(houseStuff[i][house_id] == houseID)
					{
						found = true;

						playerData[playerid][houseMenu] = i;

						format(dialogtitle, sizeof(dialogtitle), "House ID %i", houseID);
						ShowPlayerDialog(playerid, DIALOG_ADMINHOUSEOPTIONS, DIALOG_STYLE_LIST, dialogtitle, "Teleport to", "OK", "Close");

						break;
					}
				}

				if(!found)
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Unable to find information about that house. Please use /ask for more information.");
				}
			}
		}
	}

	if (dialogid == DIALOG_HOUSESFORSALE)
	{
		if (response)
		{
			/*new debug123[100];
			format(debug123, 100, "ID: %i", houseStuff[DLParam][house_id]);
			SendClientMessage(playerid, COLOR_WHITE, debug123);*/

			playerData[playerid][houseFindIteration] = 0;

			playerData[playerid][playerHouseLocating][0] = houseStuff[DLParam][houseX];
			playerData[playerid][playerHouseLocating][1] = houseStuff[DLParam][houseY];
			playerData[playerid][playerHouseLocating][2] = houseStuff[DLParam][houseZ];

			if (playerData[playerid][houseFindIteration] > 0)
			{
				RemovePlayerMapIcon(playerid, MAP_ICON_HOUSE_LOCATE);
			}

			SetPlayerMapIcon(playerid, MAP_ICON_HOUSE_LOCATE, houseStuff[DLParam][houseX], houseStuff[DLParam][houseY], houseStuff[DLParam][houseZ], 41, 0, MAPICON_GLOBAL);
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[HOUSE SEARCH] {FFFFFF}A red waypoint icon has been placed on your map, this will lead you to the house.");

			playerData[playerid][houseTimer] = SetTimerEx("locateHouse", 3000, true, "i", playerid);
		}
	}

	return 1;
}
