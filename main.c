#include "main.h"

/**
 * print_prompt - Print a prompt if STDIN is a terminal
 * @str: Prompt string
 *
 * Return: None
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
 * Returns: Nothing
 * Description: Performs any necessary initialization for the program,
 *              such as setting up signal handlers.
 */
void init_program(void)
{
	signal(SIGINT, signal_handler);
	/* Additional initialization code if needed */
	print_prompt("$ ");
}

/**
 * split_input_line - Splits an input line into tokens
 * @env: The environment variables
 * @argv: The command-line arguments
 * @line: The input line
 * @exe_name: The name of the executable
 * @cycle_count: The current cycle count
 * @exit_status: A pointer to the exit status.
 * Returns: Nothing
 *
 * Description: Splits an input line into tokens,
 *              and executes the corresponding command.
 */
void split_input_line(
		char **env,
		char **argv,
		char *line,
		char *exe_name,
		int cycle_count,
		int *exit_status)
{
	char **tokens;
	int token_count;
	char *exe_path;
	char *err_msg = (char *)malloc(SIZE_LINE);

	exe_path = (char *)malloc(sizeof(char) * SIZE_PATH);

	_memset(exe_name, 0, SIZE_TOKEN);
	tokens = process_input(line, &token_count, exe_name,
				exit_status, cycle_count, argv);

	if (token_count > 0 && tokens != NULL)
	{
		find_executable(env, tokens[0], exe_name, exe_path);
		if (_strchr(exe_path, '/'))
		{
			*exit_status = execute_command(exe_path, env,
					tokens, token_count, argv[0]);
		}
		else
		{
			concatenate_error_message(err_msg, argv[0],
					cycle_count, tokens[0]);
			write(STDERR_FILENO, err_msg, _strlen(err_msg));

			if (!isatty(STDIN_FILENO))
				exit(127);
		}
	}
	free(err_msg);
	free(exe_path);
}

/**
 * handle_user_input - Function to handle user input and execution
 * @env: The environment variables
 * @argv: The command-line arguments
 *
 * Returns: Nothing
 *
 * Description: Reads user input,
 *              splits it into tokens,
 *              and executes the corresponding command.
 */

void handle_user_input(char **env, char **argv)
{
	char exe_name[SIZE_TOKEN];
	int cycle_count = 1;
	int in_double_quotes = 0;
	int in_single_quotes = 0;
	char *multiline_buffer = NULL;
	char *line_buffer = NULL;
	size_t buffer_size = SIZE_LINE;
	size_t buffer_index = 0;
	size_t line_buffer_size = SIZE_LINE;
	ssize_t i;

	int *exit_status = (int *)malloc(sizeof(int));

	multiline_buffer = (char *)malloc(buffer_size);

	if (multiline_buffer == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	line_buffer = (char *)malloc(line_buffer_size);
	if (line_buffer == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		ssize_t read_chars = getline(&line_buffer, &line_buffer_size, stdin);

		if (read_chars == -1)
			break;

		for (i = 0; i < read_chars; i++)
		{
			char input_char = line_buffer[i];

			if (input_char == '"' && in_double_quotes == 0 && !in_single_quotes)
				in_double_quotes = 1;
			else if (input_char == '"' && in_double_quotes == 1 && !in_single_quotes)
				in_double_quotes = 0;
			else if (input_char == '\'' && in_single_quotes == 0 && !in_double_quotes)
				in_single_quotes = 1;
			else if (input_char == '\'' && in_single_quotes == 1 && !in_double_quotes)
				in_single_quotes = 0;
			else if (input_char == '\n' && !in_double_quotes && !in_single_quotes)
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
					if (multiline_buffer == NULL)
					{
						perror("Memory allocation failed");
						exit(EXIT_FAILURE);
					}
				}
			}
			if (input_char == '\n' && (in_double_quotes || in_single_quotes))
				print_prompt("> ");
		}
	}
	free(line_buffer);
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
 * Description: The main entry point of the program.
 *              Initializes the program and handles user input.
 */
int main(int argc, char **argv, char **env)
{
	(void)argc;

	init_program();
	handle_user_input(env, argv);

	return (EXIT_SUCCESS);
}
