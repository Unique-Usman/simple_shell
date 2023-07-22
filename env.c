#include "main.h"

/**
 * env - implements the built in env command
 * @environ: enviroment variables
 * Return: on sucess 1
 */

int env(char **environ)
{
	int i;
	int j = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		while (environ[i][j] != '\0')
		{
			_putchar(environ[i][j]);
			j++;
		}
		_putchar('\n');
		j = 0;

	}
	return (1);
}
