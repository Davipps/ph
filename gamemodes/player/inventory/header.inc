#define PLAYER_INV_MAX_SLOTS 25

enum enum_PlayerInv
{
	pinv_ID,
	pinv_ItemID,
	pinv_Ammount,
	pinv_Params[128]
};

new PlayerInv[MAX_PLAYERS][PLAYER_INV_MAX_SLOTS][enum_PlayerInv],
	Iterator:PlayerInv[MAX_PLAYERS]<PLAYER_INV_MAX_SLOTS>,