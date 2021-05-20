#include <YSI_Coding\y_hooks>

hook OnPlayerConnect(playerid)
{
	PlayerInfo[playerid][pHungry] = 100;
	PlayerInfo[playerid][pThirst] = 100;
	return 1;
}

ptask Hungry_Thirst_Down[interval_hungry_thirst_down * 1000](playerid)
{
   	//if(PlayerTemp[playerid][pStatus] != sSpawned) return HidePlayerHud(playerid);
	PlayerInfo[playerid][pThirst] -= floatdiv(float(interval_hungry_thirst_down), floatmul(thirst_hours_stopped, 36));
	PlayerInfo[playerid][pHungry] -= floatdiv(float(interval_hungry_thirst_down), floatmul(hungry_hours_stopped, 36));
	
	if(PlayerInfo[playerid][pThirst] <= 0.5) PlayerInfo[playerid][pThirst] = 0.5;
	if(PlayerInfo[playerid][pHungry] <= 0.5) PlayerInfo[playerid][pHungry] = 0.5;
	if(PlayerInfo[playerid][pThirst] < 20.0)
	{
		PlayerInfo[playerid][pHealth] -= 0.2;
		
		if(PlayerInfo[playerid][pThirst] <= 1.0 || PlayerInfo[playerid][pHealth] <= 0.5)
		{
			SendClientMessage(playerid, -1, "Te has desmayado por deshidratación.");
			SetPlayerHealth(playerid, 0.0);
			PlayerInfo[playerid][pThirst] = 75.0;
			return 1;
		}
		
		SetPlayerHealth(playerid, PlayerInfo[playerid][pHealth]);
		
		if(!PlayerTemp[playerid][tThirst_message])
		{
			SendClientMessage(playerid, -1, "Tienes sed, si no bebes agua pronto acabarás muriendo.");
			PlayerTemp[playerid][tThirst_message] = true;
		}
	}
	
	if(PlayerInfo[playerid][pHungry] < 20.0)
	{
		PlayerInfo[playerid][pHealth] -= 0.2;
		
		if(PlayerInfo[playerid][pHungry] <= 1.0 || PlayerInfo[playerid][pHealth] <= 0.5)
		{
			SendClientMessage(playerid, -1, "Te has desmayado por hambre.");
			SetPlayerHealth(playerid, 0.0);
			PlayerInfo[playerid][pHungry] = 55.0;
			return 1;
		}
		
		SetPlayerHealth(playerid, PlayerInfo[playerid][pHealth]);
		
		if(!PlayerTemp[playerid][tHungry_message])
		{
			SendClientMessage(playerid, -1, "Tienes hambre, si no comes nada pronto acabarás muriendo.");
			PlayerTemp[playerid][tHungry_message] = true;
		}
	} 
    return 1;
}