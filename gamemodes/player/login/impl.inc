#include <YSI_Coding\y_hooks>

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case DIALOG_LOGIN:
		{
			if(!response) return Kick(playerid);
			if(!strlen(inputtext)) return ShowPlayerDialogEx(playerid, dialogid);
			
			new passhash[64 + 1];
			SHA256_PassHash(inputtext, PlayerInfo[playerid][pSalt], passhash, sizeof passhash);
			if(!strcmp(passhash, PlayerInfo[playerid][pPassword], false))
			{
				LoadPlayerData(playerid);
				SetPlayerVirtualWorld(playerid,0);
				SetPlayerInterior(playerid,0);
				SetSpawnInfo(playerid, NO_TEAM, PlayerInfo[playerid][pSkin], DefaultPos[0], DefaultPos[1], DefaultPos[2], 0.0, 0, 0, 0, 0, 0, 0);
				TogglePlayerSpectating(playerid, false);
				return 1;
			}
			return 1;
		}
    }
    return 1;
}