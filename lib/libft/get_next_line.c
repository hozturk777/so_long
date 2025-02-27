/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozturk <huozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:30:01 by huozturk           #+#    #+#             */
/*   Updated: 2025/02/27 16:35:08 by huozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static char	*ft_after_line(char *str)
{
	char	*newstr;
	int		j;
	int		i;

	j = 0;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (free(str), NULL);
	newstr = malloc(ft_strlen(str) - i + 1);
	if (!newstr)
		return (free(str), NULL);
	i++;
	while (str[i] != '\0')
		newstr[j++] = str[i++];
	newstr[j] = '\0';
	return (free(str), newstr);
}

static char	*ft_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		line = malloc(i + 2);
	else
		line = malloc(i + 1);
	if (!line)
		return (free(str), NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_read_fd(char *str, int fd)
{
	char	*buffer;
	int		byte_readed;

	byte_readed = 1;
	buffer = (char *)malloc((42 + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(str, '\n') && byte_readed != 0)
	{
		byte_readed = read(fd, buffer, 42);
		if (byte_readed == -1)
			return (free(str), free(buffer), NULL);
		buffer[byte_readed] = '\0';
		str = ft_strjoin(str, buffer);
	}
	return (free(buffer), str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (42 <= 0 || fd < 0)
		return (NULL);
	str = ft_read_fd(str, fd);
	if (!str)
		return (NULL);
	line = ft_line(str);
	str = ft_after_line(str);
	return (line);
}
