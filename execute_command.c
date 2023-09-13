#include "main.h"

/**
 * execute_command - Execute a command with its arguments
 * @exe_name: The full path to the executable
 * @tokens: An array of strings representing the command and its arguments
 * @shell_name: The name of the shell program
 *
 * Return: void
 */

void execute_command(char *exe_path,char **env, char **tokens, char *shell_name)
{
	int wstatus, exit_status;
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Fork error");
		exit(1);
	}
	else if (child_pid == 0)
	{
		/* Child process */
		if (execve(exe_path, tokens, env) == -1)
		{
			perror(shell_name);
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

