#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

char *read_line(void);
char *remove_whitespace(char *str);
char **tokenize_str(char *str, const char *delim);
int execute_cmd(char **argv, char **tokens);
char *append_path(char *path, char *command);
char *access_path(char *command);
#endif
