/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 21:08:49 by jikwon            #+#    #+#             */
/*   Updated: 2020/02/10 02:06:05 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check(   )
{

}

int print()
{

}

int solve_puzzle(int index)
{
	int i;
	char new[10];

	i = 0;
	while (i < 10)
	{
		if (check == 1)
			solve_puzzle(index+1);
		else
			i++;
}

int	ft_ten_queens_puzzle(void)
{
	int i;

	i = 0;
	while (i < 10)
	{
		solve_puzzle(i)
		i++;
	}
	return (count);
}
