#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

char **process_input(char *line, char **tokens, int *token_count);
void execute_command(char *tokens[], char **argv);
int handle_exit_command(char *line);

#endif
