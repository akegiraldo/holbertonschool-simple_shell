#include "header.h"

/**
 * limpiarMemoria - Frees the allocated memory for buffer and wordList.
 *
 * @buffer: Pointer to the dynamically allocated input buffer.
 * @listaPalabras: Pointer to the dynamically allocated array of words.
 *
 * This function frees the memory allocated for the input buffer and the array
 * of words.
 * It iterates through the wordList and frees each word before freeing
 * the entire array.
 */
void limpiarMemoria(char *buffer, char **listaPalabras)
{
	int i;

	for (i = 0; listaPalabras[i] != NULL; i++)
	{
		free(listaPalabras[i]);
		listaPalabras[i] = NULL;
	}
	free(listaPalabras);
	free(buffer);
}
