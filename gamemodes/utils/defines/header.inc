// HOLDING(keys)
#define HOLDING(%0) \
	((newkeys & (%0)) == (%0))

// PRESSED(keys)
#define PRESSED(%0) \
	(((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))

// RELEASED(keys)
#define RELEASED(%0) \
	(((newkeys & (%0)) != (%0)) && ((oldkeys & (%0)) == (%0)))


#define HidePlayerDialog(%1)		ShowPlayerDialog(%1, -1, 0, " ", " ", " ", " ")

//
enum
{
	ADMIN_LEVEL_NONE,
	ADMIN_LEVEL_MODERATOR,
	ADMIN_LEVEL_ADMINISTRATOR,
	ADMIN_LEVEL_DEVELOPER,
	MAX_ADMIN_LEVELS
};
//

enum _:areaType //Tipos de DynamicAreas del server
{
	AREA_TYPE_NONE,
	AREA_TYPE_ITEM,
	AREA_TYPE_CREW //para este falta el sistema de clanes XD
}