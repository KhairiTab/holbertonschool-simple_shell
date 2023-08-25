#include "shell.h"
/**
 *main function - description
 */
int main(void)
{
	char *line;
	char **args;
	pid_t child_pid;
	int i;

	while (1)
	{
		line = prompt();
		if (line == NULL)
		{
			printf("\nExiting shell...\n");
			break;
		}
		args = parse_command(line);
		if (args == NULL)
		{
			free(line);
			break;
		}
		child_pid = fork();

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
			for (i = 0; args[i] != NULL; i++)
			{
				free(args[i]);
			}
			free(args);
		}
		free(line);
	}
	return (0);
}
