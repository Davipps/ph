#define DIALOG_INFO 0

/* Colores RBGA */
#define WHITE			"{ffffff}"
#define BLUE			"{0000ff}"
#define PURPLE			"{cc00ff}"
#define PINK			"{ff00dd}"
#define RED				"{ff0000}"
#define ORANGE			"{ffaa00}"
#define YELLOW			"{ffff00}"
#define GREEN			"{00cc00}"
#define PRIMARY_COLOR	"{00ff00}"
#define CYAN            "{00ffff}"

new NO_PARAMS[4] = "";

// HOLDING(keys)
#define HOLDING(%0) \
	((newkeys & (%0)) == (%0))

// PRESSED(keys)
#define PRESSED(%0) \
	(((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))

// RELEASED(keys)
#define RELEASED(%0) \
	(((newkeys & (%0)) != (%0)) && ((oldkeys & (%0)) == (%0)))

//
enum
{
	ADMIN_LEVEL_NONE,
	ADMIN_LEVEL_HELPER,
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

enum
{
	PICKUP_TYPE_NONE = 0,
	PICKUP_TYPE_DOORS,
	PICKUP_TYPE_ATM,
	PICKUP_TYPE_PROPERTY
};

enum //Type pickup door
{
	pick_TYPE_ENTER,
	pick_TYPE_EXIT
};

enum Notif_Type
{
	MSG_INFO,
	MSG_IMPORTANT,
	MSG_USE,
	MSG_WARNING,
	MSG_ERROR
}