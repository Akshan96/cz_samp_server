#include "a_samp"
#include <zcmd>

new Squirtle[MAX_PLAYERS];
new SquirtleTime[MAX_PLAYERS];
new GotATurtle[MAX_PLAYERS];
new PokemonTurtle[MAX_PLAYERS];
new Cow[MAX_PLAYERS];
new CowTime[MAX_PLAYERS];
new GotACow[MAX_PLAYERS];
new PokemonCow[MAX_PLAYERS];
new Parrot[MAX_PLAYERS];
new ParrotTime[MAX_PLAYERS];
new GotAParrot[MAX_PLAYERS];
new PokemonParrot[MAX_PLAYERS];

forward Squirtle_I_Choose_Youuuuu(playerid);
public Squirtle_I_Choose_Youuuuu(playerid)
{
        new Float:phrr[4];
        new playerstate = GetPlayerState(playerid);
        if (playerstate == PLAYER_STATE_DRIVER
        || playerstate == PLAYER_STATE_PASSENGER)
        {
        if(IsPlayerAttachedObjectSlotUsed(playerid,4))
        {
        SendClientMessage(playerid, 0xFF0000FF,"Are you crazy?..Turtle can't follow you when you're driving.");
        SendClientMessage(playerid, 0xFF0000FF,"Turtle is in your pokc ball!");
                KillTimer(SquirtleTime[playerid]);
        DestroyObject(Squirtle[playerid]);
                GotATurtle[playerid] = 0;
                }
        }
        if (playerstate == PLAYER_STATE_ONFOOT)
        {
        GetPlayerPos(playerid, phrr[0],phrr[1],phrr[2]);
                GetPlayerFacingAngle(playerid, phrr[3]);
        SetObjectRot(Squirtle[playerid],0.0, 0.0, phrr[3]);
        MoveObject(Squirtle[playerid], phrr[0]-3,phrr[1],phrr[2],10);
        }
        return 1;
}

COMMAND:goturtle(playerid,params[])
{
    new Float:x1,Float:y1,Float:z1,Float:a;
    if(IsPlayerAttachedObjectSlotUsed(playerid,4))
    {
        if (GotATurtle[playerid] == 0)
        {
        GetPlayerPos(playerid,x1,y1,z1);
    GetPlayerFacingAngle(playerid, a);
    Squirtle[playerid] = CreateObject(1609,x1,y1,z1-1,a,0.0,0.0);
    SquirtleTime[playerid] = SetTimerEx("Squirtle_I_Choose_Youuuuu",1,true, "i", playerid);
    SendClientMessage(playerid, 0x00FF00FF,"TURTLE I CHOOSE YOUU , GO!");
        SendClientMessage(playerid, 0xFFFF00FF,"Now use /getturtle to get it back to pokc ball!");
    GotATurtle[playerid] = 1;
        }
        else
        {
        SendClientMessage(playerid, 0xFF0000FF,"Are you blind?!?!");
        }
        }
    else
    {
    SendClientMessage(playerid, 0xFF0000FF,"You dont have a turtle!");
    }
        return 1;
}
COMMAND:getturtle(playerid,params[])
{
                if(IsPlayerAttachedObjectSlotUsed(playerid,4))
        {
                if (GotATurtle[playerid] == 1)
                {
        SendClientMessage(playerid, 0xFFFF00FF,"Come back in pokc ball, turtle!");
        KillTimer(SquirtleTime[playerid]);
        DestroyObject(Squirtle[playerid]);
        GotATurtle[playerid] = 0;
                }
                else
                {
                SendClientMessage(playerid, 0xFF0000FF,"First you have to call it from your pokc ball!");
                }
                }
        else
        {
        SendClientMessage(playerid, 0xFF0000FF,"You dont have a turtle!");
        }
            return 1;
}


public OnPlayerDisconnect(playerid)
{
        KillTimer(SquirtleTime[playerid]);
        GotATurtle[playerid] = 0;
        KillTimer(CowTime[playerid]);
        GotACow[playerid] = 0;
        KillTimer(ParrotTime[playerid]);
        GotAParrot[playerid] = 0;
                return 1;
}

COMMAND:buyturtle(playerid,params[])
{
        if (IsPlayerAttachedObjectSlotUsed(playerid, 4) == 0)
        {
                if (GetPlayerMoney(playerid) >= 20000)
                {
                SetPlayerAttachedObject(playerid, 4, 1609, 10, 0.0, 0.0,0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
        SendClientMessage(playerid, 0x00FF00FF,"You have bought a turtle");
        SendClientMessage(playerid, 0x00FF00FF,"Now use /goturtle to call it from pokc ball!");
        GivePlayerMoney(playerid, -20000);
                GotATurtle[playerid] = 0;
        PokemonTurtle[playerid] = 1;
                }
                }
                {
                SendClientMessage(playerid,0xFF0000FF,"You don't have enough cash!");
                }
                return 1;
}
COMMAND:sellturtle(playerid,params[])
{
        if(IsPlayerAttachedObjectSlotUsed(playerid,4))
        {
        RemovePlayerAttachedObject(playerid,4);
        DestroyObject(Squirtle[playerid]);
        SendClientMessage(playerid, 0x00FF00FF,"You have sold a turtle");
        GivePlayerMoney(playerid, 19000);
        GotATurtle[playerid] = 0;
        PokemonTurtle[playerid] = 0;
                }
        return 1;
}

 forward Cow_I_Choose_Youuuuu(playerid);
public Cow_I_Choose_Youuuuu(playerid)
{
        new Float:phrr[4];
        new playerstate = GetPlayerState(playerid);
        if (playerstate == PLAYER_STATE_DRIVER
        || playerstate == PLAYER_STATE_PASSENGER)
        {
        if(PokemonCow[playerid] == 1)
        {
        SendClientMessage(playerid, 0xFF0000FF,"Are you crazy?..Cow can't follow you when you're driving.");
        SendClientMessage(playerid, 0xFF0000FF,"Cow is in your pokc ball!");
                KillTimer(CowTime[playerid]);
        DestroyObject(Cow[playerid]);
                GotACow[playerid] = 0;
                }
        }
        if (playerstate == PLAYER_STATE_ONFOOT)
        {
        GetPlayerPos(playerid, phrr[0],phrr[1],phrr[2]);
                GetPlayerFacingAngle(playerid, phrr[3]);
        SetObjectRot(Cow[playerid],0.0, 0.0, phrr[3]);
        MoveObject(Cow[playerid], phrr[0]-10,phrr[1],phrr[2],10);
        }
        return 1;
}

COMMAND:gocow(playerid,params[])
{
    new Float:x1,Float:y1,Float:z1,Float:a;
    if(PokemonCow[playerid] == 1)
    {
        if (GotACow[playerid] == 0)
        {
        GetPlayerPos(playerid,x1,y1,z1);
    GetPlayerFacingAngle(playerid, a);
    Cow[playerid] = CreateObject(16442,x1-10,y1,z1-1,a,0.0,0.0);
    CowTime[playerid] = SetTimerEx("Cow_I_Choose_Youuuuu",1,true, "i", playerid);
    SendClientMessage(playerid, 0x00FF00FF,"COW I CHOOSE YOUU , GO!");
        SendClientMessage(playerid, 0xFFFF00FF,"Now use /getcow to get it back to pokc ball!");
    GotACow[playerid] = 1;
        }
        else
        {
        SendClientMessage(playerid, 0xFF0000FF,"Are you blind?!?!");
        }
        }
    else
    {
    SendClientMessage(playerid, 0xFF0000FF,"You dont have a cow!");
    }
        return 1;
}
COMMAND:getcow(playerid,params[])
{
                if (PokemonCow[playerid] == 1)
                {
                if (GotACow[playerid] == 1)
                {
        SendClientMessage(playerid, 0xFFFF00FF,"Come back in pokc ball, cow!");
        KillTimer(CowTime[playerid]);
        DestroyObject(Cow[playerid]);
        GotACow[playerid] = 0;
                }
                else
                {
                SendClientMessage(playerid, 0xFF0000FF,"First you have to call it from your pokc ball!");
                }
                }
        else
        {
        SendClientMessage(playerid, 0xFF0000FF,"You dont have a cow!");
        }
            return 1;
}


COMMAND:buycow(playerid,params[])
{
        if (PokemonCow[playerid] == 0 && GetPlayerMoney(playerid) >= 20000)
        {
                SendClientMessage(playerid, 0x00FF00FF,"You have bought a cow");
        SendClientMessage(playerid, 0x00FF00FF,"Now use /gocow to call it from pokc ball!");
        GivePlayerMoney(playerid, -20000);
                GotACow[playerid] = 0;
        PokemonCow[playerid] = 1;
                }
                else
                {
                SendClientMessage(playerid,0xFF0000FF,"You don't have enough cash or you already have a cow!");
                }
                return 1;
}
COMMAND:sellcow(playerid,params[])
{
        if(PokemonCow[playerid] == 1)
        {
        DestroyObject(Cow[playerid]);
        SendClientMessage(playerid, 0x00FF00FF,"You have sold a cow");
        GivePlayerMoney(playerid, 19000);
        GotACow[playerid] = 0;
        PokemonCow[playerid] = 0;
                }
        return 1;
}

forward Parrot_I_Choose_Youuuuu(playerid);
public Parrot_I_Choose_Youuuuu(playerid)
{
        new Float:phrr[4];
        new playerstate = GetPlayerState(playerid);
        if (playerstate == PLAYER_STATE_DRIVER
        || playerstate == PLAYER_STATE_PASSENGER)
        {
        if(PokemonParrot[playerid] == 1)
        {
        SendClientMessage(playerid, 0xFF0000FF,"Are you crazy?..Parrot can't follow you when you're driving.");
        SendClientMessage(playerid, 0xFF0000FF,"Parrot is in your pokc ball!");
                KillTimer(ParrotTime[playerid]);
        DestroyObject(Parrot[playerid]);
                GotAParrot[playerid] = 0;
                }
        }
        if (playerstate == PLAYER_STATE_ONFOOT)
        {
        GetPlayerPos(playerid, phrr[0],phrr[1],phrr[2]);
                GetPlayerFacingAngle(playerid, phrr[3]);
        SetObjectRot(Parrot[playerid],0.0, -90.0, phrr[3]);
        MoveObject(Parrot[playerid], phrr[0]-1,phrr[1],phrr[2]+0.5,10);
        }
        return 1;
}

COMMAND:goparrot(playerid,params[])
{
        new Float:x,Float:y,Float:z;
        if(PokemonParrot[playerid] == 1)
    {
        if (GotAParrot[playerid] == 0)
        {
        GetPlayerPos(playerid,x,y,z);
        Parrot[playerid] = CreateObject(19079,x-1,y , z,90,0,45);
    ParrotTime[playerid] = SetTimerEx("Parrot_I_Choose_Youuuuu",1,true, "i", playerid);
    SendClientMessage(playerid, 0x00FF00FF,"PARROT I CHOOSE YOUU , GO!");
        SendClientMessage(playerid, 0xFFFF00FF,"Now use /getparrot to get it back to pokc ball!");
    GotAParrot[playerid] = 1;
        }
        else
        {
        SendClientMessage(playerid, 0xFF0000FF,"Are you blind?!?!");
        }
        }
    else
    {
    SendClientMessage(playerid, 0xFF0000FF,"You dont have a parrot!");
    }
        return 1;
}
COMMAND:getparrot(playerid,params[])
{
                if (PokemonParrot[playerid] == 1)
                {
                if (GotAParrot[playerid] == 1)
                {
        SendClientMessage(playerid, 0xFFFF00FF,"Come back in pokc ball, parrot!");
        KillTimer(ParrotTime[playerid]);
        DestroyObject(Parrot[playerid]);
        GotAParrot[playerid] = 0;
                }
                else
                {
                SendClientMessage(playerid, 0xFF0000FF,"First you have to call it from your pokc ball!");
                }
                }
        else
        {
        SendClientMessage(playerid, 0xFF0000FF,"You dont have a parrot!");
        }
            return 1;
}


COMMAND:buyparrot(playerid,params[])
{
        if (PokemonParrot[playerid] == 0 && GetPlayerMoney(playerid) >= 20000)
        {
                SendClientMessage(playerid, 0x00FF00FF,"You have bought a parrot");
        SendClientMessage(playerid, 0x00FF00FF,"Now use /goparrot to call it from pokc ball!");
        GivePlayerMoney(playerid, -20000);
                GotAParrot[playerid] = 0;
        PokemonParrot[playerid] = 1;
                }
                else
                {
                SendClientMessage(playerid,0xFF0000FF,"You don't have enough cash or you already have a parrot!");
                }
                return 1;
}
COMMAND:sellparrot(playerid,params[])
{
        if(PokemonParrot[playerid] == 1)
        {
        DestroyObject(Parrot[playerid]);
        SendClientMessage(playerid, 0x00FF00FF,"You have sold a parrot");
        GivePlayerMoney(playerid, 19000);
        GotAParrot[playerid] = 0;
        PokemonParrot[playerid] = 0;
                }
        return 1;
}
