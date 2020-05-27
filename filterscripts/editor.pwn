#include <a_samp>
#include <streamer>

#define DEF_MAX_OBJECTS 5000

#define DEF_COL_WHITE 	0xFFFFFFFF
#define DEF_COL_RED 	0xAE0000FF


forward FUNCTION_LoadObjects();

new DB:EDITOR_DATABASE;

enum OBJECT_INFO
{
	OBJ_ID,
	OBJ_DB_ID,
	OBJ_MODEL,
	Float:OBJ_X,
	Float:OBJ_Y,
	Float:OBJ_Z,
	Float:OBJ_RX,
	Float:OBJ_RY,
	Float:OBJ_RZ,
	OBJ_VW,
	OBJ_INTERIOR,
	Float:OBJ_STREAM_DISTANCE,
};

new EDITOR_OBJECT[DEF_MAX_OBJECTS][OBJECT_INFO];

new EDIT_OBJECT_ID[MAX_PLAYERS];

stock Numbers(const string[])
{
	for (new i = 0, z = strlen(string); i < z; i++)
	{
		if (string[i] > '9' || string[i] < '0') return 0;
	}
	return 1;
}

public OnFilterScriptInit()
{
	print("\n--------------------------------------");
	print("IG-Object Editor By Finnick.");
	print("--------------------------------------\n");
	EDITOR_DATABASE = db_open("objects.db");
	FUNCTION_LoadObjects();
	return 1;
}

public OnFilterScriptExit()
{
	return 1;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
    if (strcmp("/editobject", cmdtext, true, 12) == 0)
	{
	    if(!IsPlayerAdmin(playerid)) return SendClientMessage(playerid,DEF_COL_RED,"You are not allowed to use this function");
	    ShowPlayerDialog(playerid,10001,DIALOG_STYLE_LIST,"{A80000}Edit Object","Position\nVirtual World\nInterior ID\nStream Distance\nDelete Object","Next","Close");
	    SendClientMessage(playerid,DEF_COL_WHITE,"You are not editing the last object you made.");
		return 1;
	}
	if (strcmp("/selectobject", cmdtext, true, 12) == 0)
	{
	    if(!IsPlayerAdmin(playerid)) return SendClientMessage(playerid,DEF_COL_RED,"You are not allowed to use this function");
	    SelectObject(playerid);
	    SendClientMessage(playerid,DEF_COL_WHITE,"Select a object that you like to edit. You only can edit objects that you created with this filterscript.");
		return 1;
	}
	if (strcmp("/createobject", cmdtext, true, 12) == 0)
	{
	    if(!IsPlayerAdmin(playerid)) return SendClientMessage(playerid,DEF_COL_RED,"You are not allowed to use this function");
	    ShowPlayerDialog(playerid,10000,DIALOG_STYLE_INPUT,"{A80000}Insert Object ID","Insert the object ID that you wan't to create.","Create","Close");
		return 1;
	}
	return 0;
}
public OnPlayerEditDynamicObject(playerid, objectid, response, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
    EDITOR_OBJECT[objectid][OBJ_X] = x;
    EDITOR_OBJECT[objectid][OBJ_Y] = y;
    EDITOR_OBJECT[objectid][OBJ_Z] = z;
    EDITOR_OBJECT[objectid][OBJ_RX] = rx;
    EDITOR_OBJECT[objectid][OBJ_RY] = ry;
    EDITOR_OBJECT[objectid][OBJ_RZ] = rz;
    SetDynamicObjectPos(objectid,x,y,z);
	SetDynamicObjectRot(objectid,rx,ry,rz);
	new EDITOR_QUERY[256];
	format(EDITOR_QUERY, sizeof(EDITOR_QUERY), "UPDATE `OBJECTS` SET `X`='%f', `Y`='%f', `Z`='%f', `RX`='%f', `RY`='%f', `RZ`='%f' WHERE `ID`=%d",
	EDITOR_OBJECT[objectid][OBJ_X],
	EDITOR_OBJECT[objectid][OBJ_Y],
	EDITOR_OBJECT[objectid][OBJ_Z],
	EDITOR_OBJECT[objectid][OBJ_RX],
	EDITOR_OBJECT[objectid][OBJ_RY],
	EDITOR_OBJECT[objectid][OBJ_RZ],
	EDITOR_OBJECT[objectid][OBJ_DB_ID]);
	db_free_result(db_query(EDITOR_DATABASE, EDITOR_QUERY));
	return 1;
}
public OnPlayerSelectDynamicObject(playerid, objectid, modelid, Float:x, Float:y, Float:z)
{
	if(EDITOR_OBJECT[objectid][OBJ_MODEL] != 0)
	{
		EDIT_OBJECT_ID[playerid] = objectid;
	    ShowPlayerDialog(playerid,10001,DIALOG_STYLE_LIST,"{A80000}Edit Object","Position\nVirtual World\nInterior ID\nStream Distance\nDelete Object","Next","Close");
    } else return SendClientMessage(playerid,DEF_COL_RED,"It seems you didn't selected a object that belows to this filterscript");
    return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == 10002 && response)
	{
	    if(!Numbers(inputtext) && strval(inputtext) != -1) return SendClientMessage(playerid,DEF_COL_RED,"You only can use numbers!"),ShowPlayerDialog(playerid,10001,DIALOG_STYLE_LIST,"{A80000}Edit Object","Position\nVirtual World\nInterior ID\nStream Distance\nDelete Object","Next","Close");
		new id = EDIT_OBJECT_ID[playerid];
		new EDITOR_QUERY[256];
		format(EDITOR_QUERY, sizeof(EDITOR_QUERY), "UPDATE `OBJECTS` SET `VW`=%d WHERE `ID`=%d",
		strval(inputtext),
		EDITOR_OBJECT[id][OBJ_DB_ID]);
		db_free_result(db_query(EDITOR_DATABASE, EDITOR_QUERY));
		SendClientMessage(playerid,DEF_COL_WHITE,"You successful changed to virtualworld of this object.");
		return ShowPlayerDialog(playerid,10001,DIALOG_STYLE_LIST,"{A80000}Edit Object","Position\nVirtual World\nInterior ID\nStream Distance\nDelete Object","Next","Close");
	}
    if(dialogid == 10003 && response)
	{
 		if(!Numbers(inputtext) && strval(inputtext) != -1) return SendClientMessage(playerid,DEF_COL_RED,"You only can use numbers!"),ShowPlayerDialog(playerid,10001,DIALOG_STYLE_LIST,"{A80000}Edit Object","Position\nVirtual World\nInterior ID\nStream Distance\nDelete Object","Next","Close");
		new id = EDIT_OBJECT_ID[playerid];
		new EDITOR_QUERY[256];
		format(EDITOR_QUERY, sizeof(EDITOR_QUERY), "UPDATE `OBJECTS` SET `INT`=%d WHERE `ID`=%d",
		strval(inputtext),
		EDITOR_OBJECT[id][OBJ_DB_ID]);
		db_free_result(db_query(EDITOR_DATABASE, EDITOR_QUERY));
	 	SendClientMessage(playerid,DEF_COL_WHITE,"You successful changed to interior of this object.");
	 	return ShowPlayerDialog(playerid,10001,DIALOG_STYLE_LIST,"{A80000}Edit Object","Position\nVirtual World\nInterior ID\nStream Distance\nDelete Object","Next","Close");
	}
    if(dialogid == 10004 && response)
	{
 		if(!Numbers(inputtext) && strval(inputtext) != -1) return SendClientMessage(playerid,DEF_COL_RED,"You only can use numbers!"),ShowPlayerDialog(playerid,10001,DIALOG_STYLE_LIST,"{A80000}Edit Object","Position\nVirtual World\nInterior ID\nStream Distance\nDelete Object","Next","Close");
		new id = EDIT_OBJECT_ID[playerid];
		new EDITOR_QUERY[256];
		format(EDITOR_QUERY, sizeof(EDITOR_QUERY), "UPDATE `OBJECTS` SET `DISTANCE`=%d WHERE `ID`=%d",
		strval(inputtext),
		EDITOR_OBJECT[id][OBJ_DB_ID]);
		db_free_result(db_query(EDITOR_DATABASE, EDITOR_QUERY));
		SendClientMessage(playerid,DEF_COL_WHITE,"You successful changed to distance of this object.");
		return ShowPlayerDialog(playerid,10001,DIALOG_STYLE_LIST,"{A80000}Edit Object","Position\nVirtual World\nInterior ID\nStream Distance\nDelete Object","Next","Close");
	}
    if(dialogid == 10001 && response)
	{
	    if(listitem == 0)
	    {
	    	EditDynamicObject(playerid, EDIT_OBJECT_ID[playerid]);
	    	return SendClientMessage(playerid,DEF_COL_WHITE,"Usage ESC or the save icon to save the position.");
	    }
	    if(listitem == 1)
	    {
	    	ShowPlayerDialog(playerid,10002,DIALOG_STYLE_INPUT,"{A80000}Virtual World","Insert the virtualworld you wan't to only stream this object in.\nUsage -1 to show it in all virtualworlds.","Save","Close");
	    }
	    if(listitem == 2)
	    {
	    	ShowPlayerDialog(playerid,10003,DIALOG_STYLE_INPUT,"{A80000}Virtual World","Insert the interior you wan't to only stream this object in.\nUsage -1 to show it in all interior\nUsage /interior to see your currently interior.","Save","Close");
	    }
	    if(listitem == 3)
	    {
	    	ShowPlayerDialog(playerid,10004,DIALOG_STYLE_INPUT,"{A80000}Virtual World","Insert the stream distance of this object. Default is 100.","Save","Close");
	    }
	    if(listitem == 4)
	    {
	        new EDITOR_QUERY[256];
			format(EDITOR_QUERY, sizeof(EDITOR_QUERY), "DELETE FROM `OBJECTS` WHERE `ID`=%d",EDITOR_OBJECT[EDIT_OBJECT_ID[playerid]][OBJ_DB_ID]);
			db_free_result(db_query(EDITOR_DATABASE, EDITOR_QUERY));
			DestroyDynamicObject(EDIT_OBJECT_ID[playerid]);
			return SendClientMessage(playerid,DEF_COL_WHITE,"You succesful deleted this object.");
	    }
	}
	if(dialogid == 10000 && response)
	{
	    if(!Numbers(inputtext)) return SendClientMessage(playerid,DEF_COL_RED,"You only can use numbers!"),ShowPlayerDialog(playerid,10000,DIALOG_STYLE_INPUT,"{A80000}Insert Object ID","Insert the object ID that you wan't to create.","Create","Close");
	    new Float:editor[3],id;
	    GetPlayerPos(playerid,editor[0],editor[1],editor[2]);
	    id = CreateDynamicObject(strval(inputtext), editor[0]+1, editor[1]+1, editor[2], 0.0,0.0,0.0, -1, -1, -1, 100.0);

		if(id > DEF_MAX_OBJECTS) return SendClientMessageToAll(DEF_COL_WHITE,"Error while creating object, it seems you are trying to create more objects then the max amount of objects.");
	    
     	EDITOR_OBJECT[id][OBJ_MODEL] = strval(inputtext);
        EDITOR_OBJECT[id][OBJ_X] = editor[0]+1;
        EDITOR_OBJECT[id][OBJ_Y] = editor[1]+1;
        EDITOR_OBJECT[id][OBJ_Z] = editor[2];
        EDITOR_OBJECT[id][OBJ_RX] = 0.0;
        EDITOR_OBJECT[id][OBJ_RY] = 0.0;
        EDITOR_OBJECT[id][OBJ_RZ] = 0.0;
        EDITOR_OBJECT[id][OBJ_VW] = -1;
        EDITOR_OBJECT[id][OBJ_INTERIOR] = -1;
        EDITOR_OBJECT[id][OBJ_STREAM_DISTANCE] = 100.0;
        EDIT_OBJECT_ID[playerid] = id;
        EditDynamicObject(playerid, id);
        
        new EDITOR_QUERY[256];
        format(EDITOR_QUERY, sizeof(EDITOR_QUERY), "INSERT INTO `OBJECTS` (`MODEL`, `X`, `Y`, `Z`, `INT`) VALUES (%d,'%f','%f','%f',%d)",
		EDITOR_OBJECT[id][OBJ_MODEL],
		EDITOR_OBJECT[id][OBJ_X],
		EDITOR_OBJECT[id][OBJ_Y],
		EDITOR_OBJECT[id][OBJ_Z],
		id+1000);
		db_free_result(db_query(EDITOR_DATABASE, EDITOR_QUERY));
	 	new DBResult:EDITOR_RESULT;
        format(EDITOR_QUERY,sizeof(EDITOR_QUERY),"SELECT `ID` FROM `OBJECTS` WHERE `INT`=%d",id+1000);
        EDITOR_RESULT = db_query(EDITOR_DATABASE,EDITOR_QUERY);
        if(db_num_rows(EDITOR_RESULT) == 1)
        {
            new temp[16];
            db_get_field(EDITOR_RESULT,0,temp,16);
		 	EDITOR_OBJECT[id][OBJ_DB_ID] = strval(temp);
		 	SendClientMessage(playerid,DEF_COL_WHITE,"Object ID received.");
        }
        db_free_result(EDITOR_RESULT);
		format(EDITOR_QUERY, sizeof(EDITOR_QUERY), "UPDATE `OBJECTS` SET `INT`=-1 WHERE `ID`=%d",EDITOR_OBJECT[id][OBJ_DB_ID]);
		db_free_result(db_query(EDITOR_DATABASE, EDITOR_QUERY));
        SendClientMessage(playerid,DEF_COL_WHITE,"Object saved to database, Usage /editobject or /selectobject to edit this object.");
	}
	return 1;
}

public FUNCTION_LoadObjects()
{
	new DBResult:EDITOR_RESULT,IDX;
	EDITOR_RESULT = db_query(EDITOR_DATABASE,  "SELECT * FROM `OBJECTS`");
	if(db_num_rows(EDITOR_RESULT) > 0) // Logged In
	{
	    new EDITOR_VALEU[26][11],id;
        for (new x=0; x<db_num_rows(EDITOR_RESULT); x++)
		{
			IDX = 0;
		    db_get_field_assoc(EDITOR_RESULT, "ID", EDITOR_VALEU[IDX], 26),IDX++;
		    db_get_field_assoc(EDITOR_RESULT, "MODEL", EDITOR_VALEU[IDX], 26),IDX++;
		    db_get_field_assoc(EDITOR_RESULT, "X", EDITOR_VALEU[IDX],26),IDX++;
		    db_get_field_assoc(EDITOR_RESULT, "Y", EDITOR_VALEU[IDX],26),IDX++;
		    db_get_field_assoc(EDITOR_RESULT, "Z", EDITOR_VALEU[IDX],26),IDX++;
		    db_get_field_assoc(EDITOR_RESULT, "RX", EDITOR_VALEU[IDX],26),IDX++;
		    db_get_field_assoc(EDITOR_RESULT, "RY", EDITOR_VALEU[IDX],26),IDX++;
		    db_get_field_assoc(EDITOR_RESULT, "RZ", EDITOR_VALEU[IDX],26),IDX++;
		    db_get_field_assoc(EDITOR_RESULT, "VW", EDITOR_VALEU[IDX],26),IDX++;
		    db_get_field_assoc(EDITOR_RESULT, "INT", EDITOR_VALEU[IDX],26),IDX++;
		    db_get_field_assoc(EDITOR_RESULT, "DISTANCE", EDITOR_VALEU[IDX],26);

		    id = CreateDynamicObject(strval(EDITOR_VALEU[1]), floatstr( EDITOR_VALEU[2]),floatstr(EDITOR_VALEU[3]),floatstr(EDITOR_VALEU[4]), floatstr( EDITOR_VALEU[5]),floatstr(EDITOR_VALEU[6]),floatstr(EDITOR_VALEU[7]), strval(EDITOR_VALEU[8]), strval(EDITOR_VALEU[9]),-1, floatstr(EDITOR_VALEU[10]));

			if(id > DEF_MAX_OBJECTS) return SendClientMessageToAll(DEF_COL_WHITE,"Error while loading objects, it seems you are trying to load more objects then the max amount of objects.");
			
			EDITOR_OBJECT[id][OBJ_DB_ID] = strval(EDITOR_VALEU[0]);
            EDITOR_OBJECT[id][OBJ_MODEL] = strval(EDITOR_VALEU[1]);
            EDITOR_OBJECT[id][OBJ_X] = floatstr(EDITOR_VALEU[2]);
            EDITOR_OBJECT[id][OBJ_Y] = floatstr(EDITOR_VALEU[3]);
            EDITOR_OBJECT[id][OBJ_Z] = floatstr(EDITOR_VALEU[4]);
            EDITOR_OBJECT[id][OBJ_RX] = floatstr(EDITOR_VALEU[5]);
            EDITOR_OBJECT[id][OBJ_RY] = floatstr(EDITOR_VALEU[6]);
            EDITOR_OBJECT[id][OBJ_RZ] = floatstr(EDITOR_VALEU[7]);
            EDITOR_OBJECT[id][OBJ_VW] = strval(EDITOR_VALEU[8]);
            EDITOR_OBJECT[id][OBJ_INTERIOR] = strval(EDITOR_VALEU[9]);
            EDITOR_OBJECT[id][OBJ_STREAM_DISTANCE] = floatstr(EDITOR_VALEU[10]);
			db_next_row(EDITOR_RESULT);
	    }
	}
	new string[128];
	format(string,sizeof(string),"%d objects have been loaded.",db_num_rows(EDITOR_RESULT));
	SendClientMessageToAll(DEF_COL_WHITE,string);
	db_free_result(EDITOR_RESULT);
	return 1;
}
