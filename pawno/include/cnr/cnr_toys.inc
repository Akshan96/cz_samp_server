#define DIALOG_ATTACH_INDEX             13500
#define DIALOG_ATTACH_INDEX_SELECTION   DIALOG_ATTACH_INDEX+1
#define DIALOG_ATTACH_EDITREPLACE       DIALOG_ATTACH_INDEX+2
#define DIALOG_ATTACH_MODEL_SELECTION   DIALOG_ATTACH_INDEX+3
#define DIALOG_ATTACH_BONE_SELECTION    DIALOG_ATTACH_INDEX+4
#define DIALOG_ATTACH_OBJECT_SELECTION  DIALOG_ATTACH_INDEX+5
#define DIALOG_ATTACH_OBJECT2_SELECTION DIALOG_ATTACH_INDEX+6

new AttachmentObjectsList[] = {
18632,
18633,
18634,
18635,
18636,
18637,
18638,
18639,
18640,
18975,
19136,
19274,
18641,
18642,
18643,
18644,
18645,
18865,
18866,
18867,
18868,
18869,
18870,
18871,
18872,
18873,
18874,
18875,
18890,
18891,
18892,
18893,
18894,
18895,
18896,
18897,
18898,
18899,
18900,
18901,
18902,
18903,
18904,
18905,
18906,
18907,
18908,
18909,
18910,
18911,
18912,
18913,
18914,
18915,
18916,
18917,
18918,
18919,
18920,
18921,
18922,
18923,
18924,
18925,
18926,
18927,
18928,
18929,
18930,
18931,
18932,
18933,
18934,
18935,
18936,
18937,
18938,
18939,
18940,
18941,
18942,
18943,
18944,
18945,
18946,
18947,
18948,
18949,
18950,
18951,
18952,
18953,
18954,
18955,
18956,
18957,
18958,
18959,
18960,
18961,
18962,
18963,
18964,
18965,
18966,
18967,
18968,
18969,
18970,
18971,
18972,
18973,
18974,
18976,
18977,
18978,
18979,
19006,
19007,
19008,
19009,
19010,
19011,
19012,
19013,
19014,
19015,
19016,
19017,
19018,
19019,
19020,
19021,
19022,
19023,
19024,
19025,
19026,
19027,
19028,
19029,
19030,
19031,
19032,
19033,
19034,
19035,
19036,
19037,
19038,
19039,
19040,
19041,
19042,
19043,
19044,
19045,
19046,
19047,
19048,
19049,
19050,
19051,
19052,
19053,
19085,
19086,
19090,
19091,
19092,
19093,
19094,
19095,
19096,
19097,
19098,
19099,
19100,
19101,
19102,
19103,
19104,
19105,
19106,
19107,
19108,
19109,
19110,
19111,
19112,
19113,
19114,
19115,
19116,
19117,
19118,
19119,
19120,
19137,
19138,
19139,
19140,
19141,
19142,
19160,
19161,
19162,
19163,
19317,
19318,
19319,
19330,
19331,
19346,
19347,
19348,
19349,
19350,
19351,
19352,
19487,
19488,
19513,
19515,
331,
333,
334,
335,
336,
337,
338,
339,
341,
321,
322,
323,
324,
325,
326,
343,
346,
347,
348,
349,
350,
351,
352,
353,
355,
356,
372,
357,
358,
361,
363,
364,
365,
366,
367,
368,
369,
371
};

new AttachmentBones[][24] = {
{"Spine"},
{"Head"},
{"Left upper arm"},
{"Right upper arm"},
{"Left hand"},
{"Right hand"},
{"Left thigh"},
{"Right thigh"},
{"Left foot"},
{"Right foot"},
{"Right calf"},
{"Left calf"},
{"Left forearm"},
{"Right forearm"},
{"Left clavicle"},
{"Right clavicle"},
{"Neck"},
{"Jaw"}
};

COMMAND:toys(playerid, params[])
{
	if(playerData[playerid][playerLoggedIn])
	{
		if (playerData[playerid][playerVIPLevel] >= 3)
		{
			new string[128];
			for(new x;x<MAX_OSLOTS;x++)
			{
				if(IsPlayerAttachedObjectSlotUsed(playerid, x))
				{
					format(string, sizeof(string), "%sSlot Used\n", string);
				}
				else
				{
					format(string, sizeof(string), "%sFree Slot\n", string);
				}
			}
			ShowPlayerDialog(playerid, DIALOG_ATTACH_INDEX_SELECTION, DIALOG_STYLE_LIST, "Toy System", string, "Select", "Close");
		}
	}
	return 1;
}

public OnPlayerEditAttachedObject(playerid, response, index, modelid, boneid,Float:fOffsetX, Float:fOffsetY, Float:fOffsetZ,Float:fRotX, Float:fRotY, Float:fRotZ,Float:fScaleX, Float:fScaleY, Float:fScaleZ)
{
	playerData[playerid][toyStatus][index] = true;
	playerData[playerid][toyID][index] = modelid;
	playerData[playerid][toyBone][index] = boneid;
	playerData[playerid][toyPosX][index] = fOffsetX;
	playerData[playerid][toyPosY][index] = fOffsetY;
	playerData[playerid][toyPosZ][index] = fOffsetZ;
	playerData[playerid][toyRotX][index] = fRotX;
	playerData[playerid][toyRotY][index] = fRotY;
	playerData[playerid][toyRotZ][index] = fRotZ;
	playerData[playerid][toyScaleX][index] = fScaleX;
	playerData[playerid][toyScaleY][index] = fScaleY;
	playerData[playerid][toyScaleZ][index] = fScaleZ;
    SetPlayerAttachedObject(playerid, index, modelid, boneid, fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ);
    SendClientMessage(playerid, COLOR_WHITE, "{B7B7B7}[SERVER] {FFFFFF}You have finished editing attachments, type /savestats to save it..");
    return 1;
}

public OnPlayerModelSelectionEx(playerid, response, extraid, modelid)
{
	if(extraid==DIALOG_ATTACH_MODEL_SELECTION)
	{
	    if(!response)
     	{
			ShowPlayerDialog(playerid, DIALOG_ATTACH_OBJECT_SELECTION, DIALOG_STYLE_LIST,"Toy System - Select Object", "Server Objects Menu\nCustom Object", "Next", "Back");
		}
	    else
	    {
		    if(GetPVarInt(playerid, "AttachmentUsed") == 1) EditAttachedObject(playerid, modelid);
		    else
		    {
			    SetPVarInt(playerid, "AttachmentModelSel", modelid);
                new string[256+1];
				new dialog[500];
				for(new x;x<sizeof(AttachmentBones);x++)
    			{
					format(string, sizeof(string), "Bone %s\n", AttachmentBones[x]);
					strcat(dialog,string);
				}
				ShowPlayerDialog(playerid, DIALOG_ATTACH_BONE_SELECTION, DIALOG_STYLE_LIST, \
				"Toy System - Bone Selection", dialog, "Select", "Cancel");
		    }//else DeletePVar(playerid, "AttachmentIndexSel");
		}
 	}
	return 1;
}