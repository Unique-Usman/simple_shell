#include "main.h"

/**
 * *_strstr - locates a substring
 * @haystack: string to search in
 * @needle: substring to look for
 *
 * Return: pointer to the beginning of the located substring
 * or NULL if the substring is not found
 */
char *_strstr(char *haystack, const char *needle)
{
	int i, j, k;

	k = _strclen(needle);
	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (j = 0; needle[j] != '\0'; j++)
		{
			if (haystack[i + j] != needle[j])
				break;
		}
		if (!needle[j])
		{
			if (*(haystack + k) != '=')
				return (NULL);
			return (&haystack[i]);
		}
	}
	return (NULL);
}
