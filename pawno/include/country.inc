// Player country lookup by Emmet

#include <a_http>

forward OnLookupComplete(playerid, country[], region[], city[]);

enum e_GeographicData
{
	e_CountryName[32 char],
	e_RegionName[32 char],
	e_CityName[32 char]
};

static 
	g_aGeographicData[MAX_PLAYERS][e_GeographicData];

public OnPlayerConnect(playerid)
{
	static
	    ip[64];

    strpack(g_aGeographicData[playerid][e_CountryName], "Unknown", 32 char);
    strpack(g_aGeographicData[playerid][e_RegionName], "Unknown", 32 char);
    strpack(g_aGeographicData[playerid][e_CityName], "Unknown", 32 char);

	if (strcmp(ip, "127.0.0.1") != 0 && !IsPlayerNPC(playerid))
	{
	    GetPlayerIp(playerid, ip, sizeof(ip));
	
		strins(ip, "www.realip.info/api/p/geoip.php?ip=", 0);
		HTTP(playerid, HTTP_GET, ip, "", "HTTP_OnCountryResponse");
	}
	#if defined CL_OnPlayerConnect
	    return CL_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}

forward HTTP_OnCountryResponse(index, response, data[]);
public HTTP_OnCountryResponse(index, response, data[])
{
	if (!IsPlayerConnected(index) || strlen(data) < 15 || strfind(data, "reserved", true) != -1)
	    return 0;

	new
		pos = -1;

	if ((pos = strfind(data, "\"country_name\":")) != -1)
		strmid(g_aGeographicData[index][e_CountryName], data, pos + 16, strfind(data, "\"", true, pos + 16), 32);
		
	if ((pos = strfind(data, "\"region_name\":")) != -1)
		strmid(g_aGeographicData[index][e_RegionName], data, pos + 15, strfind(data, "\"", true, pos + 15), 32);

	if ((pos = strfind(data, "\"city\":")) != -1)
		strmid(g_aGeographicData[index][e_CityName], data, pos + 8, strfind(data, "\"", true, pos + 8), 32);
		
	if (pos != -1)
	    CallLocalFunction("OnLookupComplete", "dsss", index, g_aGeographicData[index][e_CountryName], g_aGeographicData[index][e_RegionName], g_aGeographicData[index][e_CityName]);

	return 0;
}

stock GetPlayerCountry(playerid, country[], size = sizeof(country)) {
	return strunpack(country, g_aGeographicData[playerid][e_CountryName], size);
}

stock GetPlayerRegionName(playerid, region[], size = sizeof(region)) {
	return strunpack(region, g_aGeographicData[playerid][e_RegionName], size);
}

stock GetPlayerCity(playerid, city[], size = sizeof(city)) {
	return strunpack(city, g_aGeographicData[playerid][e_CityName], size);
}

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect CL_OnPlayerConnect

#if defined CL_OnPlayerConnect
	forward CL_OnPlayerConnect(playerid);
#endif