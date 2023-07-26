#include "shell.h"
#include <string.h>

/**
 * getcmd - reads the command using getline.
 * @cmd: memory location of the command read.
 * @len: the length parameter for getline.
 *
 * Return: the length of the input.
 */

ssize_t getcmd(char **cmd, size_t *len)
{
	ssize_t read_len;

	if (isatty(fileno(stdin)))
		write(STDOUT_FILENO, "#cisfun$ ", 9);

	read_len = getline(cmd, len, stdin);
	if (read_len == -1)
	{
		if (feof(stdin))
		{
			free(*cmd);
			exit(EXIT_SUCCESS);
		}
		perror("getline");
		free(*cmd);
		exit(EXIT_FAILURE);
	}

	if (read_len > 0 && (*cmd)[read_len - 1] == '\n')
		(*cmd)[read_len - 1] = '\0';

	return (read_len);
}

/**
 * execute - forks a child process and executes the command using execve.
 * @cmd: the command to execute.
 * @av: argument vector from main containing the name of the program.
 * @env: the list of environment variables.
 *
 * Return: the child pid on success or -1 on failure.
 */

int execute(char *cmd, char **av, char **env)
{
	int status;
	pid_t pid;
	char **exec = malloc(2 * sizeof(char *));

	exec[0] = malloc(MAX_COM_LEN * sizeof(char));
	_strcpy(exec[0], cmd);

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(exec[0]);
		free(exec);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(exec[0], exec, env) == -1)
		{
			perror(av[0]);
			free(exec[0]);
			free(exec);
			exit(EXIT_FAILURE);
		}
	}
	else
		if (wait(&status) == -1)
		{
			perror("wait");
			free(exec[0]);
			free(exec);
			exit(EXIT_FAILURE);
		}

	free(exec[0]);
	free(exec);
	return (status);
}

/**
 * main - UNIX command line interpreter.
 * @ac: arg count.
 * @av: arg vector.
 * @env: environment vector.
 *
 * Return: 0 (Success).
 */

int main(int ac __attribute__((unused)), char **av, char **env)
{
	char *command = NULL;
	size_t len = 0;
	ssize_t read_len;
	int status;
	bool interactive = isatty(fileno(stdin));

	while (1)
	{
		read_len = getcmd(&command, &len);
		if (!interactive && read_len <= 1)
			break;

		status = execute(command, av, env);
		if (status == -1)
			exit(EXIT_FAILURE);
	}

	free(command);
	return (0);
}
