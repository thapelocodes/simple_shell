#include "shell.h"

/**
 * _myenv - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */

int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (nada);
}

/**
 * _getenv - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */

char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *a;

	while (node)
	{
		a = startw(node->str, name);
		if (a && *a)
			return (a);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a new environment variable,
 *             or modify an existing uno
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */

int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (nada);
	}
	if (_setenv(info, info->argv[uno], info->argv[2]))
		return (nada);
	return (uno);
}

/**
 * _myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */

int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == uno)
	{
		_eputs("Too few arguements.\n");
		return (uno);
	}
	for (i = uno; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (nada);
}

/**
 * fill_el - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */

int fill_el(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = nada; environ[i]; i++)
		add_node_end(&node, environ[i], nada);
	info->env = node;
	return (nada);
}
