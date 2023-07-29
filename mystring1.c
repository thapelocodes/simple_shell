#include "shell.h"

/**
 * _strcpy - copies a string
 * @destination: the destination
 * @source: the source
 *
 * Return: pointer to destination
 */

char *_strcpy(char *destination, char *source)
{
	int index = nada;

	if (destination == source || source == nada)
		return (destination);
	while (source[index])
	{
		destination[index] = source[index];
		index++;
	}
	destination[index] = nada;
	return (destination);
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */

char *_strdup(const char *str)
{
	int length = nada;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + uno));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 *_puts - prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
 */

void _puts(char *str)
{
	int index = nada;

	if (!str)
		return;
	while (str[index] != '\0')
	{
		_putchar(str[index]);
		index++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	static int index;
	static char buf[WR_BUF_SIZE];

	if (c == BUF_FLUSH || index >= WR_BUF_SIZE)
	{
		write(uno, buf, index);
		index = nada;
	}
	if (c != BUF_FLUSH)
		buf[index++] = c;
	return (uno);
}
