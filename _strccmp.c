#include "main.h"

/**
  * _strccmp - compare two strings
  * @s1: one string
  * @s2: one string
  * Return: int that tells num spaces in between
 */

int _strccmp(const char *s1, const char *s2)
{
	int i = 0;

	while (*(s1 + i) == *(s2 + i) && *(s1 + i))
		i++;

	if (*(s2 + i))
		return (*(s1 + i) - *(s2 + i));
	else
		return (0);
}
