#include "so_long.h"

int	main()
{
	t_game *game;	
	void	*mlx_window;

	game_start(game);
	mlx_window = mlx_new_window(game_start, 500, 500, "Window");
	mlx_loop(game_start);
}