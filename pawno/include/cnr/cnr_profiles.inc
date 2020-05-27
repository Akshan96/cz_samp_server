/* 
	CNRSF Profiles
*/

new 
	Text:ProfileBG
;

stock profileStuff()
{
	ProfileBG = TextDrawCreate(194.500, 125.500, "loadsc2:loadsc2");
	TextDrawFont(ProfileBG, 4);
	TextDrawTextSize(ProfileBG, 247.000, 205.000);
	TextDrawColor(ProfileBG, -1);
}

COMMAND:profile(playerid, params[])
{
	TextDrawShowForPlayer(playerid, ProfileBG);
	return 1;
}

COMMAND:closeprofile(playerid, params[])
{
	TextDrawHideForPlayer(playerid, ProfileBG);
	return 1;
}