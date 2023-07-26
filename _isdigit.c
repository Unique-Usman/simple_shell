#include "main.h"

/**
 * _isdigit - checks if an argument is a digit or not
 * @c: argument to check
 * Return: 1 if digit and 0 if otherwise
 */

int _isdigit(int c)
{

if (c >= '0' && c <= '9')
{
return (1);
}
else
{
return (0);
}

}

/**
  * loop_isdigit - loops through a string passed into _isdigit()
  * @str: argument to check
  * Return: 1 if digit and 0 if otherwise
  */
int loop_isdigit(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (!_isdigit(str[i]))
			return (0);
		i++;
	}

	return (1);

}
