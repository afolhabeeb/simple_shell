#include "shell.h"

/**
 * cd_shell - changes current directory
 *
 * @shell_data: data relevant
 * Return: 1 on success
 */
int cd_shell(data_shell *shell_data)
{
	char *dir;
	int ishome, ishome2, isddash;

	dir = shell_data->args[1];

	if (dir != NULL)
	{
		ishome = _strcmp("$HOME", dir);
		ishome2 = _strcmp("~", dir);
		isddash = _strcmp("--", dir);
	}

	if (dir == NULL || !ishome || !ishome2 || !isddash)
	{
		cd_to_home(shell_data);
		return (1);
	}

	if (_strcmp("-", dir) == 0)
	{
		cd_previous(shell_data);
		return (1);
	}

	if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
	{
		cd_dot(shell_data);
		return (1);
	}

	cd_to(shell_data);

	return (1);
}
