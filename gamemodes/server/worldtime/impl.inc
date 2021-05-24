#include <YSI_Coding\y_hooks>

hook OnScriptInit()
{
	SetMyWorldTime(10);
	return 1;
}

task WorldTimeTimer[worldtime_timer_interval]()
{
	server_time[1] ++;
	if(server_time[1] == 60)
	{
		server_time[0] ++;
		if(server_time[0] == 24) server_time[0] = 0;
		server_weather = minrand(0,50);
		server_time[1] = 0;
	}

	foreach(new i : Player)
	{
		if(GetPlayerState(i) == PLAYER_STATE_SPAWNED)
		{
			SetPlayerTime(i, server_time[0], server_time[1]);
			SetPlayerWeather(i, server_weather);
		}
	}
	new str[256];
	format(str,sizeof str,"Hora: %d, Minutos: %d, Clima: %d",GetMyWorldHour(), GetMyWorldMinute(), GetMyWorldWeather());
	print(str);
	return 1;
}

CMD:getttime(playerid)
{
	new str[256];
	format(str,sizeof str,"Hora: %d, Minutos: %d, Clima: %d",GetMyWorldHour(), GetMyWorldMinute(), GetMyWorldWeather());
	SendClientMessage(playerid, -1, str);
	print(str);
	return 1;
}

CMD:settime(playerid, params[])
{
	if(sscanf(params,"ii",params[0], params[1])) return SendClientMessage(playerid, -1, "/settime [hour] [minute]");
	SetPlayerTime(playerid, params[0], params[1]);
	return 1;
}

CMD:setweather(playerid, params[])
{
	if(sscanf(params,"i",params[0])) return SendClientMessage(playerid, -1, "/settime [wheaterid]");
	SetPlayerWeather(playerid, params[0]);	
	return 1;
}