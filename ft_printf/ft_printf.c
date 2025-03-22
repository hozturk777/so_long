/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozturk <huozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:40:57 by huozturk          #+#    #+#             */
/*   Updated: 2024/12/12 16:31:40 by huozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static int	ft_pointeridentifier(const char	*format, unsigned long num)
{
	int	temp;

	temp = 0;
	if (num == 0)
	{
		if (ft_putstr("(nil)") == -1)
			return (-1);
		temp += 5;
	}	
	else
	{
		if (ft_putstr("0x") == -1)
			return (-1);
		temp += ft_putnbr(0, num, *format, 16) + 2;
	}
	return (temp);
}

static void	ft_identifier(const char *format, va_list args, int *temp)
{
	if (*format == '%')
		*temp += ft_putchar('%');
	else if ((*format == 'd' || *format == 'i'))
		*temp += ft_putnbr(va_arg(args, int), 0, *format, 10);
	else if (*format == 'c')
		*temp += ft_putchar(va_arg(args, int));
	else if (*format == 's')
		*temp += ft_putstr(va_arg(args, char *));
	else if (*format == 'u')
		*temp += ft_putnbr(va_arg(args, unsigned int), 0,*format, 10);
	else if (*format == 'x' || *format == 'X' )
		*temp += ft_putnbr(va_arg(args, unsigned int), 0, *format, 16);
	else if (*format == 'p')
		*temp += ft_pointeridentifier(format, va_arg(args, unsigned long));
	else
		*temp = -1;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		value;
	int		temp;

	if (!format)
		return (-1);
	va_start(args, format);
	value = 0;
	while (*format)
	{
		temp = 0;
		if (*format == '%')
			ft_identifier(++format, args, &temp);
		else
			temp += ft_putchar(*format);
		if (format++ && temp == -1)
			return (va_end(args), -1);
		value += temp;
	}
	return (va_end(args), value);
}
