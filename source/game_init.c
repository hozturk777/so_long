#include "so_long.h"

void	game_start(t_game *game)
{
	game->game_init = mlx_init();
}

void	game_open_window(t_game *game)
{
	game->game_window = mlx_new_window(game->game_init, 800, 600, "Maze Of Keys");
}

int	render_character_img(t_game *game)
{
	game->player_img = mlx_xpm_file_to_image(game->game_init, "image/25_OneIdle_floor.xpm", &game->player_width, &game->player_height);

	game->player_x = 0;
	game->player_y = 0;

	if (!game->player_img)
		return 1;
	mlx_put_image_to_window(game->game_init, game->game_window, game->player_img, game->player_x, game->player_y);
}

int	render_map_img(t_game *game)
{
	int	x;
	int	y;

	game->wall_img = mlx_xpm_file_to_image(game->game_init, "image/map/Dungeon.xpm", &x, &y);

	if (!game->wall_img)
		return 1;

	game->floor_img = mlx_xpm_file_to_image(game->game_init, "image/map/Floor.xpm", &x, &y);

	mlx_put_image_to_window(game->game_init, game->game_window, game->wall_img, 200, 100);

	(void)x;
	(void)y;

	if (!game->floor_img)
		return 1;
}
