#include "main.h"
/**
 * handle_build_in_commmand - check and execute built-in commands
 * @tokens: Array of command tokens.
 * Return: 1 if a built-in command was execute, 0 otherwise.
*/
int handle_build_in_commmand(char **tokens,  int *exit_status, int cycle_count, char **argv)
{
	char *name_built_in = tokens[0];
	int i = 0;
	built_in_cmd cmds[] = {
		{ "exit", handle_exit_command},
		{ "env", handle_env_command},
		{NULL, NULL}
	};

	if (tokens == NULL || tokens[0] == NULL)
		return (0);

	while (cmds[i].func != NULL)
	{
		if (strcmp(name_built_in, cmds[i].name) == 0)
		{
			cmds[i].func(tokens, exit_status, cycle_count, argv);
			return (1);
		}
		i++;
	}
	return (0);
}

