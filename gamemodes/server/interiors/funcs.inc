CreateInterior(playerid, const name[], interior, Float:x, Float:y, Float:z, Float:rot)
{
    inline const OnInsertInterior()
    {
        SendNotification(playerid, MSG_INFO, "Interior guardado exitosamente");
    }
    MySQL_TQueryInline(Handle, using inline OnInsertInterior, 
        "\
            INSERT INTO \
                `interiors`\
                (\
                    `name`,\
                    `interior_id`,\
                    `int_x`,\
                    `int_y`,\
                    `int_z`,\
                    `int_rot`\
                )\
            VALUES\
            (\
                '%e',%d,%f,%f,%f,%f\
            );\
        ",
        name,
        interior,
        x, y, z, rot
    );
    return 1;
}