stock CreateDoor(playerid, const name[], interior, icon, Float:x, Float:y, Float:z, Float:rot)
{
    inline const OnCreateDoor()
    {
        new insert = cache_insert_id();
        if(insert)
        {
            new id[4];
            id[3] = GetFreeSlotDoors();

            SetInfoDoor(insert, id[3], icon, name, interior, insert+5, rot);

            id = CreatePickupDoor(19902, icon, id[3], x, y, z);
            Doors[ id[3] ][d_ExtPickupID] = id[0];
            Doors[ id[3] ][d_ExtLabelID] = Text3D:id[1];
            Doors[ id[3] ][d_ExtMapIconID] = id[2];

            new str[50];
            format(str, 50, "puerta guardado exitosamente (id: %d)", insert);
            SendNotification(playerid, MSG_INFO, str);
        }
    }
    MySQL_TQueryInline(Handle, using inline OnCreateDoor, 
        "\
            INSERT INTO\
                `doors`\
            (\
                `name`,\
                `interior`,\
                `int_world`,\
                `ext_mapicon`,\
                `ext_posx`,\
                `ext_posy`,\
                `ext_posz`,\
                `ext_posa`\
            )\
            VALUES\
            (\
                '%e',%d,`id`+5,%d,%f,%f,%f,%f\
            )\
        ",
        name,
        Ints[interior][int_Id],
        icon,
        x, y, z, rot
    );
    return 1;
}

stock GetFreeSlotDoors()
{
    new id = -1;
    for(new i = 0; i < TOTAL_DOORS; i++)
    { 
        if(!Doors[i][d_Valid]) return i;
    }
    if(TOTAL_DOORS < MAX_DOORS) id = TOTAL_DOORS++;
    return id;
}

stock SetInfoDoor(id, slot, icon, const name[], interior_db, world, Float:rot)
{
    Doors[slot][d_ID] = id;
    format(Doors[slot][d_Name], 32, "%s", name);
    Doors[slot][d_IntFreeze] = false;
    Doors[slot][d_IntWorld] = world;
    Doors[slot][d_IntInterior] = interior_db;
    Doors[slot][d_ExtMapIcon] = icon;
    Doors[slot][d_ExtFreeze] = false;
    Doors[slot][d_ExtRot] = rot;
    Doors[slot][d_TimeOpen] = 0;
    Doors[slot][d_TimeClose] = 0;
    Doors[slot][d_Actorid] = 0;
    Doors[slot][d_Valid] = true;
}

stock CreatePickupDoor(model, icon, slot, Float:x, Float:y, Float:z)
{
    new label_str[256], info[3], id[3];

    if(Doors[slot][d_TimeOpen] == 0 && Doors[slot][d_TimeClose] == 0) 
        format(label_str, sizeof label_str, "%s\nPresiona 'Y' o usa /entrar para entrar", Doors[slot][d_Name]);
    else if(Doors[slot][d_TimeOpen] == -1 && Doors[slot][d_TimeClose] == -1) 
        format(label_str, sizeof label_str, "{FF7373}%s\nPRÓXIMA APERTURA", Doors[slot][d_Name]);
    else 
        format(label_str, sizeof label_str, "%s\n\nHorario: %02d:00h - %02d:00h\n\nPresiona 'Y' o usa /entrar para entrar", Doors[slot][d_Name], Doors[slot][d_TimeOpen], Doors[slot][d_TimeClose]);
    
    id[0] = CreateDynamicPickup(model, 1, x, y, z - 1, -1, -1);

    id[1] = _:CreateDynamic3DTextLabel(label_str, 0xFFFFFFFF, x, y, z + 0.25, 10.0, .testlos = true, .worldid = 0, .interiorid = 0);

    id[2] = -1;
    if(icon != -1) id[2] = CreateDynamicMapIcon(x, y, z, icon, -1, 0, 0);

    info[0] = PICKUP_TYPE_DOORS;
    info[1] = slot; // Index
    info[2] = pick_TYPE_ENTER; // Pickup Exterior
    Streamer_SetArrayData(STREAMER_TYPE_PICKUP, id[0], E_STREAMER_EXTRA_ID, info);

    return id;
}