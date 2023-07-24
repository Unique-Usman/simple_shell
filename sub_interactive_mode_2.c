#include "main.h"

/**
 * sub_interactive_mode_2 - sub section of intreactive mode
 * @nread: nread param
 * @tk: tk param
 * @argv: argv param
 * @i: i param
 * @buffer: buffer param
 * @args: args param
 * @lineptr: line param
 * @check: check param
 * @isInteractive: check the interactivity
 * @environ: environment variable
 * Return: 1 if continue, -1 if break
 */
int sub_interactive_mode_2(int nread, char *tk, char **argv,
			int i, char *buffer, char **args, char *lineptr, int check,
			char ***environ, int isInteractive)
{
	/*if end of file (EOF) or empty stdin is encountered - CTRL + D*/
	if (nread == EOF)
	{
		_putchar('\n');
		return (-1);
	}
	_strcpy(buffer, lineptr);
	check = sub_interactive_mode(buffer, args, tk, i, environ, isInteractive);
	if (check == 1)
	{
		return (1);
	}
	else if (check == -1)
	{
		return (-1);
	}
	/*execute_command(args, argv, *environ);*/
	return (0);
}
