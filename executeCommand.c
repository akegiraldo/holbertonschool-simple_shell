#include "header.h"


/**
 * ejecutarComando - Executes a command with the given list of words.
 * @listaPalabras: Pointer to the array of words representing the command.
 *
 * This function executes a command with the given list of words. It uses fork
 * to create a new process for the command execution. The parent process waits
 * for the child process to complete.
 * The child process handles command execution,
 * including checking if the command exists and handling built-in commands.
 *
 */
void ejecutarComando(char **listaPalabras)
{
	struct stat st;
	char *comando;
	pid_t proceso;

	comando = pathEnv(listaPalabras[0]);
	if (stat(comando, &st) != 0)
	{
		fprintf(stderr, "bash: %s command not found\n", listaPalabras[0]);
		free(comando);
		return;
	}

	proceso = fork();
	if (proceso == -1)
	{
		perror("bash: fork");
		free(comando);
		return;
	}

	if (proceso != 0)
	{
		int estado;

		waitpid(proceso, &estado, 0);
		free(comando);
		if (estado != 0)
		{
			exit(2);
		}
		return;
	}

	if (execve(comando, listaPalabras, environ) == -1)
	{
		perror("bash: execve");
		free(comando);
		exit(EXIT_FAILURE);
	}
	free(comando);
}
