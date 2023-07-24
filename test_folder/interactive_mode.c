#include "main.h"
/**
 * helper_sub_interactive_mode - helper of sub interactive mode
 * @args: args param
 * @i: i parma
 * @environ: enviroment variable
 * @isInteractive: check the interactivity
 * Return: 0 for succes. -1 for break and 1 for continue
 */
void helper_sub_interactive_mode(char **args, int i,
				 char ***environ, int isInteractive)
{
	char *old_pwd = NULL;

	if ((args[0] != NULL) && ((!_strcmp(args[0], "setenv")) ||
				  (!_strcmp(args[0], "exit")) ||
				  (!_strcmp(args[0], "unsetenv")) ||
				  (!_strcmp(args[0], "cd"))))
	{ /* implementing the exit status */
		if (_strcmp(args[0], "exit") == 0)
		{
			if (i == 2)
				exit_status(args[1]);
		}
		if (_strcmp(args[0], "setenv") == 0 && i == 3)
		{
			_setenv(args[1], args[2], 1, environ);
			env(*environ);
		}
		else if (_strcmp(args[0], "setenv") == 0)
		{
			if (!isInteractive)
			{
				env(*environ);
				perror(args[0]);
			}
		}
		if (_strcmp(args[0], "unsetenv") == 0 && i == 2)
		{
			_unsetenv(args[1], environ);
			env(*environ);
		}
		else if (_strcmp(args[0], "unsetenv") == 0)
		{
			if (!isInteractive)
			{
				env(*environ);
				perror(args[0]);
			}
		}
		if (_strcmp(args[0], "cd") == 0)
			cd(args[1], &old_pwd, *environ);

	}
}

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
			_strcpy(buffer, lineptr);
			tk = strtok(buffer, " \n");
			i = 0;
			while (tk != NULL && i < 64)
			{
				if (i != 0)
				{
					if (!_strcmp(tk, "env"))
						break;
					args[i - 1] = tk;
				}
				tk = strtok(NULL, " \n");
				i++;
			}
			/* set the last element of args to NULL */
			args[i - 1] = NULL;
			tmp++;
			helper_sub_interactive_mode(args, i - 1, &environ, isInteractive);
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
	free(lineptr);
}
