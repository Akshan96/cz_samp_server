/*
                                                                    dddddddd
   SSSSSSSSSSSSSSS hhhhhhh                                          d::::::d
 SS:::::::::::::::Sh:::::h                                          d::::::d
S:::::SSSSSS::::::Sh:::::h                                          d::::::d
S:::::S     SSSSSSSh:::::h                                          d:::::d
S:::::S             h::::h hhhhh         aaaaaaaaaaaaa      ddddddddd:::::d
S:::::S             h::::hh:::::hhh      a::::::::::::a   dd::::::::::::::d
 S::::SSSS          h::::::::::::::hh    aaaaaaaaa:::::a d::::::::::::::::d
  SS::::::SSSSS     h:::::::hhh::::::h            a::::ad:::::::ddddd:::::d
    SSS::::::::SS   h::::::h   h::::::h    aaaaaaa:::::ad::::::d    d:::::d
       SSSSSS::::S  h:::::h     h:::::h  aa::::::::::::ad:::::d     d:::::d
            S:::::S h:::::h     h:::::h a::::aaaa::::::ad:::::d     d:::::d
            S:::::S h:::::h     h:::::ha::::a    a:::::ad:::::d     d:::::d
SSSSSSS     S:::::S h:::::h     h:::::ha::::a    a:::::ad::::::ddddd::::::dd
S::::::SSSSSS:::::S h:::::h     h:::::ha:::::aaaa::::::a d:::::::::::::::::d
S:::::::::::::::SS  h:::::h     h:::::h a::::::::::aa:::a d:::::::::ddd::::d
 SSSSSSSSSSSSSSS    hhhhhhh     hhhhhhh  aaaaaaaaaa  aaaa  ddddddddd   ddddd
*/


#include <a_samp>
#define FILTERSCRIPT

new Text:Time, Text:Date;

forward settime(playerid);

public OnFilterScriptInit()
{
        print("\n--------------------------------------");
        print(" Updated Version! WORLDCLOCK+DATE By Shadow");
        print("--------------------------------------\n");

    	SetTimer("settime",1000,true);

        Date = TextDrawCreate(547.000000,11.000000,"--");

        TextDrawFont(Date,3);
        TextDrawLetterSize(Date,0.399999,1.600000);
    	TextDrawColor(Date,0xffffffff);

        Time = TextDrawCreate(547.000000,28.000000,"--");

        TextDrawFont(Time,3);
        TextDrawLetterSize(Time,0.399999,1.600000);
        TextDrawColor(Time,0xffffffff);
        return 1;
}

public OnFilterScriptExit()
{
        print("\n-----------------------------------------------------");
        print(" Update Version! WORLDCLOCK+DATE By Shadow !UNLOADED!");
        print("-----------------------------------------------------/n");
        return 1;
}

public OnPlayerSpawn(playerid)
{
        TextDrawShowForPlayer(playerid, Time), TextDrawShowForPlayer(playerid, Date);


        return 1;
}

public OnPlayerConnect(playerid)
{
    TogglePlayerClock(playerid, 0); // Show the clock
    return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
        TextDrawHideForPlayer(playerid, Time), TextDrawHideForPlayer(playerid, Date);
        return 1;
}

public settime(playerid)
{
        new string[256],year,month,day,hours,minutes,seconds;
        getdate(year, month, day), gettime(hours, minutes, seconds);
        format(string, sizeof string, "%d/%s%d/%s%d", day, ((month < 10) ? ("0") : ("")), month, (year < 10) ? ("0") : (""), year);
        TextDrawSetString(Date, string);
        format(string, sizeof string, "%s%d:%s%d:%s%d", (hours < 10) ? ("0") : (""), hours, (minutes < 10) ? ("0") : (""), minutes, (seconds < 10) ? ("0") : (""), seconds);
        TextDrawSetString(Time, string);
}
