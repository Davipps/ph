CMD:entrar(playerid)
{
	if(!PlayerEnterInterior(playerid)) SendClientMessage(playerid, -1, "No estas en una entrada");
	return 1;
}

CMD:salir(playerid)
{
	if(!PlayerExitInterior(playerid)) SendClientMessage(playerid, -1, "No estas en una entrada");
	return 1;
}

CMD:cdoor(playerid, params[])
{
	new icon, name[32];
	if(sscanf(params, "ds[32]", icon, name))return SendNotification(playerid, MSG_USE, "/cdoor [icon_id] [name]");
	if(TOTAL_DOORS >= MAX_DOORS)return SendNotification(playerid, MSG_ERROR, "Maximo de puertas alcanzado");

	bigString[0] = EOS;
    new str[63];
    strcat(bigString, "Nombre\t#ID\n");
    for(new i = 0; i < TOTAL_INTERIORS; i++)
    {
        if(!Ints[i][int_Valid])
        {
            strcat(bigString, " -\t-\n");
            continue;
        }
        format(str, sizeof(str), "%s\t%d\n", Ints[i][int_Name], Ints[i][int_Id]);
        strcat(bigString, str);
    }

	new Float:extP[4];
	GetPlayerPos(playerid, extP[0], extP[1], extP[2]);
	GetPlayerFacingAngle(playerid, extP[3]);

	inline const OnSelectInterior(pid, dialogid, response, listitem, string:inputtext[])
    {
        #pragma unused pid, dialogid, inputtext
        if(response)
        {
			if(!Ints[listitem][int_Valid]) return Dialog_ShowCallback(playerid, using inline OnSelectInterior, DIALOG_STYLE_TABLIST_HEADERS, "Interiors", bigString, "Ir", "Cancelar");
            new Float:P[3];
            GetDynamicPickupPos(Ints[listitem][int_Pickup], P[0], P[1], P[2]);
            SetPlayerPos(playerid, P[0], P[1], P[2]+1.2);
            SetPlayerFacingAngle(playerid, Ints[listitem][int_Rot]);
            SetPlayerInterior(playerid, Ints[listitem][int_IntGame]);

			inline const OnConfirmSelection(pid1, dialogid1, response1, listitem1, string:inputtext1[])
			{
				#pragma unused pid1, dialogid1, inputtext1, listitem1
				if(response1)
				{
					CreateDoor(playerid, name, listitem, icon, extP[0], extP[1], extP[2], extP[3]);
				}
				else
				return Dialog_ShowCallback(playerid, using inline OnSelectInterior, DIALOG_STYLE_TABLIST_HEADERS, "Interiors", bigString, "Ir", "Cancelar");
			}
			Dialog_ShowCallback(playerid, using inline OnConfirmSelection, DIALOG_STYLE_MSGBOX, "AVISO", "¿Seguro de seas crearlo en este interior?", "SI", "NO");
        }
    }
    Dialog_ShowCallback(playerid, using inline OnSelectInterior, DIALOG_STYLE_TABLIST_HEADERS, "Interiors", bigString, "Ir", "Cancelar");
	return 1;
}
flags:cdoor(ADMIN_LEVEL_DEVELOPER)
alias:cdoor("cd")