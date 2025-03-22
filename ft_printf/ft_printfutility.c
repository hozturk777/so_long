/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozturk <huozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:28:22 by huozturk          #+#    #+#             */
/*   Updated: 2024/12/14 16:52:07 by huozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
	{
		if (ft_putstr("(null)") == -1)
			return (-1);
		return (6);
	}
	while (*str)
	{
		if (ft_putchar(*str) == -1)
			return (-1);
		else
			len++;
		str++;
	}
	return (len);
}

static int	ft_putalnum(char check, unsigned long hexnum, long decnum)
{
	if (check == 'p')
	{
		if (ft_putchar(hexnum + '0') == -1)
			return (-1);
	}
	else
	{
		if (ft_putchar(decnum + '0') == -1)
			return (-1);
	}
	return (0);
}

static int	ft_puthexdigit(char check, unsigned long hexnum, long decnum)
{
	if (check == 'x' || check == 'X'
		|| check == 'p')
	{
		if (check == 'X')
		{
			if (ft_putchar(decnum % 10 + 'A') == -1)
				return (-1);
		}
		else if (check == 'p')
		{
			if (ft_putchar(hexnum % 10 + 'a') == -1)
				return (-1);
		}
		else if (ft_putchar(decnum % 10 + 'a') == -1)
			return (-1);
	}
	else if (ft_putchar(decnum % 10 + 'a') == -1)
		return (-1);
	return (0);
}

int	ft_putnbr(long decnum, unsigned long hexnum, const char check, int type)
{
	int		len;

	len = 0;
	if (decnum < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		len += ft_putnbr(-decnum, -hexnum, check, type) + 1;
	}
	else if (decnum > (type - 1) || hexnum > (unsigned)(type - 1))
	{
		len += ft_putnbr(decnum / type, hexnum / type, check, type);
		len += ft_putnbr(decnum % type, hexnum % type, check, type);
	}
	else if ((decnum < 10 && hexnum == 0) || (hexnum < 10 && decnum == 0))
	{
		if (ft_putalnum(check, hexnum, decnum) == -1)
			return (-1);
		len++;
	}
	else if (++len && ft_puthexdigit(check, hexnum, decnum) == -1)
		return (-1);
	return (len);
}
