#include "main.h"

/**
 * _atoi - convert string to int
 * @str : string to be converted to int
 * Return: int form of str
 */

int _atoi(char *str)
{
	int sum = 0;
	unsigned int num = 0;

	while (str[sum] != '\0')
	{
		if (str[sum] >= '0' && str[sum] <= '9')
			num = num * 10 + (str[sum] - '0');
		if (str[sum] > '9' || str[sum] < '0')
			return (-1);
		sum++;
	}
	return (num);
}
