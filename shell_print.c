#include "shell.h"

/**
 * shell_print - prints the shell messages
 *
 * @message: the print output for responses
 */

void shell_print(const char *message)
{
	write(STDOUT_FILENO, message, strlen(message));
}
