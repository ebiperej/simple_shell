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

/**
 * append_path - append command to paths
 * @path: path
 * @command: enter command
 *
 * Return: buffer of appended path on success
 * or NULL on failure
 */
char *append_path(char *path, char *command)
{
	int i, j = 0;
	char *buf;

	buf = malloc(sizeof(char) * (strlen(path) + strlen(command) + 2));
	if (!buf)
		return (NULL);

	/* copy path into buf */
	while (path[i] != '\0')
	{
		buf[i] = path[i];
		i++;
	}

	/* append '/' to buf if path do not end with it */
	if (path[i - 1] != '/')
	{
		buf[i] = '/';
		i++;
	}

	/* append command to the buf */ 
	while (command[j] != '\0')
	{
		buf[i + j] = command[j];
		j++;
	}
	
	buf[i + j] = '\0';

	return (buf);
}


/**
 * access_path - check if process can execute command in path
 * @command: entered command
 *
 * Return: buffer to executable file path on success
 * Null on failure
 */
char *access_path(char *command)
{
	char *paths, *path, *appended_buf;

	paths = strdup(getenv("PATH"));

	path = strtok(paths, ":");

	while (path != NULL)
	{
		appended_buf = append_path(path, command);

		if (access(appended_buf, F_OK | X_OK))
			return (appended_buf);
		
		path = strtok(NULL, ":");
	}
	return ("dfad");
}

