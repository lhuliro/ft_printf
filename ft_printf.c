/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuliro- <lhuliro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:58:01 by lhuliro-          #+#    #+#             */
/*   Updated: 2023/04/13 21:27:53 by lhuliro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_print_args(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_put_unsigned_nbr(va_arg(args, unsigned int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 'x' || c == 'X')
		return (ft_print_hexa(va_arg(args, unsigned int), c));
	if (c == 'p')
		return (ft_print_pointer(va_arg(args, unsigned long)));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		length;

	length = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
			length += ft_print_args(args, *(++s));
		else
			length += ft_putchar(*s);
		s++;
	}
	va_end(args);
	return (length);
}
