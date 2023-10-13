#include "main.h"

/**
 * main - entry point
 * @ac: arg count
 * @argv: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main (int ac, char **argv)
{
    size_t buf_size = 0; 
    size_t read_bytes;
    int i = 0;
    int no_of_tokens = 0;
    char *input_buf = NULL;
    char *token;

    while (1)
    {
        write(1,"(Eshell) $ ",11);
        read_bytes = getline(&input_buf, &buf_size, stdin);
        if (read_bytes == -1)
        {
            perror("Erorr....\n");
            return (-1);
        }
        array = malloc(sizeof(char *) * read_bytes);
        if (array == NULL)
        {
            perror("memory allocation error");
            return (-1);
        }
        _strcpy(array, input_buf);
        token = strtok(input_buf,"\t\n");
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
            argv[i] = malloc(sizeof(char) * _strlen(token));
            _strcpy(argv[i], token);
            token = strtok(NULL, "\t\n");
            i++; 
        }
        argv[i] = NULL;
        execute_program(argv);
    }
    free(input_buf);
    free(array);
    return (0);
}