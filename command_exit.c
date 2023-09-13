#include "main.h"
/**
 * handle_exit_command - handle exit command
 * @tokens: An array of strings of command tokens
 * Return: always return 0
*/
int handle_exit_command(char **tokens)
{
	(void) tokens; /* not used here but necessary in other funcs */

	exit(1);
	return (0);
}
