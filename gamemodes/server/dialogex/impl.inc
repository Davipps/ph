forward ShowPlayerDialogEx(playerid, dialogid);
public ShowPlayerDialogEx(playerid, dialogid)
{
	switch(dialogid)
	{
		case DIALOG_HELP: return ShowPlayerDialog(playerid, dialogid, DIALOG_STYLE_LIST, "AYUDA", DialogHelp_commands, "Siguiente", "Cerrar");
		case DIALOG_LOGIN: return ShowPlayerDialog(playerid, dialogid, DIALOG_STYLE_INPUT, "INICIAR SESIÓN", "Tu cuenta se encuentra registrada ingresa tu contraseña para ingresar", "Siguiente", "Cerrar");
		case DIALOG_REGISTER: return ShowPlayerDialog(playerid, dialogid, DIALOG_STYLE_INPUT, "REGISTRO - CONTRASEÑA (1/3)", "Esta cuenta no esta registrada ingresa una contraseña para registrate", "Siguiente", "Cerrar");
		case DIALOG_REGISTER_EMAIL: return ShowPlayerDialog(playerid, dialogid, DIALOG_STYLE_INPUT, "REGISTRO - EMAIL (2/3)", "Ingresa una dirección email para esta cuenta.\nEsta servira en caso de que pierdas/olvides tu contraseña,\n no te preocupes no recibiras ningun tipo de SPAM", "Siguiente", "Cerrar");
		case DIALOG_REGISTER_SEX: return ShowPlayerDialog(playerid, dialogid, DIALOG_STYLE_LIST, "REGISTRO - GENERO (3/3)", "Hombre\nMujer", "Siguiente", "Cerrar");
		default: ShowPlayerDialog(playerid, DIALOG_NONE, DIALOG_STYLE_MSGBOX, "", "", "", "");
	}
	return 1;
}