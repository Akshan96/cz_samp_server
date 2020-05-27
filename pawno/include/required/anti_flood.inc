#include <a_samp>
#define IP_LIMIT 2 // = Max connections from one single IP
#define SAME_IP_CONNECT 4 // = The number of connects from the same IP before banning the flooder
new Same_IP=0,Join_Stamp,ban_s[25],exceed=0;
#define Time_Limit 3500 // = The time span between connects, adjust it to your own specifications

stock GetStampIP(playerid){
	new S_IP[16];
	Join_Stamp=GetTickCount();
	GetPlayerIp(playerid,S_IP,16);
	format(ban_s, 16, "%s", S_IP);
}