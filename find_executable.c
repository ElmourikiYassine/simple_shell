#include "main.h"

/**
 * find_executable - Find the full path of
 * an executable in the PATH environment.
 *
 * @env: The environment variables.
 * @file_path: The name of the executable file.
 * @exe_path: The executable file.
 * @exe_name: The name of the executable.
 *
 * Return: (char *) The full path of the executable if found, NULL otherwise.
 */
char *find_executable(char **env, char *file_path,
		char *exe_name, char *exe_path)
{
	char *paths;
	char *path_parsed;
	char path_parsed_cat[SIZE_PATH];
	char *paths_copy;
	struct stat file_stat;

	paths = get_PATH(env);

	if (stat(file_path, &file_stat) == 0 && _strchr(file_path, '/'))
	{
		_strcpy(exe_path, file_path);
		return (exe_path);
	}

	else if (paths != NULL)
	{
		paths_copy = _strdup(paths);
		path_parsed = _strtok(paths_copy, ":");

		while (path_parsed != NULL)
		{
			_strcpy(path_parsed_cat, path_parsed);
			_strcat(path_parsed_cat, "/");
			_strcat(path_parsed_cat, exe_name);

			if (stat(path_parsed_cat, &file_stat) == 0)
			{
				_strcpy(exe_path, path_parsed_cat);
				free(paths_copy);
				return (exe_path);
			}
			path_parsed = _strtok(NULL, ":");
		}
	}
	free(paths_copy);
	return (NULL);
}

/**
 * get_PATH - Get the value of the PATH environment variable.
 * @env: The environment variables.
 * Return: (char *) The value of the PATH variable if found, NULL otherwise.
 */
char *get_PATH(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		char *envVar = env[i];

		if (_strstr(envVar, "PATH=") == envVar)
			return (envVar + 5);
		i++;
	}
	return (NULL);
}

