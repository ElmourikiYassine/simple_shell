#include "main.h"

/**
 * handle_setenv_command - Set or modify an environment variable.
 *
 * @tokens: Pointer to an array of tokens.
 * @exit_status: Pointer to the exit status.
 * @cycle_count: The cycle count.
 * @argv: Pointer to the command arguments.
 *
 * Return: 0 on success, -1 on failure.
 */
int handle_setenv_command(char **tokens, int *exit_status,
			int cycle_count, char **argv)
{
	(void) exit_status;
	(void) cycle_count;
	(void) argv;

	if (tokens[1] == NULL || tokens[2] == NULL || tokens[3] != NULL)
	{
		write(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n", 30);
		return (-1);
	}

	if (setenv(tokens[1], tokens[2], 1) == -1)
	{
		write(STDERR_FILENO, "setenv: Error setting environment variable\n", 43);
		return (-1);
	}

	return (0);
}

/**
 * handle_unsetenv_command - Unset an environment variable.
 *
 * @tokens: Pointer to an array of tokens.
 * @exit_status: Pointer to the exit status.
 * @cycle_count: The cycle count.
 * @argv: Pointer to the command arguments.
 *
 * Return: 0 on success, -1 on failure.
 */
int handle_unsetenv_command(char **tokens, int *exit_status,
				int cycle_count, char **argv)
{
	(void) exit_status;
	(void) cycle_count;
	(void) argv;

	if (tokens[1] == NULL || tokens[2] != NULL)
	{
		write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 26);
		return (-1);
	}

	if (unsetenv(tokens[1]) == -1)
	{
		write(STDERR_FILENO, "unsetenv: Error unsetting environment variable\n", 47);
		return (-1);
	}
	return (0);
}

