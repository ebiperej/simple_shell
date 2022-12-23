#include "shell.h"

/**
 * main - Entry level to simple shell
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Success: 0 | Failure: -1
 */
int main(int argc, char **argv)
{
	size_t size = 18;
	char *lineptr;
	char **cmv;

	lineptr = malloc(size * sizeof(char));
	if (!lineptr)
	{
		perror(argv[argc - argc]);
		return (-1);
	}

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("#cisfun$ ");
		}
		getline(&lineptr, &size, stdin);

		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}

		lineptr = remove_whitespace(lineptr);

		cmv = tokenize_str(lineptr, " ");
		execute_cmd(cmv);
		free(cmv);
	}
	free(lineptr);
	return (0);
}
