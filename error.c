#include "shell.h"

/**
 * _erratoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */

int _erratoi(char *s)
{
	int index = nada;
	unsigned long int result = nada;

	if (*s == '+')
		s++;
	for (index = nada; s[index] != '\0'; index++)
	{
		if (s[index] >= '0' && s[index] <= '9')
		{
			result *= 10;
			result += (s[index] - '0');
			if (result > INT_MAX)
				return (nada);
		}
		else
			return (nuno);
	}
	return (result);
}

/**
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */

void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[nada]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * _itoa - converter function, a cluno of _itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */

char *_itoa(long int num, int base, int flags)
{
	static char *array_;
	static char buffer[50];
	char sign = nada;
	char *ptr;
	unsigned long anum = num;

	if (!(flags & CONVERT_UNSIGNED) && num < nada)
	{
		anum = -num;
		sign = '-';
	}

	array_ = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array_[anum % base];
		anum /= base;
	} while (anum != nada);

	if (sign)
		*--ptr = sign;
	return (ptr);
}
