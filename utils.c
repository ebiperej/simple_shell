#include "shell.h"

/**
 * read_line - read line of input
 *
 * Return: pointer to line buffer
 */
char *read_line(void)
{
	char *lineptr;
	size_t size;

	if (getline(&lineptr, &size, stdin) == -1)
	{
		if (feof(stdin))
		{
			/* End of file | CTRL + D */
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("read_line");
			exit(EXIT_FAILURE);
		}
	}
	
	lineptr = remove_whitespace(lineptr);
	return (lineptr);
}

/**
 * remove_whitespace - removes white spaces \n, ' ', \t 
 * @str: string
 *
 * Return: pointer to line
 */
char *remove_whitespace(char *str)
{
//	int len = strlen(str) - 1;
	/* remove white space at the end */

	*(str + (strlen(str) - 1)) = '\0';
	
	/* remove whitespace at the beginning */
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;

	return (str);

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

        tokens = malloc(strlen(str) * sizeof(char) + 5);

        tokens[idx] = strtok(str, delim);

        while (tokens[idx])
        {
                ++idx;
                tokens[idx] = strtok(NULL, delim);
        }

        return (tokens);
}
