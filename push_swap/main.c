/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 02:24:47 by jikwon            #+#    #+#             */
/*   Updated: 2021/07/26 20:04:02 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_proc(char **sets, int size, t_stack *a, t_stack *b)
{
	int	i;

	i = size;
	init(a);
	init(b);
	while (i > 0)
	{
		push(a, ft_atoi(sets[i - 1]));
		i--;
	}
}

void	clear_proc(t_stack *a, t_stack *b, char **sets)
{
	int	i;

	clear(a);
	clear(b);
	if (sets)
	{
		i = 0;
		while (sets[i])
		{
			free(sets[i]);
			i++;
		}
		free(sets);
	}
}

char	**arrjoin(char **arr, char *new)
{
	int		i;
	int		cnt;
	char	**res;

	cnt = ft_arrsize(arr) + 1;
	res = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!res)
		errorexit(NULL);
	res[cnt] = NULL;
	i = 0;
	while (i < cnt - 1)
	{
		res[i] = arr[i];
		i++;
	}
	res[i] = new;
	free(arr);
	return (res);
}

char	**pre_proc(int ac, char **av, int *size)
{
	int		i;
	char	**temp;
	char	**res;
	int		j;

	i = 1;
	res = NULL;
	while (i < ac)
	{
		j = 0;
		temp = ft_split(av[i], ' ');
		if (!temp)
			errorexit(NULL);
		while (temp[j])
		{
			res = arrjoin(res, temp[j]);
			j++;
		}
		free(temp);
		i++;
	}
	*size = ft_arrsize(res);
	return (res);
}

int	main(int ac, char *av[])
{
	int		size;
	t_stack	a;
	t_stack	b;
	char	**sets;

	if (ac < 2)
		errorexit(NULL);
	sets = pre_proc(ac, av, &size);
	if  (!size || !check_arguments(size, sets))
		errorexit(NULL);
	init_proc(sets, size, &a, &b);
	control_log(INIT, NOCMD);
	a_sort(&a, &b, a.size);
	control_log(PRINT, NOCMD);
	control_log(CLEAR, NOCMD);
	clear_proc(&a, &b, sets);
}
