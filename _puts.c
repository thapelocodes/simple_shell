#include "shell.h"

/**
 * _puts - prints a string, followed by a new line, to stdout
 * @str: string to print
 */

void _puts(char *str)
{
	int i = 0;

	for (; *(str + i) != '\0'; i++)
		_putchar(*(str + i));
	_putchar('\n');
}
