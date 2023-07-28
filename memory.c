#include "shell.h"

/**
 **_memset - fills memory with a constant byte
 *@s: the pointer to the memory area
 *@b: the byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int index;

	for (index = nada; index < n; index++)
		s[index] = b;
	return (s);
}

/**
 * ffree - frees a string of strings
 * @pp: string of strings
 */

void ffree(char **pp)
{
	char **a = pp;

	if (pp == NULL)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *tp;

	if (ptr == NULL)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	tp = malloc(new_size);
	if (tp == NULL)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		tp[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (tp);
}

#include "shell.h"

/**
 * bfree - frees a pointer and NULLs the address
 * @pointer: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */

int bfree(void **pointer)
{
	if (pointer && *pointer)
	{
		free(*pointer);
		*pointer = NULL;
		return (uno);
	}
	return (nada);
}
