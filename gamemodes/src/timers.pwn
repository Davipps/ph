//Timers
task Wheater[WorlTime_interval]()
{
	WorldTime[wSeconds]++;
	
	if(WorldTime[wSeconds] >= 60)
	{
		WorldTime[wSeconds] = 0;
		WorldTime[wMinutes]++;
	}
	
	if(WorldTime[wMinutes] >= 60) 
	{
		WorldTime[wMinutes] = 0;
		WorldTime[wHour]++;
	}
	
	if(WorldTime[wHour] >= 24)
	{
		WorldTime[wHour] = 0;
	}
	
	//printf("My time is hour %d - minutes %d - seconds %d",WorldTime[wHour], WorldTime[wMinutes], WorldTime[wSeconds]);
	return 1;
}

timer KickTimer[100](playerid)
{
	Kick(playerid);
	return 1;
}

timer BanTimer[100](playerid)
{
	Ban(playerid);
	return 1;
}

timer minconnecttime[60000]()
{
	SendRconCommand("minconnectiontime 0"); //3000");
	return 1;
}