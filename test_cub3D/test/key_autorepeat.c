/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:01:40 by jikwon            #+#    #+#             */
/*   Updated: 2020/06/23 15:38:18 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_release(int keycode, void *param)
{
	t_ptr *new;
	static int x = 0;
	static int y = 0;
	new = (t_ptr *)param;
	mlx_string_put(new->mlx_ptr, new->win_ptr, x, y, 0xff0000, "hi");
	printf("%d\n", keycode);
	if (keycode == 65307)
		exit(0);
	x += 20;
	y += 10;
	return (0);
}

int main()
{
	t_ptr new;
	
	new.mlx_ptr = mlx_init();
	new.win_ptr = mlx_new_window(new.mlx_ptr, 800, 600, "helloo");

	mlx_do_key_autorepeatoff(new.mlx_ptr);
	mlx_hook(new.win_ptr, 3, 1L<<1, key_release, &new);
	mlx_loop(new.mlx_ptr);
	return (0);
}
