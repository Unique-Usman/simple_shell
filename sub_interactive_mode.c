#include "main.h"

/**
 * sub_interactive_mode - sub interactive mode
 * @buffer: buffer param
 * @args: args param
 * @tk: tk param
 * @i: i parma
 * @environ: enviroment variable
 * @isInteractive: check the interactivity
 * Return: 0 for success. -1 for break and 1 for continue
 */
int sub_interactive_mode(char *buffer, char *args[], char *tk, int i,
		char ***environ, int isInteractive)
{
	int j, k;
	pid_t pid;
	char *command;

	char *commands[64]; /*Array to store individual commands separated by ;*/

	if (_strlen(buffer) == 0) /* check empty buffer */
		return (1);
	/* Tokenize input commands based on semicolon ; */
	tk = strtok(buffer, ";");
	i = 0;
	while (tk != NULL && i < 64)
	{
		commands[i] = tk;
		tk = strtok(NULL, ";");
		i++;
	}
	/* Process each individual command */
	for (j = 0; j < i; j++)
	{
		/* Tokenize the individual command */
		command = commands[j];
		k = 0;
		tk = strtok(command, " \n");
		while (tk != NULL && k < 64)
		{
			args[k] = tk;
			tk = strtok(NULL, " \n");
			k++;
		}
		args[k] = NULL;
		if (_strlen(args[0]) == 0) /* check empty command */
			continue;
		if (_strcmp(args[0], "exit") == 0)
			return (-1); /* implement exit built-in */
		/* Fork a new process to execute the command by calling excute_command() */
		execute_command(args, args, *environ);
	}

	return (0);
}

