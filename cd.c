#include "main.h"

/**
 * cd - Changes the current working directory of the process
 * @path: path to the dir to change to
 * @old_pwd: Pointer to the variable holding
 * the prev working directory
 * @environ: environment variable
 * Return: 0 on success, -1 on failure
 */
int cd(const char *path, char **old_pwd, char **environ)
{
	char *cw_dir;
	int change_dir;

	if (path == NULL)
		path = getenv("HOME");

	if (path != NULL && _strccmp(path, "-") == 0)
		path = getenv("HOME");

	change_dir = chdir(path);
	if (change_dir == -1)
	{
		perror("cd");
		return (-1);
	}

	cw_dir = getcwd(NULL, 0);
	if (cw_dir == NULL)
	{
		perror("cd");
		return (-1);
	}

	if (*old_pwd)
		free(*old_pwd);

	*old_pwd = cw_dir;
	if (_setenv("PWD", cw_dir, 1, &environ) == -1)
	{
		perror("cd");
		return (-1);
	}

	return (0);
}
