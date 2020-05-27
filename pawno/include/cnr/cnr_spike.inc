#define MAX_SPIKE	10

enum spInfo
{
	spCreated,
    Float:spX,
    Float:spY,
    Float:spZ,
    spObject,
	Text3D:spLabel
}

new Spikes[MAX_SPIKE][spInfo];

stock DeleteClosestSpikes(playerid)
{
    for(new i = 0; i < sizeof(Spikes); i++)
  	{
  	    if(IsPlayerInRangeOfPoint(playerid, 2.0, Spikes[i][spX], Spikes[i][spY], Spikes[i][spZ]))
        {
  	        if(Spikes[i][spCreated] == 1)
            {
                Spikes[i][spCreated] = 0;
				Spikes[i][spX] = 0.0;
				Spikes[i][spY] = 0.0;
				Spikes[i][spZ] = 0.0;
				DestroyDynamicObject(Spikes[i][spObject]);
				Delete3DTextLabel(Spikes[i][spLabel]);
                return 1;
  	        }
  	    }
  	}
    return 0;
}

stock CreateSpike(Float:x,Float:y,Float:z,Float:Angle,playerid)
{
	new bool:found = false;
    for(new i = 0; i < sizeof(Spikes); i++)
  	{
  	    if(Spikes[i][spCreated] == 0)
  	    {
			new creatorString[200];
			found = true;
            Spikes[i][spCreated]=1;
            Spikes[i][spX]=x;
            Spikes[i][spY]=y;
            Spikes[i][spZ]=z-0.7;
			format(creatorString, sizeof(creatorString), "{FF0000}[SPIKE]\n{FFFFFF}Placed By: {58D3F7}%s", playerData[playerid][playerNamee]);
			Spikes[i][spLabel] = Create3DTextLabel(creatorString, 0xFF0000FF, x, y, z, 25.0, 0);
            Spikes[i][spObject] = CreateDynamicObject(2899, x, y, z - 1.3, 0, 0, Angle);
			SendClientMessage(playerid, COLOR_WHITE, "{3E7EFF}[SPIKE] {FFFFFF}You placed a spike. To remove it, type /delsp while standing near it.");
	        return 1;
  	    }
  	}
	
	if(!found)
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Maximum number of spikes created. /ask an admin to remove some.");
  	return 0;
}

COMMAND:rasp(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 1)
		{
			for(new i = 0; i < sizeof(Spikes); i++)
			{
				Spikes[i][spCreated] = 0;
				Spikes[i][spX] = 0.0;
				Spikes[i][spY] = 0.0;
				Spikes[i][spZ] = 0.0;
				DestroyDynamicObject(Spikes[i][spObject]);
				Delete3DTextLabel(Spikes[i][spLabel]);		
			}			
			
			SendClientMessageToAll(COLOR_WHITE, "{A9C4E4}An administrator has removed all spikes.");	

			new log[250];
			format(log, sizeof(log), "%s(%i) removed all spikes.", playerData[playerid][playerNamee], playerid);
			SendAdminText(playerid, log);	
		}
	}
	return 1;
}

COMMAND:placesp(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
  	    if(playerData[playerid][playerClass] == CLASS_FBI || playerData[playerid][playerClass] == CLASS_SECRETSERVICE)
  	    {
			if (GetPlayerVirtualWorld(playerid) < 1)
			{
				new Float:plocx, Float:plocy, Float:plocz, Float:ploca;
				GetPlayerPos(playerid, plocx, plocy, plocz);
				GetPlayerFacingAngle(playerid, ploca);
				
				CreateSpike(plocx, plocy, plocz + 0.6, ploca, playerid);
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Road blocks can only be placed out doors.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This command can only be used by the FBI or Secret Service class!");
		}
	}
	
	return 1;
}

COMMAND:delsp(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
  	    if(playerData[playerid][playerClass] == CLASS_FBI || playerData[playerid][playerClass] == CLASS_SECRETSERVICE)
  	    {
			DeleteClosestSpikes(playerid);
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This command can only be used by the FBI or Secret Service class!");
		}
	}	
	
	return 1;
}