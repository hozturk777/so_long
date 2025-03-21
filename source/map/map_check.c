/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozturk <huozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:59:14 by huozturk          #+#    #+#             */
/*   Updated: 2025/03/22 01:32:01 by huozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_size(t_game *game)
{
	int	w;
	int	h;
	int	tmp;

	h = 0;
	tmp = 0;
	error_control(game, "allocation map", game->map.map[h]);
	while (game->map.map[h])
	{
		w = 0;
		while (game->map.map[h][w])
		{
			w++;
		}
		if (h == 0)
			tmp = w;
		if (tmp != w)
			error_control(game, "not rectanguler", NULL);
		h++;
	}
	game->map.map_height = h;
	game->map.map_width = w;
}

static void	wall_control(t_game *game, int x, int y)
{
	int	is_wall;

	is_wall = (y == 0 || x == 0
			|| y == game->map.map_height - 1
			|| x == game->map.map_width - 1);
	if (is_wall && game->map.map[y][x] != '1')
		error_control(game, "Map perimeter invalid format", NULL);
	return ;
}

void	flood_file(char **map, int x, int y, t_counts *counts)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x])
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'P')
		counts->p_count++;
	else if (map[y][x] == 'E')
		counts->e_count++;
	else if (map[y][x] == 'C')
		counts->c_count++;
	map[y][x] = 'F';
	flood_file(map, x - 1, y, counts);
	flood_file(map, x + 1, y, counts);
	flood_file(map, x, y - 1, counts);
	flood_file(map, x, y + 1, counts);
}

int	check_remaining_elements(char **map_clone, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (map_clone[y])
	{
		x = 0;
		while (map_clone[y][x])
		{
			if (map_clone[y][x] == 'P'
					|| map_clone[y][x] == 'C'
					|| map_clone[y][x] == 'E')
				return (0);
			wall_control(game, x, y);
			x++;
		}
		y++;
	}
	return (1);
}

char	*check_map_validity(char *map_path, t_game *game)
{
	t_counts	counts;

	counts.c_count = 0;
	counts.p_count = 0;
	counts.e_count = 0;
	find_player_start(game);
	game->map.map_clone = read_map(map_path);
	if (!game->map.map_clone)
		return ("allocation fail");
	flood_file(game->map.map_clone,
		game->player_height / 48,
		game->player_y / 48,
		&counts);
	if (counts.p_count != 1 || counts.e_count != 1 || counts.c_count <= 0)
		return (array_free(game->map.map_clone), "wrong number of arguments");
	if (!check_remaining_elements(game->map.map_clone, game))
		return (array_free(game->map.map_clone), "unreachable object");
	return (NULL);
}
