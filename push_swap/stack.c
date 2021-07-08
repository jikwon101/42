#include "stack.h"

void	init(t_stack *st)
{
	st->head = NULL;
	st->size = 0;
}

int	empty(t_stack *st)
{
	return (st->size == 0);
}

void	connecting(t_node *prev, t_node *next)
{
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
}

void	pop(t_stack *st)
{
	t_node	*target;
	
	if (empty(st))
		return ;
	target = st->head;
	if (st->size == 1)
	{
		st->head = NULL;
		free(target);
	}
	else
	{
		connecting(target->prev, target->next);
		st->head = target->next;
		free(target);
	}
	st->size--;
}

void	push(t_stack *st, int val)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if(!newnode)
	{
		return ;
	}
	newnode->data = val;
	if (empty(st))
	{
		st->head = newnode;
		connecting(newnode, newnode);
	}
	else
	{
		t_node	*temp;

		temp = st->head->prev;
		connecting(newnode, st->head);
		connecting(temp, newnode);
		st->head = newnode;
	}
	st->size++;
}

int		top(t_stack const* st)
{
	return (st->head->data);
}

void	clear(t_stack *st)
{
	while (!empty(st))
	{
		pop(st);
	}
}

void	swap(t_stack *st)
{
	int	temp;

	if (empty(st))
		return ;
	temp = st->head->data;
	st->head->data = st->head->next->data;
	st->head->next->data = temp;
}

void	rotate(t_stack *st)
{
	if (empty(st))
		return ;
	st->head = st->head->next;
}

void	reverse_rotate(t_stack *st)
{
	if (empty(st))
		return ;
	st->head = st->head->prev;
}

#include <stdio.h>
void print(t_stack*st)
{
	t_node *pos;
	int		cnt = st->size;

	printf("------------\nTOP\n");
	pos = st->head;
	while (cnt)
	{
		printf("%d \n", pos->data);
		pos = pos->next;
		cnt--;
	}
	printf("END\n------------\n");
}

void printpair(t_stack *a, t_stack *b)
{
	t_node *a_pos = a->head;
	t_node *b_pos = b->head;
	int a_size = a->size;
	int b_size = b->size;

	printf("------------\nTOP\n");
	while (a_size > b_size)
	{
		printf("%2d\n", a_pos->data);
		a_pos = a_pos->next;
		a_size--;
	}
	while (a_size < b_size)
	{
		printf("            %2d\n", b_pos->data);
		b_pos = b_pos->next;
		b_size--;
	}
	while (a_size && b_size)
	{
		printf("%2d          %2d\n", a_pos->data, b_pos->data);
		a_pos = a_pos->next;
		b_pos = b_pos->next;
		a_size--;
		b_size--;
	}
	printf("\033[0;33m");	//set yello color
	printf(" a           b\n");
	printf("\033[0m");		//reset color
	printf("END\n------------\n");
	usleep(500000);
}

int	next(t_stack const* st)
{
	return (st->head->next->data);
}
