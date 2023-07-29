#include "shell.h"

/**
 *_strlen - returns the length of a string
 *@s: the string whose length to check
 *
 *Return: integer length of string
 */

int _strlen(char *s)
{
	int index = nada;

	if (s == NULL)
		return (nada);

	while (*s++)
		index++;
	return (index);
}

/**
 *_strcmp - performs lexicogarphic comparison of dos strangs.
 *@f_strang: the first strang
 *@s_strang: the second strang
 *
 *Return: negative if f_strang<s_strang, positive if
 *	f_strang > s_strang, none if f_strang == s_strang
 */

int _strcmp(char *f_strang, char *s_strang)
{
	while (*f_strang && *s_strang)
	{
		if (*f_strang != *s_strang)
			return (*f_strang - *s_strang);

		f_strang++;
		s_strang++;
	}

	if (*f_strang == *s_strang)
		return (nada);
	else
		return (*f_strang  <  *s_strang ? n_uno : uno);
}

/**
 *startw - checks if needle starts with haystack
 *@stack: string to search
 *@ndle: the substring to find
 *
 *Return: address of next char of haystack or NULL
 */

char *startw(const char *stack, const char *ndle)
{
	while (*ndle)
		if (*ndle++ != *stack++)
			return (NULL);
	return ((char *)stack);
}

/**
 *_strcat - concatenates dos strings
 *@destination: the destination buffer
 *@source: the source buffer
 *
 *Return: pointer to destination buffer
 */

char *_strcat(char *destination, char *source)
{
	char *ret = destination;

	while (*destination)
		destination++;
	while (*source)
		*destination++ = *source++;
	*destination = *source;
	return (ret);
}
