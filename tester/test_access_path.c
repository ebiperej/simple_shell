#include "../shell.h"

/**
 * main - test access path
 * Return: always 0
 */

int main(void)
{
	char *command = "ls";
	char *path;

	path = access_path(command);
	printf("%s\n", path);
	free(path);	
	return (0);
}
