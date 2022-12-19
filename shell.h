#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

char *remove_newline(char *buf);
char **tokenize_str(char *buf, const char *delim);
void execute_cmd(char **argv);

#endif
