#ifndef SHELL_H
#define SHELL_H
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_env;
	char *pid;
} data_shell;
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

<<<<<<< HEAD
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

=======
void execute_command(const char* command);
extern char **environ;
char *strcat_cd(data_shell *, char *, char *, char *);
char *error_get(data_shell *datash);
char *errornot_found(data_shell *datash);
char *errorexit_shell(data_shell *datash);int main();
int (*getbuilt_in(char *cmd))(data_shell *datash);
char *read_line(int *i_of);
void shell_loop(data_shell *datash);
sep_list *addsep_nodeend(sep_list **head, char sep);
void freesep_list(sep_list **head);
line_list *addline_nodeend(line_list **head, char *line);
void freeline_list(line_list **head);
void brg_line(char **line_ptr, size_t *n, char *buffer, size_t j);
ssize_t get_line(char **line_ptr, size_t *n, FILE *stream);
char *_get_env(const char *name, char **_env);
int _environ(data_shell *datash);
int get_error(data_shell *datash, int evalu);
void getsig_int(int signal);
int gethelp(data_shell *datash);
char *withno_comment(char *in);
void aux_help_env(void);
void aux_help_setenv(void);
void aux_help_unsetenv(void);
void aux_help_all(void);
void aux_help_exit(void);
>>>>>>> 6844c9208d9b7fbab7e7f876b6022ded02fc63fd
#endif
