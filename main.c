#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    char *line;
    char **args;

    while (1)
    {
        line = prompt(); // Get user input

        // Check for end of file (CTRL+D)
        if (line == NULL)
        {
            printf("\nExiting shell...\n");
            break; // Exit the loop
        }

        args = parse_command(line); // Parse the input into arguments

         if (args == NULL) // User entered "exit" command
        {
            free(line); // Free memory for the input line
            break; // Exit the loop
        }


        if (args != NULL)
        {
            // Fork a child process
            pid_t child_pid = fork();

            if (child_pid == -1)
            {
                perror("Fork error");
                exit(EXIT_FAILURE);
            }
            else if (child_pid == 0) // Child process
            {
                // Execute the command
                execvp(args[0], args);

                // If execvp fails, print an error and exit
                perror("Command execution error");
                exit(EXIT_FAILURE);
            }
            else // Parent process
            {
                // Wait for the child process to complete
                int child_status;
                waitpid(child_pid, &child_status, 0);

                // Free memory for the arguments array
                for (int i = 0; args[i] != NULL; i++)
                    free(args[i]);
                free(args);
            }
        }

        free(line); // Free memory for the input line
    }

    return (0);
    