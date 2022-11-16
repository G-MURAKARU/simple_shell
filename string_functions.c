#include "shell.h"

/**
 * _strchr - locates a character in a string
 * @str: string to check
 * @chr: character to locate
 *
 * Return: pointer to first occurrence of c, NULL if absent
 */
char *_strchr(char *str, char chr)
{
	while (*str)
	{
		if (*str == chr)
			return (str);
		str++;
	}
	if (!chr)
		return (str);
	return (NULL);
}

/**
 * _strcmp - compares 2 strings for similarity
 * @str1: string to compare with str2
 * @str2: string to compare with str1
 *
 * Return: difference between strings
 */
int _strcmp(char *str1, char *str2)
{
	int counter = 0;
	int8_t difference;

	while (*(str1 + counter) == *(str2 + counter) && *(str1 + counter))
		counter++;

	difference = (*(str1 + counter) - *(str2 + counter));
	return (difference);
}

/**
 * _strlen - finds the length of a string
 * @str: string whose length is being found
 *
 * Return: length of string
 */
int _strlen(char *str)
{
	int counter = 0;

	while (*str)
	{
		counter++;
		str++;
	}

	return (counter);
}

/**
 * _strncmp - compares two strings up to n bytes
 * @str1: string to compare with str2
 * @str2: string to compare with str1
 * @n_bytes: number of bytes to compare
 *
 * Return: difference between str1 and str2
 */
int _strncmp(char *str1, char *str2, int n_bytes)
{
	int counter = 0;

	for (counter = 0; str1[counter] && str2[counter] && counter < n_bytes;
		counter++)
	{
		if (str1[counter] != str2[counter])
			return (str1[counter] - str2[counter]);
	}
	return (0);
}

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 *
 * Return: a string literal
 */
char *_strdup(char *str)
{
	char *new_str;
	int counter, length;

	if (!str)
		return (NULL);

	length = _strlen(str);
	new_str = malloc(sizeof(char) * (length + 1));

	if (!new_str)
		return (NULL);
	for (counter = 0; *str; str++, counter++)
		new_str[counter] = *str;

	new_str[counter++] = '\0';
	return (new_str);
}

