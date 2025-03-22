/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozturk <huozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:59:24 by huozturk          #+#    #+#             */
/*   Updated: 2025/03/22 15:40:17 by huozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int	open_file(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (!fd)
	{
		ft_printf("file could not be opened");
		return (0);
	}
	return (fd);
}

static int	check_height(char **map, int f_len)
{
	int	len;
	int	y;

	y = 0;
	len = 0;
	while (map && map[y])
	{
		len++;
		y++;
	}
	if (f_len != len)
	{
		array_free(map);
		return (1);
	}
	return (0);
}

static char	*read_map_utilty(int fd, int *height_len)
{
	char	*line;
	char	*temp;
	char	*joined_map;

	joined_map = NULL;
	line = get_next_line(fd);
	while (line)
	{
		*height_len += 1;
		temp = joined_map;
		joined_map = ft_strjoin(joined_map, line);
		if (temp)
			free(temp);
		free(line);
		line = get_next_line(fd);
	}
	return (joined_map);
}

char	**read_map(char *map_path, t_game *game)
{
	int		fd;
	char	**map;
	char	*joined_map;
	int		len;

	len = 0;
	fd = open_file(map_path);
	if (fd <= 0)
		return (NULL);
	joined_map = read_map_utilty(fd, &len);
	close(fd);
	if (!joined_map)
		return (NULL);
	map = ft_split(joined_map, '\n');
	if (check_height(map, len))
	{
		free(joined_map);
		error_control(game, "There is a gap", NULL);
	}
	return (free(joined_map), map);
}
