char *_getenv(const char *name)
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