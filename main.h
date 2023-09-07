#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>

char **process_input(char *line, char **tokens,
		int *token_count, char **env,
		int *executable_is_found,
		char *exe_path_name);
void execute_command(char *exe_path_name, char *tokens[], char **argv);
int handle_exit_command(char *line);
int find_executable(char **env, char *exe, char *exe_path_name);


#endif

