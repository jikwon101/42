#include <mlx.h>
/*
int temp()
{
	int bpp; //the number of bits per pixel
	int size_line; //the size of a line * 4
	int endian; //depending pf the architecture of the computer i use
	void *mlx_ptr = mlx_init();
	void *win_ptr = mlx_new_window(mlx_ptr, 1000, 800, "hello");
	void *img_ptr = mlx_new_image(mlx_ptr, 800, 600); //width, height
	
	bpp = 32; //32bits. cuz a pixel is coded on 4 char. those chars worth 8bits each.
	size_line = 800 * 4; //3200byte. width is 800pixel and a pixel is coded on 4 char(=1 byte). 
	endian = 1;//0 or 1
	mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	for (int x = 0 ; x < 300 ; x++)
		for(int y = 0; y < 200; y++)
			((char *)img_ptr)[x * 4 + y * size_line * 4] = "0xFFF000";
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}
*/
int main()
{
	void *mlx_ptr = mlx_init();
	void *win_ptr = mlx_new_window(mlx_ptr, 1000, 800, "HELLO");
	void *img_ptr = mlx_new_image(mlx_ptr, 800, 600);
	int *img_data;
	int bits = 32;
	int size_line = 3200;
	int endian = 0;

	int count_w;
	int count_h;

	count_h = -1;
	img_data = (int *)mlx_get_data_addr(img_ptr, &bits, &size_line, &endian);
	int i = 0;
	while (i < 800 * 600)
	{
		img_data[i] = 0xFFFFFF;
		i++;
	}
	while (++count_h < 600)
	{
		count_w = 0;
		while (count_w++ < 300)
			img_data[count_h * 800 + count_w] = 0xFF00FF;
		while (count_w++ < 600)
			img_data[count_h * 800 + count_w] = 0x0000FF;
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 200, 200);
	mlx_loop(mlx_ptr);
	return (0);

}
