#include <YSI_Coding\y_hooks>

ShowRegister(playerid)
{
	// Called when the player responds to the dialog.
	inline const Register(pid, dialogid, response, listitem, string:inputtext[])
	{
		#pragma unused pid, dialogid, listitem
		
        if(!response) return Kick(playerid);

        if(strlen(inputtext) < MIN_PASS_LENGTH || strlen(inputtext) > MAX_PASS_LENGTH) return Dialog_ShowCallback(playerid, using inline Register, DIALOG_STYLE_PASSWORD, "REGISTRO - CONTRASEÑA (1/3)", "Esta cuenta no esta registrada, ingresa un contraseña para registrate", "Siguiente", "Cerrar");

        new salt[16];
        getRandomText(salt);
        format(PlayerInfo[playerid][pi_Salt], 16, "%s", salt);
        SHA256_PassHash(inputtext, PlayerInfo[playerid][pi_Salt], PlayerInfo[playerid][pi_Password], 64 + 1);
        Dialog_ShowCallback(playerid, using public ShowRegisterEmail<iiiis>, DIALOG_STYLE_INPUT, "REGISTRO - CORREO (2/3)", "Ingresa una dirección email para esta cuenta.\nEsta servira en caso de que pierdas/olvides tu contraseña,\n no te preocupes no recibiras ningun tipo de SPAM", "Siguiente", "Cerrar");
	}
	Dialog_ShowCallback(playerid, using inline Register, DIALOG_STYLE_PASSWORD, "REGISTRO - CONTRASEÑA (1/3)", "Esta cuenta no esta registrada, ingresa un contraseña para registrate", "Siguiente", "Cerrar");
    return 1;
}

public ShowRegisterEmail(playerid, dialogid, response, listitem, string:inputtext[])
{
    if(!response) return Kick(playerid);
    new mail[32];
    format(mail, 32, "%s", inputtext);
    if(!IsValidEmail(mail))
    {
        SendClientMessage(playerid, -1, "Correo no válido.");
        Dialog_ShowCallback(playerid, using public ShowRegisterEmail<iiiis>, DIALOG_STYLE_INPUT, "REGISTRO - CORREO (2/3)", "Ingresa una dirección email para esta cuenta.\nEsta servira en caso de que pierdas/olvides tu contraseña,\n no te preocupes no recibiras ningun tipo de SPAM", "Siguiente", "Cerrar");
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
                Dialog_ShowCallback(playerid, using public ShowRegisterEmail<iiiis>, DIALOG_STYLE_INPUT, "REGISTRO - CORREO (2/3)", "Ingresa una dirección email para esta cuenta.\nEsta servira en caso de que pierdas/olvides tu contraseña,\n no te preocupes no recibiras ningun tipo de SPAM", "Siguiente", "Cerrar");
                return 1;
            }
            else
            {
                format(PlayerInfo[playerid][pi_Email], 32, "%s", mail);
                Dialog_ShowCallback(playerid, using public ShowRegisterGender<iiiis>, DIALOG_STYLE_LIST, "REGISTRO - GENERO (2/3)", "Hombre\nMujer", "Siguiente", "Cerrar");
            }
        }
        else Kick(playerid);
    }
    MySQL_TQueryInline(Handle, using inline CheckEmail, "SELECT id FROM player WHERE email = '%e';", mail);
    return 1;
}

public ShowRegisterGender(playerid, dialogid, response, listitem, string:inputtext[])
{
    if(!response) Kick(playerid);
    switch(listitem)
    {
        case 0: (PlayerInfo[playerid][pi_Gender] = gender_MALE,PlayerInfo[playerid][pi_Skin]=26);
        case 1: (PlayerInfo[playerid][pi_Gender] = gender_FEMALE,PlayerInfo[playerid][pi_Skin]=226);
    }
    RegisterNewPlayer(playerid);
    SetPlayerVirtualWorld(playerid,0);
    SetPlayerInterior(playerid,0);
    SetSpawnInfo(playerid, NO_TEAM, PlayerInfo[playerid][pi_Skin], DefaultPos[0], DefaultPos[1], DefaultPos[2], 0.0, 0, 0, 0, 0, 0, 0);
    TogglePlayerSpectating(playerid, false);
    return 1;
}