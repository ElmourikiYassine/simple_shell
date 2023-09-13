#include "main.h"
/**
 * handle_env_command - Print the enviroment
 * @env: Pointer of the enviroment variables.
 * Return: Always return 1
*/
int handle_env_command(char **env)
{
	int i = 0;

	env = environ;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (1);
}
