#include "main.h"

/**
 * print_buffer - Prints a buffer to the standard output
 * @buffer: The buffer to be printed
 * @size: The size of the buffer
 *
 * Description: This function prints the contents of a buffer in chunks
 * of 1024 bytes to the standard output.
 */
void print_buffer(char *buffer, unsigned int size)
{
	unsigned int i;

	for (i = 0; i < size; i += 1024)
	{
		unsigned int chunk_size = (i + 1024 < size) ? 1024 : size - i;

		write(1, buffer + i, chunk_size);
	}
}

