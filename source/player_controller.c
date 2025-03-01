#include "so_long.h"

void	key_press_control(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->player_up = 1;
	else if (keycode == KEY_A)
		game->player_left = 1;
	else if (keycode == KEY_D)
		game->player_right = 1;
	else if (keycode == KEY_S)
		game->player_down = 1;
}

int	key_release(int keycode, t_game *game)
{
	// Tuş serbest bırakıldığında bayrakları sıfırla
    if (keycode == KEY_W)
        game->player_up = 0;
    else if (keycode == KEY_S)
        game->player_down = 0;
    else if (keycode == KEY_D)
        game->player_right = 0;
    else if (keycode == KEY_A)
        game->player_left = 0;

    return 0;
}

void	key_press_line(t_game *game)
{
	if (game->player_up)
		game->player_y -= 5;
	else if(game->player_down)
		game->player_y += 5;
	else if (game->player_left)
		game->player_x -= 5;
	else if (game->player_right)
		game->player_x += 5;
}

int	key_press(int keycode, t_game *game)
{
	key_press_control(keycode, game);

	if (game->player_up && game->player_left)
	{
		game->player_x -= 5;
		game->player_y -= 5;
	}
	else if (game->player_up && game->player_right)
	{
		game->player_x += 5;
		game->player_y -= 5;
	}
	else if (game->player_down && game->player_left)
	{
		game->player_x -= 5;
		game->player_y += 5;
	}
	else if (game->player_down && game->player_right)
	{
		game->player_x += 5;
		game->player_y += 5;
	}
	else if (keycode == KEY_ESC)
    {
        mlx_destroy_window(game->game_init, game->game_window);
        exit(0);
	}
	else
		key_press_line(game);
		
	// mlx_clear_window(game->game_init, game->game_window);
	// mlx_put_image_to_window(game->game_init, game->game_window, game->floor_img, game->player_x, game->player_y+5);
	// mlx_put_image_to_window(game->game_init, game->game_window, game->floor_img, game->player_x, game->player_y-5);
	render_map(game);
	mlx_put_image_to_window(game->game_init, game->game_window, game->player_img, game->player_x, game->player_y);
	

	return 0;
}
