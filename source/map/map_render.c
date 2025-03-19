#include "../so_long.h"

static void	put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->game_init, game->game_window, img, x, y);
}

void	map_put(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == '1')
				put_image(game, game->wall_img, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map.map[y][x] == 'C')
			{
				put_image(game, game->key_img, x * TILE_SIZE, y * TILE_SIZE);
				game->key_count++;
				ft_printf("key_count: %d\n", game->key_count);
			}
			else if (game->map.map[y][x] == 'E')
				put_image(game, game->player_img, x * TILE_SIZE, y * TILE_SIZE);
			else
				put_image(game, game->floor_img, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}
