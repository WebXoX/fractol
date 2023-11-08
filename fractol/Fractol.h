/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 09:27:52 by jperinch          #+#    #+#             */
/*   Updated: 2023/07/13 10:15:01 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./mlx/mlx.h"
# include "FT_PRINTF/ft_printf.h"
# include <math.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_t_window
{
	void	*mlx;
	void	*mlx_win;
	int		height;
	int		width;
	int		flag;
	double	scale;
	double	c1;
	double	c2;
	t_data	*img;
}			t_window;

typedef struct s_pixel
{
	double	x;
	double	y;
}			t_pixel;

int			create_trgb(int t, int r, int g, int b);
int			render(t_window *canva, int max, t_pixel z);
int			closes(int keycode, t_window *vars);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			zoom(int keycode, int x, int y, t_window *vars);
void		run(t_window *canva);
void		mandelbrot_render(t_window canva, int max, int iteration,
				t_pixel z);
void		julia_render(t_window canva, int max);
void		errorprint(void);
void		call(int flag, char *argc[], t_window *canva, t_pixel z);
float		ft_atof(const char *nptr, int *status, int sign);
int			ft_atoi(const char *nptr, int *status, int *sign);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);
char		*ft_substr(const char *s, unsigned int start, size_t len);
int			lchecker(char const *s, char c, int i);
char		**ft_split(char const *s, char c);
void		freed(char **a);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			wordcheck(char const *s, char c);

#endif
