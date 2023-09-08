#include "main.h"

/**
 * process_input - Process and execute user input
 * @line: The user input line to be processed
 * @token_count: A pointer to an integer that will hold the number of tokens
 * @exe_name: A buffer to store the executable name
 *
 * Return: (char **) An array of tokens.
 */

char **process_input(char *line, int *token_count, char *exe_name)
{
	char *token;
	char **tokens = (char **)malloc(sizeof(char *) * SIZE_TOKEN);

	*token_count = 0;
	strcpy(exe_name, strtok(line, " "));
	token = exe_name;

	while (token != NULL)
	{
		tokens[*token_count] = strdup(token);
		(*token_count)++;
		token = strtok(NULL, " ");
	}
	tokens[*token_count] = NULL;

	return (tokens);
}

