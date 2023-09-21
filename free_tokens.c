#include "main.h"

/**
 * count_tokens - Count the number of tokens in an array.
 * @tokens: The array of tokens.
 * Return: The number of tokens in the array.
*/
int count_tokens(char **tokens)
{
	int token_count = 0;

	while (tokens[token_count] != NULL)
	token_count++;

	return (token_count);
}

/**
 * free_tokens - Free an array of tokesn.
 * @tokens: The array of tokens to be freed.
*/
void free_tokens(char **tokens)
{
	int i;

	if (tokens == NULL)
		return;

	for (i = 0; tokens[i] != NULL; i++)
		free(tokens[i]);
}
