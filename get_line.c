#include "shell.h"

/**
 * brg_line - assigns the line variable
 * @line_ptr: the buffer the stores str
 * @buffer: the buffer of string
 * @n: size of line
 * @z: the size of str
 */
void brg_line(char **line_ptr, size_t *n, char *buffer, size_t z)
{

	if (*line_ptr == NULL)
	{
		if  (z > BUFSIZE)
			*n = z;

		else
			*n = BUFSIZE;
		*line_ptr = buffer;
	}
	else if (*n < z)
	{
		if (z > BUFSIZE)
			*n = z;
		else
			*n = BUFSIZE;
		*line_ptr = buffer;
	}
	else
	{
		_strcpy(*line_ptr, buffer);
		free(buffer);
	}
}
/**
 * get_line - its reads the input stream
 * @line_ptr: the buffer that its function to store input
 * @n: size of buffer
 * @stream: it reads the input
 * Return: number of byte in it
 */
ssize_t get_line(char **line_ptr, size_t *n, FILE *stream)
{
	int j;
	static ssize_t input;
	ssize_t retrival;
	char *buffer;
	char y = 'z';

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * BUFSIZE);
	if (buffer == 0)
		return (-1);
	while (y != '\n')
	{
		j = read(STDIN_FILENO, &y, 1);
		if (j == -1 || (j == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (j == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFSIZE)
			buffer = _realloc(buffer, input, input + 1);
		buffer[input] = y;
		input++;
	}
	buffer[input] = '\0';
	brg_line(line_ptr, n, buffer, input);
	retrival = input;
	if (j != 0)
		input = 0;
	return (retrival);
}
