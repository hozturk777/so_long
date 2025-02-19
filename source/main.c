#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->player_y -= 10;
	else if (keycode == KEY_A)
		game->player_x -= 10;
	else if (keycode == KEY_S)
		game->player_y += 10;
	else if (keycode == KEY_D)
		game->player_x += 10;
	else if (keycode == KEY_ESC)  // ESC tuşu
    {
        mlx_destroy_window(game->game_init, game->game_window);
        exit(0);  // Çıkış yap
    }

	mlx_clear_window(game->game_init, game->game_window);
	mlx_put_image_to_window(game->game_init, game->game_window, game->player_img, game->player_x, game->player_y);

	return 0;
}

int	main()
{
	t_game *game;
	void *img;

	game = (t_game *)malloc(sizeof(t_game));
	game_start(game);
	game_open_window(game);

	if (!render_character_img(game))
	{
		// Resim yüklenemedi
		ft_printf("Resim yüklenemedi!\n");
		return 1;
	}
	// mlx_key_hook(game->game_window, key_press, game);
	mlx_hook(game->game_window, 2, 1L << 0, key_press, game);

	mlx_loop(game->game_init);
}