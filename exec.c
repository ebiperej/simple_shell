#include "shell.h"

/**
 * execute_cmd - execute command
 * @argv: argument vector
 * Return: 1 on success
 */
int execute_cmd(char **argv)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
	return (1);
}

