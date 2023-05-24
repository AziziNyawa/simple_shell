#include "shell.h"

/**
 * exit_shell - exits from the shell
 * @datsh: data relevances
 * Return: 0 on success.
 */
int exit_shell(data_shell *datsh)
{
	unsigned int u_status;
	int is_digit;
	int str_length;
	int big_num;

	if (datsh->args[1] != NULL)
	{
		u_status = _atoi(datsh->args[1]);
		is_digit = _isdigit(datsh->args[1]);
		str_length = _strlen(datsh->args[1]);
		big_num = u_status > (unsigned int)INT_MAX;
		if (!is_digit || str_length > 10 || big_num)
		{
			get_error(datsh, 2);
			datsh->status = 2;
			return (1);
		}
		datsh->status = (u_status % 256);
	}
	return (0);
}
