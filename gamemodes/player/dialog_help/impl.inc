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

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
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
            return 1;
		}
    }
    return 1;
}

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
				return 1;
			}
		}
		ShowPlayerDialogEx(playerid, DIALOG_HELP);	
	}
	return 1;
}