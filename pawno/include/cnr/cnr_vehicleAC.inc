#define CHEAT_VEHICLETP_WARNINGS    3
#define CHEAT_VEHICLETP_DESYNCTIME  1000
#define CHEAT_VEHICLETP_WARNINGTIME 30

enum a_Info
{
    CHEAT_CURRENTVEH,
    CHEAT_CURRENTVEHSEAT,
    CHEAT_VEHICLETP,
    CHEAT_VEHICLETPTIME,
    CHEAT_VEHICLETPWARNINGTIME
}
new aAntiCheat[MAX_PLAYERS][a_Info];

/*
    - When a player connects, reset his information. (Might want to use your own function, or copy it)
*/
forward ac_OnPlayerConnect(playerid);
public ac_OnPlayerConnect(playerid)
{
    aAntiCheat[playerid][CHEAT_CURRENTVEH] = -1;
    aAntiCheat[playerid][CHEAT_CURRENTVEHSEAT] = -1;
    aAntiCheat[playerid][CHEAT_VEHICLETP] = 0;
    aAntiCheat[playerid][CHEAT_VEHICLETPTIME] = 0;
    aAntiCheat[playerid][CHEAT_VEHICLETPWARNINGTIME] = 0;
    return 1;
}

/*
    - When a player wants to enter a vehicle, allow it.
*/
forward ac_OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
public ac_OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    aAntiCheat[playerid][CHEAT_CURRENTVEH] = vehicleid;
    if(ispassenger) aAntiCheat[playerid][CHEAT_CURRENTVEHSEAT] = 1;
    else aAntiCheat[playerid][CHEAT_CURRENTVEHSEAT] = 0;
    return 1;
}

/*
    - Check at every data sent to the server if anything suspicious happens. If so; don't sync it.
*/
forward ac_OnPlayerUpdate(playerid);
public ac_OnPlayerUpdate(playerid)
{
    if(IsPlayerNPC(playerid)) return 1;

    new bool:AllowUpdate = true;
    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
    {
        if(GetPlayerVehicleID(playerid) != aAntiCheat[playerid][CHEAT_CURRENTVEH])
        {
            /*
                - Possible hacker found. Disable syncing and remove him from his vehicle.
            */
            AllowUpdate = false;

            aAntiCheat[playerid][CHEAT_CURRENTVEH] = -1;
            aAntiCheat[playerid][CHEAT_VEHICLETP]++;
                
            aAntiCheat[playerid][CHEAT_VEHICLETPTIME] = GetTickCount() + CHEAT_VEHICLETP_DESYNCTIME;

            new Float:x, Float:y, Float:z;
            GetPlayerPos(playerid, x, y, z);
            SetPlayerPos(playerid, x, y, z);

            new output_str[128];
            format(output_str, sizeof(output_str), "PlayerID %d gets a warning - Reason: Might use car warp", playerid);
            //SendClientMessageToAll(-1, output_str);
            
            /*
                - If it happens more than CHEAT_VEHICLETP_WARNINGS, ban him and cancel OnPlayerUpdate.
            */
			if (serverInfo[kickWarp])
			{
				if(aAntiCheat[playerid][CHEAT_VEHICLETP] > CHEAT_VEHICLETP_WARNINGS)
				{
					if (!playerData[playerid][playerBeenBanned])
					{
						playerData[playerid][playerBeenBanned] = true;
						
						new administratorAlert[250];
						format(administratorAlert, sizeof(administratorAlert), "{C73E3E}[CHEAT-DETECTION] {FFFFFF}%s(%i) has been automatically kicked for car warping.", playerData[playerid][playerNamee], playerid);
						adminchat(COLOR_WHITE, administratorAlert);	
						
						new loggingString[256];
						format(loggingString, sizeof(loggingString), "%s was kicked for car warping", playerData[playerid][playerNamee]);
						writeInLog("cheatLog.html", loggingString);
						
						playerData[playerid][playerBeenBanned] = true;
						KickWithMessage(playerid, "[KICKED] You have been kicked for car warping.");	
					}
				}
			}
        }
        else if(aAntiCheat[playerid][CHEAT_VEHICLETPTIME] > 0)
        {
            /*
                - Sync the player after desyncing the player to others for CHEAT_VEHICLETP_DESYNCTIME.
            */
            if(GetTickCount() > aAntiCheat[playerid][CHEAT_VEHICLETPTIME]) aAntiCheat[playerid][CHEAT_VEHICLETPTIME] = 0;
            else AllowUpdate = false;
        }
    }

    if(aAntiCheat[playerid][CHEAT_VEHICLETP] > 0 && gettime() > aAntiCheat[playerid][CHEAT_VEHICLETPWARNINGTIME])
    {
        aAntiCheat[playerid][CHEAT_VEHICLETP]--;
        aAntiCheat[playerid][CHEAT_VEHICLETPWARNINGTIME] = gettime() + CHEAT_VEHICLETP_WARNINGTIME;
    }

    return AllowUpdate;
}

forward ac_OnPlayerStateChange(playerid, newstate, oldstate);
public ac_OnPlayerStateChange(playerid, newstate, oldstate)
{
    /*
        - If the player starts driving, desync him for CHEAT_VEHICLETP_DESYNCTIME. ...
        ... If the player is on-foot again, reset the variables.
    */
    if(newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER)
    {
        aAntiCheat[playerid][CHEAT_VEHICLETPTIME] = GetTickCount() + CHEAT_VEHICLETP_DESYNCTIME;
    }
    else if(newstate == PLAYER_STATE_ONFOOT)
    {
        aAntiCheat[playerid][CHEAT_CURRENTVEH] = -1;
        aAntiCheat[playerid][CHEAT_CURRENTVEHSEAT] = -1;
        aAntiCheat[playerid][CHEAT_VEHICLETPTIME] = 0;
    }
    return 1;
}

/*
    - Tell the anti-cheat that the server puts the player in the vehicle, and does not need a check.
*/
stock ac_PutPlayerInVehicle(playerid, vehicleid, seatid)
{
    aAntiCheat[playerid][CHEAT_CURRENTVEH] = vehicleid;
    aAntiCheat[playerid][CHEAT_CURRENTVEHSEAT] = seatid;
    return PutPlayerInVehicle(playerid, vehicleid, seatid);
}