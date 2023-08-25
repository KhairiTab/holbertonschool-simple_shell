#ifndef SHELL_H
#define SHELL_H

/* Standard Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/* Define token delimiters */
#define TOKEN_DELIMITERS " \n"

/* Function Prototypes */
char *prompt(void); /* responsible for showing the shell prompt.*/
char **parse_command(char *line); /*parse the input into individual command and arguments.*/ 
void execute_command(char **args); /*Execute a command with its arguments*/ 



#endif /* SHELL_H */