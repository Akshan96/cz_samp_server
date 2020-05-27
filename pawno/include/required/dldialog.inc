#if defined _DLDiag_included
    #endinput
#endif
#define _DLDiag_included

#if !defined _samp_included
    #error "<a_samp> must be included before <DLDiag>"
#endif

#if !defined DLD_STRING_SIZE
    #define DLD_STRING_SIZE 1000
#endif

#if !defined DLD_MAX_LIST_ITEMS
    #define DLD_MAX_LIST_ITEMS 100
#endif
#define DLItemID DLDPlayerListItems[playerid][listitem]
#define DLParam DLDPlayerListParam[playerid][listitem]

new DLDString[DLD_STRING_SIZE];
new DLDPlayerListItems[MAX_PLAYERS][DLD_MAX_LIST_ITEMS];
new DLDPlayerListParam[MAX_PLAYERS][DLD_MAX_LIST_ITEMS];
new DLDLastIS;

stock AddDListItem(playerid, ItemStr[1000], ItemID = -1, ItemParam = -1)
{
    DLDPlayerListItems[playerid][DLDLastIS] = ItemID;
    DLDPlayerListParam[playerid][DLDLastIS] = ItemParam;
    if( !DLDLastIS ){DLDString = ""; format(DLDString, sizeof(DLDString), "%s", ItemStr);}
    else format(DLDString, sizeof(DLDString), "%s\r\n%s", DLDString, ItemStr);
    DLDLastIS++;
    return DLDLastIS -1;
}
stock ShowPlayerDList(playerid, DialogID, Caption[], Button1[], Button2[])
{
    DLDLastIS = 0;
    ShowPlayerDialog(playerid, DialogID, DIALOG_STYLE_LIST, Caption, DLDString, Button1, Button2);
    DLDString = "";
    return true;
}
stock Clear_DList(playerid)
{
    for( new i; i < DLD_MAX_LIST_ITEMS; i++ )
    {
        DLDPlayerListItems[playerid][i] = 0;
        DLDPlayerListParam[playerid][i] = 0;
    }
    return true;
}