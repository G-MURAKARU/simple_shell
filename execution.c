#include "shell.h"

/**
 * execution - executes user commands
 * @command: actual command ro execute e.g. ls
 * @user_commands: array of pointers to command statements
 *
 * Return: nothing
 */
void execution(char *command, char **user_commands)
{
	pid_t exec_pid;
	int status;
	char **env = environ;

	exec_pid = fork();
	if (exec_pid < 0)
		perror(command);

	if (exec_pid == 0)
	{
		execve(command, user_commands, env);
		perror(command);
		free(command);
		free_defined_buffer(user_commands);
		exit(98);
	}
	else
		wait(&status);
}

