#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
int	ft_putstr(char *str)
{
	int len;

	len = 0;
	if (!str)
    {
        ft_putstr("(null)");
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

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}
int	ft_putnbrutility(unsigned long num, const char checkidentifier, const char *type)
{
	long	len;

	len = 0;
	if (num > (unsigned long)(ft_strlen(type)-1) && checkidentifier == 'p')
	{
		len += ft_putnbrutility(num/ft_strlen(type), checkidentifier, type);
		len += ft_putnbrutility(num%ft_strlen(type), checkidentifier, type);
	}
	else if (num < 10 && checkidentifier == 'p')
	{
		if (ft_putchar(num + '0') == -1)
			return (-1);
		len++;
	}
	else
	{
		if (ft_putchar((num - 10 + ((checkidentifier == 'x' || checkidentifier == 'p') ? 'a' : 'A'))) == -1)
			return (-1);
		len++;
	}
	return ((int)len);
}				//	NULL İŞLEMİ YAPILACAK

int	ft_putnbr(long num, const char checkidentifier, const char *type)
{
	long		len;

	len = 0;
	if (num < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		len += ft_putnbr(-num, checkidentifier, type) + 1;
	}
	else if (num > (ft_strlen(type)-1))
	{
		len += ft_putnbr(num/ft_strlen(type), checkidentifier, type);
		len += ft_putnbr(num%ft_strlen(type), checkidentifier, type);
	}
	else if (num < 10)
	{
		if (ft_putchar(num + '0') == -1)
			return (-1);
		len++;
	}
	else
		if (++len && ft_putchar((num - 10 + ((checkidentifier == 'x' || checkidentifier == 'p') ? 'a' : 'A'))) == -1)
			return (-1);
	return ((int)len);
}
