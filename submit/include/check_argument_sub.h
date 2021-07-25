/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument_sub.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 02:25:42 by jikwon            #+#    #+#             */
/*   Updated: 2021/07/25 02:25:44 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_ARGUMENT_SUB_H
# define CHECK_ARGUMENT_SUB_H

# include "../include/libft.h"

int	is_int(char *str);
int	is_under_min(char *str, int len);
int	is_over_max(char *str, int len);
int	isn_int_range(char *str);
int	is_duplicate(int *data, int size, int n);

#endif
