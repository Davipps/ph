#include <YSI_Coding\y_hooks>

hook OnScriptInit()
{
    inline const OnInteriorsLoad()
    {
        new count;
        if(cache_get_row_count(count))
        {
            new Float:P[3], bool:isnull_type;
            for(new i = 0; i < count; i++)
            {
                cache_get_value_name_int(i, "id", Ints[i][int_Id]);
                cache_get_value_name(i, "name", Ints[i][int_Name]);
                cache_get_value_name_int(i, "interior_id", Ints[i][int_IntGame]);
                cache_is_value_name_null(i, "type", isnull_type);
                if(!isnull_type) cache_get_value_name_int(i, "type", Ints[i][int_Type]);

                cache_get_value_name_float(i, "int_x", P[0]);
                cache_get_value_name_float(i, "int_y", P[1]);
                cache_get_value_name_float(i, "int_z", P[2]);
                cache_get_value_name_float(i, "int_rot", Ints[i][int_Rot]);

                Ints[i][int_Pickup] = CreateDynamicPickup(19902, 1, P[0], P[1], P[2]-1, -1, Ints[i][int_IntGame]);
                Ints[i][int_Text] = CreateDynamic3DTextLabel("N para salir", -1, P[0], P[1], P[2], 6.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, Ints[i][int_IntGame]);

                new info[3];
                switch(Ints[i][int_Type])
                {
                    case 23: info[0] = PICKUP_TYPE_PROPERTY;
                    default: info[0] = PICKUP_TYPE_DOORS;
                }
                info[1] = i;
                info[2] = pick_TYPE_EXIT;
                Streamer_SetArrayData(STREAMER_TYPE_PICKUP, Ints[i][int_Pickup], E_STREAMER_EXTRA_ID, info);
                Ints[i][int_Valid] = true;
                TOTAL_INTERIORS++;
            }
            printf(" --> interiors (slots: %d, usados: %d)", MAX_INTERIORS, TOTAL_INTERIORS);
        }
    }
    MySQL_TQueryInline(Handle, using inline OnInteriorsLoad, "SELECT * FROM `interiors`;");
    return 1;
}