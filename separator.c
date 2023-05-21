#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 100

/**
 *  Executes a command by invoking an external program using execl.
 *handle the separator - Executes a command by calling system().
 *
 * @param command - The command to execute.
 * execute_command
 */

void execute_command(const char *command)
{
	int result = system(command);

	if (result == -1)
	{
		perror("Failed to execute the program");
	}
	printf("Executing command: %s\n", command);
}

/**
 * The entry point of the program.
 *Reads commands from the user, separated by ';',
 and executes each command using the execute_command function.
 * @return The exit status of the program.
 */

int main(void)
{
	char input[MAX_COMMAND_LENGTH];
	char *token;

	printf("Enter commands separated by ';':\n");
	fgets(input, sizeof(input), stdin);
	input[strcspn(input, "\n")] = '\0';
	/*Split input into commands separated by ';'*/
	token = strtok(input, ";");
	while (token != NULL)
	{
		execute_command(token);
		token = strtok(NULL, ";");
	}

	return (0);
}
