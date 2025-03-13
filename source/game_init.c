#include "so_long.h"

void	game_start(t_game *game)
{
	game->game_init = mlx_init();
}

void	game_open_window(t_game *game)
{
	int	i = game->map->map_width * TILE_SIZE ;
	int j = game->map->map_height * TILE_SIZE ;
	game->game_window = mlx_new_window(game->game_init, i, j, "Maze Of Keys");
}

int	render_character_img(t_game *game)
{
	game->player_img = mlx_xpm_file_to_image(game->game_init, "image/character/down1_48x48.xpm", &game->player_width, &game->player_height);

	game->player_x = 5 * TILE_SIZE;
	game->player_y = 5 * TILE_SIZE;
	// game->player_width += 15;
	if (!game->player_img)
		return 1;
	mlx_put_image_to_window(game->game_init, game->game_window, game->player_img, game->player_x, game->player_y);
}

int	render_map_img(t_game *game)
{
	int	x;
	int	y;

	game->wall_img = mlx_xpm_file_to_image(game->game_init, "image/map/Dungeon48x48.xpm", &x, &y);

	if (!game->wall_img)
		return 1;

	game->floor_img = mlx_xpm_file_to_image(game->game_init, "image/map/Floor48x48.xpm", &x, &y);

	(void)x;
	(void)y;

	if (!game->floor_img)
		return 1;
}
