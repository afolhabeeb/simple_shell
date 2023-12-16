#include "shell.h"

/**
 * lookforslash - identifies the first characer as slash
 *
 * @cmd: first element
 *
 * Return: 1 for true value and 0 for false
 */

int lookforslash(char *cmd)
{
	int cnt = 0;

	while (cmd[cnt])
	{
		if (cmd[0] == '/')
		{
			printf("%c\n", cmd[0]);
			return (1);
		}
		cnt++;
	}
	return (0);
}

/**
 * compareExit - identifies the first xter as slash
 *
 * @s1: first string
 * @s2: exit string
 *
 * Return: 1 if yes and 0 otherwise
 */

int compareExit(char *s1, char *s2)
{
	int i = 0;

	for (; (*s2 != '\0' && *s1 != '\0') && *s1 == *s2; s1++)
	{
		if (i == 3)
			break;
		i++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * compareEnv - identifies first xter is slash.
 *
 * @s1: string first
 * @s2: strinf second
 *
 * Return: 1 f yes, 0 if no
 */

int compareEnv(char *s1, char *s2)
{
	int i = 0;

	for (; (*s2 != '\0' && *s1 != '\0') && *s1 == *s2; s1++)
	{
		if (i == 2)
			break;
		i++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * id_str - identifies the keyboard inputs
 *
 * @param: command prompt from another function
 *
 * Return: string
 */

char **id_str(char *param)
{
	char **buf = malloc(1024 * sizeof(char *));
	char *split;
	int i = 0;
	char *delim = "\t\n";

	split = strtok(param, delim);

	while (split != NULL)
	{
		buf[i] = split;
		i++;
		split = strtok(NULL, delim);

	}
	execute_command(buf);
	return (buf);
}


/**
 * controlC - avoid close the shell
 *
 * @sig: keep shell going
 */

void controlC(int sig)
{
	(void) sig;
	write(1, "\n$ ", 3);
}

