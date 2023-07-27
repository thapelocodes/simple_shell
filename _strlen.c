#include "shell.h"

/**
* _strlen - a function to print the length of a string
* @s: string to be supplied
*
* Return: Always 0 (Success)
*/

size_t _strlen(char *s)
{
	size_t i = 0;

	while (; s[i] != '\0')
		;

	return (i);
}
