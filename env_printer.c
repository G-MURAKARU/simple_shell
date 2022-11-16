#include "shell.h"

/**
 * print_env - prints directories in global env variable, each on new line
 *
 * Return: nothing
 */
void print_env(void)
{
	int x = 0;
	/* extracting env from builtin global variable */
	char **env = environ;

	while (env[x])
	{
		write(STDOUT_FILENO, (const void *)env[x], _strlen(env[x]));
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
}

