#include "main.h"

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 *
 * Return: Always 0
 */
int main(int argc, char **argv, char **env)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char **tokens;
	int token_count = 0;
	int executable_is_found = 0;
	char *exe_path_name;
	(void)argc;

	exe_path_name = (char *)malloc(1024 + 1);
	tokens = (char **)malloc(sizeof(char *) * 90);

        if (exe_path_name == NULL || tokens == NULL)
	{
		perror("Memory allocation failed");
		return (-1);
        }

	printf("$ ");
	while ((nread = getline(&line, &len, stdin)) != -1)
	{
		if (nread > 0 && line[nread - 1] == '\n')
			line[nread - 1] = '\0';
			/* Remove the newline character */

		if (handle_exit_command(line)) {
		    free(line);
		    free(exe_path_name);
		    free(tokens);
		    exit(0);
		}

		tokens = process_input(line, tokens, &token_count,
					env, &executable_is_found, exe_path_name);


		if (1)
			execute_command(exe_path_name, tokens, argv);

		printf("$ ");
	}
	    free(line);
	    free(exe_path_name);
	    free(tokens);
	return (0);
}
