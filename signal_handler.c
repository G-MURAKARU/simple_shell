#include "shell.h"

/**
 * handle_signal - keeps track of interactive mode, handles SIGINT (CTRL+C)
 * @signal_number: signal number associated with SIGINT
 *
 * Return: nothing
 */
void handle_signal(int signal_number)
{
	/* declaring the signal number as unused variable */
	(void)signal_number;

	/* writing to the terminal to revert to non-interactive */
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "# ", 2);
}

