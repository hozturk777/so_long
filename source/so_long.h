#ifndef SO_LONG_H
# define SO_LONG_H

#include "../lib/minilibx-linux/mlx.h"
#include "../lib/minilibx-linux/mlx_int.h"
#include "../lib/ft_printf/ft_printf.h"
#include "../lib/get_next_line/get_next_line.h"
#include "../lib/libft/libft.h"

// Tuş kodları
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_ESC 65307
#define TILE_SIZE 24

typedef struct s_game
{
	void    *game_init;      // MiniLibX başlangıç pointer'ı
    void    *game_window;    // Oyun penceresi

    char    **map;           // Haritanın 2D dizi olarak tutulması
    int     map_width;       // Haritanın genişliği
    int     map_height;      // Haritanın yüksekliği

    int     player_x;        // Oyuncunun X konumu
    int     player_y;        // Oyuncunun Y konumu
	int     player_width;        // Oyuncunun genişlik
    int     player_height;        // Oyuncu yükseklik
    int     player_up;
    int     player_down;
    int     player_right;
    int     player_left;

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
int	render_map_img(t_game *game);
int	key_press(int keycode, t_game *game);
int	key_release(int keycode, t_game *game);
void	render_map(t_game *game);
char	**read_map(char *map_path);


#endif
