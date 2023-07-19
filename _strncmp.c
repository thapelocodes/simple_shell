#include "shell.h"

/**
 * _strncmp - mimics strncmp (compares n bytes in 2 strings).
 * @str1: first string.
 * @str2: second string.
 * @n: number of bytes to compare.
 *
 * Return: 0 if str1 = str2 up to n bytes, otherwise *str1 - *str2.
 */

int _strncmp(const char* str1, const char* str2, size_t n)
{
	size_t i = 0;

	for (; *(str2 + i) != '\0' && i < n; i++)
	{
		if (*(str1 + i) != *(str2 + i))
			return (*(str1 + i) - *(str2 + i));
		if (*(str1 + i) == '\0')
			break;
	}
	return (0);
}
