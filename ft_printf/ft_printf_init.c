/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:04:50 by jikwon            #+#    #+#             */
/*   Updated: 2020/05/07 11:08:13 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_tlist(t_option **flag)
{
	(*flag)->bar = 0;
	(*flag)->zero = 0;
	(*flag)->min_width = 0;
	(*flag)->prec = -1;
	(*flag)->sign = 0;
	return ;
}

int		ft_atoi_l(const char *str, int *i)
{
	int nbr;

	nbr = 0;
	while (ft_isdigit(str[*i]))
	{
		nbr = nbr * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (nbr);
}

void	check_width(const char *str, int *i, va_list args, t_option **flag)
{
	int	temp;

	if (str[*i] == '*')
	{
		temp = va_arg(args, int);
		(*i)++;
	}
	else
		temp = ft_atoi_l(str, i);
	if (temp < 0)
	{
		(*flag)->bar = 1;
		(*flag)->min_width = -temp;
	}
	else
		(*flag)->min_width = temp;
	return ;
}

void	check_prec(const char *str, int *i, va_list args, t_option **flag)
{
	int	temp;

	(*i)++;
	temp = 0;
	if (!ft_isdigit(str[*i]) && str[*i] != '*')
	{
		(*flag)->prec = 0;
		return ;
	}
	else if (ft_isdigit(str[*i]))
		temp = ft_atoi_l(str, i);
	else if (str[*i])
	{
		temp = va_arg(args, int);
		(*i)++;
	}
	if (temp < 0)
		(*flag)->prec = -1;
	else
		(*flag)->prec = temp;
	return ;
}

void	set_flag(const char *str, int *i, va_list args, t_option **flag)
{
	if ((*flag = (t_option *)malloc(sizeof(t_option))) == 0)
		return ;
	init_tlist(flag);
	while (str[*i] == '-' || str[*i] == '0')
	{
		if (str[*i] == '0')
			(*flag)->zero = 1;
		else
			(*flag)->bar = 1;
		(*i)++;
	}
	if (str[*i] == '*' || ft_isdigit(str[*i]))
		check_width(str, i, args, flag);
	if (str[*i] == '.')
		check_prec(str, i, args, flag);
	return ;
}
