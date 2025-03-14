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

void	key_press_line(t_game *game, int next_x, int next_y)
{
	if (game->player_up)
		next_y -= TILE_SIZE;
	else if(game->player_down)
		next_y += TILE_SIZE;
	else if (game->player_left)
		next_x -= TILE_SIZE;
	else if (game->player_right)
		next_x += TILE_SIZE;

	int map_x = next_x / TILE_SIZE;
	int map_y = next_y / TILE_SIZE;

	if (game->map->map[map_y][map_x] == '1')
		return ;
	else
	{
		if (game->player_up || game->player_down || game->player_right || game->player_left)
		{
			game->step_count += 1;
			ft_printf("step_count: %d\n", game->step_count);
		}
	}

	game->player_x = next_x;
	game->player_y = next_y;
}

int	key_press(int keycode, t_game *game)
{
	int next_x = game->player_x;
	int next_y = game->player_y;

	key_press_control(keycode, game);

	if (keycode == KEY_ESC)
    {
        mlx_destroy_window(game->game_init, game->game_window);
        exit(0);
	}
	else
		key_press_line(game, next_x, next_y);

	// mlx_clear_window(game->game_init, game->game_window);
	map_put(game);
	mlx_put_image_to_window(game->game_init, game->game_window, game->player_img, game->player_x, game->player_y);

	return 0;
}
