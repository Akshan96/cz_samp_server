// This is a comment
// uncomment the line below if you want to write a filterscript
//#define FILTERSCRIPT

#include <a_samp>
#include <zcmd>
#define Admin(%0) if(!IsPlayerAdmin(%0)){ SendClientMessage(playerid, 0xFF0000FF, "You must be admin to use this features."); return 1;}
#define Dialog(%0,%1,%2,%3) ShowPlayerDialog(%0, %1, %2, "X337 Gang System", %3, "Confirm", "Cancel")

#define MAX_ZONE			20

#define DIALOG_CREATE		669
#define DIALOG_ZONENAME		670
new message[750], query[1000];
enum _gangZone
{
	zID,
	bool:zUsed,
	zOwner,
	zName[50],
	bool:zStatus
}
new Gang[MAX_ZONE][_gangZone];

COMMAND:createzone(playerid, params[])
{
	Admin(playerid)
	Dialog(playerid, DIALOG_CREATE, DIALOG_STYLE_LIST, "Create Gang Zone\nDelete Gang Zone\nRename Gang Zone");
	return 1;
}

#if defined FILTERSCRIPT

public OnFilterScriptInit()
{
	print("\n--------------------------------------");
	print(" Blank Filterscript by your name here");
	print("--------------------------------------\n");
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

public OnPlayerConnect(playerid)
{
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
	return 1;
}

public OnPlayerSpawn(playerid)
{
	return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
	return 1;
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
	return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	if(!response)
	{
		return 1;
	}	
	switch(dialogid)
	{
		case DIALOG_CREATE:
		{
			switch(listitem)
			{
				case 0:
				{
					Dialog(playerid, DIALOG_ZONENAME, DIALOG_STYLE_INPUT, "Input zone name below.");
				}
			}
		}
	}
	return 1;
}