#include "shell.h"

/**
 * main - Entry level to simple shell
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Success: 0 | Failure: -1
 */
int main(char *argc, char **argv)
{
	pid_t pid;
	size_t size = 18;
	char *lineptr;
	char **cmv; /*command vector*/
	
	lineptr = malloc(size * sizeof(char));
	if(!lineptr)
	{
		perror(argv[0]);
		return (-1);
	}

	while (1)
	{
		printf("#cisfun$ ");
		if (getline(&lineptr, &size, stdin) == -1)
		{
			perror(argv[0]);
			continue;
		}
		*(lineptr + strlen(lineptr) - 1) = '\0'; /* replace \n by \0 */
		
		cmv = malloc((strlen(lineptr) * sizeof(char)) + 5);

		if (!cmv)
		{
			perror(argv[0]);
			continue;
		}
		cmv[0] = lineptr;
		cmv[1] = NULL;

		pid = fork();
		if (pid == -1)
		{
			perror(argv[0]);
			continue;
		}
		else if (pid == 0)
		{
			if (execve(lineptr, cmv, NULL) == -1)
			{
				perror(argv[0]);
				continue;
			}
		}
		else
		{
			wait(NULL);
		}
	}
	free(lineptr);
	return (0);
}		
