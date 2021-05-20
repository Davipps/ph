#include <YSI_Coding\y_hooks>

hook OnScriptInit()
{
    inline OnLoadProperties()
    {
        new count;
        if(cache_get_row_count(count))
        {
            new bool:isnull_name, Float:Pos[3], name[MAX_PLAYER_NAME];
            for(new i = 0; i < count; i++)
            {
                if(i >= MAX_HOUSES) break;
                cache_get_value_name_int(i, "id", House[i][h_Id]);
                cache_get_value_name_int(i, "owner", House[i][h_Owner]);
                cache_get_value_name_bool(i, "lock_door", House[i][h_lock]);
                cache_get_value_name_int(i, "price", House[i][h_Price]);
                cache_get_value_name_int(i, "world", House[i][h_World]);
                cache_get_value_name_int(i, "interior", House[i][h_Interior]);
                cache_get_value_name_float(i, "rot", House[i][h_Rot]);          
                cache_get_value_name_float(i, "pos_x", Pos[0]);
                cache_get_value_name_float(i, "pos_y", Pos[1]);
                cache_get_value_name_float(i, "pos_z", Pos[2]);

                House[i][h_PickupId] = CreateDynamicPickup((House[i][h_Owner] == 0)?(1273):(1272), 1, Pos[0], Pos[1], Pos[2], 0);

                cache_is_value_name_null(i, "name", isnull_name);
                if(!isnull_name) cache_get_value_name(i, "name", name, MAX_PLAYER_NAME);

                new info[3];
                info[0] = PICKUP_TYPE_PROPERTY;
                info[1] = i;
                info[2] = pick_TYPE_ENTER;
                Streamer_SetArrayData(STREAMER_TYPE_PICKUP, House[i][h_PickupId], E_STREAMER_EXTRA_ID, info);

                House[i][h_Valid] = true;
                TOTAL_HOUSES++;
            }
            printf(" --> properties(slots: %d, usados: %d)", MAX_HOUSES, TOTAL_HOUSES);
        }
    }
    MySQL_TQueryInline(Handle, using inline OnLoadProperties,  
        "\
            SELECT \
                `properties`.*,\
                `player`.`name` AS `name`\
            FROM \
                `properties` \
            LEFT JOIN \
                `player` \
            ON \
                `properties`.`owner` = `player`.`id`\
        "
    );
    return 1;
}

/*
    OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
    esto cambielo y hagalo compatible con el de doors para hacer un solo public
*/

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(PRESSED(KEY_NO))
    {
        new pickup = PlayerTemp[playerid][pPickup];
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
                case PICKUP_TYPE_PROPERTY:
                {
                    if(IsValidHouse(info[1]))
                    {
                         switch(House[ info[1] ][h_Sold])
                         {
                            case true:
                            {
                                if(IsRangeOfDoor(playerid, P[0], P[1], P[2]))//esto si quiere lo cambia
                                {
                                    //aqui va la funcion para entrar a la casa
                                } 
                            }
                        }
                    }
                }
            }
            
        }
    }
    return 1;
}