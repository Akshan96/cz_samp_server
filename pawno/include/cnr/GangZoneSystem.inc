/*
					==================================
						Gang Zone System by s3rious
					==================================

	Script Version in first release: 2nd March 2012 Alpha
	Last Stable Version of Script: 11th January 2015 RC-3

	The contents of this file are subject to the Mozilla Public License
	Version 1.1 (the "License"); you may not use this file except in
	compliance with the License. You may obtain a copy of the License at
	http://www.mozilla.org/MPL/

	Software distributed under the License is distributed on an "AS IS"
	basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
	License for the specific language governing rights and limitations
	under the License.

	The Original Code is Include for San Andreas Multiplayer.

	The Initial Developer of the Original Code is Erik "s3rious" Kohút

	Portions created by "s3rious" are Copyright (C) 2014
	All Rights Reserved.

	There is no need to use s3Zone include. You need just this
	file as include and customize your gamemode. YOU DON' NEED put callback into
	your gamemode. I resolved this by y_hooks. (thanks for Abagail). You just
	need change/create team variable.
	
	I made this new version because i want improve it. Maybe it contain
	some bugs but this is the main reason why i posted it. I want your
	help to help me fix some bugs. I haven't tested it yet so much only
	some basic actions.
*/


//------------------------------------------------------------------------------
#include <a_samp>
#include <YSI\y_hooks>

#define foreach(%0,%1)  for(new %0=0;%0<%1;%0++) if (IsPlayerConnected(%0))

//----------------------------------
#define MAX_ALLOWED_ZONES       100

#define MIN_INVADERS            1           // Change how many invaders are required to start war
#define WAR_DURATION            10          // How long will take war (in seconds)

enum ZONE_DATA
{
	Float:Minx,
	Float:Miny,
	Float:Maxx,
	Float:Maxy,
	ZoneColor,
	ZoneTeam,
	ZoneID,
	
	Protectors,
	Invaders
}

enum PLAYER_DATA
{
	bool:Protector,
	bool:Invader
}

new PlayerData[MAX_PLAYERS][PLAYER_DATA];       // You can use your own
new ZoneData[MAX_ALLOWED_ZONES][ZONE_DATA];
new ZoneCount   =   1;

new bool:ActiveWar = false;
new gTeam[MAX_PLAYERS];                         // You can use your own

new OldZone[MAX_PLAYERS];
new Zone[MAX_PLAYERS];

new InvaderTeam;
new AttackZone;
new WarTimer;

//------------------------------
stock GetTeam(playerid)
{

	// Here type your variable where you store team id
	// for proper operation you should use some team var because zone id depends on it.
	// -----------------
	// example pData[playerid][Team] or gTeam[playerid]
	// name of variable doesn't matter but be sure you have created var for team

	return gTeam[playerid];
}

//------------------------------------------------------------------------------
hook OnGameModeInit()
{
    SetTimer("GZCore", 1000, true);

	return 1;
}

hook OnPlayerDeath(playerid, killerid, reason)
{
	OnPlayerLeaveWarZone(playerid);
	return 1;
}

hook OnPlayerConnect(playerid)
{
	for(new i=0;i<ZoneCount;i++)
	{
	     GangZoneShowForPlayer(playerid, ZoneData[i][ZoneID], ZoneData[i][ZoneColor]);
	}
	return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
	OnPlayerLeaveWarZone(playerid);
	return 1;
}

//------------------------------------------------------------------------------
forward GZCore();
public GZCore()
{
	foreach(i, MAX_PLAYERS)
	{
	    Zone[i] = GetPlayerZone(i);
		
		if (Zone[i] != OldZone[i])
		{
		    OldZone[i] = Zone[i];
	   		OnPlayerChangeZone(i, Zone[i]);
		}
	}
}

forward CreateZone(Float:MinX, Float:MinY, Float:MaxX, Float:MaxY, _ZoneTeam, _ZoneColor);
public CreateZone(Float:MinX, Float:MinY, Float:MaxX, Float:MaxY, _ZoneTeam, _ZoneColor)
{
	if (ZoneCount < MAX_ALLOWED_ZONES)
	{
		ZoneData[ZoneCount][ZoneID]   	=   GangZoneCreate(MinX, MinY, MaxX, MaxY);

		ZoneData[ZoneCount][Minx]       =   MinX;
		ZoneData[ZoneCount][Miny]       =   MinY;
		ZoneData[ZoneCount][Maxx]       =   MaxX;
		ZoneData[ZoneCount][Maxy]       =   MaxY;

		ZoneData[ZoneCount][ZoneColor]  =   _ZoneColor;
		ZoneData[ZoneCount][ZoneTeam]   =   _ZoneTeam;

	  	ZoneCount++;                    // id 0 means none gangzone.. id 1 is some zone etc....
	  	return 1;
	}
	else return printf("Number of allowed Zones has been exceeded! Max %d", MAX_ALLOWED_ZONES);
}

// This will start only when player change zone, not when is just still in the same zone
forward OnPlayerChangeZone(playerid, newzone);
public OnPlayerChangeZone(playerid, newzone)
{
	if (ActiveWar)
	{
	    if (newzone != AttackZone)
		{
		    OnPlayerLeaveWarZone(playerid);
		}
		else
		{
		    // What happend when some come during the war in warzone
		    // i will do this in next release
		}
	}
	else
	{
	    // he must be invader if its not his teamzone
	    if (GetPlayerZone(playerid) != 0)
	    {
      		if (IsPlayerInEnemyZone(playerid))
		    {
		        // Invader
		        ZoneData[newzone][Invaders]++;
		        PlayerData[playerid][Invader]   =   true;
		        
		        if (ZoneData[newzone][Invaders] == MIN_INVADERS)
				{
		            InvaderTeam 	= 	GetTeam(playerid);
	            	AttackZone  	=   newzone;            // AttackZone as global variable
	            	
		            StartWarZone();
		        }
		    }
		    else {
		        // Protector
		        ZoneData[newzone][Protectors]++;
		        PlayerData[playerid][Protector]   =   true;
		    }
		}
		else
		{
		}
	}
}

forward StartWarZone();
public StartWarZone()
{
	ActiveWar = true;
	SetFlashZone(ZoneData[AttackZone][ZoneID]);
	//--------------------

	//--------------------
	GameTextForAll("~r~YOU STARTED WAR!", 1000*4, 5);
	
	WarTimer = SetTimer("EndWarZone", 1000*WAR_DURATION, false);
}

forward EndWarZone();
public EndWarZone()
{
	ActiveWar = false;
	GangZoneStopFlashForAll(ZoneData[AttackZone][ZoneID]);

	// war is success only if all protectors are dead!!!
	if (ZoneData[AttackZone][Invaders] == 0)
	{
		GameTextForAll("~g~DEFENDED!", 1000*4, 5);
	}
	else
	{
	    ZoneData[AttackZone][ZoneTeam]     =   InvaderTeam;

	    GameTextForAll("~g~THIS HOOD IS YOURS", 1000*4, 5);

		GangZoneHideForAll(ZoneData[AttackZone][ZoneID]);
		ZoneData[AttackZone][ZoneColor]     =   GetZoneColor(InvaderTeam);
		GangZoneShowForAll(ZoneData[AttackZone][ZoneID], GetZoneColor(InvaderTeam));
	}

	foreach(i, MAX_PLAYERS)
	{
	    if (PlayerData[i][Protector]) 	PlayerData[i][Protector] 	=   false;
		if (PlayerData[i][Invader])		PlayerData[i][Invader]		=   false;
	}
	KillTimer(WarTimer);
}

forward OnPlayerLeaveWarZone(playerid);
public OnPlayerLeaveWarZone(playerid)
{
	// What happend when protector or invader leaves war zone
    if (PlayerData[playerid][Invader])
    {
	    // war ended because all invaders lefts or are dead
	    ZoneData[AttackZone][Invaders]--;
	    if (ZoneData[AttackZone][Invaders] == 0)
		{
			EndWarZone();
		}
	}
    if (PlayerData[playerid][Protector])
    {
        // protector
        GameTextForAll("~r~GO BACK TO WAR!", 1000*3, 5);
    }
}

//- FUNCTIONS ------------------------------------------------------------------
stock IsPlayerInEnemyZone(playerid)
{
	new zoneid = GetPlayerZone(playerid);
	if ((GetPlayerZone(playerid) != 0 && GetTeam(playerid) != ZoneData[zoneid][ZoneTeam])) return true;
	else return false;
}

stock IsPlayerInAnyZone(playerid)
{
	if (GetPlayerZone(playerid) == 0) return false;
	else return true;
}

// get current player zone id
stock GetPlayerZone(playerid)
{
	new Float:X, Float:Y, Float:Z;
	GetPlayerPos(playerid, X, Y, Z);

	for (new i=0;i<ZoneCount;i++)	{
		if(X >= ZoneData[i][Minx] && X <= ZoneData[i][Maxx] && Y >= ZoneData[i][Miny] && Y <= ZoneData[i][Maxy]) return i;
	}
	return 0;
}

stock GetZoneColor(teamid)
{
	for(new i=0;i<ZoneCount;i++) 	{
	    if (ZoneData[i][ZoneTeam] == teamid)	return ZoneData[i][ZoneColor];
	}
	return 0;
}

//------------------------------------------------------
stock SetFlashZone(zoneid)
{
	GangZoneFlashForAll(zoneid, 0xFF000096);
}
