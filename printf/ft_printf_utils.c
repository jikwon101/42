/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:15:00 by jikwon            #+#    #+#             */
/*   Updated: 2020/05/08 12:37:52 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int len, int *cnt)
{
	int	i;

	i = 0;
	while (i < len)
	{
		write(1, &s[i], 1);
		(*cnt)++;
		i++;
	}
	return ;
}

char	*ft_jst_str(char *s, int count_w, t_option *flag)
{
	char	*temp;
	char	*result;

	if ((temp = (char *)malloc(count_w + 1)) == 0)
		return (0);
	temp[count_w] = '\0';
	ft_memset(temp, ' ', (size_t)count_w);
	if (flag->bar == 0)
		result = ft_strjoin(temp, s);
	else
		result = ft_strjoin(s, temp);
	free(temp);
	return (result);
}

char	*ft_jst_int(char *s, int count_w, t_option *flag)
{
	char	*temp;
	char	*result;

	if ((temp = (char *)malloc(count_w + 1)) == 0)
		return (0);
	temp[count_w] = '\0';
	if (flag->bar == 0 && flag->prec == -1 && flag->zero == 1)
		ft_memset(temp, '0', (size_t)count_w);
	else
		ft_memset(temp, ' ', (size_t)count_w);
	if (flag->bar == 0 && flag->prec == -1 && flag->zero == 1)
		result = ft_strjoin(temp, s);
	else if (flag->bar == 0)
		result = ft_strjoin(temp, s);
	else
		result = ft_strjoin(s, temp);
	free(temp);
	return (result);
}

char	*ft_setprec(t_option *flag, char *s)
{
	char	*temp;
	char	*temp_r;
	char	*result;
	int		count_p;

	count_p = flag->prec - ft_strlen(s);
	if (count_p <= 0 && flag->sign == 0)
		return (ft_strdup(s));
	else if (count_p <= 0 && flag->sign == -1)
		return (ft_strjoin("-", s));
	if ((temp = (char *)malloc(count_p + 1)) == 0)
		return (0);
	temp[count_p] = '\0';
	ft_memset(temp, '0', (size_t)count_p);
	temp_r = ft_strjoin(temp, s);
	if (flag->sign == -1)
	{
		result = ft_strjoin("-", temp_r);
		free(temp_r);
	}
	else
		result = temp_r;
	free(temp);
	return (result);
}

char	*ft_setzero(t_option *flag, char *s, int sign)
{
	int		count_w;
	char	*temp;
	char	*temp_r;
	char	*result;

	count_w = flag->min_width - ft_strlen(s) + sign;
	if (count_w <= 0)
	{
		result = (sign == 0) ? ft_strdup(s) : ft_strjoin("-", s);
		return (result);
	}
	if ((temp = (char *)malloc(count_w + 1)) == 0)
		return (0);
	temp[count_w] = '\0';
	ft_memset(temp, '0', (size_t)count_w);
	if (sign == -1)
	{
		temp_r = ft_strjoin("-", temp);
		result = ft_strjoin(temp_r, s);
		free(temp_r);
	}
	else
		result = ft_strjoin(temp, s);
	free(temp);
	return (result);
}
