
CMD:tp(playerid, params[])
{
    new Float:P[3], player;
    if(!sscanf(params, "fff", P[0], P[1], P[2]))
    {
        SetPlayerPos(playerid, P[0], P[1], P[2]);
        return 1;
    }
    else if(!sscanf(params, "u", player))
    {
        if(!IsPlayerConnected(player)) return SendNotification(playerid, MSG_ERROR, "Jugador no conectado");
        GetPlayerPos(player, P[0], P[1], P[2]);
        SetPlayerPos(playerid, P[0], P[1]+1, P[2]);
        return 1;
    }
    SendNotification(playerid, MSG_USE, "/tp [playerid | x y z]");
    return 1;
}
flags:tp(ADMIN_LEVEL_HELPER)

CMD:angle(playerid, params[])
{
    new Float:rot[2];
    if(sscanf(params, "f", rot[0])) return SendNotification(playerid, MSG_USE, "/angle [angle]");
    GetPlayerFacingAngle(playerid, rot[1]);
    SetPlayerFacingAngle(playerid, rot[0]+rot[1]);
    return 1;
}
flags:angle(ADMIN_LEVEL_HELPER)
alias:angle("rot")

CMD:cmds(playerid, params[])
{
    bigString[0] = EOS;

    strcat(bigString, "--- Admin Nivel 1 (HELPER) ---\n\n");
    strcat(bigString, cmd_Admins[0]);
    strcat(bigString, "\n\n--- Admin Nivel 2 (MODERADOR) ---\n\n");
    strcat(bigString, cmd_Admins[1]);
    strcat(bigString, "\n\n--- Admin Nivel 3 (ADMINISTRADOR) ---\n\n");
    strcat(bigString, cmd_Admins[2]);
    strcat(bigString, "\n\n--- Admin Nivel 4 (DESARROLLADOR) ---\n\n");
    strcat(bigString, cmd_Admins[3]);

    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "ADMIN CMDS", bigString, "Aceptar", "");
    return 1;
}
flags:cmds(ADMIN_LEVEL_HELPER)
alias:cmds("acmds")