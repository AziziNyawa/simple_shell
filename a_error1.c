#include "shell.h"

/**
 * strcat_cd - its a that does concatenates
 * @datash: data relevance
 * @message: prints the message
 * @err: outputed message
 * @ver_str: line counting
 * Return: prints the error message
 */
char *strcat_cd(data_shell * datash, char *message, char *err, char *ver_str)
{
	char *ill_flag;

	_strcpy(err, datash->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, datash->args[0]);
	_strcat(err, message);
	if (datash->args[1][0] == '-')
	{
		ill_flag = malloc(3);
		ill_flag[0] = '-';
		ill_flag[1] = datash->args[1][1];
		ill_flag[2] = '\0';
		_strcat(err, ill_flag);
		free(ill_flag);
	}
	else
	{
		_strcat(err, datash->args[1]);
	}

	_strcat(err, "\n");
	_strcat(err, "\0");
	return (err);
}

/**
 * error_get - error message from the cd
 * @datash: data relevance
 * Return: message indicating error
 */
char *error_get(data_shell *datash)
{
	int len, lenid;
	char *err, *ver_str, *message;

	ver_str = aux_itoa(datash->counter);
	if (datash->args[1][0] == '-')
	{
		message = ": Its Illegal option ";
		lenid = 2;
	}
	else
	{
		message = ": it can't cd to ";
		lenid = _strlen(datash->args[1]);
	}

	len = _strlen(datash->av[0]) + _strlen(datash->args[0]);
	len += _strlen(ver_str) + _strlen(msg) + lenid + 5;
	err = malloc(sizeof(char) * (len + 1));

	if (err == 0)
	{
		free(ver_str);
		return (NULL);
	}

	err = strcat_cd(datash, message, error, ver_str);

	free(ver_str);

	return (err);
}

/**
 * errornot_found - error for command not found
 * @datash: data relevance
 * Return: print an error message
 */
char *errornot_found(data_shell *datash)
{
	int len;
	char *err;
	char *ver_str;

	ver_str = aux_itoa(datash->counter);
	len = _strlen(datash->av[0]) + _strlen(ver_str);
	len += _strlen(datash->args[0]) + 16;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(err);
		free(ver_str);
		return (NULL);
	}
	_strcpy(err, datash->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, datash->args[0]);
	_strcat(err, ": not found\n");
	_strcat(err, "\0");
	free(ver_str);
	return (err);
}

/**
 * errorexit_shell - error for get exit message
 * @datash: data relevance
 * Return: prints the error message
 */
char *errorexit_shell(data_shell *datash)
{
	int len;
	char *err;
	char *ver_str;

	ver_str = aux_itoa(datash->counter);
	len = _strlen(datash->av[0]) + _strlen(ver_str);
	len += _strlen(datash->args[0]) + _strlen(datash->args[1]) + 23;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(err, datash->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, datash->args[0]);
	_strcat(err, ": Illegal number: ");
	_strcat(err, datash->args[1]);
	_strcat(err, "\n\0");
	free(ver_str);

	return (err);
}
