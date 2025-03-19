#include "../so_long.h"

void	map_size(t_game *game)
{
	int	w;
	int	h;

	h = 0;
	w = 0;
	if (!game->map.map[h])
	{
		free(game->map.map);
		// ERRORCONTROL DE MESSAGE YAZILACAK & BELKİ FREELEME İŞLEMİ
	}
	while (game->map.map[h])
		h++;
	h--;
	while (game->map.map[h][w])
		w++;
	ft_printf("GELDİ\n");
	h++;
	game->map.map_width = w;
	game->map.map_height = h;
}

static void	wall_control(t_game *game, int x, int y)
{
	int	is_wall;

	if (y == game->map.map_height - 1)
		ft_printf("%d\n", game->map.map[y][x]);
	
	is_wall = (y == 0 || x == 0 || y == game->map.map_height - 1 || x == game->map.map_width - 1);
	if (is_wall && game->map.map[y][x] != '1')
		error_control(game, "Map perimeter invalid format", NULL);
	return ;
}

void	flood_file(char **map, int x, int y, t_counts *counts)
{
	if (!map[y] || !map[y][x] || x < 0 || y < 0)
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
	flood_file(map, x + 1, y, counts);
	flood_file(map, x - 1, y, counts);
	flood_file(map, x, y + 1, counts);
	flood_file(map, x, y - 1, counts);
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
			if (map_clone[y][x] == 'P' || map_clone[y][x] == 'C' || map_clone[y][x] == 'E')
				return (0);
			wall_control(game, x, y);
			x++;
		}
		y++;
	}
	return (1);
}

char	*check_map_validity(char *map_path, int start_x, int start_y, t_game *game)
{
	char	**map_clone;
	t_counts counts;

	counts.c_count = 0;
	counts.p_count = 0;
	counts.e_count = 0;
	map_clone = read_map(map_path);
	if (!map_clone)
		return ("allocation fail");
	flood_file(map_clone, start_x, start_y, &counts);
	ft_printf("p_count: %d - e_count: %d - c_count: %d\n", counts.p_count, counts.e_count, counts.c_count);
	if (counts.p_count != 1 || counts.e_count != 1)
		return (array_free(map_clone), "wrong number of arguments");
	if (!check_remaining_elements(map_clone, game))
		return (array_free(map_clone), "unreachable object");
	array_free(map_clone);
	return (NULL);
}
