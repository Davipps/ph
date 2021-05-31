stock CreateInterior(playerid, const name[], interior, type, Float:x, Float:y, Float:z, Float:rot)
{
    inline const OnInsertInterior()
    {
        new insert = cache_insert_id();
        if(insert)
        {
            new id[3];
            id[2] = GetFreeSlotInteriors();
            SetInfoInterior(id[2], insert, type, name, interior, rot);
            id = CreatePickupInterior(19902, id[2], x, y, z, interior, type);
            Ints[ id[2] ][int_Pickup] = id[0];
            Ints[ id[2] ][int_Text] = Text3D:id[1];

            mysql_format(Handle, QUERY_BUFFER, sizeof QUERY_BUFFER, "UPDATE `interiors` SET `slot`= %d WHERE `id`= %d;", id[2], insert);
            mysql_tquery(Handle, QUERY_BUFFER);

            new str[50];
            format(str, 50, "Interior guardado exitosamente (id: %d)", insert);
            SendNotification(playerid, MSG_INFO, str);
        }
    }
    MySQL_TQueryInline(Handle, using inline OnInsertInterior, 
        "\
            INSERT INTO \
                `interiors`\
                (\
                    `name`,\
                    `interior_id`,\
                    `type`,\
                    `int_x`,\
                    `int_y`,\
                    `int_z`,\
                    `int_rot`\
                )\
            VALUES\
            (\
                '%e',%d,%d,%f,%f,%f,%f\
            );\
        ",
        name,
        interior,
        type,
        x, y, z, rot
    );
    return 1;
}

stock CreatePickupInterior(model, index, Float:x, Float:y, Float:z, interior, type)
{
    new id[2]; 
    id[0] = CreateDynamicPickup(model, 1, x, y, z-1, -1, interior);
    id[1] = _:CreateDynamic3DTextLabel("N para salir", -1, x, y, z, 6.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, interior);

    new info[3];
    switch(type)
    {
        case 23: info[0] = PICKUP_TYPE_PROPERTY;
        default: info[0] = PICKUP_TYPE_DOORS;
    }
    info[1] = index;
    info[2] = pick_TYPE_EXIT;
    Streamer_SetArrayData(STREAMER_TYPE_PICKUP, id[0], E_STREAMER_EXTRA_ID, info);
    return id;
}

stock SetInfoInterior(slot, id, type, const name[], interior, Float:rot)
{
    Ints[ slot ][int_Id] = id;
    Ints[ slot ][int_Type] = type;
    format(Ints[ slot ][int_Name], 60, "%s", name);
    Ints[ slot ][int_IntGame] = interior;
    Ints[ slot ][int_Rot] = rot;
    Ints[ slot ][int_Valid] = true;
    return 1;
}

stock GetInteriorSlot(int)
{
    for(new i = 0; i < TOTAL_INTERIORS; i++) if(Ints[i][int_Id] == int) return i;
    return -1;
}

stock GetFreeSlotInteriors()
{
    new id = -1;
    for(new i = 0; i < TOTAL_INTERIORS; i++)
    { 
        if(!Ints[i][int_Valid]) return i;
    }
    if(TOTAL_INTERIORS < MAX_INTERIORS) id = TOTAL_INTERIORS++;
    return id;
}

stock DeletePickupInterior(slot)
{
    DestroyDynamicPickup(Ints[ slot ][int_Pickup]);
    DestroyDynamic3DTextLabel(Ints[ slot ][int_Text]);
    return 1;
}

stock EditInterior(playerid, const name[], slot, type, interior, Float:x, Float:y, Float:z, Float:rot)
{
    new stream[2];
    stream[0] = Ints[ slot ][int_Pickup];
    stream[1] = _:Ints[ slot ][int_Text];
    inline const OnEditInterior()
    {
        if(cache_affected_rows())
        {    
            SetInfoInterior(slot, Ints[ slot ][int_Id], type, name, interior, rot);

            new id[2];
            id = CreatePickupInterior(19902, slot, x, y, z, interior, type);
            Ints[ slot ][int_Pickup] = id[0];
            Ints[ slot ][int_Text] = Text3D:id[1];

            DestroyDynamicPickup(stream[0]);
            DestroyDynamic3DTextLabel(Text3D:stream[1]);

            new str[50];
            format(str, 50, "Interior editado exitosamente (id: %d)", Ints[slot][int_Id]);
            SendNotification(playerid, MSG_INFO, str);
        }
    }
    MySQL_TQueryInline(Handle, using inline OnEditInterior, 
        "\
            UPDATE \
                `interiors` \
            SET \
                `name`=IF('%e'='', `name`, '%e'),\
                `interior_id`= %d,\
                `type`= %d,\
                `int_x`= %f,\
                `int_y`= %f,\
                `int_z`= %f,\
                `int_rot`= %f \
            WHERE \
                `id`= %d;\
        ",
        name,
        name,
        interior,
        type,
        x, y, z, rot,
        Ints[slot][int_Id]
    );
    return 1;
}

stock DeleteInterior(playerid, slot)
{
    inline const OnDeleteInterior()
    {
        if(cache_affected_rows())
        {
            DeletePickupInterior(slot);

            new str[50];
            format(str, 50, "Interior borrado exitosamente (id: %d)", Ints[slot][int_Id]);
            SendNotification(playerid, MSG_INFO, str);

            new tmp[e_intInfo];
            Ints[slot] = tmp;
            format(Ints[slot][int_Name], 60, "-");
            if(slot == TOTAL_INTERIORS-1)TOTAL_INTERIORS--;
        }
    }
    MySQL_TQueryInline(Handle, using inline OnDeleteInterior, 
        "\
            DELETE FROM \
                `interiors` \
            WHERE \
                `id`= %d;\
        ",
        Ints[slot][int_Id]
    );
    return 1;
}