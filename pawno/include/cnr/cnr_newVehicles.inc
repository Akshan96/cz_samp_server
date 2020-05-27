#define DEFAULT_OWNER "CNR-ADMIN"
#define DEFAULT_PRICE 250000
#define DEFAULT_VEHICLEPLATE "stif boss"

enum vInfo
{
	vehicleID,
	vehicleOwner[24],
	vehicleModel,
	vehiclePrice,
	Float:vehiclePositionX,
	Float:vehiclePositionY,
	Float:vehiclePositionZ,
	Float:vehiclePositionA
	
	//vehiclePlate[32],
	//vehicleColour1,
	//vehicleColour2
}

new vehicleInfo[][vInfo];

forward LoadVehicle();
public LoadVehicle()
{
    new loadingQuery[256], temporaryString[5], thisVehiclesID;
	
	format(loadingQuery, sizeof(loadingQuery), "SELECT * FROM `vehicles`");
    mysql_query(loadingQuery);
    mysql_store_result();

	while(mysql_retrieve_row())
	{
	
		mysql_fetch_field_row(temporaryString, "id"); thisVehiclesID = strval(temporaryString);
		    
		new query[400], row[128], field[8][24];

		format(query, sizeof(query), "SELECT * FROM `vehicles` WHERE `id` = '%i'", thisVehiclesID);
		mysql_query(query);
		mysql_store_result();
		mysql_fetch_row_format(row, "|");
		explode(row, field, "|");
		mysql_free_result();
		
		format(vehicleInfo[thisVehiclesID][vehicleOwner],24, "%s", field[1]);
		
		vehicleInfo[thisVehiclesID][vehicleModel] = strval(field[2]);
		vehicleInfo[thisVehiclesID][vehiclePrice] = strval(field[3]);
		vehicleInfo[thisVehiclesID][vehiclePositionX] = strval(field[4]);
		vehicleInfo[thisVehiclesID][vehiclePositionY] = strval(field[5]);
		vehicleInfo[thisVehiclesID][vehiclePositionZ] = strval(field[6]);
		vehicleInfo[thisVehiclesID][vehiclePositionA] = strval(field[7]);

		new Color1 = random(126); 
		new Color2 = random(126);

		vehicleInfo[thisVehiclesID][vehicleID] = CreateVehicle(vehicleInfo[thisVehiclesID][vehicleModel], vehicleInfo[thisVehiclesID][vehiclePositionX], vehicleInfo[thisVehiclesID][vehiclePositionY], vehicleInfo[thisVehiclesID][vehiclePositionZ], vehicleInfo[thisVehiclesID][vehiclePositionA], Color1, Color2, 60);
		SetVehicleNumberPlate(vehicleInfo[thisVehiclesID][vehicleID], DEFAULT_VEHICLEPLATE);
	}
	
	mysql_free_result();
}

COMMAND:createvehicle2(playerid, params[])
{
    new vehicleModel_a, creationQuery[256], Float:playersInformation[4], playersName_a[24];
			
	if(!sscanf(params, "i", vehicleModel_a))
	{
		GetPlayerPos(playerid, playersInformation[0], playersInformation[1], playersInformation[2]);
		GetPlayerFacingAngle(playerid, playersInformation[3]);
		GetPlayerName(playerid, playersName_a, sizeof(playersName_a));
		
		format(creationQuery, sizeof(creationQuery), "INSERT INTO `vehicles` (id, owner, model, price, x, y, z, a) VALUES (NULL, '%s', %d, %d, %f, %f, %f, %f);", playersName_a, vehicleModel_a, DEFAULT_PRICE, playersInformation[0], playersInformation[1], playersInformation[2], playersInformation[3]);
		mysql_query(creationQuery);
		SendClientMessage(playerid, -1, creationQuery);
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: /createvehicle [MODEL_ID]");
	}
	
	return 1;
}

COMMAND:showmetheprizes(playerid, params[])
{
	new vehicleID_a;
	if(!sscanf(params, "i", vehicleID_a))
	{
		for(new i = 0; i < sizeof(vehicleInfo); i++)
		{
			new mmmmmssg[128];
			format(mmmmmssg, 128, "%i ---- %i ----- %i", vehicleID_a, vehicleInfo[i][vehicleID], sizeof(vehicleInfo[]));
			SendClientMessage(playerid, -1, mmmmmssg);
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: /showmetheprizes [VEHICLE_ID]");
	}
	
	return 1;
}

COMMAND:lvs(playerid, params[])
{
	new test[200];
    format(test, sizeof(test), "Test: %s", vehicleInfo[5][vehicleOwner]);
    SendClientMessage(playerid, COLOR_WHITE, test);
	
	return 1;
}