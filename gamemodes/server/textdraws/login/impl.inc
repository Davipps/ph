 #include <YSI_Coding\y_hooks>

 hook OnScriptInit()
 {
    LoginTD[0] = TextDrawCreate(-4.000000, -9.000000, "TextDraw");
    TextDrawFont(LoginTD[0], 5);
    TextDrawLetterSize(LoginTD[0], 0.600000, 2.000000);
    TextDrawTextSize(LoginTD[0], 700.000000, 537.000000);
    TextDrawSetOutline(LoginTD[0], 1);
    TextDrawSetShadow(LoginTD[0], 0);
    TextDrawAlignment(LoginTD[0], 1);
    TextDrawColor(LoginTD[0], -1);
    TextDrawBackgroundColor(LoginTD[0], 255);
    TextDrawBoxColor(LoginTD[0], 50);
    TextDrawUseBox(LoginTD[0], 0);
    TextDrawSetProportional(LoginTD[0], 1);
    TextDrawSetSelectable(LoginTD[0], 0);
    TextDrawSetPreviewModel(LoginTD[0], 1882);
    TextDrawSetPreviewRot(LoginTD[0], 0.000000, 0.000000, 0.000000, 0.280000);
    TextDrawSetPreviewVehCol(LoginTD[0], 1, 1);

    LoginTD[1] = TextDrawCreate(299.000000, 101.000000, "pera");
    TextDrawFont(LoginTD[1], 1);
    TextDrawLetterSize(LoginTD[1], 0.554166, 2.949999);
    TextDrawTextSize(LoginTD[1], 400.000000, 17.000000);
    TextDrawSetOutline(LoginTD[1], 1);
    TextDrawSetShadow(LoginTD[1], 0);
    TextDrawAlignment(LoginTD[1], 1);
    TextDrawColor(LoginTD[1], -16746241);
    TextDrawBackgroundColor(LoginTD[1], 175);
    TextDrawBoxColor(LoginTD[1], 50);
    TextDrawUseBox(LoginTD[1], 0);
    TextDrawSetProportional(LoginTD[1], 1);
    TextDrawSetSelectable(LoginTD[1], 0);

    LoginTD[2] = TextDrawCreate(314.000000, 128.000000, "Roleplay");
    TextDrawFont(LoginTD[2], 0);
    TextDrawLetterSize(LoginTD[2], 0.404166, 1.750000);
    TextDrawTextSize(LoginTD[2], 400.000000, 17.000000);
    TextDrawSetOutline(LoginTD[2], 1);
    TextDrawSetShadow(LoginTD[2], 0);
    TextDrawAlignment(LoginTD[2], 1);
    TextDrawColor(LoginTD[2], -1094795521);
    TextDrawBackgroundColor(LoginTD[2], 95);
    TextDrawBoxColor(LoginTD[2], 50);
    TextDrawUseBox(LoginTD[2], 0);
    TextDrawSetProportional(LoginTD[2], 1);
    TextDrawSetSelectable(LoginTD[2], 0);

    LoginTD[3] = TextDrawCreate(272.000000, 94.000000, "LD_BEAT:cring");
    TextDrawFont(LoginTD[3], 4);
    TextDrawLetterSize(LoginTD[3], 0.600000, 2.000000);
    TextDrawTextSize(LoginTD[3], 30.500000, 39.500000);
    TextDrawSetOutline(LoginTD[3], 1);
    TextDrawSetShadow(LoginTD[3], 0);
    TextDrawAlignment(LoginTD[3], 1);
    TextDrawColor(LoginTD[3], -16711681);
    TextDrawBackgroundColor(LoginTD[3], 255);
    TextDrawBoxColor(LoginTD[3], 50);
    TextDrawUseBox(LoginTD[3], 0);
    TextDrawSetProportional(LoginTD[3], 1);
    TextDrawSetSelectable(LoginTD[3], 0);
    return 1;
}

hook OnScriptExit()
{
    for(new i; i != sizeof LoginTD; i++) TextDrawDestroy(LoginTD[i]);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    for(new i; i != sizeof LoginTD;i++) TextDrawShowForPlayer(playerid, LoginTD[i]);
    return 1;
}

hook OnPlayerSpawn(playerid)
{
    for(new i; i != sizeof LoginTD;i++) TextDrawHideForPlayer(playerid, LoginTD[i]);
    return 1;
}