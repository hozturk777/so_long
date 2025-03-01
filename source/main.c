#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

int	main()
{
	t_game *game;
	void *img;

	game = (t_game *)malloc(sizeof(t_game));
	game_start(game);
	game_open_window(game);

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
	
	game->map = read_map("./map/map1.ber");
	if (!game->map)
	{
		ft_printf("Harita Yuklenemedi!");
		return 1;
	}
	render_map(game);

	if (!render_character_img(game))
	{
		// Resim yüklenemedi
		ft_printf("Resim yüklenemedi!\n");
		return 1;
	}

	

	// mlx_key_hook(game->game_window, key_press, game);
	mlx_hook(game->game_window, 2, 1L << 0, key_press, game);
	mlx_hook(game->game_window, 3, 1L << 1, key_release, game);
	

	mlx_loop(game->game_init);
}
