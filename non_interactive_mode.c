#include "main.h"

/**
 * non_interactive_mode - executes when programing
 * is running in non_interactive mode
 * @argv: command line arguments
 * @environ: environment variables
 * Return: nothing
 */

void non_interactive_mode(char *argv[], char **environ)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	char *args[64];
	char *tk;
	int i;

	if (getline(&buffer, &buffer_size, stdin) != -1)
	{
		buffer[_strcspn(buffer, "\n")] = '\0';
		i = 0;
		/* tokenize input commands */
		tk = strtok(buffer, " ");
		i = 0;
		while (tk != NULL && i < 64)
		{
			args[i] = tk;
			tk = strtok(NULL, " ");
			i++;
		}

		/* set the last element of args to NULL */
		args[i] = NULL;

		/*Call the execute_command function passing the arguments*/
		execute_command(args, argv, environ);

		/* Free the buffer allocated by getline*/
		free(buffer);
	}
}
