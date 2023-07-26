#include "main.h"

/**
 * exit_status - exits the program with a status code
 * @arg: status code
 * Return: void
 */
int exit_status(char *arg)
{
	int status;

	if (loop_isdigit(arg) == 0)
	{
		write(1, "#cisfun$: 1: exit: Illegal number: ", _strlen("#cisfun$: 1: eexit: Illegal number: "));
		write(1, arg, _strlen(arg));
		_putchar('\n');
		return (-1);
	}
	status = _atoi(arg);

	exit(status);
}
