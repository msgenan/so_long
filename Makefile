NAME = so_long
SRCS = ./src/so_long.c \
./src/utils.c \
./src/key_press.c \
./src/parse_map.c \
./src/flood_fill.c \
./src/map_checker.c \

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L./src/mlx -lmlx -lXext -lX11 -lm
MLX_PATH = ./src/mlx
MLX = $(MLX_PATH)/libmlx.a
PRINTF_PATH = ./src/ft_printf
PRINTF = $(PRINTF_PATH)/libftprintf.a
GNL_PATH = ./src/gnl
GNL = $(GNL_PATH)/get_next_line.c $(GNL_PATH)/get_next_line_utils.c

all: $(NAME)

$(NAME): $(PRINTF)  $(MLX) $(GNL)
	$(CC) $(CFLAGS) $(MLX) $(GNL) $(SRCS) $(PRINTF) -o $(NAME) $(MLXFLAGS)
	@clear

$(MLX):
	@if [ ! -d "$(MLX_PATH)" ]; then \
		echo "Cloning minilibx-linux repository..."; \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_PATH); \
	fi
	make -C $(MLX_PATH)

$(GNL):
	@if [ ! -d "$(GNL_PATH)" ]; then \
		echo "Cloning get_next_line repository..."; \
		git clone https://github.com/msgenan/get_next_line.git $(GNL_PATH); \
	fi

$(PRINTF):
	@if [ ! -d "$(PRINTF_PATH)" ]; then \
		echo "Cloning printf repository..."; \
		git clone https://github.com/msgenan/ft_printf.git $(PRINTF_PATH); \
	fi
	make -C $(PRINTF_PATH)

clone : $(PRINTF)  $(MLX) $(GNL)

cclone :
	rm -rf $(MLX_PATH) $(PRINTF_PATH) $(GNL_PATH)
	
clean :
	make clean -C $(MLX_PATH)
	make clean -C $(PRINTF_PATH)


fclean : 
	rm -rf $(NAME)

re : fclean all

gg : clean fclean
	@clear

.PHONY: all clean fclean re gg