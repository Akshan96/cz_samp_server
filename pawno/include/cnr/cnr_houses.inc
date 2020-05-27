#define MAX_SCRIPT_HOUSES 800
#define MAX_PLAYER_HOUSES 3
#define MAX_VIP_HOUSES 6
#pragma tabsize 0

enum housestore
{
	house_id,
	house_owner[48],
	house_bought,
	house_price,
	house_password[25],
	house_title[25],
	houseLock,
	houseAlarm,
	interiorID,
	Float: houseX,
	Float: houseY,
	Float: houseZ,
	Float: interiorX,
	Float: interiorY,
	Float: interiorZ,
	Float: interiorA,
	Text3D: label,
	Text3D: infoLabel
}

new
	xHouses,
	DB:HOUSEDB,
	houseStuff[MAX_SCRIPT_HOUSES][housestore],
	houseECP[MAX_SCRIPT_HOUSES], // Enter
	houseECP2[MAX_SCRIPT_HOUSES] // Exit
;

forward load_houses();
public load_houses()
{
	new DBResult:qresult, count = 0, value[328];
	if(!db_query(DB: HOUSEDB, "SELECT * FROM `house_data`"))
	{
		print("HOUSE SYSTEM :: No houses were found in \"Houses.db\" :: 0 Loaded");
	}
	else
	{
		qresult = db_query(DB: HOUSEDB, "SELECT * FROM `house_data`");
		count = db_num_rows(qresult);
		for(new i = 0; i < count; i++)
		{
			if(count <= MAX_SCRIPT_HOUSES)
			{
				// Fetch data
				db_get_field_assoc(qresult, "house_id", value, 5); // House ID
				houseStuff[i][house_id] = strval(value);

				db_get_field_assoc(qresult, "house_owner", value, 48); // House Owner
				format(houseStuff[i][house_owner], 48, value);

				db_get_field_assoc(qresult, "house_password", value, 48); // House Password
				format(houseStuff[i][house_password], 48, value);

				db_get_field_assoc(qresult, "house_title", value, 48); // House Title
				format(houseStuff[i][house_title], 48, value);

				db_get_field_assoc(qresult, "house_bought", value, 20); // House X Position
				houseStuff[i][house_bought] = strval(value);

				db_get_field_assoc(qresult, "house_price", value, 20); // House X Position
				houseStuff[i][house_price] = strval(value);

				db_get_field_assoc(qresult, "houseX", value, 20); // House X Position
				houseStuff[i][houseX] = floatstr(value);

				db_get_field_assoc(qresult, "houseY", value, 20); // House Y Position
				houseStuff[i][houseY] = floatstr(value);

				db_get_field_assoc(qresult, "houseZ", value, 20); // House Z Position
				houseStuff[i][houseZ] = floatstr(value);

				db_get_field_assoc(qresult, "interiorX", value, 20); // Interior X Position
				houseStuff[i][interiorX] = floatstr(value);

				db_get_field_assoc(qresult, "interiorY", value, 20); // Interior Y Position
				houseStuff[i][interiorY] = floatstr(value);

				db_get_field_assoc(qresult, "interiorZ", value, 20); // Interior Z Position
				houseStuff[i][interiorZ] = floatstr(value);

				db_get_field_assoc(qresult, "interiorAngle", value, 20); // Interior Angle Position
				houseStuff[i][interiorA] = floatstr(value);

				db_get_field_assoc(qresult, "interiorID", value, 20); // Interior ID
				houseStuff[i][interiorID] = strval(value);

				db_get_field_assoc(qresult, "lockType", value, 20); // Lock Type
				houseStuff[i][houseLock] = strval(value);

				db_get_field_assoc(qresult, "houseAlarm", value, 20); // Alarm 1/0
				houseStuff[i][houseAlarm] = strval(value);

				// Create house checkpoint
				houseECP[i] = CreateDynamicCP(houseStuff[i][houseX], houseStuff[i][houseY], houseStuff[i][houseZ], 1.5, 0);
				houseECP2[i] = CreateDynamicCP(houseStuff[i][interiorX], houseStuff[i][interiorY], houseStuff[i][interiorZ], 1.5, 150 + houseStuff[i][house_id]);

				// House Labels
				new labelstring[200];
				switch(houseStuff[i][house_bought])
				{
					case 0: // For Sale
					{
						houseStuff[i][label] = CreateDynamic3DTextLabel("{58D3F7}[FOR SALE]", COLOR_WHITE, houseStuff[i][houseX], houseStuff[i][houseY], houseStuff[i][houseZ] + 0.2, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, -1);
						format(labelstring, sizeof(labelstring), "{FFFFFF}/buyhouse {FFDC2E}%i {FFFFFF}\nPrice: {FFDC2E}$%i", houseStuff[i][house_id], houseStuff[i][house_price]);
					}
					case 1: // Owned
					{
						houseStuff[i][label] = CreateDynamic3DTextLabel("{58D3F7}[ALT TO ENTER]", COLOR_WHITE, houseStuff[i][houseX], houseStuff[i][houseY], houseStuff[i][houseZ] + 0.2, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, -1);
						format(labelstring, sizeof(labelstring), "{FFFFFF}Owner: {FFDC2E}%s\n{FFFFFF}House ID: {FFDC2E}%i", houseStuff[i][house_owner], houseStuff[i][house_id], houseStuff[i][house_price]);
					}
				}

				// Information Label
				houseStuff[i][infoLabel] = CreateDynamic3DTextLabel(labelstring, 0xFF0000FF, houseStuff[i][houseX], houseStuff[i][houseY], houseStuff[i][houseZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, -1);

				// ++ xHouses
				xHouses++;

				// Continue loading houses
				db_next_row(qresult);
			}
		}

		db_free_result(qresult);
	}
}

forward reloadHouses();
public reloadHouses()
{
	for(new i = 0; i < MAX_SCRIPT_HOUSES; i++)
	{
		DestroyDynamic3DTextLabel(houseStuff[i][infoLabel]);
		DestroyDynamic3DTextLabel(houseStuff[i][label]);
		DestroyDynamicCP(houseECP[i]);
		DestroyDynamicCP(houseECP2[i]);
	}

	load_houses();
}

forward intoHouseEx(playerid, houseid, silent);
public intoHouseEx(playerid, houseid, silent)
{
	//
	// Set position
	SetPlayerPos(playerid, houseStuff[houseid][interiorX], houseStuff[houseid][interiorY], houseStuff[houseid][interiorZ]);
	SetPlayerInterior(playerid, houseStuff[houseid][interiorID]);
	SetPlayerVirtualWorld(playerid, 150 + houseStuff[houseid][house_id]);
	SetPlayerFacingAngle(playerid, houseStuff[houseid][interiorA]);

	//
	// Set data
	playerData[playerid][playerInsideHouse] = houseid;
	playerData[playerid][playerCheckpointTime] = GetTickCount();

	if (silent == 0)
	{
		if(!strcmp(houseStuff[houseid][house_owner], playerData[playerid][playerNamee], true))
		{
			SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}Welcome home! Type /housemenu to configure your property. To leave, use the checkpoint or type {58D3F7}/exithouse{FFFFFF}.");
		}
		else
		{
			new enterString[200];
			format(enterString, sizeof(enterString), "{FFDC2E}[HOUSE] {FFFFFF}This house is owned by %s - To leave, use the checkpoint or type {58D3F7}/exithouse{FFFFFF}.", houseStuff[houseid][house_owner]);
			SendClientMessage(playerid, COLOR_WHITE, enterString);
		}
	}
}

forward intoHouse(playerid);
public intoHouse(playerid)
{
	for(new houseid; houseid < MAX_SCRIPT_HOUSES; houseid++)
	{
		if(IsPlayerInDynamicCP(playerid, houseECP[houseid]))
		{
			if (houseStuff[houseid][house_bought])
			{
				if(playerData[playerid][playerJailTime] <= 0)
				{
					if(!IsPlayerInAnyVehicle(playerid))
					{
						if(!playerData[playerid][playerIsCuffed])
						{
							if(!playerData[playerid][playerIsTied])
							{
								if(!playerData[playerid][playerIsTazed])
								{
									if(!strcmp(houseStuff[houseid][house_password], "none", true) || !strcmp(houseStuff[houseid][house_owner], playerData[playerid][playerNamee], true) || playerData[playerid][breakinRenter] == houseStuff[houseid][house_id]) // No password required
									{
										new tickCountResult = GetTickCount(), reducedValue = tickCountResult - playerData[playerid][playerCheckpointTime];

										if(reducedValue > 3000)
										{
											//
											// Set position
											SetPlayerPos(playerid, houseStuff[houseid][interiorX], houseStuff[houseid][interiorY], houseStuff[houseid][interiorZ]);
											SetPlayerInterior(playerid, houseStuff[houseid][interiorID]);
											SetPlayerVirtualWorld(playerid, 150 + houseStuff[houseid][house_id]);
											SetPlayerFacingAngle(playerid, houseStuff[houseid][interiorA]);

											//
											// Set data
											playerData[playerid][playerInsideHouse] = houseid;
											playerData[playerid][playerCheckpointTime] = GetTickCount();

											if(!strcmp(houseStuff[houseid][house_owner], playerData[playerid][playerNamee], true))
											{
												SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}Welcome home! Type /housemenu to configure your property. To leave, use the checkpoint.");
											}
											else
											{
												new enterString[200];
												format(enterString, sizeof(enterString), "{FFDC2E}[HOUSE] {FFFFFF}This house is owned by %s - To leave, use the checkpoint.", houseStuff[houseid][house_owner]);
												SendClientMessage(playerid, COLOR_WHITE, enterString);
											}
										}
									}
									else // Password required
									{
										playerData[playerid][playerHousePass] = houseid;
										ShowPlayerDialog(playerid, DIALOG_ENTER_PASSWORD, DIALOG_STYLE_INPUT, "House Password", "{FE642E}This house is locked.\n{FFFFFF}Enter the password below to enter this property.", "Enter", "Cancel");
									}

									break;
								}
							}
						}
					}
				}
			}
			else
			{
				break;
			}
		}
	}

	return 1;
}

forward breakinTime(playerid);
public breakinTime(playerid)
{
	if(IsPlayerInDynamicCP(playerid, playerData[playerid][breakinCPID]))
	{
		new complete = 0;
		switch(playerData[playerid][breakinProgress])
		{
			case 1:
			{
				SetProgressBarValue(playerData[playerid][breakin], 10.0);
			}

			case 2:
			{
				SetProgressBarValue(playerData[playerid][breakin], 25.0);
			}

			case 3:
			{
				SetProgressBarValue(playerData[playerid][breakin], 35.0);
			}

			case 4:
			{
				SetProgressBarValue(playerData[playerid][breakin], 50.0);
			}

			case 5:
			{
				SetProgressBarValue(playerData[playerid][breakin], 60.0);
			}

			case 6:
			{
				SetProgressBarValue(playerData[playerid][breakin], 70.0);
			}

			case 7:
			{
				SetProgressBarValue(playerData[playerid][breakin], 80.0);
			}

			case 8:
			{
				SetProgressBarValue(playerData[playerid][breakin], 90.0);
			}

			case 9:
			{
				SetProgressBarValue(playerData[playerid][breakin], 100.0);
			}

			case 10:
			{
				KillTimer(playerData[playerid][breakinTimer]);
				DestroyProgressBar(playerData[playerid][breakin]);
				complete = 1;

				PlayerTextDrawHide(playerid, playerData[playerid][BaE][0]);
				PlayerTextDrawHide(playerid, playerData[playerid][BaE][1]);
				PlayerTextDrawHide(playerid, playerData[playerid][BaE][2]);
				PlayerTextDrawHide(playerid, playerData[playerid][BaE][3]);
				PlayerTextDrawHide(playerid, playerData[playerid][BaE][4]);

				new
					houseQuery[200]
				;

				format(houseQuery, sizeof(houseQuery), "SELECT * FROM `house_data` WHERE `house_id` = '%i' LIMIT 1", playerData[playerid][breakinID]);

				new DBResult:qresult, count = 0;
				qresult = db_query(DB: HOUSEDB, houseQuery);
				count = db_num_rows(qresult);

				if (count == 0)
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Couldn't complete action.");
				}
				else
				{
					new dbID, value[48];
					db_get_field_assoc(qresult, "house_id", value, 48);
					dbID = strval(value);

					for(new i = 0; i < MAX_SCRIPT_HOUSES; i++)
					{
						if(houseStuff[i][house_id] == dbID)
						{
							new
								breakinChance,
								alarmChance,
								zapperChance
							;

							if (houseStuff[i][houseLock] == 1) // Secure lock, higher fail chance
							{
								breakinChance = random(5);
							}
							else
							{
								breakinChance = random(3);
							}

							if (playerData[playerid][playerClass] == CLASS_CIVILIAN || playerData[playerid][playerClass] == CLASS_MEDIC)
							{
								givePlayerWanted(playerid, 12);
							}

							switch(breakinChance)
							{
								case 0, 1: // Success
								{
									SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You broke in successfully.");

									playerData[playerid][breakinRenter] = playerData[playerid][breakinID];
									intoHouse(playerid);
								}

								case 2 .. 4: // Failure
								{
									SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You failed to break in.");
								}
							}

							if (houseStuff[i][houseLock] == 2) // Zapper Lock
							{
								zapperChance = random(2);

								switch (zapperChance)
								{
									case 0, 1:
									{
										TogglePlayerControllable(playerid, 0);

										ClearAnimations(playerid);
										ApplyAnimation(playerid, "PED", "FLOOR_hit_f", 4.0, 1, 0, 0, 0, 0);

										playerData[playerid][unfreezeTimer] = SetTimerEx("Unfreeze", 3000, false, "i", playerid);
										playerData[playerid][playerIsTazed] = true;

										new Float:resetHealth;
										GetPlayerHealth(playerid, resetHealth);
										SetPlayerHealth(playerid, resetHealth - 25);

										SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[ZAPPED] {FFFFFF}You got caught by the Zapper lock system.");
									}
								}
							}

							if (houseStuff[i][houseAlarm])
							{
								alarmChance = random(3);

								switch (alarmChance)
								{
									case 0, 1: // Set alarm off
									{
										new alarmMessage[300];
										format(alarmMessage, sizeof(alarmMessage), "{FFDC2E}[BREAK-IN] {FFFFFF}%s(%i) broke into %s's house and set off the alarm.", playerData[playerid][playerNamee], playerid, houseStuff[i][house_owner]);
										SendClientMessageToAll(COLOR_WHITE, alarmMessage);
									}
								}
							}

							playerData[playerid][reBreakinTimer] = SetTimerEx("reBreakin", 60000, false, "i", playerid);
							playerData[playerid][canBreakIn] = false;

							break;
						}
					}
				}
			}
		}

		playerData[playerid][breakinProgress]++;

		if (!complete)
		{
			UpdateProgressBar(playerData[playerid][breakin], playerid);
		}
	}
	else
	{
		KillTimer(playerData[playerid][breakinTimer]);
		DestroyProgressBar(playerData[playerid][breakin]);

		PlayerTextDrawHide(playerid, playerData[playerid][BaE][0]);
		PlayerTextDrawHide(playerid, playerData[playerid][BaE][1]);
		PlayerTextDrawHide(playerid, playerData[playerid][BaE][2]);
		PlayerTextDrawHide(playerid, playerData[playerid][BaE][3]);
		PlayerTextDrawHide(playerid, playerData[playerid][BaE][4]);
	}
}

forward houseBreakin(playerid);
public houseBreakin(playerid)
{
	for(new houseid; houseid < MAX_SCRIPT_HOUSES; houseid++)
	{
		if(IsPlayerInDynamicCP(playerid, houseECP[houseid]))
		{
			if (houseStuff[houseid][house_bought])
			{
				if(playerData[playerid][playerJailTime] <= 0)
				{
					if(!IsPlayerInAnyVehicle(playerid))
					{
						if(!playerData[playerid][playerIsCuffed])
						{
							if(!playerData[playerid][playerIsTied])
							{
								if(!playerData[playerid][playerIsTazed])
								{
									if(!strcmp(houseStuff[houseid][house_password], "none", true) || !strcmp(houseStuff[houseid][house_owner], playerData[playerid][playerNamee], true) || playerData[playerid][breakinRenter] == houseStuff[houseid][house_id]) // No password required
									{
										intoHouse(playerid);
									}
									else
									{
										// can break in
										PlayerTextDrawShow(playerid, playerData[playerid][BaE][0]);
										PlayerTextDrawShow(playerid, playerData[playerid][BaE][1]);
										PlayerTextDrawShow(playerid, playerData[playerid][BaE][2]);
										PlayerTextDrawShow(playerid, playerData[playerid][BaE][3]);
										PlayerTextDrawShow(playerid, playerData[playerid][BaE][4]);

										new formatText[100];

										if (playerData[playerid][playerClass] == CLASS_CIVILIAN || playerData[playerid][playerClass] == CLASS_MEDIC)
										{
											format(formatText, sizeof(formatText), "~r~Breaking ~w~and ~r~Entering");
											PlayerTextDrawSetString(playerid, playerData[playerid][BaE][0], formatText);

											playerData[playerid][breakin] = CreateProgressBar(248.00, 209.00, 141.50, 13.20, -30527745, 100.0);
										}
										else
										{
											format(formatText, sizeof(formatText), "~b~Breaking ~w~and ~b~Entering");
											PlayerTextDrawSetString(playerid, playerData[playerid][BaE][0], formatText);

											playerData[playerid][breakin] = CreateProgressBar(248.00, 209.00, 141.50, 13.20, 24436735, 100.0);
										}

										ShowProgressBarForPlayer(playerid, playerData[playerid][breakin]);

										playerData[playerid][breakinProgress] = 1;
										playerData[playerid][breakinID] = houseStuff[houseid][house_id];
										playerData[playerid][breakinCPID] = houseECP[houseid];
										playerData[playerid][breakinTimer] = SetTimerEx("breakinTime", 800, true, "i", playerid);
									}

									break;
								}
							}
						}
					}
				}
			}
			else
			{
				break;
			}
		}
	}

	return 1;
}

forward leaveHouse(playerid, houseid);
public leaveHouse(playerid, houseid)
{
	if (playerData[playerid][playerInsideHouse] != -1)
	{
		if(IsPlayerInDynamicCP(playerid, houseECP2[houseid]))
		{
			new tickCountResult = GetTickCount(), reducedValue = tickCountResult - playerData[playerid][playerCheckpointTime];

			if(reducedValue > 3000)
			{
				//
				// Set position
				SetPlayerPos(playerid, houseStuff[houseid][houseX], houseStuff[houseid][houseY], houseStuff[houseid][houseZ]);
				SetPlayerInterior(playerid, 0);
				SetPlayerVirtualWorld(playerid, 0);

				//
				// Set data
				playerData[playerid][playerInsideHouse] = -1;
				playerData[playerid][playerCheckpointTime] = GetTickCount();
			}
		}
	}
}

forward leaveHouseEx(playerid, houseid);
public leaveHouseEx(playerid, houseid)
{
	if (playerData[playerid][playerInsideHouse] != -1)
	{
		//
		// Set position
		SetPlayerPos(playerid, houseStuff[houseid][houseX], houseStuff[houseid][houseY], houseStuff[houseid][houseZ]);
		SetPlayerInterior(playerid, 0);
		SetPlayerVirtualWorld(playerid, 0);

		//
		// Set data
		playerData[playerid][playerInsideHouse] = -1;
		playerData[playerid][playerCheckpointTime] = GetTickCount();
	}
}

forward SpawnInHouse(playerid);
public SpawnInHouse(playerid)
{
	if (playerData[playerid][spawnHouse] != -1)
	{
		new
			houseQuery[200]
		;

		format(houseQuery, sizeof(houseQuery), "SELECT * FROM `house_data` WHERE `house_id` = '%i' LIMIT 1", playerData[playerid][spawnHouse]);

		new DBResult:qresult, count = 0;
		qresult = db_query(DB: HOUSEDB, houseQuery);
		count = db_num_rows(qresult);

		if (count == 0)
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Couldn't spawn into house (Invalid ID)");
			playerData[playerid][spawnHouse] = -1;
		}
		else
		{
			new dbID, value[48];
			db_get_field_assoc(qresult, "house_id", value, 48);
			dbID = strval(value);

			for(new i = 0; i < MAX_SCRIPT_HOUSES; i++)
			{
				if(houseStuff[i][house_id] == dbID)
				{
					if(!strcmp(houseStuff[i][house_owner], playerData[playerid][playerNamee], true))
					{
						intoHouseEx(playerid, i, 1);
					}
					else
					{
						playerData[playerid][spawnHouse] = -1;
					}

					break;
				}
			}
		}
	}
}

forward locateHouse(playerid);
public locateHouse(playerid)
{
	if (playerData[playerid][houseFindIteration] < 300)
	{
		playerData[playerid][houseFindIteration]++;

		if(IsPlayerInRangeOfPoint(playerid, 7.0, playerData[playerid][playerHouseLocating][0], playerData[playerid][playerHouseLocating][1], playerData[playerid][playerHouseLocating][2]))
		{
			// They found it!
			KillTimer(playerData[playerid][houseTimer]);
			RemovePlayerMapIcon(playerid, MAP_ICON_HOUSE_LOCATE);

			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[HOUSE SEARCH] {FFFFFF}You found the house.");
		}
	}
	else
	{
		// Too many iterations, cancel the find in-case they stopped looking
		KillTimer(playerData[playerid][houseTimer]);
		RemovePlayerMapIcon(playerid, MAP_ICON_HOUSE_LOCATE);
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[HOUSE SEARCH] {FFFFFF}The house waypoint has been removed since you took too long to find it.");
		playerData[playerid][houseFindIteration] = 0;
	}
}

/**********************
| House Commands
**********************/
/*COMMAND:setowner(playerid, params[])
{
        if(playerData[playerid][playerLoggedIn] && IsPlayerConnected(playerid))
       	{
        new
                        houseID,
                        player,
                        houseQuery[200],
                        pQuery[200],
                        newName[48],
                        query[400]
                ;

        if(sscanf(params, "iu", houseID, player))
        {
            SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"setowner <house id> <playerID>\"");
        }
        else
        {
                        format(pQuery, sizeof(pQuery), "SELECT * FROM `house_data` WHERE `house_owner` = '%s'", playerData[playerid][playerNamee]);

                        new DBResult:presult, pcount = 0;
                        presult = db_query(DB: HOUSEDB, pQuery);
                        pcount = db_num_rows(presult);

                        if (pcount != 3)
                        {
                                format(houseQuery, sizeof(houseQuery), "SELECT * FROM `house_data` WHERE `house_id` = '%i' LIMIT 1", houseID);

                                new DBResult:qresult, count = 0;
                                qresult = db_query(DB: HOUSEDB, houseQuery);
                                count = db_num_rows(qresult);

                                if (count == 0)
                                {
                                        SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That house ID doesn't exist.");
                                }
                                else
                                {
                                        // Find the unique ID for house info
                                        new dbID, value[48];
                                        db_get_field_assoc(qresult, "house_id", value, 48); // House UID
                                        dbID = strval(value);

                                        for(new i = 0; i < MAX_SCRIPT_HOUSES; i++)
                                        {
                                                if(houseStuff[i][house_id] == dbID)
                                                {
                                                        if (houseStuff[i][house_bought] != 1)
                                                        {
                                                                        format(newName, sizeof(newName), "%s", playerData[playerid][playerNamee]);
                                                                        format(query, sizeof(query), "UPDATE `house_data` SET `house_bought` = '1', `house_owner` = '%s' WHERE `house_id` = '%i'", playerData[playerid][playerNamee], houseID);
                                                                        db_query(DB: HOUSEDB, query);

                                                                        houseStuff[i][house_owner] = newName;

                                                                        new purchaseMsg[200];
                                                                        format(purchaseMsg, sizeof(purchaseMsg), "{FFDC2E}[HOUSE] {FFFFFF}The owner of this house has been succesfully set.");
                                                                        SendClientMessage(playerid, COLOR_WHITE, purchaseMsg);

                                                                        playerData[playerid][houseCount] = playerData[playerid][houseCount] + 1;

                                                                        reloadHouses();

                                                }
												else
                                                {
                                                        SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This house is already owned by another player.");
                                                }

                                                        break;
                                                }
                                        }
                                }
                        }
                        else
                        {
                                SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This player cannot have more than 3 properties. Please sell a property first!");
                        }
                }
        }

        return 1;
}*/

COMMAND:reloadhouses(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			reloadHouses();

			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Houses reloaded.");
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not have permission to use that command.");
		}
	}

	return 1;
}

COMMAND:houseinfo(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			new
				houseid,
				houseQuery[200]
			;

			if(sscanf(params, "i", houseid))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"houseinfo <house id>\"");
			}
			else
			{
				format(houseQuery, sizeof(houseQuery), "SELECT * FROM `house_data` WHERE `house_id` = '%i' LIMIT 1", houseid);

				new DBResult:qresult, count = 0;
				qresult = db_query(DB: HOUSEDB, houseQuery);
				count = db_num_rows(qresult);

				if (count == 0)
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That house ID doesn't exist.");
				}
				else
				{
					// Find the unique ID for house info
					new dbID, value[48];
					db_get_field_assoc(qresult, "house_id", value, 48); // House UID
					dbID = strval(value);

					for(new i = 0; i < MAX_SCRIPT_HOUSES; i++)
					{
						if(houseStuff[i][house_id] == dbID)
						{
							new hlist[600], rhid = i;
							format(hlist, sizeof(hlist), "%s\nHouse DB Key: %i", hlist, houseStuff[rhid][house_id]);
							format(hlist, sizeof(hlist), "%s\nHouse Owner: %s", hlist, houseStuff[rhid][house_owner]);
							format(hlist, sizeof(hlist), "%s\nHouse Price: %i", hlist, houseStuff[rhid][house_price]);
							format(hlist, sizeof(hlist), "%s\nHouse Password: %s", hlist, houseStuff[rhid][house_password]);
							format(hlist, sizeof(hlist), "%s\nHouse Title: %s", hlist, houseStuff[rhid][house_title]);
							format(hlist, sizeof(hlist), "%s\nHouse Int_X: %f", hlist, houseStuff[rhid][interiorX]);
							format(hlist, sizeof(hlist), "%s\nHouse Int_Y: %f", hlist, houseStuff[rhid][interiorY]);
							format(hlist, sizeof(hlist), "%s\nHouse Int_Z: %f", hlist, houseStuff[rhid][interiorZ]);
							format(hlist, sizeof(hlist), "%s\nHouse Interior ID: %i", hlist, houseStuff[rhid][interiorID]);
							format(hlist, sizeof(hlist), "%s\nHouse Lock Type: %i", hlist, houseStuff[rhid][houseLock]);
							format(hlist, sizeof(hlist), "%s\nHouse Alarmed: %i", hlist, houseStuff[rhid][houseAlarm]);

							ShowPlayerDialog(playerid, 969, DIALOG_STYLE_LIST, "House Information", hlist, "OK", "Close");

							break;
						}
					}
				}
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not have permission to use that command.");
		}
	}

	return 1;
}

COMMAND:gotohouse(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			new
				houseid,
				houseQuery[200]
			;

			if(sscanf(params, "i", houseid))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"gotohouse <house id>\"");
			}
			else
			{
				format(houseQuery, sizeof(houseQuery), "SELECT * FROM `house_data` WHERE `house_id` = '%i' LIMIT 1", houseid);

				new DBResult:qresult, count = 0;
				qresult = db_query(DB: HOUSEDB, houseQuery);
				count = db_num_rows(qresult);

				if (count == 0)
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That house ID doesn't exist.");
				}
				else
				{
					// Find the unique ID for house info
					new dbID, value[48];
					db_get_field_assoc(qresult, "house_id", value, 48); // House UID
					dbID = strval(value);

					for(new i = 0; i < MAX_SCRIPT_HOUSES; i++)
					{
						if(houseStuff[i][house_id] == dbID)
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

							break;
						}
					}
				}
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not have permission to use that command.");
		}
	}

	return 1;
}

COMMAND:playerhouses(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 6)
		{
			new
				theirID
			;

			if(sscanf(params, "u", theirID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"playerhouses <player id>\"");
			}
			else
			{
				if (IsPlayerConnected(theirID))
				{
					new
						dialogList[256],
						DBResult:locatingResult,
						locatingQuery[128],
						resultCount,
						bool:firstOne
					;

					playerData[playerid][playerGetStats] = theirID;

					format(locatingQuery, sizeof(locatingQuery), "SELECT * FROM `house_data` WHERE `house_owner` = '%s'", playerData[theirID][playerNamee]);
					locatingResult = db_query(DB: HOUSEDB, locatingQuery);
					resultCount = db_num_rows(locatingResult);

					if(resultCount > 0)
					{
						do
						{
							new houseTitle[48], houseID, temporaryString[54];

							db_get_field_assoc(locatingResult, "house_id", temporaryString, 3);
							houseID = strval(temporaryString);

							db_get_field_assoc(locatingResult, "house_title", temporaryString, 48); // House Title
							format(houseTitle, 48, temporaryString);

							if(!strcmp(houseTitle, "none", true))
							{
								houseTitle = "No Title";
							}

							if(firstOne == true)
							{
								format(dialogList, sizeof(dialogList), "%s %s (ID: %i)\n", dialogList, houseTitle, houseID);
								firstOne = false;
							}
							else
							{
								format(dialogList, sizeof(dialogList), "%s %s (ID: %i)\n", dialogList, houseTitle, houseID);
							}

						} while(db_next_row(locatingResult));

						new titleDialog[100];
						format(titleDialog, sizeof(titleDialog), "%s's Houses", playerData[theirID][playerNamee]);

						ShowPlayerDialog(playerid, DIALOG_ADMINHOUSELIST, DIALOG_STYLE_LIST, titleDialog, dialogList, "Select", "Cancel");
					}
				}
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not have permission to use that command.");
		}
	}

	return 1;
}

COMMAND:deletehouse(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			new
				houseid,
				houseQuery[200],
				deleteQuery[200]
			;

			if(sscanf(params, "i", houseid))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"housedelete <house id>\"");
			}
			else
			{
				format(houseQuery, sizeof(houseQuery), "SELECT * FROM `house_data` WHERE `house_id` = '%i' LIMIT 1", houseid);

				new DBResult:qresult, count = 0;
				qresult = db_query(DB: HOUSEDB, houseQuery);
				count = db_num_rows(qresult);

				if (count == 0)
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That house ID doesn't exist.");
				}
				else
				{
					// Find the unique ID for house info
					new dbID, value[48];
					db_get_field_assoc(qresult, "house_id", value, 48); // House UID
					dbID = strval(value);

					for(new i = 0; i < MAX_SCRIPT_HOUSES; i++)
					{
						if(houseStuff[i][house_id] == dbID)
						{
							format(deleteQuery, sizeof(deleteQuery), "DELETE FROM `house_data` WHERE `house_id` = '%i'", houseid);
							db_query(DB: HOUSEDB, deleteQuery);

							reloadHouses();

							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}House deleted.");

							break;
						}
					}
				}
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not have permission to use that command.");
		}
	}

	return 1;
}

COMMAND:createhouse(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			new
				newPrice,
				query[400],
				Float:x,
				Float:y,
				Float:z,
				Float:intX,
				Float:intY,
				Float:intZ,
				Float:intA,
				intID
			;

			GetPlayerPos(playerid, x, y, z);

			if(sscanf(params, "i", newPrice))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"housecreate <house price>\"");
			}
			else
			{
				intX = 260.6848;
				intY = 1238.0388;
				intZ = 1084.2578;
				intA = 354.7931;
				intID = 9;

				format(query, sizeof(query), "INSERT INTO `house_data` (house_bought, house_price, house_owner, houseX, houseY, houseZ, interiorID, interiorX, interiorY, interiorZ, interiorAngle) VALUES ('0', '%i', 'CNRSF', '%f', '%f', '%f', '%i', '%f', '%f', '%f', '%f')", newPrice, x, y, z, intID, intX, intY, intZ, intA);
				db_query(DB: HOUSEDB, query);

				reloadHouses();
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not have permission to use that command.");
		}
	}

	return 1;
}

COMMAND:buyhouse(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
        new
			houseID,
			houseQuery[200],
			pQuery[200],
			newName[48],
			query[400]
		;

        if(sscanf(params, "i", houseID))
        {
            SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"buyhouse <house id>\"");
        }
        else
        {
			format(pQuery, sizeof(pQuery), "SELECT * FROM `house_data` WHERE `house_owner` = '%s'", playerData[playerid][playerNamee]);

			new DBResult:presult, pcount = 0, maxhouse = 0;
			presult = db_query(DB: HOUSEDB, pQuery);
			pcount = db_num_rows(presult);

        	switch(playerData[playerid][playerVIPLevel])
			{
			    case 4:
			    {
			        maxhouse = 10;
			    }
			    case 3:
			    {
			        maxhouse = 6; //  Right?ye
			    }
			    case 2:
			    {
			        maxhouse = 5;
			    }
			    case 0 .. 1:
			    {
			        maxhouse = 3;
			    }
			    default:
			    {
			        maxhouse = 3;
			    }
			}
			if (pcount <= maxhouse)
			{
				format(houseQuery, sizeof(houseQuery), "SELECT * FROM `house_data` WHERE `house_id` = '%i' LIMIT 1", houseID);

				new DBResult:qresult, count = 0;
				qresult = db_query(DB: HOUSEDB, houseQuery);
				count = db_num_rows(qresult);
				if (count == 0)
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That house ID doesn't exist.");
				}
				else
				{
					// Find the unique ID for house info
					new dbID, value[48];
					db_get_field_assoc(qresult, "house_id", value, 48); // House UID
					dbID = strval(value);

					for(new i = 0; i < MAX_SCRIPT_HOUSES; i++)
					{
						if(houseStuff[i][house_id] == dbID)
						{
							if (houseStuff[i][house_bought] != 1)
							{
								if (playerData[playerid][playerMoney] >= houseStuff[i][house_price])
								{
									format(newName, sizeof(newName), "%s", playerData[playerid][playerNamee]);
									format(query, sizeof(query), "UPDATE `house_data` SET `house_bought` = '1', `house_owner` = '%s' WHERE `house_id` = '%i'", playerData[playerid][playerNamee], houseID);
									db_query(DB: HOUSEDB, query);

									houseStuff[i][house_owner] = newName;

									new price = houseStuff[i][house_price];
									playerSetMoney(playerid, playerData[playerid][playerMoney] - price);

									new purchaseMsg[200];
									format(purchaseMsg, sizeof(purchaseMsg), "{FFDC2E}[HOUSE] {FFFFFF}House successfully purchased for {58D3F7}$%s", FormatNumber(houseStuff[i][house_price]));
									SendClientMessage(playerid, COLOR_WHITE, purchaseMsg);

									playerData[playerid][houseCount] = playerData[playerid][houseCount] + 1;

									reloadHouses();

									return 1;
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You don't have enough cash to purchase this property.");
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This house is already owned by another player.");
							}

							break;
						}
					}
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot purchase more than limited properties. Please sell a property first!");
			}
		}
	}

	return 1;
}

COMMAND:housecommands(playerid, params[])
{
    if (playerData[playerid][playerLoggedIn])
    {
			new string[1400];
            format(string, sizeof(string), "%s{98B0CD}Player Commands{FFFFFF}\n/buyhouse /housemenu /myhouses\n\n", string);
			format(string, sizeof(string), "%s{98B0CD}}Admin Commands{FFFFFF}\n/createhouse /deletehouse /playerhouses /houseinfo\n\n", string);

			ShowPlayerDialog(playerid, 200, DIALOG_STYLE_MSGBOX, "House Commands", string, "OK", "");
		}
    else
    {
        SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be logged in to use commands.");
    }
    return 1;
}

COMMAND:housemenu(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerInsideHouse] != -1)
		{
			new
				houseID = playerData[playerid][playerInsideHouse]
			;

			if(!strcmp(houseStuff[houseID][house_owner], playerData[playerid][playerNamee], true))
			{
				ShowPlayerDialog(playerid, DIALOG_HOUSEMENU, DIALOG_STYLE_LIST, "House Menu", "Upgrade Interior \nSet House Title \nCreate House Password \nSpawn Inside House \nHouse Upgrades \nSell House", "Select", "Cancel");
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not own this house.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be inside a house to use this command.");
		}
	}

	return 1;
}

COMMAND:exithouse(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (playerData[playerid][playerInsideHouse] != -1)
		{
			new
				houseid
			;

			houseid = playerData[playerid][playerInsideHouse];

			//
			// Set position
			SetPlayerPos(playerid, houseStuff[houseid][houseX], houseStuff[houseid][houseY], houseStuff[houseid][houseZ]);
			SetPlayerInterior(playerid, 0);
			SetPlayerVirtualWorld(playerid, 0);

			//
			// Set data
			playerData[playerid][playerInsideHouse] = -1;
			playerData[playerid][playerCheckpointTime] = GetTickCount();
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be inside a house to use this command.");
		}
	}

	return 1;
}

COMMAND:removespawn(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][spawnHouse] != -1)
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You will no longer spawn inside your house.");
			playerData[playerid][spawnHouse] = -1;
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not have a house spawn set.");
		}
	}

	return 1;
}

COMMAND:myhouses(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		new
			dialogList[256],
			DBResult:locatingResult,
			locatingQuery[128],
			resultCount,
			bool:firstOne
		;

		format(locatingQuery, sizeof(locatingQuery), "SELECT * FROM `house_data` WHERE `house_owner` = '%s'", playerData[playerid][playerNamee]);
		locatingResult = db_query(DB: HOUSEDB, locatingQuery);
		resultCount = db_num_rows(locatingResult);

		if(resultCount > 0)
		{
			do
			{
				new houseTitle[48], houseID, temporaryString[54];

				db_get_field_assoc(locatingResult, "house_id", temporaryString, 3);
				houseID = strval(temporaryString);

				db_get_field_assoc(locatingResult, "house_title", temporaryString, 48); // House Title
				format(houseTitle, 48, temporaryString);

				if(!strcmp(houseTitle, "none", true))
				{
					houseTitle = "No Title";
				}

				if(firstOne == true)
				{
					format(dialogList, sizeof(dialogList), "%s %s (ID: %i)\n", dialogList, houseTitle, houseID);
					firstOne = false;
				}
				else
				{
					format(dialogList, sizeof(dialogList), "%s %s (ID: %i)\n", dialogList, houseTitle, houseID);
				}

			} while(db_next_row(locatingResult));

			ShowPlayerDialog(playerid, DIALOG_HOUSELIST, DIALOG_STYLE_LIST, "My Houses", dialogList, "Select", "Cancel");
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You currently don't own any houses.");
		}

		db_free_result(locatingResult);
	}

	return 1;
}

COMMAND:housesforsale(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		
		new 
			dialogList[1000],
			bool:found
		;
		
		found = false;
		
		for(new i = 0; i < MAX_SCRIPT_HOUSES; i++)
		{	
			if(!strcmp(houseStuff[i][house_owner], "CNRSF", true) && houseStuff[i][house_id] > 0 && houseStuff[i][house_price] > 500000)
			{
				format(dialogList, sizeof(dialogList), "{FFFFFF}House ID: %i {D87C3E}$%s", houseStuff[i][house_id], FormatNumber(houseStuff[i][house_price]));
				AddDListItem(playerid, dialogList, DIALOG_HOUSESFORSALE, i);
				
				if (!found) found = true;
			}
			else
			{
				continue;
			}
		}
		
		if (found)
		{
			ShowPlayerDList(playerid, DIALOG_HOUSESFORSALE, "Houses For Sale", "Select", "Close");
		}
	}
	
	return 1;
}

COMMAND:cancelsearch(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (playerData[playerid][houseFindIteration] > 0)
		{
			RemovePlayerMapIcon(playerid, MAP_ICON_HOUSE_LOCATE);
			KillTimer(playerData[playerid][houseTimer]);
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cancelled the search.");
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You're not searching for a house, use /housesforsale first.");
		}
	}

	return 1;
}
