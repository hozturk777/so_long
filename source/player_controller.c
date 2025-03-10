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
	int next_x = game->player_x;
	int next_y = game->player_y;

	if (game->player_up)
		next_y -= TILE_SIZE;
	else if(game->player_down)
		next_y += TILE_SIZE;
	else if (game->player_left)
		next_x -= TILE_SIZE;
	else if (game->player_right)
		next_x += TILE_SIZE;
	
	// int x = game->player_x / TILE_SIZE;
	// int y = game->player_y / TILE_SIZE;
	// ft_printf("x: %d - y :%d - p_x: %d - p_y: %d\n", x, y, game->player_x, game->player_y);
	// ft_printf("map_check: %c\n", game->map[x][y]);
	// if (game->map[x][y] == '1')
	// 	ft_printf("ENGELLENDI");

	int map_x = next_x / TILE_SIZE;
	int map_y = next_y / TILE_SIZE;

	if (game->map[map_x][map_y] == '1')
	{
		ft_printf("ENGELLENDI\n");
		return ;
	}
	
	game->player_x = next_x;
	game->player_y = next_y;
}

int	key_press(int keycode, t_game *game)
{
	key_press_control(keycode, game);

	// if (game->player_up && game->player_left)
	// {
	// 	game->player_x -= TILE_SIZE;
	// 	game->player_y -= TILE_SIZE;
	// }
	// else if (game->player_up && game->player_right)
	// {
	// 	game->player_x += TILE_SIZE;
	// 	game->player_y -= TILE_SIZE;
	// }
	// else if (game->player_down && game->player_left)
	// {
	// 	game->player_x -= TILE_SIZE;
	// 	game->player_y += TILE_SIZE;
	// }
	// else if (game->player_down && game->player_right)
	// {
	// 	game->player_x += TILE_SIZE;
	// 	game->player_y += TILE_SIZE;
	// }
	if (keycode == KEY_ESC)
    {
        mlx_destroy_window(game->game_init, game->game_window);
        exit(0);
	}
	else
		key_press_line(game);
		
	// mlx_clear_window(game->game_init, game->game_window);
	render_map(game);
	mlx_put_image_to_window(game->game_init, game->game_window, game->player_img, game->player_x, game->player_y);
	// mlx_put_image_to_window(game->game_init, game->game_window, game->floor_img, game->player_x, game->player_y+15);
	// mlx_put_image_to_window(game->game_init, game->game_window, game->wall_img, game->player_x, game->player_y + (game->player_height - 17));
	ft_printf("width: %d - height: %d\n", game->player_width, game->player_height);

	
	return 0;
}
