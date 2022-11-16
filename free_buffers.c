#include "shell.h"

/**
 * free_defined_buffer - iteratively frees buffers
 * @buffer: buffer to free
 *
 * Return: nothing
 */
void free_defined_buffer(char **buffer)
{
	/* defining a counter to loop through and index the buffer */
	/* rem: buffer is a double pointer */

	int i = 0;

	if (!buffer || buffer == NULL)
		return;
	while (buffer[i])
	{
		free(buffer[i]);
		i++;
	}

	free(buffer);
}

