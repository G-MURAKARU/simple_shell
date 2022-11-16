#include "shell.h"

/**
 * find_path - finds the PATH env variable
 *
 * Return: PATH if PATH id found, NULL if not
 */
char *find_path(void)
{
	int counter = 0;
	/* extracting global variables */
	char **env = environ;
	/* defining a pointer to store the PATH string literal */
	char *path = NULL;

	/* looping through env variables */
	while (*env)
	{
		/* once PATH is found */
		if (_strncmp(*env, "PATH=", 5) == 0)
		{
			/**
			 * deletes PATH= part and returns
			 * string of directories in PATH only
			 */
			path = *env;

			while (*path && counter < 5)
			{
				path++;
				counter++;
			}
			return (path);
		}
		env++;
	}
	return (NULL);
}

/**
 * test_path - checks whether a PATH is valid
 * @path: tokenised PATH
 * @command: user input command
 *
 * Return: path appended with executable on success, NULL if failure
 */
char *test_path(char **path, char *command)
{
	int counter = 0;
	char *output;

	while (path[counter])
	{
		output = append_path(path[counter], command);
		/**
		 * iteratively parsing directories in PATH for the executable
		 * file corresponding to the user input
		 * checking if the file exists (F_OK)
		 * then checking if the file is executable (X_OK)
		 * rem: output string literal includes name of command binary
		 * e.g. /usr/bin/ls - it was appended in append_path()
		 */
		if (access(output, F_OK | X_OK) == 0)
			return (output);
		/* clear output if executable not in parsed directory, retry */
		free(output);
		counter++;
	}
	/* if executable not found */
	return (NULL);
}

/**
 * append_path - appends path (to binary) to input command
 * @path: path to command
 * @command: user command
 *
 * Return: buffer string with full path if success, NULL if failure
 */
char *append_path(char *path, char *command)
{
	char *str_buf;
	/* initialising variables to loop through string literals */
	size_t counter1 = 0, counter2 = 0;

	/* checking if command or path are NULL pointers */
	if (!command)
		command = "";
	if (!path)
		path = "";

	/* extra 2 spaces are for / and null-char below */
	str_buf = malloc(sizeof(char) * (_strlen(path) + _strlen(command) + 2));
	/* checking for malloc errors */
	if (!str_buf)
		return (NULL);

	/* populating decalred path with directory path */
	while (path[counter1])
	{
		str_buf[counter1] = path[counter1];
		counter1++;
	}
	/* ensuring directory path ends with a / */
	if (path[counter1 - 1] != '/')
	{
		str_buf[counter1] = '/';
		counter1++;
	}

	/* appending executable (user command) to constructed path */
	while (command[counter2])
	{
		str_buf[counter1 + counter2] = command[counter2];
		counter2++;
	}
	/* null-termination, as always */
	str_buf[counter1 + counter2] = '\0';

	return (str_buf);
}

