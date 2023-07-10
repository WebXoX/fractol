/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:39:46 by jperinch          #+#    #+#             */
/*   Updated: 2022/08/05 11:39:02 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *form, ...);
int		ft_putchar(char c);
void	ft_putnbr(int nb);
int		ft_putstr(char *s);
void	ft_putnbr_u(unsigned int nb);
int		ft_putnbr_base_cap(int nb, int x);
int		ft_putnbr_p(unsigned long long nb);
void	ft_putnbr_base(unsigned long long nb, int flag);
int		size(long long nb, int flag, int count);

#endif
