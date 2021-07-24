#include "stack.h"

void	swap(t_stack *st)
{
	int	temp;

	if (isempty(st))
		return ;
	temp = st->head->data;
	st->head->data = st->head->next->data;
	st->head->next->data = temp;
}

void	rotate(t_stack *st)
{
	if (isempty(st))
		return ;
	st->head = st->head->next;
}

void	reverse_rotate(t_stack *st)
{
	if (isempty(st))
		return ;
	st->head = st->head->prev;
}
