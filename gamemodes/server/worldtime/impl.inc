#include <YSI_Coding\y_hooks>

hook OnScriptInit()
{
	SetMyWorldTime(180);
	return 1;
}

task WorldTimeTimer[worldtime_timer_interval]()
{
	server_time[1] ++;
	if(server_time[1] == 60)
	{
		server_time[0] ++;
		if(server_time[0] == 24) {server_time[0] = 0;server_weather = minrand(1,15);}
		server_time[1] = 0;
	}

	foreach(new i : Player)
	{
		if(PlayerTemp[i][pt_State] == state_SPAWNED)
		{
			SetPlayerTime(i, server_time[0], server_time[1]);
			SetPlayerWeather(i, server_weather);
		}
	}
	return 1;
}

CMD:gettime(playerid)
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