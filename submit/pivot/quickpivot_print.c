#include "quickpivot.h"

void	printarray(t_arr *arr, int stsize)
{
	printf("[%2d] : ", (arr->data)[arr->head]);
	int i = 0;
	while (i < stsize)
	{
		if ((arr->data)[i % stsize] == -100)
			printf("%2s ", ".");
		else
			printf("%2d ", (arr->data)[i % stsize]);
		i++;
	}
	printf("\n");
  printf("---------\n");
	int k = arr->head;
	while (k < arr->head + arr->size)
	{
		printf("%d ", (arr->data)[k % stsize]);
		k++;
	}
	printf("\n");
}
