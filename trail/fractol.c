// #include "../mlx/mlx.h"
// #include "FT_PRINTF/ft_printf.h"
// #include <math.h>
// #include <stdio.h>

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// typedef struct	 location
// {
// 	double x;
// 	double y;
// 	int height;
// 	int width;
// }	location;
// typedef struct	 fractol
// {
// 	double x;
// 	double y;
// }	fractol;

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// int render(t_data img,void	*mlx_win, location pos, fractol c){
// 	int iterations;
// 	fractol z;
// 	iterations =0;
// 	z.x=0;
// 	z.y=0;
// 	while(z.x*z.x+z.y*z.y<4 && iterations<500){
// 		double temp = z.x * z.x - z.y * z.y + c.x;
//         z.y = 2 * z.x * z.y + c.y;
//         z.x = temp;
//         iterations++;
// 	}
// 	return iterations;

// }
// int juilia(t_data img,void	*mlx_win, location pos, fractol z){
// 	int iterations;
// 	iterations =0;

// 	while(z.x*z.x+z.y*z.y<4 && iterations<5000){
// 		double temp = z.x * z.x - z.y * z.y  +0.285;
//         z.y = 2 * z.x * z.y + 0.0;
//         z.x = temp;
//         iterations++;
// 	}
// 	return iterations;

// }
// int	create_trgb(int t, int r, int g, int b)
// {
// 	return (t << 24 | r << 16 | g << 8 | b);
// }
// int main(){

// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;
// 	location position;
// double scale = 4	;
// 	position.height= 1300;
// 	position.width= 1600;
	
// 	position.x= 0;
// 	position.y= 0;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, position.width,position.height, "mandalbrot");
// 	img.img = mlx_new_image(mlx,  position.width,position.height);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 		while (position.y<position.height){
// 			position.x =0;
// 			while (position.x<position.width)
// 			{
// 					mlx_pixel_put(&img,mlx_win,position.x,position.y,0x8b3a3a);
// 				position.x++;
// 			}
// 			position.y++;
// 			}
// 			position.y =0;
// 	while (position.y<position.height){
// 		position.x =0;
// 		while (position.x<position.width)
// 		{
// 			fractol c;
// 			int iteration;
// 			    c.x = (position.x - position.width / 2.0) * scale / position.width  ;
//             c.y = (position.y  - position.height  / 2.0) * scale /  position.height;

// 			 iteration= juilia(img, mlx_win,position, c);
// 			//  iteration= render(img, mlx_win,position, c);
// 			// printf("%d,sadf\n", iteration);
// 			if(iteration==500)
// 				mlx_pixel_put(&img,mlx_win,position.x,position.y,0x000);
// 			else
// 				// mlx_pixel_put(&img,mlx_win,position.x,position.y,(int)iteration *(int)position.x/2/position.y/2* 0x000FCCA46/1000);
// 				mlx_pixel_put(&img,mlx_win,position.x,position.y,create_trgb(190* iteration/50,200* iteration/50,200 * iteration/50,iteration));
// 			// int t = create_trgb(0,255,222,222);
// 			// printf("%d\n",t);
// 		position.x++;
// 		}
// 		position.y++;
		
// 	}
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 1000, 1400);

// 	// mlx_hook(mlx_win,2, 1L<<0, close, &vars)
// 	mlx_loop(mlx);
// }