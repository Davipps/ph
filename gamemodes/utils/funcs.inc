//Functions
IsValidName(const string[])
{
	new Regex:reg_exp = Regex_New("[A-Z][a-z]+_[A-Z][a-z]{1,3}[A-Z]?[a-z]*");
	new result = Regex_Check(string, reg_exp);
	Regex_Delete(reg_exp);
	return result;
}

IsValidEmail(const string[])
{
	new Regex:reg_exp = Regex_New("[a-zA-Z0-9_\\.]+@([a-zA-Z0-9\\-]+\\.)+[a-zA-Z]{2,4}"); 
	new result = Regex_Check(string, reg_exp); 
	Regex_Delete(reg_exp); 
	return result; 
}

ShowDialogInfo(playerid, dialogid, const caption[], const info[])
{
	ShowPlayerDialog(playerid, dialogid, DIALOG_STYLE_MSGBOX, caption, info, "Aceptar", "");
	return 1;
}

getRandomText(text[], length = sizeof text)
{
    for(new i = 0; i != length; i ++)
	{
		text[i] = random(2) ? (random(26) + (random(2) ? 'a' : 'A')) : (random(10) + '0');
	}
	return true;
}

minrand(min, max) //By Alex "Y_Less" Cole
{
	return random(max - min) + min;
}

SendClientMessageEx(playerid, color, const form[], {Float, _}:...) {
    new string[145];
	format(string, sizeof(string), form, ___(3));
    return (playerid == -1 ? (SendClientMessageToAll(color, string)) : (SendClientMessage(playerid, color, string)) );
}

SendNotification(playerid, Notif_Type:type, const message[]){
	new color = -1, string[256 char];
	switch(type)
	{
		case MSG_INFO:strcat(string, "« INFO » "), color = 0x00FF00FF;
		case MSG_IMPORTANT:strcat(string, "« IMPORTANTE » "), color = 0xFFFF00FF;
		case MSG_USE:strcat(string, "« USO » "), color = 0x8080FFFF;
		case MSG_WARNING:strcat(string, "« AVISO » "), color = 0xFF8000FF;
		case MSG_ERROR:strcat(string, "« ERROR » "), color = 0xFF3300FF;
	}
	strcat(string, message);
	return SendClientMessage(playerid, color, string);
}

PlayerEnterInterior(playerid)
{
	new info[3];
	
	new Float:pos[3];
	Streamer_GetArrayData(STREAMER_TYPE_PICKUP, PlayerTemp[playerid][pt_LastPickupID], E_STREAMER_EXTRA_ID, info);
	if(info[0] == PICKUP_TYPE_NONE) return 0;

	Streamer_GetFloatData(STREAMER_TYPE_PICKUP, PlayerTemp[playerid][pt_LastPickupID], E_STREAMER_X, pos[0]);
	Streamer_GetFloatData(STREAMER_TYPE_PICKUP, PlayerTemp[playerid][pt_LastPickupID], E_STREAMER_Y, pos[1]);
	Streamer_GetFloatData(STREAMER_TYPE_PICKUP, PlayerTemp[playerid][pt_LastPickupID], E_STREAMER_Z, pos[2]);
	
	if(!IsPlayerInRangeOfPoint(playerid, 1.5, pos[0], pos[1], pos[2])) return 0;
	

	switch(info[0])
	{
		case PICKUP_TYPE_DOORS:
		{
			if(info[2] == pick_TYPE_ENTER) // EstÃ¡ en el Pickup Exterior y quiere ir al interior
			{
				if(Doors[info[1]][d_TimeOpen] == 0 && Doors[info[1]][d_TimeClose] == 0) // 24 horas
				{
					PlayerInfo[playerid][pi_GameState] = state_INTERIOR;
					PlayerInfo[playerid][pi_InteriorID] = Doors[info[1]][d_ID];
					PlayerTemp[playerid][pt_InteriorIndex] = info[1];
					SetPlayerPosEx(playerid, Doors[info[1]][d_IntPos][0], Doors[info[1]][d_IntPos][1], Doors[info[1]][d_IntPos][2], Doors[info[1]][d_IntPos][3], Doors[info[1]][d_IntInterior], Doors[info[1]][d_IntWorld], false, true);
					FreezePlayer(playerid);
				}
				else
				{
					if(is_open(GetMyWorldHour(), Doors[info[1]][d_TimeOpen], Doors[info[1]][d_TimeClose]))
					{
						PlayerInfo[playerid][pi_GameState] = state_INTERIOR;
						PlayerInfo[playerid][pi_InteriorID] = Doors[info[1]][d_ID];
						PlayerTemp[playerid][pt_InteriorIndex] = info[1];
						SetPlayerPosEx(playerid, Doors[info[1]][d_IntPos][0], Doors[info[1]][d_IntPos][1], Doors[info[1]][d_IntPos][2], Doors[info[1]][d_IntPos][3], Doors[info[1]][d_IntInterior], Doors[info[1]][d_IntWorld], false, true);
						FreezePlayer(playerid);					
					}
					else {
						if(Doors[info[1]][d_TimeOpen] == -1 && Doors[info[1]][d_TimeOpen] == -1) SendClientMessageEx(playerid, -1, "%s abrirÃ¡ prÃ³ximamente.", Doors[info[1]][d_Name]);
						else SendClientMessageEx(playerid, -1, "%s estÃ¡ cerrado, su horario es: %02d:00h - %02d:00h.", Doors[info[1]][d_Name], Doors[info[1]][d_TimeOpen], Doors[info[1]][d_TimeClose]);
					}
				}
				return 1;
			}
			else return 0;
		}
		default: return 0;
	}
	return 1;
}

PlayerExitInterior(playerid)
{
	new info[3];
	
	new Float:pos[3];
	Streamer_GetArrayData(STREAMER_TYPE_PICKUP, PlayerTemp[playerid][pt_LastPickupID], E_STREAMER_EXTRA_ID, info);
	if(info[0] == PICKUP_TYPE_NONE) return 0;

	Streamer_GetFloatData(STREAMER_TYPE_PICKUP, PlayerTemp[playerid][pt_LastPickupID], E_STREAMER_X, pos[0]);
	Streamer_GetFloatData(STREAMER_TYPE_PICKUP, PlayerTemp[playerid][pt_LastPickupID], E_STREAMER_Y, pos[1]);
	Streamer_GetFloatData(STREAMER_TYPE_PICKUP, PlayerTemp[playerid][pt_LastPickupID], E_STREAMER_Z, pos[2]);
	
	if(!IsPlayerInRangeOfPoint(playerid, 1.0, pos[0], pos[1], pos[2])) return 0;
	

	switch(info[0])
	{
		case PICKUP_TYPE_DOORS:
		{
			if(info[2] == pick_TYPE_EXIT) // EstÃ¡ en el Pickup Exterior y quiere ir al interior
			{
				PlayerInfo[playerid][pi_GameState] = state_NORMAL;
				PlayerInfo[playerid][pi_InteriorID] = 0;
				PlayerTemp[playerid][pt_InteriorIndex] = -1;
				SetPlayerPosEx(playerid, Doors[info[1]][d_ExtPos][0], Doors[info[1]][d_ExtPos][1], Doors[info[1]][d_ExtPos][2], Doors[info[1]][d_ExtPos][3], Doors[info[1]][d_ExtInterior], Doors[info[1]][d_ExtWorld], false /*Doors[info[1]][ee_EXT_FREEZE]*/);
				SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
				StopAudioStreamForPlayer(playerid);
				FreezePlayer(playerid);
				return 1;
			}
			else return 0;
		}
		default: return 0;
	}
	return 1;
}

SetPlayerPosEx(playerid, Float:x, Float:y, Float:z, Float:angle, interior, world, freeze = 0, addoffset = 0)
{
	if(addoffset)
	{
		x += (1.5 * floatsin(-angle, degrees));
		y += (1.5 * floatcos(-angle, degrees));
	}
	
	PlayerInfo[playerid][pi_Pos][0] = x;
	PlayerInfo[playerid][pi_Pos][1] = y;
	PlayerInfo[playerid][pi_Pos][2] = z;
	PlayerInfo[playerid][pi_Pos][3] = angle;
	
	SetPlayerPos(playerid, x, y, z);
	SetPlayerFacingAngle(playerid, angle);
	SetPlayerInterior(playerid, interior);
	SetPlayerVirtualWorld(playerid, world);
	SetCameraBehindPlayer(playerid);
	
	if(freeze)
	{
		TogglePlayerControllable(playerid, false);
		defer TogglePlayerControl(playerid, true);
	}
	return 1;
}

FreezePlayer(playerid)
{
	TogglePlayerControllable(playerid, false);
	defer TogglePlayerControl(playerid, true);
	return 1;
}

timer TogglePlayerControl[2000](playerid, bool:controlable)
{
	return TogglePlayerControllable(playerid, controlable);
}

is_open(hour, open, close)
{
	if(open < 0 || close < 0) return false;
	if(open > close)
	{
		if(((hour >= open) && (hour < 24)) || ((hour >= 0) && (hour < close))) return true;
		else return false;
	}
	else if(open < close)
	{
		if((hour >= open) && (hour < close)) return true;
		else return false;
	}
	return false;
}

stock TimeConvert(seconds)
{
	new tmp[16];
 	new minutes = floatround(seconds/60);
  	seconds -= minutes*60;
   	format(tmp, sizeof(tmp), "%d:%02d", minutes, seconds);
   	return tmp;
}