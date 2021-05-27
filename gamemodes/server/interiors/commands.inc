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

    bigString[0] = EOS;
    for(new i = 0; i < TOTAL_INT_TYPES; i++)
    {
        strcat(bigString, IntType[i][intType_Name]);
        strcat(bigString, "\n");
    }
    Dialog_ShowCallback(playerid, using inline SelectType, DIALOG_STYLE_LIST, "SELECCIONE EL TIPO", bigString, "Seleccionar", "Cerrar");
    return 1;
}
flags:cinterior(ADMIN_LEVEL_DEVELOPER)
alias:cinterior("ci")

CMD:einterior(playerid, params[])
{
    new id, name[60];
    if(sscanf(params, "dS()[60]", id, name)) return SendNotification(playerid, MSG_USE, "/einterior [interior_id] [name]");

    new slot = GetInteriorSlot(id);
    if(slot == -1) return SendNotification(playerid, MSG_ERROR, "Interior no valido");

    inline const SelectType(pid, dialogid, response, listitem, string:inputtext[])
	{
		#pragma unused pid, dialogid, inputtext
        if(!response) return 1;
        if(listitem >= TOTAL_INT_TYPES)return 1;

        new Float:P[4];
        GetPlayerPos(playerid, P[0], P[1], P[2]);
        GetPlayerFacingAngle(playerid, P[3]);
        
        EditInterior(playerid, name, slot, IntType[listitem][intType_Id], GetPlayerInterior(playerid), P[0], P[1], P[2], P[3]);
    }
    
    bigString[0] = EOS;
    for(new i = 0; i < TOTAL_INT_TYPES; i++)
    {
        strcat(bigString, IntType[i][intType_Name]);
        strcat(bigString, "\n");
    }
    Dialog_ShowCallback(playerid, using inline SelectType, DIALOG_STYLE_LIST, "SELECCIONE EL TIPO", bigString, "Seleccionar", "Cerrar");
    return 1;
}
flags:einterior(ADMIN_LEVEL_DEVELOPER)
alias:einterior("ei")

CMD:dinterior(playerid, params[])
{
    new id;
    if(sscanf(params, "d", id)) return SendNotification(playerid, MSG_USE, "/dinterior [interior_id]");

    new slot = GetInteriorSlot(id);
    if(slot == -1) return SendNotification(playerid, MSG_ERROR, "Interior no valido");
    if(!Ints[slot][int_Valid]) return SendNotification(playerid, MSG_ERROR, "Interior no valido");

    inline const Confirm(pid, dialogid, response, listitem, string:inputtext[])
    {
        #pragma unused pid, dialogid, inputtext, listitem
        if(response)
        {
            DeleteInterior(playerid, slot);
        }
    }
    Dialog_ShowCallback(playerid, using inline Confirm, DIALOG_STYLE_MSGBOX, "AVISO", "¿Seguro desea eliminar el interior?\n", "SI", "NO");
    return 1;
}
flags:dinterior(ADMIN_LEVEL_DEVELOPER)
alias:dinterior("di")

CMD:irinterior(playerid, params[])
{
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

    inline const OnGotoInterior(pid, dialogid, response, listitem, string:inputtext[])
    {
        #pragma unused pid, dialogid, inputtext
        if(response)
        {
            new Float:P[3];
            GetDynamicPickupPos(Ints[listitem][int_Pickup], P[0], P[1], P[2]);
            SetPlayerPos(playerid, P[0], P[1], P[2]+1.2);
            SetPlayerFacingAngle(playerid, Ints[listitem][int_Rot]);
            SetPlayerInterior(playerid, Ints[listitem][int_IntGame]);
        }
    }
    Dialog_ShowCallback(playerid, using inline OnGotoInterior, DIALOG_STYLE_TABLIST_HEADERS, "Interiors", bigString, "Ir", "Cancelar");
    return 1;
}
flags:irinterior(ADMIN_LEVEL_DEVELOPER)
alias:irinterior("ii")