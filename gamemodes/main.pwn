//Debug mode comPlayerInfoler
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

#include <YSI_Visual\y_dialog>
#include <YSI_Coding\y_inline>
#include <YSI_Extra\y_inline_mysql>
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

//HEADERS

#include "utils\header"
#include "server\db\header"
#include "server\intro\header"
#include "server\vehinfo\header"
#include "server\worldtime\header"
#include "server\textdraws\login\header"
#include "server\textdraws\logo\header"
#include "server\interiors\header"
#include "server\houses\header"

#include "server\items\header"
#include "server\dropitems\header"
#include "server\doors\header"

#include "player\pinfo\header"
#include "player\ptemp\header"
#include "player\dialog_help\header"
#include "player\login\header"
#include "player\register\header"
#include "player\hungry_thirst\header"

//FUNCS

#include "utils\funcs"
#include "server\worldtime\funcs"
#include "server\dropitems\funcs"
#include "server\houses\funcs"
#include "server\doors\funcs"
#include "admin\game\funcs"

#include "player\register\funcs"
#include "player\login\funcs"
#include "player\hungry_thirst\funcs"

//IMPLS
#include "streamer\impl"
#include "server\db\impl"
#include "server\interiors\impl"
#include "server\houses\impl"
#include "server\worldtime\impl"
#include "server\textdraws\login\impl"
#include "server\textdraws\logo\impl"
#include "server\doors\impl"
#include "admin\game\impl"

#include "server\commands\impl"

#include "dev\commands\impl"

#include "admin\timers\impl"

#include "player\connection\impl"
#include "player\dialog_help\impl"
#include "player\login\impl"
#include "player\register\impl"
#include "player\hungry_thirst\impl"

timer minconnecttime[60000]()
{
	SendRconCommand("minconnectiontime 0"); //3000");
	return 1;
}

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
	
	DisableInteriorEnterExits();
	ShowPlayerMarkers(PLAYER_MARKERS_MODE_GLOBAL);
	EnableStuntBonusForAll(false);
	ManualVehicleEngineAndLights();	
	return 1;
}

main()
{
	print("Gamemode inciado corretamente ");
}