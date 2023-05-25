#include "main.h"

/* File atoa.c
 * Authors: Azizi Nyawa
 * Ronald
 */

/**
 * interactive - returns true if in interactive mode
 * @info: structure of the address
 * Return: returns 1 if its interactive
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delim
 * @c: the char to check
 * @delim: the delim string
 * Return: 1 if true, 0 if its a false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checks the alphabetic characters
 * @c: character inputer
 * Return: 1 if true and 0 if false
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - function to convert a string to a number value
 * @s: the string to be converted
 * Return: 1 if true and 0 if false
 */

int _atoi(char *s)
{
	int j, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (j = 0;  s[j] != '\0' && flag != 2; j++)
	{
		if (s[j] == '-')
			sign *= -1;

		if (s[j] >= '0' && s[j] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[j] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
