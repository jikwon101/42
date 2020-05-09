/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:37:50 by jikwon            #+#    #+#             */
/*   Updated: 2020/02/05 16:56:25 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	find_index(char *base, char to_find)
{
	int	i;

	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == to_find)
			return (i);
		i++;
	}
	return (-1);
}

int	w_sign(char *str)
{
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\f'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\n')
		i++;
	while (str[i] != 0)
	{
		if ((str[i] == '-') || (str[i] == '+'))
		{
			if (str[i] == '-')
				sign = sign * (-1);
		}
		else
		{
			return (sign);
		}
		i++;
	}
	return (sign);
}

int	check_base(char *base)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	if (len(base) <= 1)
		return (0);
	while (base[i] != 0)
	{
		j = 0;
		temp = base[i];
		if ((base[i] == '+') || (base[i] == '-') || (base[i] == '\t')
			|| (base[i] == ' ') || (base[i] == '\f') || (base[i] == '\r')
				|| (base[i] == '\v') || (base[i] == '\n'))
			return (0);
		while (base[j] != 0)
		{
			if ((temp == base[j]) && (i != j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	if (check_base(base) != 1)
		return (0);
	while ((str[i] == '\t') || (str[i] == ' ') || (str[i] == '\f')
		|| (str[i] == '\r') || (str[i] == '\v') || (str[i] == '\n')
		|| (str[i] == '+') || (str[i] == '-'))
		i++;
	while (str[i])
	{
		if (find_index(base, str[i]) == -1)
			return (w_sign(str) * nbr);
		nbr = nbr * len(base) + find_index(base, str[i]);
		i++;
	}
	return (w_sign(str) * nbr);
}
