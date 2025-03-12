#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	t_game *game;
	t_map	map;

	game = (t_game *)malloc(sizeof(t_game));
	game->map = &map;
	game_start(game);


	game->player_up = 0;
	game->player_down = 0;
	game->player_left = 0;
	game->player_right = 0;

	if (!render_map_img(game))
	{ 
		// Resim yüklenemedi
		ft_printf("Resim yüklenemedi!\n");
		return 1;
	}
	
	game->map->map = read_map(av[1]);
	map_size(game);


	if (!game->map)
	{
		ft_printf("Harita Yuklenemedi!");
		return 1;
	}
	game_open_window(game);
	
	map_put(game);

	if (!render_character_img(game))
	{
		ft_printf("Resim yüklenemedi!\n");
		return 1;
	}

	mlx_hook(game->game_window, 2, 1L << 0, key_press, game);
	mlx_hook(game->game_window, 3, 1L << 1, key_release, game);
	mlx_loop(game->game_init);
}
