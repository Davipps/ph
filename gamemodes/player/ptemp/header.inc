enum e_pt_Status
{
	state_NONE,
	state_CONNECTED,
	state_DEAD,
	state_SPAWNED
};

enum e_PlayerTemp
{
	e_pt_Status:pt_State,
	bool:pt_HungryMessage,
	bool:pt_ThirstMessage,
	pt_AreaCrew,
	pt_AreaItem,
	pt_LastPickupID,
	pt_InteriorIndex,
};
new PlayerTemp[MAX_PLAYERS][e_PlayerTemp];