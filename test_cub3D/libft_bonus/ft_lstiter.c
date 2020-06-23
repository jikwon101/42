/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 01:41:27 by jikwon            #+#    #+#             */
/*   Updated: 2020/04/05 00:20:43 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	temp = lst;
	if ((!temp) && (!f))
		return ;
	while (temp->next)
	{
		f(temp->content);
		temp = temp->next;
	}
	f(temp->content);
	return ;
}
