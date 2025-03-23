/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozturk <huozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:55:44 by huozturk          #+#    #+#             */
/*   Updated: 2025/03/23 12:39:57 by huozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../lib/minilibx-linux/mlx.h"
#include <stdlib.h>

int	extension_control(char *av_path)
{
	char	*check;

	check = ft_strchr(av_path, '.');
	if (check)
	{
		if (!ft_strncmp(check, ".ber", 4))
			return (0);
	}
	ft_putendl_fd("invalid map extension", 2);
	exit(1);
}

int	main(int ac, char **av)
{
	t_game	*game;
	char	*err_msg;

	if (ac != 2)
	{
		ft_putendl_fd("too many argv", 2);
		return (1);
	}
	extension_control(av[1]);
	game = (t_game *)ft_calloc(1, sizeof(t_game));
	error_control(game, "allocation fail", game);
	game_start(game);
	new_image(game);
	game->map.map = read_map(av[1], game);
	error_control(game, "allocation map", game->map.map);
	map_size(game);
	err_msg = check_map_validity(av[1], game);
	if (err_msg)
		error_control(game, err_msg, NULL);
	game_open_window(game);
	map_put(game);
	render_character_img(game);
	mlx_hook(game->game_window, 2, 1L << 0, key_press, game);
	mlx_hook(game->game_window, 17, 1L << 17, press_x, game);
	mlx_loop(game->game_init);
}
