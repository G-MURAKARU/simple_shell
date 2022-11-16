#include "shell.h"

/**
 * check_builtin - checks if a passed command is builtin
 * @command: tokenised command statement
 * @str: string derived from getline function call
 *
 * Return: 1 if builtin/executed, 0 if not
 */
int check_builtin(char **command, char *str)
{
	if (handle_builtin(command, str))
		return (1);
	else if (**command == '/')
	{
		execution(command[0], command);
		return (1);
	}
	return (0);
}

