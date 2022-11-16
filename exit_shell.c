#include "shell.h"

/**
 * exit_command - handles exit builtin
 * @command: tokenised command
 * @str: input read from stdin
 *
 * Return: nothing
 */
void exit_command(char **command, char *str)
{
	/* free currently allocated memory before exit */
	free(str);
	free_defined_buffer(command);
	/* exit */
	exit(0);
}

