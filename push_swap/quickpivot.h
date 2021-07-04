#ifndef QUICKPIVOT_H
# define QUICKPIVOT_H

#include "stack.h"
#include <stdio.h> //temp
# define NOP -1

typedef struct	s_arr
{
	int	*data;
	int	head;
	int	size;
}				t_arr;

int		I(int i, int option)	;
void	initarr(t_arr *arr, int stsize);
void	insert(int pos, t_arr *arr, int val);
void	push_forward(int pos, t_arr *arr, int val);
void	push_backward(int pos, t_arr *arr, int val);
int		distance(int pos, t_arr *arr);
void	sort(t_arr *arr, t_stack *st);
int		find_pivot(t_stack *st, int *res);

void	printarray(t_arr *arr, int stsize);		//temp
#endif
