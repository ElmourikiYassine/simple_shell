#include "main.h"

/**
 * split_line - Split a string into tokens.
 *
 * @line: the string to be split.
 * @tokens: the tokens.
 *
 * Return: An array of tokens.
*/
char **split_line(char *line, char **tokens)
{
	char *token;
	char *rest = line;
	int token_count = 0;

	while ((token = _strtok(rest, " ")) != NULL)
	{
		rest = NULL; /* Set to NULL for subsequent calls to strtok */
		if (token[0] == '\'' || token[0] == '"')
		{
			char *closing_quote = _strchr(token + 1, token[0]);

			if (closing_quote != NULL)
			{
				*closing_quote = '\0';
				tokens[token_count] = _strdup(token + 1);
				token_count++;
			}
			else
			{
				tokens[token_count] = _strdup(token);
				token_count++;
			}
		}
		else
		{
			tokens[token_count] = _strdup(token);
			token_count++;
		}
	}
	tokens[token_count] = NULL;
	return (tokens);
}

/**
 * process_input - Process and execute user input.
 * @line: The user input line to be processed.
 * @token_count: A pointer to an integer that will hold the number of tokens.
 * @exe_name: A buffer to store the executable name.
 * @exit_status: A pointer to the exit status.
 * @tokens: the tokens.
 * @cycle_count: The cycle count.
 * @argv: Pointer to the command arguments.
 * @is_built_in: boolean.
 * Return: (char **) An array of tokens.
 */

void process_input(char *line, int *token_count, char *exe_name,
	int *exit_status, int cycle_count, char **argv, char **tokens,
	int *is_built_in)
{

	split_line(line, tokens);

	*token_count = count_tokens(tokens);

	if (*token_count > 0)
		_strcpy(exe_name, tokens[0]);

	*is_built_in = handle_build_in_commmand(tokens,
			exit_status, cycle_count, argv);
}

