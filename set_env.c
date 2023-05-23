#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * setenv_command - Initializes or modifies an environment variable.
 *
 * @variable: The name of the environment variable.
 * @value: The value to set for the environment variable.
 *
 * Description:
 * This function initializes a new environment variable or modifies an
 * existing one with the provided value. If successful, it prints a
 * confirmation message. If an error occurs, it prints an error message
 * to stderr.
 */
void setenv_command(const char *variable, const char *value)
{
	int result = setenv(variable, value, 1);

	if (variable == NULL || value == NULL)
	{
		fprintf(stderr, "setenv: Invalid arguments\n");
		return;
	}
	if (result != 0)
	{
		fprintf(stderr, "setenv: Failed to set environment variable\n");
		return;
	}

	printf("Environment variable set: %s=%s\n", variable, value);
}

/**
 * unsetenv_command - Removes an environment variable.
 *
 * @variable: The name of the environment variable to remove.
 *
 * Description:
 * This function removes the specified environment variable. If successful,
 * it prints a confirmation message. If an error occurs, it prints an error
 * message to stderr.
 */

void unsetenv_command(const char *variable)
{
	int result = unsetenv(variable);

	if (variable == NULL)
	{
		fprintf(stderr, "unsetenv: Invalid argument\n");
		return;
	}

	if (result != 0)
	{
		fprintf(stderr, "unsetenv: Failed to unset environment variable\n");
		return;
	}

	printf("Environment variable unset: %s\n", variable);
}
