public Give_Hungry_Thirst(playerid, Float:hungry, Float:thirst)
{
    PlayerInfo[playerid][pi_Hungry]+=hungry;
    PlayerInfo[playerid][pi_Thirst]+=thirst;
    printf("Debug: Give_Hungry_Thirst(playerid, %f, %f)", hungry, thirst);
    return 1;
}