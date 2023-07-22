#include "main.h"

/**
 * sub_interactive_mode - sub interactive mode
 * @buffer: buffer param
 * @args: args param
 * @tk: tk param
 * @i: i parma
 * @environ: enviroment variable
 * @isInteractive: check the interactivity
 * Return: 0 for succes. -1 for break and 1 for continue
 */
int sub_interactive_mode(char *buffer, char **args, char *tk, int i,
			 char ***environ, int isInteractive)
{
	if (_strlen(buffer) == 0) /* check empty buffer */
		return (1);
	/*used 1 above because of \n*/
	if (_strcmp(buffer, "exit") == 0)
		return (-1); /* implement exit built-in */
	/* tokenize input commands */
	tk = strtok(buffer, " \n");
	i = 0;
	while (tk != NULL && i < 64)
	{
		args[i] = tk;
		tk = strtok(NULL, " \n");
		i++;
	}
	/* set the last element of args to NULL */
	args[i] = NULL;
	helper_sub_interactive_mode(args, i, environ, isInteractive);
	return (0);
}
