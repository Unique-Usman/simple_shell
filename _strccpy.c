#include "main.h"

/**
 * _strccpy - copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest
 * @dest: copy source to this buffer
 * @src: this is the source to copy
 * Return: copy of original source
 */

char *_strccpy(char *dest, const char *src)
{
int i;

for (i = 0; i <= _strclen(src); i++)
dest[i] = src[i];

return (dest);
}
