#include "shell.h"

/**
 * main - carries out primary actions - read, parse, execute, print
 * @argc: argument count
 * @argv: argument vector
 * @envp: environment vector
 *
 * Return: 0
 */
int main(int argc, char **argv, char **envp)
{
	/* defining string literals to handle/store user input */
	char *cmd_statement = NULL, *path_executable = NULL, *path = NULL;
	/* defining default buffer sizes as func arguments */
	size_t buffer_size = 0;
	ssize_t line_size = 0;
	/* defining buffers to be passed as func arguments */
	char **tokenised_command = NULL, **paths = NULL;

	/* declaring unused variables within this scope */
	(void)envp, (void)argv;

	/* checking for errors (argc has to be at least 1) */
	if (argc < 1)
		return (-1);

	/* initialising a signal handler - (non-)interactive mode, CTRL+C */
	signal(SIGINT, handle_signal);

	/* putting the logic in an infinite loop to continuously take input */
	while (1)
	{
		/* start by freeing buffers and pre-allocated memory */
		free_defined_buffer(tokenised_command);
		free_defined_buffer(paths);

		/* freeing path to executable command */
		free(path_executable);

		/* prompt the user for input */
		prompt_user();

		/* reading user input */
		line_size = getline(&cmd_statement, &buffer_size, stdin);
		/* checking for getline errors, EOF, CTRL+D */
		if (line_size < 0)
			break;
		info.ln_count++;
		if (cmd_statement[line_size - 1] == '\n')
			cmd_statement[line_size - 1] = '\0';

		/* extracting the command components by tokenising input */
		tokenised_command = get_string_tokens(cmd_statement);

		/**
		 * checking tokeniser output for errors or
		 * e.g. someone just pressed enter (newline)
		 */
		if (tokenised_command == NULL || *tokenised_command == NULL
			|| **tokenised_command == '\0')
			/* restart loop */
			continue;

		/* to check if passed command is builtin */
		if (check_builtin(tokenised_command, cmd_statement))
			/* if it is, handles builtin then restart prompt */
			continue;
		/* find PATH directories */
		path = find_path();
		/* split PATH directories into array with each directory */
		paths = get_string_tokens(path);
		/* test if path is valid */
		path_executable = test_path(paths, tokenised_command[0]);

		/* check if the path provided was valid */
		if (!path_executable)
			perror(argv[0]);
		else
			execution(path_executable, tokenised_command);
		/* after execution, restart prompt */
	}
	/* if getline errors, EOF, CTRL+D */
	if (line_size < 0 && flags.interactive_mode)
		write(STDERR_FILENO, "\n", 1);
	free(cmd_statement);
	return (0);
}

