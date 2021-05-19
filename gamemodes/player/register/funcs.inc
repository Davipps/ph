RegisterNewPlayer(playerid)
{
//insert into
	inline OnPlayerInserted()
	{
		new id = cache_insert_id();
		if(id)
		{
			PlayerInfo[playerid][pID] = id;
		}
		else Kick(playerid);
	}
	MySQL_TQueryInline(Handle, using inline OnPlayerInserted, 
		"\
			INSERT INTO `player`(`name`, `password`, `salt`, `email`, `gender`) VALUES ('%e','%e','%e','%e',%d)\
		",
		PlayerInfo[playerid][pName],
		PlayerInfo[playerid][pPassword], 
		PlayerInfo[playerid][pSalt], 
		PlayerInfo[playerid][pEmail], 
		PlayerInfo[playerid][pGender]
	);
	return 1;
}