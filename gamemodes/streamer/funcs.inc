stock GetDynamicPickupPos(pickupid, &Float:x, &Float:y, &Float:z)
{
    if(!IsValidDynamicPickup(pickupid)) return 0;
    Streamer_GetFloatData(STREAMER_TYPE_PICKUP, pickupid, E_STREAMER_X, x);
    Streamer_GetFloatData(STREAMER_TYPE_PICKUP, pickupid, E_STREAMER_Y, y);
    Streamer_GetFloatData(STREAMER_TYPE_PICKUP, pickupid, E_STREAMER_Z, z);
    return 1;
}