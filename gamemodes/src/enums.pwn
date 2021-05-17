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

enum e_PlayerInfo
{
	pID,
	pName,
	pPassword[65],
	pAdmin,
	pGender,
	e_pStatus:pStatus,
	pSkin,
	pLevel,
	pReputation
};
new PlayerInfo[MAX_PLAYERS][e_PlayerInfo];

enum e_VehInfo
{
	vEngine,
	vLights,
	vAlarm,
	vDoors,
}
new VehInfo[MAX_VEHICLES][e_VehInfo];