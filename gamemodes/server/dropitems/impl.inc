#include <YSI_Coding\y_hooks>

hook OnPlayerEnterDArea(playerid, areaid)
{
    new info[2];
    Streamer_GetArrayData(STREAMER_TYPE_AREA, areaid, E_STREAMER_EXTRA_ID, info);
    if(info[0] == AREA_TYPE_ITEM)
    {
        //se puede agregar un msg para indicar como se toma el item
        PlayerInfo[playerid][pAreaItem] = areaid;
    }
    return 1;
}