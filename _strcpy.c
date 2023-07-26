#include "shell.h"

/**
 * _strcpy - function copies string pointed to src and dest
 * @dest: Pointer parameter
 * @src: poiter parameter
 * Return: char
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
