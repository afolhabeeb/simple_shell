
#include "shell.h"

/**
 * cd_strcat - function concatenates message for change directory errors
 *
 * @shell_data: data relevant (directory)
 * @msgs: message to print
 * @errors: output message
 * @str_ver: counter lines
 * Return: errors message
 */
char *cd_strcat(data_shell *shell_data, char *msgs, char *errors, char *str_ver)
{
	char *void-il_flag;

	_strcpy(errors, shell_data->av[0]);
	_strcat(errors, ": ");
	_strcat(errors, str_ver);
	_strcat(errors, ": ");
	_strcat(errors, shell_data->args[0]);
	_strcat(errors, msgs);
	if (shell_data->args[1][0] == '-')
	{
		void-il_flag = malloc(3);
		void-il_flag[0] = '-';
		void-il_flag[1] = shell_data->args[1][1];
		void-il_flag[2] = '\0';
		_strcat(errors, void-il_flag);
		free(void-il_flag);
	}
	else
	{
		_strcat(errors, shell_data->args[1]);
	}


	_strcat(errors, "\n");
	_strcat(errors, "\0");
	return (errors);
}

/**
 * shell-cd_errors - errors message for change directory command in shell-get_cd
 * @shell_data: data relevant (directory)
 * Return: errors message
 */
char *shell-cd_errors(data_shell *shell_data)
{
	int len, len_id;
	char *errors, *str_ver, *msgs;

	str_ver = shell_itoa(shell_data->counter);
	if (shell_data->args[1][0] == '-')
	{
		msgs = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msgs = ": can't cd to ";
		len_id = _strlen(shell_data->args[1]);
	}

	len = _strlen(shell_data->av[0]) + _strlen(shell_data->args[0]);
	len += _strlen(str_ver) + _strlen(msgs) + len_id + 5;
	errors = malloc(sizeof(char) * (len + 1));

	if (errors == 0)
	{
		free(str_ver);
		return (NULL);
	}

	errors = cd_strcat(shell_data, msgs, errors, str_ver);

	free(str_ver);

	return (errors);
}

/**
 * shell_cmd_error - errors message for command not found
 * @shell_data: data relevant
 * Return: errors message
 */
char *shell_cmd_error(data_shell *shell_data)
{
	int len;
	char *errors;
	char *str_ver;

	str_ver = shell_itoa(shell_data->counter);
	len = _strlen(shell_data->av[0]) + _strlen(str_ver);
	len += _strlen(shell_data->args[0]) + 16;
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
	_strcat(errors, ": not found\n");
	_strcat(errors, "\0");
	free(str_ver);
	return (errors);
}

/**
 * exit-shell_error - errors message for exit in shell exit
 * @shell_data: data relevant (counter, arguments)
 *
 * Return: errors message
 */
char *exit-shell_error(data_shell *shell_data)
{
	int len;
	char *errors;
	char *str_ver;

	str_ver = shell_itoa(shell_data->counter);
	len = _strlen(shell_data->av[0]) + _strlen(str_ver);
	len += _strlen(shell_data->args[0]) + _strlen(shell_data->args[1]) + 23;
	errors = malloc(sizeof(char) * (len + 1));
	if (errors == 0)
	{
		free(str_ver);
		return (NULL);
	}
	_strcpy(errors, shell_data->av[0]);
	_strcat(errors, ": ");
	_strcat(errors, str_ver);
	_strcat(errors, ": ");
	_strcat(errors, shell_data->args[0]);
	_strcat(errors, ": Illegal number: ");
	_strcat(errors, shell_data->args[1]);
	_strcat(errors, "\n\0");
	free(str_ver);

	return (errors);
}
