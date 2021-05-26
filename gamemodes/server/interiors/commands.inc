CMD:cinterior(playerid, params[])
{
    new name_int[60];
    if(sscanf(params, "s[60]", name_int)) return SendNotification(playerid, MSG_USE, "/cinterior [name interior]");
    if(TOTAL_INTERIORS >= MAX_INTERIORS) return SendNotification(playerid, MSG_ERROR, "Maximo de interiores alcanzado");

    inline const SelectType(pid, dialogid, response, listitem, string:inputtext[])
	{
		#pragma unused pid, dialogid, inputtext
        if(!response) return 1;
        if(listitem >= TOTAL_INT_TYPES)return 1;

        new Float:P[4];
        GetPlayerPos(playerid, P[0], P[1], P[2]);
        GetPlayerFacingAngle(playerid, P[3]);
        
        CreateInterior(playerid, name_int, GetPlayerInterior(playerid), IntType[listitem][intType_Id], P[0], P[1], P[2], P[3]);
    }

    new str[600];
    for(new i = 0; i < TOTAL_INT_TYPES; i++)
    {
        strcat(str, IntType[i][intType_Name]);
        strcat(str, "\n");
    }
    Dialog_ShowCallback(playerid, using inline SelectType, DIALOG_STYLE_LIST, "SELECCIONE EL TIPO", str, "Seleccionar", "Cerrar");
    return 1;
}
flags:cinterior(ADMIN_LEVEL_DEVELOPER)
alias:cinterior("ci")