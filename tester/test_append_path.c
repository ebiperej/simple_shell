#include "../shell.h"

/**
 * main - test append path func
 * Return- always 0
 */
int main(void)
{
	char *path = "/bin/";
	char *command = "ls";
	int i = 0;

	char **paths = get_paths();

	char *path_command = append_path(paths[0], command);
	
		printf("%s\n", path_command);

//		free(path_command);
	return (0);
}
