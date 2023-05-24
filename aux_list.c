#include "shell.h"

/**
 * addsep_nodeend - adds the separator at the end
 * @head: head of the first node
 * @sep: separator found in the list (; | &).
 * Return: addressof the node at the fist position
 */
sep_list *addsep_nodeend(sep_list **head, char sep)
{
	sep_list *newnode, *temp;

	newnode = malloc(sizeof(sep_list));
	if (newnode == NULL)
		return (NULL);

	newnode->separator = sep;
	newnode->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * freesep_list - frees a the list
 * @head: head of the linked node
 * Return: nothing is returned
 */
void freesep_list(sep_list **head)
{
	sep_list *temp;
	sep_list *current;

	if (head != NULL)
	{
		current = *head;
		while ((temp = current) != NULL)
		{
			current = current->next;
			free(temp);
		}
		*head = NULL;
	}
}

/**
 * addline_nodeend - adds command at the line
 * @head: head of the link list.
 * @line: command of a line
 * Return: give back the address
 */
line_list *addline_nodeend(line_list **head, char *line)
{
	line_list *newnode, *temp;

	newnode = malloc(sizeof(line_list));
	if (newnode == NULL)
		return (NULL);

	newnode->line = line;
	newnode->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = newnode;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newnode;
	}

	return (*head);
}

/**
 * freeline_list - free the linked list
 * @head: head of the list
 * Return: nothing returned
 */
void freeline_list(line_list **head)
{
	line_list *temp;
	line_list *current;

	if (head != NULL)
	{
		current = *head;
		while ((temp = current) != NULL)
		{
			current = current->next;
			free(temp);
		}
		*head = NULL;
	}
}
