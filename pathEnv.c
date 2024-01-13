#include "header.h"


/**
 * pathEnv - Resolves the full path of a command using the PATH environment
 * variable.
 *
 * @comando: The command for which to resolve the full path.
 *
 * Return: The full path of the command if found in PATH
 * or the original command
 * if not found or in case of memory allocation failure.
 */
char *pathEnv(char *comando)
{
	char *path = _obtenerEnv("PATH");
	char *copy = strdup(path);
	char *dir, *route = NULL;

	if (copy == NULL)
	{
		perror("memory allocation failure");
		exit(EXIT_FAILURE);
	}

	dir = strtok(copy, ":");

	while (dir != NULL)
	{
		size_t route_len = strlen(dir) + strlen(comando) + 2;

		route = malloc(route_len);

		if (route == NULL)
		{
			free(copy);
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		snprintf(route, route_len, "%s/%s", dir, comando);

		if (access(route, X_OK) == 0)
		{
			free(copy);
			return (route);
		}

		free(route);
		dir = strtok(NULL, ":");
	}

	free(copy);
	return (strdup(comando));
}
