/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 02:24:47 by jikwon            #+#    #+#             */
/*   Updated: 2021/07/26 13:35:32 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(char **sets, int size, t_stack *a, t_stack *b)
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

void	clear_all(t_stack *a, t_stack *b, char **sets, int type)
{
	int	i;

	clear(a);
	clear(b);
	if (type == 2 && sets)
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

int	main(int ac, char *av[])
{
	int		size;
	t_stack	a;
	t_stack	b;
	char	**sets;

	size = ac - 1;
	sets = av + 1;
	if (ac == 2)
	{
		sets = ft_split(av[1], ' ');
		if (!sets)
			errorexit("Error : Error Malloc\n");
		size = 0;
		while (sets[size])
			size++;
	}
	if (ac < 2 || !size || !check_arguments(size, sets))
		errorexit("Error : Check Arguments\n");
	init_stack(sets, size, &a, &b);
	control_log(INIT, NOCMD);
	a_sort(&a, &b, a.size);
	control_log(PRINT, NOCMD);
	control_log(CLEAR, NOCMD);
	clear_all(&a, &b, sets, ac);
}
