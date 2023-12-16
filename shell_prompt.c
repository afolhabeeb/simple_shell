#include "shell.h"


#define MAX_CMD_LEN 256


/**
 * display_prompt - displays the shell address
 *
 */

void display_prompt(void)
{
	char *text = NULL, **environ;
	pid_t child_pid;
	int status, buflen;
	size_t bufsize = 0;
	child_pid = fork();

	for (;;)
	{
		shell_place("odun-hab$ ");
		buflen = getline(&text, &bufsize, stdin);
		if (buflen == -1)
			exit(98);
		if (compareExit(text, "exit") == 0)
			exit(0);
		if (compareEnv(text, "env") == 0)
		{
			while (*environ != NULL)
			{
				if (!(_strcmpdir(*environ, "USER")) ||
						!(_strcmpdir(*environ, "LANGUAGE")) ||
						!(_strcmpdir(*environ, "SESSION")) ||
						!(_strcmpdir(*environ, "COMPIZ_CONFIG_PROFILE")) ||
						!(_strcmpdir(*environ, "SHLV")) ||
						!(_strcmpdir(*environ, "HOME")) ||
						!(_strcmpdir(*environ, "HAB_ODUN")) ||
						!(_strcmpdir(*environ, "DESKTOP_SESSION")) ||
						!(_strcmpdir(*environ, "LOGNAME")) ||
						!(_strcmpdir(*environ, "TERM")) ||
						!(_strcmpdir(*environ, "PATH")))
					shell_place(*environ), shell_place("\n");
				environ++;
			}
		}
		child_pid = fork();
		if (child_pid < 0)
			perror("Error");
		if (child_pid == 0)
			id_str(text);
		else
			wait(&status);
	}
}
