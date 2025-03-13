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
	ft_printf("map_w: %d / map_h: %d", game->map->map_width, game->map->map_height);
}