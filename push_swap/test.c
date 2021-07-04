#include <stdio.h>

void T(int *i)
{
	i[0] = 100;
	i[1] = 999;
}

int main()
{
	int arr[2] = {0, 1};
	
	printf("%d %d\n", arr[0], arr[1]);
	T(arr);
	printf("%d %d\n", arr[0], arr[1]);
}
