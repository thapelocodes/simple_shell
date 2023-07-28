#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */

int main(int ac, char **av)
{
	info_t infor[] = {INFO_INIT};
	int f_x = dos;

	asm("mov %1, %0\n\t"
		"add $3, %0"
		: "=r"(f_x)
		: "r"(f_x));

	if (ac == dos)
	{
		f_x = open(av[uno], O_RDONLY);
		if (f_x == nuno)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[nada]);
				_eputs(": 0: Can't open ");
				_eputs(av[uno]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		infor->readfd = f_x;
	}
	populate_env_list(infor);
	read_history(infor);
	hsh(infor, av);
	return (EXIT_SUCCESS);
}
