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
		case MSG_INFO:strcat(string, "? INFO ? "), color = 0x00FF00FF;
		case MSG_IMPORTANT:strcat(string, "? IMPORTANTE ? "), color = 0xFFFF00FF;
		case MSG_USAGE:strcat(string, "? USO ? "), color = 0x8080FFFF;
		case MSG_WARNING:strcat(string, "? AVISO ? "), color = 0xFF8000FF;
		case MSG_ERROR:strcat(string, "? ERROR ? "), color = 0xFF3300FF;
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

	GetDynamicPickupPos(PlayerTemp[playerid][pt_LastPickupID], pos[0], pos[1], pos[2]);
	
	if(!IsPlayerInRangeOfPoint(playerid, 1.5, pos[0], pos[1], pos[2])) return 0;
	
	if(info[2] == pick_TYPE_ENTER) // Está en el Pickup Exterior y quiere ir al interior
	{
		switch(info[0])
		{
			case PICKUP_TYPE_DOORS:
			{
				if(Doors[info[1]][d_TimeOpen] == 0 && Doors[info[1]][d_TimeClose] == 0) // 24 horas
				{
					PlayerInfo[playerid][pi_InteriorID] = Doors[info[1]][d_ID];

					new int = Doors[ info[1] ][d_IntInterior];
					GetDynamicPickupPos(Ints[int][int_Pickup], pos[0], pos[1], pos[2]);
					SetPlayerPosEx(playerid, pos[0], pos[1], pos[2]+1.4, Ints[int][int_Rot], Ints[int][int_IntGame], Doors[info[1]][d_IntWorld], false, true);
				}
				else
				{
					if(is_open(GetMyWorldHour(), Doors[info[1]][d_TimeOpen], Doors[info[1]][d_TimeClose]))
					{
						PlayerInfo[playerid][pi_InteriorID] = Doors[info[1]][d_ID];
						
						new int = Doors[ info[1] ][d_IntInterior];
						GetDynamicPickupPos(Ints[int][int_Pickup], pos[0], pos[1], pos[2]);
						SetPlayerPosEx(playerid, pos[0], pos[1], pos[2]+1.4, Ints[int][int_Rot], Ints[int][int_IntGame], Doors[info[1]][d_IntWorld], false, true);				
					}
					else 
					{
						if(Doors[info[1]][d_TimeOpen] == -1 && Doors[info[1]][d_TimeOpen] == -1) 
							SendClientMessageEx(playerid, -1, "%s abrirá próximamente.", Doors[info[1]][d_Name]);
						else 
							SendClientMessageEx(playerid, -1, "%s está cerrado, su horario es: %02d:00h - %02d:00h.", Doors[info[1]][d_Name], Doors[info[1]][d_TimeOpen], Doors[info[1]][d_TimeClose]);
						return 0;
					}
				}
			}
			case PICKUP_TYPE_PROPERTY:
			{
				if(House[ info[1] ][h_lock] == true) return SendNotification(playerid, MSG_WARNING, "La puerta esta cerrada");
				PlayerInfo[playerid][pi_InteriorID] = House[ info[1] ][h_Id];

				new int = House[ info[1] ][h_Interior];
				GetDynamicPickupPos(Ints[int][int_Pickup], pos[0], pos[1], pos[2]);
				SetPlayerPosEx(playerid, pos[0], pos[1], pos[2]+1.4, Ints[int][int_Rot], Ints[int][int_IntGame], House[info[1]][h_World], false, true);	
			}
			default: return 0;
		}
		PlayerInfo[playerid][pi_GameState] = state_INTERIOR;
		PlayerTemp[playerid][pt_InteriorIndex] = info[1];
		FreezePlayer(playerid);	
	}
	return 1;
}

PlayerExitInterior(playerid)
{
	new info[3];
	
	new Float:pos[3];
	Streamer_GetArrayData(STREAMER_TYPE_PICKUP, PlayerTemp[playerid][pt_LastPickupID], E_STREAMER_EXTRA_ID, info);
	if(info[0] == PICKUP_TYPE_NONE) return 0;

	GetDynamicPickupPos(PlayerTemp[playerid][pt_LastPickupID], pos[0], pos[1], pos[2]);
	
	if(!IsPlayerInRangeOfPoint(playerid, 1.5, pos[0], pos[1], pos[2])) return 0;
	
	new id = PlayerTemp[playerid][pt_InteriorIndex];

	if(info[2] == pick_TYPE_EXIT) // Está en el Pickup Exterior y quiere ir al interior
	{
		switch(info[0])
		{
			case PICKUP_TYPE_DOORS:
			{
				GetDynamicPickupPos(Doors[id][d_ExtPickupID], pos[0], pos[1], pos[2]);
				SetPlayerPosEx(playerid, pos[0], pos[1], pos[2]+1.4, Doors[id][d_ExtRot], 0, 0, false /*Doors[info[1]][ee_EXT_FREEZE]*/);
			}
			case PICKUP_TYPE_PROPERTY:
			{
				GetDynamicPickupPos(House[id][h_PickupExt], pos[0], pos[1], pos[2]);
				SetPlayerPosEx(playerid, pos[0], pos[1], pos[2]+1.4, House[id][h_Rot], 0, 0, false /*Doors[info[1]][ee_EXT_FREEZE]*/);
			}
			default: return 0;
		}
		PlayerInfo[playerid][pi_GameState] = state_NORMAL;
		PlayerInfo[playerid][pi_InteriorID] = 0;
		PlayerTemp[playerid][pt_InteriorIndex] = -1;
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
		StopAudioStreamForPlayer(playerid);
		FreezePlayer(playerid);
	}
	else return 0;
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