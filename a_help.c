#include "shell.h"

/**
 * aux_help_env - providing inbuilt information
 * Return: void
 */
void aux_help_env(void)
{
	char *helping = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, helping, _strlen(helping));
	helping = "Print the enviroment of the shell.\n";
	write(STDOUT_FILENO, helping, _strlen(helping));

}
/**
 * aux_help_setenv - gets the setenv info
 * Return: void
 */
void aux_help_setenv(void)
{

	char *helping = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, helping, _strlen(helping));
	helping = "int replace)\n\t";
	write(STDOUT_FILENO, helping, _strlen(helping));
	helping = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, helping, _strlen(helping));
}
/**
 * aux_help_unsetenv - gets info about builtin unsetenv
 * Return: void
 */
void aux_help_unsetenv(void)
{
	char *helping = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, helping, _strlen(helping));
	helping = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, helping, _strlen(helping));
}


/**
 * aux_help_all - entry point to builtin
 * Return: void
 */
void aux_help_all(void)
{
	char *helping = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, helping, _strlen(helping));
	helping = "These commands are defined internally.Type 'help' to see the list";
	write(STDOUT_FILENO, helping, _strlen(helping));
	helping = "Type 'help name' to find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, helping, _strlen(helping));
	helping = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, helping, _strlen(helping));
	helping = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, helping, _strlen(helping));
	helping = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, helping, _strlen(helping));
	helping = "unsetenv [variable]\n";
	write(STDOUT_FILENO, helping, _strlen(helping));
}
/**
 * aux_help_exit - Help in information
 * Return: void
 */
void aux_help_exit(void)
{
	char *helping = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, helping, _strlen(helping));
	helping = "Exits the shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, helping, _strlen(helping));
	helping = "statusis that of the last command executed\n";
	write(STDOUT_FILENO, helping, _strlen(helping));
}
