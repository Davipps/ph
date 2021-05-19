forward Response(playerid, dialogid, response, listitem, string:inputtext[]);
public Response(playerid, dialogid, response, listitem, string:inputtext[])
{
	#pragma unused dialogid, inputtext
	
	if (response)
	{
		va_SendClientMessage(playerid, -1, "You picked: %d", listitem);
	}
	else
	{
		SendClientMessage(playerid, -1, "You pressed cancel");
	}
}

CMD:pick(playerid, params[])
{
	// Called when the player responds to the dialog.
	Dialog_ShowCallback(playerid, using public Response<iiiis>, DIALOG_STYLE_LIST, "Pick a number", "0\n1\n2\n3\n4", "OK", "Cancel");
	return 1;
}