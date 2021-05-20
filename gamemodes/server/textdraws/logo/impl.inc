#include <YSI_Coding\y_hooks>

hook OnScriptInit()
{
    LogoTD[0] = TextDrawCreate(555.000000, 0.000000, "ld_beat:cring");
    TextDrawFont(LogoTD[0], 4);
    TextDrawLetterSize(LogoTD[0], 0.600000, 2.000000);
    TextDrawTextSize(LogoTD[0], 19.000000, 23.000000);
    TextDrawSetOutline(LogoTD[0], 1);
    TextDrawSetShadow(LogoTD[0], 0);
    TextDrawAlignment(LogoTD[0], 1);
    TextDrawColor(LogoTD[0], -16711681);
    TextDrawBackgroundColor(LogoTD[0], 255);
    TextDrawBoxColor(LogoTD[0], 50);
    TextDrawUseBox(LogoTD[0], 1);
    TextDrawSetProportional(LogoTD[0], 1);
    TextDrawSetSelectable(LogoTD[0], 0);

    LogoTD[1] = TextDrawCreate(572.000000, 4.000000, "pera");
    TextDrawFont(LogoTD[1], 1);
    TextDrawLetterSize(LogoTD[1], 0.304166, 1.649999);
    TextDrawTextSize(LogoTD[1], 400.000000, 17.000000);
    TextDrawSetOutline(LogoTD[1], 1);
    TextDrawSetShadow(LogoTD[1], 1);
    TextDrawAlignment(LogoTD[1], 1);
    TextDrawColor(LogoTD[1], -16746241);
    TextDrawBackgroundColor(LogoTD[1], 57);
    TextDrawBoxColor(LogoTD[1], 50);
    TextDrawUseBox(LogoTD[1], 0);
    TextDrawSetProportional(LogoTD[1], 1);
    TextDrawSetSelectable(LogoTD[1], 0);

    LogoTD[2] = TextDrawCreate(581.000000, 19.000000, "Roleplay");
    TextDrawFont(LogoTD[2], 0);
    TextDrawLetterSize(LogoTD[2], 0.304166, 1.350000);
    TextDrawTextSize(LogoTD[2], 400.000000, 17.000000);
    TextDrawSetOutline(LogoTD[2], 1);
    TextDrawSetShadow(LogoTD[2], 0);
    TextDrawAlignment(LogoTD[2], 1);
    TextDrawColor(LogoTD[2], -1094795521);
    TextDrawBackgroundColor(LogoTD[2], 57);
    TextDrawBoxColor(LogoTD[2], 50);
    TextDrawUseBox(LogoTD[2], 0);
    TextDrawSetProportional(LogoTD[2], 1);
    TextDrawSetSelectable(LogoTD[2], 0);
    return 1;
}

hook OnScriptExit()
{
    for(new i; i != sizeof LogoTD; i++) TextDrawDestroy(LogoTD[i]);
    return 1;
}

hook OnPlayerSpawn(playerid)
{
    for(new i; i != sizeof LogoTD; i++) TextDrawShowForPlayer(playerid, LogoTD[i]);
    return 1;
}