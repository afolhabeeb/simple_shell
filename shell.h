#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdbool.h>

#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <dirent.h>
#include <limits.h>
#include <string.h>


void display_prompt(void);
void shell_print(const char *message);
void read_command(char *command, size_t size);
void execute_command(const char *command);

#endif
