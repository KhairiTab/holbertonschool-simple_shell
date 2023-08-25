#include "shell.h"

/**
 * prompt - Display a prompt and get user input
 *
 * Return: The user's command line input
 */
char *prompt(void)
{
    char *line = NULL;     // Pointer to hold the user's input line
    size_t bufsize = 0;    // Initial buffer size for getline()
    ssize_t chars_read;    // Number of characters read

    // Display the prompt
    write(STDOUT_FILENO, "$ ", 2);  // Display the shell prompt

    // Read user input
    chars_read = getline(&line, &bufsize, stdin);  // Read input from user

    // Check for end of file or read error
    if (chars_read == -1)
    {
        if (feof(stdin))  // If end of file (Ctrl+D) is encountered
        {
            free(line);       // Free allocated memory for line
            line = NULL;      // Reset line pointer to avoid dangling pointer
            write(STDOUT_FILENO, "\n", 1);  // Print newline after Ctrl+D
        }
        else
        {
            perror("Error reading input");  // Print error message
            exit(EXIT_FAILURE);             // Exit the program with failure status
        }
    }

    return line;  // Return the user's input line
}
