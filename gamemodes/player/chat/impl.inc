hook OnPlayerText(playerid, text[])
{
	if(PlayerTemp[playerid][pt_State] == state_SPAWNED)
	{
		new str[256], bool:phone, drunk_level = GetPlayerDrunkLevel(playerid),
		Float:pos[3], current_vw = GetPlayerVirtualWorld(playerid), current_int = GetPlayerInterior(playerid);
	    GetPlayerPos(playerid, pos[0], pos[1], pos[2]);

        //if(phone) //aca format si tiene telefono
		if(drunk_level > 2000) format(str, sizeof str, "dice ebrio: %s", text);
		else format(str, sizeof str, "dice: %s", text);

        foreach(new i : Player)
        {
            if(GetPlayerVirtualWorld(i) != current_vw) continue;
            if(GetPlayerInterior(i) != current_int) continue;
            
            if(IsPlayerInRangeOfPoint(i, 15.0, pos[0], pos[1], pos[2]))
            {
                SendClientMessage(i, -1, str);
            }
        }
		SetPlayerChatBubble(playerid, str, 0xFFFFFFFF, 15.0, 5000);
	}
	return 0;
}