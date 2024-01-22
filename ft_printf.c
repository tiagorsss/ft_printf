/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treis-ro <treis-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:55:54 by treis-ro          #+#    #+#             */
/*   Updated: 2024/01/22 17:05:54 by treis-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_ptr(unsigned long ptr)
{
	int	size;

	size = 0;
	if (ptr > 15)
		size += ft_put_ptr(ptr / 16);
	if ((ptr % 16) > 9)
		ft_int_putchar('a' - 10 + (ptr % 16));
	else
		ft_int_putchar('0' + (ptr % 16));
	return (size + 1);
}

int	ft_int_point(unsigned long ptr)
{
	int	size;

	size = 0;
	if (ptr == 0)
		return (ft_int_putstr("(nil)"));
	size += ft_int_putstr("0x");
	size += ft_put_ptr(ptr);
	return (size);
}

int	check_type(const char c, va_list args)
{
	int	length;

	length = 0;
	if (c == 'c')
		length += ft_int_putchar(va_arg(args, int));
	else if (c == 's')
		length += ft_int_putstr(va_arg(args, char *));
	else if (c == 'p')
		length += ft_int_point(va_arg(args, unsigned long));
	else if (c == 'd' || c == 'i')
		length += ft_int_putnbr(va_arg(args, int));
	else if (c == 'u')
		length += ft_int_putuns(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		length += ft_int_hex((unsigned int)va_arg(args, unsigned int), c);
	else if (c == '%')
		length += ft_int_putchar('%');
	return (length);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		res;
	va_list	args;

	i = 0;
	res = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			res += check_type(format[i + 1], args);
			i++;
		}
		else
			res += ft_int_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (res);
}
