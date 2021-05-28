#include <YSI_Coding\y_hooks>

hook OnPlayerLogin(playerid)
{
	pt_LastDoubt[playerid] = gettime();
	return 1;
}

CMD:duda(playerid, params[])
{
	new string[256],text[145];
	if(!sscanf(params, "s[145]", text))
	{
		if(PlayerInfo[playerid][pi_Admin] == 0 && gettime() - pt_LastDoubt[playerid] < MIN_TIME_BETWEEN_DOUBTS)
		{
			new time_sec = MIN_TIME_BETWEEN_DOUBTS - (gettime() - pt_LastDoubt[playerid]);
			SendClientMessageEx(playerid, -1, "Tienes que esperar %s minutos para volver a realizar otra consulta.", TimeConvert(time_sec));
            return 1;
		}
		else
		{
			foreach(new i : Player)
			{
				if(PlayerTemp[i][pt_State] == state_SPAWNED)
				{
                    format(string, sizeof string, "[Dudas - /d] %s(%d) [Nivel: %d]: %s", PlayerInfo[playerid][pi_Name],playerid,PlayerInfo[playerid][pi_Level],text);
					SendClientMessage(i, -1, string);
				}
			}
			pt_LastDoubt[playerid] = gettime();
            return 1;
		}
	}
	else SendClientMessage(playerid, -1, "Syntax: /duda [texto]");
	return 1;
}