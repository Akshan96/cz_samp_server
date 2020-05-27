GetXYInFrontOfPlayer(playerid, &Float:x, &Float:y, Float:distance)
{
	new Float:a;
	GetPlayerPos(playerid, x, y, a);
	GetPlayerFacingAngle(playerid, a);
	if (GetPlayerVehicleID(playerid))
	{
	  GetVehicleZAngle(GetPlayerVehicleID(playerid), a);
	}
	x += (distance * floatsin(-a, degrees));
	y += (distance * floatcos(-a, degrees));
}

RappelPlayer(playerid)
{
    new Float: Px, Float: Py, Float: Pz;
    GetPlayerPos(playerid, Px, Py, Pz);
    GetXYInFrontOfPlayer(playerid, Px, Py, 0.2);
    SetPlayerVelocity(playerid, 0.0, 0.0, -0.2);
	Rope[playerid] = CreateLineSegment(19087, 2.46, Px, Py, Pz, Px, Py, Pz - 1000.0, .RotX = 90.0, .objlengthoffset = -(2.46/2), .worldid = -1, .interiorid = -1, .playerid = -1, .maxlength = 1000.0);
	ApplyAnimation(playerid,"ped","abseil",4.0,0,0,0,1,0);
	return 1;
}

NotFalling(playerid)
{
	DestroyLineSegment(Rope[playerid]);
	ClearAnimations(playerid);
	IsRappelling[playerid] = 0;
	KillTimer(LandingChecker[playerid]);
	if(!playerData[playerid][playerAdminDuty])
		SetPlayerHealth(playerid, PlayerHealth[playerid]);
	return 1;
}

forward FallingChecker(playerid);
forward DeActivateRappel(playerid);
public FallingChecker(playerid)
{
    new Float:z;
    GetPlayerPos(playerid,z,z,z);
    if(LastZ[playerid] == z)
    {
        NotFalling(playerid);
	}
    LastZ[playerid] = z;
    return 1;
}

public DeActivateRappel(playerid)
{
	Rappel[playerid] = 0;
	return 1;
}