#include "so_long.h"

int	main()
{
	void 	*mlx_connection;
	void	*mlx_window;

	mlx_connection = mlx_init();
	mlx_new_image(,);
	mlx_window = mlx_new_window(mlx_connection, 500, 500, "Window");
	mlx_loop(mlx_connection);
}