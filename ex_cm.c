#include "main.h"
/**
 * execute_command - creates a child process and executes
 * the program in the process
 * @args: array of commands passed to the child process
 * @argv: command line arguments
 * @environ: environment variable
 * Return: nothing
 */
void execute_command(char **args, char *argv[], char **environ)
{
	pid_t child_pid;
	int status, check;
	char *path = NULL; /*var that recieves the return must not be muted directly*/
	char *token = NULL;
	char command_path[1024];
	int command_found = 0;
	char *tmp_path = NULL;

	check = checkargs(args, path, command_found, tmp_path, token, command_path);
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		/* child process*/
		if (execve(args[0], args, environ) == -1)
		{
			if (check == 0)
				perror(argv[0]);
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);/* parent process */
	}
}
