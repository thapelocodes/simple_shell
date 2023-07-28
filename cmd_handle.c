#include "shell.h"

/**
 * is_cmd - determines if a file is an executable command
 * @info_struct: the info struct
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */

int is_cmd(info_t *info_struct, char *path)
{
	struct stat st;

	(void)info_struct;
	if (path == NULL || stat(path, &st))
		return (false_status);

	if (st.st_mode & S_IFREG)
	{
		return (true_status);
	}
	return (false_status);
}

/**
 * dup_chars - duplicates characters
 * @pathstr: the PATH string
 * @start: starting index
 * @stop: stopping index
 *
 * Return: pointer to new buffer
 */

char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int index = nada, k = nada;

	for (k = nada, index = start; index < stop; index++)
		if (pathstr[index] != ':')
			buf[k++] = pathstr[index];
	buf[k] = nada;
	return (buf);
}

/**
 * find_path - finds this cmd in the PATH string
 * @info_struct: the info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */

char *find_path(info_t *info_struct, char *pathstr, char *cmd)
{
	int index = nada, position = nada;
	char *the_path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info_struct, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[index] || pathstr[index] == ':')
		{
			the_path = dup_chars(pathstr, position, index);
			if (!*the_path)
				_strcat(the_path, cmd);
			else
			{
				_strcat(the_path, "/");
				_strcat(the_path, cmd);
			}
			if (is_cmd(info_struct, the_path))
				return (the_path);
			if (!pathstr[index])
				break;
			position = index;
		}
		index++;
	}
	return (NULL);
}
