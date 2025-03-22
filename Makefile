MAKEFLAGS 			+= --no-print-directory
NAME				= so_long
LIBFT				= ./lib/libft/libft.a
MINILIBX			= ./lib/minilibx-linux/libmlx_Linux.a
PRINTF				= ./lib/ft_printf/libftprintf.a
SRC_DIR				= source/
GET_DIR				= lib/get_next_line/
OBJ_DIR				= obj/
CC					= cc
CFLAGS				= -Wall -Werror -Wextra
RM					= rm -rf

SO_LONG_DIR			=	$(SRC_DIR)so_long.c \
						$(SRC_DIR)game_init.c \
						$(SRC_DIR)player_controller.c \
						$(SRC_DIR)map/read_map.c \
						$(SRC_DIR)map/map_render.c \
						$(SRC_DIR)map/map_check.c \
						$(SRC_DIR)error/errors_handle.c \
						$(GET_DIR)get_next_line.c \
						$(GET_DIR)get_next_line_utils.c 

SRCS 				= $(SO_LONG_DIR)

OBJ 				= $(patsubst $(SO_LONG_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

COLOR_YELLOW	=	\033[0;33m \033[1m
COLOR_GREEN		=	\033[0;32m \033[1m
COLOR_RED		=	\033[0;31m \033[1m
COLOR_END		=	\033[0m

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT) $(MINILIBX) $(PRINTF)
					@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -g -Lmlx -lmlx -Llib/minilibx-linux -Imlx_linux -lXext -lX11 -lm -lz  -o $(NAME)
					@echo "\n\e[1m$(COLOR_YELLOW)$(NAME)	$(COLOR_GREEN)[is ready!]\e[0m\n$(COLOR_END)"

$(LIBFT):
					@make -C ./lib/libft
					
$(PRINTF):
					@make -C ./lib/ft_printf

$(MINILIBX):
					@make -C ./lib/minilibx-linux

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
					@mkdir -p $(@D)
					@$(CC) -Imlx $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./lib/libft
					@make clean -C ./lib/minilibx-linux
					@make clean -C ./lib/ft_printf
					@echo "\n\e[1m$(COLOR_YELLOW)objects	$(COLOR_RED)[are deleted!]\e[0m$(COLOR_END)"

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)
					@$(RM) $(PRINTF)
					@echo "\e[1m$(COLOR_YELLOW)$(NAME)	$(COLOR_RED)[is deleted!]\e[0m\n$(COLOR_END)"

re: 				fclean all

.PHONY: 			all clean fclean re





# Açıklama: Bu Makefile, "mazeofkeys" adında bir 2D oyun projesini derlemek için kullanılıyor. Kütüphaneleri (libft, minilibx, ft_printf) ve kaynak dosyaları birleştirerek çalıştırılabilir bir dosya oluşturuyor. Şimdi her satırı inceleyelim:

# NAME				= mazeofkeys
# # "NAME" değişkeni, derleme sonucunda oluşturulacak çalıştırılabilir dosyanın adını tanımlar: "mazeofkeys". Bu, projenin nihai çıktı dosyasıdır.

# LIBFT				= ./lib/libft/libft.a
# # "LIBFT", libft kütüphanesinin statik dosyasının (libft.a) yolunu belirtir. Bu kütüphane, standart C fonksiyonlarının özel bir implementasyonunu içerir ve ./lib/libft/ dizininde bulunur.

# MINILIBX			= ./lib/minilibx-linux/libmlx_Linux.a
# # "MINILIBX", MiniLibX grafik kütüphanesinin statik dosyasının (libmlx_Linux.a) yolunu tanımlar. Bu kütüphane, pencere yönetimi ve grafik işlemleri için kullanılır ve Linux uyumludur.

# PRINTF				= ./lib/ft_printf/libftprintf.a
# # "PRINTF", ft_printf kütüphanesinin statik dosyasının (libftprintf.a) yolunu belirtir. Bu, özelleştirilmiş bir printf fonksiyonu sağlar ve ./lib/ft_printf/ dizinindedir.

# SRC_DIR				= source/
# # "SRC_DIR", kaynak dosyaların (.c) bulunduğu ana dizini tanımlar: "source/". Tüm temel kod dosyaları burada yer alır.

# SRC_MAP_DIR			= source/map
# # "SRC_MAP_DIR", harita ile ilgili kaynak dosyaların bulunduğu alt dizini tanımlar: "source/map". Harita işleme kodları burada olabilir.

# GET_DIR				= lib/get_next_line/
# # "GET_DIR", get_next_line fonksiyonunun kaynak dosyalarının yer aldığı dizini belirtir: "lib/get_next_line/". Bu, dosyadan satır satır okuma için kullanılır.

# OBJ_DIR				= obj/
# # "OBJ_DIR", derlenmiş nesne dosyalarının (.o) saklanacağı dizini tanımlar: "obj/". Kaynak dosyalar derlenince buraya yerleştirilir.

# CC					= cc
# # "CC", kullanılacak derleyiciyi belirtir: "cc" (C Compiler). Bu, genellikle GCC veya Clang gibi bir derleyicinin takma adıdır.

# # CFLAGS				= -Wall -Werror -Wextra
# # "CFLAGS", derleme bayraklarını tanımlar ama burada yorum satırı (#) ile devre dışı bırakılmış. Normalde -Wall (tüm uyarıları göster), -Werror (uyarıları hata olarak değerlendir), -Wextra (ekstra uyarılar) içerirdi.

# RM					= rm -f
# # "RM", dosya silme komutunu tanımlar: "rm -f" (remove -force). "-f" bayrağı, silme işlemini zorla gerçekleştirir ve onay istemez.

# SO_LONG_DIR			= $(SRC_DIR)main.c \
# 				 		$(SRC_DIR)game_init.c \
# 				 		$(SRC_DIR)player_controller.c \
# 				 		$(SRC_DIR)read_map.c \
# 				 		$(SRC_DIR)map_render.c \
# 						$(GET_DIR)get_next_line.c \
# 						$(GET_DIR)get_next_line_utils.c
# # "SO_LONG_DIR", projenin kaynak dosyalarını (.c) listeler. Her biri bir satırda, "\" ile ayrılmıştır. main.c (ana program), game_init.c (oyun başlatma), player_controller.c (oyuncu kontrolü), read_map.c (harita okuma), map_render.c (harita çizimi), get_next_line.c ve get_next_line_utils.c (satır okuma yardımcıları) içerir.

# SRCS 				= $(SO_LONG_DIR)
# # "SRCS", kaynak dosyaları "SO_LONG_DIR" değişkenine atar. Bu, tüm kaynak dosyaları tek bir değişkende toplar.

# OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))
# # "OBJ", kaynak dosyaları (.c) nesne dosyalarına (.o) dönüştürür. "patsubst" fonksiyonu, $(SRC_DIR) içindeki .c dosyalarını $(OBJ_DIR) içindeki .o dosyalarına çevirir. Örneğin, source/main.c → obj/main.o olur.

# all: 				$(NAME)
# # "all" kuralı, varsayılan hedefi belirtir. $(NAME) yani "mazeofkeys" dosyasını oluşturur. Makefile çalıştırıldığında ilk bu hedef tetiklenir.

# $(NAME): 			$(OBJ) $(LIBFT) $(MINILIBX) $(PRINTF)
# 					@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -g -Lmlx -lmlx -Llib/minilibx-linux -Imlx_linux -lXext -lX11 -lm -lz  -o $(NAME)
# # "$(NAME)" kuralı, çalıştırılabilir dosyayı oluşturur. Bağımlılıklar: $(OBJ) (nesne dosyaları), $(LIBFT), $(MINILIBX), $(PRINTF). Komut: derleyici (cc), bayraklar (CFLAGS - burada typo var, "CFLA\"G\"S" olmalı), nesne dosyaları ve kütüphaneleri birleştirir. -g (hata ayıklama), -L (kütüphane dizini), -l (kütüphane bağlantısı: mlx, Xext, X11, m, z), -o (çıktı dosyası: mazeofkeys). "@" ile komutun terminalde görünmesi engellenir.

# $(LIBFT):
# 					@make -C ./lib/libft
# # "$(LIBFT)" kuralı, libft kütüphanesini derler. "-C" ile ./lib/libft dizinine gidip oradaki Makefile'ı çalıştırır.

# $(PRINTF):
# 					@make -C ./lib/ft_printf
# # "$(PRINTF)" kuralı, ft_printf kütüphanesini derler. ./lib/ft_printf dizinindeki Makefile'ı çalıştırır.

# # $(MINILIBX):
# # 					@make -C ./lib/minilibx-linux
# # "$(MINILIBX)" kuralı, MiniLibX kütüphanesini derlemeyi amaçlar ama yorum satırı (#) ile devre dışı bırakılmış. Normalde ./lib/minilibx-linux dizinindeki Makefile'ı çalıştırırdı.

# $(OBJ_DIR)%.o:		$(SRC_DIR)%.c
# 					@mkdir -p $(@D)
# 					@$(CC) -Imlx $(INC) -c $< -o $@
# # Nesne dosyası oluşturma kuralı. Her .c dosyası (örneğin source/main.c), karşılık gelen .o dosyasına (obj/main.o) çevrilir. "mkdir -p $(@D)" ile çıktı dizini (obj/) yoksa oluşturulur. "$(CC
