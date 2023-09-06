#include "main.h"
/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	int wstatus;
	int exit_status;
	char *tokens[64];
	char *token;
	int token_count;
	pid_t child_pid;

	(void) argc;
	(void) argv;

	printf("$ ");
	while ((nread = getline(&line, &len, stdin)) != -1)
	{
		if (nread > 0 && line[nread - 1] == '\n')
		{
			line[nread - 1] = '\0'; /* Remove the newline character */
		}

		token = strtok(line, " ");
		token_count = 0;

		while (token != NULL)
		{
			tokens[token_count++] = token;
			token = strtok(NULL, " ");
		}

		tokens[token_count] = NULL;

		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Error: ");
			return (1);
		}
		else if (child_pid == 0)
		{
			/* Child process */

			if (execve(tokens[0], tokens, NULL) == -1)
			{
				perror("Error: ");
				exit(1);
			}
		}
		else
		{
			/* Parent process */

			wait(&wstatus);

			if (WIFEXITED(wstatus))
			{
				exit_status = WEXITSTATUS(wstatus);
				(void) exit_status;
			}
		}

		printf("$ ");
	}

	free(line);
	return (0);
}

