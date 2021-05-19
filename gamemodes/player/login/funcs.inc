public LoadPlayerData(playerid)
{
	new rows;
	if(cache_get_row_count(rows))
	{
		if(rows)
		{
			return 1;
		}
	}
	return 1;
}