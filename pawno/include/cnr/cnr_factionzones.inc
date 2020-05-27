#define MAX_ZONES 1

new zones[MAX_ZONES];
new Float:zones_points_0[] = {
	-1547.0,483.0,-1591.0,418.0,-1651.0,355.0,-1710.0,299.0,-1733.0,263.0,-1447.0,260.0,-1446.0,290.0,-1342.0,293.0,-1327.0,304.0,-1325.0,433.0,
	-1223.0,437.0,-1215.0,553.0,-1467.0,524.0,-1547.0,483.0
};

new zones_text[MAX_ZONES][64] = {
	"San Fierro Army Base"
};

stock load_zones()
{
	zones[0] = CreateDynamicPolygon(zones_points_0);
}

public OnFilterScriptExit() {
	return 1;
}

public OnPlayerEnterDynamicArea(playerid, areaid) {
	for (new zone=0; zone<MAX_ZONES; zone++) {
		if (areaid==zones[zone]) {
			new msg[90];
			format(msg, 90, "{B7B7B7}[ZONE] {FFFFFF}You have entered {58D3F7}%s", zones_text[zone]);
			SendClientMessage(playerid, 0xFFFFFFFF, msg);
		}
	}
	return 1;
}

public OnPlayerLeaveDynamicArea(playerid, areaid) {
	for (new zone=0; zone<MAX_ZONES; zone++) {
		if (areaid==zones[zone]) {
			new msg[90];
			format(msg, 90, "{B7B7B7}[ZONE] {FFFFFF}You have left {58D3F7}%s", zones_text[zone]);
			SendClientMessage(playerid, 0xFFFFFFFF, msg);
		}
	}
	return 1;
}
