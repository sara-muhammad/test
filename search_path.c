#include "main.h"

/**
 * search_path - search file between the path
 * @command: cmd
 * Return: cmd path
 */

char *search_path(char *command)
{    
	const char* path = getenv("PATH");
    char* path_cpy = strdup(path);
    char* path_concat = NULL;
    char** path_split = NULL;
	char* token;
    int i = 0, j;

    struct stat info;

    if (stat(command, &info) == 0)
	{
        free(path_cpy);
        return strdup(command);
    }

    path_split = malloc(sizeof(char*) * 100);
	if (path_split == NULL)
	{
        free(path_cpy);
        return NULL;
    }

    token = strtok(path_cpy, ":");
    while (token != NULL) {
        path_split[i++] = strdup(token);
        token = strtok(NULL, ":");
    }
    path_split[i] = NULL;

    for (j = 0; path_split[j] != NULL; j++)
	{
        size_t path_len = strlen(path_split[j]);
        path_concat = malloc(path_len + strlen(command) + 2);
    	if (path_concat == NULL)
		{
            break;
        }
        strcpy(path_concat, path_split[j]);

        if (path_concat[path_len - 1] != '/')
		{
            strcat(path_concat, "/");
        }

        strcat(path_concat, command);

        if (stat(path_concat, &info) == 0)
		{
            break;
        }

        free(path_concat);
        path_concat = NULL;
    }

    free(path_cpy);
    free(path_split);

    return path_concat;
}