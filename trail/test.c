// #include "../mlx/mlx.h"
// #include <math.h>
// #include <stdio.h>
// # include <stdlib.h>


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

// typedef struct	window {
// 	void	*mlx;
// 	void	*mlx_win;
// }				window;

// int	close(int keycode, window *vars)
// {
// 		printf("Hello from key_hook %d!\n",keycode);
// 	if(keycode == 53 || keycode <0)
// 	{	mlx_clear_window(vars->mlx,vars->mlx_win);
// 		mlx_destroy_window(vars->mlx, vars->mlx_win);
// 		exit(3);
// 	}
// 	return (0);
// }

// int main(){


// 	t_data	img;
// 	location position;
// 	window vars;
// 	double scale = 2;
// 	position.height= 1000;
// 	position.width= 1400;
	
// 	position.x= 0;
// 	position.y= 0;

// 	vars.mlx = mlx_init();
// 	vars.mlx_win = mlx_new_window(vars.mlx, position.width,position.height, "mandalbrot");

	

// 	// mlx_hook(vars.mlx,2, 1L<<0, mlx_destroy_windowm, &vars);
	
// 	mlx_key_hook(vars.mlx_win, close, &vars);
// 	mlx_mouse_hook(vars.mlx_win, close, &vars);
// 	mlx_hook(vars.mlx_win,17,0,close, &vars);
// 	mlx_loop(vars.mlx);
// 	return 0;
// }