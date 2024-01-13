#include "header.h"

/**
 * main - Entry point for the program.
 *
 * This function serves as the main execution point for the program.
 * It contains a loop that repeatedly prompts the user with ":) ", reads
 * their input, processes it, and continues until the user enters:
 * "exit" or "quit".
 *
 * Return: Always returns 0 to indicate successful completion.
 */
int main(void)
{
	int cantidad;
	char *buffer;
	char **listaPalabras;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			printf(":) ");

		fflush(stdout);
		buffer = leerEntrada();

		if (strcmp(buffer, "exit") == 0 || strcmp(buffer, "quit") == 0)
		{
			free(buffer);
			exit(0);
		}


		listaPalabras = split(buffer, &cantidad);

		if (cantidad > 0)
			ejecutarComando(listaPalabras);

		limpiarMemoria(buffer, listaPalabras);
	}
	return (0);
}
