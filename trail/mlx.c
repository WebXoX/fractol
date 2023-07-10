// #include "../mlx/mlx.h"
// #include <math.h>

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;
// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// void drawtriangle(t_data img, void * mlx_win, float x, float y,float j,int color)
// {
// 	for (int i =0 ; i < 500; i++)
// 	mlx_pixel_put(&img, mlx_win,x, y+i, color); 
// 	for (int i =0 ; i < 500; i++)
// 	mlx_pixel_put(&img, mlx_win,x+i+j, y+i, color);
// 	for (int i =0 ; i <500; i++)
// 	mlx_pixel_put(&img, mlx_win,x+i+j, y+500, color);
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;
// 	t_data	img2;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	img2.img = mlx_new_image(mlx, 1920, 1080);
// 	img2.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	// for (int i =0 ; i <500; i++)
// 	// mlx_pixel_put(&img,mlx_win ,1920/2, 1080/2, 0x00FFFFF); 
// 	// for (int i =0 ; i <500; i++)
// 	// mlx_pixel_put(&img, mlx_win,1920/2+i, 1080/2+i, 0x00FFFFF);
// 	// for (int i =0 ; i <500; i++)
// 	// mlx_pixel_put(&img, mlx_win,1920/2+i, 1080/2+500, 0x00FFFFF);
// 	drawtriangle(img,mlx_win,1920/2,1080/2,0.9,0x00FFFFF);
// 	// drawtriangle(img,mlx_win,1920/2,1080/2,0,0x0);
// 	drawtriangle(img,mlx_win,1920/2+5,1080/2+5,0,0x00FFFFF);

// 	// drawtriangle(img,mlx_win,1080/2,1920/2,0x00FFFFF);
	


// 	// for (int i =0 ; i <500; i++)
// 	// mlx_pixel_put(&img,mlx_win ,1920/2, 1080/2+i, 0x0 );   
// 	// for (int i =0 ; i <500; i++)
// 	// mlx_pixel_put(&img, mlx_win,1920/2+i, 1080/2+i, 0x0 );
// 	// for (int i =0 ; i <500; i++)
// 	// mlx_pixel_put(&img, mlx_win,1920/2+i, 1080/2+500, 0x0 );
	
// 	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 100);
// 	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	// img.img = mlx_new_image(mlx, 1920, 1080);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// 	// mlx_clear_window(&mlx,mlx_win);
// 	// mlx_put_image_to_window(mlx, mlx_win, img2.img, 0, 0);
// 	mlx_destroy_image(mlx, img.img);
// }