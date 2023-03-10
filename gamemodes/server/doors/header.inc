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
	type_POLICE_LS,
	type_POLICE_SF,
	type_POLICE_LV,
	type_ALHAMBRA,
	type_POLICE_GARAGE,
	type_HOSPITAL,
	type_CLUB,
	type_DRIVING_SCHOOL
}

enum e_Doors
{
    d_ID,
    d_Name[32],
    d_Type,

    //Datos interior puerta
    bool:d_IntFreeze,
    d_IntWorld,
    d_IntInterior,
    Text3D:d_IntLabelID,
    d_IntPickupID,
   
    //Datos exterior puerta
    bool:d_ExtFreeze,
    d_ExtMapIcon,//ID del MapIcon
    d_ExtMapIconID,//Almacena id del MapIcon creado
    Float:d_ExtRot,
    Text3D:d_ExtLabelID,
    d_ExtPickupID,
	
    //Horario ejemplo abierto de 9 a 20 h
    // Coloca 0 para deshabilitar
    d_TimeOpen,
    d_TimeClose,

    d_Actorid,
    bool:d_Valid
};
new Doors[MAX_DOORS][e_Doors],
    TOTAL_DOORS;