/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treis-ro <treis-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:00:21 by treis-ro          #+#    #+#             */
/*   Updated: 2024/01/22 16:58:37 by treis-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_int_putchar(char c);
int	ft_int_putstr(char *str);
int	ft_int_putnbr(int nbr);
int	ft_int_hex(unsigned int nbr, char c);
int	ft_int_putuns(unsigned int k);
int	ft_put_ptr(unsigned long ptr);
int	ft_int_point(unsigned long ptr);
int	check_type(const char c, va_list args);
int	ft_printf(const char *format, ...);

#endif