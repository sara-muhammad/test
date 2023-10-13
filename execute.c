#include "main.h"

/**
 * execute_programm: function extract the command and execute it
 * @argv: pointer to array of args
*/

void execute_program(char **argv)
{
    char *cmd = NULL;
    char *actual_cmd = NULL;

    if (argv)
    {
        cmd = argv[0];

        actual_cmd = get_location(cmd);
        if (execve(actual_cmd, argv, NULL) == -1)
        {
            perror("Error:");
        }
    }
    
}