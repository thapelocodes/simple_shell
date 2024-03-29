#include "shell.h"

/**
 * list_len - determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */

size_t list_len(const list_t *h)
{
	size_t i = nada;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - returns an array of strings of the list->str
 * @head: pointer to first node
 *
 * Return: array of strings
 */

char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + uno));
	if (!strs)
		return (NULL);
	for (i = nada; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + uno);
		if (!str)
		{
			for (j = nada; j < i; j++)
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
	size_t i = nada;

	while (h)
	{
		_puts(myitoa(h->num, 10, nada));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nada)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * node_startw - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */

list_t *node_startw(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = startw(node->str, prefix);
		if (p && ((c == n_uno) || (*p == c)))
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
	size_t i = nada;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (n_uno);
}
