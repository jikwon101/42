/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 09:27:04 by jikwon            #+#    #+#             */
/*   Updated: 2020/01/29 14:56:15 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if ((31 < str[i]) && (str[i] < 127))
			i++;
		else
			return (0);
	}
	return (1);
}
