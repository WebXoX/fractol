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
	int 	flag;
	double 	scale;
	double c1;
	double c2;
	t_data  img;
}				window;



typedef struct	 pixel
{
	double x;
	double y;
}	pixel;
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void julia_render(window canva,int max , double c1, double c2);
void mandelbrot_render(window canva, int max);
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}


int render(window canva, pixel c, int max,pixel z)
{
	int iterations;
	iterations =0;
		// printf("%f ,%f", c.x, c.y);

	while(z.x*z.x+z.y*z.y<4 && iterations< max){
		double temp = z.x * z.x - z.y * z.y +c.x;
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
	{	
		// mlx_clear_window(vars->mlx,vars->mlx_win);
		// mlx_destroy_image(vars->mlx,&vars->img);
		// mlx_destroy_window(vars->mlx, vars->mlx_win);
		// free(&vars->img);
		// free(vars);
		exit(keycode);
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int	zoom (int keycode,int x, int y, window * vars)
{
		printf("Hello from key_hook %d!\n",keycode);
		printf("Hello from vars %f!\n",vars->c1);
	double zoom;

	zoom = 0.5;
	if(keycode == 4 || keycode == 5)
	{
		mlx_clear_window(vars->mlx,vars->mlx_win);

		if(keycode == 4)
			zoom *= -1;
		if(vars->scale >0.5 || keycode == 5)
			vars->scale+=zoom;
		else
			vars->scale-=vars->scale/10 *5;
			// mlx_destroy_image(vars->mlx,&vars->img);

			// fade(*vars,250,-0.8 , 0.156);
			
		if (vars->flag == 2)
			julia_render(*vars,250,vars->c1,vars->c2);//-0.8 , 0.156);
		else
			mandelbrot_render(*vars, 500);
		// exit(3);
	}
	return (0);
}
void fade( pixel fade,window canva, t_data img)
{
	while (fade.y<canva.height){
		fade.x =0;
		while (fade.x<canva.width)
		{
				my_mlx_pixel_put(&canva.img,fade.x,fade.y,0x8b3a3a);
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
	// canva.img.addr = mlx_get_data_addr(canva.img.img, &canva.img.bits_per_pixel, &canva.img.line_length,
	// 							&canva.img.endian);
	// fade(startp, canva, canva.img);
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
			iteration = render(canva,c, 500,z);
			if(iteration == max)
				my_mlx_pixel_put(&canva.img, startp.x, startp.y, 0x000);
			else
				my_mlx_pixel_put(&canva.img, startp.x, startp.y,(iteration) *0x0040BCD8/max); //create_trgb(190* iteration/50, 200* iteration/50,200 * iteration/50,iteration)) ;//
		startp.x++;
		}
		startp.y++;
	}
		mlx_put_image_to_window(canva.mlx, canva.mlx_win, canva.img.img, 0,0);
	mlx_key_hook(canva.mlx_win, closes, &canva);
	mlx_mouse_hook(canva.mlx_win, zoom, &canva);

	mlx_hook(canva.mlx_win,17,0,closes, &canva);
	mlx_loop(canva.mlx);
}
void julia_render(window canva,int max , double c1, double c2)
{
	pixel startp;
	// t_data	img;
	
	int iteration;
		// printf("%f ,%f", canva.c1, canva.c2);

	// canva.scale = 4;
	// fade(startp, canva, canva.img);
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

			iteration = render(canva, c,250, z);
			if(iteration == max)
				my_mlx_pixel_put(&canva.img, startp.x, startp.y, 0x000);
			else
				my_mlx_pixel_put(&canva.img, startp.x, startp.y, (int)create_trgb(0, 50* iteration/50,85 * iteration/10,iteration)); //(iteration/max) *0x00bbf9
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
void errorprint()
{
	ft_printf("--------------Welcome to fractol--------------\n");
	ft_printf("------A Graphics project to plot fractols-----\n");
	ft_printf("---AVAILABLE FRACTOLS: mandelbrot; julia;-----\n");
	ft_printf("--------------------RULES---------------------\n");
	ft_printf("   JULIA: 2 INPUTS REQUIRED IN RANGE {-2 TO 2}\n");
	ft_printf("   MANDELBROT: NO INPUT\n");

}

void call(int flag, char*argc[])
{
	window canva;
	double c1;
	double c2;
	int status;
	
	canva.mlx =  mlx_init();
	canva.height = 800;
	canva.width = 800;
	canva.scale = 4;
	canva.flag = flag;
	canva.img.img = mlx_new_image(canva.mlx,  canva.width,canva.height);
	canva.img.addr = mlx_get_data_addr(canva.img.img, &canva.img.bits_per_pixel, &canva.img.line_length,
								&canva.img.endian);
	if (flag == 1)
	{
		canva.mlx_win = mlx_new_window(canva.mlx, canva.width,canva.height, "mandelbrot");
		mandelbrot_render(canva, 500);
	}
	else if (flag == 2)
	{
		canva.c1 = ft_atof(argc[2], &status,1);
		canva.c2 = ft_atof(argc[3], &status,1);
		printf("%f sd,%f", canva.c1, canva.c2);
		if(canva.c1 > 2 && canva.c2 < -2  && canva.c1> 2 && canva.c2 < -2)
		{
			errorprint();
			return ;
		}
		canva.mlx_win = mlx_new_window(canva.mlx, canva.width,canva.height, "julia");
		julia_render(canva,250,canva.c1,canva.c2);
	}
}



int main(int argv, char *argc[]){
	
		if (ft_strncmp(argc[1],"mandelbrot",9)==0 && argv == 2)
			call(1,argc);
		else if (ft_strncmp(argc[1],"julia",5)==0 && argv >=2)
			call(2,argc);
		else
			errorprint();
			
}