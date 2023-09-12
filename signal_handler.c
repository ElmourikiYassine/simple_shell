#include "main.h"
/**
 * signal_handler - <-- TODO -->
 * @signum: <-- TODO -->
 * Retrun: void
 */
void signal_handler(int signum)
{
	(void)signum;

	printf("\n$ ");
	fflush(stdout);
}
