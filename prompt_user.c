#include "shell.h"

/**
 * prompt_user - prints $ for user input
 *
 * Return: nothing
 */
void prompt_user(void)
{
	/**
	 * isatty() checks if the passed file descriptor is associated
	 * with an interactive device i.e./e.g. the terminal (tty)
	 */
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		flags.interactive_mode = 1;
	if (flags.interactive_mode)
		write(STDERR_FILENO, "# ", 2);
}

