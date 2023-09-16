#include "main.h"

/**
 * execute_command - Execute a command with its arguments.
 *
 * @exe_path: The full path to the executable.
 * @env: Pointer to the environment variables.
 * @tokens: An array of strings representing the command and its arguments.
 * @token_count: The number of tokens.
 * @shell_name: The name of the shell program.
 *
 * Return: Returns the exit status or an error code.
 */
int execute_command(char *exe_path, char **env, char **tokens,
			int token_count, char *shell_name)
{
	int wstatus;
	pid_t child_pid;
	int i;

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

		for (i = 0; i < token_count; i++)
			free(tokens[i]);
		free(tokens);
	}
	else
	{
		/* Parent process */
		waitpid(child_pid, &wstatus, WCONTINUED);
		if (WIFEXITED(wstatus))
		{
			return (WEXITSTATUS(wstatus));
		}
		else
			return (errno);
	}
	return (0);
}

