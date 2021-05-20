stock IsValidHouse(houseid)
{
    if(houseid >= MAX_HOUSES)return 0;
    if(!House[houseid][h_Valid])return 0;
    return 1;
}

stock IsRangeOfDoor(playerid, Float:X, Float:Y, Float:Z, world = 0)
{
    if(IsPlayerInRangeOfPoint(playerid, MAX_RENGE_USE_DOOR, X, Y, Z) && GetPlayerVirtualWorld(playerid) == world) return 1;
    return 0;
}