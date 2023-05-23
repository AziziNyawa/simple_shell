#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * Changes the current directory of the process.
 *
 * @param directory The directory to change to
 * If NULL or "-", changes to the previous directory.
 * @return 0 on success, -1 on failure.
 */
int cd_command(const char *directory)
{
	char *home = getenv("HOME");
	char *previous = getenv("PWD");
	int result = chdir(directory);

	if (directory == NULL || strcmp(directory, "-") == 0)
	{
		if (previous != NULL)
			directory = previous;
		else if (home != NULL)
			directory = home;
		else
			return (-1);
	}

	if (result == 0)
	{
		setenv("PWD", directory, 1);
		return (0);
	}
	else
	{
		perror("Failed to change directory");
		return (-1);
	}
}

/**
 * The main function of the program.
 *
 * Reads a command from the user, interprets it as a cd command,
 * and changes the current directory accordingly.
 */

int main()
{
	char input[100];
	int len, result;

	printf("Enter a cd command: ");
	fgets(input, sizeof(input), stdin);
	len = strlen(input);

	if (len > 0 && input[len - 1] == '\n')
		input[len - 1] = '\0';

	result = cd_command(input);
	if (result == 0)
		printf("Directory changed successfully.\n");

	return (0);
}
