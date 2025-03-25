/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsyn <hsyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:56:02 by huozturk          #+#    #+#             */
/*   Updated: 2025/03/25 17:01:00 by hsyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../lib/minilibx-linux/mlx.h"

void	key_press_control(int *next_x, int *next_y, int keycode)
{
	if (keycode == KEY_W)
		*next_y -= TILE_SIZE;
	else if (keycode == KEY_S)
		*next_y += TILE_SIZE;
	else if (keycode == KEY_A)
		*next_x -= TILE_SIZE;
	else if (keycode == KEY_D)
		*next_x += TILE_SIZE;
}

void	key_press_line(t_game *game, int next_x, int next_y, int keycode)
{
	int	map_x;
	int	map_y;

	key_press_control(&next_x, &next_y, keycode);
	map_x = next_x / TILE_SIZE;
	map_y = next_y / TILE_SIZE;
	if (game->map.map[map_y][map_x] == '1')
		return ;
	else if (keycode == KEY_A
		|| keycode == KEY_W
		|| keycode == KEY_D
		|| keycode == KEY_S)
	{
		game->step_count += 1;
		ft_printf("step_count: %d\n", game->step_count);
		if (game->map.map[map_y][map_x] == 'C')
		{
			game->p_keys++;
			game->map.map[map_y][map_x] = '0';
		}
	}
	game->player_x = next_x;
	game->player_y = next_y;
	if (game->p_keys == game->key_count && game->map.map[map_y][map_x] == 'E')
		press_x(game);
}

int	key_press(int keycode, t_game *game)
{
	int	last_x;
	int	last_y;

	last_x = game->player_x;
	last_y = game->player_y;
	if (keycode == KEY_ESC)
		error_control(game, "game closed", NULL);
	else
		key_press_line(game, game->player_x, game->player_y, keycode);
	if (game->map.map[last_y / TILE_SIZE][last_x / TILE_SIZE] != 'E')
		mlx_put_image_to_window(game->game_init, game->game_window,
			game->floor_img, last_x, last_y);
	if (game->map.map[last_y / TILE_SIZE][last_x / TILE_SIZE] == 'E')
		mlx_put_image_to_window(game->game_init, game->game_window,
			game->exit_img, last_x, last_y);
	mlx_put_image_to_window(game->game_init, game->game_window,
		game->player_img, game->player_x, game->player_y);
	return (0);
}
