/* 
	Medic Missions
*/

#define MAX_CALLOUTS 9

enum medicEnum
{
	coID,
	coValue,
	coType,
	Float:coXYZ[3],
	coTitle[45]
}

new medicJob[MAX_CALLOUTS][medicEnum] =
{
	/*
	    - coID		    - The unique ID of the callout
		- coValue		- The amount the player will receive for the callout
		- coType		- Broken leg, dildo stuck up bum etc
		- coXYZ			- Location
	*/
	
	// Missions
	{1, 1, 1, {-2039.6962, 1184.7921, 44.8546}, "Calton Heights"},
	{2, 1, 1, {-2129.9260, 1000.2461, 79.5598}, "Calton Heights"},
	{3, 1, 1, {-2213.5293, 728.3522, 48.8199}, "China Town"},
	{4, 1, 1, {-2150.0613, 530.1138, 34.5747}, "King's"},
	{5, 1, 1, {-1945.2450, 505.5741, 34.7337}, "Downtown"},
	{6, 1, 1, {-1974.2712, 284.4948, 34.7320}, "Downtown"},
	{7, 1, 1, {-2235.9531, 159.8308, 34.8784}, "Garcia"},
	{8, 1, 1, {-2285.6838, 33.8063, 34.8898}, "Garcia"},
	{9, 1, 1, {-2097.1689, -48.2363, 34.8770}, "Doherty"}
};

COMMAND:medic(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerClass] == CLASS_MEDIC)
		{
			if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 416)
			{
				if (playerData[playerid][medicStatus] < 1)
				{
					//
					// Assign new mission to player
					new RandomMission = random(MAX_CALLOUTS);
					playerData[playerid][medicCheckpoint] = CreateDynamicRaceCP(1, medicJob[RandomMission][coXYZ][0], medicJob[RandomMission][coXYZ][1], medicJob[RandomMission][coXYZ][2], -2641.6196, 624.5779, 14.4531, 5, -1, -1, playerid, 100.0);
					
					//
					// Assign new variables to player
					playerData[playerid][medicStatus] = 1;
					playerData[playerid][medicMission] = RandomMission;
					
					new missionText[200];
					format(missionText, sizeof(missionText), "{58D3F7}[MEDIC] {FFFFFF}Pickup {FFDC2E}the injured civilian {FFFFFF}from {FFDC2E}%s {FFFFFF}", medicJob[RandomMission][coTitle]);
					SendClientMessage(playerid, COLOR_WHITE, missionText);
					
					//
					// Remove map icon
					RemovePlayerMapIcon(playerid, 69);
					
					//
					// Set map icon
					SetPlayerMapIcon(playerid, 69, medicJob[RandomMission][coXYZ][0], medicJob[RandomMission][coXYZ][1], medicJob[RandomMission][coXYZ][2], 51, 0, MAPICON_GLOBAL);
				}
				else
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You're already on a mission! {FFDC2E}/cancelmedic {FFFFFF}first!");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You must be driving an ambulance to start a mission.");
			}
		}
		else
		{
			//SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This command can only be used by medics.");
		}
	}
	
	return 1;
}

COMMAND:cancelmedic(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(playerData[playerid][playerClass] == CLASS_MEDIC)
		{
			if (playerData[playerid][medicStatus] > 0)
			{
				SendClientMessage(playerid, COLOR_WHITE, "{58D3F7}[MEDIC] {FFFFFF}Mission cancelled.");
				
				playerData[playerid][medicStatus] = -1;		
				playerData[playerid][medicMission] = -1;
				
				RemovePlayerMapIcon(playerid, 69);
				DestroyDynamicRaceCP(playerData[playerid][medicCheckpoint]);
			}
		}
		else
		{
			//SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}This command can only be used by medics.");
		}
	}
	
	return 1;
}

forward medicProgress(playerid);
public medicProgress(playerid)
{
	if (playerData[playerid][medicStatus] > 0)
	{
		if (GetVehicleModel(GetPlayerVehicleID(playerid)) == 416)
		{
			if (playerData[playerid][medicStatus] == 1)
			{
				//
				// Destroy checkpoint
				DestroyDynamicRaceCP(playerData[playerid][medicCheckpoint]);
				
				//
				// Remove map icon
				RemovePlayerMapIcon(playerid, 69);		

				//
				// Return to hospital
				playerData[playerid][medicStatus] = 2;
				
				new missionText[200];
				format(missionText, sizeof(missionText), "{58D3F7}[MEDIC] {FFFFFF}Take {FFDC2E}the injured civilian {FFFFFF}back to the hospital.");
				SendClientMessage(playerid, COLOR_WHITE, missionText);
				
				//
				// Set map icon
				SetPlayerMapIcon(playerid, 69, -2641.6196, 624.5779, 14.4531, 51, 0, MAPICON_GLOBAL);
				
				//
				// Set checkpoint
				playerData[playerid][medicCheckpoint] = CreateDynamicRaceCP(1, -2641.6196, 624.5779, 14.4531, -2641.6196, 624.5779, 14.4531, 5, -1, -1, playerid, 100.0);
			}
			
			else if (playerData[playerid][medicStatus] == 2)
			{
				new moneyToGive = randomEx(2000, 5000);
								
				new medicComplete[380];
				format(medicComplete, sizeof(medicComplete), "{58D3F7}[MEDIC] {FFFFFF}%s(%i) delivered {FFDC2E}an injured civilian {FFFFFF}to {FFDC2E}San Fierro Hospital {FFFFFF}and earnt {FFDC2E}$%s", playerData[playerid][playerNamee], playerid, FormatNumber(moneyToGive));
				SendClientMessageToAll(COLOR_WHITE, medicComplete);
				
				playerData[playerid][medicMission] = 0;
				
				//
				// Destroy checkpoint
				DestroyDynamicRaceCP(playerData[playerid][medicCheckpoint]);
				
				//
				// Remove map icon
				RemovePlayerMapIcon(playerid, 69);		

				//
				// Return to hospital
				playerData[playerid][medicStatus] = 0;
				
				playerGiveMoney(playerid, moneyToGive);
				playerGiveXP(playerid, 10);
				
				playerData[playerid][playerScore] = playerData[playerid][playerScore] + 1;
				SetPlayerScore(playerid, playerData[playerid][playerScore]);			
			}
		}
	}	
}
