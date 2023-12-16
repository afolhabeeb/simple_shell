#include "shell.h"

/**
 * charput - writes the character
 *
 * @c: the character to print
 *
 * Return: character print
 */

int charput(char c)
{
	return (write(1, &c, 1));
}

/**
 * shell_place - prints the shell messages
 *
 * @str: pointer to string
 */

void shell_place(char *str)
{
	while (*str != '\0')
	{
		charput(*str);
		str++;
	}
}

/**
 * _strcmpdir - compares two strings to find directory
 *
 * @s1: string 1
 * @s2: string 2
 *
 * Return: directory if match
 */

int _strcmpdir(char *s1, char *s2)
{
	int i = 0;

	for (; (*s2 != '\0' && *s1 != '\0') && *s1 == *s2; s1++)
	{
		if (i == 3)
			break;
		i++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strlen - string length
 *
 * @str: string
 *
 * Return: the length of the string
 */

int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;

	return (i);
}

/**
 * str_concat - concatenate string
 *
 * @s1: string
 * @s2: concatenated string
 *
 * Return: strings
 */

char *str_concat(char *s1, char *s2)
{
	char *j;
	int len1, len2, l, m, n;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	len1 = _strlen(s1);
	len2 = _strlen(s2);

	j = malloc(((len1) + (len2) + 1) * sizeof(char));

	if (j == NULL)
		return (NULL);
	for (l = 0; l < len1; l++)
		j[l] = s1[l];
	for (m = len1, n = 0; n <= len2; m++, n++)
		j[m] = s2[n];

	return (j);
}
