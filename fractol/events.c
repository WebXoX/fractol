/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 09:40:06 by jperinch          #+#    #+#             */
/*   Updated: 2023/07/13 10:11:53 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fractol.h"

int	zoom(int keycode, int x, int y, t_window *vars)
{
	double	zoom;
	t_pixel	z;

	x = 0;
	y = 0;
	z.x = 0;
	z.y = 0;
	zoom = 0.2;
	if (keycode == 4 || keycode == 5)
	{
		if (keycode == 4)
			zoom *= -1;
		if (vars->scale > 0.5 || keycode == 5)
			vars->scale += zoom;
		else
			vars->scale -= vars->scale / 10 * 5;
		if (vars->flag == 2)
			julia_render((*vars), 250);
		else
			mandelbrot_render((*vars), 500, 0, z);
	}
	return (0);
}

int	closes(int keycode, t_window *vars)
{
	if (keycode == 53)
	{
		mlx_clear_window((vars)->mlx, (vars)->mlx_win);
		mlx_destroy_image(vars->mlx, vars->img->img);
		mlx_destroy_window((vars)->mlx, (vars)->mlx_win);
		exit(1);
		return (1);
	}
	if (keycode < 0)
		exit(1);
	return (0);
}

void	run(t_window *canva)
{
	mlx_put_image_to_window(canva->mlx, canva->mlx_win, (canva)->img->img, 0,
		0);
	mlx_hook(canva->mlx_win, 17, 0, (void *)closes, &(*canva));
	mlx_key_hook(canva->mlx_win, closes, &(*canva));
	mlx_mouse_hook(canva->mlx_win, zoom, &(*canva));
	mlx_loop(canva->mlx);
}
