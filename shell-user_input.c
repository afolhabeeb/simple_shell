#include "shell.h"

/**
 * read_command - read command input from the user
 *
 * @command: takes the command argument
 * @size: the size of the standard input
 *
 * Return: no return
 */

void read_command(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			shell_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			shell_print("Error while reading input");
			exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0';
}
