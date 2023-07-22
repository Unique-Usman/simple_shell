#include "main.h"
/**
 * checkargs - check argument
 * @args: arg param
 * @path: arg path
 * @command_found: command_found param
 * @tmp_path: temporal path
 * @token: token param
 * @command_path: command path
 * Return: 0 if succes else 1
 */

int checkargs(char **args, char *path, int command_found,
	       char *tmp_path, char *token, char *command_path)
{
	if (_strchr(args[0], '/') == NULL)
	{
		if (!_strcmp(args[0], "setenv") || !_strcmp(args[0], "unsetenv") ||
							!_strcmp(args[0], "cd"))
			return (2);
		/* Command doesn't contain a slash, so search in PATH */
		path = getenv("PATH");
		command_found = 0;
		/* Creating tmp_path to avoid changing the value of the path */
		tmp_path = malloc(sizeof(char) * (_strclen(path) + 1));
		_strccpy(tmp_path, path);
		token = strtok(tmp_path, ":"); /* Used the tmp_path here */

		while (token != NULL)
		{
			_strccpy(command_path, token);
			_strcat(command_path, "/");
			_strcat(command_path, args[0]);

			if (access(command_path, X_OK) == 0)
			{
				/* Command found in PATH, execute it */
				args[0] = _strdup(command_path);
				command_found = 1;
				break;
			}
			token = strtok(NULL, ":");
		}

		free(tmp_path);
		if (!command_found)
		{
			command_not_found(args[0], "command not found");
			return (1);
		}

		return (1);
	}
	return (0);
}
