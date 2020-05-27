COMMAND:lv(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		new 
			dialogList[256], 
			DBResult:locatingResult, 
			locatingQuery[128], 
			resultCount,
			bool:firstOne
		;
		
		format(locatingQuery, sizeof(locatingQuery), "SELECT * FROM `vehicle_data` WHERE `vehicle_owner` = '%s'", playerData[playerid][playerNamee]);
		locatingResult = db_query(DB: VEHICLEDB, locatingQuery);
		resultCount = db_num_rows(locatingResult);
		
		if(resultCount > 0)
		{				
			do
			{
				new vehicleModel, temporaryString[24];
				
				db_get_field_assoc(locatingResult, "vehicle_model", temporaryString, 3);
				vehicleModel = strval(temporaryString);
				
				if(firstOne == true)
				{
					format(dialogList, sizeof(dialogList), "%s", dialogList, vehicleNames[vehicleModel - 400]);
					firstOne = false;
				}
				else
				{
					format(dialogList, sizeof(dialogList), "%s\n%s", dialogList, vehicleNames[vehicleModel - 400]);
				}
				
			} while(db_next_row(locatingResult));
			
			ShowPlayerDialog(playerid, DIALOG_VEHICLEMENU, DIALOG_STYLE_LIST, "Vehicle Locating Menu", dialogList, "Select", "Cancel");
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "you got no cars mate");
		}
  
		db_free_result(locatingResult);
	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "fuckoff hacker nig fuk");
	}
	
	return 1;
}