#include "header.h"

/**
 * leerEntrada - Reads a line of input from standard input.
 *
 * This function dynamically allocates memory for a line of input using
 * getline. It removes the newline character and returns the allocated buffer.
 *
 * Return: Pointer to the allocated input buffer. Must be freed by the caller.
 */
char *leerEntrada()
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t read;

	read = getline(&buffer, &bufsize, stdin);

	if (read == -1)
	{
		exit(0);
	}

	buffer[strcspn(buffer, "\n")] = '\0';
	return (buffer);
}
