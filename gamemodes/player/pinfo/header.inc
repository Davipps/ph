enum e_Gender
{
	gMale,
	gFemale,
};

enum e_PlayerInfo
{
	pID,
	pName[24],
	pPassword[65],
	pSalt[16],
	pEmail[32],
	pAdmin,
	e_Gender:pGender,
	pSkin,
	pLevel,
	Float:pExp,
	Float:pHealth,
	pAreaCrew,
	pAreaItem,
	Float:pHungry,
	Float:pThirst,
};
new PlayerInfo[MAX_PLAYERS][e_PlayerInfo];