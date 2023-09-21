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

void concatenate_error_message(char *error_message, const char *program_name,
	int cycle_count, const char *command)
{
	int len = 0, i;
	int cycle = cycle_count;
	int cycle_digits = 1;
	const char *not_found_msg = ": not found\n";

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
	while (*command != '\0')
		error_message[len++] = *command++;

	while (*not_found_msg != '\0')
		error_message[len++] = *not_found_msg++;

	error_message[len] = '\0';
}

