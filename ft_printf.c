/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treis-ro <treis-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:55:54 by treis-ro          #+#    #+#             */
/*   Updated: 2024/01/22 15:11:12 by treis-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_int_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_int_putstr(char *str)
{
    int i;

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

int ft_int_putnbr(int nbr)
{
    long    k;
    int     size;
    
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

int ft_int_hex(int nbr, char c)
{
    long    k;
    int     size;
    
    k = nbr;
    size = 0;
    if (k < 0)
    {
        size += ft_int_putchar('-');
        k *= -1;
    }
    if (k > 15)
        size += ft_int_hex(k / 16, c);
    else if (c == 'x')
        size += ft_int_putchar("0123456789abcdef"[(k % 16)]);
    else if (c == 'X')
        size += ft_int_putchar("0123456789ABCDEF"[(k % 16)]);
    // printf("size: %d;\nnbr: %d\n", size, nbr);
    return (size);
}

int ft_int_putuns(unsigned int k)
{
    int size;

    size = 0;
    if (k > 9)
        size += ft_int_putuns(k / 10);
    ft_int_putchar('0' + (k % 10));
    return (size + 1);            
}

int ft_put_ptr(unsigned long ptr)
{
    int size;

    size = 0;
    if (ptr > 15)
        size += ft_put_ptr(ptr / 16);
    if ((ptr % 16) > 9)
        ft_int_putchar('a' - 10 + (ptr % 16));
    else
        ft_int_putchar('0' + (ptr % 16));
    return (size + 1);
}

int ft_int_point(unsigned long ptr)
{
    int size;

    size = 0;
    if (ptr == 0)
        return (ft_int_putstr("(nil)"));
    size += ft_int_putstr("0x");
    size += ft_put_ptr(ptr);
    return (size);
}

int check_type(const char c, va_list args)
{
    int length;

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
        length += ft_int_hex(va_arg(args, int), c);
    else if (c == '%')
        length += ft_int_putchar('%');
    return length;
}

int ft_printf(const char *format, ...)
{
    int     i;
    int     res;
    va_list args;

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
