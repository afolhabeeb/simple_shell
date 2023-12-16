#include "shell.h"

/**
 * env_error - errors message for env in get_env.
 * @shell_data: data relevant (counter, arguments)
 * Return: errors message.
 */
char *env_error(data_shell *shell_data)
{
	int len;
	char *errors;
	char *str_ver;
	char *msgs;

	str_ver = shell_itoa(shell_data->counter);
	msgs = ": Unable to add/remove from environment\n";
	len = _strlen(shell_data->av[0]) + _strlen(str_ver);
	len += _strlen(shell_data->args[0]) + _strlen(msgs) + 4;
	errors = malloc(sizeof(char) * (len + 1));
	if (errors == 0)
	{
		free(errors);
		free(str_ver);
		return (NULL);
	}

	_strcpy(errors, shell_data->av[0]);
	_strcat(errors, ": ");
	_strcat(errors, str_ver);
	_strcat(errors, ": ");
	_strcat(errors, shell_data->args[0]);
	_strcat(errors, msgs);
	_strcat(errors, "\0");
	free(str_ver);

	return (errors);
}
/**
 * path_126_error - errors message for path and failure denied permission.
 * @shell_data: data relevant (counter, arguments).
 *
 * Return: The errors string.
 */
char *path_126_error(data_shell *shell_data)
{
	int len;
	char *str_ver;
	char *errors;

	str_ver = shell_itoa(shell_data->counter);
	len = _strlen(shell_data->av[0]) + _strlen(str_ver);
	len += _strlen(shell_data->args[0]) + 24;
	errors = malloc(sizeof(char) * (len + 1));
	if (errors == 0)
	{
		free(errors);
		free(str_ver);
		return (NULL);
	}
	_strcpy(errors, shell_data->av[0]);
	_strcat(errors, ": ");
	_strcat(errors, str_ver);
	_strcat(errors, ": ");
	_strcat(errors, shell_data->args[0]);
	_strcat(errors, ": Permission denied\n");
	_strcat(errors, "\0");
	free(str_ver);
	return (errors);
}
