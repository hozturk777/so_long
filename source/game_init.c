#include "so_long.h"

void	game_start(t_game *game)
{
	game->game_init = mlx_init();
}

void	game_open_window(t_game *game)
{
	game->game_window = mlx_new_window(game->game_init, 1024, 768, "Maze Of Keys");
}

int	render_character_img(t_game *game)
{
	game->player_img = mlx_xpm_file_to_image(game->game_init, "image/OneIdle.xpm", &game->player_width, &game->player_height);
	if (!game->player_img)
		return 1;
	mlx_put_image_to_window(game->game_init, game->game_window, game->player_img, 200, 200);
}