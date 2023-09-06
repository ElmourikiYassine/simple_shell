#include "main.h"
/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 * Return: Always 0
 */

int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	(void)argc;
	(void)argv;

	printf("$ ");
	while ((nread = getline(&line, &len, stdin)) != -1)
	{
		if (nread > 0 && line[nread - 1] == '\n')
			line[nread - 1] = '\0'; /* Remove the newline character */

		process_input(line);
		printf("$ ");
	}

	free(line);
	return (0);
}
