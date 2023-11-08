/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 09:44:55 by jperinch          #+#    #+#             */
/*   Updated: 2023/07/13 10:12:12 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fractol.h"

int	render(t_window *canva, int max, t_pixel z)
{
	int		iterations;
	double	temp;

	iterations = 0;
	while (z.x * z.x + z.y * z.y < 4 && iterations < max)
	{
		temp = z.x * z.x - z.y * z.y + canva->c1;
		z.y = 2 * z.x * z.y + canva->c2;
		z.x = temp;
		iterations++;
	}
	return (iterations);
}

void	mandelbrot_render(t_window canva, int max, int iteration, t_pixel z)
{
	t_pixel	startp;

	startp.y = 0;
	while (startp.y < canva.height)
	{
		startp.x = 0;
		while (startp.x < canva.width)
		{
			z.x = 0;
			z.y = 0;
			iteration = 0;
			canva.c1 = (startp.x - canva.width / 2) * canva.scale / canva.width;
			canva.c2 = (startp.y - canva.height / 2) * canva.scale
				/ canva.height;
			iteration = render(&canva, 500, z);
			if (iteration == max)
				my_mlx_pixel_put(canva.img, startp.x, startp.y, 0x000);
			else
				my_mlx_pixel_put(canva.img, startp.x, startp.y,
					(iteration) * 0x0040BCD8 / max);
			startp.x++;
		}
		startp.y++;
	}
	run(&canva);
}

void	julia_render(t_window canva, int max)
{
	t_pixel	startp;
	t_pixel	z;
	int		iteration;

	startp.y = 0;
	while (startp.y < canva.height)
	{
		startp.x = 0;
		while (startp.x < canva.width)
		{
			iteration = 0;
			z.x = (startp.x - canva.width / 2.0) * canva.scale / canva.height;
			z.y = (startp.y - canva.height / 2.0) * canva.scale / canva.width;
			iteration = render(&canva, 250, z);
			if (iteration == max)
				my_mlx_pixel_put(canva.img, startp.x, startp.y, 0x000);
			else
				my_mlx_pixel_put(canva.img, startp.x, startp.y,
					(int)create_trgb(0, 50 * iteration / 50, 85 * iteration
						/ 10, iteration));
			startp.x++;
		}
		startp.y++;
	}
	run(&canva);
}
