//Please do not remove the credit! Or I will cry :(
#include <a_samp>

new strR[255];

#define FILTERSCRIPT
#define VERSION "1.0"

public OnFilterScriptInit()
{
	print("<<-------------------------------->>");
	print("        Anti-advertisment          ");
	print("      Special Made By Dylan Green  ");
	print("         By: Dylan        ");
	print("-----------------------------------\n");
	return 1;
}

public OnPlayerText(playerid, text[])
{
	new is1=0;
 	new r=0;
 	while(strlen(text[is1]))
 	{
  	if('0'<=text[is1]<='9')
  	{
 	new is2=is1+1;
  	new p=0;
   	while(p==0)
  	{
   	if('0'<=text[is2]<='9'&&strlen(text[is2])) is2++;
 	else
  	{
   	strmid(strR[r],text,is1,is2,255);
   	if(strval(strR[r])<255) r++;
    is1=is2;
    p=1;
    }
    }
    }
    is1++;
 	}
 	if(r>=4)
 	{
  	new strMy[255];
   	new STRname[255];
   	GetPlayerName(playerid,STRname,255);
  	format(strMy, sizeof(strMy), " Suspicion advertising %s(%d): %s",STRname,playerid,text);
  	for(new j1=0; j1 < MAX_PLAYERS;j1++)
   	if(IsPlayerAdmin(j1)) SendClientMessage(j1, 0xFF0000FF, strMy);
  	for(new z=0;z<r;z++)
  	{
   	new pr2;
   	while((pr2=strfind(text,strR[z],true))!=-1) for(new i=pr2,j=pr2+strlen(strR[z]);i<j;i++) text[i]='*';
	Kick(playerid);
  	}
 	}
 	return 1;
}
