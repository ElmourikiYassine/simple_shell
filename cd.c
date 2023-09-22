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
void error_msg(char *error_message, const char *program_name,
		int cycle_count, const char *command)
{
	int len = 0, i;
	int cycle = cycle_count;
	int cycle_digits = 1;
	const char *not_found_msg = "cd: can't cd to ";

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

	while (*not_found_msg != '\0')
		error_message[len++] = *not_found_msg++;

	while (*command != '\0')
		error_message[len++] = *command++;

	error_message[len++] = '\n';
	error_message[len] = '\0';
}

/**
 * _getenv - Get the value of an environment variable.
 *
 * @name: The name of the environment variable to retrieve.
 *
 * Return: A pointer to the value of the environment variable,
 * or NULL if not found.
 */
char *_getenv(const char *name)
{
	int i;

	if (name == NULL || environ == NULL)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++)
	{
		char *env_var = environ[i];
		int j = 0;

		while (name[j] != '\0' && env_var[j] == name[j])
			j++;

		if (name[j] == '\0' && env_var[j] == '=')
			return (env_var + j + 1);
	}

	return (NULL);
}

/**
 * handle_cd_command - Change the current directory.
 *
 * @tokens: Pointer to an array of tokens.
 * @exit_status: Pointer to the exit status.
 * @cycle_count: The cycle count.
 * @argv: Pointer to the command arguments.
 *
 * Return: 0 on success, -1 on failure.
 */
int handle_cd_command(char **tokens, __attribute__((unused)) int *exit_status,
			int cycle_count, char **argv)
{
	char *new_directory;
	char current_directory[SIZE_PATH];

	if (tokens[1] == NULL || tokens[2] != NULL)
	{
		new_directory = getenv("HOME");
		if (new_directory == NULL)
			getcwd(new_directory, SIZE_PATH);
	}
	else if (_strcmp(tokens[1], "-") == 0)
	{
		new_directory = getenv("OLDPWD");
		if (new_directory == NULL)
			getcwd(new_directory, SIZE_PATH);
	}
	else
		new_directory = tokens[1];
	if (getcwd(current_directory, SIZE_PATH) == NULL)
	{
		perror("getcwd");
		return (-1);
	}
	if (chdir(new_directory) == -1)
	{
		char *error_message = (char *)malloc(SIZE_LINE);

		error_msg(error_message, argv[0],
				cycle_count, new_directory);
		write(STDERR_FILENO, error_message, _strlen(error_message));
		free(error_message);
		return (-1);
	}
	setenv("OLDPWD", current_directory, 1);
	setenv("PWD", new_directory, 1);
	if (_strcmp(tokens[1], "-") == 0)
	{
		write(STDOUT_FILENO, new_directory, _strlen(new_directory));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

