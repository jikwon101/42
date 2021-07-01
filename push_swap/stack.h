#ifndef FT_STACK_H
# define FT_STACK_H

#include <unistd.h>
#include <stdlib.h>

typedef struct	s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				data;
}				t_node;

typedef struct	s_stack
{
	t_node	*head;		//last added data
}				t_stack;			

void	init(t_stack *st);
void	pop(t_stack *st);
void	push(t_stack *st, int val);
int		top(t_stack const* st);
int		empty(t_stack *st);
void	clear(t_stack *st);
//void	swap(t_stack *st);
void	rotate(t_stack *st);
void	reverse_rotate(t_stack *st);

void	print(t_stack *st); //temp
#endif
