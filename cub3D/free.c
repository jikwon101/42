/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 11:35:15 by jikwon            #+#    #+#             */
/*   Updated: 2020/08/04 15:59:22 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all(t_ptr *set)
{
	if (set->v != NULL)
		free(set->v);
	if (set->f != NULL)
		free_t_file(set->f);
	if (set->s != NULL)
		free(set->s);
	return ;
}
