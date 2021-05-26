CreateInterior(playerid, const name[], interior, type, Float:x, Float:y, Float:z, Float:rot)
{
    inline const OnInsertInterior()
    {
        new id = cache_insert_id();
        if(id)
        {
            new str[50];
            format(str, 50, "Interior guardado exitosamente (id: %d)", id);
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