#include "shell.h"

#define MAX_CMD_LEN 256

/**
 * display_prompt - displays the shell address
 *
 */

void display_pmt(void)
{
	char command[MAX_CMD_LEN];
	pid_t child_pid = fork();
	int status;
	size_t bytesRead = read(STDIN_FILENO, command, MAX_CMD_LEN);

	while (1)
	{
		write(STDOUT_FILENO, "odun-hab$ ", 10);
		if (bytesRead == 0)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
	}
	if (command[bytesRead - 1] == '\n')
		command[bytesRead - 1] = '\0';
	else
	{
		while (getchar() != '\n')
			;
		write(STDOUT_FILENO, "command too long!\n", 18);
	}
	if (child_pid < 0)
	{
		perror("Fork Error");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execlp(command, command, (char *)NULL) == -1)
		{
			perror("Command execution failed\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			write(STDOUT_FILENO, "Command execution failed\n", 25);
	}
}
