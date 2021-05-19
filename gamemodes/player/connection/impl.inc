#include <YSI_Coding\y_hooks>

hook OnPlayerConnect(playerid)
{
	PlayerInfo[playerid][pStatus] = sConnected;
	GetPlayerName(playerid, PlayerInfo[playerid][pName], 24);
	if(!IsValidName(PlayerInfo[playerid][pName]))
	{
		ShowDialogInfo(playerid, DIALOG_INFO, "AVISO", "Tu nombre no cumple con el formato: Nombre_Apellido");
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
		inline const Checked()
		{
			new rows;
			if(cache_get_row_count(rows))
			{
				if(rows)
				{
					cache_get_value_index_int(0, 0, PlayerInfo[playerid][pID]);
					cache_get_value_index(0, 1, PlayerInfo[playerid][pPassword]);
					cache_get_value_index(0, 2, PlayerInfo[playerid][pSalt]);
					ShowLogin(playerid);
				}
				else
				{
					ShowRegister(playerid);
				}
				return 1;
			}
		}
		MySQL_TQueryInline(Handle, using inline Checked, "SELECT id, password, salt FROM `player` WHERE `name` = '%e'",PlayerInfo[playerid][pName]);
	}
	return 0;
}