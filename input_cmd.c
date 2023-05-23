#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Executes a command.
 *
 * @param command The command to execute.
 */

void execute_command(const char* command)
{
	int result = system(command);
	if (result == -1)
	{
		perror("Failed to execute the command");
	}
}

/**
 * Main function of the simple shell.
 *
 * Takes a file as a command line argument and executes the commands in the file.
 * Each command should be on a separate line in the file.
 * The shell does not print a prompt or read from stdin in this mode.
 *
 * @param argc The number of command line arguments.
 * @param argv The array of command line arguments.
 * @return 0 on success, non-zero on failure.
 */
int main(int argc, char* argv[])
{
	char line[100];
	if (argc > 1)
	{
		FILE* file = fopen(argv[1], "r");
		if (file == NULL) {
			fprintf(stderr, "Failed to open the file: %s\n", argv[1]);
			return 1;
		}

		while (fgets(line, sizeof(line), file))
		{
			line[strcspn(line, "\n")] = '\0';

			execute_command(line);
		}

		fclose(file);
	}

	return 0;
}
