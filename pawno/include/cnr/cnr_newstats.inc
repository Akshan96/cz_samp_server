new PlayerText:newStatsTD[MAX_PLAYERS][30];

public OnPlayerClickPlayer(playerid, clickedplayerid, source)
{
	new msg[512];
	new id = clickedplayerid;
	format(msg, sizeof(msg), "%s Profile", playerData[id][playerNamee]);
	PlayerTextDrawSetString(playerid, newStatsTD[playerid][2], msg);
	if(playerData[id][playerCustomSkin] != -1 && playerData[id][playerVIPLevel] > 0)
		PlayerTextDrawSetPreviewModel(playerid, newStatsTD[playerid][6], playerData[id][playerCustomSkin]);
	else
		PlayerTextDrawSetPreviewModel(playerid, newStatsTD[playerid][6], 317);
	format(msg, sizeof(msg), "%d", playerData[id][playerKills]);
	PlayerTextDrawSetString(playerid, newStatsTD[playerid][16], msg);
	format(msg, sizeof(msg), "%d", playerData[id][playerDeaths]);
	PlayerTextDrawSetString(playerid, newStatsTD[playerid][17], msg);
	new Float:ratio = float(playerData[id][playerKills]) / float(playerData[id][playerDeaths]);
	format(msg, sizeof(msg), "%.2f", ratio);
	PlayerTextDrawSetString(playerid, newStatsTD[playerid][18], msg);
	switch(playerData[id][playerClass])
	{
		case CLASS_POLICE:
			format(msg, sizeof(msg), "~b~Police");
		case CLASS_CIA:
			format(msg, sizeof(msg), "~b~CIA");
		case CLASS_FBI:
			format(msg, sizeof(msg), "~b~FBI");
		case CLASS_SECRETSERVICE:
			format(msg, sizeof(msg), "~b~SPY");
		case CLASS_ARMY:
			format(msg, sizeof(msg), "~p~Army");
		case CLASS_MEDIC:
			format(msg, sizeof(msg), "~y~Medic");
		case CLASS_CIVILIAN:
			format(msg, sizeof(msg), "~w~Civilian");
		default:
			format(msg, sizeof(msg), "~r~Undefined");
	}
	PlayerTextDrawSetString(playerid, newStatsTD[playerid][19], msg);
	format(msg, sizeof(msg), "%d", playerData[id][playerWantedLevel]);
	PlayerTextDrawSetString(playerid, newStatsTD[playerid][20], msg);
	if(playerData[id][playerVIPLevel] > 0)
		PlayerTextDrawSetString(playerid, newStatsTD[playerid][21], "~g~Yes");
	else
		PlayerTextDrawSetString(playerid, newStatsTD[playerid][21], "~r~No");
	new jobArray[7][] =
	{
		{"Kidnapper"},
		{"Mechanic"},
		{"Hitman"},
		{"Weapon dealer"},
		{"Rapist"},
		{"Drug dealer"},
		{"Terrorist"}
	};
	if(playerData[id][playerJob] != -1)
		format(msg, sizeof(msg), "~g~%s", jobArray[playerData[id][playerJob]]);
	else
		format(msg, sizeof(msg), "~r~No Job");
	PlayerTextDrawSetString(playerid, newStatsTD[playerid][22], msg);
	new count = 0;

	// read the server rules
	if (playerData[playerid][rulesRead]) {count++; } 

	// find and claim a money bag
	if (playerData[playerid][moneyBags] >= 1) {count++; } 

	// first kill achievement
	if (playerData[playerid][playerKills] >= 1) {count++; } 

	// 50 kills achievement
	if (playerData[playerid][playerKills] >= 50) {count++; } 

	// 100 kills achievement
	if (playerData[playerid][playerKills] >= 500) {  count++; } 

	// 1000 xp achievement
	if (playerData[playerid][playerXP] >= 1000) {count++; } 

	// 5000 xp achievement
	if (playerData[playerid][playerXP] >= 5000) {  count++; } 

	// 10000 xp achievement
	if (playerData[playerid][playerXP] >= 10000) {  count++; } 

	// 20000 xp achievement
	if (playerData[playerid][playerXP] >= 20000) {  count++; } 

	// first robbery
	if (playerData[playerid][playerRobberies] >= 1) {count++; } 

	// 20 robberies
	if (playerData[playerid][playerRobberies] >= 20) {count++; } 

	// 50 robberies
	if (playerData[playerid][playerRobberies] >= 50) {  count++; } 

	// 100 robberies
	if (playerData[playerid][playerRobberies] >= 100) {  count++; } 

	// 1 arrest
	if (playerData[playerid][copArrests] >= 1) {  count++; } 

	// 20 arrests
	if (playerData[playerid][copArrests] >= 20) {  count++; } 

	// 50 arrests
	if (playerData[playerid][copArrests] >= 50) {  count++; } 

	// 100 arrests
	if (playerData[playerid][copArrests] >= 100) {  count++; } 

	// 1 contract kill
	if (playerData[playerid][hitsCompleted] == 1) {  count++; } 

	// 20 contract kills
	if (playerData[playerid][hitsCompleted] >= 20) {  count++; } 

	// 1 Street Robbery
	if (playerData[playerid][streetRobberies] >= 1) {  count++; } 

	// 10 Street Robberies
	if (playerData[playerid][streetRobberies] >= 10) {  count++; } 

	// 50 Street Robberies
	if (playerData[playerid][streetRobberies] >= 50) {  count++; } 

	// 1 Street Rape
	if (playerData[playerid][streetRapes] >= 1) {  count++; } 

	// 10 Street Rapes
	if (playerData[playerid][streetRapes] >= 10) {  count++; } 

	// 50 Street Rapes
	if (playerData[playerid][streetRapes] >= 50) {  count++; } 

	// 1 Street Kidnaps
	if (playerData[playerid][playersKidnapped] >= 1) {  count++; } 

	// 10 Street Kidnaps
	if (playerData[playerid][playersKidnapped] >= 10) {  count++; } 

	// 50 Street Kidnaps
	if (playerData[playerid][playersKidnapped] >= 50) {  count++; } 

	// 1 forklift mission
	if (playerData[playerid][forkliftCompleted] >= 1) {  count++; } 

	// 10 forklift missions
	if (playerData[playerid][forkliftCompleted] >= 10) {  count++; } 

	// 50 forklift missions
	if (playerData[playerid][forkliftCompleted] >= 50) {  count++; } 

	// 1 bomb defusal
	if (playerData[playerid][bombsDefused] >= 1) {  count++; } 

	// 10 bomb defusal
	if (playerData[playerid][bombsDefused] >= 10) {  count++; } 
	format(msg, sizeof(msg), "~r~%d/~g~32", count);
	PlayerTextDrawSetString(playerid, newStatsTD[playerid][23], msg);
	new weapon = GetPlayerWeapon(playerid);
	if(weapon != 0)
	{
	    if(weapon > 0 && weapon < 10)
			weapon += 330;
		else if(weapon >= 10 && weapon <= 15)
			weapon += 311;
		else if(weapon > 15 && weapon <= 31)
			weapon += 311;
		else if(weapon == 32)
			weapon = 372;
		else if(weapon > 32 && weapon <= 45)
			weapon += 340;
		else if(weapon == 46)
			weapon = 371;
		PlayerTextDrawSetPreviewModel(playerid, newStatsTD[playerid][28], weapon);
		format(msg, sizeof(msg), "(%W)", weapon);
	}
	else
	{
		PlayerTextDrawSetPreviewModel(playerid, newStatsTD[playerid][28], weapon + 317);
		format(msg, sizeof(msg), "~r~(No Guns)");
	}
	PlayerTextDrawSetString(playerid, newStatsTD[playerid][29], msg);
	for(new i = 0; i < 30; i++)
		PlayerTextDrawShow(playerid, newStatsTD[playerid][i]);

	return 1;
}

loadnewStats(playerid)
{
	newStatsTD[playerid][0] = CreatePlayerTextDraw(playerid, 201.000000, 188.133377, "box");
	PlayerTextDrawLetterSize(playerid, newStatsTD[playerid][0], 0.000000, 23.500007);
	PlayerTextDrawTextSize(playerid, newStatsTD[playerid][0], 438.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, newStatsTD[playerid][0], 1);
	PlayerTextDrawColor(playerid, newStatsTD[playerid][0], -1);
	PlayerTextDrawUseBox(playerid, newStatsTD[playerid][0], 1);
	PlayerTextDrawBoxColor(playerid, newStatsTD[playerid][0], -16776961);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, newStatsTD[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, newStatsTD[playerid][0], 255);
	PlayerTextDrawFont(playerid, newStatsTD[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, newStatsTD[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][0], 0);

	newStatsTD[playerid][1] = CreatePlayerTextDraw(playerid, 202.299957, 190.233840, "box");
	PlayerTextDrawLetterSize(playerid, newStatsTD[playerid][1], 0.000000, 23.099981);
	PlayerTextDrawTextSize(playerid, newStatsTD[playerid][1], 435.299957, 0.000000);
	PlayerTextDrawAlignment(playerid, newStatsTD[playerid][1], 1);
	PlayerTextDrawColor(playerid, newStatsTD[playerid][1], -1);
	PlayerTextDrawUseBox(playerid, newStatsTD[playerid][1], 1);
	PlayerTextDrawBoxColor(playerid, newStatsTD[playerid][1], 765);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, newStatsTD[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, newStatsTD[playerid][1], 255);
	PlayerTextDrawFont(playerid, newStatsTD[playerid][1], 1);
	PlayerTextDrawSetProportional(playerid, newStatsTD[playerid][1], 1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][1], 0);

	newStatsTD[playerid][2] = CreatePlayerTextDraw(playerid, 321.000000, 188.133316, "X337 PROFILE");
	PlayerTextDrawLetterSize(playerid, newStatsTD[playerid][2], 0.412000, 1.907996);
	PlayerTextDrawAlignment(playerid, newStatsTD[playerid][2], 2);
	PlayerTextDrawColor(playerid, newStatsTD[playerid][2], -1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][2], 1);
	PlayerTextDrawSetOutline(playerid, newStatsTD[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, newStatsTD[playerid][2], -16776961);
	PlayerTextDrawFont(playerid, newStatsTD[playerid][2], 2);
	PlayerTextDrawSetProportional(playerid, newStatsTD[playerid][2], 1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][2], 1);

	newStatsTD[playerid][3] = CreatePlayerTextDraw(playerid, 253.200012, 204.933258, ".");
	PlayerTextDrawLetterSize(playerid, newStatsTD[playerid][3], 13.075006, 0.890666);
	PlayerTextDrawAlignment(playerid, newStatsTD[playerid][3], 1);
	PlayerTextDrawColor(playerid, newStatsTD[playerid][3], -1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, newStatsTD[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, newStatsTD[playerid][3], 255);
	PlayerTextDrawFont(playerid, newStatsTD[playerid][3], 1);
	PlayerTextDrawSetProportional(playerid, newStatsTD[playerid][3], 1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][3], 0);

	newStatsTD[playerid][4] = CreatePlayerTextDraw(playerid, 210.000000, 239.466735, "box");
	PlayerTextDrawLetterSize(playerid, newStatsTD[playerid][4], 0.000000, 16.700000);
	PlayerTextDrawTextSize(playerid, newStatsTD[playerid][4], 273.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, newStatsTD[playerid][4], 1);
	PlayerTextDrawColor(playerid, newStatsTD[playerid][4], -1);
	PlayerTextDrawUseBox(playerid, newStatsTD[playerid][4], 1);
	PlayerTextDrawBoxColor(playerid, newStatsTD[playerid][4], -16776961);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, newStatsTD[playerid][4], 0);
	PlayerTextDrawBackgroundColor(playerid, newStatsTD[playerid][4], -16776961);
	PlayerTextDrawFont(playerid, newStatsTD[playerid][4], 1);
	PlayerTextDrawSetProportional(playerid, newStatsTD[playerid][4], 1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][4], 0);

	newStatsTD[playerid][5] = CreatePlayerTextDraw(playerid, 212.000000, 241.899978, "box");
	PlayerTextDrawLetterSize(playerid, newStatsTD[playerid][5], 0.000000, 16.199998);
	PlayerTextDrawTextSize(playerid, newStatsTD[playerid][5], 271.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, newStatsTD[playerid][5], 1);
	PlayerTextDrawColor(playerid, newStatsTD[playerid][5], -1);
	PlayerTextDrawUseBox(playerid, newStatsTD[playerid][5], 1);
	PlayerTextDrawBoxColor(playerid, newStatsTD[playerid][5], 255);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, newStatsTD[playerid][5], 0);
	PlayerTextDrawBackgroundColor(playerid, newStatsTD[playerid][5], 255);
	PlayerTextDrawFont(playerid, newStatsTD[playerid][5], 1);
	PlayerTextDrawSetProportional(playerid, newStatsTD[playerid][5], 1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][5], 0);

	newStatsTD[playerid][6] = CreatePlayerTextDraw(playerid, 167.000000, 232.800003, "_");
	PlayerTextDrawLetterSize(playerid, newStatsTD[playerid][6], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, newStatsTD[playerid][6], 144.000000, 159.066665);
	PlayerTextDrawAlignment(playerid, newStatsTD[playerid][6], 1);
	PlayerTextDrawColor(playerid, newStatsTD[playerid][6], -1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, newStatsTD[playerid][6], 0);
	PlayerTextDrawBackgroundColor(playerid, newStatsTD[playerid][6], 0);
	PlayerTextDrawFont(playerid, newStatsTD[playerid][6], 5);
	PlayerTextDrawSetProportional(playerid, newStatsTD[playerid][6], 1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][6], 0);
	PlayerTextDrawSetPreviewModel(playerid, newStatsTD[playerid][6], 0);
	PlayerTextDrawSetPreviewRot(playerid, newStatsTD[playerid][6], 0.000000, 0.000000, 0.000000, 1.000000);

	newStatsTD[playerid][7] = CreatePlayerTextDraw(playerid, 240.600036, 223.766754, "Custom Skin");
	PlayerTextDrawLetterSize(playerid, newStatsTD[playerid][7], 0.260000, 1.142666);
	PlayerTextDrawAlignment(playerid, newStatsTD[playerid][7], 2);
	PlayerTextDrawColor(playerid, newStatsTD[playerid][7], -1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][7], 0);
	PlayerTextDrawSetOutline(playerid, newStatsTD[playerid][7], 0);
	PlayerTextDrawBackgroundColor(playerid, newStatsTD[playerid][7], 255);
	PlayerTextDrawFont(playerid, newStatsTD[playerid][7], 2);
	PlayerTextDrawSetProportional(playerid, newStatsTD[playerid][7], 1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][7], 0);

	newStatsTD[playerid][8] = CreatePlayerTextDraw(playerid, 283.500030, 247.833358, "Total Kills");
	PlayerTextDrawLetterSize(playerid, newStatsTD[playerid][8], 0.400000, 1.600000);
	PlayerTextDrawAlignment(playerid, newStatsTD[playerid][8], 1);
	PlayerTextDrawColor(playerid, newStatsTD[playerid][8], -1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][8], 0);
	PlayerTextDrawSetOutline(playerid, newStatsTD[playerid][8], 0);
	PlayerTextDrawBackgroundColor(playerid, newStatsTD[playerid][8], 255);
	PlayerTextDrawFont(playerid, newStatsTD[playerid][8], 1);
	PlayerTextDrawSetProportional(playerid, newStatsTD[playerid][8], 1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][8], 0);

	newStatsTD[playerid][9] = CreatePlayerTextDraw(playerid, 284.000000, 265.366577, "Total Deaths");
	PlayerTextDrawLetterSize(playerid, newStatsTD[playerid][9], 0.400000, 1.600000);
	PlayerTextDrawAlignment(playerid, newStatsTD[playerid][9], 1);
	PlayerTextDrawColor(playerid, newStatsTD[playerid][9], -1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][9], 0);
	PlayerTextDrawSetOutline(playerid, newStatsTD[playerid][9], 0);
	PlayerTextDrawBackgroundColor(playerid, newStatsTD[playerid][9], 255);
	PlayerTextDrawFont(playerid, newStatsTD[playerid][9], 1);
	PlayerTextDrawSetProportional(playerid, newStatsTD[playerid][9], 1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][9], 0);

	newStatsTD[playerid][10] = CreatePlayerTextDraw(playerid, 285.100006, 282.799835, "Ratio");
	PlayerTextDrawLetterSize(playerid, newStatsTD[playerid][10], 0.400000, 1.600000);
	PlayerTextDrawAlignment(playerid, newStatsTD[playerid][10], 1);
	PlayerTextDrawColor(playerid, newStatsTD[playerid][10], -1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][10], 0);
	PlayerTextDrawSetOutline(playerid, newStatsTD[playerid][10], 0);
	PlayerTextDrawBackgroundColor(playerid, newStatsTD[playerid][10], 255);
	PlayerTextDrawFont(playerid, newStatsTD[playerid][10], 1);
	PlayerTextDrawSetProportional(playerid, newStatsTD[playerid][10], 1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][10], 0);

	newStatsTD[playerid][11] = CreatePlayerTextDraw(playerid, 285.300018, 301.166503, "Team");
	PlayerTextDrawLetterSize(playerid, newStatsTD[playerid][11], 0.400000, 1.600000);
	PlayerTextDrawAlignment(playerid, newStatsTD[playerid][11], 1);
	PlayerTextDrawColor(playerid, newStatsTD[playerid][11], -1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][11], 0);
	PlayerTextDrawSetOutline(playerid, newStatsTD[playerid][11], 0);
	PlayerTextDrawBackgroundColor(playerid, newStatsTD[playerid][11], 255);
	PlayerTextDrawFont(playerid, newStatsTD[playerid][11], 1);
	PlayerTextDrawSetProportional(playerid, newStatsTD[playerid][11], 1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][11], 0);

	newStatsTD[playerid][12] = CreatePlayerTextDraw(playerid, 284.599975, 320.666442, "Wanted Level");
	PlayerTextDrawLetterSize(playerid, newStatsTD[playerid][12], 0.400000, 1.600000);
	PlayerTextDrawAlignment(playerid, newStatsTD[playerid][12], 1);
	PlayerTextDrawColor(playerid, newStatsTD[playerid][12], -1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][12], 0);
	PlayerTextDrawSetOutline(playerid, newStatsTD[playerid][12], 0);
	PlayerTextDrawBackgroundColor(playerid, newStatsTD[playerid][12], 255);
	PlayerTextDrawFont(playerid, newStatsTD[playerid][12], 1);
	PlayerTextDrawSetProportional(playerid, newStatsTD[playerid][12], 1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][12], 0);

	newStatsTD[playerid][13] = CreatePlayerTextDraw(playerid, 285.300018, 339.466674, "VIP");
	PlayerTextDrawLetterSize(playerid, newStatsTD[playerid][13], 0.400000, 1.600000);
	PlayerTextDrawAlignment(playerid, newStatsTD[playerid][13], 1);
	PlayerTextDrawColor(playerid, newStatsTD[playerid][13], -1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][13], 0);
	PlayerTextDrawSetOutline(playerid, newStatsTD[playerid][13], 0);
	PlayerTextDrawBackgroundColor(playerid, newStatsTD[playerid][13], 255);
	PlayerTextDrawFont(playerid, newStatsTD[playerid][13], 1);
	PlayerTextDrawSetProportional(playerid, newStatsTD[playerid][13], 1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][13], 0);

	newStatsTD[playerid][14] = CreatePlayerTextDraw(playerid, 286.299957, 357.599945, "Player Job");
	PlayerTextDrawLetterSize(playerid, newStatsTD[playerid][14], 0.400000, 1.600000);
	PlayerTextDrawAlignment(playerid, newStatsTD[playerid][14], 1);
	PlayerTextDrawColor(playerid, newStatsTD[playerid][14], -1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][14], 0);
	PlayerTextDrawSetOutline(playerid, newStatsTD[playerid][14], 0);
	PlayerTextDrawBackgroundColor(playerid, newStatsTD[playerid][14], 255);
	PlayerTextDrawFont(playerid, newStatsTD[playerid][14], 1);
	PlayerTextDrawSetProportional(playerid, newStatsTD[playerid][14], 1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][14], 0);

	newStatsTD[playerid][15] = CreatePlayerTextDraw(playerid, 285.299957, 373.866516, "Achievements");
	PlayerTextDrawLetterSize(playerid, newStatsTD[playerid][15], 0.400000, 1.600000);
	PlayerTextDrawAlignment(playerid, newStatsTD[playerid][15], 1);
	PlayerTextDrawColor(playerid, newStatsTD[playerid][15], -1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][15], 0);
	PlayerTextDrawSetOutline(playerid, newStatsTD[playerid][15], 0);
	PlayerTextDrawBackgroundColor(playerid, newStatsTD[playerid][15], 255);
	PlayerTextDrawFont(playerid, newStatsTD[playerid][15], 1);
	PlayerTextDrawSetProportional(playerid, newStatsTD[playerid][15], 1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][15], 0);

	newStatsTD[playerid][16] = CreatePlayerTextDraw(playerid, 432.400024, 246.900054, "0");
	PlayerTextDrawLetterSize(playerid, newStatsTD[playerid][16], 0.400000, 1.600000);
	PlayerTextDrawAlignment(playerid, newStatsTD[playerid][16], 3);
	PlayerTextDrawColor(playerid, newStatsTD[playerid][16], -1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][16], 0);
	PlayerTextDrawSetOutline(playerid, newStatsTD[playerid][16], 0);
	PlayerTextDrawBackgroundColor(playerid, newStatsTD[playerid][16], 255);
	PlayerTextDrawFont(playerid, newStatsTD[playerid][16], 1);
	PlayerTextDrawSetProportional(playerid, newStatsTD[playerid][16], 1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][16], 0);

	newStatsTD[playerid][17] = CreatePlayerTextDraw(playerid, 433.000000, 266.533294, "0");
	PlayerTextDrawLetterSize(playerid, newStatsTD[playerid][17], 0.400000, 1.600000);
	PlayerTextDrawAlignment(playerid, newStatsTD[playerid][17], 3);
	PlayerTextDrawColor(playerid, newStatsTD[playerid][17], -1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][17], 0);
	PlayerTextDrawSetOutline(playerid, newStatsTD[playerid][17], 0);
	PlayerTextDrawBackgroundColor(playerid, newStatsTD[playerid][17], 255);
	PlayerTextDrawFont(playerid, newStatsTD[playerid][17], 1);
	PlayerTextDrawSetProportional(playerid, newStatsTD[playerid][17], 1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][17], 0);

	newStatsTD[playerid][18] = CreatePlayerTextDraw(playerid, 433.000000, 285.199981, "0");
	PlayerTextDrawLetterSize(playerid, newStatsTD[playerid][18], 0.400000, 1.600000);
	PlayerTextDrawAlignment(playerid, newStatsTD[playerid][18], 3);
	PlayerTextDrawColor(playerid, newStatsTD[playerid][18], -1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][18], 0);
	PlayerTextDrawSetOutline(playerid, newStatsTD[playerid][18], 0);
	PlayerTextDrawBackgroundColor(playerid, newStatsTD[playerid][18], 255);
	PlayerTextDrawFont(playerid, newStatsTD[playerid][18], 1);
	PlayerTextDrawSetProportional(playerid, newStatsTD[playerid][18], 1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][18], 0);

	newStatsTD[playerid][19] = CreatePlayerTextDraw(playerid, 432.000000, 302.933197, "Civilian");
	PlayerTextDrawLetterSize(playerid, newStatsTD[playerid][19], 0.400000, 1.600000);
	PlayerTextDrawAlignment(playerid, newStatsTD[playerid][19], 3);
	PlayerTextDrawColor(playerid, newStatsTD[playerid][19], -1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][19], 0);
	PlayerTextDrawSetOutline(playerid, newStatsTD[playerid][19], 0);
	PlayerTextDrawBackgroundColor(playerid, newStatsTD[playerid][19], 255);
	PlayerTextDrawFont(playerid, newStatsTD[playerid][19], 1);
	PlayerTextDrawSetProportional(playerid, newStatsTD[playerid][19], 1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][19], 0);

	newStatsTD[playerid][20] = CreatePlayerTextDraw(playerid, 433.000000, 320.666717, "0");
	PlayerTextDrawLetterSize(playerid, newStatsTD[playerid][20], 0.400000, 1.600000);
	PlayerTextDrawAlignment(playerid, newStatsTD[playerid][20], 3);
	PlayerTextDrawColor(playerid, newStatsTD[playerid][20], -1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][20], 0);
	PlayerTextDrawSetOutline(playerid, newStatsTD[playerid][20], 0);
	PlayerTextDrawBackgroundColor(playerid, newStatsTD[playerid][20], 255);
	PlayerTextDrawFont(playerid, newStatsTD[playerid][20], 1);
	PlayerTextDrawSetProportional(playerid, newStatsTD[playerid][20], 1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][20], 0);

	newStatsTD[playerid][21] = CreatePlayerTextDraw(playerid, 434.000000, 340.266510, "No");
	PlayerTextDrawLetterSize(playerid, newStatsTD[playerid][21], 0.400000, 1.600000);
	PlayerTextDrawAlignment(playerid, newStatsTD[playerid][21], 3);
	PlayerTextDrawColor(playerid, newStatsTD[playerid][21], -1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][21], 0);
	PlayerTextDrawSetOutline(playerid, newStatsTD[playerid][21], 0);
	PlayerTextDrawBackgroundColor(playerid, newStatsTD[playerid][21], 255);
	PlayerTextDrawFont(playerid, newStatsTD[playerid][21], 1);
	PlayerTextDrawSetProportional(playerid, newStatsTD[playerid][21], 1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][21], 0);

	newStatsTD[playerid][22] = CreatePlayerTextDraw(playerid, 433.000000, 358.000000, "Terrorist");
	PlayerTextDrawLetterSize(playerid, newStatsTD[playerid][22], 0.400000, 1.600000);
	PlayerTextDrawAlignment(playerid, newStatsTD[playerid][22], 3);
	PlayerTextDrawColor(playerid, newStatsTD[playerid][22], -1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][22], 0);
	PlayerTextDrawSetOutline(playerid, newStatsTD[playerid][22], 0);
	PlayerTextDrawBackgroundColor(playerid, newStatsTD[playerid][22], 255);
	PlayerTextDrawFont(playerid, newStatsTD[playerid][22], 1);
	PlayerTextDrawSetProportional(playerid, newStatsTD[playerid][22], 1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][22], 0);

	newStatsTD[playerid][23] = CreatePlayerTextDraw(playerid, 434.000000, 373.866638, "0");
	PlayerTextDrawLetterSize(playerid, newStatsTD[playerid][23], 0.400000, 1.600000);
	PlayerTextDrawAlignment(playerid, newStatsTD[playerid][23], 3);
	PlayerTextDrawColor(playerid, newStatsTD[playerid][23], -1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][23], 0);
	PlayerTextDrawSetOutline(playerid, newStatsTD[playerid][23], 0);
	PlayerTextDrawBackgroundColor(playerid, newStatsTD[playerid][23], 255);
	PlayerTextDrawFont(playerid, newStatsTD[playerid][23], 1);
	PlayerTextDrawSetProportional(playerid, newStatsTD[playerid][23], 1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][23], 0);

	newStatsTD[playerid][24] = CreatePlayerTextDraw(playerid, 317.000000, 213.333328, "Type /closehelp to close");
	PlayerTextDrawLetterSize(playerid, newStatsTD[playerid][24], 0.200000, 1.254665);
	PlayerTextDrawAlignment(playerid, newStatsTD[playerid][24], 1);
	PlayerTextDrawColor(playerid, newStatsTD[playerid][24], -1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][24], 2);
	PlayerTextDrawSetOutline(playerid, newStatsTD[playerid][24], 0);
	PlayerTextDrawBackgroundColor(playerid, newStatsTD[playerid][24], 255);
	PlayerTextDrawFont(playerid, newStatsTD[playerid][24], 2);
	PlayerTextDrawSetProportional(playerid, newStatsTD[playerid][24], 1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][24], 2);

	newStatsTD[playerid][25] = CreatePlayerTextDraw(playerid, 48.000000, 166.666671, "box");
	PlayerTextDrawLetterSize(playerid, newStatsTD[playerid][25], 0.000000, 7.699993);
	PlayerTextDrawTextSize(playerid, newStatsTD[playerid][25], 172.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, newStatsTD[playerid][25], 1);
	PlayerTextDrawColor(playerid, newStatsTD[playerid][25], -1);
	PlayerTextDrawUseBox(playerid, newStatsTD[playerid][25], 1);
	PlayerTextDrawBoxColor(playerid, newStatsTD[playerid][25], -16776961);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][25], 0);
	PlayerTextDrawSetOutline(playerid, newStatsTD[playerid][25], 0);
	PlayerTextDrawBackgroundColor(playerid, newStatsTD[playerid][25], 255);
	PlayerTextDrawFont(playerid, newStatsTD[playerid][25], 1);
	PlayerTextDrawSetProportional(playerid, newStatsTD[playerid][25], 1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][25], 0);

	newStatsTD[playerid][26] = CreatePlayerTextDraw(playerid, 49.000000, 168.533340, "box");
	PlayerTextDrawLetterSize(playerid, newStatsTD[playerid][26], 0.000000, 7.299993);
	PlayerTextDrawTextSize(playerid, newStatsTD[playerid][26], 170.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, newStatsTD[playerid][26], 1);
	PlayerTextDrawColor(playerid, newStatsTD[playerid][26], -1);
	PlayerTextDrawUseBox(playerid, newStatsTD[playerid][26], 1);
	PlayerTextDrawBoxColor(playerid, newStatsTD[playerid][26], 255);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][26], 0);
	PlayerTextDrawSetOutline(playerid, newStatsTD[playerid][26], 0);
	PlayerTextDrawBackgroundColor(playerid, newStatsTD[playerid][26], 255);
	PlayerTextDrawFont(playerid, newStatsTD[playerid][26], 1);
	PlayerTextDrawSetProportional(playerid, newStatsTD[playerid][26], 1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][26], 0);

	newStatsTD[playerid][27] = CreatePlayerTextDraw(playerid, 48.000000, 166.666641, "Current Weapon");
	PlayerTextDrawLetterSize(playerid, newStatsTD[playerid][27], 0.273000, 1.039998);
	PlayerTextDrawAlignment(playerid, newStatsTD[playerid][27], 1);
	PlayerTextDrawColor(playerid, newStatsTD[playerid][27], -1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][27], 0);
	PlayerTextDrawSetOutline(playerid, newStatsTD[playerid][27], 0);
	PlayerTextDrawBackgroundColor(playerid, newStatsTD[playerid][27], 255);
	PlayerTextDrawFont(playerid, newStatsTD[playerid][27], 2);
	PlayerTextDrawSetProportional(playerid, newStatsTD[playerid][27], 1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][27], 0);

	newStatsTD[playerid][28] = CreatePlayerTextDraw(playerid, 156.000000, 144.733322, "_");
	PlayerTextDrawLetterSize(playerid, newStatsTD[playerid][28], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, newStatsTD[playerid][28], -169.000000, 132.000030);
	PlayerTextDrawAlignment(playerid, newStatsTD[playerid][28], 1);
	PlayerTextDrawColor(playerid, newStatsTD[playerid][28], -1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][28], 0);
	PlayerTextDrawSetOutline(playerid, newStatsTD[playerid][28], 0);
	PlayerTextDrawBackgroundColor(playerid, newStatsTD[playerid][28], 0);
	PlayerTextDrawFont(playerid, newStatsTD[playerid][28], 5);
	PlayerTextDrawSetProportional(playerid, newStatsTD[playerid][28], 1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][28], 0);
	PlayerTextDrawSetPreviewModel(playerid, newStatsTD[playerid][28], 351);
	PlayerTextDrawSetPreviewRot(playerid, newStatsTD[playerid][28], 0.000000, 0.000000, 50.000000, 3.000000);

	newStatsTD[playerid][29] = CreatePlayerTextDraw(playerid, 170.000000, 222.666702, "(SPAS)");
	PlayerTextDrawLetterSize(playerid, newStatsTD[playerid][29], 0.327000, 1.226666);
	PlayerTextDrawAlignment(playerid, newStatsTD[playerid][29], 3);
	PlayerTextDrawColor(playerid, newStatsTD[playerid][29], -1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][29], 0);
	PlayerTextDrawSetOutline(playerid, newStatsTD[playerid][29], 0);
	PlayerTextDrawBackgroundColor(playerid, newStatsTD[playerid][29], 255);
	PlayerTextDrawFont(playerid, newStatsTD[playerid][29], 1);
	PlayerTextDrawSetProportional(playerid, newStatsTD[playerid][29], 1);
	PlayerTextDrawSetShadow(playerid, newStatsTD[playerid][29], 0);
}
