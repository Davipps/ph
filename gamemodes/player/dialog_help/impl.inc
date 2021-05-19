#include <YSI_Coding\y_hooks>

hook OnScriptInit()
{
	for(new i=0; i < sizeof DialogHelp; i++)
	{
		new str[32];
		format(str, sizeof str, "%c%s\n",toupper(DialogHelp[i][dCommand][0]),DialogHelp[i][dCommand][1]);
		strcat(DialogHelp_commands, str);
	}
	return 1;
}

CMD:ayuda(playerid, params[])
{
	new command[10];
	if(sscanf(params, "s[10]", command))
	{
		inline const DialogHelpResponse(pid, dialogid, response, listitem, string:inputtext[])
		{
			#pragma unused pid, dialogid, listitem
			if(response)
			{
				callcmd::ayuda(playerid, inputtext);
				return 1;
			}
			return 1;
		}
		Dialog_ShowCallback(playerid, using inline DialogHelpResponse, DIALOG_STYLE_LIST, "AYUDA", DialogHelp_commands, "Siguiente", "Cerrar");
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
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, header, DialogHelp[i][dInfo], "Aceptar", "Cerrar");
				return 1;
			}
		}
		callcmd::ayuda(playerid,NO_PARAMS);
	}
	return 1;
}