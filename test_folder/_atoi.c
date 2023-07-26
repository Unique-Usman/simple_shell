#include "main.h"

/**
 * _atoi - convert string to int
 * @str : string to be converted to int
 * Return: int form of str
 */

int _atoi(char *str)
{
	int sum = 0;

	while (*str != '\0')
	{
		sum = (sum * 10) + (*str - 48);
		str++;
	}

	return (sum);
}
