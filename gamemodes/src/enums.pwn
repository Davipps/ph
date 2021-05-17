//Enumerators
enum //Dialog id's
{
	DIALOG_NONE,
	DIALOG_REGISTER, DIALOG_REGISTER_EMAIL, DIALOG_REGISTER_SEX, //Dialogs registers
	DIALOG_LOGIN,
	DIALOG_HELP,
};

enum e_WorldTime
{
	wSeconds,
	wMinutes,
	wHour	
};
new WorldTime[e_WorldTime];

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
	pName,
	pPassword[65],
	pSalt[16],
	pEmail[32],
	pAdmin,
	e_Gender:pGender,
	e_pStatus:pStatus,
	pSkin,
	pLevel,
	Float:pExp
};
new PlayerInfo[MAX_PLAYERS][e_PlayerInfo];

enum e_PlayerTemp
{
	tPassword[65],
};
new PlayerTemp[MAX_PLAYERS][e_PlayerTemp];

enum e_VehInfo
{
	vEngine,
	vLights,
	vAlarm,
	vDoors,
}
new VehInfo[MAX_VEHICLES][e_VehInfo];