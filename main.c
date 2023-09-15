#include "main.h"

/**
 * init_program - Function to handle program initialization
 * Returns: Nothing
 * Description: Performs any necessary initialization for the program,
 * such as setting up signal handlers.
 */
void init_program(void)
{
	char *exe_path = (char *)malloc(SIZE_PATH + 1);

	signal(SIGINT, signal_handler);
	if (exe_path == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	/* Additional initialization code if needed */
	if (isatty(STDIN_FILENO))
	{
		printf("$ ");
		fflush(stdout);
	}
}

/**
 * split_input_line - Splits an input line into tokens
 * @env: The environment variables
 * @argv: The command-line arguments
 * @line: The input line
 * @exe_name: The name of the executable
 * @cycle_count: The current cycle count
 *
 * Returns: Nothing
 *
 * Description: Splits an input line into tokens,
 * and executes the corresponding command.
 */
void split_input_line(char **env, char **argv,char *line, char *exe_name, int cycle_count, int *exit_status)
{
	char **tokens;
	int token_count;
	char *exe_path;

	memset(exe_name, 0, SIZE_TOKEN);
	tokens = process_input(line, &token_count, exe_name, exit_status, cycle_count, argv);

	if (token_count > 0 && tokens != NULL)
	{
		exe_path = find_executable(env, tokens[0], exe_name);
		if (exe_path)
			*exit_status = execute_command(exe_path, env, tokens, argv[0]);
		else
		{
			if (isatty(STDIN_FILENO))
			{	
				fprintf(stderr, "%s: %d: %s: not found\n", argv[0], cycle_count, tokens[0]);
			}
			else
			{
				fprintf(stderr, "%s: %d: %s: not found\n", argv[0], cycle_count, tokens[0]);
				exit(127);
			}
		}
	}
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
    char exe_name[SIZE_TOKEN];
    int cycle_count = 1;
    int in_double_quotes = 0;
    char *multiline_buffer = NULL;
    char input_char;
    size_t buffer_size = SIZE_LINE;
    size_t buffer_index = 0;
    int *exit_status = (int *)malloc(sizeof(int));

    multiline_buffer = (char *)malloc(buffer_size);
    if (multiline_buffer == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        input_char = getchar();

        if (input_char == EOF)
	{
            break;
        }
	else if (input_char == '"' && in_double_quotes == 0)
	{
            in_double_quotes = 1;
        } 
	else if (input_char == '"' && in_double_quotes == 1)
	{
            in_double_quotes = 0;
        }
	else if (input_char == '\n' && in_double_quotes == 0)
	{
            multiline_buffer[buffer_index] = '\0';
            split_input_line(env, argv, multiline_buffer, exe_name, cycle_count, exit_status);
            buffer_index = 0;
            cycle_count++;
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			fflush(stdout);
		}
        }
	else
	{
            multiline_buffer[buffer_index] = input_char;
            buffer_index++;

            if (buffer_index >= buffer_size) {

                buffer_size *= 2;
                multiline_buffer = realloc(multiline_buffer, buffer_size);
                if (multiline_buffer == NULL) {
                    perror("Memory allocation failed");
                    exit(EXIT_FAILURE);
                }
            }
        }
    }

    free(multiline_buffer);
}

/**
 * main -Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 * @env: The environment variables
 *
 * Return: (0) Always 0
 *
 * Description: The main entry point of the program.
 * Initializes the program and handles user input.
 */
int main(int argc, char **argv, char **env)
{
	(void)argc;

	init_program();
	handle_user_input(env, argv);

	return (EXIT_SUCCESS);
}

