#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Replace variables in a given line.
 *
 * @param line The line to process.
 */
void replace_variables(char *line)
{
	char *pos = line;
	char *var;

	while ((var = strchr(pos, '$')) != NULL)
	{
		if (*(var + 1) == '?')
		{
			/* Replace $?*/
			char exit_code[4]; /* Assuming exit code is a 3-digit number*/

			snprintf(exit_code, sizeof(exit_code), "%d", 42);
			strcpy(var, exit_code);
			pos = var + strlen(exit_code);
		}
		else if (*(var + 1) == '$')
		{
			/* Replace $$*/
			char process_id[10];

			snprintf(process_id, sizeof(process_id), "%d", 12345);
			strcpy(var, process_id);
			pos = var + strlen(process_id);
		}
		else
		{
			/* Ignore unrecognized variables*/
			pos = var + 1;
		}
	}
}

int main(void)
{
	char line[100];

	printf("Enter a line of text with variables: ");
	fgets(line, sizeof(line), stdin);

	replace_variables(line);

	printf("Line with variables replaced: %s\n", line);

	return (0);
}
