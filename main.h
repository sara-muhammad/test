#IFNDEF MAIN_H
#DEFINE MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int _strlen(char *s);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
void execute_program(char **arg);
char *_getenv(const char *name);






#endif