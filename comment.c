#include <stdio.h>
#include <string.h>

/**
 * Remove comments from a given line.
 *
 * @param line The line to process.
 */
void remove_comments(char *line)
{
	char *comment_pos = strchr(line, '#');

	if (comment_pos != NULL)
	{
		*comment_pos = '\0'; /* Truncate the line at the comment position*/
	}
}

int main(void)
{
	char line[100];

	printf("Enter a line of text (with comments): ");
	fgets(line, sizeof(line), stdin);

	remove_comments(line);

	printf("Line without comments: %s\n", line);

	return (0);
}
