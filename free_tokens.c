#include "shell.h"

/**
 * free_tokens - frees the memory allocated for each token.
 * @tokens: the array of tokens to free.
 */

void free_tokens(char **tokens)
{
	int i = 0;

	if (tokens == NULL)
		return;
	for (; tokens[i] != NULL; i++)
		free(tokens[i]);
	free(tokens);
}
