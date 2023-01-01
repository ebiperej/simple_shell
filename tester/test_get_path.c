#include "../shell.h"

/**
 * main -get path
 * Return: 0
 */

int main(void)
{
	char **paths = get_path();
	free(paths);
	return (0);
}

