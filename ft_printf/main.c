/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsyn <hsyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:38:40 by huozturk          #+#    #+#             */
/*   Updated: 2024/11/23 16:38:51 by hsyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int main()
{
    int c = 0;
    printf("len1: %d\n",ft_printf(" NULL %s NULL ", NULL));
    printf("len2: %d\n",printf(" NULL %s NULL ", NULL));
}