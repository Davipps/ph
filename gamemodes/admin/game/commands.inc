

CMD:cinterior(playerid, params[])
{
    new name_int[60];
    if(sscanf(params, "s[60]", name_int)) return SendNotification(playerid, MSG_USE, "/cinterior [name interior]");

    new Float:P[4];
    GetPlayerPos(playerid, P[0], P[1], P[2]);
    GetPlayerFacingAngle(playerid, P[3]);
    
    CreateInterior(playerid, name_int, GetPlayerInterior(playerid), P[0], P[1], P[2], P[3]);
    return 1;
}
flags:cinterior(ADMIN_LEVEL_DEVELOPER)
alias:cinterior("ci")

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