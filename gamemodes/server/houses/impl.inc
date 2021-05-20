#include <YSI_Coding\y_hook>

hook OnScriptInit()
{
    inline OnLoadHouses()
    {
        new count;
        if(cache_get_row_count(count))
        {
            for(new i = 0; i < count; i++)
            {
                if(i >= MAX_HOUSES) break;
                House[i][h_valid] = true;
                TOTAL_HOUSES++;
            }
        }
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(PRESSED(KEY_NO))
    {
        new pickup = PlayerInfo[playerid][pPickup];
        if(pickup && IsValidDynamicPickup( pickup ))
        {
            new info[2];
			Streamer_GetArrayData(STREAMER_TYPE_PICKUP, pickup, E_STREAMER_EXTRA_ID, info);
			if(info[0] != PICKUP_TYPE_NONE)return 1;

            new Float:P[3];
			Streamer_GetFloatData(STREAMER_TYPE_PICKUP, pickup, E_STREAMER_X, P[0]);
			Streamer_GetFloatData(STREAMER_TYPE_PICKUP, pickup, E_STREAMER_Y, P[1]);
			Streamer_GetFloatData(STREAMER_TYPE_PICKUP, pickup, E_STREAMER_Z, P[2]);

            switch(info[0])
            {
                case PICKUP_TYPE_PROPERTY:{
                    if(IsValidHouse(info[1])){
                        
                    }
                }
            }
            

            switch(House[ info[1] ][h_Sold]){
                case true:{
                    if(IsRangeOfDoor(playerid, P[0], P[1], P[2])){

                    } 
                    else if(IsRangeOfDoor(playerid, P[0], P[1], P[2], House[ info[1] ][h_World])){

                    } 
                    return 1;
                }
            }
        }
    }
    return 1;
}

hook OnPlayerPickUpDPickup(playerid, pickupid)
{
    PlayerInfo[playerid][pPickup] = pickupid;
    return 1;
}