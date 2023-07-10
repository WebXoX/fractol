#include "FT_PRINTF/ft_printf.h"
#include "../mlx/mlx.h"
#include "push_swap.h"
#include <math.h>
#include <stdio.h>
# include <stdlib.h>
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
typedef struct	window {
	void	*mlx;
	void	*mlx_win;
	int 	height;
	int 	width;
	double 	scale;
	t_data  img;
}				window;



typedef struct	 pixel
{
	double x;
	double y;
}	pixel;
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void julia_render(window canva,int max , double c1, double c2);
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
int render(t_data img, pixel c, int max,pixel z)
{
	int iterations;
	iterations =0;

	while(z.x*z.x+z.y*z.y<4 && iterations< max){
		double temp = z.x * z.x - z.y * z.y + c.x;
        z.y = 2 * z.x * z.y + c.y;
        z.x = temp;
        iterations++;
	}
	return iterations;

}
int	closes(int keycode, window *vars)
{
		printf("Hello from key_hook %d!\n",keycode);
	if(keycode == 53 || keycode <0)
	{	mlx_clear_window(vars->mlx,vars->mlx_win);
		// mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(3);
	}
	return (0);
}
int	zoom (int keycode, window vars)
{
		printf("Hello from key_hook %d!\n",keycode);
	if(keycode == 4 || keycode <0)
	{	
	vars.scale-=1;
	mlx_destroy_image(vars.mlx,&vars.img);
		julia_render(vars,250,1.121, 0.2);
		exit(3);
	}
	return (0);
}
void fade( pixel fade,window canva, t_data img)
{
	while (fade.y<canva.height){
		fade.x =0;
		while (fade.x<canva.width)
		{
				mlx_pixel_put(&canva.img,canva.mlx_win,fade.x,fade.y,0x8b3a3a);
			fade.x++;
		}
		fade.y++;
		}
		fade.y =0;
}
void mandelbrot_render(window canva, int max)
{
	pixel startp;
	// t_data	img;
	int iteration;

	// canva.scale = 4;
	startp.x = 0;
	startp.y = 0;
	// canva.img.img = mlx_new_image(canva.mlx,  canva.width,canva.height);
	// canva.img.addr = mlx_get_data_addr(&canva.img.img, &canva.img.bits_per_pixel, &canva.img.line_length,
	// 							&canva.img.endian);
	fade(startp, canva, canva.img);
	startp.y =0;

	while (startp.y < canva.height){
		startp.x =0;
		while (startp.x < canva.width)
		{
			pixel c;
			pixel z;

			z.x =0;
			z.y=0;
			iteration = 0;

		    c.x = (startp.x - canva.width / 2.0) * canva.scale / canva.width  ;
            c.y = (startp.y  - canva.height  / 2.0) * canva.scale /  canva.height; 
			iteration = render(canva.img, c, 500,z);
			if(iteration == max)
				mlx_pixel_put(&canva.img, canva.mlx_win, startp.x, startp.y, 0x000);
			else
				mlx_pixel_put(&canva.img, canva.mlx_win, startp.x, startp.y, create_trgb(190* iteration/50, 200* iteration/50,200 * iteration/50,iteration));
		startp.x++;
		}
		startp.y++;
	}
		// mlx_put_image_to_window(canva.mlx, canva.mlx_win, img.img, 0,0);
	mlx_key_hook(canva.mlx_win, closes, &canva);
	mlx_mouse_hook(canva.mlx_win, close, &canva);
	mlx_hook(canva.mlx_win,17,0,closes, &canva);
	mlx_loop(canva.mlx);
}
void julia_render(window canva,int max , double c1, double c2)
{
	pixel startp;
	// t_data	img;
	
	int iteration;

	// canva.scale = 4;
	startp.x = 0;
	startp.y = 0;
	canva.img.img = mlx_new_image(canva.mlx,  canva.width,canva.height);
	canva.img.addr = mlx_get_data_addr(canva.img.img, &canva.img.bits_per_pixel, &canva.img.line_length,
								&canva.img.endian);
	fade(startp, canva, canva.img);
	startp.y =0;

	while (startp.y < canva.height){
		startp.x =0;
		while (startp.x < canva.width)
		{
			pixel z;
			pixel c;
			iteration = 0;
		    z.x = (startp.x - canva.width / 2.0) * canva.scale / canva.width  ;
            z.y = (startp.y  - canva.height  / 2.0) * canva.scale /  canva.height; 
			
		    c.x = c1;
            c.y = c2; 
			iteration = render(canva.img, c, 250, z);
			if(iteration == max)
				mlx_pixel_put(&canva.mlx, canva.mlx_win, startp.x, startp.y, 0x000);
			else
				mlx_pixel_put(&canva.mlx, canva.mlx_win, startp.x, startp.y, create_trgb(190* iteration/10, 200* iteration/10,200 * iteration/10,iteration));
		startp.x++;
		}
		startp.y++;
	}
		mlx_put_image_to_window(canva.mlx, canva.mlx_win, canva.img.img, 0,0);
	mlx_key_hook(canva.mlx_win, closes, &canva);
	mlx_mouse_hook(canva.mlx_win, close, &canva);
	mlx_mouse_hook(canva.mlx_win, zoom, &canva);
	mlx_hook(canva.mlx_win,17,0,closes, &canva);
	mlx_loop(canva.mlx);
}


void call(int flag, char*argc[]){
	window canva;
	double c1;
	double c2;
	int status;
	
	canva.mlx =  mlx_init();
	canva.height = 800;
	canva.width = 800;
	canva.scale = 1;
	
	if (flag == 1)
	{
		canva.mlx_win = mlx_new_window(canva.mlx, canva.width,canva.height, "mandelbrot");
		mandelbrot_render(canva, 500);
	}
	else if (flag == 2)
	{
		// for (size_t i = 0; i < 10; i++)
		// {
			/* code */
		canva.mlx_win = mlx_new_window(canva.mlx, canva.width,canva.height, "julia");
		c1 = ft_atof(argc[2], &status,1);
		c2 = ft_atof(argc[3], &status,1);
		// canva.img.img = mlx_new_image(canva.mlx,  canva.width,canva.height);
		// canva.img.addr = mlx_get_data_addr(&canva.img.img, &canva.img.bits_per_pixel, &canva.img.line_length,
		// 						&canva.img.endian);
		julia_render(canva,250,c1,c2);
		// mlx_clear_window(canva.mlx,canva.mlx_win);

			canva.scale-=0.5;
		// }
		
	}
}
void errorprint()
{
	ft_printf("--------------Welcome to fractol--------------\n");
	ft_printf("------A Graphics project to plot fractols-----\n");
	ft_printf("---AVAILABLE FRACTOLS: mandelbrot; julia;-----\n");
	ft_printf("--------------------RULES---------------------\n");
	ft_printf("   JULIA: 2 INPUTS REQUIRED IN RANGE {-2 TO 2}\n");
	ft_printf("   MANDELBROT: NO INPUT\n");

}

int main(int argv, char *argc[]){
	
		if (ft_strncmp(argc[1],"mandelbrot",9)==0 && argv == 2)
			call(1,argc);
		else if (ft_strncmp(argc[1],"julia",5)==0 && argv >=2)
			call(2,argc);
		else
			errorprint();
}