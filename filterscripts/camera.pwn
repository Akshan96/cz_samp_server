// This is a comment
// uncomment the line below if you want to write a filterscript
//#define FILTERSCRIPT
#define MAX_PLAYERS								(500)

//where the player will spawn
#define player_x -1940.6138
#define player_y 149.7429
#define player_z 41.0000
#define player_angle 1.4989

//PLAYER CAMERA, THE ONE YOU CREATE SO YOU CAN SEE THE PLAYER
//note: for a better effect, let the camera be a few meters away from the player
#define camera_x -1940.5756
#define camera_y 154.3810
#define camera_z 41.0000

//ATTENTION; THESE ARE MILISECONDS
//untested, but it should work in theory. The smaller the value, the faster the camera.
#define moving_speed 10

//declaring stuff
//IMPORTANT: FOR THE CODE TO WORK, YOU MUST DEFINE THE ENUM BEFORE PlayerInfo
//just copy it like It's written here
enum pInfo
{
	bool:SpawnDance,
	Float:SpawnAngle,
	SpawnTimer
};

new PlayerInfo[MAX_PLAYERS][pInfo];

#include <a_samp>

#if defined FILTERSCRIPT

public OnFilterScriptInit()
{
	print("\n--------------------------------------");
	print("  ");
	print("--------------------------------------\n");
	return 1;
}

public OnFilterScriptExit()
{
	return 1;
}

#else

main()
{
	print("\n----------------------------------");
	print("  ");
	print("----------------------------------\n");
}

#endif

public OnGameModeInit()
{

	return 1;
}

public OnGameModeExit()
{
	return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
 	SetPlayerPos(playerid, player_x,player_y,player_z);
	SetPlayerFacingAngle(playerid, player_angle);
 	SetPlayerCameraPos(playerid, camera_x,camera_y,camera_z);
	SetPlayerCameraLookAt(playerid, player_x,player_y,player_z);
	//making sure the timer gets executed only once, so the camera doesn't go to fast
	if (PlayerInfo[playerid][SpawnDance]) PlayerInfo[playerid][SpawnTimer] = SetTimerEx("MoveCamera", moving_speed, true, "i", playerid);
	PlayerInfo[playerid][SpawnDance] = false; //preventing the timer to execute again
	return 1;
}

//something I found in vactions.pwn
PreloadAnimLib(playerid, animlib[]) ApplyAnimation(playerid,animlib,"null",0.0,0,0,0,0,0);

public OnPlayerConnect(playerid)
{	//loading the animation libraries
    PreloadAnimLib(playerid,"BOMBER");
  	PreloadAnimLib(playerid,"RAPPING");
  	PreloadAnimLib(playerid,"SHOP");
  	PreloadAnimLib(playerid,"BEACH");
  	PreloadAnimLib(playerid,"SMOKING");
  	PreloadAnimLib(playerid,"FOOD");
  	PreloadAnimLib(playerid,"ON_LOOKERS");
  	PreloadAnimLib(playerid,"DEALER");
	PreloadAnimLib(playerid,"CRACK");
	PreloadAnimLib(playerid,"CARRY");
	PreloadAnimLib(playerid,"COP_AMBIENT");
	PreloadAnimLib(playerid,"PARK");
	PreloadAnimLib(playerid,"INT_HOUSE");
	PreloadAnimLib(playerid,"FOOD");
	PreloadAnimLib(playerid,"PED");
	//so the timer can be executed again
	PlayerInfo[playerid][SpawnDance] = true;
    ApplyAnimation(playerid,"DANCING","DNCE_M_B",4.0,1,0,0,0,-1); //preventing a bug for the animation not being applied the first time OnPlayerRequestClass is called
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
  KillTimer( PlayerInfo[playerid][SpawnTimer] );
  return 1;
}

public OnPlayerSpawn(playerid)
{
	PlayerInfo[playerid][SpawnAngle] = 0.0; //so when you leave and another player comes, the camera will start from start
	PlayerInfo[playerid][SpawnDance] = true; //to not execute to much timers
	KillTimer( PlayerInfo[playerid][SpawnTimer] ); //to kill it, since its useless now
	PlayerPlaySound(playerid, 1186, 0.0, 0.0, 0.0); // (blank sound) to shut the music up
    SetCameraBehindPlayer(playerid); //to prevent some bugs
	return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
	return 1;
}

public OnVehicleSpawn(vehicleid)
{
	return 1;
}

public OnVehicleDeath(vehicleid, killerid)
{
	return 1;
}

public OnPlayerText(playerid, text[])
{
	return 1;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
	if (strcmp("/mycommand", cmdtext, true, 10) == 0)
	{
		// Do something here
		return 1;
	}
	return 0;
}

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	return 1;
}

public OnPlayerExitVehicle(playerid, vehicleid)
{
	return 1;
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
	return 1;
}

public OnPlayerEnterCheckpoint(playerid)
{
	return 1;
}

public OnPlayerLeaveCheckpoint(playerid)
{
	return 1;
}

public OnPlayerEnterRaceCheckpoint(playerid)
{
	return 1;
}

public OnPlayerLeaveRaceCheckpoint(playerid)
{
	return 1;
}

public OnRconCommand(cmd[])
{
	return 1;
}

public OnPlayerRequestSpawn(playerid)
{
	return 1;
}

public OnObjectMoved(objectid)
{
	return 1;
}

public OnPlayerObjectMoved(playerid, objectid)
{
	return 1;
}

public OnPlayerPickUpPickup(playerid, pickupid)
{
	return 1;
}

public OnVehicleMod(playerid, vehicleid, componentid)
{
	return 1;
}

public OnVehiclePaintjob(playerid, vehicleid, paintjobid)
{
	return 1;
}

public OnVehicleRespray(playerid, vehicleid, color1, color2)
{
	return 1;
}

public OnPlayerSelectedMenuRow(playerid, row)
{
	return 1;
}

public OnPlayerExitedMenu(playerid)
{
	return 1;
}

public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
{
	return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	return 1;
}

public OnRconLoginAttempt(ip[], password[], success)
{
	return 1;
}

public OnPlayerUpdate(playerid)
{
	return 1;
}

public OnPlayerStreamIn(playerid, forplayerid)
{
	return 1;
}

public OnPlayerStreamOut(playerid, forplayerid)
{
	return 1;
}

public OnVehicleStreamIn(vehicleid, forplayerid)
{
	return 1;
}

public OnVehicleStreamOut(vehicleid, forplayerid)
{
	return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	return 1;
}

public OnPlayerClickPlayer(playerid, clickedplayerid, source)
{
	return 1;
}

//The business part of the code
forward MoveCamera(playerid);
public MoveCamera(playerid)
{
	//this is called trigonometry. It makes the camera spin
	//you can experiment with this line. Just change the values 2, 10 and 3 to make different effects
  SetPlayerCameraPos(playerid, player_x - 2 * floatsin(-PlayerInfo[playerid][SpawnAngle], degrees), player_y - 10 * floatcos(-PlayerInfo[playerid][SpawnAngle], degrees), player_z + 3);
  SetPlayerCameraLookAt(playerid, -1940.6138, 149.7429, 41.0000 + 0.0);

	//changing the angle a little
  PlayerInfo[playerid][SpawnAngle] += 0.3;

  if (PlayerInfo[playerid][SpawnAngle] >= 360.0)
    PlayerInfo[playerid][SpawnAngle] = 0.0;

}
