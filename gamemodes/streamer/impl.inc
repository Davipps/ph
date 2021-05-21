#include <YSI_Coding\y_hooks>

public OnPlayerEnterDynamicArea(playerid, areaid)
{
    new info[2];
    Streamer_GetArrayData(STREAMER_TYPE_AREA, areaid, E_STREAMER_EXTRA_ID, info);
    switch(info[0])
    {
        case AREA_TYPE_ITEM: PlayerTemp[playerid][pt_AreaItem] = areaid;
    }
    return 1;
}

public OnPlayerPickUpDynamicPickup(playerid, pickupid)
{
    PlayerTemp[playerid][pt_LastPickupID] = pickupid;
    return 1;
}