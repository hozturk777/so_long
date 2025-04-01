/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsyn <hsyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:56:02 by huozturk          #+#    #+#             */
/*   Updated: 2025/04/01 18:18:27 by hsyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../lib/minilibx-linux/mlx.h"

static void	key_press_control(int *next_x, int *next_y, int keycode)
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
	//	PARAMETRELER
	//	keycode basılan tuş
	//	next_x & next_y karakterin pozisyonu
	int	map_x;
	int	map_y;

	key_press_control(&next_x, &next_y, keycode);	// Hangi tuşa basıldıysa o düzlemde x veya y değerine TILE_SIZE ekler
	map_x = next_x / TILE_SIZE;	//	TILE_SIZE bölme işlemi bulunduğu konumun indeks numarasını bulabilmek için
	map_y = next_y / TILE_SIZE;
	if (game->map.map[map_y][map_x] == '1')	// Yeni Gideceği konum duvar mı check
		return ;
	else if (keycode == KEY_A	//	Burada WASD ise adım sayısı arttırılır ve konsola yazdırılır 
		|| keycode == KEY_W
		|| keycode == KEY_D
		|| keycode == KEY_S)
	{
		game->step_count += 1;
		ft_printf("step_count: %d\n", game->step_count);
		if (game->map.map[map_y][map_x] == 'C')	// Gideceği konum Collect ise toplanan Collect sayısını arttırır ve o konuma floor basar
		{
			game->p_keys++;
			game->map.map[map_y][map_x] = '0';
		}
	}
	game->player_x = next_x;	// Karakterin konumu burada değişir
	game->player_y = next_y;
	if (game->p_keys == game->key_count && game->map.map[map_y][map_x] == 'E')	// Eğer yeni konumu Exit ise ve tüm Collectler toplandıysa oyunu bitirir
		press_x(game);
}

int	key_press(int keycode, t_game *game)
{
	int	last_x;
	int	last_y;

	last_x = game->player_x;	//	Hareketten önce karakterin konumlarını bi değişkene atıyoruz
	last_y = game->player_y;	//	Atma sebebimiz hareket edeceği yönde duvar var mı yok mu checklemek için
	if (keycode == KEY_ESC)		// ESC tuşuna bastığında oyunu kapatmak için
		error_control(game, "game closed", NULL);
	else
		key_press_line(game, game->player_x, game->player_y, keycode);	//	ESC harici bir tuş basılırsa çalışacak fonk
	if (game->map.map[last_y / TILE_SIZE][last_x / TILE_SIZE] != 'E')	// Karakterin eski konumuna floor basar (Exit hariç)
		mlx_put_image_to_window(game->game_init, game->game_window,
			game->floor_img, last_x, last_y);
	if (game->map.map[last_y / TILE_SIZE][last_x / TILE_SIZE] == 'E')	//	Karakterin eski konumu Exit ise Exit basar 
		mlx_put_image_to_window(game->game_init, game->game_window,
			game->exit_img, last_x, last_y);
	mlx_put_image_to_window(game->game_init, game->game_window,	//	Karakterin yeni konumunu basar
		game->player_img, game->player_x, game->player_y);
	return (0);
}
