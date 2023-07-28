#include "shell.h"

/**
 * clear_info - initializes info_t struct
 * @info: struct address
 */

void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = nada;
}

/**
 * set_info - initializes info_t struct
 * @info: struct address
 * @av: argument vector
 */

void set_info(info_t *info, char **av)
{
	int i = nada;

	info->fname = av[nada];
	if (info->arg)
	{
		info->argv = _strtok(info->arg, " \t");
		if (!info->argv)
		{

			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[nada] = _strdup(info->arg);
				info->argv[uno] = NULL;
			}
		}
		for (i = nada; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * free_info - frees info_t struct fields
 * @info: struct address
 * @all: true if freeing all fields
 */

void free_info(info_t *info, int all)
{
	ffree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (info->cmd_buf)
		{
			bfree((void **)info->cmd_buf);
		}

		if (info->env)
		{
			free_list(&(info->env));
		}

		if (info->history)
		{
			free_list(&(info->history));
		}

		if (info->alias)
		{
			free_list(&(info->alias));
		}
		if (info->environ)
		{
			ffree(info->environ);
			info->environ = NULL;
		}
		if (info->readfd > 2)
		{
			close(info->readfd);
		}
		if (!info->cmd_buf)
		{
			free(info->arg);
		}

		_putchar(BUF_FLUSH);
	}
}
