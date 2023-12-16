#include "shell.h"

/**
 * get_errors - calls the errors according the builtin, syntax or permission
 * @shell_data: data structure that contains arguments
 * @eval: errors value
 * Return: errors
 */
int get_errors(data_shell *shell_data, int eval)
{
	char *errors;

	switch (eval)
	{
	case -1:
		errors = env_error(shell_data);
		break;
	case 126:
		errors = path_126_error(shell_data);
		break;
	case 127:
		errors = shell_cmd_error(shell_data);
		break;
	case 2:
		if (_strcmp("exit", shell_data->args[0]) == 0)
			errors = exit-shell_error(shell_data);
		else if (_strcmp("cd", shell_data->args[0]) == 0)
			errors = shell-cd_errors(shell_data);
		break;
	}

	if (errors)
	{
		write(STDERR_FILENO, errors, _strlen(errors));
		free(errors);
	}

	shell_data->status = eval;
	return (eval);
}
