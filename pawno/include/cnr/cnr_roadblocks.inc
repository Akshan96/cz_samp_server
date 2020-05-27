#define MAX_ROADBLOCKS 10
 
enum rInfo
{
    sCreated,
    Float:sX,
    Float:sY,
    Float:sZ,
    sObject,
	copid,
	Text3D:rbLabel
};

new Roadblocks[MAX_ROADBLOCKS][rInfo];

COMMAND:rarb(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerLevel] >= 1)
		{
			for(new i = 0; i < sizeof(Roadblocks); i++)
			{
				Roadblocks[i][sCreated] = 0;
				Roadblocks[i][sX] = 0.0;
				Roadblocks[i][sY] = 0.0;
				Roadblocks[i][sZ] = 0.0;
				DestroyDynamicObject(Roadblocks[i][sObject]);
				Delete3DTextLabel(Roadblocks[i][rbLabel]);		
			}			
			
			SendClientMessageToAll(COLOR_WHITE, "{A9C4E4}An administrator has removed all road blocks.");	

			new log[250];
			format(log, sizeof(log), "%s(%i) removed all road blocks.", playerData[playerid][playerNamee], playerid);
			SendAdminText(playerid, log);	
		}
	}
	
	return 1;
}

COMMAND:placerb(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
  	    if(playerData[playerid][playerClass] == CLASS_FBI || playerData[playerid][playerLevel] == 6)
  	    {
			if (GetPlayerVirtualWorld(playerid) < 1)
			{
				new Float:plocx, Float:plocy, Float:plocz, Float:ploca;
				GetPlayerPos(playerid, plocx, plocy, plocz);
				GetPlayerFacingAngle(playerid, ploca);
				
				CreateRoadblock(978, plocx, plocy, plocz + 0.6, ploca, playerid);
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Road blocks can only be placed out doors.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This command can only be used by the FBI class!");
		}
	}
	
	return 1;
}

COMMAND:delrb(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
  	    if(playerData[playerid][playerClass] == CLASS_FBI || playerData[playerid][playerLevel] == 6)
  	    {
			DeleteClosestRoadblock(playerid);
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This command can only be used by the FBI class!");
		}
	}	
	
	return 1;
}

stock CreateRoadblock(Object,Float:x,Float:y,Float:z,Float:Angle, playerid)
{
	new count = 0;
    for(new i = 0; i < sizeof(Roadblocks); i++)
	{
		if(Roadblocks[i][sCreated] == 0)
		{
			new creatorString[200];
			
			Roadblocks[i][sCreated] = 1;
			Roadblocks[i][sX] = x;
			Roadblocks[i][sY] = y;
			Roadblocks[i][sZ] = z - 0.7;
			Roadblocks[i][copid] = playerid;
			Roadblocks[i][sObject] = CreateDynamicObject(Object, x, y, z - 0.9, 0, 0, Angle);
			
			format(creatorString, sizeof(creatorString), "{FFFFFF}Placed By: {58D3F7}%s", playerData[playerid][playerNamee]);
			Roadblocks[i][rbLabel] = Create3DTextLabel(creatorString, 0xFF0000FF, x, y, z, 25.0, 0);
			
			SendClientMessage(playerid, COLOR_WHITE, "{3E7EFF}[ROADBLOCK] {FFFFFF}You placed a roadblock. To remove it, type /delrb while standing near it.");
			
			count++;
			return 1;
		}
	}
	
	if (!count)
	{
		SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Maximum number of roadblocks created. /ask an admin to remove some.");
	}
	
	return 0;
}
 
stock DeleteAllRoadblocks(playerid)
{
    for(new i = 0; i < sizeof(Roadblocks); i++)
	{
		if(IsPlayerInRangeOfPoint(playerid, 100, Roadblocks[i][sX], Roadblocks[i][sY], Roadblocks[i][sZ]))
		{
			if(Roadblocks[i][sCreated] == 1)
			{
				Roadblocks[i][sCreated] = 0;
				Roadblocks[i][sX] = 0.0;
				Roadblocks[i][sY] = 0.0;
				Roadblocks[i][sZ] = 0.0;
				DestroyDynamicObject(Roadblocks[i][sObject]);
				Delete3DTextLabel(Roadblocks[i][rbLabel]);
			}
		}
	}
	
    return 0;
}
 
stock DeleteClosestRoadblock(playerid)
{
    for(new i = 0; i < sizeof(Roadblocks); i++)
	{
		if(IsPlayerInRangeOfPoint(playerid, 5.0, Roadblocks[i][sX], Roadblocks[i][sY], Roadblocks[i][sZ]))
		{
			if(Roadblocks[i][sCreated] == 1)
			{
				Roadblocks[i][sCreated] = 0;
				Roadblocks[i][sX] = 0.0;
				Roadblocks[i][sY] = 0.0;
				Roadblocks[i][sZ] = 0.0;
				DestroyDynamicObject(Roadblocks[i][sObject]);
				Delete3DTextLabel(Roadblocks[i][rbLabel]);
				
				SendClientMessage(playerid, COLOR_WHITE, "{3E7EFF}[ROADBLOCK] {FFFFFF}You removed a roadblock.");
				
				return 1;
			}
		}
	}
		
    return 0;
}

stock removePlayerRoadblocks(playerid)
{
    for(new i = 0; i < sizeof(Roadblocks); i++)
	{
		if(Roadblocks[i][copid] == playerid)
		{
			Roadblocks[i][sCreated] = 0;
			Roadblocks[i][sX] = 0.0;
			Roadblocks[i][sY] = 0.0;
			Roadblocks[i][sZ] = 0.0;
			DestroyDynamicObject(Roadblocks[i][sObject]);
			Delete3DTextLabel(Roadblocks[i][rbLabel]);
			
			return 1;
		}
		else
		{
			continue;
		}
	}	
	
	return 0;
}
