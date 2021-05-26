LoadAdminCommands()
{
	#define MAX_COMMANDS_LINE 6
	new dest[32],
        CmdArray:PC_array = PC_GetCommandArray(),
		count[4];

    for (new i; i != PC_GetArraySize(PC_array); i++)
    {
        PC_GetCommandName(PC_array, i, dest);
		switch(PC_GetFlags(dest))
		{
			case ADMIN_LEVEL_HELPER:
			{
				strcat(cmd_Admins[0], " /");
				strcat(cmd_Admins[0], dest);
				count[0]++;
				if(count[0] == MAX_COMMANDS_LINE)
				{
					count[0] = 0;
					strcat(cmd_Admins[0], "\n");
				}
			}
			case ADMIN_LEVEL_MODERATOR:
			{
				strcat(cmd_Admins[1], " /");
				strcat(cmd_Admins[1], dest);
				count[1]++;
				if(count[1] == MAX_COMMANDS_LINE)
				{
					count[1] = 0;
					strcat(cmd_Admins[1], "\n");
				}
			}
			case ADMIN_LEVEL_ADMINISTRATOR:
			{
				strcat(cmd_Admins[2], " /");
				strcat(cmd_Admins[2], dest);
				count[2]++;
				if(count[2] == MAX_COMMANDS_LINE)
				{
					count[2] = 0;
					strcat(cmd_Admins[2], "\n");
				}
			}
			case ADMIN_LEVEL_DEVELOPER:
			{
				strcat(cmd_Admins[3], " /");
				strcat(cmd_Admins[3], dest);
				count[3]++;
				if(count[3] == MAX_COMMANDS_LINE)
				{
					count[3] = 0;
					strcat(cmd_Admins[3], "\n");
				}
			}
		}
    }
    PC_FreeArray(PC_array);
	return 1;
}

timer GetAdminsCommands[500]()
{
    LoadAdminCommands();
}