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

getRandomText(const text[], length = sizeof text)
{
    for(new i = 0; i != length; i ++)
	{
		text[i] = random(2) ? (random(26) + (random(2) ? 'a' : 'A')) : (random(10) + '0');
	}
	return true;
}