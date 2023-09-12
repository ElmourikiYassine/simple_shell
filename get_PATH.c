#include "main.h"
/**
 * get_PATH - Get the value of the PATH environment variable
 * @env: The environment variables
 *
 * Return: (char *) The value of the PATH variable if found, NULL otherwise
 */
char *get_PATH(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		char *env_var = env[i];

		if (strstr(env_var, "PATH=") == env_var)
			return (env_var + 5);

		i++;
	}

	return (NULL);
}
