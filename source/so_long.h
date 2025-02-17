#ifndef SO_LONG
# define SO_LONG

#include "../lib/minilibx-linux/mlx.h"
#include "../lib/minilibx-linux/mlx_int.h"

typedef struct s_game
{
	void	*game_init;
	void	*game_window;
}	t_game;


#endif