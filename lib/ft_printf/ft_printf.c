/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsyn <hsyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:40:57 by huozturk          #+#    #+#             */
/*   Updated: 2024/11/23 16:33:38 by hsyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

static int is_valid_format(char c)
{
    return (c == 'p');
}

static void ft_identifier(const char *format, va_list args, int *temp)
{
	const char	*dec;
	
	dec = "0123456789";
	if (*format == '%')
        *temp += ft_putchar('%');
    else if ((*format == 'd' || *format == 'i'))
        *temp += ft_putnbr(va_arg(args, int), *format, dec);
    else if (*format == 'c')
        *temp += ft_putchar(va_arg(args, int));
    else if (*format == 's')
        *temp += ft_putstr(va_arg(args, char *));
	else if (*format == 'u')
        *temp += ft_putnbr(va_arg(args, unsigned int), *format, dec);
	else if (*format == 'x' || *format == 'X' )
        *temp += ft_putnbr(va_arg(args, unsigned int), *format, "0123456789ABCDEF");
	else if (*format == 'p')
	{
		unsigned long num = va_arg(args, unsigned long);
        if (num)
            *temp +=ft_putstr("0x"), *temp += ft_putnbrutility(num, *format, "0123456789ABCDEF");
        else
            *temp += ft_putstr("(nil)");
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	value;
	int temp;
	va_start(args, format);
	
	value = 0;
	while (*format)
	{
		temp = 0;
		if (*format == '%')
		{
			format++;
            while (*format == ' ' && format++)
                if(is_valid_format(*(format+1)))
					temp += ft_putchar(' ');
            ft_identifier(format, args, &temp);
		}
		else
			temp += ft_putchar(*format);
		format++;
		if (temp == -1)
			return (-1);
		value += temp;
	}
	return (value);
}
