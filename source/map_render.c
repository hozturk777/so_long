#include "so_long.h"

void    map_put(t_game *game)
{
    int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{

			if (game->map[y][x] == '1')
			{
				mlx_put_image_to_window(game->game_init, game->game_window, game->wall_img, y * TILE_SIZE, x * TILE_SIZE);
			}
			else if (game->map[y][x] == '0')
			{
				mlx_put_image_to_window(game->game_init, game->game_window, game->floor_img, y * TILE_SIZE, x * TILE_SIZE);

			}
			else if (game->map[y][x] == 'P')
			{
				mlx_put_image_to_window(game->game_init, game->game_window, game->player_img, y * TILE_SIZE, x * TILE_SIZE);

			}
			// else if (game->map[x][y] == 'E')
			// {
			// 	mlx_put_image_to_window(game->game_init, game->game_window, game->exit_img, x * TILE_SIZE, y * TILE_SIZE);
			// }
			// else if (game->map[x][y] == 'C')
			// {
			// 	mlx_put_image_to_window(game->game_init, game->game_window, game->key_img, x * TILE_SIZE, y * TILE_SIZE);
			// }
			x++;	
		}
		y++;
	}
	ft_printf("map_x: %d map_y: %d\n", y, x);
	game->map_height = x;
	game->map_width = y;
}
