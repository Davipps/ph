#include <YSI_Coding\y_hooks>

hook OnPlayerEnterDArea(playerid, areaid)
{
    new info[2];
    Streamer_GetArrayData(STREAMER_TYPE_AREA, areaid, E_STREAMER_EXTRA_ID, info);
    switch(info[0])
    {
        case AREA_TYPE_ITEM: PlayerTemp[playerid][pAreaItem] = areaid;
    }
    return 1;
}

hook OnPlayerPickUpDPickup(playerid, pickupid)
{
    PlayerTemp[playerid][pPickup] = pickupid;
    return 1;
}