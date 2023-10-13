#include "main.h"

/**
  * _isatty - verif if terminal
  */

void _isatty(void)
{
	if (isatty(STDIN_FILENO))
	    write(1, "(Eshell) $ ", 11);
}

/**
* _EOF - handles the End of File
* @len: return value of getline function
* @buff: buffer
 */
void _EOF(int len, char *buff)
{
	(void)buff;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(1, "\n", 1);
			free(buff);
		}
		exit(0);
	}
}

char **parse_string(char *buf, size_t r_bytes)
{
    char *token;
    int i = 0;
    int no_of_tokens = 0;
    char **array;
    char **args;
    
    array = malloc(sizeof(char *) * r_bytes);
    if (array == NULL)
    {
        perror("memory allocation error");
        return (-1);
    }
    _strcpy(array, buf);
    token = strtok(buf,"\t\n");
    while (token != NULL)
    {
        no_of_tokens++;
        token = strtok(NULL, "\t\n");
    }
    no_of_tokens++;
    argv = malloc(sizeof(char *) * no_of_tokens);
    token = strtok(array, "\t\n");
    while (token != NULL)
    {
        args[i] = malloc(sizeof(char) * _strlen(token));
        _strcpy(args[i], token);
        token = strtok(NULL, "\t\n");
        i++; 
    }
    args[i] = NULL;
    free(array);
    return (args);
}