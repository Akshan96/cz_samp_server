#include <a_samp>
#define FILTERSCRIPT

new Text:Date;
new Text:Line1;
new Text:Time;


public OnFilterScriptInit()
{
	Date = TextDrawCreate(565.399, 330.773, "9/06/2015");
	TextDrawLetterSize(Date, 0.459999, 1.880000);
	TextDrawAlignment(Date, 2);
	TextDrawColor(Date, -5063511);
	TextDrawSetShadow(Date, 1);
	TextDrawSetOutline(Date, 0);
	TextDrawBackgroundColor(Date, 255);
	TextDrawFont(Date, 2);
	TextDrawSetProportional(Date, 1);
	TextDrawSetShadow(Date, 1);

	Line1 = TextDrawCreate(580.399, 343.466, ".");
	TextDrawLetterSize(Line1, 11.820992, 0.899999);
	TextDrawAlignment(Line1, 2);
	TextDrawColor(Line1, -392795);  //-5963521
	TextDrawSetShadow(Line1, 0);
	TextDrawSetOutline(Line1, 0);
	TextDrawBackgroundColor(Line1, 255);
	TextDrawFont(Line1, 0);
	TextDrawSetProportional(Line1, 1);
	TextDrawSetShadow(Line1, 0);

	Time = TextDrawCreate(565.399, 350.933, "13:57:32");
	TextDrawLetterSize(Time, 0.400000, 1.600000);
	TextDrawAlignment(Time, 2);
	TextDrawColor(Time, -343365);
	TextDrawSetShadow(Time, 1);
	TextDrawSetOutline(Time, 0);
	TextDrawBackgroundColor(Time, 255);
	TextDrawFont(Time, 2);
	TextDrawSetProportional(Time, 1);
	TextDrawSetShadow(Time, 1);

	SetTimer("time", 1000, true);
	return 1;
}

public OnFilterScriptExit()
{
	return 1;
}

public OnPlayerSpawn(playerid)
{
        TextDrawShowForPlayer(playerid, Date);
        TextDrawShowForPlayer(playerid, Line1);
        TextDrawShowForPlayer(playerid, Time);
}

public OnPlayerDisconnect(playerid, reason)
{
        TextDrawHideForPlayer(playerid, Date);
        TextDrawHideForPlayer(playerid, Line1);
        TextDrawHideForPlayer(playerid, Time);
}

forward time();
public time()
{
        new string[256], year, month, day, hours, minutes, seconds;
        getdate(year, month, day), gettime(hours, minutes, seconds);
        format(string, sizeof string, "%d/%s%d/%s%d", day, ((month < 10) ? ("0") : ("")), month, (year < 10) ? ("0") : (""), year);
        TextDrawSetString(Date, string);
        format(string, sizeof string, "%s%d:%s%d:%s%d", (hours < 10) ? ("0") : (""), hours, (minutes < 10) ? ("0") : (""), minutes, (seconds < 10) ? ("0") : (""), seconds);
        TextDrawSetString(Time, string);
}
