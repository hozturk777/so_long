/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozturk <huozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:55:55 by huozturk          #+#    #+#             */
/*   Updated: 2025/03/22 00:17:34 by huozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../lib/minilibx-linux/mlx.h"

void	game_start(t_game *game)
{
	game->game_init = mlx_init();
	error_control(game, "mlx_init failed", game->game_init);
}

void	game_open_window(t_game *game)
{
	int	i;
	int	j;

	i = game->map.map_width * TILE_SIZE;
	j = game->map.map_height * TILE_SIZE;
	game->game_window = mlx_new_window(game->game_init, i, j, "Maze Of Keys");
	error_control(game, "cant open window", game->game_window);
}

void	find_player_start(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'P')
			{
				game->player_x = x * TILE_SIZE;
				game->player_y = y * TILE_SIZE;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	render_character_img(t_game *game)
{
	mlx_put_image_to_window(game->game_init, game->game_window,
		game->player_img,
		game->player_x,
		game->player_y);
}

int	*new_image(t_game *game)
{
	int	x;
	int	y;

	game->player_img = mlx_xpm_file_to_image(game->game_init,
			"img/character/plyr.xpm",
			&game->player_width, &game->player_height);
	game->wall_img = mlx_xpm_file_to_image(game->game_init,
			"img/map/Dungeon48x48.xpm", &x, &y);
	game->floor_img = mlx_xpm_file_to_image(game->game_init,
			"img/map/Floor48x48.xpm", &x, &y);
	game->key_img = mlx_xpm_file_to_image(game->game_init,
			"img/collect/key48x48.xpm", &x, &y);
	game->exit_img = mlx_xpm_file_to_image(game->game_init,
			"img/map/portal48.xpm", &x, &y);
	if (!game->player_img
		|| !game->wall_img
		|| !game->floor_img
		|| !game->key_img)
		error_control(game, "img open failed", NULL);
	return (0);
}
