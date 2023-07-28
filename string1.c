#include "shell.h"

/**
 * _puts - prints an input string.
 * @str: string to print.
 */

void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i])
		_putchar(str[i++]);
}

/**
 * _putsfd - prints an input string to a specified file descriptor.
 * @str: input string.
 * @fd: file descriptor to write to.
 *
 * Return: the number of chars put.
 */

int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
		i += _putfd(*str++, fd);
	return (i);
}

/**
 * _strchr - locates a char in a string.
 * @s: input string.
 * @c: char to locate.
 *
 * Return: pointer to memory location of char if found, NULL otherwise.
 */

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++);
	return (NULL);
}

/**
 * _strncpy - copies a string.
 * @dest: destination string.
 * @src: source string.
 * @n: max number of chars to copy.
 *
 * Return: the string with n chars copied.
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (src[i] && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
		while (i < n)
			dest[i++] = '\0';
	return (dest);
}

/**
 * _strncat - concatenates src to dest up to n bytes.
 * @dest: destination string.
 * @src: source string.
 * @n: maximum number of bytes to concatenate.
 *
 * Return: dest.
 */

char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0;

	while (dest[i])
		i++;
	while (src[i] && j < n)
		dest[i++] = src[j++];
	if (j < n)
		dest[i] = '\0';
	return (dest);
}
