#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	t_game	*game;
	char	*err_msg;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	error_control(game, "allocation fail", game);
	game_start(game);
	new_image(game);
	game->map.map = read_map(av[1]);
	error_control(game, "allocation map", game->map.map);
	map_size(game);
	err_msg = check_map_validity(av[1], 1, 1, game);
	if (err_msg)
		error_control(game, err_msg, NULL);
	game_open_window(game);
	map_put(game);
	render_character_img(game);
	mlx_hook(game->game_window, 2, 1L << 0, key_press, game);
	mlx_hook(game->game_window, 17, 1L << 17, press_x, game);
	mlx_loop(game->game_init);
}
