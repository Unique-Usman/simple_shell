#include "main.h"
/**
 * _setenv - Set the value of an environ var
 * @name: name of the environ var
 * @value: val to set for the environment va
 * @overwrite: indicate whether to overwrite an existing var
 * @environ: Pointer to the environment var array
 *
 * Description: This function sets the value
 * of an environment variable in the provided
 * environment variable array.
 * If the variable already exists and 'overwrite'
 * is set to 0, the variable will
 * not be modified. If 'overwrite' is set to 1,
 * the variable will be overwritten
 * with the new value. If the variable does
 * not exist, it will be appended to the array.
 *
 * Return: 0 on success, -1 on failure
 */
int _setenv(const char *name, const char *value,
	    int overwrite, char ***environ)
{
	int count = 0, pos, i;
	bool isPresent = false;
	char **tmp_environ;

	while ((*environ)[count++] != NULL)
	{
		if (_strstr((*environ)[count - 1], name) != NULL)
		{
			isPresent = true;
			pos = count - 1;
		}
	}
	if (isPresent && (overwrite == 0))
	{
		return (0);
	}
	if (isPresent && (overwrite == 1))
	{
		(*environ)[pos] = makeenv(name, value);
		return (0);
	}

	tmp_environ = malloc(sizeof(char *) * (count + 1));
	for (i = 0; i < count - 1; i++)
	{
		tmp_environ[i] = (*environ)[i];
	}

	tmp_environ[i++] = makeenv(name, value);
	tmp_environ[i] = NULL;
	(*environ) = tmp_environ;
	return (0);
}
