#include "shell.h"

/**
 * _atoi - function converts string to an integer
 * @s: Pointer parameter
 * Return: returns an integer value
 */

int _atoi(char *s)
{
	unsigned int count = 0, size = 0, result = 0, sign = 1, m = 1, i;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		if (*(s + count) == '-')
			sign *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}

	i = count - size;
	while (i < size && m >= 1)
	{
		result = result + ((*(s + i) - 48) * m);
		m /= 10;
		i++;
	}
	return (result * sign);
}

/**
 * print_d - prints an int to a file descriptor.
 * @num: the input.
 * @fd: file descriptor to write to.
 *
 * Return: number of chars printed.
 */

int print_d(int num, int fd)
{
	int i, count = 0, (*p_putchar)(char) = _putchar;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		p_putchar = _eputchar;
	if (num < 0)
	{
		_abs_ = -num;
		p_putchar('-');
		count++;
	}
	else
		_abs_ = num;
	current = _abs_;
	i = 1000000000;
	while (i > 1)
	{
		if (_abs_ / i)
		{
			p_putchar('0' + current / i);
			count++;
		}
		current %= i;
		i /= 10;
	}
	p_putchar('0' + current);
	count++;

	return (count);
}
