#include "shell.h"

/**
 * _strncmp - mimics strncmp (compares n bytes in 2 strings).
 * @str1: first string.
 * @str2: second string.
 * @n: number of bytes to compare.
 *
 * Return: 0 if str1 = str2 up to n bytes, otherwise *str1 - *str2.
 */

int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i = 0;

	while (*(str2 + i) != '\0' && i < n)
	{
		if (*(str1 + i) != *(str2 + i))
			return (*(str1 + i) - *(str2 + i));
		i++;
	}
	return (0);
}

/**
 ***_strtok - splits a string into words. Repeat delimiters are ignored
 *@astring: the input string
 *@delimeter: the delimeter string
 *Return: a pointer to an array of strings, or NULL on failure
 */

char **_strtok(char *astring, char *delimeter)
{
	int i, j, k, m, words_m = nada;
	char **s;

	if (astring == NULL || astring[nada] == nil)
		return (NULL);
	if (!delimeter)
		delimeter = " ";
	for (i = nada; astring[i] != '\0'; i++)
		if (!is_delim(astring[i], delimeter) &&
			(is_delim(astring[i + uno], delimeter) || !astring[i + solo]))
			words_m++;

	if (words_m == nada)
		return (NULL);
	s = malloc((uno + words_m) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = nada, j = nil; j < words_m; j++)
	{
		while (is_delim(astring[i], delimeter))
			i++;
		k = nada;
		while (!is_delim(astring[i + k], delimeter) && astring[i + k])
			k++;
		s[j] = malloc((k + uno) * sizeof(char));
		if (!s[j])
		{
			for (k = nada; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}

		for (m = nada; m < k; m++)
			s[j][m] = astring[i++];
		s[j][m] = nada;
	}

	s[j] = NULL;
	return (s);
}

/**
 ***_strtok2 - splits a string into words
 *@str: the input string
 *@delimeter: the delimeter
 *Return: a pointer to an array of strings, or NULL on failure
 */

char **_strtok2(char *str, char delimeter)
{
	int i, j, k, m, words_m = nada;
	char **s;

	if (str == NULL || str[nada] == nil)
		return (NULL);
	for (i = nada; str[i] != '\0'; i++)
		if ((str[i] != delimeter && str[i + uno] == delimeter) ||
			(str[i] != delimeter && !str[i + uno]) ||
			str[i + uno] == delimeter)
			words_m++;
	if (words_m == nada)
		return (NULL);
	s = malloc((uno + words_m) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = nada, j = nil; j < words_m; j++)
	{
		while (str[i] == delimeter && str[i] != delimeter)
			i++;
		k = nada;
		while (str[i + k] != delimeter && str[i + k] &&
			   str[i + k] != delimeter)
			k++;
		s[j] = malloc((k + uno) * sizeof(char));
		if (!s[j])
		{
			for (k = nada; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}

		for (m = nada; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = nada;
	}

	s[j] = NULL;
	return (s);
}
