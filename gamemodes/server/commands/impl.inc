public OnPlayerCommandReceived(playerid, cmd[], params[], flags)
{
	if(PlayerInfo[playerid][pAdmin] < flags && !IsPlayerAdmin(playerid))
	{
		SendClientMessageEx(playerid,-1,"El comando \"/%s\" es inválido, usá /ayuda.", cmd);
		return 0;
	}
	return 1;
}