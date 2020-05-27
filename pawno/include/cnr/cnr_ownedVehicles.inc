// cnr_ownedVehicles
forward loadOwnedVehicles();
forward respawnVehicle(ownedVehicleID);
forward findNextVehicleSlot(playerid);
forward saveVehicleComponent(ownedVehicleID, componentid);
forward getDriverID(vehicleid);
forward applyVehicleModifications(ownedVehicleID);

#define MAX_BUYABLE_VEHICLES		200
#define MAX_VEHICLES_PER_PLAYER		2
#define MAX_PLAYER_VEHICLES 3

enum vData 
{
	vehicleOwnedID,
	vehicleModel,
	vehicleOwner[24],
	Float:vehiclePosX,
	Float:vehiclePosY,
	Float:vehiclePosZ,
	Float:vehiclePosA,
	Float:vehiclePosZA,
	vehicleColour1,
	vehicleColour2,
	vehiclePlate[24],
	vehicleLockStatus,
	vehiclePrice,
	vehicleOwnedStatus,
	vehicleMods[17]
}






	
	
	
public loadOwnedVehicles()
{
	new file[72];
	for(new i = 0; i < MAX_BUYABLE_VEHICLES; i++)
	{
		format(file, sizeof(file), "vehicles/vehicle_%i.ini", i);
		
		if(fexist(file))
		{
		
			INI_Open(file);
			
			vehicleData[i][vehicleLockStatus]	=	INI_ReadInt("vehicleLockStatus");
			vehicleData[i][vehicleOwnedID] 		=	INI_ReadInt("vehicleOwnedID");
			vehicleData[i][vehicleColour1]		=	INI_ReadInt("vehicleColour1");
			vehicleData[i][vehicleColour2]		= 	INI_ReadInt("vehicleColour2");
			vehicleData[i][vehicleModel]		=	INI_ReadInt("vehicleModel");
			vehicleData[i][vehiclePrice]		=	INI_ReadInt("vehiclePrice");
			vehicleData[i][vehicleOwnedStatus]	=	INI_ReadInt("vehicleOwnedStatus");
			
			vehicleData[i][vehiclePosX]			=	INI_ReadFloat("vehiclePosX");
			vehicleData[i][vehiclePosY]			=	INI_ReadFloat("vehiclePosY");
			vehicleData[i][vehiclePosZ]			=	INI_ReadFloat("vehiclePosZ");
			vehicleData[i][vehiclePosA]			=	INI_ReadFloat("vehiclePosA");
			vehicleData[i][vehiclePosZA]		=	INI_ReadFloat("vehiclePosZA");
			
			INI_ReadString(vehicleData[i][vehiclePlate], "vehiclePlate");
			INI_ReadString(vehicleData[i][vehicleOwner], "vehicleOwner");
			
			INI_Close();
			
			vehicleCount[i] = CreateVehicle(vehicleData[i][vehicleModel], vehicleData[i][vehiclePosX], vehicleData[i][vehiclePosY], vehicleData[i][vehiclePosZ], vehicleData[i][vehiclePosZA], vehicleData[i][vehicleColour1], vehicleData[i][vehicleColour2], 120);
			SetVehicleZAngle(vehicleCount[i], vehicleData[i][vehiclePosZA]);
			
		}
		else
		{
			continue;
		}
		
	}
}

public respawnVehicle(ownedVehicleID)
{
	new file[72];
	format(file, sizeof(file), "vehicles/vehicle_%i.ini", ownedVehicleID);
		
	if(fexist(file))
	{
		DestroyVehicle(vehicleCount[ownedVehicleID]);
		vehicleCount[ownedVehicleID] = CreateVehicle(vehicleData[ownedVehicleID][vehicleModel], vehicleData[ownedVehicleID][vehiclePosX], vehicleData[ownedVehicleID][vehiclePosY], vehicleData[ownedVehicleID][vehiclePosZ], vehicleData[ownedVehicleID][vehiclePosZA], vehicleData[ownedVehicleID][vehicleColour1], vehicleData[ownedVehicleID][vehicleColour2], 120);
		SetVehicleZAngle(vehicleCount[ownedVehicleID], vehicleData[ownedVehicleID][vehiclePosZA]);
		applyVehicleModifications(ownedVehicleID);
	}
}

public getDriverID(vehicleid)
{
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(GetPlayerVehicleID(i) == vehicleid && GetPlayerState(i) == PLAYER_STATE_DRIVER) 
		{
			return i;
		}
    }
    return INVALID_PLAYER_ID;
}

COMMAND:createvehicle(playerid, params[])
{
	if(playerData[playerid][playerLevel] >= 5)
	{
		new vehiclePrice2, vehicleModel2, file[72], bool:foundGap = false;
        
        if(!sscanf(params, "ii", vehicleModel2, vehiclePrice2))
        {
			for(new i = 0; i < MAX_BUYABLE_VEHICLES; i++)
			{
				if(!foundGap)
				{
					format(file, sizeof(file), "vehicles/vehicle_%i.ini", i);
					
					if(!fexist(file))
					{
					
						new Float:x, Float:y, Float:z, Float:a, message[128];
						
						GetPlayerPos(playerid, x, y, z);
						GetPlayerFacingAngle(playerid, a);
						
							
						vehicleData[i][vehicleOwnedID]		= i;
						vehicleData[i][vehicleColour1]		= 1;
						vehicleData[i][vehicleColour2]		= 1;
						vehicleData[i][vehicleModel]		= vehicleModel2;
						vehicleData[i][vehiclePrice] 		= vehiclePrice2;
						vehicleData[i][vehicleOwnedStatus]	= 0;
						vehicleData[i][vehicleLockStatus]	= 0;
						
						vehicleData[i][vehiclePosX]			= x;
						vehicleData[i][vehiclePosY]			= y;
						vehicleData[i][vehiclePosZ]			= z;
						vehicleData[i][vehiclePosA]			= a;
						vehicleData[i][vehiclePosZA]		= 0;
						
						format(vehicleData[i][vehiclePlate], 24, "CNR");
						format(vehicleData[i][vehicleOwner], 24, "None");
						
						vehicleCount[i] = CreateVehicle(vehicleData[i][vehicleModel], vehicleData[i][vehiclePosX], vehicleData[i][vehiclePosY], vehicleData[i][vehiclePosZ], vehicleData[i][vehiclePosA], vehicleData[i][vehicleColour1], vehicleData[i][vehicleColour2], 120);
						
						format(message, sizeof(message), "{6DD926}[SUCCESS] {FFFFFF}vehicle_%i.ini has been created.", i);
						SendClientMessage(playerid, COLOR_WHITE, message);
						
						PutPlayerInVehicle(playerid, vehicleCount[i], 0);
						
						INI_Open(file);
						
						INI_WriteInt("vehicleOwnedID", vehicleData[i][vehicleOwnedID]);
						INI_WriteInt("vehicleColour1", vehicleData[i][vehicleColour1]);
						INI_WriteInt("vehicleColour2", vehicleData[i][vehicleColour2]);
						INI_WriteInt("vehicleModel", vehicleData[i][vehicleModel]);
						INI_WriteInt("vehiclePrice", vehicleData[i][vehiclePrice]);
						INI_WriteInt("vehicleLockStatus", 0);
						INI_WriteInt("vehicleOwnedStatus", vehicleData[i][vehicleOwnedStatus]);
				
						INI_WriteFloat("vehiclePosX", x);
						INI_WriteFloat("vehiclePosY", y);
						INI_WriteFloat("vehiclePosZ", z);
						INI_WriteFloat("vehiclePosA", a);
						INI_WriteFloat("vehiclePosZA", 0.0000);
			   
						INI_WriteString("vehiclePlate", vehicleData[i][vehiclePlate]);
						INI_WriteString("vehicleOwner", vehicleData[i][vehicleOwner]);
						
						INI_WriteInt("vehicleMod1", vehicleData[i][vehicleMods][0]);
						INI_WriteInt("vehicleMod2", vehicleData[i][vehicleMods][1]);
						INI_WriteInt("vehicleMod3", vehicleData[i][vehicleMods][2]);
						INI_WriteInt("vehicleMod4", vehicleData[i][vehicleMods][3]);
						INI_WriteInt("vehicleMod5", vehicleData[i][vehicleMods][4]);
						INI_WriteInt("vehicleMod6", vehicleData[i][vehicleMods][5]);
						INI_WriteInt("vehicleMod7", vehicleData[i][vehicleMods][6]);
						INI_WriteInt("vehicleMod8", vehicleData[i][vehicleMods][7]);
						INI_WriteInt("vehicleMod9", vehicleData[i][vehicleMods][8]);
						INI_WriteInt("vehicleMod10", vehicleData[i][vehicleMods][9]);
						INI_WriteInt("vehicleMod11", vehicleData[i][vehicleMods][10]);
						INI_WriteInt("vehicleMod12", vehicleData[i][vehicleMods][11]);
						INI_WriteInt("vehicleMod13", vehicleData[i][vehicleMods][12]);
						INI_WriteInt("vehicleMod14", vehicleData[i][vehicleMods][13]);
						INI_WriteInt("vehicleMod15", vehicleData[i][vehicleMods][14]);
						INI_WriteInt("vehicleMod16", vehicleData[i][vehicleMods][15]);
						INI_WriteInt("vehicleMod17", vehicleData[i][vehicleMods][16]);
						
						INI_Save();
						INI_Close();
						
						foundGap = true;
						
					}
				}
			}
			
			new log[250];
			format(log, sizeof(log), "%s(%i) created a vehicle", playerData[playerid][playerNamee], playerid);
			SendAdminText(playerid, log);
        }
        else
        {
			return SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: /createvehicle [MODEL_ID] [PRICE]");
        }
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not have the correct permissions to use this command.");
	}
	
	return 1;
}

COMMAND:destroyvehicle(playerid, params[])
{
	if(playerData[playerid][playerLevel] >= 5)
	{
		new currentVehID = GetPlayerVehicleID(playerid);

		for(new i = 0; i < MAX_BUYABLE_VEHICLES; i++)
		{
			if(currentVehID == vehicleCount[i])
			{
				new file[72], message[128];
				
				format(file, sizeof(file), "vehicles/vehicle_%i.ini", i);
				
				if(fexist(file))
				{
					
					fremove(file);
					
					DestroyVehicle(vehicleCount[i]);
					
					format(message, sizeof(message), "{6DD926}[SUCCESS] {FFFFFF}vehicle_%i.ini has been deleted.", i);
					SendClientMessage(playerid, COLOR_WHITE, message);
					
					new log[250];
					format(log, sizeof(log), "%s(%i) destroyed an owned vehicle", playerData[playerid][playerNamee], playerid);
					SendAdminText(playerid, log);
				}
			}
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not have the correct permissions to use this command.");
	}
	
	return 1;
}

COMMAND:v(playerid, params[])
{
	new commandSelection[128];
	
	if(playerData[playerid][playerLoggedIn])
	{
		if(!sscanf(params, "s[128] ", commandSelection))
		{
			if(!strcmp(commandSelection, "sell", true, 4))
			{
				if(IsPlayerInAnyVehicle(playerid))
				{
				
					new currentVehID = GetPlayerVehicleID(playerid);

					for(new i = 0; i < MAX_BUYABLE_VEHICLES; i++)
					{
						new file[72], message[128];
						
						format(file, sizeof(file), "vehicles/vehicle_%i.ini", i);
						
						if(fexist(file))
						{
							if(currentVehID == vehicleCount[i])
							{
								new returnedMoney, playerName[24], ownerName[24];
								
								INI_Open(file);
								
								GetPlayerName(playerid, playerName, sizeof(playerName));
								
								vehicleData[i][vehiclePrice]		=	INI_ReadInt("vehiclePrice");
								vehicleData[i][vehicleOwnedStatus]	=	INI_ReadInt("vehicleOwnedStatus");
								
								INI_ReadString(ownerName, "vehicleOwner");
								format(vehicleData[i][vehicleOwner], sizeof(ownerName), "%s", ownerName);
								
								if(!strcmp(playerName, vehicleData[i][vehicleOwner], true))
								{
								
									for(new b = 0; b < MAX_PLAYER_VEHICLES; b++)
									{
										if(playerData[playerid][playerVehicles][b] == i)
										{
											playerData[playerid][playerVehicles][b] = -1;
										}
									}
							
									returnedMoney = (vehicleData[i][vehiclePrice] / 2);
									playerGiveMoney(playerid, returnedMoney);
									
									INI_RemoveEntry("vehicleOwnedStatus");
									INI_RemoveEntry("vehicleLockStatus");
									INI_RemoveEntry("vehiclePlate");
									INI_RemoveEntry("vehicleOwner");
									INI_RemoveEntry("vehicleModel");
									
									INI_WriteInt("vehicleOwnedStatus", 0);
									INI_WriteInt("vehicleLockStatus", 0);
									
									INI_WriteString("vehiclePlate", "SFCNR");
									INI_WriteString("vehicleOwner", "None");
									
									format(message, sizeof(message), "{B7B7B7}[SERVER] {FFFFFF}You have sold your vehicle and received %d!", returnedMoney);
									SendClientMessage(playerid, COLOR_WHITE, message);
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You need to be in a vehicle you own to use this command!");
								}
								
								INI_Save();
								INI_Close();
								
							}
						}
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You need to be in a vehicle you own to use this command!");
				}
			}
			else if(!strcmp(commandSelection, "buy", true, 3))
			{
				if(IsPlayerInAnyVehicle(playerid))
				{
				
					new currentVehID = GetPlayerVehicleID(playerid);

					for(new i = 0; i < MAX_BUYABLE_VEHICLES; i++)
					{
						new file[72], message[128];
						
						format(file, sizeof(file), "vehicles/vehicle_%i.ini", i);
						
						if(fexist(file))
						{
							if(currentVehID == vehicleCount[i])
							{
								if(findNextVehicleSlot(playerid) != -1)
								{
									if(findNextVehicleSlot(playerid) > -1 && findNextVehicleSlot(playerid) < MAX_PLAYER_VEHICLES)
									{
										INI_Open(file);
										
										new playerName[24], ownerName[24];
										
										vehicleData[i][vehiclePrice]		=	INI_ReadInt("vehiclePrice");
										vehicleData[i][vehicleOwnedStatus]	=	INI_ReadInt("vehicleOwnedStatus");
										
										INI_ReadString(ownerName, "vehicleOwner");
										format(vehicleData[i][vehicleOwner], sizeof(ownerName), "%s", ownerName);
										
										if(vehicleData[i][vehicleOwnedStatus] == 0)
										{
											if(!strcmp("None", vehicleData[i][vehicleOwner], true))
											{
												if(playerData[playerid][playerMoney] >= vehicleData[i][vehiclePrice])
												{
												
													GetPlayerName(playerid, playerName, sizeof(playerName));
													playerGiveMoney(playerid, -vehicleData[i][vehiclePrice]);
													
													INI_RemoveEntry("vehicleOwnedStatus");
													INI_RemoveEntry("vehicleLockStatus");
													INI_RemoveEntry("vehiclePlate");
													INI_RemoveEntry("vehicleOwner");
													
													INI_WriteInt("vehicleOwnedStatus", 1);
													INI_WriteInt("vehicleLockStatus", 0);
													
													INI_WriteString("vehiclePlate", playerName);
													INI_WriteString("vehicleOwner", playerName);
													
													playerData[playerid][playerVehicles][findNextVehicleSlot(playerid)] = i;
													
													format(message, sizeof(message), "{B7B7B7}[SERVER] {FFFFFF}You have bought this vehicle for %d!", vehicleData[i][vehiclePrice]);
													SendClientMessage(playerid, COLOR_WHITE, message);
													PlayerPlaySound(playerid, 1150, 0.0, 0.0, 10.0);
													
													new engine, lights, alarm, doors, bonnet, boot, objective;
													GetVehicleParamsEx(currentVehID, engine, lights, alarm, doors, bonnet, boot, objective);
													SetVehicleParamsEx(currentVehID, 1, lights, alarm, doors, bonnet, boot, objective);
												}
												else
												{
													format(message, sizeof(message), "{B7B7B7}[SERVER] {FFFFFF}You need %d in order to purchase this vehicle.", vehicleData[i][vehiclePrice]);
													SendClientMessage(playerid, COLOR_WHITE, message);
													PlayerPlaySound(playerid, 1055, 0.0, 0.0, 10.0);
												}
											}
											else
											{
												SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You need to be in a purchasable vehicle to use this command.");
												PlayerPlaySound(playerid, 1055, 0.0, 0.0, 10.0);
											}
										}
										else
										{
											SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You need to be in a purchasable vehicle to use this command.");
											PlayerPlaySound(playerid, 1055, 0.0, 0.0, 10.0);
										}
										
										INI_Save();
										INI_Close();
									}
								}
								else
								{
									// Reached max vehicle limit
									SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You don't have an available vehicle slot.");
									PlayerPlaySound(playerid, 1055, 0.0, 0.0, 10.0);									
								}
							}
						}
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You need to be in a purchasable vehicle to use this command.");
					PlayerPlaySound(playerid, 1055, 0.0, 0.0, 10.0);
				}
			}			
			else if(!strcmp(commandSelection, "locate", true, 6))
			{
				new dialogValue[500], gotAVehicle = 0, file[72], vehicleInformation;
				for(new i = 0; i < MAX_PLAYER_VEHICLES; i++)
				{
					if(playerData[playerid][playerVehicles][i] != -1)
					{
						format(file, sizeof(file), "vehicles/vehicle_%i.ini", playerData[playerid][playerVehicles][i]);
						
						if(fexist(file))
						{
							INI_Open(file);
							vehicleInformation = INI_ReadInt("vehicleModel");
							INI_Close();
						}
						if(gotAVehicle == 0)
						{
							format(dialogValue, sizeof(dialogValue), "%s", vehicleNames[vehicleInformation - 400]);
							gotAVehicle++;
						}
						else
						{
							format(dialogValue, sizeof(dialogValue), "%s\n%s", dialogValue, vehicleNames[vehicleInformation - 400]);
						}
					}
				}
				
				if(gotAVehicle == 0)
				{
					format(dialogValue, sizeof(dialogValue), "No vehicles");
				}
				
				ShowPlayerDialog(playerid, DIALOG_VEHICLE_LOCATE, DIALOG_STYLE_LIST, "Locate your vehicle(s)", dialogValue, "Locate", "Close");
			}
			else if(!strcmp(commandSelection, "lock", true, 4))
			{
				if(IsPlayerInAnyVehicle(playerid))
				{
				
					new currentVehID = GetPlayerVehicleID(playerid);

					for(new i = 0; i < MAX_BUYABLE_VEHICLES; i++)
					{
						new file[72], message[128];
						
						format(file, sizeof(file), "vehicles/vehicle_%i.ini", i);
						
						if(fexist(file))
						{
							if(currentVehID == vehicleCount[i])
							{
								new playerName[24], ownerName[24];
								
								INI_Open(file);
								
								GetPlayerName(playerid, playerName, sizeof(playerName));

								vehicleData[i][vehicleLockStatus] = INI_ReadInt("vehicleLockStatus");
								INI_ReadString(ownerName, "vehicleOwner");
								format(vehicleData[i][vehicleOwner], sizeof(ownerName), "%s", ownerName);
								
								
								if(!strcmp(playerName, vehicleData[i][vehicleOwner], true))
								{
									if(vehicleData[i][vehicleLockStatus] != 0)
									{
										INI_RemoveEntry("vehicleLockStatus");
										
										INI_WriteInt("vehicleLockStatus", 0); // Unlock
										
										format(message, sizeof(message), "{FFDC2E}[VEHICLE] {FFFFFF}You have unlocked your vehicle!");
										SendClientMessage(playerid, COLOR_WHITE, message);
										PlayerPlaySound(playerid, 1145, 0.0, 0.0, 10.0);
									}
									else
									{
										INI_RemoveEntry("vehicleLockStatus");
										
										INI_WriteInt("vehicleLockStatus", 1); // Lock
										
										format(message, sizeof(message), "{FFDC2E}[VEHICLE] {FFFFFF}You have locked your vehicle!");
										SendClientMessage(playerid, COLOR_WHITE, message);
										PlayerPlaySound(playerid, 1145, 0.0, 0.0, 10.0);
									}
									
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You need to be in a vehicle you own to use this command!");
									PlayerPlaySound(playerid, 1055, 0.0, 0.0, 10.0);
								}
								
								INI_Save();
								INI_Close();
								
							}
						}
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You need to be in a vehicle you own to use this command!");
					PlayerPlaySound(playerid, 1055, 0.0, 0.0, 10.0);
				}				
			}
			else if(!strcmp(commandSelection, "park", true, 4))
			{
				if(IsPlayerInAnyVehicle(playerid))
				{
				
					new currentVehID = GetPlayerVehicleID(playerid);

					for(new i = 0; i < MAX_BUYABLE_VEHICLES; i++)
					{
						new file[72], message[128];
						
						format(file, sizeof(file), "vehicles/vehicle_%i.ini", i);
						
						if(fexist(file))
						{
							if(currentVehID == vehicleCount[i])
							{
								new playerName[24], ownerName[24], Float:pX, Float:pY, Float:pZ, Float:pA, Float:pZA;
								
								INI_Open(file);
								
								GetPlayerName(playerid, playerName, sizeof(playerName));
								
								INI_ReadString(ownerName, "vehicleOwner");
								format(vehicleData[i][vehicleOwner], sizeof(ownerName), "%s", ownerName);
								
								if(!strcmp(playerName, vehicleData[i][vehicleOwner], true))
								{
									GetVehiclePos(vehicleCount[i], pX, pY, pZ);
									GetVehicleZAngle(vehicleCount[i], pZA);
									GetPlayerFacingAngle(playerid, pA);
									
									INI_RemoveEntry("vehiclePosX");
									INI_RemoveEntry("vehiclePosY");
									INI_RemoveEntry("vehiclePosZ");
									INI_RemoveEntry("vehiclePosA");
									INI_RemoveEntry("vehiclePosZA");
									
									INI_WriteFloat("vehiclePosX", pX);
									INI_WriteFloat("vehiclePosY", pY);
									INI_WriteFloat("vehiclePosZ", pZ);
									INI_WriteFloat("vehiclePosA", pA);
									INI_WriteFloat("vehiclePosZA", pZA);
									
									vehicleData[i][vehiclePosX] = pX;
									vehicleData[i][vehiclePosY] = pY;
									vehicleData[i][vehiclePosZ] = pZ;
									vehicleData[i][vehiclePosA] = pA;
									vehicleData[i][vehiclePosZA] = pZA;
									
									format(message, sizeof(message), "{FFDC2E}[VEHICLE] {FFFFFF}You have parked your vehicle.");
									SendClientMessage(playerid, COLOR_WHITE, message);
									PlayerPlaySound(playerid, 1131, 0.0, 0.0, 10.0);
								}
								else if(playerData[playerid][playerLevel] >= 3)
								{
									GetVehiclePos(vehicleCount[i], pX, pY, pZ);
									GetVehicleZAngle(vehicleCount[i], pZA);
									GetPlayerFacingAngle(playerid, pA);

									INI_RemoveEntry("vehiclePosX");
									INI_RemoveEntry("vehiclePosY");
									INI_RemoveEntry("vehiclePosZ");
									INI_RemoveEntry("vehiclePosA");
									INI_RemoveEntry("vehiclePosZA");

									INI_WriteFloat("vehiclePosX", pX);
									INI_WriteFloat("vehiclePosY", pY);
									INI_WriteFloat("vehiclePosZ", pZ);
									INI_WriteFloat("vehiclePosA", pA);
									INI_WriteFloat("vehiclePosZA", pZA);
									
									vehicleData[i][vehiclePosX] = pX;
									vehicleData[i][vehiclePosY] = pY;
									vehicleData[i][vehiclePosZ] = pZ;
									vehicleData[i][vehiclePosA] = pZ;
									vehicleData[i][vehiclePosZA] = pZA;
									
									format(message, sizeof(message), "{07E08D}[ADMIN] {FFFFFF}You have admin parked this vehicle.");
									SendClientMessage(playerid, COLOR_WHITE, message);
									PlayerPlaySound(playerid, 1131, 0.0, 0.0, 10.0);
									
									new log[250];
									format(log, sizeof(log), "%s(%i) admin parked a vehicle", playerData[playerid][playerNamee], playerid);
									SendAdminText(playerid, log);
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You need to be in a vehicle you own to use this command!");
									PlayerPlaySound(playerid, 1055, 0.0, 0.0, 10.0);
								}
								
								INI_Save();
								INI_Close();
								
							}
						}
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You need to be in a vehicle you own to use this command!");
				}		
			}
			else if(!strcmp(commandSelection, "clearmods", true, 9))
			{
			
			}
			else if(!strcmp(commandSelection, "color", true, 6))
			{
				if(IsPlayerInAnyVehicle(playerid))
				{
				
					new currentVehID = GetPlayerVehicleID(playerid);

					for(new i = 0; i < MAX_BUYABLE_VEHICLES; i++)
					{
						new file[72], message[128];
						
						format(file, sizeof(file), "vehicles/vehicle_%i.ini", i);
						
						if(fexist(file))
						{
							if(currentVehID == vehicleCount[i])
							{
								new playerName[24], ownerName[24], colour_1, colour_2;
								
								INI_Open(file);
								
								GetPlayerName(playerid, playerName, sizeof(playerName));
								
								INI_ReadString(ownerName, "vehicleOwner");
								format(vehicleData[i][vehicleOwner], sizeof(ownerName), "%s", ownerName);
								
								if(!strcmp(playerName, vehicleData[i][vehicleOwner], true))
								{
									if(!sscanf(params, "s[128] ii", commandSelection, colour_1, colour_2))
									{
									
										INI_RemoveEntry("vehicleColour1");
										INI_RemoveEntry("vehicleColour2");
										
										INI_WriteInt("vehicleColour1", colour_1);
										INI_WriteInt("vehicleColour2", colour_2);
										
										vehicleData[i][vehicleColour1] = colour_1;
										vehicleData[i][vehicleColour2] = colour_2;
										
										format(message, sizeof(message), "{FFDC2E}[VEHICLE] {FFFFFF}You have recoloured your vehicle!");
										SendClientMessage(playerid, COLOR_WHITE, message);
										ChangeVehicleColor(currentVehID, colour_1, colour_2);
										
									}
									else
									{
										return SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: /v color [COLOUR_1] [COLOUR_2]");
									}
								}
								else
								{
									SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You need to be in a vehicle you own to use this command!");
								}

								INI_Save();
								INI_Close();
								
							}
						}
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You need to be in a vehicle you own to use this command!");
				}				
			}
			else if(!strcmp(commandSelection, "respawn", true, 7))
			{
				new dialogValue[500], gotAVehicle = 0, file[72], vehicleInformation;
				for(new i = 0; i < MAX_PLAYER_VEHICLES; i++)
				{
					if(playerData[playerid][playerVehicles][i] != -1)
					{
						format(file, sizeof(file), "vehicles/vehicle_%i.ini", playerData[playerid][playerVehicles][i]);
						
						if(fexist(file))
						{
							INI_Open(file);
							vehicleInformation = INI_ReadInt("vehicleModel");
							INI_Close();
						}
						if(gotAVehicle == 0)
						{
							format(dialogValue, sizeof(dialogValue), "%s", vehicleNames[vehicleInformation - 400]);
							gotAVehicle++;
						}
						else
						{
							format(dialogValue, sizeof(dialogValue), "%s\n%s", dialogValue, vehicleNames[vehicleInformation - 400]);
						}
					}
				}
				
				if(gotAVehicle == 0)
				{
					format(dialogValue, sizeof(dialogValue), "No vehicles");
				}
				
				ShowPlayerDialog(playerid, DIALOG_VEHICLE_RESPAWN, DIALOG_STYLE_LIST, "Locate your vehicle(s)", dialogValue, "Respawn", "Close");
			}
			else
			{
				return SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: /v [BUY/SELL/LOCATE/RESPAWN/LOCK/CLEARMODS/COLOR]");
			}	
		}
		else
		{
			return SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: /v [BUY/SELL/LOCATE/RESPAWN/LOCK/CLEARMODS/COLOR]");
		}
	}
	else
	{
	
	}
	
	return 1;
}

COMMAND:gotovehicle(playerid, params[])
{
    if(!IsPlayerAdmin(playerid))
    {
        return SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This command can only be used by RCON administrators.");
    }
    else
    {
        new file[60], vehicleID;
        if(sscanf(params, "i", vehicleID))
        {
            SendClientMessage(playerid, COLOR_ORANGE, "Usage: \"gotovehicle <owned id>\"");
        }
        else
        {
            new i = vehicleID;
            format(file, sizeof(file), "vehicles/vehicle_%i.ini", i);
    
            if(!fexist(file))
            {
                SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That vehicle ID does not exit!");
            }
            else
            {
				new Float:vehiclePositions[3];
				
				SetPlayerInterior(playerid, 0);
				SetPlayerVirtualWorld(playerid, 0);
				GetVehiclePos(vehicleCount[i], vehiclePositions[0], vehiclePositions[1], vehiclePositions[2]);
                SetPlayerPos(playerid, vehiclePositions[0], (vehiclePositions[1] + 2), (vehiclePositions[2] + 1));
				
                SendClientMessage(playerid,-1, "{6DD926}[SUCCESS] {FFFFFF}Teleported to vehicle.");
				new log[250];
				format(log, sizeof(log), "%s(%i) teleported to an owned vehicle", playerData[playerid][playerNamee], playerid);
				SendAdminText(playerid, log);
            }
        }
    }
    return 1;
}
