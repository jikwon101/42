/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:10:21 by jikwon            #+#    #+#             */
/*   Updated: 2020/05/08 13:02:16 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(int *cnt, unsigned char temp, t_option *flag)
{
	int				count_m;
	char			*result;

	count_m = flag->min_width > 1 ? flag->min_width : 1;
	if ((result = (char *)malloc(count_m + 1)) == 0)
		return ;
	result[count_m] = '\0';
	if (flag->zero == 1 && flag->bar == 0)
		ft_memset(result, '0', (size_t)count_m);
	else
		ft_memset(result, ' ', (size_t)count_m);
	if (flag->bar)
		result[0] = temp;
	else
		result[count_m - 1] = temp;
	ft_putstr(result, count_m, cnt);
	free(result);
	return ;
}

void	print_s(int *cnt, char *temp, t_option *flag)
{
	char	*result;
	int		count_w;
	int		count_d;
	char	*temp_r;

	if (temp == NULL)
		temp = "(null)";
	count_d = ft_strlen(temp);
	if (flag->prec != -1)
		count_d = flag->prec < count_d ? flag->prec : count_d;
	count_w = flag->min_width - count_d;
	temp_r = ft_substr(temp, 0, (size_t)count_d);
	if (count_w > 0)
		result = ft_jst_str(temp_r, count_w, flag);
	else
		result = temp_r;
	ft_putstr(result, ft_strlen(result), cnt);
	free(result);
	if (!temp_r)
		free(temp_r);
	return ;
}

void	print_p(int *cnt, void *temp_d, t_option *flag)
{
	unsigned long int	temp;
	char				*tmp_c;
	char				*tmp_r;
	char				*result;
	int					cnt_w;

	temp = (unsigned long int)temp_d;
	tmp_c = (temp == 0 && flag->prec != -1) ? ft_strdup("") :
		ft_putnbr_base(temp, HEX_L);
	if (flag->zero == 1 && flag->bar == 0 && flag->prec == -1)
	{
		tmp_r = ft_setzero(flag, tmp_c, flag->sign);
		result = ft_strjoin("0x", tmp_r + 2);
	}
	else
	{
		tmp_r = ft_strjoin("0x", tmp_c);
		cnt_w = flag->min_width - ft_strlen(tmp_r);
		result = cnt_w > 0 ? ft_jst_str(tmp_r, cnt_w, flag) : ft_strdup(tmp_r);
	}
	ft_putstr(result, ft_strlen(result), cnt);
	free(result);
	free(tmp_c);
	free(tmp_r);
	return ;
}

void	print_di(int *cnt, int tmp, t_option *flag)
{
	char	*tmp_r;
	char	*tmp_c;
	int		cnt_w;
	char	*result;

	flag->sign = tmp < 0 ? -1 : 0;
	tmp = (flag->sign == -1 && tmp != -2147483648) ? -tmp : tmp;
	if (tmp == -2147483648)
		tmp_c = ft_strdup("2147483648");
	else if (tmp == 0 && flag->prec == 0)
		tmp_c = ft_strdup("");
	else
		tmp_c = ft_putnbr_base((unsigned long int)tmp, DEC);
	if (flag->zero == 1 && flag->prec == -1 && flag->bar == 0)
		result = ft_setzero(flag, tmp_c, flag->sign);
	else
	{
		tmp_r = ft_setprec(flag, tmp_c);
		cnt_w = flag->min_width - ft_strlen(tmp_r);
		result = cnt_w >= 0 ? ft_jst_int(tmp_r, cnt_w, flag) : ft_strdup(tmp_r);
		free(tmp_r);
	}
	ft_putstr(result, ft_strlen(result), cnt);
	free(result);
	free(tmp_c);
}

void	print_ux(int *cnt, unsigned int tmp, t_option *flag, char *base)
{
	char			*tmp_r;
	char			*tmp_c;
	int				cnt_w;
	char			*result;

	if (tmp == 0 && flag->prec == 0)
		tmp_c = ft_strdup("");
	else
		tmp_c = ft_putnbr_base((unsigned long int)tmp, base);
	if (flag->zero == 1 && flag->prec == -1 && flag->bar == 0)
		result = ft_setzero(flag, tmp_c, flag->sign);
	else
	{
		tmp_r = ft_setprec(flag, tmp_c);
		cnt_w = flag->min_width - ft_strlen(tmp_r);
		result = cnt_w >= 0 ? ft_jst_int(tmp_r, cnt_w, flag) : ft_strdup(tmp_r);
		free(tmp_r);
	}
	ft_putstr(result, ft_strlen(result), cnt);
	free(result);
	free(tmp_c);
	return ;
}
