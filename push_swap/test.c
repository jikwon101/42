#include "push_swap.h"
#include <stdio.h>
int main()
{
	t_stack a;

	init(&a);
	for (int i = 1 ; i <= 4 ; i++)
	{
		push(&a, i);
	}
	int pivot = find_pivot(&a, 5);
	printf("%d\n", pivot);
}
