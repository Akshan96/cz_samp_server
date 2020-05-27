// Enum
enum DuelSystem
{
        playername[25],
        induel,
        weapname[45],
        weapid
}
new duelinfo[MAX_PLAYERS][DuelSystem];

enum sWeaponInfo
{
    wName[60],
        Valid,
        Slot
}

new WeaponInfo[][sWeaponInfo] =
{
    {"Fist",1,0},
    {"Brass Knuckles",1,0},
    {"Golf Club",1,1},
    {"Nightstick",1,1},
    {"Knife",1,1},
    {"Baseball Bat",1,1},
    {"Shovel",1,1},
    {"Pool cue",1,1},
    {"Katana",1,1},
    {"Chainsaw",1,1},
    {"Double-ended Dildo",1,10},
    {"Dildo",1,10},
    {"Vibrator",1,10},
    {"Silver Vibrator",1,10},
    {"Flowers",1,10},
    {"Cane",1,10},
    {"Grenade",1,8},
    {"Tear Gas",1,8},
    {"Molotov Cocktail",1,8},
    {"",0},
    {"",0},
    {"",0},
    {"9mm Pistol",1,2},
    {"Silenced 9mm",1,2},
    {"Deagle",1,2},
    {"Shotgun",1,3},
    {"Sawnoff Shotgun",1,3},
    {"Combat Shotgun",1,3},
    {"Micro SMG",1,4},
    {"MP5",1,4},
    {"AK-47",1,5},
    {"M4",1,5},
    {"Tec-9",1,4},
    {"Country Rifle",1,6},
    {"Sniper Rifle",1,6},
    {"RPG",1,7},
    {"HS Rocket",1,7},
    {"Flamethrower",1,7},
    {"Minigun",1,7},
    {"Sachel Charge",1,8},
    {"Detonator",1,12},
    {"Spray Can",1,9},
    {"Fire Extinguisher",1,9},
    {"Camera",1,9},
    {"Night Vision Goggles",0,11},
    {"Thermal Goggles",0,11},
    {"Parachute",1,11}
};

new invite[MAX_PLAYERS],
    inviter[MAX_PLAYERS],
    DuelSender[MAX_PLAYERS],
    DuelReciever[MAX_PLAYERS];

// Colors
#define RED                     "{FF0000}"
#define DARKRED                 "{CC0000}"
#define YELLOW                  "{FFFF00}"
#define GREEN                   "{00FF00}"
#define BLUE                    "{0000FF}"
#define ORANGE                  "{FF7F2A}"
#define PURPLE          "{FF00FF}"
#define LIGHT           "{00FFFF}"
#define WHITE           "{FFFFFF}"
#define GREY                    "{696969}"

// Commands

CMD:duel(playerid, params[])
{
    new user, weap[45], weaponid = -1, string[128], string2[128] ;
    if(sscanf(params, "us[45]", user, weap)) return SendClientMessage(playerid, -1, "USAGE: /duel <username/id> <weapon name>");
    if(user == INVALID_PLAYER_ID) return SendClientMessage(playerid, -1, "The player is currently offline!");
    if(user == playerid) return SendClientMessage(playerid, -1, "You cannot duel yourself");
    if(duelinfo[playerid][induel] == 1) return SendClientMessage(playerid, -1, "You are already in a duel");
    if(duelinfo[user][induel] == 1) return SendClientMessage(playerid, -1, "Player is already in a duel");
    if(invite[user] == 1) return SendClientMessage(playerid, -1, "Player already has a duel invitation");
    if(inviter[playerid] == 1) return SendClientMessage(playerid, -1, "You already invited a player, please wait till it's rejected or accepted!");
    if(StringNumeric(weap))
    {
        weaponid = strval(weap);
    }
    else
    {
        weaponid = CheckWeaponID(weap);
    }
    DuelSender[user] = playerid;
    duelinfo[playerid][weapid] = weaponid;
    duelinfo[playerid][weapname] = weap;
    duelinfo[user][weapid] = weaponid;
    duelinfo[user][weapname] = weap;
    invite[user] = 1;
    inviter[playerid] = 1;
    DuelReciever[playerid] = user;
    format(string, sizeof(string), ""RED"[DUEL] "WHITE"You have send a duel invitation to %s(%d). [Weapon : %s]", duelinfo[user][playername], user, weap);
    SendClientMessage(playerid, -1, string);
    format(string2, sizeof(string2), ""RED"[DUEL] "WHITE"You have recieved a duel invitation from %s(%d). [Weapon : %s]", duelinfo[playerid][playername], playerid, weap);
    SendClientMessage(playerid, -1, string2);
    return 1;
}

CMD:acceptduel(playerid, params[])
{
    if(invite[playerid] == 1)
    {
        new user = DuelSender[playerid];
        ResetPlayerWeapons(user);
        RemovePlayerFromVehicle(user);
        SetPlayerArmour(user, 0);
        SetPlayerHealth(user, 100);
        SetPlayerVirtualWorld(user, 100);
        SetPlayerPos(user, 3217.0442, 1688.5468, 15.0357);
        GivePlayerWeaponEx(user, duelinfo[playerid][weapid], 500);
        duelinfo[user][induel] = 1;
        inviter[user] = 0;

        ResetPlayerWeapons(playerid);
        RemovePlayerFromVehicle(playerid);
        SetPlayerArmour(playerid, 0);
        SetPlayerHealth(playerid, 100);
        SetPlayerVirtualWorld(playerid, 100);
        GivePlayerWeaponEx(playerid, duelinfo[user][weapid], 500);
        SetPlayerPos(playerid, 3188.8413, 1769.2462, 15.8491);
        duelinfo[playerid][induel] = 1;
        invite[playerid] = 0;
    }
    else return SendClientMessage(playerid, -1, "You didn't recieve any duel request");
    return 1;
}

CMD:declineduel(playerid, params[])
{
    if(invite[playerid] == 1)
    {
        new user = DuelSender[playerid], string[128], string2[128];
        invite[playerid] = 0;
        inviter[user] = 0;
        format(string, sizeof(string), ""RED"[DUEL] "WHITE"You have declined %s(%d)'s duel request", duelinfo[user][playername], user);
        SendClientMessage(playerid, -1, string);
        format(string2, sizeof(string2), ""RED"[DUEL] "WHITE"%s(%d) has declined your duel request", duelinfo[playerid][playername], playerid);
        SendClientMessage(playerid, -1, string2);
    }
    else return SendClientMessage(playerid, -1, "You didn't recieve any duel request");
    return 1;
}

CMD:cancelrequest(playerid, params[])
{
    if(inviter[playerid] == 1)
    {
        new user = DuelReciever[playerid], string[128], string2[128];
        inviter[playerid] = 0;
        invite[user] = 0;
        format(string, sizeof(string), ""RED"[DUEL] "WHITE"You have cancelled the request sent to%s(%d)", duelinfo[user][playername], user);
        SendClientMessage(playerid, -1, string);
        format(string2, sizeof(string2), ""RED"[DUEL] "WHITE"%s(%d) has cancelled the duel request sent to you", duelinfo[playerid][playername], playerid);
        SendClientMessage(playerid, -1, string2);
    }
    else return SendClientMessage(playerid, -1, "You didn't send any duel request");
    return 1;
}

// Stocks
StringNumeric(const str[])
{
    for(new i = 0,ii = strlen(str);i < ii;i++)
    {
        if(str[i] > '9' || str[i] < '0') return 0;
    }
    return 1;
}

stock CheckWeaponID(name[])
{
    for(new i = 0; i < 46; i++)
    {
        if(strfind(WeaponInfo[i][wName], name, true) != -1)
        {
            if(WeaponInfo[i][Valid] == 0) return -2;
            return i;
        }
    }
    return -1;
}
