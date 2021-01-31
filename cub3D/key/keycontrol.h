/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycontrol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 20:30:53 by jikwon            #+#    #+#             */
/*   Updated: 2020/07/31 15:15:43 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCONTROL_H
# define KEYCONTROL_H

# include "../cub3d.h"

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_A 0
# define KEY_W 13
# define KEY_D 2
# define KEY_S 1
# define ESC 53

void	move_w(t_ptr *set, double speed);
void	move_s(t_ptr *set, double speed);
void	move_d(t_ptr *set, double speed);
void	move_a(t_ptr *set, double speed);

#endif
