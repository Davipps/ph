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