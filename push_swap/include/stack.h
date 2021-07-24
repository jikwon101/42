#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				data;
}				t_node;

typedef struct s_stack
{
	t_node	*head;		//last added data
	int		size;
}				t_stack;			


void	pop(t_stack *st);
void	push(t_stack *st, int val);
int		top(t_stack *st);
void	clear(t_stack *st);

int		isempty(t_stack *st);
void	init(t_stack *st);
int		next(t_stack *st);
void	connecting(t_node *prev, t_node *net);

void	swap(t_stack *st);
void	rotate(t_stack *st);
void	reverse_rotate(t_stack *st);

# include "stack_print.h" //temp
#endif
