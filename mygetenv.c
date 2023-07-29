#include "shell.h"

/**
 * get_environ - returns the string array copy of our environ
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */

char **get_environ(info_t *info)
{
	if (info->env_changed || !info->environ)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = nada;
	}

	return (info->environ);
}

/**
 * _unsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 */

int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t index = nada;
	char *p;

	if (!node || !var)
		return (nada);

	while (node)
	{
		p = startw(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delnodei(&(info->env), index);
			index = nada;
			node = info->env;
			continue;
		}
		node = node->next;
		index++;
	}
	return (info->env_changed);
}

/**
 * _setenv - Initialize a new environment variable,
 *             or modify an existing uno
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string env var property
 * @value: the string env var value
 *  Return: Always 0
 */

int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (nada);

	buf = malloc(_strlen(var) + _strlen(value) + dos);
	if (!buf)
		return (uno);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		p = startw(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = uno;
			return (nada);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, nada);
	free(buf);
	info->env_changed = uno;
	return (nada);
}
