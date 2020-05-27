#include <a_samp>
#include <a_http>
#include <required/regex>
#include <cidr>

#define BANLIST         "cidr-banlist.txt"

#define KickPlayer(%0)	SetTimerEx("KickTimer", 600, 0, "i", %0)

#define COLOR_RED   	0xAA3333AA
#define COLOR_YELLOW    0xFFFF00AA
#define COLOR_GREEN		0x33AA33AA


public OnFilterScriptInit()
{
	print("\n######################################");
	print("#				     #");
	print("# Filerscript 'CIDRBAN' by someone Loaded");
	print("#				     #");
	print("######################################\n");
	return true;
}


public OnPlayerConnect(playerid)
{
	new
	    sPlayerName[MAX_PLAYER_NAME],
	    sPlayerIP[20];

	GetPlayerName(playerid, sPlayerName, sizeof(sPlayerName));
	GetPlayerIp(playerid, sPlayerIP, sizeof(sPlayerIP));

	if(IsRangeBanned(sPlayerIP))
	{
	    SendClientMessage(playerid, COLOR_RED, "{B7B7B7}[SERVER] {FFFFFF}VPN/Proxy detected, you must join with your real IP!");
		printf("%s (%s) is range banned from the server.", sPlayerName, sPlayerIP);
	    KickPlayer(playerid);
	}
	return true;
}


public OnPlayerCommandText(playerid, cmdtext[])
{
	new
	    sMsg[128],
	    sCmd[128],
	    sCIDRRange[32],
	    sStartIP[32],
	    sEndIP[32],
	    iIndex;

    sCmd = strtok(cmdtext, iIndex);

	if(strcmp(sCmd, "/bancidr", true) == 0)
	{
	    if(!IsPlayerAdmin(playerid))
	        return SendClientMessage(playerid, COLOR_RED, "{B7B7B7}[SERVER] {FFFFFF}You don't have permission to use this command!");

        sCIDRRange = strtok(cmdtext, iIndex);
		if(!strlen(sCIDRRange))
		    return SendClientMessage(playerid, COLOR_YELLOW, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"bancidr <cidr_range>\"");

		if(!IsValidCIDR(sCIDRRange))
		    return SendClientMessage(playerid, COLOR_RED, "{B7B7B7}[SERVER] {FFFFFF}You have entered an invalid CIDR_Range.");

		format(sMsg, sizeof(sMsg), "{B7B7B7}[RCON] {FFFFFF}The range %s has been banned successfully.", sCIDRRange);
		SendClientMessage(playerid, COLOR_GREEN, sMsg);

        BanCIDRRange(sCIDRRange);
        BanCurrentPlayersInRange(sCIDRRange);
        
		return true;
	}

	if(strcmp(sCmd, "/getcidr", true) == 0)
	{
	    if(!IsPlayerAdmin(playerid))
	        return SendClientMessage(playerid, COLOR_RED, "{B7B7B7}[SERVER] {FFFFFF}You don't have permission to use this command!");

        sStartIP = strtok(cmdtext, iIndex);
        sEndIP = strtok(cmdtext, iIndex);
		if(!strlen(sStartIP) || !strlen(sEndIP))
		    return SendClientMessage(playerid, COLOR_YELLOW, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"getcidr <start_ip> <end_ip>\" - EXAMPLE: /getcidr 192.168.1.0 192.168.1.42");

		if(!IsValidIP(sStartIP) || !IsValidIP(sEndIP))
		    return SendClientMessage(playerid, COLOR_RED, "{B7B7B7}[SERVER] {FFFFFF}You have entered an invalid CIDR_IP.");

		format(sMsg, sizeof(sMsg), "rafael.keramid.as/samp/cidrcalc.php?startip=%s&endip=%s", sStartIP, sEndIP);
		HTTP(playerid, HTTP_GET, sMsg, "", "ShowCIDRRange");
		
		return true;
	}
	return false;
}

strtok(const string[], &index)
{
	new length = strlen(string);
	while ((index < length) && (string[index] <= ' '))
	{
		index++;
	}

	new offset = index;
	new result[20];
	while ((index < length) && (string[index] > ' ') && ((index - offset) < (sizeof(result) - 1)))
	{
		result[index - offset] = string[index];
		index++;
	}
	result[index - offset] = EOS;
	return result;
}

stock IsValidCIDR(const sCIDR[])
{
	static
	    RegEx:rCIDR;

	if(!rCIDR)
	    rCIDR = regex_build("(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?).(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?).(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?).(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)(/(3[012]|[12]?[0-9]))");

	return regex_match_exid(sCIDR, rCIDR);
}

stock IsValidIP(const sIP[])
{
	static
	    RegEx:rIP;

	if(!rIP)
	    rIP = regex_build("(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?).(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?).(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?).(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)");

	return regex_match_exid(sIP, rIP);
}

stock IsRangeBanned(sClientIP[]) {
	new
    	bool:bBanned = false,
    	sBanCIDR[24],
		File:fBanList = fopen(BANLIST, io_readwrite);

	while(fread(fBanList, sBanCIDR))
	{
		RemoveNewLine(sBanCIDR);
		if(IsValidCIDR(sBanCIDR))
			if(cidr_match(sClientIP, sBanCIDR))
				bBanned = true;
	}

	fclose(fBanList);
    return bBanned;
}

stock BanCIDRRange(sCIDR[])
{
    new
        sBanCIDR[24],
     	File:fBanList = fopen(BANLIST, io_append);

    if(fBanList)
	{
 		format(sBanCIDR, sizeof(sBanCIDR), "%s\r\n", sCIDR);
   		fwrite(fBanList, sBanCIDR);
   		fclose(fBanList);
	}
}

stock BanCurrentPlayersInRange(sCIDR[])
{
	new
	    sPlayerIP[20];

	for(new i = 0; i < MAX_PLAYERS; i++)
	{
	    if(IsPlayerConnected(i))
	    {
	        GetPlayerIp(i, sPlayerIP, sizeof(sPlayerIP));
	        if(cidr_match(sPlayerIP, sCIDR))
	        {
	            SendClientMessage(i, COLOR_RED, "You have been range banned from this server.");
	            KickPlayer(i);
	        }
	    }
	}
}

stock RangeToCIDR(sStartIP[], sEndIP[])
{
	new
	    iStartIP = 0;
}

stock RemoveNewLine(sString[])
{
    new
		i = 0;

    while(sString[i] != 0)
	{
        if(sString[i] == '\n' || sString[i] == '\r')
            sString[i] = 0;

        else
            i++;
    }
}

forward ShowCIDRRange(index, response_code, data[]);
public ShowCIDRRange(index, response_code, data[])
{
    new
        sBuffer[128];

    if(response_code == 200)
    {
        format(sBuffer, sizeof(sBuffer), "CIDR Range(s) : %s", data);
        SendClientMessage(index, COLOR_GREEN, sBuffer);
    }
}

forward KickTimer(playerid);
public KickTimer(playerid)
{
	Kick(playerid);
}
