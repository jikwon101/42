#include <stdio.h>
#include <math.h>

union Ca
{
	char make[20];
	char model[30];
	short year;
} car;
int main()
{
	int x = 1;
	while (x++ < 10)
	{
		printf("%d\n", x);
		x *= x;
		printf("%d\n", x);
	}	
}
