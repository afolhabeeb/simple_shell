#include "shell.h"

/**
 * repeated_char - counts the repetitions of a char
 *
 * @input: input string
 * @i: index
 * Return: repetitions
 */
int repeated_char(char *input, int i)
{
	if (*(input - 1) == *input)
		return (repeated_char(input - 1, i + 1));

	return (i);
}

/**
 * errors_sep_op - finds syntax errorss
 *
 * @input: input string
 * @i: index
 * @last: last char read
 * Return: index of errors. 0 when there are no
 * errorss
 */
int errors_sep_op(char *input, int i, char last)
{
	int count;

	count = 0;
	if (*input == '\0')
		return (0);

	if (*input == ' ' || *input == '\t')
		return (errors_sep_op(input + 1, i + 1, last));

	if (*input == ';')
		if (last == '|' || last == '&' || last == ';')
			return (i);

	if (*input == '|')
	{
		if (last == ';' || last == '&')
			return (i);

		if (last == '|')
		{
			count = repeated_char(input, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}

	if (*input == '&')
	{
		if (last == ';' || last == '|')
			return (i);

		if (last == '&')
		{
			count = repeated_char(input, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}

	return (errors_sep_op(input + 1, i + 1, *input));
}

/**
 * first_char - finds index of the first char
 *
 * @input: input string
 * @i: index
 * Return: 1 if there is an errors. 0 in other case.
 */
int first_char(char *input, int *i)
{

	for (*i = 0; input[*i]; *i += 1)
	{
		if (input[*i] == ' ' || input[*i] == '\t')
			continue;

		if (input[*i] == ';' || input[*i] == '|' || input[*i] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * print_syntax_errors - prints when a syntax errors is found
 *
 * @shell_data: data structure
 * @input: input string
 * @i: index of the errors
 * @bool: to control msgs errors
 * Return: no return
 */
void print_syntax_errors(data_shell *shell_data, char *input, int i, int bool)
{
	char *msgs, *msgs2, *msgs3, *errors, *counter;
	int len;

	if (input[i] == ';')
	{
		if (bool == 0)
			msgs = (input[i + 1] == ';' ? ";;" : ";");
		else
			msgs = (input[i - 1] == ';' ? ";;" : ";");
	}

	if (input[i] == '|')
		msgs = (input[i + 1] == '|' ? "||" : "|");

	if (input[i] == '&')
		msgs = (input[i + 1] == '&' ? "&&" : "&");

	msgs2 = ": Syntax errors: \"";
	msgs3 = "\" unexpected\n";
	counter = shell_itoa(shell_data->counter);
	len = _strlen(shell_data->av[0]) + _strlen(counter);
	len += _strlen(msgs) + _strlen(msgs2) + _strlen(msgs3) + 2;

	errors = malloc(sizeof(char) * (len + 1));
	if (errors == 0)
	{
		free(counter);
		return;
	}
	_strcpy(errors, shell_data->av[0]);
	_strcat(errors, ": ");
	_strcat(errors, counter);
	_strcat(errors, msgs2);
	_strcat(errors, msgs);
	_strcat(errors, msgs3);
	_strcat(errors, "\0");

	write(STDERR_FILENO, errors, len);
	free(errors);
	free(counter);
}

/**
 * check_syntax_errors - intermediate function to
 * find and print a syntax errors
 *
 * @shell_data: data structure
 * @input: input string
 * Return: 1 if there is an errors. 0 in other case
 */
int check_syntax_errors(data_shell *shell_data, char *input)
{
	int begin = 0;
	int f_char = 0;
	int i = 0;

	f_char = first_char(input, &begin);
	if (f_char == -1)
	{
		print_syntax_errors(shell_data, input, begin, 0);
		return (1);
	}

	i = errors_sep_op(input + begin, 0, *(input + begin));
	if (i != 0)
	{
		print_syntax_errors(shell_data, input, begin + i, 1);
		return (1);
	}

	return (0);
}
