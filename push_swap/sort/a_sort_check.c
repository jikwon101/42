#include "sort.h"

int	check_ra(t_stack *a)
{
	// t 5 1 2 3 4 (type1)
	int		i;
	t_node	*pos;

	i = 0;
	pos = a->head->next;
	while (i < a->size - 1)
	{
		if (pos->data > pos->next->data)
			return (0);
		pos = pos->next;
		i++;
	}
	return (1);
}

int	check_rra(t_stack *a)
{	
	// t : 2 3 4 5 1 (type2)
	int		i;
	t_node	*pos;

	i = 0;
	pos = a->head->prev;
	while (i < a->size - 1)
	{
		if (pos->data > pos->next->data)
			return (0);
		pos = pos->next;
		i++;
	}
	return (1);
}

int	check_sa(t_stack *a)
{
	// t 2 1 3 4 5 (type1)
	t_node	*pos;
	t_node	*second;
	int		i;

	i = 0;
	pos = a->head->next;
	second = pos;
	while (i < a->size - 2)
	{	
		if (pos->data > pos->next->data)
			return (0);
		pos = pos->next;
		i++;
	}
	if (top(a) > second->data && top(a) < second->next->data)
		return (1);
	return (0);
}

int a_order_type(t_stack *a, int lsize)
{
	if (a->size == lsize && a->size > 3)
	{
		if (check_ra(a))
			return (1);
		if (check_rra(a))
			return (2);
	}
	if (check_sa(a))
		return (3);
	return (0);
}

