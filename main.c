#include "main.h"

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 * @env: <-- TODO -->

 * Return: Always 0
 */

int main(int argc, char **argv, char **env)
{
	char *line = NULL, **tokens, exe_name[SIZE_TOKEN], *exe_path;
	size_t n = 0;
	ssize_t nread;
	int token_count, cycle_count = 1, i;
	(void)argc;

	signal(SIGINT, signal_handler);
	exe_path = (char *)malloc(SIZE_PATH + 1);

	if (exe_path == NULL)
	{
		perror("Memory allocation failed");
		return (EXIT_FAILURE);
	}

	if (isatty(STDIN_FILENO))
	{
		printf("$ ");
		fflush(stdout);
	}

	while ((nread = getline(&line, &n, stdin)) != -1)
	{
		if (nread > 0 && line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		if (handle_exit_command(line))
			break;

		memset(exe_name, 0, strlen(exe_name));
		tokens = process_input(line, &token_count, exe_name);

		i = 0;
		while (tokens[i] != NULL)
			i++;

		if (token_count > 0)
		{
			exe_path = find_executable(env, tokens[0], exe_name);
			if (exe_path)
				execute_command(exe_path, tokens, argv[0]);
			else
				fprintf(stderr, "%s: %d: %s: not found\n",
				argv[0], cycle_count, tokens[0]);
		}

		cycle_count++;

		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			fflush(stdout);
		}
	}

	if (feof(stdin))
	{
		printf("\n");
		fflush(stdout);
	}

	free(line);
	return (EXIT_SUCCESS);
}
