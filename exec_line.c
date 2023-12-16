#include "shell.h"

/**
 * exec_line - finds builtins and commands
 *
 * @shell_data: data relevant (args)
 * Return: 1 on success.
 */
int exec_line(data_shell *shell_data)
{
	int (*builtin)(data_shell *shell_data);

	if (shell_data->args[0] == NULL)
		return (1);

	builtin = get_builtin(shell_data->args[0]);

	if (builtin != NULL)
		return (builtin(shell_data));

	return (cmd_exec(shell_data));
}
