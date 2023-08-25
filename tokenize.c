#include "shell.h"

/**
 * parse_command - Parse the user's input into an array of arguments
 * @line: The user's input line
 *
 * Return: An array of strings containing the parsed arguments
 */
char **parse_command(char *line)
{
    char **args = NULL;
    char *arg_copy = NULL;
    int arg_count = 0;
    char *arg;

    /* Copy line for tokenization */
    arg_copy = strdup(line);
    if (!arg_copy)
    {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    /* Count the number of arguments */
    arg = strtok(arg_copy, TOKEN_DELIMITERS);
    while (arg != NULL)
    {
        arg_count++;
        arg = strtok(NULL, TOKEN_DELIMITERS);
    }

    /* Allocate space for the arguments array */
    args = malloc(sizeof(char *) * (arg_count + 1));
    if (!args)
    {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    /* Tokenize and store the arguments */
    arg = strtok(line, TOKEN_DELIMITERS);
    for (int i = 0; i < arg_count; i++)
    {
        args[i] = strdup(arg);
        if (!args[i])
        {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }
        arg = strtok(NULL, TOKEN_DELIMITERS);
    }
    args[arg_count] = NULL;

    free(arg_copy);

    // Check for the "exit" command
    if (arg_count > 0 && strcmp(args[0], "exit") == 0)
    {
        free(args); // Free memory for the arguments array
        return NULL; // Return NULL to signal the exit command
    }

    return args;
}