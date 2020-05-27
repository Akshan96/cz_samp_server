#define MAX_SCRIPT_VEHICLES 600
#define MAX_PLAYER_VEHICLES 3

enum vehicle_store
{
	vehicle_id,
	vehicle_owner[48],
	vehicle_bought,
	vehicle_price,
	vehicle_model,
	vehicle_sid,
	vehicle_locked,
	Float: vX,
	Float: vY,
	Float: vZ,
	Float: vZA,
	Float: vA,
	colour_1,
	colour_2,
	allow_spawn
}

new 
	xVehicles = 1,
	DB:VEHICLEDB,
	oVehicle[MAX_SCRIPT_VEHICLES][vehicle_store]
;

forward load_oVehicles();
public load_oVehicles()
{
	xVehicles = 0;
	
	new DBResult:qresult, count = 0, value[328];
	//new engine, lights, alarm, doors, bonnet, boot, objective;
	
	if(!db_query(DB: VEHICLEDB, "SELECT * FROM `vehicle_data`"))
	{
		print("VEHICLE SYSTEM :: No vehicles were found in \"Vehicles.db\" :: 0 Loaded");
	}
	else
	{
		db_query(DB: VEHICLEDB, "DELETE FROM `vehicle_data` WHERE `vehicle_owner` = 'SOLD'");
		
		qresult = db_query(DB: VEHICLEDB, "SELECT * FROM `vehicle_data`");
		count = db_num_rows(qresult);
		for(new i = 0; i < count; i++)
		{
			if(count <= MAX_SCRIPT_VEHICLES)
			{
				// Fetch data
				db_get_field_assoc(qresult, "vehicle_id", value, 5); // oVehicle ID 			
				oVehicle[i][vehicle_id] = strval(value);

				db_get_field_assoc(qresult, "vehicle_owner", value, 48); // oVehicle Owner 			
				format(oVehicle[i][vehicle_owner], 48, value);
				
				db_get_field_assoc(qresult, "vehicle_bought", value, 20); // oVehicle X Position
				oVehicle[i][vehicle_bought] = strval(value);
				
				db_get_field_assoc(qresult, "vehicle_price", value, 20); // oVehicle X Position
				oVehicle[i][vehicle_price] = strval(value);
				
				db_get_field_assoc(qresult, "vehicle_model", value, 20); // oVehicle type
				oVehicle[i][vehicle_model] = strval(value);
				
				db_get_field_assoc(qresult, "vehicle_locked", value, 20); // oVehicle locked
				oVehicle[i][vehicle_locked] = strval(value);

				db_get_field_assoc(qresult, "vX", value, 20); // oVehicle X Position
				oVehicle[i][vX] = floatstr(value);

				db_get_field_assoc(qresult, "vY", value, 20); // oVehicle Y Position
				oVehicle[i][vY] = floatstr(value);

				db_get_field_assoc(qresult, "vZ", value, 20); // oVehicle Z Position 	
				oVehicle[i][vZ] = floatstr(value);

				db_get_field_assoc(qresult, "vZA", value, 20); // oVehicle Z Position 	
				oVehicle[i][vZA] = floatstr(value);
				
				db_get_field_assoc(qresult, "vA", value, 20); // oVehicle A Position 	
				oVehicle[i][vA] = floatstr(value);
				
				db_get_field_assoc(qresult, "colour_1", value, 20); // oVehicle A Position 	
				oVehicle[i][colour_1] = strval(value);
				
				db_get_field_assoc(qresult, "colour_2", value, 20); // oVehicle A Position 	
				oVehicle[i][colour_2] = strval(value);
				
				//oVehicle[i][vehicle_sid] = CreateVehicle(oVehicle[i][vehicle_model], oVehicle[i][vX], oVehicle[i][vY], oVehicle[i][vZ], oVehicle[i][vZA], oVehicle[i][colour_1], oVehicle[i][colour_2], 120);
				//SetVehicleZAngle(oVehicle[i][vehicle_id], oVehicle[i][vZA]);
				
				//GetVehicleParamsEx(oVehicle[i][vehicle_sid], engine, lights, alarm, doors, bonnet, boot, objective);
				//SetVehicleParamsEx(oVehicle[i][vehicle_sid], engine, 0, alarm, doors, 0, 0, objective);

				xVehicles++;
				db_next_row(qresult);
			}
		}
		
		db_free_result(qresult);
	}
}

stock enterVehicle(vehicleID, playerid)
{
	new
		vid
	;
	
	vid = GetPlayerVehicleID(playerid);
	
	for(new i = 0; i < MAX_SCRIPT_VEHICLES; i++)
	{
		if(oVehicle[i][vehicle_sid] == vid && GetVehicleModel(vid) == oVehicle[i][vehicle_model])
		{
			if(oVehicle[i][vehicle_sid] == vehicleID)
			{
				if (playerData[playerid][playerVehicleLocating] == oVehicle[i][vehicle_sid])
				{
					RemovePlayerMapIcon(playerid, MAP_ICON_VEHICLE_LOCATE);
				}
				
				if (oVehicle[i][vehicle_bought] == 0)
				{
					new engine, lights, alarm, doors, bonnet, boot, objective;
					GetVehicleParamsEx(vehicleID, engine, lights, alarm, doors, bonnet, boot, objective);
					SetVehicleParamsEx(vehicleID, 0, lights, alarm, doors, bonnet, boot, objective);
									
					new purchaseMsg[200];
					format(purchaseMsg, sizeof(purchaseMsg), "{58D3F7}[VEHICLE] {FFFFFF}This vehicle costs {FFDC2E}$%s{FFFFFF}. Type /vbuy to purchase it.", FormatNumber(oVehicle[i][vehicle_price]));
					SendClientMessage(playerid, COLOR_WHITE, purchaseMsg);					
				}
				else
				{
					new purchaseMsg[200];
					
					if(!strcmp(oVehicle[i][vehicle_owner], playerData[playerid][playerNamee], true))
					{
						format(purchaseMsg, sizeof(purchaseMsg), "{58D3F7}[VEHICLE] {FFFFFF}Welcome back to your vehicle. Type /v to configure it.", oVehicle[i][vehicle_owner]);
						
						new engine, lights, alarm, doors, bonnet, boot, objective;
						GetVehicleParamsEx(vehicleID, engine, lights, alarm, doors, bonnet, boot, objective);
						SetVehicleParamsEx(vehicleID, 1, lights, alarm, doors, bonnet, boot, objective);
					}
					else
					{
						if (oVehicle[i][vehicle_locked] && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
						{
							if (playerData[playerid][playerLevel] >= 3)
							{
								format(purchaseMsg, sizeof(purchaseMsg), "{58D3F7}[VEHICLE] {FFFFFF}This vehicle is locked. You can drive it because you're an administrator.");
								
								new engine, lights, alarm, doors, bonnet, boot, objective;
								GetVehicleParamsEx(vehicleID, engine, lights, alarm, doors, bonnet, boot, objective);
								SetVehicleParamsEx(vehicleID, 1, lights, alarm, doors, bonnet, boot, objective);
							}
							else
							{
								new engine, lights, alarm, doors, bonnet, boot, objective;
								GetVehicleParamsEx(vehicleID, engine, lights, alarm, doors, bonnet, boot, objective);
								SetVehicleParamsEx(vehicleID, 0, lights, alarm, doors, bonnet, boot, objective);
								format(purchaseMsg, sizeof(purchaseMsg), "{58D3F7}[VEHICLE] {FFFFFF}This vehicle is locked.");
								
								RemovePlayerFromVehicle(playerid);
							}
						}
						else
						{
							format(purchaseMsg, sizeof(purchaseMsg), "{58D3F7}[VEHICLE] {FFFFFF}This vehicle is owned by {FFDC2E}%s{FFFFFF}.", oVehicle[i][vehicle_owner]);
							
							new engine, lights, alarm, doors, bonnet, boot, objective;
							GetVehicleParamsEx(vehicleID, engine, lights, alarm, doors, bonnet, boot, objective);
							SetVehicleParamsEx(vehicleID, 1, lights, alarm, doors, bonnet, boot, objective);
						}
					}
					
					SendClientMessage(playerid, COLOR_WHITE, purchaseMsg);		
				}

				break;
			}
			else
			{
				continue;
			}
		}
	}
}	

stock SpawnVehicle(vehicleID, oldID, place, playerid)
{
	new 
		vehicleQuery[200],
		engine, lights, alarm, doors, bonnet, boot, objective
	;
	
	format(vehicleQuery, sizeof(vehicleQuery), "SELECT * FROM `vehicle_data` WHERE `vehicle_id` = '%i' LIMIT 1", vehicleID);
	
	new DBResult:qresult, count = 0, value[328];
	qresult = db_query(DB: VEHICLEDB, vehicleQuery);
	count = db_num_rows(qresult);
	
	if (count == 0)
	{
		print("Invalid spawn ID");
	}
	else
	{
		db_get_field_assoc(qresult, "vehicle_id", value, 5); // oVehicle ID 			
		oVehicle[oldID][vehicle_id] = strval(value);

		db_get_field_assoc(qresult, "vehicle_owner", value, 48); // oVehicle Owner 			
		format(oVehicle[oldID][vehicle_owner], 48, value);
		
		db_get_field_assoc(qresult, "vehicle_bought", value, 20); // oVehicle X Position
		oVehicle[oldID][vehicle_bought] = strval(value);
		
		db_get_field_assoc(qresult, "vehicle_price", value, 20); // oVehicle X Position
		oVehicle[oldID][vehicle_price] = strval(value);
		
		db_get_field_assoc(qresult, "vehicle_model", value, 20); // oVehicle type
		oVehicle[oldID][vehicle_model] = strval(value);
		
		db_get_field_assoc(qresult, "vehicle_locked", value, 20); // oVehicle locked
		oVehicle[oldID][vehicle_locked] = strval(value);

		db_get_field_assoc(qresult, "vX", value, 20); // oVehicle X Position
		oVehicle[oldID][vX] = floatstr(value);

		db_get_field_assoc(qresult, "vY", value, 20); // oVehicle Y Position
		oVehicle[oldID][vY] = floatstr(value);

		db_get_field_assoc(qresult, "vZ", value, 20); // oVehicle Z Position 	
		oVehicle[oldID][vZ] = floatstr(value);
		
		db_get_field_assoc(qresult, "vZA", value, 20); // oVehicle Z Position 	
		oVehicle[oldID][vZA] = floatstr(value);
		
		db_get_field_assoc(qresult, "vA", value, 20); // oVehicle A Position 	
		oVehicle[oldID][vA] = floatstr(value);
		
		db_get_field_assoc(qresult, "colour_1", value, 20); // oVehicle A Position 	
		oVehicle[oldID][colour_1] = strval(value);
		
		db_get_field_assoc(qresult, "colour_2", value, 20); // oVehicle A Position 	
		oVehicle[oldID][colour_2] = strval(value);
		
		oVehicle[oldID][vehicle_sid] = CreateVehicle(oVehicle[oldID][vehicle_model], oVehicle[oldID][vX], oVehicle[oldID][vY], oVehicle[oldID][vZ], oVehicle[oldID][vZA], oVehicle[oldID][colour_1], oVehicle[oldID][colour_2], 120);
		SetVehicleZAngle(oVehicle[oldID][vehicle_id], oVehicle[oldID][vZA]);
		
		GetVehicleParamsEx(oVehicle[oldID][vehicle_sid], engine, lights, alarm, doors, bonnet, boot, objective);
		SetVehicleParamsEx(oVehicle[oldID][vehicle_sid], engine, 0, alarm, doors, 0, 0, objective);
		
		if (place)
		{
			PutPlayerInVehicle(playerid, oVehicle[oldID][vehicle_sid], 0);
		}
	}	
}

/**********************
| Vehicle Commands
**********************/

COMMAND:createvehicle(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 6)
		{
			new 
				vehicleID,
				newPrice,
				query[400],
				idQuery[300],
				value[48],
				Float:x, 
				Float:y, 
				Float:z,
				Float:a
			;
			
			GetPlayerPos(playerid, x, y, z);
			
			if(sscanf(params, "ii", vehicleID, newPrice))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"createvehicle <vehicle id> <vehicle price>\"");
			}
			else
			{
				format(query, sizeof(query), "INSERT INTO `vehicle_data` (vehicle_bought, vehicle_price, vehicle_owner, vehicle_model, vX, vY, vZ, vZA, vA) VALUES ('0', '%i', 'CNRSF', '%i', '%f', '%f', '%f', '0', '%f')", newPrice, vehicleID, x, y, z, a);
				db_query(DB: VEHICLEDB, query);	
				
				format(idQuery, sizeof(idQuery), "SELECT * FROM `vehicle_data` WHERE `vehicle_bought` = '0' ORDER BY `vehicle_id` DESC LIMIT 1", playerData[playerid][playerNamee]);
				
				new DBResult:idresult;
				idresult = db_query(DB: VEHICLEDB, idQuery);

				db_get_field_assoc(idresult, "vehicle_id", value, 20); // oVehicle X Position
				new dbid = strval(value);
				
				new i = xVehicles;
				oVehicle[i][vehicle_id] = dbid;
				format(oVehicle[i][vehicle_owner], 48, "CNRSF");
				oVehicle[i][vehicle_bought] = 0;
				oVehicle[i][vehicle_price] = newPrice;
				oVehicle[i][vehicle_model] = vehicleID;
				oVehicle[i][vX] = x;
				oVehicle[i][vY] = y;
				oVehicle[i][vZ] = z;
				oVehicle[i][vA] = a;
				
				oVehicle[i][vehicle_sid] = CreateVehicle(oVehicle[i][vehicle_model], oVehicle[i][vX], oVehicle[i][vY], oVehicle[i][vZ], oVehicle[i][vA], 0, 1, 120);
				SetVehicleZAngle(oVehicle[i][vehicle_id], oVehicle[i][vA]);	

				new debugmsg[100];
				format(debugmsg, sizeof(debugmsg), "Array ID assigned: %i", i);
				SendClientMessage(playerid, COLOR_WHITE, debugmsg);
				
				xVehicles++;
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not have permission to use that command.");
		}
	}
	
	return 1;
}

COMMAND:reloadvehicles(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			for(new i = 0; i < MAX_SCRIPT_VEHICLES; i++)
			{
				oVehicle[i][vehicle_id] = -1;
				format(oVehicle[i][vehicle_owner], 1, "");
				oVehicle[i][vehicle_bought] = -1;
				oVehicle[i][vehicle_price] = -1;
				oVehicle[i][vehicle_model] = -1;
				oVehicle[i][vX] = -1;
				oVehicle[i][vY] = -1;
				oVehicle[i][vZ] = -1;
				oVehicle[i][vA] = -1;
				
				DestroyVehicle(oVehicle[i][vehicle_sid]);
				oVehicle[i][vehicle_sid] = -1;
			}
			
			load_oVehicles();
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not have permission to use that command.");
		}
	}
	
	return 1;
}

COMMAND:respawnov(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			new 
				vehicleID,
				vehicleQuery[200]
			;
			
			if(sscanf(params, "i", vehicleID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"houseinfo <house id>\"");
			}
			else
			{
				format(vehicleQuery, sizeof(vehicleQuery), "SELECT * FROM `vehicle_data` WHERE `vehicle_id` = '%i' LIMIT 1", vehicleID);
				
				new DBResult:qresult, count = 0;
				qresult = db_query(DB: VEHICLEDB, vehicleQuery);
				count = db_num_rows(qresult);
				
				if (count == 0)
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That vehicle ID doesn't exist.");
				}
				else
				{
					new dbID, value[48];
					db_get_field_assoc(qresult, "vehicle_id", value, 48);	
					dbID = strval(value);
					
					for(new i = 0; i < MAX_SCRIPT_VEHICLES; i++)
					{
						if(oVehicle[i][vehicle_id] == dbID)
						{
							DestroyVehicle(oVehicle[i][vehicle_sid]);
							SpawnVehicle(dbID, i, 0, playerid);
							
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

COMMAND:destroyvehicle(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			new 
				vehicleID,
				vehicleQuery[200],
				deleteQuery[200]
			;
			
			if(sscanf(params, "i", vehicleID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"destroyvehicle <vehicle id>\"");
			}
			else
			{
				format(vehicleQuery, sizeof(vehicleQuery), "SELECT * FROM `vehicle_data` WHERE `vehicle_id` = '%i' LIMIT 1", vehicleID);
				
				new DBResult:qresult, count = 0;
				qresult = db_query(DB: VEHICLEDB, vehicleQuery);
				count = db_num_rows(qresult);
				
				if (count == 0)
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That vehicle ID doesn't exist.");
				}
				else
				{
					new dbID, value[48];
					db_get_field_assoc(qresult, "vehicle_id", value, 48);	
					dbID = strval(value);
					
					for(new i = 0; i < MAX_SCRIPT_VEHICLES; i++)
					{
						if(oVehicle[i][vehicle_id] == dbID)
						{
							oVehicle[i][vehicle_id] = -1;
							format(oVehicle[i][vehicle_owner], 1, "");
							oVehicle[i][vehicle_bought] = -1;
							oVehicle[i][vehicle_price] = -1;
							oVehicle[i][vehicle_model] = -1;
							oVehicle[i][vX] = -1;
							oVehicle[i][vY] = -1;
							oVehicle[i][vZ] = -1;
							oVehicle[i][vA] = -1;
							
							DestroyVehicle(oVehicle[i][vehicle_sid]);		
							
							format(deleteQuery, sizeof(deleteQuery), "DELETE FROM `vehicle_data` WHERE `vehicle_id` = '%i'", dbID);
							db_query(DB: VEHICLEDB, deleteQuery);	
							
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

COMMAND:gotovehicle(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			new 
				vehicleID,
				vehicleQuery[200]
			;
			
			if(sscanf(params, "i", vehicleID))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"gotovehicle <vehicle id>\"");
			}
			else
			{
				format(vehicleQuery, sizeof(vehicleQuery), "SELECT * FROM `vehicle_data` WHERE `vehicle_id` = '%i' LIMIT 1", vehicleID);
				
				new DBResult:qresult, count = 0;
				qresult = db_query(DB: VEHICLEDB, vehicleQuery);
				count = db_num_rows(qresult);
				
				if (count == 0)
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That vehicle ID doesn't exist.");
				}
				else
				{
					new dbID, value[48];
					db_get_field_assoc(qresult, "vehicle_id", value, 48);	
					dbID = strval(value);
					
					for(new i = 0; i < MAX_SCRIPT_VEHICLES; i++)
					{
						if(oVehicle[i][vehicle_id] == dbID)
						{
							new
								Float:x,
								Float:y,
								Float:z
							;
							
							GetVehiclePos(oVehicle[i][vehicle_sid], x, y, z);
							
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

COMMAND:vbuy(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
        new
			pQuery[200],
			newName[48],
			query[400],
			maxVehicles,
			bool:found
		;
		
        if(!IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be the driver of a vehicle to use this command.");
		}
        else
        {
			format(pQuery, sizeof(pQuery), "SELECT * FROM `vehicle_data` WHERE `vehicle_owner` = '%s'", playerData[playerid][playerNamee]);
			
			new DBResult:presult, pcount = 0;
			presult = db_query(DB: VEHICLEDB, pQuery);
			pcount = db_num_rows(presult);
			
			new vid = GetPlayerVehicleID(playerid);
			
			if (playerData[playerid][playerVIPLevel] >= 1)
			{
				maxVehicles = STANDARD_VIP_MAX_VEHICLES;
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You have too many vehicles. Sell a vehicle first.");
			}
			if (playerData[playerid][playerVIPLevel] >= 2)
			{
				maxVehicles = SILVER_VIP_MAX_VEHICLES;
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You have too many vehicles. Sell a vehicle first.");
			}
			if (playerData[playerid][playerVIPLevel] >= 3)
			{
				maxVehicles = GOLD_VIP_MAX_VEHICLES;
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You have too many vehicles. Sell a vehicle first.");
			}
			if(playerData[playerid][playerVIPLevel] == 0)
			{
				maxVehicles = PLAYER_MAX_VEHICLES;
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You have too many vehicles. Sell a vehicle first.");
			}
			if (pcount != maxVehicles)
			{
				for(new i = 0; i < MAX_SCRIPT_VEHICLES; i++)
				{
					if(oVehicle[i][vehicle_sid] == vid)
					{
						found = true;
						if (oVehicle[i][vehicle_bought] != 1)
						{
							if (playerData[playerid][playerMoney] >= oVehicle[i][vehicle_price])
							{
								format(newName, sizeof(newName), "%s", playerData[playerid][playerNamee]);
								format(query, sizeof(query), "UPDATE `vehicle_data` SET `vehicle_bought` = '1', `vehicle_owner` = '%s' WHERE `vehicle_id` = '%i'", playerData[playerid][playerNamee], oVehicle[i][vehicle_id]);
								db_query(DB: VEHICLEDB, query);
								
								oVehicle[i][vehicle_owner] = newName;
								oVehicle[i][vehicle_bought] = 1;
								
								new price = oVehicle[i][vehicle_price];
								playerSetMoney(playerid, playerData[playerid][playerMoney] - price);
								
								new purchaseMsg[200];
								format(purchaseMsg, sizeof(purchaseMsg), "{58D3F7}[VEHICLE] {FFFFFF}You purchased this vehicle for {FFDC2E}$%s{FFFFFF}. Type /v to configure it.", FormatNumber(oVehicle[i][vehicle_price]));
								SendClientMessage(playerid, COLOR_WHITE, purchaseMsg);
								
								new engine, lights, alarm, doors, bonnet, boot, objective;
								GetVehicleParamsEx(vid, engine, lights, alarm, doors, bonnet, boot, objective);
								SetVehicleParamsEx(vid, 1, lights, alarm, doors, bonnet, boot, objective);
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You don't have enough cash to purchase this vehicle.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This vehicle is already owned by another player.");
						}
						
						break;
					}
				}
				
				if (!found)
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You are not inside a buyable vehicle.");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You have too many vehicles. Please sell a vehicle first!");
			}
		}
	}
	
	return 1;
}

COMMAND:v(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
		{
			new
				bool:found,
				vid
			;
			
			vid = GetPlayerVehicleID(playerid);
			
			for(new i = 0; i < MAX_SCRIPT_VEHICLES; i++)
			{
				if(oVehicle[i][vehicle_sid] == vid)
				{
					found = true;
					if(!strcmp(oVehicle[i][vehicle_owner], playerData[playerid][playerNamee], true) || playerData[playerid][playerLevel] >= 6)
					{
						playerData[playerid][vehicleMenu] = i;
						ShowPlayerDialog(playerid, DIALOG_VEHICLEMENU, DIALOG_STYLE_LIST, "Vehicle Menu", "Lock/Unlock Vehicle \nSell Vehicle \nChange Colour \nToggle Lights \nToggle Boot \nToggle Hood", "Select", "Cancel");
					}
					else
					{
						SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You are not the owner of this vehicle.");
						
						new whois[200];
						format(whois, 200, "%s", oVehicle[i][vehicle_owner]);
						print(whois);
					}
					
					break;
				}
			}
			
			if(!found)
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You are not inside an owned vehicle.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be the driver of a vehicle to use this command.");
		}
	}
	
	return 1;
}

COMMAND:vehicleinfo(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 3)
		{
			if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
			{
				new
					bool:found,
					vid
				;
				
				vid = GetPlayerVehicleID(playerid);
				
				for(new i = 0; i < MAX_SCRIPT_VEHICLES; i++)
				{
					if(oVehicle[i][vehicle_sid] == vid && GetVehicleModel(vid) == oVehicle[i][vehicle_model])
					{
						found = true;

						new vlist[600];
						format(vlist, sizeof(vlist), "%s\nVehicle DB Key: %i", vlist, oVehicle[i][vehicle_id]);
						format(vlist, sizeof(vlist), "%s\nVehicle Array Key: %i", vlist, i);
						format(vlist, sizeof(vlist), "%s\nVehicle VID: %i", vlist, oVehicle[i][vehicle_sid]);
						format(vlist, sizeof(vlist), "%s\nVehicle Owner: %s", vlist, oVehicle[i][vehicle_owner]);
						format(vlist, sizeof(vlist), "%s\nVehicle Price: $%s", vlist, FormatNumber(oVehicle[i][vehicle_price]));

						ShowPlayerDialog(playerid, 969, DIALOG_STYLE_LIST, "Vehicle Information", vlist, "OK", "Close");						

						break;
					}
				}
				
				if(!found)
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You are not inside an owned vehicle.");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be the driver of a vehicle to use this command.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not have the correct permissions to use this command.");
		}
	}
	
	return 1;
}

COMMAND:playervehicles(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
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
				format(locatingQuery, sizeof(locatingQuery), "SELECT * FROM `vehicle_data` WHERE `vehicle_owner` = '%s'", playerData[playerwho][playerNamee]);
				locatingResult = db_query(DB: VEHICLEDB, locatingQuery);
				resultCount = db_num_rows(locatingResult);
				
				if(resultCount > 0)
				{				
					do
					{
						new vehicleModel, vehicleID, temporaryString[54];
						
						db_get_field_assoc(locatingResult, "vehicle_model", temporaryString, 3);
						vehicleModel = strval(temporaryString);
						
						db_get_field_assoc(locatingResult, "vehicle_id", temporaryString, 3);
						vehicleID = strval(temporaryString);
						
						if(firstOne == true)
						{
							format(dialogList, sizeof(dialogList), "%s (ID: %i)", dialogList, vehicleNames[vehicleModel - 400], vehicleID);
							firstOne = false;
						}
						else
						{
							format(dialogList, sizeof(dialogList), "%s\n%s (ID: %i)", dialogList, vehicleNames[vehicleModel - 400], vehicleID);
						}
						
					} while(db_next_row(locatingResult));
					
					format(dialogtitle, sizeof(dialogtitle), "%s's Vehicles", playerData[playerwho][playerNamee]);
					ShowPlayerDialog(playerid, DIALOG_OPTIONSLIST, DIALOG_STYLE_LIST, dialogtitle, dialogList, "Select", "Cancel");
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That player does not own any vehicles.");
				}
		  
				db_free_result(locatingResult);
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not have permission to use that command.");
		}
	}
	
	return 1;
}

COMMAND:myvehicles(playerid, params[])
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
		
		format(locatingQuery, sizeof(locatingQuery), "SELECT * FROM `vehicle_data` WHERE `vehicle_owner` = '%s'", playerData[playerid][playerNamee]);
		locatingResult = db_query(DB: VEHICLEDB, locatingQuery);
		resultCount = db_num_rows(locatingResult);
		
		if(resultCount > 0)
		{				
			do
			{
				new vehicleModel, vehicleID, temporaryString[54];
				
				db_get_field_assoc(locatingResult, "vehicle_model", temporaryString, 3);
				vehicleModel = strval(temporaryString);
				
				db_get_field_assoc(locatingResult, "vehicle_id", temporaryString, 3);
				vehicleID = strval(temporaryString);
				
				if(firstOne == true)
				{
					format(dialogList, sizeof(dialogList), "%s (ID: %i)", dialogList, vehicleNames[vehicleModel - 400], vehicleID);
					firstOne = false;
				}
				else
				{
					format(dialogList, sizeof(dialogList), "%s\n%s (ID: %i)", dialogList, vehicleNames[vehicleModel - 400], vehicleID);
				}
				
			} while(db_next_row(locatingResult));
			
			ShowPlayerDialog(playerid, DIALOG_OPTIONSLIST, DIALOG_STYLE_LIST, "My Vehicles", dialogList, "Select", "Cancel");
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not own any vehicles.");
		}
  
		db_free_result(locatingResult);
	}
	
	return 1;
}

COMMAND:spawncar(playerid, params[])
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
		
		format(locatingQuery, sizeof(locatingQuery), "SELECT * FROM `vehicle_data` WHERE `vehicle_owner` = '%s'", playerData[playerid][playerNamee]);
		locatingResult = db_query(DB: VEHICLEDB, locatingQuery);
		resultCount = db_num_rows(locatingResult);
		
		if(resultCount > 0)
		{				
			do
			{
				TextDrawShowForPlayer(playerid, vSpawns[0]);
				TextDrawShowForPlayer(playerid, vSpawns[1]);
				
				new vehicleModel, temporaryString[54];
				
				db_get_field_assoc(locatingResult, "vehicle_model", temporaryString, 3);
				vehicleModel = strval(temporaryString);
				
				if(firstOne == true)
				{
					format(dialogList, sizeof(dialogList), "%s {D87C3E}$100", dialogList, vehicleNames[vehicleModel - 400]);
					firstOne = false;
				}
				else
				{
					format(dialogList, sizeof(dialogList), "%s\n%s {D87C3E}$100", dialogList, vehicleNames[vehicleModel - 400]);
				}
				
			} while(db_next_row(locatingResult));
			
			ShowPlayerDialog(playerid, DIALOG_VEHICLESPAWN, DIALOG_STYLE_LIST, " ", dialogList, "Spawn", "Cancel");
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not own any vehicles.");
		}
  
		db_free_result(locatingResult);
	}
	
	return 1;
}

public OnVehicleDeath(vehicleid, killerid)
{
	for(new i = 0; i < MAX_SCRIPT_VEHICLES; i++)
	{
		if (oVehicle[i][vehicle_id] != -1)
		{
			if(oVehicle[i][vehicle_sid] == vehicleid)
			{
				oVehicle[i][allow_spawn] = 0;
				DestroyVehicle(oVehicle[i][vehicle_sid]);
			}
			
			break;
		}
	}
	
	vWarped[vehicleid][Spawned] = false;
	vWarped[vehicleid][wasOccupied] = false;
}
