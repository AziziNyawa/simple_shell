#include "shell.h"

/**
 * getsig_int - handles ctr+c
 * @signal: functions to handle the signal
 */
void getsig_int(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
