#include "shell.h"

/**
 * _atoi - function converts string to an integer
 * @s: Pointer parameter
 * Return: returns an integer value
 */

int _atoi(char *s)
{
	unsigned int count = 0, size = 0, j = 0, k = 1, m = 1, i;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		if (*(s + count) == '-')
			k *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}

	i = count - size;
	while (i < count)
	{
		j = j + ((*(s + i) - 48) * m);
		m /= 10;
		i++;
	}
	return (j * k);
}
