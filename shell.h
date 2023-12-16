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

extern char **environ;


char *show_input(void);


int lookforslash(char *cmd);
int compareExit(char *s1, char *s2);
char **id_str(char *param);
void controlC(int sig);
int compareEnv(char *s1, char *s2);
int charput(char c);
void shell_place(char *str);
int _strcmpdir(char *s1, char *s2);
int _strlen(char *str);
char *str_concat(char *s1, char *s2);
void display_prompt(void);
void execute_command(char **cmd);
int main(int ac, char **av);
char *read_command(char *command);



#endif
