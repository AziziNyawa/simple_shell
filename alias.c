#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALIASES 100
#define MAX_ALIAS_LENGTH 100



void print_alias(Alias alias);
void print_aliases(void);
Alias *find_alias(char *name);
void set_alias(char *name, char *value);
void handle_alias_command(int argc, char *argv[]);

/**
 * print_alias - Print an alias in the form name='value'.
 */
void print_alias(Alias alias)
{
	printf("%s='%s'\n", alias.name, alias.value);
}

/**
 * print_aliases - Print all aliases, one per line, in the form name='value'.
 */
void print_aliases(void)
{
	for (int i = 0; i < numAliases; i++)
	{
		print_alias(aliases[i]);
	}
}

/**
 * find_alias - Find an alias by name.
 *
 * @param name: The name of the alias to find.
 * @return: Pointer to the found alias, or NULL if not found.
 */
Alias *find_alias(char *name)
{
	for (int i = 0; i < numAliases; i++)
	{
		if (strcmp(aliases[i].name, name) == 0)
		{
			return (&aliases[i]);
		}
	}
	return (NULL);
}

/**
 * set_alias - Set an alias with the given name and value.
 * If the alias already exists, replace its value.
 * If the maximum number of aliases is reached, print an error message.
 *
 * @param name: The name of the alias.
 * @param value: The value of the alias.
 */
void set_alias(char *name, char *value)
{
	Alias *existing_alias = find_alias(name);

	if (existing_alias != NULL)
	{
		strcpy(existing_alias->value, value);

	}
	else if (numAliases < MAX_ALIASES)
	{
		Alias new_alias;

		strcpy(new_alias.name, name);

		strcpy(new_alias.value, value);

		aliases[numAliases++] = new_alias;

	}
	else
	{
		printf("Maximum number of aliases reached.\n");
	}
}

/**
 * handle_alias_command - Handle the alias builtin command.
 *
 * Usage: alias [name[='value'] ...]
 * - If no arguments are provided, print all aliases.
 * - If arguments are provided, treat them as alias names.
 * - If arguments are provided in the form name='value',
 * define new aliases or update existing ones.
 *
 * @param argc: The number of command-line arguments.
 * @param argv: An array of command-line arguments.
 */
void handle_alias_command(int argc, char *argv[])
{
	if (argc == 1)
	{
		print_aliases();
	}
	else if (argc == 2)
	{
		for (int i = 1; i < argc; i++)
		{
			Alias *alias = find_alias(argv[i]);

			if (alias != NULL)
			{
				print_alias(*alias);
			}
			else
			{
				printf("Alias '%s' not found.\n", argv[i]);
			}
		}
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			char *name = strtok(argv[i], "=");
			char *value = strtok(NULL, "=");

			if (name != NULL && value != NULL)
			{
				set_alias(name, value);
			}
		}
	}
}
