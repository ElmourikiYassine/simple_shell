#include "main.h"

/**
 * signal_handler - for interrupting a process.
 * @signum: The signal number received.
 * Return: Void
 */

void signal_handler(int signum)
{
	(void) signum;

	write(STDERR_FILENO, "\n$ ", 3);
	fflush(stdout);
}

