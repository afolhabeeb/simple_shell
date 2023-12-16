#include "shell.h"

/**
 * add_sep_node_end - adds a separator found at the end
 * of a sep_list.
 * @add_list: add_list of the linked list.
 * @sep: separator found (; | &).
 * Return: address of the add_list.
 */
sep_list *add_sep_node_end(sep_list **add_list, char sep)
{
	sep_list *new, *tmp;

	new = malloc(sizeof(sep_list));
	if (new == NULL)
		return (NULL);

	new->separator = sep;
	new->next = NULL;
	tmp = *add_list;

	if (tmp == NULL)
	{
		*add_list = new;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}

	return (*add_list);
}

/**
 * free_sep_list - frees a sep_list
 * @add_list: add_list of the linked list.
 * Return: no return.
 */
void free_sep_list(sep_list **add_list)
{
	sep_list *tmp;
	sep_list *curr;

	if (add_list != NULL)
	{
		curr = *add_list;
		while ((tmp = curr) != NULL)
		{
			curr = curr->next;
			free(tmp);
		}
		*add_list = NULL;
	}
}

/**
 * add_line_node_end - adds a command line at the end
 * of a line_list.
 * @add_list: add list of the linked list.
 * @line: command line.
 * Return: address of the add_list.
 */
line_list *add_line_node_end(line_list **add_list, char *line)
{
	line_list *new, *tmp;

	new = malloc(sizeof(line_list));
	if (new == NULL)
		return (NULL);

	new->line = line;
	new->next = NULL;
	tmp = *add_list;

	if (tmp == NULL)
	{
		*add_list = new;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}

	return (*add_list);
}

/**
 * free_line_list - frees a line_list
 * @add_list: add_list of the linked list.
 * Return: no return.
 */
void free_line_list(line_list **add_list)
{
	line_list *tmp;
	line_list *curr;

	if (add_list != NULL)
	{
		curr = *add_list;
		while ((tmp = curr) != NULL)
		{
			curr = curr->next;
			free(tmp);
		}
		*add_list = NULL;
	}
}
