#include "shell.h"

/**
 * getbuilt_in - builtin that parse arguments
 * @cmd: command
 * Return: function pointer
 */
int (*getbuilt_in(char *cmd))(data_shell *)
{
	builtin_t builtin[] = {
		{ "env", _env },
		{ "exit", exit_shell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", cd_shell },
		{ "help", get_help },
		{ NULL, NULL }
	};
	int j = 0;

	while (builtin[i].name != NULL)
	{
		if (_strcmp(builtin[i].name, cmd) == 0)
			break;
		j++;
	}

	return (builtin[i].f);
}

