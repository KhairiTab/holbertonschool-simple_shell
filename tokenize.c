#include "shell.h"
/**
 *parse_command - tokenize function in shell project
 *@line: input string
 */
char **parse_command(char *line)
{
	char **args = NULL;
	char *arg_copy = NULL;
	int arg_count = 0;
	char *arg;
	int i;

	arg_copy = strdup(line);
	if (!arg_copy)
	{
		exit(EXIT_FAILURE);
	}
	arg = strtok(arg_copy, TOKEN_DELIMITERS);
	while (arg != NULL)
	{
		arg_count++;
		arg = strtok(NULL, TOKEN_DELIMITERS);
	}
	args = malloc(sizeof(char *) * (arg_count + 1));
	if (!args)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	arg = strtok(line, TOKEN_DELIMITERS);
	for (i = 0; i < arg_count; i++)
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
	if (arg_count > 0 && strcmp(args[0], "exit") == 0)
	{
		free(args);
		return (NULL);
	}
	return (args);
}
