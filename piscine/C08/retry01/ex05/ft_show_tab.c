/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:22:00 by jikwon            #+#    #+#             */
/*   Updated: 2020/02/13 19:54:44 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

int		len(char *str)
{
	int	len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

void	ft_putstr(char *str)
{
	write(1, str, len(str));
}

void	ft_putnbr(int nb)
{
	int	m;
	int n;

	if (nb >= 0)
	{
		m = nb / 10;
		n = nb % 10 + '0';
		if (m != 0)
			ft_putnbr(m);
		write(1, &n, 1);
	}
	else
		return ;
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par->str != 0)
	{
		ft_putstr(par[i].str);
		ft_putstr("\n");
		ft_putnbr(par[i].size);
		ft_purstr("\n");
		ft_putstr(par[i].copy);
		ft_putstr("\n");
		i++;
	}
}
