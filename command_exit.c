#include "main.h"

/**
 * handle_exit_command - Handle exit command.
 *
 * @tokens: An array of strings of command tokens.
 * @exit_status: Pointer to the exit status.
 * @cycle_count: The cycle count.
 * @argv: Pointer to the command arguments.
 *
 * Return: Always returns 0.
 */
int handle_exit_command(char **tokens, int *exit_status,
			int cycle_count, char **argv)
{
	if (tokens[1] != NULL)
	{
		if (atoi(tokens[1]) <= 0)
		{
			fprintf(stderr, "%s: %d: exit: Illegal number: %s\n",
				argv[0], cycle_count, tokens[1]);
			exit(2);
		}
		else
			exit(atoi(tokens[1]));
	}
	else
		exit(*exit_status);
	return (0);
}

