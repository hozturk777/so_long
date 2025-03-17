#include "../so_long.h"

void	map_size(t_game *game)
{
	int	w;
	int	h;

	h = 0;
	w = 0;
	if (!game->map->map[h])
	{
		free(game->map->map);
		// ERRORCONTROL DE MESSAGE YAZILACAK & BELKİ FREELEME İŞLEMİ
	}
	while (game->map->map[h])
		h++;
	h--;
	while (game->map->map[h][w])
		w++;
	ft_printf("GELDİ\n");
	h++;
	game->map->map_width = w;
	game->map->map_height = h;
	// ft_printf("map_w: %d / map_h: %d", game->map->map_width, game->map->map_height);
}

void	flood_file(char **map, int x, int y, t_counts *counts)
{
	if (map[y][x] == '1')
		return ;
	if (map[y][x] == 'P')
		counts->p_count++;
	else if (map[y][x] == 'E')
		counts->e_count++;
	else if (map[y][x] == 'C')
		counts->c_count++;

	map[y][x] = '1';
	flood_file(map, x + 1, y, counts);
	flood_file(map, x - 1, y, counts);
	flood_file(map, x, y + 1, counts);
	flood_file(map, x, y - 1, counts);
}
int	check_remaining_elements(char **map_clone)
{
	int	x;
	int	y;

	y = 0;
	while (map_clone[y])
	{
		x = 0;
		while (map_clone[y][x])
		{
			if (map_clone[y][x] == 'P' || map_clone[y][x] == 'C' || map_clone[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_map_validity(char *map_path, int start_x, int start_y)
{
	char	**map_clone;
	t_counts counts;
	counts.c_count = 0;
	counts.p_count = 0;
	counts.e_count = 0;
	map_clone = read_map(map_path);
	if (!map_clone)
		return (0);
	flood_file(map_clone, start_x, start_y, &counts);
	ft_printf("p_count: %d - e_count: %d - c_count: %d\n", counts.p_count, counts.e_count, counts.c_count);
	if (counts.p_count != 1 || counts.e_count != 1)
		return (0);		//ERRORCONTROL
	if (!check_remaining_elements(map_clone))
		return (0);		//ERRORCONTROL
	return (1);
}
