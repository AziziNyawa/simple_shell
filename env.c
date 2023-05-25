#include "main.h"

/**
 * _myenv - prints the working environment
 * Authors: Azizi Nyawa
 * Ronald
 * @info: Structure containing potential arguments
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - its functions to get the environment get line
 * @info: Structure containing potential
 * @name: env var name
 * Return: the value of the envirn
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *y;

	while (node)
	{
		y = starts_with(node->str, name);
		if (y && *y)
			return (y);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a new env
 * @info: Structure containing potential
 * Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove the environment variable
 * @info: Structure containing potential
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int j;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (j = 1; j <= info->argc; j++)
		_unsetenv(info, info->argv[j]);

	return (0);
}

/**
 * populate_env_list - populates environment linked list
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
