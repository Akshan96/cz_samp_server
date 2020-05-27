// Database defines
new MySQL:connection;

// Dialog defines
#define DIALOG_REGISTER 			1
#define DIALOG_LOGIN 				2
#define DIALOG_STATS 				3
#define DIALOG_STATS_MSGBOX			4
#define DIALOG_ATELEPORT        	5
#define DIALOG_HOUSEMENU        	6
#define DIALOG_HOUSEMENU_LOCKM  	7
#define DIALOG_HOUSEMENU_LOCK   	8
#define DIALOG_HOUSEMENU_UNLOCK 	9
#define DIALOG_HOUSEMENU_INT    	10
#define DIALOG_HOUSEMENU_SELL   	11
#define DIALOG_SUPASAVE         	12
#define DIALOG_DEBUG				13
#define DIALOG_WEAPONPACKS			14
#define DIALOG_ARENAS				15
#define DIALOG_JOBSELECT			16
#define DIALOG_ADMINSTATS			17
#define DIALOG_ADMINSTATS_MSGBOX	18
#define DIALOG_WEAPCHECK			19
#define DIALOG_HOSPITAL				20
#define DIALOG_GYM					21
#define DIALOG_VEHICLE_LOCATE		22
#define DIALOG_MECHCOLOUR			23
#define DIALOG_AMMU					24
#define DIALOG_RADIO				25
#define DIALOG_BANNED				26
#define DIALOG_HOUSEMENU_TITLE		27
#define DIALOG_MUSIC				28
#define DIALOG_CS		            102
#define DIALOG_ABANNED				29
#define DIALOG_CBANNED				30
#define DIALOG_COURIER_START		31
#define DIALOG_UNDERCOVER			32
#define DIALOG_VEHICLEMENU			33
#define DIALOG_UNBANME					103
#define DIALOG_HELP					34
#define DIALOG_COMMANDS				35
#define DIALOG_RULES				36
#define DIALOG_BANK					37
#define DIALOG_BANK_DEPOSIT			38
#define DIALOG_BANK_WITHDRAW		39
#define DIALOG_CITYHALL				40
#define DIALOG_JOBCHANGE			41
#define DIALOG_SETJOB				42

// Police Tutorial
#define POLICE_TUTORIAL_1			43
#define POLICE_TUTORIAL_2			44
#define POLICE_TUTORIAL_3			45
#define POLICE_TUTORIAL_4			46

// Ammunation
#define DIALOG_AMMU_MELEE			47
#define DIALOG_AMMU_HANDGUNS		48
#define DIALOG_AMMU_SUBMACHINES		49
#define DIALOG_AMMU_SHOTGUNS		50
#define DIALOG_AMMU_ASSAULTRIFLES	51
#define DIALOG_AMMU_RIFLES			52

// Weapon Dealer
#define DIALOG_CP			       104
#define DIALOG_WEAPONDEALER			53
#define DIALOG_WD_MELEE				54
#define DIALOG_WD_HANDGUNS			55
#define DIALOG_WD_SUBMACHINES		56
#define DIALOG_WD_SHOTGUNS			57
#define DIALOG_WD_ASSAULTRIFLES		58
#define DIALOG_WD_RIFLES			59

#define DIALOG_WELCOME				60
#define DIALOG_PLAYER_COLOURS		61
#define DIALOG_GUNDEAL				62
#define DIALOG_MODMENU				63
#define DIALOG_VIPSHOP				64
#define DIALOG_VIPHAT				65
#define DIALOG_EXPLOSIVE_STORE		66
#define DIALOG_VIP_ALREADY			67
#define DIALOG_VIPGUN				68
#define DIALOG_ACHIEVEMENTS			69
#define DIALOG_HOUSEMENU_PASSWORD	70
#define DIALOG_ENTER_PASSWORD		71
#define DIALOG_MECHANIC				72
#define DIALOG_HOUSEMENU_FEATURES	73
#define DIALOG_VEHICLECOLOR1		74
#define DIALOG_VEHICLECOLOR2		75
#define DIALOG_DEALERSHIP			76
#define DIALOG_SELLVEHICLE			78
#define DIALOG_LOCATEVEHICLE		79
#define DIALOG_VEHICLEOPTIONS		80
#define DIALOG_OPTIONSLIST			81
#define DIALOG_HOUSEMENU_UPGRADE	82
#define DIALOG_HOUSELIST			83
#define DIALOG_REDEMPTION			84
#define DIALOG_REDEEM_VIP			85
#define DIALOG_REDEEM_PRODUCT		86
#define DIALOG_PRODUCT				87
#define DIALOG_MINIGAMES			88
#define DIALOG_FORCE_RESPAWN		89
#define DIALOG_VEHICLESPAWN			90
#define DIALOG_XPSHOP				91
#define DIALOG_VIPCONFIRM			92
#define DIALOG_CONFIRMSALE			93
#define DIALOG_ADMINOPTIONSLIST		94
#define DIALOG_ADMINVEHICLEOPTIONS	95
#define DIALOG_HOUSEOPTIONS			96
#define DIALOG_ADMINHOUSELIST		97
#define DIALOG_ADMINHOUSEOPTIONS	98
#define DIALOG_HOUSESFORSALE		99
#define DIALOG_CONFIRMSALESERVER	100
#define DIALOG_CONNECTSONG		101
#define DIALOG_TOP                  923
#define DIALOG_NEON                 2837
#define DIALOG_TOWN                 105
#define SF							0
#define LV							1
#define	NO_TOWN						-1



#define MAX_ADMIN_SPAWNED_VEHICLES	100
#define MAX_GANGS					MAX_PLAYERS
#define MAX_GLASS 					54

// Class defines
#define CLASS_CIVILIAN				0
#define CLASS_POLICE				1
#define CLASS_ARMY					2
#define CLASS_CIA					3
#define CLASS_FBI					4
#define CLASS_FIREFIGHTER			5
#define CLASS_MEDIC					6
#define CLASS_SECRETSERVICE			7

// Job defines
#define JOB_KIDNAPPER				0
#define JOB_MECHANIC				1
#define JOB_HITMAN					2
#define JOB_WEAPONDEALER			3
#define JOB_RAPIST					4
#define JOB_DRUGDEALER				5
#define JOB_TERRORIST				6
#define JOB_PROSTITUTE				7

// Class colour defines
#define CLASS_CIVILIAN_COLOUR		0xFFFFFFFF
#define CLASS_POLICE_COLOUR			0x3E7EFFFF
#define CLASS_ARMY_COLOUR			0x8F48F5FF
#define CLASS_CIA_COLOUR			0x2F205BFF
#define CLASS_FBI_COLOUR			0x1C3EFFFF
#define CLASS_CIVILIAN_YELLOW		0xFFEC41FF
#define CLASS_CIVILIAN_ORANGE		0xDF802DFF
#define CLASS_CIVILIAN_RED			0xD92C3CFF
#define CLASS_FIREFIGHTER_COLOUR	0x9C3D36FF
#define CLASS_MEDIC_COLOUR			0xF78181FF
#define CLASS_SECRETSERVICE_COLOUR	0x00205B00

// Team defines
#define TEAM_LEO					5

// Vehicles
#define MAX_CLASS_CAR				(163)
#define MAX_COMP 40

// Map Icons
#define MAP_ICON_PLEASURE_DOME		1
#define MAP_ICON_BINCO_CLOTHING_1	2
#define MAP_ICON_BINCO_CLOTHING_2	3
#define MAP_ICON_247_1				4
#define MAP_ICON_ZEROS_RC_SHOP		5
#define MAP_ICON_SF_GYM				6
#define MAP_ICON_DRIVING_SCHOOL		7
#define MAP_ICON_DONUT_SHOP			8
#define MAP_ICON_VICTIM_CLOTHING	9
#define MAP_ICON_ZIP_CLOTHING		10
#define MAP_ICON_247_2				11
#define MAP_ICON_SEX_SHOP			12
#define MAP_ICON_RANDOM_STORE		13
#define MAP_ICON_SUPA_SAVE			14
#define MAP_ICON_HOSPITAL			15
#define MAP_ICON_VIP_LOUNGE			16
#define MAP_ICON_CLUCKIN_BELL_1		17
#define MAP_ICON_GAYDAR_STATION		18
#define MAP_ICON_AMMUNATION			19
#define MAP_ICON_CLUCKIN_BELL_2		20
#define MAP_ICON_TOWN_HALL			21
#define MAP_ICON_SFPD				22
#define MAP_ICON_COURIER_VAN		23
#define MAP_ICON_VEHICLE_LOCATE		24
#define MAP_ICON_DRUGDEALER			25
#define MAP_ICON_GAS_STATION		26
#define MAP_ICON_PIZZA_STACK		27
#define MAP_ICON_SKYDIVE			28
#define MAP_ICON_BOMB_SHOP			29
#define MAP_ICON_BANK				30
#define MAP_ICON_TRUCKING			31
#define MAP_ICON_SEX_SHOP2			32
#define MAP_ICON_BURGERSHOT			33
#define MAP_ICON_PROLAPS			34
#define MAP_ICON_TGBOTTLES			35
#define MAP_ICON_ADMINLOUNGE		36
#define MAP_ICON_BURGERSHOT_2		37
#define MAP_ICON_DEALERSHIP			38
#define MAP_ICON_BURGERSHOT_3		39
#define MAP_ICON_ZIP_CLOTHING_2		40
#define MAP_ICON_TRUCKING_2			41
#define MAP_ICON_HOSPITAL_2			42
#define MAP_ICON_JOBCENTRE			43
#define MAP_ICON_PIZZA_STACK_2		44
#define MAP_ICON_SUBURBAN			45
#define MAP_ICON_SEX_SHOP_2			46
#define MAP_ICON_MINIGAMES			47
#define MAP_ICON_AMMUNATION_2		48
#define MAP_ICON_CARSPAWN1			49
#define MAP_ICON_CARSPAWN2			50
#define MAP_ICON_CARSPAWN3			51
#define MAP_ICON_CARSPAWN4			52
#define MAP_ICON_CARSPAWN5			53
#define MAP_ICON_CARSPAWN6			54
#define MAP_ICON_CARSPAWN7			55
#define MAP_ICON_CARSPAWN8			56
#define MAP_ICON_CARSPAWN9			57
#define MAP_ICON_HOUSE_LOCATE		58

// Define colours
#define COLOR_GREY					0xAFAFAFAA
#define COLOR_GREEN					0x33AA33AA
#define COLOR_RED					0xAA3333AA
#define COLOR_YELLOW 				0xFFFF00FF
#define COLOR_WHITE 				0xFFFFFFFF
#define COLOR_BLUE 					0x0000BBAA
#define COLOR_LIGHTBLUE				0x33CCFFAA
#define COLOR_ORANGE 				0xFF9900AA
#define COLOR_RED 					0xAA3333AA
#define COLOR_LIME 					0x10F441AA
#define COLOR_MAGENTA 				0xFF00FFFF
#define COLOR_NAVY 					0x000080AA
#define COLOR_AQUA 					0xF0F8FFAA
#define COLOR_CRIMSON 				0xDC143CAA
#define COLOR_FLBLUE 				0x6495EDAA
#define COLOR_BISQUE 				0xFFE4C4AA
#define COLOR_BLACK 				0x000000AA
#define COLOR_CHARTREUSE 			0x7FFF00AA
#define COLOR_BROWN 				0XA52A2AAA
#define COLOR_CORAL 				0xFF7F50AA
#define COLOR_GOLD 					0xB8860BFF
#define COLOR_GREENYELLOW 			0xADFF2FAA
#define COLOR_INDIGO 				0x4B00B0AA
#define COLOR_IVORY					0xFFFF82AA
#define COLOR_LAWNGREEN 			0x7CFC00AA
#define COLOR_SEAGREEN 				0x20B2AAAA
#define COLOR_PURPLE 				0x9A2EFEAA

#define WEAPONPRICES_BRASSKNUCKLES	100
#define WEAPONPRICES_GOLFCLUB		150
#define WEAPONPRICES_KNIFE			100
#define WEAPONPRICES_BASEBALLBAT	150
#define WEAPONPRICES_SHOVEL			200
#define WEAPONPRICES_POOLCUE		250
#define WEAPONPRICES_CHAINSAW		750
#define WEAPONPRICES_PURPLEDILDO	250
#define WEAPONPRICES_CAMERA			100
#define WEAPONPRICES_COLT45			500
#define WEAPONPRICES_SILENCED9MM	750
#define WEAPONPRICES_DESERTEAGLE	800
#define WEAPONPRICES_MICROUZI		1000
#define WEAPONPRICES_TEC9			1000
#define WEAPONPRICES_MP5			1250
#define WEAPONPRICES_PUMPACTION		750
#define WEAPONPRICES_SAWNOFF		2500
#define WEAPONPRICES_COMBATSHOTGUN	1500
#define WEAPONPRICES_AK47			1000
#define WEAPONPRICES_M4				2000
#define WEAPONPRICES_COUNTRYRIFLE	750
#define WEAPONPRICES_SNIPERRIFLE	1000

#define INVALID_GANG_ID				-1
#define MAX_GANG_CHARS				24

#define COLOR_TIME 0xFFFFFFFF
#define COLOR_DAY  0xFFFFFFFF
#define MINUTE 1000

#define PLAYER_MAX_VEHICLES 			3	
#define VIP_MAX_VEHICLES                10
#define STANDARD_VIP_MAX_VEHICLES		4
#define SILVER_VIP_MAX_VEHICLES			6
#define GOLD_VIP_MAX_VEHICLES           7
#define GOLDPLUS_VIP_MAX_VEHICLES       10
//
#define PLAYER_MAX_HOUSES				3
#define VIP_MAX_HOUSES                  6
#define STANDARD_VIP_MAX_HOUSES         4
#define SILVER_VIP_MAX_HOUSES           5
#define GOLD_VIP_MAX_HOUSES				6
#define GOLDPLUS_VIP_MAX_HOUSES         10
//
#define function%0(%1) forward%0(%1); public%0(%1)
#undef isnull
#define isnull(%1) ((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))

new ccount[MAX_PLAYERS];
new componentsid[MAX_PLAYERS][MAX_COMP];

enum HouseInfo
{
    Owner[24],
    Title[24],
    Owned,
    Price,
    Float:XPos,
    Float:YPos,
    Float:ZPos,
    Float:IntX,
    Float:IntY,
    Float:IntZ,
    InteriorID,
    locked,
    thisID,
    VirtualWorld,
    VIP,
    Text3D:HouseLabel,
	Text3D:HouseLabel2
}

enum civSpawnLocs
{
	Float:spawnLocX,
	Float:spawnLocY,
	Float:spawnLocZ,
	Float:spawnAngle
}

new vehicleNames[213][] =
{
	{"Landstalker"}, {"Bravura"}, {"Buffalo"}, {"Linerunner"}, {"Perrenial"}, {"Sentinel"}, {"Dumper"}, {"Firetruck"}, {"Trashmaster"}, {"Stretch"},
	{"Manana"}, {"Infernus"}, {"Voodoo"}, {"Pony"}, {"Mule"}, {"Cheetah"}, {"Ambulance"}, {"Leviathan"}, {"Moonbeam"}, {"Esperanto"},
	{"Taxi"}, {"Washington"}, {"Bobcat"}, {"Mr Whoopee"}, {"BF Injection"}, {"Hunter"}, {"Premier"}, {"Enforcer"}, {"Securicar"}, {"Banshee"},
	{"Predator"}, {"Bus"}, {"Rhino"}, {"Barracks"}, {"Hotknife"}, {"Trailer 1"}, {"Previon"}, {"Coach"}, {"Cabbie"}, {"Stallion"},
	{"Rumpo"}, {"RC Bandit"}, {"Romero"}, {"Packer"}, {"Monster"}, {"Admiral"}, {"Squalo"}, {"Seasparrow"}, {"Pizzaboy"}, {"Tram"},
	{"Trailer 2"}, {"Turismo"}, {"Speeder"}, {"Reefer"}, {"Tropic"}, {"Flatbed"}, {"Yankee"}, {"Caddy"}, {"Solair"}, {"Berkley's RC Van"},
	{"Skimmer"}, {"PCJ-600"}, {"Faggio"}, {"Freeway"}, {"RC Baron"}, {"RC Raider"}, {"Glendale"}, {"Oceanic"}, {"Sanchez"}, {"Standard Sparrow"},
	{"Patriot"}, {"Quad"}, {"Coastguard"}, {"Dinghy"}, {"Hermes"}, {"Sabre"}, {"Rustler"}, {"ZR-350"}, {"Walton"}, {"Regina"},
	{"Comet"}, {"BMX"}, {"Burrito"}, {"Camper"}, {"Marquis"}, {"Baggage"}, {"Dozer"}, {"Maverick"}, {"News Chopper"}, {"Rancher"},
	{"FBI Rancher"}, {"Virgo"}, {"Greenwood"}, {"Jetmax"}, {"Hotring"}, {"Sandking"}, {"Blista Compact"}, {"Police Maverick"}, {"Boxville"}, {"Benson"},
	{"Mesa"}, {"RC Goblin"}, {"Hotring Racer A"}, {"Hotring Racer B"}, {"Bloodring Banger"}, {"Rancher"}, {"Super GT"}, {"Elegant"}, {"Journey"}, {"Bike"},
	{"Mountain Bike"}, {"Beagle"}, {"Cropdust"}, {"Stunt Plane"}, {"Tanker"}, {"Roadtrain"}, {"Nebula"}, {"Majestic"}, {"Buccaneer"}, {"Shamal"},
	{"Hydra"}, {"FCR-900"}, {"NRG-500"}, {"HPV1000"}, {"Cement Truck"}, {"Tow Truck"}, {"Fortune"}, {"Cadrona"}, {"FBI Truck"}, {"Willard"},
	{"Forklift"}, {"Tractor"}, {"Combine"}, {"Feltzer"}, {"Remington"}, {"Slamvan"}, {"Blade"}, {"Freight"}, {"Streak"}, {"Vortex"},
	{"Vincent"}, {"Bullet"}, {"Clover"}, {"Sadler"}, {"Firetruck LA"}, {"Hustler"}, {"Intruder"}, {"Primo"}, {"Cargobob"}, {"Tampa"},
	{"Sunrise"}, {"Merit"}, {"Utility"}, {"Nevada"}, {"Yosemite"}, {"Windsor"}, {"Monster A"}, {"Monster B"}, {"Uranus"}, {"Jester"},
	{"Sultan"}, {"Stratum"}, {"Elegy"}, {"Raindance"}, {"RC Tiger"}, {"Flash"}, {"Tahoma"}, {"Savanna"}, {"Bandito"}, {"Freight Flat"},
	{"Streak Carriage"}, {"Kart"}, {"Mower"}, {"Duneride"}, {"Sweeper"}, {"Broadway"}, {"Tornado"}, {"AT-400"}, {"DFT-30"}, {"Huntley"},
	{"Stafford"}, {"BF-400"}, {"Newsvan"}, {"Tug"}, {"Trailer 3"}, {"Emperor"}, {"Wayfarer"}, {"Euros"}, {"Hotdog"}, {"Club"},
	{"Freight Carriage"}, {"Trailer 3"}, {"Andromada"}, {"Dodo"}, {"RC Cam"}, {"Launch"}, {"Police Car (LSPD)"}, {"Police Car (SFPD)"}, {"Police Car (LVPD)"}, {"Police Ranger"},
	{"Picador"}, {"S.W.A.T. Van"}, {"Alpha"}, {"Phoenix"}, {"Glendale"}, {"Sadler"}, {"Luggage Trailer A"}, {"Luggage Trailer B"}, {"Stair Trailer"}, {"Boxville"},
	{"Farm Plow"}, {"Utility Trailer"}, {"Jetpack"}
};

/*new jobArray[7][] =
{
	{"Kidnapper"},
	{"Mechanic"},
	{"Hitman"},
	{"Weapon dealer"},
	{"Rapist"},
	{"Drug dealer"},
	{"Terrorist"}
};*/

new VehicleSeats[] =
{
    4,2,2,2,4,4,1,2,2,4,2,2,2,4,2,2,4,2,4,2,4,4,2,2,2,1,4,4,4,2,1,500,1,2,2,0,2,500,4,2,4,1,2,2,2,4,1,2,
    1,0,0,2,1,1,1,2,2,2,4,4,2,2,2,2,1,1,4,4,2,2,4,2,1,1,2,2,1,2,2,4,2,1,4,3,1,1,1,4,2,2,4,2,4,1,2,2,2,4,
    4,2,2,1,2,2,2,2,2,4,2,1,1,2,1,1,2,2,4,2,2,1,1,2,2,2,2,2,2,2,2,4,1,1,1,2,2,2,2,500,500,1,4,2,2,2,2,2,
    4,4,2,2,4,4,2,1,2,2,2,2,2,2,4,4,2,2,1,2,4,4,1,0,0,1,1,2,1,2,2,1,2,4,4,2,4,1,0,4,2,2,2,2,0,0,500,2,2,
    1,4,4,4,2,2,2,2,2,4,2,0,0,0,4,0,0
};

#define INVALID_SEAT_ID     999

stock GetEmptySeat(vehicleid)
{
    new bool:Taken[4],Seat,Seats; // [4] ?
    Seats = VehicleSeats[GetVehicleModel(vehicleid)-400];
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerInVehicle(i, vehicleid))
        {
            Seat = GetPlayerVehicleSeat(i);
			Taken[(Seat > 3) ? 3 : Seat] = true;
        }
    }

    for(new d; d < Seats; d++)
	{
        if(!Taken[d] && d != 0)
		{
			return d;
		}
	}
    return INVALID_SEAT_ID;
}

// New stuff

new
	Text:vSpawns[2],
	Text:loginDialog[6],
	Text:dmBox[7],
	Text:streakBox[3],
	Text:alog1,
	Text:alog2,
	Text:alog3,
	Text:alog4,
	Text:alog5,
	Text:URLTD,
	Text:MOTDTD,
	Text:doubleXPTD,
	Text:AdminDuty,
	Text:TDCourier,
	Text:TDCourier2,
	Text:newRob,
	Text:AnnounceTD,
	Text:bankTD,
	Text:gTime,
	Text:gDay,
	Text:easterSunday,
	Text:xmasDay,
	Text:vehicleDealership[4],
	gtime = 0,
	gday = 0,
	N11 = 0,
	resetEMPTimer[MAX_VEHICLES],
	hospitalCP[3],
	CardropCP,
	gymCP[2],
	paraCP,
	ammuCP[6],
	bankCP,
	skydiveCP,
	pickup_chute,
	pickup_vhealth,
	pickup_varmour,
	pickup_vhealth2,
	pickup_varmour2,
	pickup_ss,
	VIPCP1,
	VIPCP2,
	VIPCP3,
	VIPCP4,
	CITYHALL1,
	CITYHALL2,
	CITYHALL3,
	CITYHALL4,
	PoliceCP[2],
	Dropoff1CP,
	Dropoff2CP,
	Dropoff3CP,
	Dropoff4CP,
	Dropoff5CP,
	explosiveStoreCP,
	explosiveStoreCP2,
	adminLounge1,
	dildoCP,
	armyCP[2],
	rooftop[2],
	atms[17],
	dealership[2],
	alog[6][250],
	adminSpawnedVehicles[MAX_ADMIN_SPAWNED_VEHICLES],
	arenaCP,
	glassTimer,
	Rooftopenter1,
	Rooftopexit1,
	Rooftopenter2,
	Rooftopexit2,
	Rooftopenter3,
	Rooftopexit3,
	Rooftopenter4,
	Rooftopexit4,
	Rooftopenter5,
	Rooftopexit5,
	Rooftopenter6,
	Rooftopexit6,
	Rooftopenter7,
	Rooftopexit7
	//vSpawnP[9]
;

// Bank

new
	bankVault,
	bankVault2,
	bankGate,
	bankTimer,
	openBankTimer
;

// DM Event

new
	DMGate
;

stock GetDayName()
{
	new DayName[128];
    switch(gday)
    {
		case 0: format(DayName, sizeof(DayName), "Sunday");
        case 1: format(DayName, sizeof(DayName), "Monday");
        case 2: format(DayName, sizeof(DayName), "Tuesday");
        case 3: format(DayName, sizeof(DayName), "Wednesday");
        case 4: format(DayName, sizeof(DayName), "Thursday");
        case 5: format(DayName, sizeof(DayName), "Friday");
        case 6: format(DayName, sizeof(DayName), "Saturday");
    }
    return DayName;
}

new spoiler[20][0] = {
	{1000},
	{1001},
	{1002},
	{1003},
	{1014},
	{1015},
	{1016},
	{1023},
	{1058},
	{1060},
	{1049},
	{1050},
	{1138},
	{1139},
	{1146},
	{1147},
	{1158},
	{1162},
	{1163},
	{1164}
};

new nitro[3][0] = {
    {1008},
    {1009},
    {1010}
};

new fbumper[23][0] = {
    {1117},
    {1152},
    {1153},
    {1155},
    {1157},
    {1160},
    {1165},
    {1167},
    {1169},
    {1170},
    {1171},
    {1172},
    {1173},
    {1174},
    {1175},
    {1179},
    {1181},
    {1182},
    {1185},
    {1188},
    {1189},
    {1192},
    {1193}
};

new rbumper[22][0] = {
    {1140},
    {1141},
    {1148},
    {1149},
    {1150},
    {1151},
    {1154},
    {1156},
    {1159},
    {1161},
    {1166},
    {1168},
    {1176},
    {1177},
    {1178},
    {1180},
    {1183},
    {1184},
    {1186},
    {1187},
    {1190},
    {1191}
};

new exhaust[28][0] = {
    {1018},
    {1019},
    {1020},
    {1021},
    {1022},
    {1028},
    {1029},
    {1037},
    {1043},
    {1044},
    {1045},
    {1046},
    {1059},
    {1064},
    {1065},
    {1066},
    {1089},
    {1092},
    {1104},
    {1105},
    {1113},
    {1114},
    {1126},
    {1127},
    {1129},
    {1132},
    {1135},
    {1136}
};

new bventr[2][0] = {
    {1142},
    {1144}
};

new bventl[2][0] = {
    {1143},
    {1145}
};

new bscoop[4][0] = {
	{1004},
	{1005},
	{1011},
	{1012}
};

new rscoop[17][0] = {
    {1006},
    {1032},
    {1033},
    {1035},
    {1038},
    {1053},
    {1054},
    {1055},
    {1061},
    {1067},
    {1068},
    {1088},
    {1091},
    {1103},
    {1128},
    {1130},
    {1131}
};

new lskirt[21][0] = {
    {1007},
    {1026},
    {1031},
    {1036},
    {1039},
    {1042},
    {1047},
    {1048},
    {1056},
    {1057},
    {1069},
    {1070},
    {1090},
    {1093},
    {1106},
    {1108},
    {1118},
    {1119},
    {1133},
    {1122},
    {1134}
};

new rskirt[21][0] = {
    {1017},
    {1027},
    {1030},
    {1040},
    {1041},
    {1051},
    {1052},
    {1062},
    {1063},
    {1071},
    {1072},
    {1094},
    {1095},
    {1099},
    {1101},
    {1102},
    {1107},
    {1120},
    {1121},
    {1124},
    {1137}
};

new hydraulics[1][0] = {
    {1087}
};

new base[1][0] = {
    {1086}
};

new rbbars[4][0] = {
    {1109},
    {1110},
    {1123},
    {1125}
};

new fbbars[2][0] = {
    {1115},
    {1116}
};

new wheels[17][0] = {
    {1025},
    {1073},
    {1074},
    {1075},
    {1076},
    {1077},
    {1078},
    {1079},
    {1080},
    {1081},
    {1082},
    {1083},
    {1084},
    {1085},
    {1096},
    {1097},
    {1098}
};

new legalmods[48][22] = {
        {400, 1024,1021,1020,1019,1018,1013,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {401, 1145,1144,1143,1142,1020,1019,1017,1013,1007,1006,1005,1004,1003,1001,0000,0000,0000,0000},
        {404, 1021,1020,1019,1017,1016,1013,1007,1002,1000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {405, 1023,1021,1020,1019,1018,1014,1001,1000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {410, 1024,1023,1021,1020,1019,1017,1013,1007,1003,1001,0000,0000,0000,0000,0000,0000,0000,0000},
        {415, 1023,1019,1018,1017,1007,1003,1001,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {418, 1021,1020,1016,1006,1002,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {420, 1021,1019,1005,1004,1003,1001,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {421, 1023,1021,1020,1019,1018,1016,1014,1000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {422, 1021,1020,1019,1017,1013,1007,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {426, 1021,1019,1006,1005,1004,1003,1001,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {436, 1022,1021,1020,1019,1017,1013,1007,1006,1003,1001,0000,0000,0000,0000,0000,0000,0000,0000},
        {439, 1145,1144,1143,1142,1023,1017,1013,1007,1003,1001,0000,0000,0000,0000,0000,0000,0000,0000},
        {477, 1021,1020,1019,1018,1017,1007,1006,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {478, 1024,1022,1021,1020,1013,1012,1005,1004,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {489, 1024,1020,1019,1018,1016,1013,1006,1005,1004,1002,1000,0000,0000,0000,0000,0000,0000,0000},
        {491, 1145,1144,1143,1142,1023,1021,1020,1019,1018,1017,1014,1007,1003,0000,0000,0000,0000,0000},
        {492, 1016,1006,1005,1004,1000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {496, 1143,1142,1023,1020,1019,1017,1011,1007,1006,1003,1002,1001,0000,0000,0000,0000,0000,0000},
        {500, 1024,1021,1020,1019,1013,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {516, 1021,1020,1019,1018,1017,1016,1015,1007,1004,1002,1000,0000,0000,0000,0000,0000,0000,0000},
        {517, 1145,1144,1143,1142,1023,1020,1019,1018,1017,1016,1007,1003,1002,0000,0000,0000,0000,0000},
        {518, 1145,1144,1143,1142,1023,1020,1018,1017,1013,1007,1006,1005,1003,1001,0000,0000,0000,0000},
        {527, 1021,1020,1018,1017,1015,1014,1007,1001,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {529, 1023,1020,1019,1018,1017,1012,1011,1007,1006,1003,1001,0000,0000,0000,0000,0000,0000,0000},
        {534, 1185,1180,1179,1178,1127,1126,1125,1124,1123,1122,1106,1101,1100,0000,0000,0000,0000,0000},
        {535, 1121,1120,1119,1118,1117,1116,1115,1114,1113,1110,1109,0000,0000,0000,0000,0000,0000,0000},
        {536, 1184,1183,1182,1181,1128,1108,1107,1105,1104,1103,0000,0000,0000,0000,0000,0000,0000,0000},
        {540, 1145,1144,1143,1142,1024,1023,1020,1019,1018,1017,1007,1006,1004,1001,0000,0000,0000,0000},
        {542, 1145,1144,1021,1020,1019,1018,1015,1014,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {546, 1145,1144,1143,1142,1024,1023,1019,1018,1017,1007,1006,1004,1002,1001,0000,0000,0000,0000},
        {547, 1143,1142,1021,1020,1019,1018,1016,1003,1000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {549, 1145,1144,1143,1142,1023,1020,1019,1018,1017,1012,1011,1007,1003,1001,0000,0000,0000,0000},
        {550, 1145,1144,1143,1142,1023,1020,1019,1018,1006,1005,1004,1003,1001,0000,0000,0000,0000,0000},
        {551, 1023,1021,1020,1019,1018,1016,1006,1005,1003,1002,0000,0000,0000,0000,0000,0000,0000,0000},
        {558, 1168,1167,1166,1165,1164,1163,1095,1094,1093,1092,1091,1090,1089,1088,0000,0000,0000,0000},
        {559, 1173,1162,1161,1160,1159,1158,1072,1071,1070,1069,1068,1067,1066,1065,0000,0000,0000,0000},
        {560, 1170,1169,1141,1140,1139,1138,1033,1032,1031,1030,1029,1028,1027,1026,0000,0000,0000,0000},
        {561, 1157,1156,1155,1154,1064,1063,1062,1061,1060,1059,1058,1057,1056,1055,1031,1030,1027,1026},
        {562, 1172,1171,1149,1148,1147,1146,1041,1040,1039,1038,1037,1036,1035,1034,0000,0000,0000,0000},
        {565, 1153,1152,1151,1150,1054,1053,1052,1051,1050,1049,1048,1047,1046,1045,0000,0000,0000,0000},
        {567, 1189,1188,1187,1186,1133,1132,1131,1130,1129,1102,0000,0000,0000,0000,0000,0000,0000,0000},
        {575, 1177,1176,1175,1174,1099,1044,1043,1042,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {576, 1193,1192,1191,1190,1137,1136,1135,1134,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {580, 1023,1020,1018,1017,1007,1006,1001,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {589, 1145,1144,1024,1020,1018,1017,1016,1013,1007,1006,1005,1004,1000,0000,0000,0000,0000,0000},
        {600, 1022,1020,1018,1017,1013,1007,1006,1005,1004,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {603, 1145,1144,1143,1142,1024,1023,1020,1019,1018,1017,1007,1006,1001,0000,0000,0000,0000,0000}
};

new Float:CopSpawns[3][4] =
{
	{2268.0537,2445.0354,3.2734,181.3522},
	{2268.1650,2444.9575,-7.4531,180.5292},
	{2293.4761,2451.6462,10.8203,88.6331}
};

new Float:CIASpawns[2][4] =
{
	{941.1046,1736.1487,8.8516,270.8704},
	{941.1307,1730.2427,8.8516,269.5543}
};

new Float:SecretSpawns[1][4] =
{
	{2496.139892, 2397.819091, 10.820312 ,88.0134}
};

new Float:ArmySpawns[3][4] =
{
	{285.4526,2035.0264,17.6406,178.6992},
	{285.6859,2000.1420,17.6406,178.6993},
	{285.4151,1966.1923,17.6406,177.3832}
};

new Float:CivSpawns[4][4] =
{
	{2325.8777,2337.3208,10.8203,5.6401},
	{2106.3457,2199.4788,10.8203,269.2403},
	{2198.7742,1968.1080,10.8203,91.4318},
	{2124.3691,1454.2067,10.8203,180.0200}
};

new Float:MedicSpawns[2][4] =
{
	{1614.6974,1817.9830,10.8203,0.7182},
	{1599.6218,1818.3469,10.8203,1.1569}
};

// Rope System
new Float:LastZ[MAX_PLAYERS];
new Rope[MAX_PLAYERS];
new IsRappelling[MAX_PLAYERS];
new LandingChecker[MAX_PLAYERS];
new Rappel[MAX_PLAYERS];
new Float:PlayerHealth[MAX_PLAYERS];
// ===============================

stock iswheelmodel(modelid) {

    new wheelmodels[17] = {1025,1073,1074,1075,1076,1077,1078,1079,1080,1081,1082,1083,1084,1085,1096,1097,1098};

    for(new I = 0, b = sizeof(wheelmodels); I != b; ++I) {
        if (modelid == wheelmodels[I])
            return true;

    }

    return false;
}

stock IllegalCarNitroIde(carmodel) {

    new illegalvehs[29] = { 581, 523, 462, 521, 463, 522, 461, 448, 468, 586, 509, 481, 510, 472, 473, 493, 595, 484, 430, 453, 452, 446, 454, 590, 569, 537, 538, 570, 449 };

    for(new I = 0, b = sizeof(illegalvehs); I != b; ++I) {

        if (carmodel == illegalvehs[I])
            return true;

    }

    return false;
}

// assumes player is in a car - make sure it is.
stock illegal_nos_vehicle(PlayerID) {

    new carid = GetPlayerVehicleID(PlayerID);
    new playercarmodel = GetVehicleModel(carid);

    return IllegalCarNitroIde(playercarmodel);

}

stock islegalcarmod(vehicleide, componentid) {

    new modok = false;

    // stereo, hydraulics & nos (1x 2x 3x) are special.
    if ( (iswheelmodel(componentid)) || (componentid == 1086) || (componentid == 1087) || ((componentid >= 1008) && (componentid <= 1010))) {

        new nosblocker = IllegalCarNitroIde(vehicleide);

        if (!nosblocker)
            modok = true;

    } else {

        // check if the specified model CAN use this particular mod.
        for(new I = 0, b = sizeof(legalmods); I != b; ++I) {

            if (legalmods[I][0] == vehicleide) { // first is car IDE

                for(new J = 1; J < 22; J++) { // start with 1
                    if (legalmods[I][J] == componentid)
                        modok = true;
                }

            }

        }

    }

    return modok;
}

#define MAX_INI_ENTRY_TEXT 80

stock DB_Escape(text[])
{
	new
		ret[MAX_INI_ENTRY_TEXT * 2],
		ch,
		i,
		j;
	while ((ch = text[i++]) && j < sizeof (ret))
	{
		if (ch == '\'')
		{
			if (j < sizeof (ret) - 2)
			{
				ret[j++] = '\'';
				ret[j++] = '\'';
			}
		}
		else if (j < sizeof (ret))
		{
			ret[j++] = ch;
		}
		else
		{
			j++;
		}
	}
	ret[sizeof (ret) - 1] = '\0';
	return ret;
}

