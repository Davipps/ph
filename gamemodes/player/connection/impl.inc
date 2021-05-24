#include <YSI_Coding\y_hooks>

hook OnPlayerConnect(playerid)
{
	PlayerTemp[playerid][pt_State] = state_CONNECTED;
	GetPlayerName(playerid, PlayerInfo[playerid][pi_Name], 24);
	if(!IsValidName(PlayerInfo[playerid][pi_Name]))
	{
		ShowDialogInfo(playerid, DIALOG_INFO, "AVISO", "Tu nombre no cumple con el formato: Nombre_Apellido");
		defer KickTimer(playerid);
	}
	return 1;
}

hook OnPlayerRequestSpawn(playerid)
{
	if(PlayerTemp[playerid][pt_State] == state_CONNECTED) CallLocalFunction("OnPlayerRequestClass", "dd", playerid, 0);
	return 0;
}

hook OnPlayerRequestClass(playerid, classid)
{
	if(PlayerTemp[playerid][pt_State] == state_CONNECTED)
	{
		TogglePlayerSpectating(playerid, true);
		inline const Checked()
		{
			new rows;
			if(cache_get_row_count(rows))
			{
				if(rows)
				{
					cache_get_value_index_int(0, 0, PlayerInfo[playerid][pi_ID]);
					cache_get_value_index(0, 1, PlayerInfo[playerid][pi_Password]);
					cache_get_value_index(0, 2, PlayerInfo[playerid][pi_Salt]);
					ShowLogin(playerid);
				}
				else
				{
					ShowRegister(playerid);
				}
				return 1;
			}
		}
		MySQL_TQueryInline(Handle, using inline Checked, "SELECT id, password, salt FROM `player` WHERE `name` = '%e'",PlayerInfo[playerid][pi_Name]);
	}
	return 0;
}

hook OnPlayerSpawn(playerid)
{
	PlayerTemp[playerid][pt_State] = state_SPAWNED;
	return 1;
}