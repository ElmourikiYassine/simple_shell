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

extern char **environ;

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
char *find_executable(char **env,
		char *file_path,
		char *exe_name);

void signal_handler(int signum);


/**
 * _strlen - Calculate the length of a string.
 * @s: The string to calculate the length of.
 * Return: The length of the string.
 */
int _strlen(const char *s);

/**
 * _strcmp - Compare two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * Return: 0 if the strings are equal, a positive value if s1 is greater,
 *         and a negative value if s2 is greater.
 */
int _strcmp(const char *s1, const char *s2);

/**
 * _strcpy - Copy a string.
 * @dest: The destination buffer.
 * @src: The source string to copy.
 * Return: A pointer to the destination buffer.
 */
char *_strcpy(char *dest, const char *src);

/**
 * _strstr - Locate a substring in a string.
 * @haystack: The string to search in.
 * @needle: The substring to search for.
 * Return: A pointer to the beginning of the substring if found, or NULL if not found.
 */
char *_strstr(const char *haystack, const char *needle);

/**
 * _strchr - Locate a character in a string.
 * @s: The string to search in.
 * @c: The character to search for.
 * Return: A pointer to the first occurrence of the character in the string, or NULL if not found.
 */
char *_strchr(const char *s, int c);

/**
 * _strcat - Concatenate two strings.
 * @dest: The destination string.
 * @src: The source string to append.
 * Return: A pointer to the destination string.
 */
char *_strcat(char *dest, const char *src);

/**
 * _strdup - Duplicate a string in memory.
 * @str: The string to duplicate.
 * Return: A pointer to the duplicated string, or NULL if memory allocation fails.
 */
char *_strdup(const char *str);

/**
 * _atoi - Convert a string to an integer.
 * @s: The string to convert.
 * Return: The integer value represented by the string, or 0 if conversion fails.
 */
int _atoi(const char *s);


/**
 * _strpbrk - Locate the first occurrence of any character in a set.
 * @str: The string to search.
 * @accept: The set of characters to search for.
 * Return: A pointer to the first matching character, or NULL if none are found.
 */
char *_strpbrk(const char *str, const char *accept);

/**
 * _strtok - Split a string into tokens.
 * @str: The string to be split.
 * @delim: The delimiter used to split the string.
 * Return: A pointer to the next token, or NULL if there are no more tokens.
 */
char *_strtok(char *str, const char *delim);

#endif
