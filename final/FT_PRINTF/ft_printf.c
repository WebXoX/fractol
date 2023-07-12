/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:14:22 by jperinch          #+#    #+#             */
/*   Updated: 2022/08/09 12:11:42 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	formchecker(char form)
{
	char	*set;
	int		i;

	set = "%cspdiuxX";
	i = 0;
	while (set[i] != '\0')
	{
		if (form == set[i])
			return (0);
		i++;
	}
	return (1);
}

int	printer(const char *form, va_list *args, int a)
{
	if (form[0] == '%' && formchecker(form[0 + 1]) == 1)
		return (-1);
	else if (form[0] == '%' && form[1] == '%')
		a = ft_putchar('%');
	else if (form[0] == '%' && form[1] == 'c')
		a = ft_putchar(va_arg(*args, int));
	else if (form[0] == '%' && form[1] == 's')
		a = ft_putstr(va_arg(*args, char *));
	else if (form[0] == '%' && form[1] == 'p')
		a = ft_putnbr_p((unsigned long long)va_arg(*args, unsigned long long));
	else if (form[0] == '%' && form[1] == 'd')
		a = size(va_arg(*args, int), 2, 0);
	else if (form[0] == '%' && form[1] == 'i')
		a = size(va_arg(*args, int), 2, 0);
	else if (form[0] == '%' && form[1] == 'u')
		a = size((unsigned int)va_arg(*args, int), 3, 0);
	else if (form[0] == '%' && form[1] == 'x')
		a = size((int)va_arg(*args, int), 1, 0);
	else if (form[0] == '%' && form[1] == 'X')
		a = size((int)va_arg(*args, int), 0, 0);
	else
		a = ft_putchar(form[0]);
	return (a);
}

int	ft_printf(const char *form, ...)
{
	va_list	args;
	int		len;
	int		test;

	len = 0;
	va_start(args, form);
	while (form[0] != '\0')
	{
		test = printer(form, &args, 0);
		if (form[0] == '%' && formchecker(form[1]) == 0)
			form++;
		if (test != -1)
			len += test;
		form++;
	}
	va_end(args);
	return (len);
}
