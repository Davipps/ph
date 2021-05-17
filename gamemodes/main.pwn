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

public OnPlayerRequestSpawn(playerid)
{
	if(PlayerInfo[playerid][pStatus] == sConnected) CallLocalFunction("OnPlayerRequestClass", "dd", playerid, 0);
	return 0;
}

public OnPlayerRequestClass(playerid, classid)
{
	if(PlayerInfo[playerid][pStatus] == sConnected)
	{
		TogglePlayerSpectating(playerid, true);
		new query[250];
		inline OnPlayerCheck()
		{
			new rows;
			if(cache_get_row_count(rows))
			{
				if(rows)
				{
					cache_get_value_name(0, "id", PlayerInfo[playerid][pID]);
					cache_get_value_name(0, "password", PlayerInfo[playerid][pPassword]);
					cache_get_value_name(0, "salt", PlayerInfo[playerid][pSalt]);
					ShowPlayerDialogEx(playerid, DIALOG_LOGIN);
					return 1;
				}
				else
				{
					ShowPlayerDialogEx(playerid, DIALOG_REGISTER);
					return 1;
				}
			}
		}
		mysql_format(Handle, query, sizeof query, "SELECT id, password, salt FROM `player` WHERE `name` = '%e'",PlayerInfo[playerid][pName]);
		MySQL_TQueryInline(Handle, using inline OnPlayerCheck, query);
	}
	return 0;
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
		case DIALOG_LOGIN:
		{
			if(!response) return Kick(playerid);
			if(!strlen(inputtext)) return ShowPlayerDialogEx(playerid, dialogid);
			
			new passhash[64 + 1];
			SHA256_PassHash(inputtext, PlayerInfo[playerid][pSalt], passhash, sizeof passhash);
			if(!strcmp(passhash, PlayerInfo[playerid][pPassword], false))
			{
				LoadPlayerData(playerid);
				SetPlayerVirtualWorld(playerid,0);
				SetPlayerInterior(playerid,0);
				SetSpawnInfo(playerid, NO_TEAM, PlayerInfo[playerid][pSkin], DefaultPos[0], DefaultPos[1], DefaultPos[2], 0.0, 0, 0, 0, 0, 0, 0);
				TogglePlayerSpectating(playerid, false);
				return 1;
			}
			return 1;
		}
		case DIALOG_REGISTER:
		{
			if(strlen(inputtext) < MIN_PASS_LENGTH || strlen(inputtext) > MAX_PASS_LENGTH) return ShowPlayerDialogEx(playerid, dialogid);
			format(PlayerTemp[playerid][tPassword], 24, "%s", inputtext);
			
			new salt[16];
			getRandomText(salt);
			format(PlayerInfo[playerid][pSalt], 16, "%s", salt);
			SHA256_PassHash(inputtext, PlayerInfo[playerid][pSalt], PlayerInfo[playerid][pPassword], 64 + 1);
			ShowPlayerDialogEx(playerid, DIALOG_REGISTER_EMAIL);
			return 1;
		}
		case DIALOG_REGISTER_EMAIL:
		{
			if(!response) return Kick(playerid);
			new mail[32];
			format(mail, 32, "%s", inputtext);
			if(!IsValidEmail(mail))
			{
				SendClientMessage(playerid, -1, "Correo no válido.");
				ShowPlayerDialogEx(playerid, DIALOG_REGISTER_EMAIL);
				return 1;	
			}

			inline CheckEmail()
			{
				new rows;
				if(cache_get_row_count(rows))
				{
					if(rows)
					{
						SendClientMessage(playerid, -1, "Ya existe una cuenta con ese correo.");
						ShowPlayerDialogEx(playerid, dialogid);
					}
					else
					{
						format(PlayerInfo[playerid][pEmail], 32, "%s", mail);
						ShowPlayerDialogEx(playerid, DIALOG_REGISTER_SEX);
					}
				}
				else Kick(playerid);
			}
			mysql_format(Handle, QUERY_BUFFER, sizeof QUERY_BUFFER, "SELECT id FROM player WHERE email = '%e';", mail);
			MySQL_TQueryInline(Handle, using inline CheckEmail, QUERY_BUFFER);
			return 1;
		}
		case DIALOG_REGISTER_SEX:
		{
			if(!response) return Kick(playerid);
			switch(listitem)
			{
				case 0: (PlayerInfo[playerid][pGender] = gMale,PlayerInfo[playerid][pSkin]=26);
				case 1: (PlayerInfo[playerid][pGender] = gFemale,PlayerInfo[playerid][pSkin]=226);
			}
			RegisterNewPlayer(playerid);
			SetPlayerVirtualWorld(playerid,0);
			SetPlayerInterior(playerid,0);
			SetSpawnInfo(playerid, NO_TEAM, PlayerInfo[playerid][pSkin], DefaultPos[0], DefaultPos[1], DefaultPos[2], 0.0, 0, 0, 0, 0, 0, 0);
			TogglePlayerSpectating(playerid, false);
			return 1;
		}
	}
	return 1;
}

#include "src\commands.pwn"