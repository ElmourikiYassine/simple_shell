#include "main.h"

/**
 * process_input - Process and execute user input
 * @line: The user input line to be processed
 * @token_count: A pointer to an integer that will hold the number of tokens
 * @exe_name: A buffer to store the executable name
 *
 * Return: (char **) An array of tokens.
 */
char **process_input(char *line, int *token_count, char *exe_name, int *exit_status, int cycle_count, char **argv)
{
    char **tokens = (char **)malloc(sizeof(char *) * SIZE_TOKEN);
    char *token;
    char *rest = line;
    int is_built_in_command = 0;

    /*int i = 0;*/

    *token_count = 0;
/*	printf("the LINE : %s\n", line);*/

    while ((token = strtok(rest, " ")) != NULL)
    {
        rest = NULL; /* Set to NULL for subsequent calls to strtok */

        if (token[0] == '\'' || token[0] == '"')
        {
            char *closing_quote = strchr(token + 1, token[0]);

            if (closing_quote != NULL)
            {
                *closing_quote = '\0';
                tokens[*token_count] = strdup(token + 1);
                (*token_count)++;
            }
            else
            {
                tokens[*token_count] = strdup(token);
                (*token_count)++;
            }
        }
        else
        {
            tokens[*token_count] = strdup(token);
            (*token_count)++;
        }
    }

    tokens[*token_count] = NULL;
/*
	printf("-------------------\n");
    while (tokens[i] != NULL)
    {
	    printf("tk[%d] -> %s\n", i, tokens[i]);
	    i++;
    }
	printf("-------------------\n");
*/
    if (*token_count > 0)
    {
        strcpy(exe_name, tokens[0]);
    }

    is_built_in_command = handle_build_in_commmand(tokens, exit_status, cycle_count, argv);

    if (is_built_in_command)
        return (NULL);
    else
        return (tokens);
}

