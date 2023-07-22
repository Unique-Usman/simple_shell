#include "main.h"
#include <stdlib.h>

/**
 * makeenv - Creates an environment variable by
 * concatenating the name and value.
 * @name: The name of the environment variable.
 * @value: The value of the environment variable.
 *
 * Return: The created environment variable string, or NULL on failure.
 */
char *makeenv(const char *name, const char *value)
{
	int count1 = 0, count2 = 0;
	char *str;

	count1 = _strclen(name);
	count2 = _strclen(value);

	str = malloc(sizeof(char) * (count1 + count2 + 2));
	if (!str)
		return (NULL);

	str[0] = '\0';
	str = _strccat(str, name);
	str = _strccat(str, "=");
	str = _strccat(str, value);

	return (str);
}
