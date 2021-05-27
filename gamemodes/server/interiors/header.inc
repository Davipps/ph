#define MAX_INTERIORS 100

enum e_intInfo
{
    int_Id,
    int_Type,
    int_IntGame,
    int_Pickup,
    int_Name[60],
    Float:int_Rot,
    Text3D:int_Text,
    bool:int_Valid
}
new Ints[MAX_INTERIORS][e_intInfo],
    TOTAL_INTERIORS;