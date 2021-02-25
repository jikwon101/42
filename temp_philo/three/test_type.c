#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a = -3;
	unsigned int b = 500;
	
	if (a > b)
		printf("Int is bigger\n");
	if (a < b)
		printf("Uint is bigger\n");
	if (b > a)
		printf("unsigne dis bigger\n");
	if (b < a)
		printf("int is bigger\n");
}
