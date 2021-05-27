
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