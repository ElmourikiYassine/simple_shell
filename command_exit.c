#include "main.h"

/**
 * concatenate_error_message - Concatenate error message components
 * @error_message: Buffer to store the error message
 * @program_name: Name of the program
 * @cycle_count: Cycle count
 * @command: Command causing the error
 *
 * Return: None
 */

void concatenate_exit_message(char *error_message, const char *program_name,
	int cycle_count, const char *command)
{
	int len = 0, i;
	int cycle = cycle_count;
	int cycle_digits = 1;
	const char *not_found_msg = "exit: Illegal number: ";

	while (*program_name != '\0')
		error_message[len++] = *program_name++;
	error_message[len++] = ':';
	error_message[len++] = ' ';

	while (cycle / 10 > 0)
	{

		cycle_digits++;
		cycle /= 10;
	}
	for (i = 0; i < cycle_digits; i++)
	{
		error_message[len + cycle_digits - i - 1] = '0' + (cycle_count % 10);
		cycle_count /= 10;
	}
	len += cycle_digits;

	error_message[len++] = ':';
	error_message[len++] = ' ';

	while (*not_found_msg != '\0')
		error_message[len++] = *not_found_msg++;

	while (*command != '\0')
		error_message[len++] = *command++;

	error_message[len++] = '\n';
	error_message[len] = '\0';
}

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
	char *error_message = malloc(sizeof(char) * SIZE_LINE);

	if (tokens[1] != NULL)
	{
		if (atoi(tokens[1]) <= 0)
		{
			concatenate_exit_message(error_message, argv[0],
				cycle_count, tokens[1]);
			write(STDERR_FILENO, error_message, _strlen(error_message));
			_exit(2);
		}
		else
			_exit(_atoi(tokens[1]));
	}
	else
		_exit(*exit_status);

	return (0);
}

