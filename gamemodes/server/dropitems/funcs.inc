CreateDropItem(itemid, ammon, Float:X, Float:Y, Float:Z, world, interior)
{
	//if(!IsValidWeapon(weaponid))return -1;
	if(ammon <= 0 || itemid >= sizeof(d_Items) || itemid <= 0)return -1;
	new a = GetFreeSlotItemDrop();
	if(a == -1)return -1;
	d_Items[a][dit_object] = itemid;
	d_Items[a][dit_ammon] = ammon;
	d_Items[a][dit_ID] = CreateDynamicObject(items[itemid][it_object], X, Y, Z-1, 93.7, 120.0, 120.0, world, interior);
	d_Items[a][dit_area] = CreateDynamicCylinder(X, Y, Z-2, Z+2, 1.0, world, interiointeriorrid);
	new info[2];
	info[0] = AREA_TYPE_ITEM;
	info[1] = a;
	Streamer_SetArrayData(STREAMER_TYPE_AREA, d_Items[a][dit_area], E_STREAMER_EXTRA_ID, info);
	d_Items[a][dit_valid] = true;
	TOTAL_DROPS++;
	return a;
}

GetFreeSlotItemDrop()
{
	for(new i = 0; i < TOTAL_DROPS; i++) if(!d_Items[i][dit_valid])return i;
	if(TOTAL_DROPS == MAX_DROPS_ITEMS)return -1;
	new id = TOTAL_DROPS;
	TOTAL_DROPS++;
	return id;
}

IsValidDropItem(itemid)
{
	if(itemid >= MAX_DROPS_ITEMS)return 0;
	if(d_Items[itemid][dit_valid] == false)return 0;
	return 1;
}

GivePlayerItemDrop(playerid, itemid, bool:destroy = true)
{
	if(!IsValidDynamicArea(itemid))return -1;
	new info[2];
	Streamer_GetArrayData(STREAMER_TYPE_AREA, itemid, E_STREAMER_EXTRA_ID, info);
	if(info[0] == AREA_TYPE_ITEM && IsPlayerInDynamicArea(playerid, itemid, 1) && IsValidDropItem(info[1])){
		new ammon,
			weaponid,
			slot = items[ d_Items[ info[1] ][dit_object] ][it_slot];
		if(slot && slot != -1){
			GetPlayerWeaponData(playerid, slot, weaponid, ammon);
			if(weaponid > 0 && ammon > 0){
				if(weaponid != d_Items[ info[1] ][dit_object]) PlayerItemDrop(playerid, weaponid);	
			}
		}
		if(IsValidWeapon( d_Items[ info[1] ][dit_object] )) GivePlayerWeapon(playerid, d_Items[ info[1] ][dit_object], d_Items[ info[1] ][dit_ammon]);
		//SendClientMessageEx(playerid, -1, "** Recogiste un(a) %s",WEAPONS[ d_Items[ info[1] ][dit_object] ][WD_NAME]);
		
		if(destroy) DestroyDropItem(info[1]);
		return info[1];
	}
	return -1;
}

PlayerItemDrop(playerid, itemid)
{
	if(IsValidWeapon(itemid)){
		new ammon,tmp;
		GetPlayerWeaponData(playerid, items[itemid][it_slot], tmp, ammon);
		if(ammon > 0){
			new Float:dat[3];
			GetPlayerPos(playerid, dat[0], dat[1], dat[2]);
			new a = CreateDropItem(tmp, ammon, dat[0], dat[1], dat[2], GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid));
			if(a == -1) return -1;
			SetPlayerAmmo(playerid, tmp, 0);
			return a;
		}
        return -1;
	}
    new Float:dat[3];
    GetPlayerPos(playerid, dat[0], dat[1], dat[2]);
    new a = CreateDropItem(itemid, 1, dat[0], dat[1], dat[2], GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid));
    if(a == -1) return -1;
	return -1;
}

DestroyDropItem(itemid)
{
	if(!IsValidDropItem(itemid))return 0;
	DestroyDynamicObject(d_Items[itemid][dit_ID]);
	DestroyDynamicArea(d_Items[itemid][dit_area]);
	new tmp[dItemInfo]; d_Items[itemid] = tmp;
	return 1;
}