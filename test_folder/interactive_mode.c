#include "main.h"
/**
 * interactive_mode - executes when programing
 * is running in interactive mode
 * @argv: command line arguments
 * @environ: environment variables
 * @isInteractive: to chek interactivity
 * Return: nothing
 */
void interactive_mode(char *argv[], char **environ, int isInteractive)
{
	char buffer[1024], *lineptr = NULL, *args[64];
	char *prompt = "#cisfun$ ", *tk = NULL;
	size_t n = 0 /*size of buffer*/;
	int i = 0, check = 0, nread, len, check2 = 0;
	char *tmp = NULL;
	bool see = true;

	while (see)
	{
		if (isInteractive)
			print_prompt(prompt);
		nread = getline(&lineptr, &n, stdin);
		tmp = lineptr;
		len = _strlen(tmp);
		if (len > 0 && tmp[len - 1] == '\n')
			tmp[len - 1] = '\0';
		if (!_strcmp(tmp, "env"))
		{
			env(environ);
		}
		else
		{
			check2 = sub_interactive_mode_2(nread, tk, argv, i,
							buffer, args, lineptr, check,
							&environ, isInteractive);
			if (check2 == 1)
			{
				continue;
			}
			else if (check2 == -1)
			{
				break;
			}
		}
		if (!isInteractive)
			see = false;
	}
	for (i = 0; environ[i] != NULL; i++)
		free(environ[i]);
	for (i = 0; args[i] != NULL; i++)
		free(args[i]);
	free(environ);
	free(lineptr);
}
