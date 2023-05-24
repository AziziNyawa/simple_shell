#include "main.h"

/**
 * cmpenv_name - compares the new variables available
 * @n_env: name of the environment
 * @name: name that is passed
 * Return: zero when not equal
 */
int cmpenv_name(const char *n_env, const char *name)
{
	int j;

	for (j = 0; n_env[j] != '='; j++)
	{
		if (n_env[j] != name[j])
		{
			return (0);
		}
	}

	return (j + 1);
}

/**
 * _get_env - function to get environment variable
 * @name: name environment
 * @_env: the environment variable
 * Return: value of env if found
 */
char *_get_env(const char *name, char **_env)
{
	char *ptr_environ;
	int i, move;

	ptr_environ = NULL;
	move = 0;
	for (i = 0; _env[i]; i++)
	{
		move = cmpenv_name(_env[i], name);
		if (move)
		{
			ptr_environ = _env[i];
			break;
		}
	}

	return (ptr_environ + move);
}

/**
 * _environ - prints then envi variable
 * @datash: data relevant.
 * Return: 1 on success.
 */
int _environ(data_shell *datash)
{
	int i, j;

	for (i = 0; datash->_env[i]; i++)
	{

		for (j = 0; datsh->_env[i][j]; j++)
			;

		write(STDOUT_FILENO, datsh->_env[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}
