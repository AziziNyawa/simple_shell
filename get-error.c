#include "shell.h"

/**
 * get_error - it calls the error message
 * @datash: contains agurments
 * @evalu: the value error
 * Return: error
 */
int get_error(data_shell * datash, int evalu)
{
	char *err;

	switch (evalu)
	{
		case -1:
			err = error_env(datash);
			break;
		case 126:
			err = error_path_126(datash);
			break;
		case 127:
			err = error_not_found(datash);
			break;
		case 2:
			if (_strcmp("exit", datash->args[0]) == 0)
				err = error_exit_shell(datash);
			else if (_strcmp("cd", datash->args[0]) == 0)
				err = error_get_cd(datash);
			break;
	}

	if (err)
	{
		write(STDERR_FILENO, err, _strlen(err));
		free(err);
	}

	datash->status = evalu;
	return (evalu);
}
