#include "main.h"

/**
 * process_input - Process and execute user input
 * @line: The user input line to be processed
 * @token_count: A pointer to an integer that will hold the number of tokens
 * @exe_name: A buffer to store the executable name
 *
 * Return: (char **) An array of tokens.
 */

/***********-> This how it works <-*************/
/***********************************************
*
*	echo "123 456 789" "simple shell shell"
*
*	token from strtok by (" ", "\t", "\n", "\r")
*
*	token from strtok : echo
*	token from strtok : "123
*	token from strtok : 456
*	token from strtok : 789"
*	token from strtok : "simple
*	token from strtok : shell
*	token from strtok : shell"
*
*	vvvvvvvvvv then it become vvvvvvv
*
*	token [0] -> echo
*	token [1] -> 123 456 789
*	token [2] -> yassine el mouriki
*
**********************************************
*/

char **process_input(char *line, int *token_count, char *exe_name)
{
	char **tokens = (char **)malloc(sizeof(char *) * SIZE_TOKEN);
	char *token;
	char *rest = line;
	int in_quotes = 0;
	char *end_quote;
	int is_built_in_command = 0;

	*token_count = 0;
	while ((token = strtok(rest, " \t\n\r")) != NULL)
	{
		rest = NULL; /* Set to NULL for subsequent calls to strtok */

		if (token[0] == '\'' || token[0] == '"')
		{
			/* Token starts with a quote, handle quoted string */
			in_quotes = (token[0] == '\'') ? 1 : 2;
			token++; /* <- next letter */
			end_quote = strchr(token, (in_quotes == 1) ? '\'' : '"');

			if (end_quote != NULL)
			{
				/* Terminate the quoted string */
				*end_quote = '\0';
				tokens[*token_count] = _strdup(token);
				(*token_count)++;
				in_quotes = 0;
			}
			else
			{
				/* Unmatched quote, treat as a regular token */
				tokens[*token_count] = _strdup(token);
				(*token_count)++;
			}
		}
		else
		{
			/* Regular token (no quotes) */
			if (in_quotes)
			{
				/* Append to the previous token if inside quotes */
				end_quote = _strchr(token, (in_quotes == 1) ? '\'' : '"');
				if (end_quote != NULL)
					*end_quote = '\0';
				_strcat(tokens[*token_count - 1], " ");
				_strcat(tokens[*token_count - 1], token);
			}
			else
			{
				tokens[*token_count] = strdup(token);
				(*token_count)++;
			}
		}
	}
	tokens[*token_count] = NULL;

	if (*token_count > 0)
	{
		/* The first token is the executable name */
		strcpy(exe_name, tokens[0]);
	}

	is_built_in_command = handle_build_in_commmand(tokens);

	if (is_built_in_command)
		return (NULL);
	else
		return (tokens);

}
