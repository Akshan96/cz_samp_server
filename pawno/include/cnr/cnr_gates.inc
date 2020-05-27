#define MAX_GATES 200

/*
	States
 */

#define GATE_STATE_CLOSED	 0
#define GATE_STATE_OPEN 	 1

enum gInfo
{
    gate_id,
    gate_title[128],
	gate_password[128],
    Float:gateX,
    Float:gateY,
    Float:gateZ,
	Float:gateA,
	gateLabel[128],
	gate_object,
	gate_status,
	gate_created
};

new
	xGates,
	DB:GATESDB,
	Gates[MAX_GATES][gInfo]
;

forward load_gates();
public load_gates()
{
	new DBResult:qresult, count = 0, value[328];
	if(!db_query(DB: GATESDB, "SELECT * FROM `gates`"))
	{
		print("GATES SYSTEM :: No gates were found in \"Gates.db\" :: 0 Loaded");
	}
	else
	{
		qresult = db_query(DB: GATESDB, "SELECT * FROM `gates`");
		count = db_num_rows(qresult);
		for(new i = 0; i < count; i++)
		{
			if(count <= MAX_GATES)
			{
				// Fetch data
				db_get_field_assoc(qresult, "gate_id", value, 5); // Gate ID
				Gates[i][gate_id] = strval(value);

				db_get_field_assoc(qresult, "gate_title", value, 48); // Gate Title
				format(Gates[i][gate_title], 48, value);

				db_get_field_assoc(qresult, "gate_password", value, 48); // Gate Password
				format(Gates[i][gate_password], 48, value);

				db_get_field_assoc(qresult, "gate_x", value, 20); // Gate X Position
				Gates[i][gateX] = floatstr(value);

				db_get_field_assoc(qresult, "gate_y", value, 20); // Gate Y Position
				Gates[i][gateY] = floatstr(value);

				db_get_field_assoc(qresult, "gate_z", value, 20); // Gate Z Position
				Gates[i][gateZ] = floatstr(value);

				db_get_field_assoc(qresult, "gate_a", value, 20); // Gate Z Position
				Gates[i][gateA] = floatstr(value);

				Gates[i][gate_object] = CreateDynamicObject(980, Gates[i][gateX], Gates[i][gateY], Gates[i][gateZ] + 1.5, 0, 0, Gates[i][gateA]);
				Gates[i][gate_created] = true;
				Gates[i][gate_status] = GATE_STATE_CLOSED;

				new gateText[200];
				format(gateText, sizeof(gateText), "Test Gate");
				//Gates[i][gateLabel] = SetObjectMaterialText(Gates[i][gate_object], gateText, 0, OBJECT_MATERIAL_SIZE_256x128, "Arial", 28, 0, 0xFFFF8200, 0xFF000000, OBJECT_MATERIAL_TEXT_ALIGN_CENTER);

				// ++ xGates
				xGates++;

				// Continue loading houses
				db_next_row(qresult);
			}
		}

		db_free_result(qresult);
	}
}

forward reloadGates();
public reloadGates()
{
	for(new i = 0; i < MAX_GATES; i++)
	{
		DestroyDynamicObject(Gates[i][gate_object]);
		//Delete3DTextLabel(Gates[i][gateLabel]);
	}

	load_gates();
}

COMMAND:gopen(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		new
			password[128],
			count = 0
		;

		if(sscanf(params, "s[128]", password))
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"gopen <password>\"");
		}
		else
		{
			for(new i = 0; i < MAX_GATES; i++)
			{
				if(Gates[i][gate_created])
				{
					if(IsPlayerInRangeOfPoint(playerid, 7.0, Gates[i][gateX], Gates[i][gateY], Gates[i][gateZ]))
					{
						count++;

						if(!strcmp(Gates[i][gate_password], password, true))
						{
							if(Gates[i][gate_status] == GATE_STATE_CLOSED)
							{
								MoveDynamicObject(Gates[i][gate_object], Gates[i][gateX], Gates[i][gateY], Gates[i][gateZ] - 10.0, 7.0 );
								Gates[i][gate_status] = GATE_STATE_OPEN;
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}The gate must be closed before you can open it.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Incorrect password.");
						}

						break;
					}
				}
			}

			if (count == 0)
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You are not in range of a gate.");
			}
		}
	}

	return 1;
}

COMMAND:gclose(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		new
			password[128],
			count = 0
		;

		if(sscanf(params, "s[128]", password))
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"gclose <password>\"");
		}
		else
		{
			for(new i = 0; i < MAX_GATES; i++)
			{
				if(Gates[i][gate_created])
				{
					if(IsPlayerInRangeOfPoint(playerid, 7.0, Gates[i][gateX], Gates[i][gateY], Gates[i][gateZ]))
					{
						count++;

						if(!strcmp(Gates[i][gate_password], password, true))
						{
							if(Gates[i][gate_status] == GATE_STATE_OPEN)
							{
								MoveDynamicObject(Gates[i][gate_object], Gates[i][gateX], Gates[i][gateY], Gates[i][gateZ] + 1.5, 9.0 );
								Gates[i][gate_status] = GATE_STATE_CLOSED;
							}
							else
							{
								SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}The gate must be open before you can close it.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Incorrect password.");
						}

						break;
					}
				}
			}

			if (count == 0)
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You are not in range of a gate.");
			}
		}
	}

	return 1;
}

COMMAND:ginfo(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		new
			count = 0
		;

		if(IsPlayerAdmin(playerid))
		{
			for(new i = 0; i < MAX_GATES; i++)
			{
				if(Gates[i][gate_created])
				{
					if(IsPlayerInRangeOfPoint(playerid, 5.0, Gates[i][gateX], Gates[i][gateY], Gates[i][gateZ]))
					{
						count++;

						new gateInfo[200];
						format(gateInfo, sizeof(gateInfo), "{B7B7B7}[GATE] {FFFFFF}Gate ID: %i - Gate Title: %s - Gate Password: %s", Gates[i][gate_id], Gates[i][gate_title], Gates[i][gate_password]);
						SendClientMessage(playerid, COLOR_WHITE, gateInfo);

						break;
					}
				}
			}

			if (count == 0)
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You are not in range of a gate.");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not have permission to use that command.");
		}
	}

	return 1;
}

COMMAND:gatedelete(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(IsPlayerAdmin(playerid))
		{
			new
				gateid,
				gateQuery[200],
				deleteQuery[200]
			;

			if(sscanf(params, "i", gateid))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"gatedelete <gate id>\"");
			}
			else
			{
				format(gateQuery, sizeof(gateQuery), "SELECT * FROM `gates` WHERE `gate_id` = '%i' LIMIT 1", gateid);

				new DBResult:qresult, count = 0;
				qresult = db_query(DB: GATESDB, gateQuery);
				count = db_num_rows(qresult);

				if (count == 0)
				{
					SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}That gate ID doesn't exist.");
				}
				else
				{
					// Find the unique ID for house info
					new dbID, value[48];
					db_get_field_assoc(qresult, "gate_id", value, 48); // Gate UID
					dbID = strval(value);

					for(new i = 0; i < MAX_GATES; i++)
					{
						if(Gates[i][gate_id] == dbID)
						{
							format(deleteQuery, sizeof(deleteQuery), "DELETE FROM `gates` WHERE `gate_id` = '%i'", gateid);
							db_query(DB: GATESDB, deleteQuery);

							reloadGates();

							SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Gate deleted.");

							break;
						}
					}
				}
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not have permission to use that command.");
		}
	}

	return 1;
}

COMMAND:reloadgates(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(IsPlayerAdmin(playerid))
		{
			reloadGates();

			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Gates reloaded.");
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not have permission to use that command.");
		}
	}

	return 1;
}

COMMAND:gatecreate(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if(IsPlayerAdmin(playerid))
		{
			new
				query[400],
				Float:x,
				Float:y,
				Float:z,
				Float:a,
				password[128],
				title[128]
			;

			GetPlayerPos(playerid, x, y, z);
			GetPlayerFacingAngle(playerid, a);

			if(sscanf(params, "s[128]s[128]", title, password))
			{
				SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}Usage: \"gatecreate <title> <password>\"");
			}
			else
			{
				format(query, sizeof(query), "INSERT INTO `gates` (gate_title, gate_x, gate_y, gate_z, gate_a, gate_password) VALUES ('%s', '%f', '%f', '%f', '%f', '%s')", title, x, y, z, a, password);
				db_query(DB: GATESDB, query);

				SetPlayerPos(playerid, x + 1, y, z);

				reloadGates();
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You do not have permission to use that command.");
		}
	}

	return 1;
}
