/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:22:47 by jikwon            #+#    #+#             */
/*   Updated: 2020/01/26 14:39:37 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char wtchar;

	wtchar = 'a';
	while (wtchar <= 'z')
	{
		write(1, &wtchar, 1);
		wtchar++;
	}
}
