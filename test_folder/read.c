#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main ()
{
	char *buffer = malloc(sizeof(char) * 100);
	printf("Hello World\n");
	printf("Enter  your name\n");
	read(0, buffer, 100);
	printf("%s", buffer);
}
