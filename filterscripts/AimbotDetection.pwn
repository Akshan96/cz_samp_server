//Made by Kyance, assisted by Threshold do NOT remove credits.
//Version 4.0.0, fixed over 5 bugs since v1.0 BETA, and done over 10 improvements :p

//Previous update -> Fixed the aimbot giving out false results when a player is "surfing" a vehicle, AKA: Standing on a moving vehicle.
//Latest update -> Attempting to improve performance ..

#include <a_samp>
#include <zcmd>
#include <foreach>
#include <sscanf2>
#include <callbacks>

#define COLOR_NOTES 0x2894FFFF
#define COLOR_NOTES2 0xFF0000AA
#define DIALOG_SUSPECTLIST 123
#define GetPlayerLastShotVectors
#define BULLET_HIT_TYPE_PLAYER 1
#define PUB:%0(%1)	forward %0(%1); \
					public %0(%1)
//------------------------------ VARIABLES ---------------------------------------
new
	bool: DetectedForAimbot[ MAX_PLAYERS char ],
	bool: IsAFK[ MAX_PLAYERS char ],
	bool: CoolDown[ MAX_PLAYERS char ],
	TimesDetected[ MAX_PLAYERS ] = 0,
	ToggleCoolDown[ MAX_PLAYERS ]
;

#if defined FILTERSCRIPT


public OnFilterScriptInit()
{
	print("\n [abd] Aimbot Detection fs loaded\n [abd] Version: 4.0.0(DEBUG MODE)\n [abd] Created by: Kyance");
	return 1;
}
public OnFilterScriptExit()
{
	foreach(Player, i) ResetStats(i);
	print("\n [abd] Aimbot Detection fs unloaded\n [abd] Version: 4.0.0(DEBUG MODE)\n [abd] Created by: Kyance");
	return 1;
}
#endif
//------------------------------ CALLBACKS ----------------------------------
public OnPlayerPause(playerid)
{
	IsAFK{ playerid } = true;
	return 1;
}
public OnPlayerResume(playerid, time)
{
	IsAFK{ playerid } = false;
	return 1;
}
public OnPlayerConnect(playerid)
{
	ResetStats(playerid);
	return 1;
}
public OnPlayerDisconnect(playerid, reason)
{
	ResetStats(playerid);
	return 1;
}
public OnPlayerTakeDamage(playerid, issuerid, Float: amount, weaponid, bodypart)
{
    if(issuerid != INVALID_PLAYER_ID)
    {
		if(!CoolDown{ playerid } && ToggleCoolDown[issuerid]) CoolDown{ issuerid } = true, SetTimerEx("ResetCoolDown", 2500, false, "i", issuerid);
	}
	return 1;
}
public OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
{
	if(hittype == BULLET_HIT_TYPE_PLAYER && !IsPlayerNPC(hitid))
 	{
  		if(!IsAFK{ hitid } && !CoolDown{ playerid })
        {
        	new surf = GetPlayerSurfingVehicleID(playerid), tsurf = GetPlayerSurfingVehicleID(hitid);
			if(surf == INVALID_VEHICLE_ID && tsurf == INVALID_VEHICLE_ID && !IsPlayerInAnyVehicle(hitid))
			{
			    new
					Float:targetpkl = NetStats_PacketLossPercent(hitid),
					Float:playerpkl = NetStats_PacketLossPercent(playerid)
				;
			    if(targetpkl < 0.8 && playerpkl < 0.8)
			    {
				    new Float:fOriginX, Float:fOriginY, Float:fOriginZ, Float:fHitPosX, Float:fHitPosY, Float:fHitPosZ;
					GetPlayerLastShotVectors(playerid, fOriginX, fOriginY, fOriginZ, fHitPosX, fHitPosY, fHitPosZ);
					CheckForAimbot(playerid, fHitPosX, fHitPosY, fHitPosZ, hitid);
				}
				else printf("[abd] skipping '%s' and(or) '%s' due to packetloss being above 0.8", GetName(playerid), GetName(hitid));
			}
			else printf("[abd] skipping '%s' and(or) '%s' due to valid surf-vehicle/in-vehicle", GetName(playerid), GetName(hitid));
        }
        else printf("[abd] skipping '%s' and(or) '%s' due to target being afk/player having cooldown", GetName(playerid), GetName(hitid));
	}
    return 1;
}
//------------------------------ STOCKs and TIMERs ----------------------------------
stock CheckForAimbot(playerid, Float:fX, Float:fY, Float:fZ, attacked = INVALID_PLAYER_ID)
{
	if(attacked != INVALID_PLAYER_ID)
    {
   		if(!IsPlayerInRangeOfPoint(attacked, 3.0, fX, fY, fZ))
    	{
          	TimesDetected[playerid]++;
          	printf("ABD: %s(IP: %s) has received %d/10 aimbot warnings.", GetName(playerid), PlayerIP(playerid), TimesDetected[playerid]);
          	new string[110];
           	if(TimesDetected[playerid] >= 3 && TimesDetected[playerid] <= 5)
           	{
            	format(string, sizeof(string), "WARNING: %s(%d) is POSSIBLY using aimbot (%d warnings)", GetName(playerid), playerid, playerid, playerid, TimesDetected[playerid]);
                SendClientMessageToAll(COLOR_NOTES2, string), string = "\0";
				DetectedForAimbot{ playerid } = true;
            }
            else if(TimesDetected[playerid] >= 10)
            {
            	format(string, sizeof(string), "KICK: %s(%d) has been auto-kicked for receiving 10 aimbot warnings.", GetName(playerid), playerid);
             	SendClientMessageToAll(COLOR_NOTES2, string), string = "\0", Kick(playerid);
              	printf("ABD: %s(IP: %s) has been kicked for receiving 8 aimbot warnings.", GetName(playerid), PlayerIP(playerid));
            }
            string = "\0";
        }
	}
	else printf("[abd] error! 'attacked'(%d) was an invalid id!", attacked);
}
stock GetName(playerid)
{
	new pnameid[24];
	GetPlayerName(playerid,pnameid,sizeof(pnameid));
	return pnameid;
}
stock PlayerIP(playerid)
{
	new str[16];
	GetPlayerIp(playerid, str, sizeof(str));
	return str;
}
PUB:ResetCoolDown(playerid)
{
    CoolDown{ playerid } = false;
	SetTimerEx("ToggleCoolDownTimer", 3500, false, "i", playerid);
    return 1;
}
PUB:ToggleCoolDownTimer(playerid)
{
    ToggleCoolDown[playerid] = 1;
	return 1;
}

stock ResetStats(playerid)
{
	CoolDown{ playerid } = false, DetectedForAimbot{ playerid } = false, IsAFK{ playerid } = false;
	ToggleCoolDown[playerid] = 1, TimesDetected[playerid] = 0;
}
//------------------------------ COMMANDS ----------------------------------
CMD:suspects(playerid, params[]) {
	new count = 0, string1[48], string2[320];
	foreach(Player, i)
	{
		if(DetectedForAimbot{ i })
		{
		    count++;
		    format(string2, sizeof(string2), "%s\n{FC4949}%s{FFFFFF}({FC4949}%d{FFFFFF})", string2, GetName(i), i);
		}
	}
	format(string1, sizeof(string1), "{FC4949}%d {FFFFFF}suspects detected", count);
	
	if(count) ShowPlayerDialog(playerid, DIALOG_SUSPECTLIST, DIALOG_STYLE_LIST, string1, string2, "Close", "");
	else ShowPlayerDialog(playerid, DIALOG_SUSPECTLIST, DIALOG_STYLE_LIST, "0 suspects detected", "No aimboters have been detected.", "Close", "");
	string1 = "\0", string2 = "\0";
    return 1;
}

CMD:clearsuspects(playerid, params[]) {
	if(!IsPlayerAdmin(playerid)) return SendClientMessage(playerid, COLOR_NOTES2, "* You're not an admin!");
	foreach(Player, i) ResetStats(i);
	SendClientMessage(playerid, COLOR_NOTES, "* Suspect list successfully cleared!");
	return 1;
}
