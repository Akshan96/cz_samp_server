//Maded by KINGINA
//Dont' remove credits please or copy my FS

//-------------------START--------------------------
#define FILTERSCRIPT
#define TEST_MENU_ITEMS 6
#include <a_samp>
#include <streamer>
#if defined FILTERSCRIPT
new SF_CP, LV_CP;

public OnFilterScriptInit()
{
	print("\n--------------------------------------");
	print(" Airport Teleports By KINGINA loaded!!!");
	print("--------------------------------------\n");
	InitTestMenu();
	return 1;
}

public OnFilterScriptExit()
{
	return 1;
}

#else

main()
{
	print("\n----------------------------------");
	print(" Blank Gamemode by your name here");
	print("----------------------------------\n");
}

#endif


new Menu:teleport;


InitTestMenu()
{
	teleport = CreateMenu("Destinations", 1, 200.0, 150.0, 200.0, 200.0);

	//AddMenuItem(teleport, 0, "LS - Los Santos");
	//AddMenuItem(teleport, 0, "LS2 - Los Santos 2nd port");
	AddMenuItem(teleport, 0, "SF - San Fierro");
	AddMenuItem(teleport, 0, "LV - Las Venturas");
	//AddMenuItem(teleport, 0, "VM - Verdant Meadows");
	}


public OnPlayerSelectedMenuRow(playerid, row)
{
    new Menu:PlayerMenu = GetPlayerMenu(playerid);

	if(PlayerMenu == teleport) {
	{
		//if (GetPlayerWantedLevel(playerid) < 1)
			{
		    switch(row)
		    {
		        case 0: //SF
		        {
		            SetPlayerPos(playerid, -1427.6036,-286.0584,14.1484);
		            SetPlayerInterior(playerid, 0);
		            SendClientMessage(playerid, 0xFFFFFF00, "Welcome to San Fierro");
		            GivePlayerMoney(playerid, -1000);
		        }
   		     	case 1: //Lv
		        {
		            SetPlayerPos(playerid, 1683.7654,1447.5769,10.7712);
		            SetPlayerInterior(playerid, 0);
		            SendClientMessage(playerid, 0xFFFFFF00, "Welcome to Las Venturas");
		            GivePlayerMoney(playerid, -1000);
		        }
			}
 			}
		}
	}
}

public OnGameModeInit()
{
//SF
	SF_CP = CreateDynamicCP(-1422.4640,-289.6980,13.8041,1.5);
	Create3DTextLabel("{ff0000}[AIRPORT]", 0x008080FF,-1422.4640,-289.6980,14.1041,18.0, 0);
//SF
//LV
	LV_CP = CreateDynamicCP(1673.1757,1447.8678,10.7862,1.5);
	Create3DTextLabel("{ff0000}[AIRPORT]", 0x008080FF,1673.1757,1447.8678,11.0862,18.0, 0);
//LV
	return 1;
}

public OnGameModeExit()
{
	return 1;
}

public OnPlayerEnterDynamicCP(playerid, checkpointid)
{
	if(checkpointid == SF_CP || checkpointid == LV_CP)
	    ShowMenuForPlayer(teleport, playerid);
}
//                                                                                                                                                                                                                                                                                  !!!!KINGINA MADED!!!! :)
//-------------------END--------------------------
