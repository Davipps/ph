#define MAX_DOORS 50

enum
{
	type_NONE,
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
	type_TRUCK,
	type_POLICE_LS,
	type_POLICE_SF,
	type_POLICE_LV,
	type_ALHAMBRA,
	type_POLICE_GARAGE,
	type_HOSPITAL,
	type_CLUB,
	type_DRIVING_SCHOOL
}

enum e_DOORS
{
    sd_ID,
    sd_Name[32],
    sd_Type,

    //Datos interior puerta
    bool:sd_IntFreeze,
    sd_IntMapIcon,//ID del MapIcon
    sd_IntMapIconID,//Almacena id del MapIcon creado
    sd_IntWorld,
    sd_IntInterior,
    Float:sd_IntPos[4],
    Text3D:sd_IntLabelID,
    sd_IntPickupID,
   
    //Datos exterior puerta
    bool:sd_ExtFreeze,
    sd_ExtMapIcon,//ID del MapIcon
    sd_ExtMapIconID,//Almacena id del MapIcon creado
    sd_ExtWorld,
    sd_ExtInterior,
    Float:sd_ExtPos[4],
    Text3D:sd_ExtLabelID,
    sd_ExtPickupID,
	
    //Horario ejemplo abierto de 9 a 20 h
    // Coloca 0 para deshabilitar
    sd_TimeOpen,
    sd_TimeClose,

    sd_Actorid,
};
new Doors[MAX_DOORS][e_DOORS];