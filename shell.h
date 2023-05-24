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

void execute_command(const char* command);
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
#endif
