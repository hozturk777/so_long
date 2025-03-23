/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozturk <huozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:55:52 by huozturk          #+#    #+#             */
/*   Updated: 2025/03/23 12:40:58 by huozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../../lib/minilibx-linux/mlx.h"
#include <stdlib.h>

void	array_free(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	if (arr)
		free(arr);
}

static void	destroy_image(t_game *game)
{
	if (!game)
		return ;
	if (game->player_img)
		mlx_destroy_image(game->game_init, game->player_img);
	if (game->floor_img)
		mlx_destroy_image(game->game_init, game->floor_img);
	if (game->wall_img)
		mlx_destroy_image(game->game_init, game->wall_img);
	if (game->key_img)
		mlx_destroy_image(game->game_init, game->key_img);
	if (game->exit_img)
		mlx_destroy_image(game->game_init, game->exit_img);
}
void	end_game(t_game *game, int status);

void	error_control(t_game *game, char *err_msg, void *ptr)
{
	if (ptr)
		return ;
	ft_putendl_fd(err_msg, 2);
	end_game(game, 1);
}

int	press_x(t_game *game)
{
	end_game(game, 0);
	return (0);
}

void	end_game(t_game *game, int status)
{
	destroy_image(game);
	if (game)
	{
		array_free(game->map.map_clone);
		array_free(game->map.map);
	}
	if (game && game->game_window)
		mlx_destroy_window(game->game_init, game->game_window);
	if (game && game->game_init)
		mlx_destroy_display(game->game_init);
	if (game && game->game_init)
		free(game->game_init);
	if (game)
		free(game);
	exit(status);
}
