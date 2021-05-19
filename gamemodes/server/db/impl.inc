#include <YSI_Coding\y_hooks>

hook OnScriptInit()
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

hook OnScriptExit()
{
	mysql_close(Handle);
	return 1;
}

hook OnQueryError(errorid, const error[], const callback[], const query[], MySQL:handle)
{
	switch(errorid) 
	{
		case CR_SERVER_GONE_ERROR: printf("[MySQL] [ERROR]: Se ha perdido la conexión con el servidor (%d)", _:handle);
		case ER_SYNTAX_ERROR: printf("[MySQL] [ERROR]: Syntax error, query: %s (%d)", query, _:handle);
		default: printf("[MySQL] [ERROR] errorid: %d, error: %s, callback: %s, query: %s, handle: %d", errorid, error, callback, query, _:handle);
	}
	return 1;
}