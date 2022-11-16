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
	char *cmd_statement = NULL, *path_executable = NULL, *path = NULL;
	size_t buffer_size = 0;
	ssize_t line_size = 0;
	char **tokenised_command = NULL, **paths = NULL;

	(void)envp, (void)argv;
	if (argc < 1)
		return (-1);
	signal(SIGINT, handle_signal);
	while (1)
	{
		free_defined_buffer(tokenised_command);
		free_defined_buffer(paths);
		free(path_executable);
		prompt_user();
		line_size = getline(&cmd_statement, &buffer_size, stdin);
		if (line_size < 0)
			break;
		info.ln_count++;
		if (cmd_statement[line_size - 1] == '\n')
			cmd_statement[line_size - 1] = '\0';

		tokenised_command = get_string_tokens(cmd_statement);
		if (tokenised_command == NULL || *tokenised_command == NULL
			|| **tokenised_command == '\0')
			continue;
		if (check_builtin(tokenised_command, cmd_statement))
			continue;
		path = find_path();
		paths = get_string_tokens(path);
		path_executable = test_path(paths, tokenised_command[0]);
		if (!path_executable)
			perror(argv[0]);
		else
			execution(path_executable, tokenised_command);
	}
	if (line_size < 0 && flags.interactive_mode)
		write(STDERR_FILENO, "\n", 1);
	free(cmd_statement);
	return (0);
}

