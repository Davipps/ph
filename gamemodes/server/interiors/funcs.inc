CreateInterior(playerid, const name[], interior, type, Float:x, Float:y, Float:z, Float:rot)
{
    inline const OnInsertInterior()
    {
        new insert = cache_insert_id();
        if(insert)
        {
            new id[3];
            id[2] = TOTAL_INTERIORS;
            Ints[ id[2] ][int_Id] = insert;
            Ints[ id[2] ][int_Type] = type;
            format(Ints[ id[2] ][int_Name], 60, "%s", name);
            Ints[ id[2] ][int_IntGame] = interior;
            Ints[ id[2] ][int_Rot] = rot;
            id = CreatePickupInterior(19902, x, y, z, interior);
            Ints[ id[2] ][int_Pickup] = id[0];
            Ints[ id[2] ][int_Text] = Text3D:id[1];

            Ints[ id[2] ][int_Valid] = true;
            TOTAL_INTERIORS++;
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

CreatePickupInterior(model, Float:x, Float:y, Float:z, interior)
{
    new id[2]; 
    id[0] = CreateDynamicPickup(model, 1, x, y, z-1, -1, interior);
    id[1] = _:CreateDynamic3DTextLabel("N para salir", -1, x, y, z, 6.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, interior);
    return id;
}