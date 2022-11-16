#include "shell.h"

/**
 * get_string_tokens - extracts tokens from an input string
 * @line: string to be tokenised
 *
 * Return: an array of strings (double pointer)
 */
char **get_string_tokens(char *str)
{
	/* defining a buffer to store the string to be tokenised */
	/* and a copy, used in counting number of tokens */
	char *buffer = NULL, *buffer_copy = NULL;
	/* defining a variable to store extracted tokens as string literals */
	char *token = NULL;
	/* defining a string of possible delimiters/separators */
	char *delimiters = " :\t\r\n";
	/* defining the array of tokens (strings) to return to caller */
	char **tokens = NULL;
	/* defining variables used in counting number of tokens */
	unsigned int token_count = 1; /* always at least 1 token */
	size_t counter = 0, flag = 0;

	/* duplicating the input string to preserve str */
	/* bc strtok mutates string arg when tokenising - subs in null chars */
	buffer = _strdup(str);

	/* checking for errors */
	if (!buffer)
		return (NULL);

	/* duplicating above buffer, used for counting */
	/* done to preserve the pointer to the beginning of buffer */
	buffer_copy = buffer;

	/* counting number of tokens for dynamic memory allocation */
	while (*buffer_copy)
	{
		/**
		 * if delimiter found, increase token count & set flag
		 * flag used to avoid unnecessary count
		 * i.e. if 2+ delimiters appear consecutively
		 */
		if (_strchr(delimiters, *buffer_copy) != NULL && flag == 0)
		{
			token_count++;
			flag = 1;
		}
		/* if not delimiter, reset found flag */
		else if (_strchr(delimiters, *buffer_copy) == NULL
				&& flag == 1)
			flag = 0;

		buffer_copy++;
	}

	/* now to extract tokens */

	/* dynamically allocating array to store tokens */
	tokens = malloc(sizeof(char *) * (token_count + 1));
	/* extracting first token */
	token = strtok(buffer, delimiters);

	while (token) /* while str, strtok returns NULL at null or newline */
	{
		tokens[counter] = _strdup(token);
		/* check for errors i think */

		if (tokens[counter] == NULL)
		{
			free(tokens);
			return (NULL);
		}
		/* next token - pass NULL as str arg for subsequent calls */

		token = strtok(NULL, delimiters);
		counter++;
	}
	/* tokens array should be null terminated */
	tokens[counter] = '\0';
	/* clear sub buffer */
	free(buffer);

	return (tokens);
}

