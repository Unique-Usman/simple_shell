#include "main.h"

/**
 * _getline - stores into malloced buffer the user's command into shell
 * @str: buffer to store what was read to
 * Return: number of characters read or -1 on EOF
 */
ssize_t _getline(char **str)
{
	ssize_t i, no_of_char_read = 0;
	char buff[1024];
	char *newline_pos;

	*str = NULL; /* Initialize the str pointer to NULL */
	i = read(STDIN_FILENO, buff, 0);
	/* Check for EOF before reading any characters */
	if (i == 0)
		return (-1);

	while ((i = read(STDIN_FILENO, buff, 1023)) > 0)
	{
		buff[i] = '\0'; /* Null-terminate the read data */

		newline_pos = _strchr(buff, '\n');
		if (newline_pos != NULL) /* Check if a newline character is found */
		{
			*newline_pos = '\0'; /* Null-terminate the line at the newline character */
			/* Update the number of characters read to include the newline */
			i = newline_pos - buff + 1;
		}

		no_of_char_read += i; /* Increment the total number of characters read */

		/* Allocate/reallocate memory for str and concatenate buff to it */
		*str = *str ? realloc(*str, no_of_char_read + 1)
					: malloc(no_of_char_read + 1);
		if (*str == NULL)
			return (-1); /* Memory allocation failed */
		_strcat(*str, buff);

		if (newline_pos != NULL) /* If newline character is found, break the loop */
			break;
	}

	return (no_of_char_read);
}

