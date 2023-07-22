#include "main.h"

/**
 * _getline - reads an entire line from stream
 * @ptr: stores the address of the buffer containing the texts
 * @len: allocated number of buffer bytes
 * @stream: file stream to read from
 * Return: number of bytes read
 */
int _getline(char **ptr, size_t *len, FILE *stream)
{
	int buffer = 16;
	int pos = 0;
	int c; /*character to be gotten from the outspace*/
	*ptr = malloc(sizeof(char) * buffer);
	if (*ptr == NULL)
		return (-1);
	while ((c = fgetc(stream)) != EOF && c != '\n')
	{
		if (pos >= buffer)
		{
			buffer = 2 * buffer;
			*ptr = realloc(*ptr, buffer);
			if (*ptr == NULL)
				return (-1);
			(*ptr)[pos++] = c;
		}
		else
		{
			(*ptr)[pos++] = c;
		}
	}
	(*ptr)[pos] = '\0';
	*len = pos;
	free(ptr);
	return (1);
}
