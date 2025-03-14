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

void	flood_file(char **map, int x, int y)
{
	if (map[y][x] == '1')
		return ;

	map[y][x] = '1';

	flood_file(map, x + 1, y);
	flood_file(map, x - 1, y);
	flood_file(map, x, y + 1);
	flood_file(map, x, y - 1);
}

int	check_map_validity(char *map_path, int width, int height, int start_x, int start_y)
{
	char **map_clone;

	map_clone = read_map(map_path);
	if (!map_clone)
		return (0);
	
	flood_file(map_clone, start_x,start_y);
}