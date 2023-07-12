/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:50:45 by jperinch          #+#    #+#             */
/*   Updated: 2022/08/09 11:47:41 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb)
{
	char	chart;

	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		write(1, &"8", 1);
	}
	else if (nb < 0)
	{
		write(1, &"-", 1);
		ft_putnbr(nb / (-1));
	}
	else
	{
		if (nb >= 10)
			ft_putnbr(nb / 10);
		chart = nb % 10 + '0';
		write(1, &chart, 1);
	}
}

void	ft_putnbr_u(unsigned int nb)
{
	char	chart;

	if (nb >= 10)
		ft_putnbr_u(nb / 10);
	chart = nb % 10 + '0';
	write(1, &chart, 1);
}

int	ft_putnbr_p(unsigned long long nb)
{
	int					count;
	unsigned long long	numb;
	char				*c;

	c = "0123456789abcdef";
	write(1, "0x", 2);
	count = 2;
	ft_putnbr_base((unsigned long long)nb, 1);
	if (nb == 0)
		count++;
	while (nb)
	{
		nb /= 16;
		count++;
	}
	return (count);
}

void	ft_putnbr_base(unsigned long long nb, int flag)
{
	unsigned long long	numb;
	char				*c;
	char				*ca;

	c = "0123456789abcdef";
	ca = "0123456789ABCDEF";
	if (nb / 16 > 0)
		ft_putnbr_base(nb / 16, flag);
	numb = nb % 16;
	if (flag == 1)
		write(1, &c[numb], 1);
	if (flag == 0)
		write(1, &ca[numb], 1);
}

int	size(long long nb, int flag, int count)
{
	if (flag == 0 || flag == 1)
	{
		nb = (unsigned int)nb;
		ft_putnbr_base(nb, flag);
	}
	if (flag == 2)
	{
		ft_putnbr(nb);
	}
	if (flag == 3)
		ft_putnbr_u((unsigned int)nb);
	if (nb == 0 || nb < 0)
		count++;
	while (nb)
	{
		if (flag >= 2)
			nb /= 10;
		else
			nb /= 16;
		count++;
	}
	return (count);
}
