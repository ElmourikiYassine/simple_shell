#include "main.h"

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 * @env: The environment variables
 *
 * Return: (0) Always 0
 */


void signal_handler(int signum)
{
        (void) signum;

        printf("\n$ ");
        fflush(stdout);
}

int main(int argc, char **argv, char **env)
{
        char *line = NULL;
        size_t n = 0;
        ssize_t nread;
        char **tokens;
        int token_count;
        char exe_name[SIZE_TOKEN];
        char *exe_path;
        int cycle_count = 1;
        int i;
        (void) argc;

        signal(SIGINT, signal_handler);
        exe_path = (char *)malloc(SIZE_PATH + 1);
        if (exe_path == NULL)
        {
                perror("Memory allocation failed");
                return (EXIT_FAILURE);
        }
        /**
         * avoid print $ when piping the stdin in ./hsh
         * like this -> echo "/bin/ls" | ./hsh
         * (man is isatty) to know more.
         */
        if (isatty(STDIN_FILENO))
        {
                /**
                 * the fflush is used here to avoid printf buffer
                 * optimization that we saw in printf project
                 */
                printf("$ ");
                fflush(stdout);
        }
        while ((nread = getline(&line, &n, stdin)) != -1)
        {
                if (nread > 0 && line[nread - 1] == '\n')
                {
                        line[nread - 1] = '\0';
                }


                memset(exe_name, 0, strlen(exe_name));
                tokens = process_input(line, &token_count, exe_name);

                i = 0;
                while (tokens[i] != NULL)
                {
                        /* printf("token [%i] -> %s\n", i, tokens[i]); */
                        i++;
                }

                if (token_count > 0)
                {
                        exe_path = find_executable(env, tokens[0], exe_name);
                        if (exe_path)
                        {
                                execute_command(exe_path, tokens, argv[0]);
                        }
                        else
                        {
                                fprintf(stderr, "%s: %d: %s: not found\n",
                                                argv[0], cycle_count, tokens[0]);
                        }
                }

                cycle_count++;

                /**
                 * avoid print $ when piping the stdin in ./hsh
                 * like this -> echo "/bin/ls" | ./hsh
                 *
                 * (man is isatty) to know more.
                 */
                if (isatty(STDIN_FILENO))
                {
                        /**
                         * the fflush is used here to avoid printf buffer
                         * optimization that we saw in printf project
                         */
                        printf("$ ");
                        fflush(stdout);
                }

        }
                printf("\n");
                fflush(stdout);

        free(line);
        return (EXIT_SUCCESS);
}
