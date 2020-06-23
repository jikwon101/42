#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct s_con_ptr
{
	void *mlx;
	void *window;
}	con_ptr;

int key_press(int key, void *param)
{
	con_ptr *new;
	
	new = (con_ptr *)param;
	printf("hi\n");
	mlx_string_put(new->mlx, new->window, 200, 300, 0xFFF000, "hello");
	return (0);
}

int mouse_release(int button, int x, int y, void *param)
{
	con_ptr *new;
	new = (con_ptr *)param;
	//printf("%d\n", button);
	printf("x : %d, y : %d\n", x, y);
	mlx_string_put(new->mlx, new->window, x, y, 0xFF0000, "LuvJJ");
	return (0);
}

int mouse_move(int x, int y, void *param)
{
	con_ptr *new;
	new = (con_ptr *)param;
	printf("x :%d, y : %d\n", x, y);
	mlx_pixel_put(new->mlx, new->window, x, y, 0xFF0000);
	return (0);

}

int x_close(void *param)
{
	(void)param;
	exit(0);
}

int x_expose(void *param)
{
	con_ptr *new;
	
	new = (con_ptr *)param;
	for(int i = 0 ; i < 100; i++)
		for (int j = 0; j < 100; j++)
			mlx_pixel_put(new->mlx, new->window, i, j, 0xFFF000);
	printf("1\n");
	mlx_string_put(new->mlx, new->window, 100, 100, 0xFF0000, "Sure ofc");
	return (0);
}
int main()
{
    void *mlx;
    void *window;
    void *image;
    int width;
    int height;

    con_ptr *param;
    
    param = malloc(sizeof(con_ptr *));
    mlx = mlx_init();
    window = mlx_new_window(mlx, 2000, 1000, "titel");
    
    param->mlx = mlx;
    param->window=window;
    
    image = mlx_xpm_file_to_image(mlx, "./images1.xpm",&width, &height);
    mlx_put_image_to_window(mlx, window, image, 50, 50);
    //mlx_hook(window, 12,1L<<15, x_expose,  (void *)param);
    //mlx_hook(window, 2, 1L<<0, key_press, (void *)param);
    //mlx_hook(window, 4, 1L<<2, mouse_release, (void *)param);
    mlx_hook(window, 6, 1L<<6, mouse_move, (void *)param);
    mlx_loop(mlx);
    return (0);
}
