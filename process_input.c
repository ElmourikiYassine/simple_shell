#include "main.h"

/**
 * process_input - process and execute user input
 * @line: The user input line to processed
 * @token_count: The number of elements in the tokens array.
 * @exe_name: <-- TODO -->
 * Return: The tokens.
 */

char **process_input(char *line, int *token_count, char *exe_name)
{
	char **tokens = (char **)malloc(sizeof(char *) * SIZE_TOKEN);
	char *token, *rest = line, *end_quote;
	int in_quotes = 0;
	*token_count = 0;

	while ((token = strtok(rest, " \t\n\r")) != NULL)
	{
		rest = NULL;
		if (token[0] == '\'' || token[0] == '"')
		{
			in_quotes = (token[0] == '\'') ? 1 : 2;
			token++;
			end_quote = strchr(token, (in_quotes == 1) ? '\'' : '"');

			if (end_quote != NULL)
			{
				*end_quote = '\0';
				tokens[*token_count] = strdup(token);
				(*token_count)++;
				in_quotes = 0;
			}
			else
			{
				tokens[*token_count] = strdup(token);
				(*token_count)++;
			}
		}
		else
		{
			if (in_quotes)
			{
				end_quote = strchr(token, (in_quotes == 1) ? '\'' : '"');
				if (end_quote != NULL)
					*end_quote = '\0';

				strcat(tokens[*token_count - 1], " ");
				strcat(tokens[*token_count - 1], token);
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
		strcpy(exe_name, tokens[0]);

	return (tokens);
}
