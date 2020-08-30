/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 01:49:23 by jikwon            #+#    #+#             */
/*   Updated: 2020/08/10 13:24:50 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_file.h"

void	ft_free_array(char **set)
{
	int	i;

	i = 0;
	if (set == NULL)
		return ;
	while (set[i])
	{
		if (set[i] != NULL)
			free(set[i]);
		i++;
	}
	free(set);
	return ;
}

void	free_t_file(t_file *f_set)
{
	if (f_set != NULL)
	{
		if (f_set->path[N] != NULL)
			free(f_set->path[N]);
		if (f_set->path[S] != NULL)
			free(f_set->path[S]);
		if (f_set->path[E] != NULL)
			free(f_set->path[E]);
		if (f_set->path[W] != NULL)
			free(f_set->path[W]);
		if (f_set->path[I] != NULL)
			free(f_set->path[I]);
		if (f_set->worldmap != NULL)
			ft_free_array(f_set->worldmap);
		free(f_set);
	}
}
