public Give_Hungry_Thirst(playerid, Float:hungry, Float:thirst)
{
    PlayerInfo[playerid][pHungry]+=hungry;
    PlayerInfo[playerid][pThirst]+=thirst;
    printf("Debug: Give_Hungry_Thirst(playerid, %f, %f)", hungry, thirst);
    return 1;
}