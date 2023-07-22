#include "main.h"

/**
 * _strclen - counts the length of a string
 * @s: param
 * Return: i
 */

int _strclen(const char *s)
{

int i = 0;

while (s[i] != '\0')
{
i++;

}

return (i);
}
