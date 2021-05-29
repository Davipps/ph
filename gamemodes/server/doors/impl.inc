#include <YSI_Coding\y_hooks>

hook OnScriptInit()
{
	inline const OnLoadDoors()
    {
        new rows;
        if(cache_get_row_count(rows))
        {
            new Float:P[3];
            for(new i = 0; i != rows; i ++)
            {
                if(i >= MAX_DOORS) break;
                cache_get_value_name_int(i, "id", Doors[i][d_ID]);
                cache_get_value_name(i, "name", Doors[i][d_Name], 32);
                //intdata
                cache_get_value_name_int(i, "int_freeze", Doors[i][d_IntFreeze]);
                cache_get_value_name_int(i, "int_world", Doors[i][d_IntWorld]);
                cache_get_value_name_int(i, "slot", Doors[i][d_IntInterior]);
                //extdata
                cache_get_value_name_int(i, "ext_freeze", Doors[i][d_ExtFreeze]);
                cache_get_value_name_int(i, "ext_mapicon", Doors[i][d_ExtMapIcon]);
                cache_get_value_name_float(i, "ext_posx", P[0]);
                cache_get_value_name_float(i, "ext_posy", P[1]);
                cache_get_value_name_float(i, "ext_posz", P[2]);
                cache_get_value_name_float(i, "ext_posa", Doors[i][d_ExtRot]);
				cache_get_value_name_int(i, "time_open", Doors[i][d_TimeOpen]);
				cache_get_value_name_int(i, "time_close", Doors[i][d_TimeClose]);
                cache_get_value_name_int(i, "actorid", Doors[i][d_Actorid]);
                //
				new label_str[256],info[3];
				if(Doors[i][d_TimeOpen] == 0 && Doors[i][d_TimeClose] == 0) format(label_str, sizeof label_str, "%s\nPresiona 'Y' o usa /entrar para entrar", Doors[i][d_Name]);
				else if(Doors[i][d_TimeOpen] == -1 && Doors[i][d_TimeClose] == -1) format(label_str, sizeof label_str, "{FF7373}%s\nPRÓXIMA APERTURA", Doors[i][d_Name]);
				else format(label_str, sizeof label_str, "%s\n\nHorario: %02d:00h - %02d:00h\n\nPresiona 'Y' o usa /entrar para entrar", Doors[i][d_Name], Doors[i][d_TimeOpen], Doors[i][d_TimeClose]);
				
				//Doors[i][d_IntLabelID] = CreateDynamic3DTextLabel("Salida\nPresiona 'Y' o usa /salir para salir", 0xFFFFFFFF, Doors[i][d_IntPos][0], Doors[i][d_IntPos][1], Doors[i][d_IntPos][2] + 0.25, 10.0, .testlos = true, .worldid = Doors[i][d_IntWorld], .interiorid = Doors[i][d_IntInterior]);
				Doors[i][d_ExtLabelID] = CreateDynamic3DTextLabel(label_str, 0xFFFFFFFF, P[0], P[1], P[2] + 0.25, 10.0, .testlos = true, .worldid = 0, .interiorid = 0);
				
				//if(Doors[i][d_IntMapIcon] != -1) Doors[i][d_IntMapIconID] = CreateDynamicMapIcon(Doors[i][d_IntPos][0], Doors[i][d_IntPos][1], Doors[i][d_IntPos][2], Doors[i][d_IntMapIcon], -1, Doors[i][d_IntWorld], Doors[i][d_IntInterior]);
				if(Doors[i][d_ExtMapIcon] != -1) Doors[i][d_ExtMapIconID] = CreateDynamicMapIcon(P[0], P[1], P[2], Doors[i][d_ExtMapIcon], -1, 0, 0);
				
				//Doors[i][d_IntPickupID] = CreateDynamicPickup(0, 1, Doors[i][d_IntPos][0], Doors[i][d_IntPos][1], Doors[i][d_IntPos][2], Doors[i][d_IntWorld], Doors[i][d_IntInterior]);
				Doors[i][d_ExtPickupID] = CreateDynamicPickup(19902, 1, P[0], P[1], P[2] - 1, -1, -1);

				/*info[0] = PICKUP_TYPE_DOORS;
				info[1] = i; // Index
				info[2] = pick_TYPE_EXIT; // Pickup Interior
				Streamer_SetArrayData(STREAMER_TYPE_PICKUP, Doors[i][d_IntPickupID], E_STREAMER_EXTRA_ID, info);*/

				info[0] = PICKUP_TYPE_DOORS;
				info[1] = i; // Index
				info[2] = pick_TYPE_ENTER; // Pickup Exterior
				Streamer_SetArrayData(STREAMER_TYPE_PICKUP, Doors[i][d_ExtPickupID], E_STREAMER_EXTRA_ID, info);
                TOTAL_DOORS++;	
            }
            printf(" --> doors (slots: %d, usados: %d)", MAX_DOORS, TOTAL_DOORS);
        }
    }
    MySQL_TQueryInline(Handle, using inline OnLoadDoors, 
        "\
            SELECT \
                `doors`.*,\
                `interiors`.`slot` AS `slot` \
            FROM \
                `doors` \
            LEFT JOIN \
                `interiors` \
            ON \
                `interiors`.`id` = `doors`.`interior`;\
        "
    );
	return 1;
}

#include "commands"