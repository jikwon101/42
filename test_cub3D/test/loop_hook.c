/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 15:28:49 by jikwon            #+#    #+#             */
/*   Updated: 2020/06/22 16:48:46 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct s_ptr
{
	void *mlx_ptr;
	void *win_ptr;
}			t_ptr;

int loop_hook(void *temp_prm)
{
	static int i = 0;
	static int j = 0;
	t_ptr *param;

	printf("i : %d, j : %d\n", i, j);
	param = (t_ptr *)temp_prm;
	mlx_string_put(param->mlx_ptr, param->win_ptr, i, j, 0xFF0000, "OK");
	i += 300;
	j += 200;
	return (0);
}
int mouse_press(int button, int x, int y, void *temp_prm)
{
	t_ptr *param;

	param = (t_ptr *)temp_prm;
	mlx_string_put(param->mlx_ptr, param->win_ptr, x, y, 0xFFF000, "STOP");
	return (0);
}
int main()
{
	t_ptr *param;

	//initiate
	param = (t_ptr *)malloc(sizeof(t_ptr) * 1);
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, 1080, 480, "HELLO");

	mlx_hook(param->win_ptr, 4, 1L<<2, mouse_press, (void *)param);
	mlx_loop_hook(param->mlx_ptr, loop_hook, (void *)param);
	mlx_loop(param->mlx_ptr);
	free(param);
	return (0);

}
