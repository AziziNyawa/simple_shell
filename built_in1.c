#include "main.h"
/**
 * _myhistory - displays the history list available.
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: Structure containing potential arguments.
 * @str: the string alias
 * Return: Always 0
 */
int unset_alias(info_t *info, char *str)
{
	char *y, c;
	int ret;

	y = _strchr(str, '=');
	if (!y)
		return (1);
	c = *y;
	*y = 0;
	ret = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*y = c;
	return (ret);
}

/**
 * set_alias - set a alias string
 * @info: Structure containing potential arguments.
 * @str: the string
 * Return: Always 0
 */
int set_alias(info_t *info, char *str)
{
	char *y;

	y = _strchr(str, '=');
	if (!y)
		return (1);
	if (!*++y)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - functions prints an alias string
 * @node: the alias node
 * Return: Always 0
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
