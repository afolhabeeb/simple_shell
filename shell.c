#include "shell.h"

/**
 * main - output the shell itself
 *
 * @ac: first argument
 * @av: second variable
 *
 * Return: return the shell prompt with message.
 */

int main(int ac, char **av)
{
	(void)av;
	(void)ac;

	signal(SIGINT, controlC);
	display_prompt();

	return (0);

}
