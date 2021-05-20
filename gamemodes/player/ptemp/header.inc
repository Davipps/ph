enum e_pStatus
{
	sNone,
	sConnected,
	sDead,
	sSpawned
};

enum e_PlayerTemp
{
	e_pStatus:tStatus,
	bool:tHungry_message,
	bool:tThirst_message,
	pAreaCrew,
	pAreaItem,
	pPickup,
};
new PlayerTemp[MAX_PLAYERS][e_PlayerTemp];