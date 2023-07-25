#include <stdio.h>
#include <string.h>

int main()
{
	char *s;
	size_t b = 10;

	getline(&s, &b, stdin);

	for (int i = 0; i <= strlen(s); i++){
		printf("%d ", s[i]);
	}
}
