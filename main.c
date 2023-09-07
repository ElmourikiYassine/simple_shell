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
	char **tokens = (char **) malloc(sizeof(char *) * 90);
	int token_count = 0;
	int executable_is_found = 0;
	(void)argc;

	printf("$ ");
	while ((nread = getline(&line, &len, stdin)) != -1)
	{
		if (nread > 0 && line[nread - 1] == '\n')
			/* Remove the newline character */
			line[nread - 1] = '\0'; 

		tokens = process_input(line, tokens,
				&token_count, env, &executable_is_found);

		execute_command(tokens, argv);

		printf("$ ");

	}


	free(line);
	free(tokens);
	return (0);
}

