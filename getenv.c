#include "main.h"
/**
 * _getenv: function to get path variable from environ
 * @name: pointer to character
 * Return: the global variable PATH
*/

char *_getenv(char *name)
{
    extern char **environ;
    int i = 0;
    char *token;
    
    while (environ[i])
    {
        token = strtok(environ[i], "=");
        if (_strcmp(token ,name) == 0)
        {
            return (strtok(NULL, "="));
        }
        i++;
    }
    return (NULL);
}