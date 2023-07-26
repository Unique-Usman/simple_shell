#ifndef MAIN_H
#define MAIN_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

int _putchar(char c);
void execute_command(char* args[], char *argv[], char **environ);
void print_prompt(const char* prompt);
int check_mode();
void interactive_mode(char *argv[], char **environ, int isInteractive);
void non_interactive_mode(char *argv[], char **environ);
int env(char **environ);
size_t _getline(char **str);
int exit_status(char *arg);

char *_strcat(char *s1, char *s2);
char *_strchr(char *s, char c);
size_t _strcspn(const char *str, const char *reject);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strccpy(char *dest, const char *src);
int _strlen(char *s);
int _strclen(const char *s);

int _strcmp(char *s1, char *s2);
int _strccmp(const char *s1, const char *s2);
void command_not_found(char *filename, char *error_output);
int _atoi(char *str);
int checkargs(char **args, char *path, int command_found, char *tmp_path, char *token, char *command_path);
int sub_interactive_mode(char *buffer, char **args, char *tk, int i, char ***environ);
int sub_interactive_mode_2(int nread, char *tk, char **argv, 
				int i, char *buffer, char **args,
				char *lineptr, int check, char ***environ);
int checkbin(char *str);
char* makeenv(const char *name, const char *value);
char *_strstr(char *haystack, const char *needle);
char *_strccat(char *s1, const char *s2);
void _unsetenv(const char *name, char ***environ);
int _setenv(const char *name, const char *value, int overwrite, char ***environ);
int helper_sub_interactive_mode(char **args, int i, char ***environ);
int cd(const char *path, char **old_pwd, char **environ);
int _isdigit(int c);
int loop_isdigit(char *str);
#endif
