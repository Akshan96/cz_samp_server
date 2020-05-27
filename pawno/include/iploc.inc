#if !defined _samp_included
	#tryinclude <a_samp>

	#if !defined _samp_included
 		#error "Can't find file "a_samp". Are your includes in the correct directory?"
 	#endif
#endif


#if !defined HTTP
	#tryinclude <a_http>

	#if !defined HTTP
	    #error "Can't find file "a_http". Are your includes in the correct directory?"
	#endif
#endif

#define MAX_COUNTRY_NAME                    (64)
#define MAX_CITY_NAME                      	(64)

#define HTTP_REQUEST_IP 					("api.hostip.info/get_html.php?ip=")

new g_HasORIL;

forward hostip_Response(playerid, response_code, data[]);
forward OnRetrieveIpLocation(playerid, country[]);

public hostip_Response(playerid, response_code, data[])
{

	if( g_HasORIL != -1 )
	{
	    if( response_code == 200 )
	    {
	        new szCountryBuff[ MAX_COUNTRY_NAME ];
	        
	        if( data[0] != '(' )
	        {
		        new
					_itr=9,
					_citr
				;

		        while( data[ _itr ] != EOS )
				{
				    if( _itr == MAX_COUNTRY_NAME -1)
				    {

				        szCountryBuff[ _itr ] = EOS;
				        break;

				    }

				    if( data[ _itr ] == '\n')
					{
					    szCountryBuff[ _itr ] = EOS;
						break;
					}

				    szCountryBuff[ _citr++ ] = data[ _itr++ ];

				}
			}
			else
			{

			    strcat( szCountryBuff, "private country" );

			}

			CallLocalFunction( "OnRetrieveIpLocation", "ds", playerid, szCountryBuff );

	    }
	    else printf("<IPLocator Error> HTTP response code: %d", response_code );

	}
    else printf("<IPLocator Error> iploc included but the function OnRetrieveIpLocation was not found.");
}




////////////////////////////////////////////////////////////////////////////////
// CALLBACK HOOKS //////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#if defined FILTERSCRIPT

	public OnFilterScriptInit()
	{
		print("\n--------------------------------------");
		print(" Iggys Ip Locator Loaded.");
		print("--------------------------------------\n");

		g_HasORIL = funcidx("OnRetrieveIpLocation");

		if(funcidx("iploc_OnFilterScriptInit") != -1)
		{
	      	return CallLocalFunction("iploc_OnFilterScriptInit", "");
		}

		return 1;
	}

	#if defined _ALS_OnFilterScriptInit
		#undef OnFilterScriptInit
	#else
		#define _ALS_OnFilterScriptInit
	#endif
	#define OnFilterScriptInit iploc_OnFilterScriptInit

	forward iploc_OnFilterScriptInit();

#else

    public OnGameModeInit()
	{
		print("\n--------------------------------------");
		print(" Iggys Ip Locator Loaded.");
		print("--------------------------------------\n");

	    g_HasORIL = funcidx("OnRetrieveIpLocation");

		if (funcidx("iploc_OnGameModeInit") != -1)
		{
			return CallLocalFunction("iploc_OnGameModeInit", "");
		}
		return 1;
	}

	#if defined _ALS_OnGameModeInit
	    #undef OnGameModeInit
	#else
	    #define _ALS_OnGameModeInit
	#endif
	#define OnGameModeInit iploc_OnGameModeInit
	forward iploc_OnGameModeInit();

#endif

public OnPlayerConnect(playerid)
{
    if( g_HasORIL != -1 )
	{

		new
		    _szIP[ 16 ],
		    _szTmpStr[ 128 ];

		GetPlayerIp( playerid, _szIP, 16 );

		strcat( _szTmpStr, HTTP_REQUEST_IP );
		strcat( _szTmpStr, _szIP );

	 	HTTP( playerid, HTTP_GET, _szTmpStr, "", "hostip_Response");//request location of ip and send it to hostip_Response
	}

	if(funcidx("iploc_OnPlayerConnect") != -1)
	{
      	return CallLocalFunction("iploc_OnPlayerConnect", "i", playerid) != -1;
	}
  	return 1;

}

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect iploc_OnPlayerConnect

forward iploc_OnPlayerConnect(playerid);

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////