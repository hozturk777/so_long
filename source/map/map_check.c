/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsyn <hsyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:59:14 by huozturk          #+#    #+#             */
/*   Updated: 2025/04/01 14:13:03 by hsyn             ###   ########.fr       */
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

static void	wall_control(t_game *game, int x, int y)	// Map'in çevresi duvar ile mi kaplı bakacak
{
	int	is_wall;

	is_wall = (y == 0 || x == 0
			|| y == game->map.map_height - 1
			|| x == game->map.map_width - 1);
	if (is_wall && game->map.map[y][x] != '1')
		error_control(game, "Map perimeter invalid format", NULL);
	return ;
}

static void	flood_fill(char **map, int x, int y, t_counts *counts)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x])
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')	//	Map'de duvar ve 'F' varsa recursive fonksiyonu durduracak
		return ;
	if (map[y][x] == 'P')
		counts->p_count++;
	else if (map[y][x] == 'E')
		counts->e_count++;
	else if (map[y][x] == 'C')
		counts->c_count++;
	map[y][x] = 'F';	// Baktığı her yeri 'F' olarak değiştirecek ki baktığı yere tekrar tekrar bakıp sonsuz döngüye girmesin
	flood_fill(map, x - 1, y, counts);
	flood_fill(map, x + 1, y, counts);
	flood_fill(map, x, y - 1, counts);
	flood_fill(map, x, y + 1, counts);
}

static int	check_remaining_elements(char **map_clone, t_game *game)
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

	counts.c_count = 0;	//	Collectleri sayıcaz
	counts.p_count = 0;	//	Karakterleri sayıcaz(1 tane olmak zorunda)
	counts.e_count = 0;	//	Exit sayıcaz(1 tane olmak zorunda)
	find_player_start(game);	// Map'de karakterin başlangıç noktasını bulmak için
	game->map.map_clone = read_map(map_path, game);	// Struct yapımız'da map_clone oluşturuyoruz çünkü flood_file da içeriğini değiştirerek kontrol ediyoruz
	if (!game->map.map_clone)
		return ("allocation fail");
	flood_fill(game->map.map_clone,	// Flood_file'ı karakterin başlangıç noktasından başlatıyorum (/ 48 sebebi TILE_SIZE'a bölüp indeks numarasını bulabilmek için)
		game->player_x / 48,
		game->player_y / 48,
		&counts);
	if (counts.p_count != 1 || counts.e_count != 1 || counts.c_count <= 0)	// Count check
		error_control(game, "wrong number of arguments", NULL);
	if (!check_remaining_elements(game->map.map_clone, game))	// Flood_file'dan sonra map'de 'C' || 'E' || 'P' hala varsa hata dönecek
		error_control(game, "wrong number of arguments", NULL);
	return (NULL);
}
