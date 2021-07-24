#ifndef SORT_H
# define SORT_H

#include "../include/stack.h"
#include "../include/quickpivot.h"
#include "../include/command.h"

#define RED "\x1b[31m"
#define BLUE "\x1b[36m"
#define RESET "\x1b[0m"

# define ASC 1
# define DESC -1

int		is_ordered(t_stack *st, int type, int size);
void	divide(t_stack *a, t_stack *b, int type, int lsize);
void	merge(t_stack *a, t_stack *b, int type, int size);

int		a_ordered(t_stack *st, int size);
int		all_bigger_than(t_stack *a, int cnt , int pivot);
int		a_order_type(t_stack *a, int lszie);
int		a_arranged_type(t_stack *a, int lsize);
void	a_sort_sp(t_stack *a, int type);

void	a_divide(t_stack *a, t_stack *b, int lsize);
void	a_sort_three(t_stack *a);
void	a_sort(t_stack *a, t_stack *b, int lsize);

int		d_ordered(t_stack *st, int size);
int		all_smaller_than(t_stack *b, int cnt, int pivot);
int		d_order_type(t_stack *a, int lszie);
int		d_arranged_type(t_stack *a, int lsize);
void	d_sort_sp(t_stack *a, int type);

void	d_divide(t_stack *a, t_stack *b, int lsize);
void	d_sort_three(t_stack *b);
void	d_sort(t_stack *a, t_stack *b, int lsize);

#endif
