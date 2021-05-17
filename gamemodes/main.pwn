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

#include <pawn.cmd>
#include <pawn.regex>

//Macros
#define function%0(%1) forward %0(%1);public%0(%1)

//Defines
#define SERVER_VERSION	"1.0"
#define VERSION_DATE	"11/04/2021"

#define SERVER_NAME			"Opera Roleplay"
#define SERVER_SHORT_NAME	"Opera RP"
#define SERVER_GAMEMODE		"ORP "SERVER_VERSION" - Roleplay español"
#define SERVER_LANGUAGE		"Español - Spanish"
#define SERVER_WEBSITE		"Proximamente"
#define SERVER_HOSTNAME 	".:: « "SERVER_NAME" v"SERVER_VERSION" » ::."
#define SERVER_COIN			"Diamantes"

//Variables

//-- mysql
new MySQL:Handle;
new QUERY_BUFFER[4096];	

//-- time world
new WorlTime_interval = 1000; //config timer interval WorlTime - 1000 = 1 second

//-- format dialogs string
new DialogHelp_commands[200];

//Arrays
enum e_DialogHelp
{
	dCommand[32],
	dInfo[200]
}
new DialogHelp[][e_DialogHelp] = 
{
	{"general", "test 1"},
	{"vehiculos", "test 2"}
};

new RegisterMaleSkins[4] = {78, 79, 137, 200};
new RegisterFemaleSkins[4] = {10, 31, 131, 151};

//Enumerators
enum //Dialog id's
{
	DIALOG_NONE,
	DIALOG_REGISTER, DIALOG_REGISTER_EMAIL, DIALOG_REGISTER_SEX, //Dialogs registers
	DIALOG_LOGIN,
	DIALOG_HELP,
};

enum e_WorldTime
{
	wSeconds,
	wMinutes,
	wHour	
};
new WorldTime[e_WorldTime];

enum e_pStatus
{
	sNone,
	sConnected,
	sDead,
	sSpawned
};

enum e_PlayerInfo
{
	pID,
	pName,
	pPassword[65],
	pAdmin,
	pGender,
	e_pStatus:pStatus,
	pSkin,
	pLevel,
	pReputation
};
new PlayerInfo[MAX_PLAYERS][e_PlayerInfo];

enum e_VehInfo
{
	vEngine,
	vLights,
	vAlarm,
	vDoors,
}
new VehInfo[MAX_VEHICLES][e_VehInfo];

//Timers
task Wheater[WorlTime_interval]()
{
	WorldTime[wSeconds]++;
	
	if(WorldTime[wSeconds] >= 60)
	{
		WorldTime[wSeconds] = 0;
		WorldTime[wMinutes]++;
	}
	
	if(WorldTime[wMinutes] >= 60) 
	{
		WorldTime[wMinutes] = 0;
		WorldTime[wHour]++;
	}
	
	if(WorldTime[wHour] >= 24)
	{
		WorldTime[wHour] = 0;
	}
	
	//printf("My time is hour %d - minutes %d - seconds %d",WorldTime[wHour], WorldTime[wMinutes], WorldTime[wSeconds]);
	return 1;
}

timer KickTimer[100](playerid)
{
	Kick(playerid);
	return 1;
}

timer BanTimer[100](playerid)
{
	Ban(playerid);
	return 1;
}

timer minconnecttime[60000]()
{
	SendRconCommand("minconnectiontime 0"); //3000");
	return 1;
}

//Functions
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

getRandomText(const text[], length = sizeof text)
{
    for(new i = 0; i != length; i ++)
	{
		text[i] = random(2) ? (random(26) + (random(2) ? 'a' : 'A')) : (random(10) + '0');
	}
	return true;
}

IsValidName(const string[])
{
	new Regex:reg_exp = Regex_New("[A-Z][a-z]+_[A-Z][a-z]{1,3}[A-Z]?[a-z]*");
	new result = Regex_Check(string, reg_exp);
	Regex_Delete(reg_exp);
	return result;
}

IsValidEmail(const string[])
{
	new Regex:reg_exp = Regex_New("[a-zA-Z0-9_\\.]+@([a-zA-Z0-9\\-]+\\.)+[a-zA-Z]{2,4}"); 
	new result = Regex_Check(string, reg_exp); 
	Regex_Delete(reg_exp); 
	return result; 
}

ShowDialogInfo(playerid, dialogid, const caption[], const info[])
{
	ShowPlayerDialog(playerid, dialogid, DIALOG_STYLE_MSGBOX, caption, info, "Aceptar", "");
	return 1;
}

FormatDialogStrings()
{
	for(new i=0; i < sizeof DialogHelp; i++)
	{
		new str[32];
		format(str, sizeof str, "%c%s\n",toupper(DialogHelp[i][dCommand][0]),DialogHelp[i][dCommand][1]);
		strcat(DialogHelp_commands, str);
	}
	return 1;	
}
//Stocks

//Modulos
#include "src\vehdata.pwn"

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

forward ShowPlayerDialogEx(playerid, dialogid);
public ShowPlayerDialogEx(playerid, dialogid)
{
	switch(dialogid)
	{
		case DIALOG_HELP:
		{
			ShowPlayerDialog(playerid, dialogid, DIALOG_STYLE_LIST, "Ayuda", DialogHelp_commands, "Siguiente", "Cerrar");
			return 1;
		}
		default: ShowPlayerDialog(playerid, DIALOG_NONE, DIALOG_STYLE_MSGBOX, "", "", "", "");
	}
	return 1;
}

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

//Commands
CMD:ayuda(playerid, params[])
{
	new command[10];
	if(sscanf(params, "s[10]", command))
	{
		ShowPlayerDialogEx(playerid, DIALOG_HELP);
		return 1;
	}
	else
	{
		for(new i=0; i < sizeof DialogHelp; i++)
		{
			if(!strcmp(command, DialogHelp[i][dCommand], true))
			{
				new header[50];
				format(header, sizeof header, "Ayuda %c%s",toupper(DialogHelp[i][dCommand][0]),DialogHelp[i][dCommand][1]);
				ShowPlayerDialog(playerid, DIALOG_NONE, DIALOG_STYLE_MSGBOX, header, DialogHelp[i][dInfo], "Aceptar", "Cerrar");
				break;
			}
		}
	}
	return 1;
}
