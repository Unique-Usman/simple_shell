#include "main.h"

/**
 * _getline - stores into malloced buffer the user's command into shell
 * @str: buffer to store what was read to
 * Return: number of characters read
 */
size_t _getline(char **str)
{
	ssize_t i = 0, no_of_char_read = 0, num_of_loop = 0, new_line = 0, j = 0;
	char buff[1024];

	/* read while there is bytes left to read */
	while (new_line == 0 && (i = read(STDIN_FILENO, buff, 1024 - 1)))
	{
		if (i == -1) /* -1 for error */
			return (-1);

		buff[i] = '\0';

		j = 0;
		while (buff[j] != '\0')
		{
			if (buff[j] == '\n')
				new_line = 1;
			j++;
		}

		/* copy what's read to buff into _getline's buffer */
		if (num_of_loop == 0) /* malloc the first time */
		{
			i++;
			*str = malloc(sizeof(char) * i);
			*str = _strcpy(*str, buff);
			no_of_char_read = i;
			new_line = 1;
		}
		else /*realloc the subsequent time*/
		{
			no_of_char_read += i;
			*str = realloc(*str, sizeof(char) * no_of_char_read + 1);
			*str = _strcat(*str, buff);
		}
	}
	return (no_of_char_read);
}
