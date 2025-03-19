#include "so_long.h"

void	key_press_control(t_game *game, int *next_x, int *next_y, int keycode)
{
	if (keycode == KEY_W)
		*next_y -= TILE_SIZE;
	else if(keycode == KEY_S)
		*next_y += TILE_SIZE;
	else if (keycode == KEY_A)
		*next_x -= TILE_SIZE;
	else if (keycode == KEY_D)
		*next_x += TILE_SIZE;
}

void	key_press_line(t_game *game, int next_x, int next_y, int keycode)
{
	key_press_control(game, &next_x, &next_y, keycode);
		
	int map_x;
	int map_y;

	map_x = next_x / TILE_SIZE;
	map_y = next_y / TILE_SIZE;

	if (game->map.map[map_y][map_x] == '1')
		return ;	
	else if (keycode == KEY_A || keycode == KEY_W || keycode == KEY_D || keycode == KEY_S)
	{
		game->step_count += 1;
		ft_printf("step_count: %d\n", game->step_count);
		if (game->map.map[map_y][map_x] == 'C')
		{
			game->collected_keys++;
			game->map.map[map_y][map_x] = '0';
		}
		ft_printf("collected_keys: %d\n", game->collected_keys);
	}
	game->player_x = next_x;
	game->player_y = next_y;
	if (game->collected_keys == game->key_count && game->map.map[map_y][map_x] == 'E')
		press_x(game);
}

int	key_press(int keycode, t_game *game)
{
	int last_x;
	int last_y;

	last_x = game->player_x;
	last_y = game->player_y;

	if (keycode == KEY_ESC)
		error_control(game, "game closed", NULL);
	else
		key_press_line(game, game->player_x, game->player_y, keycode);

	if (game->map.map[last_y / TILE_SIZE][last_x / TILE_SIZE] != 'E')
		mlx_put_image_to_window(game->game_init, game->game_window, game->floor_img, last_x, last_y);
	
	mlx_put_image_to_window(game->game_init, game->game_window, game->player_img, game->player_x, game->player_y);

	return 0;
}
