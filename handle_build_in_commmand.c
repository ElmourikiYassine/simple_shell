#include "main.h"
/**
 * handle_build_in_commmand - 
 * @tokens:
 * Return: 
*/
int handle_build_in_commmand(char **tokens)
{
	char *name_built_in = tokens[0];
	int i = 0;
	built_in_cmd cmds[] = {
		{ "exit", handle_exit_command },
		{ "env", handle_env_command },
		{NULL, NULL}
	};

	if (tokens == NULL || tokens[0] == NULL)
		return 0;

	while (cmds[i].func != NULL)
	{
		if (strcmp(name_built_in, cmds[i].name) == 0)
		{
			cmds[i].func(tokens);
			return (1);
		}
		i++;
	}
	return (0);
}

