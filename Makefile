NAME				= so_long
LIBFT				= ./lib/libft/libft.a
MINILIBX			= ./lib/minilibx-linux/libmlx_Linux.a
PRINTF				= ./lib/ft_printf/libftprintf.a
SRC_DIR				= source/
OBJ_DIR				= obj/
CC					= cc
# CFLAGS				= -Wall -Werror -Wextra
RM					= rm -f

SO_LONG_DIR			= $(SRC_DIR)main.c \
				 		$(SRC_DIR)game_init.c \
				 		$(SRC_DIR)player_controller.c \
				 		$(SRC_DIR)read_map.c \
				 		$(SRC_DIR)render_map.c 

SRCS 				= $(SO_LONG_DIR)

OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT) $(MINILIBX) $(PRINTF)
					@$(CC) $(CFLA"G"S) $(OBJ) $(LIBFT) $(PRINTF) -Lmlx -lmlx -Llib/minilibx-linux -Imlx_linux -lXext -lX11 -lm -lz  -o $(NAME)

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

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)
					@$(RM) $(PRINTF)

re: 				fclean all

.PHONY: 			all clean fclean re








# NAME = MazeOfKeys
# SOU
# SRC = source/main.c \
# 		game_init.c \
# 		player_controller.c \
# 		read_map.c \
# 		render_map.c 
# OBJ = $(SRC:%.c=%.o)

# CFLAGS = -Wall -Wextra -Werror
# LIB_FLAG = -Llib/ft_printf -l:libftprintf.a -Lsource -l:so_long.a
# MLX_FLAG =  -Lmlx -lmlx -Llib/minilibx-linux -Imlx_linux -lXext -lX11 -lm -lz 
# all: $(NAME)

# $(NAME): $(OBJ)
# 	@make -C lib/minilibx-linux
# 	@make -C source
# 	@make -C lib/ft_printf
# 	@make -C lib/libft
# 	gcc $(OBJ) $(LIB_FLAG) $(MLX_FLAG)   -o $(NAME)

# %.o: %.c
# 	gcc $(MLX_FLAG)   -c $< -o $@

# all: $(NAME)

# clean:
# 	@rm -rf $(OBJ)

# 	@echo "\033[0;32mObje dosyaları temizlendi.\033[0m"

# fclean: clean
# 	@rm -rf $(NAME)

# 	@echo "\033[0;32mTüm derleme dosyaları temizlendi.\033[0m"

# re: fclean all

# .PHONY: re fclean clean all 






