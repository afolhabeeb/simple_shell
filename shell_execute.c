#include "shell.h"

/**
 * execute_command - executes the command prompt received by the shell
 *
 * @command: the command to be executed
 *
 * Return: no return
 */

void execute_command(const char *command)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		shell_print("Error forking process.\n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		char *args[128];
		int arg_cnt = 0;
		char *token = strtok((char *)command, " ");

		while (token != NULL)
		{
			args[arg_cnt++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_cnt] = NULL;

		execvp(args[0], args);

		shell_print("Error executing command.\n");
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);
}
