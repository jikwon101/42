#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"
# include "log.h"
# include <stdio.h> //temp

# define RED "\x1b[31m"	//temp
# define BLUE "\x1b[36m" //temp
# define RESET "\x1b[0m" //temp

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif
