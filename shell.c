#include "shell.h"

/**
 * main - output the shell itself
 *
 * @void: the void print
 *
 * Return: return the shell prompt with message.
 */

int main(void)
{
	char command[120];

	while (true)
	{
		display_prompt();
		read_command(command, sizeof(command));
		execute_command(command);
	}

	return (0);
}
