#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include "./gnl/get_next_line.h"
#include "./mlx/mlx.h"

typedef struct s_mlx
{
	void *mlx;
	void *window;
	void *floor;
	void *exit;
	void *player;
	void *wall;
	void *collect;
	int x;
	int y;
	int move;

}	t_mlx;

typedef struct s_content
{
	char **map;
	char **mapx;
	char *path;
	int vertical;
	int horizontal;
	int random;
	int playerx;
	int playery;
	int newplayerx;
	int newplayery;
	int c;
	int e;
	int p;
	int counter;
	t_mlx *a;

}	t_content;

void	map_control(t_content *x);
void 	check_char(t_content *x);
void 	check_map(t_content *x);
void 	read_map(t_content *x);
int		length(const char *str);
void	error(char *error);
void 	flood_check(t_content *x);
void 	all_map_checks(t_content *x);
void	flood_fill(t_content *x, int playerx, int playery);
void	parse_img(t_content *x);
void	textures_to_variable(t_content *x);
int		key_press(int keycode, t_content *x);
void 	key_press_update(char move, int nby, int nbx, t_content *x);
void	which_key(t_content *x);
void	parser(t_content *x);
int		cleaner(t_content *x);

#endif