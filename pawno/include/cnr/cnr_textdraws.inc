forward buildTextDraws();
forward drawGamemodeInitTextdraws();

public buildTextDraws()
{

}

public drawGamemodeInitTextdraws()
{
	alog1 = TextDrawCreate(149.000000, 352.000000 , alog[1]);
	TextDrawFont(alog1 , 1);
	TextDrawLetterSize(alog1 , 0.250000, 1.099999);
	TextDrawColor(alog1 , 0xFFFFFFFF);
	TextDrawSetOutline(alog1 , false);
	TextDrawSetProportional(alog1 , true);
	TextDrawSetShadow(alog1 , 1);

	alog2 = TextDrawCreate(149.000000, 362.000000 , alog[2]);
	TextDrawFont(alog2 , 1);
	TextDrawLetterSize(alog2 , 0.250000, 1.099999);
	TextDrawColor(alog2 , 0xFFFFFFFF);
	TextDrawSetOutline(alog2 , false);
	TextDrawSetProportional(alog2 , true);
	TextDrawSetShadow(alog2 , 1);

	alog3 = TextDrawCreate(149.000000, 372.000000 , alog[3]);
	TextDrawFont(alog3 , 1);
	TextDrawLetterSize(alog3 , 0.250000, 1.099999);
	TextDrawColor(alog3 , 0xFFFFFFFF);
	TextDrawSetOutline(alog3 , false);
	TextDrawSetProportional(alog3 , true);
	TextDrawSetShadow(alog3, 1);

	alog4 = TextDrawCreate(149.000000, 382.000000 , alog[4]);
	TextDrawFont(alog4 , 1);
	TextDrawLetterSize(alog4 , 0.250000, 1.099999);
	TextDrawColor(alog4 , 0xFFFFFFFF);
	TextDrawSetOutline(alog4 , false);
	TextDrawSetProportional(alog4 , true);
	TextDrawSetShadow(alog4, 1);

	alog5 = TextDrawCreate(149.000000, 392.000000 , alog[5]);
	TextDrawFont(alog5 , 1);
	TextDrawLetterSize(alog5 , 0.250000, 1.099999);
	TextDrawColor(alog5 , 0xFFFFFFFF);
	TextDrawSetOutline(alog5 , false);
	TextDrawSetProportional(alog5 , true);
	TextDrawSetShadow(alog5, 1);

	URLTD = TextDrawCreate(48.000000, 428.000000, "www.underprogress.com");
	TextDrawBackgroundColor(URLTD, 0x00000096);
	TextDrawFont(URLTD, 1);
	TextDrawLetterSize(URLTD, 0.280000, 1.100000);
	TextDrawColor(URLTD, -1);
	TextDrawSetOutline(URLTD, 0);
	TextDrawSetProportional(URLTD, 1);
	TextDrawSetShadow(URLTD, 1);
	TextDrawSetSelectable(URLTD, 0);

	TDCourier = TextDrawCreate(266.000000, 145.000000, "LOADING CARGO...");
	TextDrawBackgroundColor(TDCourier, 255);
	TextDrawFont(TDCourier, 1);
	TextDrawLetterSize(TDCourier, 0.360000, 1.699999);
	TextDrawColor(TDCourier, -1);
	TextDrawSetOutline(TDCourier, 0);
	TextDrawSetProportional(TDCourier, 1);
	TextDrawSetShadow(TDCourier, 1);
	TextDrawSetSelectable(TDCourier, 0);

	TDCourier2 = TextDrawCreate(266.000000, 145.000000, "UNLOADING CARGO...");
	TextDrawBackgroundColor(TDCourier2, 255);
	TextDrawFont(TDCourier2, 1);
	TextDrawLetterSize(TDCourier2, 0.360000, 1.699999);
	TextDrawColor(TDCourier2, -1);
	TextDrawSetOutline(TDCourier2, 0);
	TextDrawSetProportional(TDCourier2, 1);
	TextDrawSetShadow(TDCourier2, 1);
	TextDrawSetSelectable(TDCourier2, 0);

	AnnounceTD = TextDrawCreate(320.000000, 140.000000, "");
	TextDrawAlignment(AnnounceTD, 2);
	TextDrawBackgroundColor(AnnounceTD, 255);
	TextDrawFont(AnnounceTD, 1);
	TextDrawLetterSize(AnnounceTD, 0.329999, 1.500002);
	TextDrawColor(AnnounceTD, -1);
	TextDrawSetOutline(AnnounceTD, 1);
	TextDrawSetProportional(AnnounceTD, 1);
	TextDrawSetSelectable(AnnounceTD, 0);

	SetTimer("Timer", MINUTE, 1);
    TextDrawHideForAll(gTime);
    TextDrawHideForAll(gDay);

	gTime = TextDrawCreate(605.000000, 25.000000, "00:00");
	TextDrawAlignment(gTime, 3);
	TextDrawBackgroundColor(gTime, 0x000000FF);
	TextDrawFont(gTime, 0);
	TextDrawLetterSize(gTime, 0.535, 2.2);
	TextDrawColor(gTime, COLOR_TIME);
	TextDrawSetOutline(gTime, 1);
	TextDrawSetProportional(gTime, 1);
	TextDrawSetShadow(gTime, 1);

	gDay = TextDrawCreate(610.000000, 7.000000, "Sunday");
	TextDrawUseBox(gDay,0);
	TextDrawFont(gDay, 0);
	TextDrawLetterSize(gDay, 0.6, 1.5);
	TextDrawSetShadow(gDay, 1);
	TextDrawSetOutline(gDay, 0);
	TextDrawBackgroundColor(gDay, 0x000000FF);
	TextDrawBoxColor(gDay, 0x00000066);
	TextDrawColor(gDay,COLOR_DAY);
	TextDrawTextSize(gDay, -1880.0, -1880.0);
	TextDrawAlignment(gDay, 3);
	TextDrawSetOutline(gDay, 1);

    TextDrawShowForAll(gTime);
    TextDrawShowForAll(gDay);

	AdminDuty = TextDrawCreate(286.000000, 405.066467, "Admin on Duty");
	TextDrawBackgroundColor(AdminDuty, 255);
	TextDrawFont(AdminDuty, 0);
	TextDrawLetterSize(AdminDuty, 0.449999, 1.600000);
	TextDrawColor(AdminDuty, 0x4F0BCAAD);
	TextDrawSetOutline(AdminDuty, 1);
	TextDrawSetProportional(AdminDuty, 1);
	TextDrawSetShadow(AdminDuty, 0);
	TextDrawSetSelectable(AdminDuty, 0);

	doubleXPTD = TextDrawCreate(554.000000, 390.666473, "DOUBLE XP ~g~ON");
	TextDrawLetterSize(doubleXPTD, 0.317000, 1.431998);
	TextDrawAlignment(doubleXPTD, 1);
	TextDrawColor(doubleXPTD, -1);
	TextDrawSetShadow(doubleXPTD, 2);
	TextDrawSetOutline(doubleXPTD, 0);
	TextDrawBackgroundColor(doubleXPTD, 255);
	TextDrawFont(doubleXPTD, 1);
	TextDrawSetProportional(doubleXPTD, 1);
	TextDrawSetShadow(doubleXPTD, 2);
	TextDrawSetSelectable(doubleXPTD, false);

	MOTDTD = TextDrawCreate(320.000000, 429.000000, " ");
	TextDrawAlignment(MOTDTD, 2);
	TextDrawBackgroundColor(MOTDTD, 255);
	TextDrawFont(MOTDTD, 1);
	TextDrawLetterSize(MOTDTD, 0.300000, 1.000000);
	TextDrawColor(MOTDTD, -23449857);
	TextDrawSetOutline(MOTDTD, 0);
	TextDrawSetProportional(MOTDTD, 1);
	TextDrawSetShadow(MOTDTD, 1);

	bankTD = TextDrawCreate(553.000000, 366.000000, " ");
	TextDrawAlignment(bankTD, 2);
	TextDrawBackgroundColor(bankTD, 255);
	TextDrawFont(bankTD, 1);
	TextDrawLetterSize(bankTD, 0.280000, 1.000000);
	TextDrawColor(bankTD, -1);
	TextDrawSetOutline(bankTD, 0);
	TextDrawSetProportional(bankTD, 1);
	TextDrawSetShadow(bankTD, 1);
	TextDrawUseBox(bankTD, 1);
	TextDrawBoxColor(bankTD, 255);
	TextDrawTextSize(bankTD, 371.000000, 110.000000);
	TextDrawSetSelectable(bankTD, 0);

	loginDialog[5] = TextDrawCreate(320.000000, 144.000000, "~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~");
	TextDrawAlignment(loginDialog[5], 2);
	TextDrawBackgroundColor(loginDialog[5], 255);
	TextDrawFont(loginDialog[5], 1);
	TextDrawLetterSize(loginDialog[5], 0.500000, 1.000000);
	TextDrawColor(loginDialog[5], -1);
	TextDrawSetOutline(loginDialog[5], 0);
	TextDrawSetProportional(loginDialog[5], 1);
	TextDrawSetShadow(loginDialog[5], 1);
	TextDrawUseBox(loginDialog[5], 1);
	TextDrawBoxColor(loginDialog[5], 119);
	TextDrawTextSize(loginDialog[5], 10.000000, 293.000000);
	TextDrawSetSelectable(loginDialog[5], 0);

	loginDialog[0] = TextDrawCreate(243.000000, 140.000000, "~b~Cops ~w~and ~R~Robbers");
	TextDrawBackgroundColor(loginDialog[0], 255);
	TextDrawFont(loginDialog[0], 2);
	TextDrawLetterSize(loginDialog[0], 0.319999, 2.399998);
	TextDrawColor(loginDialog[0], -1);
	TextDrawSetOutline(loginDialog[0], 0);
	TextDrawSetProportional(loginDialog[0], 1);
	TextDrawSetShadow(loginDialog[0], 1);
	TextDrawSetSelectable(loginDialog[0], 0);

	loginDialog[1] = TextDrawCreate(320.000000, 288.000000, "~n~~n~");
	TextDrawAlignment(loginDialog[1], 2);
	TextDrawBackgroundColor(loginDialog[1], 255);
	TextDrawFont(loginDialog[1], 2);
	TextDrawLetterSize(loginDialog[1], 0.300000, 1.000000);
	TextDrawColor(loginDialog[1], -1);
	TextDrawSetOutline(loginDialog[1], 0);
	TextDrawSetProportional(loginDialog[1], 1);
	TextDrawSetShadow(loginDialog[1], 1);
	TextDrawUseBox(loginDialog[1], 1);
	TextDrawBoxColor(loginDialog[1], 255);
	TextDrawTextSize(loginDialog[1], -10.000000, 292.000000);
	TextDrawSetSelectable(loginDialog[1], 0);

	loginDialog[2] = TextDrawCreate(373.000000, 150.000000, "");
	TextDrawBackgroundColor(loginDialog[2], 51);
	TextDrawFont(loginDialog[2], 2);
	TextDrawLetterSize(loginDialog[2], 0.200000, 1.000000);
	TextDrawColor(loginDialog[2], -1);
	TextDrawSetOutline(loginDialog[2], 0);
	TextDrawSetProportional(loginDialog[2], 1);
	TextDrawSetShadow(loginDialog[2], 1);
	TextDrawSetSelectable(loginDialog[2], 0);

	loginDialog[3] = TextDrawCreate(320.000000, 143.000000, "~n~~n~");
	TextDrawAlignment(loginDialog[3], 2);
	TextDrawBackgroundColor(loginDialog[3], 255);
	TextDrawFont(loginDialog[3], 2);
	TextDrawLetterSize(loginDialog[3], 0.300000, 1.000000);
	TextDrawColor(loginDialog[3], -1);
	TextDrawSetOutline(loginDialog[3], 0);
	TextDrawSetProportional(loginDialog[3], 1);
	TextDrawSetShadow(loginDialog[3], 1);
	TextDrawUseBox(loginDialog[3], 1);
	TextDrawBoxColor(loginDialog[3], 255);
	TextDrawTextSize(loginDialog[3], -10.000000, 292.000000);
	TextDrawSetSelectable(loginDialog[3], 0);

	loginDialog[4] = TextDrawCreate(319.000000, 291.000000, "Welcome to CZCNR! Have fun!");
	TextDrawAlignment(loginDialog[4], 2);
	TextDrawBackgroundColor(loginDialog[4], 85);
	TextDrawFont(loginDialog[4], 2);
	TextDrawLetterSize(loginDialog[4], 0.409999, 1.300000);
	TextDrawColor(loginDialog[4], -1);
	TextDrawSetOutline(loginDialog[4], 0);
	TextDrawSetProportional(loginDialog[4], 1);
	TextDrawSetShadow(loginDialog[4], 1);
	TextDrawSetSelectable(loginDialog[4], 0);

	dmBox[0] = TextDrawCreate(553.000000, 281.000000, "~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~");
	TextDrawAlignment(dmBox[0], 2);
	TextDrawBackgroundColor(dmBox[0], 255);
	TextDrawFont(dmBox[0], 1);
	TextDrawLetterSize(dmBox[0], 0.500000, 1.000000);
	TextDrawColor(dmBox[0], -1);
	TextDrawSetOutline(dmBox[0], 0);
	TextDrawSetProportional(dmBox[0], 1);
	TextDrawSetShadow(dmBox[0], 1);
	TextDrawUseBox(dmBox[0], 1);
	TextDrawBoxColor(dmBox[0], 85);
	TextDrawTextSize(dmBox[0], 0.000000, 100.000000);

	dmBox[1] = TextDrawCreate(553.000000, 280.000000, "~n~~n~");
	TextDrawAlignment(dmBox[1], 2);
	TextDrawBackgroundColor(dmBox[1], 255);
	TextDrawFont(dmBox[1], 1);
	TextDrawLetterSize(dmBox[1], 0.500000, 1.000000);
	TextDrawColor(dmBox[1], -1);
	TextDrawSetOutline(dmBox[1], 0);
	TextDrawSetProportional(dmBox[1], 1);
	TextDrawSetShadow(dmBox[1], 1);
	TextDrawUseBox(dmBox[1], 1);
	TextDrawBoxColor(dmBox[1], 136);
	TextDrawTextSize(dmBox[1], 0.000000, 100.000000);

	dmBox[2] = TextDrawCreate(513.000000, 284.000000, "DM Arena Stats");
	TextDrawBackgroundColor(dmBox[2], 255);
	TextDrawFont(dmBox[2], 2);
	TextDrawLetterSize(dmBox[2], 0.230000, 1.000000);
	TextDrawColor(dmBox[2], -1);
	TextDrawSetOutline(dmBox[2], 0);
	TextDrawSetProportional(dmBox[2], 1);
	TextDrawSetShadow(dmBox[2], 1);

	dmBox[3] = TextDrawCreate(510.000000, 310.000000, "Kills:");
	TextDrawBackgroundColor(dmBox[3], 119);
	TextDrawFont(dmBox[3], 1);
	TextDrawLetterSize(dmBox[3], 0.300000, 1.000000);
	TextDrawColor(dmBox[3], -89368321);
	TextDrawSetOutline(dmBox[3], 0);
	TextDrawSetProportional(dmBox[3], 1);
	TextDrawSetShadow(dmBox[3], 1);

	dmBox[4] = TextDrawCreate(510.000000, 324.000000, "Deaths:");
	TextDrawBackgroundColor(dmBox[4], 119);
	TextDrawFont(dmBox[4], 1);
	TextDrawLetterSize(dmBox[4], 0.300000, 1.000000);
	TextDrawColor(dmBox[4], -94873345);
	TextDrawSetOutline(dmBox[4], 0);
	TextDrawSetProportional(dmBox[4], 1);
	TextDrawSetShadow(dmBox[4], 1);

	dmBox[5] = TextDrawCreate(510.000000, 339.000000, "K/D Ratio:");
	TextDrawBackgroundColor(dmBox[5], 119);
	TextDrawFont(dmBox[5], 1);
	TextDrawLetterSize(dmBox[5], 0.300000, 1.000000);
	TextDrawColor(dmBox[5], 1960771839);
	TextDrawSetOutline(dmBox[5], 0);
	TextDrawSetProportional(dmBox[5], 1);
	TextDrawSetShadow(dmBox[5], 1);

	dmBox[6] = TextDrawCreate(510.000000, 355.000000, "Kill Streak:");
	TextDrawBackgroundColor(dmBox[6], 119);
	TextDrawFont(dmBox[6], 1);
	TextDrawLetterSize(dmBox[6], 0.300000, 1.000000);
	TextDrawColor(dmBox[6], -1618872321);
	TextDrawSetOutline(dmBox[6], 0);
	TextDrawSetProportional(dmBox[6], 1);
	TextDrawSetShadow(dmBox[6], 1);

	streakBox[0] = TextDrawCreate(320.000000, 299.000000, "~n~~n~~n~~n~~n~~n~~n~~n~~n~");
	TextDrawAlignment(streakBox[0], 2);
	TextDrawBackgroundColor(streakBox[0], 255);
	TextDrawFont(streakBox[0], 1);
	TextDrawLetterSize(streakBox[0], 0.500000, 1.000000);
	TextDrawColor(streakBox[0], -1);
	TextDrawSetOutline(streakBox[0], 0);
	TextDrawSetProportional(streakBox[0], 1);
	TextDrawSetShadow(streakBox[0], 1);
	TextDrawUseBox(streakBox[0], 1);
	TextDrawBoxColor(streakBox[0], 85);
	TextDrawTextSize(streakBox[0], 160.000000, 210.000000);

	streakBox[1] = TextDrawCreate(320.000000, 277.000000, "~n~~n~");
	TextDrawAlignment(streakBox[1], 2);
	TextDrawBackgroundColor(streakBox[1], 255);
	TextDrawFont(streakBox[1], 1);
	TextDrawLetterSize(streakBox[1], 0.500000, 1.000000);
	TextDrawColor(streakBox[1], -1);
	TextDrawSetOutline(streakBox[1], 0);
	TextDrawSetProportional(streakBox[1], 1);
	TextDrawSetShadow(streakBox[1], 1);
	TextDrawUseBox(streakBox[1], 1);
	TextDrawBoxColor(streakBox[1], 255);
	TextDrawTextSize(streakBox[1], 160.000000, 210.000000);

	streakBox[2] = TextDrawCreate(320.000000, 280.000000, "~r~~h~kill streak unlocked");
	TextDrawAlignment(streakBox[2], 2);
	TextDrawBackgroundColor(streakBox[2], 255);
	TextDrawFont(streakBox[2], 2);
	TextDrawLetterSize(streakBox[2], 0.280000, 1.100000);
	TextDrawColor(streakBox[2], -1);
	TextDrawSetOutline(streakBox[2], 0);
	TextDrawSetProportional(streakBox[2], 1);
	TextDrawSetShadow(streakBox[2], 1);

	easterSunday = TextDrawCreate(501.000000, 380.000000, "~y~EASTER SUNDAY");
	TextDrawBackgroundColor(easterSunday, 34);
	TextDrawFont(easterSunday, 1);
	TextDrawLetterSize(easterSunday, 0.400000, 1.000000);
	TextDrawColor(easterSunday, 12582911);
	TextDrawSetOutline(easterSunday, 0);
	TextDrawSetProportional(easterSunday, 1);
	TextDrawSetShadow(easterSunday, 1);

	vehicleDealership[0] = TextDrawCreate(320.000000, 150.000000, "~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~");
	TextDrawAlignment(vehicleDealership[0], 2);
	TextDrawBackgroundColor(vehicleDealership[0], 255);
	TextDrawFont(vehicleDealership[0], 1);
	TextDrawLetterSize(vehicleDealership[0], 0.500000, 1.000000);
	TextDrawColor(vehicleDealership[0], -1);
	TextDrawSetOutline(vehicleDealership[0], 0);
	TextDrawSetProportional(vehicleDealership[0], 1);
	TextDrawSetShadow(vehicleDealership[0], 1);
	TextDrawUseBox(vehicleDealership[0], 1);
	TextDrawBoxColor(vehicleDealership[0], 85);
	TextDrawTextSize(vehicleDealership[0], 160.000000, 210.000000);

	vehicleDealership[1] = TextDrawCreate(319.000000, 162.000000, "Creating your vehicle...");
	TextDrawAlignment(vehicleDealership[1], 2);
	TextDrawBackgroundColor(vehicleDealership[1], 68);
	TextDrawFont(vehicleDealership[1], 2);
	TextDrawLetterSize(vehicleDealership[1], 0.230000, 1.299999);
	TextDrawColor(vehicleDealership[1], -1);
	TextDrawSetOutline(vehicleDealership[1], 0);
	TextDrawSetProportional(vehicleDealership[1], 1);
	TextDrawSetShadow(vehicleDealership[1], 1);

	vehicleDealership[2] = TextDrawCreate(320.000000, 127.000000, "~n~~n~");
	TextDrawAlignment(vehicleDealership[2], 2);
	TextDrawBackgroundColor(vehicleDealership[2], 255);
	TextDrawFont(vehicleDealership[2], 1);
	TextDrawLetterSize(vehicleDealership[2], 0.500000, 1.000000);
	TextDrawColor(vehicleDealership[2], -1);
	TextDrawSetOutline(vehicleDealership[2], 0);
	TextDrawSetProportional(vehicleDealership[2], 1);
	TextDrawSetShadow(vehicleDealership[2], 1);
	TextDrawUseBox(vehicleDealership[2], 1);
	TextDrawBoxColor(vehicleDealership[2], 255);
	TextDrawTextSize(vehicleDealership[2], 160.000000, 210.000000);

	vehicleDealership[3] = TextDrawCreate(260.000000, 130.000000, "~y~Vehicle Dealership");
	TextDrawBackgroundColor(vehicleDealership[3], 255);
	TextDrawFont(vehicleDealership[3], 2);
	TextDrawLetterSize(vehicleDealership[3], 0.280000, 1.100000);
	TextDrawColor(vehicleDealership[3], -1);
	TextDrawSetOutline(vehicleDealership[3], 0);
	TextDrawSetProportional(vehicleDealership[3], 1);
	TextDrawSetShadow(vehicleDealership[3], 1);
	
	TopTD[0] = TextDrawCreate(446.000152, 124.700004, "usebox");
	TextDrawLetterSize(TopTD[0], 0.000000, 28.222597);
	TextDrawTextSize(TopTD[0], 202.799957, 0.000000);
	TextDrawAlignment(TopTD[0], 1);
	TextDrawColor(TopTD[0], 0);
	TextDrawUseBox(TopTD[0], true);
	TextDrawBoxColor(TopTD[0], 102);
	TextDrawSetShadow(TopTD[0], 0);
	TextDrawSetOutline(TopTD[0], 0);
	TextDrawFont(TopTD[0], 0);

	TopTD[1] = TextDrawCreate(209.199996, 124.700004, "usebox");
	TextDrawLetterSize(TopTD[1], 0.000000, 28.222593);
	TextDrawTextSize(TopTD[1], 204.399993, 0.000000);
	TextDrawAlignment(TopTD[1], 1);
	TextDrawColor(TopTD[1], 0);
	TextDrawUseBox(TopTD[1], true);
	TextDrawBoxColor(TopTD[1], -5963521);
	TextDrawSetShadow(TopTD[1], 0);
	TextDrawSetOutline(TopTD[1], 0);
	TextDrawFont(TopTD[1], 0);

	TopTD[2] = TextDrawCreate(324.000030, 125.439964, "TOP KILLER");
	TextDrawLetterSize(TopTD[2], 0.497198, 2.742399);
	TextDrawAlignment(TopTD[2], 2);
	TextDrawColor(TopTD[2], -5963521);
	TextDrawSetShadow(TopTD[2], 0);
	TextDrawSetOutline(TopTD[2], 1);
	TextDrawBackgroundColor(TopTD[2], 51);
	TextDrawFont(TopTD[2], 2);
	TextDrawSetProportional(TopTD[2], 1);

	TopTD[3] = TextDrawCreate(229.600051, 142.613220, "............................................................");
	TextDrawLetterSize(TopTD[3], 0.297200, 1.361066);
	TextDrawAlignment(TopTD[3], 1);
	TextDrawColor(TopTD[3], -5963521);
	TextDrawSetShadow(TopTD[3], 0);
	TextDrawSetOutline(TopTD[3], 1);
	TextDrawBackgroundColor(TopTD[3], 51);
	TextDrawFont(TopTD[3], 0);
	TextDrawSetProportional(TopTD[3], 1);

	TopTD[4] = TextDrawCreate(217.599899, 163.519821, "1.");
	TextDrawLetterSize(TopTD[4], 0.449999, 1.600000);
	TextDrawAlignment(TopTD[4], 1);
	TextDrawColor(TopTD[4], -1);
	TextDrawSetShadow(TopTD[4], 0);
	TextDrawSetOutline(TopTD[4], 1);
	TextDrawBackgroundColor(TopTD[4], 51);
	TextDrawFont(TopTD[4], 1);
	TextDrawSetProportional(TopTD[4], 1);

	TopTD[5] = TextDrawCreate(217.799896, 180.199905, "2.");
	TextDrawLetterSize(TopTD[5], 0.449999, 1.600000);
	TextDrawAlignment(TopTD[5], 1);
	TextDrawColor(TopTD[5], -1);
	TextDrawSetShadow(TopTD[5], 0);
	TextDrawSetOutline(TopTD[5], 1);
	TextDrawBackgroundColor(TopTD[5], 51);
	TextDrawFont(TopTD[5], 1);
	TextDrawSetProportional(TopTD[5], 1);

	TopTD[6] = TextDrawCreate(217.999893, 196.879974, "3.");
	TextDrawLetterSize(TopTD[6], 0.449999, 1.600000);
	TextDrawAlignment(TopTD[6], 1);
	TextDrawColor(TopTD[6], -1);
	TextDrawSetShadow(TopTD[6], 0);
	TextDrawSetOutline(TopTD[6], 1);
	TextDrawBackgroundColor(TopTD[6], 51);
	TextDrawFont(TopTD[6], 1);
	TextDrawSetProportional(TopTD[6], 1);

	TopTD[7] = TextDrawCreate(218.199890, 212.813400, "4.");
	TextDrawLetterSize(TopTD[7], 0.449999, 1.600000);
	TextDrawAlignment(TopTD[7], 1);
	TextDrawColor(TopTD[7], -1);
	TextDrawSetShadow(TopTD[7], 0);
	TextDrawSetOutline(TopTD[7], 1);
	TextDrawBackgroundColor(TopTD[7], 51);
	TextDrawFont(TopTD[7], 1);
	TextDrawSetProportional(TopTD[7], 1);

	TopTD[8] = TextDrawCreate(217.599884, 228.000152, "5.");
	TextDrawLetterSize(TopTD[8], 0.449999, 1.600000);
	TextDrawAlignment(TopTD[8], 1);
	TextDrawColor(TopTD[8], -1);
	TextDrawSetShadow(TopTD[8], 0);
	TextDrawSetOutline(TopTD[8], 1);
	TextDrawBackgroundColor(TopTD[8], 51);
	TextDrawFont(TopTD[8], 1);
	TextDrawSetProportional(TopTD[8], 1);

	TopTD[9] = TextDrawCreate(217.799880, 243.186889, "6.");
	TextDrawLetterSize(TopTD[9], 0.449999, 1.600000);
	TextDrawAlignment(TopTD[9], 1);
	TextDrawColor(TopTD[9], -1);
	TextDrawSetShadow(TopTD[9], 0);
	TextDrawSetOutline(TopTD[9], 1);
	TextDrawBackgroundColor(TopTD[9], 51);
	TextDrawFont(TopTD[9], 1);
	TextDrawSetProportional(TopTD[9], 1);

	TopTD[10] = TextDrawCreate(217.999877, 258.373565, "7.");
	TextDrawLetterSize(TopTD[10], 0.449999, 1.600000);
	TextDrawAlignment(TopTD[10], 1);
	TextDrawColor(TopTD[10], -1);
	TextDrawSetShadow(TopTD[10], 0);
	TextDrawSetOutline(TopTD[10], 1);
	TextDrawBackgroundColor(TopTD[10], 51);
	TextDrawFont(TopTD[10], 1);
	TextDrawSetProportional(TopTD[10], 1);

	TopTD[11] = TextDrawCreate(217.399871, 275.053588, "8.");
	TextDrawLetterSize(TopTD[11], 0.449999, 1.600000);
	TextDrawAlignment(TopTD[11], 1);
	TextDrawColor(TopTD[11], -1);
	TextDrawSetShadow(TopTD[11], 0);
	TextDrawSetOutline(TopTD[11], 1);
	TextDrawBackgroundColor(TopTD[11], 51);
	TextDrawFont(TopTD[11], 1);
	TextDrawSetProportional(TopTD[11], 1);

	TopTD[12] = TextDrawCreate(217.599868, 290.240295, "9.");
	TextDrawLetterSize(TopTD[12], 0.449999, 1.600000);
	TextDrawAlignment(TopTD[12], 1);
	TextDrawColor(TopTD[12], -1);
	TextDrawSetShadow(TopTD[12], 0);
	TextDrawSetOutline(TopTD[12], 1);
	TextDrawBackgroundColor(TopTD[12], 51);
	TextDrawFont(TopTD[12], 1);
	TextDrawSetProportional(TopTD[12], 1);

	TopTD[13] = TextDrawCreate(215.399856, 306.920379, "10.");
	TextDrawLetterSize(TopTD[13], 0.449999, 1.600000);
	TextDrawAlignment(TopTD[13], 1);
	TextDrawColor(TopTD[13], -1);
	TextDrawSetShadow(TopTD[13], 0);
	TextDrawSetOutline(TopTD[13], 1);
	TextDrawBackgroundColor(TopTD[13], 51);
	TextDrawFont(TopTD[13], 1);
	TextDrawSetProportional(TopTD[13], 1);

	TopTD[14] = TextDrawCreate(244.000045, 164.266555, "CZCNR CZCNR");
	TextDrawLetterSize(TopTD[14], 0.250799, 1.487999);
	TextDrawAlignment(TopTD[14], 1);
	TextDrawColor(TopTD[14], -5963521);
	TextDrawSetShadow(TopTD[14], 0);
	TextDrawSetOutline(TopTD[14], 1);
	TextDrawBackgroundColor(TopTD[14], 51);
	TextDrawFont(TopTD[14], 1);
	TextDrawSetProportional(TopTD[14], 1);

	TopTD[15] = TextDrawCreate(244.200042, 180.946624, "CZCNR CZCNR");
	TextDrawLetterSize(TopTD[15], 0.250799, 1.487999);
	TextDrawAlignment(TopTD[15], 1);
	TextDrawColor(TopTD[15], 65535);
	TextDrawSetShadow(TopTD[15], 0);
	TextDrawSetOutline(TopTD[15], 1);
	TextDrawBackgroundColor(TopTD[15], 51);
	TextDrawFont(TopTD[15], 1);
	TextDrawSetProportional(TopTD[15], 1);

	TopTD[16] = TextDrawCreate(243.600036, 198.373336, "CZCNR CZCNR");
	TextDrawLetterSize(TopTD[16], 0.250799, 1.487999);
	TextDrawAlignment(TopTD[16], 1);
	TextDrawColor(TopTD[16], 16711935);
	TextDrawSetShadow(TopTD[16], 0);
	TextDrawSetOutline(TopTD[16], 1);
	TextDrawBackgroundColor(TopTD[16], 51);
	TextDrawFont(TopTD[16], 1);
	TextDrawSetProportional(TopTD[16], 1);

	TopTD[17] = TextDrawCreate(243.800033, 214.306716, "CZCNR CZCNR");
	TextDrawLetterSize(TopTD[17], 0.250799, 1.487999);
	TextDrawAlignment(TopTD[17], 1);
	TextDrawColor(TopTD[17], -1);
	TextDrawSetShadow(TopTD[17], 0);
	TextDrawSetOutline(TopTD[17], 1);
	TextDrawBackgroundColor(TopTD[17], 51);
	TextDrawFont(TopTD[17], 1);
	TextDrawSetProportional(TopTD[17], 1);

	TopTD[18] = TextDrawCreate(244.000030, 230.240051, "CZCNR CZCNR");
	TextDrawLetterSize(TopTD[18], 0.250799, 1.487999);
	TextDrawAlignment(TopTD[18], 1);
	TextDrawColor(TopTD[18], -1);
	TextDrawSetShadow(TopTD[18], 0);
	TextDrawSetOutline(TopTD[18], 1);
	TextDrawBackgroundColor(TopTD[18], 51);
	TextDrawFont(TopTD[18], 1);
	TextDrawSetProportional(TopTD[18], 1);

	TopTD[19] = TextDrawCreate(243.400024, 245.426788, "CZCNR CZCNR");
	TextDrawLetterSize(TopTD[19], 0.250799, 1.487999);
	TextDrawAlignment(TopTD[19], 1);
	TextDrawColor(TopTD[19], -1);
	TextDrawSetShadow(TopTD[19], 0);
	TextDrawSetOutline(TopTD[19], 1);
	TextDrawBackgroundColor(TopTD[19], 51);
	TextDrawFont(TopTD[19], 1);
	TextDrawSetProportional(TopTD[19], 1);

	TopTD[20] = TextDrawCreate(243.600021, 260.613525, "CZCNR CZCNR");
	TextDrawLetterSize(TopTD[20], 0.250799, 1.487999);
	TextDrawAlignment(TopTD[20], 1);
	TextDrawColor(TopTD[20], -1);
	TextDrawSetShadow(TopTD[20], 0);
	TextDrawSetOutline(TopTD[20], 1);
	TextDrawBackgroundColor(TopTD[20], 51);
	TextDrawFont(TopTD[20], 1);
	TextDrawSetProportional(TopTD[20], 1);

	TopTD[21] = TextDrawCreate(243.800018, 275.053649, "CZCNR CZCNR");
	TextDrawLetterSize(TopTD[21], 0.250799, 1.487999);
	TextDrawAlignment(TopTD[21], 1);
	TextDrawColor(TopTD[21], -1);
	TextDrawSetShadow(TopTD[21], 0);
	TextDrawSetOutline(TopTD[21], 1);
	TextDrawBackgroundColor(TopTD[21], 51);
	TextDrawFont(TopTD[21], 1);
	TextDrawSetProportional(TopTD[21], 1);

	TopTD[22] = TextDrawCreate(244.000015, 291.733703, "CZCNR CZCNR");
	TextDrawLetterSize(TopTD[22], 0.250799, 1.487999);
	TextDrawAlignment(TopTD[22], 1);
	TextDrawColor(TopTD[22], -1);
	TextDrawSetShadow(TopTD[22], 0);
	TextDrawSetOutline(TopTD[22], 1);
	TextDrawBackgroundColor(TopTD[22], 51);
	TextDrawFont(TopTD[22], 1);
	TextDrawSetProportional(TopTD[22], 1);

	TopTD[23] = TextDrawCreate(243.400009, 307.667114, "CZCNR CZCNR");
	TextDrawLetterSize(TopTD[23], 0.250799, 1.487999);
	TextDrawAlignment(TopTD[23], 1);
	TextDrawColor(TopTD[23], -1);
	TextDrawSetShadow(TopTD[23], 0);
	TextDrawSetOutline(TopTD[23], 1);
	TextDrawBackgroundColor(TopTD[23], 51);
	TextDrawFont(TopTD[23], 1);
	TextDrawSetProportional(TopTD[23], 1);

	TopTD[24] = TextDrawCreate(439.400024, 166.013198, "10000000 XP");
	TextDrawLetterSize(TopTD[24], 0.250799, 1.487999);
	TextDrawAlignment(TopTD[24], 3);
	TextDrawColor(TopTD[24], -5963521);
	TextDrawSetShadow(TopTD[24], 0);
	TextDrawSetOutline(TopTD[24], 1);
	TextDrawBackgroundColor(TopTD[24], 51);
	TextDrawFont(TopTD[24], 1);
	TextDrawSetProportional(TopTD[24], 1);

	TopTD[25] = TextDrawCreate(439.199829, 181.946441, "10000000 XP");
	TextDrawLetterSize(TopTD[25], 0.250799, 1.487999);
	TextDrawAlignment(TopTD[25], 3);
	TextDrawColor(TopTD[25], 65535);
	TextDrawSetShadow(TopTD[25], 0);
	TextDrawSetOutline(TopTD[25], 1);
	TextDrawBackgroundColor(TopTD[25], 51);
	TextDrawFont(TopTD[25], 1);
	TextDrawSetProportional(TopTD[25], 1);

	TopTD[26] = TextDrawCreate(438.599853, 198.626556, "10000000 XP");
	TextDrawLetterSize(TopTD[26], 0.250799, 1.487999);
	TextDrawAlignment(TopTD[26], 3);
	TextDrawColor(TopTD[26], 16711935);
	TextDrawSetShadow(TopTD[26], 0);
	TextDrawSetOutline(TopTD[26], 1);
	TextDrawBackgroundColor(TopTD[26], 51);
	TextDrawFont(TopTD[26], 1);
	TextDrawSetProportional(TopTD[26], 1);

	TopTD[27] = TextDrawCreate(438.799865, 214.559967, "10000000 XP");
	TextDrawLetterSize(TopTD[27], 0.250799, 1.487999);
	TextDrawAlignment(TopTD[27], 3);
	TextDrawColor(TopTD[27], -1);
	TextDrawSetShadow(TopTD[27], 0);
	TextDrawSetOutline(TopTD[27], 1);
	TextDrawBackgroundColor(TopTD[27], 51);
	TextDrawFont(TopTD[27], 1);
	TextDrawSetProportional(TopTD[27], 1);

	TopTD[28] = TextDrawCreate(438.999877, 231.240051, "10000000 XP");
	TextDrawLetterSize(TopTD[28], 0.250799, 1.487999);
	TextDrawAlignment(TopTD[28], 3);
	TextDrawColor(TopTD[28], -1);
	TextDrawSetShadow(TopTD[28], 0);
	TextDrawSetOutline(TopTD[28], 1);
	TextDrawBackgroundColor(TopTD[28], 51);
	TextDrawFont(TopTD[28], 1);
	TextDrawSetProportional(TopTD[28], 1);

	TopTD[29] = TextDrawCreate(438.399902, 247.173461, "10000000 XP");
	TextDrawLetterSize(TopTD[29], 0.250799, 1.487999);
	TextDrawAlignment(TopTD[29], 3);
	TextDrawColor(TopTD[29], -1);
	TextDrawSetShadow(TopTD[29], 0);
	TextDrawSetOutline(TopTD[29], 1);
	TextDrawBackgroundColor(TopTD[29], 51);
	TextDrawFont(TopTD[29], 1);
	TextDrawSetProportional(TopTD[29], 1);

	TopTD[30] = TextDrawCreate(437.799926, 262.360229, "10000000 XP");
	TextDrawLetterSize(TopTD[30], 0.250799, 1.487999);
	TextDrawAlignment(TopTD[30], 3);
	TextDrawColor(TopTD[30], -1);
	TextDrawSetShadow(TopTD[30], 0);
	TextDrawSetOutline(TopTD[30], 1);
	TextDrawBackgroundColor(TopTD[30], 51);
	TextDrawFont(TopTD[30], 1);
	TextDrawSetProportional(TopTD[30], 1);

	TopTD[31] = TextDrawCreate(437.999938, 276.800354, "10000000 XP");
	TextDrawLetterSize(TopTD[31], 0.250799, 1.487999);
	TextDrawAlignment(TopTD[31], 3);
	TextDrawColor(TopTD[31], -1);
	TextDrawSetShadow(TopTD[31], 0);
	TextDrawSetOutline(TopTD[31], 1);
	TextDrawBackgroundColor(TopTD[31], 51);
	TextDrawFont(TopTD[31], 1);
	TextDrawSetProportional(TopTD[31], 1);

	TopTD[32] = TextDrawCreate(437.399963, 291.987121, "10000000 XP");
	TextDrawLetterSize(TopTD[32], 0.250799, 1.487999);
	TextDrawAlignment(TopTD[32], 3);
	TextDrawColor(TopTD[32], -1);
	TextDrawSetShadow(TopTD[32], 0);
	TextDrawSetOutline(TopTD[32], 1);
	TextDrawBackgroundColor(TopTD[32], 51);
	TextDrawFont(TopTD[32], 1);
	TextDrawSetProportional(TopTD[32], 1);

	TopTD[33] = TextDrawCreate(437.599975, 308.667236, "10000000 XP");
	TextDrawLetterSize(TopTD[33], 0.250799, 1.487999);
	TextDrawAlignment(TopTD[33], 3);
	TextDrawColor(TopTD[33], -1);
	TextDrawSetShadow(TopTD[33], 0);
	TextDrawSetOutline(TopTD[33], 1);
	TextDrawBackgroundColor(TopTD[33], 51);
	TextDrawFont(TopTD[33], 1);
	TextDrawSetProportional(TopTD[33], 1);

	TopTD[34] = TextDrawCreate(224.799926, 347.946716, ".....................");
	TextDrawLetterSize(TopTD[34], 0.344399, 1.487999);
	TextDrawAlignment(TopTD[34], 1);
	TextDrawColor(TopTD[34], -1);
	TextDrawSetShadow(TopTD[34], 0);
	TextDrawSetOutline(TopTD[34], 1);
	TextDrawBackgroundColor(TopTD[34], 51);
	TextDrawFont(TopTD[34], 2);
	TextDrawSetProportional(TopTD[34], 1);

	TopTD[35] = TextDrawCreate(352.200134, 348.946746, ".....................");
	TextDrawLetterSize(TopTD[35], 0.344399, 1.487999);
	TextDrawAlignment(TopTD[35], 1);
	TextDrawColor(TopTD[35], -1);
	TextDrawSetShadow(TopTD[35], 0);
	TextDrawSetOutline(TopTD[35], 1);
	TextDrawBackgroundColor(TopTD[35], 51);
	TextDrawFont(TopTD[35], 2);
	TextDrawSetProportional(TopTD[35], 1);

	TopTD[36] = TextDrawCreate(352.400146, 345.466705, "..........");
	TextDrawLetterSize(TopTD[36], 0.385199, 1.443199);
	TextDrawAlignment(TopTD[36], 1);
	TextDrawColor(TopTD[36], -1);
	TextDrawSetShadow(TopTD[36], 0);
	TextDrawSetOutline(TopTD[36], 1);
	TextDrawBackgroundColor(TopTD[36], 51);
	TextDrawFont(TopTD[36], 2);
	TextDrawSetProportional(TopTD[36], 1);

	TopTD[37] = TextDrawCreate(352.600158, 353.186767, "..........");
	TextDrawLetterSize(TopTD[37], 0.385199, 1.443199);
	TextDrawAlignment(TopTD[37], 1);
	TextDrawColor(TopTD[37], -1);
	TextDrawSetShadow(TopTD[37], 0);
	TextDrawSetOutline(TopTD[37], 1);
	TextDrawBackgroundColor(TopTD[37], 51);
	TextDrawFont(TopTD[37], 2);
	TextDrawSetProportional(TopTD[37], 1);

	TopTD[38] = TextDrawCreate(259.200103, 352.693359, "..........");
	TextDrawLetterSize(TopTD[38], 0.385199, 1.443199);
	TextDrawAlignment(TopTD[38], 1);
	TextDrawColor(TopTD[38], -1);
	TextDrawSetShadow(TopTD[38], 0);
	TextDrawSetOutline(TopTD[38], 1);
	TextDrawBackgroundColor(TopTD[38], 51);
	TextDrawFont(TopTD[38], 2);
	TextDrawSetProportional(TopTD[38], 1);

	TopTD[39] = TextDrawCreate(258.600128, 343.986602, "..........");
	TextDrawLetterSize(TopTD[39], 0.385199, 1.443199);
	TextDrawAlignment(TopTD[39], 1);
	TextDrawColor(TopTD[39], -1);
	TextDrawSetShadow(TopTD[39], 0);
	TextDrawSetOutline(TopTD[39], 1);
	TextDrawBackgroundColor(TopTD[39], 51);
	TextDrawFont(TopTD[39], 2);
	TextDrawSetProportional(TopTD[39], 1);

	TopTD[40] = TextDrawCreate(295.999938, 349.439910, "Great Work");
	TextDrawLetterSize(TopTD[40], 0.213199, 1.883733);
	TextDrawAlignment(TopTD[40], 1);
	TextDrawColor(TopTD[40], -1);
	TextDrawSetShadow(TopTD[40], 0);
	TextDrawSetOutline(TopTD[40], 1);
	TextDrawBackgroundColor(TopTD[40], 51);
	TextDrawFont(TopTD[40], 2);
	TextDrawSetProportional(TopTD[40], 1);

	TopTD[41] = TextDrawCreate(197.600128, 110.506759, "Type /closehelp to close");
	TextDrawLetterSize(TopTD[41], 0.449999, 1.600000);
	TextDrawAlignment(TopTD[41], 1);
	TextDrawColor(TopTD[41], -1);
	TextDrawSetShadow(TopTD[41], 0);
	TextDrawSetOutline(TopTD[41], 1);
	TextDrawBackgroundColor(TopTD[41], 51);
	TextDrawFont(TopTD[41], 0);
	TextDrawSetProportional(TopTD[41], 1);
}

stock LoginTextDraws(playerid)
{
	// Vehicle Spawns
	vSpawns[0] = TextDrawCreate(320.000000, 117.000000, "~n~~n~");
	TextDrawAlignment(vSpawns[0], 2);
	TextDrawBackgroundColor(vSpawns[0], 0x00000077);
	TextDrawFont(vSpawns[0], 1);
	TextDrawLetterSize(vSpawns[0], 0.500000, 1.000000);
	TextDrawColor(vSpawns[0], -1);
	TextDrawSetOutline(vSpawns[0], 0);
	TextDrawSetProportional(vSpawns[0], 1);
	TextDrawSetShadow(vSpawns[0], 1);
	TextDrawUseBox(vSpawns[0], 1);
	TextDrawBoxColor(vSpawns[0], 0x00000077);
	TextDrawTextSize(vSpawns[0], 157.000000, 181.000000);

	vSpawns[1] = TextDrawCreate(320.000000, 120.000000, "~y~Vehicle Spawn Point");
	TextDrawAlignment(vSpawns[1], 2);
	TextDrawBackgroundColor(vSpawns[1], 255);
	TextDrawFont(vSpawns[1], 2);
	TextDrawLetterSize(vSpawns[1], 0.280000, 1.100000);
	TextDrawColor(vSpawns[1], -1);
	TextDrawSetOutline(vSpawns[1], 0);
	TextDrawSetProportional(vSpawns[1], 1);
	TextDrawSetShadow(vSpawns[1], 1);



	//MOVIE MODE
	playerData[playerid][MM1] = CreatePlayerTextDraw(playerid, 489.199981, 438.300079, "usebox");
	PlayerTextDrawLetterSize(playerid, playerData[playerid][MM1], 0.004000, -6.609169);
	PlayerTextDrawTextSize(playerid, playerData[playerid][MM1], 613.200012, 0.000000);
	PlayerTextDrawAlignment(playerid, playerData[playerid][MM1], 1);
	PlayerTextDrawColor(playerid, playerData[playerid][MM1], 0);
	PlayerTextDrawUseBox(playerid, playerData[playerid][MM1], true);
	PlayerTextDrawBoxColor(playerid, playerData[playerid][MM1], 102);
	PlayerTextDrawSetShadow(playerid, playerData[playerid][MM1], 0);
	PlayerTextDrawSetOutline(playerid, playerData[playerid][MM1], 0);
	PlayerTextDrawFont(playerid, playerData[playerid][MM1], 0);

	playerData[playerid][MM2] = CreatePlayerTextDraw(playerid, 551.199951, 383.786560, "~b~Cops ~w~And ~R~Robbers ~w~San Fierro");
	PlayerTextDrawLetterSize(playerid, playerData[playerid][MM2], 0.269199, 1.667199);
	PlayerTextDrawAlignment(playerid, playerData[playerid][MM2], 2);
	PlayerTextDrawColor(playerid, playerData[playerid][MM2], -1);
	PlayerTextDrawSetShadow(playerid, playerData[playerid][MM2], 0);
	PlayerTextDrawSetOutline(playerid, playerData[playerid][MM2], 1);
	PlayerTextDrawBackgroundColor(playerid, playerData[playerid][MM2], 51);
	PlayerTextDrawFont(playerid, playerData[playerid][MM2], 2);
	PlayerTextDrawSetProportional(playerid, playerData[playerid][MM2], 1);

	playerData[playerid][MM3] = CreatePlayerTextDraw(playerid, 552.000000, 397.973327, "~b~Cops ~w~And ~R~Robbers ~w~San Fierro");
	PlayerTextDrawLetterSize(playerid, playerData[playerid][MM3], 0.339600, 1.040000);
	PlayerTextDrawAlignment(playerid, playerData[playerid][MM3], 2);
	PlayerTextDrawColor(playerid, playerData[playerid][MM3], -1);
	PlayerTextDrawSetShadow(playerid, playerData[playerid][MM3], 0);
	PlayerTextDrawSetOutline(playerid, playerData[playerid][MM3], 1);
	PlayerTextDrawBackgroundColor(playerid, playerData[playerid][MM3], 51);
	PlayerTextDrawFont(playerid, playerData[playerid][MM3], 1);
	PlayerTextDrawSetProportional(playerid, playerData[playerid][MM3], 1);

	playerData[playerid][MM4] = CreatePlayerTextDraw(playerid, 498.399932, 422.613372, "www.CZCNR.ml");
	PlayerTextDrawLetterSize(playerid, playerData[playerid][MM4], 0.233199, 0.927999);
	PlayerTextDrawAlignment(playerid, playerData[playerid][MM4], 1);
	PlayerTextDrawColor(playerid, playerData[playerid][MM4], 0xFFFFFF);
	PlayerTextDrawSetShadow(playerid, playerData[playerid][MM4], 0);
	PlayerTextDrawSetOutline(playerid, playerData[playerid][MM4], 1);
	PlayerTextDrawBackgroundColor(playerid, playerData[playerid][MM4], 255);
	PlayerTextDrawFont(playerid, playerData[playerid][MM4], 1);
	PlayerTextDrawSetProportional(playerid, playerData[playerid][MM4], 1);
	// For Easter
	playerData[playerid][Eggs][0] = CreatePlayerTextDraw(playerid, 500.0, 340.0, "_");
	PlayerTextDrawFont(playerid, playerData[playerid][Eggs][0], TEXT_DRAW_FONT_MODEL_PREVIEW);
	PlayerTextDrawUseBox(playerid, playerData[playerid][Eggs][0], 1);
	PlayerTextDrawBoxColor(playerid, playerData[playerid][Eggs][0], 0xFFFFFF00);
	PlayerTextDrawBackgroundColor(playerid, playerData[playerid][Eggs][0], 0xFFFFFF00);
	PlayerTextDrawTextSize(playerid, playerData[playerid][Eggs][0], 40.0, 40.0);
	PlayerTextDrawSetPreviewModel(playerid, playerData[playerid][Eggs][0], 19341);

	playerData[playerid][Eggs][1] = CreatePlayerTextDraw(playerid, 530.0, 340.0, "_");
	PlayerTextDrawFont(playerid, playerData[playerid][Eggs][1], TEXT_DRAW_FONT_MODEL_PREVIEW);
	PlayerTextDrawUseBox(playerid, playerData[playerid][Eggs][1], 1);
	PlayerTextDrawBoxColor(playerid, playerData[playerid][Eggs][1], 0xFFFFFF00);
	PlayerTextDrawBackgroundColor(playerid, playerData[playerid][Eggs][1], 0xFFFFFF00);
	PlayerTextDrawTextSize(playerid, playerData[playerid][Eggs][1], 40.0, 40.0);
	PlayerTextDrawSetPreviewModel(playerid, playerData[playerid][Eggs][1], 19343);

	playerData[playerid][Eggs][2] = CreatePlayerTextDraw(playerid, 560.0, 340.0, "_");
	PlayerTextDrawFont(playerid, playerData[playerid][Eggs][2], TEXT_DRAW_FONT_MODEL_PREVIEW);
	PlayerTextDrawUseBox(playerid, playerData[playerid][Eggs][2], 1);
	PlayerTextDrawBoxColor(playerid, playerData[playerid][Eggs][2], 0xFFFFFF00);
	PlayerTextDrawBackgroundColor(playerid, playerData[playerid][Eggs][2], 0xFFFFFF00);
	PlayerTextDrawTextSize(playerid, playerData[playerid][Eggs][2], 40.0, 40.0);
	PlayerTextDrawSetPreviewModel(playerid, playerData[playerid][Eggs][2], 19342);

	/***
	playerData[playerid][cnrLogo] = CreatePlayerTextDraw(playerid, 498.000000, 404.666687, "CZ COPS AND ROBBERS");
	PlayerTextDrawLetterSize(playerid, playerData[playerid][cnrLogo], 0.361999, 1.917334);
	PlayerTextDrawAlignment(playerid, playerData[playerid][cnrLogo], 1);
	PlayerTextDrawColor(playerid, playerData[playerid][cnrLogo], 55646571);   //55756571
	PlayerTextDrawSetShadow(playerid, playerData[playerid][cnrLogo], 1);
	PlayerTextDrawSetOutline(playerid, playerData[playerid][cnrLogo], 0);
	PlayerTextDrawBackgroundColor(playerid, playerData[playerid][cnrLogo], 255);
	PlayerTextDrawFont(playerid, playerData[playerid][cnrLogo], 1);
	PlayerTextDrawSetProportional(playerid, playerData[playerid][cnrLogo], 1);
	PlayerTextDrawSetShadow(playerid, playerData[playerid][cnrLogo], 1);
	PlayerTextDrawShow(playerid, playerData[playerid][cnrLogo]);
	***/
	
	playerData[playerid][cnrLogo] = CreatePlayerTextDraw(playerid, 501.000000, 391.000000, "CZ ~B~COPS ~w~AND ~R~ROBBERS");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][cnrLogo], 0x00000055);
	PlayerTextDrawFont(playerid,playerData[playerid][cnrLogo], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][cnrLogo], 0.319999, 1.899999);
	PlayerTextDrawColor(playerid,playerData[playerid][cnrLogo], 255);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][cnrLogo], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][cnrLogo], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][cnrLogo], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][cnrLogo], 0);
	PlayerTextDrawShow(playerid, playerData[playerid][cnrLogo]);

	
	playerData[playerid][playerExperience] = CreatePlayerTextDraw(playerid, 566.000000, 425.199920, "0/1000");
	PlayerTextDrawLetterSize(playerid, playerData[playerid][playerExperience], 0.349000, 1.618666);
	PlayerTextDrawAlignment(playerid, playerData[playerid][playerExperience], 2);
	PlayerTextDrawColor(playerid, playerData[playerid][playerExperience], -1);
	PlayerTextDrawSetShadow(playerid, playerData[playerid][playerExperience], 1);
	PlayerTextDrawSetOutline(playerid, playerData[playerid][playerExperience], 0);
	PlayerTextDrawBackgroundColor(playerid, playerData[playerid][playerExperience], 255);//255
	PlayerTextDrawFont(playerid, playerData[playerid][playerExperience], 2);
	PlayerTextDrawSetProportional(playerid, playerData[playerid][playerExperience], 1);
	PlayerTextDrawSetShadow(playerid, playerData[playerid][playerExperience], 0);
	PlayerTextDrawShow(playerid, playerData[playerid][playerExperience]);
	
	playerData[playerid][playerAddedXPTD] = CreatePlayerTextDraw(playerid, 542.000000, 432.000000, " ");
	PlayerTextDrawBackgroundColor(playerid, playerData[playerid][playerAddedXPTD], 255);//255
	PlayerTextDrawFont(playerid, playerData[playerid][playerAddedXPTD], 1);
	PlayerTextDrawLetterSize(playerid, playerData[playerid][playerAddedXPTD], 0.330000, 0.799999);
	PlayerTextDrawColor(playerid, playerData[playerid][playerAddedXPTD], -1);
	PlayerTextDrawSetOutline(playerid, playerData[playerid][playerAddedXPTD], 0);
	PlayerTextDrawSetProportional(playerid, playerData[playerid][playerAddedXPTD], 1);
	PlayerTextDrawSetShadow(playerid, playerData[playerid][playerAddedXPTD], 0);
	//PlayerTextDrawShow(playerid, playerData[playerid][playerAddedXPTD]);

	playerData[playerid][playerJailTimerTD] = CreatePlayerTextDraw(playerid, 250.000000, 9.000000, " ");
	PlayerTextDrawBackgroundColor(playerid, playerData[playerid][playerJailTimerTD], 255);
	PlayerTextDrawFont(playerid, playerData[playerid][playerJailTimerTD], 1);
	PlayerTextDrawLetterSize(playerid, playerData[playerid][playerJailTimerTD], 0.350000, 1.300000);
	PlayerTextDrawColor(playerid, playerData[playerid][playerJailTimerTD], -1);
	PlayerTextDrawSetOutline(playerid, playerData[playerid][playerJailTimerTD], 0);
	PlayerTextDrawSetProportional(playerid, playerData[playerid][playerJailTimerTD], 1);
	PlayerTextDrawSetShadow(playerid, playerData[playerid][playerJailTimerTD], 1);
	PlayerTextDrawShow(playerid, playerData[playerid][playerJailTimerTD]);

	playerData[playerid][playerTruckingTD] = CreatePlayerTextDraw(playerid, 320.000000, 150.000000, " ");
	PlayerTextDrawBackgroundColor(playerid, playerData[playerid][playerTruckingTD], 0x00000040);
	PlayerTextDrawFont(playerid, playerData[playerid][playerTruckingTD], 1);
	PlayerTextDrawLetterSize(playerid, playerData[playerid][playerTruckingTD], 0.500000, 2.000000);
	PlayerTextDrawColor(playerid, playerData[playerid][playerTruckingTD], -1);
	PlayerTextDrawSetOutline(playerid, playerData[playerid][playerTruckingTD], 0);
	PlayerTextDrawSetProportional(playerid, playerData[playerid][playerTruckingTD], 1);
	PlayerTextDrawSetShadow(playerid, playerData[playerid][playerTruckingTD], 1);
	PlayerTextDrawAlignment(playerid, playerData[playerid][playerTruckingTD], 2);
	PlayerTextDrawShow(playerid, playerData[playerid][playerTruckingTD]);

	playerData[playerid][playerTruckingWaitTD] = CreatePlayerTextDraw(playerid, 290.000000, 168.000000, " ");
	PlayerTextDrawBackgroundColor(playerid, playerData[playerid][playerTruckingWaitTD], 0x00000040);
	PlayerTextDrawFont(playerid, playerData[playerid][playerTruckingWaitTD], 1);
	PlayerTextDrawLetterSize(playerid, playerData[playerid][playerTruckingWaitTD], 0.290000, 1.200000);
	PlayerTextDrawColor(playerid, playerData[playerid][playerTruckingWaitTD], -65281);
	PlayerTextDrawSetOutline(playerid, playerData[playerid][playerTruckingWaitTD], 0);
	PlayerTextDrawSetProportional(playerid, playerData[playerid][playerTruckingWaitTD], 1);
	PlayerTextDrawSetShadow(playerid, playerData[playerid][playerTruckingWaitTD], 1);
	PlayerTextDrawShow(playerid, playerData[playerid][playerTruckingWaitTD]);

	playerData[playerid][playerHitmarkerTD] = CreatePlayerTextDraw(playerid, 275.000000, 103.000000, " ");
	PlayerTextDrawBackgroundColor(playerid, playerData[playerid][playerHitmarkerTD], 255);
	PlayerTextDrawFont(playerid, playerData[playerid][playerHitmarkerTD], 1);
	PlayerTextDrawLetterSize(playerid, playerData[playerid][playerHitmarkerTD], 0.390000, 2.100002);
	PlayerTextDrawColor(playerid, playerData[playerid][playerHitmarkerTD], -1273422337);
	PlayerTextDrawSetOutline(playerid, playerData[playerid][playerHitmarkerTD], 1);
	PlayerTextDrawSetProportional(playerid, playerData[playerid][playerHitmarkerTD], 1);
	PlayerTextDrawShow(playerid, playerData[playerid][playerHitmarkerTD]);

	playerData[playerid][wantedStars] = CreatePlayerTextDraw(playerid, 558.000000, 122.000000, " ");
	PlayerTextDrawBackgroundColor(playerid, playerData[playerid][wantedStars], 0x00000040);
	PlayerTextDrawFont(playerid, playerData[playerid][wantedStars], 2);
	PlayerTextDrawLetterSize(playerid, playerData[playerid][wantedStars], 0.280000, 0.899999);
	PlayerTextDrawColor(playerid, playerData[playerid][wantedStars], 0xFFFFFFFF);
	PlayerTextDrawSetOutline(playerid, playerData[playerid][wantedStars], 1);
	PlayerTextDrawSetProportional(playerid, playerData[playerid][wantedStars], 1);
	PlayerTextDrawAlignment(playerid, playerData[playerid][wantedStars], 2);
	PlayerTextDrawShow(playerid, playerData[playerid][wantedStars]);

	playerData[playerid][playerTracker] = CreatePlayerTextDraw(playerid, 88.000000, 322.000000, " ");
	PlayerTextDrawBackgroundColor(playerid, playerData[playerid][playerTracker], 0x00000040);
	PlayerTextDrawFont(playerid, playerData[playerid][playerTracker], 2);
	PlayerTextDrawLetterSize(playerid, playerData[playerid][playerTracker], 0.300000, 1.000000);
	PlayerTextDrawColor(playerid, playerData[playerid][playerTracker], 0xFFFFFFFF);
	PlayerTextDrawSetOutline(playerid, playerData[playerid][playerTracker], 1);
	PlayerTextDrawSetProportional(playerid, playerData[playerid][playerTracker], 1);
	PlayerTextDrawAlignment(playerid, playerData[playerid][playerTracker], 2);
	PlayerTextDrawShow(playerid, playerData[playerid][playerTracker]);

	playerData[playerid][playerTracker] = CreatePlayerTextDraw(playerid, 88.000000, 322.000000, " ");
	PlayerTextDrawBackgroundColor(playerid, playerData[playerid][playerTracker], 0x00000040);
	PlayerTextDrawFont(playerid, playerData[playerid][playerTracker], 2);
	PlayerTextDrawLetterSize(playerid, playerData[playerid][playerTracker], 0.300000, 1.000000);
	PlayerTextDrawColor(playerid, playerData[playerid][playerTracker], 0xFFFFFFFF);
	PlayerTextDrawSetOutline(playerid, playerData[playerid][playerTracker], 1);
	PlayerTextDrawSetProportional(playerid, playerData[playerid][playerTracker], 1);
	PlayerTextDrawAlignment(playerid, playerData[playerid][playerTracker], 2);
	PlayerTextDrawShow(playerid, playerData[playerid][playerTracker]);

	/***************
	| DM ARENA
	***************/

	playerData[playerid][dmArena][0] = CreatePlayerTextDraw(playerid, 536.000000, 310.000000, "0"); // 29
	PlayerTextDrawBackgroundColor(playerid, playerData[playerid][dmArena][0], 119);
	PlayerTextDrawFont(playerid, playerData[playerid][dmArena][0], 2);
	PlayerTextDrawLetterSize(playerid, playerData[playerid][dmArena][0], 0.220000, 1.000000);
	PlayerTextDrawColor(playerid, playerData[playerid][dmArena][0], -1);
	PlayerTextDrawSetOutline(playerid, playerData[playerid][dmArena][0], 0);
	PlayerTextDrawSetProportional(playerid, playerData[playerid][dmArena][0], 1);
	PlayerTextDrawSetShadow(playerid, playerData[playerid][dmArena][0], 1);

	playerData[playerid][dmArena][1] = CreatePlayerTextDraw(playerid, 550.000000, 324.000000, "0"); // 6
	PlayerTextDrawBackgroundColor(playerid, playerData[playerid][dmArena][1], 119);
	PlayerTextDrawFont(playerid, playerData[playerid][dmArena][1], 2);
	PlayerTextDrawLetterSize(playerid, playerData[playerid][dmArena][1], 0.220000, 1.000000);
	PlayerTextDrawColor(playerid, playerData[playerid][dmArena][1], -1);
	PlayerTextDrawSetOutline(playerid, playerData[playerid][dmArena][1], 0);
	PlayerTextDrawSetProportional(playerid, playerData[playerid][dmArena][1], 1);
	PlayerTextDrawSetShadow(playerid, playerData[playerid][dmArena][1], 1);

	playerData[playerid][dmArena][2] = CreatePlayerTextDraw(playerid, 564.000000, 339.000000, "0"); // 4.83
	PlayerTextDrawBackgroundColor(playerid, playerData[playerid][dmArena][2], 119);
	PlayerTextDrawFont(playerid, playerData[playerid][dmArena][2], 2);
	PlayerTextDrawLetterSize(playerid, playerData[playerid][dmArena][2], 0.220000, 1.000000);
	PlayerTextDrawColor(playerid, playerData[playerid][dmArena][2], -1);
	PlayerTextDrawSetOutline(playerid, playerData[playerid][dmArena][2], 0);
	PlayerTextDrawSetProportional(playerid, playerData[playerid][dmArena][2], 1);
	PlayerTextDrawSetShadow(playerid, playerData[playerid][dmArena][2], 1);

	playerData[playerid][dmArena][3] = CreatePlayerTextDraw(playerid, 567.000000, 355.000000, "2");
	PlayerTextDrawBackgroundColor(playerid, playerData[playerid][dmArena][3], 119);
	PlayerTextDrawFont(playerid, playerData[playerid][dmArena][3], 2);
	PlayerTextDrawLetterSize(playerid, playerData[playerid][dmArena][3], 0.220000, 1.000000);
	PlayerTextDrawColor(playerid, playerData[playerid][dmArena][3], -1);
	PlayerTextDrawSetOutline(playerid, playerData[playerid][dmArena][3], 0);
	PlayerTextDrawSetProportional(playerid, playerData[playerid][dmArena][3], 1);
	PlayerTextDrawSetShadow(playerid, playerData[playerid][dmArena][3], 1);

	playerData[playerid][killStreak] = CreatePlayerTextDraw(playerid, 319.000000, 309.000000, "~g~A Kill Streak~w~~n~Some Unlock");
	PlayerTextDrawAlignment(playerid, playerData[playerid][killStreak], 2);
	PlayerTextDrawBackgroundColor(playerid, playerData[playerid][killStreak], 68);
	PlayerTextDrawFont(playerid, playerData[playerid][killStreak], 2);
	PlayerTextDrawLetterSize(playerid, playerData[playerid][killStreak], 0.330000, 2.299999);
	PlayerTextDrawColor(playerid, playerData[playerid][killStreak], -1);
	PlayerTextDrawSetOutline(playerid, playerData[playerid][killStreak], 0);
	PlayerTextDrawSetProportional(playerid, playerData[playerid][killStreak], 1);
	PlayerTextDrawSetShadow(playerid, playerData[playerid][killStreak], 1);

	/***************
	| NEW UI
	***************/

	playerData[playerid][Welcome1] = CreatePlayerTextDraw(playerid,255.000000, 153.000000, "~b~Cops ~w~and ~R~Robbers");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][Welcome1], 85);
	PlayerTextDrawFont(playerid,playerData[playerid][Welcome1], 3);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][Welcome1], 0.449999, 2.199999);
	PlayerTextDrawColor(playerid,playerData[playerid][Welcome1], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][Welcome1], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][Welcome1], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][Welcome1], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][Welcome1], 0);

	playerData[playerid][Welcome2] = CreatePlayerTextDraw(playerid,320.000000, 150.000000, "~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~");
	PlayerTextDrawAlignment(playerid,playerData[playerid][Welcome2], 2);
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][Welcome2], 255);
	PlayerTextDrawFont(playerid,playerData[playerid][Welcome2], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][Welcome2], 0.500000, 1.000000);
	PlayerTextDrawColor(playerid,playerData[playerid][Welcome2], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][Welcome2], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][Welcome2], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][Welcome2], 1);
	PlayerTextDrawUseBox(playerid,playerData[playerid][Welcome2], 1);
	PlayerTextDrawBoxColor(playerid,playerData[playerid][Welcome2], 85);
	PlayerTextDrawTextSize(playerid,playerData[playerid][Welcome2], 160.000000, 210.000000);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][Welcome2], 0);

	playerData[playerid][Welcome3] = CreatePlayerTextDraw(playerid,230.000000, 180.000000, "Welcome to Cops and Robbers San Fierro.");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][Welcome3], 68);
	PlayerTextDrawFont(playerid,playerData[playerid][Welcome3], 2);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][Welcome3], 0.200000, 1.000000);
	PlayerTextDrawColor(playerid,playerData[playerid][Welcome3], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][Welcome3], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][Welcome3], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][Welcome3], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][Welcome3], 0);

	playerData[playerid][Welcome4] = CreatePlayerTextDraw(playerid,256.000000, 212.000000, "Useful Commands");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][Welcome4], 255);
	PlayerTextDrawFont(playerid,playerData[playerid][Welcome4], 2);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][Welcome4], 0.339998, 1.299999);
	PlayerTextDrawColor(playerid,playerData[playerid][Welcome4], -89368321);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][Welcome4], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][Welcome4], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][Welcome4], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][Welcome4], 0);

	playerData[playerid][Welcome5] = CreatePlayerTextDraw(playerid,258.000000, 236.000000, "/help ~n~/cmds ~n~/pc");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][Welcome5], 255);
	PlayerTextDrawFont(playerid,playerData[playerid][Welcome5], 2);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][Welcome5], 0.399998, 1.199998);
	PlayerTextDrawColor(playerid,playerData[playerid][Welcome5], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][Welcome5], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][Welcome5], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][Welcome5], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][Welcome5], 0);

	playerData[playerid][Welcome6] = CreatePlayerTextDraw(playerid,320.000000, 294.000000, "~n~~n~");
	PlayerTextDrawAlignment(playerid,playerData[playerid][Welcome6], 2);
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][Welcome6], 255);
	PlayerTextDrawFont(playerid,playerData[playerid][Welcome6], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][Welcome6], 0.500000, 1.000000);
	PlayerTextDrawColor(playerid,playerData[playerid][Welcome6], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][Welcome6], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][Welcome6], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][Welcome6], 1);
	PlayerTextDrawUseBox(playerid,playerData[playerid][Welcome6], 1);
	PlayerTextDrawBoxColor(playerid,playerData[playerid][Welcome6], 255);
	PlayerTextDrawTextSize(playerid,playerData[playerid][Welcome6], -10.000000, 210.000000);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][Welcome6], 0);

	playerData[playerid][Welcome7] = CreatePlayerTextDraw(playerid,230.000000, 297.000000, "Type /closehelp to close this dialog");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][Welcome7], 85);
	PlayerTextDrawFont(playerid,playerData[playerid][Welcome7], 2);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][Welcome7], 0.209999, 1.100000);
	PlayerTextDrawColor(playerid,playerData[playerid][Welcome7], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][Welcome7], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][Welcome7], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][Welcome7], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][Welcome7], 0);

	playerData[playerid][Welcome8] = CreatePlayerTextDraw(playerid,226.000000, 192.000000, "Thanks for joining, we hope you have fun!");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][Welcome8], 68);
	PlayerTextDrawFont(playerid,playerData[playerid][Welcome8], 2);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][Welcome8], 0.200000, 1.000000);
	PlayerTextDrawColor(playerid,playerData[playerid][Welcome8], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][Welcome8], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][Welcome8], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][Welcome8], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][Welcome8], 0);

	// INNOCENT KILL TD

	playerData[playerid][InnocentKill1] = CreatePlayerTextDraw(playerid,274.000000, 154.000000, "~r~INNOCENT KILL");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][InnocentKill1], 85);
	PlayerTextDrawFont(playerid,playerData[playerid][InnocentKill1], 3);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][InnocentKill1], 0.449999, 2.199999);
	PlayerTextDrawColor(playerid,playerData[playerid][InnocentKill1], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][InnocentKill1], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][InnocentKill1], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][InnocentKill1], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][InnocentKill1], 0);

	playerData[playerid][InnocentKill2] = CreatePlayerTextDraw(playerid,320.000000, 150.000000, "~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~");
	PlayerTextDrawAlignment(playerid,playerData[playerid][InnocentKill2], 2);
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][InnocentKill2], 255);
	PlayerTextDrawFont(playerid,playerData[playerid][InnocentKill2], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][InnocentKill2], 0.500000, 1.000000);
	PlayerTextDrawColor(playerid,playerData[playerid][InnocentKill2], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][InnocentKill2], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][InnocentKill2], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][InnocentKill2], 1);
	PlayerTextDrawUseBox(playerid,playerData[playerid][InnocentKill2], 1);
	PlayerTextDrawBoxColor(playerid,playerData[playerid][InnocentKill2], 136);
	PlayerTextDrawTextSize(playerid,playerData[playerid][InnocentKill2], 160.000000, 210.000000);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][InnocentKill2], 0);

	playerData[playerid][InnocentKill3] = CreatePlayerTextDraw(playerid,228.000000, 180.000000, "You killed an innocent player, watch it!");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][InnocentKill3], 68);
	PlayerTextDrawFont(playerid,playerData[playerid][InnocentKill3], 2);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][InnocentKill3], 0.200000, 1.000000);
	PlayerTextDrawColor(playerid,playerData[playerid][InnocentKill3], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][InnocentKill3], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][InnocentKill3], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][InnocentKill3], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][InnocentKill3], 0);

	playerData[playerid][InnocentKill4] = CreatePlayerTextDraw(playerid,256.000000, 212.000000, "Useful Commands");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][InnocentKill4], 255);
	PlayerTextDrawFont(playerid,playerData[playerid][InnocentKill4], 2);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][InnocentKill4], 0.339998, 1.299999);
	PlayerTextDrawColor(playerid,playerData[playerid][InnocentKill4], -89368321);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][InnocentKill4], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][InnocentKill4], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][InnocentKill4], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][InnocentKill4], 0);

	playerData[playerid][InnocentKill5] = CreatePlayerTextDraw(playerid,258.000000, 236.000000, "/pc ~n~/iw ~n~/tk");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][InnocentKill5], 255);
	PlayerTextDrawFont(playerid,playerData[playerid][InnocentKill5], 2);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][InnocentKill5], 0.399998, 1.199998);
	PlayerTextDrawColor(playerid,playerData[playerid][InnocentKill5], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][InnocentKill5], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][InnocentKill5], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][InnocentKill5], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][InnocentKill5], 0);

	playerData[playerid][InnocentKill6] = CreatePlayerTextDraw(playerid,320.000000, 294.000000, "~n~~n~");
	PlayerTextDrawAlignment(playerid,playerData[playerid][InnocentKill6], 2);
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][InnocentKill6], 255);
	PlayerTextDrawFont(playerid,playerData[playerid][InnocentKill6], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][InnocentKill6], 0.500000, 1.000000);
	PlayerTextDrawColor(playerid,playerData[playerid][InnocentKill6], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][InnocentKill6], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][InnocentKill6], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][InnocentKill6], 1);
	PlayerTextDrawUseBox(playerid,playerData[playerid][InnocentKill6], 1);
	PlayerTextDrawBoxColor(playerid,playerData[playerid][InnocentKill6], 255);
	PlayerTextDrawTextSize(playerid,playerData[playerid][InnocentKill6], -10.000000, 210.000000);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][InnocentKill6], 0);

	playerData[playerid][InnocentKill7] = CreatePlayerTextDraw(playerid,230.000000, 297.000000, "Type /closehelp to close this dialog");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][InnocentKill7], 85);
	PlayerTextDrawFont(playerid,playerData[playerid][InnocentKill7], 2);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][InnocentKill7], 0.209999, 1.100000);
	PlayerTextDrawColor(playerid,playerData[playerid][InnocentKill7], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][InnocentKill7], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][InnocentKill7], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][InnocentKill7], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][InnocentKill7], 0);

	playerData[playerid][InnocentKill8] = CreatePlayerTextDraw(playerid,266.000000, 191.000000, "~r~You will be cop banned!");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][InnocentKill8], 68);
	PlayerTextDrawFont(playerid,playerData[playerid][InnocentKill8], 2);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][InnocentKill8], 0.200000, 1.000000);
	PlayerTextDrawColor(playerid,playerData[playerid][InnocentKill8], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][InnocentKill8], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][InnocentKill8], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][InnocentKill8], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][InnocentKill8], 0);

	/***************
	| NEW STATISTICS
	***************/

	playerData[playerid][PlayerStats][0] = CreatePlayerTextDraw(playerid,203.000000, 222.000000, "Players Robbed:");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][PlayerStats][0], 136);
	PlayerTextDrawFont(playerid,playerData[playerid][PlayerStats][0], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][PlayerStats][0], 0.270000, 1.100000);
	PlayerTextDrawColor(playerid,playerData[playerid][PlayerStats][0], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][PlayerStats][0], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][PlayerStats][0], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][PlayerStats][0], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][PlayerStats][0], 0);

	playerData[playerid][PlayerStats][1] = CreatePlayerTextDraw(playerid,320.000000, 140.000000, "~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~");
	PlayerTextDrawAlignment(playerid,playerData[playerid][PlayerStats][1], 2);
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][PlayerStats][1], 255);
	PlayerTextDrawFont(playerid,playerData[playerid][PlayerStats][1], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][PlayerStats][1], 0.500000, 1.000000);
	PlayerTextDrawColor(playerid,playerData[playerid][PlayerStats][1], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][PlayerStats][1], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][PlayerStats][1], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][PlayerStats][1], 1);
	PlayerTextDrawUseBox(playerid,playerData[playerid][PlayerStats][1], 1);
	PlayerTextDrawBoxColor(playerid,playerData[playerid][PlayerStats][1], 85);
	PlayerTextDrawTextSize(playerid,playerData[playerid][PlayerStats][1], 10.000000, 293.000000);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][PlayerStats][1], 0);

	playerData[playerid][PlayerStats][2] = CreatePlayerTextDraw(playerid,179.000000, 126.000000, "~y~Your Statistics");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][PlayerStats][2], 255);
	PlayerTextDrawFont(playerid,playerData[playerid][PlayerStats][2], 0);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][PlayerStats][2], 0.600000, 2.000000);
	PlayerTextDrawColor(playerid,playerData[playerid][PlayerStats][2], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][PlayerStats][2], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][PlayerStats][2], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][PlayerStats][2], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][PlayerStats][2], 0);

	playerData[playerid][PlayerStats][3] = CreatePlayerTextDraw(playerid,202.000000, 161.000000, "Criminal Statistics");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][PlayerStats][3], 68);
	PlayerTextDrawFont(playerid,playerData[playerid][PlayerStats][3], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][PlayerStats][3], 0.280000, 1.500000);
	PlayerTextDrawColor(playerid,playerData[playerid][PlayerStats][3], -1104466945);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][PlayerStats][3], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][PlayerStats][3], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][PlayerStats][3], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][PlayerStats][3], 0);

	playerData[playerid][PlayerStats][4] = CreatePlayerTextDraw(playerid,203.000000, 181.000000, "Kills:");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][PlayerStats][4], 102);
	PlayerTextDrawFont(playerid,playerData[playerid][PlayerStats][4], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][PlayerStats][4], 0.319999, 1.100000);
	PlayerTextDrawColor(playerid,playerData[playerid][PlayerStats][4], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][PlayerStats][4], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][PlayerStats][4], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][PlayerStats][4], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][PlayerStats][4], 0);

	playerData[playerid][PlayerStats][5] = CreatePlayerTextDraw(playerid,203.000000, 194.000000, "Deaths:");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][PlayerStats][5], 136);
	PlayerTextDrawFont(playerid,playerData[playerid][PlayerStats][5], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][PlayerStats][5], 0.270000, 1.100000);
	PlayerTextDrawColor(playerid,playerData[playerid][PlayerStats][5], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][PlayerStats][5], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][PlayerStats][5], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][PlayerStats][5], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][PlayerStats][5], 0);

	playerData[playerid][PlayerStats][6] = CreatePlayerTextDraw(playerid,203.000000, 208.000000, "Stores Robbed:");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][PlayerStats][6], 136);
	PlayerTextDrawFont(playerid,playerData[playerid][PlayerStats][6], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][PlayerStats][6], 0.270000, 1.100000);
	PlayerTextDrawColor(playerid,playerData[playerid][PlayerStats][6], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][PlayerStats][6], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][PlayerStats][6], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][PlayerStats][6], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][PlayerStats][6], 0);

	playerData[playerid][PlayerStats][7] = CreatePlayerTextDraw(playerid,203.000000, 236.000000, "Players Raped:");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][PlayerStats][7], 255);
	PlayerTextDrawFont(playerid,playerData[playerid][PlayerStats][7], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][PlayerStats][7], 0.270000, 1.100000);
	PlayerTextDrawColor(playerid,playerData[playerid][PlayerStats][7], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][PlayerStats][7], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][PlayerStats][7], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][PlayerStats][7], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][PlayerStats][7], 0);

	playerData[playerid][PlayerStats][8] = CreatePlayerTextDraw(playerid,203.000000, 250.000000, "K/D Ratio:");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][PlayerStats][8], 136);
	PlayerTextDrawFont(playerid,playerData[playerid][PlayerStats][8], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][PlayerStats][8], 0.270000, 1.100000);
	PlayerTextDrawColor(playerid,playerData[playerid][PlayerStats][8], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][PlayerStats][8], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][PlayerStats][8], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][PlayerStats][8], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][PlayerStats][8], 0);

	playerData[playerid][PlayerStats][9] = CreatePlayerTextDraw(playerid,341.000000, 161.000000, "Police Statistics");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][PlayerStats][9], 68);
	PlayerTextDrawFont(playerid,playerData[playerid][PlayerStats][9], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][PlayerStats][9], 0.280000, 1.500000);
	PlayerTextDrawColor(playerid,playerData[playerid][PlayerStats][9], 1267580159);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][PlayerStats][9], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][PlayerStats][9], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][PlayerStats][9], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][PlayerStats][9], 0);

	playerData[playerid][PlayerStats][10] = CreatePlayerTextDraw(playerid,341.000000, 181.000000, "Kills:");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][PlayerStats][10], 102);
	PlayerTextDrawFont(playerid,playerData[playerid][PlayerStats][10], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][PlayerStats][10], 0.319999, 1.100000);
	PlayerTextDrawColor(playerid,playerData[playerid][PlayerStats][10], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][PlayerStats][10], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][PlayerStats][10], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][PlayerStats][10], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][PlayerStats][10], 0);

	playerData[playerid][PlayerStats][11] = CreatePlayerTextDraw(playerid,341.000000, 194.000000, "Arrests:");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][PlayerStats][11], 136);
	PlayerTextDrawFont(playerid,playerData[playerid][PlayerStats][11], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][PlayerStats][11], 0.270000, 1.100000);
	PlayerTextDrawColor(playerid,playerData[playerid][PlayerStats][11], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][PlayerStats][11], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][PlayerStats][11], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][PlayerStats][11], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][PlayerStats][11], 0);

	playerData[playerid][PlayerStats][12] = CreatePlayerTextDraw(playerid,341.000000, 209.000000, "Detains:");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][PlayerStats][12], 102);
	PlayerTextDrawFont(playerid,playerData[playerid][PlayerStats][12], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][PlayerStats][12], 0.319999, 1.100000);
	PlayerTextDrawColor(playerid,playerData[playerid][PlayerStats][12], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][PlayerStats][12], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][PlayerStats][12], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][PlayerStats][12], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][PlayerStats][12], 0);

	playerData[playerid][PlayerStats][13] = CreatePlayerTextDraw(playerid,320.000000, 283.000000, "~n~~n~");
	PlayerTextDrawAlignment(playerid,playerData[playerid][PlayerStats][13], 2);
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][PlayerStats][13], 255);
	PlayerTextDrawFont(playerid,playerData[playerid][PlayerStats][13], 2);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][PlayerStats][13], 0.300000, 1.000000);
	PlayerTextDrawColor(playerid,playerData[playerid][PlayerStats][13], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][PlayerStats][13], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][PlayerStats][13], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][PlayerStats][13], 1);
	PlayerTextDrawUseBox(playerid,playerData[playerid][PlayerStats][13], 1);
	PlayerTextDrawBoxColor(playerid,playerData[playerid][PlayerStats][13], 255);
	PlayerTextDrawTextSize(playerid,playerData[playerid][PlayerStats][13], -10.000000, 292.000000);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][PlayerStats][13], 0);

	playerData[playerid][PlayerStats][14] = CreatePlayerTextDraw(playerid,230.000000, 287.000000, "Type /closehelp to close this dialog");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][PlayerStats][14], 85);
	PlayerTextDrawFont(playerid,playerData[playerid][PlayerStats][14], 2);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][PlayerStats][14], 0.209999, 1.100000);
	PlayerTextDrawColor(playerid,playerData[playerid][PlayerStats][14], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][PlayerStats][14], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][PlayerStats][14], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][PlayerStats][14], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][PlayerStats][14], 0);

	playerData[playerid][PlayerStats][15] = CreatePlayerTextDraw(playerid,231.000000, 181.000000, "~y~392");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][PlayerStats][15], 102);
	PlayerTextDrawFont(playerid,playerData[playerid][PlayerStats][15], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][PlayerStats][15], 0.319999, 1.100000);
	PlayerTextDrawColor(playerid,playerData[playerid][PlayerStats][15], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][PlayerStats][15], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][PlayerStats][15], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][PlayerStats][15], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][PlayerStats][15], 0);

	playerData[playerid][PlayerStats][16] = CreatePlayerTextDraw(playerid,240.000000, 194.000000, "~y~27");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][PlayerStats][16], 136);
	PlayerTextDrawFont(playerid,playerData[playerid][PlayerStats][16], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][PlayerStats][16], 0.270000, 1.100000);
	PlayerTextDrawColor(playerid,playerData[playerid][PlayerStats][16], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][PlayerStats][16], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][PlayerStats][16], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][PlayerStats][16], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][PlayerStats][16], 0);

	playerData[playerid][PlayerStats][17] = CreatePlayerTextDraw(playerid,275.000000, 208.000000, "~y~42");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][PlayerStats][17], 136);
	PlayerTextDrawFont(playerid,playerData[playerid][PlayerStats][17], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][PlayerStats][17], 0.270000, 1.100000);
	PlayerTextDrawColor(playerid,playerData[playerid][PlayerStats][17], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][PlayerStats][17], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][PlayerStats][17], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][PlayerStats][17], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][PlayerStats][17], 0);

	playerData[playerid][PlayerStats][18] = CreatePlayerTextDraw(playerid,277.000000, 222.000000, "~y~17");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][PlayerStats][18], 136);
	PlayerTextDrawFont(playerid,playerData[playerid][PlayerStats][18], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][PlayerStats][18], 0.270000, 1.100000);
	PlayerTextDrawColor(playerid,playerData[playerid][PlayerStats][18], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][PlayerStats][18], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][PlayerStats][18], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][PlayerStats][18], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][PlayerStats][18], 0);

	playerData[playerid][PlayerStats][19] = CreatePlayerTextDraw(playerid,271.000000, 236.000000, "~y~12");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][PlayerStats][19], 136);
	PlayerTextDrawFont(playerid,playerData[playerid][PlayerStats][19], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][PlayerStats][19], 0.270000, 1.100000);
	PlayerTextDrawColor(playerid,playerData[playerid][PlayerStats][19], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][PlayerStats][19], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][PlayerStats][19], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][PlayerStats][19], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][PlayerStats][19], 0);

	playerData[playerid][PlayerStats][20] = CreatePlayerTextDraw(playerid,251.000000, 251.000000, "~y~14.5");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][PlayerStats][20], 136);
	PlayerTextDrawFont(playerid,playerData[playerid][PlayerStats][20], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][PlayerStats][20], 0.270000, 1.000000);
	PlayerTextDrawColor(playerid,playerData[playerid][PlayerStats][20], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][PlayerStats][20], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][PlayerStats][20], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][PlayerStats][20], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][PlayerStats][20], 0);

	playerData[playerid][PlayerStats][21] = CreatePlayerTextDraw(playerid,250.000000, 10.000000, "New Textdraw");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][PlayerStats][21], 255);
	PlayerTextDrawFont(playerid,playerData[playerid][PlayerStats][21], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][PlayerStats][21], 0.500000, 1.000000);
	PlayerTextDrawColor(playerid,playerData[playerid][PlayerStats][21], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][PlayerStats][21], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][PlayerStats][21], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][PlayerStats][21], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][PlayerStats][21], 0);

	playerData[playerid][PlayerStats][22] = CreatePlayerTextDraw(playerid,379.000000, 194.000000, "~y~3");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][PlayerStats][22], 136);
	PlayerTextDrawFont(playerid,playerData[playerid][PlayerStats][22], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][PlayerStats][22], 0.270000, 1.100000);
	PlayerTextDrawColor(playerid,playerData[playerid][PlayerStats][22], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][PlayerStats][22], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][PlayerStats][22], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][PlayerStats][22], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][PlayerStats][22], 0);

	playerData[playerid][PlayerStats][23] = CreatePlayerTextDraw(playerid,369.000000, 181.000000, "~y~9");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][PlayerStats][23], 102);
	PlayerTextDrawFont(playerid,playerData[playerid][PlayerStats][23], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][PlayerStats][23], 0.319999, 1.100000);
	PlayerTextDrawColor(playerid,playerData[playerid][PlayerStats][23], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][PlayerStats][23], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][PlayerStats][23], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][PlayerStats][23], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][PlayerStats][23], 0);

	playerData[playerid][PlayerStats][24] = CreatePlayerTextDraw(playerid,386.000000, 209.000000, "~y~0");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][PlayerStats][24], 102);
	PlayerTextDrawFont(playerid,playerData[playerid][PlayerStats][24], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][PlayerStats][24], 0.319999, 1.100000);
	PlayerTextDrawColor(playerid,playerData[playerid][PlayerStats][24], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][PlayerStats][24], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][PlayerStats][24], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][PlayerStats][24], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][PlayerStats][24], 0);

	/***************
	| Break into homes
	***************/

	playerData[playerid][BaE][0] = CreatePlayerTextDraw(playerid,235.000000, 153.000000, "~r~Breaking ~w~and ~r~Entering");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][BaE][0], 85);
	PlayerTextDrawFont(playerid,playerData[playerid][BaE][0], 3);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][BaE][0], 0.449999, 2.199999);
	PlayerTextDrawColor(playerid,playerData[playerid][BaE][0], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][BaE][0], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][BaE][0], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][BaE][0], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][BaE][0], 0);

	playerData[playerid][BaE][1] = CreatePlayerTextDraw(playerid,320.000000, 150.000000, "~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~");
	PlayerTextDrawAlignment(playerid,playerData[playerid][BaE][1], 2);
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][BaE][1], 255);
	PlayerTextDrawFont(playerid,playerData[playerid][BaE][1], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][BaE][1], 0.500000, 1.000000);
	PlayerTextDrawColor(playerid,playerData[playerid][BaE][1], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][BaE][1], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][BaE][1], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][BaE][1], 1);
	PlayerTextDrawUseBox(playerid,playerData[playerid][BaE][1], 1);
	PlayerTextDrawBoxColor(playerid,playerData[playerid][BaE][1], 85);
	PlayerTextDrawTextSize(playerid,playerData[playerid][BaE][1], 160.000000, 210.000000);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][BaE][1], 0);

	playerData[playerid][BaE][2] = CreatePlayerTextDraw(playerid,236.000000, 180.000000, "Attempting to break into this home..");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][BaE][2], 68);
	PlayerTextDrawFont(playerid,playerData[playerid][BaE][2], 2);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][BaE][2], 0.200000, 1.000000);
	PlayerTextDrawColor(playerid,playerData[playerid][BaE][2], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][BaE][2], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][BaE][2], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][BaE][2], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][BaE][2], 0);

	playerData[playerid][BaE][3] = CreatePlayerTextDraw(playerid,320.000000, 244.000000, "~n~~n~");
	PlayerTextDrawAlignment(playerid,playerData[playerid][BaE][3], 2);
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][BaE][3], 255);
	PlayerTextDrawFont(playerid,playerData[playerid][BaE][3], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][BaE][3], 0.500000, 1.000000);
	PlayerTextDrawColor(playerid,playerData[playerid][BaE][3], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][BaE][3], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][BaE][3], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][BaE][3], 1);
	PlayerTextDrawUseBox(playerid,playerData[playerid][BaE][3], 1);
	PlayerTextDrawBoxColor(playerid,playerData[playerid][BaE][3], 255);
	PlayerTextDrawTextSize(playerid,playerData[playerid][BaE][3], -10.000000, 210.000000);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][BaE][3], 0);

	playerData[playerid][BaE][4] = CreatePlayerTextDraw(playerid,238.000000, 247.000000, "Type /cancel to close this dialog");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][BaE][4], 85);
	PlayerTextDrawFont(playerid,playerData[playerid][BaE][4], 2);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][BaE][4], 0.209999, 1.100000);
	PlayerTextDrawColor(playerid,playerData[playerid][BaE][4], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][BaE][4], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][BaE][4], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][BaE][4], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][BaE][4], 0);

	/***************
	| ROBBERY TEXTDRAW
	***************/


	playerData[playerid][robTD][0] = CreatePlayerTextDraw(playerid, 314.500000, 188.562500, "Robbing: ~w~Burger Shot");
	PlayerTextDrawLetterSize(playerid, playerData[playerid][robTD][0], 0.192499, 1.389999);
	PlayerTextDrawAlignment(playerid, playerData[playerid][robTD][0], 2);
	PlayerTextDrawColor(playerid, playerData[playerid][robTD][0], -5963521);
	PlayerTextDrawSetShadow(playerid, playerData[playerid][robTD][0], 0);
	PlayerTextDrawSetOutline(playerid, playerData[playerid][robTD][0], 1);
	PlayerTextDrawBackgroundColor(playerid, playerData[playerid][robTD][0], 51);
	PlayerTextDrawFont(playerid, playerData[playerid][robTD][0], 2);
	PlayerTextDrawSetProportional(playerid, playerData[playerid][robTD][0], 1);

	playerData[playerid][robTD][1] = CreatePlayerTextDraw(playerid, 394.500000, 190.937500, "usebox");
	PlayerTextDrawLetterSize(playerid, playerData[playerid][robTD][1], 0.000000, 8.773611);
	PlayerTextDrawTextSize(playerid, playerData[playerid][robTD][1], 229.500000, 0.000000);
	PlayerTextDrawAlignment(playerid, playerData[playerid][robTD][1], 1);
	PlayerTextDrawColor(playerid, playerData[playerid][robTD][1], 0);
	PlayerTextDrawUseBox(playerid, playerData[playerid][robTD][1], true);
	PlayerTextDrawBoxColor(playerid, playerData[playerid][robTD][1], 102);
	PlayerTextDrawSetShadow(playerid, playerData[playerid][robTD][1], 0);
	PlayerTextDrawSetOutline(playerid, playerData[playerid][robTD][1], 0);
	PlayerTextDrawFont(playerid, playerData[playerid][robTD][1], 0);

	playerData[playerid][robTD][2] = CreatePlayerTextDraw(playerid, 313.500000, 215.250000, "lllllllllllllll");
	PlayerTextDrawLetterSize(playerid, playerData[playerid][robTD][2], 0.773999, 2.654374);
	PlayerTextDrawAlignment(playerid, playerData[playerid][robTD][2], 2);
	PlayerTextDrawColor(playerid, playerData[playerid][robTD][2], -16776961);
	PlayerTextDrawSetShadow(playerid, playerData[playerid][robTD][2], 0);
	PlayerTextDrawSetOutline(playerid, playerData[playerid][robTD][2], 1);
	PlayerTextDrawBackgroundColor(playerid, playerData[playerid][robTD][2], 51);
	PlayerTextDrawFont(playerid, playerData[playerid][robTD][2], 1);
	PlayerTextDrawSetProportional(playerid, playerData[playerid][robTD][2], 1);

	playerData[playerid][robTD][3] = CreatePlayerTextDraw(playerid, 318.000000, 253.312500, "Press C to cancel the robbery.");
	PlayerTextDrawLetterSize(playerid, playerData[playerid][robTD][3], 0.188499, 1.153750);
	PlayerTextDrawAlignment(playerid, playerData[playerid][robTD][3], 2);
	PlayerTextDrawColor(playerid, playerData[playerid][robTD][3], -1);
	PlayerTextDrawSetShadow(playerid, playerData[playerid][robTD][3], 0);
	PlayerTextDrawSetOutline(playerid, playerData[playerid][robTD][3], 1);
	PlayerTextDrawBackgroundColor(playerid, playerData[playerid][robTD][3], 51);
	PlayerTextDrawFont(playerid, playerData[playerid][robTD][3], 1);
	PlayerTextDrawSetProportional(playerid, playerData[playerid][robTD][3], 1);



	/***************
	| CLASS SELECTION
	***************/

	playerData[playerid][classSelect][0] = CreatePlayerTextDraw(playerid,320.000000, 140.000000, "~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~");
	PlayerTextDrawAlignment(playerid,playerData[playerid][classSelect][0], 2);
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][classSelect][0], 255);
	PlayerTextDrawFont(playerid,playerData[playerid][classSelect][0], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][classSelect][0], 0.500000, 1.000000);
	PlayerTextDrawColor(playerid,playerData[playerid][classSelect][0], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][classSelect][0], 1);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][classSelect][0], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][classSelect][0], 1);
	PlayerTextDrawUseBox(playerid,playerData[playerid][classSelect][0], 1);
	PlayerTextDrawBoxColor(playerid,playerData[playerid][classSelect][0], 85);
	PlayerTextDrawTextSize(playerid,playerData[playerid][classSelect][0], 10.000000, 293.000000);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][classSelect][0], 0);

	playerData[playerid][classSelect][1] = CreatePlayerTextDraw(playerid,179.000000, 126.000000, "~y~Class Selection");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][classSelect][1], 255);
	PlayerTextDrawFont(playerid,playerData[playerid][classSelect][1], 0);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][classSelect][1], 0.600000, 2.000000);
	PlayerTextDrawColor(playerid,playerData[playerid][classSelect][1], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][classSelect][1], 1);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][classSelect][1], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][classSelect][1], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][classSelect][1], 0);

	playerData[playerid][classSelect][2] = CreatePlayerTextDraw(playerid,202.000000, 161.000000, "Undefined Class");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][classSelect][2], 68);
	PlayerTextDrawFont(playerid,playerData[playerid][classSelect][2], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][classSelect][2], 0.280000, 1.500000);
	PlayerTextDrawColor(playerid,playerData[playerid][classSelect][2], 1217650431);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][classSelect][2], 1);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][classSelect][2], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][classSelect][2], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][classSelect][2], 0);

	playerData[playerid][classSelect][3] = CreatePlayerTextDraw(playerid,202.000000, 180.000000, "Undefined String 1");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][classSelect][3], 51);
	PlayerTextDrawFont(playerid,playerData[playerid][classSelect][3], 2);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][classSelect][3], 0.200000, 1.100000);
	PlayerTextDrawColor(playerid,playerData[playerid][classSelect][3], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][classSelect][3], 1);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][classSelect][3], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][classSelect][3], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][classSelect][3], 0);

	playerData[playerid][classSelect][4] = CreatePlayerTextDraw(playerid,202.000000, 192.000000, "Undefined String 2");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][classSelect][4], 255);
	PlayerTextDrawFont(playerid,playerData[playerid][classSelect][4], 2);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][classSelect][4], 0.200000, 1.100000);
	PlayerTextDrawColor(playerid,playerData[playerid][classSelect][4], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][classSelect][4], 1);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][classSelect][4], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][classSelect][4], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][classSelect][4], 0);

	playerData[playerid][classSelect][5] = CreatePlayerTextDraw(playerid,320.000000, 283.000000, "~n~~n~");
	PlayerTextDrawAlignment(playerid,playerData[playerid][classSelect][5], 2);
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][classSelect][5], 255);
	PlayerTextDrawFont(playerid,playerData[playerid][classSelect][5], 2);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][classSelect][5], 0.300000, 1.000000);
	PlayerTextDrawColor(playerid,playerData[playerid][classSelect][5], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][classSelect][5], 1);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][classSelect][5], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][classSelect][5], 1);
	PlayerTextDrawUseBox(playerid,playerData[playerid][classSelect][5], 1);
	PlayerTextDrawBoxColor(playerid,playerData[playerid][classSelect][5], 255);
	PlayerTextDrawTextSize(playerid,playerData[playerid][classSelect][5], -10.000000, 292.000000);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][classSelect][5], 0);

	playerData[playerid][classSelect][6] = CreatePlayerTextDraw(playerid,319.000000, 287.000000, "0 XP REQUIRED");
	PlayerTextDrawAlignment(playerid,playerData[playerid][classSelect][6], 2);
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][classSelect][6], 85);
	PlayerTextDrawFont(playerid,playerData[playerid][classSelect][6], 2);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][classSelect][6], 0.209999, 1.100000);
	PlayerTextDrawColor(playerid,playerData[playerid][classSelect][6], 0xE2FF00FF);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][classSelect][6], 1);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][classSelect][6], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][classSelect][6], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][classSelect][6], 0);

	playerData[playerid][classSelect][7] = CreatePlayerTextDraw(playerid,202.000000, 205.000000, "Undefined String 3");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][classSelect][7], 255);
	PlayerTextDrawFont(playerid,playerData[playerid][classSelect][7], 2);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][classSelect][7], 0.200000, 1.100000);
	PlayerTextDrawColor(playerid,playerData[playerid][classSelect][7], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][classSelect][7], 1);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][classSelect][7], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][classSelect][7], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][classSelect][7], 0);

	/***************
	| OBJECTS LOADING
	***************/

	playerData[playerid][objects][0] = CreatePlayerTextDraw(playerid,320.000000, 150.000000, "~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~");
	PlayerTextDrawAlignment(playerid,playerData[playerid][objects][0], 2);
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][objects][0], 255);
	PlayerTextDrawFont(playerid,playerData[playerid][objects][0], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][objects][0], 0.500000, 1.000000);
	PlayerTextDrawColor(playerid,playerData[playerid][objects][0], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][objects][0], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][objects][0], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][objects][0], 1);
	PlayerTextDrawUseBox(playerid,playerData[playerid][objects][0], 1);
	PlayerTextDrawBoxColor(playerid,playerData[playerid][objects][0], 85);
	PlayerTextDrawTextSize(playerid,playerData[playerid][objects][0], 160.000000, 210.000000);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][objects][0], 0);

	playerData[playerid][objects][1] = CreatePlayerTextDraw(playerid,319.000000, 172.000000, "The objects around you are~n~loading.");
	PlayerTextDrawAlignment(playerid,playerData[playerid][objects][1], 2);
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][objects][1], 68);
	PlayerTextDrawFont(playerid,playerData[playerid][objects][1], 2);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][objects][1], 0.230000, 1.300000);
	PlayerTextDrawColor(playerid,playerData[playerid][objects][1], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][objects][1], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][objects][1], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][objects][1], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][objects][1], 0);

	playerData[playerid][objects][2] = CreatePlayerTextDraw(playerid,320.000000, 127.000000, "~n~~n~");
	PlayerTextDrawAlignment(playerid,playerData[playerid][objects][2], 2);
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][objects][2], 255);
	PlayerTextDrawFont(playerid,playerData[playerid][objects][2], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][objects][2], 0.500000, 1.000000);
	PlayerTextDrawColor(playerid,playerData[playerid][objects][2], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][objects][2], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][objects][2], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][objects][2], 1);
	PlayerTextDrawUseBox(playerid,playerData[playerid][objects][2], 1);
	PlayerTextDrawBoxColor(playerid,playerData[playerid][objects][2], 255);
	PlayerTextDrawTextSize(playerid,playerData[playerid][objects][2], 160.000000, 210.000000);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][objects][2], 0);

	playerData[playerid][objects][3] = CreatePlayerTextDraw(playerid,280.000000, 130.000000, "~y~Please Wait");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][objects][3], 255);
	PlayerTextDrawFont(playerid,playerData[playerid][objects][3], 2);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][objects][3], 0.280000, 1.100000);
	PlayerTextDrawColor(playerid,playerData[playerid][objects][3], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][objects][3], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][objects][3], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][objects][3], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][objects][3], 0);
	
	/***************
	| TOWN TD
	***************/
	
	/*playerData[playerid][townTD] = CreatePlayerTextDraw(playerid, 307.350311, 0.583424, "/SELECTTOWN IF YOU WANT TO CHANGE SPAWN CITY");
	PlayerTextDrawLetterSize(playerid, playerData[playerid][townTD], 0.145929, 1.045833);
	PlayerTextDrawAlignment(playerid, playerData[playerid][townTD], 2);
	PlayerTextDrawColor(playerid, playerData[playerid][townTD], -1);
	PlayerTextDrawSetShadow(playerid, playerData[playerid][townTD], 0);
	PlayerTextDrawSetOutline(playerid, playerData[playerid][townTD], 1);
	PlayerTextDrawBackgroundColor(playerid, playerData[playerid][townTD], 51);
	PlayerTextDrawFont(playerid, playerData[playerid][townTD], 1);
	PlayerTextDrawSetProportional(playerid, playerData[playerid][townTD], 1);
	PlayerTextDrawShow(playerid, playerData[playerid][townTD]);*/

	/*************** :vlol
	| ACHIEVEMENTS
	**************/

	playerData[playerid][Achieve1] = CreatePlayerTextDraw(playerid,431.000000, 260.000000, "      ");
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][Achieve1], 255);
	PlayerTextDrawFont(playerid,playerData[playerid][Achieve1], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][Achieve1], 0.500000, 1.000000);
	PlayerTextDrawColor(playerid,playerData[playerid][Achieve1], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][Achieve1], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][Achieve1], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][Achieve1], 1);
	PlayerTextDrawUseBox(playerid,playerData[playerid][Achieve1], 1);
	PlayerTextDrawBoxColor(playerid,playerData[playerid][Achieve1], 128);
	PlayerTextDrawTextSize(playerid,playerData[playerid][Achieve1], 205.000000, 0.000000);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][Achieve1], 0);

	playerData[playerid][Achieve2] = CreatePlayerTextDraw(playerid,317.000000, 262.000000, "Achievement Unlocked");
	PlayerTextDrawAlignment(playerid,playerData[playerid][Achieve2], 2);
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][Achieve2], 255);
	PlayerTextDrawFont(playerid,playerData[playerid][Achieve2], 2);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][Achieve2], 0.200000, 1.100000);
	PlayerTextDrawColor(playerid,playerData[playerid][Achieve2], -4259585);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][Achieve2], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][Achieve2], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][Achieve2], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][Achieve2], 0);

	playerData[playerid][Achieve3] = CreatePlayerTextDraw(playerid,320.000000, 276.000000, "Achieved.");
	PlayerTextDrawAlignment(playerid,playerData[playerid][Achieve3], 2);
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][Achieve3], 255);
	PlayerTextDrawFont(playerid,playerData[playerid][Achieve3], 1);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][Achieve3], 0.200000, 1.000000);
	PlayerTextDrawColor(playerid,playerData[playerid][Achieve3], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][Achieve3], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][Achieve3], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][Achieve3], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][Achieve3], 0);

	playerData[playerid][Achieve4] = CreatePlayerTextDraw(playerid,320.000000, 290.000000, "Achieved.");
	PlayerTextDrawAlignment(playerid,playerData[playerid][Achieve4], 2);
	PlayerTextDrawBackgroundColor(playerid,playerData[playerid][Achieve4], 68);
	PlayerTextDrawFont(playerid,playerData[playerid][Achieve4], 2);
	PlayerTextDrawLetterSize(playerid,playerData[playerid][Achieve4], 0.170000, 1.000000);
	PlayerTextDrawColor(playerid,playerData[playerid][Achieve4], -1);
	PlayerTextDrawSetOutline(playerid,playerData[playerid][Achieve4], 0);
	PlayerTextDrawSetProportional(playerid,playerData[playerid][Achieve4], 1);
	PlayerTextDrawSetShadow(playerid,playerData[playerid][Achieve4], 1);
	PlayerTextDrawSetSelectable(playerid,playerData[playerid][Achieve4], 0);
	
	playerData[playerid][xpBar] = CreateProgressBar(503.000000, 427.999786, 128.5, 13.2, 16711884);
	SetProgressBarValue(playerData[playerid][xpBar], 0.0);
	ShowProgressBarForPlayer(playerid, playerData[playerid][xpBar]);
}
