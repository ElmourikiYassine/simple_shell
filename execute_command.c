#include "main.h"
/**
 * execute_command - execute a command with its arguments
 * @tokens: An array of string representing the command
 * Return: Void
 */
void execute_command(char *tokens[])
{
	int wstatus, exit_status;
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error: ");
		exit(1);
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
			(void)exit_status;
		}
	}
}
