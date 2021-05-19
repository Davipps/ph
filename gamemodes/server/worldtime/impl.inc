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
		if(server_time[0] == 24) server_time[0] = 0;
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
}