#include "stack.h"

int	isempty(t_stack *st)
{
	return (st->size == 0);
}

void	init(t_stack *st)
{
	st->head = NULL;
	st->size = 0;
}

int	next(t_stack *st)
{
	return (st->head->next->data);
}

void	connecting(t_node *prev, t_node *next)
{
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
}
