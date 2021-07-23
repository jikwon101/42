/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 21:24:16 by jikwon            #+#    #+#             */
/*   Updated: 2021/07/24 01:58:08 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_putchr_fd(char c, int fd)
{
	write(fd, &c, 1);
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n >= 0)
		num = (unsigned int)n;
	else
	{
		write(fd, "-", 1);
		num = (unsigned int)(-n);
	}
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	ft_putchr_fd((char)(num % 10 + '0'), fd);
	return ;
}
