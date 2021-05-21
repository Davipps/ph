enum e_pi_GameState
{
	state_NORMAL,
	state_HOSPITAL,
	state_INTERIOR,
	state_OWN_PROPERTY,
	state_GUEST_PROPERTY,
	state_ARRESTED,
	state_JAIL,
	state_CRACK
};

enum e_pi_Gender
{
	gender_MALE,
	gender_FEMALE,
};

enum e_PlayerInfo
{
	pi_ID,
	pi_Name[24],
	pi_Password[65],
	pi_Salt[16],
	pi_Email[32],
	pi_Admin,
	e_pi_GameState:pi_GameState,
	e_pi_Gender:pi_Gender,
	pi_Skin,
	pi_Level,
	Float:pi_Exp,
	Float:pi_Health,
	Float:pi_Hungry,
	Float:pi_Thirst,
	Float:pi_Pos[4],
	pi_InteriorID,
};
new PlayerInfo[MAX_PLAYERS][e_PlayerInfo];