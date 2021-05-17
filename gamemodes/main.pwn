//Debug mode compiler
#pragma option -d2

//MaxPlayers
#define MAX_PLAYERS 100

//Config YSI
#define YSI_NO_OPTIMISATION_MESSAGE
#define YSI_NO_MODE_CACHE
#define YSI_NO_VERSION_CHECK
#define YSI_YES_HEAP_MALLOC

//Includes
#include <crashdetect>
#include <a_samp>
#include <a_mysql>
#include <streamer>
#include <sscanf2>

#include <YSI_Coding\y_inline>
#include <YSI_Data\y_iterate>
#include <YSI_Coding\y_stringhash>
#include <YSI_Coding\y_timers>
#include <YSI_Game\y_vehicledata>
//#include <YSI_Visual\y_zonenames>

#include <pawn.cmd>
#include <pawn.regex>

//Config server
#define SERVER_VERSION	"1.0"
#define VERSION_DATE	"11/04/2021"

#define SERVER_NAME			"Opera Roleplay"
#define SERVER_SHORT_NAME	"Opera RP"
#define SERVER_GAMEMODE		"ORP "SERVER_VERSION" - Roleplay español"
#define SERVER_LANGUAGE		"Español - Spanish"
#define SERVER_WEBSITE		"Proximamente"
#define SERVER_HOSTNAME 	".:: « "SERVER_NAME" v"SERVER_VERSION" » ::."
#define SERVER_COIN			"Diamantes"

//Modulos
#include "src\macros.pwn"
#include "src\defines.pwn"
#include "src\vars.pwn"
#include "src\arrays.pwn"
#include "src\enums.pwn"
#include "src\functions.pwn"
#include "src\timers.pwn"
#include "src\mysql.pwn"
#include "src\dialogex.pwn"
#include "src\textdraws.pwn"
#include "src\3dtextlabels.pwn"

//Callbacks
public OnGameModeInit()
{
	SetGameModeText(SERVER_GAMEMODE);
    SendRconCommand("hostname "SERVER_HOSTNAME"");
    SendRconCommand("language "SERVER_LANGUAGE"");
	SendRconCommand("weburl "SERVER_WEBSITE"");
	SendRconCommand("minconnectiontime 0");
    SendRconCommand("ackslimit 8000");
    SendRconCommand("messageslimit 100");
    SendRconCommand("conncookies 1");
	SendRconCommand("cookielogging 0");
	SendRconCommand("chatlogging 0");
	SendRconCommand("sleep 1");
	defer minconnecttime();

	ConnectDatabase();
	FormatDialogStrings();
	
	DisableInteriorEnterExits();
	ShowPlayerMarkers(PLAYER_MARKERS_MODE_GLOBAL);
	EnableStuntBonusForAll(false);
	ManualVehicleEngineAndLights();	
	return 1;
}

public OnPlayerConnect(playerid)
{
	PlayerInfo[playerid][pStatus] = sConnected;
	GetPlayerName(playerid, PlayerInfo[playerid][pName], 24);
	if(!IsValidName(PlayerInfo[playerid][pName]))
	{
		ShowDialogInfo(playerid, DIALOG_NONE, "AVISO", "Tu nombre no cumple con el formato: Nombre_Apellido");
		defer KickTimer(playerid);
	}
	return 1;
}

/* public OnPlayerRequestSpawn(playerid)
{
	if(PlayerInfo[playerid][pStatus] == sConnected) CallLocalFunction("OnPlayerRequestClass", "dd", playerid, 0);
	return 0;
} */

/* public OnPlayerRequestClass(playerid, classid)
{
	if(PlayerInfo[playerid][pStatus] == sConnected)
	{
		new query[250];
		inline OnPlayerCheck()
		{
			new rows;
			if(cache_get_row_count(rows))
			{
				
			}
		}
		mysql_format(Handle, query, sizeof query, "SELECT name, password, salt FROM `player` WHERE `name` = '%e'",PlayerInfo[playerid][pName]);
		MySQL_TQueryInline(Handle, using inline OnPlayerCheck, query);
	}
	return 0;
} */

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case DIALOG_HELP:
		{
			if(response)
			{
				callcmd::ayuda(playerid, inputtext);
				return 1;
			}
		}
	}
	return 1;
}

#include "src\commands.pwn"