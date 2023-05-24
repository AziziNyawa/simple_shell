#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void execute_command(const char* command);
int main();

/*alias*/
void print_alias(Alias alias);
void print_aliases(void);
Alias *find_alias(char *name);
void set_alias(char *name, char *value);
void handle_alias_command(int argc, char *argv[]);

/*changing directory*/
int cd_command(const char *directory);
int main();

/*comments*/
void remove_comments(char *line);
int main(void);

/*logical_oparators*/
void execute_command(const char *command);

/*replacements*/
void replace_variables(char *line)

/* separators*/
void execute_command(const char *command);

/* inputs*/
int main(int argc, char *argv[]);
void execute_command(const char *command);

/*set-enviroment*/
void setenv_command(const char *variable, const char *value);
void unsetenv_command(const char *variable);

#endif
