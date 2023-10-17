#ifndef SHELL_H
#define SHELL_H

/*LIBRARIES*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

/*PROTOTYPES*/
int blank_line(char *buffer);
char *get_env(char *env_var);
void _envprint(void);
void _puts(char *str);
int _putchar(char c);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *search_path(char *command);
char **_split(char *str, char *sep);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
void *_calloc(unsigned int nmemb, unsigned int size);
int execmd(char **args);

/* GLOBAL VAR*/
extern char **environ;

#endif
