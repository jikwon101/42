#include <stdio.h>

int T(int i)
{
	return (i + 1);
}

int main()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};

	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");
	arr[T(0)] = arr[T(1)];
	
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
