#define MAX_ENTER_EXIST 50
new total_EnterExits=-1;

enum
{
	type_NO_INFO,
	type_BINCO,
	type_SUBURBAN,
	type_PROLAPS,
	type_DIDIER_SACHS,
	type_VICTIM,
	type_ZIP,
	type_247,
	type_PIZZA,
	type_CLUCKIN_BELL,
	type_BURGER_SHOT,
	type_BANK_LS,
	type_BANK_SF,
	type_BANK_LV,
	type_CITY_HALL_LS,
	type_UNITY_STATION,
	type_POLICE_LS,
	type_POLICE_SF,
	type_POLICE_LV,
	type_ALHAMBRA,
	type_POLICE_GARAGE,
	type_HOSPITAL,
	type_CLUB
};

enum Enter_Exits
{
	ee_ID,
	ee_NAME[32],
	
	ee_TYPE,
	
	ee_INT_FREEZE,
	ee_INT_WORLD,
	ee_INT_INTERIOR,
	Float:ee_INT_POS[4], //posicion del interior con angulos del player
	
	ee_EXT_MAPICON,
	ee_EXT_FREEZE,
	ee_EXT_WORLD,
	ee_EXT_INTERIOR,
	Float:ee_EXT_POS[4],//posicion del exterior con angulos del player
	
	ee_TIME_OPEN,
	ee_TIME_CLOSE,
	
	ee_INT_MAPICON_ID,
	ee_EXT_MAPICON_ID,
	Text3D:ee_INT_LABEL_ID,
	Text3D:ee_EXT_LABEL_ID,
	
	ee_INT_PICKUP_ID,
	ee_EXT_PICKUP_ID,

	ee_INT_ACTOR_ID,
	ee_INT_ACTOR_SKIN,
	ee_INT_ACTOR_WORLD,
	ee_INT_ACTOR_INTERIOR,
	Float:ee_INT_ACTOR_POS[4],
};
new ENTER_EXIT[MAX_ENTER_EXIST][Enter_Exits];


forward CreateEnterExit(const name[], type); // Crea un enterexit y retorna la id del enterexit
forward SetIntPosEnterExit(enterexitid, Float:posx, Float:posy, Float:posz, Float:angle, world, interior); // Cambia la posicion interior de un enter_exit
forward SetExtPosEnterExit(enterexitid, Float:posx, Float:posy, Float:posz, Float:angle, world, interior); // Cambia la posicion exterior de un exter_exit
forward SetExtMapIconExterExit(enterexitid, mapiconid); // Cambia el mapicon del exterior de un exter_exit
forward SetTimeOpenEnterExit(enterexitid, open, close); // Cambia el tiempo de abierto y cerrado de un enter_exit ejemplo abierto de 9 a 20 SetTimeOpenEnterExit(enterexitid, 9, 20);
forward ToggleIntFreezeEnterExit(enterexitid, bool:freeze); // Activa para congelar unos segundos el player al entrar
forward ToggleExtFreezeEnterExit(enterexitid, bool:freeze); // Activa para congelar unos segundos el player al salir
forward CreateActorEnterExit(enterexitid, skin, Float:posx, Float:posy, Float:posz, Float:angle); // Crea actor enter_exit