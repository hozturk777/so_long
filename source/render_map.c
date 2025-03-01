#include "so_long.h"

void    render_map(t_game *game)
{
    int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{

			if (game->map[x][y] == '1')
			{
				mlx_put_image_to_window(game->game_init, game->game_window, game->wall_img, y * TILE_SIZE, x * TILE_SIZE);
			}
			else if (game->map[x][y] == '0')
			{
				mlx_put_image_to_window(game->game_init, game->game_window, game->floor_img, y * TILE_SIZE, x * TILE_SIZE);
				// mlx_put_image_to_window(game->game_init, game->game_window, game->floor_img, game->player_y * TILE_SIZE, game->player_x * TILE_SIZE );

			}
			else if (game->map[x][y] == 'P')
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
			y++;	
		}
		x++;
	}
}
