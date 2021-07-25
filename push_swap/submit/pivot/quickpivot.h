/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickpivot.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 02:29:53 by jikwon            #+#    #+#             */
/*   Updated: 2021/07/25 22:09:51 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICKPIVOT_H
# define QUICKPIVOT_H

# include "../include/libft.h"
# include "../include/stack.h"

# define NOP -1

typedef struct s_arr
{
	int	*data;
	int	head;
	int	size;
}				t_arr;

int		_i(int i, int option);
void	initarr(t_arr *arr, int stsize);
void	insert(int pos, t_arr *arr, int val);
int		distance(int pos, t_arr *arr);
int		find_pivot(t_stack *st, int lsize);

#endif
