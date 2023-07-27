#include "shell.h"

/**
 * _strcat - Concatenates (put together) the string pointed to by @src,
 *           to the end of the string pointed to by @dest, terminating null byte
 *           at the end.
 * @dest: pointer to the string to be concatenated upon.
 * @src: pointer to source string to be appended to @dest.
 *
 * Return: A pointer to the destination string @dest.
 */

char *_strcat(char *dest, char *src)
{
	int src_index = 0, d_count = 0;

	while (dest[d_count])
	{
		d_count++;
	}

	while (src[src_index])
	{
		dest[d_count] = src[src_index];
		d_count++;
		src_index++;
	}

	dest[d_count] = '\0';

	return (dest);
}
