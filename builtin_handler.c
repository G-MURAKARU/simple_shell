#include "shell.h"

/**
 * handle_builtin - handles execution of builtin functions
 * @command: - tokenised command
 * @str: - input read from stdin
 *
 * Return: 1 if executed, 0 if not
 */
int handle_builtin(char **command, char *str)
{
	/* builtins to handle are env and exit */
	struct builtin builtin = {"env", "exit"};

	/* checking for string matching with env || exit */
	if (_strcmp(*command, builtin.env) == 0)
	{
		print_env();
		return (1);
	}
	else if (_strcmp(*command, builtin.exit) == 0)
	{
		exit_command(command, str);
		return (-1);
	}
	return (0);
}

