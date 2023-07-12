/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:12:05 by jperinch          #+#    #+#             */
/*   Updated: 2023/07/12 16:03:39 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fractol.h"

void	errorprint(void)
{
	ft_printf("--------------Welcome to fractol--------------\n");
	ft_printf("------A Graphics project to plot fractols-----\n");
	ft_printf("---AVAILABLE FRACTOLS: mandelbrot; julia;-----\n");
	ft_printf("--------------------RULES---------------------\n");
	ft_printf("   JULIA: 2 INPUTS REQUIRED IN RANGE {-2 TO 2}\n");
	ft_printf("   MANDELBROT: NO INPUT\n");
	exit(0);
}

void	call(int flag, char *argc[], t_window *canva, t_pixel z)
{
	t_data	img;

	canva->flag = flag;
	img.img = mlx_new_image(canva->mlx, canva->width, canva->height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	canva->img = &img;
	if (flag == 1)
	{
		canva->mlx_win = mlx_new_window(canva->mlx, canva->width, canva->height,
				"mandelbrot");
		mandelbrot_render((*canva), 500, 0, z);
	}
	else if (flag == 2)
	{
		canva->c1 = ft_atof(argc[2], 0, 1);
		canva->c2 = ft_atof(argc[3], 0, 1);
		if ((canva->c1 > 2 || canva->c1 < -2) || (canva->c2 > 2 || canva->c2
				< -2))
			errorprint();
		canva->mlx_win = mlx_new_window(canva->mlx, canva->width, canva->height,
				"julia");
		julia_render((*canva), 250);
	}
}

int	main(int argv, char *argc[])
{
	t_window	canva;
	t_pixel		z;

	z.x = 0;
	z.y = 0;
	canva.height = 800;
	canva.width = 800;
	canva.scale = 4;
	canva.mlx = mlx_init();
	if (ft_strncmp(argc[1], "mandelbrot", 9) == 0 && argv == 2)
		call(1, argc, &canva, z);
	else if (ft_strncmp(argc[1], "julia", 5) == 0 && argv >= 2)
		call(2, argc, &canva, z);
	else
		errorprint();
	return (0);
}
