#include <YSI_Coding\y_hooks>

hook OnPlayerConnect(playerid)
{
	PlayerInfo[playerid][pi_Hungry] = 100;
	PlayerInfo[playerid][pi_Thirst] = 100;
	return 1;
}

ptask Hungry_Thirst_Down[interval_hungry_thirst_down * 1000](playerid)
{
   	//if(PlayerTemp[playerid][pStatus] != sSpawned) return HidePlayerHud(playerid);
	PlayerInfo[playerid][pi_Thirst] -= floatdiv(float(interval_hungry_thirst_down), floatmul(thirst_hours_stopped, 36));
	PlayerInfo[playerid][pi_Hungry] -= floatdiv(float(interval_hungry_thirst_down), floatmul(hungry_hours_stopped, 36));
	
	if(PlayerInfo[playerid][pi_Thirst] <= 0.5) PlayerInfo[playerid][pi_Thirst] = 0.5;
	if(PlayerInfo[playerid][pi_Hungry] <= 0.5) PlayerInfo[playerid][pi_Hungry] = 0.5;
	if(PlayerInfo[playerid][pi_Thirst] < 20.0)
	{
		PlayerInfo[playerid][pi_Health] -= 0.2;
		
		if(PlayerInfo[playerid][pi_Thirst] <= 1.0 || PlayerInfo[playerid][pi_Health] <= 0.5)
		{
			SendClientMessage(playerid, -1, "Te has desmayado por deshidratación.");
			SetPlayerHealth(playerid, 0.0);
			PlayerInfo[playerid][pi_Thirst] = 75.0;
			return 1;
		}
		
		SetPlayerHealth(playerid, PlayerInfo[playerid][pi_Health]);
		
		if(!PlayerTemp[playerid][pt_ThirstMessage])
		{
			SendClientMessage(playerid, -1, "Tienes sed, si no bebes agua pronto acabarás muriendo.");
			PlayerTemp[playerid][pt_ThirstMessage] = true;
		}
	}
	
	if(PlayerInfo[playerid][pi_Hungry] < 20.0)
	{
		PlayerInfo[playerid][pi_Health] -= 0.2;
		
		if(PlayerInfo[playerid][pi_Hungry] <= 1.0 || PlayerInfo[playerid][pi_Health] <= 0.5)
		{
			SendClientMessage(playerid, -1, "Te has desmayado por hambre.");
			SetPlayerHealth(playerid, 0.0);
			PlayerInfo[playerid][pi_Hungry] = 55.0;
			return 1;
		}
		
		SetPlayerHealth(playerid, PlayerInfo[playerid][pi_Health]);
		
		if(!PlayerTemp[playerid][pt_HungryMessage])
		{
			SendClientMessage(playerid, -1, "Tienes hambre, si no comes nada pronto acabarás muriendo.");
			PlayerTemp[playerid][pt_HungryMessage] = true;
		}
	} 
    return 1;
}