#include "shell.h"

/**
 *prompt - Display a prompt and get user input
 *
 *Return: The user's command line input
 */
char *prompt(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t chars_read;

	write(STDOUT_FILENO, "$ ", 2);
	chars_read = getline(&line, &bufsize, stdin);
	if (chars_read == -1)
	{
		if (feof(stdin))
		{
			free(line);
			line = NULL;
			write(STDOUT_FILENO, "\n", 1);
		}
		else
		{
			perror("Error reading input");
			exit(EXIT_FAILURE);
		}
	}

	return (line);
}
