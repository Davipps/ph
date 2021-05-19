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

//-- server
#include "utils\defines\header.inc"
#include "server\db\header"
#include "server\dialogs\header.inc" //estos id de dialogos talvez cambien por inline dialog que hare proximamente
#include "server\intro\header.inc"
#include "server\vehinfo\header.inc"
#include "server\worldtime\header.inc"
#include "server\items\header.inc"
#include "server\dropitems\header.inc"

//-- player
#include "player\pinfo\header.inc"
#include "player\dialog_help\header.inc"
#include "player\register\header.inc"

//FUNCS

//-- utils
#include "utils\functions\funcs.inc"
#include "server\worldtime\funcs.inc"

//-- player
#include "player\register\funcs"
#include "player\login\funcs"

//-- drop items
#include "server\dropitems\funcs.inc"

//IMPLS

#include "server\db\impl.inc"
#include "server\worldtime\impl.inc"
#include "server\dialogex\impl.inc"
#include "server\commands\impl.inc"
#include "server\dropitems\impl.inc"

#include "dev\commands\impl.inc"

#include "admin\timers\impl.inc"

#include "player\connection\impl.inc"
#include "player\dialog_help\impl.inc"
#include "player\login\impl.inc"
#include "player\register\impl.inc"

#include "test\inline_dialog\impl.inc"

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
	print("Gamemode inciado corretamente");
}