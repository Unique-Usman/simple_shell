#include "main.h"
/**
 * helper_sub_interactive_mode - helper of sub interactive mode
 * @args: args param
 * @i: i parma
 * @environ: enviroment variable
 * Return: 0 for succes. -1 for break and 1 for continue
 */
int helper_sub_interactive_mode(char **args, int i, char ***environ)
{
	char *old_pwd = NULL;

	if ((args[0] != NULL) && ((!_strcmp(args[0], "setenv")) ||
				(!_strcmp(args[0], "exit")) ||
				(!_strcmp(args[0], "unsetenv")) ||
				(!_strcmp(args[0], "cd"))))
	{ /* implementing the exit status */
		if (_strcmp(args[0], "exit") == 0)
		{
			if (i == 1)
				exit(0);
			if (i >= 2)
				exit_status(args[1]);
		}
		else if (_strcmp(args[0], "setenv") == 0 && i == 3)
		{
			_setenv(args[1], args[2], 1, environ);
		}
		else if (_strcmp(args[0], "setenv") == 0)
		{
			write(STDOUT_FILENO, "Too few argument\n", _strlen("Too few argument\n"));
		}
		else if (_strcmp(args[0], "unsetenv") == 0 && i == 2)
		{
			_unsetenv(args[1], environ);
		}
		else if (_strcmp(args[0], "unsetenv") == 0)
		{
			write(STDOUT_FILENO, "Too few argument\n", _strlen("Too few argument\n"));
		}
		else if (_strcmp(args[0], "cd") == 0)
			cd(args[1], &old_pwd, *environ);
		else
		{
			perror(args[0]);
		}

	}
	return (0);
}

/**
 * parse_args - split input line into arguments
 * @line: pointer to buffer
 * @args: command line arguments
 * @max_args: maximum number of command line args
 * Return: int
 */
int parse_args(char *line, char **args, int max_args)
{
	int i = 0;
	char *token = strtok(line, " \n");

	while (token != NULL && i < max_args - 1)
	{
		args[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}
	args[i] = NULL; /*Set the last element to NULL*/
	return (i);
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
	char *prompt = "#cisfun$ ";
	size_t n = 0;
	int nread, num_args, check2 = 0;
	bool see = true;

	while (see)
	{
		if (isInteractive)
			print_prompt(prompt);
		nread = getline(&lineptr, &n, stdin);
		if (nread == -1 || nread == EOF)
		{
			_putchar('\n');
			break; /*handle end of input or error*/
		}
		lineptr[nread - 1] = '\0'; /*Remove the newline character*/
		num_args = parse_args(lineptr, args, 64);
		if (num_args > 0)
		{
			if (_strcmp(args[0], "env") == 0)
				env(lineptr, environ);
			else if (_strcmp(args[0], "exit") == 0 || _strcmp(args[0], "setenv") == 0 ||
				_strcmp(args[0], "unsetenv") == 0 || _strcmp(args[0], "cd") == 0)
			{
						helper_sub_interactive_mode(args, num_args, &environ);
			}
			else
			{
				check2 = sub_interactive_mode_2(nread, args[0], argv, num_args,
						buffer, args, lineptr, 0,
						&environ);
				if (check2 == 1)
				{
					continue;
				}
				else if (check2 == -1)
				{
					break;
				}
			}
		}

		if (!isInteractive)
			see = false;
	}
	if (_strcmp(args[0], "env") != 0)
		free(lineptr);
}
