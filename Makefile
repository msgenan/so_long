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

COLOR_LIGHT_RED     =   \033[0;91m
COLOR_LIGHT_GREEN   =   \033[0;92m
COLOR_LIGHT_BLUE    =   \033[0;94m

all: $(NAME)

$(NAME): $(PRINTF) $(MLX) $(GNL) $(SRCS)
	@$(CC) $(CFLAGS) $(MLX) $(GNL) $(SRCS) $(PRINTF) -o $(NAME) $(MLXFLAGS)
	@clear
	@echo "$(COLOR_LIGHT_GREEN)Make is done"

$(MLX):
	@if [ ! -d "$(MLX_PATH)" ]; then \
		echo "$(COLOR_LIGHT_BLUE)Cloning MLX..."; \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_PATH); \
	fi
	@make -C $(MLX_PATH) > /dev/null 2>&1

$(PRINTF):
	@if [ ! -d "$(PRINTF_PATH)" ]; then \
		echo "$(COLOR_LIGHT_BLUE)Cloning PRINTF..."; \
		git clone https://github.com/msgenan/ft_printf.git $(PRINTF_PATH); \
	fi
	@make -C $(PRINTF_PATH) > /dev/null 2>&1

$(GNL):
	@if [ ! -d "$(GNL_PATH)" ]; then \
		echo "$(COLOR_LIGHT_BLUE)Cloning GNL..."; \
		git clone https://github.com/msgenan/get_next_line.git $(GNL_PATH); \
	fi

clone : $(PRINTF) $(MLX) $(GNL)
	@echo "$(COLOR_BLUE)🌀 Cloned Eveything Necessary"

cclone :
	@rm -rf $(MLX_PATH) $(PRINTF_PATH) $(GNL_PATH)
	
clean :
	@make clean -C $(MLX_PATH) > /dev/null 2>&1
	@make clean -C $(PRINTF_PATH) > /dev/null 2>&1
	@echo "$(COLOR_LIGHT_GREEN)🌿 Output files are Cleared"


fclean : clean
	@rm -rf $(NAME)

re : fclean all

gg : clean fclean cclone
	@clear
	@echo "$(COLOR_LIGHT_GREEN)🌿 Everthing Cleared"

.PHONY: all clean fclean re gg