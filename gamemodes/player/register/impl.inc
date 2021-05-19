#include <YSI_Coding\y_hooks>

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{ 		
    switch(dialogid)
    {
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