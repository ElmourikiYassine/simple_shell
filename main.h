#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

#define SIZE_TOKEN 90
#define SIZE_LINE 1024
#define SIZE_PATH 1024

extern char **environ;

/**
 * struct built_in_cmd - Represent a built-in command and handler func.
 * @name: the name of the built-in command.
 * @func: A pointer to the func that handles the command.
*/
typedef struct built_in_cmd
{
	char *name;
	int (*func)(char **tokens);

} built_in_cmd;

char **process_input(char *line, int *token_count, char *exe_name);
void execute_command(char *exe_path,char **env, char **tokens, char *shell_name);
int handle_build_in_commmand(char **tokens);
int handle_exit_command(char **tokens);
int handle_env_command(char **tokens);
char *get_PATH(char **env);
char *find_executable(char **env, char *file_path, char *exe_name);
void free_state(char **tokens, char *exe_path);
void signal_handler(int signum);

#endif
