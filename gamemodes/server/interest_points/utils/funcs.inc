public CreateEnterExit(const name[], type)
{
    total_EnterExits++;
    ENTER_EXIT[total_EnterExits][ee_ID] = total_EnterExits;
    format(ENTER_EXIT[total_EnterExits][ee_NAME],32,"%s",name);
    ENTER_EXIT[total_EnterExits][ee_TYPE] = type;
    return total_EnterExits;
}

public SetIntPosEnterExit(enterexitid, Float:posx, Float:posy, Float:posz, Float:angle, world, interior)
{
    ENTER_EXIT[enterexitid][ee_INT_POS][0] = posx;
    ENTER_EXIT[enterexitid][ee_INT_POS][1] = posy;
    ENTER_EXIT[enterexitid][ee_INT_POS][2] = posz;
    ENTER_EXIT[enterexitid][ee_INT_POS][3] = angle;
    ENTER_EXIT[enterexitid][ee_INT_WORLD] = world;
    ENTER_EXIT[enterexitid][ee_INT_INTERIOR] = interior;
    return 1;
}

public SetExtPosEnterExit(enterexitid, Float:posx, Float:posy, Float:posz, Float:angle, world, interior)
{
    ENTER_EXIT[enterexitid][ee_EXT_POS][0] = posx;
    ENTER_EXIT[enterexitid][ee_EXT_POS][1] = posy;
    ENTER_EXIT[enterexitid][ee_EXT_POS][2] = posz;
    ENTER_EXIT[enterexitid][ee_EXT_POS][3] = angle;
    ENTER_EXIT[enterexitid][ee_EXT_WORLD] = world;
    ENTER_EXIT[enterexitid][ee_EXT_INTERIOR] = interior;
    return 1;
}

public SetExtMapIconExterExit(enterexitid, mapiconid)
{
    ENTER_EXIT[enterexitid][ee_EXT_MAPICON] = mapiconid;
    return 1;
}

public SetTimeOpenEnterExit(enterexitid, open, close)
{
    ENTER_EXIT[enterexitid][ee_TIME_OPEN] = open;
    ENTER_EXIT[enterexitid][ee_TIME_CLOSE] = close;
    return 1;
}

public ToggleIntFreezeEnterExit(enterexitid, bool:freeze)
{
    ENTER_EXIT[enterexitid][ee_INT_FREEZE] = freeze;
    return 1;
}

public ToggleExtFreezeEnterExit(enterexitid, bool:freeze)
{
    ENTER_EXIT[enterexitid][ee_EXT_FREEZE] = freeze;
    return 1;
}

public CreateActorEnterExit(enterexitid, skin, Float:posx, Float:posy, Float:posz, Float:angle)
{
    if(ENTER_EXIT[enterexitid][ee_TYPE] == type_NO_INFO) return 1;
    ENTER_EXIT[enterexitid][ee_INT_ACTOR_ID] = CreateDynamicActor
    (
        ENTER_EXIT[enterexitid][ee_INT_ACTOR_SKIN], 
        ENTER_EXIT[enterexitid][ee_INT_ACTOR_POS][0], 
        ENTER_EXIT[enterexitid][ee_INT_ACTOR_POS][1], 
        ENTER_EXIT[enterexitid][ee_INT_ACTOR_POS][2],
        ENTER_EXIT[enterexitid][ee_INT_ACTOR_POS][3], 
        true, 
        100.0, 
        ENTER_EXIT[enterexitid][ee_INT_WORLD],
        ENTER_EXIT[enterexitid][ee_INT_INTERIOR]
    );
    return 1;
}

LoadEnterExits()
{
	new total_enterexits, label_str[256], info[3];
		
	for(new i = 0; i != total_EnterExits; i ++)
	{
		ENTER_EXIT[total_enterexits][ee_ID] = total_enterexits + 1;

		if(ENTER_EXIT[total_enterexits][ee_TIME_OPEN] == 0 && ENTER_EXIT[total_enterexits][ee_TIME_CLOSE] == 0) format(label_str, sizeof label_str, ""PRIMARY_COLOR"%s\n\n"WHITE"Escribe "PRIMARY_COLOR"/entrar "WHITE"para entrar", ENTER_EXIT[total_enterexits][ee_NAME]);
		else format(label_str, sizeof label_str, ""PRIMARY_COLOR"%s\n"WHITE"Horario: "PRIMARY_COLOR"%02d:00 - %02d:00\n\n"WHITE"Escribe "PRIMARY_COLOR"/entrar "WHITE"para entrar", ENTER_EXIT[total_enterexits][ee_NAME], ENTER_EXIT[total_enterexits][ee_TIME_OPEN], ENTER_EXIT[total_enterexits][ee_TIME_CLOSE]);
		
		ENTER_EXIT[total_enterexits][ee_INT_LABEL_ID] = CreateDynamic3DTextLabel("{FF6633}SALIDA\n"WHITE"Escribe "PRIMARY_COLOR"/salir "WHITE"para salir", 0xFFFFFFFF, ENTER_EXIT[total_enterexits][ee_INT_POS][0], ENTER_EXIT[total_enterexits][ee_INT_POS][1], ENTER_EXIT[total_enterexits][ee_INT_POS][2] + 0.25, 10.0, .testlos = true, .worldid = ENTER_EXIT[total_enterexits][ee_INT_WORLD], .interiorid = ENTER_EXIT[total_enterexits][ee_INT_INTERIOR]);
		ENTER_EXIT[total_enterexits][ee_EXT_LABEL_ID] = CreateDynamic3DTextLabel(label_str, 0xFFFFFFFF, ENTER_EXIT[total_enterexits][ee_EXT_POS][0], ENTER_EXIT[total_enterexits][ee_EXT_POS][1], ENTER_EXIT[total_enterexits][ee_EXT_POS][2] + 0.25, 10.0, .testlos = true, .worldid = ENTER_EXIT[total_enterexits][ee_EXT_WORLD], .interiorid = ENTER_EXIT[total_enterexits][ee_EXT_INTERIOR]);
		
		if(ENTER_EXIT[total_enterexits][ee_EXT_MAPICON] != -1) ENTER_EXIT[total_enterexits][ee_EXT_MAPICON_ID] = CreateDynamicMapIcon(ENTER_EXIT[total_enterexits][ee_EXT_POS][0], ENTER_EXIT[total_enterexits][ee_EXT_POS][1], ENTER_EXIT[total_enterexits][ee_EXT_POS][2], ENTER_EXIT[total_enterexits][ee_EXT_MAPICON], -1, ENTER_EXIT[total_enterexits][ee_EXT_WORLD], ENTER_EXIT[total_enterexits][ee_EXT_INTERIOR]);
		
		ENTER_EXIT[total_enterexits][ee_INT_PICKUP_ID] = CreateDynamicPickup(0, 1, ENTER_EXIT[total_enterexits][ee_INT_POS][0], ENTER_EXIT[total_enterexits][ee_INT_POS][1], ENTER_EXIT[total_enterexits][ee_INT_POS][2], ENTER_EXIT[total_enterexits][ee_INT_WORLD], ENTER_EXIT[total_enterexits][ee_INT_INTERIOR]);
		ENTER_EXIT[total_enterexits][ee_EXT_PICKUP_ID] = CreateDynamicPickup(19902, 1, ENTER_EXIT[total_enterexits][ee_EXT_POS][0], ENTER_EXIT[total_enterexits][ee_EXT_POS][1], ENTER_EXIT[total_enterexits][ee_EXT_POS][2] - 1.0, ENTER_EXIT[total_enterexits][ee_EXT_WORLD], ENTER_EXIT[total_enterexits][ee_EXT_INTERIOR]);
		
		info[0] = PICKUP_TYPE_ENTER_EXIT;
		info[1] = total_enterexits; // Index
		info[2] = 1; // Pickup Interior
		Streamer_SetArrayData(STREAMER_TYPE_PICKUP, ENTER_EXIT[total_enterexits][ee_INT_PICKUP_ID], E_STREAMER_EXTRA_ID, info);
		
		info[0] = PICKUP_TYPE_ENTER_EXIT;
		info[1] = total_enterexits; // Index
		info[2] = 2; // Pickup Exterior
		Streamer_SetArrayData(STREAMER_TYPE_PICKUP, ENTER_EXIT[total_enterexits][ee_EXT_PICKUP_ID], E_STREAMER_EXTRA_ID, info);
		//CreateInteriorActor(ENTER_EXIT[total_enterexits][ee_INTERIOR_TYPE], ENTER_EXIT[total_enterexits][ee_INT_WORLD], ENTER_EXIT[total_enterexits][ee_INT_INTERIOR]);
		
		total_enterexits ++;
	}
	return 1;
}