#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stddef.h>

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(const char *str);
char *_strncat(char *dest, char *src);
void _isatty(void);
void _EOF(int len, char *buff);
char *get_path(char *command);
char **parse_string(char *buf, size_t r_bytes);
void execute_program(char **arg);
char *_getenv(char *name);






#endif