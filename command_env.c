#include "main.h"

/**
 * handle_env_command - Print the environment.
 *
 * @tokens: Pointer to an array of tokens.
 * @exit_status: Pointer to the exit status.
 * @cycle_count: The cycle count.
 * @argv: Pointer to the command arguments.
 *
 * Return: Always returns 1.
 */

int handle_env_command(char **tokens, int *exit_status,
			int cycle_count, char **argv)
{
	int i = 0;
	(void)tokens;
	(void)exit_status;
	(void)cycle_count;
	(void)argv;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}

