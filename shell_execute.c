#include "shell.h"

/**
 * execute_command - executes the command prompt received by the shell
 *
 * @cmd: the command to be executed
 *
 * Return: no return
 */

void execute_command(char **cmd)
{
	char *param = (*(cmd + 1));
	char *s, *slash = "/";
	char *o;
	char *var_print = *cmd;
	char *argv[4];

	if ((access(cmd[0], F_OK) == 0))
	{
		argv[0] = cmd[0];
		argv[1] = param;
		argv[2] = ".";
		argv[3] = NULL;

		if (execve(argv[0], argv, NULL) == -1)
			perror("Error");
	}
	else
	{
		o = read_command(var_print);
		slash = str_concat(o, slash);
		s = str_concat(slash, *cmd);

		argv[0] = s;
		argv[1] = param;
		argv[2] = ".";
		argv[3] = NULL;

		if (execve(argv[0], argv, NULL) == -1)
			perror("Error");
	}
}
