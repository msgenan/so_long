NAME = so_long
SRCS = ./src/so_long.c ./src/map_checker.c ./src/more_map_checker.c ./src/functions.c ./src/gnl/get_next_line.c ./src/gnl/get_next_line_utils.c
		
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L ./src/mlx -lmlx -lXext -lX11 -lm -lz
MLX = ./src/mlx/libmlx.a
PRINTF = ./src/ft_printf/libftprintf.a
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(FT_PRINTF) $(OBJS) -lXext -lX11 -lm -o $(NAME)
	@clear
	@echo "'-'"

all: $(MLX) $(NAME)



$(MLX) :
	make -C ./src/mlx

$(PRINTF) :
	make -C ./src/ft_printf

clean : 
	rm -rf $(OBJS)
	make clean -C ./src/ft_printf
	make clean -C ./src/ft_printf

fclean : 
	rm -rf $(NAME) $(MLX) $(PRINTF)

re : fclean all

gg : clean fclean
	@clear
	@echo "^_'"

.PHONY: all clean fclean re gg