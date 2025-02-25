/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozturk <huozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:26:05 by huozturk          #+#    #+#             */
/*   Updated: 2024/11/07 13:49:49 by huozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dst, const char *src, size_t dstsize)
{
	size_t	j;
	size_t	dlen;
	size_t	slen;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	j = 0;
	while (dlen >= dstsize)
		return (dstsize + slen);
	while (*(src + j) != '\0' && j < dstsize - dlen - 1)
	{
		*(dst + dlen + j) = *(src + j);
		j++;
	}
	*(dst + dlen + j) = '\0';
	return (dlen + slen);
}
