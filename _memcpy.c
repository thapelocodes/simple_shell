#include "shell.h"

/**
 * _memcpy - Copies @n bytes from the memory area pointed
 *           to by sting  @src into string @dest.
 * @dest: pointer to the string memory to copy to.
 * @src: pointer of string to  copy characters from.
 * @n: number of bytes memory to copy from @src.
 *
 * Return: returs @dest.
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
