#ifndef SO_LONG_H
# define SO_LONG_H

#include "../lib/minilibx-linux/mlx.h"
#include "../lib/minilibx-linux/mlx_int.h"
#include "../lib/ft_printf/ft_printf.h"

typedef struct s_game
{
	void    *game_init;      // MiniLibX başlangıç pointer'ı
    void    *game_window;    // Oyun penceresi

    char    **map;           // Haritanın 2D dizi olarak tutulması
    int     map_width;       // Haritanın genişliği
    int     map_height;      // Haritanın yüksekliği

    int     player_x;        // Oyuncunun X konumu
    int     player_y;        // Oyuncunun Y konumu
	int     player_width;        // Oyuncunun X konumu
    int     player_height;        // Oyuncunun Y konumu

    int     key_count;       // Toplam toplanması gereken anahtar parçası
    int     collected_keys;  // Oyuncunun topladığı anahtar parçaları

    int     exit_x;          // Çıkış kapısının X konumu
    int     exit_y;          // Çıkış kapısının Y konumu
    int     exit_unlocked;   // 0: Kapı kapalı, 1: Açık

    void    *player_img;     // Oyuncu sprite'ı
    void    *wall_img;       // Duvar sprite'ı
    void    *floor_img;      // Zemin sprite'ı
    void    *key_img;        // Anahtar parçası sprite'ı
    void    *exit_img;       // Çıkış kapısı sprite'ı
}	t_game;

void	game_start(t_game *game);
void	game_open_window(t_game *game);
int	render_character_img(t_game *game);

#endif