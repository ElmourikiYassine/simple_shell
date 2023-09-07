#include "main.h"

/**
 * process_input - process and execute user input
 * @line: The user input line to processed
 * @tokens: An array of tokens provided by the user , the delimiter is " ".
 * @token_count: The number of elements in the tokens array.
 *
 * Return: The tokens.
 */
char **process_input(char *line, char **tokens,
		int *token_count, char **env, int *executable_is_found)
{
	char *token;

	token = strtok(line, " ");
	*token_count = 0;

	*executable_is_found = find_executable(env);
	while (token != NULL)
	{
		tokens[*token_count] = token;
		*token_count = *token_count + 1;
		token = strtok(NULL, " ");
	}

	tokens[*token_count] = NULL;
	return (tokens);
}

