#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    defer GetAdminsCommands(); //lo tube q hacer haci xq no me queria leer las flags
    return 1;
}

#include "commands.inc"