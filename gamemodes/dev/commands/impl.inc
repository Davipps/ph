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

CMD:getpos(playerid)
{
	new Float:pos[4];
	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	GetPlayerFacingAngle(playerid, pos[3]);
	SendClientMessageEx(playerid, -1, "%f, %f, %f, %f", pos[0], pos[1], pos[2], pos[3]);
	printf("%f, %f, %f, %f", pos[0], pos[1], pos[2], pos[3]);
	return 1;
}

CMD:setpos(playerid, params[])
{
	new Float:pos[4];
	if(sscanf(params,"ffff",pos[0], pos[1], pos[2], pos[3])) return SendClientMessage(playerid, -1, "/setpos [posx] [posx] [posz] [angle]");
	SetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	SetPlayerFacingAngle(playerid, pos[3]);
	return 1;
}

CMD:givemeadmin(playerid)
{
    PlayerInfo[playerid][pi_Admin] = ADMIN_LEVEL_DEVELOPER;
    return 1;
}