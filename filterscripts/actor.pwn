#include <a_samp>
#include <a_actor>
#include <required/zcmd>

new newbots[11];
new Float:botspos[11][4] =
{
        {-1745.6602,891.3812,29.9970},
        {-1745.7996,886.8665,29.9562},
        {-1745.7451,881.9039,29.9721},
        {-1745.8673,876.3864,29.9365},
        {-2421.6902,752.5062,35.1719},
        {-2417.1846,752.3717,35.1719},
        {-2412.1162,752.0607,35.1719},
        {-2407.2354,751.5665,35.1786},
        {-2019.6844,-79.2887,35.3203},
        {-2022.9045,-79.2370,35.3203},
        {-2026.1235,-79.2085,35.3203}
};

public OnFilterScriptInit()
{
    for(new i; i < sizeof(botspos); i++) newbots[i] = CreateActor(203, botspos[i][0],botspos[i][1], botspos[i][2], botspos[i][3]);

	return 1;
}

CMD:stop(playerid,params[])
{
	if(IsPlayerAdmin(playerid))
    for(new i; i < sizeof(newbots); i++) ClearActorAnimations(newbots[i]);

	return 1;
}

CMD:drunk1(playerid, params[])
{
    if(IsPlayerAdmin(playerid))
    for(new i; i < sizeof(newbots); i++) ApplyActorAnimation(newbots[i], "PED", "WALK_DRUNK", 4.0, 1, 1, 1, 0, 0);

	return 1;
}

CMD:taichi1(playerid, params[])
{
    if(IsPlayerAdmin(playerid))
    for(new i; i < sizeof(newbots); i++) ApplyActorAnimation(newbots[i], "PARK","Tai_Chi_Loop",4.0,1,0,0,0,0);

	return 1;
}

CMD:bd1(playerid, params[])
{
    if(IsPlayerAdmin(playerid))
    for(new i; i < sizeof(newbots); i++) ApplyActorAnimation(newbots[i], "RUNNINGMAN", "DANCE_G2", 4.0, 1, 0, 0, 0, 0);

	return 1;
}
