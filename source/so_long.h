#ifndef SO_LONG_H
# define SO_LONG_H

#include "../lib/minilibx-linux/mlx.h"
#include "../lib/minilibx-linux/mlx_int.h"

typedef struct s_game
{
	void	*game_init;
	void	*game_window;
}	t_game;

void	game_start(t_game *game);


#endif