#include "main.h"


/**
 * _strcat - concatenates two string
 * @s1: string 1
 * @s2: string 2
 * Return: concatenated strings
 */
char *_strcat(char *s1, char *s2)
{

	int i = 0;
	int ii = 0;
	int c = 0;
	int j = 0;

	while (s1[i] != '\0')
	{
		i++;
		c++;
	}

	while (s2[ii] != '\0')
	{
		ii++;
		c++;
	}

	if (s1 == NULL)
		return (NULL);

	while (s2[j] != '\0')
	{
		s1[i] = s2[j];
		i++;
		j++;
	}

	s1[i] = '\0';

	return (s1);
}
