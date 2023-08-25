#include "shell.h"

/**
 * execute_command - Execute a command with its arguments
 * @args: The array of command and arguments
 */
void execute_command(char **args)
{
    pid_t child_pid = fork();

    if (child_pid == -1)
    {
        perror("Fork error");
        exit(EXIT_FAILURE);
    }
    else if (child_pid == 0)
    {
        execvp(args[0], args);
        perror("Command execution error");
        exit(EXIT_FAILURE);
    }
    else
    {
        int child_status;
        waitpid(child_pid, &child_status, 0);
    }
}
