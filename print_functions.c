#include "shell.h"

/**
 * _putchar - writes a character c to stdout
 * @c: character to write
 *
 * Return: 1 on success; -1 on failure, errno set
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string
 * @str: string literal to be printed
 *
 * Return: number of bytes(chars) printed
 */
int _puts(char *str)
{
	uint8_t counter = 0;

	while (*(str + counter) != '\0')
	{
		_putchar(*(str + counter));
		counter++;
	}
	return (counter);
}

