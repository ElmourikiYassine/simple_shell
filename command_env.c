#include "main.h"
/**
 * handle_env_command - Print the enviroment
 * @env: Pointer of the enviroment variables.
 * Return: Always return 1
*/
extern char **environ;

int handle_env_command(char **tokens, int *exit_status, int cycle_count, char **argv)
{
	int i = 0;
	(void) tokens;
	(void) exit_status;
	(void) cycle_count;
	(void) argv;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
