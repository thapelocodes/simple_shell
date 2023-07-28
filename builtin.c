#include "shell.h"

/**
 * _myexit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */

int _myexit(info_t *info)
{
	int check_exit;

	if (info->argv[uno]) /* If there is an exit arguement */
	{
		check_exit = _erratoi(info->argv[uno]);
		if (check_exit == nuno)
		{
			info->status = duo;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[uno]);
			_eputchar('\n');
			return (uno);
		}
		info->err_num = _erratoi(info->argv[uno]);
		return (-2);
	}
	info->err_num = nuno;
	return (-2);
}

/**
 * _mycd - changes the current dir of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */

int _mycd(info_t *info)
{
	int chdrtr;
	char *s, *dir, buffer[1024];

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[uno])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdrtr = chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdrtr = chdir(dir);
	}
	else if (_strcmp(info->argv[uno], "-") == nada)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (uno);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdrtr = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdrtr = chdir(info->argv[uno]);
	if (chdrtr == nuno)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[uno]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (nada);
}

/**
 * _myhelp - changes the current dir of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */

int _help(info_t *info)

	char **arguments_array;

	arguments_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (nada)
		_puts(*arguments_array); /* temp att_unused workaround */
	return (nada);
}
