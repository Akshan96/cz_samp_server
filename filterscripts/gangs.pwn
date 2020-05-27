#include <a_samp>
#include <zcmd>

#define COLOR_LIGHTBLUE 0x33CCFFAA
#define COLOR_RED 0xAA3333AA
#define COLOR_GREY 0xAFAFAFAA
#define COLOR_YELLOW 0xFFFF00AA
#define COLOR_PINK 0xFF66FFAA
#define COLOR_BLUE 0x0000BBAA
#define COLOR_WHITE 0xFFFFFFAA
#define COLOR_DARKRED 0x660000AA
#define COLOR_ORANGE 0xFF9900AA
#define COLOR_BRIGHTRED 0xFF0000AA
#define COLOR_INDIGO 0x4B00B0AA
#define COLOR_VIOLET 0x9955DEEE
#define COLOR_LIGHTRED 0xFF99AADD
#define COLOR_SEAGREEN 0x00EEADDF
#define COLOR_GRAYWHITE 0xEEEEFFC4
#define COLOR_LIGHTNEUTRALBLUE 0xabcdef66
#define COLOR_GREENISHGOLD 0xCCFFDD56
#define COLOR_LIGHTBLUEGREEN 0x0FFDD349
#define COLOR_NEUTRALBLUE 0xABCDEF01
#define COLOR_LIGHTCYAN 0xAAFFCC33
#define COLOR_LEMON 0xDDDD2357
#define COLOR_MEDIUMBLUE 0x63AFF00A
#define COLOR_NEUTRAL 0xABCDEF97
#define COLOR_BLACK 0x00000000
#define COLOR_NEUTRALGREEN 0x81CFAB00
#define COLOR_DARKGREEN 0x12900BBF
#define COLOR_LIGHTGREEN 0x24FF0AB9
#define COLOR_DARKBLUE 0x300FFAAB
#define COLOR_BLUEGREEN 0x46BBAA00
#define COLOR_PINK 0xFF66FFAA
#define COLOR_LIGHTBLUE 0x33CCFFAA
#define COLOR_DARKRED 0x660000AA
#define COLOR_ORANGE 0xFF9900AA
#define COLOR_PURPLE 0x800080AA
#define COLOR_GRAD1 0xB4B5B7FF
#define COLOR_GRAD2 0xBFC0C2FF
#define COLOR_RED1 0xFF0000AA
#define COLOR_GREY 0xAFAFAFAA
#define COLOR_GREEN 0x33AA33AA
#define COLOR_RED 0xAA3333AA
#define COLOR_YELLOW 0xFFFF00AA
#define COLOR_WHITE 0xFFFFFFAA
#define COLOR_BROWN 0x993300AA
#define COLOR_CYAN 0x99FFFFAA
#define COLOR_TAN 0xFFFFCCAA
#define COLOR_PINK 0xFF66FFAA
#define COLOR_KHAKI 0x999900AA
#define COLOR_LIME 0x99FF00AA
#define COLOR_SYSTEM 0xEFEFF7AA
#define COLOR_GRAD2 0xBFC0C2FF
#define COLOR_GRAD4 0xD8D8D8FF
#define COLOR_GRAD6 0xF0F0F0FF
#define COLOR_GRAD2 0xBFC0C2FF
#define COLOR_GRAD3 0xCBCCCEFF
#define COLOR_GRAD5 0xE3E3E3FF
#define COLOR_GRAD1 0xB4B5B7FF

#define MAX_BANDS 100 // Max Groups 100. You can change to max up to 500!

enum ginfo
{
        grname[75],
        leader,
        active
};

enum pginfo
{
        gid,
        order,
        invited,
        attemptjoin
};

new BAND[MAX_PLAYERS][pginfo];
new BANDinfo[MAX_BANDS][ginfo];

public OnFilterScriptInit()
{
        for(new x; x<MAX_PLAYERS; x++)
        {
                BAND[x][gid] = -1;
                BAND[x][order] = -1;
                BAND[x][invited] = -1;
                BAND[x][attemptjoin] = -1;
        }
        return 1;
}

public OnPlayerConnect(playerid)
{
        BAND[playerid][gid] = -1;
        BAND[playerid][invited] = -1;
        BAND[playerid][attemptjoin] = -1;
        return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
        return 1;
}

COMMAND:gangcreate(playerid, params[])
{
        if(BAND[playerid][gid] != -1) return SendClientMessage(playerid, 0xFF0000, "Leave your band with {FFFFFF}/Gangleave{FF0000} before creating a new one!");
        if(strlen(params) > 49 || strlen(params) < 3) return SendClientMessage(playerid, 0xFF0000, "Usage: {FFFFFF}/Gangcreate{FF0000} (Gang name 3-50 characters)!");
        if(IsBANDTaken(params)) return SendClientMessage(playerid, 0xFF0000, "ERROR: Gang name is already in Use!");
        CreateBAND(params, playerid);
        return 1;
}

COMMAND:gangleave(playerid, params[])
{
        if(BAND[playerid][gid] == -1) return SendClientMessage(playerid, 0xFF0000, "ERROR:You are not in a Gang to leave one!");
        LeaveBAND(playerid, 0);
        return 1;
}

COMMAND:gangaccept(playerid, params[])
{
        if(BAND[playerid][order] != 1) return SendClientMessage(playerid, 0xFF0000, "You are not the leader of the Gang, you cannot invite people!");
        new cid;
        if(isnull(params)) return SendClientMessage(playerid, 0xFF0000, "Usage: {FFFFFF}/Gangaccept{FF0000} [id]");
        cid = strval(params);
        if(!IsPlayerConnected(cid)) return SendClientMessage(playerid, 0xFF0000, "Player Is not connected!");
        if(BAND[cid][gid] == BAND[playerid][gid]) return SendClientMessage(playerid, 0xFF0000, "Player Is already in your band!");
        if(BAND[cid][invited] == BAND[playerid][gid]) return SendClientMessage(playerid, 0xFF0000, "Player has already been invited to your band!");
        if(BAND[cid][attemptjoin] == BAND[playerid][gid]) return BANDJoin(cid, BAND[playerid][gid]);
        BAND[cid][invited] = BAND[playerid][gid];
        new string[125], pname[24];
        GetPlayerName(playerid, pname, 24);
        format(string, sizeof(string), "You have been invited to join Band {FFFFFF}%s(ID.%d){FFCC66} by {FFFFFF}%s(ID.%d). /Gangjoin %d", BANDinfo[BAND[playerid][gid]][grname], BAND[playerid][gid], pname, playerid, BAND[playerid][gid]);
        SendClientMessage(cid, 0xFFCC66, string);
        GetPlayerName(cid, pname, 24);
        format(string, sizeof(string), "You have invited {FFFFFF}%s(ID.%d){FFCC66} to join your band!", pname, cid);
        SendClientMessage(playerid, 0xFFCC66, string);
        return 1;
}

COMMAND:gangowner(playerid, params[])
{
        if(BAND[playerid][order] != 1) return SendClientMessage(playerid, 0xFF0000, "You are not the leader of the Gang, you cannot change the leader!");
        new cid;
        if(isnull(params)) return SendClientMessage(playerid, 0xFF0000, "Usage: {FFFFFF}/Gangowner{FF0000} [id]");
        cid = strval(params);
        if(!IsPlayerConnected(cid)) return SendClientMessage(playerid, 0xFF0000, "Player Is not connected!");
        if(cid == playerid)  return SendClientMessage(playerid, 0xFF0000, "ERROR: You are now Gang Leader :D!");
        if(BAND[playerid][gid] != BAND[cid][gid]) return SendClientMessage(playerid, 0xFF0000, "Player Is not in your Gang!");
        ChangeMemberOrder(BAND[playerid][gid], 1);
        BAND[playerid][order] = BANDMembers(BAND[playerid][gid]);
        return 1;
}
COMMAND:gangjoin(playerid, params[])
{
        if(BAND[playerid][gid] != -1) return SendClientMessage(playerid, 0xFF0000, "You are already in a Gang! Leave your current one before joining another one!");
        new grid;
        if( (isnull(params) && BAND[playerid][invited] != -1 ) || ( strval(params) == BAND[playerid][invited] && BAND[playerid][invited] != -1) ) return BANDJoin(playerid, BAND[playerid][invited]);
        if(isnull(params)) return SendClientMessage(playerid, 0xFF0000, "Usage: {FFFFFF}/Gangjoin{FF0000} [id]");
        grid = strval(params);
        if(!BANDinfo[grid][active]) return SendClientMessage(playerid, COLOR_RED, "ERROR: You wanted to join band which doesnt Exsist!!");
        BAND[playerid][attemptjoin] = grid;
        new string[125], pname[24];
        GetPlayerName(playerid, pname, 24);
        format(string, sizeof(string), "You have requested to join band %s(ID:%d)", BANDinfo[grid][grname], grid);
        SendClientMessage(playerid, 0xFFCC66, string);
        format(string, sizeof(string), "{FFFFFF}%s(ID.%d) {FFCC66}has requested to join your Gang. Type /Gangaccept %d to accept him!", pname, playerid, playerid);
        SendMessageToLeader(grid, string);
        return 1;
}

COMMAND:gangkick(playerid, params[])
{
        if(BAND[playerid][order] != 1) return SendClientMessage(playerid, COLOR_RED, "ERROR:You are not the leader of a Gang, you cannot kick!");
        new cid;
        if(isnull(params)) return SendClientMessage(playerid, 0xFF0000, "Usage: {FFFFFF}/Gangkick{FF0000} [id]");
        cid = strval(params);
        if(!IsPlayerConnected(cid)) return SendClientMessage(playerid, 0xFF0000, "Player Is not connected!");
        if(cid == playerid)  return SendClientMessage(playerid, 0xFF0000, "You cannot kick yourself, silly.");
        if(BAND[playerid][gid] != BAND[cid][gid]) return SendClientMessage(playerid, 0xFF0000, "Player Is not in your Gang!");
        LeaveBAND(cid, 1);
        return 1;
}

COMMAND:bm(playerid, params[])
{
        if(BAND[playerid][gid] == -1) return SendClientMessage(playerid, 0xFF0000, "ERROR: You are not in Band. You cannot Talk over Radio!");
        if(isnull(params)) return SendClientMessage(playerid, COLOR_RED, "USAGE: ! [message]. WARNING! Its ICly!");
        new pname[24], string[140+24];
        GetPlayerName(playerid, pname, 24);
        format(string, sizeof(string), "%s(ID.%d): %s", pname, playerid, params);
        SendMessageToAllBANDMembers(BAND[playerid][gid], string);
        return 1;
}
COMMAND:gangsinfo(playerid, params[])
{
    if(BAND[playerid][gid] == -1) return SendClientMessage(playerid, COLOR_GREEN, "ERROR: You are not in Gang. To check Gang Stats, go in your Gang!");
    SendClientMessage(playerid, COLOR_GREEN ,"Warning: Gang Stats are Currently Under Construction! Need ideas for it. ");
    return 1;
}

COMMAND:ganglist(playerid, params[])
{
    if(isnull(params) && BAND[playerid][gid] == -1) return SendClientMessage(playerid, 0xFF0000, "Usage: {FFFFFF}/Ganglist{FF0000} [id]");
    if(isnull(params))
        {
                DisplayBANDMembers(BAND[playerid][gid], playerid);
                return 1;
        }
    new grid = strval(params);
    if(!BANDinfo[grid][active]) return SendClientMessage(playerid, 0xFF0000, "The band ID you have entered is not active!");
    DisplayBANDMembers(grid, playerid);
    return 1;
}

COMMAND:gangs(playerid, params[])
{
    ListBANDs(playerid);
    return 1;
}

COMMAND:grl(playerid, params[])
        return cmd_gangleave(playerid, params);

COMMAND:grc(playerid, params[])
        return cmd_gangcreate(playerid, params);

COMMAND:gri(playerid, params[])
        return cmd_gangaccept(playerid, params);

COMMAND:grlead(playerid, params[])
        return cmd_gangowner(playerid, params);

COMMAND:grj(playerid, params[])
        return cmd_gangjoin(playerid, params);

COMMAND:grk(playerid, params[])
        return cmd_gangkick(playerid, params);

COMMAND:gm(playerid, params[])
        return cmd_bm(playerid, params);

COMMAND:grlist(playerid, params[])
        return cmd_ganglist(playerid, params);


stock DisplayBANDMembers(BANDid, playerid)
{
    new amount[2], string[200], shortstr[55], pname[24];
    format(string, sizeof(string), "Band Members for %s(ID:%d)", BANDinfo[BANDid][grname], BANDid);
    SendClientMessage(playerid, 0xFFFFFF, string);
    string = "";
    for(new x; x<MAX_PLAYERS; x++)
        {
            if(BAND[x][gid] == BANDid)
            {
                amount[0] ++;
                amount[1] ++;
                GetPlayerName(x, pname, 24);
                if(BANDinfo[BANDid][leader] != x) format(shortstr, sizeof(shortstr), "%s(%d),", pname, x);
                if(BANDinfo[BANDid][leader] == x) format(shortstr, sizeof(shortstr), "[Leader]%s(%d),", pname, x);
                if(amount[1] == 1) format(string, sizeof(string), "%s", shortstr);
                if(amount[1] != 1) format(string, sizeof(string), "%s %s", string, shortstr);
                if(amount[0] == 6)
                {
                strdel(string, strlen(string)-1, strlen(string));
                SendClientMessage(playerid, 0xFFCC66, string);
                string = "";
                amount[0] = 0;
                }
            }
        }
    strdel(string, strlen(string)-1, strlen(string));
    if(amount[0] != 0) SendClientMessage(playerid, 0xFFCC66, string);
    return 1;
}

stock ListBANDs(playerid)
{
        new amount[2], string[200], shortstr[55];
        SendClientMessage(playerid, 0xFFFFFF, "Current Active Gangs:");
        for(new x=0; x<MAX_BANDS; x++)
        {
        if(BANDinfo[x][active])
                {
                        amount[0] ++;
                        amount[1] ++;
                        format(shortstr, sizeof(shortstr), "%s(ID:%d)", BANDinfo[x][grname], x);
                        if(amount[1] == 1) format(string, sizeof(string), "%s", shortstr);
        				if(amount[1] != 1) format(string, sizeof(string), "%s %s", string, shortstr);
                        if(amount[0] == 4)
                        {
                            SendClientMessage(playerid, 0xFFCC66, string);
                            string = "";
                            amount[0] = 0;
                        }
                }
        }
        if(amount[1] == 0) SendClientMessage(playerid, 0xFFFF00, "There are currently no active gangs!");
        if(amount[1] != 0) SendClientMessage(playerid, 0xFFCC66, string);
        return 1;
}




stock SendMessageToLeader(BANDi, message[])
    return SendClientMessage(BANDinfo[BANDi][leader], 0xFFCC66, message);

stock BANDJoin(playerid, BANDi)
{
        BAND[playerid][gid] = BANDi;
        BAND[playerid][order] = BANDMembers(BANDi);
    	BAND[playerid][attemptjoin] = -1;
    	BAND[playerid][invited] = -1;
    	new pname[24], string[130];
        GetPlayerName(playerid, pname, 24);
    	format(string, sizeof(string), "%s is now in your Gang!", pname);
    	SendMessageToAllBANDMembers(BANDi, string);
        format(string, sizeof(string), "You are now in gang %s(ID:%d)", BANDinfo[BANDi][grname] ,BANDi);
        SendClientMessage(playerid, 0xFFCC66, string);
        return 1;
}

stock FindNextSlot()
{
        new id;
        while(BANDinfo[id][active]) id ++;
        return id;
}

stock IsBANDTaken(grpname[])
{
        for(new x; x<MAX_BANDS; x++)
        {
            if(BANDinfo[x][active] == 1)
            {
                        if(!strcmp(grpname, BANDinfo[x][grname], true) && strlen(BANDinfo[x][grname]) != 0) return 1;
                }
        }
        return 0;
}

stock BANDInvite(playerid, BANDid)
    return BAND[playerid][invited] = BANDid;

stock CreateBAND(grpname[], owner)
{
        new slotid = FindNextSlot();
        BANDinfo[slotid][leader] = owner;
        format(BANDinfo[slotid][grname], 75, "%s", grpname);
        BANDinfo[slotid][active] = 1;
        BAND[owner][gid] = slotid;
        BAND[owner][order] = 1;
        new string[120];
        format(string, sizeof(string), "You created Gang %s(ID:%d)", grpname, slotid);
        SendClientMessage(owner, 0xFFCC66, string);
        return slotid;
}

stock LeaveBAND(playerid, reason)
{
        new BANDid = BAND[playerid][gid], orderid = BAND[playerid][order], string[100], pname[24];
        BAND[playerid][gid] = -1;
        BAND[playerid][order] = -1;
        BANDCheck(BANDid, orderid);
        GetPlayerName(playerid, pname, 24);
        if(reason == 0)
        {
        format(string, sizeof(string), "{FFFFFF}%s(%d){FFCC66} has left the Gang!", pname, playerid);
        SendClientMessage(playerid, 0xFFCC66, "You are leave from the gang");
        }
        if(reason == 1)
        {
                format(string, sizeof(string), "{FFFFFF}%s(%d){FFCC66} has kicked from the Gang!", pname, playerid);
        		SendClientMessage(playerid, 0xFFCC66, "You are kicked from the gang!");
        }
    	if(reason == 2) format(string, sizeof(string), "{FFFFFF}%s(%d){FFCC66} has left your Gang (Disconnected)!", pname, playerid);
        SendMessageToAllBANDMembers(BANDid, string);
        return 1;
}

stock BANDCheck(BANDid, orderid)
{
        new gmems = BANDMembers(BANDid);
        if(!gmems) BANDinfo[BANDid][active] = 0;
        if(gmems != 0) ChangeMemberOrder(BANDid, orderid);
        return 1;
}

stock BANDMembers(BANDid)
{
    if(!BANDinfo[BANDid][active]) return 0;
    new BANDmembers;
    for(new i; i<MAX_PLAYERS; i++) if(BAND[i][gid] == BANDid) BANDmembers++;
    return BANDmembers;
}

stock ChangeMemberOrder(BANDid, orderid)
{
        for(new x; x<MAX_PLAYERS; x++)
        {
                if(BAND[x][gid] != BANDid || BAND[x][order] < orderid) continue;
                BAND[x][order] --;
                if(BAND[x][order] == 1)
                {
                        BANDinfo[BANDid][leader] = x;
                        new string[128], pname[24];
                        GetPlayerName(x, pname, 24);
                        format(string, sizeof(string), "{FFFFFF}%s(ID.%d){FFCC66} is now Gang Leader! Congratiulations!", pname, x);
                        SendMessageToAllBANDMembers(BANDid, string);
                }
        }
        return 1;
}

stock SendMessageToAllBANDMembers(BANDid, message[])
{
        if(!BANDinfo[BANDid][active]) return 0;
        for(new x; x<MAX_PLAYERS; x++) if(BAND[x][gid] == BANDid) SendClientMessage(x, 0xFFCC66, message);
        return 1;
}
