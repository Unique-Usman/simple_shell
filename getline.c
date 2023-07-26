#include "main.h"

/**
 * _getline - Custom getline function for the shell
 * @str: Double pointer to the buffer where the line will be stored
 *
 * Return: Number of characters read or -1 on error or EOF
 */
ssize_t _getline(char **str)
{
	static char buffer[1024];
	static ssize_t buff_size;
	static ssize_t current_pos;
	char c;
	ssize_t num_read, line_len;

	if (buff_size == 0 || current_pos >= buff_size)
	{
		current_pos = 0;
		buff_size = read(STDIN_FILENO, buffer, sizeof(buffer));
		if (buff_size <= 0)
			return (buff_size); /* Return -1 on error or EOF */
	}
	/* Allocate memory for the line buffer */
	*str = malloc(buff_size + 1);
	if (*str == NULL)
		return (-1); /* Memory allocation failed */
	line_len = 0; /* Number of characters in the current line */
	while (current_pos < buff_size)
	{
		c = buffer[current_pos++];
		(*str)[line_len++] = c;
		/* If a newline is encountered, break the loop */
		if (c == '\n')
			break;
	}
	/* Null-terminate the line */
	(*str)[line_len] = '\0';
	if (current_pos >= buff_size)
	{
		buff_size = 0;
		current_pos = 0;
	}
	return (line_len);
}

