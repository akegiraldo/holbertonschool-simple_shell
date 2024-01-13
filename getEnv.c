#include "header.h"

/**
 * _obtenerEnv - Gets the value of an environment variable.
 *
 * @nombre: The name of the environment variable.
 *
 * Return: A pointer to the value of the environment variable.
 *         Returns NULL if the variable is not found or if input is invalid.
 *         The returned pointer is to the actual value within the environment.
 *         It should not be modified or freed by the caller.
 */
char *_obtenerEnv(const char *nombre)
{
	char **env_var;
	size_t name_length;

	if (nombre == NULL || environ == NULL)
		return (NULL);

	name_length = strlen(nombre);

	for (env_var = environ; *env_var != NULL; ++env_var)
	{
		if (strncmp(*env_var, nombre, name_length) == 0
				&& (*env_var)[name_length] == '=')
		{
			return (*env_var + name_length + 1);
		}
	}
	return (NULL);
}
