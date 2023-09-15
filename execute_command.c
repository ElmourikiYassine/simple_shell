#include "main.h"

/**
 * execute_command - Execute a command with its arguments
 * @exe_path: The full path to the executable
 * @env: <--TODO-->
 * @tokens: An array of strings representing the command and its arguments
 * @shell_name: The name of the shell program
 *
 * Return: void
 */
int execute_command(char *exe_path,char **env, char **tokens, char *shell_name)
{
	int wstatus;
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Fork error");
		exit(errno);
	}
	else if (child_pid == 0)
	{
		
		child_pid = getpid();
		/* Child process */
		if (execve(exe_path, tokens, env) == -1)
		{
			perror(shell_name);
			_exit(errno);
		}
	}
	else
	{
		/* Parent process */
		waitpid(child_pid, &wstatus, WCONTINUED);
		if (WIFEXITED(wstatus))
		{
			return  WEXITSTATUS(wstatus);
		}
		else
			return (errno);
	}
	return (0);
}

