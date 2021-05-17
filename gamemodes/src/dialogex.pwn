//Callback to format dialogs

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