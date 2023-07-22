#include "main.h"
/**
 * command_not_found - to print errror
 * @filename: name of the file which contain the error
 * @error_output: error message
 */

void command_not_found(char *filename, char *error_output)
{
	while (*filename != '\0')
		_putchar(*filename++);
	_putchar(':');
	_putchar(' ');
	while (*error_output != '\0')
		_putchar(*error_output++);
	_putchar('\n');
}
