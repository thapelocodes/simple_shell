#include "shell.h"

/**
 * split - splits a string into an array of tokens.
 * @str: the string to split.
 * @delimiters: the delimiters to use for splitting.
 * @tokens: an array to store the tokens.
 * @max: the maximum number of tokens.
 *
 * Return: the number of tokens.
 */

int split(char *str, const char *delimiters, char **tokens, int max)
{
	int count = 0;
	char *token;

	token = strtok(str, delimiters);
	while (token != NULL && count < max)
	{
		tokens[count] = token;
		count++;
		token = strtok(NULL, delimiters);
	}
	tokens[count] = NULL;
	return (count);
}
