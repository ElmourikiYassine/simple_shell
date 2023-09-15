#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>

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
	int (*func)(char **tokens, int *exit_status, int cycle_count, char **argv);

} built_in_cmd;

char **process_input(char *line, int *token_count, char *exe_name, int *exit_status, int cycle_count, char **argv);
int execute_command(char *exe_path,char **env, char **tokens, char *shell_name);
int handle_build_in_commmand(char **tokens, int *exit_status, int cycle_count, char **argv);
int handle_exit_command(char **tokens, int *exit_status, int cycle_count, char **argv);
int handle_env_command(char **tokens, int *exit_status, int cycle_count, char **argv);
char *get_PATH(char **env);
char *find_executable(char **env, char *file_path, char *exe_name);
void free_state(char **tokens, char *exe_path);
void signal_handler(int signum);

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strstr(char *haystack, char *needle);
char *_strchr(char *s, char c);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);



#endif
