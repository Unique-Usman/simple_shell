#include "main.h"
/**
 * exit_status - exits the program with a status code
 * @arg: status code
 * Return: void
 */
void exit_status(char *arg)
{
	int status = _atoi(arg);

	exit(status);
}
