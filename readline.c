#include "shell.h"

/**
 * read_line - reads line str
 * @i_of: gives back value of getline func
 * Return: input str
 */
char *read_line(int *i_of)
{
	char *input = NULL;
	size_t buffer_size = 0;

	*i_of = getline(&input, &buffer_size, stdin);

	return (input);
}
