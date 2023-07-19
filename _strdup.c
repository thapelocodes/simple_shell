#include "shell.h"

/**
 * _strdup - duplicates a string.
 * @s: the string to duplicate.
 *
 * Return: the duplicated string.
 */

char *_strdup(const char *s)
{
	size_t len;
	char *dup;

	len = _strlen((char *)s) + 1;
	dup = malloc(len * sizeof(char));
	if (dup == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	return (_memcpy(dup, (char *)s, len));
}
