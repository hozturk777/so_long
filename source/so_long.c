/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsyn <hsyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:55:44 by huozturk          #+#    #+#             */
/*   Updated: 2025/04/01 13:55:02 by hsyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../lib/minilibx-linux/mlx.h"
#include <stdlib.h>

static int	extension_control(char *av_path)
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

	if (ac != 2)	// ac = 2 olmak zorunda (./so_long map.ber) 
	{
		ft_putendl_fd("too many argv", 2);
		return (1);
	}
	extension_control(av[1]);	//	Girilen map argümanı .ber uzantısı mı diye check
	game = (t_game *)ft_calloc(1, sizeof(t_game));	//	Game struct yapımız için yer tahsisi
	error_control(game, "allocation fail", game);	//	Tahsis edilemezse freeleyip oyunu bitirmek için fonksiyon
	game_start(game);	// Mlx'e start veriyoruz mlx_init() ile
	new_image(game);	// Oyun görsellerini struct yapımızda ki değişkenlerimize dosya yollarını atıyoruz
	game->map.map = read_map(av[1], game);	// .ber uzantılı mapimizi get_next_line ile okuyoruz
	error_control(game, "allocation map", game->map.map);	// Map okunamazsa freeleyip bitirmek için
	map_size(game);	//	Map'in Width ve Height'ini alıyoruz oyun ekranını map boyutunda açmak için
	err_msg = check_map_validity(av[1], game);	// Map Kontrolleri için
	if (err_msg)	// Map kontrolünden hata mesajı dönerde girip freeleyip bitirmek için
		error_control(game, err_msg, NULL);
	game_open_window(game);	// Mlx kütüphanesini kullanarak map.height ve map.width kadar ekran açıyoruz
	map_put(game);	// Açılan ekrana görselleri basıyoruz
	render_character_img(game);	// Map'e karakteri basıyoruz
	mlx_hook(game->game_window, 2, 1L << 0, key_press, game);	//	İnput olarak klavyeden girilen hookları yakalayıp key press fonksiyonunu çalıştırıyor (2 demek tuşa basıldığında çalışacak demek (1L << 0 ise linux işletim sisteminde maskeleme işlemi yani tuşa basıldığını checkleyip eğer basıldıysa işlemi yap))
	mlx_hook(game->game_window, 17, 1L << 17, press_x, game);	//	Ekranın çarpı tuşuna basma hookunu yakaladığında press_x fonksiyonunu çağırır
	mlx_loop(game->game_init);	// mlx kütüphanesinin sonsuz döngüsü oyunu bitirene kadar oyunun açık kalmasını sağlar
}
