#include <stdio.h>

//new1.c 파일이 없을떄 
int main()
{
	FILE *inf = fopen("new1.c", "r");
	if (!inf)
		perror("ERROR in main");
	return (0);
}
