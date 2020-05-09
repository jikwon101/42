/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:37:17 by jikwon            #+#    #+#             */
/*   Updated: 2020/02/05 16:56:03 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char new)
{
	if ((new == '\t') || (new == ' ') || (new == '\f')
		|| (new == '\r') || (new == '\v') || (new == '\n'))
		return (1);
	else
		return (0);
}

int	w_sign(char *str)
{
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	while (is_space(str[i]) == 1)
		i++;
	while (str[i] != 0)
	{
		if ((str[i] == '-') || (str[i] == '+'))
		{
			if (str[i] == '-')
				sign = sign * (-1);
		}
		else
			return (sign);
		i++;
	}
	return (sign);
}

int	to_nbt(char *str)
{
	int i;
	int len;
	int	nbr;

	i = 0;
	len = 0;
	nbr = 0;
	while (str[len])
		len++;
	while (i < len)
	{
		if ((str[i] >= '0') && (str[i] <= '9'))
		{
			nbr = nbr * 10 + (str[i] - '0');
			i++;
			if ((str[i] < '0') || (str[i] > '9'))
				return (nbr);
		}
		else
			i++;
	}
	return (nbr);
}

int	ft_atoi(char *str)
{
	int	sign;
	int number;

	if (str == 0)
		return (0);
	sign = w_sign(str);
	number = to_nbt(str);
	return (sign * number);
}
