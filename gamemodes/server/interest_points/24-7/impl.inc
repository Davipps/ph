
#include <YSI_Coding\y_hooks>

hook OnScriptInit()
{
    for(new i=0; i != sizeof ext_pos_247; i++)
    {    
        new enterexitid = CreateEnterExit("24/7", type_247);
        SetIntPosEnterExit(enterexitid, int_pos_247[0], int_pos_247[1], int_pos_247[2], int_pos_247[3], 18, i);
        SetExtPosEnterExit(enterexitid, ext_pos_247[i][0], ext_pos_247[i][1], ext_pos_247[i][2], ext_pos_247[i][3], 0, 0);
        SetExtMapIconExterExit(enterexitid, 17);
        SetTimeOpenEnterExit(enterexitid, 9, 20);
        ToggleIntFreezeEnterExit(enterexitid, false);
        ToggleExtFreezeEnterExit(enterexitid, false);
    }
    return 1;
}

CMD:247(playerid, params[])
{
    new rand;
    if(sscanf(params,"d",rand)) return SendClientMessage(playerid, -1, "/247 [id]");
    SetPlayerPos(playerid, ENTER_EXIT[rand][ee_EXT_POS][0], ENTER_EXIT[rand][ee_EXT_POS][1], ENTER_EXIT[rand][ee_EXT_POS][2]);
    return 1;
}