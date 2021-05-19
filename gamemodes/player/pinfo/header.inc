enum e_pStatus
{
	sNone,
	sConnected,
	sDead,
	sSpawned
};

enum e_Gender
{
	gMale,
	gFemale
}

enum e_PlayerInfo
{
	pID,
	pName[24],
	pPassword[65],
	pSalt[16],
	pEmail[32],
	pAdmin,
	e_Gender:pGender,
	e_pStatus:pStatus,
	pSkin,
	pLevel,
	Float:pExp,
	Float:pHungry,
	Float:pThirst,
};
new PlayerInfo[MAX_PLAYERS][e_PlayerInfo];

enum e_PlayerTemp
{
	tPassword[65],
};
new PlayerTemp[MAX_PLAYERS][e_PlayerTemp];