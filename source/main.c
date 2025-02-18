#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

int	main()
{
	t_game *game;
	void *img;
	int	img_width;
	int	img_height;

	game = (t_game *)malloc(sizeof(t_game));
	game_start(game);
	game_open_window(game);

	if (!render_character_img(game))
	{
		// Resim yüklenemedi
		ft_printf("Resim yüklenemedi!\n");
		return 1;
	}

	mlx_loop(game->game_init);
}