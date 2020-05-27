const Float:INF_FLOAT=Float:0x7F800000;

stock Float:GetDistanceBetweenPoints(Float:x1,Float:y1,Float:z1,Float:x2,Float:y2,Float:z2) //By Gabriel "Larcius" Cordes
{
	return floatadd(floatadd(floatsqroot(floatpower(floatsub(x1,x2),2)),floatsqroot(floatpower(floatsub(y1,y2),2))),floatsqroot(floatpower(floatsub(z1,z2),2)));
}

stock Float:GetDistanceToPoint(playerid,Float:x1,Float:y1,Float:z1) //By Gabriel "Larcius" Cordes
{
	if (IsPlayerConnected(playerid))
	{
		new Float:x2,Float:y2,Float:z2;
		GetPlayerPos(playerid,x2,y2,z2);
		return GetDistanceBetweenPoints(x1,y1,z1,x2,y2,z2);
	}
	return INF_FLOAT;
}

stock Float:GetDistanceBetweenPlayers(playerid,playerid2) //By Slick (Edited by Sacky and Gabriel "Larcius" Cordes)
{
	if(IsPlayerConnected(playerid) && IsPlayerConnected(playerid2))
	{
		new Float:x1,Float:y1,Float:z1;
		GetPlayerPos(playerid2,x1,y1,z1);
		return GetDistanceToPoint(playerid,x1,y1,z1);
	}
	return INF_FLOAT;
}

stock GetClosestPlayer(playerid) //By Slick (edited by Gabriel "Larcius" Cordes)
{
	if(IsPlayerConnected(playerid) && IsPlayerConnected(0))
	{
		new closestplayer=0;
		new Float:closestdist=GetDistanceBetweenPlayers(playerid,0);
		for(new playerid2=0; playerid2<MAX_PLAYERS; playerid2++)
		{
			new Float:dist = GetDistanceBetweenPlayers(playerid,playerid2);
			if ((dist < closestdist))
			{
				closestdist = dist;
				closestplayer = playerid;
			}
		}
		return closestplayer;
	}
	return -1;
}