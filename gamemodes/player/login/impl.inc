ShowLogin(playerid)
{
	// Called when the player responds to the dialog.
	inline const Login(pid, dialogid, response, listitem, string:inputtext[])
	{
		#pragma unused pid, dialogid, listitem
		
		if (!response || isnull(inputtext))
		{
			SendClientMessage(playerid, -1, "Ingresa un contraseña");
			ShowLogin(playerid);
			return 1;
		}

		new password[64+1];
		SHA256_PassHash(inputtext, PlayerInfo[playerid][pi_Salt], password, sizeof password);
		if(!strcmp(password, PlayerInfo[playerid][pi_Password], false))
		{
			MySQL_TQueryInline(Handle, using callback OnPlayerDataLoad, "SELECT * FROM `player` WHERE `id` = '%d'",PlayerInfo[playerid][pi_ID]);
			SetPlayerVirtualWorld(playerid,0);
			SetPlayerInterior(playerid,0);
			SetSpawnInfo(playerid, NO_TEAM, PlayerInfo[playerid][pi_Skin], DefaultPos[0], DefaultPos[1], DefaultPos[2], 0.0, 0, 0, 0, 0, 0, 0);
			TogglePlayerSpectating(playerid, false);
			return 1;
		}
		else //contraseña incorrecta
		{
			ShowLogin(playerid);
		}
		return 1;
	}
	Dialog_ShowCallback(playerid, using inline Login, DIALOG_STYLE_PASSWORD, ""PRIMARY_COLOR"INICIAR SESIÓN", ""WHITE"Esta cuenta esta registrada, ingresa tu contraseña", "Siguiente", "Cerrar");
	return 1;
}