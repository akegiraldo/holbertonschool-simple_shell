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
	char *comando;
	pid_t proceso;

	comando = pathEnv(listaPalabras[0]);

	proceso = fork();
	if (proceso == -1)
	{
		perror("bash: fork");
		free(comando);
		return;
	}

	else if (proceso == 0)
	{
		/*
		 *if (strcmp("printenv", wordList[0]) == 0 || strcmp("env", wordList[0])==0)
		 *{
		 *	printEnv();
		 *	free(command);
		 *}
		*/
		execve(comando, listaPalabras, environ);
		perror("./shell");
		exit(EXIT_FAILURE);
	}
	else
	{
		int estado;

		waitpid(proceso, &estado, 0);
		free(comando);
	}
}
