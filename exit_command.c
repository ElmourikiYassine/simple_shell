#include "main.h"
/**
 * handle_exit_command - handle exit command
 * @line: the user input
 * Return: return 1 if command was exit otherwise return 0
*/
int handle_exit_command(char *line)
{
	if (strcmp(line, "exit") == 0)
		return (1);

	return (0);
}
