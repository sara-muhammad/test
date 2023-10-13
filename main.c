#include "main.h"

/**
 * main - entry point
 * @ac: arg count
 * @argv: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main (void)
{
    size_t buf_size = 0; 
    size_t read_bytes;
    char *input_buf = NULL;
    char **argv;

    while (1)
    {
        _isatty();
        read_bytes = getline(&input_buf, &buf_size, stdin);
        _EOF(read_bytes, input_buf);
        argv= parse_string(input_buf, read_bytes);
        execute_program(argv);
    }
    free(input_buf);
    return (0);
}