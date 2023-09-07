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
		int *token_count, char **env,
		int *executable_is_found,
		char *exe_path_name)
{
	char *token;
	char *executable_name;

	*token_count = 0;

	executable_name = strtok(line, " ");
	token = executable_name;

	while (token != NULL)
	{
		tokens[*token_count] = strdup(token);
		(*token_count)++;
		token = strtok(NULL, " ");
	}
	tokens[*token_count] = NULL;

	/* the only reason this func is called here is we need strtok()  call
	 * and this is the place we do that
	 * */

	    if (*token_count > 0)
	    {
		*executable_is_found = find_executable(env, executable_name, exe_path_name);
	    }

	return (tokens);
}

