#include "shell.h"

/**
 * execute_cmd - execute command
 * @argv: argument vector
 * @tokens: tokens
 * Return: 1 on success
 */
int execute_cmd(char **argv, char **tokens)
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
		if (execve(tokens[0], tokens, NULL) == -1)
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

/**
 * tokenize_str - break string into array
 * @str: string
 * @delim: delimiters
 * Return: array of string
 */
char **tokenize_str(char *str, const char *delim)
{
	char **tokens;
	int idx = 0;

	tokens = malloc(1024 * sizeof(char *));
	tokens[idx] = strtok(str, delim);

	while (tokens[idx])
	{
		++idx;
		tokens[idx] = strtok(NULL, delim);
	}
	return (tokens);
}
