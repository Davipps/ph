public OnPlayerCommandReceived(playerid, cmd[], params[], flags)
{
	if(PlayerInfo[playerid][pi_Admin] < flags && !IsPlayerAdmin(playerid))
	{
		SendClientMessageEx(playerid,-1,"El comando \"/%s\" es inv?lido, us? /ayuda.", cmd);
		return 0;
	}
	return 1;
}

public OnPlayerCommandPerformed(playerid, cmd[], params[], result, flags)
{
	if(result == -1) SendClientMessageEx(playerid,-1,"El comando \"/%s\" es inv?lido, us? /ayuda.", cmd);
	return 1;
}