#include "shell.h"

/**
 *hsh - main shell loop
 *@info: the parameter &return info struct
 *@av: the argument vector from main()
 *
 *Return: 0 on success, 1 on error, or error code
 */

int hsh(info_t *info, char **av)
{
	ssize_t rs = nada;
	int builtin_ret = nada;

	while (rs != nuno && builtin_ret != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		rs = get_input(info);
		if (rs != nuno)
		{
			set_info(info, av);
			builtin_ret = find_builtin(info);
			if (builtin_ret == nuno)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, nada);
	}

	write_history(info);
	free_info(info, uno);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == nuno)
			exit(info->status);
		exit(info->err_num);
	}

	return (builtin_ret);
}

/**
 *find_builtin - finds a builtin command
 *@info: the parameter &return info struct
 *
 *Return: -1 if builtin not found,
 *			0 if builtin executed successfully,
 *			1 if builtin found but not successful,
 *			-2 if builtin signals exit()
 */

int find_builtin(info_t *info)
{
	int index, builtin_ret = nuno;
	builtin_table builtintbl[] = {
		{ "exit", _myexit
		},
		{ "env", _myenv
		},
		{ "help", _myhelp
		},
		{ "history", _myhistory
		},
		{ "setenv", _mysetenv
		},
		{ "unsetenv", _myunsetenv
		},
		{ "cd", _mycd
		},
		{ "alias", _myalias
		},
		{
			NULL, NULL
		}
	};

	for (index = nada; builtintbl[index].type; index++)
		if (_strcmp(info->argv[nada],
				builtintbl[index].type) == nada)
		{
			info->line_count++;
			builtin_ret = builtintbl[index].func(info);
			break;
		}

	return (builtin_ret);
}

/**
 *find_cmd - finds a command in PATH
 *@info: the parameter &return info struct
 *
 *Return: void
 */

void find_cmd(info_t *info)
{
	char *path = NULL;
	int index, xk;

	info->path = info->argv[nada];
	if (info->linecount_flag == uno)
	{
		info->line_count++;
		info->linecount_flag = nada;
	}

	for (index = nada, xk = nada; info->arg[index]; index++)
		if (!is_delim(info->arg[index], " \t\n"))
			xk++;
	if (!xk)
		return;

	path = find_path(info, _getenv(info, "PATH="),
		info->argv[nada]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=") ||
				info->argv[nada][nada] == '/') &&
			is_cmd(info, info->argv[nada]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "Not Found\n");
		}
	}
}

/**
 *fork_cmd - forks a an exec thread to run cmd
 *@info: the parameter &return info struct
 *
 *Return: void
 */

void fork_cmd(info_t *info)
{
	pid_t pod_child;

	pod_child = fork();
	if (pod_child == nuno)
	{
		perror("Error:");
		return;
	}

	if (pod_child == nada)
	{
		if (execve(info->path, info->argv,
				get_environ(info)) == nuno)
		{
			free_info(info, uno);
			if (errno == EACCES)
				exit(126);
			exit(uno);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
