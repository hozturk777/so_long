#include "../so_long.h"

void    map_put(t_game *game)
{
    int	x;
	int	y;

	y = 0;

	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			if (game->map->map[y][x] == '1')
				mlx_put_image_to_window(game->game_init, game->game_window, game->wall_img, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map->map[y][x] == 'C')
			{
				mlx_put_image_to_window(game->game_init, game->game_window, game->key_img, x * TILE_SIZE, y * TILE_SIZE);
				
			}
			else
				mlx_put_image_to_window(game->game_init, game->game_window, game->floor_img, x * TILE_SIZE, y * TILE_SIZE);
			// else if (game->map->map[y][x] == 'E')
			// 	mlx_put_image_to_window(game->game_init, game->game_window, game->player_img, x * TILE_SIZE, y * TILE_SIZE);
			
			x++;
		}
		y++;
	}
}
