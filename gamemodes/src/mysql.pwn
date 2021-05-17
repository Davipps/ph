new MySQL:Handle;
new QUERY_BUFFER[4096];	

ConnectDatabase()
{ 
	mysql_log(ERROR | WARNING | INFO);
	Handle = mysql_connect_file("db.ini");
	
	if(Handle == MYSQL_INVALID_HANDLE || mysql_errno(Handle) != 0)
	{
		print("\n ----------------------------------");
		print("      Conexión con DB fallida!      ");
		print(" ----------------------------------\n");
     	SendRconCommand("exit");
		return 0;
	}
	else
	{
		print("\n ----------------------------------------");
		print(" La conexión con la base de datos funciona.");
		print(" ----------------------------------------\n");
		mysql_tquery(Handle, "SET FOREIGN_KEY_CHECKS = 1; UPDATE `player` SET `connected` = '0', `playerid` = '-1';");
		return 1;
	}
}

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
		return 1;
	}

	mysql_format
	(
		Handle, QUERY_BUFFER, sizeof QUERY_BUFFER,
		"INSERT INTO `player`(`name`, `password`, `salt`, `email`, `gender`) VALUES (%e,%e,%e,%e,%d)",
		PlayerInfo[playerid][pName],PlayerInfo[playerid][pSalt], PlayerInfo[playerid][pPassword], PlayerInfo[playerid][pEmail], PlayerInfo[playerid][pGender]
	);
	MySQL_TQueryInline(Handle, using inline OnPlayerInserted, QUERY_BUFFER);
	return 1;
}

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