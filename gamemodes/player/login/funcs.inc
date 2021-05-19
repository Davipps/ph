LoadPlayerData(playerid)
{
	inline OnPlayerDataLoad()
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
	MySQL_TQueryInline(Handle, using inline OnPlayerDataLoad, "SELECT * FROM `player` WHERE `ID` = '%d'",PlayerInfo[playerid][pID]);
	return 1;
}