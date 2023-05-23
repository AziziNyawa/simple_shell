#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Executes a command by printing and executing it using the system() function.
 *
 * @param command The command to execute.
 */
void execute_command(const char* command)
{
	printf("Executing command: %s\n", command);
	system(command);
}

/**
 * The main function of the program.
 *
 * Reads multiple commands from the user, separated by ';',
 * and executes each command based on the previous command's result and the logical operators.
 */
int main()
{
	char input[100];
	char* token;
	int status = 1;

	printf("Enter commands separated by ';':\n");
	fgets(input, sizeof(input), stdin);
	input[strcspn(input, "\n")] = '\0';

	token = strtok(input, ";");
	while (token != NULL)
	{
		if (status)
		{
			execute_command(token);
			status = system(token);
		}
		else
		{
			printf("Skipping command: %s\n", token);
		}

		if (status && strstr(token, "&&"))
		{
			status = 1;
		}
		else if (!status && strstr(token, "||"))
		{
			status = 1;
		}
		else
		{
			status = 0;
		}

		token = strtok(NULL, ";");
	}

	return (0);
}
