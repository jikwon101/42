#include "stack.h"

void	init(t_stack *st)
{
	st->head = NULL;
}

int	empty(t_stack *st)
{
	if (st->head == NULL)
		return (1);
	return (0);
}

void	pop(t_stack *st)
{
	t_node	*temp;

	if (empty(st))
		return ;
	temp = st->head;
	st->head = st->head->next;
	if (st->head)
		st->head->prev = NULL;
	free(temp);
}

void	push(t_stack *st, int val)
{
	t_node *newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
		return ;
	newnode->data = val;
	newnode->prev = NULL;
	if (empty(st))
	{
		newnode->next = NULL;
		st->head = newnode;
	}
	else
	{
		newnode->next = st->head;
		st->head->prev = newnode;
		st->head = newnode;
	}
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
/*
void	swap(t_stack *st)
{
	t_node	*temp;

	temp = st->head;
	st->head = st->head->next;
	st->head->prev = NULL;
	temp->prev = st->head;
	temp->next = st->head->next;
	st->head->next = temp;
}
*/
void	rotate(t_stack *st)
{
	t_node	*temp;
	t_node	*pos;

	temp = st->head;
	st->head = st->head->next;
	st->head->prev = NULL;
	temp->prev = NULL;
	temp->next = NULL;
	pos = st->head;
	while (pos->next)
	{
		pos = pos->next;
	}
	pos->next = temp;
	temp->prev = pos;
}

void	reverse_rotate(t_stack *st)
{
	t_node	*pos;
	t_node	*temp;

	pos = st->head;
	while (pos->next)
	{
		pos = pos->next;
	}
	temp = pos;
	pos->prev->next = NULL;
	temp->prev = NULL;
	temp->next = st->head;
	st->head->prev = temp;
	st->head = temp;
}

#include <stdio.h>
void print(t_stack*st)
{
	t_node *pos;
	
	printf("------------\nTOP\n");
	pos = st->head;
	while (pos)
	{
		printf("%d\n", pos->data);
		pos = pos->next;
	}
	printf("END\n------------\n");
}
