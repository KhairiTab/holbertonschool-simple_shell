#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define TOKEN_DELIMITERS " \n"

char *prompt(void);
char **parse_command(char *line);
void execute_command(char **args);

#endif
