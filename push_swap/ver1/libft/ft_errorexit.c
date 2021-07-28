/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errorexit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 23:11:25 by jikwon            #+#    #+#             */
/*   Updated: 2021/07/26 20:11:16 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	errorexit(char *str)
{
	if (!str)
		write(2, "Error\n", 6);
	else
		write(2, str, ft_strlen(str));
	exit(1);
}
