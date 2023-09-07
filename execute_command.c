#include "main.h"

/**
 * execute_command - execute a command with its arguments
 * @tokens: An array of string representing the command
 * @argv: The arguments passed with in the main function
 * so we can match the output demanded.
 *
 * Return: Void
 */
void execute_command(char *exe_path_name, char *tokens[], char **argv) {
    int wstatus, exit_status;
    pid_t child_pid;

    if (exe_path_name == NULL) {
        fprintf(stderr, "Error: exe_path_name is NULL\n");
        exit(1);
    }

    child_pid = fork();

    if (child_pid == -1) {
        perror("Fork error");
        exit(1);
    } else if (child_pid == 0) {
        /* Child process */
        if (execve(exe_path_name, tokens, NULL) == -1) {
            perror(argv[0]);
            exit(1);
        }
    } else {
        /* Parent process */
        wait(&wstatus);
        if (WIFEXITED(wstatus)) {
            exit_status = WEXITSTATUS(wstatus);
            printf("Child exited with status %d\n", exit_status);
        }
    }
}
