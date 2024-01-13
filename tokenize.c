#include "header.h"

/**
 * split - Tokenizes an input string into an array of words.
 *
 * @textoEntrada: The input string to be tokenized.
 * @cantidadPalabras: Ptr to an int to store the word count.
 *
 * Return: Ptr to the dynamically allocated array of words.
 *         Must be freed by the caller.
 */

char **split(const char *textoEntrada, int *cantidadPalabras)
{
	char **wordList = NULL;
	char *token;
	char *copy = strdup(textoEntrada);

	wordList = malloc(MAX_WORDS * sizeof(char *));

	if (wordList == NULL)
	{
		free(copy);
		perror("memory allocation failure");
		exit(EXIT_FAILURE);
	}

	token = strtok(copy, SEPARATOR);

	*cantidadPalabras = 0;

	while (token != NULL)
	{
		wordList[*cantidadPalabras] = strdup(token);
		(*cantidadPalabras)++;
		token = strtok(NULL, SEPARATOR);
	}

	wordList[*cantidadPalabras] = NULL;
	free(copy);
	return (wordList);
}
