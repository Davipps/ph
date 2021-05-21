#include <YSI_Coding\y_hooks>

hook OnScriptInit()
{
	inline const OnLoadDoors()
    {
        new rows;
        if(cache_get_row_count(rows))
        {
            new totalDoors;
            for(new i = 0; i != rows; i ++)
            {
                cache_get_value_name_int(i, "id", Doors[i][sd_ID]);
                cache_get_value_name(i, "name", Doors[i][sd_Name], 32);
                //intdata
                cache_get_value_name_int(i, "int_freeze", Doors[i][sd_IntFreeze]);
                cache_get_value_name_int(i, "int_mapicon", Doors[i][sd_IntMapIcon]);
                cache_get_value_name_int(i, "int_world", Doors[i][sd_IntWorld]);
                cache_get_value_name_int(i, "int_interior", Doors[i][sd_IntInterior]);
                cache_get_value_name_float(i, "int_posx", Doors[i][sd_IntPos][0]);
                cache_get_value_name_float(i, "int_posy", Doors[i][sd_IntPos][1]);
                cache_get_value_name_float(i, "int_posz", Doors[i][sd_IntPos][2]);
                cache_get_value_name_float(i, "int_posa", Doors[i][sd_IntPos][3]);
                //extdata
                cache_get_value_name_int(i, "ext_freeze", Doors[i][sd_ExtFreeze]);
                cache_get_value_name_int(i, "ext_mapicon", Doors[i][sd_ExtMapIcon]);
                cache_get_value_name_int(i, "ext_world", Doors[i][sd_ExtWorld]);
                cache_get_value_name_int(i, "ext_interior", Doors[i][sd_ExtInterior]);
                cache_get_value_name_float(i, "ext_posx", Doors[i][sd_ExtPos][0]);
                cache_get_value_name_float(i, "ext_posy", Doors[i][sd_ExtPos][1]);
                cache_get_value_name_float(i, "ext_posz", Doors[i][sd_ExtPos][2]);
                cache_get_value_name_float(i, "ext_posa", Doors[i][sd_ExtPos][3]);
				cache_get_value_name_int(i, "time_open", Doors[i][sd_TimeOpen]);
				cache_get_value_name_int(i, "time_close", Doors[i][sd_TimeClose]);
                cache_get_value_name_int(i, "actorid", Doors[i][sd_Actorid]);
                //
				new label_str[256],info[3];
				if(Doors[i][sd_TimeOpen] == 0 && Doors[i][sd_TimeClose] == 0) format(label_str, sizeof label_str, "%s\nPresiona 'Y' o usa /entrar para entrar", Doors[i][sd_Name]);
				else if(Doors[i][sd_TimeOpen] == -1 && Doors[i][sd_TimeClose] == -1) format(label_str, sizeof label_str, "{FF7373}%s\nPRÓXIMA APERTURA", Doors[i][sd_Name]);
				else format(label_str, sizeof label_str, "%s\n\nHorario: %02d:00h - %02d:00h\n\nPresiona 'Y' o usa /entrar para entrar", Doors[i][sd_Name], Doors[i][sd_TimeOpen], Doors[i][sd_TimeClose]);
				
				Doors[i][sd_IntLabelID] = CreateDynamic3DTextLabel("Salida\nPresiona 'Y' o usa /salir para salir", 0xFFFFFFFF, Doors[i][sd_IntPos][0], Doors[i][sd_IntPos][1], Doors[i][sd_IntPos][2] + 0.25, 10.0, .testlos = true, .worldid = Doors[i][sd_IntWorld], .interiorid = Doors[i][sd_IntInterior]);
				Doors[i][sd_ExtLabelID] = CreateDynamic3DTextLabel(label_str, 0xFFFFFFFF, Doors[i][sd_ExtPos][0], Doors[i][sd_ExtPos][1], Doors[i][sd_ExtPos][2] + 0.25, 10.0, .testlos = true, .worldid = Doors[i][sd_ExtWorld], .interiorid = Doors[i][sd_ExtInterior]);
				
				if(Doors[i][sd_IntMapIcon] != -1) Doors[i][sd_IntMapIconID] = CreateDynamicMapIcon(Doors[i][sd_IntPos][0], Doors[i][sd_IntPos][1], Doors[i][sd_IntPos][2], Doors[i][sd_IntMapIcon], -1, Doors[i][sd_IntWorld], Doors[i][sd_IntInterior]);
				if(Doors[i][sd_ExtMapIcon] != -1) Doors[i][sd_ExtMapIconID] = CreateDynamicMapIcon(Doors[i][sd_ExtPos][0], Doors[i][sd_ExtPos][1], Doors[i][sd_ExtPos][2], Doors[i][sd_ExtMapIcon], -1, Doors[i][sd_ExtWorld], Doors[i][sd_ExtInterior]);
				
				Doors[i][sd_IntPickupID] = CreateDynamicPickup(0, 1, Doors[i][sd_IntPos][0], Doors[i][sd_IntPos][1], Doors[i][sd_IntPos][2], Doors[i][sd_IntWorld], Doors[i][sd_IntInterior]);
				Doors[i][sd_ExtPickupID] = CreateDynamicPickup(19902, 1, Doors[i][sd_ExtPos][0], Doors[i][sd_ExtPos][1], Doors[i][sd_ExtPos][2] - 1, Doors[i][sd_ExtWorld], Doors[i][sd_ExtInterior]);

				info[0] = PICKUP_TYPE_DOORS;
				info[1] = i; // Index
				info[2] = 1; // Pickup Interior
				Streamer_SetArrayData(STREAMER_TYPE_PICKUP, Doors[i][sd_IntPickupID], E_STREAMER_EXTRA_ID, info);
                totalDoors++;	
            }
            printf("Debug: Doors loaded %d", totalDoors);
        }
    }
    MySQL_TQueryInline(Handle, using inline OnLoadDoors, "SELECT * FROM `doors`");
	return 1;
}