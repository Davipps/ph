RegisterNewPlayer(playerid)
{
//insert into
	inline OnPlayerInserted()
	{
		new id = cache_insert_id();
		if(id)
		{
			PlayerInfo[playerid][pi_ID] = id;
		}
		else Kick(playerid);
	}
	MySQL_TQueryInline(Handle, using inline OnPlayerInserted, 
		"\
			INSERT INTO `player`(`name`, `password`, `salt`, `email`, `gender`) VALUES ('%e','%e','%e','%e',%d)\
		",
		PlayerInfo[playerid][pi_Name],
		PlayerInfo[playerid][pi_Password], 
		PlayerInfo[playerid][pi_Salt], 
		PlayerInfo[playerid][pi_Email], 
		PlayerInfo[playerid][pi_Gender]
	);
	return 1;
}