#include "shell.h"

/**
 * get_help - function that retrieves help messages according builtin
 * @shell_data: data structure (args and input)
 * Return: Return 0
*/
int get_help(data_shell *shell_data)
{

	if (shell_data->args[1] == 0)
		shell_help_general();
	else if (_strcmp(shell_data->args[1], "setenv") == 0)
		shell_help_setenv();
	else if (_strcmp(shell_data->args[1], "env") == 0)
		shell_help_env();
	else if (_strcmp(shell_data->args[1], "unsetenv") == 0)
		shell_help_unsetenv();
	else if (_strcmp(shell_data->args[1], "help") == 0)
		shell_help();
	else if (_strcmp(shell_data->args[1], "exit") == 0)
		shell_help_exit();
	else if (_strcmp(shell_data->args[1], "cd") == 0)
		shell_help_cd();
	else if (_strcmp(shell_data->args[1], "alias") == 0)
		shell_help_alias();
	else
		write(STDERR_FILENO, shell_data->args[0],
		      _strlen(shell_data->args[0]));

	shell_data->status = 0;
	return (1);
}
