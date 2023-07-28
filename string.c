#include "shell.h"

/**
 * _strlen - determines the length of a string.
 * @s: string whose length is evaluated.
 *
 * Return: size_t length of string.
 */

size_t _strlen(char *s)
{
	size_t len = 0;

	if (!s)
		return (0);

	while (s[len])
		len++;
	return (len);
}

/**
 * _strcmp - performs lexicorgarphic comparison of two strings.
 * @s1: first string.
 * @s2: second string.
 *
 * Return: <0 id s1 < s2, >0 if s1 > s2, 0 if s1 == s2.
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
	return (*s1 - *s2);
}

/**
 * _strcat - concatenates two strings.
 * @dest: destination buffer.
 * @src: source buffer.
 *
 * Return: pointer to destination buffer.
 */

char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		dest++ = *src++;
	*dest = *src;
	return (ret);
}

/**
 * _strcpy - copies a string.
 * @dest: the destination buffer.
 * @src: the source buffer.
 *
 * Return: pointer to destination,
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i]);
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (0);
}

/**
 * _strdup - duplicates a string.
 * @str: string to duplicate.
 *
 * Return: pointer to the duplicated string.
 */

char *_strdup(const char *str)
{
	char *ret;
	int len = 0;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	for (len++; len >= 0; len--)
		ret[len] = *str--;
	return (ret);
}
