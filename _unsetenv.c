#include "main.h"
/**
 * _unsetenv - Unset an environment var
 * @name: name of the environment var to unset
 * @environ: Pointer to the environment variable arr
 *
 * Description: This function removes the specified
 * environment variable from the environment
 * variable array. It searches for the variable
 * by name and removes all occurrences
 * if multiple exist. If the variable does
 * not exist, the function does nothing.
 *
 * Return: None
 */
void _unsetenv(const char *name, char ***environ)
{
	int count = 0, pos = 0, i;
	bool isPresent = false;
	char **tmp_environ;

	while ((*environ)[count++] != NULL)
	{
	}
	for (i = 0; i < count - 1; i++)
	{
		if (_strstr((*environ)[i], name) != NULL)
		{
			isPresent = true;
			pos++;
		}
	}
	if (!isPresent)
	{
		return;
	}
	tmp_environ = malloc(sizeof(char *) * (count - pos));
	pos = 0;
	for (i = 0; i < count - 1; i++)
	{
		if (_strstr((*environ)[i], name) == NULL)
			tmp_environ[pos++] = (*environ)[i];
	}
	tmp_environ[pos] = NULL;
	(*environ) = tmp_environ;
}
