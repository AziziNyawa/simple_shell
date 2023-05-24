#include "shell.h"

/**
 * withno_comment - it deletes the comments
 * @in: inputed str
 * Return: the input with no comments
 */
char *withno_comment(char *in)
{
	int i, end_at;

	end_at = 0;
	for (i = 0; in[i]; i++)
	{
		if (in[i] == '#')
		{
			if (i == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[i - 1] == ' ' || in[i - 1] == '\t' || in[i - 1] == ';')
				end_at = i;
		}
	}

	if (end_at != 0)
	{
		in = _realloc(in, i, up_to + 1);
		in[end_at] = '\0';
	}

	return (in);
}

/**
 * shell_loop - the main loop of shell
 * @datash: data relevance
 * Return: nothing is returned.
 */
void shell_loop(data_shell *datash)
{
	char *input;
	int looping, i_of;

	looping = 1;
	while (looping == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		input = read_line(&i_of);
		if (i_of != -1)
		{
			input = withno_comment(input);
			if (input == NULL)
				continue;

			if (check_syntax_error(datash, input) == 1)
			{
				datash->status = 2;
				free(input);
				continue;
			}
			input = rep_var(input, datash);
			looping = split_commands(datash, input);
			datash->counter += 1;
			free(input);
		}
		else
		{
			looping = 0;
			free(input);
		}
	}
}
