#define MAX_HOUSES          3000
#define MAX_RENGE_USE_DOOR  2.0

enum e_HouseInfo
{
    h_Id,
    h_PickupExt,
    h_PickupInt,
    Text3D: h_Text,
    h_Interior,
    h_World,
    h_Price,
    h_Owner,
    Float:h_Rot,
    bool:h_Sold,
    bool: h_lock, 
    bool:h_Valid
};
new House[MAX_HOUSES][e_HouseInfo],
    TOTAL_HOUSES;