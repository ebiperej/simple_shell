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
	size_t size = 0;
	char *lineptr = NULL;
	char **tokens;
	int status = 1;
	const char *delim = " ";
	char *path;
	(void)(argc);



	printf("%s\n", append_path("bin","ls"));
	return (1);
	while (status)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("#cisfun$ ");
		}
		if (getline(&lineptr, &size, stdin) == -1)
		{
			free(lineptr);
			if (feof(stdin))
				exit(EXIT_SUCCESS);	
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}

		*(lineptr + (strlen(lineptr) - 1)) = '\0';	
		tokens = tokenize_str(lineptr, delim);
		
		if (tokens[0] != NULL)
			execute_cmd(argv, tokens);
		free(tokens);
	}
	free(lineptr);
	return (0);
}
