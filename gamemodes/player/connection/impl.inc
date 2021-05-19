#include <YSI_Coding\y_hooks>

hook OnPlayerConnect(playerid)
{
	PlayerInfo[playerid][pStatus] = sConnected;
	GetPlayerName(playerid, PlayerInfo[playerid][pName], 24);
	if(!IsValidName(PlayerInfo[playerid][pName]))
	{
		ShowDialogInfo(playerid, DIALOG_NONE, "AVISO", "Tu nombre no cumple con el formato: Nombre_Apellido");
		defer KickTimer(playerid);
	}
	return 1;
}

hook OnPlayerRequestSpawn(playerid)
{
	if(PlayerInfo[playerid][pStatus] == sConnected) CallLocalFunction("OnPlayerRequestClass", "dd", playerid, 0);
	return 0;
}

hook OnPlayerRequestClass(playerid, classid)
{
	if(PlayerInfo[playerid][pStatus] == sConnected)
	{
		TogglePlayerSpectating(playerid, true);
		new query[250];
		inline OnPlayerCheck()
		{
			new rows;
			if(cache_get_row_count(rows))
			{
				if(rows)
				{
					cache_get_value_name(0, "id", PlayerInfo[playerid][pID]);
					cache_get_value_name(0, "password", PlayerInfo[playerid][pPassword]);
					cache_get_value_name(0, "salt", PlayerInfo[playerid][pSalt]);
					ShowPlayerDialogEx(playerid, DIALOG_LOGIN);
					return 1;
				}
				else
				{
					ShowPlayerDialogEx(playerid, DIALOG_REGISTER);
					return 1;
				}
			}
		}
		mysql_format(Handle, query, sizeof query, "SELECT id, password, salt FROM `player` WHERE `name` = '%e'",PlayerInfo[playerid][pName]);
		MySQL_TQueryInline(Handle, using inline OnPlayerCheck, query);
	}
	return 0;
}