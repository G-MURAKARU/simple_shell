#include "shell.h"

/**
 * get_string_tokens - extracts tokens from an input string
 * @str: string to be tokenised
 *
 * Return: an array of strings (double pointer)
 */
char **get_string_tokens(char *str)
{
	char *buffer = NULL, *buffer_copy = NULL, *token = NULL;
	char *delimiters = " :\t\r\n";
	char **tokens = NULL;
	unsigned int token_count = 1; /* always at least 1 token */
	size_t counter = 0, flag = 0;

	buffer = _strdup(str);
	if (!buffer)
		return (NULL);
	buffer_copy = buffer;
	while (*buffer_copy)
	{
		if (_strchr(delimiters, *buffer_copy) != NULL && flag == 0)
		{
			token_count++;
			flag = 1;
		}
		else if (_strchr(delimiters, *buffer_copy) == NULL
				&& flag == 1)
			flag = 0;
		buffer_copy++;
	}
	tokens = malloc(sizeof(char *) * (token_count + 1));
	token = strtok(buffer, delimiters);
	while (token)
	{
		tokens[counter] = _strdup(token);

		if (tokens[counter] == NULL)
		{
			free(tokens);
			return (NULL);
		}
		token = strtok(NULL, delimiters);
		counter++;
	}
	tokens[counter] = '\0';
	free(buffer);

	return (tokens);
}

