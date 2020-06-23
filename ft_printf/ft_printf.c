/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:25:01 by jikwon            #+#    #+#             */
/*   Updated: 2020/05/08 12:01:14 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_conv(const char *str, int *i, int *cnt, va_list args)
{
	t_option	*flag;

	(*i)++;
	set_flag(str, i, args, &flag);
	if (str[*i] == '%')
		print_c(cnt, '%', flag);
	else if (str[*i] == 'c')
		print_c(cnt, va_arg(args, int), flag);
	else if (str[*i] == 's')
		print_s(cnt, va_arg(args, char *), flag);
	else if (str[*i] == 'p')
		print_p(cnt, va_arg(args, void *), flag);
	else if (str[*i] == 'd' || str[*i] == 'i')
		print_di(cnt, va_arg(args, int), flag);
	else if (str[*i] == 'u')
		print_ux(cnt, va_arg(args, unsigned int), flag, DEC);
	else if (str[*i] == 'x')
		print_ux(cnt, va_arg(args, unsigned int), flag, HEX_L);
	else if (str[*i] == 'X')
		print_ux(cnt, va_arg(args, unsigned int), flag, HEX_U);
	(*i)++;
	free(flag);
}

int		ft_printf(const char *str, ...)
{
	int		index;
	int		cnt;
	va_list	args;

	index = 0;
	cnt = 0;
	va_start(args, str);
	while (str[index])
	{
		if (str[index] == '%')
			print_conv(str, &index, &cnt, args);
		else
		{
			write(1, &str[index], 1);
			cnt++;
			index++;
		}
	}
	return (cnt);
}
