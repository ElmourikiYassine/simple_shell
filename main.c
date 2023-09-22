#include "main.h"

/**
 * print_prompt - Print a prompt if STDIN is a terminal
 * @str: Prompt string
 */
void print_prompt(char *str)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDIN_FILENO, str, 2);
		fflush(stdout);
	}
}

/**
 * init_program - Function to handle program initialization
 *
 * Returns: Nothing
 *
 * Description: Performs any necessary initialization for the program,
 * such as setting up signal handlers.
 */
void init_program(void)
{
	signal(SIGINT, signal_handler);
	print_prompt("$ ");
}

/**
 * split_input_line - Splits an input line into tokens
 * @env: The environment variables
 * @argv: The command-line arguments
 * @line: The input line
 * @exe_name: The name of the executable
 * @cycle_count: The current cycle count
 * @exit_status: the exit code for exiting.
 *
 * Returns: Nothing
 *
 * Description: Splits an input line into tokens,
 * and executes the corresponding command.
 */
void split_input_line(char **env, char **argv,
					char *line, char *exe_name, int cycle_count, int *exit_status)
{
	char *exe_path = (char *)malloc(sizeof(char) * SIZE_PATH);
	char **tokens = (char **)malloc(sizeof(char *) * SIZE_TOKEN);
	char *err_msg = (char *)malloc(sizeof(char *) * SIZE_TOKEN);
	int is_built_in, token_count;

	_memset(exe_name, 0, SIZE_TOKEN);
	process_input(line, &token_count, exe_name, exit_status,
					cycle_count, argv, tokens, &is_built_in);

	if (token_count > 0 && tokens != NULL && !is_built_in)
	{
		exe_path = find_executable(env, tokens[0], exe_name, exe_path);
		if (exe_path)
			*exit_status = execute_command(exe_path, env, tokens, argv[0]);
		else
		{
			concatenate_error_message(err_msg, argv[0],
					cycle_count, tokens[0]);
			write(STDERR_FILENO, err_msg, _strlen(err_msg));
			if (!isatty(STDIN_FILENO))
				exit(127);

		}
	}
	free(exe_path);
	free_tokens(tokens);
	free(tokens);
	free(err_msg);
}

/**
 * handle_user_input - Function to handle user input and execution
 * @env: The environment variables
 * @argv: The command-line arguments
 *
 * Returns: Nothing
 *
 * Description: Reads user input,
 * splits it into tokens,
 * and executes the corresponding command.
 */

void handle_user_input(char **env, char **argv)
{
	int cycle_count = 1, in_double_quotes = 0;
	char exe_name[SIZE_TOKEN], *multiline_buffer = NULL, input_char;
	size_t buffer_size = SIZE_LINE, buffer_index = 0;
	int *exit_status = (int *)malloc(sizeof(int));

	multiline_buffer = (char *)malloc(buffer_size);
	*exit_status = 0;
	while (1)
	{
		input_char = _getline();
		if (input_char == EOF)
			break;
		else if (input_char == '"' && in_double_quotes == 0)
			in_double_quotes = 1;
		else if (input_char == '"' && in_double_quotes == 1)
			in_double_quotes = 0;
		else if (input_char == '\n' && in_double_quotes == 0)
		{
			multiline_buffer[buffer_index] = '\0';
			split_input_line(env, argv, multiline_buffer,
					exe_name, cycle_count, exit_status);
			buffer_index = 0;
			cycle_count++;
			print_prompt("$ ");
		}
		else
		{
			multiline_buffer[buffer_index] = input_char;
			buffer_index++;
			if (buffer_index >= buffer_size)
			{
				buffer_size *= 2;
				multiline_buffer = _realloc(multiline_buffer, buffer_size);
			}
		}
	}
	free(multiline_buffer);
	free(exit_status);
}

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 * @env: The environment variables
 *
 * Return: (0) Always 0
 *
 */
int main(int argc, char **argv, char **env)
{
	(void)argc;

	init_program();
	handle_user_input(env, argv);
	return (EXIT_SUCCESS);
}
