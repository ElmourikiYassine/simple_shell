#include "main.h"
/**
 * process_input - process and execute user input
 * @line: The user input line to processed
 * Return: Void
 */
void process_input(char *line)
{
		char *tokens[64];
		char *token;
		int token_count;

		token = strtok(line, " ");

		while (token != NULL)
		{
		tokens[token_count++] = token;
		token = strtok(NULL, " ");
		}

		tokens[token_count] = NULL;
		execute_command(tokens);
}
