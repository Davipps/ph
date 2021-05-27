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