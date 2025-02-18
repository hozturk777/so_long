#include "so_long.h"
#include <stdlib.h>

int	main()
{
	t_game *game;
	void	*mlx_window;

	game = (t_game *)malloc(sizeof(t_game));
	game_start(game);
	mlx_window = mlx_new_window(game->game_init, 500, 500, "Window");
	mlx_loop(game->game_init);
}