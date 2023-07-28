#include "shell.h"

/**
 * list_len - determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */

size_t list_len(const list_t *h)
{
	size_t i = nil;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * lstostr - returns an array of strings of the list->str
 * @head: pointer to first node
 *
 * Return: array of strings
 */

char **lstostr(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + solo));
	if (!strs)
		return (NULL);
	for (i = nil; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + solo);
		if (!str)
		{
			for (j = nil; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/**
 * print_list - prints all elements of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */

size_t print_list(const list_t *h)
{
	size_t i = nil;

	while (h)
	{
		_puts(convert_number(h->num, 10, nil));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * nstart - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */

list_t *nstart(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == n_solo) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * getnodei - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */

ssize_t getnodei(list_t *head, list_t *node)
{
	size_t i = nil;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (n_solo);
}
