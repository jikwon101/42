/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:43:20 by jikwon            #+#    #+#             */
/*   Updated: 2020/01/30 10:59:36 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_printable(int new)
{
	if ((new < 32) || (new >= 127))
		return (1);
	else
		return (0);
}

void	to_hex(int test)
{
	int		m;
	int		n;
	char	hex[16];

	hex[0] = '0';
	hex[1] = '1';
	hex[2] = '2';
	hex[3] = '3';
	hex[4] = '4';
	hex[5] = '5';
	hex[6] = '6';
	hex[7] = '7';
	hex[8] = '8';
	hex[9] = '9';
	hex[10] = 'a';
	hex[11] = 'b';
	hex[12] = 'c';
	hex[13] = 'd';
	hex[14] = 'e';
	hex[15] = 'f';
	m = test / 16;
	n = test % 16;
	write(1, "\\", 1);
	write(1, &hex[m], 1);
	write(1, &hex[n], 1);
}

int		size_str(char *str)
{
	int length;

	length = 0;
	while (str[length] != 0)
		length++;
	return (length);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	int				length;
	unsigned char	nstr;

	i = 0;
	length = size_str(str);
	while (i < length)
	{
		nstr = (unsigned char)str[i];
		if (is_printable(nstr) == 0)
			write(1, &nstr, 1);
		else
			to_hex(nstr);
		i++;
	}
}
