#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: pointer 1
 * @s2: pointer 2
 * Return: result
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);

		s1++;
		s2++;
	}
	return (0);
}

/**
 * _strcpy - function that copies the string pointed to by src
 * @dest: pointer
 * @src: ponter
 * Return: @dest
 */
char *_strcpy(char *dest, char *src)
{
	char *c = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (c);
}

/**
 * _strcat - function that concatenates two strings
 * @dest: string
 * @src: string
 * Return: @dest
 */

char *_strcat(char *dest, char *src)
{
	int a, b;

	for (a = 0; dest[a] != '\0'; a += 1)
	{}

	for (b = 0; src[b] != '\0'; b += 1)
	{
		dest[a] = src[b];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

/**
 * _strlen - string length
 * @s: string
 * Return: result
 *
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}

/**
 * _split - split string
 * @str: string
 * @sep: separator
 * Return: divided path
 */

char **_split(char *str, char *sep)
{
    char **split_str = NULL;
    int count = 0;
    int i = 0;

    char *token = strtok(str, sep);
    while (token != NULL)
    {
        count++;
        token = strtok(NULL, sep);
    }

    split_str = (char **)calloc(count + 1, sizeof(char *));
    if (!split_str)
    {
        free(split_str);
        return NULL;
    }

    token = strtok(str, sep);
    while (token != NULL)
    {
        split_str[i] = strdup(token);
        token = strtok(NULL, sep);
        i++;
    }

    return split_str;
}
