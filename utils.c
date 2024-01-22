/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treis-ro <treis-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:04:33 by treis-ro          #+#    #+#             */
/*   Updated: 2024/01/22 17:05:59 by treis-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_int_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_int_putstr("(null)");
		return (6);
	}
	while (*str)
	{
		i += ft_int_putchar(*str);
		str++;
	}
	return (i);
}

int	ft_int_putnbr(int nbr)
{
	long	k;
	int		size;

	k = nbr;
	size = 0;
	if (k < 0)
	{
		size += ft_int_putchar('-');
		k *= -1;
	}
	if (k > 9)
		size += ft_int_putnbr(k / 10);
	ft_int_putchar('0' + (k % 10));
	return (size + 1);
}

int	ft_int_hex(unsigned int nbr, char c)
{
	long	k;
	int		size;

	k = nbr;
	size = 0;
	if (k < 0)
	{
		size += ft_int_putchar('-');
		k *= -1;
	}
	if (k > 15)
		size += ft_int_hex(k / 16, c);
	if (c == 'x')
		ft_int_putchar("0123456789abcdef"[(k % 16)]);
	else if (c == 'X')
		ft_int_putchar("0123456789ABCDEF"[(k % 16)]);
	return (size + 1);
}

int	ft_int_putuns(unsigned int k)
{
	int	size;

	size = 0;
	if (k > 9)
		size += ft_int_putuns(k / 10);
	ft_int_putchar('0' + (k % 10));
	return (size + 1);
}
