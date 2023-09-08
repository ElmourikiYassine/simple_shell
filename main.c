#include "main.h"

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 * @env: The environment variables
 *
 * Return: (0) Always 0
 */

int main(int argc, char **argv, char **env)
{
	char *line = NULL;
	size_t n = 0;
	ssize_t nread;
	char **tokens;
	int token_count;
	char *exe_path;
	char *exe_name;
	int cycle_count = 1;
	(void)argc;

	exe_name = (char *)malloc(sizeof(char) * SIZE_TOKEN);
	exe_path = (char *)malloc(SIZE_LINE + 1);
	if (exe_path == NULL || exe_name == NULL)
	{
		perror("Memory allocation failed");
		return (-1);
	}
	printf("$ ");
	while ((nread = getline(&line, &n, stdin)) != -1)
	{
		if (nread > 0 && line[nread - 1] == '\n')
			line[nread - 1] = '\0'; /* Remove the newline character */
		if (handle_exit_command(line))
			exit(0);
		tokens = process_input(line, &token_count, exe_name);
		if (token_count >= 0)
			exe_path = find_executable(env, tokens[0], exe_name);
		if (exe_path)
			execute_command(exe_path, tokens, argv[0]);
		else
		{
			fprintf(stderr, "%s: %d: %s: not found\n",
				argv[0], cycle_count, tokens[0]);
		}
		cycle_count++;
		printf("$ ");
	}
	free(exe_path);
	free(tokens);
	return (0);
}

