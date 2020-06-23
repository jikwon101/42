#include <string.h> //strerror
#include <stdio.h>
#include <errno.h> //errorno
int main()
{
	FILE *inf = fopen("new1.c", "r");
	if (!inf)
		printf("Error opening file : %s\n", strerror(errno));
	return (0);
}
