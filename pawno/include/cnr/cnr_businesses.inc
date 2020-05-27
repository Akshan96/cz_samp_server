#define MAX_SCRIPT_BUSINESSES 20
#define MAX_PLAYER_BUSINESSES 2

enum businessstore
{
	business_id,
	business_owner[48],
	business_bought,
	business_price,
	business_title[25],
	interiorID,
	Float: busX,
	Float: busY,
	Float: busZ,
	Float: interiorX,
	Float: interiorY,
	Float: interiorZ,
	Float: interiorA,
	Text3D: label,
	Text3D: infoLabel
}

new 
	xBusinsses,
	DB:BUSINESSDB,
	business[MAX_SCRIPT_HOUSES][businessstore],
	businessCP[MAX_SCRIPT_BUSINESSES], // Enter
	businessCP2[MAX_SCRIPT_BUSINESSES] // Exit
;

forward load_businesses();
public load_businesses()
{
	BUSINESSDB = db_open("dbs/Businesses.db");
	
	new DBResult:qresult, count = 0, value[328];
	if(!db_query(DB: BUSINESSDB, "SELECT * FROM `business_data`"))
	{
		print("BUSINESS SYSTEM :: No businesses were found in \"Businesses.db\" :: 0 Loaded");
	}
	else
	{
		qresult = db_query(DB: BUSINESSDB, "SELECT * FROM `business_data`");
		count = db_num_rows(qresult);
		for(new i = 0; i < count; i++)
		{
			if(count <= MAX_SCRIPT_BUSINESSES)
			{
				// Fetch data
				db_get_field_assoc(qresult, "business_id", value, 5); // business ID 			
				business[i][business_id] = strval(value);

				db_get_field_assoc(qresult, "business_owner", value, 48); // business Owner 			
				format(business[i][business_owner], 48, value);
				
				db_get_field_assoc(qresult, "business_title", value, 48); // business Title 			
				format(business[i][business_title], 48, value); 
				
				db_get_field_assoc(qresult, "business_bought", value, 20); // business X Position
				business[i][business_bought] = strval(value);
				
				db_get_field_assoc(qresult, "business_price", value, 20); // business X Position
				business[i][business_price] = strval(value);

				db_get_field_assoc(qresult, "busX", value, 20); // business X Position
				business[i][busX] = floatstr(value);

				db_get_field_assoc(qresult, "busY", value, 20); // business Y Position
				business[i][busY] = floatstr(value);

				db_get_field_assoc(qresult, "busZ", value, 20); // business Z Position 	
				business[i][busZ] = floatstr(value);
				
				db_get_field_assoc(qresult, "interiorX", value, 20); // Interior X Position
				business[i][interiorX] = floatstr(value);

				db_get_field_assoc(qresult, "interiorY", value, 20); // Interior Y Position
				business[i][interiorY] = floatstr(value);

				db_get_field_assoc(qresult, "interiorZ", value, 20); // Interior Z Position 	
				business[i][interiorZ] = floatstr(value);
				
				db_get_field_assoc(qresult, "interiorAngle", value, 20); // Interior Angle Position 	
				business[i][interiorA] = floatstr(value);
				
				db_get_field_assoc(qresult, "interiorID", value, 20); // Interior ID 	
				business[i][interiorID] = strval(value);
				
				// Create house checkpoint
				businessCP[i] = CreateDynamicCP(business[i][busX], business[i][busY], business[i][busZ], 1.5, 0);
				businessCP2[i] = CreateDynamicCP(business[i][interiorX], business[i][interiorY], business[i][interiorZ], 1.5, 150 + business[i][business_id]);
				
				// House Labels
				new labelstring[200];
				switch(business[i][business_bought])
				{
					case 0: // For Sale
					{
						business[i][label] = Create3DTextLabel("{58D3F7}[BUSINESS]", COLOR_WHITE, business[i][busX], business[i][busY], business[i][busZ] + 0.2, 25.0, 0, 1);
						format(labelstring, sizeof(labelstring), "{FFFFFF}Owner: {FFDC2E}For Sale\n{FFFFFF}Bus ID: {FFDC2E}%i", business[i][business_id]);
					}
					case 1: // Owned
					{
						business[i][label] = Create3DTextLabel("{58D3F7}[BUSINESS]", COLOR_WHITE, business[i][busX], business[i][busY], business[i][busZ] + 0.2, 25.0, 0, 1);
						format(labelstring, sizeof(labelstring), "{FFFFFF}Title: {FFDC2E}%s \n{FFFFFF}Owner: {FFDC2E}%s \n{FFFFFF}Bus ID: {FFDC2E}%i", business[i][business_title], business[i][business_owner], business[i][business_id]);
					}
				}
				
				// Information Label
				business[i][infoLabel] = Create3DTextLabel(labelstring, 0xFF0000FF, business[i][busX], business[i][busY], business[i][busZ], 25.0, 0);
				
				// ++ xBusinsses
				xBusinsses++;
				
				print("loaded 1");
				
				// Continue loading houses
				db_next_row(qresult);
			}
		}
		
		db_free_result(qresult);
	}
}

forward reloadBusinesses();
public reloadBusinesses()
{
	for(new i = 0; i < MAX_SCRIPT_BUSINESSES; i++)
	{	
		Delete3DTextLabel(business[i][infoLabel]);
		Delete3DTextLabel(business[i][label]);				
		DestroyDynamicCP(businessCP[i]);
		DestroyDynamicCP(businessCP2[i]);
	}
	
	load_businesses();
}

forward intoBusEx(playerid, busid, silent);
public intoBusEx(playerid, busid, silent)
{
	//
	// Set position
	SetPlayerPos(playerid, business[busid][interiorX], business[busid][interiorY], business[busid][interiorZ]);
	SetPlayerInterior(playerid, business[busid][interiorID]);
	SetPlayerVirtualWorld(playerid, 150 + business[busid][business_id]);	
	SetPlayerFacingAngle(playerid, business[busid][interiorA]);
	
	//
	// Set data
	playerData[playerid][playerInsideBusiness] = busid;
	playerData[playerid][playerCheckpointTime] = GetTickCount();
	
	if (silent == 0)
	{
		if(!strcmp(business[busid][business_owner], playerData[playerid][playerNamee], true))
		{
			SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[HOUSE] {FFFFFF}Welcome back! Type /busmenu to configure your business. To leave, use the checkpoint or type {58D3F7}/exitbus{FFFFFF}.");
		}
		else
		{
			new enterString[200];
			format(enterString, sizeof(enterString), "{FFDC2E}[HOUSE] {FFFFFF}This business is owned by %s - To leave, use the checkpoint or type {58D3F7}/exitbus{FFFFFF}.", business[busid][business_owner]);
			SendClientMessage(playerid, COLOR_WHITE, enterString);
		}
	}
}

forward intoBus(playerid);
public intoBus(playerid)
{
	for(new busid; busid < MAX_SCRIPT_BUSINESSES; busid++)
	{
		if(IsPlayerInDynamicCP(playerid, businessCP[busid]))
		{
			new debugbus[200];
			format(debugbus, 200, "Inside ID: %i", busid);
			print(debugbus);
			
			if (business[busid][business_bought])
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
									new tickCountResult = GetTickCount(), reducedValue = tickCountResult - playerData[playerid][playerCheckpointTime];
									
									if(reducedValue > 3000)
									{
										//
										// Set position
										SetPlayerPos(playerid, business[busid][interiorX], business[busid][interiorY], business[busid][interiorZ]);
										SetPlayerInterior(playerid, business[busid][interiorID]);
										SetPlayerVirtualWorld(playerid, 150 + business[busid][business_id]);
										SetPlayerFacingAngle(playerid, business[busid][interiorA]);
										
										//
										// Set data
										playerData[playerid][playerInsideBusiness] = busid;
										playerData[playerid][playerCheckpointTime] = GetTickCount();
										
										if(!strcmp(business[busid][business_owner], playerData[playerid][playerNamee], true))
										{
											SendClientMessage(playerid, COLOR_WHITE, "{FFDC2E}[BUSINESS] {FFFFFF}Welcome back! Type /busmenu to configure your business. To leave, use the checkpoint.");
										}
										else
										{
											new enterString[200];
											format(enterString, sizeof(enterString), "{FFDC2E}[BUSINESS] {FFFFFF}This business is owned by %s - To leave, use the checkpoint.", business[busid][business_owner]);
											SendClientMessage(playerid, COLOR_WHITE, enterString);
										}
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
				new buyMsg[200];
				format(buyMsg, sizeof(buyMsg), "{FFDC2E}[BUSINESS] {FFFFFF}This business is for sale. Type {FFDC2E}/buybus {FFFFFF}%i", business[busid][business_id]); 
				SendClientMessage(playerid, COLOR_WHITE, buyMsg);
				break;
			}
		}
		else
		{
			break;
		}
	}
	
	return 1;
}

forward leaveBus(playerid, busid);
public leaveBus(playerid, busid)
{
	if (playerData[playerid][playerInsideBusiness] != -1)
	{
		if(IsPlayerInDynamicCP(playerid, businessCP2[busid]))
		{
			new tickCountResult = GetTickCount(), reducedValue = tickCountResult - playerData[playerid][playerCheckpointTime];
			
			if(reducedValue > 3000)
			{
				//
				// Set position
				SetPlayerPos(playerid, business[busid][busX], business[busid][busY], business[busid][busZ]);
				SetPlayerInterior(playerid, 0);
				SetPlayerVirtualWorld(playerid, 0);		
				
				//
				// Set data
				playerData[playerid][playerInsideBusiness] = -1;
				playerData[playerid][playerCheckpointTime] = GetTickCount();
			}
		}
	}
}

forward leaveBusEx(playerid, busid);
public leaveBusEx(playerid, busid)
{
	if (playerData[playerid][playerInsideBusiness] != -1)
	{
		//
		// Set position
		SetPlayerPos(playerid, business[busid][busX], business[busid][busY], business[busid][busZ]);
		SetPlayerInterior(playerid, 0);
		SetPlayerVirtualWorld(playerid, 0);		
		
		//
		// Set data
		playerData[playerid][playerInsideBusiness] = -1;
		playerData[playerid][playerCheckpointTime] = GetTickCount();
	}
}

/**********************
| Business Commands
**********************/

COMMAND:reloadbusinesses(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			reloadBusinesses();
			
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Businesses reloaded.");
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not have permission to use that command.");
		}
	}
	
	return 1;
}


COMMAND:gotobus(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 5)
		{
			new 
				busid,
				houseQuery[200]
			;
			
			if(sscanf(params, "i", busid))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"gotobus <business id>\"");
			}
			else
			{
				BUSINESSDB = db_open("dbs/Businesses.db");
				
				format(houseQuery, sizeof(houseQuery), "SELECT * FROM `business_data` WHERE `business_id` = '%i' LIMIT 1", busid);
				
				new DBResult:qresult, count = 0;
				qresult = db_query(DB: BUSINESSDB, houseQuery);
				count = db_num_rows(qresult);
				
				if (count == 0)
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That house ID doesn't exist.");
				}
				else
				{
					// Find the unique ID for house info
					new dbID, value[48];
					db_get_field_assoc(qresult, "business_id", value, 48); // House UID 			
					dbID = strval(value);
					
					for(new i = 0; i < MAX_SCRIPT_HOUSES; i++)
					{
						if(business[i][business_id] == dbID)
						{
							new
								Float:x,
								Float:y,
								Float:z
							;
							
							x = business[i][busX];
							y = business[i][busY];
							z = business[i][busZ];
							
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


COMMAND:buscreate(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 6)
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
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"buscreate <business price>\"");
			}
			else
			{
				intX = 260.6848;
				intY = 1238.0388;
				intZ = 1084.2578;
				intA = 354.7931;
				intID = 9;
				
				format(query, sizeof(query), "INSERT INTO `business_data` (business_bought, business_price, business_owner, busX, busY, busZ, interiorID, interiorX, interiorY, interiorZ, interiorAngle) VALUES ('0', '%i', 'CZCNR', '%f', '%f', '%f', '%i', '%f', '%f', '%f', '%f')", newPrice, x, y, z, intID, intX, intY, intZ, intA);
				printf("%s", query);
				db_query(DB: BUSINESSDB, query);	
				
				reloadBusinesses();
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not have permission to use that command.");
		}
	}
	
	return 1;
}

COMMAND:busmenu(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerInsideBusiness] != -1)
		{
			new
				busID = playerData[playerid][playerInsideBusiness]
			;
			
			if(!strcmp(business[busID][business_owner], playerData[playerid][playerNamee], true))
			{
				ShowPlayerDialog(playerid, DIALOG_HOUSEMENU, DIALOG_STYLE_LIST, "CZCNR Business Menu", "Import Stock \nSet Business Title \nOpen/Close Business \nWithdraw Earnings \nBusiness Stats \nSell Business", "Select", "Cancel");
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not own this business.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be inside a business to use this command.");
		}
	}
	
	return 1;
}