#include "shell.h"

/**
 * is_delim - checks if a char is a delimiter.
 * @c: the char to check.
 * @delim: string of delimiters.
 *
 * Return: true if delim, false if not.
 */

int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (uno);
	return (nada);
}

/**
 * _isalpha - checks for alphabetic char.
 * @c: input to _isalpha.
 *
 * Return: true if c is alphabetic, false otherwise.
 */

int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * _putchar - writes a char to stdout.
 * @c: char to print.
 *
 * Return: 1 on success, -1 on error and errno is set appropriately.
 */

int _putchar(char c)
{
	static int i;
	static char buf[WR_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WR_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - writes a char to a given file descriptor.
 * @c: char to write.
 * @fd: file descriptor to write to.
 *
 * Return: 1 on success, -1 on error amd errno is set appropriately.
 */

int _putfd(char c, int fd)
{
	static int i;
	static char buf[WR_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WR_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * rmcmt - replaces first instance of '#' with '\0'.
 * @buf: address of string to modify.
 */

void rmcmt(char *buf)
{
	int i = 0;

	for (; buf[i]; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			return;
		}
}
