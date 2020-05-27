// Vehicle Name Text v1.1.1
//      by biltong
// You may edit this script as you like, so long as you credit myself for the original.
#include <a_samp>
#define FILTERSCRIPT
#if defined FILTERSCRIPT
#define GAMETEXT_COLOR 5 //Change this to change the color of the text. 0 = yellow(default), 1 = blue, 2 = green, 3 = red, 4 = purple, 5 = white, 6 = black.

new VehicleNames[212][] = {
{"Landstalker"},{"Bravura"},{"Buffalo"},{"Linerunner"},{"Perrenial"},{"Sentinel"},{"Dumper"},
{"Firetruck"},{"Trashmaster"},{"Stretch"},{"Manana"},{"Infernus"},{"Voodoo"},{"Pony"},{"Mule"},
{"Cheetah"},{"Ambulance"},{"Leviathan"},{"Moonbeam"},{"Esperanto"},{"Taxi"},{"Washington"},
{"Bobcat"},{"Mr Whoopee"},{"BF Injection"},{"Hunter"},{"Premier"},{"Enforcer"},{"Securicar"},
{"Banshee"},{"Predator"},{"Bus"},{"Rhino"},{"Barracks"},{"Hotknife"},{"Trailer 1"},{"Previon"},
{"Coach"},{"Cabbie"},{"Stallion"},{"Rumpo"},{"RC Bandit"},{"Romero"},{"Packer"},{"Monster"},
{"Admiral"},{"Squalo"},{"Seasparrow"},{"Pizzaboy"},{"Tram"},{"Trailer 2"},{"Turismo"},
{"Speeder"},{"Reefer"},{"Tropic"},{"Flatbed"},{"Yankee"},{"Caddy"},{"Solair"},{"Berkley's RC Van"},
{"Skimmer"},{"PCJ-600"},{"Faggio"},{"Freeway"},{"RC Baron"},{"RC Raider"},{"Glendale"},{"Oceanic"},
{"Sanchez"},{"Sparrow"},{"Patriot"},{"Quad"},{"Coastguard"},{"Dinghy"},{"Hermes"},{"Sabre"},
{"Rustler"},{"ZR-350"},{"Walton"},{"Regina"},{"Comet"},{"BMX"},{"Burrito"},{"Camper"},{"Marquis"},
{"Baggage"},{"Dozer"},{"Maverick"},{"News Chopper"},{"Rancher"},{"FBI Rancher"},{"Virgo"},{"Greenwood"},
{"Jetmax"},{"Hotring"},{"Sandking"},{"Blista Compact"},{"Police Maverick"},{"Boxville"},{"Benson"},
{"Mesa"},{"RC Goblin"},{"Hotring Racer A"},{"Hotring Racer B"},{"Bloodring Banger"},{"Rancher"},
{"Super GT"},{"Elegant"},{"Journey"},{"Bike"},{"Mountain Bike"},{"Beagle"},{"Cropdust"},{"Stunt"},
{"Tanker"}, {"Roadtrain"},{"Nebula"},{"Majestic"},{"Buccaneer"},{"Shamal"},{"Hydra"},{"FCR-900"},
{"NRG-500"},{"HPV1000"},{"Cement Truck"},{"Tow Truck"},{"Fortune"},{"Cadrona"},{"FBI Truck"},
{"Willard"},{"Forklift"},{"Tractor"},{"Combine"},{"Feltzer"},{"Remington"},{"Slamvan"},
{"Blade"},{"Freight"},{"Streak"},{"Vortex"},{"Vincent"},{"Bullet"},{"Clover"},{"Sadler"},
{"Firetruck LA"},{"Hustler"},{"Intruder"},{"Primo"},{"Cargobob"},{"Tampa"},{"Sunrise"},{"Merit"},
{"Utility"},{"Nevada"},{"Yosemite"},{"Windsor"},{"Monster A"},{"Monster B"},{"Uranus"},{"Jester"},
{"Sultan"},{"Stratum"},{"Elegy"},{"Raindance"},{"RC Tiger"},{"Flash"},{"Tahoma"},{"Savanna"},
{"Bandito"},{"Freight Flat"},{"Streak Carriage"},{"Kart"},{"Mower"},{"Duneride"},{"Sweeper"},
{"Broadway"},{"Tornado"},{"AT-400"},{"DFT-30"},{"Huntley"},{"Stafford"},{"BF-400"},{"Newsvan"},
{"Tug"},{"Trailer 3"},{"Emperor"},{"Wayfarer"},{"Euros"},{"Hotdog"},{"Club"},{"Freight Carriage"},
{"Trailer 3"},{"Andromada"},{"Dodo"},{"RC Cam"},{"Launch"},{"Police Car (LSPD)"},{"Police Car (SFPD)"},
{"Police Car (LVPD)"},{"Police Ranger"},{"Picador"},{"S.W.A.T. Van"},{"Alpha"},{"Phoenix"},{"Glendale"},
{"Sadler"},{"Luggage Trailer A"},{"Luggage Trailer B"},{"Stair Trailer"},{"Boxville"},{"Farm Plow"},
{"Utility Trailer"}
};

new VehicleModel[MAX_PLAYERS];
new CFCTimer;
forward CheckForChange(playerid);
forward ShowGameTextForPlayer(playerid);

public OnFilterScriptInit()
{
        print("\n--------------------------------------");
        print(" Loaded Vehicle Names v1.1");
        print("         by biltong");
        print("--------------------------------------\n");
        return 1;
}

public OnFilterScriptExit()
{
        return 1;
}

public OnPlayerStateChange(playerid, newstate, oldstate) //checks when the player gets in a vehicle
{
        if(newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER)
        {
            VehicleModel[playerid] = GetVehicleModel(GetPlayerVehicleID(playerid));
            ShowGameTextForPlayer(playerid);
            return 1;
        }
        if(newstate != PLAYER_STATE_DRIVER && (oldstate == PLAYER_STATE_DRIVER || oldstate == PLAYER_STATE_PASSENGER)) KillTimer(CFCTimer); //kills timer that checks for left vehicle if player exits vehicle
        return 1;
}
public CheckForChange(playerid) //Checks if the player has changed vehicles.
{
        if(GetVehicleModel(GetPlayerVehicleID(playerid)) != VehicleModel[playerid]) //makes sure the new vehicle isn't the same as old vehicle
        {
            VehicleModel[playerid] = GetVehicleModel(GetPlayerVehicleID(playerid));
        	ShowGameTextForPlayer(playerid);
        }
        return 1;
}
public ShowGameTextForPlayer(playerid) //optimised code here :D
{
        new string[32];
        switch(GAMETEXT_COLOR) //sets the text's color
    {
    		case 0: format(string,sizeof(string),"%s",VehicleNames[VehicleModel[playerid]-400]); //yellow
            case 1: format(string,sizeof(string),"~b~%s",VehicleNames[VehicleModel[playerid]-400]); //blue
            case 2: format(string,sizeof(string),"~g~%s",VehicleNames[VehicleModel[playerid]-400]); //green
            case 3: format(string,sizeof(string),"~r~%s",VehicleNames[VehicleModel[playerid]-400]); //red
            case 4: format(string,sizeof(string),"~p~%s",VehicleNames[VehicleModel[playerid]-400]); //purple
            case 5: format(string,sizeof(string),"~w~%s",VehicleNames[VehicleModel[playerid]-400]); //white
            case 6: format(string,sizeof(string),"%~|~s",VehicleNames[VehicleModel[playerid]-400]); //black
        }
        GameTextForPlayer(playerid,string,2000,1); //shows the text
        CFCTimer = SetTimerEx("CheckForChange",1000,true,"i",playerid); //starts timer to check if player has changed vehicles
        return 1;
}
#endif
