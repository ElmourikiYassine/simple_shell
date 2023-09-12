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

char **process_input(char *line, int *token_count, char *exe_name);
void execute_command(char *exe_path, char **tokens, char *shell_name);
int handle_exit_command(char *line);
char *get_PATH(char **env);
char *find_executable(char **env, char *file_path, char *exe_name);
void free_state(char **tokens, char *exe_path);
char *get_PATH(char **env);
void signal_handler(int signum);

#endif
