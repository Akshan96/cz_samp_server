Log(destinationFile[], stringToWrite[], bool:usedtimestamp = false)
{

	new
		logFile[32] = "saved/", date, month, year, hour, minute;
	getdate(date, month, year);
	gettime(hour, minute);
	strcat(logFile, destinationFile);

    if(!fexist(logFile))
    {
        new
			File:fileToCreate = fopen(logFile, io_write);

        fclose(fileToCreate);
    }

    new
		stringForLogging[512];

	if(usedtimestamp)
		format(stringForLogging, 512, "<font color='red'>%d/%d/%d (%d:%d) </font>%s<br/>", date, month, year, hour, minute, stringToWrite);
	else
		format(stringForLogging, 512, "%s<br/>", stringToWrite);

    new
		File:fileToAppend = fopen(logFile, io_append);

    fwrite(fileToAppend, stringForLogging);
    fclose(fileToAppend);

    return 1;
}

COMMAND:setint(playerid, params[])
{
	new id;
	if(!sscanf(params, "d", id))
		SetPlayerInterior(playerid, id);
	return 1;
}

COMMAND:setvw(playerid, params[])
{
	new id;
	if(!sscanf(params, "d", id))
		SetPlayerVirtualWorld(playerid, id);
	return 1;
}

COMMAND:savecar(playerid, params[])
{
	new pilihan[56];
	if(sscanf(params, "s[56]", pilihan))
	{
		SendClientMessage(playerid, -1, "Example command: /savecar <FBI/ARMY/POLICE/SECRET/CIVIL>");
	}
	else
	{
		if(IsPlayerInAnyVehicle(playerid))
		{
			new msg[512], Float:x, Float:y, Float:z, Float:a, vehicleid;
			vehicleid = GetPlayerVehicleID(playerid);
			GetVehiclePos(vehicleid, x, y, z);
			GetVehicleZAngle(vehicleid, a);
			if(!strcmp(pilihan, "FBI", true))
				format(msg, sizeof(msg), "{CLASS_FBI, %d, %f, %f, %f, %f, 0, 0, 120}", GetVehicleModel(vehicleid), x, y, z, a);
			else if(!strcmp(pilihan, "ARMY", true))
				format(msg, sizeof(msg), "{CLASS_ARMY, %d, %f, %f, %f, %f, 0, 0, 120}", GetVehicleModel(vehicleid), x, y, z, a);
			else if(!strcmp(pilihan, "POLICE", true))
				format(msg, sizeof(msg), "{CLASS_POLICE, %d, %f, %f, %f, %f, 0, 0, 120}", GetVehicleModel(vehicleid), x, y, z, a);
			else if(!strcmp(pilihan, "SECRET", true))
				format(msg, sizeof(msg), "{CLASS_SECRETSERVICE, %d, %f, %f, %f, %f, 0, 0, 120}", GetVehicleModel(vehicleid), x, y, z, a);
			else if(!strcmp(pilihan, "CIVIL", true))
				format(msg, sizeof(msg), "{CLASS_CIVILIAN, %d, %f, %f, %f, %f, 0, 0, 120}", GetVehicleModel(vehicleid), x, y, z, a);
			else
			{
				SendClientMessage(playerid, -1, "Example command: /savecar <FBI/ARMY/POLICE/SECRET>");
				return 1;
			}
			Log("vehicles.html", msg);
			SendClientMessage(playerid, -1, "Saved");
		}
		else
		{
			SendClientMessage(playerid, -1, "You must be on vehicle LOL");
		}
	}
	return 1;
}

COMMAND:createenter(playerid, params[])
{
	new mapicon;
	if(sscanf(params, "d", mapicon))
	{
		return 0;
	}
	else
	{
		new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
		SetPVarFloat(playerid, "nx", x);
		SetPVarFloat(playerid, "ny", y);
		SetPVarFloat(playerid, "nz", z);
		SetPVarInt(playerid, "mi", mapicon);
		SendClientMessage(playerid, -1, "Saved");
	}
	return 1;
}

COMMAND:createexit(playerid, params[])
{
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z);
	SetPVarInt(playerid, "sv", GetPlayerVirtualWorld(playerid));
	SetPVarInt(playerid, "si", GetPlayerInterior(playerid));
	SetPVarFloat(playerid, "ex", x);
	SetPVarFloat(playerid, "ey", y);
	SetPVarFloat(playerid, "ez", z);
	SendClientMessage(playerid, -1, "Saved");
	return 1;
}

COMMAND:savepos(playerid, params[])
{
	new nme[100];
	if(!sscanf(params, "s[100]", nme))
	{
		new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
		new msg[512];
		format(msg, sizeof(msg), "%f, %f, %f // %s", x, y, z, nme);
		Log("span.html", msg);
		SendClientMessage(playerid, -1, "Saved");
	}
	return 1;
}

COMMAND:createrob(playerid, params[])
{
	new high, nme[100];
	if(sscanf(params, "ds[100]", high, nme))
	{
		return 0;
	}
	else
	{
		new Float:x, Float:y, Float:z, msg[1024];
		GetPlayerPos(playerid, x, y, z);
		format(msg, sizeof(msg), "{43, {%f, %f, %f}, {%f, %f, %f}, {%f, %f, %f}, 1, 2000, %d, %d, %d, \"%s\", 0}", GetPVarFloat(playerid, "nx"), GetPVarFloat(playerid, "ny"), GetPVarFloat(playerid, "nz"), GetPVarFloat(playerid, "ex"), GetPVarFloat(playerid, "ey"), GetPVarFloat(playerid, "ez"), x, y, z, high, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid), nme);
		Log("robberyCP.html", msg);
		SendClientMessage(playerid, -1, "Robbery place has been created!");
		foreach(new i : Player)
			SetPlayerMapIcon(i, 1337, GetPVarFloat(playerid, "nx"), GetPVarFloat(playerid, "ny"), GetPVarFloat(playerid, "nz"), GetPVarInt(playerid, "mi"), 0, MAPICON_LOCAL); // Icon for prolaps
	}
	return 1;
}