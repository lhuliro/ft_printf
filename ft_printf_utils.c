/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuliro- <lhuliro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:28:48 by lhuliro-          #+#    #+#             */
/*   Updated: 2023/04/13 21:45:31 by lhuliro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		length;
	long	number;

	length = 0;
	number = n;
	if (n < 0)
	{
		length += ft_putchar('-');
		number *= -1;
	}
	if (number >= 10)
		length += ft_putnbr(number / 10);
	length += ft_putchar(number % 10 + '0');
	return (length);
}

int	ft_put_unsigned_nbr(unsigned int n)
{
	int	length;

	length = 0;
	if (n >= 10)
		length += ft_put_unsigned_nbr(n / 10);
	length += ft_putchar(n % 10 + '0');
	return (length);
}

int	ft_putstr(char *str)
{
	int	length;

	length = 0;
	if (!str)
		str = "(null)";
	while (str[length] != '\0')
		length += ft_putchar(str[length]);
	return (length);
}

int	ft_print_hexa(unsigned long nbr, char c)
{
	int		length;
	int		char_adjustor;

	length = 0;
	if (c == 'x')
		char_adjustor = 87;
	if (c == 'X')
		char_adjustor = 55;
	if (nbr < 16)
	{
		if (nbr < 10)
			length += ft_putchar(nbr + '0');
		else
			length += ft_putchar(nbr + char_adjustor);
		return (length);
	}
	length += ft_print_hexa(nbr / 16, c);
	length += ft_print_hexa(nbr % 16, c);
	return (length);
}

int	ft_print_pointer(unsigned long ptr)
{
	int	length;

	length = 0;
	length += ft_putstr("0x");
	length += ft_print_hexa(ptr, 'x');
	return (length);
}
