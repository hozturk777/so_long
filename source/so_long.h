/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozturk <huozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:56:30 by huozturk          #+#    #+#             */
/*   Updated: 2025/03/22 15:38:55 by huozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/ft_printf/ft_printf.h"
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft/libft.h"

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define TILE_SIZE 48

typedef struct s_counts
{
	int	e_count;
	int	p_count;
	int	c_count;
	int	c_count_main;
}	t_counts;

typedef struct s_map
{
	char	**map;
	char	**map_clone;
	int		map_width;
	int		map_height;
}	t_map;

typedef struct s_game
{
	void		*game_init;
	void		*game_window;
	t_map		map;
	int			player_x;
	int			player_y;
	int			player_width;
	int			player_height;
	int			step_count;
	int			key_count;
	int			p_keys;
	int			exit_x;
	int			exit_y;
	int			exit_unlocked;
	void		*player_img;
	void		*wall_img;
	void		*floor_img;
	void		*key_img;
	void		*exit_img;
}	t_game;

void	game_start(t_game *game);
void	game_open_window(t_game *game);
void	render_character_img(t_game *game);
int		*new_image(t_game *game);
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
void	map_put(t_game *game);
char	**read_map(char *map_path, t_game *game);
void	map_size(t_game *game);
char	*check_map_validity(char *map_path, t_game *game);
void	error_control(t_game *game, char *err_msg, void *ptr);
void	array_free(char **arr);
int		press_x(t_game *game);
void	find_player_start(t_game *game);
void	check_invalid_format(t_game *game);

#endif