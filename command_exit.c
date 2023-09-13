#include "main.h"
/**
 * handle_exit_command - handle exit command
 * @line: the user input
 * Return: return 1 if command was exit otherwise return 0
*/
int handle_exit_command(char **tokens)
{
	(void) tokens; /* not used here but necessary in other funcs */

	exit(1);
	return (0);
}
