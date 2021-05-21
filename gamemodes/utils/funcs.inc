//Functions
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

getRandomText(text[], length = sizeof text)
{
    for(new i = 0; i != length; i ++)
	{
		text[i] = random(2) ? (random(26) + (random(2) ? 'a' : 'A')) : (random(10) + '0');
	}
	return true;
}

minrand(min, max) //By Alex "Y_Less" Cole
{
	return random(max - min) + min;
}

SendClientMessageEx(playerid, color, const form[], {Float, _}:...) {
    new string[145];
	format(string, sizeof(string), form, ___(3));
    return (playerid == -1 ? (SendClientMessageToAll(color, string)) : (SendClientMessage(playerid, color, string)) );
}

SendNotification(playerid, Notif_Type:type, const message[]){
	new color = -1, string[256 char];
	switch(type)
	{
		case MSG_INFO:strcat(string, "« INFO » "), color = 0x00FF00FF;
		case MSG_IMPORTANT:strcat(string, "« IMPORTANTE » "), color = 0xFFFF00FF;
		case MSG_USE:strcat(string, "« USO » "), color = 0x8080FFFF;
		case MSG_WARNING:strcat(string, "« AVISO » "), color = 0xFF8000FF;
		case MSG_ERROR:strcat(string, "« ERROR » "), color = 0xFF3300FF;
	}
	strcat(string, message);
	return SendClientMessage(playerid, color, string);
}