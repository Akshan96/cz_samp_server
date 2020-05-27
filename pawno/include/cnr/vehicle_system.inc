#define MAX_SAVED_VEHICLES 		 500
#define SOUND_BUY_CAR_RESPRAY	 1134

enum v_Info
{
    vOwner,
    vOwnerName[128],
    vModelID,
    Float:vX,
    Float:vY,
    Float:vZ,
    Float:vAngle,
    Float:vHealth,
    vColor1,
    vColor2,
    vPaintjob,
    vNumberPlate[10],
    bool:vLocked,
    vehicleID,
	vOwned,
	mod[17],
//	neon[3]
}

new VehicleInfo[MAX_SAVED_VEHICLES][v_Info], DB:VEHICLESDB, tuned;

forward Load_Vehicles();
public Load_Vehicles()
{
	print("Loading Vehicles");

	new DBResult:qresult, count = 0, field[328], debugMsg[200];
	if(!db_query(DB: VEHICLESDB, "SELECT * FROM `vehicles`"))
	{
		print("VEHICLE SYSTEM :: No vehicles were found in \"newvehicles\" :: 0 Loaded");
	}
	else
	{
		qresult = db_query(DB: VEHICLESDB, "SELECT * FROM `vehicles`");
		count = db_num_rows(qresult);

		new id, modelid, owner, vlocked, Float:x, Float:y, Float:z, Float:angle, Float:health, color1, color2, paintjob;

		for(new i = 0; i < count; i++)
		{
			if(count <= MAX_SAVED_VEHICLES)
			{
				db_get_field_assoc(qresult, "id", field, 48);
				id = strval(field);

				db_get_field_assoc(qresult, "owner", field, 48);
				owner = strval(field);

				db_get_field_assoc(qresult, "modelid", field, 48);
				modelid = strval(field);

				db_get_field_assoc(qresult, "locked", field, 48);
				vlocked = strval(field);

				db_get_field_assoc(qresult, "x", field, 48);
				x = floatstr(field);

				db_get_field_assoc(qresult, "y", field, 48);
				y = floatstr(field);

				db_get_field_assoc(qresult, "z", field, 48);
				z = floatstr(field);

				db_get_field_assoc(qresult, "angle", field, 48);
				angle = floatstr(field);

				db_get_field_assoc(qresult, "health", field, 48);
				health = floatstr(field);

				db_get_field_assoc(qresult, "color1", field, 48);
				color1 = strval(field);

				db_get_field_assoc(qresult, "color2", field, 48);
				color2 = strval(field);

				db_get_field_assoc(qresult, "mod1", field, 48);
				VehicleInfo[id][mod][0] = strval(field);

				db_get_field_assoc(qresult, "mod2", field, 48);
				VehicleInfo[id][mod][1] = strval(field);

				db_get_field_assoc(qresult, "mod3", field, 48);
				VehicleInfo[id][mod][2] = strval(field);

				db_get_field_assoc(qresult, "mod4", field, 48);
				VehicleInfo[id][mod][3] = strval(field);

				db_get_field_assoc(qresult, "mod5", field, 48);
				VehicleInfo[id][mod][4] = strval(field);

				db_get_field_assoc(qresult, "mod6", field, 48);
				VehicleInfo[id][mod][5] = strval(field);

				db_get_field_assoc(qresult, "mod7", field, 48);
				VehicleInfo[id][mod][6] = strval(field);

				db_get_field_assoc(qresult, "mod8", field, 48);
				VehicleInfo[id][mod][7] = strval(field);

				db_get_field_assoc(qresult, "mod9", field, 48);
				VehicleInfo[id][mod][8] = strval(field);

				db_get_field_assoc(qresult, "mod10", field, 48);
				VehicleInfo[id][mod][9] = strval(field);

				db_get_field_assoc(qresult, "mod11", field, 48);
				VehicleInfo[id][mod][10] = strval(field);

				db_get_field_assoc(qresult, "mod12", field, 48);
				VehicleInfo[id][mod][11] = strval(field);

				db_get_field_assoc(qresult, "mod13", field, 48);
				VehicleInfo[id][mod][12] = strval(field);

				db_get_field_assoc(qresult, "mod14", field, 48);
				VehicleInfo[id][mod][13] = strval(field);

				db_get_field_assoc(qresult, "mod15", field, 48);
				VehicleInfo[id][mod][14] = strval(field);

				db_get_field_assoc(qresult, "mod16", field, 48);
				VehicleInfo[id][mod][15] = strval(field);

				db_get_field_assoc(qresult, "mod17", field, 48);
				VehicleInfo[id][mod][16] = strval(field);

				db_get_field_assoc(qresult, "paintjob", field, 48);
				paintjob = strval(field);

				// - Finally, save the data to the array.
				VehicleInfo[id][vModelID] = modelid;
				VehicleInfo[id][vOwner] = owner;
				VehicleInfo[id][vLocked] = !!vlocked;
				VehicleInfo[id][vX] = x;
				VehicleInfo[id][vY] = y;
				VehicleInfo[id][vZ] = z;
				VehicleInfo[id][vAngle] = angle;
				VehicleInfo[id][vColor1] = color1;
				VehicleInfo[id][vColor2] = color2;
				VehicleInfo[id][vPaintjob] = paintjob;
				VehicleInfo[id][vHealth] = health;
				VehicleInfo[id][vOwned] = true;

				format(debugMsg, sizeof(debugMsg), "(%i) Loaded! Owner: %i", id, VehicleInfo[id][vOwner]);
				print(debugMsg);

				db_next_row(qresult);
			}
		}
	}
}

public OnVehicleMod(playerid, vehicleid, componentid)
{
    new vehicleide = GetVehicleModel(vehicleid);
    new modok = islegalcarmod(vehicleide, componentid);

    if (!modok) {
        return 0;
    }
	else
	{
		SaveComponent(playerid, vehicleid, componentid);
	}

    return 1;
}

public OnVehiclePaintjob(playerid, vehicleid, paintjobid)
{
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		new query[400];

		for(new i; i < MAX_SAVED_VEHICLES; i++)
		{
			if (vehicleid != VehicleInfo[i][vehicleID]) continue;

			if (VehicleInfo[i][vOwner] == playerData[playerid][actualID])
			{
				format(query, sizeof(query), "UPDATE `vehicles` SET `paintjob` = '%i' WHERE `id` = '%i'", paintjobid, i);
				VehicleInfo[i][vPaintjob] = paintjobid;
				db_query(DB: VEHICLESDB, query);
			}
		}
	}
}

public OnVehicleRespray(playerid, vehicleid, color1, color2)
{
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		new query[400];

		for(new i; i < MAX_SAVED_VEHICLES; i++)
		{
			if (vehicleid != VehicleInfo[i][vehicleID]) continue;

			if (VehicleInfo[i][vOwner] == playerData[playerid][actualID])
			{
				format(query, sizeof(query), "UPDATE `vehicles` SET `color1` = '%i', `color2` = '%i' WHERE `id` = '%i'", color1, color2, i);
				VehicleInfo[i][vColor1] = color1;
				VehicleInfo[i][vColor2] = color2;

				db_query(DB: VEHICLESDB, query);
			}
		}
	}
}

forward SaveComponent(playerid, vehicleid, componentid);
public SaveComponent(playerid, vehicleid, componentid)
{
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		new query[400];

		for(new i; i < MAX_SAVED_VEHICLES; i++)
		{
			if (vehicleid != VehicleInfo[i][vehicleID]) continue;

			if (VehicleInfo[i][vOwner] == playerData[playerid][actualID])
			{
				for(new s=0; s<20; s++) {
					if(componentid == spoiler[s][0]) {
						VehicleInfo[i][mod][0] = componentid;
						format(query, sizeof(query), "UPDATE `vehicles` SET `mod1` = '%i' WHERE `id` = '%i'", componentid, i);
					}
				}
				for(new s=0; s<3; s++) {
					if(componentid == nitro[s][0]) {
						VehicleInfo[i][mod][1] = componentid;
						format(query, sizeof(query), "UPDATE `vehicles` SET `mod2` = '%i' WHERE `id` = '%i'", componentid, i);
					}
				}
				for(new s=0; s<23; s++) {
					if(componentid == fbumper[s][0]) {
						VehicleInfo[i][mod][2] = componentid;
						format(query, sizeof(query), "UPDATE `vehicles` SET `mod3` = '%i' WHERE `id` = '%i'", componentid, i);
					}
				}
				for(new s=0; s<22; s++) {
					if(componentid == rbumper[s][0]) {
						VehicleInfo[i][mod][3] = componentid;
						format(query, sizeof(query), "UPDATE `vehicles` SET `mod4` = '%i' WHERE `id` = '%i'", componentid, i);
					}
				}
				for(new s=0; s<28; s++) {
					if(componentid == exhaust[s][0]) {
						VehicleInfo[i][mod][4] = componentid;
						format(query, sizeof(query), "UPDATE `vehicles` SET `mod5` = '%i' WHERE `id` = '%i'", componentid, i);
					}
				}
				for(new s=0; s<2; s++) {
					if(componentid == bventr[s][0]) {
						VehicleInfo[i][mod][5] = componentid;
						format(query, sizeof(query), "UPDATE `vehicles` SET `mod6` = '%i' WHERE `id` = '%i'", componentid, i);
					}
				}
				for(new s=0; s<2; s++) {
					if(componentid == bventl[s][0]) {
						VehicleInfo[i][mod][6] = componentid;
						format(query, sizeof(query), "UPDATE `vehicles` SET `mod7` = '%i' WHERE `id` = '%i'", componentid, i);
					}
				}
				for(new s=0; s<4; s++) {
					if(componentid == bscoop[s][0]) {
						VehicleInfo[i][mod][7] = componentid;
						format(query, sizeof(query), "UPDATE `vehicles` SET `mod8` = '%i' WHERE `id` = '%i'", componentid, i);
					}
				}
				for(new s=0; s<17; s++) {
					if(componentid == rscoop[s][0]) {
						VehicleInfo[i][mod][8] = componentid;
						format(query, sizeof(query), "UPDATE `vehicles` SET `mod9` = '%i' WHERE `id` = '%i'", componentid, i);
					}
				}
				for(new s=0; s<21; s++) {
					if(componentid == lskirt[s][0]) {
						VehicleInfo[i][mod][9] = componentid;
						format(query, sizeof(query), "UPDATE `vehicles` SET `mod10` = '%i' WHERE `id` = '%i'", componentid, i);
					}
				}
				for(new s=0; s<21; s++) {
					if(componentid == rskirt[s][0]) {
						VehicleInfo[i][mod][10] = componentid;
						format(query, sizeof(query), "UPDATE `vehicles` SET `mod11` = '%i' WHERE `id` = '%i'", componentid, i);
					}
				}
				for(new s=0; s<1; s++) {
					if(componentid == hydraulics[s][0]) {
						VehicleInfo[i][mod][11] = componentid;
						format(query, sizeof(query), "UPDATE `vehicles` SET `mod12` = '%i' WHERE `id` = '%i'", componentid, i);
					}
				}
				for(new s=0; s<1; s++) {
					if(componentid == base[s][0]) {
						VehicleInfo[i][mod][12] = componentid;
						format(query, sizeof(query), "UPDATE `vehicles` SET `mod13` = '%i' WHERE `id` = '%i'", componentid, i);
					}
				}
				for(new s=0; s<4; s++) {
					if(componentid == rbbars[s][0]) {
						VehicleInfo[i][mod][13] = componentid;
						format(query, sizeof(query), "UPDATE `vehicles` SET `mod14` = '%i' WHERE `id` = '%i'", componentid, i);
					}
				}
				for(new s=0; s<2; s++) {
					if(componentid == fbbars[s][0]) {
						VehicleInfo[i][mod][14] = componentid;
						format(query, sizeof(query), "UPDATE `vehicles` SET `mod15` = '%i' WHERE `id` = '%i'", componentid, i);
					}
				}
				for(new s=0; s<17; s++) {
					if(componentid == wheels[s][0]) {
						VehicleInfo[i][mod][15] = componentid;
						format(query, sizeof(query), "UPDATE `vehicles` SET `mod16` = '%i' WHERE `id` = '%i'", componentid, i);
					}
				}

				db_query(DB: VEHICLESDB, query);

				return 1;
			}

			break;
		}
	}
	return 0;
}

stock ModVehicle(vehicleid)
{
	for(new i; i < MAX_SAVED_VEHICLES; i++)
	{
		if (vehicleid != VehicleInfo[i][vehicleID]) continue;

		new tuned2 = 0;

		if(VehicleInfo[i][mod][0] != 0) {
			AddVehicleComponent(vehicleid, VehicleInfo[i][mod][0]);
			tuned2 = 1;
		}
		if(VehicleInfo[i][mod][1] != 0) {
			AddVehicleComponent(vehicleid, VehicleInfo[i][mod][1]);
			tuned2 = 1;
		}
		if(VehicleInfo[i][mod][2] != 0) {
			AddVehicleComponent(vehicleid, VehicleInfo[i][mod][2]);
			tuned2 = 1;
		}
		if(VehicleInfo[i][mod][3] != 0) {
			AddVehicleComponent(vehicleid, VehicleInfo[i][mod][3]);
			tuned2 = 1;
		}
		if(VehicleInfo[i][mod][4] != 0) {
			AddVehicleComponent(vehicleid, VehicleInfo[i][mod][4]);
			tuned2 = 1;
		}
		if(VehicleInfo[i][mod][5] != 0) {
			AddVehicleComponent(vehicleid, VehicleInfo[i][mod][5]);
			tuned2 = 1;
		}
		if(VehicleInfo[i][mod][6] != 0) {
			AddVehicleComponent(vehicleid, VehicleInfo[i][mod][6]);
			tuned2 = 1;
		}
		if(VehicleInfo[i][mod][7] != 0) {
			AddVehicleComponent(vehicleid, VehicleInfo[i][mod][7]);
			tuned2 = 1;
		}
		if(VehicleInfo[i][mod][8] != 0) {
			AddVehicleComponent(vehicleid, VehicleInfo[i][mod][8]);
			tuned2 = 1;
		}
		if(VehicleInfo[i][mod][9] != 0) {
			AddVehicleComponent(vehicleid, VehicleInfo[i][mod][9]);
			tuned2 = 1;
		}
		if(VehicleInfo[i][mod][10] != 0) {
			AddVehicleComponent(vehicleid, VehicleInfo[i][mod][10]);
			tuned2 = 1;
		}
		if(VehicleInfo[i][mod][11] != 0) {
			AddVehicleComponent(vehicleid, VehicleInfo[i][mod][11]);
			tuned2 = 1;
		}
		if(VehicleInfo[i][mod][12] != 0) {
			AddVehicleComponent(vehicleid, VehicleInfo[i][mod][12]);
			tuned2 = 1;
		}

		if(tuned2 == 1) {
			tuned++;
		}

		break;
	}
}

public OnVehicleDeath(vehicleid, killerid)
{
	for(new i; i < MAX_SAVED_VEHICLES; i++)
	{
		if (vehicleid != VehicleInfo[i][vehicleID]) continue;

		/*if(IsValidDynamicObject(VehicleInfo[vehicleID][neon][1]))
		{
			DestroyDynamicObject(VehicleInfo[vehicleID][neon][1]);
			DestroyDynamicObject(VehicleInfo[vehicleID][neon][2]);
		}*/
		DestroyVehicle(VehicleInfo[i][vehicleID]);
		OwnedVehicleRespawn(i);

		break;
	}
}

forward OwnedVehicleRespawn(vehicleid);
public OwnedVehicleRespawn(vehicleid)
{
	/*if(IsValidDynamicObject(VehicleInfo[vehicleID][neon][1]))
	{
		DestroyDynamicObject(VehicleInfo[vehicleID][neon][1]);
		DestroyDynamicObject(VehicleInfo[vehicleID][neon][2]);
	}*/
	VehicleInfo[vehicleid][vehicleID] = CreateVehicle(VehicleInfo[vehicleid][vModelID], VehicleInfo[vehicleid][vX], VehicleInfo[vehicleid][vY], VehicleInfo[vehicleid][vZ], VehicleInfo[vehicleid][vAngle], VehicleInfo[vehicleid][vColor1], VehicleInfo[vehicleid][vColor2], 3600);
	ModVehicle(VehicleInfo[vehicleid][vehicleID]);
	ChangeVehiclePaintjob(VehicleInfo[vehicleid][vehicleID], VehicleInfo[vehicleid][vPaintjob]);
}

forward dealershipSpawn(playerid);
public dealershipSpawn(playerid)
{
	new
		idQuery[200],
		value[48],
		DBResult:idresult
	;

	format(idQuery, sizeof(idQuery), "SELECT * FROM `vehicles` WHERE `owner` = '%i' ORDER BY `id` DESC LIMIT 1", playerData[playerid][actualID]);
	idresult = db_query(DB: VEHICLESDB, idQuery);

	db_get_field_assoc(idresult, "id", value, 20);
	new i = strval(value);

	db_free_result(idresult);

	VehicleInfo[i][vehicleID] = CreateVehicle(VehicleInfo[i][vModelID], VehicleInfo[i][vX], VehicleInfo[i][vY], VehicleInfo[i][vZ], VehicleInfo[i][vAngle], VehicleInfo[i][vColor1], VehicleInfo[i][vColor2], 3600);
	print("Spawned");

	//break;

	SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[VEHICLE] {FFFFFF}Your vehicle has been created!");

	//format(msg, sizeof(msg), "{58D3F7}[DEALERSHIP] {FFFFFF}You purchased a %s for {FFDC2E}$%s{FFFFFF}. Park it somewhere sensible.", vehicleNames[dealershipData[d][vehicle_model] - 400], FormatNumber(dealershipData[d][vehicle_price]));
	//SendClientMessage(playerid, COLOR_WHITE, msg);

	ac_PutPlayerInVehicle(playerid, VehicleInfo[i][vehicleID], 0);
	//playerTakeMoney(playerid, dealershipData[d][vehicle_price]);
}

// - Create a new vehicle, assign it to an owner, save all information.
forward Vehicle_Create(modelid, owner, Float:x, Float:y, Float:z, Float:angle, ownerid);
public Vehicle_Create(modelid, owner, Float:x, Float:y, Float:z, Float:angle, ownerid)
{
	new
		query[400],
		color1 = -1,
		color2 = -1
	;

	format(query, sizeof(query), "INSERT INTO `vehicles` (owner, modelid, locked, x, y, z, angle, health, color1, color2) VALUES (%d, %d, %d, %f, %f, %f, %f, %f, %d, %d)", owner, modelid, 0, x, y, z, angle, 1000.0, color1, color2);
	db_query(DB: VEHICLESDB, query);

	Load_Vehicles();
	//Vehicle_SpawnPlayerVehicle(ownerid, owner);
}

COMMAND:removepaintjob(playerid, params[])
{
	if (playerData[playerid][playerLoggedIn])
	{
		if (IsPlayerInAnyVehicle(playerid))
		{
			new
				vid = GetPlayerVehicleID(playerid);

			for(new i; i < MAX_SAVED_VEHICLES; i++)
			{
				if (vid != VehicleInfo[i][vehicleID]) continue;

				if(VehicleInfo[i][vOwner] != playerData[playerid][actualID])
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot remove paintjob another player's vehicle.");
				}
				else
				{
					VehicleInfo[i][vPaintjob] = 3;
					ChangeVehiclePaintjob(VehicleInfo[i][vehicleID], 3);
					PlayerPlaySound(playerid, SOUND_BUY_CAR_RESPRAY, 0.0, 0.0, 10.0);
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Succesfully removed paintjob.");
				}

				break;
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be inside a vehicle to use this command.");
		}
	}

	return 1;
}

/*COMMAND:neon(playerid, params[])
{
	if (playerData[playerid][playerLoggedIn])
	{
		if (IsPlayerInAnyVehicle(playerid))
		{
			new
				vid = GetPlayerVehicleID(playerid)
			;

			for(new i; i < MAX_SAVED_VEHICLES; i++)
			{
				if (vid != VehicleInfo[i][vehicleID]) continue;

				if(VehicleInfo[i][vOwner] != playerData[playerid][actualID])
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You don't own this vehicle.");
				}
				else
				{
					ShowPlayerDialog(playerid, DIALOG_NEON, DIALOG_STYLE_LIST, "Choose your neon colour","Blue\nGreen\nYellow\nWhite\nPink\nTurn off Neon","Select","Close");
				}
				break;
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be inside a vehicle to use this command.");
		}
	}
	return 1;
}*/

COMMAND:vsell(playerid, params[])
{
	if (playerData[playerid][playerLoggedIn])
	{
		if (IsPlayerInAnyVehicle(playerid))
		{
			new
				vid = GetPlayerVehicleID(playerid),
				otherPlayer,
				price
			;

			for(new i; i < MAX_SAVED_VEHICLES; i++)
			{
				if (vid != VehicleInfo[i][vehicleID]) continue;

				if(VehicleInfo[i][vOwner] != playerData[playerid][actualID])
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot sell someone else's vehicle.");
				}
				else
				{
					if(sscanf(params, "ui", otherPlayer, price))
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"vsell <player id> <price>\"");
					}
					else
					{
						if (otherPlayer != playerid)
						{
							if (price < 0 || price > 10000000)
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot sell this vehicle for that price.");
							}
							else
							{
								if (IsPlayerConnected(otherPlayer) && playerData[otherPlayer][playerLoggedIn])
								{
									/*
										vSellTo,
										vBuyFrom,
										vBuyPrice
									*/

									playerData[playerid][vSellTo] = otherPlayer;
									playerData[playerid][vSellPrice] = price;
									playerData[playerid][vSellID] = i;

									// Ask the seller to confirm this before offering it to the buyer
									new string[1400];
									format(string, sizeof(string), "%sAre you sure you wish to sell your vehicle to another player?\n\n", string);

									format(string, sizeof(string), "%s{98B0CD}Sell To: {FFFFFF}%s\n", string, playerData[otherPlayer][playerNamee]);
									format(string, sizeof(string), "%s{98B0CD}You Will Receive: {FFFFFF}$%s\n\n", string, FormatNumber(price));

									format(string, sizeof(string), "%s{FFFFFF}This action is irreversible. The vehicle will no longer be yours.", string);

									ShowPlayerDialog(playerid, DIALOG_CONFIRMSALE, DIALOG_STYLE_MSGBOX, "Sell Vehicle", string, "Confirm", "Cancel");
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player is not connected or is not logged in.");
								}
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot sell this vehicle to yourself.");
						}
					}
				}

				break;
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be inside a vehicle to use this command.");
		}
	}

	return 1;
}

COMMAND:buyvehicle(playerid, params[])
{
	if (playerData[playerid][playerLoggedIn])
	{
		if (playerData[playerid][vBuyFrom] != -1)
		{
			new
				otherPlayer,
				query[300],
				pQuery[200],
				maxVehicles
			;

			if(sscanf(params, "u", otherPlayer))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"buyvehicle <seller id>\"");
			}
			else
			{
				if (playerData[otherPlayer][vSellTo] == playerid)
				{
					if (playerData[playerid][actualID] != 0)
					{
						// Player can purchase
						if (playerData[playerid][playerMoney] >= playerData[playerid][vBuyPrice])
						{
							new
								BuyVehicleID = playerData[playerid][vBuyID]
							;

							format(pQuery, sizeof(pQuery), "SELECT * FROM `vehicles` WHERE `owner` = '%i'", playerData[playerid][actualID]);

							new DBResult:presult, pcount = 0;
							presult = db_query(DB: VEHICLESDB, pQuery);
							pcount = db_num_rows(presult);

							if (playerData[playerid][playerVIPLevel] >= 1)
							{
								maxVehicles = STANDARD_VIP_MAX_VEHICLES;
							}
							else if (playerData[playerid][playerVIPLevel] >= 2)
							{
								maxVehicles = SILVER_VIP_MAX_VEHICLES;
							}
							else if (playerData[playerid][playerVIPLevel] >= 3)
							{
								maxVehicles = GOLD_VIP_MAX_VEHICLES;
							}
							else if (playerData[playerid][playerVIPLevel] >= 4)
							{
								maxVehicles = GOLDPLUS_VIP_MAX_VEHICLES;
							}
							else if(playerData[playerid][playerVIPLevel] == 0)
							{
								maxVehicles = PLAYER_MAX_VEHICLES;
							}
							if (pcount != maxVehicles)
							{
								// Update the vehicle owner
								format(query, sizeof(query), "UPDATE `vehicles` SET `owner` = '%i' WHERE `id` = '%i'", playerData[playerid][actualID], BuyVehicleID);
								VehicleInfo[BuyVehicleID][vOwner] = playerData[playerid][actualID];
								VehicleInfo[BuyVehicleID][vLocked] = true;

								if (IsPlayerInAnyVehicle(otherPlayer))
								{
									if (GetPlayerVehicleID(otherPlayer) == VehicleInfo[BuyVehicleID][vehicleID])
									{
										RemovePlayerFromVehicle(otherPlayer);
									}
								}

								db_query(DB: VEHICLESDB, query);

								// Take the cash
								playerTakeMoney(playerid, playerData[playerid][vBuyPrice]);
								playerGiveMoney(otherPlayer, playerData[playerid][vBuyPrice]);

								savePlayerStats(playerid);
								savePlayerStats(otherPlayer);

								SendClientMessage(playerid, COLOR_WHITE, "{FE9A2E}[VEHICLE TRADE] {FFFFFF}The trade has been completed, the vehicle is now yours. Type /myveh to locate and/or respawn it.");
								SendClientMessage(otherPlayer, COLOR_WHITE, "{FE9A2E}[VEHICLE TRADE] {FFFFFF}The trade has been completed, the vehicle has now been sold.");
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You have no available vehicle slots, sell a vehicle first!");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot afford to accept the trade.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Your session token is invalid, please quit and re-join to complete the trade.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}There was a problem with the trade, please ask the seller to re-trade the vehicle.");
				}
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}There are no offers available.");
		}
	}

	return 1;
}

COMMAND:myveh(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		new
			dialogList[1000],
			DBResult:locatingResult,
			locatingQuery[128],
			resultCount
		;

		format(locatingQuery, sizeof(locatingQuery), "SELECT * FROM `vehicles` WHERE `owner` = '%i'", playerData[playerid][actualID]);
		locatingResult = db_query(DB: VEHICLESDB, locatingQuery);
		resultCount = db_num_rows(locatingResult);

		if(resultCount > 0)
		{
			do
			{
				new vehicleModel, ownedID, temporaryString[54];

				db_get_field_assoc(locatingResult, "modelid", temporaryString, 3);
				vehicleModel = strval(temporaryString);

				db_get_field_assoc(locatingResult, "id", temporaryString, 3);
				ownedID = strval(temporaryString);

				format(dialogList, sizeof(dialogList), "%s (ID: %i)", vehicleNames[vehicleModel - 400], ownedID);
				AddDListItem(playerid, dialogList, DIALOG_OPTIONSLIST, ownedID);

			} while(db_next_row(locatingResult));

			ShowPlayerDList(playerid, DIALOG_OPTIONSLIST, "My Vehicles", "Select", "Close");
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not own any vehicles.");
		}

		db_free_result(locatingResult);
	}

	return 1;
}

COMMAND:playervehicles(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 3)
		{
			new
				playerwho,
				dialogtitle[60],
				dialogList[256],
				DBResult:locatingResult,
				locatingQuery[128],
				resultCount,
				bool:firstOne
			;

			if(sscanf(params, "u", playerwho))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"playervehicles <playerid>\"");
			}
			else
			{
				if (IsPlayerConnected(playerwho))
				{
					if(playerData[playerwho][playerLoggedIn])
					{
						format(locatingQuery, sizeof(locatingQuery), "SELECT * FROM `vehicles` WHERE `owner` = '%i'", playerData[playerwho][actualID]);
						locatingResult = db_query(DB: VEHICLESDB, locatingQuery);
						resultCount = db_num_rows(locatingResult);
						playerData[playerid][playerGetStats] = playerwho;

						if(resultCount > 0)
						{
							do
							{
								new vehicleModel, tvehicleID, temporaryString[54];

								db_get_field_assoc(locatingResult, "modelid", temporaryString, 3);
								vehicleModel = strval(temporaryString);

								db_get_field_assoc(locatingResult, "id", temporaryString, 3);
								tvehicleID = strval(temporaryString);

								if(firstOne == true)
								{
									format(dialogList, sizeof(dialogList), "%s (ID: %i)", dialogList, vehicleNames[vehicleModel - 400], tvehicleID);
									firstOne = false;
								}
								else
								{
									format(dialogList, sizeof(dialogList), "%s\n%s (ID: %i)", dialogList, vehicleNames[vehicleModel - 400], tvehicleID);
								}

							} while(db_next_row(locatingResult));

							format(dialogtitle, sizeof(dialogtitle), "%s's Vehicles", playerData[playerwho][playerNamee]);
							ShowPlayerDialog(playerid, DIALOG_ADMINOPTIONSLIST, DIALOG_STYLE_LIST, dialogtitle, dialogList, "Select", "Cancel");
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player does not own any vehicles.");
						}

						db_free_result(locatingResult);
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
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not have permission to use that command.");
		}
	}

	return 1;
}

COMMAND:lock(playerid, params[])
{
	if (playerData[playerid][playerLoggedIn])
	{
		if (IsPlayerInAnyVehicle(playerid))
		{
			new
				vid = GetPlayerVehicleID(playerid),
				query[400]
			;

			for(new i; i < MAX_SAVED_VEHICLES; i++)
			{
				if (vid != VehicleInfo[i][vehicleID]) continue;

				if(VehicleInfo[i][vOwner] != playerData[playerid][actualID])
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot lock/unlock another player's vehicle.");
				}
				else
				{
					if (VehicleInfo[i][vLocked])
					{
						format(query, sizeof(query), "UPDATE `vehicles` SET `locked` = '0' WHERE `id` = '%i'", i);
						VehicleInfo[i][vLocked] = !!0;

						SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[VEHICLE] {FFFFFF}Your vehicle has been {FFDC2E}unlocked{FFFFFF}.");
					}
					else
					{
						format(query, sizeof(query), "UPDATE `vehicles` SET `locked` = '1' WHERE `id` = '%i'", i);
						VehicleInfo[i][vLocked] = !!1;

						SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[VEHICLE] {FFFFFF}Your vehicle has been {FFDC2E}locked{FFFFFF}.");
					}

					new debugmsg[200];
					format(debugmsg, sizeof(debugmsg), "Tried to lock DB ID: %i", i);
					print(debugmsg);

					db_query(DB: VEHICLESDB, query);
				}

				break;
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be inside a vehicle to use this command.");
		}
	}

	return 1;
}

COMMAND:park(playerid, params[])
{
	if (playerData[playerid][playerLoggedIn])
	{
		if (IsPlayerInAnyVehicle(playerid))
		{
			new
				vid = GetPlayerVehicleID(playerid),
				query[400]
			;

			for(new i; i < MAX_SAVED_VEHICLES; i++)
			{
				if (vid != VehicleInfo[i][vehicleID]) continue;

				if(VehicleInfo[i][vOwner] != playerData[playerid][actualID] && playerData[playerid][playerLevel] < 3)
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You cannot park another player's vehicle.");
				}
				else
				{
					new
						vehicle,
						Float:x,
						Float:y,
						Float:z,
						Float:za,
						Float:a
					;

					vehicle = GetPlayerVehicleID(playerid);

					GetVehiclePos(vehicle, x, y, z);
					GetVehicleZAngle(vehicle, za);
					GetPlayerFacingAngle(playerid, a);

					VehicleInfo[i][vX] = x;
					VehicleInfo[i][vY] = y;
					VehicleInfo[i][vZ] = z;
					VehicleInfo[i][vAngle] = za;

					format(query, sizeof(query), "UPDATE `vehicles` SET `x` = '%f', `y` = '%f', `z` = '%f', `angle` = '%f' WHERE `id` = '%i'", x, y, z, za, i);

					SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[VEHICLE] {FFFFFF}Your vehicle will spawn here in future.");

					new debugmsg[200];
					format(debugmsg, sizeof(debugmsg), "Tried to park DB ID: %i", i);
					print(debugmsg);

					db_query(DB: VEHICLESDB, query);
				}

				break;
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be inside a vehicle to use this command.");
		}
	}

	return 1;
}

COMMAND:colour1(playerid, params[])
{
	if (playerData[playerid][playerLoggedIn])
	{
		new
			vid = GetPlayerVehicleID(playerid),
			query[400],
			colour
		;

		for(new i; i < MAX_SAVED_VEHICLES; i++)
		{
			if (vid != VehicleInfo[i][vehicleID]) continue;

			if(VehicleInfo[i][vOwner] != playerData[playerid][actualID])
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This is not your vehicle.");
			}
			else
			{
				if(sscanf(params, "i", colour))
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"colour1 <colour id>\"");
				}
				else
				{
					if(colour < 0 || colour > 255)
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Pick a colour between 0 and 255.");
					}
					else
					{
						PlayerPlaySound(playerid, SOUND_BUY_CAR_RESPRAY, 0.0, 0.0, 10.0);
						ChangeVehicleColor(VehicleInfo[i][vehicleID], colour, VehicleInfo[i][vColor2]);
						VehicleInfo[i][vColor1] = colour;

						format(query, sizeof(query), "UPDATE `vehicles` SET `color1` = '%i' WHERE `id` = '%i'", colour, i);
						db_query(DB: VEHICLESDB, query);
					}
				}
			}

			break;
		}
	}

	return 1;
}

COMMAND:colour2(playerid, params[])
{
	if (playerData[playerid][playerLoggedIn])
	{
		new
			vid = GetPlayerVehicleID(playerid),
			query[400],
			colour
		;

		for(new i; i < MAX_SAVED_VEHICLES; i++)
		{
			if (vid != VehicleInfo[i][vehicleID]) continue;

			if(VehicleInfo[i][vOwner] != playerData[playerid][actualID])
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This is not your vehicle.");
			}
			else
			{
				if(sscanf(params, "i", colour))
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"colour2 <colour id>\"");
				}
				else
				{
					if(colour < 0 || colour > 255)
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Pick a colour between 0 and 255.");
					}
					else
					{
						PlayerPlaySound(playerid, SOUND_BUY_CAR_RESPRAY, 0.0, 0.0, 10.0);
						ChangeVehicleColor(VehicleInfo[i][vehicleID], VehicleInfo[i][vColor1], colour);
						VehicleInfo[i][vColor2] = colour;

						format(query, sizeof(query), "UPDATE `vehicles` SET `color2` = '%i' WHERE `id` = '%i'", colour, i);
						db_query(DB: VEHICLESDB, query);
					}
				}
			}

			break;
		}
	}

	return 1;
}

/*
	- Enter vehicle
*/

forward enterVehicle(playerid, pID, vid);
public enterVehicle(playerid, pID, vid)
{
	new
		dmsg[200]
	;

	for(new i; i < MAX_SAVED_VEHICLES; i++)
	{
		if (vid != VehicleInfo[i][vehicleID]) continue;

		format(dmsg, sizeof(dmsg), "Owner: %i; Locked: %i", VehicleInfo[i][vOwner], VehicleInfo[i][vLocked]); print(dmsg);

		if(VehicleInfo[i][vOwner] != pID)
		{
			if (VehicleInfo[i][vLocked])
			{
				if (playerData[playerid][playerLevel] >= 3 && playerData[playerid][playerAdminDuty])
				{
					new
						OwnedBy[100],
						FoundOwner[48]
					;

					for(new v = 0; v < MAX_PLAYERS; v++)
					{
						if(IsPlayerConnected(v) && playerData[v][actualID] == VehicleInfo[i][vOwner])
						{
							format(FoundOwner, sizeof(FoundOwner), "%s", playerData[v][playerNamee]);

							break;
						}
					}

					format(OwnedBy, sizeof(OwnedBy), "{58D3F7}[VEHICLE] {FFFFFF}This is a locked vehicle vehicle owned by %s", FoundOwner);
					SendClientMessage(playerid, COLOR_WHITE, OwnedBy);

					new engine, lights, alarm, doors, bonnet, boot, objective;
					GetVehicleParamsEx(VehicleInfo[i][vehicleID], engine, lights, alarm, doors, bonnet, boot, objective);
					SetVehicleParamsEx(VehicleInfo[i][vehicleID], 1, lights, alarm, doors, bonnet, boot, objective);
				}
				else
				{
					new engine, lights, alarm, doors, bonnet, boot, objective;
					GetVehicleParamsEx(vid, engine, lights, alarm, doors, bonnet, boot, objective);
					SetVehicleParamsEx(vid, 0, lights, alarm, doors, bonnet, boot, objective);

					RemovePlayerFromVehicle(playerid);

					SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[VEHICLE] {FFFFFF}This is locked, you cannot drive it.");
				}
			}
			else
			{
				new
					OwnedBy[100],
					FoundOwner[48]
				;

				for(new v = 0; v < MAX_PLAYERS; v++)
				{
					if(IsPlayerConnected(v) && playerData[v][actualID] == VehicleInfo[i][vOwner])
					{
						format(FoundOwner, sizeof(FoundOwner), "%s", playerData[v][playerNamee]);

						break;
					}
				}

				format(OwnedBy, sizeof(OwnedBy), "{58D3F7}[VEHICLE] {FFFFFF}This vehicle is owned by %s", FoundOwner);
				SendClientMessage(playerid, COLOR_WHITE, OwnedBy);

				new engine, lights, alarm, doors, bonnet, boot, objective;
				GetVehicleParamsEx(VehicleInfo[i][vehicleID], engine, lights, alarm, doors, bonnet, boot, objective);
				SetVehicleParamsEx(VehicleInfo[i][vehicleID], 1, lights, alarm, doors, bonnet, boot, objective);
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[VEHICLE] {FFFFFF}Welcome back to your vehicle. Type /vcmds to view vehicle commands.");

			new engine, lights, alarm, doors, bonnet, boot, objective;
			GetVehicleParamsEx(VehicleInfo[i][vehicleID], engine, lights, alarm, doors, bonnet, boot, objective);
			SetVehicleParamsEx(VehicleInfo[i][vehicleID], 1, lights, alarm, doors, bonnet, boot, objective);

			if (vid == playerData[playerid][playerVehicleLocating])
			{
				// Found the vehicle
				RemovePlayerMapIcon(playerid, MAP_ICON_VEHICLE_LOCATE);
			}
		}

		break;
	}
}

COMMAND:vcmds(playerid, params[])
{
	if (playerData[playerid][playerLoggedIn])
	{
		new string[600];
		format(string, sizeof(string), "%s{D8D8D8}Vehicle Commands \n", string);
		format(string, sizeof(string), "%s{98B0CD}/vsell <playerid> <price> {FFFFFF}- Sell the vehicle to a player. \n", string);
		format(string, sizeof(string), "%s{98B0CD}/colour1 <colour id>{FFFFFF}- Choose the first colour. \n", string);
		format(string, sizeof(string), "%s{98B0CD}/colour2 <colour id>{FFFFFF}- Choose the second colour. \n", string);
		format(string, sizeof(string), "%s{98B0CD}/lock {FFFFFF}- Lock/Unlock your vehicle. \n", string);
		format(string, sizeof(string), "%s{98B0CD}/park {FFFFFF}- Park the vehicle (set the respawn point). \n", string);
		format(string, sizeof(string), "%s{98B0CD}/myveh {FFFFFF}- View your vehicles. \n", string);
		format(string, sizeof(string), "%s{98B0CD}/removepaintjob {FFFFFF}- Remove your paintjob. \n", string);

		ShowPlayerDialog(playerid, 125, DIALOG_STYLE_MSGBOX, "Vehicle Commands", string, "OK", "");
	}

	return 1;
}

/*
    - Start vehicle spawning
*/

// - Spawn a vehicle with a playerid, using a vehicleID.
// ! NOTE: "pID" is the player id saved in MySQL.
// ! NOTE: "vehicleid" is NOT the MODEL NUMBER. This is the ID saved in MySQL. Set to 0 if not sure.

forward Vehicle_SpawnPlayerVehicle(playerid, pID);
public Vehicle_SpawnPlayerVehicle(playerid, pID)
{
	new dmsg[100], vehicleid;

	for(new i; i < MAX_SAVED_VEHICLES; i++)
	{
		if(VehicleInfo[i][vOwner] != pID) continue;
		DestroyVehicle(VehicleInfo[i][vehicleID]);
	}

	for(new i = 0; i < MAX_SAVED_VEHICLES; i++)
	{
		if(VehicleInfo[i][vOwner] == pID)
		{
			format(dmsg, sizeof(dmsg), "(FOUND) Vehicle ID: %i; Owner: %i", i, VehicleInfo[i][vOwner]);
			print(dmsg);

			vehicleid = i;
			//DestroyObject(VehicleInfo[i][neon][1]);
			//DestroyObject(VehicleInfo[i][neon][2]);
			VehicleInfo[vehicleid][vehicleID] = CreateVehicle(VehicleInfo[vehicleid][vModelID], VehicleInfo[vehicleid][vX], VehicleInfo[vehicleid][vY], VehicleInfo[vehicleid][vZ], VehicleInfo[vehicleid][vAngle], VehicleInfo[vehicleid][vColor1], VehicleInfo[vehicleid][vColor2], 3600);
			ModVehicle(VehicleInfo[i][vehicleID]);
			ChangeVehiclePaintjob(VehicleInfo[i][vehicleID], VehicleInfo[i][vPaintjob]);
		}
	}

    /*if(VehicleInfo[vehicleid][vehicleID] == INVALID_VEHICLE_ID)
    {
        print(" ! (Vehicle_SpawnVehicle) You've reached the MAX_VEHICLES limit!");
        return INVALID_VEHICLE_ID;
    }*/

    //SetVehicleHealth(VehicleInfo[vehicleid][vehicleID], VehicleInfo[vehicleid][vHealth]);
    //SetVehicleNumberPlate(VehicleInfo[vehicleid][vehicleID], VehicleInfo[vehicleid][vNumberPlate]);
    //return VehicleInfo[vehicleid][vehicleID];
}

stock Vehicle_DestroyPlayerVehicle(pID, vehicleid = 0)
{
    if(vehicleid == 0)
    {
        for(new i; i < MAX_SAVED_VEHICLES; i++)
        {
            if(VehicleInfo[i][vOwner] != pID) continue;

            DestroyVehicle(VehicleInfo[i][vehicleID]);
			VehicleInfo[i][vehicleID] = INVALID_VEHICLE_ID;
        }
    }
    else DestroyVehicle(VehicleInfo[vehicleid][vehicleID]);
    return 1;
}
