#include "main.h"

/**
 * main - Entry point
 * @argc: number of command line argument
 * @argv: array of command line arguments
 * @environ: enviroment variables
 * Return: Always 0 on success
 */

int main(int __attribute__((unused)) argc, char *argv[], char **environ)
{
	int isInteractive;

	isInteractive = check_mode();
	interactive_mode(argv, environ, isInteractive);

	return (0);
}
