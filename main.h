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
typedef struct built_in_cmd
{
	char *name;
	int (*func)(char **tokens, int *exit_status, int cycle_count, char **argv);

} built_in_cmd;

char **process_input(char *line,
		int *token_count,
		char *exe_name,
		int *exit_status,
		int cycle_count,
		char **argv);

int execute_command(char *exe_path,
		char **env,
		char **tokens,
		int token_count,
		char *shell_name);

int handle_build_in_commmand(char **tokens,
		int *exit_status,
		int cycle_count,
		char **argv);

int handle_exit_command(char **tokens,
		int *exit_status,
		int cycle_count,
		char **argv);

int handle_env_command(char **tokens,
		int *exit_status,
		int cycle_count,
		char **argv);

char *get_PATH(char **env);
char *find_executable(char **env, char *file_path,
		char *exe_name, char *exe_path);

void signal_handler(int signum);
int _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);
char *_strcpy(char *dest, const char *src);
char *_strstr(const char *haystack, const char *needle);
char *_strchr(const char *s, int c);
char *_strcat(char *dest, const char *src);
char *_strdup(const char *str);
int _atoi(const char *s);
char *_strpbrk(const char *str, const char *accept);
char *_strtok(char *str, const char *delim);



void *_memset(void *s, int c, size_t n);
void *memcpy(void *dest, const void *src, size_t count);
void *_realloc(void *ptr, size_t size);
void concatenate_error_message(char *error_message, const char *program_name,
	int cycle_count, const char *command);
void free_tokens(char **tokens);
int count_tokens(char **tokens);
#endif
