/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozturk <huozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:38:22 by huozturk          #+#    #+#             */
/*   Updated: 2025/02/27 16:53:34 by huozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include "../libft/libft.h"

int ft_printf(const char *, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int ft_putnbr(long  num, const char checkidentifier, const char *type);
int	ft_putnbrutility(unsigned long num, const char checkidentifier, const char *type);

#endif